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

int main()
{
    //ファイル構造体へのポインタを宣言
    Iris list[150]; //構造体の配列を用意
    FILE *fp;
    char str[1024];
    char *ptr;
    int i;
    int num = 0;
    fp = fopen("iris.data", "r"); //Irisデータセットのファイル(iris.data)を読み込み
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
        list[i] = read_lst(str, i); //すべてのデータを構造体の配列に格納
        num++;
    }

    for (i = 0; i < num; i++)
    {
        printIris(list[i]); //配列内の要素の内容をすべて標準出力に表示
    }
    //ファイルを閉じる
    fclose(fp);
    return 0;
}