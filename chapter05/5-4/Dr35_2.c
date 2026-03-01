// リストデータの探索
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
    struct tfield *head, *p, sentinel; // 番兵
    char key[20];

    head = &sentinel;
    while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        p -> pointer = head;
        head = p;
    }

    rewind(stdin); // 探索
    while (printf("Key name" ), scanf("%s", key) != EOF) {
        strcpy(sentinel.name, key); // 番兵にキーを入れる
        p = head;
        while (strcmp(p -> name, key) != 0) {
            p = p -> pointer;
        }
        if (p != &sentinel) printf("%s %s\n", p->name, p->tel);
        else printf("見つかりません\n");
    }

    return 0;
}

struct tfield *talloc(void) { // 記憶領域の取得
    return (struct tfield *)malloc(sizeof(struct tfield));
}
