#!/bin/bash



cat << EOF | gnuplot
  set term png
set xlabel "e11"
set ylabel "strainEnergy_density(eV/Angstrom^3)"
  set output "c11.png"
  plot 'output' using 1:2 with lines
  f(x) = a*x**2+b*x+c
  a=0.0561;b=0.001;c=0.001
  FIT_LIMIT=1e-4
  fit f(x) "output" using 1:2 via a,b,c
EOF

mv c11.png c11_${latticename}.png
awk -F' *=* +' '/[+]\/-/{printf "%s%s",$2,(++i%3)?" ":"\n"}' fit.log  >fitdata

gcc -Wall fit.c -o fit
./fit >> /home/masud/job/bcc/output
