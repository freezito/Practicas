const int foquito=9;

void setup()
{
 pinMode(foquito,OUTPUT);
}
void loop()
{
 digitalWrite(foquito, HIGH);
 delay(100);
 digitalWrite(foquito, LOW);
}
