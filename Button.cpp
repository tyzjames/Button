#include "Arduino.h"
#include "Button.h"


Button::Button(int pin, int button_state)
{
  this->_pin = pin;
  pinMode(this->_pin, INPUT);
  digitalWrite(this->_pin, button_state);

}

void Button::on_press()
{
  if (digitalRead(this->_pin) == LOW && millis() - this->_previousMillis > this->_debounce) {
      this->_previousMillis = millis();
      this->_on_press = true;
  }
}

bool Button::is_pressed()
{
  if (digitalRead(this->_pin) == LOW && millis() - this->_previousMillis > this->_debounce) {
      this->_previousMillis = millis();
      return true;
  }
  return false;
}

void Button::set_status(bool inType) {
  this->_on_press = true;
}

bool Button::is_pressed(int inDebounce)
{
  if (digitalRead(this->_pin) == LOW && millis() - this->_previousMillis > inDebounce) {
      this->_previousMillis = millis();
      return true;
  }
  return false;
}

bool Button::is_released(int inDebounce) {
  if (digitalRead(this->_pin) == HIGH && millis() - this->_previousMillis > inDebounce) {
      this->_previousMillis = millis();
      return true;
  }
  return false;
}

void Button::read_switch(){
    on_press();
}

bool Button::get_short(){
  return this->_on_press;
}

bool Button::get_status() {
  if (digitalRead(this->_pin) == LOW) {
      return true;
  }

  return false;
}

void Button::reset(){
  this->_on_press = false;
}

void Button::set_debounce(int inDebounce) {
  this->_debounce = inDebounce;
}
