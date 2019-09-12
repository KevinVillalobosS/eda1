#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "test.h"

int main(){
    pixel pixeles[5][4];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            pixeles[i][j].Red = i;
            pixeles[i][j].Green = j;
            pixeles[i][j].Blue = i*j;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            printf("los pixeles son: %i %i %i \n", pixeles[i][j].Red, pixeles[i][j].Green, pixeles[i][j].Blue);
        }
    }
    
}
/*printf("%d %d %d %d \n", matriz[i][0], matriz[i][1], matriz[i][2], i);
        printf("%d %d %d %d \n", pixeles[i][0], pixeles[i][1], pixeles[i][2], i);
        printf("---------------\n");*/   