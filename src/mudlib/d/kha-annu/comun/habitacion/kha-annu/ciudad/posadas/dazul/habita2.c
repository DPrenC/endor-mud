#define TPHP TP->QueryHP()
#define MAXHP TP->QueryMaxHP()
#include "./path.h"
#include <properties.h>
#include <door.h>
#include "/secure/wizlevels.h"
inherit KHA_ROOM;
int despertar();
int suenyo();

create()
{
    ::create();
    SetIntShort("la habitaci�n normal, en la posada del Drag�n Azul");
    SetIntLong("Te encuentras en la habitaci�n normal. Tiene una cama con s�banas limpias. "
        "Ves una mesita de noche sobre la que hay una vela usada. Una alfombra protege los "
        "pies del fr�o suelo.\n");
    SetIntBright(70);
    SetIndoors(1);
    SetLocate("ciudad de Kha-annu");
    AddDetail(({"alfombra","gran alfombra"}),"Es de color rojo y cubre todo el suelo de la "
        "habitaci�n.\n");
    AddDetail(({"cama"}),"Una cama preparada, con s�banas limpias en la que puedes dormir.\n");
    AddExit("pasillo","pasillo1");
    AddDoor("pasillo","la puerta del pasillo",
        "Es una simple puerta de madera, como las que pudieras encontrar en "
        "cualquier casa.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}), GENDER_FEMALE, "llave2_n",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
}

init()
{
    (::init());
    add_action("getaction","",1);
    getinput();
}

getaction(string str) { return getcmds(query_verb() ); }

getinput(string str)
{
    mixed ret;
    if (ret = getcmds(str)) input_to("getinput");
    return ret;
}

getcmds(string str)
{
    if (find_call_out("suenyo") == -1)
    {
        switch(str)
        {
            case "dormir":
                descansar();
                return 1;
            break;
            case "descansar":
                descansar();
                return 1;
            break;
            case "despertar":
                write("Pero... no estas durmiendo!\n");
                return 1;
            break;
            default:
                return 0;
            break;
        }
    }
    if (find_call_out("suenyo") != -1)
    {
        switch(str)
        {
            case "estado":
                return 0;
            break;
            case "quien":
                return 0;
            break;
            case "canales":
                return 0;
            break;
            case "abandonar":
                despertar();
                return 1;
            break;
            case "exit":
                despertar();
                return 1;
            break;
            case "reiniciar":
                despertar();
                return 1;
            break;
            case "quit":
                despertar();
                return 1;
            break;
            case "despertar":
                despertar();
                return 1;
            break;
            case "dormir":
                write("Ya estas durmiendo.\n");
                return 1;
            break;
            default:
                if (IS_LEARNER(TP)) return 0;
                else
                {
                    if (str[0..0] == "=") return 0;
                    if (str[0..4] == "canal") return 0;
                    if (str[0..4] == "ayuda") return 0;
                    write("No puedes hacer eso mientras duermes.\n");
                    return 1;
                }
        }
    }
}

int descansar()
{
    if (TPHP >= MAXHP)
    {
        write("No tienes sue�o.\n");
        return 1;
    }
    else
    {
        write("Te acercas a la cama y duermes. Escribe 'despertar' para levantarte.\n");
        suenyo();
        return 1;
    }
}

int suenyo()
{
    if ( TPHP >= MAXHP) despertar();
    else
    {
        TP->SetHP(TPHP + 2);
        switch(random(5))
        {
            case 0:
                write("Zzzz... Zzzz... Zzzz...\n");
            break;
            default: break;
        }
        call_out("suenyo",1);
        return 1;
    }
}

int despertar()
{
    remove_call_out("suenyo");
    write("\nTe despiertas despues de tu descanso.\n\n");
    TP->LookAfterMove();
    return 1;
}
