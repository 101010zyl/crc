#include "def.h"

int
showbinary(polynml n)
{
    int i;
    for (i = BITNUM - 1; i >= 0; i--) {
        if (n & (1ULL << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf(" %llx", n);
    printf("\n");
    return 0;
}

int
showinfo(polynml origin, polynml gen)
{
    printf("\nnow the polynomials are:\n");
    printf("origin: ");
    showpolynml(origin);
    printf("generator: ");
    showpolynml(gen);
    printf("\n");
    return 1;
}

int showmenu()
{
    printf("\n----------------------------------------\n");
    printf("menu:\n");
    printf("1. set origin\n");
    printf("2. set generator\n");
    printf("3. show info\n");
    printf("4. encode\n");
    printf("5. quit\n");
    printf("6. set generator as: ");
    showpolynml(set[0]);
    printf("7. set generator as: ");
    showpolynml(set[1]);
    printf("-----------------------------------------\n");
    return 1;
}

int
inputpolynml(polynml *n)
{
    *n = 0;
    printf("For polynomial x^31 + x^3 + 1, input \"31 3 0 -1\", -1 is the end of input.\n");
    printf("input: \n");
    int input = 0;
    while(scanf("%d", &input) != EOF){
        if(input < -1 || input >= BITNUM){
            printf("invalid input\n");
            return 0;
            break;
        }
        getchar();
        if(input == -1){
            break;
        }
        *n |= (1ULL << input);
    }
    printf("input polynomial: ");
    showpolynml(*n);
    return 1;
}

int
showpolynml(polynml n)
{
    int i;
    for(i = BITNUM - 1; i >= 0; i--){
        if(n & (1ULL << i)){
            printf("x^%d + ", i);
        }
    }
    printf("0\n");
    return 1;
}