/*------------------------------------------------------
* Filename: TalBiton_const_pointer.c
* Description: recives a channel number and transfers gili's tv to it
* Author: Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    const int channel=80;
    const int channel_for_Gili=80;
    const int* channel_pointer=&channel;
    printf("%d\nGili please enter a channel number\n", *channel_pointer);
    scanf("%d", &channel_for_Gili);
    channel_pointer=&channel_for_Gili;
    printf("%d\n", *channel_pointer);
    return 0;
}
