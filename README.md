# ARM-STM32-COTS
This repository contains MCAL drivers, HAL drivers, application layer, and libraries for ARM microcontroller STM32.

## Libraries:
- STD types: Standard types library.
- BIT math: Bit manipulation library.

## MCAL Layer:
- RCC: Reset and Clock Control driver.
- GPIO: General Purpose Input/Output driver.
- NVIC: Nested Vector Interrupt Controller driver.
- EXTI: External Interrupt driver.
- AFIO: Alternate Function I/O driver.
- STK: SysTick Timer driver.

## HAL Layer:
- LED: LED driver.
- 7SEGMENT: 7-segment display driver.
- ULTRASONIC: Ultrasonic sensor driver.
- LEDMATRIX: LED matrix driver.
- IRREMOTE: IR infrared remote access driver.

## Application Layer:
### 01-7Segment
This project prints from 0 to 9 on 7Segment and does that forever.      
[Watch the video](https://drive.google.com/file/d/1hDn8wlbTfSS8ist9v0QXSvrNVePE9mwb/view?usp=drive_link).

### 02-LedAnimation
Led Animations:
This project plays animations on 8 LEDs on the kit in the following patterns, repeating forever:
1. Shift left/right (ping-pong) LED to LED -> 200 ms, 4 times.
2. In/out (Fat7y yawarda) LED to LED -> 200 ms, 4 times.
3. Flashing LED every 500 ms -> 4 times.
[Watch the video](https://drive.google.com/file/d/1hDn8wlbTfSS8ist9v0QXSvrNVePE9mwb/view?usp=drive_link).

### 03-Display Name using LED Matrix
This project controls an LED matrix display.     
This application displays the text "abdalla skar" and rotates it from left to right indefinitely.   
[Watch the video](https://drive.google.com/file/d/11p-0RSphCJAbunPxSIuC154-T7QjTlK0/view?usp=drive_link).
