/****************************************************************************
Fichero: entrenamiento.c
Autor: Kastwey
Fecha: 04/02/2006 (no tenía cabecera así que esta es la fecha ;) )
Descripción: La entrada de la zona de entrenamiento de los guardabosques. Como
no tiene cabecera, la pongo yo.
****************************************************************************/

#include "path.h"
inherit TRAIN_BASE;

int cmd_oeste()
{
  write(W("Prefieres ir por el camino marcado para el entrenamiento, que es "
  	"hacia el norte, o si lo que quieres es ir al gremio, puedes ir hacia "
  	"el este.\n"));
  return 1;
}

create(){
  ::create();

  SetIntShort("una habitación al aire libre");
  SetIntLong(W("Estás en una habitación al aire libre. Al parecer estás en la "
  	"zona destinada al entrenamiento de los miembros del gremio. Hacia el "
  	"norte está la zona de práctica, y hacia el sur la zona de aprendizaje "
  	"asistido por profesores.\n"));

  AddExit("este", BASE+"gremio");
  AddExit("norte", TRAIN+"escalar");
  AddExit("sur", TRAIN+"habilidades");
  AddExit("oeste", SF(cmd_oeste));
}

varargs int allow_enter(int method, mixed extra)
{
  if (!TI) return ME_NO_ENTER;
  if (TP->QueryGuild()!=GC_GUARDABOSQUES && !query_wiz_level(TP)) return ME_NO_ENTER;
  return ::allow_enter(method, extra);
}
