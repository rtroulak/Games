/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2015-01-01 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int **array;

 /*Function which print the array*/
void print_array(int N){
  
  int i=0,j=0,x;
  
    for(i=0;i<=N+1;i++)
  {
     for(j=0;j<3;j++)
    {
      
      if(i==0)
      {
	if(j==0)
	  printf("A\t");
	if(j==1)
	  printf("B\t");
	if(j==2)
	  printf("C\t\n");
      }
      else
      {
      if(array[i][j]==0){
	
	if(j==2)
	  printf("|\n");
	else
	  printf("|\t");
      }
      else{
	
	 printf("%d",array[i][j]); 
	 if(j==2)
	   printf("\n");
	 else
	   printf("\t");
      }
      }
    }
 
  }
  printf("--------------------------------\n");
}


 /*Function which searh which find the stack A B or C*/
int from_to(char val){
    if(val=='A')
    return 0;
  else if(val=='B')
    return 1;
  else if(val=='C')
    return 2;
  else
    printf("ERROR 404\n");
}


 /*Function which do the changes in the array*/
void change_array(int N,int n,char first,char second){
  int i,j,x,from,to,prev;
  
  from=from_to(first);
  to=from_to(second);
  
  for(i=0;i<=N+1;i++)
  {
    
    if(array[i][from]==n)
    {
     array[i][from]=0;
     for(j=1;j<=N+1;j++){
       
       if(j==N+1 && array[j][to]==0)
       {
	 array[j][to]=n;
	 break;
       }
	else if(array[j][to]!=0)
	{
	 array[prev][to]=n;
	 break;
	}
    prev=j;
    }
     
    }
    
  }
  
}

/*The main recursive_func for the moves of disks*/
void recursive_func(int N,int n,char first,char second,char third)
{
  
  if(n==1)
  {
    printf("Disk[%d] : %c->%c\n",n,first,second);
    change_array(N,n,first,second);
    print_array(N);
    return;
  }
  recursive_func(N,n-1,first,third,second);
  
    printf("Disk[%d] : %c->%c\n",n,first,second);
    change_array(N,n,first,second);
    print_array(N);
  recursive_func(N,n-1,third,second,first);
  
  
  
}

/*Function which allocate memory for array*/
void malloc_array(int N){
  int i;
  array = malloc((sizeof *array) * N+2);
  
  if (array)
  {
    for (i = 0; i < N+2; i++)
  {
    array[i] = malloc(sizeof *array[i] * 3);
  }
}
}
/*Function which initialize the array*/
void myfunc(int N)
{
  int i=0,j=0;
  
  for(i=0;i<=N+1;i++)
  {
    for(j=0;j<3;j++)
    {
      if(i==0)
      {
	if(j==0)
	  array[i][j]=-1;
	if(j==1)
	  array[i][j]=-2;
	if(j==2)
	  array[i][j]=-3;
      }
      else
      {
	if(j==0){
	  if(i>1){
	    array[i][j]=i-1;
	  }else{
	    array[i][j]=0;
	  }
	}
	else{
	 array[i][j]=0;
	}
      }
	
      }

  }
    
  }

 

int main(int argc, char *argv[]){
  
    
    int N;
    if(argv[1]==NULL)
    {
      printf("NO Argument by terminal NULL!\n");
      exit(EXIT_FAILURE);
    }
   
    N=atoi(argv[1]);/*do argv1 intenger*/
    
    malloc_array(N);
    if(N==0)
    {
      printf("Wrong Argument by terminal 0!\n");
      exit(EXIT_FAILURE);
    }
    
    myfunc(N);
    printf("The first Array is:\n");
    print_array(N);
    recursive_func(N,N,'A','C','B');
    printf("\t\t^\n\t\t|\n    this is the final array!\n");
  
  
}