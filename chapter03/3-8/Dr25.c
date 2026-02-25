// ハッシュ
#include <stdio.h>
#include <string.h>

#define TableSize 1050
#define ModSize 1000

int hash(char *);

struct tel { // データ・テーブル
    char name[12];
    char telnum[12];
    int empty;
} dat[TableSize];

int main(void) {
    int n;
    char a[12], b[12];

    printf("名前 電話番号\n");
    while (scanf("%s %s", a, b) != EOF) {
        n = hash(a);                                    // Bug2修正: ハッシュ値を挿入位置の起点にする
        while (n < TableSize && dat[n].empty) n++;      // 空きスロットを線形探索
        if (n < TableSize) {
            strcpy(dat[n].name, a);
            strcpy(dat[n].telnum, b);
            dat[n].empty = 1;
        } else printf("表が一杯です\n");
    }

    rewind(stdin);
    printf("検索するデータを入力してください\n");
    while (scanf("%s", a) != EOF) {
        n = hash(a);
        while (n < TableSize && dat[n].empty && strcmp(a, dat[n].name) != 0) n++;  // Bug3修正: emptyチェック追加
        if (n < TableSize && dat[n].empty) printf("%15s%15s\n", dat[n].name, dat[n].telnum);  // Bug3修正
        else printf("データは見つかりませんでした\n");
    }

    return 0;
}

int hash(char *s) { // ハッシュ関数
    int n;

    n = strlen(s);
    return (s[0] - 'A' + (s[n/2 - 1] - 'A') * 26 + (s[n-2] - 'A') * 26 * 26)
    %ModSize;
}
