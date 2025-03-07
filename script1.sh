#!/bin/bash

MEU_IP=$(hostname -I) #aqui eu passo um comando pra uma variavel

echo "seu IP local.. $MEU_IP. Agora digite o endereco de uma pagina: "
read PAGINA_WEB #pegar variavel

ping -c 5 $PAGINA_WEB #ping 5 vezes

if [ $? -eq 0 ]; #pega o ultimo comando e ve se deu certo
then
	echo "**** SITE com conectividade. Conseguiu efetuar o ping ****"
else
	echo "**** ALERTA! problema de conectividade ou  site nao existe! ****"
fi
