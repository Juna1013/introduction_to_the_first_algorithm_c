// 戦略を持つじゃんけん
#include <stdio.h>

int main(void) {
    int man, computer, C, M, judge;
    int table[3][3][3] = {{{0,0,0},{0,0,0},{0,0,0}},
                          {{0,0,0},{0,0,0},{0,0,0}},
                          {{0,0,0},{0,0,0},{0,0,0}}},
        hist[3] = {0,0,0}; // 勝敗の度数
    const char *hand[3] = {"グー", "チョキ", "パー"};

    C = M = 0;
    while (1) {
        if (table[C][M][0] > table[C][M][1] && table[C][M][0] > table[C][M][2]) computer = 0;
        else if (table[C][M][1] > table[C][M][2]) computer = 1;
        else computer = 2;

        printf("0:グー 1:チョキ 2:パー\n");
        printf("あなたの手 "); scanf("%d", &man);

        printf("コンピュータの手 %s\n", hand[computer]);

        judge = (computer - man + 3) % 3;
        switch (judge) { // 判定
            case 0: printf("ひきわけ\n");
                    table[C][M][(computer + 2) % 3]++; break;
            case 1: printf("あなたの勝ち\n");
                    table[C][M][computer]--; break;
            case 2: printf("コンピュータの勝ち\n");
                    table[C][M][computer]++; break;
        }
        M = man; // 1つ前の状態を保存
        C = computer;

        hist[judge]++;
        printf("--- %d 勝 %d 敗 %d 分 --- \n\n", hist[1], hist[2], hist[0]);
    }
}
