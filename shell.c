#include <stdio.h>
#include <math.h>


#define MAX_ITEMS 100000
#define MAX_CHAR 10
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

void shellSortBASE2(int array[], int vectorLength, FILE* output){
  int i,j,k,tmp;

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
      }
    }
    prtArray(array,vectorLength,output);
    fprintf(output,"INCR=%d\n",i);
  }
}

void shellSortKNUTH(int array[], int vectorLength, FILE* output){
  int i,j,k,tmp,initI;

  initI = 1;
  while((initI * 3 + 1) < vectorLength){
    initI = initI * 3 + 1;
  }

  for(i=initI;i>0;i=i/3){//Incremento.
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
      }
    }
    prtArray(array,vectorLength,output);
    fprintf(output,"INCR=%d\n",i);
  }
}

void shellSortCIURA(int array[], int vectorLength, FILE* output){
  int i,j,k,tmp,initI;
  int ciuraBASE[] = { 1,4,10,23,57,132,301,701,1577,3548,7983,17961,40412,90927,204585,460316};
  int currentCiura;

  initI=0;
  while(vectorLength > ciuraBASE[initI+1]){
    initI++;
  }

  while(initI>=0){//Incremento.
    i = ciuraBASE[initI];
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
      }
    }
    prtArray(array,vectorLength,output);
    fprintf(output,"INCR=%d\n",i);
    initI--;
  }
}

void shellSort(int array[], int vectorLength, FILE* output){
  int i,j,k,tmp;

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
      }
    }
    prtArray(array,vectorLength,output);
    fprintf(output,"INCR=%d\n",i);
  }
}

int main(){
  int buffer[MAX_ITEMS];
  int bufferClone[MAX_ITEMS];
  int nItems;
  int i,j,k;
  fpos_t position;
  FILE* input;
  FILE* output;
  char seqName[3][MAX_CHAR] = {"SHELL\n","KNUTH\n","CIURA\n"};
  char cName[MAX_CHAR];

  if((input = fopen(DEFAULT_INPUT,"r")) == NULL){
    printf("Erro ao abrir arquivo %s \n",DEFAULT_INPUT);
  }else{
    fgetpos(input, &position);
    if((output = fopen(DEFAULT_OUTPUT,"w")) == NULL){
      printf("Erro ao abrir arquivo %s \n",DEFAULT_OUTPUT);
    }else{
      while(feof(input)==0){
        fscanf(input,"%d ",&nItems);
        for(i=0;i<nItems;i++){
          fscanf(input,"%d ",&buffer[i]);
        }
        /*printf("nItens:%d\n",nItems);/*
        puts("\nVetor:");
        prtArrayCLI(buffer,nItems);
        puts("\n"); */


        //printf("J:%d K:%d\n",j,k);

        for(j=0;j<3;j++){
          for(k=0; k < MAX_ITEMS; k++) {
            bufferClone[k] = buffer[k];
          }
          prtArray(buffer,nItems,output);
          fprintf(output,"SEQ=");
          fputs(&seqName[j-1][MAX_CHAR],output);
          switch(j){
            case 0:
              shellSort(bufferClone, nItems, output);
              break;
            case 1:
              shellSortKNUTH(bufferClone, nItems, output);
              break;
            case 2:
              shellSortCIURA(bufferClone, nItems, output);
              break;
          }
        }
      }
    }
  }

  fclose(output);
  fclose(input);
  return 0;
}
