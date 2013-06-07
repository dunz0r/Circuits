/**
 * \file firmware/main.c
 * \brief Main functions for USB-keyboard
 * \author Ronald Schaten <ronald@schatenseite.de>
 * \version $Id: main.c,v 1.5 2008-07-12 21:05:24 rschaten Exp $
 *
 * License: GNU GPL v2 (see License.txt)
 */

/**
 * \mainpage Dulcimer
 *
 * \section sec_intro Introduction
 *
 * A computer keyboard can be a very personal utensil. Especially if it is an
 * extraordinary well built one, like for example the IBM Model M. The Model M
 * design dates back to 1984, but it still has many fans even nowadays. It came
 * with the usual keyboard connectors. First the old 5-pin one, later a PS/2
 * plug. Unfortunately is that, at least to my knowledge, they never released a
 * version with USB.
 *
 * A friend of mine knew that I already had built other USB-devices, and one of
 * them even acted as a keyboard (it isn't really a keyboard, but that's a
 * different story... ;-) ). He is a big fan of the Model M, so he asked if I
 * could put new life in one of his old keyboards, which had a broken circuit
 * inside. And this is the result...
 *
 * \subsection sec_technique Hard- and Software
 *
 * The main part of a computer keyboard circuit is the key matrix. You can
 * imagine it as a number of keys, placed on a raster of horizontal (rows) and
 * vertical (columns) wires. In the case of a Model M keyboard, we have a
 * matrix of 8x16 lines. Eight columns in 16 rows, or the other way around,
 * depending on how you look at it. Each key is connected to one column and one
 * row. If you press the key, it will connect the column and the row on it's
 * crossing of the lines.
 *
 * Connected to this matrix is a keyboard controller. That's a chip with a
 * number of I/O-lines to detect the state of the matrix, and on the other side
 * an interface that enables it to talk to the computer. Oh, and not to forget:
 * it also has three output lines to drive the LEDs for Num-, Caps- and
 * Scroll-lock.
 *
 * What I did in this project is, that I dumped the keyboard controller chip
 * and its circuit, and replaced it by an ATmega32 and my own circuit. The
 * ATmega scans the matrix for keyboard activity, controls the LEDs and talks
 * to the computer.
 *
 * For further convenience, I added a boot-loader. With that, it is possible to
 * update the keyboard's firmware without disassembling it, and without the
 * need for a dedicated programmer.
 *
 * \subsection sec_hardware Other hardware?
 *
 * As mentioned, the controller in this project is just connected to an
 * ordinary keyboard matrix. You can find this kind of matrix in all kinds of
 * keyboards, from key-telephones over good old hardware like the Commodore
 * C=64 or the Schneider CPC, keyboards with non-PC-connectors like those made
 * by Sun, to modern hardware that could need a few more features.
 *
 * Till now, I just made a PCB layout for the IBM Model M, but I intend to
 * modify at least a Sun keyboard. In order to do that, I expect having to
 * refactor the key-scanning, since the key-matrix is not 16x8. The positions
 * of the keys on the matrix will be different, I'll have to re-engineer that.
 * And of course, I'll have to make another PCB.
 *
 * \subsection sec_features Features
 *
 * At the moment, the keyboard should be able to do everything that the average
 * off-the-shelf-keyboard can do. But there are many features that are
 * possible, regarding the fact that the ATmega32 is absolutely bored till now.
 * You can think of 'magic keystrokes' that turn some hidden features on or
 * off, like for example:
 *  - send complete phrases on one keystroke
 *  - 'autofire' feature on keys that don't repeat normally, for example Alt+F4
 *  - change keyboard layout without reconfiguring the computer
 *  - turn bouncing keys on or off, to annoy other people using your computer
 *  - random caps lock function
 *  - use arrow keys as mouse, without having to include a special driver in
 *    the OS.
 *
 * With a little tweaking on the hardware side, there should be even more
 * possibilities:
 *  - turn the oldtimer-keyboard into a supermodern wireless bluetooth one
 *  - implement keylogger-funktionality, using for example an SD-card
 *  - include an USB-hub into the keyboard
 *
 * If you are just a little like me, it won't take you much brainstorming to
 * come up with own useful -- or even better: useless -- ideas. ;-)
 *
 * \section sec_install Building and installing
 *
 * Both, the bootloader and firmware are simply built with "make". You may need
 * to customize both makefiles to fit to your system. If you don't want to add
 * new features, you don't need to build the software yourself. You can use the
 * hex-files included in this package.
 *
 * \subsection sec_boot Bootloader
 *
 * I used the USBaspLoader from Objective Development, the same guys that wrote
 * the AVR-USB-driver: http://www.obdev.at/products/avrusb/usbasploader.html
 *
 * The reason why I chose this over some other available USB-bootloaders is,
 * that this one emulates a common ISP-programmer that is supported by avrdude.
 * In this way, the same program can be used to program the chip that is used
 * without a bootloader.
 *
 * To prepare the ATmega32, you have to connect it to your computer with the
 * ISP-programmer of your choice and modify the makefile according to that.
 * Then you enter the bootloader-directory and enter the following line:
 *
 * \code
 * make fuse && make flash && make lock
 * \endcode
 * 
 * With 'fuse' you prepare the fuse-bits of your AVR, 'flash' transfers the
 * bootloader to the device and 'lock' prevents you from overwriting the
 * bootloader. Don't fear the locking: you can always reset it with your
 * ordinary programmer. In fact, it is disabled in the moment you use your
 * ordinary programmer to reflash the device, even without any special
 * parameters. The locking only affects the bootloader behavior.
 *
 * Afterwards you can put the programmer back into the toolbox, you won't need
 * it from here on.
 *
 * When you plug in the device while holding the minus-key on the number-keypad
 * pressed, the keyboard indicates that it would like to get a new firmware by
 * showing a running light on the LEDs. That firmware will be flashed over the
 * normal USB-cable that the keyboard is connected with.
 *
 * \subsection sec_fw Firmware
 *
 * If you intend to recompile the firmware yourself, you will need avr-gcc and
 * avr-libc (a C-library for the AVR controller). Please read the instructions
 * at http://www.nongnu.org/avr-libc/user-manual/install_tools.html for how to
 * install the GNU toolchain (avr-gcc, assembler, linker etc.) and avr-libc.
 *
 * Once you have the GNU toolchain for AVR microcontrollers installed, you can
 * run "make" in the subdirectory "firmware".
 *
 * Afterwards -- or if you decided not to compile the firmware yourself -- you
 * can flash it to the device:
 *
 * \code
 * make program
 * \endcode
 *
 * Remember that you have to start the bootloader at first: unplug the
 * keyboard, hold the minus-key on the number-keypad pressed and replug it. If
 * the modified keyboard is the only one within reach: good luck! ;-)
 *
 * \section sec_usage Usage
 *
 * Connect the keyboard to the USB-port. All LED should flash up to indicate
 * that the device is initialized.
 *
 * Then you can use the keyboard as always. If additional features get
 * implemented, you will be able to use them in their respective ways.
 *
 * \section sec_drawbacks Drawbacks
 *
 * I don't know if and how keyboard manufacturers face the problem of ghost
 * keys, I didn't take special measurements for this. I hope that the engineers
 * at IBM distributed the keys on the matrix in a way that minimizes this
 * problem. Don't misunderstand: I haven't experienced that on this keyboard,
 * but I know that it's a common problem on key-matrixes.
 *
 * \section sec_files Files in the distribution
 *
 * - \e Readme.txt: Documentation, created from the htmldoc-directory.
 * - \e firmware: Source code of the controller firmware.
 * - \e firmware/usbdrv: USB driver -- See Readme.txt in this directory for
 *   info.
 * - \e bootloader: The USBaspLoader, properly configured for this project. I
 *   only modified the bootloaderconfig.h and the Makefile.
 * - \e USBaspLoader.2008-02-05.tar.gz: The unmodified bootloader sources, for
 *   reference.
 * - \e circuit: Circuit diagrams in PDF and KiCAD format. KiCAD is a free
 *   schematic- and layout-tool, you can learn more about it at its homepage:
 *   http://www.lis.inpg.fr/realise_au_lis/kicad/
 * - \e License.txt: Public license for all contents of this project, except
 *   for the USB driver. Look in firmware/usbdrv/License.txt for further info.
 * - \e Changelog.txt: Logfile documenting changes in soft-, firm- and
 *   hardware.
 * - \e refman.pdf: Full documentation of the software.
 *
 * \section sec_thanks Thanks!
 *
 * I'd like to thank <b>Objective Development</b> for the possibility to use
 * their driver for my project. In fact, this project wouldn't exist without
 * the driver.
 *
 * And of course I'd like to thank that friend of mine -- I doubt that he'd
 * like to read his name in this place, I'll put it in if he wants me to --
 * that gave me the idea for this project.
 *
 * \section sec_license About the license
 *
 * My work - all contents except for the USB driver - is licensed under the GNU
 * General Public License (GPL). A copy of the GPL is included in License.txt.
 * The driver itself is licensed under a special license by Objective
 * Development. See firmware/usbdrv/License.txt for further info.
 *
 * <b>(c) 2008 by Ronald Schaten - http://www.schatenseite.de</b>
 */

