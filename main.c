#include<stdio.h>

const unsigned short Width = 208, Height = 65;

int main(void){
    char start;

    printf("Ready?\nEnter Y/N ");

    start = getchar();
    if (start != 'Y'){
        return 0;
    }
    while (1)
    {
        for (int k = 0;  k < 3; k++){
            for (int i = 0; i < Height * Width; i ++){
                printf("%c", (char)((int)'8' + k));
            }
        }
    }
    

}