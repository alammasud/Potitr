#include<math.h>
void  create_fcc_111(int nx, int ny, int nz, int ntot, double a, double* x, double* y, double* z,double* lx, double* ly, double* lz){

int i,j,k,t,l;

double vacuum;
vacuum=20;

double ax = a*sqrt(2)/2;
double  ay = a*sqrt(6)/2;
double  az = a*sqrt(3);
double   x0 = 0.0;
double  x2 = sqrt(2)/4*a;
double   y2 = sqrt(6)/4*a;
double y3 = sqrt(6)/6*a;
double  y4 = sqrt(6)*5/12*a;
double   y5 = sqrt(6)*2/6*a;
double   y6 = sqrt(6)/12*a;


lx[0]=nx*ax;lx[1]=0;lx[2]=0;
ly[0]=0;ly[1]=ny*ay;ly[2]=0;
lz[0]=0;lz[1]=0;lz[2]=az*nz+vacuum;

   double layer;

double unit[6][3];
unit[0][0]=x0;unit[0][1]=x0;unit[0][2]=0;
unit[1][0]=x2;unit[1][1]=y2;unit[1][2]=0;
unit[2][0]=x0;unit[2][1]=y3;unit[2][2]=0;
unit[3][0]=x2;unit[3][1]=y4;unit[3][2]=0;
unit[4][0]=x0;unit[4][1]=y5;unit[4][2]=0;
unit[5][0]=x2;unit[5][1]=y6;unit[5][2]=0;
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
