static int PinMotorIzq = 10; // Cambiado a un pin analógico (asegúrate de que sea PWM)
static int PinMotorDer = 11; // Cambiado a un pin analógico (asegúrate de que sea PWM)
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

    if (sensorIzq == HIGH && sensorDer == LOW && sensorMed == HIGH) {
        EngineForward();
    }
    if (sensorIzq == LOW && sensorDer == HIGH && sensorMed == LOW) {
        RightEngine();
    }
    if (sensorDer == LOW && sensorIzq == HIGH && sensorMed == LOW) {
        LeftEngine();
    }

    delay(20);
}

void EngineForward() {
    analogWrite(PinMotorIzq, 200); // Ajusta el valor para controlar la velocidad
    analogWrite(PinMotorDer, 200); // Ajusta el valor para controlar la velocidad
}

void EngineStop() {
    analogWrite(PinMotorIzq, 0);
    analogWrite(PinMotorDer, 0);
}

void RightEngine() {
    analogWrite(PinMotorIzq, 0);
    analogWrite(PinMotorDer, 200); // Ajusta el valor para controlar la velocidad
}

void LeftEngine() {
    analogWrite(PinMotorIzq, 200); // Ajusta el valor para controlar la velocidad
    analogWrite(PinMotorDer, 0);
}
