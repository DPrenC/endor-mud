/*
DESCRIPCION  : Salon de reuniones en el ayuntamiento
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/salon_ayto.c
MODIFICACION : 26-07-98 [Angor@Simauria] Creacion.
               24-10-98 [Angor@Simauria] Separado el salon del gremio
               28-10-99 [jorus@simauria] Modificacion para berat
[Maler]
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SCHEDULER_ROOM;

create() {
    ::create();
    SetIntShort("el sal�n del ayuntamiento");
    SetIntLong("Est�s en una amplia sala de reuniones en el ayuntamiento. Aqu� se reune la gente "
     "del pueblo cuando se debe discutir alg�n tema de inter�s com�n o por el mero "
     "hecho de charlar un rato. Al fondo hay una chimenea y varios c�modos butacones "
     "donde descansar y charlar al calor del fuego. Las paredes est�n adornadas con "
     "varios trofeos colgados en ellas.\n");

    AddDetail(({"chimenea","brasas"}),W(
    "Es una chimenea baja y ancha de piedra en la que arden lentamente las brasas de "
    "un fuego, proporcionando una agradable temperatura al ambiente.\n"));

    AddDetail(({"butacones","butacas"}),W(
     "Junto a la chimenea y formando un peque�o corro hay unos cuantos butacones que "
     "sin duda conocieron tiempos mejores. Son una especie de sofas individuales "
     "forrados con una descolorida tela de color azulado.\n"));

  AddDetail(({"trofeos"}),
     "A lo largo de las paredes del sal�n hay colgados varios trofeos obtenidos por "
	 "algunos de los ciudadanos del pueblo. Puedes observar varias cabezas disecadas"
     "de animales salvajes, una vieja y oxidada espada e incluso un arpon para "
     "cazar ballenas, premio del �ltimo concurso de pesca celebrado aqu� en el pueblo.\n");

    AddDetail(({"cabezas","cabezas disecadas"}),"Seguro que sus due�os ya no las echan de menos.\n");

SetIntNoise("Las brasas del fuego crepitan ocasionalmente.\n");
SetIntSmell("Huele un poco a humo.\n");
SetLocate("Berat");
  SetIntBright(30);
AddExit("abajo","./ayuntami");
    SetMainRoom("./ayuntami");
    SetNotifyExits(({}));
    SetLastDest("./cprin4");
}