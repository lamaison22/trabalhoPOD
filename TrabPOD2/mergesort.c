#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>

 
void intercala(int *vet,int inicio, int meio, int fim){
   int *aux=malloc((fim-inicio+1)*sizeof(int)); 
   int i = inicio;
   int j= meio+1;
   int k=0;
   while((i<=meio)&&(j<=fim)){
       if(vet[i]<=vet[j]){
           aux[k]=vet[i];
           i++;
       }
       else{
       aux[k]=vet[j];
       j++;
   }
       k++;
   }
   while(i<=meio){
       aux[k]=vet[i];
       k++;
       i++;
   }
   while(j<=fim){
       aux[k]=vet[j];
       k++;
       j++;
   }
   for (int k = inicio; k <= fim; k++)
   {
       vet[k]=aux[k-inicio];
   }
  
  
   free(aux);
  
  
}
void merge(int *vet,int inicio,int fim){
   if(inicio<fim){
       int meio;
       meio=(inicio+fim)/2;
       merge(vet,inicio,meio);
       merge(vet,meio+1,fim);
       intercala(vet,inicio,meio,fim);
   }
 
}
 
int main(){
   struct timeval start, stop;
  gettimeofday(&start, NULL);

  FILE *arq;
  arq=fopen("nums100k.txt","r");
  char num[12];
  char *result;
  int n=100000;
  int inicio,fim,meio;
  int cont=0;
  int i=0;
  int *vet;
  vet=malloc(n*sizeof(int));


// vetor crescente
// for (int i = 0; i < n; i++)
// {
//     vet[i]=i;

// }

     //decrescente
     for (int i = n-1; i>0 ; i--){
        vet[cont]=i;
        cont++;
      
    }



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
//             // printf("%d ",cont);
            
      
//         }
//     }
  
 
  merge(vet,0,n-1);

  gettimeofday(&stop, NULL);
  float a=((stop.tv_sec - start.tv_sec)* 1000000 + stop.tv_usec - start.tv_usec);
   printf("Tempo: %.6fs\n",a/1000000);
  
 
  
}
