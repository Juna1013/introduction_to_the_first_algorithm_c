// 一様乱数（線形合同法）
#include <stdio.h>

unsigned rndnum = 13;

unsigned irnd(void);

int main(void) {
    for (int j = 0; j < 100; j++) printf("%8d", irnd());
    printf("\n");

    return 0;
}

unsigned irnd(void) {
    rndnum = (rndnum * 109 + 1021) % 32768;
    return rndnum;
}
