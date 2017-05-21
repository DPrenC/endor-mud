// DESCRIPCION : habitacion comun a esta zona
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit ROOM;

create(){
 if (::create()) return 1;
 SetIntShort("cuevas de Morhugok");
 SetIntLong("cuevas de Morhugok.\n");
 SetLocate("cuevas de Morhugok");
 SetIntSmell("Huele a salitre.\n");
 SetIntNoise("Las olas rompen ruidosamente contra las rocas de los acantilados.\n");

#include "detalles.h"

}