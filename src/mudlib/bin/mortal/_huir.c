// Comando huir
public int main(string arg) {

  if (!TP) return 0;

  if (!TP->Fighting()) return notify_fail("No estás combatiendo .\n");
  if (TP->QueryQuieroHuir()) {
    write("Cambias de idea y decides continuar combatiendo.\n");
    return !(TP->SetQuieroHuir(0));
  }
  else {
    write("Buscas una manera de eludir a tu enemigo y abandonar el combate.\n");
    return TP->SetQuieroHuir(1);
  }
  return 0;
}