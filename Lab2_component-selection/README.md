Lab 2 - Component selection.

This lab has two sections. 

The first part is analytical, using the regulators schamtic. 

You'll choose the necessary resistors to adjust output voltage of your regulators and a matching current-limiting resistors for your LEDs. 

Geneate a BOM using KiCAD, save to a CSV, update the missing resistor values, and upload a copy of your spreadsheet with the correct resistor values. 

Also upload a description of how you calculated your values. 

The second part is physical, the goal here is to be familiar with the component packages you might be using in your designs. 

Assemble the board with your chosen resistor values, verify with the multimeter that you have correct output voltage or that your board is non-functional.  Connect to the analog pin of an ESP32 and read the voltage.  

For your regulators, set the first output voltage to 3V + 0.01 * the day of the month you were born.  So if you were born on the 15th, you should set the voltage to 3.15V

For the second output voltage, add 0.1 to the first output voltage.   So if you were born on the 15th, set it to 3.25V

AFTER checking them with the multimeter, you are going to attach your ESP32 to the outputs and read the voltage using an analog input pin.

some boards will be non-functional.  try to debug and fix it if you want.  but its OK if you read zero volts to your ESP32. 

Assembling the SOT223 package circuit is required and should be relatively easy.  
Assembling the SOT23-5 package circuit is also required if your board has the footprints, and should be manageable. 
Assembling the SC70 package is completely optional but could be a fun challenge!

Also there is at least one error in the schematic.  Bonus points for finding it!

Please upload to canvas :

Your selected resistors and the calculations you made (any format is OK, e.g. screenshot of spreadsheet)
    A picture of your board
    Link to github repo of your ESP32 code
    Screenshot of the github repo of your ESP32 code
    screenshot of the serial output from your ESP32
