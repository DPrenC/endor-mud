/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PUB;

create(){
    ::create();
    SetIntShort("la taberna de guerreros");
    SetIntLong(
        "No parece un sitio muy hospitalario que digamos. Decenas de guerreros con "
        "armas afiladas se reunen alrededor de las mesas a contar sus hazañas.\n  De vez"
        " en cuando, siempre hay algún altercado pero que normalmente no pasa a mayores"
        " ya que nos encontramos en una ciudad neutral.\n  Si quieres probar algún tipo"
        " de mejunge extraño has llegado al sitio correcto y no se te ocurra pedir nada"
        " de menos de 30 grados de alcohol.\n");
    SetIntBright(30);
    SetIntNoise("Todo el mundo habla de sus victorias y combates.\n");
    SetIntSmell("No puedes saber exactamente a que huele, pero huele mal.\n");

    AddDetail(({"taberna","pub","garito","habitacion", "habitacion"}),
        "Esta taberna es muy particular, las paredes están adornadas con todo tipo de"
        " armaduras, espadas, hachas, etc..  Una giganta sirve a estos energumenos sus"
        " bebidas mientras recibe toda clase de insinuaciones y otras cosas no muy"
        " afectivas.\n");
    AddDetail(({"guerreros","guerrero","gente","clientes"}),
        "Los guerreros se reunen alrededor de las mesas para charlar mientras se toman"
        " varias jarras de bebidas lo bastante fuertes como para tumbar a un gigante.\n");
    AddDetail(({"mesas","mesa"}),
        "Son unas simples mesas redondas de madera algo demacradas.\n");
    AddDetail(({"paredes","pared"}),
        "Estan llenas de armas colgadas, tantas que se podría armar a un grupo de 20"
        " personas sin problemas.\n");

    AddDrink("cerveza","una",4,5,6,0,"Te bebes una cerveza bien fresquita.");
    AddDrink("grog","una jarra de",3,8,4,0);
    AddDrink("vino rancio","un vaso de",2,4,2,0,"Uarrgghh.. esta asqueroso.");
    AddDrink("yith-pen","un vaso de",8,2,5,0,
          "Sabe a leche con almendras pero es muy refrescante y sabroso.");
    AddDrink("whisky","un vaso de",1,7,2,0);
    AddDrink("orujo","un vaso de",3,10,1,0,
          "Notas como el orujo te va quemando la garganta lentamente.\n");
    AddDrink("agua margarita","un vaso de",4,9,3,0,
          "¿Cómo algo con un nombre tan exótico puede tener un sabor tan malo?.\n");

    SetKeeper("/d/goldhai/comun/pnj/crowy/tabernera_crowy");
    AddExit("oeste",CROWY("calle13"));
    SetLocate("Crowy");
}
