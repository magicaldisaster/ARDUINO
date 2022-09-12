int echo = 11;
int trig = 10;
int tantos = 0;
int buzzer = 12;

void setup(){
  for(int i=2; i<9; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
}
void loop(){
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  int duracion = pulseIn(echo, HIGH);
  int distancia = duracion/58.2;
  if(distancia<=4 && distancia >=0){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    tantos++;
  }
  if(tantos>9){
    tantos=0;
  }
  Serial.println("Puntos:");
  Serial.print(tantos);
  switch(tantos){
    case 0:
    numero(1,1,1,1,1,1,0);
    break;
    case 1:
    numero(0,1,1,0,0,0,0);
    break;
    case 2:
    numero(1,1,0,1,1,0,1);
    break;
    case 3:
    numero(1,1,1,1,0,0,1);
    break;
    case 4:
    numero(0,1,1,0,0,1,1);
    break;
    case 5:
    numero(1,0,1,1,0,1,1);
    break;
    case 6:
    numero(1,0,1,1,1,1,1);
    break;
    case 7:
    numero(1,1,1,0,0,0,0);
    break;
    case 8:
    numero(1,1,1,1,1,1,1);
    break;
    case 9:
    numero(1,1,1,0,0,1,1);
    break;
  } 
}
void numero(int a, int b, int c, int d, int e, int f, int g){
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  digitalWrite(6, e);
  digitalWrite(7, f);
  digitalWrite(8, g);
  delay(500);
}
