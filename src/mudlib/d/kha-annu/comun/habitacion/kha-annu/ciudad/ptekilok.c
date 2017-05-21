#include "./path.h"
inherit KHA_ROOM;

pescar() {
  object guardia;
     {
        if (present("canya",TP) || present("caña",TP)) {
	        seteuid(getuid(TO)); // Faltaba Esta Linea [Kintups]
            guardia = clone_object(MONS+"guardia");
            guardia->move(environment(TP));
            write(
"Ves llegar a un Guardia Enano. Al parecer te ha visto pescando... ahora es "
"cuando te das cuenta de que hay un cartel adosado al puente que prohibe pescar "
"en este río.\n");
            call_out("gdecir",3);
            return 1;
        }
        else {
            write("No podras pescar sin el equipo apropiado.\n");
            return 1;
        }
     }
}

gdecir() {
   tell_room(CIUDAD+"ptekilok",
"El Oficial de la Guardia dice: Esta prohibida la pesca dentro de la ciudad.\n"
"Vamos! Circule, fuera!\n");

    call_out("Ataque",30);
    return 1;
}

Ataque() {
}

create() {
  ::create();
  SetPreIntShort("sobre");
  SetIntShort("un puente en Kha-annu");
  SetIntLong(
"Estas sobre un puente encima del río Gaut-Kilok. Es un viejo puente de\n\madera muy resistente; tendra por lo menos dos siglos de antiguedad pero no\n\por ello esta descuidado, al contrario el puente parece muy solido. Puedes\n\ver peces de todos los colores surcando y saltando las cristalinas aguas\n\del río. Unas grandes antorchas iluminan el puente dia y noche.\n");  SetIndoors(1);  // con valor 0, la hab. estara al aire libre.
  SetIntBright(80);  // Luz entrante en la hab.
  AddDetail(({"antorchas","antorcha"}),
  "Son solo un par de antorchas que iluminan el puente. No desprenden fuego, ni "
  "ninguna clase de gas... solo un brillo azul.\n");
  AddDetail("puente",
  "Este es el puente sobre el río Gaut-Kilok, el mas caudaloso de Kha-annu "
  "Una señal de madera llama tu atencion.\n");
  AddDetail(({"senyal","senyal de madera"}),"Parece una vieja senyal de madera. Tiene algo escrito.\n");
  AddDetail(({"río","Gaut-Kilok","río Gaut-Kilok"}),
  "Los llamativos peces saltan sobre la espuma del agua del río.\n");
  AddReadMsg(({"señal","senyal"}),
  "La señal pone: río Gaut-Kilok, PROHIBIDA LA PESCA.\n");
  AddExit("sur",CIUDAD+"kilok6");
  AddExit("norte",CIUDAD+"kilok7");
}

init() {
   ::init();
   add_action("pescar","pescar");
}