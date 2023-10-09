#include "def.h"

int
showbinary(polynml n)
{
    int i;
    for (i = BITNUM; i >= 0; i--) {
        if (n & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}

int
showinfo(polynml origin, polynml gen)
{
    printf("origin: ");
    showbinary(origin);
    printf("generator: ");
    showbinary(gen);
    return 1;
}

int showmenu()
{
    printf("\nmenu:\n");
    printf("1. set origin\n");
    printf("2. set generator\n");
    printf("3. show info\n");
    printf("4. encode\n");
    printf("5. quit\n\n");
    return 1;
}