void setup() {
  //set outputs 
  for(int k=1;k<=13;k++) {
    pinMode(k, OUTPUT);
  }
  //set inputs
  pinMode(14, INPUT);
}


int minOnes=0;
int minTens=1;
int hrOnes=0;
int hrTens=0;

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
  delay(500);
  if(runTime(10, 1, 4, minOnes)){
    runTime(10, 1, 4, minOnes);
    if(runTime(5, 5, 7, minTens)){


    }
  } 
}
