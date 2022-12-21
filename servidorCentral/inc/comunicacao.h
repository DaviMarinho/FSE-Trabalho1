#ifndef COMUNICACAO_H_
#define COMUNICACAO_H_

typedef struct {
  float temperatura;
  float umidade;
} DHT22;

void acionaDistribuido();
void *recebeDistribuido();
void leTempUmidade();
int enviaDistribuido(int item, int status, unsigned short int porta);

#endif /* COMUNICACAO_H_ */