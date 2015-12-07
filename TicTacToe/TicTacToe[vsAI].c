/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2015-01-01 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char array[3][3];
int numberinfunc=0;

/*
 * Function which init the public array of Chars
 */
void init_array(){
  int i,j;
  for(i=0;i<=3;i++)
  {
    for(j=0;j<=3;j++){
      array[i][j]=' ';
    }
  }

}


/*
 * Function which check the final points to win
 */
int check_cpu(int pi,int pj,int di,int dj,int ti,int tj,char a[3][3]){
  int e;
  char end;
  if(a[pi][pj]=='X' && a[di][dj]=='X' &&  a[ti][tj]==' ')
  {
    if(a[pi][pj]==a[di][dj])
    {
      
      a[ti][tj]='O';
      return 1;
    }
  }
  else if( a[di][dj]=='X' && a[ti][tj]=='X' &&  a[pi][pj]==' ')
  {
     if(a[di][dj]==a[ti][tj])
    {
    
     
      a[pi][pj]='O';
      return 1;
    }
  }
  else if( a[pi][pj]=='X' && a[ti][tj]=='X')
  {
     if(a[pi][pj]==a[ti][tj] &&  a[di][dj]==' ')
    {
      
      a[di][dj]='O';
      return 1;
    }
  }
  return 0;
}

/*
 * Function which try to avoid lose
 */
int avoid_lose(char a[3][3]){
  
  int picked=0;
  /*Katheta*/
  /*for 1,4,7*/
  if(!picked)
  picked=check_cpu(0,0,0,1,0,2,a);
  /*for 2,5,8*/
  if(!picked)
  picked=check_cpu(1,0,1,1,1,2,a);
  /*for 3,6,9*/
  if(!picked)
  picked=check_cpu(2,0,2,1,2,2,a);

  /*Orizontia*/
  /*for 1,2,3*/
  if(!picked)
  picked=check_cpu(0,0,1,0,2,0,a);
  /*for 4,5,6*/
  if(!picked)
  picked=check_cpu(0,1,1,1,2,1,a);
  /*for 7,8,9*/
  if(!picked)
  picked=check_cpu(0,2,1,2,2,2,a);

  /*Diagwnia!*/
  /*for 1,5,9*/
  if(!picked)
  picked=check_cpu(0,0,1,1,2,2,a);
  /*for 7,5,3*/
  if(!picked)
  picked=check_cpu(2,0,1,1,0,2,a);

  return picked;
}


int randInRange(int min, int max)
{
  return min + (int) (rand() / (double) (RAND_MAX) * (max - min + 1));
}


/*
 * Function which playing the moves of computer
 */

void cpu_playing(char a[3][3])
{
  int randr,randc,ready=0;
  if(a[1][1]==' ')
    a[1][1]='O';
  else
  {
   int picked;
   picked=avoid_lose(a);
   if(!picked)
   {
      
      while(ready==0)
      {
	randr=randInRange(0, 2);
	randc=randInRange(0, 2);
	if(a[randr][randc]==' ')
	{
	  a[randr][randc]='O';
	  ready=1;
	}
      }
  }
}
}


/*
 * Function which check the final points to win
 */
void check(int pi,int pj,int di,int dj,int ti,int tj){
  int e;
  char end;
  if(array[pi][pj]!=' ' && array[di][dj]!=' ' && array[ti][tj]!=' '){
  if(array[pi][pj]==array[di][dj]){
    if(array[di][dj]==array[ti][tj])
    {
      printf("Player %c won!\n",array[pi][pj]);
      exit(EXIT_SUCCESS);
      
    }

    }
  }

}

void check_for_tied()
{
  int i,j,flag=0;
  for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
   {
     if(array[i][j]==' ')
       flag=1;
   }
  }
  
  if(!flag)
    {
      printf("We Have Tied!\n");
      exit(EXIT_SUCCESS);
      
    }
    
}

/*
 * Function which all possible points for the win
 */
void check_if_someone_wins(){

  /*Katheta*/
  /*for 1,4,7*/
  check(0,0,0,1,0,2);
  /*for 2,5,8*/
  check(1,0,1,1,1,2);
  /*for 3,6,9*/
  check(2,0,2,1,2,2);

  /*Orizontia*/
  /*for 1,2,3*/
  check(0,0,1,0,2,0);
  /*for 4,5,6*/
  check(0,1,1,1,2,1);
  /*for 7,8,9*/
  check(0,2,1,2,2,2);

  /*Diagwnia!*/
  /*for 1,5,9*/
  check(0,0,1,1,2,2);
  /*for 7,5,3*/
  check(2,0,1,1,0,2);

}

/*
 * Function which prints he point
 */
void the_print(int i ,int j){

  if(i==1)
  {
    if(j==2)
      printf("%c",array[0][0]);
    if(j==6)
      printf("%c",array[0][1]);
    if(j==10)
      printf("%c",array[0][2]);
  }

  if(i==3)
  {
    if(j==2)
      printf("%c",array[1][0]);
    if(j==6)
      printf("%c",array[1][1]);
    if(j==10)
      printf("%c",array[1][2]);
  }

  if(i==5)
  {
    if(j==2)
      printf("%c",array[2][0]);
    if(j==6)
      printf("%c",array[2][1]);
    if(j==10)
      printf("%c",array[2][2]);
  }

}

/*
 * Function which prints the current status of the game
 */
void print_tictactoe(){

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
 * Tic-Tac-Toe
 */
int tictactoe(char a[3][3], char player){
  int d,ready=0;
  int column,row;
  numberinfunc++; 
  printf("\n-----------------------------------------\n");
  printf("player = %c  (move %d)\n",player,numberinfunc);
  
   
  if(player=='X'){
    
 
    while(ready==0){
     
    printf("choose your move:\nrow:");
    scanf("%d",&row);
    printf("column:");
    scanf("%d",&column);
    if(row>2 || column>2 || row<0 || column<0){
      printf("Invalid Move,Try again!\n");
    }
    else if(a[row][column]==' ')
    {
      printf("Valid move!\n");
      a[row][column]='X';
      ready=1;
    }
    
    else
    {
      printf("Invalid Move,Try again!\n");
    }
    }
  }
  else if(player=='O')
  {
    cpu_playing(a);
  }
  
     
  
  
  if(player=='X')
    player='O';
  else if(player=='O')
    player='X';
  
  
  printf("\nCurrent Status of Tic TaC ToE:\n");
  print_tictactoe();
  check_for_tied();
  check_if_someone_wins();
  
  tictactoe(a,player);
}

/*
 * Main Function
 */


int main(int argc, char *argv[]){

  char buffer[128];
  char Player;
  int playerNum;
  int pick,again,yolo; 
  char ch, file_name[25];
  FILE *fp;
  init_array();

  printf("Begining Status:\n");
  print_tictactoe();
  
  srand(time(NULL));
  playerNum = 1 + rand() % 2; /* Random number is generated */
  if(playerNum==1)
    Player='X';
  else
    Player='O';
  
  
  
  tictactoe(array,Player);
  


  return 1;
}
