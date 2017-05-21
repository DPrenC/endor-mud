// Comando parar
#include <wizlevels.h>
#include <properties.h>
#include <moving.h>

public int main (string str) {
  if (!TP) return 0;

  switch (str) {
    case "de atacar":
        TP->RemoveEnemies();
        write("Dejas de atacar a tus enemigos.\n");
        return 1;
    case "de perseguir":
        TP->RemoveHunters();
        write("Dejas de perseguir a tus víctimas.\n");
        return 1;
    case "de seguir":
        TP->Set(P_IS_FOLLOWER, FOLLOW_NO); //FOLLOW_NO = 0
        write("Ok, ya no sigues a nadie.\n");
        return 1;
    case "de espiar":
        if (IS_WIZARD(TP)) {
            snoop(TP); // Finaliza las espias de TP
            write("Ok, ya no espías a nadie.\n");
            return 1;
        }
    }

  if (IS_LEARNER(TP))
    return notify_fail("Uso:\n"
                "parar de atacar         Deja de atacar.\n"
                "parar de perseguir      Deja de perseguir.\n"
                "parar de seguir         Deja de seguir.\n"
                "parar de espiar         Deja de espiar.\n");
  return notify_fail("Uso:\n"
                "parar de atacar         Deja de atacar.\n"
                "parar de perseguir      Deja de perseguir.\n"
                "parar de seguir         Deja de seguir.\n");
}
