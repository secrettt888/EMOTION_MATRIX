# Emotion Matrix (Matrice de Emoții)

[cite_start]This project uses an ESP32 [cite: 96] [cite_start]and an 8x8 LED Matrix (MAX7219) [cite: 97] to display different facial expressions based on physical button presses. 

[cite_start]**Authors:** Tîmpău Cristiana-Maria & Şutu Fabian [cite: 12, 13, 14]

## Features
* [cite_start]Displays four different emotions corresponding to 4 physical buttons[cite: 168, 169]: Happy, Sad, Neutral, and Surprised.
* Automatically clears the display when no buttons are pressed.
* Fully documented wiring and logic.

## [cite_start]Hardware Components [cite: 94, 95]
* [cite_start]1x ESP32 Development Board [cite: 96]
* [cite_start]1x 8x8 LED Matrix with MAX7219 Driver [cite: 97]
* [cite_start]4x Push Buttons [cite: 99]
* [cite_start]4x Pull-down Resistors [cite: 100]
* [cite_start]Breadboard & Jumper wires [cite: 98, 147]

## Pin Configuration

### MAX7219 LED Matrix
[cite_start]The matrix is controlled using the `LedControl` library via SPI-like communication:
* [cite_start]**DIN (Data In)** -> Pin 21 [cite: 157]
* [cite_start]**CLK (Clock)** -> Pin 27 [cite: 158]
* [cite_start]**CS (Chip Select)** -> Pin 32 [cite: 159]
* [cite_start]**VCC** -> 5V / 3.3V (ESP32 specific VCC) [cite: 160]
* [cite_start]**GND** -> Common Ground [cite: 160]

### Push Buttons (Input)
[cite_start]Each button is connected to an input pin and requires a pull-down resistor to GND to ensure a stable `LOW` state when not pressed[cite: 141, 142]:
* [cite_start]**Button 1 (Happy)** -> Pin 34 [cite: 27, 72, 74]
* [cite_start]**Button 2 (Sad)** -> Pin 33 [cite: 28, 76, 78]
* [cite_start]**Button 3 (Neutral)** -> Pin 15 [cite: 29, 80, 81]
* [cite_start]**Button 4 (Surprised)** -> Pin 16 [cite: 30, 88, 90]

## Software Requirements
This project was written in the Arduino IDE. You will need to install the following library via the Arduino Library Manager:
* [cite_start]**`LedControl`** (by Eberhard Fahle) - Used to control the MAX7219 matrix.

## How It Works
[cite_start]The code defines four byte arrays (`hf`, `nf`, `sf`, `rf`) containing binary representations of the faces (`1` turns an LED on, `0` leaves it off)[cite: 35, 36, 138, 139]. The `loop()` constantly checks the state of the buttons using `digitalRead()`. [cite_start]When a specific button registers a `HIGH` signal (pressed), it calls the corresponding drawing function, illuminating the specific LEDs to create the face[cite: 228, 230, 231, 233]. 
