/*****************************************************************************************
 ARCHIVO:       tdhab31.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>

inherit ROOM;

object obj;
int vis;

int inst_bote(string str);

public void create()
{
    ::create();

    SetIntShort("la enfermería");
    SetIntLong("Sigues en la enfermería. La habitación está llena de camas "
          "polvorientas y varios armarios. También hay estanterías en las que distingues "
          "frascos rotos.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"estanterias", "estanterías"}), "Casi todos los botes están rotos. Tal "
          "vez alguno se haya salvado.\n");
    //funcion mirar_botes que enseñe la llave de la puerta secreta al guardian
    AddRoomCmd("buscar", "inst_bote");

    AddExit("norte", ALULAGO("templo/tdhab32.c"));
    AddExit("nordeste", ALULAGO("templo/tdhab34.c"));
}

int inst_bote(string str)
{
    if(!str || str != "bote") return 0;
    if(vis)
    {
        write("Aunque ahora no hay nada, antes habia algo en ellas.\n");
        return 0;
    }
    obj = clone_object(ALUOBJ("otro/botkey.c"));
    obj->move(TO, M_SILENT);
    write("Entre las estanterías ves un pequeño bote en buen estado.\n");
    vis = 1;
    return 1;
}

public varargs void reset()
{
	 vis = 0;
   ::reset();
}