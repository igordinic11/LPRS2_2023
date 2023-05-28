const int axisButtonPin = 2;         // Pin koji je povezan sa tasterom za izbor ose
const int directionButtonPin = 3;    // Pin koji je povezan sa tasterom za izbor smera
const int stopButtonPin = 4;         // Pin koji je povezan sa tasterom za izbor vrednosti za Stop

int selectedAxis = 1;                // Izabrana osa (1 = X, 2 = Y, 3 = Z)
int selectedDirection = 1;           // Izabrani smer (-1 = Negativan, 1 = Pozitivan)
int stopValue = 0;                   // Izabrana vrednost za Stop (0 = Isključeno, 1 = Uključeno)

void setup() {
  pinMode(axisButtonPin, INPUT_PULLUP);
  pinMode(directionButtonPin, INPUT_PULLUP);
  pinMode(stopButtonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Provera pritiska tastera za izbor ose
  if (digitalRead(axisButtonPin) == LOW) {
    delay(500); // Debouncing - kratko čekanje radi stabilnosti signala

    // Promena izabrane ose
    selectedAxis++;
    if (selectedAxis > 3) {
      selectedAxis = 1;
    }

    // Ispis na serijski port
    Serial.print("Axis=");
    Serial.print(selectedAxis);
    Serial.print(" Enc=");
    Serial.print(selectedDirection);
    Serial.print(" Stop=");
    Serial.println(stopValue);
  }

  // Provera pritiska tastera za izbor smera
  if (digitalRead(directionButtonPin) == LOW) {
    delay(500); // Debouncing - kratko čekanje radi stabilnosti signala

    // Promena izabranog smera
    selectedDirection *= -1;

    // Ispis na serijski port
    Serial.print("Axis=");
    Serial.print(selectedAxis);
    Serial.print(" Enc=");
    Serial.print(selectedDirection);
    Serial.print(" Stop=");
    Serial.println(stopValue);
  }

  // Provera pritiska tastera za izbor vrednosti za Stop
  if (digitalRead(stopButtonPin) == LOW) {
    delay(500); // Debouncing - kratko čekanje radi stabilnosti signala

    // Promena izabrane vrednosti za Stop
    stopValue = 1 - stopValue;

    // Ispis na serijski port
    Serial.print("Axis=");
    Serial.print(selectedAxis);
    Serial.print(" Enc=");
    Serial.print(selectedDirection);
    Serial.print(" Stop=");
    Serial.println(stopValue);
  }
}
