#include "path.h"
#include <properties.h>
#include <magia.h>
#include <moving.h>
inherit ROOM;

/* esta función impide la acción coger para que no devuelva el no ves eso... */
public int decor(string str) {
    if ((str=="libro")||(str=="libros")||(str=="caja")||(str=="cajas")||(str=="cajita")||
        (str=="cajitas")||(str=="frasco")||(str=="frascos")||(str=="embase")||(str=="embases"))
    {
        write("una fuerza mágica te impide acercarte a la estantería.\n");
        say(TP->QueryName()+" intenta acercarse a la estantería, pero una fuerza mágica se lo impide.\n");
        return 1;
    }
    if ((str == "mesa") || (str == "mesita") || (str == "altar") || (str == "mantel"))
    {
        write("Una fuerza mágica te impide tocar el altar.\n");
        say(TP->QueryName()+" se aproxima al altar, pero es rechazad"+PO->QueryGenderEndString()+" por una fuerza mágica.\n");
        return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetIntShort("el laboratorio");
    SetIntLong("Esto es el laboratorio privado de Yalin.\nAl contrario que el resto de la casa, "
        "este lugar es sobrio y funcional.\nHay sendas estanterías al este y al oeste. Una está "
        "llena de cajitas y frascos de cristal, y la otra está repleta de libros.\nAl fondo hay "
        "una mesita con forma de altar, donde Yalin realiza sus conjuros, y constituye la única "
        "nota de elegancia del lugar.\n");
    SetIntSmell("Sientes mareos ante el fuerte olor a incienso y otras hierbas mezclado con "
        "algunos olores desagradables que no sabes distinguir.\n");
    SetIntNoise("No oyes nada. Este lugar está preparado para que nada moleste a su ocupante "
        "cuando trabaja.\n");
    SetIntBright(50);
    AddDetail(({"embases","cajas","cajitas","frascos","productos"}), "No consigues determinar qué "
        "contienen los embases que ves, y no estás muy segur"+TP->QueryGenderEndString()+" de querer saberlo.\n");
    AddDetail(({"libro","libros"}), "Son los libros de magia y hechicería de los que Yalin se "
        "sirve en sus conjuros y artificios.\n");
    AddDetail(({"estante","estantes","estantería","estanterías","estanteria","estanterias"}),
        "Están abarrotadas de productos de hechicería y libros de magia.\n");
    AddRoomCmd("coger", "decor");
    AddItem("obj/altar");
    AddItem("obj/silla");
    AddExit("oeste", TORRE("rooms/yalin/pasillo"));
}
