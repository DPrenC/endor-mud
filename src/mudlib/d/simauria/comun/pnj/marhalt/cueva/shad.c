/**********************************************************************
*    Nombre: shad.c                                                   *
*    Localizacion: Cueva de los Trolls                                *
*    Realizada por : Cajun, el ejecutor                               *
*    Coautores: Adamas, Guybrush                                      *
*    Creado : 17-11-99                                                *
*    Modificado: 30-02-00 -> Movimiento                               *
*                24-03-00 -> Quitado el movimiento                    *
*                31-03-00 -> Añadido el caparazon                     *
*                02-04-00 -> Quitados varios typos                    *
*                14-09-01 -> Nyh le mete mano pa ponerlo bien         *
***********************************************************************/

#include <rooms.h>
#include <properties.h>
#include <gremios.h>
#include "path.h"

inherit NPC;

create() {
  ::create();
  SetStandard("Shad","shad",([GC_LUCHADOR: 55]),GENDER_MALE);
  SetShort("un shad");
  SetLong("Un monstruo cubierto de un caparazón de concha con una pequeña cabeza en \
en la parte central de su torso. Sus dos brazos terminan en dos grandes \
pinzas. Su larga cola serpentea inquietamente moviendo un mechón de pelo en \
su punta. Debido a su color negro obsidiana se funde en la oscuridad.\n");
  SetHands( ({ ({"pinza derecha",0,10}),({"pinza izquierda",0,10}),({"cola",0,15}) }) );
  SetAggressive(1);
  SetAlign(-500);
  SetAC(25);
  SetSize(P_SIZE_LARGE);
  AddItem(OBJETO+"otro/caparazon",REFRESH_REMOVE,SF(wearme));
}
