# Love Potion Examples Repo

This repository is filled with various examples for use with Love Potiion.
- If you would like to request an example, please place an issue :)


## Pacman
- You'll need devkitpro-pacman installed
    - Follow [these](http://switchbrew.org/index.php?title=Setting_up_Development_Environment) instructions from the official switchbrew wiki to do this

### Packages
- Install the following via `sudo (dkp-)pacman -S <name>`:
    - devkit-env
    - general-tools
    - 3dstools
    - switchtools

## Compiling your Game or Examples

1. Download the latest Switch or 3DS release as a *.elf (if applicable) [here](https://github.com/TurtleP/LovePotion/releases).
2. Place it at the top level of a directory where you will put your personal Love Potion projects.
3. Set the `LOVEPOTION_3DS` and/or `LOVEPOTION_SWITCH` environment variable as an absolute path to the *.elf file(s) from the last step.
4. Change to any of the example directories and run `make`

Once the \*.nro/\*.3dsx is built, you may use ftpd or nxlink/3dslink to transfer it to your device.
All of the examples currently are using the Switch template, but can be easily swapped for the 3DS one.