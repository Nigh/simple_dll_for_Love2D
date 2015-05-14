

function love.load()
	lib=require("lovelib")
	print(lib.doubles(1234))
end

function love.update(dt)
	_dt=dt
end

function love.draw()
	love.graphics.printf(_dt, 1, 1,1)
	love.graphics.printf(lib.doubles(_dt),1,20,1)
	love.graphics.printf(lib.avr(1,2,3,6,7,8),1,40,1)
end
