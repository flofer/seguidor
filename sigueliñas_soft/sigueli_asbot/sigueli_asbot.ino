
 //********sigueliñasbot************

                   //declaración de variables

int controlxiro=0;
int sensorEsq=A1;
int sensorDto=A3;

                  //modo consola
void setup(){ 
 Serial.begin(9600);
 
                    //motor dereito A
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 
                    //conexión para motor esquerdo B
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 
                 // declarar os Sensores dos TCRT5000 como entradas
 pinMode(sensorEsq,INPUT); //cable vermello a A1
 pinMode(sensorDto,INPUT); //cable amarelo a A3
 
                //función para deter os dous motores 
}
void parar(){
 digitalWrite(10,LOW);
 digitalWrite(11,LOW);
 digitalWrite(6,LOW);
 digitalWrite(5,LOW);
                   //función para que os motores xiren os dous no sentido horario
  } 
void adiante(){
 digitalWrite(10,HIGH);
 digitalWrite(11,LOW);
 digitalWrite(6,LOW);
 digitalWrite(5,HIGH);
 
                 //función para que xire só o motor esquerdo e o robot se desprace cara a dereita
}  
void xiroDta(){
 digitalWrite(10,LOW);
 digitalWrite(11,LOW);
 digitalWrite(6,LOW);
 digitalWrite(5,HIGH);
}

                 //función para que xire no sentido do reloxo o motor dereito
void xiroEsq(){ 
 digitalWrite(10,HIGH);
 digitalWrite(11,LOW);
 digitalWrite(6,LOW);
 digitalWrite(5,LOW);
 }
                //lectura dos valores dos dous sensores...
void loop() {   
 sensorEsq=analogRead (A1);
 sensorDto=analogRead (A3);
     //Para ver os valores en consola
 Serial.println(   );
 Serial.println("Valor motor ESQ.....");
 Serial.println(analogRead(sensorEsq));
 delay(500);
 Serial.println(   );
 Serial.println("Valor motor DER.....");
 Serial.println(analogRead(A3));

                  //os valores dos sensores son superiores a 600 o robot adiante
if(sensorEsq > 600 && sensorDto > 600){
 adiante();
 }
                 //o valor do sensor esquerdo é inferior de 600
 else if(sensorEsq < 600 && sensorDto > 600){
   xiroDta();
   controlxiro = 1 ;
   }
                 //o valor do sensor dereito é inferior a 600
  else if( sensorEsq > 600 && sensorDto < 600){
   xiroEsq();
   controlxiro = 0 ;
                 //os dous valores son inferiores a 600
  }
  else if( sensorEsq < 600 && sensorDto < 600){
   parar();
   controlxiro = 0 ;
  }
               //o robot xirará á dereita ou á esquerda dependendo do valor que tome a variable controlxiro
else{
 if(controlxiro == 0){
   xiroDta();
   }
   else{
     xiroEsq();
     }
 }
}

