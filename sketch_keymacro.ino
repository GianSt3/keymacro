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
    keyboardWrite(KEY_LEFT_ARROW);
  }
  if (digitalRead(buttons::down) == LOW) {
    keyboardWrite(KEY_DOWN_ARROW);
  }
  if (digitalRead(buttons::right) == LOW) {
    keyboardWrite(KEY_RIGHT_ARROW);
  }
  if (digitalRead(buttons::up) == LOW) {
    keyboardWrite(KEY_UP_ARROW);
  }
  if (digitalRead(buttons::modLeft) == LOW) {
    keyboardWrite(KEY_HOME);
  }
  if (digitalRead(buttons::modRight) == LOW) {
    keyboardWrite(KEY_END);
  }

  if (pressed) {
    myDelay = 42;
    pressed = false;
  } else {
    myDelay = 150;
  }
}

void keyboardWrite(char key) {
  Keyboard.write(key);
  delay(myDelay);
  pressed = true;
}
