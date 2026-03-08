// 2分探索木のトラバーサル
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;  // 左部分木へのポインタ
    char name[12];       // 名前
    struct tnode *right; // 右部分木へのポインタ
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *, char *);
void treewalk(struct tnode *);

int main(void) {
    char dat[12];
    struct tnode *root;

    root = NULL;
    while (scanf("%s", dat) != EOF) {
        root = gentree(root, dat);
    }
    treewalk(root);

    return 0;
}

void treewalk(struct tnode *p) { // 木のトラバーサル
    if (p != NULL) {
        treewalk(p->left);
        printf("%s\n", p->name);
        treewalk(p->right);
    }
}

struct tnode *gentree(struct tnode *p, char *w) { // 木作成の手続き
    if (p == NULL) {
        p = talloc();
        strcpy(p->name, w);
        p->left = p->right = NULL;
    } else if (strcmp(w, p->name) < 0) {
        p->left = gentree(p->left, w);
    } else p->right = gentree(p->right, w);
    return p;
}

struct tnode *talloc(void) { // 記憶領域の取得
    return (struct tnode *)malloc(sizeof(struct tnode));
}
