//----- BINARY CLOCK -----

//Citrus Hack 2018 Project
//Authors: Jason Chan, Jack Cui

//This project is a 24 hr Binary clock. It is meant for an Arduino UNO min of 13 pins.
// 


//--------------------------------------------------------------------------------
//You can set the time here (ie. 9:45pm = 21:45 -> 5,4,1,2)
//--------------------------------------------------------------------------------
int minOnes=6;
int minTens=2;
int hrOnes=8;
int hrTens=1;

//DEFAULT TIME to zero out...
//int minOnes=0;
//int minTens=1;
//int hrOnes=1;
//int hrTens=1;


void setup() {
//  Serial.begin(9600);
  //set outputs 
  for(int k=1;k<=13;k++) {
    pinMode(k, OUTPUT);
  }
  //set inputs
  //pinMode(14, INPUT);

//if you set the time these should initialize the time you set
  runTime(10,1,4,minOnes);
  runTime(6,5,7,minTens);
  runTime(10,8,11,hrOnes);
  runTime(2,12,13,hrTens);
}


//This function runs as a column controller, maxCount is the maximum a digit 
//should count to (ie. 0-9 for min ones place and 0-5 for the min tens place).
//beginLed and endLed is the number the led is listed on. The light array:
//---------------
//      11     4
//      10  7  3
//  13  9   6  2
//  12  8   5  1
//---------------
//These cloumns should be passed into the function like so runTime(6, 5, 7, minTens)
//place varible is what digit place. we keep a global varible for those places
//In general this function writes the lights based on the binary number.
//The number 7 = 1110 or ON ON ON OFF for the lights.

bool runTime(int maxCount, int beginLed, int endLed, int& place) {
  int temp = place;
  int remainder;

  place += 1;
  if(place == maxCount+1) {
    place = 0;
  }
  
  //loops through lights, determines number
  for(int i = beginLed; i <= endLed; i++){
    remainder = temp % 2;
    temp = temp / 2;
    if(remainder == 1) {
      digitalWrite(i, HIGH);
    }
    else if(remainder == 0) {
      digitalWrite(i, LOW);
    }
  }

  if(place == 0){
    return true;
  }
  return false;
  
}



//Test all lights
void loop() {
//  Serial.print(hrTens);
//  Serial.print(hrOnes);
//  Serial.print(":");
//  Serial.print(minTens);
//  Serial.begin(9600);
//  Serial.print(minOnes);
//  Serial.print("\n");
//  Serial.end();

//--------------------------------------------------------------------------------
//Use this to change clock speed or rate of change. <1000>ms = 1 second
//This Arduino was designed as a 24 hr clock so the default can be <60000> = 1 min
//--------------------------------------------------------------------------------
  delay(1000);

  
  //CHANGE MINUETS
  if(runTime(10, 1, 4, minOnes)){
    runTime(10, 1, 4, minOnes);
    
    if(runTime(6, 5, 7, minTens)){
      runTime(6, 5, 7, minTens);
      
      
      //CHANGE HOURS
      if(hrTens == 3) {
        //when the tens place is two count up 3
        if(runTime(4,8,11,hrOnes)) {
          runTime(4,8,11,hrOnes);

          if(runTime(3,12,13,hrTens)){
            runTime(3,12,13,hrTens);
          }
        }
      }
      else {
          if(runTime(10,8,11,hrOnes)){
            runTime(10,8,11, hrOnes);

            if(runTime(3,12,13,hrTens)){
              runTime(3,12,13,hrTens);
          }
        }
      }
    }
  }
}
