// 循環・双方向リストデータの作成
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    struct tfield *left;  // 逆ポインタ
    char name[20];        // 名前
    char tel[20];         // 電話番号
    struct tfield *right; // 順ポインタ
};

struct tfield *talloc(void);

int main(void) {
    struct tfield *head, *p;

    head = talloc(); // ダミー・ノードの作成
    head->left = head->right = head;

    while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
        p -> right = head;
        p -> left = head -> left;
        head -> left -> right = p;
        head -> left = p;
    }

    printf("\n 順方向リスト \n");
    p = head -> right;
    while (p != head) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p -> right;
    }
    printf("\n 逆方向リスト \n");
    p = head -> left;
    while (p != head) {
        printf("%15s%15s\n", p->name, p->tel);
        p = p->left;
    }

    return 0;
}

struct tfield *talloc(void) { // 記憶領域の取得
    return (struct tfield *)malloc(sizeof(struct tfield));
}
