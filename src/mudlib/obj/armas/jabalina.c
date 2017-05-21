/* Fichero: jabalina.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_JABALINA, 8, P_SIZE_GENERIC, M_HIERRO);
   SetShort("una jabalina");
   SetLong(
   "Es una corta lanza de mango recto y algo m�s grueso hacia la parte final.\n"
   "Est� rematada por una cabeza met�lica c�nica y pesada para proporcionar potencia al "
   "arma cuando es arrojada. Este tipo de lanzas son utilizadas como armas arrojadizas a "
   "corta distancia o de combate cuerpo a cuerpo con un escudo. Adem�s, son muy �tiles "
   "en la caza de animales de gran tama�o como jabal�es o ciervos. Son muy utilizadas "
   "por las razas m�s menudas de la Tierra Media.\n");
   AddId(({"jabalina","lanza","venablo"}));
}
