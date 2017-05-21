/***************************************************************************************
 ARCHIVO:	acian.c
 AUTOR:		[z] Zomax
 FECHA:		18-12-2001
 COMENTARIOS:	Acian, un pescador.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Acian el pescador","humano",10,GENERO_MASCULINO);
  SetWhimpy(10);
  SetAlign(50);
  SetAggressive(0);
  SetName("Acian");
  SetIds(({"humano","acian","Acian","pescador"}));
  SetShort("Acian el pescador");
  SetLong(W("Acian es un humano de mediana edad que le gusta sentarse tranquilamente "
  	"a charlar y beber con los amigos o a pescar en el muelle mientras fuma en pipa. "
  	"Aunque la verdad es que eso es lo que dice él. La realidad es que siempre se "
  	"pasa los días en la taberna con sus amigos.\n"));
  AddQuestion(({"concurso","concurso de pesca"}),W("Acian te dice: Ah si, el concurso. Hay un concurso "
  	"en la cofradía, pero son demasiado estrictos. Yo una vez pesqué el pez más "
  	"grande que nadie ha visto, pero se me volvió a caer al lago. De todas formas "
  	"me considero el ganador moral, por eso no me preocupa volver a pescar para el "
  	"concurso, no tengo nada que demostrar.\n"),1);

  AddItem(RHOEVAR("koek/comercio/carpinteria/pipa"),REFRESH_REMOVE);
  AddItem(RHOEVAR("koek/comercio/herbolario/tabaco"),REFRESH_ALWAYS);
}
