void increment(){
  if(getHour() == 59){
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
      hour += i * pow(2, count);
    }
    count++;
  }
}

int getMin(){
  int minute = 0;
  int count = 0;
  for(int i = 7; i < 9; i++){
    minute += i * pow(2, count) * 10;
	 count++;
  }
  count = 0;
  for(int i = 10; i < 13; i++){
	minute += i * pow(2, count);
	count++;
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