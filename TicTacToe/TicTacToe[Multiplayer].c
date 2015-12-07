/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2015-01-01 
*/
#include <stdio.h>
#include <stdlib.h>


char array[9];

/*
 * Function which init the public array of Chars
 */
void init_array(){
  int i;
  for(i=0;i<=9;i++)
  {
    array[i]=' ';
  }
  
}

/*
 * Function which prints only the pieces of the game which have Chars X or O or ' '
 */
void the_print(int i ,int j){
  
  if(i==1)
  {
    if(j==2)
      printf("%c",array[1]);
    if(j==6)
      printf("%c",array[2]);
    if(j==10)
      printf("%c",array[3]);
  }

  if(i==3)
  {
    if(j==2)
      printf("%c",array[4]);
    if(j==6)
      printf("%c",array[5]);
    if(j==10)
      printf("%c",array[6]);
  }
  
  if(i==5)
  {
    if(j==2)
      printf("%c",array[7]);
    if(j==6)
      printf("%c",array[8]);
    if(j==10)
      printf("%c",array[9]);
  }
  
}

/*
 * Function which prints the current status of the game
 */
void print_curr_status(){
  
  int i,j;
  int count=1;
  for(i=1;i<=5;i++)
  {
    for(j=1;j<=11;j++)
    {
      if(i%2==0)
      {
	if(j==4 || j==8)
	{
	  printf("+");
	}
	else
	{
	  printf("-");
	}
      }
      if(i%2!=0)
      {
	if(j==4 || j==8)
	{
	  printf("|");
	}
	else if(j==2 || j==6 || j==10)
	{
	  
	  the_print(i,j);
	  
	  
	}
	else
	{
	    printf(" ");
	}
    }
  } 
    printf("\n");
}
}



/*
 * Function which prints only the pieces of the game which have Chars X or O or ' '
 */
int pick_point(int point,int player){
  
  if(point==0 || point>9){
    printf("Wrong Place type again!!\n");
    return 2;
  }
  if(array[point]==' ')
  {
    if(player==1)
      array[point]='X';
    if(player==2)
      array[point]='O';
    printf("Correct Place!!\n");
    return 1;
  }
  else
  {
    printf("Wrong Place type again!\n");
    return 2;
  }
    
  
}

/*
 * Function which check the final points to win
 */
void check(int i,int j,int k){
  
  if(array[i]!=' ' && array[j]!=' ' && array[k]!=' '){
  if(array[i]==array[j]){
    if(array[j]==array[k])
    {
      printf("Player %c won!\n",array[i]);
      exit(EXIT_SUCCESS);
     
      
    }
      
    }
  }
  
}

/*
 * Function which all possible points for the win
 */
void check_if_someone_wins(){
  
  /*Katheta*/
  /*for 1,4,7*/
  check(1,4,7);
  /*for 2,5,8*/
  check(2,5,8);
  /*for 3,6,9*/
  check(3,6,9);
  
  /*Orizontia*/
  /*for 1,2,3*/
  check(1,2,3);
  /*for 4,5,6*/
  check(4,5,6);
  /*for 7,8,9*/
  check(7,8,9);
  
  /*Diagwnia!*/
  /*for 1,5,9*/
  check(1,5,9);
  /*for 7,5,3*/
  check(7,5,3);
  
}

/*
 * Main Function
 */
int main(int argc, char *argv[]){ 
  char buffer[128];
  int Player=1;
  int pick,again,yolo;
  init_array();
  
  print_curr_status();
  while(1)
  {
    if(Player == 1)/*Player 1 turn*/
    {
      again=2;
      while(again!=1){
      printf("Player X:");
      
      
      fgets(buffer,sizeof(buffer),stdin);
      pick = atoi(buffer); 
      if(pick>9)
	again=2;
      else
	again=pick_point(pick,1);
      Player=2;
      }
      printf("\n");
      print_curr_status();
      check_if_someone_wins();
      printf("\n------------------------\n");
      
      
    }
    else/*Player 2 turn*/
    {
      again=2;
      while(again!=1){
      printf("Player Y:");
      fgets(buffer,sizeof(buffer),stdin);
      pick = atoi(buffer); 
      if(pick>9)
	again=2;
      else
	again=pick_point(pick,2);
      Player=1;
      }
      printf("\n");
      print_curr_status();
      check_if_someone_wins();
      printf("\n------------------------\n");
     
    }
    
  }
  
  
  return 1;
}