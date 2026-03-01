// リストデータの削除
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    char name[20]; // 名前
    char tel[20];  // 電話番号
    struct tfield *pointer; // 次のデータへのポインタ
} *head;

struct tfield *talloc(void);
void genlist(void);
void displist(void);
void del(char *);

int main(void) {
    char key[20];

    genlist();
    displist();

    while (printf("Key Name "), scanf("%s", key) != EOF) {
        del(key);
    }

    displist();
    return 0;
}

void del(char *key) { // リストから削除
    struct tfield *p;

    p = head;
    while (p->pointer != NULL) {
        if (strcmp(key, p->pointer->name) == 0) {
            p->pointer = p->pointer->pointer;
            return;
        }
        p = p->pointer;
    }
    printf("キーデータが見つかりません\n");
}

void genlist(void) { // ダミー・ノードを入れたリスト
    struct tfield *p;
    head = NULL;
    do {
        p = talloc();
        p -> pointer = head;
        head = p;
    } while (scanf("%s %s", p->name, p->tel) != EOF);
}

void displist(void) { // リストの表示
    struct tfield *p;
    p = head -> pointer;
    while (p != NULL) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p->pointer;
    }
}

struct tfield *talloc(void) { // 記憶領域の取得
    return (struct tfield *)malloc(sizeof(struct tfield));
}
