// ハッシュ
#include <stdio.h>
#include <string.h>

#define TableSize 1000
#define ModSize 1000

int hash(char *);

struct tel {
    char name[20];
    char telnum[20];
} dat[TableSize];

int main(void) {
    int n;
    char a[20], b[20];

    printf("名前 電話番号\n");
    while (scanf("%s %s", a, b) != EOF) {
        n = hash(a);
        strcpy(dat[n].name, a);
        strcpy(dat[n].telnum, b);
    }

    rewind(stdin);
    printf("検索するデータを入力してください\n");
    while (scanf("%s", a) != EOF) {
        n = hash(a);
        printf("%15s%15s\n", dat[n].name, dat[n].telnum);
    }
}

int hash(char *s) {
    int n;

    n = (int)strlen(s);

    if (n < 2) {
        return (unsigned char)s[0] % ModSize;
    }

    return ((unsigned char)s[0]
          + (unsigned char)s[n/2 - 1] * 26
          + (unsigned char)s[n-2]     * 26 * 26)
          % ModSize;
}
