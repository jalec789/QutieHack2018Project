
//int minOnes=0;
//int minTens=1;
//int hrOnes=1;
//int hrTens=1;

int minOnes=0;
int minTens=5;
int hrOnes=6;
int hrTens=1;

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


void setup() {
  Serial.begin(9600);
  //set outputs 
  for(int k=1;k<=13;k++) {
    pinMode(k, OUTPUT);
  }
  //set inputs
  pinMode(14, INPUT);

  runTime(10,1,4,minOnes);
  runTime(6,5,7,minTens);
  runTime(10,8,11,hrOnes);
  runTime(2,12,13,hrTens);

  
}



//Test all lights
void loop() {
  
  //RUN MINUETS
  if(runTime(10, 1, 4, minOnes)){
    runTime(10, 1, 4, minOnes);
    
    if(runTime(6, 5, 7, minTens)){
      runTime(6, 5, 7, minTens);
      
      
      //RUN HOURS
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
  Serial.print(hrTens);
  Serial.print(hrOnes);
  Serial.print(":");
  Serial.print(minTens);
  Serial.print(minOnes);
  Serial.print("\n");
  delay(60000);
}
