#include<stdio.h>

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
  fprintf(fp,"%s","units           metal\n");
  fprintf(fp,"%s","boundary        p p p\n");
  fprintf(fp,"%s","atom_style      atomic\n");
  fprintf(fp,"%s","read_data       datafile\n");
  fprintf(fp,"%s","pair_style      meam\n");
 // fprintf(fp,"%s","pair_coeff      * * /Users/masud/MD/potentials/library_bccLeebaskes.meam latticename /Users/masud/MD/potentials/latticename.meam latticename\n");
//  fprintf(fp,"pair_coeff      * *  /Users/masud/MD/potentials/library_%s.meam %s /Users/masud/MD/potentials/%s.meam  %s\n",ch1,ch,ch,ch);
  fprintf(fp,"pair_coeff      * *  %s/%s.meam %s %s/%s.meam  %s\n",ch2,ch1,ch,ch2,ch,ch);
  fprintf(fp,"%s","neighbor        2.0 bin\n");
  fprintf(fp,"%s","neigh_modify    delay 10\n");
  fprintf(fp,"%s","dump            1 all custom 100000 dump id type x y z fx fy fz\n");
  fprintf(fp,"%s","log             log\n");
  fprintf(fp,"%s","thermo_style    custom step atoms pe ke etotal press vol lx ly lz\n");
  fprintf(fp,"%s","thermo_modify   line one format float %.16g\n");
  fprintf(fp,"%s","fix             1 all box/relax iso 0.0 vmax 0.0001\n");
  fprintf(fp,"%s","min_style       cg\n");
  fprintf(fp,"%s","min_modify      line quadratic\n");
  fprintf(fp,"%s", "minimize        0.0 0.0 5000 5000\n");

}

