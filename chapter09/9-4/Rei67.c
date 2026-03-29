// ダイナミック・プログラミング（ナップ・サック問題）
#include <stdio.h>

#define limit 8 // ナップサックの重量制限値
#define n 5     // 品物の種類
#define min 1   // 重さの最小値

int main(void) {
    struct body {
        char name[20]; // 品物
        int size;      // 重さ
        long price;    // 価格
    } a[] = {{"plum", 4, 4500}, {"apple", 5, 5700}, {"orange", 2, 2250}, {"strawberry", 1, 1100}, {"melon", 6, 6700}};
    long newvalue, value[limit+1];
    int item[limit+1], i, s, p;

    for (s = 0; s <= limit; s++) {
        value[s] = 0; // 初期値
    }

    for (i = 0; i < n; i++) {
        for (s = a[i].size; s <= limit; s++) { // 品物の番号
            p = s - a[i].size;                 // ナップのサイズ
            newvalue = value[p] + a[i].price;  // 空きサイズ
            if (newvalue > value[s]) {
                value[s] = newvalue; item[s] = i; // 最適解の更新
            }
        }
    }

    printf("品目 価格\n");
    for (s = limit; s >= min; s = s - a[item[s]].size) {
        printf("%10s%5ld\n", a[item[s]].name, a[item[s]].price);
    }
    printf("合計 %5ld\n", value[limit]);

    return 0;
}
