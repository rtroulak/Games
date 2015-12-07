
/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2015-01-01 
*/

#include <stdio.h>
#include <stdlib.h>
void srand( unsigned seed );



void main()
{ 

    char pin[26]={"abcdefghijklmnopqrstuvwxyz"};
    char c,x,e[15];
    char lekseis[10][8]={"chairs","public","ultras","alepou","kounia","loader","adults","agrios","adults","skoufi","yolo","kamia","paixnidi","programmatismos"};
    srand( time(NULL) );
    int i,N,rand(),t=0,j=0,y=0,a,f=0;
    int k=rand();
    printf("dwse arithmo lathwn pou mporeis na kaneis:\n");
    scanf("%d",&N);
    k=(k%10);
    
  
    for(i=0;i<10;i++)
    { 
      if (i==0)
      {
        printf("%c",lekseis[k][0]);
        e[i]=lekseis[k][0];}
      else if (i==5)
      {
        printf("%c",lekseis[k][5]);
        e[i]=lekseis[k][5];}
      else if (i>5)
	    {
        e[i]=' ';
        printf("%c",e[i]);}
      else
      {
        e[i]='.';
       printf("%c",e[i]);}
      }
     
      printf("\nErrors = %d out of %d\n",y,N);
      printf("Available Char:");
      
      for(i=0;i<26;i++)
       printf("%c ",pin[i]);
      
      printf("\nGive a Char:\n");
      scanf("%c",&c);
      
      for(i=0;i<26;i++)
      {
        if (pin[i]==c)
        { 
          pin[i]=' ';
        }
      }

     x=getchar();
     
      while ((t<4)||(y<=N)) 
      { 
        for(i=0;i<8;i++)
        if (i==0)
          printf("%c",e[0]);
        else if (i==5)
          printf("%c",e[5]);
        else if (lekseis[k][i]==x)
        {
          printf("%c",lekseis[k][i]);
          e[i]=lekseis[k][i];
	        t++;
	        y--;
	      }
        else 
          printf("%c",e[i]);
         
        y++;
      
        if (t==4)
	      {
          printf("\nEnikises mpre su!!!!!!!!!!!!!!!Etsa Bravo.... :)\n");
	        break;
	      }
	 
        if (y>=N)
	      {
          printf("\nErrors = %d out of %d\n",y,N);
	        printf("\nGame Over I am Sorry arxige mou :P\n");
	        break;
	      }
	 
        printf("\nErrors = %d out of %d\n",y,N);
	      printf("Available Char:");
	  
        for(i=0;i<26;i++)
          printf("%c ",pin[i]);
            

        printf("\nGive a Char:\n");
        scanf("%c",&c);
	  
        for(i=0;i<26;i++)
        {
          if (pin[i]==c)
          pin[i]=' ';
        }
          
        x=getchar();
	}
}