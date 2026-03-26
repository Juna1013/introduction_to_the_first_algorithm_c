// オイラーの一筆書き
#include <stdio.h>

#define Node 4 // 節点の数
#define Root 6 // 辺の数
#define Start 1 // 開始点

int a[Node+1][Node+1] = {{0,0,0,0,0},
                         {0,0,1,0,1},
                         {0,1,0,1,2},
                         {0,0,1,0,1},
                         {0,1,2,1,0}};
int success,
    v[Root+1], // 経路を入れるスタック
    n; // 通過した道の数

void visit(int);

int main(void) {
    success = 0; n = Root;
    visit(Start);
    if (success == 0) {
        printf("解なし\n");
    }
}

void visit(int i) {
    int j;
    v[n] = i;
    if (n == 0 && i == Start) {
        printf("解 %d:", ++success);
        for (i = 0; i <= Root; i++) {
            printf("%d", v[i]);
        }
        printf("\n");
    } 
    for (j = 1; j <= Node; j++) {
        if (a[i][j] != 0) {
            a[i][j]--; a[j][i]--;
            n--;
            visit(j);
            a[i][j]++; a[j][i]++;
            n++;
        }
    }
}