#define F_CPU 12000000L    ///< we use a 12MHz crystal

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

#include "usbdrv.h"
#include "keycodes.h"

/* ----------------------- hardware I/O abstraction ------------------------ */


#define PORTCOLUMNS PORTB  ///< port on which we read the state of the columns
#define PINCOLUMNS  PINB   ///< port on which we read the state of the columns
#define DDRCOLUMNS  DDRB   ///< port on which we read the state of the columns
#define PORTROWS1   PORTA  ///< first port connected to the matrix rows
#define PINROWS1    PINA   ///< first port connected to the matrix rows
#define DDRROWS1    DDRA   ///< first port connected to the matrix rows
#define PORTROWS2   PORTC  ///< second port connected to the matrix rows
#define PINROWS2    PINC   ///< second port connected to the matrix rows
#define DDRROWS2    DDRC   ///< second port connected to the matrix rows

#define PORTLEDS    PORTD  ///< port on which the LEDs are connected
#define PINLEDS     PIND   ///< port on which the LEDs are connected
#define DDRLEDS     DDRD   ///< port on which the LEDs are connected
#define LEDSCROLL   PIND4  ///< address of the scroll-lock LED
#define LEDCAPS     PIND5  ///< address of the caps-lock LED
#define LEDNUM      PIND6  ///< address of the num-lock LED

