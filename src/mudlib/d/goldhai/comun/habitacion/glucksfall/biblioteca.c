#include "path.h"
#include <moving.h>

inherit "/room/bibl_room";
inherit GROOM;

int cogido;

pergamino()
{
 object perga;

 if (cogido) {
  write("Abres el libro y al leerlo un frio intenso empieza a recorrer tu cuerpo.\n");
  return 1;
 }

 perga=clone_object("/guilds/kisalas/pergamino/pergamino_sombra");
 write("Coges el libro y lo abres. De pronto ves que cae un pergamino antiguo.\n");
 perga->move(TO,M_SPECIAL, "cae al suelo");
 cogido++;
 return 1;
}


create()
{
  ::create();
  SetIntShort("la biblioteca");
  SetIntLong("De la biblioteca solo le queda el nombre el resto es una pura "
             "ruina de cascotes y paredes destrozadas. Ser�a raro que "
             "encontrases alg�n libro en este lugar as� que quiz� sea "
             "mejor que salgas cuanto antes, no se te vaya a caer el techo "
             "encima.\n");
  SetIndoors(1);
  SetIntBright(50);

  SetTema("Las guerras mitol�gicas");
  AddBook("Orcos","Los orcos en la guerra",SF(pergamino));
  AddExit("oeste","calle6");
  SetLocate("Glucksfall");
}

reset()
{ ::reset();
 cogido=0;
}