/*
DESCRIPCION  : Habitacion de reposo
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/reposo.c
MODIFICACION : 08-02-98 [Angor@Simauria] Creacion.
               16-09-98 [Angor@Simauria] Modificaciones varias
               10-10-99 [Woo] Castellanizado, además ahora no se puede hacer
                        magia aquí.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la habitación de reposo");
  SetIntLong(
"Estás en un lugar de reposo en el templo de Asthar. La habitación es amplia "
"y junto a sus blancas paredes se encuentran una serie de camas destinadas a la "
"recuperación de los pacientes de Asthar. En la pared este de la habitación se "
"hallan una serie de amplios ventanales que te permiten ver el exterior: la plaza "
"del templo y más alla el vasto oceano al este, y el templo al sudeste. Ves "
"varios cirios ardiendo lentamente que desprenden un perfume denso y adormecedor.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
 "Gracias a ellos, es en este lugar donde las almas de los seres se "
 "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

AddDetail(({"cama","camas"}),
  "Tras la operación de cambio de raza o la encarnación de un espiritu, un "
  "individuo se debilita. Es por ello que en este edificio anexo al templo se "
  "dispone de esta habitación de reposo, en cuyas camas y bajo los atentos cuidados "
  "de los ayudantes de Asthar los cuerpos se recuperan de la complicada operación "
  "hasta que finalmente despiertan totalmente recuperados.\n");

AddDetail(({"ventanales","ventanas","oceano","templo","plaza","mar","monolito"}),
 "Los ventanales de la habitación te permiten observar el exterior. Frente a ti "
 "se encuentra una gran plaza de adoquines blancos en cuyo centro observas un "
 "monolito de basalto negro. La plaza acaba en el borde del acantilado y más allá "
 "se extiende majestuoso el oceano. Al sur de la plaza se encuentra el templo, un "
 "gran edificio coronado por una impresionante cúpula semiesférica.\n");

AddDetail(({"cirio","cirios","vela","velas","cera","recipientes"}),
 "A lo largo de la habitación hay dispuestos varios cirios ardiendo. Son velas "
 "bajas y gruesas colocadas dentro de unos recipientes de cristal. Los cirios "
 "están encendidos, pero su llama casi apenas se ve. La cera al quemarse despide "
 "un perfume denso y adormecedor que, probablemente tenga propiedades curativas.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("El perfume de los cirios aunque denso, no resulta agobiante.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);

 AddExit("sur",TEMPLO("escalera"));
 AddItem(PNJ("enfermera"),REFRESH_HOME);
 ForbidAllMagic();
 SetSafe(1);
}
