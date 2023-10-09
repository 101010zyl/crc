#include "def.h"

int
main()
{
    printf("long long int: %d\n", sizeof(long long int));
    printf("long int: %d\n", sizeof(long int));
    printf("int: %d\n", sizeof(int));
    printf("\n");
    polynml origin = 0;
    polynml gen = 0;
    char input;
    showmenu();
    showinfo(origin, gen);
    polynml set[2] = {0xd, 0x18005};
    while(1){
        if(scanf("%d", &input) == EOF){
            break;
        }
        printf("input: %d\n", input);
        switch(input){
            case 1:
                printf("input origin: ");
                scanf("%lld", &origin);
                break;
            case 2:
                printf("input generator: ");
                scanf("%lld", &gen);
                break;
            case 3:
                showinfo(origin, gen);
                break;
            case 4:
                break;
            case 5:
                return 0;
            default:
                printf("invalid input\n");
                showmenu();
                break;
        }
    }
    return 0;
}