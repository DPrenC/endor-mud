/*
DESCRIPCION  : Habitacion de reposo
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/reposo.c
MODIFICACION : 08-02-98 [Angor@Simauria] Creacion.
               16-09-98 [Angor@Simauria] Modificaciones varias
               10-10-99 [Woo] Castellanizado, adem�s ahora no se puede hacer
                        magia aqu�.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la habitaci�n de reposo");
  SetIntLong(
"Est�s en un lugar de reposo en el templo de Asthar. La habitaci�n es amplia "
"y junto a sus blancas paredes se encuentran una serie de camas destinadas a la "
"recuperaci�n de los pacientes de Asthar. En la pared este de la habitaci�n se "
"hallan una serie de amplios ventanales que te permiten ver el exterior: la plaza "
"del templo y m�s alla el vasto oceano al este, y el templo al sudeste. Ves "
"varios cirios ardiendo lentamente que desprenden un perfume denso y adormecedor.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 "La isla Limbo es el lugar m�gico de Simauria donde habitan los dioses. "
 "Gracias a ellos, es en este lugar donde las almas de los seres se "
 "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

AddDetail(({"cama","camas"}),
  "Tras la operaci�n de cambio de raza o la encarnaci�n de un espiritu, un "
  "individuo se debilita. Es por ello que en este edificio anexo al templo se "
  "dispone de esta habitaci�n de reposo, en cuyas camas y bajo los atentos cuidados "
  "de los ayudantes de Asthar los cuerpos se recuperan de la complicada operaci�n "
  "hasta que finalmente despiertan totalmente recuperados.\n");

AddDetail(({"ventanales","ventanas","oceano","templo","plaza","mar","monolito"}),
 "Los ventanales de la habitaci�n te permiten observar el exterior. Frente a ti "
 "se encuentra una gran plaza de adoquines blancos en cuyo centro observas un "
 "monolito de basalto negro. La plaza acaba en el borde del acantilado y m�s all� "
 "se extiende majestuoso el oceano. Al sur de la plaza se encuentra el templo, un "
 "gran edificio coronado por una impresionante c�pula semiesf�rica.\n");

AddDetail(({"cirio","cirios","vela","velas","cera","recipientes"}),
 "A lo largo de la habitaci�n hay dispuestos varios cirios ardiendo. Son velas "
 "bajas y gruesas colocadas dentro de unos recipientes de cristal. Los cirios "
 "est�n encendidos, pero su llama casi apenas se ve. La cera al quemarse despide "
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
