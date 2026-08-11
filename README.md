# SmartTraffic: Intelligent Traffic Light Control System

## Description
An advanced, real-time embedded traffic management system designed to simulate a modern smart intersection. This project goes beyond simple timed lights by integrating pedestrian crossing requests, real-time countdown timers, and synchronized audio-visual feedback to ensure safe and efficient traffic flow.

## ️ Component Usage & Technical Implementation

###  Seven-Segment Displays
*   **Usage:** Real-time countdown timers.
*   **Role:** Dedicated to displaying the remaining seconds for each traffic light phase (Green, Yellow, Red). This provides drivers and pedestrians with precise, predictable timing, reducing anxiety and improving intersection safety.

### LCD Display (16x2)
*   **Usage:** Pedestrian Human-Machine Interface (HMI).
*   **Role:** Displays clear, text-based instructions for pedestrians (e.g., "WAIT", "WALK NOW", "CARS STOPPING"). It ensures accessibility and clear communication for foot traffic.

###  Push Buttons (Pedestrian Request)
*   **Usage:** Pedestrian crossing interrupt.
*   **Role:** Allows pedestrians to safely request a crossing. When pressed, the firmware safely queues a state change to stop vehicle traffic and grant a "Walk" signal, mimicking real-world US-style crosswalk systems.

###  Buzzer (Audio Feedback)
*   **Usage:** Synchronized audio countdown.
*   **Role:** Emits a "Formula-1" style beeping sequence as the light timer counts down. This provides crucial audio cues for visually impaired pedestrians and alerts drivers that a light change is imminent.

###  LEDs (Traffic Signals)
*   **Usage:** Primary vehicle traffic control.
*   **Role:** Standard Red, Yellow, and Green LEDs simulate the physical traffic lights, controlled by the microcontroller's state machine.

##  Key Software Features & Logic

###  Real-Time Countdown State Machine
*   **The Feature:** Instead of using simple delay loops, the system uses hardware timers/interrupts to accurately decrement the seven-segment displays in real-time.
*   **The Logic:** The firmware manages a strict state machine (Green -> Yellow -> Red -> Green) while simultaneously updating the visual displays and listening for button inputs without freezing the system.

###  Pedestrian Crossing Interrupt Logic
*   **The Problem:** Pedestrians need a safe way to cross without waiting for a full, fixed cycle.
*   **The Solution:** The push button acts as an external interrupt or polled request. When pressed, the system safely completes the current phase, transitions to Red for cars, and updates the LCD to "WALK", ensuring pedestrian safety without causing abrupt, dangerous stops for cars.


##  Real-World Applications
*   **Smart City Intersections:** Dynamic traffic flow management.
*   **School Zones:** Enhanced pedestrian safety with audio-visual warnings.
*   **Hospital Crossings:** Accessible crossing systems for visually impaired individuals.
*   **High-Speed Roads:** Advanced warning systems for drivers approaching intersections.

##  Project Structure
*   `/Src` - Contains all the main C source code files (main logic, timer drivers, LCD driver, seven-segment driver).
*   `/Inc` - Contains all the C header files for modular code organization.
*   `/Proteus` - Contains the Proteus simulation design files and schematics.

## 🔧 How to Run the Simulation
1. Open the `.DBK` or `.PWI` file located in the `Proteus` folder using Proteus Design Suite.
2. Compile the Embedded C code in your IDE (e.g., Atmel Studio / AVR Studio).
3. Load the generated `.hex` file into the microcontroller component in Proteus.
4. Run the simulation. Watch the seven-segment timers count down, listen to the buzzer, and press the pedestrian button to trigger a crossing sequence.
