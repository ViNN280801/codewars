// Task: Timmy & Sarah think they are in love, but around where they live, they will only know once
// they pick a flower each. If one of the flowers has an even number of petals and the other has
// an odd number of petals it means they are in love.

// Write a function that will take the number of petals of each flower and return true if they are in love and false if they aren't.

#include <stdio.h>
#include <stdbool.h>

// Returns true if petals are in love, and false if they aren't
bool lovefunc(int flower1, int flower2)
{
    return (((flower1 % 2 == 0) && (flower2 % 2 != 0)) || ((flower1 % 2 != 0) && (flower2 % 2 == 0))) ? true : false;
}

int main(int argc, char *argv[])
{
    // Initializing count of petals of 1st flower and petals of 2nd flower
    int petals_1, petals_2 = 0;
    printf("Enter count of petals on 1st flower: ");
    scanf("%d", &petals_1);
    printf("Enter count of petals on 2nd flower: ");
    scanf("%d", &petals_2);

    // Checking returned bool for print consequence information
    if(lovefunc(petals_1, petals_2) == true)
        printf("Timmy and Sarah are in love.\n");
    else
        printf("Timmy and Sarah aren't in love.\n");

    return 0;
}