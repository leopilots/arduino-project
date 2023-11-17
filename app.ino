static int PinIN1 = 8; //motor izquierdo
static int PinIN2 = 9; //motor derecho
static int PinSensorIzq = 5;
static int PinSensorDer = 6;
static int PinSensorMed = 7;

void setup() {
    //iniciamos las comunicaciones con el puerto serie para el monitor serie
    Serial.begin(9600); 

    pinMode(PinIN1, OUTPUT);
    pinMode(PinIN2, OUTPUT);

    pinMode(PinSensorIzq, INPUT); //sensor izquierdo
    pinMode(PinSensorDer, INPUT); //sensor derecho
    pinMode(PinSensorMed, INPUT); //sensor del medio
}

void loop() {
    int sensorIzq = 0;
    int sensorDer = 0;
    int sensorMed = 0;

    sensorIzq = digitalRead(PinSensorIzq); 
    sensorDer = digitalRead(PinSensorDer);
    sensorMed = digitalRead(PinSensorMed);

    if(sensorIzq == LOW && sensorDer == LOW && sensorMed == HIGH) { EngineForward(); Serial.print("sensor del medio.\n"); }
    //if(sensorIzq == LOW && sensorDer == LOW && sensorMed == LOW) { EngineStop();  }
    if(sensorIzq == HIGH && sensorDer == LOW && sensorMed == LOW) { RightEngine(); Serial.print("sensor izquierdo\n"); }
    if(sensorDer == HIGH && sensorIzq == LOW && sensorMed == LOW) { LeftEngine(); Serial.print("sensor derecho\n"); }

    delay(20); 
}

// funciones
void EngineForward() {
    digitalWrite (PinIN1, HIGH);   //motor izquierdo adelante
    digitalWrite (PinIN2, HIGH);   //motor derecho adelante
}

void EngineStop() {
    digitalWrite (PinIN1, LOW);   //motor izquierdo detenido
    digitalWrite (PinIN2, LOW);   //motor derecho detenido
}

void RightEngine() {
    digitalWrite(PinIN1, LOW);  //motor izquierdo no avanza
    digitalWrite(PinIN2, HIGH);  //motor derecho avanza
}

void LeftEngine() {
    digitalWrite(PinIN1, HIGH);   //motor izquierdo avanza
    digitalWrite(PinIN2, LOW);    //motor derecho no avanza
}
