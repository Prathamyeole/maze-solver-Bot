#define LS 2
#define RS 3
#define FS 4
#define LMC 6
#define LMA 5
#define RMC 8
#define RMA 7
#define LW LOW
#define HG HIGH
#define pi 3.14159265359

float width = 25;
float sensor = 25;
float mmps = 30;
float axle = 100;

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(FS, INPUT);
  pinMode(LMC, OUTPUT);
  pinMode(RMC, OUTPUT);
  pinMode(LMA, OUTPUT);
  pinMode(RMA, OUTPUT);
}

void turnRight(){
  float tm = (width/2)/mmps;
  digitalWrite(LMC,LOW);digitalWrite(LMA,LOW);digitalWrite(RMC,LOW);digitalWrite(RMA,LOW);
  digitalWrite(RMA, HIGH);
  digitalWrite(LMC, HIGH);
  delay(tm);
  digitalWrite(RMA, LOW);
  digitalWrite(LMC, LOW);
  delay(200);
  digitalWrite(RMC, HIGH);
  digitalWrite(LMC, HIGH);
  delay((pi*axle)/(4*mmps));
  digitalWrite(RMC, LOW);
  digitalWrite(LMC, LOW);
  delay(200);
  digitalWrite(RMA, HIGH);
  digitalWrite(LMC, HIGH);
  delay((width/2 + 12.5)/mmps);
  digitalWrite(RMA, LOW);
  digitalWrite(LMC, LOW);
}

void turnLeft(){
  float tm = (width/2)/mmps;
  digitalWrite(LMC,LOW);digitalWrite(LMA,LOW);digitalWrite(RMC,LOW);digitalWrite(RMA,LOW);
  digitalWrite(RMA, HIGH);
  digitalWrite(LMC, HIGH);
  delay(tm);
  digitalWrite(RMA, LOW);
  digitalWrite(LMC, LOW);
  delay(200);
  digitalWrite(RMA, HIGH);
  digitalWrite(LMA, HIGH);
  delay((pi*axle)/(4*mmps));
  digitalWrite(RMA, LOW);
  digitalWrite(LMA, LOW);
  delay(200);
  digitalWrite(RMA, HIGH);
  digitalWrite(LMC, HIGH);
  delay((width/2 + 12.5)/mmps);
  digitalWrite(RMA, LOW);
  digitalWrite(LMC, LOW);
}

void turnBack(){
  digitalWrite(LMC,LOW);digitalWrite(LMA,LOW);digitalWrite(RMC,LOW);digitalWrite(RMA,LOW);
  delay(200);
  digitalWrite(RMA, HIGH);
  digitalWrite(LMA, HIGH);
  delay((pi*axle)/(2*mmps));
  digitalWrite(RMA, LOW);
  digitalWrite(LMA, LOW);
}

void Forward(){
  digitalWrite(RMA, HIGH);
  digitalWrite(LMC, HIGH);
}

void loop() {
  if(digitalRead(RS) == LW){
    turnRight();
  }
  else if(digitalRead(FS) == LW){
    Forward();
  }
  else if(digitalRead(LS) == LW){
    turnLeft();
  }
  else{
    turnBack();
 
  }
}
