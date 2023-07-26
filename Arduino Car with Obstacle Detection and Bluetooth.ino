 Z);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo myservo;   

char command;
boolean goesForward=false;
int distance = 100;
int speedSet = 0;

void setup() {


  myservo.attach(10);  
  myservo.write(115); 
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}



void loop() {
 int distanceR = 0;
 int distanceL =  0;

     if(Serial.available()>0){
     command = Serial.read();
     
     
     delay(1000);

           
    switch(command){
    case 'A':
    {
      lookRight();
      lookLeft();
      moveF();
      delay(1000);
      moveStop();
      lookRight();
      lookLeft();
      turnRight();
      moveF();
      delay(500);
      lookRight();
      lookLeft();
      moveStop();
    }
    break;
    
    case 'B':
    {
      lookRight();
      lookLeft();
      moveF();
      delay(1000);
      moveStop();
      lookRight();
      lookLeft();
      turnLeft();
      moveF();
      delay(500);
      lookRight();
      lookLeft();
      moveStop();
    }
    break;
    }
}

}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  } 
  
void moveF() {

  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}



void turnRight() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);    
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);     
} 
 
void turnLeft() {
  motor1.run(BACKWARD);   
    motor2.run(FORWARD); 
      delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
}  
