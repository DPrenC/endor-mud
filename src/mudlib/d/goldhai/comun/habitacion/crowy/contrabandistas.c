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
    SetIntShort("la taberna de contrabandistas");
    SetIntLong("   La taberna la Daga Sangrienta es uno de los tugurios con peor "
        "reputación de Crowi.  Bandidos, salteadores, mercenarios y toda clase de "
        "rufianes forman la clientela, intercambiando  botín, historias de sus viajes "
        "y aventuras, e informaciónes que luego emplean para mejor llevar a cabo sus "
        "fechorías.\n En una de las paredes, balanceándose de un oxidado clavo hay una "
        "tabla con el cartel que da nombre a la taberna, y que anima o disuade a "
        "permanecer, aquí dentro, a los viajeros según su grado de honrradez.\n El local"
        " consta de una gran sala en la que se amontonan mesas y bancos destartalados "
        "que parecen no haber visto un trapo limpio en varias décadas. El  suelo está"
        " hecho de viejas tablas que crujen y chirrían de todas las maneras posibles "
        "cuando se avanza por ellas, y cubierto de una capa de serrín tan antiguo como "
        "la misma ciudad de Crowi. \n");
    AddDetail("cartel", "Es el tosco dibujo  de una mano empuñando una larga daga "
        "tinta en sangre.\n");
    SetIndoors(1);
    SetIntBright(20);
    SetIntNoise("Todos hablan muy bajito como si quisieran que nadie les oyera.\n");
    SetIntSmell("Es el típico olor de taberna asquerosa.\n");
    AddDetail(({"paredes","pared"}),
        "Son simples paredes de piedra sin ningún ornamento colgado, exceptuando el "
        "cartel.\n");
    AddDetail(({"contrabandistas","contrabandista","gente"}),
        "Parecen tipos sin escrúpulos que serían capaces de vender un brazo propio si"
        " sacaran un buen provecho.\n  Problemas con piratas, objetos valiosos que "
        "quieres conseguir, te persigue la justicia, etc... estos tipos se encargan "
        " de cualquier cosa, lo único que tienes que hacer es hablar con la persona "
        "adecuada.\n");
    SetKeeper(PNJ_CROWY("tabernero_contrabandista"));
    AddDrink("cerveza","una",4,5,6,0,"Te bebes una cerveza bien fresquita.");
    AddDrink("vino","un vaso de",2,5,3,0);
    AddDrink("agua","un vaso de",3,0,12,0,
        "Te bebes un vaso de agua bien refrescante.");
    AddDrink("yith-pen","un vaso de",8,2,5,0,
        "Sabe a leche con almendras pero es muy refrescante y sabroso.");
    AddDrink("whisky","un vaso de",1,7,2,0);
    AddFood("pollo","una porción de",10,12,0);
    AddFood("conejo","una porción de",8,10,0);
    AddFood("jabali","una pata de",9,13,0);
    AddFood("souffle de ternera","una porción de",11,9,0);
    AddFood("kribbat","una porción de",6,10,60,
        "Es algo crujiente y que tiene un sabor como de carne de cerdo empanada de"
        " arroz poco hecho. Está bastante bueno.");

    AddExit("oeste",CROWY("calle18"));

    AddItem(PNJ_CROWY("contrabandista1"),REFRESH_DESTRUCT);
    AddItem(PNJ_CROWY("contrabandista2"),REFRESH_DESTRUCT);
    AddItem(PNJ_CROWY("salteador"),REFRESH_DESTRUCT);

   SetLocate("Crowy");
}
