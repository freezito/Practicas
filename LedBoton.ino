int estado = 0;
void setup ()
{
 pinMode (8, INPUT);
 pinMode (9, OUTPUT);
}
void loop ()
{
 estado = digitalRead (8);
 if (estado == HIGH)
 {
 digitalWrite (9, HIGH);
 }
 else
 {
 digitalWrite (9, LOW);
 }
}
