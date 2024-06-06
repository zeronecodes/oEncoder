#include "reg_map.h"
#include "delay.h"
#include "util.h"
#include "led.h"
#include "usart.h"

// Define binary codes for alphanumeric characters
const unsigned char led_codes[62] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, // '0' - '9'
    0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, // 'a' - 't'
    0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, // 'u' - 'z'
    0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, // 'A' - 'J'
    0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, // 'K' - 'T'
    0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, // 'U' - 'Z'
};

void init_leds(void) {
    init_led(); // Call the provided init_led function
}

void set_leds(unsigned char code) {
    // Turn off all LEDs first
    off_led1();
    off_led2();
    off_led3();
    off_led4();
    off_led5();
    off_led6();

    // Turn on LEDs according to the binary code
    if (code & 0x01) on_led1();
    if (code & 0x02) on_led2();
    if (code & 0x04) on_led3();
    if (code & 0x08) on_led4();
    if (code & 0x10) on_led5();
    if (code & 0x20) on_led6();
}

unsigned char encode_char(char c) {
    if (c >= '0' && c <= '9') {
        return led_codes[c - '0'];
    } else if (c >= 'a' && c <= 'z') {
        return led_codes[c - 'a' + 10];
    } else if (c >= 'A' && c <= 'Z') {
        return led_codes[c - 'A' + 36];
    } else {
        return 0x00; // Not an alphanumeric character
    }
}

int main(void) {
    char c;
    int error_code;
    unsigned char code;

    // Initialize LEDs
    init_leds();

    // Initialize USART for serial communication
    init_usart(__BAUD_9600__);

    // Main loop
    while (1) {
        // Read a character from the terminal emulator
        c = sscanc();

        // Handle possible USART errors
        if (error_code == __RET_FRAME_ERROR__) {
            // sprintc("Frame Error\r\n");
            continue;
        } else if (error_code == __RET_PARITY_ERROR__) {
            // sprintc("Parity Error\r\n");
            continue;
        }

        // Encode the character if it's alphanumeric
        code = encode_char(c);
        
        // Set the LEDs according to the encoded character
        set_leds(code);
        
        // Wait for a short period to debounce
        delay_ms(500);
    }
    return 0; // This line will never be reached
}