/****************************************************************************
Fichero: cam_cortado10.c
Autor: Ratwor
Fecha: 19/08/2007
Descripci�n: El camino entre monta�as que se dirije a la cueva de los trolls.
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";

create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntLong(" Aqu� la pendiente del desfiladero deja de ser tan pronunciada "
    "continuando su ascenso en direcci�n este, mientras que al suroeste se precipita en "
    "una profunda garganta. Justo al norte la oscura boca de una cueva parece bostezar,"
    " rodeada por algunos esqueletos que no presagian nada bueno. La quietud solo "
    "se ve interrumpida por el rodar de alguna piedrecita suelta, el goteo del agua "
    "sobre las piedras y el l�gubre canto del viento entre las aristas de roca.\n"
    " El lugar aparece limpio de vegetaci�n como si alguien la hubiera arrancado por "
    "completo, y en algunos lugares donde la escasa agua ha creado algo de fango pueden "
    "apreciarse unas marcas extra�as.\n");
    AddDetail(({"huellas","huella", "marca", "marcas"}),
    "  Al fijarte con mas atenci�n en las marcas, descubres que se trata de huellas. Y "
    "son unas huellas muy grandes. Peor a�n, te parece reconocer que el pie que "
    "repos� aqu� contaba con unas garras bestiales.\n");
    AddExit("suroeste", "./cam_cortado09");
    AddExit("este", "./cam_cortado11");
    AddExit("norte",MARH("cueva/cueva00"));

}
