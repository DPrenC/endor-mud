/****************************************************************************
Fichero: shilda.c
Autor: Kastwey
Fecha: 28/03/2006
Descripci�n: Shilda, la gran kisala
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <gremios.h>
#include <rooms.h>



inherit NPC;

create()
{
    ::create();
    SetStandard("Shilda","elfo",([GC_KISALA:100]), GENDER_FEMALE);
    SetShort("Shilda, la Gran Kisala");
    SetLong("Shilda es uno de los seres m�s hermosos que habitan en Simauria. Es una elfa "
            "de casi dos metros de altura. Su cuerpo es una oda a la belleza, "
            "a la vez que est� debidamente curtido por el duro entrenamiento que "
            "llevan las Kisalas. Sus ojos, de un misterioso verde oliva, producen "
            "una maravillosa hipnosis en aquel que osa fijar la mirada en ellos, "
            "mientras que su tupida y larga cabellera negra le cae por la espalda, "
            "recogida en una trenza con un broche de oro casi tan sublime como su "
            "portadora. Sobre su esbelto cuerpo descansa una sencilla pero bonita "
            "t�nica hasta sus rodillas, con un s�mbolo en el pecho.\n");

    SetIds(({"shilda", "Shilda", "kisala", "guildmaster", "gran kisala", "elfa"}));
    Set(P_CANT_FIGHT,1);
    Set(P_CANT_STEAL,1);

    AddItem(AM_OBJETO("broche_guildmaster"), REFRESH_REMOVE, 1, SF(wearme));
    AddItem(AM_OBJETO("tunica_guildmaster"), REFRESH_REMOVE, 1, SF(wearme));

}
public int cmd_matar(string str)
{
    if (!str || member(QueryIds(), str) < 0 || present(str, environment()) != TO) return 0;
    write("Cuando te preparas para avalanzarte contra Shilda, la gran Kisala "
          "parece hacerse el doble de grande que t�, mientras te mira con ojos "
          "fr�os cual t�mpanos de hielo. Con voz g�lida y pausada te pregunta: "
          "'�De verdad crees que en un enfrentamiento podr�as hacerme da�o?'\n"
          "Tras sopesarlo, decides que no es prudente seguir adelante. Al instante, "
          "Shilda parece reducirse hasta su tama�o natural, mientras te "
          "sonr�e como si nada hubiese pasado.\n");
    say("Shilda mira a " + CAP(TNAME) + " quien palidece por momentos. La gran kisala "
        "le dice con tono glacial: '�De verdad crees que en un enfrentamiento podr�as "
        "hacerme da�o?'\n" +
        CAP(TNAME) + " retrocede varios pasos mientras su cara toma un color a�n m�s "
        "p�lido. Parece que hubiese visto un fantasma.\n", TP);
    return 1;
}

public int cmd_robar(string str)
{
    if (!str) return 0;
    if (str[..1] == "a ") str = str[2..];
    if (member(QueryIds(), str) < 0 || present(str, environment()) != TO) return 0;
    write("Shilda te mira y esboza una enigm�tica sonrisa... "
          "Es como si pudiese leer tus intenciones. Decides que quiz�s convenga elegir "
          "a otra v�ctima a la que robar.\n");
    say("Shilda mira a " + CAP(TNAME) + " y le sonr�e de forma enigm�tica.\n", TP);
    return 1;
}

    init()
{
    ::init();
    add_action("cmd_matar", "matar");
    add_action("cmd_robar", "robar");
}

