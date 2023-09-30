#include <RotaryEncoder.h>

RotaryEncoder encoder(13, 27);
#define g1 32
#define g2 34
#define g3 35
#define g4 36
#define g5 39
#define g6 33
int newpos, Break, Accel;
long int timer;
char Gp, Clutch,led;

void setup() {


  pinMode (g1, INPUT);
  pinMode (g2, INPUT);
  pinMode (g3, INPUT);
  pinMode (g4, INPUT);
  pinMode (g5, INPUT);
  pinMode (g6, INPUT);
  pinMode (25, INPUT);
  pinMode (26, INPUT);
  Serial.begin(115200);
  timer = millis();
}

void loop() {
  //break
  Break = map(analogRead(4), 0, 3000, 100, 0);

  //accel
  Accel = map(analogRead(15), 0, 3000, 100, 0);

  //clatch
  if (analogRead(14) <= 1500) {
    Clutch = 1;
  }
  else {
    Clutch = 0;
  }

  //encoder
  static int pos = 0;
  encoder.tick();
  newpos = encoder.getPosition();
  if (pos != newpos) {
    pos = newpos;
    //Serial.print("pos:");
    //Serial.println(newpos);
  }


  //indecator

  if (digitalRead(25) == 0) {
    led = '1';
  }
  else if (digitalRead(26) == 0) {
    led = '2';
  }
  else {
    led = '0';
  }


  if ((digitalRead(g1) == 0) & Clutch == 1)  {
    Gp = '1';
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g2) == 0) & Clutch == 1) {
    Gp = '3';
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g3) == 0) & Clutch == 1) {
    Gp =  '2';
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g4) == 0) & Clutch == 1) {
    Gp = '5';
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g5) == 0) & Clutch == 1) {
    Gp = '4';
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g6) == 0) & Clutch == 1)  {
    Gp = '6';
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }

  //Print

  if (millis() - timer >= 500) {
    //    Serial.println("ok");
    Serial.print("Gear: ");
    Serial.print(Gp);
    Serial.print(", pos:");
    Serial.print(newpos);
    Serial.print(", Break: ");
    Serial.print(Break);
    Serial.print(", Accel: ");
    Serial.print(Accel);
    Serial.print(", led: ");
    Serial.println(led);
    timer = millis();
  }
}
