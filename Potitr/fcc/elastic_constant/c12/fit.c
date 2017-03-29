#include<stdio.h>
#include<stdlib.h>



int main(){

FILE* fp;
double aa,bb,cc;

fp=fopen("fitdata","r");
int i;
if(fp==NULL){
printf("Error in reading file for post process.");
}

for(i=0;i<1;i++){
if(feof(fp))
break;
fscanf(fp," %le %le %le",&aa,&bb,&cc);
//printf("%le %le %le %le %le %le %le %le %le %le",step,atoms,pe,ke,etotal,press,vol,lx,ly,lz);
}
//double energy,volatom;

FILE* fp1;
double kk;
fp1=fopen("bal","r");

if(fp1==NULL){
printf("Error in reading file for post process.");
}

for(i=0;i<1;i++){
if(feof(fp1))
break;
fscanf(fp1," %le",&kk);
//printf("%le %le %le %le %le %le %le %le %le %le",step,atoms,pe,ke,etotal,press,vol,lx,ly,lz);
}

//energy=etotal/atoms;
//volatom=vol/atoms;
double c12;
double bal;
bal=aa*2*160.217646;
c12=(2*kk-bal)/2;

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("c12\t\t%lf\t\t(GPa)\n",c12);
fclose(fp);
fclose(fp1);

return 0;
}



