int controlxiro=0;  // Se é 1 xirar á dereita, se é 0 xirar á esquerda
int sensorEsq=A1;  //Cable amarelo a A1 motor Dto
int sensorDto=A3; //Cable vermello a A3 motor Esq
int r=100; //variable para indicar o retardo na velocidade dos motores

 void setup(){ 

  //motor Esq
 pinMode(5,OUTPUT);  //cable negro
 pinMode(6,OUTPUT);  //cable branco
 
  //motor Dto
 pinMode(7,OUTPUT); //cable gris
 pinMode(8,OUTPUT); // cable lila

 //Sensores
 pinMode(sensorEsq,INPUT); //cable vermello
 pinMode(sensorDto,INPUT); //cable amarelo
 
}

void adiante(){
                   //Motor Esq
 digitalWrite(5,LOW);                  
 digitalWrite(6,HIGH); delay(r); digitalWrite(6, LOW); delay(r); 
       
                   //Motor Dto
 digitalWrite(7,HIGH); delay(r);digitalWrite(10, LOW);delay(r); 
 digitalWrite(8,LOW);
 
 } 

void xiroDta(){  
  
                  //Motor Esq
 digitalWrite(5,LOW);                
 digitalWrite(6,HIGH);delay(r);digitalWrite(6, LOW); delay(r);

                  //Motor Dto
 digitalWrite(7,LOW);
 digitalWrite(8,LOW); 
}

void xiroEsq(){
                   //Motor Equ
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 
                  //Motor Dto
 digitalWrite(7,HIGH);delay(r);digitalWrite(10, LOW);delay(r);           
 digitalWrite(8,LOW); 
 
 }
 
void loop() {

  
sensorDto=digitalRead(A1);  //motor Dto
sensorEsq=digitalRead(A3);  //motor Esq

   if(sensorEsq == 1 && sensorDto == 1){ //Os dous estan sobre liña negra
      adiante();
                                      }
      else if(sensorEsq==0 && sensorDto==1){  //O sensorEsq le zona branca e o sensorDto sobre a liña negra
         xiroDta();
         controlxiro = 1 ;
                                      }
     else if(sensorEsq==1 && sensorDto==0){  //O sensorEsq sobre liña negra e o sensorDto sobre zona branca
           xiroEsq();
           controlxiro = 0 ; 
                                        }
 
  else{
      if(controlxiro==0){
         xiroEsq();
                         }
   else if (controlxiro==1){
     xiroDta();
                              }
                                      }
           }

