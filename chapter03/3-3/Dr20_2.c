// 線形探索法（break版）
#include <stdio.h>
#include <string.h>

#define N 10

int main(void) {
    struct girl {
        char name[20];
        int age;
    } a[N+1] = {"Ann", 18, "Rolla", 19, "Nancy", 16, "Eluza", 17,
                "Juliet", 18, "Machilda", 20, "Emy", 15, "Candy", 16,
                "Ema", 17, "Mari", 18};
    char key[20];
    int i, flag = 0;

    printf("検索する data ? "); scanf("%s", key);

    for (i = 0; i < N; i++) {
        if (strcmp(key, a[i].name) == 0) {
            printf("%s %d\n", a[i].name, a[i].age);
            flag = 1;
            break;
        }
    }

    if (flag != 1) printf("見つかりませんでした\n");
    return 0;
}
