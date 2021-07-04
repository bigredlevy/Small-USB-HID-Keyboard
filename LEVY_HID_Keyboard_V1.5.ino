// LEVY
// http://levysounddesign.blogspot.com/

// SMALL USB-HID KEYBOARD
// Hardware Version 2.0
// Software Version 1.5
// Created 04MAY21
// Updated 02JUL21

// DESCRIPTION:
// Software for USB HID keyboard developed for Raspberry Pi Field PC project.

// BOARDS / MODULES:
// Sparkfun pro-micro ATmega32U4 (5V, 16MHz)
// 64 key qwerty keyboard wired in 8x8 matrix (see schematic for info)

// SOFTWARE VERSION CHANGELOG:
// 1.5 - fixed issue with function keys
// 1.0 to 1.4 - initial design

// TASKS ONGOING:
// nil

// NOTE:
// Keypad library could not be implemented as it does not easily support multiple key presses.
// Caps lock and Shift key capitalisation of char keys is not implemented in this code, PC takes care of this.
// Cannot implement PAUSE button.

// INCLUDE:
#include <Keyboard.h>         //pre-installed library for HID keyboard

// CONSTANTS:
int row1 = 21;                //keypad matrix row 1
int row2 = 10;                //keypad matrix row 2
int row3 = 20;                //keypad matrix row 3
int row4 = 16;                //keypad matrix row 4
int row5 = 19;                //keypad matrix row 5
int row6 = 14;                //keypad matrix row 6
int row7 = 18;                //keypad matrix row 7
int row8 = 15;                //keypad matrix row 8

int col1 = 2;                 //keypad matrix col 1
int col2 = 3;                 //keypad matrix col 2
int col3 = 4;                 //keypad matrix col 3
int col4 = 5;                 //keypad matrix col 4
int col5 = 6;                 //keypad matrix col 5
int col6 = 7;                 //keypad matrix col 6
int col7 = 8;                 //keypad matrix col 7
int col8 = 9;                 //keypad matrix col 8

// VARIABLES:
boolean flagFn = false;       //flag for function (Fn) button

// OBJECTS:

// SETUP:
void setup() {
  //Serial.begin(9600);         //DEBUG ONLY Start serial communication.

  pinMode(row1, OUTPUT);        //set row pin output
  pinMode(row2, OUTPUT);        //set row pin output
  pinMode(row3, OUTPUT);        //set row pin output
  pinMode(row4, OUTPUT);        //set row pin output
  pinMode(row5, OUTPUT);        //set row pin output
  pinMode(row6, OUTPUT);        //set row pin output
  pinMode(row7, OUTPUT);        //set row pin output
  pinMode(row8, OUTPUT);        //set row pin output

  digitalWrite(row1, HIGH);     //digital write row pin high
  digitalWrite(row2, HIGH);     //digital write row pin high
  digitalWrite(row3, HIGH);     //digital write row pin high
  digitalWrite(row4, HIGH);     //digital write row pin high
  digitalWrite(row5, HIGH);     //digital write row pin high
  digitalWrite(row6, HIGH);     //digital write row pin high
  digitalWrite(row7, HIGH);     //digital write row pin high
  digitalWrite(row8, HIGH);     //digital write row pin high

  pinMode(col1, INPUT_PULLUP);  //set col pin input pullup
  pinMode(col2, INPUT_PULLUP);  //set col pin input pullup
  pinMode(col3, INPUT_PULLUP);  //set col pin input pullup
  pinMode(col4, INPUT_PULLUP);  //set col pin input pullup
  pinMode(col5, INPUT_PULLUP);  //set col pin input pullup
  pinMode(col6, INPUT_PULLUP);  //set col pin input pullup
  pinMode(col7, INPUT_PULLUP);  //set col pin input pullup
  pinMode(col8, INPUT_PULLUP);  //set col pin input pullup

  Keyboard.begin();             //Start USB HID keyboard

}

