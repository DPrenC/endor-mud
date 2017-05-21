// DESCRIPCION : escalera al promontorio
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 replace_program();
 SetIntShort("la escalera a un promontorio de la bah�a de Morhugok");
 SetIntLong(
 "La escalera va girando a medida que asciende por el promontorio y desde este "
 "punto intermedio ya se tiene una buena vista de la bah�a. Los pelda�os son "
 "altos y est�n parcialmente tallados en la roca y apuntalados con planchas de "
 "madera. La vegetaci�n tropical que crece entre las grietas del promontorio "
 "lucha por ocupar el espacio de la escalera y sus ra�ces se entrelazan con "
 "los escalones.\n");
  
 AddDetail(({"escalera"}), this_object()->QueryIntLong() );
  
 AddExit("suroeste",MORHUGOK("escalera4"));
 AddExit("este",MORHUGOK("playa5"));
}
