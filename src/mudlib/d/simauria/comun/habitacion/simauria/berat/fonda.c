/*
DESCRIPCION  : fonda
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/fonda.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
[Mal]
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <moving.h>
#define RUTA "/d/simauria/comun/pnj/simauria/berat/"
inherit SHOP;

int go_east() {
    if (sk_in_shop() && (present("llave1",TP) || present("llave2",TP) )) {
        write("El posadero salta el mostrador para detenerte y te dice:\n ¡Eh, "
        +TP->QueryRace()+"! A donde vas con esa llave!? ¡Tienes que depositarla antes "
        "de salir!\n");
        say("El posadero salta el mostrador y detiene a" +TP->QueryName()+
        " para reclamarle la llave.\n");
      return 1;
    }else {
       TP->move("./cprin4",M_GO);
       return 1;
    }
}

create() {
    ::create();

     SetIntShort("la posada de Grenel");
     SetIntLong("Estás en la vieja posada de Berat, parece una posada tranquila "
    "y acogedora, los tapices polvorientos y las antorchas casi consumidas "
    "te indican que no es una posada muy visitada, al fondo ves el mostrador "
    "con su correspondiente timbre para llamar al posadero, y a la derecha "
    "las escaleras que conducen a las habitaciones.\n");
    SetIntBright(30);
    AddArticle(OTRO("llave1"),REFRESH_REMOVE,1);
    AddArticle(OTRO("llave2"),REFRESH_REMOVE,1);
    RemoveDustbin();
    SetSell(0);
    CanShow(0);
    SetAppraise(0);
    SetIdentify(0);

    AddDetail(({"alfombra","gran alfombra"}),
    "Cubre todo el suelo y esta decorada con rombos y figuras geométricas.\n");
    AddDetail(({"escalera", "escaleras"}),
    "Son unas escaleras de madera polvorientas.\n");
    AddDetail("mostrador",
    "Es un mostrador de madera, bastante viejo y polvoriento.\n");
     AddDetail("timbre",
    "Es un pequeño timbre que puedes usar para llamar la atención del encargado.\n");
    AddDetail(({"luces", "antorchas"}),
    "Aun estando desgastadas, iluminan la habitación.\n");
    AddDetail(({"pared","paredes"}),
    "No parecen envejecer con el paso de los años, únicamente se aprecia su vejez, en "
    "el polvo acumulado.\n");
    RemoveExit("almacen");
    AddExit("arriba","./fonda2");
    AddExit("este", "./cprin4");
    AddDoor("este", "la puerta de salida",
    "Es la puerta de salida que da a la calle principal.\n",
    ({"puerta", "puerta de salida", "puerta del este"}));
    SetCloseTime(({}));
    SetLocate("berat");
   SetShopkeeper(PNJ("simauria/berat/posadero"));
}

init() {
   ::init();
    add_action("Devuelta","depositar");
    add_action("Devuelta","devolver");
    add_action("Devuelta","entregar");
    add_action("Venta","vender");
    add_action("Timbre","usar");
    add_action("Timbre","tocar");
    add_action("Timbre","llamar");
    add_action("Timbre","pulsar");
    add_action("Timbre","apretar");
    add_action("Timbre","golpear");
    add_action("Matar","matar");
}

Devuelta(string str) {
object ob;
   if (str != "llave" &&
       (present("llave1",TP) || present("llave2",TP) || present("llave3",TP) ) ) {
          write("Depositar QUE?\n");
          return 1;
   }
   if (!sk_in_shop())
   {
     return notify_fail("Parece que el tendero no está.\n",
                        NOTIFY_NOT_VALID);
   }
if (!present("llave",TP)) return 0;
   if (present("llave1",TP)) {
       ob = present("llave1",TP);
       ob->remove();
       if(ob) destruct(ob);
       write("Entregas la llave a Grenel, y este la guarda en su bolsillo.\n");
       say(
TP->QueryName()+" entrega una llave a Grenel.\n");
       tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve "
                 "cuando quieras.\n");
       TO->AddArticle(OTRO("llave1"),REFRESH_REMOVE,1);
       return 1;
   }
   if (present("llave2",TP)) {
       ob = present("llave2",TP);
       ob->remove();
       if (ob) destruct(ob);
       write("Entregas la llave al posadero, y este la guarda en su bolsillo.\n");
       say(
TP->QueryName()+" entrega una llave al posadero.\n");
       tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve "
                 "cuando quieras.\n");
       TO->AddArticle(OTRO("llave2"),REFRESH_REMOVE,1);
       return 1;
   }
}
Matar(string str) {
   if (str == "posadero" || str == "Grenel" || str == "el posadero" ||
       str == "al posadero" || str == "grenel" || str == "Grenel, el posadero") {
      write("No sería muy inteligente matar al posadero en su posada, "
            "con tantos guardias por aquí.\n");
      return 1;
   } else return 0;
}

Timbre(string str) {
      if (str != "timbre")  {
	 write("Que quieres hacer con eso?.\n");
	 return 1;
      }
        if (QueryShopkeeper()) {
         write("Aporreas el timbre que hay en el mostrador.\n");
         say(TP->QueryName()+" toca el timbre del mostrador.\n");
         tell_room(TO, "El posadero dice: Hey! "+capitalize(TP->QueryRace())+
                       "! Estoy aqui! Que deseas?\n");
  return 1;
      } else {
          write("Aporreas el timbre del mostrador pero nadie acude a atenderte.\n");
          say(TP->QueryName()+" toca el timbre que hay sobre la barra.\n");
          return 1;
   }
}

int Venta(string str) {
    if (!str) { write("Vender que?\n"); return 1; }
    if (QueryShopkeeper()) {
    write("Intentas vender tu "+str+" al posadero.\n");
    say(TP->QueryName()+" intenta vender algo al posadero.\n");
    tell_room(TO,
"El posadero dice: No, "+TP->QueryRace()+". No suelo comprar nada.\n");
    return 1;
    } else {
      write("No ves aqui a nadie para venderle nada.\n");
      return 1;
    }
}