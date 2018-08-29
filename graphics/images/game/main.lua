function love.load()
    my_image = love.graphics.newImage("swoof.png")
end

function love.update(dt)

end

function love.draw()
    --LOVE defaults the coordinates to 0, 0
    --Extra arguments include: quad, scaling (x or y), rotation, etc
    love.graphics.draw(my_image)
end

function love.gamepadpressed(joy, button)
    if button == "plus" then
        love.event.quit() --quit the app on pressing +
    end
end

function love.gamepadreleased(joy, button)

end

function love.gamepadaxis(joy, axis, value)

end