#define PORTJUMPERS PORTD  ///< port for additional jumpers
#define PINJUMPERS  PIND   ///< port for additional jumpers
#define DDRJUMPERS  DDRD   ///< port for additional jumpers
#define JUMPER0     PD1    ///< address for jumper 0
#define JUMPER1     PD3    ///< address for jumper 1
#define JUMPER2     PD7    ///< address for jumper 2

/**
 * Initialize hardware. Configure ports as inputs and outputs, set USB reset
 * condition, start timer and blink LEDs.
 */
static void hardwareInit(void) {
    // column-port is input
    PORTCOLUMNS = 0xff;
    DDRCOLUMNS  = 0x00;

    // row-ports are output
    PORTROWS1   = 0xff;
    DDRROWS1    = 0x00;
    PORTROWS2   = 0xff;
    DDRROWS2    = 0x00;

    // port D contains USB (D0, D2),
    //                 LEDs (D4, D5, D6)
    //             and Jumpers (D1, D3, D7),
    // so we call it PORTD instead of PORTJUMPERS or PORTLEDS
    PORTD       = 0xfa; // 1000 1010: activate pull-ups except on USB- and LED-lines
    DDRD        = 0x75; // 0111 0101: all pins input except USB (-> USB reset) and LED-pins
                        // USB Reset by device only required on Watchdog Reset
    _delay_us(11);      // delay >10ms for USB reset
    DDRD        = 0x70; // 0111 0000 bin: remove USB reset condition

    // configure timer 0 for a rate of 12M/(1024 * 256) = 45.78Hz (~22ms)
    TCCR0 = 5;          // timer 0 prescaler: 1024

    // blink, to indicate power-on
    PORTLEDS &= ~((1 << LEDNUM) | (1 << LEDCAPS) | (1 << LEDSCROLL));
    _delay_ms(50);
    PORTLEDS |= ((1 << LEDNUM) | (1 << LEDCAPS) | (1 << LEDSCROLL));
}

