/* Fichero: jabalina.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_JABALINA, 8, P_SIZE_GENERIC, M_HIERRO);
   SetShort("una jabalina");
   SetLong(
   "Es una corta lanza de mango recto y algo más grueso hacia la parte final.\n"
   "Está rematada por una cabeza metálica cónica y pesada para proporcionar potencia al "
   "arma cuando es arrojada. Este tipo de lanzas son utilizadas como armas arrojadizas a "
   "corta distancia o de combate cuerpo a cuerpo con un escudo. Además, son muy útiles "
   "en la caza de animales de gran tamaño como jabalíes o ciervos. Son muy utilizadas "
   "por las razas más menudas de la Tierra Media.\n");
   AddId(({"jabalina","lanza","venablo"}));
}
