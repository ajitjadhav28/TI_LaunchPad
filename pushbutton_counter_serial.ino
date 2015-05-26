// initializing variables and pins of microcontroller
short int button=PUSH2;
short int red=2;
short int green=14;
int count=0;
short int buttonState=0;
void setup()
{
  // put your setup code here, to run once:
  // initiakizing serial communication, push button 
  // and led pins
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(button,INPUT_PULLUP);
}

void loop()
{
  // actual counter goes here
  Serial.println("\nThis is Simple Counter \n Push pushbutton to count and enter x to exit");
  delay(5000);
      while(1){
        buttonState=digitalRead(button);
        if(buttonState==LOW){
          digitalWrite(red,LOW);
          digitalWrite(green,HIGH);
          count++;
          Serial.println(count);
          delay(300);
          digitalWrite(green,LOW);
        }
        digitalWrite(red,HIGH);
      if(Serial.read()=='x')
      {
        Serial.println("\nTotal Coutn = ");
        Serial.println(count);
        Serial.println("\nTerminating session");
        count=0;
        loop();
      }  
    }
 }    
 
