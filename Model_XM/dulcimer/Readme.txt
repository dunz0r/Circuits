This file is auto-generated from the content of firmware/main.c
You'll have more fun if you read the HTML-content in htmldoc or the PDF.

     * [1]Main Page
     * [2]Data Structures
     * [3]Files

                                    Dulcimer

Introduction

   A computer keyboard can be a very personal utensil. Especially if it is
   an extraordinary well built one, like for example the IBM Model M. The
   Model M design dates back to 1984, but it still has many fans even
   nowadays. It came with the usual keyboard connectors. First the old
   5-pin one, later a PS/2 plug. Unfortunately is that, at least to my
   knowledge, they never released a version with USB.

   A friend of mine knew that I already had built other USB-devices, and
   one of them even acted as a keyboard (it isn't really a keyboard, but
   that's a different story... ;-) ). He is a big fan of the Model M, so
   he asked if I could put new life in one of his old keyboards, which had
   a broken circuit inside. And this is the result...

  Hard- and Software

   The main part of a computer keyboard circuit is the key matrix. You can
   imagine it as a number of keys, placed on a raster of horizontal (rows)
   and vertical (columns) wires. In the case of a Model M keyboard, we
   have a matrix of 8x16 lines. Eight columns in 16 rows, or the other way
   around, depending on how you look at it. Each key is connected to one
   column and one row. If you press the key, it will connect the column
   and the row on it's crossing of the lines.

   Connected to this matrix is a keyboard controller. That's a chip with a
   number of I/O-lines to detect the state of the matrix, and on the other
   side an interface that enables it to talk to the computer. Oh, and not
   to forget: it also has three output lines to drive the LEDs for Num-,
   Caps- and Scroll-lock.

   What I did in this project is, that I dumped the keyboard controller
   chip and its circuit, and replaced it by an ATmega32 and my own
   circuit. The ATmega scans the matrix for keyboard activity, controls
   the LEDs and talks to the computer.

   For further convenience, I added a boot-loader. With that, it is
   possible to update the keyboard's firmware without disassembling it,
   and without the need for a dedicated programmer.

  Other hardware?

   As mentioned, the controller in this project is just connected to an
   ordinary keyboard matrix. You can find this kind of matrix in all kinds
   of keyboards, from key-telephones over good old hardware like the
   Commodore C=64 or the Schneider CPC, keyboards with non-PC-connectors
   like those made by Sun, to modern hardware that could need a few more
   features.

   Till now, I just made a PCB layout for the IBM Model M, but I intend to
   modify at least a Sun keyboard. In order to do that, I expect having to
   refactor the key-scanning, since the key-matrix is not 16x8. The
   positions of the keys on the matrix will be different, I'll have to
   re-engineer that. And of course, I'll have to make another PCB.

  Features

   At the moment, the keyboard should be able to do everything that the
   average off-the-shelf-keyboard can do. But there are many features that
   are possible, regarding the fact that the ATmega32 is absolutely bored
   till now. You can think of 'magic keystrokes' that turn some hidden
   features on or off, like for example:
     * send complete phrases on one keystroke
     * 'autofire' feature on keys that don't repeat normally, for example
       Alt+F4
     * change keyboard layout without reconfiguring the computer
     * turn bouncing keys on or off, to annoy other people using your
       computer
     * random caps lock function
     * use arrow keys as mouse, without having to include a special driver
       in the OS.

   With a little tweaking on the hardware side, there should be even more
   possibilities:
     * turn the oldtimer-keyboard into a supermodern wireless bluetooth
       one
     * implement keylogger-funktionality, using for example an SD-card
     * include an USB-hub into the keyboard

   If you are just a little like me, it won't take you much brainstorming
   to come up with own useful -- or even better: useless -- ideas. ;-)

