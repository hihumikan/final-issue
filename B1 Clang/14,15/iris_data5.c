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

int main()
{
    //ファイル構造体へのポインタを宣言
    Iris list[150];
    Iris hns[150];
    FILE *fp;
    char str[1024];
    char *ptr;
    int i;
    int counter[3] = {0};
    double tmp[3][4] = {0.0};
    double tmp2[3][4] = {0.0};
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

    for (i = 0; i < num; i++)
    {
        Iris iris = list[i];
        if (!strcmp(iris.class, "Iris-setosa"))
        { //if文で文字を比較し、該当のtmp（二次元配列に代入)
            //tmp[x][y] (xはクラス分別,yは特徴量)
            counter[0]++;
            tmp[0][0] += iris.sepal_length;
            tmp[0][1] += iris.sepal_width;
            tmp[0][2] += iris.petal_length;
            tmp[0][3] += iris.petal_width;
        }
        else if (!strcmp(iris.class, "Iris-versicolor"))
        {
            counter[1]++;
            tmp[1][0] += iris.sepal_length;
            tmp[1][1] += iris.sepal_width;
            tmp[1][2] += iris.petal_length;
            tmp[1][3] += iris.petal_width;
        }
        else
        {
            counter[2]++;
            tmp[2][0] += iris.sepal_length;
            tmp[2][1] += iris.sepal_width;
            tmp[2][2] += iris.petal_length;
            tmp[2][3] += iris.petal_width;
        }
    }
    //printf("-回数-\nIris-setosa:%d\nIris-versicolor:%d\nIris-virginica:%d\n", counter[0], counter[1], counter[2]);
    //counterで各クラスを計算し、それを平均として割る。この場合だと全て50になるが、とりあえずメタはしない事にする。
    tmp[0][0] = tmp[0][0] / counter[0];
    tmp[0][1] = tmp[0][1] / counter[0];
    tmp[0][2] = tmp[0][2] / counter[0];
    tmp[0][3] = tmp[0][3] / counter[0];
    //printf("Iris-setosa 平均:%f,%f,%f,%f\n", tmp[0][0], tmp[0][1], tmp[0][2], tmp[0][3]);
    tmp[1][0] = tmp[1][0] / counter[1];
    tmp[1][1] = tmp[1][1] / counter[1];
    tmp[1][2] = tmp[1][2] / counter[1];
    tmp[1][3] = tmp[1][3] / counter[1];
    //printf("Iris-versicolor 平均:%f,%f,%f,%f\n", tmp[1][0], tmp[1][1], tmp[1][2], tmp[1][3]);
    tmp[2][0] = tmp[2][0] / counter[2];
    tmp[2][1] = tmp[2][1] / counter[2];
    tmp[2][2] = tmp[2][2] / counter[2];
    tmp[2][3] = tmp[2][3] / counter[2];
    //printf("Iris-virginica 平均:%f,%f,%f,%f\n", tmp[2][0], tmp[2][1], tmp[2][2], tmp[2][3]);

    //ファイルを閉じる
    for (i = 0; i < 150; i++)
    {
        Iris iris = list[i];
        if (!strcmp(iris.class, "Iris-setosa")) //各データの値から平均を引き、偏差を求め、2乗し、2乗の合計をデータの総数で割る
        {
            hns[i].sepal_length = (pow(iris.sepal_length - tmp[0][0], 2.0));
            hns[i].sepal_width = (pow(iris.sepal_width - tmp[0][1], 2.0));
            hns[i].petal_length = (pow(iris.petal_length - tmp[0][2], 2.0));
            hns[i].petal_width = (pow(iris.petal_width - tmp[0][3], 2.0));
            tmp2[0][0] += hns[i].sepal_length;
            tmp2[0][1] += hns[i].sepal_width;
            tmp2[0][2] += hns[i].petal_length;
            tmp2[0][3] += hns[i].petal_width;
        }
        else if (!strcmp(iris.class, "Iris-versicolor"))
        {
            hns[i].sepal_length = (pow(iris.sepal_length - tmp[1][0], 2.0));
            hns[i].sepal_width = (pow(iris.sepal_width - tmp[1][1], 2.0));
            hns[i].petal_length = (pow(iris.petal_length - tmp[1][2], 2.0));
            hns[i].petal_width = (pow(iris.petal_width - tmp[1][3], 2.0));
            tmp2[1][0] += hns[i].sepal_length;
            tmp2[1][1] += hns[i].sepal_width;
            tmp2[1][2] += hns[i].petal_length;
            tmp2[1][3] += hns[i].petal_width;
        }
        else
        {
            hns[i].sepal_length = (pow(iris.sepal_length - tmp[2][0], 2.0));
            hns[i].sepal_width = (pow(iris.sepal_width - tmp[2][1], 2.0));
            hns[i].petal_length = (pow(iris.petal_length - tmp[2][2], 2.0));
            hns[i].petal_width = (pow(iris.petal_width - tmp[2][3], 2.0));
            tmp2[2][0] += hns[i].sepal_length;
            tmp2[2][1] += hns[i].sepal_width;
            tmp2[2][2] += hns[i].petal_length;
            tmp2[2][3] += hns[i].petal_width;
        }
    }
    tmp2[0][0] = sqrt(tmp2[0][0] / counter[0]);
    tmp2[0][1] = sqrt(tmp2[0][1] / counter[0]);
    tmp2[0][2] = sqrt(tmp2[0][2] / counter[0]);
    tmp2[0][3] = sqrt(tmp2[0][3] / counter[0]);
    //printf("Iris-setosa 偏差:%f,%f,%f,%f\n", tmp2[0][0], tmp2[0][1], tmp2[0][2], tmp2[0][3]);
    tmp2[1][0] = sqrt(tmp2[1][0] / counter[1]);
    tmp2[1][1] = sqrt(tmp2[1][1] / counter[1]);
    tmp2[1][2] = sqrt(tmp2[1][2] / counter[1]);
    tmp2[1][3] = sqrt(tmp2[1][3] / counter[1]);
    //printf("Iris-versicolor 偏差:%f,%f,%f,%f\n", tmp2[1][0], tmp2[1][1], tmp2[1][2], tmp2[1][3]);
    tmp2[2][0] = sqrt(tmp2[2][0] / counter[2]);
    tmp2[2][1] = sqrt(tmp2[2][1] / counter[2]);
    tmp2[2][2] = sqrt(tmp2[2][2] / counter[2]);
    tmp2[2][3] = sqrt(tmp2[2][3] / counter[2]);
    //printf("Iris-virginica 偏差:%f,%f,%f,%f\n", tmp2[2][0], tmp2[2][1], tmp2[2][2], tmp2[2][3]);

    printf("Iris-setosa(avg,sd)\n");
    printf("sepal_length: (%f,%f)\n sepal_width: (%f,%f)\n petal_length: (%f,%f)\n petal_width: (%f,%f)\n", tmp[0][0], tmp2[0][0], tmp[0][1], tmp2[0][1], tmp[0][2], tmp2[0][2], tmp[0][3], tmp2[0][3]);
    printf("Iris-versicolor(avg,sd)\n");
    printf("sepal_length: (%f,%f)\n sepal_width: (%f,%f)\n petal_length: (%f,%f)\n petal_width: (%f,%f)\n", tmp[1][0], tmp2[1][0], tmp[1][1], tmp2[1][1], tmp[1][2], tmp2[1][2], tmp[1][3], tmp2[1][3]);
    printf("Iris-virginica(avg,sd)\n");
    printf("sepal_length: (%f,%f)\n sepal_width: (%f,%f)\n petal_length: (%f,%f)\n petal_width: (%f,%f)\n", tmp[2][0], tmp2[2][0], tmp[2][1], tmp2[2][1], tmp[2][2], tmp2[2][2], tmp[2][3], tmp2[2][3]);
    fclose(fp);
    return 0;
}