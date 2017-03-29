#include<math.h>
void  create_diamond_110(int nx, int ny, int nz, int ntot, double a, double* x, double* y, double* z,double* lx, double* ly, double* lz){

int i,j,k,t,l;



double ax=a*sqrt(6)/2;
double ay=a*sqrt(2)/2;
double az=a*sqrt(3);

lx[0]=nx*ax;lx[1]=0;lx[2]=0;
ly[0]=0;ly[1]=ny*ay;ly[2]=0;
lz[0]=0;lz[1]=0;lz[2]=nz*az;
double unit[12][3];

   unit[0][0]=0;unit[0][1]=0;unit[0][2]=0;
   unit[1][0]=0;unit[1][1]=0;unit[1][2]=3.0*az/4.0;
   unit[2][0]=ax/3.0;unit[2][1]=0.0;unit[2][2]=az/12.0;
   unit[3][0]=ax/3.0;unit[3][1]=0.0;unit[3][2]=az/3.0;
   unit[4][0]=2*ax/3.0;unit[4][1]=0.0;unit[4][2]=5*az/12.0;
   unit[5][0]=2*ax/3.0;unit[5][1]=0.0;unit[5][2]=2*az/3.0;
   unit[6][0]=ax/6.0;unit[6][1]=ay/2.0;unit[6][2]=5*az/12.0;
   unit[7][0]=ax/6.0;unit[7][1]=ay/2.0;unit[7][2]=2*az/3.0;
   unit[8][0]=ax/2.0;unit[8][1]=ay/2.0;unit[8][2]=0.0;
   unit[9][0]=ax/2.0;unit[9][1]=ay/2.0;unit[9][2]=3*az/4.0;
   unit[10][0]=10*ax/12.0;unit[10][1]=ay/2.0;unit[10][2]=az/12.0;
   unit[11][0]=10*ax/12.0;unit[11][1]=ay/2.0;unit[11][2]=az/3.0;

l=0; 
  for(i=0;i<nx;i++){ 
     for(j=0;j<ny;j++){ 
       for(k=0;k<nz;k++){ 
	 for(t=0;t<12;t++){
	   x[l]=unit[t][0]+i*ax;
	   y[l]=unit[t][1]+j*ay;
	   z[l]=unit[t][2]+k*az;
	   l++;
	 }
       }
     }
  }
}
