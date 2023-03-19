# Temperature Measurement with BMP180 for STM32 with HAL Library

This project is a temperature measurement system using the BMP180 Digital Barometric Air Pressure Sensor and the STM32 microcontroller with HAL library. The BMP180 sensor is a high-precision, low-power digital barometer that can be used to measure temperature, pressure, and altitude.

![image](https://user-images.githubusercontent.com/88224304/226205648-2a3a008f-4419-4c6e-a89f-dbd7cb500b05.png)

## Requirements
To use this project, you will need the following hardware and software:
- STM32 microcontroller
- BMP180 Digital Barometric Air Pressure Sensor
- Breadboard and jumper wires
- USB cable for programming and power
- STM32CubeIDE or other compatible IDE

## Installation
**1.** Connect the BMP180 sensor to the STM32 microcontroller according to the pin configuration specified in the STM32CubeIDE's .ioc file.

**2.** Download and install STM32CubeIDE or other compatible IDE.

**3.** Download and import the project files from this GitHub repository.

**4.** Build the project and flash the code onto the microcontroller.

## Usage
**1.** Power on the microcontroller and wait for it to initialize.

**2.** Connect the microcontroller to your computer using a USB cable.

**3.** Open STM Studio and connect to the microcontroller.

**4.** In the Variables tab, you should see the temperature value being displayed.

**5.** You can also observe the temperature value changing in real-time as the sensor is exposed to different temperatures.

**6.** The measurement can be calibrated by adjusting the calibration constants in the code.

## Contributing
If you find any issues or bugs in the code, please submit an issue on the GitHub repository. Contributions are also welcome.

## Credits
This project was created by Sezin Arseven, based on the BMP180 library by Adafruit Industries.
