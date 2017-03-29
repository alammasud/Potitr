#!/bin/bash

here=$(pwd)


rm -f latticefile.txt
rm -f datafile
rm -f input.txt
rm -f displacement.txt
rm -f output
rm -f ../../d111p112



xxx=$(grep -i 'a_0' $here/../../output | tail -n1 |  sed -e 's/a_0\(.*\)(.*)/\1/')
#latticename="Fe"
cohesiveenergy=$(grep -i 'E_0' $here/../../output | tail -n1 |  sed -e 's/E_0\(.*\)(.*)/\1/')


  echo "  $xxx " > latticefile.txt

gcc -Wall lattice.c -o lattice
./lattice

declare -a arr=( $(<out))

rm -f displacement.txt
rm -f fit.log

for arr in ${arr[@]};do
	        aaid=${arr[$idx]}
		         echo "  $aaid " > displacement.txt



make clean
make all
./main
fn2=input.txt

#sed -i -re "s/latticename/${latticename}/g" $fn2
sed -i -re "s/aaa/${aaid}/g" $fn2

lammps <input.txt

 grep Loop log -B1|grep -v Loop|awk '7' > eout
gcc -Wall postprocess.c -o postprocess
./postprocess >> output

#mv log log.${aaid}

rm log


done

gcc -Wall plo.c -o plo
./plo >> ../../d111p112

# cat << EOF | gnuplot
 #  set term png
 #  set xlabel "displacement<111>(ang)"
 #  set ylabel "Fault_Energy(meV/ang^2)"
 #  set output "gamma_112.png"
 #  plot 'gammasurface' using 1:2 with lines
#EOF

#mv gamma_112.png gamma_112.${latticename}.png
