// 最短路のルートの表示
#include <stdio.h>
#include <stdlib.h>

#define N 8 // 節点の数
#define M 9999

int a[N+1][N+1] = {{0,0,0,0,0,0,0,0,0}, // 隣接行列
                   {0,0,1,7,2,M,M,M,M},
                   {0,1,0,M,M,2,4,M,M},
                   {0,7,M,0,M,M,2,3,M},
                   {0,2,M,M,0,M,M,5,M},
                   {0,M,2,M,M,0,1,M,M},
                   {0,M,4,2,M,1,0,M,6},
                   {0,M,M,3,5,M,M,0,2},
                   {0,M,M,M,M,M,6,2,0}};

int main(void) {
    int j,k,p,start,min,
        leng[N+1],  // 節点までの距離
        v[N+1],     // 確定フラグ
        index[N+1]; // 前の接点へのポインタ
    
    printf("始点"); scanf("%d", &start);
    for (k = 1; k <= N; k++) {
        leng[k] = M; v[k] = 0; index[k] = 0;
    }
    leng[start] = 0;
    index[start] = 0; // 始点はどこも通さない

    for (j = 1; j <= N; j++) {
        min = M; // 最小の節点を探す
        for (k = 1; k <= N; k++) {
            if (v[k] == 0 && leng[k] < min) {
                p = k; min = leng[k];
            }
        }
        v[p] = 1;

        if (min == M) {
            printf("グラフは連結ではない\n");
            exit(1);
        }

        // pを経由してkに至る長さがそれまでの最短路より小さければ更新
        for (k = 1; k <= N; k++) {
            if ((leng[p] + a[p][k]) < leng[k]) {
                leng[k] = leng[p] + a[p][k];
                index[k] = p;
            }
        }
    }

    for (j = 1; j <= N; j++) { // 最短路のルートの表示
        printf("%3d : %d", leng[j], j); // 終端
        p = j;
        while (index[p] != 0) {
            printf(" <-- %d", index[p]);
            p = index[p];
        }
        printf("\n");
    }

    return 0;
}
