#include<math.h>

void  create_hcp(int nx, int ny, int nz, int ntot, double a, double* x, double* y, double* z,double* lx, double* ly, double* lz){

int i,j,k,t,l;


double c=sqrt(8.0/3.0)*a;

	double h[4][3];
	h[0][0]=0;h[0][1]=0;h[0][2]=0;
	h[1][0]=a/2.0;h[1][1]=a*sqrt(3.0)/2.0;h[1][2]=0;
	h[2][0]=0;h[2][1]=2.0*a/(sqrt(3.0));h[2][2]=c/2.0;
	h[3][0]=a/2.0;h[3][1]=a/(2.0*sqrt(3.0));h[3][2]=c/2.0;




lx[0]=nx*a;lx[1]=0;lx[2]=0;
ly[0]=0;ly[1]=ny*a*sqrt(3.0);ly[2]=0;
lz[0]=0;lz[1]=0;lz[2]=nz*c;

//lx[0]=nx*a;lx[1]=0;lx[2]=0;
//ly[0]=0;ly[1]=ny*a;ly[2]=0;
//lz[0]=0;lz[1]=0;lz[2]=nz*(a*cos(30*(M_PI/180)));

l=0;    
for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
                for(k=0;k<nz;k++){
                        for(t=0;t<4;t++){
                                x[l]=h[t][0]+i*a;
                                y[l]=h[t][1]+j*a*sqrt(3.0);
                                z[l]=h[t][2]+k*c;
                                l++;
                        }
                }
        }
}
}

      
       


