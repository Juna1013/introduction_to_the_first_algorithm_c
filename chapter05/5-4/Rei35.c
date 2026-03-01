// リストデータへの追加
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
void link(char *);

int main(void) {
    char key[20];

    genlist();
    displist();

    while (printf("Key Name "), scanf("%s", key) != EOF) {
        link(key);
    }

    displist();

    return 0;
}

void link(char *key) { // リストへの追加
    struct tfield *p, *n;

    n = talloc();
    printf("追加データ");
    scanf("%s %s", n->name, n->tel);

    p = head;
    while (p != NULL) {
        if (strcmp(key, p->name) == 0) {
            n -> pointer = p -> pointer;
            p -> pointer = n;
            return;
        }
        p = p -> pointer;
    }
    printf("キーデータが見つかりません\n");
}

void genlist(void) { // リストの作成
    struct tfield *p;

    head = NULL;
    while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        p -> pointer = head;
        head = p;
    }
}

void diplist(void) { // リストの表示
    struct tfield *p;
    p = head;
    while (p != NULL) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p -> pointer;
    }
}

struct tfield *talloc(void) { // 記憶領域の取得
    return (struct tfield *)malloc(sizeof(struct tfield));
}
