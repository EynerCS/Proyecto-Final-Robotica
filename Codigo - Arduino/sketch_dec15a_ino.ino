#include <Servo.h> 
#include <EEPROM.h>

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor

//////ABAJO
Servo myservo9;
Servo myservo11;
Servo myservo8;
Servo myservo10;
// create servo object to control a servo 
                // a maximum of eight servo objects can be created 
////////////ARRIBA
//Servo myservo7;
////////////////////
 
int pos = 0;    // variable to store the servo position 
int pos1 = 170; 
 
void setup() 
{ 
  
  for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);
    
  // turn the LED on when we're done
  digitalWrite(13, HIGH);  
  
  
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  
  
  //ABAJO
  //////angulo 180
  myservo9.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo11.attach(11);
  ////////////////angulo0
  myservo8.attach(8);
  myservo10.attach(10);
  ///ARRIBA/////////////////ARRIBA
  //myservo7.attach(7);
  
  
  /////////////
    /////////POSICION INICIAL/////////////////////
  myservo9.write(170);
  myservo11.write(170);
  myservo8.write(10);
  myservo10.write(10); 
  ////INICIAL ARRIBA//
  //myservo7.write(170);
  ///////////////////////
  
}
 
void planchas(){

  for(pos = 10; pos < 170; pos += 1)  // goes from 0 degrees to 180 degrees 
  { 
    pos1 -=1; 
    myservo8.write(pos);
    myservo10.write(pos);
    //////////
    myservo9.write(pos1);
    myservo11.write(pos1);
    // in steps of 1 degree 
    //myservo.write(pos);
    
          // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 170; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    pos1 += 1;
    myservo8.write(pos);
    myservo10.write(pos);
    //////////
    myservo9.write(pos1);
    myservo11.write(pos1);    
    
    
        // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }

}

void loop() 
{ 
  
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  
  if(d<120){
    planchas();
  }
   
  

}
