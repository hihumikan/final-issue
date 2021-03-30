#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("%d,%d,%d,%lf,%lf,%c\n", eq.year, eq.month, eq.day, eq.lat, eq.lon, eq.scale);
}

int main(void)
{
    Eq list[10624];
    int num = 0;
    FILE *fp;
    FILE *new;
    char line[256];
    new = fopen("h2011_eq_0311.csv", "w");
    if (new == NULL)
    {                            // オープンに失敗した場合
        printf("cannot open\n"); // エラーメッセージを出して
        exit(1);                 // 異常終了
    }
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
        if (list[i].month == 3 && list[i].day == 11)
        {
            if (list[i].scale >= 52)
            {
                printEq(list[i]);
                fprintf(new, "%d,%d,%d,%lf,%lf,%c\n", list[i].year, list[i].month,list[i].day, list[i].lat, list[i].lon, list[i].scale);
            }//forで洗い流して、fprintfで3/11出力
        }
    }
    fclose(new);
    return 0;
}