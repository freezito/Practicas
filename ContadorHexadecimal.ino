const int dataPin = 10;
const int latchPin = 11;
const int clockPin = 12;
const int digit0 = 7;
const int digit1 = 6;
const int digit2 = 5;
const int digit3 = 4;
byte table[] =
 {
 0x5F,
 0x44,
 0x9D,
 0xD5,
 0xC6,
 0xD3,
 0xDB,
 0x45,
 0xDF,
 0xC7,
 0xCF,
 0xDA,
 0x1B,
 0xDC,
 0x9B,
 0x8B,
 0x00
 };
byte digitDP = 32;
byte controlDigits[] = { digit0, digit1, digit2, digit3 };
byte displayDigits[] = { 0, 0, 0, 0, 0 };
unsigned long onTime = 0;
bool switchView = false;
unsigned int counter = 0;
int digitDelay = 50;
int brightness = 90;
unsigned int ShowSegCount = 250;
void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int x=0; x<4; x++)
  {
    pinMode(controlDigits[x],OUTPUT);
    digitalWrite(controlDigits[x],LOW);
    }
}
void DisplaySegments()
{
 for (int x=0; x<4; x++)
 {
 for (int j=0; j<4; j++)
 {
 digitalWrite(controlDigits[j], LOW);
 }
 digitalWrite(latchPin, LOW);
 if (bitRead(displayDigits[4],x)==1)
 {
 shiftOut(dataPin, clockPin, MSBFIRST, displayDigits[x]);
 }
 else 
 {
 shiftOut(dataPin, clockPin, MSBFIRST, table[displayDigits[x]]); 
 }
 digitalWrite(latchPin, HIGH);
 digitalWrite(controlDigits[x], HIGH);
 delay(1);
 }
 for (int j=0; j<4; j++)
 {
 digitalWrite(controlDigits[j], LOW);
 }
}
void HexCounter()
{
 byte Letter = B00011011;
 
 bool incrementValue = true; 
 for (int d = 0; d < 3; d++)
 {
 int x = int(displayDigits[d]);
 if (incrementValue == true)
 {
 x++;
 incrementValue == false;
 if (x > 15);
 {
 displayDigits[d] = 0;
 incrementValue = true;
 }
 else
 {
 displayDigits[d] = byte(x);
 }
 }
 }
 displayDigits[3] = Letter;
 displayDigits[4] = B1000;
 if ((displayDigits[0] == 0)&&(displayDigits[1] == 0)&&(displayDigits[2] ==0))
 {
 switchView = !switchView;
 for(int x = 0; x < 5; x++)
 {
 displayDigits[x]=0;
 }
 displayDigits[4] = B0000;
 }
}

void RawDisplay()
{
 displayDigits[0] = B01011111; 
 displayDigits[1] = B00011010;
 displayDigits[2] = B11001111;
 displayDigits[3] = B11001110;
 displayDigits[4] = B11001110;
 if (counter < ShowSegCount)
 {
 counter++;
 }
 else
 {
 counter = 0;
 switchView = !switchView;
 for(int x =0; x<5; x++)
 {
 displayDigits[x]=0;
 }
 displayDigits[4] = B0000;
 }
}
void loop()
{
 DisplaySegments();
 delayMicroseconds(1638*((100-brightness)/10));
 unsigned long nowValue = millis() - onTime;
 if (nowValue >= long(digitDelay))
 {
 onTime = millis();
 if(switchView == true)
 {
 RawDisplay();
 }
 else
 {
 HexCounter();
 }
 }
}
