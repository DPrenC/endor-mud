// Comando casa

#include <stdrooms.h>
#include <moving.h>

public int main(string str) {
  mixed rc;
  string home;

  if (!TP) return 0;

  home = TP->QueryHome();

  if (   !sizeof(home)
      || catch(rc = TP->move(home, M_TELEPORT))
      || rc != ME_OK)
    TP->move(CENTER, M_TELEPORT);
  return 1;
}