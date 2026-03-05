// 2分探索木の配列表現
#include <stdio.h>
#include <string.h>

#define nil -1
#define MaxSize 100

struct tnode { // 左部分木へのポインタ
    int left;
    char name[12];
    int right; // 右部分木へのポインタ
};

int main(void) {
    struct tnode a[MaxSize] = {{  1, "Machilda",   2},
                               {  2, "Candy"   ,   4},
                               {  5, "Rolla"   , nil},
                               {nil, "Ann"     , nil},
                               {  6, "Emy"     ,   7},
                               {nil, "Nancy"   , nil},
                               {nil, "Eluza"   , nil},
                               {nil, "Lisa"    , nil}};
    char key[12];
    int p;

    printf("Search name --> "); scanf("%s", key);
    p = 0;
    while (p != nil) {
        if (strcmp(key, a[p].name) == 0) {
            printf("見つかりました\n");
            break;
        } else if (strcmp(key, a[p].name) < 0) {
            p = a[p].left; // 左部分木へ移動
        } else p = a[p].right; // 右部分木へ移動
    }

    return 0;
}
