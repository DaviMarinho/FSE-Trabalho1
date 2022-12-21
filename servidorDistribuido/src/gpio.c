#include "gpio.h"
#include "comunicacao.h"

int gpioToPin( int value ){
  /*
    Receives a GPIO port number and translates to a WiringPI pin number
  */

    int pinToGpioR2 [64] = {
      17, 18, 27, 22, 23, 24, 25, 4,	// From the Original Wiki - GPIO 0 through 7:	wpi  0 -  7
      2,  3,				                  // I2C  - SDA0, SCL0				wpi  8 -  9
      8,  7,				                  // SPI  - CE1, CE0				wpi 10 - 11
      10,  9, 11, 			            	// SPI  - MOSI, MISO, SCLK			wpi 12 - 14
      14, 15,			                  	// UART - Tx, Rx				wpi 15 - 16
      28, 29, 30, 31,			            // Rev 2: New GPIOs 8 though 11			wpi 17 - 20
      5,  6, 13, 19, 26,		         	// B+						wpi 21, 22, 23, 24, 25
      12, 16, 20, 21,			            // B+						wpi 26, 27, 28, 29
      0,  1,			                  	// B+						wpi 30, 31
    } ;


    int index = 0;

    while ( index < 64 && pinToGpioR2[index] != value ) ++index;

    return ( index == 64 ? -1 : index );
}

void ativaDesativaDispositivo(int codigoGPIO, int status) {
  printf("===============================\n");
  printf("| Alterando estado da gpio %d |\n", codigoGPIO);
  printf("===============================\n");
  printf("\n");

  int wiringPIpin = gpioToPin(codigoGPIO);
  pinMode(wiringPIpin, OUTPUT);
  digitalWrite(wiringPIpin, status);
}

void sensorPresenca(void) {
  int message = 1;
  enviaCentral(message);
  printf("======================\n");
  printf("| Sensor de Presença |\n");
  printf("======================\n");
  printf("\n");
}

void sensorFumaca(void) {
  int message = 2;
  enviaCentral(message);
  printf("====================\n");
  printf("| Sensor de Fumaça |\n");
  printf("====================\n");
  printf("\n");
}

void sensorJanela(void) {
  int message = 3;
  enviaCentral(message);
  printf("====================\n");
  printf("| Sensor da Janela |\n");
  printf("====================\n");
  printf("\n");
}

void sensorPorta(void) {
  int message = 4;
  enviaCentral(message);
  printf("===========================\n");
  printf("| Sensor porta de entrada |\n");
  printf("===========================\n");
  printf("\n");
}


void* handleGPIO() {
  /*
    Used to interact with all sensors
  */

  // looping through all sensors and using wiringPiISR to interact with them, also attaching
  // the handler functions which will be called upon any changes 

  int *portasDispositivosEntrada =  getDispositivosEntrada();
  int qtdeDispositivosEntrada = getQtdeDispositivosEntrada();
  int gpioPort;
  int wiringPIpin;

  for(int i =0; i < qtdeDispositivosEntrada ; i++){
      gpioPort = portasDispositivosEntrada[i];
      wiringPIpin = gpioToPin(gpioPort);
      pinMode(wiringPIpin, OUTPUT);
      switch (gpioPort)
      {
        case 7:
         wiringPiISR(wiringPIpin, INT_EDGE_BOTH, sensorPresenca);
         break;
        case 1:
         wiringPiISR(wiringPIpin, INT_EDGE_BOTH, sensorFumaca);
         break;
        case 12:
         wiringPiISR(wiringPIpin, INT_EDGE_BOTH, sensorJanela);
         break;
        case 16:
         wiringPiISR(wiringPIpin, INT_EDGE_BOTH, sensorPorta);
         break;
      default:
        break;
      }
     
  }

  for(;;) {
    sleep(1);
  }
}

void desativaDispositivos() {

  int *portasDispositivosSaida =  getDispositivosSaida();
  int qtdeDispositivosSaida = getQtdeDispositivosSaida();
  int wiringPIpin;

  for (size_t i = 0; i < qtdeDispositivosSaida; i++)
  {
    wiringPIpin = gpioToPin(portasDispositivosSaida[i]);
    pinMode(wiringPIpin, OUTPUT);
    digitalWrite(wiringPIpin, LOW);
  }

}