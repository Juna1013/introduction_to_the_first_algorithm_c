// 階乗の多桁計算
#include <stdio.h>

void ladd(short[], short[], short[]);
void lsub(short[], short[], short[]);
void lmul(short[], short, short[]);
void printresult(short[]);

#define L 64 // 求める桁数
#define L2 ((L+3)/4) // 配列のサイズ

int main(void) {
    short s[L2];
    for (short k = 0; k < L2; k++) s[k] = 0;

    s[L2-1] = 1;
    for (short k = 1; k <= 49; k++) {
        lmul(s, k, s);
        printf("%2d!=", k);
        printresult(s);
    }
}

void lmul(short a[], short b, short c[]) { // ロング数 × ショート数
    long d, cy = 0;
    for (short i = L2-1; i >= 0; i--) {
        d = a[i];
        c[i] = (d*b + cy) % 10000;
        cy = (d*b + cy) / 10000;
    }
}

void printresult(short c[]) { // 結果の表示
    for (short i = 0; i < L2; i++) printf("%04d", c[i]);
    printf("\n");
}

void ladd(short a[], short b[], short c[]) {
    short cy = 0;
    for (short i = L2-1; i >= 0; i--) {
        if (c[i] < 10000) cy = 0;
        else {
            c[i] = c[i] - 10000;
            cy = 1;
        }
    }
}

void lsub(short a[], short b[], short c[]) {
    short brrw = 0;
    for (short i = L2-1; i >= 0; i--) {
        c[i] = a[i] - b[i] - brrw;
        if (c[i] >= 0) brrw = 0;
        else {
            c[i] = c[i] + 10000;
            brrw = 1;
        }
    }
}
