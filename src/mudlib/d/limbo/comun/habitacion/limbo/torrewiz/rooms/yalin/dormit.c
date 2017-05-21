#include "path.h"
#include <properties.h>
#include <magia.h>
#include <sounds.h>
inherit ROOM;

/* La siguiente función devuelve una respuesta no standard cuando el jugador intenta coger un objeto del decorado. */
public int decor(string str) {
    if (str == "ventana")
    {
        write("¡Qué bruto eres! ¿Cómo piensas cogerla?\n");
        return 1;
    }
    return 0;
}

/*La siguiente función da una respuesta cuando el jugador intenta abrir un objeto del decorado*/
public int noabre(string str)
{
    if (str=="ventana")
    {
        write("Ya está abierta.\n");
        return 1;
    }
    return 0;
}

/*la siguiente función responde cuando el jugador intenta cerrar la ventana.*/
public int nocer(string str) {
    if (str=="ventana")
    {
        write("La ventana es mágica; se abre y se cierra según las necesidades de "
            "los dueños de la casa.\n");
        return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetIntShort("el dormitorio");
    SetIntLong("Éste es el único dormitorio de la casa.\nAquí es donde Yalin y su niño se "
        "retiran a descansar o a dormir cuando tienen sueño, o, cuando no lo tienen, "
        "a otros menesteres, quizá menos dignos, pero más interesantes y placenteros.\nEl "
        "mobiliario es lujoso, y elaborado con madera de sándalo. Se compone de una "
        "amplia cama con una mesita, un armario y un tocador.\n");
    SetIntBright(50);
    SetIntSmell("Hueles una mezcla de perfumes que jamás habías conocido. Tal vez la propia "
        "Yalin los fabrica para ella y su niño.\n");
    SetIntNoise("Por la ventana abierta, entra el rumor del mar, y de algún bosque cercano.\n");
    AddDetail(({"ventana"}),"Es un hueco rectangular abierto en el muro, que sirve para dar "
        "luz y ventilar. ¿Nunca has visto ninguna?\n");
    Set(P_TPORT,TPORT_NO);
    AddRoomCmd("coger", "decor");
    AddRoomCmd("abrir", "noabre");
    AddRoomCmd("cerrar", "nocer");
    AddItem("obj/cama");
    AddItem("obj/mesita");
    AddItem("obj/armario");
    AddItem("obj/tocador");
    AddExit("oeste", TORRE("rooms/yalin/workroom"));
    SetSoundEnvironment(SND_AMBIENTES("olas"),30);
}
