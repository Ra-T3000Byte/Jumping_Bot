#define RPWM 5 // GPIO5 (D1)
#define LPWM 4 // GPIO4 (D2)
#define R_EN 0 // GPIO0 (D3)
#define L_EN 2 // GPIO2 (D4)
#define PWM_SPEED 200 // Speed value (0-1023 for ESP8266)

void setup() {
    pinMode(RPWM, OUTPUT);
    pinMode(LPWM, OUTPUT);
    pinMode(R_EN, OUTPUT);
    pinMode(L_EN, OUTPUT);
   
    digitalWrite(R_EN, HIGH); // Enable right side
    digitalWrite(L_EN, HIGH); // Enable left side
}

void loop() {
    // Rotate forward
    analogWrite(RPWM, PWM_SPEED);
    analogWrite(LPWM, 0);
    delay(1000); // Run for 3 seconds
   
    // Stop
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    delay(1000); // Pause for 1 second
   
    // Rotate backward
    analogWrite(RPWM, 0);
    analogWrite(LPWM, PWM_SPEED);
    delay(1000); // Run for 3 seconds
   
    // Stop
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    delay(1000); // Pause for 1 second
}
