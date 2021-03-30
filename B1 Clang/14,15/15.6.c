#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

typedef struct quake
{
    int year;
    int month;
    int day;
    double lat;
    double lon;
    char scale;
} Eq;
void printEq(Eq eq)
{
    printf("%d年,%d月,%d日,緯度:%lf,経度:%lf,震度:%c\n", eq.year, eq.month, eq.day, eq.lat, eq.lon, eq.scale);
}
// 年と月からその月の日数を得る関数
int modday(int month)//月毎に月末の日数が違うので関数定義
{
    int days = 0;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    case 2:
        days = 28;
        break;
    }
    return days;
}

int main(void)
{
    Eq list[10624];
    int num = 0;
    FILE *fp;
    char line[256];
    int monthday[13][33] = {0};
    double monthpow[13][33] = {0};
    int counter[13] = {0};
    int tmp = 0;
    double dock = 0;
    double average = 0.0;
    double bunsan = 0.0;
    double tempest = 0.0;
    int daycounter = 1;

    if ((fp = fopen("h2011_eq.csv", "r")) == NULL)
    {
        printf("file open error!!\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, 256, fp) != NULL)
    {
        //printf("%s", line);
        Eq eq;
        eq.year = atoi(strtok(line, ",\n"));
        eq.month = atoi(strtok(NULL, ",\n"));
        eq.day = atoi(strtok(NULL, ",\n"));
        eq.lat = atof(strtok(NULL, ",\n"));
        eq.lon = atof(strtok(NULL, ",\n"));
        eq.scale = strtok(NULL, ",\n")[0];
        list[num] = eq;
        num++;
    }
    fclose(fp);

    for (int i = 0; i < num; i++)
    {
        if (list[i].month == 1)
        {
            counter[0]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 2)
        {
            counter[1]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 3)
        {
            counter[2]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 4)
        {
            counter[3]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 5)
        {
            counter[4]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 6)
        {
            counter[5]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 7)
        {
            counter[6]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 8)
        {
            counter[7]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 9)
        {
            counter[8]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 10)
        {
            counter[9]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 11)
        {
            counter[10]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
        else if (list[i].month == 12)
        {
            counter[11]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                if (j == list[i].day)
                {
                    monthday[list[i].month][j]++;
                    dock++;
                }
            }
        }
    }

    for (int i = 0; i < 13; i++)
    {
        tmp = counter[i] + tmp;
        counter[i] = 0;
    }
    average = dock / 365;
    printf("総数:%d 平均:%f\n", tmp, average);
    /*
    for(int i=1;i<13;i++){
        printf("%d月",i);
        for(int j=1;j<32;j++){
            printf("%d日:",j);
            printf("%d\n",monthday[i][j]);
        }
    }

*/
    //-----------------------------------------
    for (int i = 0; i < num; i++)
    {
        if (list[i].month == 1)
        {
            counter[0]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 2)
        {
            counter[1]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {

                //tempest=monthday[list[i].month][j] - average;
                //printf("%d,%d   %f\n",list[i].month,j,tempest);
                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 3)
        {
            counter[2]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 4)
        {
            counter[3]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {

                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 5)
        {
            counter[4]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 6)
        {
            counter[5]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 7)
        {
            counter[6]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 8)
        {
            counter[7]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {

                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 9)
        {
            counter[8]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {

                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 10)
        {
            counter[9]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {

                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 11)
        {
            counter[10]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {

                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
        else if (list[i].month == 12)
        {
            counter[11]++;
            for (int j = 1; j <= modday(list[i].month); j++)
            {
                monthpow[list[i].month][j] = (pow(monthday[list[i].month][j] - average, 2.0));
            }
        }
    }
    //printf("1月:%d  2月:%d  3月:%d  4月:%d  5月:%d  6月:%d  \n7月:%d  8月:%d  9月:%d  10月:%d  11月:%d  12月:%d\n", counter[0], counter[1], counter[2], counter[3], counter[4], counter[5], counter[6], counter[7], counter[8], counter[9], counter[10], counter[11]);

    for (int i = 1; i < 13; i++)
    {
        for (int j = 1; j < 32; j++)
        {
            bunsan = monthpow[i][j] + bunsan;
            //printf("%d月%d日 %f\n", i, j, monthpow[i][j]);
            //printf("%f\n",bunsan);
            //printf("%f\n",sqrt(bunsan/num));
        }
    }
    printf("偏差:%f\n", sqrt(bunsan / num));
    return 0;
}