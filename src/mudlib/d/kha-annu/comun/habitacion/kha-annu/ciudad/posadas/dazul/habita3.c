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
    SetIntShort("la habitación lujosa, en la posada del Dragón Azul");
    SetIntLong("Ésta es la habitación lujosa de la posada del Dragón Azul. La cama es enorme, "
        "y está rodeada con un mosquitero que la cubre por completo. El suelo está cubierto "
        "con una alfombra de color azul que está impecable.\n");
    SetIntBright(70);
    SetIndoors(1);
    SetLocate("ciudad de Kha-annu");
    AddDetail(({"alfombra","gran alfombra"}),"La alfombra parece tejida a mano completamente.\n");
    AddDetail(({"cama"}),"La cama es ENORME!\n");
    AddExit("pasillo","pasillo1");
    AddDoor("pasillo","la puerta del pasillo",
        "Es una simple puerta de madera, como las que pudieras encontrar en "
        "cualquier casa.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}), GENDER_FEMALE, "llave3_l",
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
        write("No tienes sueño.\n");
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
        TP->SetHP(TPHP + 3);
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
