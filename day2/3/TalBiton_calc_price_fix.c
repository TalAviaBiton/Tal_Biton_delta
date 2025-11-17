/*------------------------------------------------------
* Filename: TalBiton_calc_price_fix.c
* Description: recives the length width and weight of a package and prints its size in cmr' weight and price of shipping
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#define SHEEPING_COST 5.5
#define KG_COST 11
#define PER_CMR_COST 0.03
#define SIZE_DIVIDED_BY_WEIGHT_COST 0.01
int main() {
    int length=0, width=0, weight=0;
    float size_cmr=0.0,price_nis=0.0, weight_kg=0.0;

    printf("please enter length width and weight\n");
    scanf("%d %d %d",&length,&width,&weight);
    
    size_cmr=(float)length*width/10;
    weight_kg=(float)weight/1000;
    price_nis=SHEEPING_COST+weight_kg*KG_COST+size_cmr*PER_CMR_COST+SIZE_DIVIDED_BY_WEIGHT_COST*(float)size_cmr/weight_kg;

    printf("size in cmr:%.2f\nweight in kg:%.3f\nprice(new israeli shekel):%.2f\n",size_cmr,(float)weight,price_nis);
    
    return 0;
}