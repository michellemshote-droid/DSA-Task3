// Generate N terms of a Fibonacci series using recursion
#include <stdio.h>

void fibonacci(int n, int a, int b) {
    if (n == 0) {
        return;
    }

    printf("%d ", a);

    fibonacci(n - 1, b, a + b);
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");

    if (n > 0) {
        fibonacci(n, 0, 1);
    }

    printf("\n");

    return 0;
}
