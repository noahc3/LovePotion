function love.load()

end

function love.update(dt)

end

function love.draw()
    love.graphics.setColor(1, 1, 1)
    love.graphics.print("Shapes!", 100, 100)

    love.graphics.setColor(1, 1, 0)
    love.graphics.rectangle("fill", 100, 150, 100, 100)

    love.graphics.setColor(0.5, 0, 0.8)
    love.graphics.circle("fill", 300, 200, 10)

    love.graphics.setColor(0, 1, 0)
    love.graphics.rectangle("line", 100, 400, 100, 100)

    love.graphics.setColor(0.33, 0.8, 0.9)
    love.graphics.circle("line", 300, 350, 10)
end

function love.gamepadpressed(joy, button)
    if button == "plus" then
        love.event.quit()
    end
end