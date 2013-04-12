#!/usr/local/bin/lua


function list_iter(t)
        local i = 0
        -- in lua5.1 table has a interface getn,
        -- in lua5.2 the interface getn of table has be obsolete,we should use #n or maxn
        -- local n = table.getn(t)
        local n = table.maxn(t)
        -- local n = #t
        return function()
                i = i + 1
                if i <= n then return t[i] end
        end
end


helpful_guys = {
        "----参与翻译----",
        "buxiu","凤舞九天","zhang3",
        "morler","lambda","sunlight",
        "\n",

        "----参与校对----",
        "凤舞九天","doyle","flicker",
        "花生魔人","zhang3","Kasi",
        "\n"
}

for e in list_iter(helpful_guys) do
        print(e)
end
