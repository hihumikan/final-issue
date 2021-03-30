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
    printf("%d年,%d月,%d日,緯度:%lf,経度:%lf,震度:%c\n", eq.year, eq.month, eq.day, eq.lat, eq.lon, eq.scale);
}

int main(void)
{
    Eq list[10624];
    int num = 0;
    FILE *fp;
    char line[256];
    if ((fp = fopen("h2011_eq.csv", "r")) == NULL)
    {
        printf("file open error!!\n");
        exit(EXIT_FAILURE);//動画そのままの処理
    }
    while (fgets(line, 256, fp) != NULL)
    {
        printf("%s", line);
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
        printEq(list[i]);
    }
    return 0;
}