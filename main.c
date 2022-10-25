#include <stdio.h>
#include <stdlib.h>

int NumeroDeVertices, NumeroDeArestas;

int** ReadGrafo(int** grafo){
    //  Declarar variaveis
    FILE *fGrafo;
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
    fclose(fGrafo);
    return grafo;
}

int ChecarCores(int** grafo, int Linha){
    for (int i = 0; i < NumeroDeVertices; i++){
        if(grafo[Linha][] == Cor){
            return 0
        }
    }
}

int main(){
    int Cor = 2;
    int** grafo = ReadGrafo(grafo);
    for(int i=0; i< 4; i++){
        for(int j=0;j < 4;j++){
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < NumeroDeVertices; i++){
        for(int j = 0; j < NumeroDeVertices; j++){
            if(grafo[i][j] == 1){
                Cor = 2;
                while(grafo[i][j] == 1){
                    if (ChecarLinha(grafo, i)&&ChecarColuna(grafo, j)){
                        grafo[i][j] = Cor;
                    }
                    else{
                        Cor ++;
                    }
                }
            }
        }
    }

}