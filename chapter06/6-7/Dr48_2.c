// ヒープ・ソート
#include <stdio.h>

void swap(int *, int *);
void shiftdown(int, int, int[]);

int main(void) {
    int heap[100];
    int i, n, m;

    n = 1; // データを木に割り当てる
    while (scanf("%d", &heap[n]) != EOF) n++;
    m = n-1; // nの保存
    for (i = m/2; i >= 1; i--) shiftdown(i, m, heap); // 初期ヒープの作成
    while (m > 1) {
        swap(&heap[1], &heap[m]);
        m--; // 木の終端を切り離す
        shiftdown(1, m, heap);
    }
    for (i = 1; i < n; i++) printf("%d ", heap[i]);
    printf("\n");

    return 0;
}

void shiftdown(int p, int n, int heap[]) { // 下方移動
    int s;
    s = 2 * p;
    while (s <= n) {
        if (s < n && heap[s+1] > heap[s]) { // 左と右の子の大きい方
            s++;
        }
        if (heap[p] >= heap[s]) {
            break;
        }
        swap(&heap[p], &heap[s]);
        p = s; s = 2 * p; // 親と子の位置の更新
    }
}

void swap(int *a, int *b) {
    int w;
    w = *a; *a = *b; *b = w;
}
