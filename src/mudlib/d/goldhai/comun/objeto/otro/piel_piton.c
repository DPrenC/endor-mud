/****************************************************************************
Fichero: piel_piton.c
Autor: Ratwor
Fecha: 16/08/2007
Descripci�n: La piel de la pit�n real para el cintur�n de Gaena.
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit THING;
private int pGender;
public int SetGender(int gen) { return pGender = gen; }
public int QueryGender() { return pGender; }
create(){
    ::create();

    SetShort("la piel de una pit�n Real");
    SetLong("es la piel de una Pit�n Real, tiene tonos de negro, crema, amarillo y "
    "blanco. Mide poco m�s de un metro y tiene un tacto peculiar.\n");
    SetWeight(1000);
    SetValue(1100);
    SetSize(P_SIZE_SMALL);
    AddId(({"piel", "piel de serpiente", "piel de pit�n", "piel de piton", "piel_gaena"}));
    SetGender(GENERO_FEMENINO);
}
