# Servo Angle Control with LCD Display and Status LEDs

This project demonstrates a servo motor angle control system using an Arduino-compatible board.  
The system continuously sweeps the servo motor between 0 and 180 degrees.  
A 16x2 I2C LCD is used to display the current servo angle in real time.  
Two LEDs are integrated to visually indicate the direction of rotation.  
The blue LED turns on while the servo moves from 0 to 180 degrees.  
The red LED turns on while the servo moves from 180 back to 0 degrees.  
The servo is connected to digital pin 8.  
The blue LED is connected to digital pin 2.  
The red LED is connected to digital pin 3.  
The LCD operates via the I2C interface using address 0x27.  
The system initializes the LCD and servo during the setup phase.  
During operation, the servo angle is updated incrementally with small delays to create smooth motion.  
Each new angle value is written to the LCD display.  
The degree symbol is displayed using the HD44780 character code.  
A short delay is added after each sweep cycle for visibility and stability.  
The project was developed using PlatformIO and the Arduino framework.  
It demonstrates basic servo control using the Servo library.  
It also showcases I2C communication with an LCD module.  
The implementation is suitable for learning embedded control fundamentals.  
This project provides a simple and effective example of motion control with visual feedback.
