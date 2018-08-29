function love.load()
    local down, OS = "plus", {love.system.getOS()}
    if OS[2] == "3DS" then
        down = "start"
    end
    exitKey = down
end

function love.update(dt)

end

function love.draw()
    love.graphics.print("Hello World!", 10, 10)
end

function love.gamepadpressed(joy, button)
    if button == exitKey then
        love.event.quit()
    end
end
