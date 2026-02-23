// シェルソート（改良挿入法）
#include <stdio.h>
#include <stdlib.h>

#define N 100 // データ数

int main(void) {
    int a[N], i, j, k, gap, t;

    for (i = 0; i < N; i++) { // N個の乱数
        a[i] = rand();
    }

    gap = N / 2;
    while (gap > 0) {
        for (k = 0; k < gap; k++) {
            for (j = i-gap; j >= k; j = j - gap) {
                if (a[j] > a[j + gap]) {
                    t = a[j]; a[j] = a[j + gap]; a[j + gap] = t;
                } else break;
            }
        }
        gap = gap / 2;
    }

    for (i = 0; i < N; i++) {
        printf("%8d", a[i]);
    }
    printf("\n");
}
