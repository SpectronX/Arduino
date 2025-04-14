## IR Remote-Controlled Fan Speed using Arduino

🛠️ In this setup, I focused on using an IR remote to control the speed of a fan, which is represented here by a simple DC motor. I’ve come across common components like temperature sensors and potentiometers for such control, but then decided to integrate IR communication PWM (Pulse Width Modulation) control from an Arduino.

🔧 The components required for this project include: an Arduino Uno board, an IR sensor, an IR remote, a DC motor, a TIP120 Darlington transistor, a 9V battery, a diode, and a breadboard with jumper wires.

📘 Let’s take a look at the roles of some key components involved, starting with the transistor. From electronics, a transistor is a three-terminal semiconductor device that acts as a switch or amplifier. In this setup, the TIP120 transistor is used to control the higher current needed by the motor, which the Arduino alone cannot provide. The transistor has three terminals: base, collector, and emitter. The base is connected to a PWM-capable digital pin on the Arduino. This allows the Arduino to send a fluctuating signal to the base, effectively controlling the motor speed by adjusting the average voltage. The collector connects to one terminal of the motor, while the emitter is connected to ground. One should note that the transistor doesn’t increase voltage. It rather allows a larger current from the 9V battery to flow through the motor, based on the smaller signal from the Arduino.

🔋 The 9V battery is what powers the motor. One terminal of the motor is connected to the collector of the transistor, and the other terminal is connected to the positive terminal of the 9V battery. This ensures the motor receives enough voltage and current for proper operation. A diode is also included, placed in parallel across the motor terminals. The diode is oriented with the anode toward the battery’s positive terminal and the cathode toward the transistor’s collector. This configuration helps absorb any back EMF (a reverse voltage spike) generated when the motor is turned off.

🌐 Finally, the circuit requires a common ground. The emitter of the transistor and the negative terminal of the 9V battery are both connected to one of the Arduino’s GND pins. This shared ground provides a stable reference point for all voltages in the system.

🎮 So, when in action, the button is pressed on the IR remote which is detected by the sensor. The signal is sent to the Arduino which also maps this input to a specific PWM value. This value is sent to the transistor’s base enabling a control of the voltage supply to the transistor.

⚠️ However, in simulating the circuit, I find that the rpm values on the motor don’t stick to one value when changed. Any help on that would be appreciated. Thank you! 😀


