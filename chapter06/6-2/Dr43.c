// 最小ノード・最大ノードの探索
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left; // 左部分木へのポインタ
    char name[12]; // 名前
    struct tnode *right; // 右部分木へのポインタ
};

struct tnode *talloc(void);

int main(void) {
    char dat[12];
    struct tnode *root, *p, *old = NULL;

    root = talloc(); // ルート・ノード
    scanf("%s", root->name);
    root->left = root->right = NULL;

    while (scanf("%s", dat) != EOF) {
        p = root; // 木のサーチ
        while (p != NULL) {
            old = p;
            if (strcmp(dat, p->name) <= 0) {
                p = p->left;
            } else p = p->right;
        }
        p = talloc(); // 新しいノードの接続
        strcpy(p->name, dat);
        p->left = p->right = NULL;
        if (strcmp(dat, old->name) <= 0) old->left = p;
        else old->right = p;
    }

    p = root; // 最小ノード・最大ノードの探索
    while (p->left != NULL) p = p->left;
    printf("最小ノード = %s\n", p->name);

    p = root;
    while (p->right != NULL) p = p->right;
    printf("最大ノード = %s\n", p->name);

    return 0;
}

struct tnode *talloc(void) { // 記憶領域の取得
    return (struct tnode *)malloc(sizeof(struct tnode));
}
