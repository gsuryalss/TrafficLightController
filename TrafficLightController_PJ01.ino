/*
To implement the automated traffic light controller in single circuit.
*/

#define GLED 3       // Green LED 
#define YLED 4       // Yellow LED
#define RLED 5       // Red LED

#define PAUSE 250    // intermediate delay quarter second

#define YDUR 5000    // Yellow LED ON duration
#define RDUR 15000    // Red LED ON duration

// initialize push button
int switchState =0;

/*
Setup function runs only one time
*/
void setup(){
 
  pinMode(2, INPUT);  // intialize push button input
   
  // intialize output led ports
  pinMode(GLED, OUTPUT);  
  pinMode(YLED, OUTPUT);  
  pinMode(RLED, OUTPUT);
 
}

/* 
Indefinite loop routine
*/
void loop() {
  
  switchState=digitalRead(2); // reads signal from push button
  
  if(switchState == LOW){
    
    digitalWrite(GLED, HIGH); // Green glows
    digitalWrite(YLED,LOW);
    digitalWrite(RLED,LOW);
  
}
else{  // button is pressed
  
  delay(PAUSE);
  digitalWrite(GLED,LOW);
  digitalWrite(YLED, HIGH);  // yellow glows for 5 seconds
  delay(YDUR);
  digitalWrite(YLED, LOW);
  delay(PAUSE);
  digitalWrite(RLED,HIGH); // Red glows for 15 seconds
  delay(RDUR);
}

}
