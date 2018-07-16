# Love Potion Examples Repo

This repository is filled with various examples for use with Love Potiion.
- If you would like to request an example, please place an issue :)


## "Dependencies"
- You'll need devkitpro-pacman installed
    - Follow [these](http://switchbrew.org/index.php?title=Setting_up_Development_Environment) instructions from the official switchbrew wiki to do this

### Switch
- Install the `switch-dev` bundle: `sudo (dkp-)pacman -S switch-dev`.

### 3DS
- Install the `3ds-dev` bundle: `sudo (dkp-)pacman -S 3ds-dev`.

### Rsync
- Make sure `rsync` is also present on the system. Try running it.
    - If it doesn't exist, install it through your package manager.
    - This allows copying your Lua files properly to avoid any dotfiles.

## Compiling your Game or Examples

1. Download the latest Switch release as an *.elf file [here](https://github.com/TurtleP/LovePotion/releases).
2. Place it at the top level of a directory where you will put your personal Love Potion projects.
3. Set the `LOVEPOTION_3DS` and/or `LOVEPOTION_SWITCH` environment variable as an absolute path to the *.elf file(s) from the last step, appropriately.
4. Change to any of the example directories and run `make`

Once the \*.nro/\*.3dsx is built, you may use ftpd or nxlink/3dslink to transfer it to your device.