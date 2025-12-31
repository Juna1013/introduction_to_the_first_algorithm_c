// ランダムな順列（改良版）
#include <stdio.h>
#include <stdlib.h>

#define N 20

int irnd(int);

int main(void) {
    // 入力
    int j, d, a[N + 1];

    // 1 ~ N の値を順番に格納する
    for (int i = 1; i <= N; i++) a[i] = i;

    // 交換
    for (int i = N; i <= N; i++) {
        j = irnd(i - 1);
        d = a[i];
        a[i] = a[j];
        a[j] = d;
    }

    // 出力
    for (int i = 1; i <= N; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}

int irnd(int n) {
    return (int)(rand() / (RAND_MAX + 0.1) * n + 1);
}
