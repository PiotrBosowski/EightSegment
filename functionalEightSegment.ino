//pinout:
const int A = 6;
const int B = 8;
const int C = 3;
const int D = 2;
const int E = 1;
const int F = 7;
const int G = 5;
const int DOT = 4;
const int VCC_0 = 9;
const int VCC_1 = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  digitalWrite(A, HIGH);
  pinMode(B, OUTPUT);
  digitalWrite(B, HIGH);
  pinMode(C, OUTPUT);
  digitalWrite(C, HIGH);
  pinMode(D, OUTPUT);
  digitalWrite(D, HIGH);
  pinMode(E, OUTPUT);
  digitalWrite(E, HIGH);
  pinMode(F, OUTPUT);
  digitalWrite(F, HIGH);
  pinMode(G, OUTPUT);
  digitalWrite(G, HIGH);
  pinMode(DOT, OUTPUT);
  digitalWrite(DOT, HIGH);
  pinMode(VCC_0, OUTPUT);
  digitalWrite(VCC_0, LOW);
  pinMode(VCC_1, OUTPUT);
  digitalWrite(VCC_1, LOW);
}

bool numbersDisplayTable[10][8] = 
{ //DOT,   A,    B,    C,    D,    E,    F,    G
  {HIGH,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW, HIGH}, //0
  {HIGH, HIGH,  LOW,  LOW, HIGH, HIGH, HIGH, HIGH}, //1
  {HIGH,  LOW,  LOW, HIGH,  LOW,  LOW, HIGH,  LOW}, //2
  {HIGH,  LOW,  LOW,  LOW,  LOW, HIGH, HIGH,  LOW}, //3
  {HIGH, HIGH,  LOW,  LOW, HIGH, HIGH,  LOW,  LOW}, //4
  {HIGH,  LOW, HIGH,  LOW,  LOW, HIGH,  LOW,  LOW}, //5
  {HIGH,  LOW, HIGH,  LOW,  LOW,  LOW,  LOW,  LOW}, //6
  {HIGH,  LOW,  LOW,  LOW, HIGH, HIGH, HIGH, HIGH}, //7
  {HIGH,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW}, //8
  {HIGH,  LOW,  LOW,  LOW,  LOW, HIGH,  LOW,  LOW}  //9
};

void displayCypher(int number, int displayer)
{
  digitalWrite(VCC_0, LOW);
  digitalWrite(VCC_1, LOW);
  number = (number < 0) ? 0 : (number > 9 ? 9 : number);
  digitalWrite(A, numbersDisplayTable[number][1]);
  digitalWrite(B, numbersDisplayTable[number][2]);
  digitalWrite(C, numbersDisplayTable[number][3]);
  digitalWrite(D, numbersDisplayTable[number][4]);
  digitalWrite(E, numbersDisplayTable[number][5]);
  digitalWrite(F, numbersDisplayTable[number][6]);
  digitalWrite(G, numbersDisplayTable[number][7]);
  digitalWrite(DOT, numbersDisplayTable[number][0]);
  if(displayer == 0) digitalWrite(VCC_0, HIGH);
  else digitalWrite(VCC_1, HIGH);
}

void displayNumber_loop(int number, int timeRemaining)
{
  int firstCypher = number%10;
  int secondCypher = (number/10)%10;
  while(timeRemaining > 0)
  {
    displayCypher(secondCypher, 1);
    delay(10);
    displayCypher(firstCypher, 0);
    delay(10);
    timeRemaining-=20;
  }
}

int number = 99;
void loop()
{
  displayNumber_loop(number--, 1000);
}
