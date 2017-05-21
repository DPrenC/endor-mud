#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

int cmd_escalar()
{
  int perc;

  if (TP->QueryWeight()>90000)
    return notify_fail("Eres demasiado pesado para subir por la cuerda.\n");

  write("Empiezas a trepar por la cuerda...\n");
  perc=TP->UseSkill(HAB_TREPAR);

  if (perc<1)
    return notify_fail("�Pero se te resbala por entre los dedos!\n");

  write("Consigues escalar hasta una caba�a.\n");
  TP->move(ATB_CI("ciudad12"));

  return 1;
}


create()
{
  ::create();

  SetIntLong(W("En otros tiempos, en tiempos de guerra, esta zona fu� el "
  	"per�metro exterior de defensa; los restos de la muralla externa "
  	"as� lo indican. Con total probabilidad esos muros aguantaron un "
  	"brutal acoso. Claro que quiz�s no, quiz�s su funcion era proteger "
  	"al desvalido mundo del acoso de sus antiguos moradores.\n"
  	"Ahora no es m�s que una zona residencial de segunda plagada de "
  	"caba�as plantadas sin excesivo orden. La calle principal sigue hacia "
  	"el este, y te preguntas hacia d�nde sube esa cuerda que parece estar "
  	"invit�ndote a pegarte el costalazo de tu vida.\n"));

  AddDetail("calle", "La calle central sigue hacia el este.\n");
  AddDetail("cuerda", W("Es una cuerda normal y corriente. Todo aventurero que "
  	"se precie debe tener una tia llamada Gilda que trence cuerdas de ese "
  	"tipo, as� que probablemente sabr�s el material, su rugosidad, el peso "
  	"que puede aguantar y el guarrazo que te puedes dar si se te ocurre "
  	"realizar cualquier otro tipo de tarea que no sea agarrarte fervientemente "
  	"con ambas manos mientras intentes treparla.\n"));
  AddExit("subir", SF(cmd_escalar));
  AddExit("este", ATB_CI("ciudad06"));
  AddExit("sur", ATB_B("bosque32"));
}

