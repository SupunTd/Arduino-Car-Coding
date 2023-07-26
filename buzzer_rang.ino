
int status = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char data = Serial.read();

    Serial.write(data);


    if(data == 'R'){
      status = 1;
      }else if (data == 'L'){
        status = 0;
        }

    //delay(50);


    if(status == 1) {
      digitalWrite(13,HIGH);
      }else{
              digitalWrite(13,LOW);
        }
    
    
}

}
