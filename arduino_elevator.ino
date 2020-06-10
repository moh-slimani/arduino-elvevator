
// 7 segments pins
int a = 22;
int b = 23;
int c = 24;
int d = 25;
int e = 26;
int f = 27;
int g = 28;


// limit switches pins
int sw1 = 2;
int sw2 = 3;
int sw3 = 18;

void setup() {
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G


  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(sw1), floor1reach, FALLING );
  attachInterrupt(digitalPinToInterrupt(sw2), floor2reach, FALLING );
  attachInterrupt(digitalPinToInterrupt(sw3), floor3reach, FALLING );
}

void loop() {
  delay(10000);
}


void displayDigit(int digit)
{
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);
 
 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);
 
 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);
 
 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);
 
 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);
 
 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);
 
}
void displayDigitOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void floor1reach() {
  displayDigitOff();
  displayDigit(1);
}

void floor2reach() {
  displayDigitOff();
  displayDigit(2);
}

void floor3reach() {
  displayDigitOff();
  displayDigit(3);
}
