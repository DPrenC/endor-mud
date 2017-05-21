/*
DESCRIPCION  : Calle de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/calle01.c
MODIFICACION :
04-02-99 [Angor] Creacion
16-09-07 [Angor] Correccion de typos
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <door.h>
#include <scheduler.h>
#include <sounds.h>
inherit ROOM;

create() {
  ::create();
 SetIntShort("la calle del pueblo de Gaddaro");
  SetIntLong(
  "Te encuentras a la entrada del peque�o pueblo de Gaddaro. Oyes el ruido "
    "del trabajo en la herreria que queda al este de aqu�. Al oeste se encuentra "
    "una casa particular. Un camino parte de aqu� hacia el sur alejandose del "
    "pueblo.\n");

#include "geografia.ic"
#include "ambiente.ic"

 SetIntNoise("Oyes el ruido del trabajo en la herreria.\n");

 AddExit("sur",GADDARO("calle00"));
 AddExit("este",GADDARO("herreria"));
 AddExit("oeste",GADDARO("casa01"));
 AddExit("norte",GADDARO("calle02"));
    AddDoor("este","la puerta de la herrer�a",
        "Es una puerta de hierro. No es que nadie vaya a intentar robar aqu�, pero "
            "probablemente el herrero se ha hecho �l mismo la puerta, y �l mismo la repare, "
            "cuesti�n de econom�a...\n",
        ({"puerta","puerta este","puerta de herrer�a","puerta de la herrer�a"}),GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando ves que la puerta no se abre, recuerdas que el "
                "herrero tambi�n necesita descansar...\n","Buscas una puerta que abrir, pero "
                "en la oscuridad te va a resultar imposible...\n"}),({"@nombre@ trata de "
                "entrar en la herrer�a, seguramente piensa que los herreros no duermen...\n",
                "Oyes que alguien se remueve furioso en las sombras...\n"}),"Parece que "
                "alguien trata de abrir la puerta...\n"})]));
}
