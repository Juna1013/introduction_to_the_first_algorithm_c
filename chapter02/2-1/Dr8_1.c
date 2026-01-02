// 一様性の検定
#include <stdio.h>

#define N 1000 // 乱数の発生回数
#define M 10 // 整数乱数の範囲
#define F (N/M) // 期待値
#define SCALE (40.0/F) // ヒストグラムの高さ（自動スケール）

unsigned rndnum = 13; // 乱数の初期値

unsigned irnd(void);
double rnd(void);

int main(void) {
    int rank, hist[M+1];
    double e = 0.0;

    for (int i = 1; i <= M; i++) hist[i] = 0; // 0クリア
    for (int i = 0; i < N; i++) { // 1 ~ M の乱数を1つ発生
        rank = (int)(M * rnd() + 1);
        hist[rank]++;
    }

    for (int i = 1; i <= M; i++) { // ヒストグラムの表示
        printf("%3d : %3d ", i, hist[i]);
        for (int j = 0; j < hist[i] * SCALE; j++) printf("*");
        printf("\n");

        e = e + (double)(hist[i] - F) * (hist[i] - F) / F;
    }
    printf("χ 2 = %f\n", e);

    return 0;
}

unsigned irnd(void) { // 0 ~ 32767 の整数乱数
    rndnum = (rndnum * 109 + 1021) % 32767;
    return rndnum;
}

double rnd(void) { // 0 ~ 1 未満の実数乱数
    return irnd() / 32767.1;
}