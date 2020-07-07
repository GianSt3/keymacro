#include <Keyboard.h>

// yellow - 2 - (RIGHT)
// orange - 3 - (DOWN)
// red - 4 (LEFT)
// purple - 5 special_right
// blue - 6 (UP)
// green - 7 special_left


int wLeft = 4;
int wDown = 3;
int wRight = 2;
int wUp = 6;

int wModLeft = 7;
int wModRight = 5;

int myDelay = 150;

bool pressed = false;

void setup() {
  pinMode(wLeft, INPUT_PULLUP);
  pinMode(wDown, INPUT_PULLUP);
  pinMode(wRight, INPUT_PULLUP);
  pinMode(wUp, INPUT_PULLUP);
  pinMode(wModLeft, INPUT_PULLUP);
  pinMode(wModRight, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {

  if (digitalRead(wLeft) == LOW) {
    Keyboard.write(KEY_LEFT_ARROW);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(wDown) == LOW) {
    Keyboard.write(KEY_DOWN_ARROW);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(wRight) == LOW) {
    Keyboard.write(KEY_RIGHT_ARROW);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(wUp) == LOW) {
    Keyboard.write(KEY_UP_ARROW);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(wModLeft) == LOW) {
    Keyboard.write(KEY_HOME);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(wModRight) == LOW) {
    Keyboard.write(KEY_END);
    delay(myDelay);
    pressed = true;
  }
  
  if (pressed) {
    myDelay = 42;
    pressed = false;
  } else {
    myDelay = 150;
  }
}
