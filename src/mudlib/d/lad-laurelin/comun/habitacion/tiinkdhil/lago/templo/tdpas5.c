/*****************************************************************************************
 ARCHIVO:       tdpas5.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;
inherit ALUOBJ("otro/anteojos"); //[ztico] no entiendo para qué...

int PUESTO; //[ztico] ésto no se usa

int leer_tapiz(string str);

public void create()
{
    ::create();

    SetIntShort("el pasillo");
    SetIntLong("¿Es que no se va a terminar nunca? Esto está hecho una pena, y mira "
          "que debió ser agradable el sitio. Hay algunos restos de algo parecido a un "
          "tapiz en la pared.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"tapiz", "tapices"}), "No tienen dibujos, sólo un escrito en élfico "
          "antiguo.\n");
    AddRoomCmd("leer", "leer_tapiz");

    AddExit("nordeste", ALULAGO("templo/tdpas13.c"));
    AddExit("sur", ALULAGO("templo/tdpas4.c"));

    AddItem(ALUPNJ("adepto"), REFRESH_DESTRUCT, 1);
}

int leer_tapiz(string str)
{
    if ((str != "tapiz") && (str != "escrito"))
    {
    	  write("¿Leer QUÉ?\n");
    	  return 1;
    }
    if (TP->QueryInt() < 20) write("Ni un elfo entendería lo que pone.\n");

    write("Consigues leer en élfico antiguo:\n\nMalhadados todos los que se atrevan a "
          "entrar en nuestro templo con intenciones deshonestas, pues la ira de Dehim "
          "caerá sobre ellos, y acabará con sus vidas desde el CENTRO de nuestra "
          "alma.\n");
    return 1;
}