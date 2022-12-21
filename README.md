# FSE-Trabalho1

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
É necessário trocar o `<n>` pelo número da sala.

## Comandos

* Para encerrar um programa, utilize as teclas `Ctrl + C`.

