#!/bin/bash
echo "compilando"
gcc -p -o knn knn2.c -lm
echo "executando"
echo "------------------------------------------------------------------------"
./knn < ../resultado/testing > saida
#./knn < ../resultado/testing 

cat saida >> ../resultado/resultadoGeral
cat saida
echo "------------------------------------------------------------------------">> ../resultado/resultadoGeral
echo "------------------------------------------------------------------------"
gprof --brief -p knn

echo "------------------------------------------------------------------------"
