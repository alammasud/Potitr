#include<stdlib.h>
#include<stdio.h>
#include<math.h>

   void generate_datafile_for_lammps(double* lx,double* ly,double* lz,double a,double* x,double* y,double* z, int ntot){
   int i;
   FILE* fp2;
   fp2=fopen("datafile","w+");
   
   fprintf(fp2, " \n");
   fprintf(fp2, " %i atoms \n",ntot);
  fprintf(fp2, " \n");
  fprintf(fp2, " 1 atom types\n");
  fprintf(fp2, " %20.20f %20.20f xlo xhi\n", 0.0, lx[0]);
  fprintf(fp2, " %20.20f %20.20f ylo yhi\n",0.0, ly[1]);
  fprintf(fp2, " %20.20f %20.20f zlo zhi\n",0.0, lz[2]);
  fprintf(fp2, " %20.20f %20.20f %20.20f xy xz yz\n",ly[0], lz[0],lz[1]);
  fprintf(fp2, " \n");
  fprintf(fp2, " Atoms \n");
  fprintf(fp2, " \n");
  
  
  
  for(i = 0; i< ntot;i++){
     fprintf(fp2,"\t%d\t1\t%20.20f\t%20.20f\t%20.20f\n",i+1,x[i],y[i],z[i]);
     }
  }

   void input_file(){
	    char ch[60];
	    char ch1[60];
            char ch2[60];
           FILE* fp1;
	fp1=fopen("latname.txt","r");
	fscanf(fp1,"%s %s %s",ch,ch1,ch2);
	fclose(fp1);
   
   FILE* fp;
   fp=fopen("input.txt","w+");
   fprintf(fp,"%s","clear\n");
     fprintf(fp,"%s","units           metal\n");
     fprintf(fp,"%s","boundary        p p p\n");
    fprintf(fp,"%s","atom_style      atomic\n");
    fprintf(fp,"%s","read_data       datafile\n");
    fprintf(fp,"%s","pair_style      meam\n");
   // fprintf(fp,"%s","pair_coeff      * * /Users/masud/MD/potentials/library_latticename.meam latticename /Users/masud/MD/potentials/latticename.meam latticename\n");
//   fprintf(fp,"pair_coeff      * *  /Users/masud/MD/potentials/library_%s.meam %s /Users/masud/MD/potentials/%s.meam  %s\n",ch1,ch,ch,ch);
   fprintf(fp1,"pair_coeff      * *  %s/%s.meam %s %s/%s.meam  %s\n",ch2,ch1,ch,ch2,ch,ch);
    fprintf(fp,"%s","group todel id 2\n");
    fprintf(fp,"%s","delete_atoms group todel\n");
    fprintf(fp,"%s","neighbor        2.0 bin\n");
    fprintf(fp,"%s","neigh_modify    delay 10\n");
    fprintf(fp,"%s","dump            1 all custom 1 dump id type x y z\n");
    fprintf(fp,"%s","log             log\n");
    fprintf(fp,"%s","thermo_style    custom step atoms pe ke etotal press vol lx ly lz\n");
    fprintf(fp,"%s","thermo_modify   line one format float %.16g\n");
  //  fprintf(fp,"%s","fix             1 all box/relax iso 0.0 vmax 0.001\n");
    fprintf(fp,"%s","min_style       cg\n");
    fprintf(fp,"%s","min_modify      line quadratic\n");
    fprintf(fp,"%s", "minimize        1.0e-15 1.0e-15 10000000 100000000\n");
  
  }



void  create_bcc(int nx, int ny, int nz, int ntot, double a, double* x, double* y, double* z,double* lx, double* ly, double* lz){

int i,j,k,t,l;
double unit[2][3];

unit[0][0]=0;unit[0][1]=0;unit[0][2]=0;
unit[1][0]=a/2;unit[1][1]=a/2;unit[1][2]=a/2;


lx[0]=nx*a;lx[1]=0;lx[2]=0;
ly[0]=0;ly[1]=ny*a;ly[2]=0;
lz[0]=0;lz[1]=0;lz[2]=a*nz;

l=0;    
for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
                for(k=0;k<nz;k++){
                        for(t=0;t<2;t++){
                                x[l]=unit[t][0]+i*a;
                                y[l]=unit[t][1]+j*a;
                                z[l]=unit[t][2]+k*a;
                                l++;
                        }
                }
        }
}
}


int main(){
int nx,ny,nz,ntot;
double* x;double* y; double* z;
double* lx;double* ly; double* lz;
double a;

//nx=10;ny=10;nz=10;
FILE* lattice;
lattice=fopen("latticefile.txt","r");
	if(lattice==NULL)
 	{
     		printf("No datas can be found in the File");
     		exit(1);
 	}

 	while(fscanf(lattice,"%le %i %i %i ", &a,&nx,&ny,&nz) != feof(lattice))
 	{
 	   //printf("latticeparameter=%le\n",a);
 	 break;
 	}
	
	fclose(lattice);

ntot=2*nx*ny*nz;
//double a=3.61331595816302897362;

x=(double*) malloc(ntot*sizeof(double));
y=(double*) malloc(ntot*sizeof(double));
z=(double*) malloc(ntot*sizeof(double));
lx=(double*) malloc(3*sizeof(double));
ly=(double*) malloc(3*sizeof(double));
lz=(double*) malloc(3*sizeof(double));

  create_bcc( nx, ny, nz, ntot, a, x, y, z,lx, ly,lz);
int i;
for(i=0;i<ntot;i++){
//printf("%20.20lf\t%20.20lf\t%20.20lf\n",x[i],y[i],z[i]);
}

 generate_datafile_for_lammps( lx, ly, lz, a, x, y, z, ntot);

 input_file();

return 0;
}
