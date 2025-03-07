#!/bin/bash

echo "Digite um limite de Processos aceitavel: "
read LIM_PROCESSOS #passa um valor para a variavel

ATUAL_PROCESSOS=$(ps | wc -l) # ./contar_processos.sh  passa um script ou comando para uma variavel

if [ $ATUAL_PROCESSOS -lt $LIM_PROCESSOS ]; #compara as duas
then
	echo "Numero de processos atualmente eh MENOR que o limite estipulado!"
elif [ $ATUAL_PROCESSOS -gt $LIM_PROCESSOS ];
then
	echo " ****ALERTA!**** Numero de processos atual eh MAIOR que o limite estipulado!"
fi 
