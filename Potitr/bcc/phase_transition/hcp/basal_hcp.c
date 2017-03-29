#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void basal_hcp(int nx, int ny, int nz, int ntot, double a, double* x, double* y, double* z,double* lx, double* ly, double* lz){

double pivalue,pioverthree,pioversix,ac;
ac=sqrt(8.0/3.0)*a;
pivalue=2.0*asin(1.0);
pioverthree=pivalue/3.0;
pioversix=pivalue/6.0;
double r1,r2,r3;
r1=(2.0/3.0)*a*cos(pivalue/3.0)+(1.0/3.0)*a*cos(pivalue/3.0);
r2=ac*0.5;
r3=(2.0/3.0)*a*sin(pivalue/3.0)-(1.0/3.0)*a*sin(pivalue/3.0);
double unit[4][3];
unit[0][0]=0;unit[0][1]=0;unit[0][2]=0;
unit[1][0]=a*sin(pivalue/6.0);unit[1][1]=0;unit[1][2]=a*cos(pivalue/6.0);
unit[2][0]=r1;unit[2][1]=r2;unit[2][2]=r3;
unit[3][0]=r1+a*sin(pivalue/6.0); unit[3][1]=r2;unit[3][2]=r3+a*cos(pivalue/6.0);

lx[0]=nx*a;lx[1]=0.0;lx[2]=0.0;
ly[0]=0.0;ly[1]=ny*ac;ly[2]=0.0;
lz[0]=0.0;lz[1]=0.0;lz[2]=nz*2*a*cos(pivalue/6.0);


int i,j,k,l,t;
t=0;
for(i=0;i<nx;i++){
 for(j=0;j<ny;j++){
  for(k=0;k<nz;k++){
    for(l=0;l<4;l++){
      x[t]=unit[l][0]+i*a;
      y[t]=unit[l][1]+j*ac;
      z[t]=unit[l][2]+k*2*a*cos(pivalue/6.0);
      t++;
      }
}
}
}
}
