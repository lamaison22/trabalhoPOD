#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void countSort(int n, int exp, int *vet) {
  int *a = malloc(n*sizeof(int));
  int count[10] = { 0 };

  for (int i = 0; i < n; i++){
    
    count[(vet[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    count[(vet[i] / exp) % 10]--;
    a[count[(vet[i] / exp) % 10]] = vet[i];
  }

  for (int i = 0; i < n; i++)
    vet[i] = a[i];
}

void sort(int n, int *vet) {
  int max = vet[0];

  for (int i = 1; i < n; i++)
    if (vet[i] > max) max = vet[i];

  for (int exp = 1; max / exp > 0; exp *= 10)
    countSort(n, exp, vet);
}

int main() {
  struct timeval start, stop;
  gettimeofday(&start, NULL);


  FILE *arq;
  arq=fopen("nums.txt","r");
  char num[12];
  char *result;
  int n=100000;
  int i=0;
  int cont=0;

  int *vet;


  vet = malloc(n*sizeof(int));

//vetor crescente
// for (int i = 0; i < n; i++)
// {
//   vet[i]=i;
// }


//decrescente
 for (int i = n-1; i>0 ; i--){
    vet[cont]=i;
    cont++;
  
}

// vetor que le numeros aleatorios do txt
// while (!feof(arq))
//     {
        
//         //Lê uma linha (inclusive com o '\n')
//         result = fgets(num, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
//         if (result){  // Se foi possível ler
//             int valor = atoi(num);
//             vet[i]=valor;
//             cont++;
//             i++;
//             // printf("%d ",cont);
            
      
//         }
//     }
  sort(n, vet);

  gettimeofday(&stop, NULL);
  float a=((stop.tv_sec - start.tv_sec)* 1000000 + stop.tv_usec - start.tv_usec);
    printf("Tempo: %.6fs\n",a/1000000);
  return 0;
}