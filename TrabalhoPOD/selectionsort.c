#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

struct timeval stop, start;

void swap(int menor, int i, int *vet){
    int aux;
    aux = vet[i];
    vet[i] = vet[menor];
    vet[menor] = aux; 
}

int main(){
    gettimeofday(&start, NULL);

    FILE *arq;
    arq=fopen("nums.txt","r"); 
    char num[12];
    int i=0;
    char *result;

    srand(time(NULL));   // Initialization, should only be called once.
 
    int n=10000;
    int *vet;
    long int contswap=0;
    long long int contcompare=0;
    int cont =0;
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
    // for (int i = 0; i<n ; i++){
    //     vet[i]=i;
    // }
 
    //Cria vetor decrescente
    // for (int i = n-1; i>0 ; i--){
    //     int r=rand();
    //     vet[cont]=i;
    //     cont++;
    // }

    for(int i = 0; i < n-1; i++){
        int menor = i;
        for(int j = i; j < n; j++){
            contcompare++;
            if(vet[menor] > vet[j])
                menor = j;
        }
        swap(menor, i , vet);
        contswap++;
    }
  
    gettimeofday(&stop, NULL);

    printf("\nNumero de swaps: %ld\n",contswap);
    printf("Numero de comparacoes: %lld\n",contcompare);
    float a=((stop.tv_sec - start.tv_sec)*1000000 + stop.tv_usec - start.tv_usec);
    printf("Tempo: %.6fs\n",a/1000000);

    return 0;
}