/**
 * /torrewiz/hall.c
 */
// TODO: Mejorar los detalles.

#include "path.h"
#include <wizlevels.h>
#include <moving.h>

inherit ROOM;

int ir_arriba() {
    if (IS_WIZARD(TP)) {
        write("Cruzas el escudo magico.\n");
        TP->move(TORRE("piso1/center"), M_GO);
        return 1;
    } else {
        write("Una fuerza magica te impide subir por las escaleras.\n");
        return 1;
    }
}

int ir_abajo() {
   if (IS_LEARNER(TP)) {
       write("Cruzas el campo magico y bajas al sotano.\n");
       TP->move(TORRE("sotano/center"), M_GO);
       return 1;
   } else {
      write("Una fuerza magica te impide bajar por las escaleras.\n");
      return 1;
   }
}

static string _grabados() {
    return "Las paredes están llenas de dibujos y grabados de escenas de "
    "algún tiempo presente, pasado o futuro, quien sabe. De hecho tienes "
    "la extraña sensación de que cambian ligeramente cada vez que miras, "
    "como si el devenir del tiempo los hiciese evolucionar.\n";
}

create() {
    ::create();
    SetIntShort("el centro de la Torre de los Wizards");
    SetIntLong(
"Te encuentras en la enorme y diáfana sala circular de casi 7 metros de altura "
"que es la entrada principal de la "
"Torre de los Wizards. La habitación está iluminada por una luz cálida que no "
"tiene ningún origen aparente. Sus paredes estan llenas de dibujos y grabados "
"de escenas de algún tiempo presente, pasado o futuro, quien sabe. De hecho "
"tienes la extraña sensación de que cambian ligeramente cada vez que miras, "
"como si el devenir del tiempo los hiciese evolucionar. En el centro una "
"grandiosa escalera se alza imponente.\n"
    );
    SetIntBright(70);

    SetIndoors(1);
    AddDetail( ({"dibujo","dibujos", "grabado", "grabados"}), SF(_grabados));
    AddDetail( ({"escalera"}), "En el centro una grandiosa escalera se alza imponente.\n" );
    AddExit("arriba",SF(ir_arriba));
    AddExit("abajo",SF(ir_abajo));
    AddExit("salir",LIMBO("bridge03"));
}
