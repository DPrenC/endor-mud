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
        "reputaci�n de Crowi.  Bandidos, salteadores, mercenarios y toda clase de "
        "rufianes forman la clientela, intercambiando  bot�n, historias de sus viajes "
        "y aventuras, e informaci�nes que luego emplean para mejor llevar a cabo sus "
        "fechor�as.\n En una de las paredes, balance�ndose de un oxidado clavo hay una "
        "tabla con el cartel que da nombre a la taberna, y que anima o disuade a "
        "permanecer, aqu� dentro, a los viajeros seg�n su grado de honrradez.\n El local"
        " consta de una gran sala en la que se amontonan mesas y bancos destartalados "
        "que parecen no haber visto un trapo limpio en varias d�cadas. El  suelo est�"
        " hecho de viejas tablas que crujen y chirr�an de todas las maneras posibles "
        "cuando se avanza por ellas, y cubierto de una capa de serr�n tan antiguo como "
        "la misma ciudad de Crowi. \n");
    AddDetail("cartel", "Es el tosco dibujo  de una mano empu�ando una larga daga "
        "tinta en sangre.\n");
    SetIndoors(1);
    SetIntBright(20);
    SetIntNoise("Todos hablan muy bajito como si quisieran que nadie les oyera.\n");
    SetIntSmell("Es el t�pico olor de taberna asquerosa.\n");
    AddDetail(({"paredes","pared"}),
        "Son simples paredes de piedra sin ning�n ornamento colgado, exceptuando el "
        "cartel.\n");
    AddDetail(({"contrabandistas","contrabandista","gente"}),
        "Parecen tipos sin escr�pulos que ser�an capaces de vender un brazo propio si"
        " sacaran un buen provecho.\n  Problemas con piratas, objetos valiosos que "
        "quieres conseguir, te persigue la justicia, etc... estos tipos se encargan "
        " de cualquier cosa, lo �nico que tienes que hacer es hablar con la persona "
        "adecuada.\n");
    SetKeeper(PNJ_CROWY("tabernero_contrabandista"));
    AddDrink("cerveza","una",4,5,6,0,"Te bebes una cerveza bien fresquita.");
    AddDrink("vino","un vaso de",2,5,3,0);
    AddDrink("agua","un vaso de",3,0,12,0,
        "Te bebes un vaso de agua bien refrescante.");
    AddDrink("yith-pen","un vaso de",8,2,5,0,
        "Sabe a leche con almendras pero es muy refrescante y sabroso.");
    AddDrink("whisky","un vaso de",1,7,2,0);
    AddFood("pollo","una porci�n de",10,12,0);
    AddFood("conejo","una porci�n de",8,10,0);
    AddFood("jabali","una pata de",9,13,0);
    AddFood("souffle de ternera","una porci�n de",11,9,0);
    AddFood("kribbat","una porci�n de",6,10,60,
        "Es algo crujiente y que tiene un sabor como de carne de cerdo empanada de"
        " arroz poco hecho. Est� bastante bueno.");

    AddExit("oeste",CROWY("calle18"));

    AddItem(PNJ_CROWY("contrabandista1"),REFRESH_DESTRUCT);
    AddItem(PNJ_CROWY("contrabandista2"),REFRESH_DESTRUCT);
    AddItem(PNJ_CROWY("salteador"),REFRESH_DESTRUCT);

   SetLocate("Crowy");
}
