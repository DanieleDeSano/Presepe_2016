

#define SPOT 2
#define G_STRIP 3
#define ROSONE 4
#define B_STRIP 5
#define R_STRIP 6
#define CAMPANILE 7
#define CASA 8
#define SCURO 9
#define SOLE 10
#define CAPANNA 11
#define NORCINO_INF 12
#define NORCINO_SUP 13

 
#define STEP 10 

void setup() {
  // put your setup code here, to run once:

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  
  analogWrite(0, 3);
  analogWrite(0, 5);
  analogWrite(0, 6);
  analogWrite(0, 9);
  analogWrite(0, 10);
  analogWrite(0, 11);
  
  digitalWrite (2, LOW);
  digitalWrite (4, LOW);
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);
  digitalWrite (12, LOW);
  digitalWrite (13, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
//  analogWrite(10, 255);

  int i ;
 
  // fase 1
  
  digitalWrite (CAPANNA, HIGH);
  analogWrite (B_STRIP, 30);
  digitalWrite (SCURO, HIGH);
  digitalWrite (SPOT, HIGH);
 
   delay (4000);

  delay (6000);

  // sec 5
  
  // fase 2
  
  digitalWrite (CAMPANILE, HIGH);
  
  delay (2000);

  digitalWrite (ROSONE, HIGH);

  delay (2000);

  digitalWrite (SPOT, LOW);

  delay (3000);

  // sec 15
  
  // fase 3
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    
      
    v = 255.0 * (i / 800.0);
    
    
    analogWrite(B_STRIP,  max(30,v) );
    analogWrite(SCURO,  255-v );
    
    delay(STEP);
  }  

  // fase 4
  
  digitalWrite (NORCINO_SUP, HIGH);
  delay(2000);
  digitalWrite (CASA, HIGH);
  delay(3000);
  
  // sec 28

  // fase 5
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    
      
    v = 255.0 * (i / 800.0);
    
    
    analogWrite(R_STRIP,  v );
    
    delay(STEP);
  }  
  
  
  // fase 6

  digitalWrite (NORCINO_SUP, LOW);
  delay (2000);
  digitalWrite (NORCINO_INF, HIGH);
  
  // fase 7
  
   for (int i = 0 ; i < 800 ; i++)
  {
    float v ;
    
      
    v = 255.0 * (i / 800.0);
    
    
    analogWrite(G_STRIP,  v );
    
    delay(STEP);
  }  
  
  // fase 8
  
  digitalWrite (CASA, LOW);
  delay(1000);
//  digitalWrite (SPOT, LOW);
  delay(4000);
  digitalWrite (CAMPANILE, LOW);
  delay(3000);
  digitalWrite (ROSONE, LOW);
  
   for (int i = 0 ; i < 600 ; i++)
  {
    float v ;
    v = 80.0 * (i / 600.0);
    
    analogWrite(SOLE,  v );
    delay(STEP);
  }  
   for (int i = 0 ; i < 300 ; i++)
  {
    float v ;
    v = 80 + 175.0 * (i / 300.0);
    
    analogWrite(SOLE,  v );
    delay(STEP);
  }  
  
  delay(8000);

  // fase 9
  
   for (int i = 0 ; i < 400 ; i++)
  {
    float v ;
    v = 175.0 * (i / 400.0);
    
    analogWrite(SOLE,  255-v );
    delay(STEP);
  }  
   for (int i = 0 ; i < 700 ; i++)
  {
    float v ;
    float z;
    
    v = 80.0 * (i / 700.0);

    z = 230.0 * (i / 700.0);
    
    analogWrite(SOLE,  255-175-v );
    analogWrite(R_STRIP,  255-z );
    analogWrite(G_STRIP,  255-z );
    delay(STEP);
  }  
  
  
  // sec 67
  
  // fase 10
  
  digitalWrite (CAMPANILE, HIGH);
  
  for (int i = 0 ; i < 800 ; i++)
  {
    float v;
    
    v = 25.0 * (i / 800.0);

    analogWrite(R_STRIP,  25-v );
    analogWrite(G_STRIP,  25-v );
    if (i == 400)
    {
       digitalWrite (ROSONE, HIGH);
      
    }
    delay(STEP);
  }  

  digitalWrite (NORCINO_INF, LOW);
  
  // sec 75

  // fase 11

  delay (2000);
  digitalWrite (NORCINO_SUP, HIGH);
  delay (5000);
  digitalWrite (CASA, HIGH);
  delay (5000);
//  digitalWrite (SPOT, HIGH);
  delay (5000);
  
  // fase 12
  
     for (int i = 0 ; i < 1800 ; i++)
  {
    float v ;
    float z;
    
    v = 225.0 * (i / 1800.0);

    z = 255.0 * (i / 1800.0);
    
    analogWrite(B_STRIP,  255-v );
    analogWrite(SCURO,  z );
    
    if (i == 700)
    {
       digitalWrite (CASA, LOW);
    }
    if (i == 1000)
    {
       digitalWrite (NORCINO_SUP, LOW);
    }
    if (i == 1300)
    {
//       digitalWrite (SPOT, LOW);
    }
    if (i == 1500)
    {
       digitalWrite (CAMPANILE, LOW);
    }

    if (i == 1780)
    {
       digitalWrite (ROSONE, LOW);
    }
    
    delay(STEP);
  }  

  
  
  // -------------
  

}
