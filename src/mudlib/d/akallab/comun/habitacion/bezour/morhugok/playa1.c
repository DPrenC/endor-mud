// DESCRIPCION : playa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 SetIntShort("la playa de la bah�a de Morhugok");
 SetIntLong(
 "La playa de la peque�a bah�a de Morhugok comienza al oeste de aqu� y va "
 "despu�s girando hacia el sureste. La bah�a es en realidad una inmensa "
 "grieta entre los dos promontorios sobre los que ves unos poblados "
 "protegidos con una empalizada. Al este de aqu� un arroyo desemboca "
 "en la playa y al sur, un muelle permite acceder a los barcos fondeados.\n");

 AddExit("sur",MORHUGOK("muelle"));
 AddExit("oeste",MORHUGOK("playa0"));
 AddExit("este",MORHUGOK("playa2"));
 replace_program();
}