| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- |

# ESP32 UART Communication Project

This project demonstrates UART-based communication between two ESP32 boards using the ESP-IDF framework.

## 🔧 Features
- Master and Slave mode switching via GPIO
- FreeRTOS-based task structure
- Structured telegram message protocol
- Modular design for easy protocol expansion

## 📁 Project Structure
📦 ESP32_UART_project
┣ 📂 main
┃ ┣ 📜 main.c
┃ ┗ 📜 CMakeLists.txt
┣ 📜 CMakeLists.txt
┣ 📜 sdkconfig
┗ 📜 README.md

## 🚀 Getting Started
- Open the project using the ESP-IDF environment
- Run `idf.py set-target esp32` if needed
- Build the project with `idf.py build`
- Flash using `idf.py -p <PORT> flash`

