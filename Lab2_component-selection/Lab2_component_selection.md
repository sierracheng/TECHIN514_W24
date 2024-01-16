## Lab 2: Component Selection and Surface Mount Soldering

**This lab has two sections: analytical and physical**

## Lab Prerequisites

Before this lab, make sure you have the following ready:

* KiCAD installation on your laptop for PCB design
* **USB-C cable**: Make sure you can connect ESP32 to your laptop

## Section 1: analyse and component selection

The first part is analytical, using the regulators schamtic.

Step 1: Geneate a BOM using KiCAD and save to a CSV

1. Open the file *regulators.kicad_pro* with KiCAD, and double-click the _sch tab

   ![1704914601583](image/Lab2_component_selection/1704914601583.png)
2. Then click Tool -> Generate BOM to generate the spreadsheet:

   ![1704914658150](image/Lab2_component_selection/1704914658150.png)
3. Select *bom_csv_grouped_extra* on the left then click *Generate
   ![1704914833159](image/Lab2_component_selection/1704914833159.png)*
4. The file should appear under the same directory as the schematic file, showing on the screen
   ![1704914904565](image/Lab2_component_selection/1704914904565.png)
5. Open the CSV file, and fill in all UNKNOWN values based on your calculation mentioned below:
   ![1704914966570](image/Lab2_component_selection/1704914966570.png)

Step 2: Datasheet reading, calculation, and component selection

* You'll choose the necessary resistors to adjust output voltage of your regulators and a matching current-limiting resistors for your LEDs.
  * For your regulators, set the first output voltage (VOUT1, on the left) to 2V + 0.01 * the day of the month you were born. So if you were born on the 15th, you should set the voltage to 2.15V;
  * For the second output voltage (VOUT2, in the middle), add 0.1 to the first output voltage. So if you were born on the 15th, set it to 2.25V;
  * For the third output voltage (VOUT3, on the right), set it to the same voltage as VOUT2.

Here's a brief instruction about how to read a datasheet, using the LM317 regulator as an example:

1. Check the Terminal Configuration and Functions to know what pins are for on this device;
2. Check the Speficiations (Specs), especially Absolute Maximum Ratings of the device. This will ensure you won't destroy the device with high voltage/current;
   ![1704915396628](image/Lab2_component_selection/1704915396628.png)
3. For regulators, there will be a section of *Application and Implementation* to demonstrate how to assemble it with resistors and capacitors. Typically, there should be an equation about how the output voltage is set: **the selection of the resistors will affect the output voltage**, and this is what your calculation should aim for
   ![1704915523873](image/Lab2_component_selection/1704915523873.png)

   There could be other details on the datasheet that might help your component selection. Please check them out carefully.

**For circuits with LEDs and resistors in serial, make sure you select a suitable resistor that will make the current forward (If) in a suitable range.**

# ESP32 Voltage Measurement Exercise

The second part is physical, the goal here is to be familiar with the component packages you might be using in your designs.

## Instructions

Here is the PCB layout with the same device names as the schematics:
![]()![1704936122514](image/Lab2_component_selection/1704936122514.png)![]()![]()

### Connect to ESP32 and Read Voltage

- Connect the PCB output to an analog pin on the ESP32.
- Program the ESP32 to read the analog value from this pin.
- It's acceptable for some boards to be non-functional or read zero volts.

### Convert ADC Values to Voltage

- The ESP32 ADC provides values between 0 and 4095. Convert these to voltage readings.
- Use the formula: `Voltage = (ADC_Value / 4095.0) * 3.3` to convert the ADC readings to volts.
  - In practice, further calibration beyone the equation above is required if you want to read the analog accurately. Try calibrating your ESP32 to read the exact voltage output if you want.
- Display the voltage readings in the serial monitor.

## Additional Resources

- You can refer to this blog as reference to calculate voltage from ADC [Random Nerd Tutorials - ESP32 ADC Analog Read](https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/).

## Safety Note

Always double-check connections and voltages with a multimeter before connecting your ESP32 to avoid potential damage.

## Frequently-asked questions (FAQ)

Q: What should I do if I cannot find a **resistor** in the lab that exactly matches my calculation?

A: This is a typical situation, and I believe you must have encountered it during your TECHIN512 class. You can choose one resistor in the lab whose resistance is the closest to your calculation. This, of course, will affect the voltage output and produce some error, but acceptable. However, be sure that you are filling in the spreadsheet with the **IDEAL, CALCULATED** resistance but not based on your selection, otherwise it would be difficult for us to check whether your calculation is correct or not.

Q: My circuit is correctly connected, but when using the multimeter to measure the voltage, I cannot get the reading. What's wrong with my board>
A:

* First, checking whether the ground (GND) pins are all connected. Using the left circuit as an example in the aboved figure, there are two pins on the PCB boards both representing the GND: the first one is the white circuit on the right of R2, and the second one is the white circuit above D1. Therefore, you shall use a wire to connect them.
* Also, your power supply negative and multimeter negative/ESP32 GND shall be connected to those pins as well.
* If they're still not working, probably your board is mis-printed and need detailed debugging. You can use a multimeter and switch it to the connectivity mode (with the icon of a diode) and check whether the pins/nodes shall be connected together are connected, and there's no short between other connections and wires.

Q: My circiut is correctly connected, but the voltage readout is way lower than expected (e.g. below 2V). What's wrong with my setup?
A: This is a typical phenomenon when you are powering the board with your ESP32/XIAO but not an external power supply. As illustrated in the instruction, you shall power your board with a 5V DC power supply (I bet the usage of the power supply is covered in TECHIN512). The voltage output of Seeeduino XIAO is only 3.3V. If you read the datasheet of LM317 carefully, you shall notice that there's a requirement about the minimum difference between the input and output voltage. Therefore, if the input voltage is not high enough, the output voltage cannot reach your ~2V target, regardless of your resistor selection.

Q: I've checked my board with the multimetor and the output is correct, but when I'm using the XIAO board to read the analog, I cannot have the correct readings (sometimes reads zero). What should I do?

A: If you check your XIAO board carefully, you shall notice that there's a tag on one side of it writing "**Seeeduino XIAO ESP32S3**". Therefore, check your PlatformIO setup and see if you've selected the correct board setup. This is **DIFFERENT** from our previous lab's choice which we set up the environment for Atmel platform based XIAO board. Here's the [link of the correct board environment setup](https://docs.platformio.org/en/latest//boards/espressif32/seeed_xiao_esp32s3.html), and you can paste it in your `platformio.ini` file to re-config it.

```
[env:seeed_xiao_esp32s3]
platform = espressif32
board = seeed_xiao_esp32s3
framework = arduino
```
