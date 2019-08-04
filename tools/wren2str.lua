-- One-liner to escape the string
local file = io.open(arg[1], "rb")
local output = io.open(arg[2], "w")

output:write("const char *" .. arg[3] .. " = ")

for line in file:lines() do
  output:write(string.format('%q "\\n"', line) .. '\n')
end

output:write ";"

file:close()
output:close()
