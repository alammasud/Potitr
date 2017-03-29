#include<stdio.h>
#include<stdlib.h>



int main(){

FILE* fp;
double b0,e0,bp,v0;

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
printf("\nB_0\t\t%lf\t\t(GPa)\nE0\t\t%lf\t\t(eV/atom)\nBp\t\t%lf\nv0\t\t%lf\t\t(angstrom^3/atom)\n",b0*160.217646,e0,bp,v0);

return 0;
}



