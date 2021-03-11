#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

typedef struct temp
{
    int year;         //年
    int month;        //月
    int day;          //日
    double rainall;   //降水量
    int rainflag;     //雨が降ったかどうか0,1
    double avetemp;   //平均気温
    double lighttime; //平均照度
    double avewet;    //湿度
    double avehpa;    //気圧
    double aveclo;    //雲量
} Tp;
void printTp(Tp tp)
{
    printf("%d,%d,%d,%f,%d,%f,%f,%f,%f,%f\n", tp.year, tp.month, tp.day, tp.rainall, tp.rainflag, tp.avetemp, tp.lighttime, tp.avewet, tp.avehpa, tp.aveclo);
}
int main(void)
{
    Tp list[1827];
    int num = 0;
    Tp array_test[1000];
    Tp array_learn[1500];
    double near[500][1500] = {0};
    double min[500] = {0};
    int i, k, flag;
    int count = {0};
    FILE *fp;
    FILE *new;
    char line[256];
    double ave[13];
    int tmp, dada, j = {0};
    int user, x, counterman[2] = {0};
    double tmp2, sum, ssss;
    double conp[2][2] = {0};
    double sample1[2] = {23, 60};
    if ((fp = fopen("datalint2.csv", "r")) == NULL)
    {
        printf("file open error!!\n");
        exit(EXIT_FAILURE);
    }
    new = fopen("rain.csv", "a");
    if (new == NULL)
    {                            // オープンに失敗した場合
        printf("cannot open\n"); // エラーメッセージを出して
        exit(1);                 // 異常終了
    }
    while (fgets(line, 256, fp) != NULL)
    {
        //printf("%s", line);
        Tp tp;
        tp.year = atoi(strtok(line, ",\n"));
        tp.month = atoi(strtok(NULL, ",\n"));
        tp.day = atoi(strtok(NULL, ",\n"));
        tp.rainall = atof(strtok(NULL, ",\n"));
        tp.avetemp = atof(strtok(NULL, ",\n"));
        tp.lighttime = atof(strtok(NULL, ",\n"));
        tp.avewet = atof(strtok(NULL, ",\n"));
        tp.avehpa = atof(strtok(NULL, ",\n"));
        tp.aveclo = atof(strtok(NULL, ",\n"));
        list[num] = tp;
        num++;
    }

    for (int i = 0; i < num; i++)
    {
        if (list[i].rainall >= 20)
        {
            list[i].rainflag = 1;
        }
        else if (list[i].rainall > 0)
        {
            list[i].rainflag = 1;
        }
        else
        {
            list[i].rainflag = 0;
        }
    }
    i = num;
    while (i > 1)
    {
        Tp tmp;
        srand((unsigned int)time(NULL)); //これを抜ければ乱数の種を変更しなくなる
        int j = rand() % i;
        //printf("%d\n",j);
        i--;
        tmp = list[i]; //これによってlist全体をランダムにする
        list[i] = list[j];
        list[j] = tmp;
    }

    for (i = 0; i < 366; i++)
    {
        array_test[i] = list[i]; //代入
    }
    for (i = 366, k = 0; i < num; i++, k++)
    {
        array_learn[k] = list[i];
    }

    for (k = 0; k < 366; k++)
    {
        near[k][0] = sqrt(((pow(array_test[k].avetemp - array_learn[0].avetemp, 2.0)) + (pow(array_test[k].avewet - array_learn[0].avewet, 2.0)) + (pow(array_test[k].lighttime - array_learn[0].lighttime, 2.0)) + (pow(array_test[k].avehpa - array_learn[0].avehpa, 2.0))));
        min[k] = near[k][0]; //最初だけ一番小さいと置いておく
                             //printf("%f,%d\n",min[k],k);
    }
    for (k = 0; k < 366; k++)
    {
        for (i = 1; i < 1462; i++)
        { //arraytestとlearnを１－NNし、小さければmin[k]とcount(learnの場所)をとっておき、終わったときに表示
            near[k][i] = sqrt(((pow(array_test[k].avetemp - array_learn[i].avetemp, 2.0)) + (pow(array_test[k].avewet - array_learn[i].avewet, 2.0)) + (pow(array_test[k].lighttime - array_learn[i].lighttime, 2.0)) + (pow(array_test[k].avehpa - array_learn[i].avehpa, 2.0))));
            if (near[k][i] < min[k])
            {
                min[k] = near[k][i];
                count = i;
            }
        }
        //printf("%d,%d\n",array_test[k].rainflag,array_learn[count].rainflag);
        if (array_test[k].rainflag == 0 && array_learn[count].rainflag == 0)
        {
            conp[0][0]++;
        }
        else if (array_test[k].rainflag == 0 && array_learn[count].rainflag == 1)
        {
            conp[0][1]++;
        }
        else if (array_test[k].rainflag == 1 && array_learn[count].rainflag == 0)
        {
            conp[1][0]++;
        }
        else if (array_test[k].rainflag == 1 && array_learn[count].rainflag == 1)
        {
            conp[1][1]++;
        }
        else
        {
            return 1;
        }
        //aaa(array_learn[count].rainflag);
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    for (int w = 0; w < 2; w++)
    {
        for (int q = 0; q < 2; q++)
        {
            conp[w][q] = 0;
        }
    }
    for (int w = 0; w < 500; w++)
    {
        for (int q = 0; q < 1500; q++)
        {
            near[w][q] = 0;
        }
    }
    for (int w = 0; w < 500; w++)
    {
        array_test[i] = list[0];
    }
    for (int w = 0; w < 1500; w++)
    {
        array_learn[i] = list[0];
    }
    user = 5;
    printf("1回目 \n");
    x = 0;
    count = 0;
    tmp2 = num / user;

    for (i = 0; i < round(tmp2); i++)
    {
        array_test[i] = list[i]; //代入
        counterman[0]++;
        count++;
    }
    for (i = round(tmp2), k = 0; i < num; i++, k++)
    {
        array_learn[k] = list[i]; //代入
        count++;
        counterman[1]++;
    }
    for (k = 0; k < round(tmp2); k++)
    {
        near[k][0] = sqrt(((pow(array_test[k].avetemp - array_learn[0].avetemp, 2.0)) + (pow(array_test[k].avewet - array_learn[0].avewet, 2.0)) + (pow(array_test[k].lighttime - array_learn[0].lighttime, 2.0)) + (pow(array_test[k].avehpa - array_learn[0].avehpa, 2.0))));
        min[k] = near[k][0]; //距離計算の初期化
    }

    for (k = 0; k < round(tmp2); k++)
    {
        for (i = 1; i < counterman[1]; i++)
        { //arraytestとlearnを１－NNし、小さければmin[k]とcount(learnの場所)をとっておき、終わったときに表示
            near[k][i] = sqrt(((pow(array_test[k].avetemp - array_learn[i].avetemp, 2.0)) + (pow(array_test[k].avewet - array_learn[i].avewet, 2.0)) + (pow(array_test[k].lighttime - array_learn[i].lighttime, 2.0)) + (pow(array_test[k].avehpa - array_learn[i].avehpa, 2.0))));
            if (near[k][i] < min[k])
            {
                min[k] = near[k][i];
                count = i;
            }
            //printf("%d\n",count);
        }
        //printf("%d,%d\n",array_test[k].rainflag,array_learn[count].rainflag);
        if (array_test[k].rainflag == 0 && array_learn[count].rainflag == 0)
        {
            conp[0][0]++;
        }
        else if (array_test[k].rainflag == 0 && array_learn[count].rainflag == 1)
        {
            conp[0][1]++;
        }
        else if (array_test[k].rainflag == 1 && array_learn[count].rainflag == 0)
        {
            conp[1][0]++;
        }
        else if (array_test[k].rainflag == 1 && array_learn[count].rainflag == 1)
        {
            conp[1][1]++;
        }
        else
        {
            return 1;
        }
        //aaa(array_learn[count].rainflag);
    }
    printf("正解割合 ボールドアウトの混同行列（2値分類の場合)\n");
    //fprintf(new, "%f,%f,%f,%f\n", (conp[0][0] / (conp[0][0] + conp[0][1])), conp[0][1] / (conp[0][0] + conp[0][1]), conp[1][0] / (conp[1][0] + conp[1][1]), (conp[1][1] / (conp[1][0] + conp[1][1])));
    printf("%f,%f\n%f,%f\n\n", (conp[0][0] / (conp[0][0] + conp[0][1])), conp[0][1] / (conp[0][0] + conp[0][1]), conp[1][0] / (conp[1][0] + conp[1][1]), (conp[1][1] / (conp[1][0] + conp[1][1])));

    fclose(fp);
    return 0;
}