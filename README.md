# 🎭 Emotion Matrix

This is an interactive project built with an ESP32 and an 8x8 LED Matrix (MAX7219) that displays different facial expressions based on physical button presses.

👩‍💻 **Authors:** [ Țîmpău Cristiana-Maria &Șutu Fabian ]

## ✨ Features
* Displays four different emotions corresponding to the 4 buttons: Happy, Sad, Neutral, and Surprised.
* Automatically clears the screen (turns off the LEDs) when no buttons are pressed.

## 🛠️ Hardware Components
The following components were used to build this circuit:
* 1x ESP32 Development Board
* 1x 8x8 LED Matrix with MAX7219 driver
* 4x Push buttons
* 4x Resistors (used as pull-down resistors to avoid short circuits)
* Breadboard and jumper wires

## 🔌 Pin Configuration (Pinout)

### MAX7219 LED Matrix
The matrix communicates with the ESP32 using the following pins:
* **DIN (Data In)** ➡️ Pin 21
* **CLK (Clock)** ➡️ Pin 27
* **CS (Chip Select)** ➡️ Pin 32

### Buttons (Input)
Each button is connected to the power source, an input pin, and to Ground (GND) through a resistor:
* 🟢 **Button 1 (Happy)** ➡️ Pin 34
* 🔵 **Button 2 (Sad)** ➡️ Pin 33
* 🟡 **Button 3 (Neutral)** ➡️ Pin 15
* 🔴 **Button 4 (Surprised)** ➡️ Pin 16

## 💻 Software
The code was developed using the Arduino IDE. To run this code, you will need the following libraries:
* **`LedControl`** - Used to control the MAX7219 matrix lighting.
* **`binary.h`** - Used to define the face shapes through predefined binary values (0 and 1).
