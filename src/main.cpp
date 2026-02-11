/**
 * @file main.cpp
 * @brief OLED interfacing example for Arduino (Adafruit SSD1306)
 *
 * This example demonstrates initializing an Adafruit SSD1306 OLED display
 * over I2C and writing simple text to the screen. The code is written to be
 * compatible with Arduino boards (for example: Arduino Uno R4).
 *
 * The main purpose of this file is educational: show how to initialize the
 * display and print static lines of text. It intentionally keeps the
 * loop() function empty so users can add their own application logic.
 *
 * @author Project
 * @date 2026-02-11
 * @version 1.0
 *
 * @note This file uses the Adafruit_GFX and Adafruit_SSD1306 libraries. Make
 * sure they are installed in your Arduino/PlatformIO environment.
 *
 * @copyright MIT (or your preferred license)
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/**
 * @def SCREEN_WIDTH
 * @brief Width of the OLED display in pixels.
 */
#define SCREEN_WIDTH 128

/**
 * @def SCREEN_HEIGHT
 * @brief Height of the OLED display in pixels.
 */
#define SCREEN_HEIGHT 64

/**
 * @def OLED_ADDR
 * @brief I2C address of the OLED display (common addresses: 0x3C or 0x3D).
 */
#define OLED_ADDR 0x3C

/**
 * @brief SSD1306 display instance used throughout this example.
 *
 * This example constructs the Adafruit_SSD1306 object at runtime inside
 * setup() to avoid static initialization order issues with the Wire object
 * (which is initialized by the Arduino core). The pointer is nullptr until
 * setup() completes successfully.
 *
 * Lifetime:
 * - Allocated with new in setup().
 * - Not deleted in this simple example because Arduino typically runs
 *   indefinitely; delete if you later refactor for clean shutdowns.
 */
Adafruit_SSD1306* display = nullptr;

/**
 * @brief Arduino setup routine.
 *
 * The setup() function performs the following steps:
 * 1. Starts Serial at 9600 baud for debugging output.
 * 2. Attempts to initialize the SSD1306 display. If initialization fails,
 *    it prints an error message to Serial and halts execution.
 * 3. Clears the display buffer, sets text size/color/cursor, and prints two
 *    lines of text before calling display.display() to update the screen.
 *
 * @return void
 */
void setup() {
    Serial.begin(9600);

    // Create the display object after Arduino/Wire is initialized to avoid
    // static initialization order problems reported by some static analyzers.
    display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_ADDR);

    // Initialize the display. The begin() call returns true on success.
    // SSD1306_SWITCHCAPVCC is used to tell the library the display is using
    // the internal charge pump to generate the display voltage.
    if (!display->begin(SSD1306_SWITCHCAPVCC, OLED_ADDR))
    {
        Serial.println("OLED not found");
        // Halt here - display is required for this example.
        while (true);
    }

    // Clear any old data and prepare text parameters
    display->clearDisplay();
    display->setTextSize(2);               // 2x text size
    display->setTextColor(SSD1306_WHITE); // Draw white text
    display->setCursor(0, 0);             // Start at top-left corner

    // Print two example lines. Use println so each call advances to a new line.
    display->println("Arduino Uno R4");
    // display->println("Hello Student");
    delay(1000); // small delay before printing the next line
    display->println("Pradeep");

    // Push buffer to the physical display
    display->display();
    // write your initialization code here
}

/**
 * @brief Arduino main loop.
 *
 * This example keeps the loop empty to act as a template for adding user
 * code. Typical uses will update the display from within loop() or call
 * helper functions from here.
 *
 * @return void
 */
void loop() {
    // write your code here
}