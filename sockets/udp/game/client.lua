local client = {}

function client:init(ip, port)
    self.socket = require "socket".udp()

    local OS = {love.system.getOS()}
    if OS[2] ~= "Switch" then
        self.socket:settimeout(0)
    end
    
    self.status = self.socket:setpeername(ip, port)

    self.socket:send("connect;DatTester")

    self.ip = ip
    self.port = port

    self.online = true
end

function client:update(dt)
    local datagram = self.socket:receive()
    if datagram then
        local data = datagram:split(";")

        if data[1] == "pong" then
            self.status = "connected! " .. data[2] .. "!"
        end
    end
end

function client:isOnline()
    return self.online
end

function client:getStatus()
    local ret = "disconnected"
    if self.status == 1 then
        ret = "connected {" .. self.ip .. ":" .. self.port .. "}"
    else
        ret = tostring(self.status)
    end

    return ret
end

return client