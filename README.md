# Löve Potion

LovePotion fork with unzip functionality added to Switch version.

See [the original repo](https://github.com/TurtleP/LovePotion) for details on LovePotion itself.

### Unzip functionality

love.filesystem.unzip(string source, string destination)

unzip will update zipProgress and zipMax integer values with the number of the current file being worked on and the total number of files needing to be worked on once every second. It will also force a single UI refresh for progress bars and such.

Example:
```lua
function love.gamepadpressed(joy, button)
    if button == "plus" then
            love.filesystem.unzip("/switch/retroarch_installer/retroarch.zip", "/")
    end
end

function love.draw() {
    ...
    
    love.graphics.setColor(1, 1, 1)
    printc( "Installing RetroArch (" .. (zipProgress + 1) .. "/" .. zipMax .. ") ", 640, 300, 1280 )
    progressBar(240, 350, 800, 20, (zipProgress + 1), zipMax)
    
    ...
}
```

### License

License changed from MIT to GPL3 to comply with license for code used from [joel16's NX-Shell](https://github.com/joel16/NX-Shell)
