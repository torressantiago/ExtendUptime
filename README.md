# ExtendUptime
This project implements a bare metal to extend a logic high using ATMEGA328p.

## Setup
The setup uses INT0 (pin 2 in Arduino UNO), a digital port which can be set to detect a rising edge and generate an interrupt as result. This interrupt the toggles an arbitrary output pin, which is set here to PORTB5 (pin 13 in Arduino UNO). Once the state of the output pin has been toggled, a timer is set to 2 Hz. Once the timer reaches its end, it will generate an interrupt that will reset the timer to stop interrupting itself and set to low the output pin's state. A setup to test this code can be found below.

![setup](Doc/HighLevelSchematic.png)

You can test this setup @: https://www.tinkercad.com/things/3YCzbEGLNoQ-smashing-gogo-bruticus/editel?sharecode=QqdjqGblJZ84lZONKK-AdAIN6XaM14Qd_Lhm7XkvtmE