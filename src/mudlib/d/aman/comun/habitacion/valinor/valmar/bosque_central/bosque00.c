/*****************************************************************************************
 ARCHIVO:       bosque00.c
 AUTOR:         Ztico
 FECHA:         15-03-2005


******************************************************************************************/

#include "./path.h"
#include <nightday.h>

inherit HAB_VALMAR("hab_bosque.c");

public string change_long();
public string f_oler();


create()
{
    if(::create()) return 1;


    SetIntLong(SF(change_long));

    AddDetail("suelo", "Abunda el trébol.\n");
    AddDetail(({"trébol", "trebol", "parcelas"}), "Hay unas pequeñas y ondulantes "
        "parcelas de tréboles rosados y purpúreos, y algunas de trébol dulce y blanco "
        "con olor a miel.\n");
    AddDetail(({"hierba", "hierba suave"}), "La hierba se eleva medio palmo sobre el "
        "suelo.\n");
    AddDetail(({"árboles", "arboles", "álamos", "alamos", "abedules", "olmos"}), "Hay "
        "gran variedad de especies de árboles. Puedes ver esbeltos álamos con troncos "
        "delgados y erguidos, altos abedules de amplias copas, cuyo follaje tiembla al "
        "menor soplo de brisa, algunos olmos que tienen unos abultamientos suberosos del "
        "mismo tejido que la corteza de sus troncos y otros con copas ligeras e "
        "infinidad de ramas finas y pequeñas hojas pardas.\n");
    AddDetail("arcos", "Son muy irregulares y no muy altos.\n");
    SetIndoors(0);

    SetIntSmell(SF(f_oler));
    SetIntNoise("Escuchas susurros y cánticos procedentes del interior del bosque.\n");

    AddExit("noroeste", HAB_BOSQUE_CENTRAL("bosque01.c"));
    AddExit("norte", HAB_BOSQUE_CENTRAL("bosque02.c"));
    AddExit("noreste", HAB_BOSQUE_CENTRAL("bosque03.c"));


}

public string change_long()
{
    string new_int_long;

    switch(NIGHTDAY->QueryState())
    {
        //Luz Alta: 70 -- 100
        case ND_PRENOON:
        case ND_DAY:
        case ND_POSTNOON:

            new_int_long = "Estás en un pequeño claro rodeado de álamos, abedules y "
                "olmos que se aprietan unos contra otros. Ofrece un aspecto pacífico "
                "bajo la intensa luz del sol. Entre los árboles se abren tres arcos, "
                "hacia el norte, noroeste y nordeste, que sirven de entrada al bosque. "
                "El suelo está cubierto por hierba suave y matas de trébol.\n";
            AddDetail("claro", "El claro es cálido y sombreado, protegido por simpáticos "
                "olmos, abedules y álamos, en cuyo interior, pájaros y ardillas han "
                "construido sus nidos.\n");
            break;

        //Luz Media: 20 -- 40
        case ND_DAWN:
        case ND_SUNRISE:
        case ND_PREFALL:
        case ND_FALL:

            new_int_long =  "Estás en un pequeño claro rodeado de álamos, abedules y "
                "olmos que se aprietan unos contra otros. Ofrece un aspecto pacífico "
                "bajo la suave luz del sol. Entre los árboles se abren tres arcos, "
                "hacia el norte, noroeste y nordeste, que sirven de entrada al bosque. "
                "El suelo está cubierto por hierba suave y matas de trébol.\n";
            AddDetail("claro", "El claro es cálido y sombreado, protegido por simpáticos "
                "olmos, abedules y álamos, en cuyo interior, pájaros y ardillas han "
                "construido sus nidos.\n");
            break;

        //Luz Baja: 0 -- 10
        case ND_PRENIGHT:
        case ND_NIGHT:
        case ND_PREDAWN:

            new_int_long = "Estás en un pequeño claro rodeado de álamos, abedules y "
                "olmos que se aprietan unos contra otros. Entre los árboles se abren "
                "tres arcos, hacia el norte, noroeste y nordeste, que sirven de entrada "
                "al bosque. El suelo está cubierto por hierba suave y matas de trébol.\n";
            AddDetail("claro", "El claro es cálido. Está protegido por simpáticos olmos, "
                "robles y fresnos, en cuyo interior pájaros y ardillas han construido "
                "sus nidos.\n");
            break;

        default:

        	  new_int_long =  "Estás en un pequeño claro rodeado de álamos, abedules y "
                "olmos que se aprietan unos contra otros. Ofrece un aspecto pacífico "
                "bajo la suave luz del sol. Entre los árboles se abren tres arcos, "
                "hacia el norte, noroeste y nordeste, que sirven de entrada al bosque. "
                "El suelo está cubierto por hierba suave y matas de trébol.\n";
            AddDetail("claro", "El claro es cálido y sombreado, protegido por simpáticos "
                "olmos, abedules y álamos, en cuyo interior, pájaros y ardillas han "
                "construido sus nidos.\n");
            break;
    }
    return new_int_long;
}

public string f_oler()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Este olor tan puro y fresco te repugna.\n";
    return "Te llega el aroma dulzón del trébol.\n";
}
