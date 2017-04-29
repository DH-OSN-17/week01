#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>

int ex1() {
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("sizeof(i) = %lu, value = %i\n", sizeof(i), i);
    printf("sizeof(f) = %lu, value = %f\n", sizeof(f), f);
    printf("sizeof(d) = %lu, value = %lf\n", sizeof(d), d);

    return 0;
}

int ex2() {
    char buffer[256] = {0};

    fgets(buffer, 256, stdin);

    size_t len = strlen(buffer);
    for(size_t i = 0; i * i < len; i++) {
        char tmp = buffer[i];
        buffer[i] = buffer[len-1-i];
        buffer[len-1-i] = tmp;
    }

    printf("%s\n", buffer);

    return 0;
}

int ex3(int argc, char* argv[]) {
    if(argc != 2) {
        perror("Please enter exactly 1 argument");
    }

    int heigth = atoi(argv[1]);
    int width = 2 * heigth - 1;
    int margin = width / 2;
    int stars = 1;

    while(heigth--) {
        for(int i = 0; i < margin; i++) {
            printf(" ");
        }

        for(int i = 0; i < stars; i++) {
            printf("*");
        }

        printf("\n");
        margin--;
        stars += 2;
    }

    return 0;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int ex4() {
    int a, b;
    scanf("%i %i", &a, &b);
    swap(&a, &b);
    printf("%i %i\n", a, b);
    return 0;
}

int main(int argc, char *argv[]) {
    return ex4();
}
