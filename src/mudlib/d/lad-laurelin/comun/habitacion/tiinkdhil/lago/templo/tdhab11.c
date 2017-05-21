/*****************************************************************************************
 ARCHIVO:       tdhab11.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <money.h>

#define MESITAS ({"encima de la mesita", "encima de las mesitas", "encima mesitas"})

inherit ROOM;

private int v;

int mirar_encima(string str);

public void create()
{
    ::create();

    SetIntShort("el dormitorio");
    SetIntLong("Una hilera de camas invade practicamente la habitaci�n. Las mantas "
          "est�n deshechas y llenas de telara�as. Al lado de �stas hay mesitas de noche "
          "que todav�a est�n en pie.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("mesitas", "Est�n grabadas con gran detalle. Algunas tienen objetos "
          "ENCIMA.\n");
    // a�adida una funci�n (mirar encima de la (mesita)) que tiene dinero
    AddRoomCmd("mirar", "mirar_encima");

    AddExit("norte", ALULAGO("templo/tdpas12.c"));
    AddExit("oeste", ALULAGO("templo/tdpas13.c"));

    AddItem(ALUPNJ("monjef"), REFRESH_DESTRUCT,1);
}

int mirar_encima(string str)
{
    if(!str || member(MESITAS, str) < 0) return 0;

    if(v == 1)
    {
    	  //No se por qu� no rula el notify_fail, aunque �sto no me gusta, te
    	  //da el mensaje si alguien no ha cogido el dinero, sigue estando ah�
        write("Lo que hab�a, alguien se lo ha llevado.\n"); return 1;
    }
    AddItem("/obj/money", REFRESH_REMOVE,
           (["Money" : MONEY_DEMON->CreateMoney((random(1000)+10), ({"silver"}))]));
    v = 1;
    return 1;
}

public varargs void reset()
{
    v = 0;
    ::reset();
}
