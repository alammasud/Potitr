#include<stdio.h>
#include<stdlib.h>

//void equilibrium_properties(double cohesive_energy,double vol_per_atom,double etotal,double vol, double atoms){

//cohesive_energy=etotal/atoms;
//vol_per_atom=vol/atoms;
//}


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
double uu,kachu;
FILE* fp2;
fp2=fopen("displacement.txt","r");
for(i=0;i<1;i++){
if(feof(fp2))
break;
fscanf(fp2,"%le %le",&uu,&kachu);
}
double cohe;
FILE* fp3;
fp3=fopen("cohesive.txt","r");
for(i=0;i<1;i++){
if(feof(fp3))
break;
fscanf(fp3,"%le",&cohe);
}



//double eper;
//eper=etotal/atoms;
double strain_energy;


strain_energy=etotal/(5*5*5*kachu*kachu*kachu);//strain energy density

//equilibrium_properties(cohesive_energy,vol_per_atom,etotal,vol,atoms);
printf("%20.20lf\t%20.20lf\n",uu,strain_energy);
fclose(fp);
fclose(fp2);
fclose(fp3);
return 0;
}

