/*------------------------------------------------------
* Filename: TalBiton_num_sum.c
* Description: checks if the ends of a series equal to all other numbers in sum
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
int main() {
    int i=0, first=0,prev=0, last=0, sum=0;
    scanf("%d", &first);
    while(scanf("%d", &last)){
        sum+=prev;
        prev=last;
    }
    if(prev+first==sum){
            printf("the sum is equal\n");
    }
    else{
            printf("the sum is not equal\n");

    }
    return 0;
}

/*PS C:\Users\TAL\Documents\delta\C> gcc TalBiton_num_sum.c -o TalBiton_num_sum.exe
PS C:\Users\TAL\Documents\delta\C> ./TalBiton_num_sum.exe 
15 4 3 3 2 1 2 1 1*
the sum is equal
PS C:\Users\TAL\Documents\delta\C> ./TalBiton_num_sum.exe
123 -123 123 -123 123 -123*
the sum is equal
PS C:\Users\TAL\Documents\delta\C> ./TalBiton_num_sum.exe
244 -100 300 22 23 2 -6 3 0*
the sum is equal
PS C:\Users\TAL\Documents\delta\C> ./TalBiton_num_sum.exe
15 4 3 2 2 1 2 1 1*
the sum is not equal
PS C:\Users\TAL\Documents\delta\C> ./TalBiton_num_sum.exe
1 1 1 1 1 1 1 1 1 9*
the sum is not equal
PS C:\Users\TAL\Documents\delta\C>*/