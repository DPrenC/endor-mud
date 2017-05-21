/****************************************************************************
Fichero: cam_cortado10.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: El camino entre montañas que se dirije a la cueva de los trolls.
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";

create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntLong(" Aquí la pendiente del desfiladero deja de ser tan pronunciada "
    "continuando su ascenso en dirección este, mientras que al suroeste se precipita en "
    "una profunda garganta. Justo al norte la oscura boca de una cueva parece bostezar,"
    " rodeada por algunos esqueletos que no presagian nada bueno. La quietud solo "
    "se ve interrumpida por el rodar de alguna piedrecita suelta, el goteo del agua "
    "sobre las piedras y el lúgubre canto del viento entre las aristas de roca.\n"
    " El lugar aparece limpio de vegetación como si alguien la hubiera arrancado por "
    "completo, y en algunos lugares donde la escasa agua ha creado algo de fango pueden "
    "apreciarse unas marcas extrañas.\n");
    AddDetail(({"huellas","huella", "marca", "marcas"}),
    "  Al fijarte con mas atención en las marcas, descubres que se trata de huellas. Y "
    "son unas huellas muy grandes. Peor aún, te parece reconocer que el pie que "
    "reposó aquí contaba con unas garras bestiales.\n");
    AddExit("suroeste", "./cam_cortado09");
    AddExit("este", "./cam_cortado11");
    AddExit("norte",MARH("cueva/cueva00"));

}
