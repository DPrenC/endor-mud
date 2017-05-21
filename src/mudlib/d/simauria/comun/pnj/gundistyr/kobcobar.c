/* ***********************************************************                                                        *
*    Archivo: kobcobar.c                                 *
*    Autor: [a] Articman                                 *
*    Modificaci�n: [a] Creaci�n                          *
*                                                        *
********************************************************** */

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <commands.h>

inherit NPC;

string *verbo,*articulo,*nombre;
object ob;
int papeles;
    
create(){
    ::create();
    SetStandard("un kobold cobarde","kobold",7,GENERO_MASCULINO);
    SetAlign(-1000);
    SetAggressive(0);
    SetName("un kobold");
    SetIds(({"kobold","kobold cobarde","cobarde"}));
    SetShort("un kobold cobarde");
    SetSize(1);
    SetLong(W("Es un kobold. Como todos los de su raza es de menor tama�o que "
        "un humano y su piel es de tonos marrones. Est� totalmente sucio debido a "
        "su vida en las cuevas y viste con viejas ropas desgarradas. Tiene unas "
        "prominentes orejas, al igual que su boca. Est� muy encorvado, se�al "
        "t�pica de su raza.\n"));
    InitChats(10,({"Un kobold te mira muy asustado.\n",
        "Un kobold dice: �Porrr favorrr no me pegues! Te darrr� lo que "
        "quierrras.\n",
        "Un kobold dice: P�deme lo que quierrras, que si puedo te lo "
        "darrr� pero porrr favorrr, no me mates. �Te lo rrruego!\n",
        "Un kobold dice: Tengo unos papeles que quiz� te pueden "
        "interrresarrr.\n",
        "Un kobold dice: Dime que quieres y te lo dar�, pero "
        "perd�name la vida.\n"
    }));
    AddQuestion(({"papeles"}),W("Un kobold te dice: �Estos papeles? Los recog� del cuerpo de "
        "unos pobres desgraciados a los que asaltamos por la noche. Si los "
        "quieres dimelo, dime que quieres los papeles.\n"),1);
    verbo=({"quiero","deseo","dame"});
    articulo=({"los","unos"});
    nombre=({"escritos","documentos","papeles"});
    papeles=1;
}

init()
{
    ::init();
    add_action("cmd_decir", "decir");
    add_action("cmd_decir", "'", AA_NOSPACE);
}

public int cmd_decir(string str)
{
    int i,j,k;
    string frase;
    for (i=0;i<sizeof(verbo);i++)
    {
        for (j=0;j<sizeof(articulo);j++)
        {
            for (k=0;k<sizeof(nombre);k++)
            {
                frase=implode(({verbo[i],articulo[j],nombre[k]})," ");
                if (str==frase)
                {
                    if (papeles==1)
                    {
                        tell_room(environment(), "El kobold dice: �Quierrrres los papeles? Son todo tuyos, perrro "
                            "no me mates por favor.\n");
                        write("El kobold te da un mont�n de papeles.\n");
                        say("El kobold le da un mont�n de papeles a " + CAP(TNAME) + ".\n", TP);
                        ob=clone_object(GOBJETO("otro/gundistyr/manuscrito"));
                        if (ob->move(TP) != ME_OK)
                        {
                            write("Cuando vas a coger los papeles, estos se te escuren y caen al suelo.\n");
                            say("Cuando " + CAP(TNAME) + " va a coger los papeles, se le escurren y caen al suelo.\n", TP);
                            ob->move(environment());
                        }
                        papeles=0;
                        return 1;
                    }
                    else
                    {
                        write("Un kobold te dice: '�Quierrrrres los papeles? Lo siento, pero ya se "
                        "llevarrrrron todos los que ten�a. Por favorrrrr disculpa mi "
                        "errrrorrrrr.'\n");
                        say("Un kobold le dice a " + CAP(TNAME) + ": '�Quierrrrres los papeles? Lo siento, pero ya se "
                        "llevarrrrron todos los que ten�a. Por favorrrrr disculpa mi "
                        "errrrorrrrr.'\n");
                    }
                    break;
                }
            }
        }
    }
    return 1;
}

reset(){
    ::reset();
    papeles=1;
}
