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
    int counter[15] = {0};
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
    for (int i = 0; i < num; i++)//for文で全ての行.scale検索をかける
    {
        if (list[i].scale == 49)
        {
            counter[0]++;
        } else if(list[i].scale == 50){
            counter[1]++;
        } else if(list[i].scale == 51){
            counter[2]++;
        }else if(list[i].scale == 52){
            counter[3]++;
        }else if(list[i].scale == 53){
            counter[4]++;
        }else if(list[i].scale == 54){
            counter[5]++;
        }else if(list[i].scale == 55){
            counter[6]++;
        }else if(list[i].scale == 56){
            counter[7]++;
        }else if(list[i].scale == 57){
            counter[8]++;
        }else if(list[i].scale == 65){
            counter[9]++;
        }else if(list[i].scale == 66){
            counter[10]++;
        }else if(list[i].scale == 67){
            counter[11]++;
        }else if(list[i].scale == 68){
            counter[12]++;
        }else if(list[i].scale == 69){
            counter[13]++;
        }else if(list[i].scale == 70){
            counter[14]++;
        }
    }
    printf("1:%d,2:%d,3:%d,4:%d,5:%d,6:%d,7:%d,8:%d,9:%d\nA:%d,B:%d,C:%d,D:%d,E:%d,F:%d",counter[0],counter[1],counter[2],counter[3],counter[4],counter[5],counter[6],counter[7],counter[8],counter[9],counter[10],counter[11],counter[12],counter[13],counter[14]);
    //表示
    /*
    for (int i = 0; i < num; i++)
    {
        if((list[i].month == 3 && list[i].day >= 11) ||  list[i].month > 3){
            //if(!strcmp(&list[i].scale,"4")||!strcmp(&list[i].scale,"A")||!strcmp(&list[i].scale,"C")||!strcmp(&list[i].scale,"D")||(!strcmp(&list[i].scale,"A")==1)){
            if(list[i].scale >= 52){
                printEq(list[i]);
            }
        }
    }
    */
    return 0;
}