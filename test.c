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

void rotarPixeles90(pixel rotado[anchoPixeles][altoPixeles], pixel aRotar[altoPixeles][anchoPixeles]){
    for (int i = 0; i < anchoPixeles; i++){
        for (int j = 0; j < altoPixeles; j++){
            rotado[i][j].Red = aRotar[altoPixeles-1-j][i].Red;
            rotado[i][j].Green = aRotar[altoPixeles-1-j][i].Green;
            rotado[i][j].Blue = aRotar[altoPixeles-1-j][i].Blue;
        }
    }
}

void rotarPixeles180(pixel rotado[altoPixeles][anchoPixeles], pixel aRotar[altoPixeles][anchoPixeles]){
    for (int i = 0; i < altoPixeles; i++){
        for (int j = 0; j < anchoPixeles; j++){
            rotado[i][j].Red = aRotar[altoPixeles-1-i][anchoPixeles-1-j].Red;
            rotado[i][j].Green = aRotar[altoPixeles-1-i][anchoPixeles-1-j].Green;
            rotado[i][j].Blue = aRotar[altoPixeles-1-i][anchoPixeles-1-j].Blue;
        }
    }
}


void rotarPixeles270(pixel rotado[anchoPixeles][altoPixeles], pixel aRotar[altoPixeles][anchoPixeles]){
    for (int i = 0; i < anchoPixeles; i++){
        for (int j = 0; j < altoPixeles; j++){
            rotado[i][j].Red = aRotar[j][anchoPixeles-1-i].Red;
            rotado[i][j].Green = aRotar[j][anchoPixeles-1-i].Green;
            rotado[i][j].Blue = aRotar[j][anchoPixeles-1-i].Blue;
        }
    }
}


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



int verificarIgualdad(pixel porRevisar[altoPixeles][anchoPixeles], pixel pixeles[altoPixeles][anchoPixeles], int contador){
    bool sonIguales = true;
    for (int i=0; i<altoPixeles; i++){
        for (int j=0; j < anchoPixeles; j++){
            if (porRevisar[i][j].Red != pixeles[i][j].Red || porRevisar[i][j].Green != pixeles[i][j].Green || porRevisar[i][j].Blue != pixeles[i][j].Blue ){
                sonIguales = false;
                break;
            }
        }
        if (!(sonIguales)){
            break;
        }
        
    }
    if (sonIguales){
        return contador + 1;
    }else{
        return contador;
    }
}

void buscarImagen(pixel pixeles[altoPixeles][anchoPixeles], pixel **imagen, int indicador){
    pixel primero;
    primero.Red = pixeles[0][0].Red;
    primero.Green = pixeles[0][0].Green;
    primero.Blue = pixeles[0][0].Blue;
    int contador = 0;
    /*printf("%i %i %i\n",primero[0],primero[1],primero[2]);*/
 	for (int i = 0; i < altoImagen; i++){
        for (int j = 0; j < anchoImagen; j++){
            /*printf("%i , %i : %i\n",i,j,indicador);
            printf("%d %d %d \n", imagen[i][j].Red, imagen[i][j].Green, imagen[i][j].Blue);*/
            if (imagen[i][j].Red == primero.Red && imagen[i][j].Green == primero.Green && imagen[i][j].Blue == primero.Blue){
                bool sePaso = false;
                if (indicador == 0 || indicador == 180){
                    pixel porRevisar[altoPixeles][anchoPixeles];
                    for (int k = 0; k < altoPixeles; k++){
                        if (sePaso || (i+k >= altoImagen)){
                            sePaso = true;
                            break;
                        }
                        for (int m = 0; m < anchoPixeles; m++){
                            if (j+m >= anchoImagen){
                                sePaso = true;
                                break;
                            }
                            porRevisar[k][m].Red = imagen[i+k][j+m].Red;
                            porRevisar[k][m].Green = imagen[i+k][j+m].Green;
                            porRevisar[k][m].Blue = imagen[i+k][j+m].Blue;
                        }
                        
                    }/*end Main For*/
                    if (!(sePaso)){
                        contador = verificarIgualdad(porRevisar, pixeles, contador);
                    }
                }else{
                    pixel porRevisar[anchoPixeles][altoPixeles];
                    for (int k = 0; k < anchoPixeles; k++){
                        if (sePaso || (i+k >= altoImagen)){
                            sePaso = true;
                            break;
                        }
                        for (int m = 0; m < altoPixeles; m++){
                            if (j+m >= anchoImagen){
                                sePaso = true;
                                break;
                            }
                            porRevisar[k][m].Red = imagen[i+k][j+m].Red;
                            porRevisar[k][m].Green = imagen[i+k][j+m].Green;
                            porRevisar[k][m].Blue = imagen[i+k][j+m].Blue;
                        }
                        
                    }/*end Main For*/
                    if (!(sePaso)){
                        contador = verificarIgualdad(porRevisar, pixeles, contador);

                    }
                }/*end else*/
                
            }/*End If*/

    
        }
    }
    printf("Cantidad para rotacion %i: %i\n", indicador, contador);

   

}


