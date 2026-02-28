// スタック
#include <stdio.h>

#define MaxSize 100 // スタック・サイズ
int stack[MaxSize]; // スタック
int sp = 0; // スタック・ポインタ
int push(int);
int pop(int *);

int main(void) {
    int c, n;

    while (printf("]"), (c = getchar()) != EOF) {
        rewind(stdin);
        if (c == 'i' || c == 'I') {
            printf("data --> ");
            scanf("%d", &n); rewind(stdin);
            if (push(n) == -1) {
                printf("スタックが一杯です\n");
            }
        }

        if (c == 'o' || c == 'O') {
            if (pop(&n) == -1) {
                printf("スタックは空です\n");
            } else printf("stack data --> %d\n", n);
        }
    }

    return 0;
}

int push(int n) { // スタックにデータを頼む手続き
    if (sp < MaxSize) {
        stack[sp] = n;
        sp++;
        return 0;
    } else return -1; // スタックが一杯のとき
}

int pop(int *n) { // スタックからデータを取り出す手続き
    if (sp > 0) {
        sp--;
        *n = stack[sp];
        return 0;
    } else return -1; // スタックが空のとき
}
