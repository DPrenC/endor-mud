/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Fran@Simauria modificandorrrr
 *   Ultima modificacion: 26 Sep, 2000.
 */

#include "path.h"
#include <properties.h>
#include <door.h>

inherit KHA_ROOM;

int abierto;
int tester;

create()
{
    ::create();
    tester = 0;
    abierto = 0;
    SetIntShort("una habitación de invitados");
    SetIntLong("Estás en otra habitación en el segundo piso. Esta habitación "
    	  "parece más pequeña. Sólo hay una cama, una mesilla de noche"
	      "y un sillón pequeño, esta habitación no parece especial.\n");
    SetIntBright(50);
    AddExit("oeste",PISO2+"piso2_8");
    AddDoor("oeste","la puerta del pasillo","Es una puerta de madera, adornada con paneles de cristal.\n",
    ({"puerta","puerta de pasillo","puerta del pasillo"}), GENDER_FEMALE,
    ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDetail( ({"lampara","lamparas"}),
        "Ves lámparas de diamante que cuelgan del techo y que despiden una luz "
    "azulada.\n");
   AddDetail(({"paredes","pared",}),
"Al fijarte bien notas que las paredes, realmente, estan hechas de oro!\n");
  AddDetail("suelo","Puedes ver el reflejo de las lamparas sobre el suelo\n");
  AddDetail("cama","La cama es preciosa, parece muy confortable.\n");
  AddDetail("sillon","Solo un pequenyo sillon.\n");
    AddRoomCmd("abrir","abre");
    AddRoomCmd("cerrar","cierra");
AddDetail("mesilla","Una mesilla de noche.\n");
}
init()  {
   ::init();
   add_action("mirar","m");
   add_action("mirar","mi");
   add_action("mirar","mir");
   add_action("mirar","mira");
   add_action("mirar","mirar");
   add_action("mirar","exa");
}

int abre(string str) 
{
    if ((str =="mesilla") || (str =="mesilla de noche"))
    {
        if (abierto == 1) write("La mesilla de noche ya esta abierta.\n");
        if (abierto == 0)
        {
  	        write("Abres la mesilla de noche.\n");
            say(capitalize(getuid(TP))+" abre la mesilla de noche.\n");
            abierto = 1;
        }
        return 1;
    } 
}

int cierra(string str) 
{
    if ((str =="mesilla") || (str =="mesilla de noche"))
    {
        if (abierto == 0) write("La mesilla ya esta cerrada.\n");
        if (abierto == 1) 
        {
            write("Cierras la mesilla de noche.\n");
            say(capitalize(getuid(TP))+" cierra la mesilla de noche.\n");
  	        abierto = 0;
        }
        return 1;
    }
}

int mirar(string str)  {
   if ((str !="mesilla") && (str !="mesilla de noche"))  {
     notify_fail("Mirar Que?\n");
     return 0;
  }
   else  {
      if (abierto == 0) {
 	  write("La mesilla esta cerrada.\n");
	  say(capitalize(getuid(TP))+" mira la mesilla.\n");
          return 1;
      }
      if ((abierto == 1) && (tester == 0)) {
	  write("Miras dentro de la mesilla y encuentras una pequenya pila"+
		"de monedas dentro.\n");
	  say(capitalize(getuid(TP))+" mira dentro de la mesilla"+
	      "de noche.\n");
	  TP->adjust_money(20+random(10),"gold");
	  tester = 1;
          return 1;
      }
      if ((abierto == 1) && (tester == 1)) {
	  write("Miras dentro de la mesilla, pero no parece haber nada "+
		"interesante dentro de ella.\n");
          return 1;
      }
   }
}