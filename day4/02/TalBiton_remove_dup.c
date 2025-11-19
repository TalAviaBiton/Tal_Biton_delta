/*------------------------------------------------------
* Filename: TalBiton_remove_dup.c
* Description: removes duplicates from a sorted array
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> 

int* remove_dup1(int arr[],int *size);//removes duplicate numbers
int  remove_dup2(int *arr,int size);//removes duplicate numbers
void remove_dup3(int *arr,int *size);//removes duplicate numbers
int* remove_dup4(int arr[],int size);//removes duplicate numbers
void print_arr(int *arr1, int size);//prints arr
int not_in_arr(int *arr, int num, int size);//checks if num in arr
void add_to_arr(int *arr, int num, int *size);//if num isnt in -adds num to arr

int main(){//only to check- not requierd
    int arr[14]={0,0,1,2,2,2,3,4,5,6,7,7,8,9};
    int *p=arr;
    int size=14;
    printf("1:\n");
    int *dynamic_arr=remove_dup1(arr,&size);
    printf("%d\n",size);
    size=14;
    arr[0]=0;arr[1]=0;arr[2]=1;arr[3]=2,arr[4]=2;arr[5]=2;arr[6]=3;arr[7]=4;arr[8]=5;arr[9]=6;arr[10]=7;arr[11]=7;arr[12]=8;arr[13]=9;
    printf("2:\n");
    size=remove_dup2(arr,size);
    printf("%d\n",size);
    size=14;
    arr[0]=0;arr[1]=0;arr[2]=1;arr[3]=2,arr[4]=2;arr[5]=2;arr[6]=3;arr[7]=4;arr[8]=5;arr[9]=6;arr[10]=7;arr[11]=7;arr[12]=8;arr[13]=9;
    printf("3:\n");
    remove_dup3(arr, &size);
    printf("%d\n",size);
    size=14;
    arr[0]=0;arr[1]=0;arr[2]=1;arr[3]=2,arr[4]=2;arr[5]=2;arr[6]=3;arr[7]=4;arr[8]=5;arr[9]=6;arr[10]=7;arr[11]=7;arr[12]=8;arr[13]=9;
    printf("4:\n");
    dynamic_arr=remove_dup4(arr,size);
    printf("%d\n",size);

    return 0;
}

int* remove_dup1(int arr[],int *size){
    int counter=0;
    int *dynamic_arr=(int *)malloc((sizeof(int))*(*size));
    for(int i=0;i<*size;i++){
        add_to_arr(dynamic_arr,arr[i],&counter);
    }

    print_arr(dynamic_arr, counter);
    print_arr(arr, *size);

    *size=counter;
    return dynamic_arr;
    free (dynamic_arr);

}

int remove_dup2(int *arr,int size){
    int counter=0;
    int *dynamic_arr=(int *)malloc((sizeof(int))*(size));
    for(int i=0;i<size;i++){
        add_to_arr(dynamic_arr,arr[i],&counter);
    }

    print_arr(dynamic_arr, counter);
    print_arr(arr, size);

    arr=dynamic_arr;
    free (dynamic_arr);
    return counter;
}

void remove_dup3(int *arr,int *size){
    int counter=0;
    int *dynamic_arr=(int *)malloc((sizeof(int))*(*size));
    for(int i=0;i<*size;i++){
        add_to_arr(dynamic_arr,arr[i],&counter);
    }

    print_arr(dynamic_arr, counter);
    print_arr(arr, *size);

    *size=counter;
    arr=dynamic_arr;
    free (dynamic_arr);

}

int* remove_dup4(int arr[],int size){
    int counter=0;
    int *dynamic_arr=(int *)malloc((sizeof(int))*(size));

    for(int i=0;i<size;i++){
        add_to_arr(dynamic_arr,arr[i],&counter);
    }

    print_arr(dynamic_arr, counter);
    print_arr(arr, size);

    return dynamic_arr;
    free (dynamic_arr);
}

void print_arr(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int not_in_arr(int *arr, int num, int size){
    for(int i=0;i<size;i++){
        if(*(arr+i)==num){
            return 0;
        }    
    }
    return 1;
}

void add_to_arr(int *arr, int num, int *size){
   if(not_in_arr(arr,num,*size)){
        (*size)++;
        arr=(int *)realloc(arr,(sizeof(int))*(*size));
        *(arr+(*size)-1)=num;
   }
}

