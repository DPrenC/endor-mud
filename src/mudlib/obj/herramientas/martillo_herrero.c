/*  Fichero: martillo_herrero.c
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: martillo gen�rico para forjar y reparar objetos met�licos.
Tama�o humano*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_MARTILLO, 3, P_SIZE_LARGE, M_HIERRO);
  SetShort("un martillo de herrero");
  SetLong(
  "Este pesado martillo est� dise�ado para la forja y el moldeado de metales. Una de las "
  "caras es redonda y plana mientras que la otra se estrecha hasta convertirse en una "
  "simple arista. El mango de la herramienta est� forrada de metal y cuero para evitar "
  "que el intenso calor, el metal al rojo y las brasas lo da�en.\n");
  AddId(({"martillo", "herramienta", "martillo_herrero", "martillo_forja"}));
  AddAdjective(({"pesado", "de", "hierro"}));
  SetWeight(3000);
}