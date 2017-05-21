/* SIMAURIA '/room/mar.c'
   ======================
   [w] Woo@simauria

   29-12-97 [w] Este es el fichero temporal donde todos los barcos estaran
                cuando esten navegando de un puerto a otro.
   24-08-98 [w] Solucionado un pequenyo bug en allow_enter()
   27-10-98 [w] Modificado el lugar de habitacion
*/

#include <moving.h>

inherit ROOM;

public void create()
{
  ::create();
  SetIntShort("En medio del mar");
  SetIntLong("Te encuentras en medio del mar rodeado de agua por todas partes.\n");
  SetIndoors(0);
}


public int allow_enter(int method,mixed extra) // Solo pueden haber barcos
{
  if (member(inherit_list(PO), "/obj/transporte/mar/barco.c")==-1)
    return ME_NO_ENTER;
  return ME_OK;
}

