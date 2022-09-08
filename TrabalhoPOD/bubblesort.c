#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

struct timeval stop, start;

void swap(int *vet, int x, int y){
    int aux;
    aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
}

int main(){
    gettimeofday(&start, NULL);
    
    FILE *arq;
    arq=fopen("nums.txt","r");
    char num[12];
    char *result;

    int n=10000;
    int i=0;
    int flag=1;
    int *vet;
    int cont=0;
    long long int contswap=0;
    long long int contcompare = 0;

    srand(time(NULL));   // Initialization, should only be called once.
  
    vet = malloc(n*sizeof(int));
    while (!feof(arq))
    {
        //Lê uma linha (inclusive com o '\n')
        result = fgets(num, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        if (result){  // Se foi possível ler
            int valor = atoi(num);
            vet[i]=valor;
            i++;
        }
    }

    //Cria vetor crescente
    // for (int i = 0; i < n; i++)
    // {
    //     vet[i]=i;
    // }
  
    //Cria vetor decrescente
    // for (int i = n-1; i>0 ; i--){
    //     //int r=rand();
    //     vet[cont]=i;
    //     cont++;
    // }
    
    for (int i = 0; i < n; i++){
        if(vet[i] < vet[i+1] && i!=n-1){
            contcompare++;
        }
    }

    if(contcompare == (n-1)){
        flag=0;
    }

    if (flag != 0){
        contcompare = 0;
        for(int i = n-1; i > 0; i--){
            for(int j = 0; j<i; j++){
                contcompare++;
                if(vet[j] > vet[j+1]){
                    swap(vet, j, j+1);
                    flag=1;
                    contswap++;
                }
            }
        }
    }
    
    if(flag==0){
        printf("Melhor caso\n");

        gettimeofday(&stop, NULL);

        printf("\nNumero de swaps: %lld\n",contswap);
        printf("Numero de comparacoes: %lld\n",contcompare);
        float a=((stop.tv_sec - start.tv_sec)*1000000 + stop.tv_usec - start.tv_usec);
        printf("Tempo: %.6fs\n",a/1000000);

    }
    else{
        gettimeofday(&stop, NULL);

        printf("\nNumero de swaps: %lld\n",contswap);
        printf("Numero de comparacoes: %lld\n",contcompare);
        float a=((stop.tv_sec - start.tv_sec)* 1000000 + stop.tv_usec - start.tv_usec);
        printf("Tempo: %.6fs\n",a/1000000);
    }

    return 0;
}