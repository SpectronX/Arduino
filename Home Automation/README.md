# Arduino-Based Home Automation Systems

As part of exploring what Arduino can be used for, I worked on a series of subsystems to simulate simple home automation functionalities. With practical beginner-friendly implementations, I managed to cover four key systems:

- Intruder Detection System
- Automatic Door System
- Temperature-Controlled Fan System
- Automatic Lighting System  
  
---

## Intruder Detection System

This system uses a **PIR (Passive Infrared) sensor** and a **buzzer** (would be adding a LCD display to it soon). Simple function: when motion is detected in a monitored or restricted area, the buzzer sounds, alerting the user. This setup can be used for home security or for detecting presence in a space.

## Automatic Door System

The door system is built using an **Ultrasonic Sensor** and a **micro servo motor**. The sensor emits ultrasonic pulses and listens for echoes to determine how close an object (like a person) is:

- If someone is within a defined range (e.g., < 50 cm), and moving towards the system, the Arduino commands the servo motor to rotate, simulating the door opening. Also, when the person is outside the defined range or cannot be "seen" by the Arduino after entering, the door closes.

This mimics a proximity-triggered automatic door mechanism.

---

## Automatic Lighting System

This system utilizes a **photoresistor (LDR)** and a **bulb**. The LDR’s resistance changes with light levels—lower in bright light and higher in darkness. It forms a **voltage divider** with a resistor and is connected to the Arduino's analog input. The Arduino reads the voltage to determine lighting conditions:

- **Low light** → Low voltage → Bulb ON  
- **Bright light** → High voltage → Bulb OFF

This setup allows the bulb to turn on automatically when it's dark and off when it's bright.

---

## Temperature-Controlled Fan System

This system uses a **TMP36 temperature sensor** and a **DC motor** as a fan. Based on temperature readings, the Arduino adjusts fan speed using PWM (Pulse Width Modulation):

- **Higher temperatures** → **Faster fan speed**
- **Lower temperatures** → **Slower or no fan operation**

Temperature is calculated from analog readings, for which its voltage and temperature equivalent is found using the formula in the code.



