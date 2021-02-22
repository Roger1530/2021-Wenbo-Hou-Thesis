//Program: Testing of the serial input with the LED
//Author: Wenbo Hou
//Last modified: 13/2/2021
//----------------------------------------------------------------------
//The user input three numbers to the program, the first define the on 
//time of the LED on pin 13, the second number define the off time of the
//LED, the third number define the repeat time of the program.
//----------------------------------------------------------------------

  // Define the output message
  String msg1 = "I am ready";
  String msg2 = "Please enter three numbers: ";

  // define the output pin
  int LedPin = 13;

  // define an array to store the input integers
  int myInts[4];

void setup() {

  pinMode(LedPin,OUTPUT);

  // Set the baud rate to be 9600
  Serial.begin(9600);

  // Set the timeout to 5 second
  Serial.setTimeout(5000);
}

void loop() {
  // print the first message
  Serial.println(msg1);
  Serial.println(msg2);

  // Read the input integers from the user through serial monitor
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
    digitalWrite(LedPin,HIGH);
    delay(myInts[0]);
    
    digitalWrite(LedPin,LOW);
    delay(myInts[1]);
    
  }
  // exit the program
  exit(0);
}
