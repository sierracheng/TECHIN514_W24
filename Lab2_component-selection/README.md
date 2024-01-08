Lab 2 - Component selection.

You'll choose the necessary resistors to adjust output voltage of your regulators and a matching ballast resistor for your LEDs, assemble to the board, and verify with multimeter that you have the correct output voltage.

For your regulators, set the first output voltage to 3V + 0.01 * the day of the month you were born.  So if you were born on the 15th, you should set the voltage to 3.15V

For the second output voltage, add 0.1 to the first output voltage.   So if you were born on the 15th, set it to 3.25V

AFTER checking them with the multimeter, you are going to attach your ESP32 to the outputs and read the voltage using an analog input pin.

Assembling the SC70 package is completely optional but could be a fun challenge!

Also there is at least one error in the schematic.  Bonus points for finding it!

Please upload to canvas :

Your selected resistors and the calculations you made (any format is OK, e.g. screenshot of spreadsheet)
    A picture of your board
    Link to github repo of your ESP32 code
    Screenshot of the github repo of your ESP32 code
    screenshot of the serial output from your ESP32
