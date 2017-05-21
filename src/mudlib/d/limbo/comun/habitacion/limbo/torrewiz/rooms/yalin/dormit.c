#include "path.h"
#include <properties.h>
#include <magia.h>
#include <sounds.h>
inherit ROOM;

/* La siguiente funci�n devuelve una respuesta no standard cuando el jugador intenta coger un objeto del decorado. */
public int decor(string str) {
    if (str == "ventana")
    {
        write("�Qu� bruto eres! �C�mo piensas cogerla?\n");
        return 1;
    }
    return 0;
}

/*La siguiente funci�n da una respuesta cuando el jugador intenta abrir un objeto del decorado*/
public int noabre(string str)
{
    if (str=="ventana")
    {
        write("Ya est� abierta.\n");
        return 1;
    }
    return 0;
}

/*la siguiente funci�n responde cuando el jugador intenta cerrar la ventana.*/
public int nocer(string str) {
    if (str=="ventana")
    {
        write("La ventana es m�gica; se abre y se cierra seg�n las necesidades de "
            "los due�os de la casa.\n");
        return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetIntShort("el dormitorio");
    SetIntLong("�ste es el �nico dormitorio de la casa.\nAqu� es donde Yalin y su ni�o se "
        "retiran a descansar o a dormir cuando tienen sue�o, o, cuando no lo tienen, "
        "a otros menesteres, quiz� menos dignos, pero m�s interesantes y placenteros.\nEl "
        "mobiliario es lujoso, y elaborado con madera de s�ndalo. Se compone de una "
        "amplia cama con una mesita, un armario y un tocador.\n");
    SetIntBright(50);
    SetIntSmell("Hueles una mezcla de perfumes que jam�s hab�as conocido. Tal vez la propia "
        "Yalin los fabrica para ella y su ni�o.\n");
    SetIntNoise("Por la ventana abierta, entra el rumor del mar, y de alg�n bosque cercano.\n");
    AddDetail(({"ventana"}),"Es un hueco rectangular abierto en el muro, que sirve para dar "
        "luz y ventilar. �Nunca has visto ninguna?\n");
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
