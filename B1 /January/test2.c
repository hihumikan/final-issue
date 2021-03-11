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
    FILE *new;
    FILE *new2;
    FILE *new3;
    char line[256];
    double ave[13];
    double min = 0.0;
    double near[1827];
    double counter[20] = {0};
    double raincounter[20] = {0};
    double sample1[2] = {23, 60};
    if ((fp = fopen("datalint2.csv", "r")) == NULL) //入力先
    {
        printf("file open error!!\n");
        exit(EXIT_FAILURE);
    }
    new = fopen("tmp.csv", "w");
    if (new == NULL)
    {                            // オープンに失敗した場合
        printf("cannot open\n"); // エラーメッセージを出して
        exit(1);                 // 異常終了
    }
    new2 = fopen("light.csv", "w");
    if (new2 == NULL)
    {                            // オープンに失敗した場合
        printf("cannot open\n"); // エラーメッセージを出して
        exit(1);                 // 異常終了
    }
    new3 = fopen("wet.csv", "w");
    if (new3 == NULL)
    {                            // オープンに失敗した場合
        printf("cannot open\n"); // エラーメッセージを出して
        exit(1);                 // 異常終了
    }
    while (fgets(line, 256, fp) != NULL)
    {
        //printf("%s", line);
        Tp tp; //各配列にファイル内容代入
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

    for (int i = 0; i < num; i++) //雨が降ったかどうかのflag
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

    for (int i = 0; i < num; i++) //5度づつ小分けにしてカウント
    {
        if (list[i].avetemp <= 0)
        {
            counter[0]++;
            if (list[i].rainflag > 0)
            {
                raincounter[0]++; //雨が降ったならば
            }
        }
        else if (list[i].avetemp <= 5)
        {
            counter[1]++;
            if (list[i].rainflag > 0)
            {
                raincounter[1]++;
            }
        }
        else if (list[i].avetemp <= 10)
        {
            counter[2]++;
            if (list[i].rainflag > 0)
            {
                raincounter[2]++;
            }
        }
        else if (list[i].avetemp <= 15)
        {
            counter[3]++;
            if (list[i].rainflag > 0)
            {
                raincounter[3]++;
            }
        }
        else if (list[i].avetemp <= 20)
        {
            counter[4]++;
            if (list[i].rainflag > 0)
            {
                raincounter[4]++;
            }
        }
        else if (list[i].avetemp <= 25)
        {
            counter[5]++;
            if (list[i].rainflag > 0)
            {
                raincounter[5]++;
            }
        }
        else if (list[i].avetemp <= 30)
        {
            counter[6]++;
            if (list[i].rainflag > 0)
            {
                raincounter[6]++;
            }
        }
        else if (list[i].avetemp <= 35)
        {
            counter[7]++;
            if (list[i].rainflag > 0)
            {
                raincounter[7]++;
            }
        }
        else
        {
            counter[8]++;
            if (list[i].rainflag > 0)
            {
                raincounter[8]++;
            }
        }
    }
    printf("気温による雨確率\n");
    for (int i = 0, k = 0; i < 8; i++, k += 5)
    { //雨が降った確率出力
        printf("%d度以下 元の数:%d,雨の数:%d,\n", k, (int)counter[i], (int)raincounter[i]);
        fprintf(new, "%d,%d,%d,%f\n", k, (int)counter[i], (int)raincounter[i], ((raincounter[i] / counter[i]) * 100.0));
    }
    //以下同じ様な処理
    for (int i = 0; i < 20; i++)
    {
        counter[i] = 0;
        raincounter[i] = 0;
    }

    for (int i = 0; i < num; i++)
    {
        if (list[i].lighttime <= 0)
        {
            counter[0]++;
            if (list[i].rainflag > 0)
            {
                raincounter[0]++;
            }
        }
        else if (list[i].lighttime <= 2)
        {
            counter[1]++;
            if (list[i].rainflag > 0)
            {
                raincounter[1]++;
            }
        }
        else if (list[i].lighttime <= 4)
        {
            counter[2]++;
            if (list[i].rainflag > 0)
            {
                raincounter[2]++;
            }
        }
        else if (list[i].lighttime <= 6)
        {
            counter[3]++;
            if (list[i].rainflag > 0)
            {
                raincounter[3]++;
            }
        }
        else if (list[i].lighttime <= 8)
        {
            counter[4]++;
            if (list[i].rainflag > 0)
            {
                raincounter[4]++;
            }
        }
        else if (list[i].lighttime <= 10)
        {
            counter[5]++;
            if (list[i].rainflag > 0)
            {
                raincounter[5]++;
            }
        }
        else if (list[i].lighttime <= 12)
        {
            counter[6]++;
            if (list[i].rainflag > 0)
            {
                raincounter[6]++;
            }
        }
        else if (list[i].lighttime <= 14)
        {
            counter[7]++;
            if (list[i].rainflag > 0)
            {
                raincounter[7]++;
            }
        }
        else
        {
            counter[8]++;
            if (list[i].rainflag > 0)
            {
                raincounter[8]++;
            }
        }
    }
    printf("\n\n");
    printf("日照時間による雨確率\n");
    for (int i = 0, k = 0; i < 9; i++, k += 2)
    {
        printf("%dh 元の数:%d,雨の数:%d\n", k, (int)counter[i], (int)raincounter[i]);
        fprintf(new2, "%d,%d,%d,%f\n", k, (int)counter[i], (int)raincounter[i], ((raincounter[i] / counter[i]) * 100.0));
    }

    for (int i = 0; i < 20; i++)
    {
        counter[i] = 0;
        raincounter[i] = 0;
    }
    for (int i = 0; i < num; i++)
    {
        if (list[i].avewet <= 0)
        {
            counter[0]++;
            if (list[i].rainflag > 0)
            {
                raincounter[0]++;
            }
        }
        else if (list[i].avewet <= 10)
        {
            counter[1]++;
            if (list[i].rainflag > 0)
            {
                raincounter[1]++;
            }
        }
        else if (list[i].avewet <= 20)
        {
            counter[2]++;
            if (list[i].rainflag > 0)
            {
                raincounter[2]++;
            }
        }
        else if (list[i].avewet <= 30)
        {
            counter[3]++;
            if (list[i].rainflag > 0)
            {
                raincounter[3]++;
            }
        }
        else if (list[i].avewet <= 40)
        {
            counter[4]++;
            if (list[i].rainflag > 0)
            {
                raincounter[4]++;
            }
        }
        else if (list[i].avewet <= 50)
        {
            counter[5]++;
            if (list[i].rainflag > 0)
            {
                raincounter[5]++;
            }
        }
        else if (list[i].avewet <= 60)
        {
            counter[6]++;
            if (list[i].rainflag > 0)
            {
                raincounter[6]++;
            }
        }
        else if (list[i].avewet <= 70)
        {
            counter[7]++;
            if (list[i].rainflag > 0)
            {
                raincounter[7]++;
            }
        }
        else if (list[i].avewet <= 80)
        {
            counter[8]++;
            if (list[i].rainflag > 0)
            {
                raincounter[8]++;
            }
        }
        else if (list[i].avewet <= 90)
        {
            counter[9]++;
            if (list[i].rainflag > 0)
            {
                raincounter[9]++;
            }
        }
        else
        {
            counter[10]++;
            if (list[i].rainflag > 0)
            {
                raincounter[10]++;
            }
        }
    }
    printf("\n\n");
    printf("湿度による雨確率\n");
    for (int i = 0, k = 0; i < 11; i++, k += 10)
    {
        printf("%d%% 元の数:%d,雨の数:%d\n", k, (int)counter[i], (int)raincounter[i]);
        fprintf(new3, "%d,%d,%d,%f\n", k, (int)counter[i], (int)raincounter[i], ((raincounter[i] / counter[i]) * 100.0));
    }

    fclose(fp); //ファイル閉じる
    fclose(new);
    fclose(new2);
    fclose(new3);
    return 0;
}