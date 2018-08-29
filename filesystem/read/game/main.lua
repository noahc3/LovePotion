function love.load()
    myFile = love.filesystem.newFile("linux.txt", "r")
    content = myFile:read()
    myFile:close()
end

function love.update(dt)

end

function love.draw()
    love.graphics.print("Contents of 'linux.txt':\n\n" .. content, 100, 100)
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