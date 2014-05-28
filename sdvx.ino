
#include <Bounce.h>

#include <Encoder.h>

Encoder myEnc(0, 1);

Encoder myEnc2(2, 3);


Bounce button0 = Bounce(0, 10);

Bounce button1 = Bounce(1, 10);

Bounce button2 = Bounce(2, 10);

Bounce button3 = Bounce(3, 10);

Bounce button4 = Bounce(4, 10);

Bounce button5 = Bounce(5, 10);

Bounce button6 = Bounce(6, 10);

Bounce button7 = Bounce(7, 10);

Bounce button8 = Bounce(8, 10);

Bounce button9 = Bounce(9, 10);

Bounce button10 = Bounce(10, 10);


void setup() {



  pinMode(4, INPUT_PULLUP);

  pinMode(5, INPUT_PULLUP);

  pinMode(6, INPUT_PULLUP);  

  pinMode(7, INPUT_PULLUP);

  pinMode(8, INPUT_PULLUP);

  pinMode(9, INPUT_PULLUP);

  pinMode(10, INPUT_PULLUP);

}

long oldPosition  = -999;

long oldPosition2  = -999;


void loop() {

  // Update all the buttons.  There should not be any long

  // delays in loop(), so this runs repetitively at a rate

  // faster than the buttons could be pressed and released.

  button0.update();   //left Knob

  button1.update();   //right Knob

  button2.update();   //left Knob

  button3.update();   //right Knob

  button4.update();

  button5.update();

  button6.update();

  button7.update();

  button8.update();

  button9.update();

  button10.update();



    long newPosition = myEnc.read();

 {   

  if (newPosition != oldPosition) {  

    //Serial.println(newPosition);

    if(newPosition-oldPosition>0)

    {

      Serial.println("A");

      Joystick.button(1,1); //falling

      Joystick.button(2,0);

    }

    else if(newPosition-oldPosition<0)

    {

      Serial.println("B");

      Joystick.button(2,1);  //falling

      Joystick.button(1,0);

    }

    oldPosition = newPosition;

  }

  else   //same position

  {

      Joystick.button(1,0);  ///riging

      Joystick.button(2,0);  ///rising

      

  }

  


long newPosition2 = myEnc2.read();

  if (newPosition2 != oldPosition2) {  

    //Serial.println(newPosition);

    if(newPosition2-oldPosition2>0)

    {

      Serial.println("C");

      Joystick.button(3,1); //falling

      Joystick.button(4,0);

    }

    else if(newPosition2-oldPosition2<0)

    {

      Serial.println("D");

      Joystick.button(4,1); 

     Joystick.button(3,0); //falling

    }

    oldPosition2 = newPosition2;

  }

  else   //same position

  {

      Joystick.button(3,0);  ///riging

      Joystick.button(4,0);  ///rising

  }

  delay(30);

}

 //------------------------------------------------------- 

  if (button4.fallingEdge()) {

    Joystick.button(5, 1);

  }

  if (button5.fallingEdge()) {

    Joystick.button(6, 1);

  }

  if (button6.fallingEdge()) {

    Joystick.button(7, 1);

  }

  if (button7.fallingEdge()) {

    Joystick.button(8, 1);

  }

  if (button8.fallingEdge()) {

    Joystick.button(9, 1);

  }

  if (button9.fallingEdge()) {

    Joystick.button(10, 1);

  }

  if (button10.fallingEdge()) {

    Joystick.button(11, 1);

  }

  

  // Check each button for "rising" edge

  // Update the Joystick buttons only upon changes.

  // rising = low (pressed - button connects pin to ground)

  //          to high (not pressed - voltage from pullup resistor)


  if (button4.risingEdge()) {

    Joystick.button(5, 0);

  }

  if (button5.risingEdge()) {

    Joystick.button(6, 0);

  }

  if (button6.risingEdge()) {

    Joystick.button(7, 0);

  }

  if (button7.risingEdge()) {

    Joystick.button(8, 0);

  }

  if (button8.risingEdge()) {

    Joystick.button(9, 0);

  }

  if (button9.risingEdge()) {

    Joystick.button(10, 0);

  }

    if (button10.risingEdge()) {

    Joystick.button(11, 0);

  }


   

}

