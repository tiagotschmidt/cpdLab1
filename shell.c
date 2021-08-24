#include <stdio.h>
#include <math.h>


#define MAX_ITEMS 100000
#define DEFAULT_INPUT "entrada1.txt"

void prtArray(int array[], int cIndex, int vectorLength){
  if(vectorLength > 0){
    printf("%d ",array[cIndex]);
    prtArray(array,cIndex+1,vectorLength-1);
  }else{
    printf("\n");
  }
}

void shellSort(int array[], int vectorLength){
  int i,j,k,tmp;
  prtArray(array,0,6);

  for(i=vectorLength/2;i>0;i=i/2){//Incremento.
    for(j=i;j<vectorLength;j++){//Percorre cada grupo.
      for(k=j-i;k>=0;k=k-1){//
        printf("I:%d\tJ:%d\tK:%d\n",i,j,k);
        if(array[k+i]>=array[k]){//Se o elemento já estiver ordenado, para.
          break;
        }else{//Se não:Executa troca,
          tmp = array[k];
          array[k] = array[k+i];
          array[k+i] = tmp;
          prtArray(array,0,6);
        }
      }
    }
  }
}

void readFile(int buffer[], int *nItems){ 
  
}

int main(){
  int buffer[MAX_ITEMS*3];   
  int nItems;
  int i;
  FILE* input;

  if((input = fopen(DEFAULT_INPUT,"r")) == NULL){
    printf("Erro ao abrir arquivo %s \n",DEFAULT_INPUT);    
  }else{
    while(fgetc(input) != EOF){
      fscanf(input,"%d",&nItems);
      for(i=0;i<nItems;i++){
        fscanf(input,"%d",&buffer[i]);
      }
      
      puts("Vetor atual:");
      prtArray(buffer,0,nItems);
    }    
  }

//puts("Começou.");
//shellSort(teste,6);
  

  return 0;
}
