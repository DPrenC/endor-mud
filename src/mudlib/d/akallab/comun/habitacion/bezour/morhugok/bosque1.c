// DESCRIPCION : bosque
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 SetIntShort("el bosque de la bahía de Morhugok");
 SetIntLong(
 "Al parecer esta zona del bosque se destina a la extracción de madera: los "
 "árboles grandes han sido talados y varios grandes troncos se apilan junto "
 "al sendero que conduce a la playa. Las paredes de los altos acantilados se "
 "alzan frente a ti cubiertas de vegetación tropical que vive en las grietas "
 "de la roca.\n");

 AddExit("suroeste",MORHUGOK("playa4"));
 AddItem(OTRO("tronco_talado"), REFRESH_DESTRUCT, d2()+1); 
}