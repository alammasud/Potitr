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


//energy=etotal/atoms;
//volatom=vol/atoms;

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("\nc11\t\t%lf\t\t(GPa)\n",aa*160.217646*2);

return 0;
}



