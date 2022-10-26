#include <stdio.h>
#include <stdlib.h>

int NumeroDeVertices, NumeroDeArestas;

int** LerGrafo(int** grafo){
    //  Declarar variaveis
    FILE *fGrafo;
    //  Abrir arquivo
    fGrafo = fopen("grafo.txt","r");
    // Verificar se o arquivo foi aberto
    if(fGrafo == NULL){
        printf("\n\n Erro Na leitura do arquivo\n\n");
    }
    //  Ler a quantidade de vertices e arestas
    fscanf(fGrafo, "%d %d", &NumeroDeVertices, &NumeroDeArestas);

    //  alocar a quantidade necessaria de memoria
    grafo = calloc(NumeroDeVertices, sizeof(int*) + 1);
    for(int i = 0; i < NumeroDeVertices; i++){  
        grafo[i] = calloc(NumeroDeVertices, sizeof(int*));
    }
    //  Alocar um ponteiro nulo para facilitar a liberação da memoria no final do programa
    grafo[NumeroDeVertices] = NULL;

    //  Popular grafo com os dados do .txt
    for(int i=0; i< NumeroDeVertices; i++){
        for(int j=0;j < NumeroDeVertices;j++){
            fscanf(fGrafo, "%d", &grafo[i][j]);
        }
    }
    //  Fechar o .txt
    fclose(fGrafo);
    return grafo;
}

int ChecarCores(int** grafo, int Linha, int Coluna, int Cor){

    //  Percorer a linha e coluna do grafo simultaneamente
    for (int i = 0; i < NumeroDeVertices; i++){
        //  Se existir uma aresta com a cor em questão na linha, retornar Falso
        if(grafo[Linha][i] == Cor){
            return 0;
        }
        //  Se existir uma aresta com a cor em questão na coluna, retornar Falso
        if(grafo[i][Coluna] == Cor){
            return 0;
        }
    }
    // Se nao existir uma aresta com a cor em questão na coluna ou na linha retornar Verdadeiro
    return 1;
}

int main(){ 
    //  Chamar a função que le o Grafo
    int** grafo = LerGrafo(grafo);

    // imprimir a lista de adjacencia
    printf("Lista de Adjacencia antes de colorir\n\n");
    for(int i=0; i< 4; i++){
        printf("      ");
        for(int j=0;j < 4;j++){
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //  Percorer todos os pontos da lista de adjacencia 
    for(int i = 0; i < NumeroDeVertices; i++){
        for(int j = 0; j < NumeroDeVertices; j++){
            //  Checar se a aresta ja foi colorida
            if(grafo[i][j] == 1){
                //  Comecar pela primeira cor
                int Cor = 2;
                //  Repetir enquanto a aresta não for colorida
                while(grafo[i][j] == 1){
                    // Verificar se existem arestas adjacentes com a mesma cor
                    if (ChecarCores(grafo, i, j, Cor)){
                        // Se nao houver arestas adjacentes com a cor em questão colorir a aresta
                        grafo[i][j] = Cor;
                    }
                    else{
                        // Se ja existir uma aresta com a cor em questão passar para a proxima cor
                        Cor ++;
                    }
                }
            }
        }
    }

    // Declarar variavel para contar o numero de cores
    int NumeroDeCores = 0;
    printf("Lista de Adjacencia Colorida\n\n");
    // percorer a lista de adjacencia que ja foi colorida, imprimindo os pontos e contando as cores
    for(int i=0; i< 4; i++){
        printf("      ");
        for(int j=0;j < 4;j++){
            printf("%d ", grafo[i][j]);
            if (grafo[i][j] - 1 > NumeroDeCores){
                NumeroDeCores = grafo[i][j] -1;
            }
        }
        printf("\n");
    }
    printf("\nForam usadas %d Cores para colorir o grafo\n\n", NumeroDeCores);

    // Liberar a memoria que foi alocada
    for(int i = 0; grafo[i] != NULL; i++){
        free(grafo[i]);
    }
    free(grafo);
}