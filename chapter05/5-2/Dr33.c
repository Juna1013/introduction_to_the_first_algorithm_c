// キュー（待ち行列）
#include <stdio.h>

int queuein(int);
int queueout(int *);
void disp(void);

#define MaxSize 100 // キュー・サイズ
int queue[MaxSize]; // キュー
int head = 0, // 先頭データへのポインタ
    tail = 0; // 終端データへのポインタ

int main(void) {
    int c, n;

    while (printf("]"), (c = getchar()) != EOF) {
        rewind(stdin);
        switch (c) {
            case 'i':
            case 'I': printf("data --> ");
                      scanf("%d", &n); rewind(stdin);
                      if (queuein(n) == 1) printf("待ち行列が一杯です\n");
                      break;
            case 'o':
            case 'O': if (queueout(&n) == -1) printf("待ち行列は空です\n");
                      else printf("queue data --> %d\n", n);
                      break;
            case 'l':
            case 'L': disp();
                      break;
        }
    }

    return 0;
}

int queuein(int n) { // キューにデータを入れる手続き
    if ((tail + 1) % MaxSize != head) {
        queue[tail] = n;
        tail++;
        tail = tail % MaxSize;
        return 0;
    } else return -1; // キューが一杯のとき
}

int queueout(int *n) { // キューからデータを取り出すとき
    if (tail != head) {
        *n = queue[head];
        head++;
        head = head % MaxSize;
        return 0;
    } else return -1; // キューが空のとき
}

void disp(void) { // 待ち行列の内容を表示する手続き
    int i;

    i = head;
    while (i != tail) {
        printf("%d\n", queue[i]);
        i++;
        i = i % MaxSize;
    }
}
