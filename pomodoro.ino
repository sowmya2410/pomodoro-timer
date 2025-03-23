const int clk_ML = 2;
const int clk_MR = 3;
const int clk_SL = 4;
const int clk_SR = 5;
const int rst_ML = 6;
const int rst_MR = 7;
const int rst_SL = 8;
const int rst_SR = 9;
const int DE_ML = 10;
const int DE_MR = 11;
const int DE_SL = 12;
const int DE_SR = 13;
const int work = A0;
const int break_button = A1;
const int buzzer = A2;
const int stop = A3;
int i = 0;
int var1 = 0;
int var2 = 0;
int var3 = 0;
int var4 = 0;
int X = 0;
boolean Setup = true;
boolean Stop = false;

void setup() {
  pinMode(clk_ML, OUTPUT);
  pinMode(clk_MR, OUTPUT);
  pinMode(clk_SL, OUTPUT);
  pinMode(clk_SR, OUTPUT);
  pinMode(rst_ML, OUTPUT);
  pinMode(rst_MR, OUTPUT);
  pinMode(rst_SL, OUTPUT);
  pinMode(rst_SR, OUTPUT);
  pinMode(DE_ML, OUTPUT);
  pinMode(DE_MR, OUTPUT);
  pinMode(DE_SL, OUTPUT);
  pinMode(DE_SR, OUTPUT);
  pinMode(work, INPUT_PULLUP);
  pinMode(break_button, INPUT_PULLUP);
  pinMode(stop, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  all_rst();
  digitalWrite(DE_ML, HIGH);
  digitalWrite(DE_MR, HIGH);
  digitalWrite(DE_SL, HIGH);
  digitalWrite(DE_SR, HIGH);
  delay(500);
  Display_Test();
}

void loop() {
  if (digitalRead(work) == LOW) {
    Setup = false;
    var1 = 1;
    var2 = 0;
    var3 = 5;
    var4 = 2;
  }
  if (digitalRead(break_button) == LOW) {
    Setup = false;
    var1 = 1;
    var2 = 0;
    var3 = 5;
    var4 = 0;
  }
   if (digitalRead(stop) == LOW) {
    Setup = false;
    var1 = 0;
    var2 = 0;
    var3 = 0;
    var4 = 0;
  }
  var1 = var1 - 1;
  if (var1 == -1 && var2 == 0 && var3 == 0 && var4 == 0) {
    buzz();
  } else if (var1 == -1) {
    var2 = var2 - 1;
    var1 = 9;
  }
  if (var2 == -1) {
    var2 = 5;
    var3 = var3 - 1;
  }
  if (var3 == -1) {
    var3 = 9;
    var4 = var4 - 1;
  }
  delay(1000);
  digitalWrite(rst_SR, HIGH);
  digitalWrite(rst_SR, LOW);
  for (i = 0; i < var1; i++) {
    digitalWrite(clk_SR, HIGH);
    digitalWrite(clk_SR, LOW);
  }
  digitalWrite(rst_SL, HIGH);
  digitalWrite(rst_SL, LOW);
  for (i = 0; i < var2; i++) {
    digitalWrite(clk_SL, HIGH);
    digitalWrite(clk_SL, LOW);
  }
  digitalWrite(rst_MR, HIGH);
  digitalWrite(rst_MR, LOW);
  for (i = 0; i < var3; i++) {
    digitalWrite(clk_MR, HIGH);
    digitalWrite(clk_MR, LOW);
  }
  digitalWrite(rst_ML, HIGH);
  digitalWrite(rst_ML, LOW);
  for (i = 0; i < var4; i++) {
    digitalWrite(clk_ML, HIGH);
    digitalWrite(clk_ML, LOW);
  }
}

void all_rst() {
  digitalWrite(rst_ML, HIGH);
  digitalWrite(rst_MR, HIGH);
  digitalWrite(rst_SL, HIGH);
  digitalWrite(rst_SR, HIGH);
  digitalWrite(rst_ML, LOW);
  digitalWrite(rst_MR, LOW);
  digitalWrite(rst_SL, LOW);
  digitalWrite(rst_SR, LOW);
}

void Display_Test() {
  all_rst();
  int var = 10;
  for (int j = 0; j < 10; j++) {
    var = var - 1;
    for (i = 0; i < var; i++) {
      digitalWrite(clk_ML, HIGH);
      digitalWrite(clk_MR, HIGH);
      digitalWrite(clk_SL, HIGH);
      digitalWrite(clk_SR, HIGH);
      digitalWrite(clk_ML, LOW);
      digitalWrite(clk_MR, LOW);
      digitalWrite(clk_SL, LOW);
      digitalWrite(clk_SR, LOW);
    }
    delay(250);
    all_rst();
  }
}

void buzz() {
  for (i = 0; i < 10; i++) {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
}
