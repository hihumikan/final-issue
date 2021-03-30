#include <stdio.h>
#include <string.h>
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

    Iris iris1 = {6.7, 3.0, 5.2, 2.3, "Iris-virginica"}; //２つの変数 iris1, iris2 を以下の設定で初期化
    Iris iris2 = {7.0, 3.2, 4.7, 1.4, "Iris-versicolor"};
    printIris(iris1); //作成した構造体変数の内容を標準出力に
    printIris(iris2);
    return 0;
}