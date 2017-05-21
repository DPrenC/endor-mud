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

    AddDetail("suelo", "Abunda el tr�bol.\n");
    AddDetail(({"tr�bol", "trebol", "parcelas"}), "Hay unas peque�as y ondulantes "
        "parcelas de tr�boles rosados y purp�reos, y algunas de tr�bol dulce y blanco "
        "con olor a miel.\n");
    AddDetail(({"hierba", "hierba suave"}), "La hierba se eleva medio palmo sobre el "
        "suelo.\n");
    AddDetail(({"�rboles", "arboles", "�lamos", "alamos", "abedules", "olmos"}), "Hay "
        "gran variedad de especies de �rboles. Puedes ver esbeltos �lamos con troncos "
        "delgados y erguidos, altos abedules de amplias copas, cuyo follaje tiembla al "
        "menor soplo de brisa, algunos olmos que tienen unos abultamientos suberosos del "
        "mismo tejido que la corteza de sus troncos y otros con copas ligeras e "
        "infinidad de ramas finas y peque�as hojas pardas.\n");
    AddDetail("arcos", "Son muy irregulares y no muy altos.\n");
    SetIndoors(0);

    SetIntSmell(SF(f_oler));
    SetIntNoise("Escuchas susurros y c�nticos procedentes del interior del bosque.\n");

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

            new_int_long = "Est�s en un peque�o claro rodeado de �lamos, abedules y "
                "olmos que se aprietan unos contra otros. Ofrece un aspecto pac�fico "
                "bajo la intensa luz del sol. Entre los �rboles se abren tres arcos, "
                "hacia el norte, noroeste y nordeste, que sirven de entrada al bosque. "
                "El suelo est� cubierto por hierba suave y matas de tr�bol.\n";
            AddDetail("claro", "El claro es c�lido y sombreado, protegido por simp�ticos "
                "olmos, abedules y �lamos, en cuyo interior, p�jaros y ardillas han "
                "construido sus nidos.\n");
            break;

        //Luz Media: 20 -- 40
        case ND_DAWN:
        case ND_SUNRISE:
        case ND_PREFALL:
        case ND_FALL:

            new_int_long =  "Est�s en un peque�o claro rodeado de �lamos, abedules y "
                "olmos que se aprietan unos contra otros. Ofrece un aspecto pac�fico "
                "bajo la suave luz del sol. Entre los �rboles se abren tres arcos, "
                "hacia el norte, noroeste y nordeste, que sirven de entrada al bosque. "
                "El suelo est� cubierto por hierba suave y matas de tr�bol.\n";
            AddDetail("claro", "El claro es c�lido y sombreado, protegido por simp�ticos "
                "olmos, abedules y �lamos, en cuyo interior, p�jaros y ardillas han "
                "construido sus nidos.\n");
            break;

        //Luz Baja: 0 -- 10
        case ND_PRENIGHT:
        case ND_NIGHT:
        case ND_PREDAWN:

            new_int_long = "Est�s en un peque�o claro rodeado de �lamos, abedules y "
                "olmos que se aprietan unos contra otros. Entre los �rboles se abren "
                "tres arcos, hacia el norte, noroeste y nordeste, que sirven de entrada "
                "al bosque. El suelo est� cubierto por hierba suave y matas de tr�bol.\n";
            AddDetail("claro", "El claro es c�lido. Est� protegido por simp�ticos olmos, "
                "robles y fresnos, en cuyo interior p�jaros y ardillas han construido "
                "sus nidos.\n");
            break;

        default:

        	  new_int_long =  "Est�s en un peque�o claro rodeado de �lamos, abedules y "
                "olmos que se aprietan unos contra otros. Ofrece un aspecto pac�fico "
                "bajo la suave luz del sol. Entre los �rboles se abren tres arcos, "
                "hacia el norte, noroeste y nordeste, que sirven de entrada al bosque. "
                "El suelo est� cubierto por hierba suave y matas de tr�bol.\n";
            AddDetail("claro", "El claro es c�lido y sombreado, protegido por simp�ticos "
                "olmos, abedules y �lamos, en cuyo interior, p�jaros y ardillas han "
                "construido sus nidos.\n");
            break;
    }
    return new_int_long;
}

public string f_oler()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Este olor tan puro y fresco te repugna.\n";
    return "Te llega el aroma dulz�n del tr�bol.\n";
}
