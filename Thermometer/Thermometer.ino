/// 
/// @mainpage	Thermometer 
///
/// @details	Thermometer sending data to the controller
/// @n 		
/// @n 
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Jakub Wozniak
/// @author		Jakub Wozniak
/// @date		23/10/14 8:37 pm
/// @version	<#version#>
/// 
/// @copyright	(c) Jakub Wozniak, 2014
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
///


///
/// @file		Thermometer.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Jakub Wozniak
/// @author		Jakub Wozniak
/// @date		23/10/14 8:37 pm
/// @version	<#version#>
/// 
/// @copyright	(c) Jakub Wozniak, 2014
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(ROBOTIS)
#include "libpandora_types.h"
#include "pandora.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(RFDUINO) // RFduino specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

// Include application, user and local libraries


// Prototypes


// Define variables and constants


// Add setup code 
void setup() 
{

}

// Add loop code 
void loop() 
{

}
