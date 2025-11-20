/*------------------------------------------------------
* Filename: 8queens.c
* Description: 8 queens problem
* Author: Tal Aviya Biton & Ravid Rosenberg
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define QUEENS 8

void zero(int bord[QUEENS][QUEENS]);//returns bord to stage 0
int is_ok(int row, int col, int bord[QUEENS][QUEENS]);//checks if its ok to put a queen in [row][col] 
int mark(int row, int col, int bord[QUEENS][QUEENS]);//marks all the spots the queen in [row][col] affects
void unmark(int row, int col, int bord[QUEENS][QUEENS]);//unmarks all the spots the queen in [row][col] affects
int recusivePut(int bord[QUEENS][QUEENS], int queens);//a recursive function to put queens on the bord
int main(){
    int bord[QUEENS][QUEENS]={0};                               
    zero(bord);
    int res=recusivePut(bord,QUEENS);

    //printing
    for(int i=0;i<QUEENS;i++){
        for(int j=0;j<QUEENS;j++){
            if(bord[i][j]==1){
                printf("%c,", '*');
            }
            else{
                printf("%c,", ' ');
            }
        }
        printf("%c", '\n');
    }

    return 0;    
}

/*0=available, 1=queen, <0 =affected*/
int is_ok(int row, int col, int bord[QUEENS][QUEENS]){//checks if its ok to put a queen in [row][col] 
    if(bord[row][col]!=0){
        return 0;
    }

    //rows
    for (int i = 0; i < QUEENS; i++)
    {
        if(bord[row][i]>0){
            return 0;
        }
    }

    //cols
    for (int i = 0; i < QUEENS; i++)
    {
        if(bord[i][col]>0){
            return 0;
        }
    }

    //cross
    for (int i = 0; row-i<0||col-i<0; i++)
    {
        if(bord[row-i][col-i]>0){
            return 0;
        }
    }
    for (int i = 0; row-i<0||col-i>8; i++)
    {
        if(bord[row-i][col+i]>0){
            return 0;
        }
    }
    for (int i = 0; row-i>8||col-i<0; i++)
    {
        if(bord[row+i][col-i]>0){
            return 0;
        }
    }
    for (int i = 0; row-i>8||col-i>8; i++)
    {
        if(bord[row+i][col+i]>0){
            return 0;
        }
    }
    return 1;
}
int mark(int row, int col, int bord[QUEENS][QUEENS]){//marks all the spots the queen in [row][col] affects
    if(is_ok( row,  col, bord)){
        bord[row][col]=1;
    }
    else{
        return 0;
    }
    
    for (int i = 0; i < QUEENS; i++)
    {
        if( i==col){// skip bord[row][col]
            continue;
        }
        bord[row][i]--;
    }
    for (int i = 0; i < QUEENS; i++)
    {
        if( i==row){//skip bord[row][col]
            continue;
        }
        bord[i][col]--;
    }

    //cross
    for (int i = 1; row-i>0&&col-i>0; i++)
    {
        bord[row-i][col-i]--;
    }
    for (int i = 1; row-i>0&&col+i>8; i++)
    {
        bord[row-i][col+i]--;
    }
    for (int i = 1; row+i<8&&col-i>0; i++)
    {
        bord[row+i][col-i]--;
    }
    for (int i = 1; row+i<8&&col+i<8; i++)
    {
        bord[row+i][col+i]--;
    }
    return 1;
    
}
void unmark(int row, int col, int bord[QUEENS][QUEENS]){//unmarks all the spots the queen in [row][col] affects
    bord[row][col]=0;
   
    for (int i = 0; i < QUEENS; i++)
    {
        if( i==col){ //skip bord[row][col]
            continue;
        }
        bord[row][i]++;
    }
    for (int i = 0; i < QUEENS; i++)
    {
        if( i==row){//skip bord[row][col]
            continue;
        }
        bord[i][col]++;
    }

    //cross
    for (int i = 1; row-i>0&&col-i>0; i++)
    {
        bord[row-i][col-i]++;
    }
    for (int i = 1; row-i>0&&col+i>8; i++)
    {
        bord[row-i][col+i]++;
    }
    for (int i = 1; row+i<8&&col-i>0; i++)
    {
        bord[row+i][col-i]++;
    }
    for (int i = 1; row+i<8&&col+i<8; i++)
    {
        bord[row+i][col+i]++;
    }
    
    
}
int recusivePut(int bord[QUEENS][QUEENS], int queens){//a recursive function to put queens on the bord
    if(queens==0){
        return 0;
    }
    int flag=0, j=0;

     for(;j<QUEENS;j++){
        if(mark(QUEENS-queens, j, bord)){
            flag=recusivePut(bord, queens-1);
                break;
        }
    } 

    if(j==QUEENS){
        return 1;
    }

    while(flag){
        for(int i=0;i<QUEENS;i++){
            if(bord[QUEENS-queens][i]==1){
                unmark(QUEENS-queens, i, bord);
                j++;
                for(;j<QUEENS;j++){
                    if(mark(QUEENS-queens, j, bord)){
                        flag=recusivePut(bord, queens-1);
                        break;
                    }
                } 
                if(j==QUEENS){
                    return 1;
                }
                break;
            }
        }    
    }

}
void zero(int bord[QUEENS][QUEENS]){
    for(int i=0;i<QUEENS;i++){
        for(int j=0;j<QUEENS;j++){
            bord[i][j]=0;
        }
    }
}
