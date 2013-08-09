//CO burn in

//Karen Nisley under Non-Commercial Share-Alike Attribution CC.


const int sensorZero = A0;        //sensor inputs to Arduino
const int sensorOne = A1;
const int sensorTwo = A2;
const int sensorThree = A3;        //sensor inputs to Arduino
const int sensorFour = A4;
const int sensorFive = A5;

int sensorZeroValue = 0;          //initial value of sensor inputs
int sensorOneValue = 0;
int sensorTwoValue = 0;
int sensorThreeValue = 0;          
int sensorFourValue = 0;
int sensorFiveValue = 0;

const int sensorControl0 = 5;  //PWM output to fet
const int sensorControl1 = 6;  //PWM output to fet

const int ledPin =  13;     //the number of the LED pin

int iterations = 0;


void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(sensorControl0, OUTPUT);
  pinMode(sensorControl1, OUTPUT);
  Serial.begin(9600); 
  Serial.println("We're gonna take data!");
  Serial.println("Sensor Zero, Sensor One, Sensor Two, Iterations");
  digitalWrite(sensorControl0, HIGH);
  digitalWrite(sensorControl1, HIGH);
  delay(300000);        //wait 5 minutes for preheat
}


void loop(){
  while(iterations < 144){
  //turn on fets
  digitalWrite(sensorControl0, HIGH);
  digitalWrite(sensorControl1, HIGH);
  
  //wait for heat
  delay(60000);                           //wait for 60 seconds of heat
  //take data, blink LED while taking data and sending to computer
  digitalWrite(ledPin, HIGH);
  sensorZeroValue = analogRead(sensorZero);
  sensorOneValue = analogRead(sensorOne);
  sensorTwoValue = analogRead(sensorTwo);
  sensorThreeValue = analogRead(sensorThree);
  sensorFourValue = analogRead(sensorFour);
  sensorFiveValue = analogRead(sensorFive);
  iterations = iterations ++;
  // print the results to the serial monitor:                       
  Serial.print(sensorZeroValue);
  Serial.print(", ");
  Serial.print(sensorOneValue);
  Serial.print(", ");
  Serial.print(sensorTwoValue);
  Serial.print(", ");
  Serial.print(sensorThreeValue);
  Serial.print(", ");
  Serial.print(sensorFourValue);
  Serial.print(", ");
  Serial.print(sensorFiveValue);
  Serial.print(", ");
  Serial.println(iterations);
  digitalWrite(sensorControl0, LOW);
  digitalWrite(sensorControl1, LOW);
  digitalWrite(ledPin, LOW);
  delay(90000);                      //wait for 90 seconds of cool
  }
  
}
