#include <stdio.h>

void indent(int);          // 들여쓰기 함수 선언
int tab = 0;               // 들여쓰기 깊이 추적용 전역 변수

double power(double x, int n) {
    indent(tab);
    printf("power(%.2f, %d)\n", x, n);

    if (n == 0) {
        indent(tab);
        printf("=> 1 (base case)\n");
        return 1.0;
    }

    ++tab;
    double result;
    if (n % 2 == 0) {
        result = power(x * x, n / 2);
    } else {
        result = x * power(x * x, (n - 1) / 2);
    }
    --tab;

    indent(tab);
    printf("=> %.2f\n", result);
    return result;
}

// 들여쓰기 함수
void indent(int t) {
    for (int i = 0; i < t; i++)
        printf("  ");  // 공백 두 칸씩 들여쓰기
}

// 메인 함수
int main() {
    double x;
    int n;

    printf("x 값을 입력하세요: ");
    scanf("%lf", &x);
    printf("n 값을 입력하세요: ");
    scanf("%d", &n);

    double result = power(x, n);
    printf("%.2f^%d = %.2f\n", x, n, result);

    return 0;
}