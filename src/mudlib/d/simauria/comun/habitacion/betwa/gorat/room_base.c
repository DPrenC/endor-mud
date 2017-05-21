// DESCRIPCION : habitacion comun a esta zona
// MODIFICACION: 04-06-2008 [Angor] Creacion

#include "./path.h"
inherit SIM_ROOM;

create(){
 if (::create()) return 1;
 SetIntShort("Gorat");
 SetIntLong("En alguna parte de Gorat.\n");
 SetLocate("Gorat");
 SetIntSmell("Huele a salitre.\n");
 SetIntNoise("Las olas rompen contra las rocas de la costa.\n");
 SetIndoors(0);
    
#include "detalles.h"

}
