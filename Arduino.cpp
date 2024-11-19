// Pines del HC-SR04
const int trigPin = 9;
const int echoPin = 8;

// Pines de alerta
const int buzzerPin = 3;
const int motorPin = 5;

// Distancia límite en cm para activar alertas
const int distanciaLimite = 50;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  
  Serial.begin(9600); // Para monitorear en la consola
}

void loop() {
  long duracion;
  int distancia;

  // Enviar pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer la duración del eco
  duracion = pulseIn(echoPin, HIGH);

  // Calcular distancia en cm
  distancia = duracion * 0.034 / 2;

  // Mostrar la distancia en la consola (opcional)
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Activar alertas si la distancia es menor al límite
  if (distancia > 0 && distancia < distanciaLimite) {
    digitalWrite(buzzerPin, HIGH);  // Activar buzzer
    digitalWrite(motorPin, HIGH);  // Activar motor vibrador
  } else {
    digitalWrite(buzzerPin, LOW);  // Apagar buzzer
    digitalWrite(motorPin, LOW);  // Apagar motor vibrador
  }

  delay(100); // Pequeña pausa para estabilidad
}
