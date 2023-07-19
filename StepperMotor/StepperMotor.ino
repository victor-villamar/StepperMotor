

/////////////////////////LIBRARIES////////////////////////
//////////////////////////////////////////////////////////

#include <AccelStepper.h>

/////////////////////////STEPPER MOTOR////////////////////////
//////////////////////////////////////////////////////////////

//Define steper motor pins

#define driverEN 5            // ENABLE- pin
#define driverDIR 6           // DIR- pin
#define driverPUL 7           // PUL- pin
#define motorInterfaceType 1  // means one stepper driver

//Define stepper variable
AccelStepper stepper(motorInterfaceType,driverPUL,driverDIR);

/////////////////////////GLOBAL CONTROL VARIABLES////////////////////////
/////////////////////////////////////////////////////////////////////////

//define varibales
bool allowed = true; //allowed flag

void setup() {
  
  Serial.begin(9600);

  //Pin mode assignment
  pinMode(driverEN,OUTPUT);

  initialCondition();

}

void loop() {
  // put your main code here, to run repeatedly:

  runstepper();
}


/*Function that sets the initial conditions*/
void initialCondition(){
  
  //Set the maximun speed and acceleration
  stepper.setMaxSpeed(3000); //steps/s
  stepper.setAcceleration(1000); //stepers/s^2

  //Set the minimun pulse width
  stepper.setMinPulseWidth(25);

  //Disable Outputs
  digitalWrite(driverEN,LOW); //set pin LOW
  stepper.disableOutputs(); //disable outputs

}

/*Function to allow motor movement*/
void runstepper(){

  if(allowed == true){
    stepper.enableOutputs(); //enable outputs
    digitalWrite(driverEN,HIGH);
    stepper.run(); //run the stepper motor
    stepper.setSpeed(1000); //set a speed
    stepper.runSpeed(); //move the motor
  }

  else{
    stepper.disableOutputs();
    digitalWrite(driverEN,LOW);
    return;
  }
}
