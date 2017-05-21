#include <mud.h>
#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;


create () {
  ::create();
Set(P_INT_SHORT,"un huerto");
SetIntLong(
"Te encuentras en un pequenyo campo cultivado de hortalizas. Ves todo\n"
"tipo de verduras: tomates, zanahorias, nabos, patatas, etc. El huerto\n"
"esta rodeado de un pequenyo seto que lo separa del campo de maiz hacia\n"
"el norte y el este. Al oeste hay un camino que conduce al granero.\n"
"Hacia el sur se encuentra la vivienda de los granjeros.\n");

SetIndoors(0);
SetIntNoise("Crees oir como crecen las plantas.\n");
SetIntSmell("Hueles a tierra mojada.\n");
SetLocate("nandor");

AddDetail(({"campos","campo","campo de maiz"}),
"Un gran maizal que se extiende hasta donde alcanza la vista. Hay un\n"
"pequenyo sendero hacia el sudeste rodeando la casa que conduce a el.\n");
AddDetail(({"granero"}),
"Una gran construccion de madera para almacenar el grano.\n");
AddDetail(({"vivienda","casa","granja"}),
"Una casa de madera de dos pisos perfecta para vivir en el campo.\n");
AddExit("oeste","./granero");
AddExit("sur","./granja1");
AddExit("sudeste","./maizal1");
HideExit("sudeste",1);
}
