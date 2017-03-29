#!/bin/bash
#Purpose: Calculate material properties of fcc system

#for run in {1..2} 
#do
here=$(pwd)
rm -f output
  declare -a arr=( -0.004 -0.003 -0.002 -0.001 0.00 0.001 0.002 0.003 0.004  )

  
  for arr in ${arr[@]};do
  aaid=${arr[$idx]}


rm -f latticefile.txt
rm -f datafile
rm -f input.txt
rm -f displacement.txt
rm -f eout
rm -f fit.log

xxx=$(grep -i 'a_0' $here/../../output | tail -n1 |  sed -e 's/a_0\(.*\)(.*)/\1/')
#latticename="Fe"
cohesiveenergy=$(grep -i 'E_0' $here/../../output | tail -n1 |  sed -e 's/E_0\(.*\)(.*)/\1/')


uu=${aaid}
echo "  $xxx  " >> latticefile.txt
echo "  ${uu} $xxx  " >> displacement.txt

fn2=input.txt
#sed -i -re  "s/blabla/$blabla/g" displacement.txt

#declare -a arr=(-0.001 0.00 0.000)

#for i in ${arr[@]};do
#aaid=${arr[$idx]}

#sed -i -re "s/uu/$aaid/g" displacement.txt
make clean
make all
./main
sed -i -re "s/latticename/${latticename}/g" $fn2


#Command to execute LAMMPS
lammps <input.txt

 grep Loop log -B1|grep -v Loop|awk '7' > eout
gcc -Wall postprocess.c -o postprocess
 ./postprocess  >> output

#mv log log.${uu}
#mv dump dump.${uu}

rm log
rm dump

done

cat << EOF | gnuplot
  set term png
set xlabel "e22"
set ylabel "strainEnergy_density(eV/Angstrom^3)"
  set output "c12.png"
  plot 'output' using 1:2 with lines
  f(x) = a*x**2 + b*x + c
  FIT_LIMIT=1e-3
  fit f(x) "output" using 1:2 via a,b,c
EOF

#mv c12.png c12.${latticename}.png
grep -i 'c11' ../../output | tail -n1 |  sed -e 's/c11\(.*\)(.*)/\1/' > bal

awk -F' *=* +' '/[+]\/-/{printf "%s%s",$2,(++i%3)?" ":"\n"}' fit.log  >fitdata

gcc -Wall fit.c -o fit
./fit >> ../../output

