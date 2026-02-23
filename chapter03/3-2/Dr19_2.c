// シェルソート（改良挿入法）
#include <stdio.h>
#include <stdlib.h>

#define N 100 // データ数

int main(void) {
    int a[N], i, j, gap, t;

    for (i = 0; i < N; i++) { // N個の乱数
        a[i] = rand();
    }

    for (gap = 1; gap < N/3; gap = 3*gap+1); // Nより小さい範囲で最大のgapを求める

    while (gap > 0) {
        for (i = gap; i < N; i++) {
            for (j = i - gap; j >= 0; j = j - gap) {
                if (a[j] > a[j + gap]) {
                    t = a[j]; a[j] = a[j + gap]; a[j + gap] = t;
                } else break;
            }
        }
        gap = gap / 3;
    }

    for (i = 0; i < N; i++) {
        printf("%8d", a[i]);
    }
    printf("\n");
}
