# IoT-Based Rain Protection System

## Project Overview

An Internet of Things (IoT)-based rain protection system developed to help protect outdoor materials, such as agricultural produce and clothes, from unexpected rainfall.

The system uses a NodeMCU ESP8266 to collect environmental sensor readings, communicate with a Blynk mobile application, notify the user when rain is detected, and control a servo-operated protective shed.

## Features

- Rain detection using an FC-37 rain sensor.
- Rain-level readings through the sensor's analog output.
- Temperature and humidity monitoring using a DHT11 sensor.
- Light-level monitoring using an LDR module.
- Local environmental readings displayed on an I²C LCD.
- Mobile monitoring through the Blynk application.
- Rain notifications through the mobile application.
- Remote opening and closing of the protective shed using an SG90 micro servo.

## Hardware Components

- NodeMCU ESP8266 Wi-Fi development board
- FC-37 rain sensor
- DHT11 temperature and humidity sensor
- LDR sensor module
- SG90 micro servo motor
- I²C LCD module
- Breadboard and jumper wires
- Power supply and associated connections

## Software and Technologies

- Arduino IDE
- Arduino/C++
- ESP8266 Wi-Fi
- Blynk IoT mobile application
- Embedded sensor interfacing
- Servo motor control

## Working Principle

The NodeMCU receives readings from the rain sensor, DHT11 sensor, and LDR module. Environmental readings are displayed on the LCD and shared with the Blynk application.

When the rain sensor detects rain, the system sends a notification to the mobile application. The user can operate a slider in the application to control the servo-operated rain shed.

The documented implementation relies on user operation of the protection slider; automatic rain-triggered deployment of the shed is not claimed here.

## Repository Structure

- `src/` — Arduino source code
- `hardware/` — component information and circuit documentation
- `docs/` — project report and supporting documentation
- `media/` — prototype photos and application screenshots

## Setup and Usage

1. Install the Arduino IDE and ESP8266 board support.
2. Install the libraries required by the source code.
3. Connect the sensors, LCD, and servo according to the circuit documentation.
4. Configure Wi-Fi and Blynk credentials securely.
5. Upload the Arduino sketch to the NodeMCU ESP8266.
6. Configure the Blynk dashboard and virtual pins to match the code.
7. Test sensor readings, rain notifications, and manual shed control.

Do not publish real network passwords or authorization tokens.

## Applications

- Protection of clothes from unexpected rain
- Protection of agricultural produce during outdoor drying
- Rain-responsive protective sheds
- Potential adaptation for other weather-sensitive outdoor materials

## Project Report

A redacted copy of the project report can be placed in `docs/` after removing exposed credentials and checking that the document is suitable for public sharing.

## Project Status

Mini project completed as documented in the project report.

## Author

Kiran Joy T

GitHub: [https://github.com/KiranJoyT]
