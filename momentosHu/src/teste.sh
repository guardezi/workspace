#!/bin/bash
t=huFuncionando_histograma
c=100
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
			../../momentosHu/src/opencvHU ../../extracacaoHu/Trademarks/Treinamento/$i/$j.png >> ../../resultado/caracteristicas
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

cp ../resultado/caracteristicas ../../knn2/
cp ../resultado/caracteristicasTeste ../../knn2/

cd ../../knn2/
pwd
#numero de k:
for i in {1..7}
do
	echo $i > ../resultado/testing
	echo $i >> ../resultado/resultadoGeral
	echo $t >> ../resultado/resultadoGeral
	#echo main.c$t >> ../resultado/resultadoGeral
	
	./make.sh
done
echo "________________________________________________________________________">> ../resultado/resultadoGeral