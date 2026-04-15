# Arduino Pin Guide and Upload Steps

This project uses buttons, LEDs, and a buzzer to build a simple binary calculator.

## Pin Mapping

### Buttons (Input Pullup)
- firstNumberButton: pin 2
- secondNumberButton: pin 3
- signButton: pin 4
- resultButton: pin 5

### Buzzer
- buzzerPin: pin 7

### Result LEDs (5-bit)
- ledPins[0]: pin 9
- ledPins[1]: pin 10
- ledPins[2]: pin 11
- ledPins[3]: pin 12
- ledPins[4]: pin 13

### Second Number LEDs (4-bit)
- SecondNumberPins[0]: pin 31
- SecondNumberPins[1]: pin 33
- SecondNumberPins[2]: pin 35
- SecondNumberPins[3]: pin 37

### First Number LEDs (4-bit)
- FirstNumberPins[0]: pin 39
- FirstNumberPins[1]: pin 41
- FirstNumberPins[2]: pin 43
- FirstNumberPins[3]: pin 45

### Sign LED
- signPin: pin 47

## How to Upload in Arduino IDE

1. Open Arduino IDE.
2. Click File > Open.
3. Select the project sketch file: main.ino.
4. Connect your Arduino board to your Mac using USB.
5. In Arduino IDE, go to Tools > Board and choose your board model.
6. Go to Tools > Port and choose the correct USB port for your board.
7. Click the Verify button (check mark) to compile.
8. Click the Upload button (right arrow).
9. Wait for the message that upload is complete.

## Quick Wiring Note for the Buzzer

- Connect buzzer positive (+) to pin 7.
- Connect buzzer negative (-) to GND.
- If your buzzer needs more current than a pin can safely provide, use a transistor driver.

## Project Behavior Summary

- Press first number button to count first value (0 to 15).
- Press second number button to count second value (0 to 15).
- Press sign button to toggle operation:
	- Off = addition
	- On = subtraction
- Press result button to calculate and show result on result LEDs.


