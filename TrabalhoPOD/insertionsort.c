#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

struct timeval stop, start;
    
int main(){
    gettimeofday(&start, NULL);

    FILE *arq;
    arq=fopen("nums.txt","r");
    char num[12];
    char *result;
    
    int n=10000;
    int *vet;
    int cont=0;
    long long int contswaps=0;
    long long int contcompare=0;
    int i=0;

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

    //Cria vetor decrescente
    // for (int i = n-1; i>0 ; i--){
    //     vet[cont]=i;
    //     cont++;
    // }

    //Cria vetor crescente
    // for (int i = 0; i<n; i++){
    //     vet[i]=i;
    // }

    int menor = vet[0];
    for(int i = 1; i < n; i++){
        int p = vet[i];
        int j = i-1;
        contcompare++;
        while(j >= 0 && vet[j] > p){
            vet[j+1] = vet[j];
            contswaps++;
            j--;
        }
        vet[j+1] = p;
    }

    gettimeofday(&stop, NULL);

    printf("\nNumero de trocas: %lld\n",contswaps);
    printf("Numero de comparacoes: %lld\n",contcompare);

    float a=((stop.tv_sec - start.tv_sec)* 1000000 + stop.tv_usec - start.tv_usec);
    printf("Tempo: %.6fs\n",a/1000000);
          
    return 0;
}