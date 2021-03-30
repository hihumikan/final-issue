#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct iris
{
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
    char class[30];
} Iris;
Iris read_lst(char str[], int i)
{
    char *tp;
    Iris tmp;
    tp = strtok(str, ",");
    tmp.sepal_length = atof(tp);

    tp = strtok(NULL, ",");
    tmp.sepal_width = atof(tp);

    tp = strtok(NULL, ",");
    tmp.petal_length = atof(tp);

    tp = strtok(NULL, ",");
    tmp.petal_width = atof(tp);

    tp = strtok(NULL, ",\n");
    strcpy(tmp.class, tp);
    return tmp;
}
void printIris(Iris iris)
{
    printf("%lf,%lf,%lf,%lf,%s\n", iris.sepal_length, iris.sepal_width, iris.petal_length, iris.petal_width, iris.class);
}
void printClass(int i)
{
    if (i == 0)
    {
        printf("Iris-setosa\n");
    }
    else if (i == 1)
    {
        printf("Iris-versicolor\n");
    }
    else
    {
        printf("Iris-virginica\n");
    }
}
int main()
{
    //ファイル構造体へのポインタを宣言
    Iris list[150];
    Iris hns[150];
    FILE *fp;
    char str[1024];
    char *ptr;
    int i, k;
    double near[3][150] = {0.0}; //近いサンプル算出tmp
    double min;
    double sample1[4] = {5.7, 4.0, 1.2, 0.2}; //サンプル
    double sample2[4] = {5.9, 2.9, 4.2, 1.5};
    double sample3[4] = {5.6, 2.8, 4.8, 2.0};
    int num = 0;
    //iris.dataを読み込みモードで開く
    fp = fopen("iris.data", "r");
    //ファイルオープンに失敗したとき
    if (fp == NULL)
    {
        //失敗を表示し終了
        printf("ファイルオープン失敗\n");
        return -1;
    }
    //fgetsの戻り値がnullになるまで続ける
    //strにファイルからバイト取得し格納
    for (i = 0; fgets(str, 256, fp) != NULL; i++)
    {
        list[i] = read_lst(str, i);
        num++;
    }
    near[0][0] = sqrt(((pow(list[0].sepal_length - sample1[0], 2.0)) + (pow(list[0].sepal_width - sample1[1], 2.0)) + (pow(list[0].petal_length - sample1[2], 2.0)) + (pow(list[0].petal_width - sample1[3], 2.0))));
    min = near[0][0];
    for (i = 1, k = 0; i < num; i++) //150個全て計算し、一番近い最小値を算出x3
    {
        near[0][i] = sqrt(pow(list[i].sepal_length - sample1[0], 2.0) + pow(list[i].sepal_width - sample1[1], 2.0) + pow(list[i].petal_length - sample1[2], 2.0) + pow(list[i].petal_width - sample1[3], 2.0));
        //printf("%f\n",near[0][i]);
        if (near[0][i] < min)
        { // 最小値求める //
            min = near[0][i];
            k = i; //kに入ってるのが一番小さい
        }
    }
    printf("sample1 一番近いクラス%s\n", list[k].class);

    near[1][0] = sqrt(((pow(list[0].sepal_length - sample2[0], 2.0)) + (pow(list[0].sepal_width - sample2[1], 2.0)) + (pow(list[0].petal_length - sample2[2], 2.0)) + (pow(list[0].petal_width - sample2[3], 2.0))));
    min = near[1][0];
    for (i = 1, k = 0; i < num; i++)
    {
        near[1][i] = sqrt(pow(list[i].sepal_length - sample2[0], 2.0) + pow(list[i].sepal_width - sample2[1], 2.0) + pow(list[i].petal_length - sample2[2], 2.0) + pow(list[i].petal_width - sample2[3], 2.0));
        //printf("%f\n",near[1][i]);
        if (near[1][i] < min)
        { // 最小値求める //
            min = near[1][i];
            k = i;
        }
    }
    printf("sample2 一番近いクラス%s\n", list[k].class);

    near[2][0] = sqrt(((pow(list[0].sepal_length - sample3[0], 2.0)) + (pow(list[0].sepal_width - sample3[1], 2.0)) + (pow(list[0].petal_length - sample3[2], 2.0)) + (pow(list[0].petal_width - sample3[3], 2.0))));
    min = near[2][0];
    for (i = 1, k = 0; i < num; i++)
    {
        near[2][i] = sqrt(pow(list[i].sepal_length - sample3[0], 2.0) + pow(list[i].sepal_width - sample3[1], 2.0) + pow(list[i].petal_length - sample3[2], 2.0) + pow(list[i].petal_width - sample3[3], 2.0));
        //printf("%f\n",near[2][i]);
        if (near[2][i] < min)
        { // 最小値求める //
            min = near[2][i];
            k = i;
        }
    }
    printf("sample3 一番近いクラス%s\n", list[k].class);
    return 0;
}