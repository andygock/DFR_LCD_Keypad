
# LCD and Keypad Library for DFRobot LCD Keypad Arduino Shield

- [Blog post](https://gock.net/blog/2013/arduino-library-for-df-robot-16x2-lcd-keypad-shield/)
- [Compatible Shield](https://wiki.dfrobot.com/LCD_KeyPad_Shield_For_Arduino_SKU__DFR0009)

## Installation

To install, it simply copy the `DFR_LCD_Keypad` directory into the `libraries/` directory. This libraries directory on Windows by default is `c:\Users\USERNAME\Documents\Arduino\libraries\`.

Start Arduino and you should be able to open the example from the menu.

This has been tested on Arduino 1.8.16 IDE.

## Pin 10 bug

*Update: This existed in 2013, but haven't checked this in 2021.*

Just one thing to mention, they all happen to have a flaw in the design, so **don’t use pin 10** when using this shield. The library has functions to enable and disable the backlight. But in the design, a flaw exists, that when pin 10 is set to output, and set high, it could cause the IO pin of the MCU (the main Atmel chip) to deliver too much current (over the datasheet’s maximum rating) to the backlight LED. This may cause the over stressing of the MCU and may reduce its life, or maybe even blow it up.

- To set the backlight on, set pin 10 as input.
- To set the backlight off, set pin 10 as output, and *immediately* set output low (never high!)

For more information, there is discussion [on the Arduino forums](https://arduino.cc/forum/index.php?topic=96747.0) about this.
