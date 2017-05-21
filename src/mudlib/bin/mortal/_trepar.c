//Nyh
//Creada para que no de un urg? cuando escribes esta accion y no tienes nada.

int main(string str) {
//  if (TP->QueryCombatDelay())
//    return notify_fail(this_player->QueryCombatDelayMsg());
  if (!str) return notify_fail("¿Trepar qué?.\n");
  return notify_fail("No puedes trepar por ahi.\n");
}
