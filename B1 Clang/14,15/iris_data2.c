#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct iris
{
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
    char class[30];
} Iris;
void printIris(Iris iris)
{
    printf("%lf,%lf,%lf,%lf,%s\n", iris.sepal_length, iris.sepal_width, iris.petal_length, iris.petal_width, iris.class);
}

int main()
{
    Iris test;
    char *tp;
    char line[] = ("5.7,2.9,4.2,1.3,Iris-versicolor\n"); //文字列を分割してiris構造体にセット
    tp = strtok(line, ",\n");
    //printf("%s\n", tp);
    test.sepal_length = atof(tp);

    tp = strtok(NULL, ",\n");
    //printf("%s\n", tp);
    test.sepal_width = atof(tp);

    tp = strtok(NULL, ",\n");
    //printf("%s\n", tp);
    test.petal_length = atof(tp);

    tp = strtok(NULL, ",\n");
    //printf("%s\n", tp);
    test.petal_width = atof(tp);

    tp = strtok(NULL, ",\n");
    //printf("%s\n", tp);
    strcpy(test.class, tp);
    printIris(test); //セットした構造体変数の内容を標準出力に表示
    return 0;
}