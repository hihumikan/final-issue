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
/* void printTp(Tp tp){
    printf("%d年,%d月,%d日,%d,%d,%d\n",tp.year,tp.month,tp.day,tp.maxtemp,tp.mintemp,tp.waterave);
} */
int main(void)
{
    Tp list[1827];
    int num = 0;
    Tp array_test[365];
    Tp array_learn[1462];
    int i, n;
    int q, w, e, r, t;
    FILE *fp;
    char line[256];
    double x, y;
    double sumX = {0};
    double sumY = {0};
    double sumX2 = {0};
    double sumY2 = {0};
    /* double aveX[13] = {0}, aveY[13] = {0};
    double hns2X[13] = {0}, hns2Y[13] = {0};
    double hns2ALLX = {0}, hns2ALLY = {0};
    double hnsdefaX[13] = {0}, hnsdefaY[13] = {0};
    double kyoubun[13]={0},tmp={0},soukankei={0}; */
    if ((fp = fopen("datalint2.csv", "r")) == NULL)
    {
        printf("file open error!!\n");
        exit(EXIT_FAILURE);
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

    printf("2015/1/14~2020/1/14\n");
    printf("Where do you want to start?\n");
    printf("year?: ");
    scanf("%d", &q);
    printf("month?: ");
    scanf("%d", &w); //年と月を聞く
    r = 2000;
    for (i = 0; i < num; i++) //場所を特定
    {
        if (list[i].year == q && list[i].month == w)
        {
            r = i;
        }
    }
    if (r == 2000)
    {
        printf("指定した範囲は見つからなかった。");
        return 1;
    }

    while (1)
    { //範囲を入力1以下なら入力し直し
        printf("範囲は?:");
        scanf("%d", &n);
        if (n < 2)
        {
            printf("nop\n");
            continue;
        }
        break;
    }
    for (i = r; i < r + n; i++)
    {
        x = list[i].day; //最小二乗法で直線を推定
        y = list[i].avetemp;
        sumX += x;
        sumY += y;
        sumX2 += x * x;
        sumY2 += x * y;
    }
    double d = sumX2 * n - sumX * sumX;
    double a = (sumY2 * n - sumX * sumY) / d;
    double b = (sumX2 * sumY - sumY2 * sumX) / d;
    printf("x=%d+1 y=%f\n", n, a * (n + 1) + b);
    printf("実際の次の日の気温  %f度\n", list[i + 1].avetemp);
    fclose(fp);
    return 0;
}