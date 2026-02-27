// すべての迷路を辿る
#include <stdio.h>

int m[9][9] = {{2, 2, 2, 2, 2, 2, 2, 2, 2},
               {2, 0, 0, 0, 0, 0, 0, 0, 2},
               {2, 0, 2, 2, 0, 2, 2, 0, 2},
               {2, 0, 2, 0, 0, 2, 0, 0, 2},
               {2, 0, 2, 0, 2, 0, 2, 0, 2},
               {2, 0, 0, 0, 0, 0, 2, 0, 2},
               {2, 2, 0, 2, 2, 0, 2, 2, 2},
               {2, 0, 0, 0, 0, 0, 0, 0, 2},
               {2, 2, 2, 2, 2, 2, 2, 2, 2},};
int Si, Sj, Ei, Ej, success, sp, ri[100], rj[100]; // 通過位置を入れるスタック

int visit(int, int);

int main(void) {
    sp = 0; // スタック・ポインタの初期化
    success = 0; // 脱出に成功したかを示すフラグ
    Si = 1; Sj = 1; Ei = 7; Ej = 7; // 入口と出口の位置

    printf("\n 迷路の探索");
    if (visit(Si, Sj) == 0) printf("出口は見つかりませんでした\n");
    printf("\n");

    return 0;
}

int visit(int i, int j) {
    int k;
    static int path = 1;

    m[i][j] = 1;
    ri[sp] = i; rj[sp] = j; sp++; // 訪問位置をスタックに積む

    if (i == Ei && j == Ej) { // 出口に達したとき
        printf("\n path = %d\n", path++); // 通過点の表示
        for (k = 0; k < sp; k++) {
            printf("(%d, %d) ", ri[k], rj[k]);
        }
        success = 1;
    }

    // 迷路をさまよう
    if (m[i][j+1] == 0) visit(i, j+1);
    if (m[i+1][j] == 0) visit(i+1, j);
    if (m[i][j-1] == 0) visit(i, j-1);
    if (m[i-1][j] == 0) visit(i-1, j);

    sp--; // スタックから捨てる
    m[i][j] = 0; // 別な経路の探索のため

    return success;
}
