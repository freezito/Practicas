void setup(){
  }
void loop()
{
  for (int fokito=2;fokito<=9;fokito++)
  {
    digitalWrite(fokito, HIGH);
    delay(500);
    }
    for(int fokito=9;fokito>=2;fokito--)
    {
      digitalWrite(fokito, LOW);
      delay(100);
      }
      for(int fokito=9;fokito>=2;fokito--)
      {
        digitalWrite(fokito, HIGH);
        delay(250);
        }
        for (int fokito=2;fokito<=9;fokito++)
        {
          digitalWrite(fokito, LOW);
          delay(100);
          }
}
