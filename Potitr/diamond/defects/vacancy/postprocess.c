#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main(){

FILE* fp;
double step, pe, ke, etotal, press, vol, lx, ly, lz;
int atoms;

fp=fopen("eout","r");
int i;
if(fp==NULL){
printf("Error in reading file for post process.");
}

for(i=0;i<1;i++){
if(feof(fp))
break;
fscanf(fp,"%le %i %le %le %le %le %le %le %le %le",&step,&atoms,&pe,&ke,&etotal,&press,&vol,&lx,&ly,&lz);
//printf("\n%lf\n %lf\n %lf\n %lf\n %lf\n %lf\n %lf\n %lf\n %lf\n %lf\n",step,atoms,pe,ke,etotal,press,vol,lx,ly,lz);
}
//printf("%i",atoms);
double Ev,cohe;
//area=lx*ly;
//int duplicate;
//duplicate=pow((atoms+1)/4,(1/3));

//printf("%i",atoms);
FILE* kachu;

kachu=fopen("cohesive.txt","r");
fscanf(kachu,"%le",&cohe);


Ev=etotal-atoms*(cohe);//convesion factor to convert into mj/m2

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("\nEv\t\t%lf\t\t(eV)\n",Ev);
fclose(fp);
fclose(kachu);
return 0;
}



