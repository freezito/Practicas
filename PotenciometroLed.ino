const int analogPin = 0;
const int ledPin = 9;
int inputValue = 0;
int outputValue = 0;
void setup ()
{
 Serial.begin(9600);
}
void loop ()
{
 inputValue = analogRead (analogPin);
 Serial.print("Input: ");
 Serial.println(inputValue);
 outputValue = map(inputValue, 0, 1023, 0, 255);
 Serial.print("Output: ");
 Serial.println(outputValue);
 analogWrite(ledPin, outputValue);
 delay(1000);
}
