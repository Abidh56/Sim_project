/*
  gear 1-32,2-34,3-35,4-36,5-39,6-33

  Break           4,
  Accel           15,
  Clutch          14,
  rIndicator      26,
  lIndicator      25,
  Headlight       21,
  Engine          22,
  Wiper           23,
  horn            27
*/

#define g1 32
#define g2 34
#define g3 35
#define g4 36
#define g5 39
#define g6 33
int  Break, Accel, Clutch, rightindicator, leftindicator, Headlight, Engine, Wiper, Cl, horn;
int  Gp = 0;
int Status = 0;
long int timer;

void setup() {
  pinMode (g1, INPUT);
  pinMode (g2, INPUT);
  pinMode (g3, INPUT);
  pinMode (g4, INPUT);
  pinMode (g5, INPUT);
  pinMode (g6, INPUT);
  pinMode (25, INPUT);
  pinMode (26, INPUT);
  pinMode (27, INPUT);

  pinMode (21, INPUT);
  pinMode (22, INPUT);
  pinMode (23, INPUT);

  Serial.begin(115200);
  timer = millis();
}

void loop() {

  //break
  Break = map(analogRead(4), 4095, 0, 0, 100);
  if (Break <= 40) {
    Break = 0;
  }
  //accel
  Accel = map(analogRead(15), 4095, 0, 0, 100);

  //clatch
  Cl = map(analogRead(14), 4095, 0, 0, 100);


  if (Cl >= 50) {
    Clutch = 1;
  }
  else {
    Clutch = 0;
  }

  //indecator

  if (digitalRead(25) == 0) {
    leftindicator = 1;
  }
  else {
    leftindicator = 0;
  }

  if (digitalRead(26) == 0) {
    rightindicator = 1;
  }
  else {
    rightindicator = 0;
  }


  if (digitalRead(21) == 0) {
    Headlight = 1;
  }
  else {
    Headlight = 0;
  }

  if (digitalRead(23) == 0) {
    Wiper = 1;
    // Serial.println("Wp");
  }
  else {
    Wiper = 0;
  }


  if (digitalRead(22) == 0) {
    Engine = 1;
  }
  else {
    Engine = 0;
  }

  if (digitalRead(27) == 0) {
    horn = 1;
  }
  else {
    horn = 0;
  }


  if ((digitalRead(g1) == 0) & Clutch == 1)  {
    Gp = 4;
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g2) == 0) & Clutch == 1) {
    Gp = 1;
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g3) == 0) & Clutch == 1) {
    Gp =  6;
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g4) == 0) & Clutch == 1) {
    Gp = 2;
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g5) == 0) & Clutch == 1) {
    Gp = 3;
    //Serial.print("Gear: ");
    //Serial.println(Gp);
  }
  else if ((digitalRead(g6) == 0) & Clutch == 1)  {
    Gp = 5;
    //Serial.print("Gear: ");
    //Serial.println(Gp);


  }

  //Print

  if (millis() - timer >= 1) {
    //Serial.print("{");
    //    Serial.print("0"); /*steering*/Serial.print(",");
    Serial.print(Gp); /*Gear*/    Serial.print(",");
    Serial.print(Accel);          Serial.print(",");
    Serial.print(Cl);         Serial.print(",");
    Serial.print(Break); /*Break*/ Serial.print(",");
    //    Serial.print(", Status: ");




    // Serial.print(Headlight);        //Serial.print(",");
    //Serial.print(Engine);           //Serial.print(",");
    //Serial.print(Wiper);            //Serial.print(",");
    //Serial.println(leftindicator);    //Serial.print(",");
    //Serial.println(rightindicator);
    //Serial.println("}");

    Status = Headlight + 2 * horn + 4 * Engine + 8 *  Wiper + 16 *  leftindicator  + 32 * rightindicator ;
    Serial.println(Status);
    timer = millis();
  }
}
