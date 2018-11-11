void increment(){
  if(9 == HIGH && 7 == HIGH){
    incrementHour();
  }
  else{
    incrementMin();
  }
}

void incrementMin(){
  
}

void incrementHour(){
  
}

int getHour(){
  int hour = 0;
  int count = 0;
  for(int i = 1; i < 2; i++){
    if(i == HIGH){
      hour += i*10
    }
  }
  for(int i = 3; i < 6; i++){
    if(i == HIGH){
      hour += i * pow(2^count);
    }
    count++;
  }
}

int getMin(){
  int minute = 0;
  int count = 0;
  for(int i = 7; i < 9; i++){
    minute += i * pow(2*count) * 10;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  bool mins = false;
  bool hours = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  //Initial State  
  
  delay(60000);
  increment();
}
