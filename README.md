The simplest circuit for transmitting data over a power line between two Arduinos, using only 2 wires and 1 capacitor.

The SoftwareSerial protocol is used to transfer data.

Signal transmission and power go through pin D11 on both Arduinos.

![image](https://github.com/14types/simplest-power-line-communication-between-Arduinos/assets/34601503/72b712b0-bdf5-4d21-984d-94973ff4c9fd)

For 1 second, a high signal is sent to D11 on the first Arduino to power the second Arduino and to power the capacitor.

Next, 0 is applied to D11 and sending and receiving data through the serial starts

https://www.youtube.com/watch?v=aywDoc-Y9T4
