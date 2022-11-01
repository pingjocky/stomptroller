#include <OneButton.h>
#include <MIDI.h>

/**  Button Config
      ---------------
      | 1    2    3 |
      |             |
      |             |
      | 4    5    6 |
      ---------------
*/

// configure buttons
OneButton button1(7, true, true);
OneButton button2(6, true, true);
OneButton button3(5, true, true);
OneButton button4(2, true, true);
OneButton button5(3, true, true);
OneButton button6(4, true, true);

// Create and bind the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // button 1
  button1.attachClick(button1Press);
  button1.attachLongPressStart(button1LongPressStart);
  button1.attachDoubleClick(button1DoubleClick);

  // button 2
  button2.attachClick(button2Press);
  button2.attachLongPressStart(button2LongPressStart);

  // button 3
  button3.attachClick(button3Press);
  button3.attachLongPressStart(button3LongPressStart);
  button3.attachDoubleClick(button3DoubleClick);

  // button 4
  button4.attachClick(button4Press);
  button4.attachLongPressStart(button4LongPressStart);
  
  // button 5
  button5.attachClick(button5Press);
  button5.attachLongPressStart(button5LongPressStart);
  
  // button 6
  button6.attachClick(button6Press);
  button6.attachLongPressStart(button6LongPressStart);
  
  // MIDI setup
  MIDI.begin();
}

void loop() {
  button1.tick();
  button2.tick();
  button3.tick();
  button4.tick();
  button5.tick();
  button6.tick();

  // TODO: do we need the delay here as in the example?
}


// button 1 Events
void button1Press() {
  // Snapshot 1
  MIDI.sendControlChange(69, 0, 1);
}

void button1LongPressStart() {
  // FS4
  MIDI.sendControlChange(72, 0, 1);
}

void button1DoubleClick() {
  // 1 Switch Looper Undo/Redo
  MIDI.sendControlChange(63, 69, 1);
}


// button 2 Events
void button2Press() {
  // Snapshot 2
  MIDI.sendControlChange(69, 1, 1);
}

void button2LongPressStart() {
  // FS5
  MIDI.sendControlChange(72, 127, 1);
}

// button 3 Events
void button3Press() {
  // Snapshot 3
  MIDI.sendControlChange(69, 2, 1);
}

void button3LongPressStart() {
  // Next Footswitch Mode
  MIDI.sendControlChange(71, 4, 1);
}

void button3DoubleClick() {
  // Tuner screen on/off
  MIDI.sendControlChange(68, 69, 1);
}

// button 4 Events
void button4Press() {
  // 1 Switch Looper Record
  MIDI.sendControlChange(60, 69, 1);
}

void button4LongPressStart() {
  // 1 Switch Looper Forward
  MIDI.sendControlChange(65, 1, 1);
}

// button 5 Events
void button5Press() {
  // 1 Switch Looper Overdub
  MIDI.sendControlChange(60, 1, 1);
}

void button5LongPressStart() {
  // 1 Switch Looper Reverse
  MIDI.sendControlChange(65, 69, 1);
}

// button 6 Events
void button6Press() {
  // // 1 Switch Looper Play
  MIDI.sendControlChange(61, 69, 1);
}

void button6LongPressStart() {
  // 1 Switch Looper Stop
  MIDI.sendControlChange(61, 1, 1);
}
