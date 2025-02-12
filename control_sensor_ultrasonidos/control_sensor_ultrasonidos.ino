//Librerias necesarias

//Variables globales
const int echo = 4;
const int trigger = 5;
int distancia;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //iniciamos el puerto serie
  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  distancia = detecta_sensor();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print("cm");

  delay(100);

}

//Funcion para medir la distancia con un sensor de ultrasonidos
int detecta_sensor(){
  long tiempo;
  long distancia;

  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigger, LOW);

  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo * 0.01657;

  return (distancia);
}
