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
#latticename="Fe"
xxx=2.5
cohesiveenergy=$(grep -i 'E_0' $here/../../output | tail -n1 |  sed -e 's/E_0\(.*\)(.*)/\1/') 



echo "  $xxx  " > latticefile.txt
echo " $cohesiveenergy " >cohesive.txt

#gcc -Wall lattice.c -o lattice
#./lattice 

#declare -a arr=( $(<out))

#rm -f deform.txt
#rm -f fit.log

#for arr in ${arr[@]};do
 #   aaid=${arr[$idx]}
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

#mv log log.ev.${aaid}
#mv dump dump.ev.${aaid}

rm log
rm dump

#done





# cat << EOF | gnuplot
 # set term png
 # set xlabel "Volume/atom"
 # set ylabel "Energy/atom"
 # set output "EV.png"
 # plot 'output' using 1:2 with lines
#  f(x) = E0 + ((B0*x)/(Bp0*(Bp0 - 1)))*(Bp0*(1 - v0/x) + (v0/x )**Bp0 - 1) 
#  E0=-1.6;B0=0.1;Bp0=3;v0=20
 # FIT_LIMIT=1e-6
#replot
 # fit f(x) 'output' using 1:2 via B0,E0,Bp0,v0


#EOF

#mv EV.png EV.${latticename}.png


#grep -i '+/-' fit.log   |  sed -re 's/.*=\s*(.*)(.*)/\1/' >fitdata
#grep -i '+/-' fit.log   | sed -re 's/.*=\s*(.*)   .+*$/\1/' >fitdata
#sed -i -re "s/+*/000/g" $fitdata

#awk -F' *=* +' '/[+]\/-/{printf "%s%s",$2,(++i%4)?" ":"\n"}' fit.log >fitdata

#gcc -Wall fit.c -o fit
#./fit >> ../../output

