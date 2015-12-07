#include <stdio.h>


#define MGR		204
#define mGR		236
#define NGR		205
#define nGR		237
#define PGR		208
#define pGR		240
#define TGR		212
#define tGR		244

#define MEN		78
#define mEN		109
#define NEN		79
#define nEN		110
#define BEN		66
#define bEN		98
#define DEN		68
#define dEN		100


int cmap[256][3];
void initialize_cmap()//arxikopoiisi map se pinaka 2 diastasewn!i deuteri diastasi gia tonous kai dialutika
{
  cmap[181][1] = 34;//dialutika
  cmap[182][1] = 65;
  cmap[184][1] = 69;
  cmap[185][1] = 72;
  cmap[186][1] = 73;
  cmap[188][1] = 79;
  cmap[190][1] = 89;  
  cmap[191][1] = 87;
  cmap[192][1] = 34;//dialutika
  cmap[192][2] = 39;//tonos
  cmap[168][0] = 34;//dialutika
  cmap[180][0] = 39;//tonos
  cmap[181][0] = 39;//tonos
  cmap[182][0] = 39;//tonos
  cmap[184][0] = 39;//tonos
  cmap[185][0] = 39;//tonos
  cmap[186][0] = 39;//tonos
  cmap[188][0] = 39;//tonos
  cmap[190][0] = 39;//tonos
  cmap[191][0] = 39;//tonos
  cmap[192][0] = 105;
  cmap[193][0] = 65;
  cmap[194][0] = 86;
  cmap[195][0] = 71;
  cmap[196][0] = 68;
  cmap[197][0] = 69;
  cmap[198][0] = 90;
  cmap[199][0] = 72;
  cmap[200][0] = 56;
  cmap[201][0] = 73;
  cmap[202][0] = 75;
  cmap[203][0] = 76;
  cmap[204][0] = 77;
  cmap[205][0] = 78;
  cmap[206][0] = 75;
  cmap[207][0] = 79;
  cmap[208][0] = 80;
  cmap[209][0] = 82;
  cmap[211][0] = 83;
  cmap[212][0] = 84;
  cmap[213][0] = 89;
  cmap[214][0] = 70;
  cmap[215][0] = 88;
  cmap[216][0] = 80;
  cmap[217][0] = 87;
  cmap[218][0] = 34;//dialutika
  cmap[219][0] = 34;//dialutika
  cmap[220][0] = 97;
  cmap[221][0] = 101;
  cmap[222][0] = 104;
  cmap[223][0] = 105;     
  cmap[224][0] = 121;
  cmap[225][0] = 97;
  cmap[226][0] = 118;
  cmap[227][0] = 103;
  cmap[228][0] = 100;
  cmap[229][0] = 101;
  cmap[230][0] = 122;
  cmap[231][0] = 104;
  cmap[232][0] = 56;
  cmap[233][0] = 105;
  cmap[234][0] = 107;
  cmap[235][0] = 108;
  cmap[236][0] = 109;
  cmap[237][0] = 110;
  cmap[238][0] = 107;
  cmap[239][0] = 111;
  cmap[240][0] = 112;
  cmap[241][0] = 114;
  cmap[242][0] = 115;
  cmap[243][0] = 115;
  cmap[244][0] = 116;
  cmap[245][0] = 121;
  cmap[246][0] = 102;
  cmap[247][0] = 120;
  cmap[248][0] = 112;
  cmap[249][0] = 119;
  cmap[250][0] = 105;
  cmap[251][0] = 121;     
  cmap[252][0] = 111;
  cmap[253][0] = 121;
  cmap[254][0] = 119;
  cmap[206][1] = 83;     
  cmap[254][1] = 39;//tonos
  cmap[252][1] = 39;//tonos
  cmap[253][1] = 39;//tonos
  cmap[251][1] = 34;//dialutika
  cmap[250][1] = 34;//dialutika
  cmap[248][1] = 115;
  cmap[238][1] = 115;
  cmap[216][1] = 83;
  cmap[219][1] = 89;
  cmap[218][1] = 73;
  cmap[224][1] = 34;//dialutika
  cmap[224][2] = 39;//tonos 
  cmap[223][1] = 39;//tonos
  cmap[222][1] = 39;//tonos
  cmap[221][1] = 39;//tonos
  cmap[220][1] = 39;//tonos	
}


void printch(int c) {
	int d,i = 0;

	if(c==MGR){//periptwsi tou M ellinikou kefalaiou elegxei ean to epomeno einai p mikro i P kefalaio
		d=getchar();
		if((d==PGR)||(d==pGR))
		   putchar(BEN);
		else{//alliws emfanizei kai ta duo
		   putchar(cmap[c][i]);
		   while (cmap[d][i] != NULL && i < 3) putchar(cmap[d][i++]);}
	}

	else if(c==mGR){//periptwsi tou m ellinikou mikrou elegxei ean to epomeno einai p mikro i P kefalaio
		d=getchar();
		if((d==PGR)||(d==pGR))
		   putchar(bEN);
		else{//alliws emfanizei kai ta duo
		   putchar(cmap[c][i]);
		   while (cmap[d][i] != NULL && i < 3) putchar(cmap[d][i++]);}
	}
	
	else if(c==nGR){//periptwsi tou n ellinikou mikrou elegxei ean to epomeno einai t mikro i T kefalaio
		d=getchar();
		if((d==TGR)||(d==tGR))
		   putchar(dEN);
		else{//alliws emfanizei kai ta duo
		   putchar(cmap[c][i]);
		   while (cmap[d][i] != NULL && i < 3) putchar(cmap[d][i++]);}
	}
	else if(c==NGR){//periptwsi tou N ellinikou kefalaiou elegxei ean to epomeno einai t mikro i T kefalaio
		d=getchar();
		if((d==TGR)||(d==tGR))
		   putchar(DEN);
		else{//alliws emfanizei kai ta duo
		   putchar(cmap[c][i]);
		  while (cmap[d][i] != NULL && i < 3) putchar(cmap[d][i++]);}
	}
	
	
        else if (cmap[c][i] == NULL)//periptwsi pou den uparxei ston pinaka
		putchar(c);
	else 
	{while (cmap[c][i] != NULL && i < 3)//sunithismeni periptwsi xaraktirwn
		putchar(cmap[c][i++]);}
}



int main(void) {
	
	int 		ch;
	
	
	initialize_cmap();//arxikopoiisi
	
	
	while ((ch = getchar()) != EOF) {//diavasma xaraktira ena ena
		printch(ch);//kalesma sinartisis print
	}
	
	return 0;
}

