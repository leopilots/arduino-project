// variables
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

    //definimos el modo de operación del pin (INPUT/OUPUT)
    pinMode(PinIN1, OUTPUT);
    pinMode(PinIN2, OUTPUT);
    pinMode(PinIN3, OUTPUT);
    pinMode(PinIN4, OUTPUT);
    pinMode(PinSensorIzq, INPUT); //sensor izquierdo
    pinMode(PinSensorDer, INPUT); //sensor derecho
    pinMode(PinSensorMed, INPUT); //sensor del medio
}

void loop() {
    // variables de los sensores
    int sensorIzq = 0;
    int sensorDer = 0;
    int sensorMed = 0;

    sensorIzq = digitalRead(PinSensorIzq); 
    sensorDer = digitalRead(PinSensorDer);
    sensorMed = digitalRead(PinSensorMed);

    // ruedas avanzan hacia adelante (arrancar)
    if(sensorIzq == LOW && sensorDer == LOW && sensorMed == HIGH) {                                 //los sensores laterales no detectan una zona oscura y el del medio si, va para adelante
        EngineForward();                                                                            //llamamos la función (avanza para adelante)
    }
    // ruedas se detienen, los sensores no detectan zonas oscuras
    if(sensorIzq == LOW && sensorDer == LOW && sensorMed == LOW) {
        EngineStop();                                                                               //llamamos la función (detenemos los motores)
    }
    // el sensor izquierdo detecta una zona oscura, se detiene el mismo y arranca el derecho
    if(sensorIzq == HIGH && sensorDer == LOW && sensorMed == LOW) {                                 //el sensor izquierdo detecta una zona oscura y los demás no  
        RightEngine();                                                                              //llamamos la función (arranca motor derecho)
    }
    // el sensor derecho detecta una zona oscura, se detiene el mismo y arranca el izquierdo
    if(sensorDer == HIGH && sensorIzq == LOW && sensorMed == LOW) {                                 //el sensor derecho detecta una zona oscura y los demás no
        LeftEngine();                                                                               //llamamos la función (arranca motor izquierdo)
    }

    delay(20); //tiempo en el que leemos los sensores
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