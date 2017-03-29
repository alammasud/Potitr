#!/bin/bash
#Purpose: Calculate material properties of fcc system

here=$(pwd)


rm -f latticefile.txt
rm -f datafile
rm -f input.txt
rm -f displacement.txt
rm -f cohesive.txt
rm -f output
rm -f eout


xxx=$(grep -i 'a_0' $here/../../output | tail -n1 |  sed -e 's/a_0\(.*\)(.*)/\1/')
cohesiveenergy=$(grep -i 'E_0' $here/../../output | tail -n1 |  sed -e 's/E_0\(.*\)(.*)/\1/')




echo "  $cohesiveenergy  " > cohesive.txt




declare -a nz=( 5   )
  
  for nz in ${nz[@]};do
      aaid=${nz[$idx]}
  #sed -i -re "s/duplicate/${aaid}/g" main.c
  echo "  $xxx ${aaid} ${aaid} ${aaid} " > latticefile.txt



gcc -Wall create_fcc_vacancy.c -o create_fcc_vacancy -lm
./create_fcc_vacancy

fn2=input.txt

#sed -i -re "s/latticename/${latticename}/g" $fn2


#Command to execute LAMMPS
lammps <input.txt

 grep Loop log -B1|grep -v Loop|awk '7' > eout
gcc -Wall postprocess.c -o postprocess -lm
./postprocess >> ../../output

#mv log log.vacancy.${latticename}
#mv dump dump.vacancy.${latticename}

done

 cat << EOF | gnuplot
   set term png
   set xlabel "natoms"
   set ylabel "Energy(eV)"
   set output "vf_energy.png"
   plot 'output' using 1:2 with lines
EOF

#mv vf_energy.png vf_energy.${latticename}.png
