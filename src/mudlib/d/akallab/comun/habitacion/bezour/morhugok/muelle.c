// DESCRIPCION : muelle
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
//inherit MORHUGOK("comun");
inherit PORT;

create(){
 if (::create()) return 1;
 SetIntShort("el muelle de la bah�a de Morhugok");
 SetIntLong(
 "La peque�a bah�a de Morhugok es uno de los pocos refugios naturales en "
 "esta costa de acantilados. La bah�a es en realidad una inmensa grieta entre "
 "dos promontorios de roca que debieron desprenderse de los acantilados hace "
 "mucho tiempo. Al fondo de la bah�a se halla una delgada playa de arena y tras "
 "ella, a los pies del acantilado ha crecido un peque�o bosque. Este muelle en "
 "el que est�s, permite a los barcos acceder a la playa.\n");

 AddExit("norte",MORHUGOK("playa1"));
 AddShip(BAR_TORMENTA("barco"));

 SetLocate("cuevas de Morhugok");
 SetIntSmell("Huele a salitre.\n");
 SetIntNoise("Las olas rompen ruidosamente contra las rocas de los acantilados.\n");

#include "detalles.h"
}