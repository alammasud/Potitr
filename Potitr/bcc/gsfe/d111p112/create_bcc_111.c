#include<math.h>
void  create_bcc_111(int nx, int ny, int nz, int ntot, double a, double* x, double* y, double* z,double* lx, double* ly, double* lz){

int i,j,k,t,l;



double ax = a*sqrt(6);
double  ay = a*sqrt(2);
double  az = a*sqrt(3)/2;


lx[0]=nx*ax;lx[1]=0;lx[2]=0;
ly[0]=0;ly[1]=ny*ay;ly[2]=0;
lz[0]=0;lz[1]=0;lz[2]=nz*az;

   double layer;

double unit[6][3];
unit[0][0]=0;unit[0][1]=0;unit[0][2]=0;
unit[1][0]=ax/2;unit[1][1]=ay/2;unit[1][2]=0;
unit[2][0]=ax/3;unit[2][1]=0;unit[2][2]=0;
unit[3][0]=5*ax/6;unit[3][1]=ay/2;unit[3][2]=0;
unit[4][0]=ax/6;unit[4][1]=ay/2;unit[4][2]=0;
unit[5][0]=2*ax/3;unit[5][1]=0;unit[5][2]=0;
l=0; 
  for(i=0;i<nx;i++){ 
     for(j=0;j<ny;j++){
       layer=0;
       for(k=0;k<nz;k++){ 
	 for(t=0;t<6;t++){
	   x[l]=unit[t][0]+i*ax;
	   y[l]=unit[t][1]+j*ay;
	   z[l]=unit[t][2]+(layer*az)/3;
           if(t%2==1){
	      layer+=1;
             }
	   l++;
	 }
       }
     }
  }
}
