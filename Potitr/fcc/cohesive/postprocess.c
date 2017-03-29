#include<stdio.h>
#include<stdlib.h>
#include<math.h>



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

int mutu;
mutu=atoms/(4*5*5);
double latpara;
latpara=lx/mutu;
cohesive_energy=etotal/atoms;
vol_per_atom=vol/atoms;
//double ll;
//ll=pow((2*vol_per_atom),(1/3));

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("\nE_0\t\t%20.20lf\t\t(eV/atom)\na_0\t\t%20.20lf\t\t(angstrom)\nV_0\t\t%lf\t\t(angstrom^3/atom)\n",cohesive_energy,latpara,vol_per_atom);

return 0;
}



