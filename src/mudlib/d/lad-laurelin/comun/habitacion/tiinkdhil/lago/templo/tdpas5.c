/*****************************************************************************************
 ARCHIVO:       tdpas5.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;
inherit ALUOBJ("otro/anteojos"); //[ztico] no entiendo para qu�...

int PUESTO; //[ztico] �sto no se usa

int leer_tapiz(string str);

public void create()
{
    ::create();

    SetIntShort("el pasillo");
    SetIntLong("�Es que no se va a terminar nunca? Esto est� hecho una pena, y mira "
          "que debi� ser agradable el sitio. Hay algunos restos de algo parecido a un "
          "tapiz en la pared.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"tapiz", "tapices"}), "No tienen dibujos, s�lo un escrito en �lfico "
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
    	  write("�Leer QU�?\n");
    	  return 1;
    }
    if (TP->QueryInt() < 20) write("Ni un elfo entender�a lo que pone.\n");

    write("Consigues leer en �lfico antiguo:\n\nMalhadados todos los que se atrevan a "
          "entrar en nuestro templo con intenciones deshonestas, pues la ira de Dehim "
          "caer� sobre ellos, y acabar� con sus vidas desde el CENTRO de nuestra "
          "alma.\n");
    return 1;
}