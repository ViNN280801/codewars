// Task: Once upon a time, on a way through the old wild mountainous west,…
// … a man was given directions to go from one point to another.
// The directions were "NORTH", "SOUTH", "WEST", "EAST". Clearly "NORTH" and "SOUTH"
// are opposite, "WEST" and "EAST" too.

// Going to one direction and coming back the opposite direction right
// away is a needless effort. Since this is the wild west, with dreadful
// weather and not much water, it's important to save yourself some energy,
// otherwise you might die of thirst!
// How I crossed a mountainous desert the smart way.

// The directions given to the man are, for example,
// the following (depending on the language):

// ["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"].
// or
// { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
// or
// [North, South, South, East, West, North, West]

// You can immediately see that going "NORTH" and immediately
// "SOUTH" is not reasonable, better stay to the same place!
// So the task is to give to the man a simplified version of the
// plan. A better plan in this case is simply:

// ["WEST"]
// or
// { "WEST" }
// or
// [West]

// Other examples:
// In ["NORTH", "SOUTH", "EAST", "WEST"], the direction "NORTH" + "SOUTH"
// is going north and coming back right away.
// The path becomes ["EAST", "WEST"], now "EAST" and "WEST" annihilate each
// other, therefore, the final result is [] (nil in Clojure).
// In ["NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"], "NORTH" and "SOUTH"
// are not directly opposite but they become directly opposite after the
// reduction of "EAST" and "WEST" so the whole path is reducible to ["WEST", "WEST"].

// Write a function dirReduc which will take an array of
// strings and returns an array of strings with the needless
// directions removed (W<->E or S<->N side by side).

// The Haskell version takes a list of directions with data Direction = North | East | West | South.
// The Clojure version returns nil when the path is reduced to nothing.
// The Rust version takes a slice of enum Direction {North, East, West, South}.

// See more examples in "Sample Tests:"
// Notes
// Not all paths can be made simpler. The path ["NORTH", "WEST", "SOUTH", "EAST"]
// is not reducible. "NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and
// "EAST" are not directly opposite of each other and can't become such.
// Hence the result path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].
// if you want to translate, please ask before translating.

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <map>

// North, South, West, East
using directionCords = std::pair<int, int>;
using cardinalDirection = std::map<std::string, directionCords>;

static const cardinalDirection directionMap{
    {"NORTH", {0, 1}},
    {"SOUTH", {0, -1}},
    {"WEST", {-1, 0}},
    {"EAST", {1, 0}}};

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
    {
        if (arr.size() <= 1)
            return arr;

        for (unsigned i = 1; i < arr.size(); i++)
        {
            std::string pos{arr.at(i - 1)}, nextPos{arr.at(i)};

            bool northSouth{(directionMap.at(pos).first == directionMap.at(nextPos).first) &&
                            (directionMap.at(pos).second != directionMap.at(nextPos).second)};

            bool westEast{(directionMap.at(pos).second == directionMap.at(nextPos).second) &&
                          (directionMap.at(pos).first != directionMap.at(nextPos).first)};

            bool isOppositeDirection{northSouth || westEast};

            if (isOppositeDirection)
            {
                arr.erase(std::begin(arr) + (i - 1), std::begin(arr) + (i + 1));
                i = 0;
            }
        }

        return arr;
    }
};

template <typename T>
void print_vec(std::vector<T> vec)
{
    for (auto el : vec)
    {
        std::cout << el << '\t';
    }
    std::endl(std::cout);
}

int main()
{
    std::vector<std::string> arr1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "NORTH"};
    std::vector<std::string> vec = DirReduction::dirReduc(arr1);
    print_vec(arr1);

    arr1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    vec = DirReduction::dirReduc(arr1);
    print_vec(arr1);

    return EXIT_SUCCESS;
}
