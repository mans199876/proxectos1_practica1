#include "ultrasonidos.cpp"
#include "motor.cpp"

int trig1 = , trig2 = , echo1 = , echo = ;
int enableA = , in1 = , in2 = ;
int enableB = , in3 = , in4 = ;

ultrasonidos ultrasonidos1(trig1, echo1);
ultrasonidos ultrasonidos2(trig2, echo2);

coche robot(enableA, enableB, in1, in2, in3, in4);

void setup() {
  // put your setup code here, to run once:
  ultrasonidos1.iniciar();
  ultrasonidos2.iniciar();
  robot.iniciarCoche();
}

void loop() {
  // put your main code here, to run repeatedly:
  long medicionAdelante = ultrasonidos1.medicion();
  long medicionAtras = ultrasonidos2.medicion();

  if ((medicionAdelante > 40) || (medicionAtras > 40)){
    if(medicionAdelante > medicionAtras) robot.moverAdelante(125);
    else robot.moverAtras(125);
  }else robot.parar();
}