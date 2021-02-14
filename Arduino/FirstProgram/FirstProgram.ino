//The user input three numbers to the program, the first define the on 
//time of the LED on pin 13, the second number define the off time of the
//LED, the third number define the repeat time of the program.
//Author: Wenbo Hou
//Last modified: 13/2/2021

  // Define the output message
  String msg1 = "I am ready";
  String msg2 = "Please enter three numbers: ";

  int myInts[4];

void setup() {

  pinMode(13,OUTPUT);

  // Set the baud rate to be 9600
  Serial.begin(9600);
  
  Serial.setTimeout(5000);// Set the timeout to 5 second.
}

void loop() {
  // print the first message
  Serial.println(msg1);
  Serial.println(msg2);
  
  while (Serial.available()<3) {} 
  
  for(int n=0; n<3; n=n+1)
  {
    myInts[n] = Serial.parseInt(); 
  }

  // print 3 numbers, first tells how long LED will be on, the second tells
  // how long the LED will be off, the third tells how many times this will
  // repeats

  Serial.print("First number: ");
  Serial.println(myInts[0]);
  Serial.print("Second number: ");
  Serial.println(myInts[1]);
  Serial.print("Third number: ");
  Serial.println(myInts[2]);
  Serial.print("\n");
  
  for(int i = 0; i < myInts[2]; i++)
  {
    Serial.print("Iteration: ");
    Serial.println(i+1);
    digitalWrite(13,HIGH);
    delay(myInts[0]);
    
    digitalWrite(13,LOW);
    delay(myInts[1]);
    
  }
  // exit the program
  exit(0);
  
}
