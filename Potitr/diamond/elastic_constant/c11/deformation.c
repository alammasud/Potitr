#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"create_diamond.h"

void matrixmulti(double a[3][3],double b[3][3],double c[3][3]){
double sum;
sum=0;
int i,j,k;

 for ( i = 0 ; i< 3 ; i++ )
    {
      for ( j = 0 ; j < 3 ; j++ )
      {
        for ( k = 0 ; k < 3 ; k++ )
        {
          sum = sum + a[i][k]*b[k][j];

        }
 
        c[i][j] = sum;
        sum = 0;
      }
    }
}

double dotproduct(double a[3],double b[3]){



return (a[0]*b[0]+a[1]*b[1]+a[2]*b[2]);

}

void crossproduct(double a[3],double b[3],double c[3]){

c[0]=a[1]*b[2]-a[2]*b[1];
c[1]=-a[0]*b[2]+b[0]*a[2];
c[2]=a[0]*b[1]-a[1]*b[0];

}

double norm(double* a){

double q;

q=sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);

return q;
}




void inverse(double a[3][3],double b[3][3]){

    int i,j;
    double determinant=0;

   // printf("Enter the 9 elements of matrix: ");
   // for(i=0;i<3;i++)
   // for(j=0;j<3;j++)
   // scanf("%f",&a[i][j]);

    //printf("\nThe matrix is\n");
    //for(i=0;i<3;i++){
    //printf("\n");
    //for(j=0;j<3;j++)
    //printf("%f\t",a[i][j]);
   // }

    for(i=0;i<3;i++)
    determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));

//    printf("\nInverse of matrix is: \n\n");
    for(i=0;i<3;i++){
//printf("\n");
    for(j=0;j<3;j++)
    b[i][j]=((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/ determinant;

//printf("%f\n",b[i][j]);

    }
}



void deformation(double* x, double* y, double* z,double* lx,double* ly, double* lz, double* strain,int ntot,double a,int nx,int ny, int nz){
 create_diamond( nx, ny, nz, ntot, a, x,y,z,lx,ly,lz);

double uu;

FILE* strainfile;
  strainfile=fopen("displacement.txt","r");
          if(strainfile==NULL)
          {
                  printf("No datas can be found in the File");
                  exit(1);
          }
  
          while(fscanf(strainfile," %le ", &uu) != feof(strainfile))
          {
             //printf("=%le\n",a);
           break;
          }
  
          fclose(strainfile);



//if(index==0){
//strain[0]=0;strain[1]=0;strain[2]=0;
//strain[3]=0;strain[4]=0;strain[5]=0;
//}
//else if(index==1){
strain[0]=uu;strain[1]=0;strain[2]=0;
 strain[3]=0;strain[4]=0;strain[5]=0;
//}
//else if(index==2){
//strain[0]=uu;strain[1]=(-1)*uu;strain[2]=0;
  //strain[3]=0;strain[4]=0;strain[5]=0;
//}

//else if(index==3){
 //strain[0]=0;strain[1]=0;strain[2]=0;
 // strain[3]=2*uu;strain[4]=0;strain[5]=0;
// }

double ax[3],ay[3],az[3];

ax[0]=(1+strain[0])*lx[0];
ax[1]=0.5*strain[5]*lx[0];
ax[2]=0.5*strain[4]*lx[0];


ay[0]=0.5*strain[5]*ly[1];
ay[1]=(1+strain[1])*ly[1];
ay[2]=0.5*strain[3]*ly[1];


  az[0]=0.5*strain[4]*lz[2];
  az[1]=0.5*strain[3]*lz[2];
  az[2]=(1+strain[2])*lz[2];


int i;


double bx,by,bz;
 bx=norm(ax);
 by=norm(ay);
 bz=norm(az);

// printf("%le\t%le\t%le\n",bx,by,bz);


double alpha,beta,gamma;

alpha=acos(dotproduct(ay,az)/(by*bz));
beta=acos(dotproduct(ax,az)/(bx*bz));
gamma=acos(dotproduct(ax,ay)/(bx*by));



double xlo,xhi,ylo,yhi,zlo,zhi,xy,xz,yz;

xlo=0;ylo=0;zlo=0;

xhi=bx;
yhi=sin(gamma)*by;
xy=cos(gamma)*by;
xz=cos(beta)*bz;
yz=( by * bz * cos(alpha)-xy*xz)/ yhi;

zhi = sqrt( bz*bz - xz*xz - yz*yz );




double newboxx[3],newboxy[3],newboxz[3];

newboxx[0]=xhi-xlo;
newboxx[1]=0;
newboxx[2]=0;

newboxy[0]=xy;
newboxy[1]=yhi-ylo;
newboxy[2]=0;

newboxz[0]=xz;
newboxz[1]=yz;
newboxz[2]=zhi-zlo;


double rotation[3][3];

double inver[3][3],cell[3][3];


for(i=0;i<3;i++){//cell after applying strain
cell[0][i]=ax[i];
cell[1][i]=ay[i];
cell[2][i]=az[i];
}

double box[3][3];//box according to lammps input for triclinic

for(i=0;i<3;i++){
box[0][i]=newboxx[i];
box[1][i]=newboxy[i];
box[2][i]=newboxz[i];
}


inverse(cell,inver);

matrixmulti(inver,box,rotation);


for(i=0;i<3;i++){

lx[i]=newboxx[i];
ly[i]=newboxy[i];
lz[i]=newboxz[i];
//printf("%lf\t%lf\t%lf\n",lx[i],ly[i],lz[i]);
 }


for(i=0;i<ntot;i++){

x[i]=x[i]*rotation[0][0]+y[i]*rotation[1][0]+z[i]*rotation[2][0];

y[i]=x[i]*rotation[0][1]+y[i]*rotation[1][1]+z[i]*rotation[2][1];

z[i]=x[i]*rotation[0][2]+y[i]*rotation[1][2]+z[i]*rotation[2][2];

//printf("%lf\t%lf\t%lf\n",x[i],y[i],z[i]);
}


}

//int main(){

//int nx,ny,nz,ntot;
//nx=1;ny=1;nz=1;
//ntot=4*nx*ny*nz;
//double lat;lat=1;
//double* x;double* y; double* z;

//x=(double*) malloc(ntot*sizeof(double));
//y=(double*) malloc(ntot*sizeof(double));
//z=(double*) malloc(ntot*sizeof(double));



//double* lx; double* ly; double* lz; double* strain;

//lx=(double*) malloc(3*sizeof(double));
//ly=(double*) malloc(3*sizeof(double));
//lz=(double*) malloc(3*sizeof(double));

//strain=(double*) malloc(6*sizeof(double));
//create_fcc(nx,ny,nz,ntot,lat,x,y,z,lx,ly,lz);



//deformation(x,y,z,lx,ly,lz,strain,ntot,lat,nx,ny,nz);

//return 0;

//}

