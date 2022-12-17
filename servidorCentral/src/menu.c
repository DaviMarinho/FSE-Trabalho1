// #include <curses.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "menu.h"
// #include "comunicacao.h"

Aparelhos aparelhos;
Sensores sensores;

void atualizaDispositivo(int dispNum, int novoStatus, int serv){
  unsigned short int porta = serv ? 10741 : 10741;

  enviaDistribuido(dispNum, novoStatus, porta);
}

char * verificaOnOff(int estadoSensorAparelho) {
  if(estadoSensorAparelho == 1)
    return "ON";
  else
    return "OFF";
}

void mostraMenu() {

    printf(" | =============== STATUS DAS ENTRADAS =============== | =============== STATUS DAS SAIDAS =============== |\n\n");

    printf(" | ===============================================  SALA 01  ============================================= |\n");
    printf(" | ---      Sensor de presenca: %s                    |      0 -  Lampada 01: %s |\n", verificaOnOff(sensores.presenca), verificaOnOff(aparelhos.lampada01));
    printf(" | ---      Sensor de fumaca: %s                      |      1 -  Lampada 02: %s |\n", verificaOnOff(sensores.fumaca), verificaOnOff(aparelhos.lampada02));
    printf(" | ---      Sensor janela: %s                         |      2 -  Projetor Multimidia: %s |\n", verificaOnOff(sensores.janela), verificaOnOff(aparelhos.projetor));
    printf(" | ---      Sensor porta de entrada: %s               |      3 -  Ar-condicionado: %s |\n", verificaOnOff(sensores.porta), verificaOnOff(aparelhos.arCondicionado));
    printf(" | ---      Sensor contagem de pessoas entrando:      |      4 -  Alarme: %s |\n", verificaOnOff(aparelhos.alarme));
    printf(" | ---      Sensor contagem de pessoas saindo:        |      5 -  Para ligar todos os aparelhos. |\n");
    printf(" | ===============================================    |      6 -  Para desligar todos os aparelhos. |\n\n");

    printf(" | ===============================================  SALA 02  ============================================= |\n");

    printf(" =- SALA 02 --\n");
    printf("  Sensor de presenca: %s\n", verificaOnOff(sensores.presenca));
    printf("  Sensor de fumaca: %s\n", verificaOnOff(sensores.fumaca));
    printf("  Sensor janela: %s\n", verificaOnOff(sensores.janela));
    printf("  Sensor porta de entrada: %s\n", verificaOnOff(sensores.porta));
    printf("  Sensor de contagem de pessoas entrando:\n");
    printf("  Sensor de contagem de pessoas saindo:\n");


    printf(" ----- STATUS DAS SAIDAS -----\n\n");

    printf(" -- Codigo |  Sala 2\n");
    printf("       0   | Lampada 01: %s\n", verificaOnOff(aparelhos.lampada01));
    printf("       1   | Lampada 02: %s\n", verificaOnOff(aparelhos.lampada02));
    printf("       2   | Projeto Multimidia: %s\n", verificaOnOff(aparelhos.projetor));
    printf("       3   | Ar-condicionado: %s\n", verificaOnOff(aparelhos.arCondicionado));
    printf("       4   | Alarme: %s\n", verificaOnOff(aparelhos.alarme));

}

