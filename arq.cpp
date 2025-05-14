// semaforo de tres vias + pedestre

//botão pedestre
int botao= 6;

//primeira via
int ledv1_verm= 4;
int ledv1_lrj= 3;
int ledv1_verd= 2;

//segunda via
int ledv2_verm= 9;
int ledv2_lrj= 10;
int ledv2_verd= 11;

//via pedestre
int ledv3_verm= 12;
int ledv3_verd= 13;


void setup() {

//leds de todas vias
 pinMode(ledv1_verm, OUTPUT);
 pinMode(ledv1_lrj, OUTPUT);
 pinMode(ledv1_verd, OUTPUT);
 pinMode(ledv2_verm, OUTPUT);
 pinMode(ledv2_lrj, OUTPUT);
 pinMode(ledv2_verd, OUTPUT);
 pinMode(ledv3_verm, OUTPUT);
 pinMode(ledv3_verd, OUTPUT);

 // botão ligado
  pinMode(botao, INPUT); 

}

void loop() {
// início

  //primeira via
  digitalWrite(ledv1_verd, HIGH);
  digitalWrite(ledv1_lrj, LOW);
  digitalWrite(ledv1_verm, LOW);

  //segunda via
  digitalWrite(ledv2_verd, LOW);
  digitalWrite(ledv2_lrj, LOW);
  digitalWrite(ledv2_verm, HIGH);

  //terceira via
  digitalWrite(ledv3_verd, LOW);
  digitalWrite(ledv3_verm, HIGH);
  delay(2000);

 
  //via 1, amarelo
  digitalWrite(ledv1_verd, LOW);
  digitalWrite(ledv1_lrj, HIGH);
  delay(2000);

  //via 1, vermelho
  digitalWrite(ledv1_lrj, LOW);
  digitalWrite(ledv1_verm, HIGH);
  delay(2000);
  
  //via 2, verde
  digitalWrite(ledv2_verm, LOW);
  digitalWrite(ledv2_verd, HIGH);
  delay(2000);

  //via 2, amarelo
  digitalWrite(ledv2_verd, LOW);
  digitalWrite(ledv2_lrj, HIGH);
  delay(2000);
  digitalWrite(ledv2_lrj, LOW);
  digitalWrite(ledv2_verm, HIGH);
  delay(2000);
  
  //se o pedestre acionou o botão
  if(digitalRead(botao)==HIGH) {
    delay(1000);

    //pedestre liberado
    digitalWrite(ledv3_verm, LOW);
    digitalWrite(ledv3_verd, HIGH);
    delay(3000); //tempo 

    //pedestre fechado
    digitalWrite(ledv3_verd, LOW);
   digitalWrite(ledv3_verm, HIGH);
 
  }

}



//  chase effect 

//constantes
const int numLeds = 12;
const int leds[numLeds] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // pinos dos LEDs
const int ledsAcesos= 3;
const int pinoPot = A0; 

//início & laços de repetição
void setup() {
  Serial.begin(9600);
 for (int i = 0; i < numLeds; i++) {
  //pinos = saída
  pinMode(leds [i], OUTPUT);
 } 
}

void loop() {
  //potenciometro
  int potValue= analogRead(pinoPot);

  //mostrar o valor do potenciometro
  Serial.print("Valor do potenciometro: ");
  Serial.println(potValue);

  //tempo
  int delayTime= map(potValue, 0, 1023, 100, 1000);

  //acende os leds
  for (int i= 0; i <= numLeds - ledsAcesos; i++) {
    for (int j=0; j < ledsAcesos; j++){
      digitalWrite(leds[i + j], HIGH);
    }
    delay(500);

  //apaga os leds
    for (int j = 0; j< ledsAcesos; j++){
      digitalWrite(leds[i + j], LOW);
    }
  }
}



// chase effect com largura variavel

const int qtdLEDs = 12;
const int ledPins[qtdLEDs] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int trigPin = 12;
const int echoPin = 13;


long duration;
int distance;
int largura = 3; 
int posicao = 0; 
bool indo = true; 

void setup() {
  for (int i = 0; i < qtdLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  largura = map(distance, 2, 20, 1, qtdLEDs);
  largura = constrain(largura, 1, qtdLEDs); 

  for (int i = 0; i < qtdLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  for (int i = 0; i < largura; i++) {
    int ledIndex = posicao + i;
    if (ledIndex >= 0 && ledIndex < qtdLEDs) {
      digitalWrite(ledPins[ledIndex], HIGH);
    }
  }

  if (indo) {
    posicao++;
    if (posicao + largura > qtdLEDs) {
      indo = false;
      posicao = qtdLEDs - largura - 1;
    }
  } else {
    posicao--;
    if (posicao < 0) {
      indo = true;
      posicao = 0;
    }
  }
}


