// 順位付け（改良版）
#include <stdio.h>

#define Num 10
#define Max 100
#define Min 0

int main(void) {
    int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
    int juni[Max + 2];

    // 0クリア
    for (int i = Min; i <= Max; i++) juni[i] = 0;

    // 各得点に対応する添え字の数列の内容を+1
    for (int i = 0; i < Num; i++) juni[a[i]]++;

    // 1つ右の要素の内容を加える
    juni[Max + 1] = 1;
    for (int i = Max; i >= Min; i--) juni[i] = juni[i] + juni[i + 1];
    printf("　得点　順位\n");
    for (int i = 0; i < Num; i++) printf("%6d%6d\n", a[i], juni[a[i] + 1]);

    return 0;
}
