int SER = 2;
int RCLK = 3;
int SRCLK = 4;

#define TIEMPO 0
void Verificacion();
  
void setup()
{

}
void loop()
{

}

void Verificacion(){
  short int matriz_LED[8][8]={{1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
  for(int f = 0; f < 8; f++){
    for(int c = 0; c < 8; c++){
      digitalWrite(SER, matriz_LED[f][c]);
      digitalWrite(SRCLK, 0);digitalWrite(SRCLK, 1);digitalWrite(SRCLK, 0);
      digitalWrite(RCLK, 0);digitalWrite(RCLK, 1);digitalWrite(RCLK, 0);
      delay(50);
    }
  }
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

}

void imagen ();
