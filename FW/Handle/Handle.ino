const int axisButtonPin = 2;                  
const int positiveDirectionButtonPin = 3;     
const int negativeDirectionButtonPin = 5;    
const int stopButtonPin = 4;                  

int selectedAxis = 0;                         
int selectedDirection = 0;                    
int stopValue = 0;                            

void setup() {
  pinMode(axisButtonPin, INPUT_PULLUP);
  pinMode(positiveDirectionButtonPin, INPUT_PULLUP);
  pinMode(negativeDirectionButtonPin, INPUT_PULLUP);
  pinMode(stopButtonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(axisButtonPin) == LOW) {
    delay(500); 
    selectedAxis++;
    if (selectedAxis > 3) {
      selectedAxis = 1;
    }
    selectedDirection = 0;
    Serial.print("Axis=");
    Serial.print(selectedAxis);
    Serial.print(" Enc=");
    Serial.print(selectedDirection);
    Serial.print(" Stop=");
    Serial.println(stopValue);
  }


  if (digitalRead(positiveDirectionButtonPin) == LOW) {
    delay(180); 

    selectedDirection = digitalRead(positiveDirectionButtonPin) == LOW ? 1 : 0;
    if (selectedDirection != 0) {
      Serial.print("Axis=");
      Serial.print(selectedAxis);
      Serial.print(" Enc=");
      Serial.print(selectedDirection);
      Serial.print(" Stop=");
      Serial.println(stopValue);
    }else{
      Serial.print("Axis=");
      Serial.print(selectedAxis);
      Serial.print(" Enc=");
      Serial.print(selectedDirection);
      Serial.print(" Stop=");
      Serial.println(stopValue);
      }
  }

  if (digitalRead(negativeDirectionButtonPin) == LOW) {
    delay(180);
    selectedDirection = digitalRead(negativeDirectionButtonPin) == LOW ? -1 : 0;
    if (selectedDirection != 0) {
      Serial.print("Axis=");
      Serial.print(selectedAxis);
      Serial.print(" Enc=");
      Serial.print(selectedDirection);
      Serial.print(" Stop=");
      Serial.println(stopValue);
    }else{
      Serial.print("Axis=");
      Serial.print(selectedAxis);
      Serial.print(" Enc=");
      Serial.print(selectedDirection);
      Serial.print(" Stop=");
      Serial.println(stopValue);
      }
  }

  if (digitalRead(stopButtonPin) == LOW) {
    delay(500);
    stopValue = 1 - stopValue;
    Serial.print("Axis=");
    Serial.print(selectedAxis);
    Serial.print(" Enc=");
    Serial.print(selectedDirection);
    Serial.print(" Stop=");
    Serial.println(stopValue);
  }
}
