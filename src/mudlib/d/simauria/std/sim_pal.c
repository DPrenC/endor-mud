/*
   ##################################################################
   ## sim_pal.c : Habitacion estandard para el Palacio Real.       ##
   ## Creacion : 14/10/97. [n] Nemesis (nemesis@simauria.upv.es)   ##
   ##################################################################
*/

#include "../path.h"

inherit ROOM;

haz_matar(str) {
 int i,j,k,nom;
 if (!str) {
  return 0;
 }
 write("Inicias el combate, pero de repente aparecen guardias de todas partes "
       "y te sujetan. De pronto, todo se vuelve negro.\n");
 i=0;
 while (i<50000) {
  i++;
  }

 write("\nLa conciencia vuelve a ti durante unos instantes y notas un traqueteo.\n"
       "Vuelves a caer inconsciente.....\n");
  TP->move(SIMA("capital/mazmorra"));

 j=0;
 while (j<50000) {
  if (j>49995) write("\n................");
  j++;
  }

 write("\n\nTe despiertas en una celda oscura y humeda.\n");
 return 1;
}


init() {

add_action("haz_matar","matar");
 ::init();
}


create()
{

 ::create();
 SetIntShort("algún lugar en el Palacio Real");
 SetIntLong("Estas en alguna parte del vasto Palacio Real de Simauria.\n");
 SetIndoors(1);
 SetIntBright(35);
 SetLocate("Simauria Capital");
 SetIntNoise("No oyes nada en especial.\n");
 SetIntSmell("No hueles nada en especial.\n");
 SetServer(SERVER);
 ForbidAllMagic("La magia esta prohibida en este lugar.\n");

}
