/****************************************************************************
Fichero: jerton.c
Autor: Ratwor
Fecha: 22/07/2006
Un viejete para jugar a los dados.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <money.h>
inherit NPC;

public int cmd_apostar(string str)
{
    int tirada_player,tirada_pnj,cobres,apuesta;
    string *pagar;

    switch(str)
    {
        case "1": case "1 platino": case "1 pt": apuesta=1; break;
        case "2": case "2 platinos": case "2 pt": case "2 platino": apuesta=2; break;
        case "3": case "3 platinos": case "3 pt": case "3 platino": apuesta=3; break;
        case "4": case "4 platinos": case "4 pt": case "4 platino": apuesta=4; break;
        case "5": case "5 platinos": case "5 pt": case "5 platino": apuesta=5; break;
        default: return notify_fail("Jerton te dice: mejor apostamos de 1 a 5 platinos.\n");
    }
    cobres = apuesta * 1000;
    if (MONEY_LIB->QuerySomeonesValue(TP) >= cobres)
    {
        tirada_player = d6(3);
        tirada_pnj = d6(3);

        string *mensajes =
        ({"poniendo cara de ilusi�n", "con gran maestr�a", "como analizando lo que hace",
        "como si su vida dependiera de ello", "desinteresadamente", "con temor",
        "duditativamente", "como pensando en otra cosa", "con j�bilo", "con nervios",
        "con �nsia de ganar", "con la mirada perdida", "como temblando", "con fuerza",
        "con energ�a", "fuertemente", "murmurando algo",
        "diciendo en voz baja que va a ganar", "suspirando", "apretando los dientes",
        "poniendo una cara extra�a"});

        play_sound(environment(TP), SND_SUCESOS("lanzar_dados"));
        write ("Decides apostar " + apuesta + " platino" + (apuesta > 1 ? "s" : "") + ".\n"
            "Jerton agita el cubilete, "+mensajes[random(sizeof(mensajes))]+
            ", y tira los dados sacando "+tirada_pnj+ ", vuelve a meter los dados y "
            "te lo da para que hagas tu jugada.\n T� agitas tambi�n el cubilete y "
            "lanzas los dados sacando "+tirada_player+ ", metes nuevamente los dados "
            "en el cubilete y se lo devuelves a Jerton.\n");
        say (CAP(TP->QueryRealName()) + " decide apostar " + apuesta + " platino"
        + (apuesta > 1 ? "s" : "") + ".\n Jerton agita el cubilete, "
        + mensajes[random(sizeof(mensajes))]+", y lanza los dados sacando "+tirada_pnj+
        ", vuelve a meter los dados en el cubilete y se lo da a "+CAP(TNAME)+
        ", el cual tambi�n agita los dados y los lanza sacando "+tirada_player+
        ".\n Tras su jugada le devuelve el cubilete a Jerton.\n",TP);

        if (tirada_player == tirada_pnj)
        {
            tell_room (environment(), "Ambas tiradas han tenido el mismo resultado, por "
            "tanto no hay ganador ni perdedor, habr� que hacer otra apuesta...\n");
            return 1;
        }
        if (tirada_player < tirada_pnj)
        {
            write ("Has sacado menos puntuaci�n que Jerton y pierdes.\n");
            say (CAP(TP->QueryRealName()) + " ha sacado menos puntuaci�n en su tirada. "
            ".\n", TP);
            pagar = MONEY_LIB->PayValueString2(TP, cobres, 0, "a Jerton por perder la apuesta");
            write (pagar[0]);
            say (pagar[1], TP);
            return 1;
        }
        write ("Tu tirada es superior y Jerton te paga " +apuesta + " platino" +
        (apuesta > 1 ? "s" : "") + " no con buena cara.\n");
        say (CAP(TP->QueryRealName()) + " ha sacado m�s puntuaci�n en su tirada,y Jerton"
        ", con resignaci�n, le paga " + apuesta + "platino" + (apuesta > 1 ? "s" : "") +
        " por ganar la apuesta.\n", TP);
        object dinero;
        dinero = MONEY_LIB->QueryMoneyObject(TP);
        if (!dinero) { dinero = clone_object("/obj/money"); dinero->move(TP); }
        dinero->AdjustMoney((["platino":apuesta]));
        return 1;
    }
    return notify_fail("no te llega el dinero para esa apuesta.\n");
}

create()
{
    ::create();
    SetStandard("Jerton", "humano", 15, GENDER_MALE);
    SetShort("Jerton el pescador");
    SetLong("Jerton es un viejo pescador que ya no tiene el cuerpo para pescar y pasa "
    "las horas jugando a los dados, en algunas tabernas de la zona de Betwa y "
    "alrededores, con todo aquel que se preste a dedicarle un rato con su compa��a. "
    "Para jugar usa un cubilete de piel y unos dados de marfil que le trajo un amigo "
    "marinero de tierras lejanas, los cuales guarda con gran aprecio.\n");
    SetSmell("Huele un poco a sudor.\n");
    SetCitizenship("gorat");
    AddId(({"jerton", "pescador", "viejo", "anciano"}));
    InitChats(3, ({"Jerton se acaricia la barbilla pensativo.\n",
        "Jerton te pregunta: �jugamos?\n",
              "Jerton observa lo que le rodea.\n",
              "Jerton mueve el cubilete para ajitar los dados.\n",
              "Jerton te mira como queri�ndote decir algo.\n"}));
    AddQuestion("dados", "Jerton te dice: me los trajo un gran amigo de tierras lejanas.\n");
    AddQuestion(({"jugar", "juego"}), "Jerton te dice: es muy sencillo, escribes apostar "
               "m�s el n�mero de platinos que quieres apostar de entre 1 a 5, y el "
               "que saque m�s puntuaci�n con los dados gana la apuesta.\n");
    AddQuestion("apuesta", "Jerton te dice: mejor apostamos solo platinos y nos dejamos "
    "de l�os, me dices t� la cantidad de platinos que quieres jugar de entre 1 a 5.\n");
    AddQuestion("cubilete", "Jerton te dice: pues para ajitar los dados y no tenerlos en la mano.\n");
    SetShrugMsg("Jerton no parece entender la pregunta.\n");
    Set(P_CANT_STEAL, "Es un anciano, mejor r�bale a otro.\n"); //para  que no le roben el cubilete.
    AddItem(GOBJETO("otro/betua/cubilete"), REFRESH_REMOVE);
}

public void init()
{
    ::init();
    add_action("cmd_apostar", "apostar");
}
