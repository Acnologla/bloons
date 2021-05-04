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
        name: "Macaco dardo",
        path: "000",
        mapDificulty: [Advanced, Extreme],
        dificulty: [Hard], 
        description: "Bom macaco para voce colocar no inicio do jogo em dificuldades e mapas dificeis"
    },
    {
        name: "Bombardeiro",
        path: "040",
        mapDificulty: [Advanced, Extreme],
        dificulty: [Hard], 
        description: "Bom macaco para o round 40"
    },  
    {
        name: "Macaco de gelo",
        path: "024",
        mapDificulty: [Extreme],
        dificulty: [Easy, Medium,Hard], 
        description: "Bom macaco para mapas pequenos"
    },
    {
        name: "Cospe cola",
        path: "420",
        mapDificulty: [Normal, Intermediary],
        dificulty: [Easy, Medium, Hard], 
        description: "Bom macaco para mapas faceis"
    },
    {
        name: "Helicoptero",
        path: "203",
        mapDificulty: [Normal, Intermediary, Advanced, Extreme],
        dificulty: [Hard],
        description: "Helicoptero que segura MOABs e segue os baloes."     
    }, 
    {
        name: "Super macaco",
        path: "203",
        mapDificulty: [Intermediary, Advanced, Extreme],
        dificulty: [Medium, Hard],
        description: "Super macaco bom contra bloons de ceramica e moabs"     
    },
    {
        name: "Druida",
        path: "401",
        mapDificulty: [Advanced, Extreme],
        dificulty: [Hard],
        description: "Druida bom contra bloons de ceramica"     
    },{
        name: "Usina de espinhos",
        path: "025",
        mapDificulty: [Normal,Intermediary,Advanced, Extreme],
        dificulty: [Hard],
        description: "Otimo contra bloons de ceramicas e ddts"     
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