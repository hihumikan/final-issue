#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
int main()
{
    //ファイル構造体へのポインタを宣言
    Iris array_all[150];
    Iris array_learn[120];
    Iris array_test[30];
    FILE *fp;
    char str[1024];
    char *ptr;
    int i, k, x, t;
    int count;
    int conmat[3][3] = {0};
    char ThreeClass0[] = "Iris-setosa";
    char ThreeClass1[] = "Iris-versicolor";
    char ThreeClass2[] = "Iris-virginica";
    int user = 0, num = 0;
    double tmp = 0, sum = 0;
    int flag;
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
        array_all[i] = read_lst(str, i);
        num++;
    }
    //printf("%d", num);
    i = num;
    while (i > 1)
    {
        Iris tmp;
        srand((unsigned int)time(NULL)); //これを抜ければ乱数の種を変更しなくなる
        int j = rand() % i;
        //printf("%d\n",j);
        i--;
        tmp = array_all[i];
        array_all[i] = array_all[j];
        array_all[j] = tmp;
    }
    printf("array_allの分割数n(int型)を数字で指定してください:");
    scanf("%d", &user); //入力
    printf("1回目 \n");
    x = 0;            //userまでのカウント
    count = 0;        //デバッグ
    tmp = num / user; //総数から入力した分割数で割る

    for (i = 0; i < round(tmp); i++)
    {
        array_test[i] = array_all[i]; //代入
        printIris(array_test[i]);
        count++; //デバッグ
    }
    printf("\n\n");
    printf("%d\n", count); //デバッグ
    for (i = round(tmp), k = 0; i < num; i++, k++)
    {
        array_learn[k] = array_all[i];
        printIris(array_learn[k]); //表示
        count++;                   //デバッグ
    }
    printf("\n\n");
    printf("%d\n", count);
    //numは全部の数 tmpは割った数 sumは割った数から回数分足すやつ
    for (x = 1, flag = 0; x < user; x++)
    {
        count = 0;
        printf("%d回目\n", x + 1);
        if (x != flag)
        {
            sum = tmp + sum;
            flag++; //足されてるかどうかのflag sumでテストデータの開始位置を表す
        }
        for (i = 0, t = 0; i < round(sum); i++, t++)
        {
            array_learn[i] = array_all[i]; //代入
        }
        for (i = round(sum), k = 0; i < round(round(sum) + round(tmp)); i++, k++)
        {
            array_test[k] = array_all[i]; //代入
        }

        if (num <= round(round(sum) + round(tmp))) //learnとtest代入した後、またlearnに代入するかどうかのif文
        {
            for (int g = 0; g < round(tmp); g++)
            {
                printIris(array_test[g]);
                count++;
            }
            printf("\n\n");
            printf("%d\n", count); //デバック用
            for (int g = 0; g < num - round(tmp); g++)
            {
                printIris(array_learn[g]);
                count++;
            }
            printf("\n\n");
            printf("%d\n", count); //デバック用
            printf("end\n");
            continue;
        }

        for (i = round(round(sum) + round(tmp)); i < num; i++, t++)
        {
            array_learn[t] = array_all[i]; //testデータ後のlearnのあまり代入
        }
        for (int g = 0; g < round(tmp); g++)
        {
            printIris(array_test[g]); //表示
            count++;                  //デバッグ
        }
        printf("\n\n");
        printf("%d\n", count);
        for (int g = 0; g < num - round(tmp); g++)
        {
            printIris(array_learn[g]); //表示
            count++;
        }
        printf("\n\n");
        printf("%d\n", count); //デバッグ
    }
    fclose(fp);
    return 0;
}