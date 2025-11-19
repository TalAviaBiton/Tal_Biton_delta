/*------------------------------------------------------
* Filename: TalBiton_dynamic_struct_fix.c
* Description: recives 2 clocks and adds them
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

struct Clock
{
    int hour;//0-23
    int minuts;//0-59
    int seconds;//0-59
};

struct Clock* add_clocks(struct Clock clock1, struct Clock clock2);//operator +for struct clock: clock1+clock2

int main(){
    char dots=':';
    struct Clock *clock1=(struct Clock*) malloc(sizeof(struct Clock));
    struct Clock *clock2=(struct Clock*) malloc(sizeof(struct Clock));

    printf("clock format is 00:00:00\n");
    printf("please enter the first clock:\n");
    scanf("%d %c %d %c %d",&(clock1->hour),&dots,&(clock1->minuts),&dots,&(clock1->seconds));
    while(clock1->hour>23||clock1->hour<0||clock1->minuts>59||clock1->minuts<0||clock1->seconds>59||
            clock1->seconds<0){
        printf("please enter the first clock again:\n");
        scanf("%d %c %d %c %d",&(clock1->hour),&dots,&(clock1->minuts),&dots,&(clock1->seconds));

    }
    printf("please enter the second clock:\n");
    scanf("%d %c %d %c %d",&(clock2->hour),&dots,&(clock2->minuts),&dots,&(clock2->seconds));
    while(clock2->hour>23||clock2->hour<0||clock2->minuts>59||clock2->minuts<0||clock2->seconds>59||
            clock2->seconds<0){
        printf("please enter the second clock again:\n");
        scanf("%d %c %d %c %d",&(clock2->hour),&dots,&(clock2->minuts),&dots,&(clock2->seconds));
    }

    clock1= add_clocks(*clock1, *clock2);//clock1+=clock2

    printf("added clocks:\n");
    printf("%d:%d:%d",(clock1->hour),(clock1->minuts),(clock1->seconds));

    
    free(clock1);
    free(clock2);
    return 0;
}


struct Clock* add_clocks(struct Clock clock1, struct Clock clock2){
    struct Clock *clock3=(struct Clock*) malloc(sizeof(struct Clock));
    int days=0;

    clock3->seconds=clock1.seconds+clock2.seconds;
    while(clock3->seconds>59){
        clock3->minuts++;
        clock3->seconds-=60;
    }
    clock3->minuts=clock1.minuts+clock2.minuts;
    while(clock3->minuts>59){
        clock3->hour++;
        clock3->minuts-=60;
    }
    clock3->hour=clock1.hour+clock2.hour;
    while(clock3->hour>23){
        days++;
        clock3->hour-=24;
    }

    return clock3;
}