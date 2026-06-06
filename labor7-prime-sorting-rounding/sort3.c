#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int *b, int *c) {
    int temp;

    
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(int argc, char *argv[]) {    
    if (argc != 4) {
        printf("usage: sort3 number number number\n");
        return 1;
    }  
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    sort(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);

    return 0;
}
