#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
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
    Iris array_all[150];
    Iris array_learn[120];
    Iris array_test[30];
    FILE *fp;
    char str[1024];
    char *ptr;
    int i, k;
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
        array_all[i] = read_lst(str, i); //Irisデータをarray_all配列にすべて読みこむ
        num++;
    }

    i = num;
    while (i > 1)
    {
        Iris tmp;
        srand((unsigned int)time(NULL)); //これを抜ければ乱数の種を変更しなくなる
        int j = rand() % i;
        //printf("%d\n",j);
        i--;
        tmp = array_all[i];
        array_all[i] = array_all[j]; //配列をランダムにする
        array_all[j] = tmp;
    }

    printf("array_learn\n");
    for (i = 0; i < 120; i++) //そのうち4/5をarray_learnに入れる
    {
        array_learn[i] = array_all[i];
        printIris(array_learn[i]);
    }
    printf("\n\narray_test\n");
    for (i = 120, k = 0; i < num; i++, k++) //のこりの1/5をarray_testに入れる
    {
        array_test[k] = array_all[i];
        printIris(array_test[k]);
    }

    //ファイルを閉じる
    fclose(fp);
    return 0;
}