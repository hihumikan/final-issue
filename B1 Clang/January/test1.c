#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int i, k;
    FILE *fp;
    char line[256];
    double ave[13];
    double min = 0.0;
    double near[1827];
    double sample1[2] = {23, 60};
    if ((fp = fopen("datalint2.csv", "r")) == NULL)
    {
        printf("file open error!!\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, 256, fp) != NULL)
    {
        //printf("%s", line);
        Tp tp; //入力したデータ代入
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

    for (int i = 0; i < num; i++) //雨が降ったかどうか判定
    {
        if (list[i].rainall >= 20)
        {
            list[i].rainflag = 2;
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
    printf("温度と湿度？\n");
    scanf("%lf", &sample1[0]); //年月日求めるための湿度と温度を入力
    scanf("%lf", &sample1[1]);
    near[0] = sqrt(pow(list[0].avetemp - sample1[0], 2.0) + (pow(list[0].avewet - sample1[1], 2.0)));
    min = near[0];
    for (i = 1, k = 0; i < num; i++) //全て計算し、一番近い最小値を算出
    {
        near[i] = sqrt(pow(list[i].avetemp - sample1[0], 2.0) + (pow(list[i].avewet - sample1[1], 2.0)));
        //printf("%f\n",near[0][i]);
        if (near[i] < min)
        { // 最小値求める //
            min = near[i];
            k = i; //kに入ってるのが一番小さい
        }
    }
    printf("指定した温度,湿度から %d年 %d月 %d日が一番近いと推測できます.\n", list[k].year,
           list[k].month, list[k].day);
    if (list[k].rainflag == 2)
    {
        printf("その日は20mm以上の雨が降っています\n");
    }
    else if (list[k].rainflag == 1)
    {
        printf("その日は0mm以上20mm以下の雨が降っています\n");
    }
    else
    {
        printf("その日は雨が降ってません\n");
    }
    /* for(int i=0;i<num;i++){
        printTp(list[i]);
    } */

    fclose(fp);
    return 0;
}