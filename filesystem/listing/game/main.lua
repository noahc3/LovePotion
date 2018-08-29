function love.load()
    directoryListing = love.filesystem.getDirectoryItems("")

    infoString = "Directory Listing:\n"
    infoString = infoString .. table.concat(directoryListing, ",\n")
end

function love.update(dt)

end

function love.draw()
    love.graphics.print(infoString, 100, 100)
end

function love.gamepadpressed(joy, button)
    if button == "plus" then
        love.event.quit()
    end
end

function love.gamepadreleased(joy, button)

end

function love.gamepadaxis(joy, axis, value)

end
