// 2分探索木のトラバーサル（非再帰版）
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

void treewalk(struct tnode *p) { // 木のトラバーサル（非再帰版）
    struct tnode *q, *w[128];
    int sp = 0;

    q = p;
    while (!(sp == 0 && q == NULL)) {
        while (q != NULL) { // 行けるだけ左に進む
            w[sp++] = q; // 親の位置をスタックに積む
            q = q->left;
        }
        sp--; // 1つ前の親に戻る
        printf("%s\n", w[sp]->name);
        q = w[sp]->right; // 右へ進む
    }
}

struct tnode *gentree(struct tnode *p, char *w) { // 木の作成の再帰手続き
    if (p == NULL) {
        p = talloc();
        strcpy(p->name, w);
        p->left = p->right = NULL;
    } else if (strcmp(p->name, w) < 0) {
        p->right = gentree(p->right, w);
    } else {
        p->left = gentree(p->left, w);
    }
    return p;
}

struct tnode *talloc(void) { // 記憶領域の取得
    return (struct tnode *)malloc(sizeof(struct tnode));
}
