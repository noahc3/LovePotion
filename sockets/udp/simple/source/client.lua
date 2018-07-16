local client = {}

function client:init(ip, port)
	self.socket = require "socket".udp()

	if not ip then
		ip = "localhost"
	end

	if love.system.getOS() ~= "HorizonNX" then
		self.socket:settimeout(0)
	end
	
	self.status = self.socket:setpeername(ip, port)

	local username, func = "NX-Tester", love.system.getUsername
	if func and func() then
		username = func()
	end

	self.socket:send("connect;" .. username)

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
	return self.status or "disconnected"
end

function client:sendData(data)
	self.socket:send(data)
end

return client