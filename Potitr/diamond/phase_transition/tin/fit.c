#include<stdio.h>
#include<stdlib.h>



int main(){

FILE* fp;
double e0,b0,bp,v0;

fp=fopen("fitdata","r");
int i;
if(fp==NULL){
printf("Error in reading file for post process.");
}

for(i=0;i<1;i++){
if(feof(fp))
break;
fscanf(fp," %le %le %le %le",&b0,&e0,&bp,&v0);

//printf("%le %le %le %le %le %le %le %le %le %le",step,atoms,pe,ke,etotal,press,vol,lx,ly,lz);
}
//double energy,volatom;


//energy=etotal/atoms;
//volatom=vol/atoms;

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);



FILE* fp1;
double cohe;

fp1=fopen("cohesive.txt","r");

if(fp1==NULL){
printf("Error in reading file for post process.");
}

for(i=0;i<1;i++){
if(feof(fp1))
break;
fscanf(fp1," %le",&cohe);
//printf("%le %le %le %le %le %le %le %le %le %le",step,atoms,pe,ke,etotal,press,vol,lx,ly,lz);
}
double ediff;


ediff=cohe-e0;
printf("\nE_bcc->fcc\t\t%lf\t\t(eV/atom)\n",ediff);

return 0;
}



