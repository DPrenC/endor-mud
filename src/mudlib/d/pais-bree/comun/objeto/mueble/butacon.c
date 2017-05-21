/* 
Fichero: butacon.c
Autor: aule
Fecha: 02/08/2014
Descripci�n: un sill�n para la habitaci�n de Cebadilla.
*/

#include <properties.h>
#include "path.h"
#include <materials.h>

inherit "/std/asiento";

create()
{
    ::create();
    Set("name","un confortable butac�n");
    SetDescripcion 
    ("Es un sill�n de cuero con brazos, asiento y respaldo mullidos,con un coj�n y "
    	"una manta de lana que lo cubren.\n"
    	"Colocado frente al fuego, invita a sentarse en �l y echar una cabezadita.\n");
    	AddSubDetail("manta",
    	"Es una manta de suave lana blanca que reposa pulcramente doblada sobre el sill�n.\n"
    	"Puede usarse para cubrirse mientras se reposa frente al fuego.\n");
    	AddSubDetail(({"cojin", "coj�n"}),
    		"Un coj�n mullido y con algunos bordados sencillos.\n");
        AddId(({"sillon","sill�n", "butacon", "butac�n"}));
    SetAds(({"de","cuero","confortable"}));
        SetValue(10000);
        Set(P_GENDER, GENERO_MASCULINO);
            SetWeight(50000);
SetMaterial(M_CUERO);
    SetMaxPlazas(1);
    SetNoGet("Ser�a un esc�ndalo que alguien te viera intentando llevarte el ancestral butac�n de la familia Mantecona.\n");
    }

