static int PinMotorIzq = 8; 
static int PinMotorDer = 9; 
static int PinSensorIzq = 5;
static int PinSensorDer = 6;
static int PinSensorMed = 7;

void setup() {
    Serial.begin(9600); 

    pinMode(PinMotorIzq, OUTPUT);
    pinMode(PinMotorDer, OUTPUT);

    pinMode(PinSensorIzq, INPUT); 
    pinMode(PinSensorDer, INPUT);
    pinMode(PinSensorMed, INPUT);
}

void loop() {
    int sensorIzq = 0;
    int sensorDer = 0;
    int sensorMed = 0;

    sensorIzq = digitalRead(PinSensorIzq); 
    sensorDer = digitalRead(PinSensorDer);
    sensorMed = digitalRead(PinSensorMed);

    if(sensorIzq == LOW && sensorDer == LOW && sensorMed == HIGH) { EngineForward(); }
    if(sensorIzq == HIGH && sensorDer == LOW && sensorMed == LOW) { RightEngine(); }
    if(sensorDer == HIGH && sensorIzq == LOW && sensorMed == LOW) { LeftEngine(); }

    delay(20); 
}

void EngineForward() {
    digitalWrite(PinMotorIzq, HIGH);  
    digitalWrite(PinMotorDer, HIGH);  
}

void EngineStop() {
    digitalWrite(PinMotorIzq, LOW);   
    digitalWrite(PinMotorDer, LOW);   
}

void RightEngine() {
    digitalWrite(PinMotorIzq, LOW);  
    digitalWrite(PinMotorDer, HIGH); 
}

void LeftEngine() {
    digitalWrite(PinMotorIzq, HIGH);  
    digitalWrite(PinMotorDer, LOW);   
}
