# Button
Read an input switch on an Arduino pin and determine the press status

<h2>Steps</h2>
- Initialize the switch
```c++
Button pb1(pin, button_state, read_type)
```
Type|Parameter|Description
---|---|---
int|pin| Pin number the switch is connected to.
int|button_state| Set the initial state of the pin (HIGH or LOW). Default HIGH.
boolean|read_type | If true, switch will read long presses.

- Read switch status
```c++

#include <Button.h>
#define SW1 5

Button pb1 (SW1, HIGH, false);

setup(){

}

loop() {

  //Read switch here. Create function to read multiple switches if necessary
  pb1.read_switch();

  if (pb1.get_long()) {
    Serial.println("long press");
  } else if (pb1.get_short()) {
    Serial.println("short press");
  }

  //Reset switch here to clear values
  pb1.reset();

}
```
This reads any switch state changes. Call **get_long()** to get the boolean value if the switch is held down (500ms default) and **get_short()** to get the boolean value if the switch has been pressed down.

If read_type == true, short presses will only be read on-release instead of on-press.

- Read multiple switch press

To read multiple switches, see example:
```c++

#include <Button.h>
#define SW1 5
#define SW2 6

Button pb1 (SW1, HIGH, false);
Button pb2 (SW2, HIGH, false);

Button arr_pb[] = {pb1, pb2); //Add switches into an array

setup(){
  Serial.begin(9600);
}

loop() {

  //Read switch here. Create function to read multiple switches if necessary
  read_switches();

  if (arr_pb[0].get_short() && arr_pb[1].get_short()){
    Serial.println("SW1 & SW2 pressed");
  } else if (arr_pb[0].get_short()){
    Serial.println("SW1 pressed");
  } else if (arr_pb[1].get_short()){
    Serial.println("SW2 pressed");
  }

}

// To read the status of multiple switches/
void read_switches(){

  //Reset all switch values before reading
  reset_switches();

  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 5; i++){
      arr_pb[i].read_switch();
      delayMicroseconds(8);
    }

    for (int i = 4; i >= 0; i--){
      arr_pb[i].read_switch();
      delayMicroseconds(8);
    }
  }
}

// Reset all switch values
void reset_switches(){
  for (int i = 0; i < 5; i++){
    arr_pb[i].reset();
  }
}

```
