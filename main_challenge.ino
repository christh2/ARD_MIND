const int red_led=1;
const int green_led=2;
const int blue_led=3;

const int red_button=8;
const int green_button=9;
const int blue_button=10;

const int leds[3]={1,2,3};
const int potentio=0;
int tension= 0;

int red_state;
int green_state;
int blue_state;

void setup() {
 pinMode(red_led,OUTPUT);
 pinMode(green_led,OUTPUT);
 pinMode(blue_led,OUTPUT);

 pinMode(red_button,INPUT);
 pinMode(green_button,INPUT);
 pinMode(blue_button,INPUT);

 int i=0
 for(i=0;i<3;i++){
  pinMode(leds[i],OUTPUT);
  digitalWrite(leds[i],LOW)
 }
 
}

void loop() {
  
  red_state=0;
  green_state=0;
  blue_state=0;

  red_state=digitalRead(red_button);
  green_state=digitalRead(green_button);
  blue_state=digitalRead(blue_button);
  
  if (red_state==1){
    digitalWrite(red_led,LOW);
  }
  else{
    digitalWrite(red_led,HIGH);
  }

  if (green_state==1){
    digitalWrite(green_led,LOW);
  }
  else{
    digitalWrite(green_led,HIGH);
  }

  if (blue_state==1){
    digitalWrite(blue_led,LOW);
  }
  else{
    digitalWrite(blue_led,HIGH);
  }

tension=analogRead(potentio);

}