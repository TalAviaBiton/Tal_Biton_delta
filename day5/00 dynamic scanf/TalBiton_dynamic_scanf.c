/*------------------------------------------------------
* Filename: TalBiton_dynamic_scanf.c
* Description: recives a string and prints it safly
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 11//last space for '\0'

char* dyn_scanf(void);

int main(){    
    printf("please enter a string and enter when your done\n");
    printf(dyn_scanf());
    return 0;
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
        char buff[SIZE]="0123456789";//the last index is for \0
        while(*(str+size-1)!='\n'){
        fgets(buff, SIZE, stdin);
        len=strlen(buff);
        str=(char*)realloc(str,sizeof(char)*(size+len+1));
        *(str+size+len)='\0';
        for (int i = 0; i < len; i++){
            *(str+size+i)=buff[i];
        }
        size+=len;
    }
    }
    
    
    return str;
}