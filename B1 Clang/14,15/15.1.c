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
}//動画そのままの処理

int main()
{
    char line[] = ("2011,1,1,36.657500,40.973500,3\n");
    Eq eq;
    eq.year = atoi(strtok(line, ",\n"));
    eq.month = atoi(strtok(NULL, ",\n"));
    eq.day = atoi(strtok(NULL, ",\n"));
    eq.lat = atof(strtok(NULL, ",\n"));
    eq.lon = atof(strtok(NULL, ",\n"));
    eq.scale = strtok(NULL, ",\n")[0];

    printEq(eq);
    return 0;
}
