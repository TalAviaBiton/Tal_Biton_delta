/*------------------------------------------------------
* Filename: TalBiton_calc_age.c
* Description: recives the current date and yoyr b-day and prints your age
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#define DAYS_IN_MONTH 30
#define DAYS_IN_YEAR 365
int main() {
    int day=0, month=0, year=0, current_day=0, current_month=0, current_year=0, days=0;
    float months=0.0,years=0.0;

    printf("please enter your b-day\n");
    scanf("%d/%d/%d",&day,&month,&year);
    printf("please enter today's date\n");
    scanf("%d/%d/%d",&current_day,&current_month,&current_year);

    days=current_day-day+(current_month-month)*DAYS_IN_MONTH+(current_year-year)*DAYS_IN_YEAR;
    months=(float)days/DAYS_IN_MONTH;
    years=(float)days/DAYS_IN_YEAR;

    printf("your age in days:%d\nyour age in months:%f\nyour age in years:%f\n",days,months,years);
    
    return 0;
}