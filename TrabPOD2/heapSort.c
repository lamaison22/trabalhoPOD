#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int *vet, int a, int b) {
  int aux = vet[b];
  vet[b] = vet[a];
  vet[a] = aux;
}

void heap(int *vet, int i, int n) {
  int cima = i;
  int esqrd = 2 * i + 1;
  int dir = 2 * i + 2;

  if (esqrd < n && vet[esqrd] > vet[cima])
    cima = esqrd;

  if (dir < n && vet[dir] > vet[cima])
    cima = dir;

  if (cima != i){
    swap(vet, i, cima);
    heap(vet, cima, n);
  }
}

void sort(int *vet, int n){
  for (int k = n / 2 - 1; k >= 0; k--){
    heap(vet, k, n);

  }

  for (int k = n-1; k >= 1; k--) {
    swap(vet, 0, k);
    heap(vet, 0, k);
  }
}

int main() {
  struct timeval start, stop;
  gettimeofday(&start, NULL);

  FILE *arq;
  arq=fopen("nums100k.txt","r");
  char num[12];
  char *result;
  int n=100000;
  int *vet;
  int cont=0;
  int i=0;


  vet = malloc(n*sizeof(int));

//vetor aleatorio q le txt
//   while (!feof(arq))
//     {
        
//         //Lê uma linha (inclusive com o '\n')
//         result = fgets(num, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
//         if (result){  // Se foi possível ler
//             int valor = atoi(num);
         
//             vet[i]=valor;
//             cont++;
//             i++;
            
      
//         }
//     }

//crescente
    // for (int i = 0; i < n; i++)
    // {
    //     vet[i]=i;
    // }


//     decrescente
for (int i = n-1; i>0 ; i--){
        vet[cont]=i;
        // printf("%d ",vet[cont]);
        cont++;
      
}  
  
  sort(vet, n);
  
    
    

  gettimeofday(&stop, NULL);
    float a=((stop.tv_sec - start.tv_sec)* 1000000 + stop.tv_usec - start.tv_usec);
    printf("Tempo: %.6fs\n",a/1000000);

  return 0;
}