int SER = 2;
int RCLK = 3;
int SRCLK = 4;

void Verificacion();
void imagen (short int [8][8]);
void Limpieza_Pantalla();
void Muestra_posiciones();
void Muestra_Patron_Dibujo(char [8][8]);
void Realizando_Dibujo(char [8][8]);
void Pubik();
  
  
int main(){
	
  init();
  Serial.begin(9600);

  
  while(1){
  	int opcion = 0;
  	short int panel_LED[8][8] = {};
  	for(int i = 0; i < 8; i++){
      		for(int j = 0; j < 8; j++){
       	    		panel_LED[i][j] = 0;
      		}
 	 }
 	Serial.println("opcion 1 -> Verificacion");
  	Serial.println("opcion 2 -> Mostrar un solo patron");
  	Serial.println("opcion 3 -> Mostrar una secuencia de patrones");
    Serial.println("opcion 4 -> Limpiar patron de la matriz LED");
  	Serial.print("Elija una opcion -> ");
  	while(Serial.available()==0);						   
  	opcion = Serial.parseInt();
  	Serial.println(opcion);
	switch (opcion) 
    {
      case 1 :{Verificacion();
               Limpieza_Pantalla();
               break;}
      case 2 :{imagen(panel_LED);
               Limpieza_Pantalla();
               break;}   
      case 3 :{Pubik();
               Limpieza_Pantalla();
               break;} 
      case 4 :{Verificacion();
               Limpieza_Pantalla();
               break;} 
      default:{Serial.println("Ingreso una opcion incorrecta, por favor vuelva a ingresar -> ");
               while(Serial.available()==0);						   
               opcion = Serial.parseInt();
               Serial.println(opcion);}
    }
  }
}

