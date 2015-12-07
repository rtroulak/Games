/**
* 
* @author  Troulakis Georgios Rafail <rtroulak@gmail.com> 
* @version 1.0
* @since   2015-01-01 
*/

#include<stdio.h> 



int elax_koin_pollap(int x,int y){
  
  int max,temp;
  
  if(x>y)
    temp=max=x;
  else
    temp=max=y;
  
  while(1){
    
    if(max%x==0 && max%y==0)
      return max;
    else
      max=max+temp;
    
    
  }
  
  
  
}



int main(int argc, char *argv[]){
  
  int x1,x2,y1,y2,ekp=0,tempx,tempy;
  
  /*diavasma akeraiwn*/
  printf("Dwse prwto klasma (arithmiti,paranomasti):");
  scanf("%d",&x1);
  scanf("%d",&x2);
  printf("Dwse deutero klasma (arithmiti,paranomasti):");
  scanf("%d",&y1);
  scanf("%d",&y2);
  
  
  /*elegxos gia mi orimena klasmata*/
  if(x2==0){
    
    printf("To prwto klasma den orizetai dioti exei paranomasti iso me to miden!\n");
    return 0;
  }
  
  if(y2==0){
    
    printf("To deutero klasma den orizetai dioti exei paranomasti iso me to miden!\n");
    return 0;
  }
  
  /*evresi elaxistou koinou pollaplasiou*/
  ekp=elax_koin_pollap(x2,y2);
  
  printf("\n\nExoume ta klasmata %d/%d + %d/%d \ntwn opoiwn oi paranomastes exoun elaxisto koino pollaplasio to <%d>!\n",x1,x2,y1,y2,ekp);
  
  /*upologimos newn klasmatwn analogws to elaxisto koino pollaplasio*/
  tempx=ekp/x2;
  tempy=ekp/y2;
  x1=tempx*x1;
  y1=tempy*y1;
  
  /*praksi kai emfanisi neou klasmatos*/
  printf("\n\ni praksi einai:\n%d/%d + %d/%d =\n[%d/%d]\n",x1,ekp,y1,ekp,x1+y1,ekp);
  
  
  return 1;
}