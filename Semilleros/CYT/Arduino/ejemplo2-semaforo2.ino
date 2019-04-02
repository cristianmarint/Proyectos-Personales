#include <Adafruit_NeoPixel.h>

int PIN=2; //Pin donde está conectada la tira de leds
int NUMPIXELS=6; //Número de leds conectados

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// colores
const int colors [3][3]={
    {255,0,0}, //Rojo
    {255,255,0}, //Amarillo
    {0,255,0} //verde
};

// Variable que controla el turno global de los semaforos.
int estado=0;

void setup()
{
  Serial.begin(9600);

  pixels.begin(); // Inicialización
  pixels.show(); // Reiniciar todos los pixels apagados
}
 
void loop()
{
  semaforo(0,2,1,2);
  estado=0;
}


// Usa la variable global del estado
// Variables de tiempo para cada color del semaforo
//            //turno   t. rojo   t. verde   t. amarillo
void semaforo(int turno,float tr ,float te  ,float ta){
    while(estado==turno){
        // Serial.print("Estado=> ");Serial.println(estado);
        // Serial.print("+Turno=>");Serial.println(turno);


        int i = 0;
        int c = 0;

        float ut = 1000;

          // // rojo
          // pixels.setPixelColor(0, colors[0][0], colors[0][1], colors[0][2] );
          // pixels.setPixelColor(1, colors[0][0], colors[0][1], colors[0][2] );
          // pixels.show();
          // delay(ut*tr);
          // // amarillo
          // pixels.setPixelColor(2, colors[1][0], colors[1][1], colors[1][2] );
          // pixels.setPixelColor(3, colors[1][0], colors[1][1], colors[1][2] );
          // pixels.show();
          // delay(ut*te);
          // // verde
          // pixels.setPixelColor(4, colors[2][0], colors[2][1], colors[2][2] );
          // pixels.setPixelColor(5, colors[2][0], colors[2][1], colors[2][2] );
          // pixels.show();
          // delay(ut*ta);

          for( i = 0; i < pixels.numPixels(); i+2)
          {
            if(i%2!=0){c++;}
        // Serial.print("Estado=> ");Serial.println(estado);
        // Serial.print("+Turno=>");Serial.println(turno);
              pixels.setPixelColor(i, colors[c][0], colors[c][1], colors[c][2] );
              pixels.setPixelColor(i+1, colors[c][0], colors[c][1], colors[c][2] );
              pixels.show();
              delay(ut*tr);
          }

          for( i = 0; i < pixels.numPixels(); i++)
          {
            pixels.setPixelColor(i,0);
          }
          pixels.show();
          

        estado++; 
    }
}


// Circuito en:
// https://www.tinkercad.com/things/0mWjvUwhhYG-ejemplo2-semaforo2/


// tutorial para conectar la tira:
// https://www.youtube.com/watch?v=BQHMMlEAj3g