/* ------------------------------------------------------------------------- */
/* ----------------------------- USB interface ----------------------------- */
/* ------------------------------------------------------------------------- */

static uint8_t reportBuffer[8]; ///< buffer for HID reports
static uint8_t idleRate;        ///< in 4ms units
static uint8_t protocolVer = 1; ///< 0 = boot protocol, 1 = report protocol
uint8_t expectReport = 0;       ///< flag to indicate if we expect an USB-report

#define LED_NUM     0x01  ///< num LED on a boot-protocol keyboard
#define LED_CAPS    0x02  ///< caps LED on a boot-protocol keyboard
#define LED_SCROLL  0x04  ///< scroll LED on a boot-protocol keyboard
#define LED_COMPOSE 0x08  ///< compose LED on a boot-protocol keyboard
#define LED_KANA    0x10  ///< kana LED on a boot-protocol keyboard
uint8_t LEDstate = 0;     ///< current state of the LEDs

/** USB report descriptor (length is defined in usbconfig.h). The report
 * descriptor has been created with usb.org's "HID Descriptor Tool" which can
 * be downloaded from http://www.usb.org/developers/hidpage/ (it's an .exe, but
 * it even runs under Wine).
 */
char PROGMEM usbHidReportDescriptor[USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH] = {
    0x05, 0x01,   // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,   // USAGE (Keyboard)
    0xa1, 0x01,   // COLLECTION (Application)
    0x05, 0x07,   //   USAGE_PAGE (Keyboard)
    0x19, 0xe0,   //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,   //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,   //   LOGICAL_MINIMUM (0)
    0x25, 0x01,   //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,   //   REPORT_SIZE (1)
    0x95, 0x08,   //   REPORT_COUNT (8)
    0x81, 0x02,   //   INPUT (Data,Var,Abs)
    0x95, 0x01,   //   REPORT_COUNT (1)
    0x75, 0x08,   //   REPORT_SIZE (8)
    0x81, 0x03,   //   INPUT (Cnst,Var,Abs)
    0x95, 0x05,   //   REPORT_COUNT (5)
    0x75, 0x01,   //   REPORT_SIZE (1)
    0x05, 0x08,   //   USAGE_PAGE (LEDs)
    0x19, 0x01,   //   USAGE_MINIMUM (Num Lock)
    0x29, 0x05,   //   USAGE_MAXIMUM (Kana)
    0x91, 0x02,   //   OUTPUT (Data,Var,Abs)
    0x95, 0x01,   //   REPORT_COUNT (1)
    0x75, 0x03,   //   REPORT_SIZE (3)
    0x91, 0x03,   //   OUTPUT (Cnst,Var,Abs)
    0x95, 0x06,   //   REPORT_COUNT (6)
    0x75, 0x08,   //   REPORT_SIZE (8)
    0x15, 0x00,   //   LOGICAL_MINIMUM (0)
    0x25, 0x65,   //   LOGICAL_MAXIMUM (101)
    0x05, 0x07,   //   USAGE_PAGE (Keyboard)
    0x19, 0x00,   //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,   //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,   //   INPUT (Data,Ary,Abs)
    0xc0          // END_COLLECTION
};

/**
 * This function is called whenever we receive a setup request via USB.
 * \param data[8] eight bytes of data we received
 * \return number of bytes to use, or 0xff if usbFunctionWrite() should be
 * called
 */
