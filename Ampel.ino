// Definiere die Pins für die Ampel und den Knopf
const int greenPin = 2;
const int yellowPin = 3;
const int redPin = 4;
const int buttonPin = 5;

// Definiere die Anfangszeiten für jede Phase der Ampel
const unsigned long greenTime = 5000; // 5 Sekunden für Grün
const unsigned long yellowTime = 2000; // 2 Sekunden für Gelb
const unsigned long redTime = 5000; // 5 Sekunden für Rot

// Variablen zur Verfolgung der Ampelzustände und der Zeit
int currentState = 0; // 0 = Grün, 1 = Gelb, 2 = Rot
unsigned long previousMillis = 0;

// Initialisierung
void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Der Knopf ist an VCC verbunden, wenn er nicht gedrückt wird
}

// Hauptprogramm
void loop() {
  unsigned long currentMillis = millis(); // Aktuelle Zeit abrufen
  
  // Knopfzustand überprüfen
  if (digitalRead(buttonPin) == LOW) {
    // Knopf wurde gedrückt, setze die Ampel auf Rot
    currentState = 2;
  }
  
  // Ampelsteuerung
  switch(currentState) {
    case 0: // Grün
      digitalWrite(greenPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      if (currentMillis - previousMillis >= greenTime) {
        currentState = 1; // Wechsel zu Gelb
        previousMillis = currentMillis;
      }
      break;
    case 1: // Gelb
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, LOW);
      if (currentMillis - previousMillis >= yellowTime) {
        currentState = 2; // Wechsel zu Rot
        previousMillis = currentMillis;
      }
      break;
    case 2: // Rot
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);
      // Hier bleibt die Ampel auf Rot, bis der Knopf gedrückt wird
      break;
  }
}
