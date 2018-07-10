#define e1 5
#define e2 6
#define d1 9
#define d2 10

int trigger_front = A4;
int echo_front = A5;

int trigger_left = A2;
int echo_left = A3;

int trigger_right = A1;
int echo_right = A0;

void setup()
{
  pinMode(trigger_front, OUTPUT);
  pinMode(echo_front, INPUT);

  pinMode(trigger_left, OUTPUT);
  pinMode(echo_left, INPUT);

  pinMode(trigger_right, OUTPUT);
  pinMode(echo_right, INPUT);

  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
    
  Serial.begin(115200);
  delay(100);
}

void loop()
{

  
  long distance_front, distance_left, distance_right, right, left, front;

  digitalWrite(trigger_front, LOW);  
  
  delayMicroseconds(2);              
  
  digitalWrite(trigger_front, HIGH); 
  
  delayMicroseconds(5);               
  
  digitalWrite(trigger_front, LOW); 
  
  distance_front = pulseIn(echo_front, HIGH); 
  
  front = distance_front / 29 / 2;

  digitalWrite(trigger_left, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_left, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger_left, LOW);
  distance_left = pulseIn(echo_left, HIGH);
  left = distance_left / 29 / 2;

  digitalWrite(trigger_right, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_right, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger_right, LOW);
  distance_right = pulseIn(echo_right, HIGH);
  right = distance_right / 29 / 2;
  
  Serial.print(front);

  Serial.print(" | ");

  Serial.print(left);

  Serial.print(" | ");

  Serial.print(right);

  Serial.println(" ");

  analogWrite(e1, 0);            
  analogWrite(e2, 0);            
  analogWrite(d1, 0);            
  analogWrite(d2, 0);            

        
  if (front > 8)
  {

    if (right > 7 && right < 13)
    {

      analogWrite(e1, 120);
      analogWrite(e2, 0);
      analogWrite(d1, 0);
      analogWrite(d2, 130);
    }

    if (right >= 13)
    {

      analogWrite(e1, 120);
      analogWrite(e2, 0);
      analogWrite(d1, 0);
      analogWrite(d2, 110);
    }


    if (right <= 7) 
    {

      analogWrite(e1, 100);
      analogWrite(e2, 0);
      analogWrite(d1, 0);
      analogWrite(d2, 120);
    }
  }


  if (left <= 15 && right > 15 && front <= 10) rightRotation(); 

  if (left > 15 && right > 15 && front <= 10) rightRotation(); 

  if (right <= 15 && left > 15 && front <= 10) leftRotation(); 

  if (right <= 15 && left <= 15 && front <= 10) fullRotation();
  
}

void leftRotation() 
{

  analogWrite(e1, 0);
  analogWrite(e2, 120);
  analogWrite(d1, 0);
  analogWrite(d2, 120);
  delay(700);

}

void rightRotation() 
{

  analogWrite(e1, 120);
  analogWrite(e2, 0);
  analogWrite(d1, 120);
  analogWrite(d2, 0);
  delay(700);

}

void fullRotation() 
{

  analogWrite(e1, 120);
  analogWrite(e2, 0);
  analogWrite(d1, 120);
  analogWrite(d2, 0);
  delay(1450);

}