Building and installing

   Both, the bootloader and firmware are simply built with "make". You may
   need to customize both makefiles to fit to your system. If you don't
   want to add new features, you don't need to build the software
   yourself. You can use the hex-files included in this package.

  Bootloader

   I used the USBaspLoader from Objective Development, the same guys that
   wrote the AVR-USB-driver:
   [4]http://www.obdev.at/products/avrusb/usbasploader.html

   The reason why I chose this over some other available USB-bootloaders
   is, that this one emulates a common ISP-programmer that is supported by
   avrdude. In this way, the same program can be used to program the chip
   that is used without a bootloader.

   To prepare the ATmega32, you have to connect it to your computer with
   the ISP-programmer of your choice and modify the makefile according to
   that. Then you enter the bootloader-directory and enter the following
   line:

 make fuse && make flash && make lock

   With 'fuse' you prepare the fuse-bits of your AVR, 'flash' transfers
   the bootloader to the device and 'lock' prevents you from overwriting
   the bootloader. Don't fear the locking: you can always reset it with
   your ordinary programmer. In fact, it is disabled in the moment you use
   your ordinary programmer to reflash the device, even without any
   special parameters. The locking only affects the bootloader behavior.

   Afterwards you can put the programmer back into the toolbox, you won't
   need it from here on.

   When you plug in the device while holding the minus-key on the
   number-keypad pressed, the keyboard indicates that it would like to get
   a new firmware by showing a running light on the LEDs. That firmware
   will be flashed over the normal USB-cable that the keyboard is
   connected with.

  Firmware

   If you intend to recompile the firmware yourself, you will need avr-gcc
   and avr-libc (a C-library for the AVR controller). Please read the
   instructions at
   [5]http://www.nongnu.org/avr-libc/user-manual/install_tools.html for
   how to install the GNU toolchain (avr-gcc, assembler, linker etc.) and
   avr-libc.

   Once you have the GNU toolchain for AVR microcontrollers installed, you
   can run "make" in the subdirectory "firmware".

   Afterwards -- or if you decided not to compile the firmware yourself --
   you can flash it to the device:

 make program

   Remember that you have to start the bootloader at first: unplug the
   keyboard, hold the minus-key on the number-keypad pressed and replug
   it. If the modified keyboard is the only one within reach: good luck!
   ;-)

Usage

   Connect the keyboard to the USB-port. All LED should flash up to
   indicate that the device is initialized.

   Then you can use the keyboard as always. If additional features get
   implemented, you will be able to use them in their respective ways.

Drawbacks

   I don't know if and how keyboard manufacturers face the problem of
   ghost keys, I didn't take special measurements for this. I hope that
   the engineers at IBM distributed the keys on the matrix in a way that
   minimizes this problem. Don't misunderstand: I haven't experienced that
   on this keyboard, but I know that it's a common problem on
   key-matrixes.

Files in the distribution

     * Readme.txt: Documentation, created from the htmldoc-directory.
     * firmware: Source code of the controller firmware.
     * firmware/usbdrv: USB driver -- See Readme.txt in this directory for
       info.
     * bootloader: The USBaspLoader, properly configured for this project.
       I only modified the [6]bootloaderconfig.h and the Makefile.
     * USBaspLoader.2008-02-05.tar.gz: The unmodified bootloader sources,
       for reference.
     * circuit: Circuit diagrams in PDF and KiCAD format. KiCAD is a free
       schematic- and layout-tool, you can learn more about it at its
       homepage: [7]http://www.lis.inpg.fr/realise_au_lis/kicad/
     * License.txt: Public license for all contents of this project,
       except for the USB driver. Look in firmware/usbdrv/License.txt for
       further info.
     * Changelog.txt: Logfile documenting changes in soft-, firm- and
       hardware.
     * refman.pdf: Full documentation of the software.

Thanks!

   I'd like to thank Objective Development for the possibility to use
   their driver for my project. In fact, this project wouldn't exist
   without the driver.

   And of course I'd like to thank that friend of mine -- I doubt that
   he'd like to read his name in this place, I'll put it in if he wants me
   to -- that gave me the idea for this project.

About the license

   My work - all contents except for the USB driver - is licensed under
   the GNU General Public License (GPL). A copy of the GPL is included in
   License.txt. The driver itself is licensed under a special license by
   Objective Development. See firmware/usbdrv/License.txt for further
   info.

   (c) 2008 by Ronald Schaten - [8]http://www.schatenseite.de
     __________________________________________________________________


    Generated on Sat Jul 12 22:27:14 2008 for Dulcimer by  [9]doxygen
    1.5.4

References

   1. file://localhost/home/rschaten/microcontroller/dulcimer/htmldoc/main.html
   2. file://localhost/home/rschaten/microcontroller/dulcimer/htmldoc/annotated.html
   3. file://localhost/home/rschaten/microcontroller/dulcimer/htmldoc/files.html
   4. http://www.obdev.at/products/avrusb/usbasploader.html
   5. http://www.nongnu.org/avr-libc/user-manual/install_tools.html
   6. file://localhost/home/rschaten/microcontroller/dulcimer/htmldoc/bootloaderconfig_8h.html
   7. http://www.lis.inpg.fr/realise_au_lis/kicad/
   8. http://www.schatenseite.de/
   9. http://www.doxygen.org/index.html
