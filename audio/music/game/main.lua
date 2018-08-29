function love.load()
    jamImage = love.graphics.newImage("jam.png")
    jamQuads = {} --animation frames

    for i = 1, 2 do --automate loading in a way
        --Quads split an image into pieces (x, y, width, height, atlasWidth, atlasHeight)
        jamQuads[i] = love.graphics.newQuad((i - 1) * 480, 0, 480, 480, 960, 480)
    end

    --timer to control the animation
    jamTimer = 0
    jamQuadIndex = 1

    --Music MUST be streamed, otherwise it takes a lot of memory
    pantsMusic = love.audio.newSource("pants.ogg", "stream")
    pantsMusic:setLooping(true) --Let's loop
    pantsMusic:play()

    --Sets the background to teal
    love.graphics.setBackgroundColor(0.3, 0.5, 0.5)
end

function love.update(dt)
    jamTimer = jamTimer + 14 * dt

    --Sets out quad index based on the rate and amount of quads
    jamQuadIndex = math.floor(jamTimer % 2) + 1 --+1 because lua is 1-based inecies
end

function love.draw()
    --draw our animation, centered
    love.graphics.draw(jamImage, jamQuads[jamQuadIndex], (1280 - 520) / 2, (720 - 480) / 2)
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