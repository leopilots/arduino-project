static int PinIN1 = 2;
static int PinIN2 = 3;
static int PinIN3 = 4;
static int PinIN4 = 5;
static int PinSensorIzq = 8;
static int PinSensorDer = 9;
static int PinSensorMed = 10;

void setup() {
    //iniciamos las comunicaciones con el puerto serie para el monitor serie
    Serial.begin(9600); 

    pinMode(PinIN1, OUTPUT);
    pinMode(PinIN2, OUTPUT);
    pinMode(PinIN3, OUTPUT);
    pinMode(PinIN4, OUTPUT);
    pinMode(PinSensorIzq, INPUT); //sensor izquiero
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

    if(sensorIzq == LOW && sensorDer == LOW && sensorMed == HIGH) {                                 
        EngineForward();                                                                            
    }
    if(sensorIzq == LOW && sensorDer == LOW && sensorMed == LOW) {
        EngineStop();                                                                               
    }
    if(sensorIzq == HIGH && sensorDer == LOW && sensorMed == LOW) {                                   
        RightEngine();                                                                              
    }
    if(sensorDer == HIGH && sensorIzq == LOW && sensorMed == LOW) {                                 
        LeftEngine();                                                                               
    }
    delay(20); 
}

// funciones
void EngineForward() {
    digitalWrite (PinIN1, LOW);   //motor izquierdo adelante
    digitalWrite (PinIN2, HIGH); 
    digitalWrite (PinIN3, HIGH);  //motor derecho adelante
    digitalWrite (PinIN4, LOW); 
}

void EngineStop() {
    digitalWrite (PinIN1, LOW);   //motor izquierdo detenido
    digitalWrite (PinIN2, LOW);
    digitalWrite (PinIN3, LOW);   //motor derecho detenido 
    digitalWrite (PinIN4, LOW);
}

void RightEngine() {
    digitalWrite (PinIN1, HIGH);  //motor izquierdo atras
    digitalWrite (PinIN2, LOW);  
    digitalWrite (PinIN3, HIGH);  //motor derecho adelante
    digitalWrite (PinIN4, LOW); 
}

void LeftEngine() {
    digitalWrite (PinIN1, LOW);   //motor izquierdo adelante
    digitalWrite (PinIN2, HIGH);  
    digitalWrite (PinIN3, LOW);   //motor derecho atras
    digitalWrite (PinIN4, HIGH);
}