#include <LiquidCrystal.h>
 #include <Servo.h>
LiquidCrystal lcd = LiquidCrystal(13, 12, 11, 10, 9, 8);

int S1 = 7;
int S2 = 6;
int S3 = 5;
int S4 = 4;

int IN = 1;
int OUT = 2;
int gateMotor = 0;

//identify servo
Servo myservo;

void setup()
{
  lcd.begin(20, 4); // initialize the lcd
  pinMode (S1, INPUT);
  pinMode (S2, INPUT);
  pinMode (S3, INPUT);
  pinMode (S4, INPUT);
  pinMode (IN, INPUT);
  pinMode (OUT, INPUT);
  pinMode (gateMotor, OUTPUT);



  //red,green leed configure
  pinMode (14, OUTPUT);
   pinMode (15, OUTPUT);
    pinMode (16, OUTPUT);
     pinMode (17, OUTPUT);
      pinMode (18, OUTPUT);
       pinMode (19, OUTPUT);
        pinMode (20, OUTPUT);
         pinMode (21, OUTPUT);
      
      
myservo.attach(gateMotor);
   
}


void loop()
{
 
  //first row show
  if ((digitalRead(S1) == HIGH) && (digitalRead(S2) == HIGH) && (digitalRead(S3) == HIGH) && (digitalRead(S4) == HIGH))
  {
    lcd.setCursor(8, 0);
    lcd.print("     ");
    lcd.setCursor(3, 0);
    lcd.print("               ");
    lcd.setCursor(3, 0);
    lcd.print("Sorry, no empty");

  } else {
    lcd.setCursor(8, 0);
    lcd.print("     ");
    lcd.setCursor(3, 0);
    lcd.print("               ");
    lcd.setCursor(8, 0);
    lcd.print("Slots");

  }


  lcd.setCursor(0, 2);
  lcd.print("S1:");

  lcd.setCursor(11, 2);
  lcd.print("S2:");

  lcd.setCursor(0, 3);
  lcd.print("S3:");

   lcd.setCursor(11,3);
     lcd.print("S4:");

  //CHeck Slot 1
  if (digitalRead(S1) == LOW) {

    lcd.setCursor(3, 2);
    lcd.print("     ");
    lcd.setCursor(3, 2);
    lcd.print("empty");
    digitalWrite(14,HIGH);
    digitalWrite(15,LOW);

  } else {
    lcd.setCursor(3, 2);
    lcd.print("     ");
    lcd.setCursor(3, 2);
    lcd.print("NA");
    digitalWrite(14,LOW);
    digitalWrite(15,HIGH);

  }


  //check slot 2
  if (digitalRead(S2) == LOW) {

    lcd.setCursor(14, 2);
    lcd.print("     ");
    lcd.setCursor(14, 2);
    lcd.print("empty");
     digitalWrite(16,HIGH);
    digitalWrite(17,LOW);
  } else {

    lcd.setCursor(14, 2);
    lcd.print("     ");
    lcd.setCursor(14, 2);
    lcd.print("NA");
     digitalWrite(16,LOW);
    digitalWrite(17,HIGH);
  }


  //check slot 3
  if (digitalRead(S3) == LOW) {

    lcd.setCursor(3, 3);
    lcd.print("     ");
    lcd.setCursor(3, 3);
    lcd.print("empty");
     digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    

  } else {
    lcd.setCursor(3, 3);
    lcd.print("     ");
    lcd.setCursor(3, 3);
    lcd.print("NA");
         digitalWrite(18,LOW);
    digitalWrite(19,HIGH);

  }

  //check slot 4
  if (digitalRead(S4) == LOW) {

    lcd.setCursor(14, 3);
    lcd.print("     ");
    lcd.setCursor(14, 3);
    lcd.print("empty");
    digitalWrite(20,HIGH);
    digitalWrite(21,LOW);


  } else {
    lcd.setCursor(14, 3);
    lcd.print("     ");
    lcd.setCursor(14, 3);
    lcd.print("NA");
 digitalWrite(20,LOW);
    digitalWrite(21,HIGH);
  }



  // IN part
  if ((digitalRead(IN) == HIGH) && ((digitalRead(S1) == LOW) || (digitalRead(S2) == LOW) || (digitalRead(S3) == LOW) || (digitalRead(S4) == LOW)))
  {
     for (int pos = 0; pos <= 90; pos += 1) { 
    myservo.write(pos);              
    delay(15);                     
     }
   delay(1000);
     for (int pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                     
     }
 
  }

  

  //OUT
 if(digitalRead(OUT) == HIGH){
     for (int pos = 0; pos <= 90; pos += 1) { 
    myservo.write(pos);              
    delay(15);                     
     }
   delay(1000);
     for (int pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                     
     }
  } 
 


}
