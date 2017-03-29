#include<stdio.h>

void input_file(){

FILE* fp;
fp=fopen("input.txt","w+");
  fprintf(fp,"%s","units           metal\n");
  fprintf(fp,"%s","boundary        p p p\n");
  fprintf(fp,"%s","atom_style      atomic\n");
  fprintf(fp,"%s","read_data       datafile\n");
  fprintf(fp,"%s","pair_style      meam\n");
  fprintf(fp,"%s","pair_coeff      * * ../../../potentials/library.meam latticename ../../../potentials/latticename.meam latticename\n");
  fprintf(fp,"%s","neighbor        2.0 bin\n");
  fprintf(fp,"%s","neigh_modify    delay 10\n");
  fprintf(fp,"%s","dump            1 all custom 1 dump id type x y z\n");
  fprintf(fp,"%s","log             log\n");
  fprintf(fp,"%s","thermo_style    custom step atoms pe ke etotal press vol lx ly lz\n");
  fprintf(fp,"%s","thermo_modify   line one format float %.16g\n");
  fprintf(fp,"%s","fix             1 all box/relax iso 0.0 vmax 0.001\n");
  fprintf(fp,"%s","min_style       cg\n");
  fprintf(fp,"%s","min_modify      line quadratic\n");
  fprintf(fp,"%s", "minimize        1.0e-30 1.0e-20 100000 1000000\n");

}

