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
}
double Esurface,area,cohesiveenergy;
area=lx*ly;
//int duplicate;
FILE* fn;
fn=fopen("cohesive.txt","r");
fscanf(fn,"%le ",&cohesiveenergy);

//duplicate=atoms/(5*5*2);


Esurface=((etotal-atoms*(cohesiveenergy))/(2*area))*1000;//convesion factor to convert into mj/m2

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("\nE_100\t\t%lf\t\t(meV/ang2)\n",Esurface);

return 0;
}



