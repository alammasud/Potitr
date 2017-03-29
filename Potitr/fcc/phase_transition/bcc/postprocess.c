#include<stdio.h>
#include<stdlib.h>



int main(){

FILE* fp;
double step, atoms, pe, ke, etotal, press, vol, lx, ly, lz;


fp=fopen("eout","r");
int i;
if(fp==NULL){
printf("Error in reading file for post process.");
}

for(i=0;i<1;i++){
if(feof(fp))
break;
fscanf(fp,"%le %le %le %le %le %le %le %le %le %le",&step,&atoms,&pe,&ke,&etotal,&press,&vol,&lx,&ly,&lz);
//printf("%le %le %le %le %le %le %le %le %le %le",step,atoms,pe,ke,etotal,press,vol,lx,ly,lz);
}
double cohesive_energy;


cohesive_energy=etotal/atoms;


 double cohe;
FILE* fp1;

fp1=fopen("cohesive.txt","r");

if(fp1==NULL){
printf("Error in reading file for post process.");
}

for(i=0;i<1;i++){
if(feof(fp1))
break;
fscanf(fp1,"%le",&cohe);
//printf("%le %le %le %le %le %le %le %le %le %le",step,atoms,pe,ke,etotal,press,vol,lx,ly,lz);
}
double ediff;
ediff=cohesive_energy-cohe;//cohse is the energy of bcc 

double latpara;
latpara=lx/5.0;

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("\nEfcc->bcc\t\t%lf\t\t(meV/atom)\nbcclat\t\t%.10lf\t\t(angstrom)\n",ediff*1000,latpara);

return 0;
}



