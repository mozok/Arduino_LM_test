#define PWMPin 3
int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PWMPin, OUTPUT);
  
  while(!Serial)
  {
    ;
  }
  Serial.println("Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    value = Serial.parseInt();

    if (value >= 0 && value <= 255)
    {
       analogWrite(PWMPin, value);
       Serial.print("Set PWM to: ");
       Serial.println(value);
    }
    else
    {
      Serial.print("Wrong value");
    }
  }

}
