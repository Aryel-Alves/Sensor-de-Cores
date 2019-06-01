//Pinos de conexao do sensor TCS3200
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
 
//Pinos do led RGB
const int pinoledverm = 2;
const int pinoledverd = 3;
const int pinoledazul = 4;
 
//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;

// Constantes morse
const int DIT = 300; // ponto em morse (tempo aceso)
const int DAH = 1000; // traço em morse (tempo aceso)
const int LETRA = 300; // Delay entre as letras
 
void setup()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(pinoledverm, OUTPUT);
  pinMode(pinoledverd, OUTPUT);
  pinMode(pinoledazul, OUTPUT);
  Serial.begin(9600);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}

/********************************************************* LOOP *********************************************************************************************/ 
void loop()
{
  //Detecta a cor
  color();
  //Mostra valores no serial monitor
  Serial.print("Vermelho :");
  Serial.print(red, DEC);
  Serial.print(" Verde : ");
  Serial.print(green, DEC);
  Serial.print(" Azul : ");
  Serial.print(blue, DEC);
  Serial.println();
 
  //Verifica se a cor vermelha foi detectada
  if (red < blue && red < green && red < 100)
  {
    Serial.println("Vermelho detectado");
    vermelho_morse();
  }
 
  //Verifica se a cor azul foi detectada
  else if (blue < red && blue < green && blue < 1000)
  {
    Serial.println("Azul detectado");
    azul_morse();
  }
 
  //Verifica se a cor verde foi detectada
  else if (green < red && green < blue)
  {
    Serial.println("Verde detectado");
    verde_morse();
  }
  Serial.println();
 
  //Delay para apagar os leds e reiniciar o processo
  delay(50);
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH);
}
/********************************************************* FIM DO LOOP *********************************************************************************************/ 


void liga_Dit_Azul(){ // acende ponto em azul
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, LOW); //Acende o led azul   
  delay(DIT);               
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH);   
  delay(200);               
}

void liga_Dah_Azul(){ // acende traço em azul
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, LOW); //Acende o led azul   
  delay(DAH);              
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH);   
  delay(200);               
}
void liga_Dit_Vermelho(){ // acende ponto em vermelho
  digitalWrite(pinoledverm, LOW); //Acende o led vermelho
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH); 
  delay(DIT);               
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH);   
  delay(200);               
}
void liga_Dah_Vermelho(){ // acende traço em vermelho
  digitalWrite(pinoledverm, LOW); //Acende o led vermelho
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH); 
  delay(DAH);               
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH);   
  delay(200);               
}
void liga_Dit_Verde(){ // acende ponto em verde
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, LOW); //Acende o led verde
  digitalWrite(pinoledazul, HIGH);
  delay(DIT);              
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH);   
  delay(200);               
}
void liga_Dah_Verde(){ // acende traço em verde
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, LOW); //Acende o led verde
  digitalWrite(pinoledazul, HIGH);
  delay(DAH);               
  digitalWrite(pinoledverm, HIGH);
  digitalWrite(pinoledverd, HIGH);
  digitalWrite(pinoledazul, HIGH);   
  delay(200);               
} 

void azul_morse(){
  // AZUL = .- --.. ..- .-..
  
  // letra A
  liga_Dit_Azul();
  liga_Dah_Azul();  
  delay(LETRA); // espera de 300 ms entre as letras

  // letra Z
  liga_Dah_Azul();
  liga_Dah_Azul();
  liga_Dit_Azul();
  liga_Dit_Azul();
  delay(LETRA); //espera 300 ms entre as letras

  // letra U
  liga_Dit_Azul();
  liga_Dit_Azul();
  liga_Dah_Azul();
  delay(LETRA); //espera 300 ms entre as letras

  // letra L
  liga_Dit_Azul();
  liga_Dah_Azul();
  liga_Dit_Azul();
  liga_Dit_Azul();
  delay(LETRA); // espera de 300 ms entre as letras
  
  //espera 3 segundos para repetir palavra
  delay(3000);
}
void vermelho_morse(){
  // VERMELHO = ...- . .-. -- . .-.. .... ---
  
  // letra V
  liga_Dit_Vermelho();
  liga_Dit_Vermelho();
  liga_Dit_Vermelho();
  liga_Dah_Vermelho(); 
  delay(LETRA); // espera de 300 ms entre as letras
   
  // letra E
  liga_Dit_Vermelho();
  delay(LETRA);
   
  // letra R
  liga_Dit_Vermelho();
  liga_Dah_Vermelho();
  liga_Dit_Vermelho();
  delay(LETRA); 
  
  // letra M
  liga_Dah_Vermelho();
  liga_Dah_Vermelho();
  delay(LETRA);
  
  // letra E
  liga_Dit_Vermelho();
  delay(LETRA);
  
  // letra L
  liga_Dit_Vermelho();
  liga_Dah_Vermelho();
  liga_Dit_Vermelho();
  liga_Dit_Vermelho();
  delay(LETRA);
  
  // letra H
  for (int x=0; x<4; x++) {
  	liga_Dit_Vermelho();
  }
  delay(LETRA);
  
  // letra O
  for (int x=0; x<3; x++) {
  	liga_Dah_Vermelho();
  }
  delay(LETRA);
    
  delay(3000); //espera 3 segundos para repetir palavra
}

void verde_morse(){
  //verde = ...- . .-. -.. .
  
  // letra V
  liga_Dit_Verde();
  liga_Dit_Verde();
  liga_Dit_Verde();
  liga_Dah_Verde();
  delay(LETRA); // espera de 300 ms entre as letras
  
  // letra E
  liga_Dit_Verde();
  delay(LETRA);
  
  // letra R
  liga_Dit_Verde();
  liga_Dah_Verde();
  liga_Dit_Verde();
  delay(LETRA); 
  
  // letra D
  liga_Dah_Verde();
  liga_Dit_Verde();
  liga_Dit_Verde();
  delay(LETRA); 
  
  // letra E
  liga_Dit_Verde();
  delay(LETRA);
  
  delay(3000); //espera 3 segundos para repetir palavra
}

void color()
{
  //Rotina que le o valor das cores
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
