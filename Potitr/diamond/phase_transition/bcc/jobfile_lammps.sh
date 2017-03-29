#!/bin/bash
#Purpose: Calculate material properties of fcc system

here=$(pwd)


rm -f latticefile.txt
rm -f datafile
rm -f input.txt
rm -f eout
rm -f out
rm -f output


xxx=$(grep -i 'a_0' $here/../../output | tail -n1 |  sed -e 's/a_0\(.*\)(.*)/\1/')
#latticename="Ta"
cohesiveenergy=$(grep -i 'E_0' $here/../../output | tail -n1 |  sed -e 's/E_0\(.*\)(.*)/\1/')

echo "  $xxx  " > latticefile.txt
echo " $cohesiveenergy " >cohesive.txt
#gcc -Wall lattice.c -o lattice
#./lattice 

#declare -a arr=( $(<out))

#rm -f deform.txt
#rm -f fit.log

#for arr in ${arr[@]};do
#    aaid=${arr[$idx]}
#sed -i -re "s/duplicate/${aaid}/g" main.c
#echo "  ${aaid}  " > deform.txt



fn2=input.txt
make clean
make all
./main
#sed -i -re "s/latticename/${latticename}/g" $fn2


#Command to execute LAMMPS
lammps <input.txt

 grep Loop log -B1|grep -v Loop|awk '7' > eout
gcc -Wall postprocess.c -o postprocess
./postprocess >> ../../output

#gcc readump1.c -o readump1
#./readump1





mv EV.png EV.${latticename}.png

