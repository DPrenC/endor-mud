/*
DESCRIPCION  : un portal de teletransporte a Limbo
*/

#include <moving.h>
#include <properties.h>
#include <messages.h>

inherit THING;

#define DESTINO "/d/limbo/comun/habitacion/limbo/stonehenge/monolito"


string* raza;   //raza que puede pasar a traves de el
int i;


string inscrip()
{
    if (!raza ||!sizeof(raza)) return "Este monolito s�lo puede ser usado por los wizars.\n";
    return "Este monolito lo pueden utilizar las siguientes razas: " +
           implode(raza[0..<2], ", ") + (sizeof(raza[0..<2]) ? " y " : "" ) + raza[<1] + ".\n";
}

public string* QueryRaza(){return raza;}
public string *SetRaza(mixed r)
{
    if (!pointerp(r) && !stringp(r)) return raza;
    return raza = (pointerp(r) ? r : ({r}));
}


int entrar_cmd(string s)
{
    int ok = 0;
    string msg_wizard;

    if (query_wiz_level(TP))
    {
        ok=1;
        msg_wizard = "Acercas tu mano hacia el monolito y tocas su fr�a superficie. "
                     "De repente, oyes una profunda voz en tu cabeza: 'Dada tu "
                     "condici�n de wizard, se te permite usar el monolito sin "
                     "importar cual sea tu raza'. La superficie del monolito se licua al "
                     "tacto de tu mano. Pasas a trav�s de �l, y apareces en el "
                     "centro de Stonehenge, en la isla Limbo";
    }
    else if (member(raza || ({}), TP->QueryRace()) <0)
    {
        write("Acercas tu mano hacia el monolito y tocas su fr�a superficie. De repente, "
              "pierdes por un momento la visi�n y un doloroso escalofr�o recorre tu "
              "cuerpo. Oyes una voz grave en el interior de tu cabeza que te dice que este "
              "portal no esta hecho para los de tu raza. Poco a poco recuperas de "
              "nuevo la visi�n.\n");
        tell_room(environment(), ({MSG_SEE, TNAME+" toca la superficie del monolito y ves como su "
                                 "cuerpo sufre una ligera combulsi�n.\n"}), ({TP}));
    }
    else ok=1;

    if (ok)
    {
        TP->move(DESTINO,M_SPECIAL, ({"toca la superficie del monolito, que parece licuarse "
                                      "al contacto, y pasa a trav�s de ella. " + TNAME +
                                      " ha desaparecido",
                                      "aparece de repente surgiendo a trav�s del monolito",
                                      msg_wizard || "Acercas tu mano hacia el monolito y "
                                      "tocas su fr�a superficie. De repente, notas que la "
                                      "dura superficie de la piedra se convierte en "
                                      "una especie de l�quido que te permite entrar en "
                                      "ella. Pasas a trav�s de la piedra como si se "
                                      "tratase de una puerta, sintiendo un extra�o "
                                      "cosquilleo en tu cuerpo. Miras a tu alrededor y te "
                                      "das cuenta de que ahora est�s en un lugar muy "
                                      "distinto al que estabas"}));
    }
    return 1;
}

create()
{
    ::create();
    SetShort("un gran monolito");
    SetLong("Es un gran monolito de basalto negro que, inexplicablemente, levita "
            "a un medio metro sobre el nivel del suelo. Sus caras son planas y tan "
            "lisas como espejos, y sus medidas guardan una matem�tica proporci�n "
            "de ancho:largo:alto de 1:4:9. Te recuerda a uno parecido aunque mucho "
            "m�s grande que viste una vez en la isla Limbo. En la base ves una "
            "inscripci�n. Parece absurdo, pero sientes que se puede 'entrar' en �l...\n");
    SetIds(({"monolito","portal"}));
    SetWeight(100000);
    SetValue(0);
    Set(P_NOGET,1);
    AddSubReadMsg(({"inscripcion","inscripci�n","letrero","mensaje"}),SF(inscrip));
    AddSubDetail(({"inscripcion","inscripci�n","letrero","mensaje"}),
                 "Grabada en la piedra, observas una inscripci�n. Quiz�s podr�as leerla.\n");
}


init()
{
    ::init();
    add_action("entrar_cmd","entrar");
}

