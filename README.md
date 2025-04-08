Supported Targets	ESP32	ESP32-C2	ESP32-C3	ESP32-S2	ESP32-S3

ESP32 UART Communication Project

This project demonstrates UART-based communication between two ESP32 boards using the ESP-IDF framework.

# ESP32 UART Communication Project

This project demonstrates UART-based communication between two ESP32 boards using the ESP-IDF framework.

## Features
- Master and Slave mode switching via GPIO
- FreeRTOS-based task structure
- Structured telegram message protocol
- Modular design for easy protocol expansion

## Project Structure
ESP32_UART_project
┣  main
┃ ┣  main.c
┃ ┗  CMakeLists.txt
┣ CMakeLists.txt
┣  sdkconfig
┗  README.md

## Getting Started
- Open the project using the ESP-IDF environment
- Run `idf.py set-target esp32` if needed
- Build the project with `idf.py build`
- Flash using `idf.py -p <PORT> flash`

## References

- [ESP32 UART Communication Tutorial – ControllersTech](https://controllerstech.com/esp32-2-how-to-use-uart-part2/)

- [ESP-IDF UART Driver Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/uart.html)

- [ESP-AT Command Set – Espressif Docs](https://docs.espressif.com/projects/esp-at/en/latest/AT_Command_Set/)
