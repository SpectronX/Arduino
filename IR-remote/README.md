### This document outlines my experience working with an IR remote and sensor in Arduino to control an LCD screen

Similar to C++, programming Arduino also requires libraries to extend functionality of some components. For working with an IR remote, I used the `<IRremote.hpp>` library, which provides functions for handling remote communication protocols.

The IR sensor used has three pins: the right pin connects to the **VCC** which is **5V** on the Arduino, the **GND** (middle pin) connects to the **GND** of the Arduino and the **OUT** pin (left pin) goes to any digital pin on the Arduino board. In using the remote, one should also note that it has protocols for communication, usually **NEC** protocol.

In writing the code, the IR remote and sensor are configured in the `void setup() {…}`. By using `IrReceiver.begin(sensor pin)`, we prepare the remote and the sensor for work. The sensor pin is configured as **input** using the `pinMode(sensorpin, INPUT)` and must match the digital pin connected to the OUT pin of the sensor. The transmission protocol used in communicaiton allows the remote to send a **32-bit hexadecimal data format** encoded in the signal. The IR receiver also on the other end, through the library, decodes this received data into a number. A reference table with button values and their corresponding decoded numbers is included below. 

Since Arduino is always listening, it checks if data has been received before processing. So, in the `void loop() {..}`, if we want to start using the sensor, we check to see if it has already received data using `IrReceiver.decode()` and store the value in any variable. The value obtained is the number of the button that has been converted from a hex format to a number by the sensor and stored in `IrReceiver.decodedIRData.decodedRawData`. This variable holds the **32-bit number** transoformed by the IR receiver.

## Reference table for values related to their respective buttons.
