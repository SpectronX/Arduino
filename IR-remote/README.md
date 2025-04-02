# This document outlines my experience working with an IR remote and sensor in Arduino to control an LCD screen

Similar to C++, Arduino programming also requires libraries to extend functionality. For working with an IR remote, we use the `<IRremote.hpp>` library, which provides functions for handling remote communication protocols. Therefore, one would have to include this library to access the remotes functionalities. 

The IR sensor used in Arduino is the HX 1838 sensor. This sensor has three pins: one connects to the **VCC** (right) which connects to **5V** on the Arduino, the **GND** (middle) which connects to the **GND** of the Arduino and the **OUT** pin (left) goes to any digital pin on the Arduino board. In using the remote, one should also note that it has protocols for communication, usually **NEC** (full meaning) which produces a hexadecimal code for every button press.

In writing the code, the IR remote and sensor are configured in the `void setup() {…}`. By using `IrReceiver.begin(sensor pin)`. Then the sensor pin is configured as **input** and must match the digital pin connected to the OUT pin of the sensor. Remotes have a particular protocol they operate by and for the remote being used, it operates on the **NEC protocol**. This protocol allows the remote to send a **32-bit hexadecimal data format** along with the signal. The IR receiver also on the other end, by the library, decodes this received data into a number. A reference table with button values and their corresponding decoded numbers is included below. 

Since Arduino is always listening, it checks if data has been received before processing. So, in the `void loop() {..}`, if we want to start using the sensor, we check to see if it has already received data using `IrReceiver.decode()` and store the value in any variable. The value obtained is the number of the button that has been converted from a hex format to a number by the sensor and stored in `IrReceiver.decodedIRData.decodedRawData`. This variable holds the **32-bit number** decoded by the IR receiver.

## Reference table for values related to their respective buttons.
