/* Izet@Simauria */

#include "path.h"
#include <moving.h>

inherit KHA_ROOM;

int go_up();
int Nada();

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("El corredor es estrecho aquí. Sobre ti ves una salida que quizá pudieses "
        "alcanzar. El pasillo se prolonga hacia la oscuridad y tus ojos no son capaces de "
        "penetrar el denso manto de sombras... tu conciencia casi te fuerza a retroceder. "
        "Huele a algo como... ¡¡¡ohhh!!!\n");
    SetIndoors(1);
    SetIntBright(30);
    AddDetail("suelo","El suelo esta lleno de restos de comida podrida. Parece que nadie ha "
        "pasado por aquí desde hace tiempo.\n");
    AddDetail(({"salida","techo"}),"Arriba ves una salida. Siendo lo suficientemente hábil, "
        "crees que podrías alcanzarla.\n");
    AddExit("norte",CLOACAS+"cloaca2");
    AddExit("arriba",SF(Nada));
    HideExit("arriba",1);
    AddRoomCmd("trepar",SF(go_up));
}

int Nada()
{
    write("No podrás subir tan fácilmente, deberás trepar.\n");
    return 1;
}

int go_up()
{
    int RAN_DES;
    RAN_DES = random(TP->QueryDex())+1;
    if (RAN_DES < 5)
    {
        write("Empiezas a subir por las paredes intentando trepar, pero no eres lo "
            "suficientemente hábil, y caes al suelo de nuevo.\n");
        say(TP->QueryName()+" empieza a trepar, pero resbala y cae al suelo.\n",TP);
        if (RAN_DES == 1)
        {
            write("¡Aaay! ¡Te has hecho mucho daño!\n");
            say("¡Ufff, parece que se ha hecho daño!\n",TP);
            TP->SetHP( (TP->QueryHP()) - random(30) );
            return 1;
        }
        else { return 1; }
    }
    else
    {
        write("Empiezas a trepar hacia la salida, y abres la trampilla.\n");
        say(TP->QueryName()+" trepa hasta la salida, abre la trampilla y desaparece.\n",TP);
        TP->move(PISO1+"stair1",M_SILENT);
        TP->LookAfterMove();
        return 1;
    }
}
