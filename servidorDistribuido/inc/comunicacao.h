#ifndef COMUNICACAO_H_
#define COMUNICACAO_H_

void *recebeCentral(void *porta);
void enviaCentral(int message);
char *criaIpDistribuido(int ipParte1, int ipParte2, int ipParte3, int ipParte4);

#endif /* COMUNICACAO_H_ */