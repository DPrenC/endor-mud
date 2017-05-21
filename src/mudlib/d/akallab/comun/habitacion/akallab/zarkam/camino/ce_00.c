/*
DESCRIPCION  : Camino del Este
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/ce_00.c
MODIFICACION : 12-02-98 [Angor@Simauria] Creacion.
               05-10-98 [Angor@Simauria] Varias modificaciones
               29-10-98 [Chaos] Modificada una salida
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino del Este");
  SetIntLong(
     "Te encuentras en el camino del Este del valle de Zarkam. Este camino comienza "
     "en un cruce con el Sendero de los Cráneos, al oeste de aqui, y avanza hacia el "
     "desfiladero del Paso de Akkbar al este del valle. Lejos al nordeste ves unos "
     "campos de cultivo en medio del valle. El camino el pedregoso y polvoriento, y "
     "el frio viento que sopla con fuerza se deja sentir.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "Es una importante via de comunicacion que recorre el valle de norte a sur.\n");

  AddDetail(({"camino","camino del este","camino del Este"}),
     "Estas en este camino que cruza el valle de Zarkam de este a oeste.\n");

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("oeste",Z_CAMINO("cc_00"));//para que funcione el portal
 AddExit("este",Z_CAMINO("ce_01"));
}
