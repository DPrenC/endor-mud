/***
fichero: /guilds/guardabosques/train/magia.c
30/08/2004. Kastwey@simauria. A�adido el SetIntShort.
***/

#include "path.h"
#include <money.h>

inherit TRAIN_BASE;

create()
{
  ::create();

  SetIntShort("la habitaci�n de aprendizaje de magia");
  SetIntLong(W("Aqu� puedes aprender habilidades m�gicas nuevas, as� como "
  	"entrenar tu magia cuando hayas llegado a tu nivel m�ximo. "
  	"Las paredes est�n llenas de estanter�as donde "
  	"ves much�simos libros y objetos m�s o menos arcanos, plantas, etc. "
     "Al norte parece estar la habitaci�n de entrenamiento f�sico. Ves un "
     "cartel que podr�as leer.\n"));

    SetIndoors(1);
    SetIntBright(50);

    AddDetail("cartel", "Es un cartel. Podr�as leerlo.\n");
  AddReadMsg("cartel", W(
"Lees el cartel:\n"
"Safras puede ense�arte diversas habilidades, as� como ayudarte a mejorar las "
"que ya conoces, cuando has llegado a su l�mite us�ndola por tu cuenta. Las "
"habilidades que puedes aprender y sus niveles se detallan a continuaci�n:\n\n"
"Nivel        Habilidad\n"
"-----        ---------\n"
"  5 ........ Corteza de �rbol (corteza)\n"
"  8 ........ Calmar animales (calmar)\n"
" 10 ........ Convocar animales (convocar)\n"
" 15 ........ Sangre �rbol (sangre)\n"
" 15 ........ Piel p�trea (piedra)\n"
" 20 ........ Transmutaci�n en animal (transmutar)\n"
"25 ......... Miedo paralizante (miedo)\n"
" 30 ........ Piel f�rrea (hierro)\n\n"
"El nombre entre par�ntesis denota el comando de aprendizaje. Por ejemplo, "
"para aprender la corteza de �rbol, se deber� poner 'aprender corteza'.\n"));

  AddExit("norte", TRAIN+"habilidades");
  AddItem(BASE+"/pnj/safras");
}
