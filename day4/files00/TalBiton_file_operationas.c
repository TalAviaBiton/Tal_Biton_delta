/*------------------------------------------------------
* Filename: TalBiton_file_operationas.c
* Description: operations on files
* Author: Tal Aviya Biton
-------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char* print_file_contents(const char *file_name) {//recives a file and prints it and returns it as string
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("error ant open file\n");
        return NULL;
    }
    int index=0;
    char *txt;
    txt=(char*)malloc(sizeof(char));
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
        for(int i=0;i<128;i++){
            txt[index]=buffer[i];
            index++;
        }
    }
    return txt;

    fclose(fp);

}

void write_to_file(const char* file_name, const char* text) {//recives a file and text and writs the txt to the file
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        perror("error cant open file to w");
        return;
    }
    if(text){
        fprintf(fp, "%s", text);
    }
    fclose(fp);
}

void copy_file_f(const char* file_name1, const char* file_name2){//recives 2 files and text and writs the second one to the first and prints the file
    write_to_file(file_name2,print_file_contents(file_name1));
}

void count_file_fast(const char* file_name) {//counts the words lines and letters in a file
    int lines=0;
    int words=0;
    int chars=0;
    FILE *fp = fopen(file_name, "r");
     if (fp == NULL) {
        printf("error cant open file\n");
        return;
    }
    char buffer[8192];
    int in_word = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        int len = strlen(buffer);
        chars += len;

        for (int i = 0; i < len; i++) {
            char ch = buffer[i];

            if (ch == '\n') {
                lines++;
                if (in_word) {
                     words++; in_word = 0; 
                    }
            }
            else if (isspace((unsigned char)ch)) {
                if (in_word) { 
                    words++; in_word = 0; 
                }
            }
            else {
                in_word = 1;
            }
        }
    }

    if (in_word) {
        words++;
    }
    if (chars > 0 & buffer[strlen(buffer)-1] != '\n') {
        lines++; 
    }
    fclose(fp);
    printf("%d\n  %d\n %d\n ", lines, words, chars);

}

void delete_line(const char* file_name, int line_number){//deletes a line by its number from a file 
    
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        perror("error cant open file to w");
        return;
    }
    char buffer[8192];
    for(int i=0; i<line_number;i++){
        fgets(buffer, sizeof(buffer), fp);
    }
    fputs("", fp); 
    fclose(fp);

}

int count_string_in_file(const char *file_name,const char* str){//counts how many times a string appears in a file
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("error cant open file to w");
        return -1;
    }
    char * txt=print_file_contents(file_name);
    int index=0;
    int counter=0;
    while (*txt) {
        if(*txt==str[index]){
            index++;
        }
        else{
            index=0;
        }
        if(index==strlen(str)){
            counter++;
            index=0;
        }
        txt++;
    }
    return counter;
    fclose(fp);

}

