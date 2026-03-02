// 自己再編成探索
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    char name[20]; // 名前
    char tel[20];  // 電話番号
    struct tfield *pointer; // 次のデータへのポインタ
};

struct tfield *talloc(void);

int main(void) {
    char key[20];
    struct tfield *head, *p, *old1, *old2, *q;

    head = NULL;
    while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        p->pointer = head;
        head = p;
    }

    while (printf("\n Key Name ? "), scanf("%s", key) != EOF) {
        p = head;
        old1 = old2 = NULL;
        while (p != NULL) {
            if (strcmp(key, p->name) == 0) {
                printf("%15s%15s\n", p->name, p->tel);
                if (old2 != NULL) {         // p は先頭ではない
                    if (old1 == NULL) {     // p は2番目（先頭と入れ替え）
                        old2->pointer = p->pointer;
                        p->pointer = head;
                        head = p;
                    } else {               // p は3番目以降（直前と入れ替え）
                        q = old1->pointer;
                        old1->pointer = p;
                        old2->pointer = p->pointer;
                        p->pointer = q;
                    }
                }
                break;
            }
            old1 = old2;
            old2 = p;
            p = p->pointer;
        }
    }

    return 0;
}

struct tfield *talloc(void) {
    return (struct tfield *)malloc(sizeof(struct tfield));
}
