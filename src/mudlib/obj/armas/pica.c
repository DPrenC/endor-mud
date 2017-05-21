/* Fichero: pica.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_PICA, 10, P_SIZE_LARGE, M_HIERRO);
   SetShort("una pica");
   SetLong(
   "La pica es una versi�n mucho m�s larga de la lanza, midiendo unos cuatro metros y "
   "medio o incluso m�s. cuenta con una contera de bronce en la parte posterior para "
   "afianzarla en el suelo o la parte interna del pie, un mango recio y forrado en "
   "tejido de cuerda de esparto a trechos para facilitar su agarre, y una punta pesada y "
   "algo m�s larga de lo habitual, para maximizar su potencia de penetraci�n.\n"
   "Las picas son muy poco utilizadas en la Tierra Media y solo por tropas muy bien "
   "entrenadas que cuenten con el n�mero suficiete de efectivos para presentar un "
   "infranqueable frente de puntas de hierro. En otros casos resulta un arma engorrosa "
   "de manejar y pr�cticamente in�til en combate singular.\n");
}