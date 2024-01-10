# Lab 2 - Component selection.

## Lab Instructions

This lab has two sections:

The first part is analytical, using the regulators schamtic.

- You'll choose the necessary resistors to adjust output voltage of your regulators and a matching current-limiting resistors for your LEDs.
  - For your regulators, set the first output voltage (VOUT1) to 3V + 0.01 * the day of the month you were born. So if you were born on the 15th, you should set the voltage to 3.15V
  - For the second output voltage (VOUT2), add 0.1 to the first output voltage. So if you were born on the 15th, set it to 3.25V
- Geneate a BOM using KiCAD, save to a CSV, update the missing resistor values, and upload a copy of your spreadsheet with the correct resistor values.
- Also upload a description of how you calculated your values.

The second part is physical, the goal here is to be familiar with the component packages you might be using in your designs.

- Assemble the board with your chosen resistor values, verify with the multimeter that you have correct output voltage or that your board is non-functional.  Connect to the analog pin of an ESP32 and read the voltage.
- AFTER checking them with the multimeter, you are going to attach your ESP32 to the outputs and read the voltage using an analog input pin.
- Some boards will be non-functional.  try to debug and fix it if you want.  but its OK if you read zero volts to your ESP32.

## Requirements

Assembling the SOT223 package circuit (on the left) is required and should be relatively easy.
Assembling the SOT23-5 package circuit (in the middle) is also required if your board has the footprints, and should be manageable.
Assembling the SC70 package (on the right) is completely optional but could be a fun challenge!

Also there is at least one error in the schematic.  Bonus points for finding it!

## What to Submit on Canvas

- A single PDF file containing:
  - Your selected resistors and the calculations you made
    - Please be verbose about how you did the calculation, and what essential information you found from the datasheet
  - Screenshot of the exported BOM spreadsheet, with values filled in
- A picture of your board
- Link to github repo of your ESP32 code
- Screenshot of the github repo of your ESP32 code
- Screenshot of the serial output from your ESP32 (zeros are okay if you get a non-functioning board)
