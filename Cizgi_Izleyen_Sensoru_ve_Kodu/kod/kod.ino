const int sag_i=6;
const int sag_g=7;
const int sol_i=5;
const int sol_g=4;

const int sol_sensor=2;
const int sag_sensor=3;

int sol_durum,sag_durum;

void setup() {

  pinMode(sag_i,OUTPUT);
  pinMode(sag_g,OUTPUT);
  pinMode(sol_i,OUTPUT);
  pinMode(sol_g,OUTPUT);

  pinMode(sag_sensor,INPUT);
  pinMode(sol_sensor,INPUT);

  Serial.begin(9600);
}

void loop() {
  sol_durum=digitalRead(sol_sensor);
  sag_durum=digitalRead(sag_sensor);
  
  Serial.print("sag sensor=");
  Serial.println(sag_durum);
  Serial.print("sol sensor=");
  Serial.println(sol_durum);
  Serial.println("_________________________");
  

  if(sol_durum==LOW && sag_durum==LOW)//ileri
  {
    digitalWrite(sag_i,HIGH);
    digitalWrite(sag_g,LOW);
    digitalWrite(sol_i,HIGH);
    digitalWrite(sol_g,LOW);
  }
  else if(sol_durum==LOW && sag_durum==HIGH)//sağa dön
  {
    digitalWrite(sag_i,HIGH);
    digitalWrite(sag_g,HIGH);
    digitalWrite(sol_i,HIGH);
    digitalWrite(sol_g,LOW);
  }
  else if(sol_durum==HIGH && sag_durum==LOW)//sola dön
  {
    digitalWrite(sag_i,HIGH);
    digitalWrite(sag_g,LOW);
    digitalWrite(sol_i,HIGH);
    digitalWrite(sol_g,HIGH);
  }
  else //dur
  {
    digitalWrite(sag_i,LOW);
    digitalWrite(sag_g,LOW);
    digitalWrite(sol_i,LOW);
    digitalWrite(sol_g,LOW);
  }
    delay(15);

  
  digitalWrite(sol_i,LOW);
  digitalWrite(sol_g,LOW);

  

  digitalWrite(sag_i,LOW);
  digitalWrite(sag_g,LOW);

  delay(75);


  
}
