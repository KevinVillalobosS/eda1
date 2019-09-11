/* Directivas
Estandar de entrada y salida (stdio)*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "test.h"

int anchoPixeles;
int altoPixeles;
int anchoImagen;
int altoImagen;

void imprimirPixeles(pixel pixeles[altoPixeles][anchoPixeles]){
    for (int i = 0; i < altoPixeles; i++){
        for (int j = 0; j < anchoPixeles; j++){
            printf("los pixeles son: %i %i %i \n", pixeles[i][j].Red, pixeles[i][j].Green, pixeles[i][j].Blue);
        }
    }
}

void imprimirImagen(pixel imagen[altoImagen][anchoImagen]){
    for (int i = 0; i < altoImagen; i++){
        for (int j = 0; j < anchoImagen; j++){
            printf("los pixeles son: %i %i %i \n", imagen[i][j].Red, imagen[i][j].Green, imagen[i][j].Blue);
        }
    }
}



void verificarIgualdad(int matriz[][3], int pixeles[][3]){
    int total = matriz[0][2];
    printf("La matriz es: \n");
    bool sonIguales = true;
    for (int i=0; i<total; i++){
        printf("%d %d %d %d \n", matriz[i][0], matriz[i][1], matriz[i][2], i);
        printf("%d %d %d %d \n", pixeles[i][0], pixeles[i][1], pixeles[i][2], i);
        printf("---------------\n");
        if (matriz[i][0] != pixeles[i][0] || matriz[i][1] != pixeles[i][1] || matriz[i][2] != pixeles[i][2] ){
            printf("fallo\n");
            sonIguales = false;
            break;
        }
    }
    if (sonIguales){
        printf("Tenemos ganador!\n");
    }
}

void buscarImagen(int pixeles[][3], int imagen[][3]){
    int primero[3] = {pixeles[1][0],pixeles[1][1],pixeles[1][2]};
    printf("El ancho esasfasf: %d ",pixeles[0][2]);
    /*printf("%i %i %i\n",primero[0],primero[1],primero[2]);*/
    int i,j,k,m;
    int total = anchoImagen * altoImagen;
    for (i=0; i< total; i++){
        if (imagen[i][0] == primero[0] && imagen[i][1] == primero[1] && imagen[i][2] == primero[2]){
            j = i;
            int porRevisar[anchoPixeles*altoPixeles][3];
            porRevisar[0][0] = anchoPixeles;
            porRevisar[0][1] = altoPixeles;
            porRevisar[0][2] = anchoPixeles*altoPixeles;
            k=1;
            m = 0;
            while(k < anchoPixeles*altoPixeles){
                    if (m == anchoPixeles){
                        j = j + anchoImagen - anchoPixeles;
                        m = 0;
                    }
                    porRevisar[k][0] = imagen[j][0];
                    porRevisar[k][1] = imagen[j][1];
                    porRevisar[k][2] = imagen[j][2];
                    
                    k = k + 1;
                    m = m + 1;
                    j = j + 1;

            }
            printf("encontre una coincidencia con iterador igual a %i \n",i);
            verificarIgualdad(porRevisar, pixeles);
        }
    }
}

void leer(pixel matriz[altoPixeles][anchoPixeles], char auxLectura, FILE *archivo, int totalMatriz){
    int pixel; 
	int pixel2; 
	int pixel3; 
	char* coma = (char*)malloc(4*sizeof(char)); 
    int contador = 0;
	for (int i = 0; i < altoPixeles; i++){
        for (int j = 0; j < anchoPixeles; j++){
            if (contador == anchoPixeles-1){
                auxLectura = fscanf(archivo, "%d %c %d %c %d\n", &pixel, coma, &pixel2, coma, &pixel3); 
                contador = 0;
            }else{
                auxLectura = fscanf(archivo, "%d %c %d %c %d", &pixel, coma, &pixel2, coma, &pixel3); 
            }
            matriz[i][j].Red = pixel;
            matriz[i][j].Green = pixel2;
            matriz[i][j].Blue = pixel3;
            contador = contador + 1;
            /* printf("%d %d %d \n", pixel, pixel2, pixel3);*/
        }
    }  
}

void leerImagen(pixel imagen[altoImagen][anchoImagen], char auxLectura, FILE *archivo, int totalMatriz){
    int pixel; 
	int pixel2; 
	int pixel3; 
	char* coma = (char*)malloc(4*sizeof(char)); 
    int contador = 0;
	for (int i = 0; i < altoImagen; i++){
        for (int j = 0; j < anchoImagen; j++){
            if (contador == anchoImagen-1){
                auxLectura = fscanf(archivo, "%d %c %d %c %d\n", &pixel, coma, &pixel2, coma, &pixel3); 
                contador = 0;
            }else{
                auxLectura = fscanf(archivo, "%d %c %d %c %d", &pixel, coma, &pixel2, coma, &pixel3); 
            }
            imagen[i][j].Red = pixel;
            imagen[i][j].Green = pixel2;
            imagen[i][j].Blue = pixel3;
            contador = contador + 1;
            /* printf("%d %d %d \n", pixel, pixel2, pixel3);*/
        }
    }  
}

int leerInstrucciones (char* nombre){ 
    FILE *archivo0;
    archivo0 = fopen("buscar4.in","r");
	char auxLectura0;
    auxLectura0 = fscanf(archivo0, "%d[^ ]", &anchoPixeles);
    printf("El ancho es: %d ",anchoPixeles);
    auxLectura0 = fscanf(archivo0, "%d[^\n]", &altoPixeles);
    printf("El alto es: %d \n",altoPixeles);
    pixel pixeles[anchoPixeles][altoPixeles];

    /*
    int pixeles[total][3];
    pixeles[0][0] = ancho;
    pixeles[0][1] = alto;
    pixeles[0][2] = ancho*alto;*/
   
    leer(pixeles,auxLectura0,archivo0, anchoPixeles*altoPixeles);

    printf("%d %d %d\n", pixeles[0][0].Red, pixeles[0][0].Green, pixeles[0][0].Blue);
    imprimirPixeles(pixeles);
    fclose(archivo0);
   
   
    FILE *archivo1;
    archivo1 = fopen("imagen4.in","r");
	char auxLectura1;
	int ancho1 = 0;
	int alto1 = 0;
    auxLectura1 = fscanf(archivo1, "%d[^ ]", &anchoImagen);
    printf("El ancho es: %d ",anchoImagen);
    auxLectura1 = fscanf(archivo1, "%d[^\n]", &altoImagen);
    printf("El alto es: %d \n",altoImagen);
    int total1 = ancho1*alto1;
    pixel imagen[altoImagen][anchoImagen];
    imagen[0][0].Red = ancho1;
    leerImagen(imagen,auxLectura1,archivo1, anchoImagen*altoImagen);
    
    /*buscarImagen(pixeles, imagen);*/
    imprimirImagen(imagen);
    fclose(archivo1);
    return 0;
}


void inicializar(){
}

/* Función main inicia la ejecución del programa */
int main(){
    leerInstrucciones("prueba.txt");
    
} /* fin de main */

