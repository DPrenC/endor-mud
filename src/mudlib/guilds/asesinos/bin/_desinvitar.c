#include "../sys/asesinos.h"
#include <combat.h>

int main(string str) {
object target;
  if (TP->QueryGuildLevel() < 50) return 0;
  if(!str)
  {
     write(W("A quien deseas desinvitar del gremio?\n"));
   	 return -1;
  }
  if (!find_object(lower_case(str)))
  {
      write(W("No ves a "+capitalize(str)+" a tu alrededor.\n"));
      return -1;
  }
  target=present(str,environment(TP));
  if (!target)
  {
      write(W("No ves a "+capitalize(str)+" a tu alrededor.\n"));
      return -1;
  }
  if(target==TP)
  {
      write(W("Desinvitar a uno mismo? Je je je.\n"));
      return -1;
  }
  if(!(target->Query("I_WAS_INVITED_BY_ASSASSINS")))
  {
     write(W(capitalize(str)+" no estaba en la lista de invitados.\n"));
     return -1;
  }
  write(W("Sacas a "+capitalize(str)+" de la lista de invitados a gremio.\n"));
  tell_object(target,W(capitalize(getuid(TP))+" te ha quitado de la lista de invitados a Las Rosas Negras.\n"));
  target->Set("I_WAS_INVITED_BY_ASSASSINS",0);
  return 1;
}
