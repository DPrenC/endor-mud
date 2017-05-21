/*****************************************************************************************
 ARCHIVO:       robledal28.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Gruta en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#define TOPE_LUZ 10

inherit BASE_ISLA;

private int hay_murcielagos = 1;

public void desp_murcielagos(int luz);
public mixed mirar_murcielagos();

create()
{
    if(::create()) return 1;

    SetIntShort("la gruta");
    SetIntLong("La gruta aquí conforma algo así como un declive escalonado que desciende "
        "por debajo del nivel de las salas contiguas. Los escalones de piedra son "
        "irregulares. Por encima de tu cabeza descubres una bóveda granítica en cuyo "
        "centro destaca una masa oscura y movediza.\n");
    AddDetail(({"escalones", "declive", "declive escalonado"}), "La humedad hace que "
        "todo el piso sea peligroso.\n");
    AddDetail(({"techo", "bóveda", "boveda", "bóveda granítica"}), "Se alza unos cinco "
        "metros por encima de ti. Hay algo que se mueve.\n");
    AddDetail("suelo", "Está lleno de suciedad y grandes montones de excrementos.\n");
    AddDetail(({"suciedad", "excrementos"}), "No limpian muy a menudo por aquí.\n");
    AddDetail(({"masa", "masa oscura", "masa movediza", "masa oscura y movediza"}),
        "Parece que son.... !Murciélagos¡\n");
    AddDetail(({"murciélagos", "murcielagos"}), SF(mirar_murcielagos));

    SetIntSmell("Huele a deshechos y poquería.\n");
    SetIntNoise("Oyes un incesante susurro, como un revoloteo.\n");

    SetIndoors(1);
    SetIntBright(0);

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal33.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal22.c"));
}

//Sobrecargo el _recalculate_intlight(), de esta forma, cuando cambia la luz se ejecuta
//desp_murcielagos()

public static _recalculate_intlight()
{
    int val, light;

    light = QueryIntLight();
    val = ::_recalculate_intlight();

    if (val == light)
        return val;
    if(hay_murcielagos)
        call_out("desp_murcielagos", 1, val);
    return val;
}

public void desp_murcielagos(int luz)
{
    int i;

    if(luz > TOPE_LUZ)
    {
        tell_room(TO, "Parece que el exceso de luz, ha despertado a los moradores del "
            "lugar.\n");
        for(i = 15; i--;) { clone_object(PNJ_VALMAR("murcielago.c"))->move(TO); }
        hay_murcielagos = 0;
    }
}

public mixed mirar_murcielagos()
{
    if(present("murcielago_faeria", TO))
        return 0;
    else
        return "Revolotean tranquilos en la oscuridad.\n";
}
