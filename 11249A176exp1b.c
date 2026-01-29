#include <stdio.h>
int fibonacciRecursive(int n);
int main() {
    int terms = 10;
    printf("Fibonacci Series (Recursive): ");
    for (int i = 0; i < terms; i++) {
        printf("%d, ", fibonacciRecursive(i));
    }
    printf("\n");
    return 0;
}
int fibonacciRecursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2));
}
