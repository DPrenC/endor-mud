/*
DESCRIPCION  : Oficina de correos de la ciudad de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/tienda/correos.c
MODIFICACION : 16-11-98 [Angor@Simauria] Creacion.
               26-10-99 [woo] Quitado el cartero.. donde esta?
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>

inherit ROOM;

public int coger_cmd(string str)
{
  object ob;
  if (str!="folleto") return 0;
  ob = clone_object("/mail/folleto_correos");
  if (ob->move(TP,M_SILENT)!=ME_OK){
      write("No puedes llevar nada mas.\n");
      ob->remove();
      if (ob) destruct(ob);
      }
  else
      write("Recoges uno de los folleto de correos.\n");
  return 1;
}

create() {
  ::create();
 SetIntShort("la oficina de correos de Limbo");
  SetIntLong(
    "Te encuentras en la oficina de correos de la ciudad de Zarkam. Este local es la "
    "sucursal local de la Hermandad de Mensajeros y su funcion es la de proporcionar "
    "los medios para que los habitantes de este mundo puedan cartearse. Sobre el "
    "mostrador ves una caja con folletos que puedes coger donde se explica como "
    "utilizar este servicio. El cartero, un gnomo bastante inquieto, pasa el rato "
    "organizando las cartas en varios grandes archivadores.\n");

  AddDetail(({"archivadores","achivador","grandes archivadores"}),
    "En los grandes archivadores que hay tras el mostrador se clasifica el correo por "
    "zonas para que luego los mensajeros lo repartan.\n");

  AddDetail(({"ganso","gansos"}),
    "Dado su tamanyo, los gnomos suelen emplear como montura a gansos. En el caso de "
    "que trabajen en correos, suele ser habitual que sea este el sistema que se "
    "emplee para entregar las cartas o llevarlas de una a otra oficina de correos. "
    "En esta en concreto no ves ningun ganso, pero es probable que el cartero tenga "
    "al suyo en la trastienda.\n");

  SetIntNoise("El unico ruido es el del trasiego de sobres del cartero.\n");
  SetIntSmell("Huele a papel.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);
  AddExit("sur",Z_CIUDAD("calle_19"));
//  AddItem(PNJ("std/cartero"));
  AddRoomCmd("coger",SF(coger_cmd));
}


