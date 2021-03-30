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
    double near[30][120];
    FILE *fp;
    char str[1024];
    double min[30];
    char *ptr;
    int i, k, x, t;
    int count;
    double conmat[3][3] = {0};
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
    printf("array_allの分割数5 \n");
    user = 5; //５分割クロスバリデーションで評価
    printf("1回目 \n");
    x = 0; //--------------------初期化
    count = 0;
    tmp = num / user;

    for (i = 0; i < round(tmp); i++)
    {
        array_test[i] = array_all[i]; //代入
        //printIris(array_test[i]);
        count++;
    }

    for (i = round(tmp), k = 0; i < num; i++, k++)
    {
        array_learn[k] = array_all[i]; //代入
        count++;
    }

    for (k = 0; k < 30; k++)
    {
        near[k][0] = sqrt(((pow(array_test[k].sepal_length - array_learn[0].sepal_length, 2.0)) + (pow(array_test[k].sepal_width - array_learn[0].sepal_width, 2.0)) + (pow(array_test[k].petal_length - array_learn[0].petal_length, 2.0)) + (pow(array_test[k].petal_width - array_learn[0].petal_width, 2.0))));
        min[k] = near[k][0]; //距離計算の初期化
        //printf("%f,%d\n",min[k],k);
    }

    for (k = 0; k < 30; k++)
    {
        for (i = 1; i < 120; i++)
        {
            near[k][i] = sqrt(((pow(array_test[k].sepal_length - array_learn[i].sepal_length, 2.0)) + (pow(array_test[k].sepal_width - array_learn[i].sepal_width, 2.0)) + (pow(array_test[k].petal_length - array_learn[i].petal_length, 2.0)) + (pow(array_test[k].petal_width - array_learn[i].petal_width, 2.0))));
            if (near[k][i] < min[k])
            {
                min[k] = near[k][i];
                count = i; //全ての距離計算
            }
        }
        if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
        {
            conmat[0][0]++;
        }
        else if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
        {
            conmat[0][1]++;
        }
        else if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
        {
            conmat[0][2]++;
        }
        else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
        {
            conmat[1][0]++;
        }
        else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
        {
            conmat[1][1]++;
        }
        else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
        {
            conmat[1][2]++;
        }
        else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
        {
            conmat[2][0]++;
        }
        else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
        {
            conmat[2][1]++;
        }
        else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
        {
            conmat[2][2]++;
        }
        else
        {
            printf("どこにも行かなかった？？");
            return 1; //出来なかった場合は終了 1を返す
        }
    }
    printf("割合(パーセント省略)は\n"); //結果を混同行列で表示
    printf("%f, %f, %f\n%f, %f, %f\n%f, %f, %f\n", (conmat[0][0] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[0][1] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[0][2] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[1][0] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[1][1] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[1][2] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[2][0] / (conmat[2][0]+conmat[2][1]+conmat[2][2])) * 100, (conmat[2][1] / (conmat[2][0]+conmat[2][1]+conmat[2][2])) * 100, (conmat[2][2] / (conmat[2][0]+conmat[2][1]+conmat[2][2]) * 100));

    for (x = 1, flag = 0; x < user; x++)
    {
        //--------------------初期化
        count = 0;
        for (int w = 0; w < 3; w++)
        {
            for (int q = 0; q < 3; q++)
            {
                conmat[w][q] = 0;
            }
        }
        for (int w = 0; w < 30; w++)
        {
            for (int q = 0; q < 150; q++)
            {
                conmat[w][q] = 0;
                min[w] = 0;
                near[w][q] = 0;
            }
        }
        //---------------------
        printf("%d回目\n", x + 1);
        if (x != flag)
        {
            sum = tmp + sum; //sumにテストデータの開始位置を変更
            flag++;          //
        }
        for (i = 0, t = 0; i < round(sum); i++, t++) //0からテストデータ開始位置まで
        {
            array_learn[i] = array_all[i]; //代入
        }
        for (i = round(sum), k = 0; i < round(round(sum) + round(tmp)); i++, k++)
        {                                 //テストデータから学習データまで
            array_test[k] = array_all[i]; //代入
        }

        if (num <= round(round(sum) + round(tmp))) //学習データがなかったら
        {

            for (k = 0; k < 30; k++)
            {
                near[k][0] = sqrt(((pow(array_test[k].sepal_length - array_learn[0].sepal_length, 2.0)) + (pow(array_test[k].sepal_width - array_learn[0].sepal_width, 2.0)) + (pow(array_test[k].petal_length - array_learn[0].petal_length, 2.0)) + (pow(array_test[k].petal_width - array_learn[0].petal_width, 2.0))));
                min[k] = near[k][0]; //距離計算の初期化
                //printf("%f,%d\n",min[k],k);
            }
            for (k = 0; k < 30; k++)
            {
                for (i = 1; i < 120; i++)
                {
                    near[k][i] = sqrt(((pow(array_test[k].sepal_length - array_learn[i].sepal_length, 2.0)) + (pow(array_test[k].sepal_width - array_learn[i].sepal_width, 2.0)) + (pow(array_test[k].petal_length - array_learn[i].petal_length, 2.0)) + (pow(array_test[k].petal_width - array_learn[i].petal_width, 2.0))));
                    if (near[k][i] < min[k])
                    {
                        min[k] = near[k][i];
                        count = i; //距離計算
                    }
                }
                if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
                {
                    conmat[0][0]++; //カウントアップ
                }
                else if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
                {
                    conmat[0][1]++;
                }
                else if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
                {
                    conmat[0][2]++;
                }
                else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
                {
                    conmat[1][0]++;
                }
                else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
                {
                    conmat[1][1]++;
                }
                else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
                {
                    conmat[1][2]++;
                }
                else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
                {
                    conmat[2][0]++;
                }
                else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
                {
                    conmat[2][1]++;
                }
                else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
                {
                    conmat[2][2]++;
                }
                else
                {
                    printf("どこにも行かなかった？？");
                    return 1;
                }
            } //結果を混同行列で表示
            printf("割合(パーセント省略)は\n");
            printf("%f, %f, %f\n%f, %f, %f\n%f, %f, %f\n", (conmat[0][0] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[0][1] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[0][2] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[1][0] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[1][1] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[1][2] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[2][0] / (conmat[2][0]+conmat[2][1]+conmat[2][2])) * 100, (conmat[2][1] / (conmat[2][0]+conmat[2][1]+conmat[2][2])) * 100, (conmat[2][2] / (conmat[2][0]+conmat[2][1]+conmat[2][2]) * 100));
            printf("end\n");
            continue;
        }

        for (i = round(round(sum) + round(tmp)); i < num; i++, t++) //テストデータ開始 学習データを代入numの最後まで
        {
            array_learn[t] = array_all[i];
        }
        for (k = 0; k < 30; k++)
        {
            near[k][0] = sqrt(((pow(array_test[k].sepal_length - array_learn[0].sepal_length, 2.0)) + (pow(array_test[k].sepal_width - array_learn[0].sepal_width, 2.0)) + (pow(array_test[k].petal_length - array_learn[0].petal_length, 2.0)) + (pow(array_test[k].petal_width - array_learn[0].petal_width, 2.0))));
            min[k] = near[k][0]; //距離計算の初期化
            //printf("%f,%d\n",min[k],k);
        }
        for (k = 0; k < 30; k++)
        {
            for (i = 1,count=0; i < 120; i++)
            {
                near[k][i] = sqrt(((pow(array_test[k].sepal_length - array_learn[i].sepal_length, 2.0)) + (pow(array_test[k].sepal_width - array_learn[i].sepal_width, 2.0)) + (pow(array_test[k].petal_length - array_learn[i].petal_length, 2.0)) + (pow(array_test[k].petal_width - array_learn[i].petal_width, 2.0))));
                if (near[k][i] < min[k])
                {
                    min[k] = near[k][i];
                    count = i; //距離計算
                }
            }
            if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
            {
                conmat[0][0]++;
            }
            else if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
            {
                conmat[0][1]++;
            }
            else if (strcmp(ThreeClass0, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
            {
                conmat[0][2]++;
            }
            else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
            {
                conmat[1][0]++;
            }
            else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
            {
                conmat[1][1]++;
            }
            else if (strcmp(ThreeClass1, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
            {
                conmat[1][2]++;
            }
            else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass0, array_learn[count].class) == 0)
            {
                conmat[2][0]++;
            }
            else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass1, array_learn[count].class) == 0)
            {
                conmat[2][1]++;
            }
            else if (strcmp(ThreeClass2, array_test[k].class) == 0 && strcmp(ThreeClass2, array_learn[count].class) == 0)
            {
                conmat[2][2]++;
            }
            else
            {
                printf("どこにも行かなかった？？");
                return 1;
            }
        }
        printf("正解割合(パーセント省略)は\n"); //結果を混同行列で表示
        printf("%f, %f, %f\n%f, %f, %f\n%f, %f, %f\n", (conmat[0][0] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[0][1] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[0][2] / (conmat[0][0]+conmat[0][1]+conmat[0][2])) * 100, (conmat[1][0] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[1][1] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[1][2] / (conmat[1][0]+conmat[1][1]+conmat[1][2])) * 100, (conmat[2][0] / (conmat[2][0]+conmat[2][1]+conmat[2][2])) * 100, (conmat[2][1] / (conmat[2][0]+conmat[2][1]+conmat[2][2])) * 100, (conmat[2][2] / (conmat[2][0]+conmat[2][1]+conmat[2][2]) * 100));
    }
    fclose(fp);
    return 0;
}