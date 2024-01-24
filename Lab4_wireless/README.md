# ESP32 Wireless Lab Rubric

Total Points: 100

Submit a single PDF containing your Team details (team name, members). Include screenshots as specified below. Ensure the screenshots are clear and properly labeled as per the requirements.

## BLE Scan (10 Points)
- **Objective**: Identify Bluetooth devices in the vicinity.
- **Requirement**: Submit a screenshot of your serial monitor displaying the number of Bluetooth devices detected during the scan.

## Establishing Bluetooth Connection (20 Points)
- **Objective**: Establish a Bluetooth connection with your partner's ESP32.
- **Requirement**: Attach a screenshot of the client’s serial monitor showing the successful connection. Ensure the server device’s name is circled in the screenshot.

## Sensor Device Signal Processing and Data Transmission (Server Device) (30 Points)
- **Objective**: Collect and process distance data using the HC-SR04 sensor; transmit over Bluetooth if certain conditions are met.
- **Requirement**:
  - Submit a screenshot of the serial monitor showing the distance value collected from the HC-SR04 distance sensor.
  - Ensure data is transmitted over Bluetooth to the client device **only** when the distance is less than 30cm.

## Display Device Signal Processing and Data Receiving (40 Points)
- **Objective**: Receive, process, and display distance data on the client device.
- **Requirements**:
  - Submit a screenshot of your serial monitor receiving the distance data from the sensor device.
  - Submit an additional screenshot of your serial monitor after data processing. The processed data should clearly display:
    1. The distance received from the sensor device over Bluetooth.
    2. The maximum and minimum distance received since the beginning of data reception.
    3. Do this for at least 10 different distance values.

**Note**: Ensure that all screenshots are clear, and the required data or indicators are appropriately highlighted or circled. Follow the specific instructions for each section closely to meet the criteria for full points.