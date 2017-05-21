/*
DESCRIPCION  : Almacen (Aserradero en el bosque)
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
			   26-10-99 [Angor@Simauria] modificacion/quest
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <messages.h>
inherit ROOM;

public int coger_cmd(string str){
  object ob;
  if (!TP) return 0;

  if ((str=="tablon")||(str=="tabla")||(str=="madera"))
      {
      ob=present(str,TP);
      if (ob) return notify_fail("Tu ya tienes un pesado tablon, "
	  "para que quieres cargar con otro...\n",NOTIFY_NOT_VALID);

	  ob=clone_object(QUEST+"amuleto/tablon");
	  if (ob)
	     {
	     ob->move(TP);
		 tell_room(TO, ({ MSG_SEE, NOMBRE+" carga con uno de los tablones de madera.\n" }), ({ TP }));
         write("Agarras un pesado tablon de madera de uno de los montones.\n");
		 return 1;
	     }
      }
      else return 0;
   return 0;
  }

create() {
  ::create();
  SetIntShort("el almacén del aserradero");
  SetIntLong(
  "Esta habitacion sirve de almacen para la madera proviniente del "
  "aserradero y del bosque. Puedes ver como en un lado se apilan troncos "
  "que todavia no han pasado por las sierras, mientras que en otro lado se "
  "hayan los tablones ya cortados y preparadas para abandonar el lugar hacia "
  "la ciudad de Zarkam, donde seran empleados para cualquier trabajo de "
  "carpinteria o construccion.\n");

  AddDetail(({"madera","troncos","tablones"}),
  "Ves como la madera se divide en dos tipos apilados en dos zonas "
  "distintas de este almacen. Por un lado se encuentra la madera recien "
  "llegada del bosque y por otro la que ya ha pasado por el aserradero "
  "y se encuentra cortada en tablones, preparada para ser enviada a "
  "Zarkam.\n");

  SetIntNoise("Oyes el ruido de la maquinaria que hay en la habitacion del sur.\n");
  SetIntSmell("Uele a madera.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("sur",Z_BOSQUE("maquinaria"));
  AddRoomCmd("coger","coger_cmd");
}
