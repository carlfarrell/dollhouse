
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D13 13
#define D10 10
#define D11 11
#define D12 12

#define D2 2
#define D3 3

int hrct = 1;

boolean atwork7 = false;
int workshift7 = 0;

boolean atwork8 = false;
int workshift8 = 0;

boolean atwork13 = false;
int workshift13 = 0;

boolean atwork10 = false;
int workshift10 = 0;

boolean atwork11 = false;
int workshift11 = 0;

boolean atwork12 = false;
int workshift12 = 0;


void setup () {

  pinMode(D4, OUTPUT); 
  pinMode(D5, OUTPUT); 
  pinMode(D6, OUTPUT); 
  pinMode(D7, OUTPUT); 
  pinMode(D8, OUTPUT);
  pinMode(D13, OUTPUT); 
  pinMode(D10, OUTPUT); 
  pinMode(D11, OUTPUT); 
  pinMode(D12, OUTPUT); 
  
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
}

void loop() {


  //----------------------------------------- top floor
  if (random(1) < 0.3) if ( hrct > random(6, 13) && hrct < random(21, 24))   digitalWrite(D4, HIGH);
  else digitalWrite(D4, LOW);

  if (random(1) < 0.3) if ( hrct > random(6, 13) && hrct < random(21, 24))   digitalWrite(D5, HIGH);
  else digitalWrite(D5, LOW);

  if (random(1) < 0.3) if ( hrct > random(6, 13) && hrct < random(21, 24))   digitalWrite(D6, HIGH);
  else digitalWrite(D6, LOW);

  //----------------------------------------- middle floor
  if (atwork7 == true) {
    if (workshift7 >= 1 && workshift7 < 8) workshift7++;
    else if (workshift7 >= 8) {
      workshift7 = 0;
      atwork7 = false;
    }
  }

  else if (random(1) < .9) if ( hrct == 8) { 
    atwork7 = true;
    workshift7 = 1;
  }
  else if (random(1) < .9) if ( hrct > random(4, 6) && hrct < 8) digitalWrite(D7, HIGH);
  else if (random(1) < .9) if ( hrct > random(16, 20) && hrct < random(20, 23)) digitalWrite(D7, HIGH);
  else digitalWrite(D7, LOW);

  if (atwork8 == true) {
    if (workshift8 >= 1 && workshift8 < 8) workshift8++;
    else if (workshift8 >= 8) {
      workshift8 = 0;
      atwork8 = false;
    }
  }
  else if (random(1) < .9) if ( hrct == 8) { 
    atwork8 = true;
    workshift8 = 1;
  }
  else if (random(1) < .9) if ( hrct > random(4, 6) && hrct < 8) digitalWrite(D8, HIGH);
  else if (random(1) < .9) if ( hrct > random(16, 20) && hrct < random(20, 23)) digitalWrite(D8, HIGH);
  else digitalWrite(D8, LOW);

  if (atwork13 == true) {
    if (workshift13 >= 1 && workshift13 < 8) workshift13++;
    else if (workshift13 >= 8) {
      workshift13 = 0;
      atwork13 = false;
    }
  }
  else if (random(1) < .9) if ( hrct == 8) { 
    atwork13 = true;
    workshift13 = 1;
  }
  else if (random(1) < .9) if ( hrct > random(4, 6) && hrct < 8) digitalWrite(D13, HIGH);
  else if (random(1) < .9) if ( hrct > random(16, 20) && hrct < random(20, 23)) digitalWrite(D13, HIGH);
  else digitalWrite(D13, LOW);

  //----------------------------------------- bottom floor

    if (atwork10 == true) {
      if (workshift10 >= 1 && workshift10 < 8) workshift10++;
      else if (workshift10 >= 8) {
        workshift10 = 0;
        atwork10 = false;
      }
    }
    else if (random(1) < .6) if ( hrct == 15) { 
      atwork10 = true;
      workshift10 = 1;
    }
    else if (random(1) < .6) if ( hrct > random(7, 13) && hrct < 15) digitalWrite(D10, HIGH);
    else if (random(1) < .6) if ( hrct > random(22, 24)) digitalWrite(D10, HIGH);
    else if (random(1) < .6) if ( hrct < random(0, 4)) digitalWrite(D10, HIGH);
    else digitalWrite(D10, LOW);
    
    
    
        if (atwork11 == true) {
      if (workshift11 >= 1 && workshift11 < 8) workshift11++;
      else if (workshift11 >= 8) {
        workshift11 = 0;
        atwork11 = false;
      }
    }
    else if (random(1) < .6) if ( hrct == 15) { 
      atwork11 = true;
      workshift11 = 1;
    }
   else  if (random(1) < .6) if ( hrct > random(7, 13) && hrct < 15) digitalWrite(D11, HIGH);
   else  if (random(1) < .6) if ( hrct > random(22, 24)) digitalWrite(D11, HIGH);
   else  if (random(1) < .6) if ( hrct < random(0, 4)) digitalWrite(D11, HIGH);
    else digitalWrite(D11, LOW);
    
    
        if (atwork12 == true) {
      if (workshift12 >= 1 && workshift12 < 8) workshift12++;
      else if (workshift12 >= 8) {
        workshift12 = 0;
        atwork12 = false;
      }
    }
    else if (random(1) < .6) if ( hrct == 15) { 
      atwork12 = true;
      workshift12 = 1;
    }
   else  if (random(1) < .6) if ( hrct > random(7, 13) && hrct < 15) digitalWrite(D12, HIGH);
   else  if (random(1) < .6) if ( hrct > random(22, 24)) digitalWrite(D12, HIGH);
   else  if (random(1) < .6) if ( hrct < random(0, 4)) digitalWrite(D12, HIGH);
    else digitalWrite(D12, LOW);
    
    if (random(1) < .5) {
      digitalWrite(D2,HIGH);
      digitalWrite(D3,LOW);
    }
    else {
      digitalWrite(D3,HIGH);
      digitalWrite(D2,LOW);
    }
    
  

  hrct++;
  if (hrct > 24) hrct = 1;
  delay(4000);


}









