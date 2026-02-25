// 2分探索法
#include <stdio.h>

#define N 10

int main(void) {
    int a[] = {2, 3, 7, 11, 31, 50, 55, 70, 77, 80};
    int key, low, high, mid;

    printf("検索する data ? "); scanf("%d", &key);

    low = 0; high = N-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] <= key) low = mid + 1;
        if (a[mid] >= key) high = mid - 1;
    }
    if (low == high+2) printf("%d は %d 番目にありました\n", a[mid], mid);
    else printf("見つかりませんでした\n");

    return 0;
}
