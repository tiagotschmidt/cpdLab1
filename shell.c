#include <stdio.h>

void prtArray(int array[], int cIndex, int vectorLength){
  if(vectorLength > 0){
    printf("%d\t",array[cIndex]);
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

int main(){
  int teste[] = {87,42,25,13,8,7};

  puts("Começou.");
  shellSort(teste,6);
  prtArray(teste,0,6);

  return 0;
}
