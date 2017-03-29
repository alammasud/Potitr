#!/bin/bash
 cat << EOF | gnuplot
 set term  png noenhanced
 set output 'out.png'
 set linestyle 1 lt 1 lw 1
 set linestyle 2 lt -1 lw 1
 set linestyle 3 lt 3 lw 1
 set linestyle 4 lt 4 lw 1
 set linestyle 5 lt 5 lw 1
 plot 'Li1.txt' w l ls 1, \
'Li2.txt' w l ls 2, \
'Li3.txt' w l ls 3, \
'Li4.txt' w l ls 4


EOF

