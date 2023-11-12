#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define NEIGBOUR_CELLS_COUNT 8
#define UNIVERSE_SIZE 3

typedef enum
{
    DEAD = 0,
    LIVE = 1
} cell_state_t;

typedef struct
{
    int x;
    int y;
    cell_state_t state;
} cell_t;

void update_screen()
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef __unix__
    system("clear");
#endif
}

void check_ptr(void *p)
{
    if (!p)
    {
        fprintf(stderr, "Can't allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Getter for cell state.
 * @param cell specified cell
 * @return `0` if cell is dead, `1` if cell is live.
 */
cell_state_t get_cell_state(cell_t *cell, cell_t **universe, int rows, int cols)
{
    // Checking if the specified cell is not a border and is not an edge element
    int x = (cell->x + rows) % rows,
        y = (cell->y + cols) % cols;

    return universe[x][y].state;
}

/**
 * @brief Fills cell with the specified params.
 * @param row x.
 * @param col y.
 * @param cell ptr to cell that we want to fill.
 */
void fill_cell(int row, int col, cell_t *cell, cell_t **universe, int rows, int cols)
{
    cell->x = row;
    cell->y = col;
    cell->state = get_cell_state(cell, universe, rows, cols);
}

void print_cell(cell_t *cell)
{
    printf("cell[%d][%d] = %d\n", cell->x, cell->y, cell->state);
}

/**
 * @brief Getter for Moore's neighbour cells.
 * @param cell specified cell to find neighbour cells.
 * @return 8 neighbour cells:
 * 0 1 2
 * 3 x 4
 * 5 6 7
 */
cell_t *get_neighbour_cells(cell_t cell, cell_t **universe, int rows, int cols)
{
    cell_t *cells = (cell_t *)calloc(NEIGBOUR_CELLS_COUNT, sizeof(cell_t));
    check_ptr(cells);

    // Manually filling cells
    fill_cell(cell.x - 1, cell.y + 1, &cells[0], universe, rows, cols);
    fill_cell(cell.x, cell.y + 1, &cells[1], universe, rows, cols);
    fill_cell(cell.x + 1, cell.y + 1, &cells[2], universe, rows, cols);
    fill_cell(cell.x - 1, cell.y, &cells[3], universe, rows, cols);
    fill_cell(cell.x + 1, cell.y, &cells[4], universe, rows, cols);
    fill_cell(cell.x - 1, cell.y - 1, &cells[5], universe, rows, cols);
    fill_cell(cell.x, cell.y - 1, &cells[6], universe, rows, cols);
    fill_cell(cell.x + 1, cell.y - 1, &cells[7], universe, rows, cols);

    return cells;
}

/**
 * @brief Getter for count of live cells.
 * @param cell specified cell.
 * @return Count of the live neighbour cells (max is 8).
 */
int get_count_of_live_cells(cell_t cell, cell_t **universe, int rows, int cols)
{
    cell_t *cells = get_neighbour_cells(cell, universe, rows, cols);

    int count_of_live = 0;
    for (int i = 0; i < NEIGBOUR_CELLS_COUNT; ++i)
        count_of_live += get_cell_state(&cells[i], universe, rows, cols);

    free(cells);
    cells = NULL;

    return count_of_live;
}

/**
 * @brief Getter for the next cell state.
 * @param row x.
 * @param col y.
 * @param rows border for x.
 * @param cols border for y.
 * @return `0` if the next state of the cell is `DEAD`, otherwise `1` - `LIVE`.
 */
int get_next_cell_state(cell_t cell, int rows, int cols, cell_t **universe)
{
    // Checking that we don't go beyond the borders of positive numbers
    assert(cell.x >= 0 && cell.y >= 0);

    // Getting count of live cells in Moore's neighborhood
    int count = get_count_of_live_cells(cell, universe, rows, cols);

    // By the rules of the Game of Live:
    // 1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
    // 2. Any live cell with more than three live neighbours dies, as if by overcrowding.
    // 3. Any live cell with two or three live neighbours lives on to the next generation.
    // 4. Any dead cell with exactly three live neighbours becomes a live cell.
    return (get_cell_state(&cell, universe, rows, cols) == LIVE) ? ((count < 2 || count > 3) ? DEAD : LIVE)
           : (count == 3)                                        ? LIVE
                                                                 : DEAD;
}

/**
 * @brief Converter for `int *[]` to `cell_t *[]`.
 * @param raw_cells raw cells.
 * @param rows count of rows.
 * @param cols count of columns.
 * @param cells double ptr to the cells.
 */
void ppint_to_cells(int const *const raw_cells[], int rows, int cols, cell_t ***cells)
{
    // Allocate memory for the 2D array of cell_t structures
    *cells = (cell_t **)calloc(rows, sizeof(cell_t *));
    check_ptr(*cells);

    for (int i = 0; i < rows; ++i)
    {
        (*cells)[i] = (cell_t *)calloc(cols, sizeof(cell_t));
        check_ptr((*cells)[i]);

        for (int j = 0; j < cols; ++j)
        {
            // Fill in the cell_t structure with the corresponding values from the raw_cells array
            fill_cell(i, j, &(*cells)[i][j], *cells, rows, cols);
            (*cells)[i][j].state = (raw_cells[i][j] == 0) ? DEAD : LIVE;
        }
    }
}

/**
 * @brief Prints universe to the terminal.
 * @param cells the current state of the universe as a 2D array of integers.
 * @param rows number of rows in the universe.
 * @param cols number of columns in the universe.
 */
void print_universe(cell_t **cells, int rows, int cols)
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
            printf("%d ", cells[row][col].state);
        printf("\n");
    }
}

/**
 * @brief Updates the state of the universe based on the rules of the Game of Life.
 * @param cells The current state of the universe as a 2D array of integers.
 * @param rows Number of rows in the universe.
 * @param cols Number of columns in the universe.
 * @return A new 2D array of integers representing the updated state of the universe.
 */
cell_t **update_universe(cell_t **cells, int rows, int cols)
{
    // Allocate memory for the updated cells
    cell_t **updated_cells = (cell_t **)calloc(rows, sizeof(cell_t *));
    check_ptr(updated_cells);

    for (int i = 0; i < rows; ++i)
    {
        updated_cells[i] = (cell_t *)calloc(cols, sizeof(cell_t));
        check_ptr(updated_cells[i]);
    }

    // Update each cell based on the rules of the Game of Life
    for (int row = 0; row < rows; ++row)
        for (int col = 0; col < cols; ++col)
        {
            fill_cell(row, col, &updated_cells[row][col], cells, rows, cols);
            updated_cells[row][col].state = get_next_cell_state(cells[row][col], rows, cols, cells);
        }

    return updated_cells;
}

/**
 * @brief Checker of live state of the universe.
 * @param cells the current state of the universe as a 2D array of integers.
 * @param rows number of rows in the universe.
 * @param cols number of columns in the universe.
 * @return `1` if at least one cell is still alive, otherwise `0`.
 */
int is_universe_live(cell_t **cells, int rows, int cols)
{
    for (int row = 0; row < rows; ++row)
        for (int col = 0; col < cols; ++col)
            // If at least one cell is live - all universe is live
            // (but in this case this last cell will die caused by underpopulation).
            if (cells[row][col].state == LIVE)
                return LIVE;
    return DEAD;
}

int **get_generation(int const *const cells[], int generations, int *rowptr, int *colptr)
{
    // Assuming the input cells array is a square grid, find the dimensions
    *rowptr = *colptr = 0;
    while (cells[*rowptr] != NULL)
        ++(*rowptr);
    if (*rowptr > 0)
    {
        *colptr = 0;
        while (cells[0][*colptr] != -1)
            ++(*colptr);
    }

    // Convert the initial generation to cell_t structures
    cell_t **current_cells = NULL;
    ppint_to_cells(cells, *rowptr, *colptr, &current_cells);

    // Simulate the Game of Life for the specified number of generations
    for (int gen = 0; gen < generations; ++gen)
    {
        // Print the current state of the universe
        print_universe(current_cells, *rowptr, *colptr);
        printf("\n");

        // Update the universe to the next generation
        cell_t **updated_cells = update_universe(current_cells, *rowptr, *colptr);

        // Free the memory of the current generation
        for (int i = 0; i < *rowptr; ++i)
        {
            free(current_cells[i]);
            current_cells[i] = NULL;
        }
        free(current_cells);
        current_cells = NULL;

        // Set the current generation to the updated one
        current_cells = updated_cells;
    }

    // Convert the final state back to an integer array
    int **final_state = (int **)calloc((*rowptr + 1), sizeof(int *));
    for (int i = 0; i < *rowptr; ++i)
    {
        final_state[i] = (int *)calloc((*colptr + 1), sizeof(int));
        for (int j = 0; j < *colptr; ++j)
            final_state[i][j] = current_cells[i][j].state;
        final_state[i][*colptr] = -1; // Mark the end of the row
    }
    final_state[*rowptr] = NULL; // Mark the end of the array of pointers

    // Free the memory of the final generation
    for (int i = 0; i < *rowptr; ++i)
    {
        free(current_cells[i]);
        current_cells[i] = NULL;
    }
    free(current_cells);
    current_cells = NULL;

    // Return the final state of the universe
    return final_state;
}

int main()
{
    const int *const gen[] = {
        (int[]){1, 1, 0},
        (int[]){1, 1, 0},
        (int[]){0, 0, 0},
    };

    // Convert the initial generation to cell_t structures
    cell_t **current_cells = NULL;
    ppint_to_cells(gen, 3, 3, &current_cells);

    // Run the Game of Life until all cells are dead
    while (is_universe_live(current_cells, 3, 3))
    {
        // Print the current state of the universe
        print_universe(current_cells, 3, 3);
        printf("\n");

        // Update the universe to the next generation
        cell_t **updated_cells = update_universe(current_cells, 3, 3);

        // Free the memory of the current generation
        for (int i = 0; i < 3; ++i)
        {
            free(current_cells[i]);
            current_cells[i] = NULL;
        }
        free(current_cells);
        current_cells = NULL;

        // Set the current generation to the updated one
        current_cells = updated_cells;
    }
    print_universe(current_cells, 3, 3);
    printf("\n");

    return EXIT_SUCCESS;
}
