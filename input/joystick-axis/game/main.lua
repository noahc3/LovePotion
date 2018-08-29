function love.load()
    axes = 
    {
        left = {"None", 0},
        right = {"None", 0}
    }
end

function love.update(dt)

end

function love.draw()
    local i = 0
    for k, v in pairs(axes) do
        love.graphics.print("Stick " .. k .. ": " .. v[1] .. " " .. v[2], 100, 100 + (i * 18))
        i = i + 1
    end
end

function love.gamepadpressed(joy, button)
    if button == "plus" then
        love.event.quit()
    end
end

--Axes are strings, "leftx/lefty" "rightx/righty"
--Values are -1 -> 0 -> 1
function love.gamepadaxis(joy, axis, value)
    if axis:find("left") then
        axes.left[1] = axis
        axes.left[2] = value
    elseif axis:find("right") then
        axes.right[1] = axis
        axes.right[2] = value
    end
end