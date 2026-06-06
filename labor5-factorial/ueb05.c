#include <stdio.h>

int berechneFakultaet(int n);

int main() {
    int n;
    printf(" geben Sie eine natürliche Zahl ein: ");
    scanf("%d", &n);

    int faktor = berechneFakultaet(n);

    printf("Die Fakultät von %d ist: %d\n", n, faktor);

    return 0;
}

int berechneFakultaet(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * berechneFakultaet(n - 1);
    }
}
