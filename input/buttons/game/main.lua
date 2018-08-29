function love.load()
    currentButton =
    {
        pressed = "None",
        released = "None"
    }
end

function love.update(dt)

end

function love.draw()
    local i = 0
    for k, v in pairs(currentButton) do
        love.graphics.print(k .. ": " .. v, 100, 100 + (i * 18))
        i = i + 1
       end
end

function love.gamepadpressed(joy, button)
    if button == "plus" then
        love.event.quit()
    else
        currentButton.pressed = button
    end
end

function love.gamepadreleased(joy, button)
    currentButton.released = button
end