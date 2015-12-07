/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2015-01-01 
*/

#include<stdio.h> 
#include<stdlib.h>

int winner;

int search_ace(int *array,int N){
  int x,i;
  x=0;
  for(i=1;i<=N;i++){
    
    if(array[i]==1){
      x++;
    
      winner=i;
    }
  }
  
  return x;
  
}


int main(int argc, char *argv[]){
  
  int N=0,i,j;
  int *array;/*int *t = (int*)malloc(sizeof(int)*10);*/
  int no_ace;
  printf("Dwse arithmo mellothanatwn:");
  
  
  scanf("%d",&N);
  
  array=(int*)malloc(sizeof(int)*N);
  

  
  
  for(i=1;i<=N;i++){
    array[i]=1;
  }
  i=1;
  
   printf("\n================THE GAME'S ACTION====================================\n");
   
   
  if(N==1){
     
     printf("\n====================================================================\n");
    printf("\n=====================THE WINNER OF THE GAME=========================");
      printf("\nPlayer 1 is alone,he can commit suicide or win this game!! his choice!!\n");
      printf("====================================================================\n");
      return 1;
    
  } 
  
  while(no_ace!=1){
    int counter=0,kanejena=0;;
    no_ace=0;
    
    
    for(j=2;j<=N;j++){
      
      if(kanejena){
	j=1;
      
	kanejena=0;
      }
	
      if(array[j]==1 && counter==0){
	printf("\t\tdead of %d\n",j);
	array[j]=0;
	counter=1;
      }
      if(array[j]==1 && counter==1){
	printf("\t\t\t\tnew killer is %d\n",j);
	counter=0;
      }
      if(j==N){
	
	if(array[1]==1 && array[N]==1){
	  printf("\t\tdead of 1\n");
	  array[1]=0;
	  counter=1;
	  
	}
	if(array[1]==1 && array[N]==0){
	  kanejena=1;
	  
	}
	
	
	j=1;
	
      }
      
    no_ace=search_ace(array,N);
    if(no_ace==1){
      printf("\n====================================================================\n");
       printf("\n=====================THE WINNER OF THE GAME=========================");
      printf("\nFinally The winner zombie is= %d player!!!!\n",winner);
      printf("====================================================================\n");
      return 1;
    }
      
    }
    
  
    
    
    
   
    
  }
  

 
  
}