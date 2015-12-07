
/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2011-05-01 
*/

#include <stdio.h>
#include <stdlib.h>
char kout[6][14] = {"||_|_|_|_|_|\n","|_|_|_|_|_|\n","|_|_|_|_|_|\n","|_|_|_|_|_|\n","|_|_|_|_|_|\n","|_|_|_|_|_|\n"};
void pins();
void pino();
int epis(int);
int nik();


void main()/*KURIA SUNARTISI*/
{
  int x,y,i,j,ta,tb,N=0,A=1;

  do
  {
    if (N!=2)
    {
      printf("Paiktis 1:epelekse stili apo 1 mexri 5:\n");
      scanf("%d",&x);
      x=epis(x);
      pins(x);
      N=nik();
    }

 
    if (N!=1)
    {
      printf("Paiktis 2:epelekse stili:\n");
      scanf("%d",&y);
      y=epis(y);
      pino(y);
      N=nik();
    }
  }


  
  while (N==0);
  {
    if (N==1)
      printf("\nNikitis einai o Paiktis1\n");
    else if (N==2)
      printf("\nNikitis einai o Paiktis2\n");
    else
      printf("\nIsopalia irthe to paixnidi\n");
  }


}


void pins(int x)/*SUNARTISI ME TIN OPOIA EMFANIZOUME TON PINAKA GIA TO 'S'*/
{ 
  int i,j,y;
  y=5;
  
  if (kout[y][x]!='_')
  
  do
  {
    y--;
  }
  while (kout[y][x]!='_');

  kout[y][x]='S';

  for(i=0;i<6;i++)
  {
    for (j=1;j<=14;j++)
      printf("%c", kout[i][j]);
  }

}



void pino(int x)/*IDIA SUNARTISI ME PANW ALLA ME TO 'O'*/
{ 
  int i,j,y;
  y=5; 
 
  if (kout[y][x]!='_')
  
  do
  {
    y--;
  }
  while (kout[y][x]!='_');

  kout[y][x]='O';

  for(i=0;i<=6;i++)
  {
    for (j=1;j<=14;j++)
      printf("%c" ,kout[i][j]);
  }

}




int epis(int x)/*SUNARTISI ME TIN OPOIA RITHMIZOUME TO KELI TOU PINAKA POU THA PAEI TO GRAMMA*/
{ 
  int w;
  if (x==1)
  {  w=1;
     return w;
  }
  else if (x==2)
  {  w=3;
     return w;
  }
  else if (x==3)
  {  w=5;
     return w;
  }
  else if (x==4)
  {  w=7;
     return w;
  }
  else if (x==5)
  {  w=9;
     return w;
  }
  else
  {do
  {
   printf("Lathos timi ksanadwse timi:\n");
   scanf("%d",&x);
   }while ((x<5)&&(x<1));
   w=epis(x);/*KALW ANADROMIKA TIN SUNARTISI GIA NA RITHMISW PALI TO KELI*/
   return w;
   }
}

int nik()
{
  int i,t;
  t=0;
  for(i=0;i<6;i++)
   {  if  (((kout[i][1]=='S')&&(kout[i][3]=='S')&&(kout[i][5]=='S'))||((kout[i][3]=='S')&&(kout[i][5]=='S')&&(kout[i][7]=='S'))||((kout[i][5]=='S')&&(kout[i][7]=='S')&&(kout[i][9]=='S')))
       t=1;
     else if (((kout[i][1]=='O')&&(kout[i][3]=='O')&&(kout[i][5]=='O'))||((kout[i][3]=='O')&&(kout[i][5]=='O')&&(kout[i][7]=='O'))||((kout[i][5]=='O')&&(kout[i][7]=='O')&&(kout[i][9]=='O')))
       t=2;
     
   }
  for (i=1;i<=14;i+=2)
  { if (((kout[1][i]=='S')&&(kout[2][i]=='S')&&(kout[3][i]=='S'))||((kout[0][i]=='S')&&(kout[1][i]=='S')&&(kout[2][i]=='S'))||((kout[2][i]=='S')&&(kout[3][i]=='S')&&(kout[4][i]=='S'))||((kout[5][i]=='S')&&(kout[3][i]=='S')&&(kout[4][i]=='S')))
       t=1;
    else if (((kout[0][i]=='O')&&(kout[1][i]=='O')&&(kout[2][i]=='O'))||((kout[1][i]=='O')&&(kout[2][i]=='O')&&(kout[3][i]=='O'))||((kout[2][i]=='O')&&(kout[3][i]=='O')&&(kout[4][i]=='O'))||((kout[5][i]=='O')&&(kout[3][i]=='O')&&(kout[4][i]=='O')))
       t=2;
  }
   return t;
}