const int LED_PIN = 13;
int clignonte = 5;  
const int DUREE_VARIATION = 2048;  // a diviser par 256 pour delaie
const int ATTENTE_ALLUMAGE = 2000;
const int ATTENTE_CLIGNONTEMENT= 250;
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);  // initialise les series de communication
}
void allumer() {
  Serial.println("Allume – 6225272");
  digitalWrite(LED_PIN, HIGH);
  delay(ATTENTE_ALLUMAGE);
};

void clignonter() {
  Serial.println("Clignontement–6225272");
  for (int i = 0; i < clignonte; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(ATTENTE_CLIGNONTEMENT);
    digitalWrite(LED_PIN, LOW);
    delay(ATTENTE_CLIGNONTEMENT);
  }
};

void variation() {
  Serial.println("Variation - 6225272");
  int delaiVariation = (DUREE_VARIATION/256);
  for (int i = 0; i <= 255; i++) {
    analogWrite(LED_PIN, i);
    delay(delaiVariation);
  }
};

void eteint() {
  Serial.println("Éteint - 6225272");
  digitalWrite(LED_PIN, LOW);
  delay(ATTENTE_ALLUMAGE);
};

void loop() {
  allumer();
  clignonter();
  variation();
  eteint();
};
