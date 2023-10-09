#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int polynml;
#define BITNUM 64

static polynml set[2] = {0x000000000000000d, 0x18005};

// util.c
int showbinary(polynml n);
int showinfo(polynml origin, polynml gen);
int showmenu();
int inputpolynml(polynml *n);
int showpolynml(polynml n);

// crc.c
polynml crc(polynml origin, polynml gen);