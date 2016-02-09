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
    bool is_pressed(int inDebounce);
    bool is_released(int inDebounce);
    void reset();
    void set_debounce(int inDebounce);
    void set_status(bool inType);

  private:
    int _pin;
    unsigned long _previousMillis = 0;
    unsigned long _debounce = 200;
    int _button_state;
    bool _on_press = false;
    void on_press();
};

#endif
