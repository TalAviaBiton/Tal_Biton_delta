/*------------------------------------------------------
* Filename: TalBiton_array_sort.c
* Description: sorts an array
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

#define LEN 10

void print_pointers(int* pointers[LEN]);
void swap(int **p1, int **p2);

int main() {
    int i=0, j=0, swapped=0;
    int input[LEN]={0};
    int *pointers[LEN];

    for(int index=0;index<LEN;index++){
        scanf("%d", &input[index]);
    }

    for(int index=0;index<LEN;index++){
        pointers[index]=&input[index];
    }

    print_pointers(pointers);

    for (i = 0; i < LEN - 1; i++) {
        swapped = 0;
        for (j = 0; j < LEN - i - 1; j++) {
            if (*pointers[j] > *pointers[j + 1]) {
                swap(&pointers[j], &pointers[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }

    print_pointers(pointers);

    return 0;
}

void print_pointers(int* pointers[LEN]){
    for(int index=0;index<LEN;index++){
        printf("%d,", *pointers[index]);
        printf("%x ", pointers[index]);

    }
    printf("\n");
}

void swap(int **p1, int **p2)
{
    int *tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}
