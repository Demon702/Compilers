#!/bin/bash
rm *.sym
rm *.symy
rm *.ast
rm *.asty
rm *.icodey
rm *.evaly
rm *.icode
rm *.eval
# rm *\.c\.spim

listvar=*.c
# listvar="8.c"

# listvar="test2.c"
# listvar="test5.c"

make

for i in $listvar
do
    echo "#######################"
    echo $i
    echo "#######################"
    ./yoursclp  -ast -symtab -icode $i
    mv "$i.ast" "$i.asty"   
    # mv "$i.sym" "$i.symy"
    mv "$i.sym" "$i.symy"
    # ./yoursclp -icode $i  >> "$i.icodey"
    # mv "$i.icode" "$i.icodey"
    # ./yoursclp -eval $i 
    # mv "$i.eval" "$i.evaly"
    mv "$i.spim" "$i.t.spim"
    mv "$i.ic" "$i.icy"
    ./sclp -symtab -ast -icode $i
    # ./sclp -tokens $i
    echo "diff for ast"
    diff "$i.ast" "$i.asty"
    echo "--------------------"
    echo "diff for symtab"
    diff "$i.sym" "$i.symy"
    # ./sclp -icode $i  >> "$i.icode"
    # ./sclp -eval $i 
    echo "diff for icode"
    diff "$i.ic" "$i.icy"
    echo "--------------------"


    # echo "diff for eval"
    # diff "$i.eval" "$i.evaly"
    # echo "--------------------"
    echo "diff for spim"
    diff "$i.t.spim" "$i.spim"
    echo "--------------------"
done
