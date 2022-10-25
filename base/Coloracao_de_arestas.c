#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificarV(int **matriz,int c,int v,int j){
    int a;
	
	for(a=0;a<v;a++){
		if(matriz[a][j]==c){
            return(0);
        }
    }
    return(1);
}

int verificarH(int **matriz,int c,int v,int i){
	int b;
	
       for(b=0;b<v;b++){
        if(matriz[i][b]==c){ 
			return(0);
        }
    }
    return(1);

}

int main(){
    
	int v,x,i,j,c,**matriz;
   
    FILE *arqentrada;
    
    arqentrada=fopen("Grafo.txt","r");
    if(arqentrada == NULL){
        printf("Erro ao exibir arquivo!!!");
        return 1;
    }
    fscanf(arqentrada, "%d %d", &v, &x);
    
	matriz= (int**)malloc(sizeof(int*)*v);
   
    for(i=0;i<v;i++){
		matriz[i]=(int*)malloc(sizeof(int)*v);
    }
    
	for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            fscanf(arqentrada,"%d",&matriz[i][j]);
        }
    }
    fclose(arqentrada);

    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            if(matriz[i][j]==1){
                c=2;
                do{
                    if(verificarV(matriz,c,v,j)&&verificarH(matriz,c,v,i)){
                        matriz[i][j]=c;
                    }else{
                        c++;
                    }
                }while(matriz[i][j]==1);
			}
        }
    }

	for(i=0;i<v;i++){
        printf("\n");
        for(j=0;j<v;j++){
            printf("%d \t", matriz[i][j]);
            if(matriz[i][j]>=c){
            	c=matriz[i][j];
			}
        }
    }
    printf("\nCores usadas: %d",c-1);
    return 0;
}
