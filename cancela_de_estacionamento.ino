#include <Servo.h>
#include <Ultrasonic.h>

Servo myservo; // Criando a variável para o servo

int pos = 0; // Definindo um valor inicial para variável que guarda a posição do servo motor
const int echo = 5; // Definindo o pino do ultrasônico que envia as ondas ultrasônicas
const int trig = 4; // Definindo o pino do ultrasônico que recebe as ondas ultrasônicas

Ultrasonic ultrasonic(trig, echo);

int distance = 0;

void setup() {
  myservo.attach(6); // Definindo pino responsável pelo controle do servo motor
  Serial.begin(9600); // Iniciando comunicação serial
}

void loop() {
  
  distance = ultrasonic.read();
  Serial.println(distance); // Mostrando resultados na serial
  
  if (distance < 15) {
    if (pos > 140) {
      for (pos = 150; pos >= 60; pos -= 4) {
        myservo.write(pos);
        delay(5);
      }  
    }
    delay(3000);
  } else {
    if (pos < 150) {
     for (pos = pos; pos <= 150; pos += 4) {
        // in steps of 1 degree
        myservo.write(pos);
        delay(5);
      }
      delay(200);
    } 
  }
  
  delay(20);
}
