long int timer =0;
void setup() {
  Serial.begin(115200);
  timer = millis();
}

void loop() {
  //Print

  if (millis() - timer >= 500) {
    //    Serial.println("ok");
    Serial.print("Gear: ");
    Serial.print(random(1,5));
    Serial.print(", Steering pos:");
    Serial.print(random(0,360));
    Serial.print(", Break: ");
    Serial.print(random(1,10));
    Serial.print(", Accel: ");
    Serial.println(random(1,10));
    timer = millis();
  }
}
