#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void pos2lamp(double latpara,double shift,double* lx,double* ly,double* lz,int ntot,double* x,double* y,double* z){
	char firstline[30];
	double a;
	char crystalname1[20],crystalname2[20];
	int nat1,nat2;
	char dir[50];
	int i;
//	double* x;double* y;double* z;
	FILE* fp;
	fp =fopen("POSCAR","r");
	fscanf(fp," %s",firstline);
	fscanf(fp,"%lf",&a);
	fscanf(fp,"%lf %lf %lf",&lx[0],&lx[1],&lx[2]);
	fscanf(fp,"%lf %lf %lf",&ly[0],&ly[1],&ly[2]);
	fscanf(fp,"%lf %lf %lf",&lz[0],&lz[1],&lz[2]);
	fscanf(fp," %s ",crystalname1);
	fscanf(fp,"%i ",&nat1);
	fscanf(fp,"%s",dir);
	ntot=nat1;
//	x=(double*)malloc(ntot*sizeof(double));
//	y=(double*)malloc(ntot*sizeof(double));
//	z=(double*)malloc(ntot*sizeof(double));
	for(i=0;i<ntot;i++){
		fscanf(fp,"%lf %lf %lf",&x[i],&y[i],&z[i]);
	}
	fclose(fp);
	double dftlat;
	dftlat=1.0;
	lx[0]=lx[0]/dftlat;
	ly[1]=ly[1]/dftlat;
	lz[2]=lz[2]/dftlat;
	double boxx,boxy,boxz;
	boxx=lx[0];
	boxy=ly[1];
	boxz=lz[2];

	FILE* fp2;
	fp2=fopen("datafile","w+");

	fprintf(fp2, " \n");
	fprintf(fp2, " %i atoms \n",ntot);
	fprintf(fp2, " \n");
	fprintf(fp2, " 1 atom types\n");
	fprintf(fp2, " %20.20f %20.20f xlo xhi\n",0.0,boxx);
	fprintf(fp2, " %20.20f %20.20f ylo yhi\n",0.0,boxy);
	fprintf(fp2, " %20.20f %20.20f zlo zhi\n",0.0,boxz);
	fprintf(fp2, " \n");
	fprintf(fp2, " Atoms \n");
	fprintf(fp2, " \n");

	for(i= 0;i<ntot;i++){
		if (i<ntot/2){
		fprintf(fp2,"\t%d\t1\t%20.20f\t%20.20f\t%20.20f\n",i+1,x[i],y[i],z[i]);
		}
		else{
			fprintf(fp2,"\t%d\t1\t%20.20f\t%20.20f\t%20.20f\n",i+1,x[i]+shift,y[i],z[i]);
		}
	}
	fclose(fp2);
}

