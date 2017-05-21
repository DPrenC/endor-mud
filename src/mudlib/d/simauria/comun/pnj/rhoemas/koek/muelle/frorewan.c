/***************************************************************************************
 ARCHIVO:	frorewan.c
 AUTOR:		[z] Zomax
 FECHA:		18-12-2001
 COMENTARIOS:	Frorewan, un pescador.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Frorewan el pescador","humano",10,GENERO_MASCULINO);
  SetWhimpy(10);
  SetAlign(50);
  SetAggressive(0);
  SetName("Frorewan");
  SetIds(({"humano","frorewan","Frorewan","pescador"}));
  SetShort("Frorewan el pescador");
  SetLong(W("Frorewan es un humano no muy joven que se dedica la mayor parte del "
  	"tiempo a fanfarronear de sus grandes capturas con la caña, como buen pescador "
  	"que se precie. Algunas veces se pasa por el muelle a pescar con sus amigos, "
  	"quizás para dar un toque de realismo a sus historias, pero suele estar "
  	"casi siempre en la taberna que hay en el hogar del pescador, contando sus "
  	"historias a quien quiera entre copa y copa.\n"));
  AddQuestion(({"concurso","concurso de pesca"}),W("Froewan exclama: El concurso... ¡Por todos los dioses!, "
  	"¡se me olvidaba!... bueno, en cuanto acabe de beber iré a pescar.\n"),1);
}
