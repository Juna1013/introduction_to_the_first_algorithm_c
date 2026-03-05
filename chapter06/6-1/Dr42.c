// 2分探索木へのデータ追加
#include <stdio.h>
#include <string.h>

#define nil -1
#define MaxSize 100

struct tnode {
    int left; // 左部分木へのポインタ
    char name[12];
    int right; // 右部分木へのポインタ
};

int sp = 8; // ノードの格納現在位置
struct tnode a[MaxSize] = {{  1, "Machilda",   2},
                           {  2, "Candy"   ,   4},
                           {  5, "Rolla"   , nil},
                           {nil, "Ann"     , nil},
                           {  6, "Emy"     ,   7},
                           {nil, "Nancy"   , nil},
                           {nil, "Eluza"   , nil},
                           {nil, "Lisa"    , nil}};

int main(void) {
    char key[12];
    int p, old, i;

    printf("New Name --> "); scanf("%s", key);
    p = 0; // 木のサーチ
    while (p != nil) {
        old = p;
        if (strcmp(key, a[p].name) <= 0) p = a[p].left;
        else p = a[p].right;
    }

    a[sp].left = a[sp].right = nil; // 新しいノードの接続
    strcpy(a[sp].name, key);
    if (strcmp(key, a[old].name) <= 0) a[old].left = sp;
    else a[old].right = sp;
    sp++;

    for (i = 0; i < sp; i++) {
        printf("%4d%12s%4d\n", a[i].left, a[i].name, a[i].right);
    }

    return 0;
}