void leer(pixel matriz[altoPixeles][anchoPixeles], char auxLectura, FILE *archivo){
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
            /*printf("%d %d %d \n", pixel, pixel2, pixel3);*/
        }
    }  
}

void leerImagen(pixel **imagen, char auxLectura, FILE *archivo){
    int pixel; 
	int pixel2; 
	int pixel3; 
	char* coma = (char*)malloc(4*sizeof(char)); 
	for (int i = 0; i < altoImagen; i++){
        for (int j = 0; j < anchoImagen; j++){
            if (j == anchoImagen-1){
                auxLectura = fscanf(archivo, "%d %c %d %c %d\n", &pixel, coma, &pixel2, coma, &pixel3); 
            }else{
                auxLectura = fscanf(archivo, "%d %c %d %c %d", &pixel, coma, &pixel2, coma, &pixel3); 
            }
            imagen[i][j].Red = pixel;
            imagen[i][j].Green = pixel2;
            imagen[i][j].Blue = pixel3;
        }
    }  
}

int leerInstrucciones (char* nombre){ 
    FILE *archivo0;
    archivo0 = fopen("buscar2.in","r");
	char auxLectura0;
    auxLectura0 = fscanf(archivo0, "%d[^ ]", &anchoPixeles);
    auxLectura0 = fscanf(archivo0, "%d[^\n]", &altoPixeles);
    pixel pixeles[anchoPixeles][altoPixeles];
    
    leer(pixeles,auxLectura0,archivo0);

    fclose(archivo0);

    FILE *archivo1;
    archivo1 = fopen("imagen2.in","r");
	char auxLectura1;
    auxLectura1 = fscanf(archivo1, "%d[^ ]", &anchoImagen);
    auxLectura1 = fscanf(archivo1, "%d[^\n]", &altoImagen);

    /*pixel imagen[altoImagen][anchoImagen] = malloc(sizeof(int));*/
    pixel **imagen = (pixel **)malloc(anchoImagen * 4 * altoImagen *sizeof(pixel *));
    for (int i = 0; i < altoImagen; ++i){
        imagen[i] = (pixel *)malloc(anchoImagen * sizeof(pixel));
    }
    leerImagen(imagen,auxLectura1,archivo1);

    pixel rotada90[anchoPixeles][altoPixeles];
    rotarPixeles90(rotada90, pixeles);

    pixel rotada180[altoPixeles][anchoPixeles];
    rotarPixeles180(rotada180, pixeles);

    pixel rotada270[anchoPixeles][altoPixeles];
    rotarPixeles270(rotada270, pixeles);

    buscarImagen(pixeles, imagen,0);
    buscarImagen(rotada90, imagen,90);
    buscarImagen(rotada180, imagen,180);
    buscarImagen(rotada270, imagen,270);

    free(imagen);
 
    fclose(archivo1);
    return 0;
}

/* Función main inicia la ejecución del programa */
int main(){
    leerInstrucciones("prueba.txt");
    
} /* fin de main */