// PROGRAM MAIN LOOP:
void loop() {

  //TEST KEYS                                     //[row][col] <key> / <functionKey>

  digitalWrite(row1, LOW);                        //START TEST ROW 1 - digital write low row 1

  if (digitalRead(col1) == 0) {                   //[1][1] '`'
    Keyboard.press('`');
  } else {
    Keyboard.release('`');
  }

  if (digitalRead(col2) == 0) {                   //[1][2] '1' / F1
    if (flagFn == false) Keyboard.press('1');
    if (flagFn == true) Keyboard.press(KEY_F1);
  } else {
    Keyboard.release('1');
    Keyboard.release(KEY_F1);
  }

  if (digitalRead(col3) == 0) {                   //[1][3] '2' / F2
    if (flagFn == false) Keyboard.press('2');
    if (flagFn == true) Keyboard.press(KEY_F2);
  } else {
    Keyboard.release('2');
    Keyboard.release(KEY_F2);
  }

  if (digitalRead(col4) == 0) {                   //[1][4] '3' / F3
    if (flagFn == false) Keyboard.press('3');
    if (flagFn == true) Keyboard.press(KEY_F3);
  } else {
    Keyboard.release('3');
    Keyboard.release(KEY_F3);
  }

  if (digitalRead(col5) == 0) {                   //[1][5] '4' / F4
    if (flagFn == false) Keyboard.press('4');
    if (flagFn == true) Keyboard.press(KEY_F4);
  } else {
    Keyboard.release('4');
    Keyboard.release(KEY_F4);
  }

  if (digitalRead(col6) == 0) {                   //[1][6] '5' / F5
    if (flagFn == false) Keyboard.press('5');
    if (flagFn == true) Keyboard.press(KEY_F5);
  } else {
    Keyboard.release('5');
    Keyboard.release(KEY_F5);
  }

  if (digitalRead(col7) == 0) {                   //[1][7] '6' / F6
    if (flagFn == false) Keyboard.press('6');
    if (flagFn == true) Keyboard.press(KEY_F6);
  } else {
    Keyboard.release('6');
    Keyboard.release(KEY_F6);
  }

  if (digitalRead(col8) == 0) {                   //[1][8] ESC
    Keyboard.press(KEY_ESC);
  } else {
    Keyboard.release(KEY_ESC);
  }

  digitalWrite(row1, HIGH);                       //END TEST ROW 1 - digital write high row 1

  digitalWrite(row2, LOW);                        //START TEST ROW 2 - digital write low row 2

  if (digitalRead(col1) == 0) {                   //[2][1] BACKSPACE
    Keyboard.press(KEY_BACKSPACE);
  } else {
    Keyboard.release(KEY_BACKSPACE);
  }

  if (digitalRead(col2) == 0) {                   //[2][2] '=' / F12
    if (flagFn == false) Keyboard.press('=');
    if (flagFn == true) Keyboard.press(KEY_F12);
  } else {
    Keyboard.release('=');
    Keyboard.release(KEY_F12);
  }

  if (digitalRead(col3) == 0) {                   //[2][3] '-' / F11
    if (flagFn == false) Keyboard.press('-');
    if (flagFn == true) Keyboard.press(KEY_F11);
  } else {
    Keyboard.release('-');
    Keyboard.release(KEY_F11);
  }

  if (digitalRead(col4) == 0) {                   //[2][4] '0' / F10
    if (flagFn == false) Keyboard.press('0');
    if (flagFn == true) Keyboard.press(KEY_F10);
  } else {
    Keyboard.release('0');
    Keyboard.release(KEY_F10);
  }

  if (digitalRead(col5) == 0) {                   //[2][5] '9' / F9
    if (flagFn == false) Keyboard.press('9');
    if (flagFn == true) Keyboard.press(KEY_F9);
  } else {
    Keyboard.release('9');
    Keyboard.release(KEY_F9);
  }

  if (digitalRead(col6) == 0) {                   //[2][6] '8' / F8
    if (flagFn == false) Keyboard.press('8');
    if (flagFn == true) Keyboard.press(KEY_F8);
  } else {
    Keyboard.release('8');
    Keyboard.release(KEY_F8);
  }

  if (digitalRead(col7) == 0) {                   //[2][7] '7' / F7
    if (flagFn == false) Keyboard.press('7');
    if (flagFn == true) Keyboard.press(KEY_F7);
  } else {
    Keyboard.release('7');
    Keyboard.release(KEY_F7);
  }

  if (digitalRead(col8) == 0) {                   //[2][8] INSERT / PRINT SCREEN (ASCII 206)
    if (flagFn == false) Keyboard.press(KEY_INSERT);
    if (flagFn == true) Keyboard.press(206);
  } else {
    Keyboard.release(KEY_INSERT);
    Keyboard.release(206);
  }

  digitalWrite(row2, HIGH);                       //END TEST ROW 2 - digital write high row 2

  digitalWrite(row3, LOW);                        //START TEST ROW 3 - digital write low row 3

  if (digitalRead(col1) == 0) {                   //[3][1] TAB
    Keyboard.press(KEY_TAB);
  } else {
    Keyboard.release(KEY_TAB);
  }

  if (digitalRead(col2) == 0) {                   //[3][2] 'q'
    Keyboard.press('q');
  } else {
    Keyboard.release('q');
  }

  if (digitalRead(col3) == 0) {                   //[3][3] 'w'
    Keyboard.press('w');
  } else {
    Keyboard.release('w');
  }

  if (digitalRead(col4) == 0) {                   //[3][4] 'e'
    Keyboard.press('e');
  } else {
    Keyboard.release('e');
  }

  if (digitalRead(col5) == 0) {                   //[3][5] 'r'
    Keyboard.press('r');
  } else {
    Keyboard.release('r');
  }

  if (digitalRead(col6) == 0) {                   //[3][6] 't'
    Keyboard.press('t');
  } else {
    Keyboard.release('t');
  }

  if (digitalRead(col7) == 0) {                   //[3][7] 'y'
    Keyboard.press('y');
  } else {
    Keyboard.release('y');
  }

  if (digitalRead(col8) == 0) {                   //[3][8] COMMAND/WINDOWS
    Keyboard.press(KEY_LEFT_GUI);
  } else {
    Keyboard.release(KEY_LEFT_GUI);
  }

  digitalWrite(row3, HIGH);                       //END TEST ROW 3 - digital write high row 3

  digitalWrite(row4, LOW);                        //START TEST ROW 4 - digital write low row 4

  if (digitalRead(col1) == 0) {                   //[4][1] BACKSLASH (ASCII 92)
    Keyboard.press(92);
  } else {
    Keyboard.release(92);
  }

  if (digitalRead(col2) == 0) {                   //[4][2] ']'
    Keyboard.press(']');
  } else {
    Keyboard.release(']');
  }

  if (digitalRead(col3) == 0) {                   //[4][3] '['
    Keyboard.press('[');
  } else {
    Keyboard.release('[');
  }

  if (digitalRead(col4) == 0) {                   //[4][4] 'p'
    Keyboard.press('p');
  } else {
    Keyboard.release('p');
  }

  if (digitalRead(col5) == 0) {                   //[4][5] 'o'
    Keyboard.press('o');
  } else {
    Keyboard.release('o');
  }

  if (digitalRead(col6) == 0) {                   //[4][6] 'i'
    Keyboard.press('i');
  } else {
    Keyboard.release('i');
  }

  if (digitalRead(col7) == 0) {                   //[4][7] 'u'
    Keyboard.press('u');
  } else {
    Keyboard.release('u');
  }

  if (digitalRead(col8) == 0) {                   //[4][8] DELETE / PAUSE
    if (flagFn == false) Keyboard.press(KEY_DELETE);
    if (flagFn == true);  //nop - could not implement PAUSE
  } else {
    Keyboard.release(KEY_DELETE);
  }

  digitalWrite(row4, HIGH);                       //END TEST ROW 4 - digital write high row 4

  //5x
  digitalWrite(row5, LOW);                        //START TEST ROW 5 - digital write low row 5

  if (digitalRead(col1) == 0) {                   //[5][1] CAPS LOCK
    Keyboard.press(KEY_CAPS_LOCK);
  } else {
    Keyboard.release(KEY_CAPS_LOCK);
  }

  if (digitalRead(col2) == 0) {                   //[5][2] 'a'
    Keyboard.press('a');
  } else {
    Keyboard.release('a');
  }

  if (digitalRead(col3) == 0) {                   //[5][3] 's'
    Keyboard.press('s');
  } else {
    Keyboard.release('s');
  }

  if (digitalRead(col4) == 0) {                   //[5][4] 'd'
    Keyboard.press('d');
  } else {
    Keyboard.release('d');
  }

  if (digitalRead(col5) == 0) {                   //[5][5] 'f'
    Keyboard.press('f');
  } else {
    Keyboard.release('f');
  }

  if (digitalRead(col6) == 0) {                   //[5][6] 'g'
    Keyboard.press('g');
  } else {
    Keyboard.release('g');
  }

  if (digitalRead(col7) == 0) {                   //[5][7] 'h'
    Keyboard.press('h');
  } else {
    Keyboard.release('h');
  }

  if (digitalRead(col8) == 0) {                   //[5][8] FUNCTION
    flagFn = true;    //set function flag
  } else {
    flagFn = false;   //reset function flag
  }

  digitalWrite(row5, HIGH);                       //END TEST ROW 5 - digital write high row 5

  //6x
  digitalWrite(row6, LOW);                        //START TEST ROW 6 - digital write low row 6

  if (digitalRead(col1) == 0) {                   //[6][1] RETURN
    Keyboard.press(KEY_RETURN);
  } else {
    Keyboard.release(KEY_RETURN);
  }

  if (digitalRead(col2) == 0) {                   //[6][2] UP ARROW / PAGE UP
    if (flagFn == false) Keyboard.press(KEY_UP_ARROW);
    if (flagFn == true) Keyboard.press(KEY_PAGE_UP);
  } else {
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.release(KEY_PAGE_UP);
  }

  if (digitalRead(col3) == 0) {                   //[6][3] APOSTROPHE (ASCII 39)
    Keyboard.press(39);
  } else {
    Keyboard.release(39);
  }

  if (digitalRead(col4) == 0) {                   //[6][4] ';'
    Keyboard.press(';');
  } else {
    Keyboard.release(';');
  }

  if (digitalRead(col5) == 0) {                   //[6][5] 'l'
    Keyboard.press('l');
  } else {
    Keyboard.release('l');
  }

  if (digitalRead(col6) == 0) {                   //[6][6] 'k'
    Keyboard.press('k');
  } else {
    Keyboard.release('k');
  }

  if (digitalRead(col7) == 0) {                   //[6][7] 'j'
    Keyboard.press('j');
  } else {
    Keyboard.release('j');
  }

  if (digitalRead(col8) == 0) {                   //[6][8] ALT
    Keyboard.press(KEY_LEFT_ALT);
  } else {
    Keyboard.release(KEY_LEFT_ALT);
  }

  digitalWrite(row6, HIGH);                       //END TEST ROW 6 - digital write high row 6

  //7x
  digitalWrite(row7, LOW);                        //START TEST ROW 7 - digital write low row 7

  if (digitalRead(col1) == 0) {                   //[7][1] SHIFT
    Keyboard.press(KEY_LEFT_SHIFT);
  } else {
    Keyboard.release(KEY_LEFT_SHIFT);
  }

  if (digitalRead(col2) == 0) {                   //[7][2] 'z'
    Keyboard.press('z');
  } else {
    Keyboard.release('z');
  }

  if (digitalRead(col3) == 0) {                   //[7][3] 'x'
    Keyboard.press('x');
  } else {
    Keyboard.release('x');
  }

  if (digitalRead(col4) == 0) {                   //[7][4] 'c'
    Keyboard.press('c');
  } else {
    Keyboard.release('c');
  }

  if (digitalRead(col5) == 0) {                   //[7][5] 'v'
    Keyboard.press('v');
  } else {
    Keyboard.release('v');
  }

  if (digitalRead(col6) == 0) {                   //[7][6] 'b'
    Keyboard.press('b');
  } else {
    Keyboard.release('b');
  }

  if (digitalRead(col7) == 0) {                   //[7][7] 'n'
    Keyboard.press('n');
  } else {
    Keyboard.release('n');
  }

  if (digitalRead(col8) == 0) {                   //[7][8] CTRL
    Keyboard.press(KEY_LEFT_CTRL);
  } else {
    Keyboard.release(KEY_LEFT_CTRL);
  }

  digitalWrite(row7, HIGH);                       //END TEST ROW 7 - digital write high row 7

  //8x
  digitalWrite(row8, LOW);                        //START TEST ROW 8 - digital write low row 8

  if (digitalRead(col1) == 0) {                   //[8][1] RIGHT ARROW / END
    if (flagFn == false) Keyboard.press(KEY_RIGHT_ARROW);
    if (flagFn == true) Keyboard.press(KEY_END);
  } else {
    Keyboard.release(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_END);
  }

  if (digitalRead(col2) == 0) {                   //[8][2] DOWN ARROW / PAGE DOWN
    if (flagFn == false) Keyboard.press(KEY_DOWN_ARROW);
    if (flagFn == true)  Keyboard.press(KEY_PAGE_DOWN);
  } else {
    Keyboard.release(KEY_DOWN_ARROW);
    Keyboard.release(KEY_PAGE_DOWN);
  }

  if (digitalRead(col3) == 0) {                   //[8][3] LEFT ARROW / HOME
    if (flagFn == false) Keyboard.press(KEY_LEFT_ARROW);
    if (flagFn == true) Keyboard.press(KEY_HOME);
  } else {
    Keyboard.release(KEY_LEFT_ARROW);
    Keyboard.release(KEY_HOME);
  }

  if (digitalRead(col4) == 0) {                   //[8][4] '/'
    Keyboard.press('/');
  } else {
    Keyboard.release('/');
  }

  if (digitalRead(col5) == 0) {                   //[8][5] '.'
    Keyboard.press('.');
  } else {
    Keyboard.release('.');
  }

  if (digitalRead(col6) == 0) {                   //[8][6] ','
    Keyboard.press(',');
  } else {
    Keyboard.release(',');
  }

  if (digitalRead(col7) == 0) {                   //[8][7] 'm'
    Keyboard.press('m');
  } else {
    Keyboard.release('m');
  }

  if (digitalRead(col8) == 0) {                   //[8][8] SPACE
    Keyboard.press(' ');
  } else {
    Keyboard.release(' ');
  }

  digitalWrite(row8, HIGH);                       //END TEST ROW 8 - digital write high row 8
}

// REFERENCE:
//links go here
// Keyboard Library - https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
// Key Modifiers - https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
