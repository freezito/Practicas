const int rojitoPin = 11;
const int verdesitoPin = 10;
const int azulitoPin = 9;

void setup()
{
pinMode(rojitoPin, OUTPUT);
pinMode(verdesitoPin, OUTPUT);
pinMode(azulitoPin, OUTPUT);
}
void loop()
{
 color(244, 0, 123);
 delay(1000);
 color(0 , 255, 0);
 delay(1000);
 color(0, 0, 255);
 delay(1000);
 color(255, 0, 252);
 delay(1000);
 color(237, 109, 0);
 delay(1000);
 color(255, 215, 0);
 delay(1000);
 color(34, 139, 34);
 delay(1000);
 color(0, 112, 255);
 delay(1000);
 color(0, 46, 90);
 delay(1000);
 color(128, 0, 128);
 delay(1000);
}
void color (unsigned char red, unsigned char green, unsigned char blue)
{
 analogWrite(rojitoPin, red);
 analogWrite(verdesitoPin, green);
 analogWrite(azulitoPin, blue);
}
