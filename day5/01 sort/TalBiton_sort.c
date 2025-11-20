/*------------------------------------------------------
* Filename: TalBiton_sort.c
* Description: recives 5 strings and prints them sorted by length and by alphabetical order safly
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 11//last space for '\0'
#define STRINGS 5

char* dyn_scanf(void);//input function
void swap(void **p1, void **p2);//swaps two numbers in the series
void bbl_sort(int size, void** arr, int (*compare)(char* str1, char* str2));//buble sort
int cmp_len(char* str1, char*str2);//compares the strings by their length
int cmp_val(char* str1, char*str2);//compares the strings by their alphabetical value

int main(){    
    void* strings[STRINGS];
    char*tmp;
    int (*cmp_pointer)(char* str1, char* str2);

    for(int i=1;i<STRINGS+1;i++){
        printf("enter string number %d:",i);
        tmp=dyn_scanf();
        strings[i-1]=tmp;
    }

    cmp_pointer=cmp_len;
    bbl_sort(STRINGS,strings,cmp_pointer);

    for(int i=0;i<STRINGS-1;i++){
        printf("%s,",strings[i]);
    }
    printf("%s\n",strings[STRINGS-1]);

    cmp_pointer=cmp_val;
    bbl_sort(STRINGS,strings,cmp_pointer);

    for(int i=0;i<STRINGS-1;i++){
        printf("%s,",strings[i]);
    }
    printf("%s\n",strings[STRINGS-1]);

    return 0;
}

int cmp_len(char* str1, char*str2){//compares the strings by their length
    if(strlen(str1)>strlen(str2)){
        return 1;
    }
    if(strlen(str1)<strlen(str2)){
        return 2;
    }
    return 0;//equal
}

int cmp_val(char* str1, char*str2){//compares the strings by their alphabetical value
    int len=strlen(str1), ret=0;
    if(strlen(str1)>strlen(str2)){
        len=strlen(str2);
        ret=1;
    }
    for(int i=0;i<len;i++){
        if(str1[i]>str2[i]){
            return 1;
        }
        if(str1[i]<str2[i]){
            return 2;
        }
    }
    if(strlen(str1)<strlen(str2)){
        ret=2;
    }
    return ret;

}

void bbl_sort(int size, void** arr, int (*compare)(char* str1, char* str2)){//buble sort
    int swapped=0;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if ((*compare)(*(arr+j), *(arr+j + 1))==1){
                swap((arr+j), (arr+j + 1));
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void swap(void **p1, void **p2)//swaps two arguments
{
    void *tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}

char* dyn_scanf(void){
    /*i assumed the string will be short so i decided to use getchar and recive the input char by char.
     for long input it is unefficient but for short input it saves the need to assign a buffer
     i prefer to realloc 8 times then to realloc twice and assign a 6 byte buffer, 
     also this method prevents the program from allocating space that will not be used. */

    int size=0, len=0,res=0;
    char* str=(char*)malloc(sizeof(char));
    *str='\0';
    do{
        size++;
        str=(char*)realloc(str,sizeof(char)*(size+1));
        *(str+size)='\0';
        *(str+size-1)=getchar();
    }while(*(str+size-1)!='\n' && size<10);

    /*if the input is longer then 10 characters, the program assigns a buffer and reads the input into it, 
    the reallocation is done by the length of the new input in the buffer and so as the concatenation
    this method prevents the program from allocating space that will not be used.*/
    if(*(str+size-1)!='\n'){
        char buff[BUFF_SIZE]="0123456789";//the last index is for \0
        while(*(str+size-1)!='\n'){
        fgets(buff, BUFF_SIZE, stdin);
        len=strlen(buff);
        str=(char*)realloc(str,sizeof(char)*(size+len+1));
        *(str+size+len)='\0';
        for (int i = 0; i < len; i++){
            *(str+size+i)=buff[i];
        }
        size+=len;
    }
    }
    
    *(str+strlen(str)-1)='\0';
    return str;
}