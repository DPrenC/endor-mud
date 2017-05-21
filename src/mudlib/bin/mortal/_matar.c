// Comando matar

#include <search.h>

public int main(string str) {
  object eob;

  if (!TP) return 0;

  if (TP->QueryGhost()) {
    return notify_fail("Eres un espíritu desprovisto de una envoltura de carne mortal y no puedes hacer eso.\n",
                       NOTIFY_NOT_CMD);
  }
  if (!sizeof(str)) {
    return notify_fail("¿Matar a QUIÉN?\n", NOTIFY_ILL_ARG);
  }
  eob = search(TP, lower_case(str), SEARCH_ENV|SM_OBJECT&(~(SM_LOCATE)));
  if (!TP->CanSeeObject(eob)) {
    return notify_fail(""+str+" no está aquí.\n", NOTIFY_NOT_VALID);
  }
  if (!living(eob)) {
    return notify_fail(capitalize(str)+" no esta vivo.\n", NOTIFY_NOT_VALID);
  }
  if (eob == TO) {
    return notify_fail("Si piensas que el suicidio es una alternativa, "
                       "escribe 'suicidar'.\n", NOTIFY_NOT_VALID);
  }

  return TP->Kill(eob);

}