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
//double Esurface,area,cohesiveenergy;
double area=lx*lz;
double  dist;
FILE* fn;
fn=fopen("displacement.txt","r");
fscanf(fn,"%lf ",&dist);

//duplicate=atoms/(2*2*2);


//Esurface=((etotal-atoms*(-cohesiveenergy))/(2*area))*16021.765;//convesion factor to convert into mj/m2

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("%lf %lf  %lf\n",dist,area,pe);

return 0;
}



