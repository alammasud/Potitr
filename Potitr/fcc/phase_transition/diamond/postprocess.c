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
double cohesive_energy,vol_per_atom;


cohesive_energy=etotal/atoms;
vol_per_atom=vol/atoms;

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("%20.20lf\t%20.20lf\n",cohesive_energy,vol_per_atom);

return 0;
}



