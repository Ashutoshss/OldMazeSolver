#include <afstandssensor.h>
#include <EEPROM.h>

// AfstandsSensor(triggerPin, echoPin);
AfstandsSensor front(A3, A2);  
AfstandsSensor left(11,13);
AfstandsSensor right(A1, A0);
#define motor1Pin1 12
#define motor1Pin2 4
#define motor2Pin1 8
#define motor2Pin2 7
int i=0;
void setup () {
    Serial.begin(9600);  
     pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  analogWrite(5,80);
  analogWrite(6,80);
}

void loop () 
{
   int leftDistance = left.afstandCM();
  int frontDistance =front.afstandCM();
  int rightDistance = right.afstandCM();

  // Check if there is an obstacle in front of the robot
  if (frontDistance < 15)
   {
    // If there is an obstacle, turn left or right based on the distances from the left and right sensors
    if (leftDistance > rightDistance)
     {
        // EEPROM.update(i,'L');
      leftTurn();
      // delay(100);
      i++;

    }
     else
      {
      //  EEPROM.update(i,'R');
       rightTurn();
      //  delay(100);
       i++;
    }
  } else {
    // If there is no obstacle, move forward
    //  EEPROM.update(i,'F');
    move();
    // delay(100);
    i++;
  }

  //  exit(0);
}
void move()
{
  for(int i=0;i<90;i++)
  {
      int l=left.afstandCM();
      int r=right.afstandCM();
      int f=front.afstandCM();
      Serial.println(i);
      Serial.println(l);
      Serial.println(r);
      Serial.println(".....");
      if(f<=10)
      {
        break;
      }
       else if (l <= 3 )
        {
        analogWrite(5,80);
        analogWrite(6,40);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      
      digitalWrite(motor2Pin1,HIGH );
      digitalWrite(motor2Pin2, LOW);
    }
       else if (l <= 5 )
        {
        analogWrite(5,80);
        analogWrite(6,60);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      
      digitalWrite(motor2Pin1,HIGH );
      digitalWrite(motor2Pin2, LOW);
    }
      else if (l <= 8 ) {
        analogWrite(5,80);
        analogWrite(6,70);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      
      digitalWrite(motor2Pin1,HIGH );
      digitalWrite(motor2Pin2, LOW);
    }
    else if(r <= 3 ){
      //  analogWrite(5,100);
        analogWrite(5,40);
        analogWrite(6,80);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      
        // analogWrite(6,200);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    }
    else if(r <= 5 ){
      //  analogWrite(5,100);
        analogWrite(5,60);
        analogWrite(6,80);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      
        // analogWrite(6,200);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    }

    else if(r <= 8 ){
      //  analogWrite(5,100);
        analogWrite(5,70);
        analogWrite(6,80);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      
        // analogWrite(6,200);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
    }

    else 
    {
        analogWrite(5,80);
        analogWrite(6,80);
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2,LOW );
    }
  }
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2,LOW );
}
void rightTurn()
{
        analogWrite(5,80);
        analogWrite(6,80);
        for(int i=0;i<100;i++)
        {
            Serial.println(i);
          digitalWrite(motor1Pin1, HIGH);
          digitalWrite(motor1Pin2, LOW);
          digitalWrite(motor2Pin1, LOW);
          digitalWrite(motor2Pin2,HIGH );
        }
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2,LOW );
      
}
void leftTurn()
{
        analogWrite(5,80);
        analogWrite(6,80);
        for(int i=0;i<90;i++)
        {
            Serial.println(i);
          digitalWrite(motor1Pin1, LOW);
          digitalWrite(motor1Pin2, HIGH);
          digitalWrite(motor2Pin1, HIGH);
          digitalWrite(motor2Pin2,LOW );
        }
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      
}
