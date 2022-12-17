#ifndef LEJSON_H_
#define LEJSON_H_

typedef struct config {
    int portaDistribuido;
    char ipCentral[13];
} JSONConfig;

JSONConfig leJSONConfig(const char* nomeArquivo);
int *getDispositivosEntrada();
int getQtdeDispositivosEntrada();
int getQtdeDispositivosSaida();
int *getDispositivosSaida();
int getPorta();


#endif /* LEJSON_H_ */