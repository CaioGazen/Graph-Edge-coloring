#include <stdio.h>
#include <stdlib.h>

int** ReadGrafo(int** grafo){
    //  Declarar variaveis
    FILE *fGrafo;
    int NumeroDeVertices, NumeroDeArestas;
    //  Abrir arquivo
    fGrafo = fopen("grafo.txt","r");
    if(fGrafo == NULL){
        printf("\n\n Erro Na leitura do arquivo\n\n");
    }
    // Ler a quantidade de vertices e arestas
    fscanf(fGrafo, "%d %d", &NumeroDeVertices, &NumeroDeArestas);

    //alocar a quantidade necessaria de memoria
    grafo = calloc(NumeroDeVertices, sizeof(int*) + 1);
    for(int i = 0; i < NumeroDeVertices; i++){  
        grafo[i] = calloc(NumeroDeVertices, sizeof(int*));
    }
    //Alocar um ponteiro nulo para facilitar a liberação da memoria no final do programa
    grafo[NumeroDeVertices] = NULL;

    // Popular grafo com os dados do .txt
    for(int i=0; i< NumeroDeVertices; i++){
        for(int j=0;j < NumeroDeVertices;j++){
            fscanf(fGrafo, "%d", &grafo[i][j]);
        }
    }
    return grafo;
}

int main(){
    int** grafo = ReadGrafo(grafo);
    for(int i=0; i< 4; i++){
        for(int j=0;j < 4;j++){
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
}