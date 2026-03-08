// ヒープの作成（下方移動）
#include <stdio.h>

void swap(int *, int *);

int main(void) {
    int heap[100];
    int i, n, p, s, m;

    n = 1;
    while (scanf("%d", &heap[n]) != EOF) n++; // データを木に割り当てる
    m = n-1; // データ数
    for (i = m/2; i >= 1; i--) {
        p = i; // 親の位置
        s = 2 * p; // 左の子の位置
        while (s <= m) {
            if (s < m && heap[s+1] < heap[s]) s++; // 左と右の子の小さい方
            if (heap[p] <= heap[s]) break;
            swap(&heap[p], &heap[s]);
            p = s; s = 2 * p; // 親と子の位置の更新
        }
    }
    for (i = 1; i <= m; i++) printf("%d ", heap[i]);
    printf("\n");

    return 0;
}

void swap(int *a, int *b) {
    int w;
    w = *a; *a = *b; *b = w;
}
