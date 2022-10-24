#include <stdio.h>
#include <stdlib.h>

int ReadGrafo(char nome[]){
FILE *fGrafo;
    int temp = 0, Ln = 1,Cn =0, cont = 0;
    char tempc = 0;



    fGrafo = fopen(nome,"r");
    if(fGrafo == NULL){
        printf("\n\n Erro Na leitura do arquivo\n\n");
    }
    while(!feof(fGrafo)){
        cont++;
        fscanf(fGrafo, " %d", &temp); 
    }
    rewind(fGrafo);
    while(!feof(fGrafo)){
        fscanf(fGrafo, "%c", &tempc);
        if(tempc == '\n'){ 
            Ln++;
        }
    }
    rewind(fGrafo);
    Cn = cont/Ln;
    int* grafo = calloc((Ln * Cn), sizeof(int));
    for(int i=0; i< Ln; i++){
        for(int j=0;j < Cn;j++){
            fscanf(fGrafo, "%d", &grafo[i * Cn + j]);
        }
    }
    return ;
}