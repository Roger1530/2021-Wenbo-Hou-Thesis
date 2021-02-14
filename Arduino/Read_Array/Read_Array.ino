String msg = "Please enter three numbers: ";
int myInts[6];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(5000);// Set the timeout to 5 second.
}

void loop() {
  Serial.println(msg);
  
  // put your main code here, to run repeatedly:
  while (Serial.available()<3) {} // Wait 'till there are 9 Bytes waiting
  for(int n=0; n<3; n=n+1)
  myInts[n] = Serial.parseInt(); // Then: Get them.

  for (int i = 0; i < 3; i = i + 1) {
  Serial.println(myInts[i]);
  }
 // memset(myInts, 0, sizeof(myInts));
}
