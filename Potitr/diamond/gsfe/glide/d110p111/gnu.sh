#!/bin/bash

#Purpose: Calculate material properties of fcc system

here=$(pwd)


 cat << EOF | gnuplot
  set term png
  set title "Li(112) gamma surface(meV/Sq. ang)"
  set xlabel "d_111(u/b)"
  set ylabel "Fault Energy(meV/ang2)"
  set output "gamma_112.png"
  plot 'gammasurface' using 1:2 title "MEAM" with lines, 'Li_fault_dft.txt' using 1:2 title "DFT" with lines
EOF

#mv gamma_110.png gamma_100final.png
