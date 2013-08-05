//CO burn in

//Karen Nisley under Non-Commercial Share-Alike Attribution CC.


const int sensorZero = A0;        //direct control input

int sensorZeroValue = 0;          //initial value of sensorZero's input

const int sensorZeroControl = 5;  //PWM output to direct control

const int ledPin =  13;     //the number of the LED pin

int iterations = 0;


void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(sensorZeroControl, OUTPUT);
  Serial.begin(9600); 
  Serial.println("We're gonna heat for 5 minutes, and then take data!");
  digitalWrite(sensorZeroControl, HIGH);
  delay(300000);        //wait 5 minutes for preheat
}


void loop(){
  while(iterations < 144){
  //turn on fets
  digitalWrite(sensorZeroControl, HIGH);
  
  //wait for heat
  delay(60000);                           //wait for 60 seconds of heat
  //take data, blink LED while taking data and sending to computer
  digitalWrite(ledPin, HIGH);
  sensorZeroValue = analogRead(sensorZero);
  // print the results to the serial monitor:
  Serial.print("sensorZero = " );                       
  Serial.println(sensorZeroValue);      
  iterations = iterations ++;  
  Serial.print("We've done this ");
  Serial.print(iterations);
  Serial.println(" times.");
  digitalWrite(sensorZeroControl, LOW);
  digitalWrite(ledPin, LOW);
  delay(90000);                      //wait for 90 seconds of cool
  }
  
}
