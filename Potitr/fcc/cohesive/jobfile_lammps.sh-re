#!/bin/bash
#Purpose: Calculate material properties of fcc system

here=$(pwd)


#rm -f latticefile.txt
rm -f datafile
rm -f input.txt
rm -f eout
rm -f output

#xxx=3.60
#latticename="Cu"

#echo "  $xxx  " >> latticefile.txt


fn2=input.txt
make clean
make all
./main
#sed -i -re "s/latticename/${latticename}/g" $fn2


#Command to execute LAMMPS
lammps <input.txt

 grep Loop log -B1|grep -v Loop|awk '7' > eout
gcc -Wall postprocess.c -o postprocess
./postprocess > ../output

#mv log log.E0.${latticename}
#mv dump dump.E0.${latticename}


