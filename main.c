#include "def.h"

static polynml origin = 0;
static polynml gen = 0;
static char input = 0;

int
main()
{
    printf("long long int: %d\n", sizeof(unsigned long long int));
    printf("long int: %d\n", sizeof(long int));
    printf("int: %d\n", sizeof(int));
    printf("\n");

    gen = set[0];
    origin = 0x29;

    while(1){
        showmenu();
        if(scanf("%d", &input) == EOF){
            break;
        }
        printf("input: %d\n", input);
        switch(input){
            case 1:
                printf("input origin: ");
                if(inputpolynml(&origin) == 0){
                    printf("origin input failed.\n");
                }
                showinfo(origin, gen);
                break;
            case 2:
                printf("input generator: ");
                if(inputpolynml(&gen) == 0){
                    printf("generator input failed.\n");
                }
                showinfo(origin, gen);
                break;
            case 3:
                showinfo(origin, gen);
                break;
            case 4:
                crc(origin, gen);
                break;
            case 5:
                return 0;
                break;
            case 6:
                gen = set[0];
                showinfo(origin, gen);
                break;
            case 7:
                gen = set[1];
                showinfo(origin, gen);
                break;
            default:
                printf("invalid input\n");
                showmenu();
                break;
        }
    }
    return 0;
}