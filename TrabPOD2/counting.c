#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

 void sort(int n, int k, int *vet) {
  int *a = (int*)calloc(k + 1, sizeof(int));

  for (int i = 0; i < n; i++) {
      a[vet[i]]++;
  }
//   for (int i = 0; i < k + 1; i++) {
//     for (int j = 0; j < a[i]; j++) {
//       printf("%d ", i);                  //aq printa ordenado 
//     }
//   }
}

int main() {
  struct timeval start, stop;
  gettimeofday(&start, NULL);

  FILE *arq;
  arq=fopen("nums.txt","r");
  char num[12];
  char *result;
  int n=100000;
//   int k=213145; //maior numero do vetor 10k aleatorio
// int k =42142;//maior numero do vetor 50k aleatorio
//   int k =32767; //maior valor do vet 100k aleatorio
//   int k=49999; no crescente informar o n-1 (maior numero)
  int k=99999;
  int *vet;
  int i=0;
  int cont=0;


 

  vet = malloc(n*sizeof(int));

  //vetor crescente
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


// para vetor aleatorio que le txt
//  while (!feof(arq))
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


  sort(n, k, vet);

  gettimeofday(&stop, NULL);
  float a=((stop.tv_sec - start.tv_sec)* 1000000 + stop.tv_usec - start.tv_usec);
    printf("Tempo: %.6fs\n",a/1000000);

  return 0;
}