//LO PRIMERO ES DECLARAR LAS VARIABLES
boolean a,b; //a Y b SON LAS VARIABLES QUE SE ENCARGARAN DE DEFINIR EL SENTIDO DE GIRO DE LOS MOTORES. POR ELLO ES BOOLEAN YA QUE SOLO PODRAN SER 0 O 1
char dato;//ESTA VARIABLE RECOGERA LAS LETRAS QUE LE MANDA LA APLICACIO,POR ESO ES CHAR YA QUE TODO SON LETRAS.
//d Y i SON LAS VARIABLES QUE VAMOS A USAR PARA OTORGAR LA VELOCIDAD DE NUESTRO ROBOT DEPENDIENDO DE LA TENSION QUE MANDEMOS A LOS MOTORES
int d;
int i;
void setup() {
Serial.begin(9600);
//ENTRADAS
pinMode(2,INPUT);
//SALIDAS 
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0){
    dato = Serial.read();//HACEMOS QUE LA LETRA QUE LE LLEGUE AL BT SE LE ASIGNE A LA VARIABLE dato
    Serial.println(dato);
    //CON EL SWITCH LO QUE VAMOS A HACER ES COMPARAR MEDIANTE LOS CASE LOS VALORES QUE TIENE DATO, CUANDO COINCIDAN SE EJECUTARA LA SENTENCIA QUE ESTA DENTRO DE DICHO CASE.
      switch (dato) {
         case ('X'):{ //PULSANDO EL BOTON TRIANGULO AUMENTAMOS LA VELOCIDAD AL MAXIMO
          i=255;
          d=255;
          break;//SE USA PARA SALIR DEL CASE UNA VEZ QUE SE HA EJECUTADO LA SENTENCIA COMPLETA Y QUE NO COINCIDE LA LETRA QUE TIENE DATO CON LA DE ESE CASE
        }
         case ('x'):{  //NO PULSANDO EL BOTON TRIANGULO PONEMOS LA VELOCIDAD A LA MITAD
          i=128;
          d=128;
          break;
        }        
        case ('F'):{  //PARA ALANTE
          Movimiento (1,0,i,d);
          break;
        }
        case ('B'):{  //PARA ATRAS
          Movimiento (0,1,i,d);
          break;
        }
        case ('L'):{  //DERECHA
          Movimiento (1,0,255,0);
          break;
        }
        case ('R'):{  //IZQUIERDA
          Movimiento (1,0,0,255);
          break;
        }
        case ('G'):{  //ALANTE DERECHA
          Movimiento (1,0,0,255);
          break;
        }
        case ('I'):{  //ALANTE IZQUIERDA
          Movimiento (1,0,0,255);
          break;
        }
        case ('W'):{ //GIRAR SOBRE SI MISMO
          //MOTOR-DER
          analogWrite(10,i);
          digitalWrite(7,0);
          digitalWrite(6,1);
          //MOTOR-IZQ
          analogWrite(11,d);
          digitalWrite(8,1);
          digitalWrite(9,0);        
        }
        case ('S'):{  //STOP
          Movimiento (1,0,0,0);
          break;
        }
        case ('V'):{  //PITIDO
          digitalWrite(13,1);
          delay(200);
          digitalWrite(13,0);
          break;
        }        
      }
}
}
//AQUI TENEMOS LA FUNCION DE USUARIO QUE HEMOS USADO. LA HEMOS ASIGNADO DIFERENTES VARIABLES PARA QUE CUANDO LA LLAMEMOS PONGAMOS LOS PARAMETROS QUE NOSOTROS DESEEMOS
void Movimiento (int a, int b, int i, int d){//255 y 245
  //MOTOR-DER
  analogWrite(10,i);
  digitalWrite(7,a);
  digitalWrite(6,b);
  //MOTOR-IZQ
  analogWrite(11,d);
  digitalWrite(8,a);
  digitalWrite(9,b);
}

