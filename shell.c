#include <stdio.h>
#include <math.h>


#define MAX_ITEMS 100000
#define DEFAULT_INPUT "entrada1.txt"
#define DEFAULT_OUTPUT "saida.txt"

void prtArray(int array[], int vectorLength, FILE* output){ 
  int i;
  for(i=0;i<vectorLength;i++){
    fprintf(output,"%d ",array[i]);
  }
}
void prtArrayCLI(int array[], int vectorLength){  
  int i;
  for(i=0;i<vectorLength;i++){
    printf("%d ",array[i]);
  }
}

void shellSort(int array[], int vectorLength, FILE* output){
  int i,j,k,tmp;
  prtArray(array,vectorLength,output);
  fprintf(output,"SEQ=TXT\n");

  for(i=vectorLength/2;i>0;i=i/2){//Incremento.
    for(j=i;j<vectorLength;j++){//Percorre cada grupo.
      for(k=j-i;k>=0;k=k-1){//
        //printf("I:%d\tJ:%d\tK:%d\n",i,j,k);
        if(array[k+i]>=array[k]){//Se o elemento já estiver ordenado, para.
          break;
        }else{//Se não:Executa troca,
          tmp = array[k];
          array[k] = array[k+i];
          array[k+i] = tmp;          
        }
        prtArray(array,vectorLength,output);
        fprintf(output,"INCR=%d\n",i);
      }
    }
  }
}

int main(){
  int buffer[MAX_ITEMS];   
  int nItems;
  int i;
  fpos_t position;
  FILE* input;
  FILE* output;

  if((input = fopen(DEFAULT_INPUT,"r")) == NULL){
    printf("Erro ao abrir arquivo %s \n",DEFAULT_INPUT);    
  }else{
    fgetpos(input, &position);
    if((output = fopen(DEFAULT_OUTPUT,"w")) == NULL){
      printf("Erro ao abrir arquivo %s \n",DEFAULT_OUTPUT);    
    }else{
      while(feof(input)==0){       
        fscanf(input,"%d",&nItems);
        for(i=0;i<nItems;i++){
          fscanf(input,"%d ",&buffer[i]);
        }  
        printf("nItens:%d\n",nItems);/*
          puts("\nVetor:");
          prtArrayCLI(buffer,nItems);  
          puts("\n"); */          

        shellSort(buffer, nItems, output);  
      }
    }     
  }

  fclose(output);
  fclose(input); 
  return 0;
}
