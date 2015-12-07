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

int SIZE_T=0,SIZE_OF_R=0,SIZE_OF_C=0,CURRENT_BLOCK=1,tmp1=1,tmp2=1,epi=1,epi2=1,epibac=1;
char *file_to_open;
char *value;

int **sudoku;
int *valid,*fail_colums,*fail_rows,*fail_block;


/*
 * Function which malloc the dynamic checker arrays of sudoku
 */
void malloc_colums()
{
  
  valid=malloc((sizeof *valid) * SIZE_T);
  fail_colums=malloc((sizeof *fail_colums) * SIZE_T);
  fail_rows=malloc((sizeof *fail_rows) * SIZE_T);
  fail_block=malloc((sizeof *fail_block) * SIZE_T);
 
}


/*
 * Function which malloc the dynamic array of sudoku
 */
void malloc_array(){
  int i;
  sudoku = malloc((sizeof *sudoku) * SIZE_T+1);
  
  if (sudoku)
  {
    for (i = 0; i < SIZE_T+1; i++)
  {
    sudoku[i] = malloc(sizeof *sudoku[i] * SIZE_T+1);
  }
}
}


/*
 * Function which init valid array
 */
void init_valid(){
  int x;
  for(x=0;x<=SIZE_T;x++)
  {
    valid[x]=0;
  }
}


/*
 * Function which init all arrays
 */
void init_arrays(){
  int x,y;
   for(x=0;x<=SIZE_T;x++)
   {
    for(y=0;y<=SIZE_T;y++)
    {
     sudoku[x][y]=0;
    }
   }
   for(x=0;x<=SIZE_T;x++)
   {
     valid[x]=0;
   }
}

/*
 * Function which print arrays
 */
void print_array(){
  int i=1,j=1;
  printf("sudoku array is:\n");
  for(i=1;i<=SIZE_T;i++)
  {
    for(j=1;j<=SIZE_T;j++)
    {
      printf("%d ",sudoku[i][j]);
    }
    printf("\n");
  }
}

/*
 * Function which check rows
 */
int checkr(int stable){
  int i=1;
   for(i=1;i<=SIZE_T;i++)
  {
    valid[sudoku[stable][i]]=1;
  }
  
  for(i=1;i<=SIZE_T;i++)
   {
     if(valid[i] == 0){
	return 2;
     }
   }
   return 0;
}

/*
 * Function which checkj colums
 */
int checkc(int stable){
  int i=1;
   for(i=1;i<=SIZE_T;i++)
  {
    valid[sudoku[i][stable]]=1;
  }
  
   for(i=1;i<=SIZE_T;i++)
   {
     if(valid[i] == 0){
	return 2;
     }
   }
  
  return 0;
}



int checkb(int block){
  int i=1,j=1,bar=0,bac=0,yolo;
  bar=SIZE_T/SIZE_OF_R;
  bac=SIZE_T/SIZE_OF_C;
    if(block==1)
    {
      for(i=1;i<=SIZE_OF_R;i++)
      {
	for(j=1;j<=SIZE_OF_C;j++)
	{
	  valid[sudoku[i][j]]=1;
	}
      }
      
      for(i=1;i<=SIZE_T;i++)
      {
	if(valid[i] == 0){
	  return 2;
	}
      }
      tmp1=tmp1+bar;
      return 0;
    }
    else{
    
      for(i=tmp1;i<tmp1+bar;i++){
	for(j=tmp2;j<tmp2+bac;j++){/*
	  printf("Block=%d:\n",block);  
	  printf("[%d]\n",sudoku[j][i]);
	  */
	  
	  valid[sudoku[j][i]]=1;
	  
	}
      }
      
      
      
      tmp1=tmp1+bar;
      epi++;
      if(block==bac*epibac){
	tmp1=1;
	epi=1;
	epi2++;
	tmp2=tmp2+bac;
	epibac++;
      }
  
      for(i=1;i<=SIZE_T;i++)
      {
	
	if(valid[i] == 0){
	  return 2;
	}
      }
    }
  
  return 0;
}

/*
 * Function which check valid blocks
 */
void check_valid(){
 int i=1,j=1,colum=1,row=1,block=1; 
 
 /*colums*/
 while(row<=SIZE_T){
  fail_rows[row]=checkr(row);
  init_valid();
  row++;
 }
 
 while(colum<=SIZE_T){
  fail_colums[colum]=checkc(colum);
  init_valid();
  colum++;
 }
 while(block<=SIZE_T){
  fail_block[block]=checkb(block);
  init_valid();
  block++;
 }
/*  
 pick_fail_block();*/
}

/*
 * Function which prints result
 */
void Result(){
  
  int i,flag;
  
  /*for row*/
  printf("Invalid rows: ");
  for(i=1;i<=SIZE_T;i++){
    
    if(fail_rows[i]==2)
    {	flag=2;
	printf("%d ",i);
    }
  }
  if(flag!=2){
    printf("None");
  }
  printf("\n");
 
  /*for columns*/
  printf("Invalid colums: ");
  for(i=1;i<=SIZE_T;i++){
    
    if(fail_colums[i]==2)
    {	flag=2;
	printf("%d ",i);
    }
  }
  if(flag!=2){
    printf("None");
  }
  
  printf("\n");
  
  /*for blocks*/
  printf("Invalid blocks: ");
  for(i=1;i<=SIZE_T;i++){
    
    if(fail_block[i]==2)
    {	flag=2;
	printf("%d ",i);
    }
  }
  if(flag!=2){
    printf("None");
  }
  
  printf("\n");
  
  if(flag!=2){
    printf("Correct Sudoku!!\n");
  }
  
}

/*
 * Function which free all malloc-ed memory
 */
void free_all_g_mem(){
  
  
  
  free(fail_colums);
  free(fail_rows);
  free(fail_block);
  free(sudoku);
 
}

/*main function*/
int main(int argc, char *argv[]){ 
 
  char line [500]; /* or other suitable maximum line size */
  int i=1,j=1,m,n;
  char *filename= argv[1];/*read from arguments the name of the file*/
  FILE *file = fopen ( filename, "r" );
  
  do{
    printf("Hi,\ngive me positive integer (n):");
    scanf("%d",&n);
  }while(n<0);
  
  do{
    printf("\ngive me positive integer (m):");
    scanf("%d",&m);
  }while(m<0);
    
  SIZE_T=m*n;
  SIZE_OF_R=n;
  SIZE_OF_C=m;
   
  
  malloc_array();
  malloc_colums();
  init_arrays();
  if(argv[1]==NULL){
     printf("File Does Not Given By arguments!!\n",argv[1]); 
     exit(EXIT_FAILURE);
  }

  printf("File opened:%s\n",argv[1]);

  i=1;
  if ( file != NULL )/*if file exists*/
   {
     
      while ( fgets ( line, sizeof line, file ) != NULL )
      {
	
	value=strtok(line," ");
	j=1;
	while (value != NULL)
	{
	  
	  sudoku[i][j]=atoi(value);
	  j++;
	  value = strtok (NULL, " ");
	}
	i++;
	
	
      }
   }
   else/*if not exists*/
   {
     printf("File(%s) Not exists!!\n",argv[1]); 
     exit(EXIT_FAILURE);
   }
   
   fclose ( file );
   
   printf("\n");
   print_array();
   check_valid();
   
   Result();/*
   free_all_g_mem();*/
   return 0;
}