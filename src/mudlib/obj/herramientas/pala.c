/*
Fichero: pala.c
Autor: Aule
Fecha: 20/09/2014
Descripci�n: una pala para cavar o lo que se tercie.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
 ::create();
  SetStandard(WT_IMPROVISADA, 3, P_SIZE_LARGE, M_HIERRO);
 SetShort("una pala");
 SetLong(
 "Es una pala formada por un s�lido mango de madera y una hoja c�ncava de punta "
 "redondeada para permitir recoger tierra, piedras o lo que se desee. El borde est� "
 "ligeramente afilado para poder hincar la herramienta en el terreno.\n");
 AddId(({"pala","pala de cavar", "herramienta"}));
 SetWeight(2500);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
}
