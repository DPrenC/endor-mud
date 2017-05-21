#include "./path.h"

inherit THING;

#define LUZ      20

int valor;

create(){
  ::create();
  valor = LUZ;
  CambiaLuz();
  SetLong("Un hongo luminoso, brillando con una luz azul y pulsante.\n");
  SetWeight (10 + random(20));
  SetValue (0);
  SetLight(LUZ);
  SetIds(({"hongo"}));
}

public int CambiaLuz() {
  if (valor == 0) {
     remove_call_out("CambiaLuz");
     write("El hongo da su último latido de luz, y se pudre en tus manos.\n");
     say("El hongo de "+TP->QueryName()+" se extingue en sus manos.\n");
     if (TO) remove(TO);
     TO->destruct();
     return 1;
  }
  if (valor == LUZ / 5) {
   write("El hongo esta perdiendo parte de su luminosidad azul.\n");
   say("El hongo luminoso de "+TP->QueryName()+" ha perdido brillo.\n");
  }
  if (valor > 0) {
    SetLight(valor);
    valor = valor -1;
    SetShort("un hongo luminoso: " + valor);
    call_out("CambiaLuz",1);
  }
  return 0;
}

string QuerySmell() {
  return "No huele a nada que quisieras comer.\n";
}

string QueryNoise() {
  return "Al acercar mucho el oido, notas un débil latido.\n";
}
