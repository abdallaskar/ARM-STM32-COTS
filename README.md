# ARM-STM32-COTS
This repository contains the MCAL drivers, HAL drivers, application layer, and libraries for ARM microcontroller STM32. The structure is modular, making it suitable for embedded systems projects with a focus on real-time applications and hardware abstraction.  

## Libraries:
- STD Types: Standard data types library.
- BIT Math: Bit manipulation and utility macros for efficient low-level operations.

## MCAL (Microcontroller Abstraction Layer): 
- RCC (Reset and Clock Control): Driver for controlling the clock and reset functionality of the STM32.
- GPIO (General Purpose Input/Output): Driver for managing digital input/output pins.
- NVIC (Nested Vector Interrupt Controller): Driver for interrupt management.
- EXTI (External Interrupt): Driver for handling external interrupts.
- AFIO (Alternate Function I/O): Driver for configuring alternate functions on GPIO pins.
- STK (SysTick Timer): SysTick Timer driver for accurate time delays and system timing.

    - V0: Basic SysTick Timer functionality.
    - V1: Extended SysTick Timer features, adding more control over timing events.

## HAL (Hardware Abstraction Layer):  
- LED: Driver for controlling LEDs.
- 7SEGMENT: Driver for interfacing with 7-segment displays.
- ULTRASONIC: Driver for ultrasonic sensor interfacing.
- LEDMATRIX: Driver for controlling LED matrix displays.
- IRREMOTE: Driver for interfacing with infrared remote control.
- DAC (Digital-to-Analog Converter): Newly added driver for converting digital signals to analog, useful for audio applications.
    
## Service Layer:
### 01-OS (Operating System)
This layer includes an operating system, which is an RTOS (Real-Time Operating System) that depends on timers and allows you to create tasks, manage concurrency, and execute them in a timely manner.    

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
### 04-Toggle LEDs using OS 
This new application demonstrates how to toggle LEDs using the included operating system (OS). It utilizes the OS to create tasks for LED toggling, showcasing concurrency management and real-time task execution. 

[Watch the video](https://drive.google.com/file/d/17Elrg1hPa41biPqtOkyCUvUfqBGC392X/view?usp=drive_link).  

### 05-Audio System using DAC 

This new application showcases audio playback functionality. It takes a digital audio signal, converts it to analog using the DAC driver, and plays it through an audio output. This project demonstrates how to use the DAC in a real-time audio system.

[Watch the video](https://drive.google.com/file/d/1ske7qNZHNc63afRzJKDt6XhiAlfAFuqf/view?usp=sharing).  
