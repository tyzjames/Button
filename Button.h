#ifndef Button_H
#define Button_H

#include "Arduino.h"

class Button
{
  public:
    Button(int pin, int button_state);
    void init();
    bool get_short();
    bool get_status();
    void read_switch();
    bool is_pressed();
    void reset();

  private:
    int _pin;
    unsigned long _previousMillis = 0;
    unsigned long _debounce = 200;
    int _button_state;
    bool _on_press = false;
    void on_press();
};

#endif
