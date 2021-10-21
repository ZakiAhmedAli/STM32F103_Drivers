# STM32F103_Drivers
This repo will contain all the derives that I have created. Feel free to comment, on anything you want

## MCAL "Micro-Controller Abstraction Layer"

Every Peripheral divided into 4 files

peripheral_private.h -> Register masking

peripheral_interface.h -> API Prototypes, #defines and structs used in program

peripheral_Program.c -> Peripheral Program: APIs Implementation

## HAL "Hardware Abstraction Layer"

A hardware abstraction layer (HAL) is a logical division of code that serves as an abstraction layer between a computer's physical hardware and its software. It provides a device driver interface allowing a program to communicate with the hardware.

### The HAL provides the following benefits:

Allowing applications to extract as much performance out of the hardware devices as possible

Enabling device drivers to provide direct access to each hardware device, which allows programs to be device-independent

Allowing software programs to communicate with the hardware devices at a general level

Facilitating portability
