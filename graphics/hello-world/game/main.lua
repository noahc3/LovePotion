function love.load()

end

function love.update(dt)

end

function love.draw()
    love.graphics.print("Hello World!", 300, 300)
end

function love.gamepadpressed(joy, button)
    if button == "plus" then
        love.event.quit()
    end
end