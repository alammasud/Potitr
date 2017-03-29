#include<stdio.h>
void generate_datafile_for_lammps(double* lx,double* ly,double* lz,double a,double* x,double* y,double* z, int ntot){
int i;
FILE* fp2;
fp2=fopen("datafile","w+");

fprintf(fp2, " \n");
fprintf(fp2, " %i atoms \n",ntot);
fprintf(fp2, " \n");
fprintf(fp2, " 1 atom types\n");
fprintf(fp2, " %.20f %.20f xlo xhi\n", 0.0, lx[0]);
fprintf(fp2, " %.20f %.20f ylo yhi\n",0.0, ly[1]);
fprintf(fp2, " %.20f %.20f zlo zhi\n",0.0, lz[2]);
fprintf(fp2, " \n");
fprintf(fp2, " Atoms \n");
fprintf(fp2, " \n");



for(i = 0; i< ntot;i++){
   fprintf(fp2,"\t%d\t1\t%.20f\t%.20f\t%.20f\n",i+1,x[i],y[i],z[i]);
   }
}
