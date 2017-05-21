/*
DESCRIPCION : patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio01.c
MODIFICACION: 28-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>

inherit ROOM;

//los PNJ no pasan
int ir_e()
{
if (TP->QueryIsPlayer()) return TP->move(Z_CASTILLO("patio/patio00"),M_GO);
  return 1;
}

create() {
 ::create();
 SetIntShort("la entrada al patio del castillo");
 SetIntLong(
     "Estas en el amplio patio que se halla entre el castillo de Zarkam y la muralla "
     "que lo rodea. Un amplio pasadizo se abre en la muralla justo al este de aqui y "
     "permite salir al exterior. Al norte y adosada a la muralla observas la caseta "
     "donde vive la guardia que custodia esta puerta. El establo donde la guardia "
     "tiene a sus monturas queda al sur de aqui.\n");

 AddDetail(({"reja"}),
     "Es una reja en forma de cuadricula hecha con gruesas barras de metal que puede "
     "ser bajada o elevada mediante algun tipo de mecanismo. Cuando esta bajada "
     "bloquea la salida del pasadizo, impidiendo asi el acceso al castillo.\n");

  AddDetail(({"pasadizo","tunel"}),
     "Es una especie de ancho tunel realizado en la muralla del castillo. A traves de "
     "de el se puede ir de la plaza mayor de la ciudad al patio del castillo.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege el castillo rodeandolo por completo. "
     "Dirias que debe tener al menos unos cinco metros de altura en las partes mas "
     "bajas sin contar con las almenas. Cada cierta distancia observas una torre o una "
     "escalera adosada a la muralla que permiten subir a ella. Continamente ves a "
     "soldados fuertemente armados patrullando sobre la muralla.\n");

  AddDetail(({"establo"}),"Queda al sur de aqui.\n");
  AddDetail(({"caseta"}),"Esta junto a la muralla al norte de aqui.\n");

SetIntNoise("Se oye el ajetreo tipico del castillo.\n");
SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
SetLocate("castillo de Zarkam");
SetIndoors(0);

AddExit("norte",Z_CASTILLO("patio/guardia"));
AddExit("oeste",Z_CASTILLO("patio/patio02"));
AddExit("sur",Z_CASTILLO("patio/establo"));
AddExit("este",SF(ir_e));
}

