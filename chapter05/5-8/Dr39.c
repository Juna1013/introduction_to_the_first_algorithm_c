// 優先順位パーシング（直説法）
#include <stdio.h>
#define Max(a, b) ((a)>(b)?(a):(b))
#define Min(a, b) ((a)<(b)?(a):(b))

double v[50]; // 計算用スタック
char ope[50]; // 演算子用スタック
int pri[256]; // 優先順位テーブル
int sp1, sp2; // スタック・ポインタ

void calc(void);

int main(void) {
    const char *expression = "(1>2|2<8|3<4)|(9<2)", *p = expression;

    pri['|'] = 1; pri['<'] = pri['>'] = 2;
    pri['('] = 3; pri[')'] = 0;

    ope[0] = 0; pri[0] = -1;
    sp1 = sp2 = 0;
    while (*p != '\0') {
        if ('0' <= *p && *p <= '9') v[++sp2] = *p - '0';
        else {
            while (pri[*p] <= pri[ope[sp1]] && ope[sp1] != '(') {
                calc();
            }
            if (*p != '(') ope[++sp1] = *p;
            else sp1--;
        }
        p++;
    }
    while (sp1 > 0) calc();
    printf("%s = %f\n", expression, v[1]);

    return 0;
}

void calc(void) {
    switch(ope[sp1]) {
        case '|' : v[sp2-1]=(v[sp2-1]+v[sp2])/2; break;
        case '>' : v[sp2-1]=Max(v[sp2-1], v[sp2]); break;
        case '<' : v[sp2-1]=Min(v[sp2-1], v[sp2]); break;
    }
    sp2--; sp1--;
}
