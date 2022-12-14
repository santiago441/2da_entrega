#include "mbed.h"

DigitalIn Pulsador(A1);
DigitalOut Display1(A3);

BusOut Segmentos(D2,D3,D4,D5,D6,D7,D8,D9); // A B C D E F G DP

const char seg[6] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF}; // A B C D E F
const char numeros[6] = {0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82}; // 1 2 3 4 5 6


void Efecto(void);
void Random(void);


int main() {

 Display1 = 1;

 Segmentos = 0xC0; // Numero inicial del display en 0

 while (1) {   

     if(Pulsador == 1){     

         int Pulsador = 1;  

         Efecto();   // Visualización efecto carga de numero funcion efecto                                 
         Efecto();   // Visualización efecto carga de numero funcion efecto por 2da vez
         Random();   // Visualizacion del numero aleatoreo
         ThisThread::sleep_for(500ms);

         Pulsador = 0;

        }

    }

}

// Función para efecto de carga de numero
void Efecto(void){
     
    //secuencia segmentos

    for(int i=0 ; i<6 ; i++) {

        Segmentos = seg[i];

        ThisThread::sleep_for(100ms);

    }
     
}

// Funcion para numero aleatoreo
void Random(void){
    
    int num;

    num = rand()%6;   

    Segmentos = numeros[num];

}
