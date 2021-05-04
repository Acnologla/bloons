type dificulty = Easy | Medium | Hard

type mapDificulty = Normal | Intermediary | Advanced | Extreme

type monkey = {
    name: string,
    mapDificulty: list(mapDificulty),
    dificulty: list(dificulty),
    description: string,
    path: string
}

let monkeys = [
    {
        name: "Macaco Dardo",
        path: "000",
        mapDificulty: [Advanced, Extreme],
        dificulty: [Hard], 
        description: "Bom macaco para voce colocar no inicio do jogo em dificuldades e mapas dificeis."
    },
    {
        name: "Macaco Bumerangue",
        path: "024",
        mapDificulty: [Normal],
        dificulty: [Medium, Hard],
        description: "Lança um bumerangue que segue um caminho curvo. Atinge uma camada de 3 bloons."     
    },
    {
        name: "Usina de Espinhos",
        path: "025",
        mapDificulty: [Normal,Intermediary,Advanced, Extreme],
        dificulty: [Hard],
        description: "Otimo contra bloons de ceramicas e DDTS."     
    },
    {
        name: "Macaco Ninja",
        path: "402",
        mapDificulty: [Normal, Intermediary],
        dificulty: [Medium, Hard],
        description: "Bom contra todos os bloons sem blindagem."     
    },
    {
        name: "Bombardeiro",
        path: "040",
        mapDificulty: [Advanced, Extreme],
        dificulty: [Hard], 
        description: "Bom macaco para o round 40."
    },  
    {
        name: "Macaco de Gelo",
        path: "024",
        mapDificulty: [Extreme],
        dificulty: [Easy, Medium,Hard], 
        description: "Bom macaco para mapas reduzidos."
    },
    {
        name: "Cospe Cola",
        path: "420",
        mapDificulty: [Normal, Intermediary],
        dificulty: [Easy, Medium, Hard], 
        description: "Bom macaco para mapas faceis."
    },
    {
        name: "Helicoptero",
        path: "203",
        mapDificulty: [Normal, Intermediary, Advanced, Extreme],
        dificulty: [Hard],
        description: "Helicoptero que segura MOABs e segue os baloes."     
    }, 
    {
        name: "Super Macaco",
        path: "203",
        mapDificulty: [Intermediary, Advanced, Extreme],
        dificulty: [Medium, Hard],
        description: "Super Macaco bom contra bloons de ceramica e MOABs"     
    },
    {
        name: "Mago",
        path: "302",
        mapDificulty: [Normal, Intermediary, Advanced, Extreme],
        dificulty: [Easy, Medium, Hard],
        description: "Lança raios mágicos que estoura 2 bloons, bom para todos os mapas."     
    },
    {
        name: "Druida",
        path: "401",
        mapDificulty: [Advanced, Extreme],
        dificulty: [Hard],
        description: "Druida bom contra bloons de ceramica."     
    }
]

let pathToStr = (path) => 
    Js.String.split("", path) 
    |> Array.to_list 
    |> String.concat("-")

let printInfoAboutMap = (dificulty, mapDificulty) => {
    List.(filter((monkey) => {
        exists((==)(dificulty), monkey.dificulty) && exists((==)(mapDificulty), monkey.mapDificulty)
    } , monkeys))
    |> List.iter(monkey => Js.log("[" ++ pathToStr(monkey.path) ++"] " ++ monkey.name ++ "\n" ++ monkey.description ))
}

printInfoAboutMap(Hard, Advanced)
