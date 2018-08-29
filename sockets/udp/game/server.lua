local server = {}

function server:init(port)
    self.socket = require "socket".udp()
    
    local OS = {love.system.getOS()}
    if OS[2] ~= "Switch" then
        self.socket:settimeout(0)
    end

    self.status = self.socket:setsockname("*", port)

    self.clients = {}

    self.online = true
    self.reset = false

    self.resetTimer = 1

    self.ip = "*"
    self.port = port
end

function server:update(dt)
    local datagram, ip, port = self.socket:receivefrom()
    if datagram then
        local data = datagram:split(";")
        if data[1] == "connect" then
            table.insert(self.clients, {data[2], ip, port})

            self.status = data[2] .. " has connected via " .. ip .. ":" .. port

            self.reset = true
        end
    end

    if self.reset then
        --[[local ret = ""
        for i = 1, #self.clients do
            ret = ret .. self.clients[i][1] .. ";"
        end

        for i = 1, #self.clients do
            self.socket:sendto("pong;" .. ret, self.clients[i][2], self.clients[i][3])
        end]]

        self.reset = false
    end
end

function server:isOnline()
    return self.online
end

function server:getStatus()
    local ret = "disconnected"
    if self.status == 1 then
        ret = "connected {" .. self.ip .. ":" .. self.port .. "}"
    else
        ret = tostring(self.status)
    end

    return ret
end

return server