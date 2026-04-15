// --- BUTTON PINS (use UNIQUE pins) ---
const int firstNumberButton = 2;
const int secondNumberButton = 3;
const int signButton = 4;
const int resultButton = 5;

// --- COUNTERS ---
int firstCount = 0;   // 0–15
int secondCount = 0;  // 0–15
int result = 0;

int signMode = 0;

// --- LED PINS ---
const int ledPins[5] = {9, 10, 11, 12, 13};          // result (5-bit)
const int SecondNumberPins[4] = {31, 33, 35, 37};    // second number (4-bit)
const int FirstNumberPins[4]  = {39, 41, 43, 45};    // first number (4-bit)
const int signPin = 47; 

// Buzzer pin
const int buzzerPin = 7;
    
// --- BUTTON STATES (for edge detection) ---
int lastFirstState  = HIGH;
int lastSecondState = HIGH;
int lastSignState   = HIGH;
int lastResultState = HIGH;

void setup() {
  // LED outputs
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(FirstNumberPins[i], OUTPUT);
    pinMode(SecondNumberPins[i], OUTPUT);
  }

  pinMode(signPin, OUTPUT);

  pinMode(buzzerPin, OUTPUT); // Set buzzer - pin 9 as an output

  // Buttons (pullups)
  pinMode(firstNumberButton, INPUT_PULLUP);
  pinMode(secondNumberButton, INPUT_PULLUP);
  pinMode(signButton, INPUT_PULLUP);
  pinMode(resultButton, INPUT_PULLUP);
}

void loop() {

  // --- READ BUTTONS ---
  int firstState  = digitalRead(firstNumberButton);
  int secondState = digitalRead(secondNumberButton);
  int signState   = digitalRead(signButton);
  int resultState = digitalRead(resultButton);

  // --- FIRST NUMBER BUTTON ---
  if (firstState == LOW && lastFirstState == HIGH) {
    firstCount++;
    if (firstCount > 15) firstCount = 0;
    delay(150);
  }

  // --- SECOND NUMBER BUTTON ---
  if (secondState == LOW && lastSecondState == HIGH) {
    secondCount++;
    if (secondCount > 15) secondCount = 0;
    delay(150);
  }

  // --- SIGN TOGGLE BUTTON ---
  if (signState == LOW && lastSignState == HIGH) {
    signMode = !signMode;  // toggle
    delay(150);
  }

  // --- RESULT BUTTON ---
  if (resultState == LOW && lastResultState == HIGH) {
    result = 0;
    tone(buzzerPin, 1000); // Send 1K sound signal...
    delay(1000);        
    noTone(buzzerPin);     
    if (signMode == 0) {
      result = firstCount + secondCount;
      firstCount = 0;
      secondCount = 0;
    } else {
      result = firstCount - secondCount;
      if (result < 0) result = 0;  // clamp (optional)
      firstCount = 0;
      secondCount = 0;
    }
    // Play a simple melody (C5, E5, G5)
    tone(buzzerPin, 523, 200); 
    delay(250);
    tone(buzzerPin, 659, 200); 
    delay(250);
    tone(buzzerPin, 784, 400); 
  }

  // --- UPDATE LAST STATES ---
  lastFirstState  = firstState;
  lastSecondState = secondState;
  lastSignState   = signState;
  lastResultState = resultState;

  // --- DISPLAY FIRST NUMBER (4-bit) ---
  for (int i = 0; i < 4; i++) {
    int bitValue = (firstCount >> i) & 1;
    digitalWrite(FirstNumberPins[i], bitValue);
  }

  // --- DISPLAY SECOND NUMBER (4-bit) ---
  for (int i = 0; i < 4; i++) {
    int bitValue = (secondCount >> i) & 1;
    digitalWrite(SecondNumberPins[i], bitValue);
  }

  // --- DISPLAY SIGN ---
  digitalWrite(signPin, signMode == 0 ? LOW : HIGH);

  // --- DISPLAY RESULT (5-bit) ---
  for (int i = 0; i < 5; i++) {
    int bitValue = (result >> i) & 1;
    digitalWrite(ledPins[i], bitValue);
  }
}

