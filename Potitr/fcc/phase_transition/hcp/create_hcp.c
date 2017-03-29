
void  create_hcp(int nx, int ny, int nz, int ntot, double a, double* x, double* y, double* z,double* lx, double* ly, double* lz){

int i,j,k,t,l;
double unit[4][3];

unit[0][0]=0;unit[0][1]=0;unit[0][2]=0;
unit[1][0]=0.5*a;unit[1][1]=0.866*a;unit[1][2]=0;
unit[2][0]=0.5*a;unit[2][1]=0.288751346*a;unit[2][2]=0.5*1.633*a;
unit[3][0]=0;unit[3][1]=1.1547*a;unit[3][2]=0.5*1.633*a;

lx[0]=nx*a;lx[1]=0;lx[2]=0;
ly[0]=0;ly[1]=ny*a*1.732;ly[2]=0;
lz[0]=0;lz[1]=0;lz[2]=a*nz*1.633;

l=0;    
for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
                for(k=0;k<nz;k++){
                        for(t=0;t<4;t++){
                                x[l]=unit[t][0]+i*a;
                                y[l]=unit[t][1]+j*a*1.732;
                                z[l]=unit[t][2]+k*a*1.633;
                                l++;
                        }
                }
        }
}
}

      
       


