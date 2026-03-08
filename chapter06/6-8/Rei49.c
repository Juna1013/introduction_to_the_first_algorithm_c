// 式の木
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;  // 左部分木へのポインタ
    char ope;            // 項目
    struct tnode *right; // 右部分木へのポインタ
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *, char *);
void prefix(struct tnode *);
void infix(struct tnode *);
void postfix(struct tnode *);

int main(void) {
    struct tnode *root;
    char expression[] = "ab*c+e/-";

    root = NULL;
    root = gentree(root, expression);

    printf("\nprefix  = "); prefix(root); // 式の木の走査
    printf("\ninfix   = "); infix(root);
    printf("\npostfix = "); postfix(root);
    printf("\n");

    return 0;
}

struct tnode *gentree(struct tnode *p, char *w) { // 式の木の作成
    int n;

    n = strlen(w);
    p = talloc();
    p->ope = w[n-1]; // 文字列の終端をノードにする
    w[n-1] = '\0';   // 終端を除く
    if (p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/') {
        p->right = gentree(p->right, w);
        p->left = gentree(p->left, w);
    } else p->left = p->right = NULL;
    return p;
}

void prefix(struct tnode *p) { // 接頭形
    if (p != NULL) {
        putchar(p->ope);
        prefix(p->left);
        prefix(p->right);
    }
}

void infix(struct tnode *p) { // 挿入形
    if (p != NULL) {
        infix(p->left);
        putchar(p->ope);
        infix(p->right);
    }
}

void postfix(struct tnode *p) { // 接尾形
    if (p != NULL) {
        postfix(p->left);
        postfix(p->right);
        putchar(p->ope);
    }
}

struct tnode *talloc(void) { // 記憶領域の取得
    return (struct tnode *)malloc(sizeof(struct tnode));
}
