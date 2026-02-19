/*
  Blink
  Developer: Kade Demaagd
  Date 2.13.2026

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// the setup function runs once when you press reset or power the board
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(10, OUTPUT);  
  pinMode(9, OUTPUT);   
  pinMode(8, OUTPUT);   
  pinMode(6, OUTPUT);   
}

void loop() {

  // ===== SIREN SWEEP UP =====
  for (int freq = 500; freq <= 1500; freq += 10) {

    tone(8, freq);

    // --- Double flash left ---
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    delay(40);
    digitalWrite(10, LOW);
    delay(40);

    digitalWrite(10, HIGH);
    delay(40);
    digitalWrite(10, LOW);
    delay(80);

    // --- Double flash right ---
    digitalWrite(9, HIGH);
    delay(40);
    digitalWrite(9, LOW);
    delay(40);

    digitalWrite(9, HIGH);
    delay(40);
    digitalWrite(9, LOW);
    delay(80);

    // Fade LED (same as before)
    analogWrite(6, brightness);
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
  }

  // ===== SIREN SWEEP DOWN =====
  for (int freq = 1500; freq >= 500; freq -= 10) {

    tone(8, freq);

    // Same strobe pattern
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    delay(40);
    digitalWrite(10, LOW);
    delay(40);

    digitalWrite(10, HIGH);
    delay(40);
    digitalWrite(10, LOW);
    delay(80);

    digitalWrite(9, HIGH);
    delay(40);
    digitalWrite(9, LOW);
    delay(40);

    digitalWrite(9, HIGH);
    delay(40);
    digitalWrite(9, LOW);
    delay(80);

    analogWrite(6, brightness);
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
  }
}
