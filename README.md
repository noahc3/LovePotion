# Love Potion Examples Repo

This repository is filled with various examples for use with Love Potiion.
- If you would like to request an example, please place an issue :)


## "Dependencies"
- You'll need devkitpro-pacman installed with the `switch-dev` bundle.
    - Follow [these](http://switchbrew.org/index.php?title=Setting_up_Development_Environment) instructions from the official switchbrew wiki to do this

- Once installed, make sure `rsync` is also present on the system.
    - This allows copying your Lua files properly to avoid any dotfiles.

## Compiling your Game or Examples

1. Download the latest Switch release as an *.elf file [here](https://github.com/TurtleP/LovePotion/releases).
2. Place it at the top level of a directory where you will put your personal Love Potion projects.
3. Set the `LOVEPOTION_ELF` environment variable as an absolute path to the *.elf file from the last step.
4. Change to any of the example directories and run `make`

Once the *.nro is built, you may use ftpd or nxlink to transfer it to your Switch.