/*=============================================================*
 |             << Fortaleza:Simauria [m] Maler >>              |
 *=============================================================*
 |               Creacion............. 03-07-00                |
 |                                                             |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <gremios.h>

inherit NPC;

create ()
{
    ::create();
    if (!clonep()) return;
    seteuid(getuid());
    SetStandard("Cored","humano",([GC_LUCHADOR:62]),GENERO_MASCULINO);
    SetShort("Cored, el legendario bandido");
    SetMaxHP(1300);
    SetHP(1300);
    SetLong("Ante t� tienes a Cored, el bandido legendario. A simple vista parece un humano "
    "normal, vestido de azul. Se rumorea que no puede envejecer, pues el cielo no lo acepta y "
    "el infierno no lo quiere. Al mirar en sus ojos ves la mirada de alguien que lo ha visto todo. "
    "Te mira, y mientras se acerca a ti te pregunta: '�Qu� deseas de mi, mortal?'\n");
    SetIds(({"humano","lord","cored","Cored", "bandido"}));
    AddQuestion(({"tamara", "Tamara"}),
    "Cored te dice: �La pelirroja? es la tendera del castillo, no me molestes.\n");
    AddQuestion(({"hechizo", "hechizos"}),"Cored te dice: Puedo ense�arte el hechizo de "
        "lanza de fuego. Para ello pon aprender\n");
    InitChats(2,"Cored dice: La sabidur�a de los a�os me ha ense�ado muchos hechizos.\n");
    SetAlign(-140);
    AddItem(ARMA("espada2"),REFRESH_REMOVE,SF(wieldme));
    AddItem(ARMA("espada2"),REFRESH_REMOVE,SF(wieldme));
}

init(){
  ::init();
  add_action("aprender_cmd","aprender");
}

aprender_cmd()
{
  if(TP->QueryGuild()!=GC_HECHICEROS){
    write("Cored te dice: A ti no quiero ense�arte.\nCored te mira con desd�n.\n");
    return 1;
  }
  else
  {
    TP->AddPlayerSpell("lanza de fuego", 1, 70, P_INT);
    write("Cored te ense�a el manejo basico del hechizo.\n");
    return 1;
  }
}