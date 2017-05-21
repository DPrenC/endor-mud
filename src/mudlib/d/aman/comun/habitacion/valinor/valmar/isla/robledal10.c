/*****************************************************************************************
 ARCHIVO:       robledal10.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:   Hacia el este, ventana de la posada02_hab1.c
*****************************************************************************************/

#include "./path.h"
#include <classes.h>
#include <moving.h>
#include <combat.h>

inherit BASE_ISLA;

private int hay_barrotes = 1;
private int ventana_cerrada = 1;

public string f_mirar_paredes();
public string f_mirar_ventana();
public string f_mirar_barrotes();
public int cmd_mover(string str);
public int cmd_usar(string str);
public int f_introducir(object arma, object pj);

create()
{
    if(::create()) return 1;

    SetIntShort("las cercanías de la posada");
    SetIntLong("No aciertas a ver nada a simple vista a causa de la intensa niebla que "
        "puebla el bosque. Hacia el este se encuentran las paredes exteriores de la "
        "posada 'El Unicornio Azul'. \n");
    AddDetail("niebla", "Todo está envuelto en una neblina casi permanente que seguro "
        "despierta fascinación y respeto.\n");
    AddDetail("paredes", SF(f_mirar_paredes));
    AddDetail("ventana", SF(f_mirar_ventana));
    AddDetail("barrotes", SF(f_mirar_barrotes));
    AddDetail("ranura", "Tiene el tamaño justo para que quepa un objeto afilado.\n");
    AddDetail(({"robles", "viejos robles"}), "Nunca habías visto antes unos robles tan "
        "altos y esbeltos como los de este bosque, la corteza de los troncos es "
        "blanquecina y están repletos de nudos.\n");
    AddDetail(({"árboles", "arboles"}), "Están cubiertos de líquenes, musgos, "
        "bromelias y orquídeas con flores de brillantes colores, así como por decenas "
        "de helechos.\n");
    AddDetail("helechos", "Son hermosos y gigantescos, de colores vivaces y "
        "alegres.\n");
    AddDetail("suelo", "No ves el suelo en el que pisas a causa de la niebla.\n");

    AddRoomCmd("mover", "cmd_mover");
    AddRoomCmd("usar", "cmd_usar");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal14.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal04.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal09.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal13.c"));
}

public string f_mirar_paredes()
{
    if(hay_barrotes)
        return "En una de ellas, hay una ventana protegida con barrotes.\n";
    else if(ventana_cerrada)
        return "En una de ellas, hay una ventana de madera y está cerrada.\n";
    return "En una de ellas, hay una ventana de madera y está abierta de par en par.\n";
}

public string f_mirar_ventana()
{
    if(ventana_cerrada)
        return "Está hecha de madera vieja, tiene una ranura en la parte inferior.\n";
    return "Está hecha de madera vieja, está abierta.\n";
}

public string f_mirar_barrotes()
{
    if(hay_barrotes)
        return "Están sujetos a la pared, pero no parecen muy firmes.\n";
    else if(present("barrotes"))
        return 0;
    return "Parece que han sido arrancados de la pared.\n";
}

public int cmd_mover(string str)
{
    object barrotes;

    if(!str || str != "barrotes")
        return notify_fail("¿Mover qué?\n");

    if(hay_barrotes)
    {
        if(TP->QueryStr() <= 20)
        {
            write("Forcejeas intentando arrancar los barrotes, pero te fallan las "
                "fuerzas.\n");
            say(CAP(TNAME) + " hace algo, pero la niebla te impide ver con detalle "
                "sus movimientos.\n");
            return 1;
        }
        write("Forcejeas unos instantes y los barrotes ceden con bastante facilidad.\n");
        say(CAP(TNAME) + " hace algo, pero la niebla te impide ver con detalle "
            "sus movimientos.\n");
        clone_object(OBJ_OTRO_VALINOR("barrotes.c"))->move(TO, M_SILENT);
        hay_barrotes = 0;
        return 1;
    }
    return notify_fail("No ves barrotes para mover.\n");
}

public int QueryBarrotes() { return hay_barrotes; }

public int cmd_usar(string str)
{
    string str1, str2, tipo_arma;
    object arma, pj;

    if(!ventana_cerrada) return 0;
    if(!str)
        return notify_fail("¿Usar <Qué> en <qué>?\n");
    if(sscanf(LOWER(str), "%s en %s", str1, str2) != 2)
        return notify_fail("¿Usar <Qué> en <qué>?\n");

    else if(str2 != "ranura")
        return notify_fail("¿Usar <Qué> en <qué>?\n");
    else if(!hay_barrotes)
    {
    	  pj = TP;
        arma = present(str1, pj);
        if(!arma)
            return notify_fail("No tienes " + str1 + ".\n");
        else
        {
            if (member(arma->QueryClassIds(), C_WEAPON) < 0)
                return notify_fail("No puedes usar " + arma->QueryShort() + " en la "
                                   "ranura.\n");
            tipo_arma = arma->QueryWeaponType();

            if (member(({CS_HACHA, CS_CUCHILLO, CS_ESPADA}), arma->QueryWeaponType()) <0) // no se puede usar
                return notify_fail("No puedes usar " + arma->QueryShort() + " en la ranura.\n");
            else if (member(pj->QueryWeapons(), arma) < 0) // tiene que empuñarla
                return notify_fail("Deberías empuñar " + arma->QueryShort() + " para "
                                    "poder hacer algo útil.\n");
            f_introducir(arma, pj);
        }
    }
    return notify_fail("Deberías quitar antes los barrotes de alguna manera.\n");
}

public int f_introducir(object arma, object pj)
{
    write("Introduces " + arma->QueryShort() + " por la ranura y empujas "
                      "hasta que cede.\n");
    say(CAP(TNAME) + " hace algo, pero la niebla te impide ver con "
                      "detalle sus movimientos.\n");
    return 1;
}

public varargs void reset()
{
    ::reset();
    hay_barrotes = 1;
    ventana_cerrada = 1;
}
