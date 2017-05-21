/***
fichero: /guilds/guardabosques/train/magia.c
30/08/2004. Kastwey@simauria. Añadido el SetIntShort.
***/

#include "path.h"
#include <money.h>

inherit TRAIN_BASE;

create()
{
  ::create();

  SetIntShort("la habitación de aprendizaje de magia");
  SetIntLong(W("Aquí puedes aprender habilidades mágicas nuevas, así como "
  	"entrenar tu magia cuando hayas llegado a tu nivel máximo. "
  	"Las paredes están llenas de estanterías donde "
  	"ves muchísimos libros y objetos más o menos arcanos, plantas, etc. "
     "Al norte parece estar la habitación de entrenamiento físico. Ves un "
     "cartel que podrías leer.\n"));

    SetIndoors(1);
    SetIntBright(50);

    AddDetail("cartel", "Es un cartel. Podrías leerlo.\n");
  AddReadMsg("cartel", W(
"Lees el cartel:\n"
"Safras puede enseñarte diversas habilidades, así como ayudarte a mejorar las "
"que ya conoces, cuando has llegado a su límite usándola por tu cuenta. Las "
"habilidades que puedes aprender y sus niveles se detallan a continuación:\n\n"
"Nivel        Habilidad\n"
"-----        ---------\n"
"  5 ........ Corteza de árbol (corteza)\n"
"  8 ........ Calmar animales (calmar)\n"
" 10 ........ Convocar animales (convocar)\n"
" 15 ........ Sangre árbol (sangre)\n"
" 15 ........ Piel pétrea (piedra)\n"
" 20 ........ Transmutación en animal (transmutar)\n"
"25 ......... Miedo paralizante (miedo)\n"
" 30 ........ Piel férrea (hierro)\n\n"
"El nombre entre paréntesis denota el comando de aprendizaje. Por ejemplo, "
"para aprender la corteza de árbol, se deberá poner 'aprender corteza'.\n"));

  AddExit("norte", TRAIN+"habilidades");
  AddItem(BASE+"/pnj/safras");
}
