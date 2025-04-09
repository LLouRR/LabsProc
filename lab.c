#include <stdio.h>
#include <math.h>
#include "lab.h"
#define pi 3.14
#define YES 1
#define NO 0
#define MAXLINE 1000

void laba1() {
    float A, B, C, P;
    printf("A=");
    scanf("%f", &A);
    printf("B=");
    scanf("%f", &B);
    printf("C=");
    scanf("%f", &C);
    P = ((A + B * B) / (C - A));
    printf("%f\n", P);
}

void laba2() {
    double E;
    printf("Введите значение E: ");
    scanf("%lf", &E);
    double sum = 0.0;
    int n = 1;
    double sign = 1.0;
    double term;

    while (1) {
        term = sign * (n + 2.0) / (3.0 * n - 2.0); // Исправлено деление
        if (fabs(term) <= E) {
            break;
        }
        sum += term;
        sign *= -1;
        n++;
    }
    printf("Сумма ряда: %.6lf\n", sum);
}

static int to_lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

void laba3() {
    int c;
    int flag = NO;
    int cnt = 0;
    int first_char;
    int last_char;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '.' || c == '\n' || c == ',' || c == '\t' || c == '!' || c == '?') {
            if (flag == YES) {
                if (first_char == last_char) {
                    cnt++;
                }
            }
            flag = NO;
        } else {
            c = to_lower(c);
            if (flag == NO) {
                first_char = c;
                last_char = c;
                flag = YES;
            } else {
                last_char = c;
            }
        }
    }

    if (flag == YES && first_char == last_char) {
        cnt++;
    }

    printf("Number of words: %d\n", cnt);
}

static void process_line(char buffer[]) {
    char c;
    int flag = NO;
    int delete_next = NO;
    int i = 0, pos = 0, start;

    while ((c = buffer[i]) != '\0') {
        if (c == ' ' || c == ',' || c == '.' || c == '\n' || c == '\t') {
            if (flag == YES) {
                if (!delete_next) {
                    for (int j = start; j < i; j++) {
                        buffer[pos++] = buffer[j];
                    }
                } else {
                    delete_next = NO;
                }
                flag = NO;
            }
            buffer[pos++] = c;
            if (c == ',') {
                delete_next = YES;
            }
        } else {
            if (flag == NO) {
                start = i;
                flag = YES;
            }
        }
        i++;
    }

    if (flag == YES && !delete_next) {
        for (int j = start; j < i; j++) {
            buffer[pos++] = buffer[j];
        }
    }

    buffer[pos] = '\0';
}

void laba4() {
    char line[MAXLINE];
    fgets(line, MAXLINE, stdin);
    process_line(line);
    puts(line);
}