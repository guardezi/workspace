#!/bin/bash
DE=$1
PARA=$2
FILES=`ls *`
for x in $FILES
do
   sed -e "s/$DE/$PARA/g" $x > /tmp/$x.tmp
   mv /tmp/$x.tmp $x
   echo "Alterações efetuadas em $x"
done
