/*
DESCRIPCION : entrada al patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio00.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit ROOM;

//los PNJ no pasan
int ir_o()
{
if (TP->QueryIsPlayer()) return TP->move(Z_CASTILLO("patio/patio01"),M_GO);
  return 1;
}

create() {
 ::create();
 SetIntShort("la entrada al patio del castillo");
 SetIntLong(
     "Te encuentras bajo la muralla del castillo en un amplio pasadizo que comunica la "
     "plaza mayor de Zarkam con el patio del castillo. Por la longitud del pasadizo "
     "calculas que la muralla debe tener al menos unos 5 o 6 metros de grosor. Ves que "
     "al final del pasadizo hay una reja levadiza que permite impedir la entrada al "
     "castillo en caso de necesidad. Ahora la reja esta alzada y puedes pasar.\n");

 AddDetail(({"reja"}),
     "Es una reja en forma de cuadricula hecha con gruesas barras de metal que puede "
     "ser bajada o elevada mediante algun tipo de mecanismo. Cuando esta bajada "
     "bloquea la salida del pasadizo, impidiendo asi el acceso al castillo.\n");

  AddDetail(({"pasadizo","tunel"}),
     "Es una especie de ancho tunel realizado en la muralla del castillo. A traves de "
     "de el se puede ir de la plaza mayor de la ciudad al patio del castillo.\n");

  AddDetail(({"muralla"}),"Estas bajo ella asi que no puedes ver mucho.\n");

SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
SetLocate("castillo de Zarkam");
SetIndoors(1);

AddExit("este",Z_CIUDAD("plaza_02"));
AddExit("oeste",SF(ir_o));
}

