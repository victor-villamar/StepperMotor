/*Program to control the movement of the stepper motor*/

/*Character for command

  p: rotate the stepper motor in positive direction relative
  n: rotate the stepper motor in negative direction relative
  R: rotate the stepper motor to and absolute positive position
  r: rotate the stepper motor to and absolute negative position
  s: stop the stepper motor
  a: sets an acceleration value
  l: prints the current position



*/

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
bool newdata,allowed = true;     //booleans for new data form serial and allowed flag
char receivedcommand;           //command for computer
long receivedsteps = 0;         //value of steps
long receivedspeed = 0;         //value of speed
long receivedacceleration = 0; //value of acceleration
int direction = 1;             // 1 positive, -1 negative

void setup() {
  
  Serial.begin(9600);

  //Pin mode assignment
  pinMode(driverEN,OUTPUT);

  initialCondition();

}

void loop() {
  // put your main code here, to run repeatedly:

  runstepper();
  checkcommand();
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

  stepper.setCurrentPosition(0);
  Serial.print("\n The current position is: ");
  Serial.println(stepper.currentPosition());

}

/*Function to allow motor movement*/
void runstepper(){

  if(allowed == true){
    stepper.enableOutputs(); //enable outputs
    digitalWrite(driverEN,HIGH);
    stepper.run(); //run the stepper motor
  }

  else{
    stepper.disableOutputs();
    digitalWrite(driverEN,LOW);
    return;
  }
}

/*Fuction for receiving the commands*/

void checkcommand(){

  if(Serial.available() > 0){ //if we receive something from the computer

    receivedcommand = Serial.read();
    newdata = true;   //indicate that there is a new data

    if(newdata == true){

      switch(receivedcommand){

        case 'p':   //move relatively to the current position (positive)
          receivedsteps = Serial.parseFloat();    //value for the steps
          receivedspeed = Serial.parseFloat();    //value for the speed
          direction = 1;
          Serial.println("Positive direction");
          rotateRelative();                       //run the function
          break;
        
        case 'n':   //move relativly to the current position (negative)
          receivedsteps = Serial.parseFloat();    //value for the steps
          receivedspeed = Serial.parseFloat();    //value for the speed
          direction = -1;
          Serial.println("Negative direction");
          rotateRelative();                       //run the function
          break;
        
        case 'R':   //move absolutely to the current position (positive)
          receivedsteps = Serial.parseFloat();    //value for the steps
          receivedspeed = Serial.parseFloat();    //value for the speed
          direction = 1;
          Serial.println("Absolute position [+].");
          rotateAbsolute();
          break;
        
        case 'r':   //move absolutely to the current position (negative)
          receivedsteps = Serial.parseFloat();    //value for the steps
          receivedspeed = Serial.parseFloat();    //value for the speed
          direction = -1;
          Serial.println("Absolute position [-].");
          rotateAbsolute();
          break;
        
        case 's':   //stops the stepper motor
          stepper.stop();               //Stop the motor
          stepper.disableOutputs();     //disable power pins
          digitalWrite(driverEN,LOW);
          Serial.println("Stopped");
          allowed= false;               //disable running
          break;
        
        case 'a':
          allowed = false;                                    //Still keep running disable
          stepper.disableOutputs();                           //disable power
          receivedacceleration = Serial.parseFloat();         //receive the acceleration form te serial
          stepper.setAcceleration(receivedacceleration);      //update the value of variable
          Serial.print("New acceleration value: ");
          Serial.println(receivedacceleration);
          break;
        
        case 'l':   //location
          allowed = false;
          stepper.disableOutputs();                              //disable power pins
          digitalWrite(driverEN,LOW);
          Serial.print("Current location of the motors: ");
          Serial.println(stepper.currentPosition());            //Printing the current position in steps
          break;
        
        default:
          break;

      }
    }

    newdata = false;

  }
}

void rotateRelative(){    //Move X steps from the current position of the stepper motor

  allowed = true;
  stepper.setMaxSpeed(receivedspeed);     //set the speed
  stepper.move(direction*receivedsteps);  //set relative distance and direction

}

void rotateAbsolute(){

  allowed = true;
  stepper.setMaxSpeed(receivedspeed);
  stepper.moveTo(direction*receivedsteps);
}

