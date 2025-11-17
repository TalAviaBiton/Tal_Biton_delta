/*------------------------------------------------------
* Filename: TalBiton_calc_price.c
* Description: recives the current date and yoyr b-day and prints your age
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#define SHEEPING_COST 5.5
#define KG_COST 11
#define PER_CMR_COST 3
#define SIZE_DIVIDED_BY_WEIGHT_COST 1
int main() {
    int length=0, width=0, weight=0;
    float size_cmr=0.0,price_nis=0.0;

    printf("please enter length width and weight\n");
    scanf("%d %d %d",&length,&width,&weight);
    
    size_cmr=(float)length*width/10;
    price_nis=SHEEPING_COST+weight*KG_COST+size_cmr*PER_CMR_COST+SIZE_DIVIDED_BY_WEIGHT_COST*(float)size_cmr/weight;

    printf("size in cmr:%.2f\nweight in kg:%.3f\nprice(new israeli shekel):%.2f\n",size_cmr,(float)weight,price_nis);
    
    return 0;
}