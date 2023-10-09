#include "def.h"

// calculate the crc code
polynml
crc(polynml origin, polynml gen)
{
    printf("origin: ");
    showbinary(origin);
    printf("generator: ");
    showbinary(gen);
    
    //get the length of gen
    int genlen = 0;
    int i = 0;
    for(i = BITNUM - 1; i >= 0; i--){
        if(gen & (1 << i)){
            genlen = i;
            break;
        }
    }

    // get the length of origin
    int originlen = 0;
    for(i = BITNUM - 1; i >= 0; i--){
        if(origin & (1 << i)){
            originlen = i;
            break;
        }
    }

    polynml result = 0;
    polynml remainder = 0;
    polynml divider = origin << genlen;
    polynml temp = divider >> originlen;

    int resultlen = originlen;
    int dividetimes = originlen;

    int j = 0;
    for(j = originlen; j >= 0; j--){
        if(temp & (1 << genlen)){
            result |= (1 << j);
            temp ^= gen;
        }else{
            temp ^= 0;
        }
        if(j == 0){
            remainder = temp;
            break;
        }
        temp <<= 1;
        temp |= ((divider >> (j - 1)) & 1);
    }

    polynml code = divider | remainder;
    printf("result: ");
    showbinary(code);
    return code;
}