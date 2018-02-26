# A very very ... simple library for 3 phase brushless dc motor

Version: 1.0.0 <br>
Release date: 2018-02-26 <br>

## Summary

This library is to drive  [Brushless DC Motor](https://en.wikipedia.org/wiki/Brushless_DC_electric_motor)  that interfaces with the
[Arduino](https://www.arduino.cc/)-compatible controller . It
makes simple to drive 3 phase DC motors.

## Getting started

### Hardware

The
[gizDuino](http://www.e-gizmo.net/oc/index.php?route=product/product&product_id=483) (*In my case*)
can be purchased on [e-Gizmo Mechatronix Central](www.e-gizmo.net/) website, Or any Arduino compatible board. Before continuing, careful reading of the product page as well as the [user's guide](http://e-gizmo.net/oc/kits%20documents/GIZDUINO%20FOLDER/MANUAL.zip) is
recommended.

### Software

Manual library installation :

1. Download the
   [latest release archive from GitHub](https://github.com/Tarsier-Marianz/Tarsier_BLDC/archive/master.zip)
   and decompress it.
2. Rename the folder "`Tarsier_BLDC-master`" to "`Tarsier_BLDC`".
3. Drag the "`Tarsier_BLDC`" folder into the "libraries" directory inside your
   Arduino sketchbook directory. You can view your sketchbook location by
   opening the "**File**" menu and selecting "**Preferences**" in the Arduino IDE. If
   there is not already a "**libraries**" folder in that location, you should make
   the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Example program

An example sketch is available that shows how to use the library.  You
can access it from the Arduino IDE by opening the "**File**" menu,
selecting "**Examples**", and then selecting "`Tarsier_BLDC`".  If
you cannot find these examples, the library was probably installed
incorrectly and you should retry the installation instructions above.


## Documentation

- `Tarsier_BLDC()` <br> Default constructor, selects the
  default pins as connected by the digital pins *5*, *6* and *7*.
- `Tarsier_BLDC(byte pin1, byte pin2, byte pin3)` <br>
  Alternate constructor for connections remapped by user on its desired configuration.
- `void setPins(byte pin1, byte pin2, byte pin3)` <br> Another alternate way to configure pin connection of the Arduino board to 3 phase BLDC motor.
- `void setDelay(int delayTime)` <br> Set time delay
- `void forward()` <br> Command to forward motor
- `void forward()` <br> Command to backward motor

### *Motor encoding sequence*
        int _sequence [6][3] = {
            {1, 1, 0},
            {1, 0, 0},
            {1, 0, 1},
            {0, 0, 1},
            {0, 1, 1},
            {0, 1, 0},
        };


Pin output encoding sequence can be found [here](http://elabz.com/brushless-dc-motor-with-arduino/)

## Example Program
See the demo inside **examples** sub-folder.

  - [DVD_3PhaseMotor](https://github.com/Tarsier-Marianz/Tarsier_BLDC/blob/master/examples/DVD_3PhaseMotor/DVD_3PhaseMotor.ino)


## Credits

[Elabz.com](http://elabz.com/brushless-dc-motor-with-arduino/) -for motor encoding sequence

[Visual Studio Code](https://code.visualstudio.com/
) - letting me to use a free Code Editor

[Arduino IDE](https://www.arduino.cc/en/Main/OldSoftwareReleases) - for code writing and uploading to a board.

