#include<stdio.h>

void input_file(double* lx, double* ly, double* lz){
double ay=ly[1]/2-0.1;

char ch[60];
char ch1[60];
char ch2[60];

FILE* fp1;
fp1=fopen("latname.txt","r");
fscanf(fp1,"%s %s %s",ch,ch1,ch2);
fclose(fp1);



FILE* fp;
fp=fopen("input.txt","w+");

  
  fprintf(fp,"%s","units           metal\n");
  fprintf(fp,"%s","boundary        p s p\n");
  fprintf(fp,"%s","atom_style      atomic\n");
  fprintf(fp,"%s","read_data       datafile\n");
  fprintf(fp,"%s","pair_style      meam\n");
//  fprintf(fp,"%s","pair_coeff      * * /Users/masud/MD/potentials/library_latticename.meam latticename /Users/masud/MD/potentials/latticename.meam latticename\n");
// fprintf(fp,"pair_coeff      * *  /Users/masud/MD/potentials/library_%s.meam %s /Users/masud/MD/potentials/%s.meam  %s\n",ch1,ch,ch,ch);
  fprintf(fp,"pair_coeff      * *  %s/%s.meam %s %s/%s.meam  %s\n",ch2,ch1,ch,ch2,ch,ch);
  fprintf(fp,"region 1 block %.20lf %.20lf %.20lf %.6lf %.20lf %.20lf\n",0.0, lx[0],0.0,ay,0.0,lz[2]);
  fprintf(fp,"region 2 block %.20lf %.20lf %.6lf %.20lf %.20lf %.20lf\n",0.0,lx[0],ay,ly[1],0.0,lz[2]);
  fprintf(fp,"%s","group bot region 1\n");
  fprintf(fp,"%s","group top region 2\n");
  fprintf(fp,"%s","displace_atoms top move 0.0 0.0 aaa\n");
  fprintf(fp,"%s","neighbor        2.0 bin\n");
  fprintf(fp,"%s","neigh_modify    delay 10\n");
  fprintf(fp,"%s","fix 1 top setforce 0 NULL 0\n");
  fprintf(fp,"%s","fix 2 bot setforce 0 0 0\n");
  fprintf(fp,"%s","dump            1 all custom 1 dump id type x y z\n");
  fprintf(fp,"%s","log             log\n");
  fprintf(fp,"%s","thermo_style    custom step atoms pe ke etotal press vol lx ly lz \n");
  fprintf(fp,"%s","thermo_modify   line one format float %.16g\n");
  fprintf(fp,"%s","min_style       cg\n");
  fprintf(fp,"%s","min_modify      line quadratic\n");
  fprintf(fp,"%s", "minimize        1.0e-6 1.0e-6 50000 50000\n");

}

