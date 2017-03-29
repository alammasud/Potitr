#!/bin/bash

#Purpose: Calculate material properties of fcc system

here=$(pwd)


rm -f latticefile.txt
rm -f datafile
rm -f input.txt
rm -f output
rm -f cohesive.txt

xxx=$(grep -i 'a_0' /Users/masud/MD/diamond/output | tail -n1 |  sed -e 's/a_0\(.*\)(.*)/\1/')
#latticename="Fe"
cohesiveenergy=$(grep -i 'E_0' /Users/masud/MD/diamond/output | tail -n1 |  sed -e 's/E_0\(.*\)(.*)/\1/')




echo "  $cohesiveenergy " > cohesive.txt


declare -a nz=(  6  )

for nz in ${nz[@]};do
    aaid=${nz[$idx]}
#sed -i -re "s/duplicate/${aaid}/g" main.c
echo "  $xxx ${aaid}  " > latticefile.txt





make clean
make all
./main
fn2=input.txt

#sed -i -re "s/latticename/${latticename}/g" $fn2


#Command to execute LAMMPS
lammps <input.txt

 grep Loop log -B1|grep -v Loop|awk '7' > eout
gcc -Wall postprocess.c -o postprocess
./postprocess >> ../../output

#gcc readump1.c -o readump1
#./readump1

done

# cat << EOF | gnuplot
 # set term png
 # set xlabel "nlayer"
 # set ylabel "E_110(mJ/m^2)"
 # set output "E_110.png"
 # plot 'output' using 1:2 with lines
#EOF

#mv E_110.png E_110.${latticename}.png
