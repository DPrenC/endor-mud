#include "path.h"
#include <properties.h>
#include <magia.h>
#include <moving.h>
inherit ROOM;

/* esta funci�n impide la acci�n coger para que no devuelva el no ves eso... */
public int decor(string str) {
    if ((str=="libro")||(str=="libros")||(str=="caja")||(str=="cajas")||(str=="cajita")||
        (str=="cajitas")||(str=="frasco")||(str=="frascos")||(str=="embase")||(str=="embases"))
    {
        write("una fuerza m�gica te impide acercarte a la estanter�a.\n");
        say(TP->QueryName()+" intenta acercarse a la estanter�a, pero una fuerza m�gica se lo impide.\n");
        return 1;
    }
    if ((str == "mesa") || (str == "mesita") || (str == "altar") || (str == "mantel"))
    {
        write("Una fuerza m�gica te impide tocar el altar.\n");
        say(TP->QueryName()+" se aproxima al altar, pero es rechazad"+PO->QueryGenderEndString()+" por una fuerza m�gica.\n");
        return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetIntShort("el laboratorio");
    SetIntLong("Esto es el laboratorio privado de Yalin.\nAl contrario que el resto de la casa, "
        "este lugar es sobrio y funcional.\nHay sendas estanter�as al este y al oeste. Una est� "
        "llena de cajitas y frascos de cristal, y la otra est� repleta de libros.\nAl fondo hay "
        "una mesita con forma de altar, donde Yalin realiza sus conjuros, y constituye la �nica "
        "nota de elegancia del lugar.\n");
    SetIntSmell("Sientes mareos ante el fuerte olor a incienso y otras hierbas mezclado con "
        "algunos olores desagradables que no sabes distinguir.\n");
    SetIntNoise("No oyes nada. Este lugar est� preparado para que nada moleste a su ocupante "
        "cuando trabaja.\n");
    SetIntBright(50);
    AddDetail(({"embases","cajas","cajitas","frascos","productos"}), "No consigues determinar qu� "
        "contienen los embases que ves, y no est�s muy segur"+TP->QueryGenderEndString()+" de querer saberlo.\n");
    AddDetail(({"libro","libros"}), "Son los libros de magia y hechicer�a de los que Yalin se "
        "sirve en sus conjuros y artificios.\n");
    AddDetail(({"estante","estantes","estanter�a","estanter�as","estanteria","estanterias"}),
        "Est�n abarrotadas de productos de hechicer�a y libros de magia.\n");
    AddRoomCmd("coger", "decor");
    AddItem("obj/altar");
    AddItem("obj/silla");
    AddExit("oeste", TORRE("rooms/yalin/pasillo"));
}
