-- need fix format

function print_table(t)
    if type(t) ~= "table" then
        error(line .. "type wrong")
    end

    local n = table.maxn(t)
    print("table")
    print("{")
    for i=1,n do
        if type(t[i]) == "table" then
            print("[" .. i .. "]" .. "=>")
            print_table(t[i])
        else
            print("[" .. i .."]" .. "=>" .. t[i])
        end
    end
    print("}")
end

t = {1,{1,2,3.5,"2"},3}

print_table(t)
