/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION :
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetPreIntShort("frente a");
SetIntShort("un panteón");
SetIntLong("  Te encuentras frente a un panteon, por lo que puedes deducir pertenecio\n"
           "a alguien realmente importante de la zona. Esta construido en marmol y es\n"
           "como si no hubiese envejecido por el paso del tiempo. Dentro se puede ver\n"
           "algo de luz. El camino realiza un giro brusco frente a el.\n");

AddDetail(("panteón")," Tiene una gran reja a su entrada,por entre los barrotes se puede\n"
                       "apreciar que dentro,iluminado por la luz de algunas antorchas que\n"
                       "aun quedan encendidas, se puede apreciar la tumba donde yace tan\n"
                       "importante personaje.\n");

AddDetail(("tumba")," Desde esta distancia y con la poca luz, no llegas a distinguir\n"
                      "mucho mas.\n");

AddDetail(({"antorcha","antorchas"})," Estan colgadas en la pared, la mayor de parte de ellas\n"+
		" estan apagadas, aunque quedan un par de ellas encendidas, lo\n"
                "suficiente para dejar entreveer lo que hay en el interior.\n");

AddDetail (({"niebla"}),"  Cerca del suelo es espesa y apenas te deja ver la hierba que\n" +
		        "recubre todo el cementerio,el resto se trata de una niebla mucho\n"
                        "menos densa pero que aun así te impide ver el final del camino.\n");

SetIntNoise("  Se puede oir la suave brisa del viento,que mueve la hierba.Se oye algo mas\n"
            "al fondo, al parecer es el sonido de unas risas muy femeninas.\n");

SetIntSmell("  Pese a ser un cementerio, mira por donde no tiene mal olor.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(20);

AddExit("oeste","mausoleo3");
AddExit("este","mausoleo5");
AddExit("norte","hab_radhul");
}