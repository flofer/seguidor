int controlxiro=0;  // Se é 1 xirar á dereita, se é 0 xirar á esquerda
int sensorEsq=A1;  //Cable amarelo a A1 motor Dto
int sensorDto=A3; //Cable vermello a A3 motor Esq
int r=100; //variable para indicar o retardo na velocidade dos motores

 void setup(){ 

  //motor Esq
 pinMode(5,OUTPUT);  //cable negro
 pinMode(6,OUTPUT);  //cable branco
 
  //motor Dto
 pinMode(10,OUTPUT); //cable gris
 pinMode(11,OUTPUT); // cable lila

 //Sensores
 pinMode(sensorEsq,INPUT); //cable vermello
 pinMode(sensorDto,INPUT); //cable amarelo
 
}

void adiante(){
                   //Motor Esq
 digitalWrite(5,LOW);                  
 digitalWrite(6,HIGH); delay(r); digitalWrite(6, LOW); delay(r); 
       
                   //Motor Dto
 digitalWrite(10,HIGH); delay(r);digitalWrite(10, LOW);delay(r); 
 digitalWrite(11,LOW);
 
 } 

void xiroDta(){  
  
                  //Motor Esq
 digitalWrite(5,LOW);                
 digitalWrite(6,HIGH);delay(r);digitalWrite(6, LOW); delay(r);

                  //Motor Dto
 digitalWrite(10,LOW);
 digitalWrite(11,LOW); 
}

void xiroEsq(){
                   //Motor Equ
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 
                  //Motor Dto
 digitalWrite(10,HIGH);delay(r);digitalWrite(10, LOW);delay(r);           
 digitalWrite(11,LOW); 
 }
void loop() {
sensorDto=analogRead(A1);  //motor Dto
sensorEsq=analogRead(A3);  //motor Esq
// Para ver resultados en consola

     /*    Serial.begin(9600);
 
                      Serial.println(   );
                      Serial.print("Motor Esq..... = ");
                      Serial.println(sensorEsq);
                      Serial.print("PWM de pin 6........................... = ");
                      Serial.println(digitalRead(6));
                      Serial.print("PWM de pin 5........................... = ");
                      Serial.println(digitalRead(5));
                      Serial.print("PWM de pin 10.......................... = ");
                      Serial.println(digitalRead(10));
                      Serial.print("PWM de pin 11.......................... = ");
                      Serial.println(digitalRead(11));
                      Serial.println(   );
                                delay(2000);
                      Serial.print(" Motor Der.... = ");
                      Serial.println(sensorDto); 
                      Serial.print("PWM de pin 6........................... = ");
                      Serial.println(digitalRead(6));
                      Serial.print("PWM de pin 5........................... = ");
                      Serial.println(digitalRead(5));
                      Serial.print("PWM de pin 10.......................... = ");
                      Serial.println(digitalRead(10));
                      Serial.print("PWM de pin 11.......................... = ");
                      Serial.println(digitalRead(11));
                  */  
                    
if(sensorEsq > 600 && sensorDto > 600){  //Os dous estan sobre liña negra
 adiante();
 }
 else if(sensorEsq < 600 && sensorDto > 600){  //O sensorEsq le zona branca e o sensorDto sobre a liña negra
   xiroDta();
   controlxiro = 1 ;
   }
  else if( sensorEsq > 600 && sensorDto < 600){  //O sensorEsq sobre liña negra e o sensorDto sobre zona branca
   xiroEsq();
   controlxiro = 0 ; 
     }
  /*         
   *  else if( sensorEsq > 600 && sensorDto > 600){ //os dous sobre zona branca
   // parar();
   //controlxiro = 0 ;
   // }
   */
else{
 if(controlxiro = 0){
   xiroEsq();
   }
   else{
     xiroDta();
     }
 }
}

