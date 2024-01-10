# Lab 2 - Component selection.

## Lab Instructions

In this lab you will learn about electrical component selection and analysis, datasheet reading, and surface-mount soldering.

Follow the instruction written in[ Lab2: Component Selection.md](https://github.com/GIXLabs/TECHIN514_W24/blob/main/Lab2_component-selection/Lab2_component_selection.md) to:

* Generate the BOM spreadsheet using KiCAD;
* Reading the devices' datasheet and calculation the UNKNOWN values on the datasheet, then fill them in;
* Assemble the board with your chosen resistor values
* Verify the voltage output with the multimeter, and then attach your ESP32 to the outputs and read the voltage using an analog input pin.

**Some boards will be non-functional. Try to debug and fix it if you want. But its OK if you read zero volts to your ESP32.**

Some other resources:

* [KiCAD installation](https://www.kicad.org/download/)
* [Datasheets](https://github.com/GIXLabs/TECHIN514_W24/tree/main/Lab2_component-selection/datasheets)

## Lab Requirements

Assembling the SOT223 package circuit (on the left) is required and should be relatively easy.
Assembling the SOT23-5 package circuit (in the middle) is also required if your board has the footprints, and should be manageable.
Assembling the SC70 package (on the right) is completely optional but could be a fun challenge!

**Also there is AT LEAST ONE error in the schematic. Bonus points for finding it!**

## What to Submit on Canvas

- A single PDF file containing:
  - Your selected resistors and the calculations you made
    - Please be verbose about how you did the calculation, and what essential information you found from the datasheet
  - Screenshot of the exported BOM spreadsheet, with values filled in
  - A picture of your board
  - Link to github repo of your ESP32 code
  - Screenshot of the github repo of your ESP32 code
  - Screenshot of the serial output from your ESP32 (zeros are okay if you get a non-functioning board)
