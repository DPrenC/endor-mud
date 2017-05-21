/* Fichero: herradura_g.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: una herradura para cabalgaduras grandes como caballos
*/

#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetValue(100);
  SetWeight(700);
  SetIds(({"herradura","herradura de caballo"}));

  SetShort("una herradura");
  SetLong(
  "Es una herradura, una sólida lámina de hierro con forma más o menos de arco y "
  "orificios para introducir los clavos que la unen al casco del animal. Sirve para "
  "impedir el desgaste excesivo de los cascos de las monturas.\n");
}