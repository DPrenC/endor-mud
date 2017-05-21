/*
DESCRIPCION : desvan de la posada la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/desvan02.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el desván de la posada");
  SetIntLong(
    "Estas en un extremo del desvan de la posada. Las inclinadas cubiertas del tejado "
    "llegan hasta el suelo de esta espaciosa estancia. Un ventanal permite ver la "
    "plaza desde aqui. Sobre la pared oeste del desvan se amontonan todo tipos de "
    "trastos viejos cubietos de una gruesa capa de polvo. Puedes ver un poco de todo: "
    "viejos armarios, percheros, un par de mesas, sillas, y hasta un reloj de cuco "
    "estropeado.\n");

  AddDetail(({"ventanal","ventana"}),
    "Es una amplia ventana cuadrada realizada en la cubierta del tejado de la posada. "
    "Su cristal esta sucio y el marco un poco ajado, pero parece que aisla bien del "
    "gelido aire que sopla en este valle. La luz que lo atraviesa, ilumina el desvan. "
    "Puedes ver la plaza central de Zarkam que queda al norte de la posada.\n");

  AddDetail(({"trastos","trastos viejos","armarios","mesas","percheros","reloj"}),
    "Son solo un monton de trastos viejos amontonados que sin duda conocieron tiempos "
    "mejores. Ahora descansan amontonados en un rincon del desvan acumulando polvo.\n");

  SetIntNoise("Se oye a alguien roncar.\n");
  SetIntSmell("Hmm.. quiza alguien deberia abrir una ventana para ventilar el desvan.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("este",Z_POSADA("desvan01"));
}
