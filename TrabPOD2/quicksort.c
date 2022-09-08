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

int particiona(int *vet, int inicio, int fim){
    int posPivo = fim;
    int k = inicio;
    for(int i = inicio; i < fim; i++){
        if(vet[i] <= vet[posPivo]){
            swap(vet, i, k);
            k++;
        }
    }
    if(vet[k] > vet[posPivo]){
        swap(vet, k, fim);
        posPivo = k;
    }
    return posPivo;
}

void quickSort(int *vet, int inicio, int fim){
    if(inicio < fim){
        int pospivo = particiona(vet, inicio, fim);
        quickSort(vet, inicio, pospivo-1);
        quickSort(vet, pospivo+1, fim);
    }
}

int main(){
    gettimeofday(&start, NULL);
    FILE *arq;
    arq=fopen("nums.txt","r");
    char num[12];
    char *result;
    int n=50000;
    int cont=0;
    int i=0;
    int inicio;
    int *vet;
    vet = malloc(n*sizeof(int));

    // vetor crescente
    // for (int i = 0; i < n; i++)
    // {
    //     vet[i]=i;
    // }

      //decrescente
    //  for (int i = n-1; i>0 ; i--){
    //     vet[cont]=i;
    //     // printf("%d ",vet[cont]);
    //     cont++;
      
    // }
    
   
    //para vetor aleatorio lendo arquivo de texto   
   while (!feof(arq))
    {
        
        //Lê uma linha (inclusive com o '\n')
        result = fgets(num, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        if (result){  // Se foi possível ler
            int valor = atoi(num);
            vet[i]=valor;
            cont++;
            i++;
        }
    }
    
    int fim = vet[n-1];
    quickSort(vet, 0, n-1);

    gettimeofday(&stop, NULL);
    float a=((stop.tv_sec - start.tv_sec)* 1000000 + stop.tv_usec - start.tv_usec);
    printf("Tempo: %.6fs\n",a/1000000);

  

    return 0;
}