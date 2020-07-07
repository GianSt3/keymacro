#include <Keyboard.h>

// yellow - 2 - (RIGHT)
// orange - 3 - (DOWN)
// red - 4 (LEFT)
// purple - 5 special_right
// blue - 6 (UP)
// green - 7 special_left

enum buttons {
  left = 4,
  down = 3,
  right = 2,
  up = 6,
  modLeft = 7,
  modRight = 5
};

int myDelay = 150;

bool pressed = false;

void setup() {
  pinMode(buttons::left, INPUT_PULLUP);
  pinMode(buttons::down, INPUT_PULLUP);
  pinMode(buttons::right, INPUT_PULLUP);
  pinMode(buttons::up, INPUT_PULLUP);
  pinMode(buttons::modLeft, INPUT_PULLUP);
  pinMode(buttons::modRight, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {

  if (digitalRead(buttons::left) == LOW) {
    Keyboard.write(KEY_LEFT_ARROW);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(buttons::down) == LOW) {
    Keyboard.write(KEY_DOWN_ARROW);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(buttons::right) == LOW) {
    Keyboard.write(KEY_RIGHT_ARROW);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(buttons::up) == LOW) {
    Keyboard.write(KEY_UP_ARROW);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(buttons::modLeft) == LOW) {
    Keyboard.write(KEY_HOME);
    delay(myDelay);
    pressed = true;
  }
  if (digitalRead(buttons::modRight) == LOW) {
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
