function love.load()
    touches = {}
end

function love.update(dt)

end

function love.draw()
    local j = 0
    for i, v in pairs(touches) do
        if v then --validate the position info, otherwise we skip drawing its info
            love.graphics.print("Touch #" .. j + 1 .. ": " .. v.x .. ", " .. v.y, 100, 100 + (j * 18))
            j = j + 1
        end
    end
    
    love.graphics.print("Touch the screen!", 100, 50)
end

function love.gamepadpressed(joy, button)
    if button == "plus" then
        love.event.quit()
    end
end

function love.touchpressed(id, x, y, dx, dy, pressure)
    if not touches[id] then --the touch isn't in our table
        touches[id] = {x = x, y = y} --adds it
    end
end

function love.touchreleased(id, x, y, dx, dy, pressure)
    if touches[id] then
        touches[id] = nil --remove this object value since it doesn't exist
    end    
end

function love.touchmoved(id, x, y, dx, dy, pressure)
    if touches[id] then
        touches[id] = {x = x, y = y} --update the position
    end
end