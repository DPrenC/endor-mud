/****************************************************************************
Fichero: piel_piton.c
Autor: Ratwor
Fecha: 16/08/2007
Descripción: La piel de la pitón real para el cinturón de Gaena.
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit THING;
private int pGender;
public int SetGender(int gen) { return pGender = gen; }
public int QueryGender() { return pGender; }
create(){
    ::create();

    SetShort("la piel de una pitón Real");
    SetLong("es la piel de una Pitón Real, tiene tonos de negro, crema, amarillo y "
    "blanco. Mide poco más de un metro y tiene un tacto peculiar.\n");
    SetWeight(1000);
    SetValue(1100);
    SetSize(P_SIZE_SMALL);
    AddId(({"piel", "piel de serpiente", "piel de pitón", "piel de piton", "piel_gaena"}));
    SetGender(GENERO_FEMENINO);
}
