
/*---------------------------------------------------------------------------
  28-10-98 [Woo@Simauria]   Creacion.
  ----------------------------------------------------------------------------*/

#include "./path.h"
#define AUDAZ "/d/akallab/comun/transporte/barco/audaz/audaz"
#define BENOSHAN "/d/goldhai/comun/transporte/barco/benoshan/benoshan"

inherit PORT;

create(){
    ::create();
   SetIntShort("el puerto de Gorat");
    SetIntLong(
        "Est�s en el puerto pesquero de Gorat. Se trata de un puerto  de madera bastante "
        "peque�o y viejo.\n  Puedes ver una caseta de pescadores aqu� en medio.\n"
        " A lo lejos, hacia el norte y pasando un embarcadero, se divisa el famoso "
        "faro de Gorat.\n Regularmente aqu� atraca un barco que lleva a la isla de Goldhai, "
        "otro que lleva al pueblo mercante de Berat y otro a la ciudad orca de Azzor.\n"
        " Apoyada contra la pared de la caseta, puedes ver una tabla vieja y cuarteada "
        "en la que aparecen reflejados los barcos que hacen escala en este puerto.\n");
    SetIndoors(0);
    SetClimateServer(SERVER);
    SetIntNoise("Puedes oir todo el ruido que genera un puerto.\n");
    SetIntSmell("Huele a pescado.\n");

    AddDetail(({"mar","oceano","agua", "oc�ano"}),
        "Es como un gran lago pero con agua salada.\n");
    AddDetail(({"caseta del pescador","caseta pescador","caseta"}),
        "Cuatro maderos con un techo de ramas.. hay que ver a lo que llaman algunos"
        "caseta de pescadores.\n");
    AddDetail(({"puerto","puerto","habitacion","lugar"}),
        "Es un puerto de pescadores.\n");
    AddDetail(({"barco","barcos"}),
        "Ves unos pequenyos barcos medio hundidos atracados en el muelle...\n");

    AddShip(BENOSHAN);
    AddShip(AUDAZ);
    AddShip(RADIANTE("radiante"));

    AddExit("este", BETWA "gorat/calles/callep0");
    AddExit("norte",BETWA "gorat/playa/embarcadero");

    SetLocate("puerto de Gorat");
}
