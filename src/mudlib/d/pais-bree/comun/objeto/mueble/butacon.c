/* 
Fichero: butacon.c
Autor: aule
Fecha: 02/08/2014
Descripción: un sillón para la habitación de Cebadilla.
*/

#include <properties.h>
#include "path.h"
#include <materials.h>

inherit "/std/asiento";

create()
{
    ::create();
    Set("name","un confortable butacón");
    SetDescripcion 
    ("Es un sillón de cuero con brazos, asiento y respaldo mullidos,con un cojín y "
    	"una manta de lana que lo cubren.\n"
    	"Colocado frente al fuego, invita a sentarse en él y echar una cabezadita.\n");
    	AddSubDetail("manta",
    	"Es una manta de suave lana blanca que reposa pulcramente doblada sobre el sillón.\n"
    	"Puede usarse para cubrirse mientras se reposa frente al fuego.\n");
    	AddSubDetail(({"cojin", "cojín"}),
    		"Un cojín mullido y con algunos bordados sencillos.\n");
        AddId(({"sillon","sillón", "butacon", "butacón"}));
    SetAds(({"de","cuero","confortable"}));
        SetValue(10000);
        Set(P_GENDER, GENERO_MASCULINO);
            SetWeight(50000);
SetMaterial(M_CUERO);
    SetMaxPlazas(1);
    SetNoGet("Sería un escándalo que alguien te viera intentando llevarte el ancestral butacón de la familia Mantecona.\n");
    }

