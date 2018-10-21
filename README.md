# Löve Kit

Love Kit is a Love Potion fork with a focus on creating utility applications for the Nintendo Switch

Many people want to create utilities for the Switch but could not be bothered to learn C/C++. LovePotion has great graphical rendering abilities using an easy to learn language, but has many restrictions in system level functionality. This fork aims to remove those restrictions and add useful utility functions.

See [the original repo](https://github.com/TurtleP/LovePotion) for details on LovePotion itself. This readme will only cover changes made to LovePotion.

### Changes

 * Filesystem restrictions removed.
    * LovePotion usually restricts file reading/writing to your NRO's directory (ex. you can only write to the /switch folder and subdirectories). This fork removes those restrictions, giving you full access to SDMC and ROMFS.
    * By default, paths without a specified mountpoint are redirected to the SD card. You can use mountpoints sdmc: or romfs: to specify which mount point to use (ex. romfs:/some/path.jpg)
 * Unzip functionality added

### Unzip functionality

love.filesystem.unzip(string source, string destination)

callback unzipUpdate(int currentValue, int maxValue)

callback unzipDone()

The unzip function runs on another thread to keep the UI thread unblocked. The function will call unzipUpdate(int currentValue, int maxValue) each time a file is extracted, and unzipDone() when the extraction is complete.

Example:
```lua
zipProgress = 0
zipMax = 1

function love.gamepadpressed(joy, button)
    if button == "plus" then
            love.filesystem.unzip("/switch/retroarch_installer/retroarch.zip", "/")
    end
end

function unzipUpdate(currentValue, maxValue)
   zipProgress = currentValue
   zipMax = maxValue
end

function unzipDone()
    nextPage()
end

function love.draw()
    ...
    
    love.graphics.setColor(1, 1, 1)
    printc( "Installing RetroArch (" .. (zipProgress + 1) .. "/" .. zipMax .. ") ", 640, 300, 1280 )
    progressBar(240, 350, 800, 20, (zipProgress + 1), zipMax)
    
    ...
end
```

### License

License changed from MIT to GPL3 to comply with license for code used from [joel16's NX-Shell](https://github.com/joel16/NX-Shell)
