/*****************************************************************************************
 ARCHIVO:       parra.c
 AUTOR:         Ztico & Kastwey
 FECHA:         03-06-2006
 DESCRIPCIÓN:   Una preciosa parra mágica.

*****************************************************************************************/

#include "./path.h"
#include <properties.h>
#include <moving.h>

inherit THING;

private int hay_racimo = 1;

public string f_mirar_racimo();
public int cmd_coger(string str);

create()
{
    if(::create()) return 1;

    seteuid(getuid());
    SetShort("una parra mágica");
    SetLong("Se trata de una parra mágica. Tiene la virtud de aislar del mundo exterior "
        "al individuo que se arrope entre sus nudosas ramas. Ésta en concreto, se "
        "destaca por su gran altura, y por enredarse firmemente sobre un soporte "
        "invisible. Se alza majestuosa, casi burlando a la gravedad, dándote la "
        "sensación de un gran edificio de intrincadas formas que se sostiene gracias a "
        "una fuerza mágica y misteriosa. Aquí y allá puedes ver grandes racimos cargados "
        "de apetitosas uvas, que al mirar, provocan en ti un sentimiento de intensa "
        "alegría, mezclada con nostalgia de alguna época que no eres capaz de precisar. "
        "Sin duda la magia está presente en esta magnífica construcción de la "
        "naturaleza, en formas sutiles e insospechadas.\n");
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    AddId(({"parra", "parra mágica"}));
    AddSubDetail(({"racimos", "racimo", "rácimos", "rácimo"}), 
    "La parra está repleta de grandes racimos de uvas.\n");
    Set(P_NOTAKE, 1);
}

public int cmd_coger(string str)
{
    string str1;
    object racimo;

    if(!str) return 0;
    if(!str || (str != "racimo" && str != "racimo de parra" && str != "rácimo" &&
                str != "racimo de la parra"))
    {
        return 0;
    }
    if(hay_racimo)
    {
        if(present("racimo_uvas", TO))
        {
            hay_racimo = 0;
            return 0;
        }
        write("Coges un racimo de uvas de la parra.\n");
        say(CAP(TNAME) + " coge un racimo de uvas de la parra.\n");

        racimo = clone_object(OBJ_COMIDA_VALINOR("racimo.c"));
        if(racimo->move(TP) != ME_OK)
        {
            write("No puedes llevar más peso. Sin poder evitarlo, el racimo se te cae "
                "al suelo.\n");
            say("Sin poder evitarlo, a " + CAP(TNAME) + ", se le cae un racimo al "
                "suelo.\n");
            racimo->move(TO);
            hay_racimo = 0;
            return NOTIFY_NOT_VALID;
        }
        hay_racimo = 0;
        return 1;
    }
    else
    {
        return notify_fail("Los racimos están demasiado altos y no puedes alcanzar.\n",
                           NOTIFY_NOT_VALID);
    }
}

public varargs void init()
{
    ::init();

    add_action("cmd_coger", "coger");
}

reset()
{
    hay_racimo = 1;
}
