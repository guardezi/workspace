#!/bin/bash
t=original
clear
cp main.c ../backup/main.c$t
echo compilando
make
echo executando
echo 20 7 >caracteristicas

for i in {1..4}
do
	for j in {1..5}
		do
			echo Treinamento/$i/$j.png
			./Teste ../../extracacaoHu/Trademarks/Treinamento/$i/$j.png >> caracteristicas
			echo $i >> caracteristicas	
		done
done

echo 20 7 >caracteristicasTeste
for i in {1..4}
do
	for j in {1..5}
		do
			echo Teste/$i/$j.png
			./Teste ../../extracacaoHu/Trademarks/Teste/$i/$j.png >> caracteristicasTeste
			echo $i >> caracteristicasTeste	
		done
done
echo substituindo "," por "."
sed -e "s/,/./g" caracteristicasTeste > /tmp/x.tmp
mv /tmp/x.tmp caracteristicasTeste

sed -e "s/,/./g" caracteristicas > /tmp/x.tmp
mv /tmp/x.tmp caracteristicas

cp caracteristicas /home/jeferson/workspace/knn2/
cp caracteristicasTeste	/home/jeferson/workspace/knn2/

cd /home/jeferson/workspace/knn2/

#numero de k:
for i in {1..7}
do
	echo $i > testing
	echo k=$i >> /home/jeferson/workspace/extrairHU/src/resultadoGeral
	echo main.c$t >> /home/jeferson/workspace/extrairHU/src/resultadoGeral
	echo "cvErode(threshold, open_morf, NULL,9);">> /home/jeferson/workspace/extrairHU/src/resultadoGeral
	echo "cvDilate(open_morf, open_morf, NULL,9);"	>> /home/jeferson/workspace/extrairHU/src/resultadoGeral
	echo "cvMoments(open_morf, &moments,1);"	>> /home/jeferson/workspace/extrairHU/src/resultadoGeral
	
	./make.sh
done
echo "________________________________________________________________________">> /home/jeferson/workspace/extrairHU/src/resultadoGeral
