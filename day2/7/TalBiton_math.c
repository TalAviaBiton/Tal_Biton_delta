/*------------------------------------------------------
* Filename: TalBiton_math.c
* Description: operates some mathematical operations
* Author: Tal Aviya Biton
-------------------------------------------------------*/
#include <math.h>
#include <stdio.h>
int main() {
    float a=0.0, b=0.0, c=0.0, r1=0.0, r2=0.0, m=0.0, n=0.0, x=0.0, y=0.0, a1=0.0, d=0.0, k=0.0, ak=0.0;
    scanf("%f %f %f", &a,&b,&c);
    r1=(sqrt(b*b-4*a*c)-b)/(2*a);
    r2=(sqrt(b*b-4*a*c)+b)/(-2*a);
    scanf("%f %f ", &m,&n);
    x=-1*(n/m);
    y=n;
    scanf("%f %f %f",&a1 ,&d,&k);
    ak=a1+(k-1)*d;
    return 0;
}