void Verificacion(){
  /**Esta funcion permite verificar la funcionalidad de todos los 
  LED's**/
  
  short int matriz_LED[8][8]={{1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
  /**La matriz anterior sirve para determinar el estado de los LED's
  siendo 1 alto y 0 bajo **/
  
  for(int f = 0; f < 8; f++){
    for(int c = 0; c < 8; c++){
      digitalWrite(SER, matriz_LED[f][c]); 
      digitalWrite(SRCLK, 0);digitalWrite(SRCLK, 1);digitalWrite(SRCLK, 0);
      digitalWrite(RCLK, 0);digitalWrite(RCLK, 1);digitalWrite(RCLK, 0);
      delay(50);
    }
  }
  /** El ciclo anterior sirve para encender o mantener apagados los LED's
  dependiendo del valor que tengan**/
 
  for(int f = 0; f < 8; f++){
    for(int c = 0; c < 8; c++){
      matriz_LED[f][c]=1;
    }
  }
  for(int f = 0; f < 8; f++){
    for(int c = 0; c < 8; c++){
      digitalWrite(SER, matriz_LED[f][c]);
      digitalWrite(SRCLK, 0);digitalWrite(SRCLK, 1);digitalWrite(SRCLK, 0);
      digitalWrite(RCLK, 0);digitalWrite(RCLK, 1);digitalWrite(RCLK, 0);
    }
  }
  delay(2000);
   /** El ciclo anterior sirve para encender todos los LED's a la vez**/
  for(int f = 0; f < 8; f++){
    for(int c = 0; c < 8; c++){
      matriz_LED[f][c]=0;
    }
  }
  for(int f = 0; f < 8; f++){
    for(int c = 0; c < 8; c++){
      digitalWrite(SER, matriz_LED[f][c]);
      digitalWrite(SRCLK, 0);digitalWrite(SRCLK, 1);digitalWrite(SRCLK, 0);
      digitalWrite(RCLK, 0);digitalWrite(RCLK, 1);digitalWrite(RCLK, 0);
    }
  }
}

void imagen (short int panel_LED[8][8]){
  /** Esta función permite que el usuario dibuje su propio patrón
  y después pueda visualizar el patron en la matriz LED**/
  
	char patrones[8][8]={{' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' '}};
    Muestra_posiciones();
    delay(2000);
    Realizando_Dibujo(patrones);
    /**La matriz patrones junto con la funcion Realizando_Dibujo muestra en el 
  monitor serial una matriz de 8x8 con los espacios en blanco y va modificando
  los espacios con una 'X' donde el usuario desee**/
  
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(patrones[i][j] == 'X'){
                panel_LED[i][j] = 1;
            }
        }
    }
  /**El ciclo anterior sirve para determinar el estado de los LED's
  dependiendo de las elecciones del usuario**/
  
  for(int f = 0; f < 8; f++){
    for(int c = 0; c < 8; c++){
      digitalWrite(SER, panel_LED[f][c]);
      digitalWrite(SRCLK, 0);digitalWrite(SRCLK, 1);digitalWrite(SRCLK, 0);
      digitalWrite(RCLK, 0);digitalWrite(RCLK, 1);digitalWrite(RCLK, 0);
    }
  }
  /**El ciclo anterior enciende los LED's dependiendo del estado en la
  matriz panel_LED**/
}

void Limpieza_Pantalla(){
  /** Esta funcion limpia la pantalla **/
    for(int i = 0; i < 20; i++)
       Serial.println();
}

void Muestra_posiciones(){
  /**Esta funcion le muestra al usuario una matriz 8x8 donde cada posición
  va a tener un valor que representa un led**/
  
    int patrones[8][8]={{1,2,3,4,5,6,7,8},{9,10,11,12,13,14,15,16},{17,18,19,20,21,22,23,24},{25,26,27,28,29,30,31,32},{33,34,35,36,37,38,39,40},{41,42,23,44,45,46,47,48},{49,50,51,52,53,54,55,56},{57,58,59,60,61,62,63,64}};
    /**La matriz anterior representa los valores que se le asignaran a cada LED**/
  	int cont = 0;
   /**El siguiente ciclo imprime en el monitor serial una matriz 8x8 donde cada
   espacio va a tener un valor asignado**/
    for(int fila = 0; fila < 8; fila++){
        Serial.println("+---+---+---+---+---+---+---+---+");
        for(int colum = 0; colum < 8; colum++){
            cont++;
            if((cont/10) == 0 && colum == 0){
                if(cont != 9){
                Serial.print("| ");
                Serial.print(patrones[fila][colum]);
                Serial.print(" | ");
                }
             else{
                Serial.print("| ");
                Serial.print(patrones[fila][colum]);
                Serial.print(" |");
                }
            }
            else if((cont/10) == 0 && colum != 7){
                Serial.print(patrones[fila][colum]);
              	Serial.print(" | ");
            }
            else if((cont/10) == 0 && colum == 7){
                Serial.print(patrones[fila][colum]);
                Serial.print(" |");
            }
            if((cont/10) != 0 && colum == 0){
                Serial.print("|");
                Serial.print(patrones[fila][colum]);
                Serial.print(" |");
            }
            else if((cont/10) != 0){
               Serial.print(patrones[fila][colum]);
               Serial.print(" |");
            }
        }
       Serial.println();
    }
    Serial.println("+---+---+---+---+---+---+---+---+");
}

void Muestra_Patron_Dibujo(char dibujo[8][8]){
 /**Esta funcion le muestra al usuario una matriz 8x8 donde cada posición
  va a estar vacia o con una 'X' dependiendo del estado de la matriz dibujo **/
  
    for(int fila = 0; fila < 8; fila++){
        Serial.println("+---+---+---+---+---+---+---+---+");
        for(int colum = 0; colum < 8; colum++){
            if(colum == 0){
            Serial.print("| ");
            Serial.print(dibujo[fila][colum]);
            }
            else{
               Serial.print(" | ");
               Serial.print(dibujo[fila][colum]);
            }
        }
        Serial.println(" |");
    }
    Serial.println("+---+---+---+---+---+---+---+---+");
}

void Realizando_Dibujo(char patrones [8][8]){
  /**Esta funcion le muestra al usuario una matriz 8x8 donde cada posición
  va a estar vacia y puede ser utilizada para dibujar el patron
  que se desee**/
  
    int posicion = 0;
    Muestra_Patron_Dibujo(patrones);
    Serial.print("Ingrese la posicion que desea encender -> ");
  	while(Serial.available()==0);						   
  	posicion = Serial.parseInt();
  	Serial.println(posicion);
  /**En la parte anterior se le pide al usuario que ingrese la posicion que 
  desee de la matriz 8x8, teniendo en cuenta que la posicion que elija significa
  que ese LED va a ser encendido y ademas tener en cuentael cuadro mostrado por 
  la funcion Muestra_Patron_Dibujo**/
    
    while(posicion <= 64){
        if(posicion < 9){
            if(patrones[0][posicion-1] == ' '){
                patrones[0][posicion-1] = 'X';
            }
            else{
                patrones[0][posicion-1] = ' ';
            }
        }
        else if(posicion >= 9 && posicion < 17){
            if(patrones[1][posicion-9] == ' '){
                patrones[1][posicion-9] = 'X';
            }
            else{
                patrones[1][posicion-9] = ' ';
            }
        }
        else if(posicion >= 17 && posicion < 25){
            if(patrones[2][posicion-17] == ' '){
                patrones[2][posicion-17] = 'X';
            }
            else{
                patrones[2][posicion-17] = ' ';
            }
        }
        else if(posicion >= 25 && posicion < 33){
            if(patrones[3][posicion-25] == ' '){
                patrones[3][posicion-25] = 'X';
            }
            else{
                patrones[3][posicion-25] = ' ';
            }
        }
        else if(posicion >= 33 && posicion < 41){
            if(patrones[4][posicion-33] == ' '){
                patrones[4][posicion-33] = 'X';
            }
            else{
                patrones[4][posicion-33] = ' ';
            }
        }
        else if(posicion >= 41 && posicion < 49){
            if(patrones[5][posicion-41] == ' '){
                patrones[5][posicion-41] = 'X';
            }
            else{
                patrones[5][posicion-41] = ' ';
            }
        }
        else if(posicion >= 49 && posicion < 57){
            if(patrones[6][posicion-49] == ' '){
                patrones[6][posicion-49] = 'X';
            }
            else{
                patrones[6][posicion-49] = ' ';
            }
        }

        else{
            if(patrones[7][posicion-57] == ' '){
                patrones[7][posicion-57] = 'X';
            }
            else{
                patrones[7][posicion-57] = ' ';
            }
        }
      /** El ciclo anterior va modificando la matriz que muestra el patron
      dibujado**/
       Limpieza_Pantalla();
       Muestra_Patron_Dibujo(patrones);
       Serial.print("Ingrese la posicion que desea encender -> ");
       while(Serial.available()==0);						   
       posicion = Serial.parseInt();
       Serial.println(posicion);
    }
}

void Pubik()
{ 
    int n = 0, cont = 0, cont2 = -1, seg = 0, cantidad_c = 0;
  
    Serial.print("Ingrese la cantidad de patrones que desea mostrar -> ");
    while(Serial.available()==0);						   
    n = Serial.parseInt();
    Serial.println(n);
  
  	Serial.print("Ingrese el tiempo que desea ver un patron en segundos -> ");
    while(Serial.available()==0);						   
    seg = Serial.parseInt();
    Serial.println(seg);
  
  	Serial.print("Ingrese la cantidad de veces que desea ver el ciclo -> ");
    while(Serial.available()==0);						   
    cantidad_c= Serial.parseInt();
    Serial.println(cantidad_c);
   /**Hata este punto la funcion lo que hace es pedirle al usuario el numero
   de patrones que desea ingresar y la cantidad de tiempo que desea entre
   los patrones**/
  
    int *Pointer_Secue = new int [n*64];
    /**Se reserva espacio en el Heap dependiendo de la cantidad de
    patrones que desee el usuario**/
    char patrones[8][8]={};
    Muestra_posiciones();
    delay(2000);
    for(int cont = 0; cont < n; cont++){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
               patrones[i][j] = ' ';
            }
        }

        Realizando_Dibujo(patrones);

         for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cont2++;
                if(patrones[i][j] == 'X'){
                    *(Pointer_Secue + cont2) = 1;
                }
                else{
                   *(Pointer_Secue + cont2) = 0;
                }
            }
        }

        Serial.println( "Patron finalizado");
    }
  /**En el ciclo anterior se van creando los patrones que desea mostrar el usuario
  con ayuda de la funcion Realizando_Dibujo y ademas se van agregando los patrones en orden al espacio de memoria en el Heap(se agregan los patrone como 1 y 0
siendo 1 un High y 0 un Low )**/
  while(cont < cantidad_c){
    cont++;
    int div = 0;
      for(int i = 0; i < (n*64); i++){
        div++;
        digitalWrite(SER, *(Pointer_Secue + i));
        digitalWrite(SRCLK, 0);digitalWrite(SRCLK, 1);digitalWrite(SRCLK, 0);
        digitalWrite(RCLK, 0);digitalWrite(RCLK, 1);digitalWrite(RCLK, 0);
        if(div == 64){
          div = 0;
          delay(seg*1000);
        }
      }
    }
      /**El ciclo anterior encienden los patrones que puso el usuario y que hasta el momento estan almacenados en el Heap**/
    free (Pointer_Secue);
}