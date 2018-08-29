function love.load()
    fedoraMan = love.graphics.newImage("meme.png")
    memeSound = love.audio.newSource("nicememe.ogg", "static")

    imageFade = 0.1
end

function love.update(dt)
    --hacky trick just to do this, but eh
    if not memeSound:isPlaying() then
        imageFade = 0.1
    end
end

function love.draw()
    --Setting the color to a low fade value
    --LOVE uses 0 -> 1 color ranges
    love.graphics.setColor(1, 1, 1, 1 * imageFade)
    love.graphics.draw(fedoraMan)
end

function love.gamepadpressed(joy, button)
    if button == "a" then
        --Don't play the sound if it's already playing
        if not memeSound:isPlaying() then
            imageFade = 1
            memeSound:play()
        end
    elseif button == "plus" then
        love.event.quit() --quit
    end
end

function love.gamepadreleased(joy, button)

end

function love.gamepadaxis(joy, axis, value)

end
