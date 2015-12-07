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

char *value;

int sudoku[10][10];
int valid[9],fail_colums[9],fail_rows[9],fail_block[9];


/*
 * Function which init valid array
 */
void init_valid(){
  int x;
  for(x=0;x<10;x++)
  {
    valid[x]=0;
  }
}


/*
 * Function which init all arrays
 */
void init_arrays(){
  int x,y;
   for(x=0;x<11;x++)
   {
    for(y=0;y<11;y++)
    {
     sudoku[x][y]=0;
    }
   }
   for(x=0;x<10;x++)
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
  for(i=1;i<10;i++)
  {
    for(j=1;j<10;j++)
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
   for(i=1;i<10;i++)
  {
    valid[sudoku[stable][i]]=1;
  }
  
  for(i=1;i<10;i++)
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
   for(i=1;i<10;i++)
  {
    valid[sudoku[i][stable]]=1;
  }
  
   for(i=1;i<10;i++)
   {
     if(valid[i] == 0){
	return 2;
     }
   }
  
  return 0;
}

/*
 * Function which pick fail blocks
 */
void pick_fail_block()
{
    int i,j;
    for(i=1;i<=3;i++)
    {
     for(j=1;j<=3;j++)
     {
	  
	  if(fail_rows[i]==2 && fail_colums[j]==2)
	  {
	    fail_block[1]=2;
	  }
     }
     for(j=4;j<=6;j++)
     {
       if(fail_rows[i]==2 && fail_colums[j]==2)
       {
	    fail_block[2]=2;
       }
     }
     for(j=7;j<=9;j++)
     {
       if(fail_rows[i]==2 && fail_colums[j]==2)
       {
	    fail_block[3]=2;
       }
     }
    }
    
    for(i=4;i<=6;i++)
    {
     for(j=1;j<=3;j++)
     {
	  if(fail_rows[i]==2 && fail_colums[j]==2)
	  {
	    fail_block[4]=2;
	  }
     }
     for(j=4;j<=6;j++)
     {
       if(fail_rows[i]==2 && fail_colums[j]==2)
       {
	    fail_block[5]=2;
       }
     }
     for(j=7;j<=9;j++)
     {
      if(fail_rows[i]==2 && fail_colums[j]==2)
       {
	    fail_block[6]=2;
       }
     }
    }
    
    for(i=7;i<=9;i++)
    {
     for(j=1;j<=3;j++)
     {
	  if(fail_rows[i]==2 && fail_colums[j]==2)
	  {
	    fail_block[7]=2;
	  }
     }
     for(j=4;j<=6;j++)
     {
       if(fail_rows[i]==2 && fail_colums[j]==2)
       {
	    fail_block[8]=2;
       }
     }
     for(j=7;j<=9;j++)
     {
       if(fail_rows[i]==2 && fail_colums[j]==2)
       {
	    fail_block[9]=2;
       }
     }
    }
  
}

/*
 * Function which check valid blocks
 */
void check_valid(){
 int i=1,j=1,colum=1,row=1; 
 
 /*colums*/
 while(row<10){
  fail_rows[row]=checkr(row);
  init_valid();
  row++;
 }
 
 while(colum<10){
  fail_colums[colum]=checkc(colum);
  init_valid();
  colum++;
 }
  
 pick_fail_block();
}

/*
 * Function which prints result
 */
void Result(){
  
  int i,flag;
  
  /*for row*/
  printf("Invalid rows: ");
  for(i=1;i<10;i++){
    
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
  for(i=1;i<10;i++){
    
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
  for(i=1;i<10;i++){
    
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

/*main function*/
int main(int argc, char *argv[]){ 
 
  char line [ 128 ]; /* or other suitable maximum line size */
  int i=1,j=1;
  char *filename= argv[1];/*read from arguments the name of the file*/
  FILE *file = fopen ( filename, "r" );
  init_arrays();
  printf("%s\n",argv[1]);
  
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
   
   Result();
   
   return 0;
}