uint8_t usbFunctionSetup(uint8_t data[8]) {
    usbRequest_t *rq = (void *)data;
    usbMsgPtr = reportBuffer;
    if ((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS) {
        // class request type
        if (rq->bRequest == USBRQ_HID_GET_REPORT) {
            // wValue: ReportType (highbyte), ReportID (lowbyte)
            // we only have one report type, so don't look at wValue
            return sizeof(reportBuffer);
        } else if (rq->bRequest == USBRQ_HID_SET_REPORT) {
            if (rq->wLength.word == 1) {
                // We expect one byte reports
                expectReport = 1;
                return 0xff; // Call usbFunctionWrite with data
            }
        } else if (rq->bRequest == USBRQ_HID_GET_IDLE) {
            usbMsgPtr = &idleRate;
            return 1;
        } else if (rq->bRequest == USBRQ_HID_SET_IDLE) {
            idleRate = rq->wValue.bytes[1];
        } else if (rq->bRequest == USBRQ_HID_GET_PROTOCOL) {
            if (rq->wValue.bytes[1] < 1) {
                protocolVer = rq->wValue.bytes[1];
            }
        } else if(rq->bRequest == USBRQ_HID_SET_PROTOCOL) {
            usbMsgPtr = &protocolVer;
            return 1;
        }
    } else {
        // no vendor specific requests implemented
    }
    return 0;
}

/**
 * The write function is called when LEDs should be set. Normally, we get only
 * one byte that contains info about the LED states.
 * \param data pointer to received data
 * \param len number ob bytes received
 * \return 0x01
 */
uint8_t usbFunctionWrite(uchar *data, uchar len) {
    if (expectReport && (len == 1)) {
        LEDstate = data[0]; // Get the state of all 5 LEDs
        if (LEDstate & LED_NUM) { // light up caps lock
            PORTLEDS &= ~(1 << LEDNUM);
        } else {
            PORTLEDS |= (1 << LEDNUM);
        }
        if (LEDstate & LED_CAPS) { // light up caps lock
            PORTLEDS &= ~(1 << LEDCAPS);
        } else {
            PORTLEDS |= (1 << LEDCAPS);
        }
        if (LEDstate & LED_SCROLL) { // light up caps lock
            PORTLEDS &= ~(1 << LEDSCROLL);
        } else {
            PORTLEDS |= (1 << LEDSCROLL);
        }
    }
    expectReport = 0;
    return 0x01;
}

/**
 * Send a single report to the computer. This function is not used during
 * normal typing, it is only used to send non-pressed keys to simulate input.
 * \param mode modifier-byte
 * \param key key-code
 */
void usbSendReport(uint8_t mode, uint8_t key) {
    // buffer for HID reports. we use a private one, so nobody gets disturbed
    uint8_t repBuffer[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    repBuffer[0] = mode;
    repBuffer[2] = key;
    while (!usbInterruptIsReady()); // wait
    usbSetInterrupt(repBuffer, sizeof(repBuffer)); // send
}

/* ------------------------------------------------------------------------- */

uint8_t curmatrix[16];  ///< contains current state of the keyboard

/**
 * The keymatrix-array contains positions of keys in the matrix. Here you can
 * see which row is connected to which column when a key is pressed. This array
 * probably has to be modified if this firmware is ported to a different
 * keyboard.
 * \sa modmatrix
 */
const uint8_t PROGMEM keymatrix[16][8] = {
  // 0              1             2                  3                4               5              6               7
    {KEY_Reserved,  KEY_Reserved, KEY_Reserved,      KEY_Reserved,    KEY_Reserved,   KEY_Reserved,  KEY_Reserved,   KEY_Reserved   }, //  0
    {KEY_Reserved,  KEY_Reserved, KEY_Reserved,      KEY_Reserved,    KEY_Reserved,   KEY_Reserved,  KEY_Reserved,   KEY_Reserved   }, //  1
    {KEY_ESCAPE,    KEY_Tab,      KEY_grave,         KEY_1,           KEY_Q,          KEY_A,         KEY_Z,          KEY_Reserved   }, //  2
    {KEY_Euro,      KEY_capslock, KEY_F1,            KEY_2,           KEY_W,          KEY_S,         KEY_X,          KEY_Reserved   }, //  3
    {KEY_F4,        KEY_F3,       KEY_F2,            KEY_3,           KEY_E,          KEY_D,         KEY_C,          KEY_Reserved   }, //  4
    {KEY_G,         KEY_T,        KEY_5,             KEY_4,           KEY_R,          KEY_F,         KEY_V,          KEY_B          }, //  5
    {KEY_F5,        KEY_DELETE,   KEY_F9,            KEY_F10,         KEY_Reserved,   KEY_Reserved,  KEY_Return,     KEY_Spacebar   }, //  6
    {KEY_H,         KEY_Y,        KEY_6,             KEY_7,           KEY_U,          KEY_J,         KEY_M,          KEY_N          }, //  7
    {KEY_F6,        KEY_rbracket, KEY_equals,        KEY_8,           KEY_I,          KEY_K,         KEY_comma,      KEY_Reserved   }, //  8
    {KEY_Reserved,  KEY_F7,       KEY_F8,            KEY_9,           KEY_O,          KEY_L,         KEY_dot,        KEY_Reserved   }, //  9
    {KEY_apostroph, KEY_lbracket, KEY_minus,         KEY_0,           KEY_P,          KEY_semicolon, KEY_hash,       KEY_slash      }, // 10
    {KEY_Reserved,  KEY_KP4,      KEY_DeleteForward, KEY_F11,         KEY_KP7,        KEY_KP1,       KEY_NumLock,    KEY_DownArrow  }, // 11
    {KEY_KP0,       KEY_KP5,      KEY_Insert,        KEY_F12,         KEY_KP8,        KEY_KP2,       KEY_KPslash,    KEY_RightArrow }, // 12
    {KEY_KPcomma,   KEY_KP6,      KEY_PageUp,        KEY_PageDown,    KEY_KP9,        KEY_KP3,       KEY_KPasterisk, KEY_KPminus    }, // 13
    {KEY_UpArrow,   KEY_Reserved, KEY_Home,          KEY_End,         KEY_KPplus,     KEY_KPenter,   KEY_Pause,      KEY_LeftArrow  }, // 14
    {KEY_Reserved,  KEY_Reserved, KEY_Reserved,      KEY_PrintScreen, KEY_ScrollLock, KEY_Reserved,  KEY_Reserved,   KEY_Reserved   }, // 15
};

/**
 * The modmatrix-array contains positions of the modifier-keys in the matrix.
 * It is built in the same way as the keymatrix-array.
 * \sa keymatrix
 */
const uint8_t PROGMEM modmatrix[16][8] = { // contains positions of modifiers in the matrix
  // 0             1               2                 3         4         5         6                  7
    {MOD_NONE,     MOD_NONE,       MOD_CONTROL_LEFT, MOD_NONE, MOD_NONE, MOD_NONE, MOD_CONTROL_RIGHT, MOD_NONE     }, //  0
    {MOD_NONE,     MOD_SHIFT_LEFT, MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_SHIFT_RIGHT,   MOD_NONE     }, //  1
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, //  2
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, //  3
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, //  4
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, //  5
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, //  6
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, //  7
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, //  8
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, //  9
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, // 10
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, // 11
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, // 12
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, // 13
    {MOD_NONE,     MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_NONE     }, // 14
    {MOD_ALT_LEFT, MOD_NONE,       MOD_NONE,         MOD_NONE, MOD_NONE, MOD_NONE, MOD_NONE,          MOD_ALT_RIGHT}, // 15
};

/**
 * This structure can be used as a container for a single 'key'. It consists of
 * the key-code and the modifier-code.
 */
typedef struct {
    uint8_t mode;
    uint8_t key;
} Key;

/**
 * Convert an ASCII-character to the corresponding key-code and modifier-code
 * combination.
 * \parm character ASCII-character to convert
 * \return structure containing the combination
 */
Key charToKey(char character) {
    Key key;
    // initialize with reserved values
    key.mode = MOD_NONE;
    key.key = KEY_Reserved;
    if ((character >= 'a') && (character <= 'z')) {
        // a..z
        key.key = (character - 'a') + 0x04;
    } else if ((character >= 'A') && (character <= 'Z')) {
        // A..Z
        key.mode = MOD_SHIFT_LEFT;
        key.key = (character - 'A') + 0x04;
    } else if ((character >= '1') && (character <= '9')) {
        // 1..9
        key.key = (character - '1') + 0x1E;
    }
    // we can't map the other characters directly, so we switch...
    switch (character) {
        case '0':
            key.key = KEY_0; break;
        case '!':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_1; break;
        /*
        case '@':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_2; break;
        case '#':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_3; break;
        */
        case '$':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_4; break;
        case '%':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_5; break;
        case '^':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_6; break;
        case '&':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_7; break;
        case '*':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_8; break;
        case '(':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_9; break;
        case ')':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_0; break;
        case ' ':
            key.key = KEY_Spacebar; break;
        case '-':
            key.key = KEY_minus; break;
        case '_':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_minus; break;
        case '=':
            key.key = KEY_equals; break;
        case '+':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_equals; break;
        case '[':
            key.key = KEY_lbracket; break;
        case '{':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_lbracket; break;
        case ']':
            key.key = KEY_rbracket; break;
        case '}':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_rbracket; break;
        case '\\':
            key.key = KEY_backslash; break;
        case '|':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_backslash; break;
        case '#':
            key.key = KEY_hash; break;
        case '@':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_hash; break;
        case ';':
            key.key = KEY_semicolon; break;
        case ':':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_semicolon; break;
        case '\'':
            key.key = KEY_apostroph; break;
        case '"':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_apostroph; break;
        case '`':
            key.key = KEY_grave; break;
        case '~':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_grave; break;
        case ',':
            key.key = KEY_comma; break;
        case '<':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_comma; break;
        case '.':
            key.key = KEY_dot; break;
        case '>':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_dot; break;
        case '/':
            key.key = KEY_slash; break;
        case '?':
            key.mode = MOD_SHIFT_LEFT;
            key.key = KEY_slash; break;
    }
    if (key.key == KEY_Reserved) {
        // still reserved? WTF? return question mark...
        key.mode = MOD_SHIFT_LEFT;
        key.key = KEY_slash;
    }
    return key;
} 

/**
 * Send a key to the computer, followed by the release of all keys. This can be
 * used repetitively to send a string.
 * \param keytosend key structure to send
 */
void sendKey(Key keytosend) {
    usbSendReport(keytosend.mode, keytosend.key);
    usbSendReport(0, 0);
}

/**
 * Send a string to the computer. This function converts each character of an
 * ASCII-string to a key-structure and uses sendKey() to send it.
 * \param string string to send
 */
void sendString(char* string) {
    for (uint8_t i = 0; i < strlen(string); i++) {
        Key key = charToKey(string[i]);
        sendKey(key);
    }
}

/**
 * Print the current state of the keyboard in a readable form. This function
 * is used for debug-purposes only.
 */
void printMatrix(void) {
    for (uint8_t i = 0; i <= 15; i++) {
        char buffer[10];
        /*
        sprintf(buffer, "%d%d%d%d%d%d%d%d.",
                (curmatrix[i] & (1 << 0) ? 1 : 0),
                (curmatrix[i] & (1 << 1) ? 1 : 0),
                (curmatrix[i] & (1 << 2) ? 1 : 0),
                (curmatrix[i] & (1 << 3) ? 1 : 0),
                (curmatrix[i] & (1 << 4) ? 1 : 0),
                (curmatrix[i] & (1 << 5) ? 1 : 0),
                (curmatrix[i] & (1 << 6) ? 1 : 0),
                (curmatrix[i] & (1 << 7) ? 1 : 0));
                */
        sprintf(buffer, "%2x", curmatrix[i]);
        sendString(buffer);
        if (i == 7) {
            sendString(":");
        } else {
            sendString(".");
        }
    }
    sendString("---");
}

/**
 * Scan and debounce keypresses. This is the main worker function for normal
 * keyboard operation, the code contains lot of comments. Basically, it first
 * scans the keyboard state. If a change is detected, it initializes a counter
 * that is decreased each time this function is called. If the counter reaches
 * 1, that means that the same scan result has been scanned ten times in a row,
 * so we can be pretty sure that the keys are in a certain state (as in: not
 * bouncing). Then, the codes for keys and modifiers are searched from the two
 * arrays, the USB-message to send the state is prepared. The return value of
 * this function indicates if the message has to be sent.
 * \return flag to indicate whether something has changed
 */
uint8_t scankeys(void) {
    static uint8_t debounce = 5;
    uint8_t retval = 0;
    for (uint8_t row = 0; row <= 15; row++) {
        if (row <= 7) {
            DDRROWS1  = (1 << row);
            PORTROWS1 = ~(1 << row);
            DDRROWS2  = 0x00;
            PORTROWS2 = 0xff;
        } else {
            DDRROWS1  = 0x00;
            PORTROWS1 = 0xff;
            // (15 - row) looks a bit weird, you would expect (row - 8) here.
            // This is because pins on PORTC are ordered in the other direction
            // than on PORTA. With (15 - row), we have the bytes in the
            // resulting matrix matching the pins of the keyboard connector.
            DDRROWS2  = (1 << (15 - row));
            PORTROWS2 = ~(1 << (15 - row));
        }
        _delay_us(30);
        uint8_t data = ~PINCOLUMNS;
        if (data != curmatrix[row]) {
            // if a change was detected
            debounce = 10; // activate debounce counter
            curmatrix[row] = data; // and store the result
        }
    }
    if (debounce) {
        // Count down, but avoid underflow
        debounce--;
    }
    if (debounce == 1) {
        // debounce counter expired, create report
        uint8_t reportIndex = 2; // reportBuffer[0] contains modifiers
        memset(reportBuffer, 0, sizeof(reportBuffer)); // clear report buffer
        for (uint8_t row = 0; row <= 15; row++) { // process all rows for key-codes
            uint8_t data = curmatrix[row]; // restore buffer
            if (data != 0xff) { // anything on this row? - optimization
                for (uint8_t col = 0; col <= 7; col++) { // check every bit on this row
                    uint8_t key, modifier;
                    if (data & (1 << col)) {
                        key = pgm_read_byte(&keymatrix[row][col]);
                        modifier = pgm_read_byte(&modmatrix[row][col]);
                    } else {
                        key = KEY_Reserved;
                        modifier = MOD_NONE;
                    }
                    if (key != KEY_Reserved) { // keycode should be added to report
                        if (reportIndex >= sizeof(reportBuffer)) { // too many keycodes
                            if (!retval & 0x02) { // Only fill buffer once
                                memset(reportBuffer+2, KEY_ErrorRollOver, sizeof(reportBuffer)-2);
                                retval |= 0x02; // continue decoding to get modifiers
                            }
                        } else {
                            reportBuffer[reportIndex] = key; // set next available entry
                            reportIndex++;
                        }
                    }
                    if (modifier != MOD_NONE) { // modifier should be added to report
                        reportBuffer[0] |= modifier;
                    }
                }
            }
        }
        retval |= 0x01; // must have been a change at some point, since debounce is done
    }
    return retval;
}

/* ------------------------------------------------------------------------- */

/**
 * Main function, containing the main loop that manages timer- and
 * USB-functionality.
 * /return the obligatory integer that nobody cares about...
 */
int main(void) {
    uint8_t updateNeeded = 0;
    uint8_t idleCounter = 0;
    wdt_enable(WDTO_2S);
    hardwareInit();
    usbInit();
    sei();

    scankeys();
    while (1) {
        // main event loop
        wdt_reset();
        usbPoll();

        updateNeeded = scankeys(); // changes?

        // check timer if we need periodic reports
        if (TIFR & (1 << TOV0)) {
            TIFR = (1 << TOV0); // reset flag
            if (idleRate != 0) { // do we need periodic reports?
                if(idleCounter > 4){ // yes, but not yet
                    idleCounter -= 5; // 22ms in units of 4ms
                } else { // yes, it is time now
                    updateNeeded = 1;
                    idleCounter = idleRate;
                }
            }
        }
        // if an update is needed, send the report
        if (updateNeeded && usbInterruptIsReady()) {
            updateNeeded = 0;
            usbSetInterrupt(reportBuffer, sizeof(reportBuffer));
        }
    }
    return 0;
}

/* ------------------------------------------------------------------------- */
