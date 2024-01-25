#include <stddef.h>

enum membership
{
    OPEN = 1,
    SENIOR = 2
};

void open_or_senior(size_t n, const int members[n][2], enum membership memberships[n])
{
    for (size_t i = 0ul; i < n; ++i)
        memberships[i] = (members[i][0] >= 55 && members[i][1] > 7) ? SENIOR : OPEN;
}
