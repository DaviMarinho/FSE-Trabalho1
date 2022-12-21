# FSE-Trabalho1

# Video disponível em:

https://youtu.be/p1Qv5E5L_h0

## Execução

Há 1 servidor central e vários servidores distribuídos. Sendo assim, o programa será executado para cada servidor, em terminais separados.

Para compilar o código de um servidor, execute no diretório raiz (diretório servidorCentral ou servidorDistribuido) o comando

```
make ou make all
```

Para o servidor central, agora basta executar:
```
bin/bin
```

Para os servidores distribuídos, o comando deve receber o arquivo de configuração. Por exemplo, para o servidor distribuído de cada sala, seria:
```
bin/bin configuracao_sala_exemplo.json
```
Podendo ser alterado o nome do arquivo de configuração.

No arquivo de configuração pode ser alterado os valores:

```
ip_servidor_central
porta_servidor_central
ip_servidor_distribuido
porta_servidor_distribuido
nome
gpio
```

## Comandos

* Para encerrar um programa, utilize as teclas `Ctrl + C`.

