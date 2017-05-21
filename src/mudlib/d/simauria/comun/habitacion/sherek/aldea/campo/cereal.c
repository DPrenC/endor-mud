/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/campo/cereal.c
Autor: Lug y Yalin
Fecha: 15/01/2007
Descripci�n: Base para los campos de cereales de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("un campo de cultivo en la granja de la aldea de Sloch");
    SetIntLong("Est�s en un campo roturado que se dedica a la plantaci�n "
        "de los diferentes tipos de cereal que son producidos en esta "
        "aldea. Puedes ver surcos paralelos donde nacen las plantas.\n");
    SetIntSmell("Hueles a tierra removida y a campo.\n");
    SetIntNoise("Solamente se escuchan zumbidos de insectos, el viento al "
        "pasar entre las hojas y el canto de alg�n ave.\n");
    AddDetail(({"suelo"}), "ves por todas partes tierra removida que te "
        "indica que este lugar est� cultivado.\n");
    AddDetail(({"cereal","cereales","planta","plantas"}),"son diversos tipos "
        "de cereales que han sido plantados en este lugar para ser "
        "consumidos cuando maduren.\n");
    AddDetail(({"surcos", "surco"}), "son unos surcos paralelos que se "
        "extienden por toda la plantaci�n, han sido hechos con el arado y "
        "sirven para plantar en ellos las diferentes plantas que hay aqu�.\n");
}
