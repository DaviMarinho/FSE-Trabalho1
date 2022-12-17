#ifndef COMUNICACAO_H_
#define COMUNICACAO_H_

typedef struct {
  float temperatura;
  float umidade;
} DHT22;

#define SERVER_DISTRIBUTED_IP "164.41.98.16"
#define SERVER_CENTRAL_PORT 10741 
#define SERVER_DISTRIBUTED_PORT 10741


void acionaDistribuido();
void *recebeDistribuido();
void leTempUmidade();
int enviaDistribuido(int item, int status, unsigned short int porta);

#endif /* COMUNICACAO_H_ */