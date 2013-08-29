#!/bin/bash
t=hu07_minimo
k=3
c=7
clear
cp main.c ../../resultado/backup/main.c$t
echo compilando
make
echo executando
echo 20 $c > ../../resultado/caracteristicas

for i in {1..4}
do
	for j in {1..5}
		do
			echo Treinamento/$i/$j.png
			./opencvHU ../../extracacaoHu/Trademarks/Treinamento/$i/$j.png >> ../../resultado/caracteristicas
			echo $i >> ../../resultado/caracteristicas
		done
done

echo 20 $c > ../../resultado/caracteristicasTeste	
for i in {1..4}
do
	for j in {1..5}
		do
			echo Teste/$i/$j.png
			./opencvHU ../../extracacaoHu/Trademarks/Teste/$i/$j.png >> ../../resultado/caracteristicasTeste
			echo $i >> ../../resultado/caracteristicasTeste
		done
done


echo $k > ../../resultado/testing
cat ../../resultado/caracteristicas >> ../../resultado/testing
cat ../../resultado/caracteristicasTeste >> ../../resultado/testing
#cat ../../resultado/testing

cd ../../knn2/
pwd
echo $k
echo $k >> ../resultado/resultadoGeral
echo $k >> ../resultado/resultadoGeral
#echo main.c$t >> ../resultado/resultadoGeral
./make.sh
#done
echo "________________________________________________________________________">> ../resultado/resultadoGeral