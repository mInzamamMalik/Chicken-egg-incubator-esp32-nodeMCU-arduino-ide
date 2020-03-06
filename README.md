# Chicken-egg-incubator-esp32-nodeMCU-arduino-ide
In this project I created a chicken egg incubation hardware, I have used 5v single channel relay, led indicator light, Buzzer for alarm sound in case of over heat and under heat


how it works: it simply have a tungstun buld connected to relay, 100W to 250w according to the amount of eggs and size of box,
you can also use electric heater if you box is very big but usually it doesnt require that much heat so bulb works, 
it simply shuts the relay (bulb) down when required heat is archived and turn it back on when temprature goes down and this happens every second
heat bw 35.5C and 28.5C is acceptable for chicken egg incubator, so it beeps when under heat and countinious buzzer beep in case of over heat
if hard ware can automatically shut the buld why I added buzzer on over heat, reason is the bulb is not the only possible source of heat it could be abything else, may be you try to add another bulb other then this hardware or may be in afternoor sun becomes too hot and cause over heat (in this case you need to open your box for some fresh air and reduce heat, I am also gonna add a fan in this hardware for very hot regions such as Saudi and Qatar, however USA, canada europe probably never face this)
 


TODO: I will add an OLED display in the device to display temrature and 


referance documents:

use DHT11: https://circuits4you.com/2019/01/25/esp32-dht11-22-humidity-temperature-sensor-interfacing-example/
blink LED: https://www.instructables.com/id/Blinking-an-LED-With-ESP32/
5V Relay: https://www.instructables.com/id/Interface-Relay-Module-With-NodeMCU/


pinout: https://www.youtube.com/watch?v=7h2bE2vNoaY