void menuAtivaDesativa() {
    system("clear");

    printf("\n  Qual dos dispositivos deseja ativar/desativar? Digite o código respectivo\n\n");
    printf("   CODIGO   |     DISPOSITIVO     |   STATUS ATUAL\n");
    printf("------------|---------------------|------------------\n");
    printf("                 Sala 1          \n");
    printf("------------|---------------------|------------------\n");
    printf("     0      | Lampada 01          |      %s\n", verificaOnOff(aparelhos.lampada01));
    printf("     1      | Lampada 02          |      %s\n", verificaOnOff(aparelhos.lampada02));
    printf("     2      | Projeto Multimidia  |      %s\n", verificaOnOff(aparelhos.projetor));
    printf("     3      | Ar-condicionado     |      %s\n", verificaOnOff(aparelhos.arCondicionado));
    printf("     4      | Alarme              |      %s\n", verificaOnOff(aparelhos.alarme));

    printf("------------|---------------------|------------------\n");
    printf("                 Sala 2         \n");
    printf("------------|---------------------|------------------\n");
    printf("     5      | Lampada 01:         |      %s\n", verificaOnOff(aparelhos.lampada01));
    printf("     6      | Lampada 02:         |      %s\n", verificaOnOff(aparelhos.lampada02));
    printf("     7      | Projeto Multimidia: |      %s\n", verificaOnOff(aparelhos.projetor));
    printf("     8      | Ar-condicionado:    |      %s\n", verificaOnOff(aparelhos.arCondicionado));
    printf("     9      | Alarme              |      %s\n", verificaOnOff(aparelhos.alarme));

    
    __fpurge(stdin);
    char comando = getchar();

    if(comando == '0') {
      printf("===============================================\n");
      printf("| COMANDO 0 - Liga/desliga lampada 1 - Sala 1 |\n");
      printf("===============================================\n");
      printf("\n");
      aparelhos.lampada01 = !aparelhos.lampada01;
      atualizaDispositivo(18,aparelhos.lampada01,0);
    } 
    else if(comando == '1') {
      printf("===============================================\n");
      printf("| COMANDO 1 - Liga/desliga lampada 2 - Sala 1 |\n");
      printf("===============================================\n");
      printf("\n");
      aparelhos.lampada02 = !aparelhos.lampada02;
      atualizaDispositivo(23,aparelhos.lampada02,0);
    }
    else if(comando == '2') {
      printf("==============================================\n");
      printf("| COMANDO 2 - Liga/desliga projetor - Sala 1 |\n");
      printf("==============================================\n");
      printf("\n");
      aparelhos.projetor = !aparelhos.projetor;
      atualizaDispositivo(25,aparelhos.projetor,0);
    }
    else if(comando == '3') {
      printf("=====================================================\n");
      printf("| COMANDO 3 - Liga/desliga ar-condicionado - Sala 1 |\n");
      printf("=====================================================\n");
      printf("\n");
      aparelhos.arCondicionado = !aparelhos.arCondicionado;
      atualizaDispositivo(24,aparelhos.arCondicionado,0);
    }
    else if(comando == '4') {
      printf("============================================\n");
      printf("| COMANDO 4 - Liga/desliga alarme - Sala 1 |\n");
      printf("============================================\n");
      printf("\n");
      aparelhos.alarme = !aparelhos.alarme;
      atualizaDispositivo(16,aparelhos.alarme,0);
    }
    else if(comando == '5') {
      printf("================================================\n");
      printf("| COMANDO 5 - Liga todos dispositivos - Sala 1 |\n");
      printf("================================================\n");
      printf("\n");
      aparelhos.lampada01 = 1;
      aparelhos.lampada02 = 1;
      aparelhos.projetor = 1;
      aparelhos.arCondicionado = 1;
      aparelhos.alarme = 1;
      atualizaDispositivo(18, aparelhos.lampada01, 0);
      atualizaDispositivo(23, aparelhos.lampada02, 0);
      atualizaDispositivo(25, aparelhos.projetor, 0);
      atualizaDispositivo(24, aparelhos.arCondicionado, 0);
      atualizaDispositivo(16, aparelhos.alarme, 0);
      mostraMenu();
    }
    else if(comando == '6') {
      printf("===================================================\n");
      printf("| COMANDO 6 - Desliga todos dispositivos - Sala 1 |\n");
      printf("===================================================\n");
      printf("\n");
      aparelhos.lampada01 = 0;
      aparelhos.lampada02 = 0;
      aparelhos.projetor = 0;
      aparelhos.arCondicionado = 0;
      aparelhos.alarme = 0;
      atualizaDispositivo(18, aparelhos.lampada01, 0);
      atualizaDispositivo(23, aparelhos.lampada02, 0);
      atualizaDispositivo(25, aparelhos.projetor, 0);
      atualizaDispositivo(24, aparelhos.arCondicionado, 0);
      atualizaDispositivo(16, aparelhos.alarme, 0);
      mostraMenu();
    }
    else if(comando == '9') {
        printf("COMANDO 9\n");
    }
    else {
        printf("Comando inválido\nAperte 'ENTER' para tentar novamente.\n");
        // __fpurge(stdin);
        // getchar();
        sleep(2);
        system("clear");

    }
}

void trata_SIGTSTP(int signum) {

    menuAtivaDesativa();

}

void* menuFunc() {
    signal(SIGTSTP, trata_SIGTSTP);
    // system("clear");
    while(1) {
        system("clear");
        mostraMenu();
        sleep(5);
        // leTempUmidade();
        __fpurge(stdin);

    }

}

void trataSensores(int comando) {
  
  switch (comando)
  {
    case 1:
      sensores.presenca = !sensores.presenca;
      break;
    case 2:
      sensores.fumaca = !sensores.fumaca;
      break;
    case 3:
      sensores.janela = !sensores.janela;
      break;
    case 4:
      sensores.porta = !sensores.porta;
      break;
    // case 5:
    //   sensores.entradaPessoas = !sensores.entradaPessoas;
    //   break;
    // case 6:
    //   sensores.saidaPessoas = !sensores.saidaPessoas;
    //   break;
    case 7:
      sensores.temperatura = !sensores.temperatura;
      break;
    case 8:
      break;
    case 9:
      break;
    default:
      break;
  }
}