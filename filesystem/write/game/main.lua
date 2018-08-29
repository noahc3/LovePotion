function love.load()
    myString = [[
        I don't even know what I should put here.
        Seriously, there's no creativity in this at all.
        Could meme, but what's the point?
        After all, it's free real estate.
    ]]

    myFile = love.filesystem.newFile("exists.txt", "w")
    myFile:write(myString)
    myFile:flush()
    myFile:close()
end

function love.update(dt)

end

function love.draw()
    love.graphics.print("Wrote this to a file:\n\n" .. myString, 100, 100)
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