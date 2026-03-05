// 2分探索木の作成（再帰版）
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left; // 左部分木へのポインタ
    char name[12]; // 名前
    struct tnode *right; // 右部分木へのポインタ
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *, char *);

int main(void) {
    char dat[12];
    struct tnode *root, *p;

    root = NULL;
    while (scanf("%s", dat) != EOF) {
        root = gentree(root, dat);
    }
    p = root;
    while (p != NULL) { // 左のノードをたどる
        printf("%s\n", p->name);
        p = p->left;
    }

    return 0;
}

struct tnode *gentree(struct tnode *p, char *w) { // 木の作成の再帰手続き
    if (p == NULL) {
        p = talloc();
        strcpy(p->name, w);
        p->left = p->right = NULL;
    } else if (strcmp(w, p->name) < 0) {
        p->left = gentree(p->left, w);
    } else {
        p->right = gentree(p->right, w);
    }
    return p;
}

struct tnode *talloc(void) { // 記憶領域の取得
    return (struct tnode *)malloc(sizeof(struct tnode));
}
