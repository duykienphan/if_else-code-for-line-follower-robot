#define M1 4 //left
#define M2 5
#define M3 6 //right
#define M4 7
#define enA 9
#define enB 10

int M, L1, L2, R1, R2;
int line = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readSensor();
  //exportSensorValue();
  //test();

  if ((M < line) && (L1 > line) && (R1 > line) && (L2 > line) && (R2 > line)) {
    analogWrite(enA, 80);
    analogWrite(enB, 80);
    Forward();
  }
  else if ((M < line) && (L1 < line) && (R1 > line) && (L2 > line) && (R2 > line)) {
    analogWrite(enA, 80);
    analogWrite(enB, 80);
    Forward();
  }
  else if ((M > line) && (L1 < line) && (R1 > line) && (L2 > line) && (R2 > line)) {
    analogWrite(enA, 50);
    analogWrite(enB, 100);
    Left();
  }
  else if ((M > line) && (L1 < line) && (R1 > line) && (L2 < line) && (R2 > line)) {
    analogWrite(enA, 50);
    analogWrite(enB, 100);
    Left();
  }
  else if ((M < line) && (L1 > line) && (R1 < line) && (L2 > line) && (R2 > line)) {
    analogWrite(enA, 80);
    analogWrite(enB, 80);
    Forward();
  }
  else if ((M > line) && (L1 > line) && (R1 < line) && (L2 > line) && (R2 > line)) {
    analogWrite(enA, 100);
    analogWrite(enB, 50);
    Right();
  }
  else if ((M > line) && (L1 > line) && (R1 < line) && (L2 > line) && (R2 < line)) {
    analogWrite(enA, 100);
    analogWrite(enB, 50);
    Right();
  }
  else if ((M > line) && (L1 > line) && (R1 > line) && (L2 < line) && (R2 > line)) {
    analogWrite(enA, 10);
    analogWrite(enB, 100);
    Left();
  }
  else if ((M > line) && (L1 > line) && (R1 > line) && (L2 > line) && (R2 < line)) {
    analogWrite(enA, 100);
    analogWrite(enB, 10);
    Right();
  }
  else if ((M > line) && (L1 > line) && (R1 > line) && (L2 > line) && (R2 > line)) {
    analogWrite(enA, 100);
    analogWrite(enB, 100);
    Back();
  }
  else if ((M < line) && (L1 < line) && (R1 < line) && (L2 < line) && (R2 < line)) {
    Stop();
  }
  else if ((M < line) && (L1 > line) && (R1 < line) && (L2 > line) && (R2 < line)) {
    analogWrite(enA, 0);
    analogWrite(enB, 100);
    Right();
  }
  else if ((M < line) && (L1 < line) && (R1 < line) && (L2 > line) && (R2 < line)) {
    analogWrite(enA, 0);
    analogWrite(enB, 100);
    Right();
  }
  else if ((M < line) && (L1 < line) && (R1 > line) && (L2 < line) && (R2 > line)) {
    analogWrite(enA, 0);
    analogWrite(enB, 100);
    Right();
  }
  else if ((M < line) && (L1 < line) && (R1 < line) && (L2 < line) && (R2 > line)) {
    analogWrite(enA, 0);
    analogWrite(enB, 100);
    Right();
  }
  else
    Stop();
}

void readSensor() {
  L2 = analogRead(A0);
  L1 = analogRead(A1);
  M = analogRead(A2);
  R1 = analogRead(A3);
  R2 = analogRead(A4);
}

void exportSensorValue() {
  Serial.println(L2);
  Serial.println(L1);
  Serial.println(M);
  Serial.println(R1);
  Serial.println(R2);
  Serial.println();
  delay(1000);
}

void Forward() {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  Serial.println("forward");
}

void Left() {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  Serial.println("left");
}

void Right() {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  Serial.println("right");
}

void Stop() {
  analogWrite(enA, 0);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(enB, 0);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  Serial.println("stop");
}

void Back() {
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  Serial.println("back");
}


void test() {
  Forward();
  delay(2000);
  Right();
  delay(2000);
  Left();
  delay(2000);
  Stop();
  delay(2000);
}
