/* Fichero: mangual.h */
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MANGUAL, 8, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un mangual");
   SetLong(
   "Este mangual est� formado por un grueso mango de dura madera de unos setenta "
   "cent�metros de longitud rematado por un aro de hierro del que cuelga una cadena algo "
   "m�s larga que sujeta una gruesa bola de hierro macizo.\n"
   "Los golpes proporcionados por la bola y la cadena al balancear el arma son muy "
   "da�inos, y puede llegar a arrancarse el arma del oponente, aunque su manejo es "
   "engorroso y requiere gran fuerza, siendo adem�s poco precisa.\n"
   "No es un arma muy com�n en la Tierra Media, aunque los orcos, trasgos y algunos "
   "clanes de Enanos gustan de empu�arlas en combate.\n");
  }