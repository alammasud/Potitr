#!/bin/bash
 cat << EOF | gnuplot
  set term png
  set xlabel "Volume/atom"
  set ylabel "Energy/atom"
  set output "EV.png"
  plot 'mg3cadft.txt' using 1:2 with lines
  f(x) = E0 + ((B0*x)/(Bp0*(Bp0 - 1)))*(Bp0*(1 - v0/x) + (v0/x )**Bp0 - 1) 
  E0=-39;B0=0.08;Bp0=3.0;v0=26.0
  FIT_LIMIT=1e-3
replot
  fit f(x) 'mg3cadft.txt' using 1:2 via B0,E0,Bp0,v0


EOF
