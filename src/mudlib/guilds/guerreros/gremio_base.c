/**
 * Gremio de Guerreros
 */

#include "path.h"
#include "wguild.h"
#include <rooms.h>
#include <properties.h>
#include <wizlevels.h>
#include <skills.h>
#include <guild.h>
#include <moving.h>

//------------------------------------------------------------------------------

inherit GUILD;

//------------------------------------------------------------------------------

private nosave mapping pLevelPresays = ([]); // pLevelPresays = ([lvl:Presay])

//------------------------------------------------------------------------------

public string GuildLevel2Presay(int lvl)
// evaluate the presay
{
  string rc;
  rc = "";
  if (!pLevelPresays||lvl<1) return rc;
  while(!pLevelPresays[lvl] && lvl--);
  return pLevelPresays[lvl]||rc;
}


public mapping SetLevelPresays(mapping t)
// set all presays: ([lvl:presay])
{
  if (!t) return pLevelPresays;
  return pLevelPresays = t;
}


public mapping QueryLevelPresays()
{
  return pLevelPresays;
}


public mapping AddLevelPresay(int lvl,string presay)
// Add a presay for a certain level
{
  if (lvl<0) return pLevelPresays;
  if (!pLevelPresays) pLevelPresays = m_allocate(0,1);
  pLevelPresays[lvl] = presay;
  return pLevelPresays;
}

private status compare_len(string s1,string s2)
{
  return sizeof(s1)>sizeof(s2);
}

public void InformAdvance(object pl, string what)
{
  int i,lvl;
  string presay,*oldpresays,orgpresay;
  if (!pl) return;
  /*
    Para evitar que Mi-Amigo-Wizard(tm) juegue con los SP, se le bajan
    cada vez que se suba la Inteligencia.
    En un futuro, cuando se implemente el "nivel 42", un guerrero podrá
    subir sus SP gradualmente, hasta llegar al máximo que le permita su
    inteligencia, a partir de ese nivel.
  */

  if (what==P_INT)
    {
     pl->SetMaxSP(50);
     pl->SetSP(50);
    }

  if (what!="level") return;

  // Al avanzar un nivel se mira si vas a subir de rango también...

  lvl=pl->QueryGuildLevel();
  presay = GuildLevel2Presay(lvl);
  orgpresay = implode(explode(pl->QueryPresay()||""," ")-({""})," ");
  oldpresays = sort_array(m_values(QueryLevelPresays()),SF(compare_len));
  for(i=sizeof(oldpresays);i--&&sizeof(orgpresay);)
    orgpresay = implode(explode(orgpresay,oldpresays[i]),"");
  if (sizeof(orgpresay))
    orgpresay = presay+" "+orgpresay+" ";
  else
    orgpresay = presay+" ";
  if (orgpresay!=pl->QueryPresay())
    pl->SetPresay(orgpresay);
  write("Obtienes el rango de "+presay+".\n");

// Para finalizar, inicializo los "nuevos" valores de los skills...
//TO->AdvanceSkills();

}

int cmd_join(string str)
{
  int iv,pos,unirse;
  string presay,*presays,newpresay;
  object pl;
  pl = TP;

  /*
    Los guerreros no tienen magia. Ahora bien, quitársela por completo
    sería ridículo. En lugar de eso, se reducen sus SP al mínimo posible: 50.
    Adicionalmente, como anti-cheat, se le vuelven a poner a 50 cada vez que
    avance la inteligencia.
  */
  if (unirse=::cmd_join(str))
  {
   pl->SetMaxSP(50);
   pl->SetSP(50);
 // Al unirse, también se le pone el rango correspondiente
   InformAdvance(pl, "level");
  }
  return unirse;
}

public void InformRemove(string name)
{
  int iv;
  object pl;
  string *presays;
  if (!pl=find_object(lower_case(name))) return;
  presays = explode(pl->QueryPresay()," ")-({""});
  presays-=m_values(QueryLevelPresays());

  if (!sizeof(presays)) pl->SetPresay("", 1); // el 1 es para q no lo anuncie
  else pl->SetPresay(implode(presays," ")+" ", 1); // el 1 es para q no lo anuncie

// Se le devuelven los SP normales al renunciar
  pl->SetMaxSP(0);
  pl->SetTitle("el antiguo guerrero");
}

public void create_ob()
{
    ::create_ob();
  SetIndoors(1);
  SetIntBright(45);
  SetGuildname("Gremio de Guerreros");
  SetGuildclass(GC_GUERREROS);
  SetGuildMaster("Drix");
/*
  AddGuildquest(Q_GHOUL,9,"nemesis",
    "Liberar la aldea de Nandor",
    "Cosas terribles están ocurriendo en el cementerio de Nandor. Un monstruo\n"
    "está profanando las sepulturas. Mata a la bestia y trae la cabeza de\n"
    "vuelta para que el guildmaster la vea. Serás recompensado.\n");
  AddGuildquest(Q_ACERO,30,"nemesis",
    "Averiguar el Secreto del Acero.",
    "Sólo un guerrero completamente formado debe aceptar esta peligrosa\n"
    "misión, pues de lo contrario morirá en el intento. En las montañas,\n"
    "más allá del castillo de Nandor, encontrarás la tumba de Gnudur. En\n"
    "ella hallarás el Secreto. ¡Pero cuidado! Ninguna de las armas que\n"
    "lleves te servirá allí.\n");
*/

  SetCreators(({"Nemesis"}));
  SetGuildobject(HELM);

  ForbidAllMagic("No puedes reunir suficiente energía para lanzar tu hechizo.\n");

  AddLevelPresay(  1, "núbil en las artes del combate");
  AddLevelPresay(  5, "joven guerrero");
  AddLevelPresay( 10, "Soldado");
  AddLevelPresay( 15, "Soldado de 1ª clase");
  AddLevelPresay( 20, "Soldado de primera línea");
  AddLevelPresay( 25, "Soldado Veterano");
  AddLevelPresay( 30, "Guerrero de Élite");
  AddLevelPresay( 35, "Experimentado combatiente");
  AddLevelPresay( 40, "Sargento Primero");
  AddLevelPresay( 45, "Brigada");
  AddLevelPresay( 50, "Subteniente");
  AddLevelPresay( 55, "Suboficial Mayor");
  AddLevelPresay( 60, "Alférez");
  AddLevelPresay( 65, "Teniente");
  AddLevelPresay( 70, "Capitán");
  AddLevelPresay( 75, "Comandante");
  AddLevelPresay( 80, "Teniente Coronel");
  AddLevelPresay( 85, "Coronel");
  AddLevelPresay( 90, "General de Brigada");
  AddLevelPresay( 95, "General de División");
  AddLevelPresay(100, "Teniente General");
  AddLevelPresay(150, "General de Ejército");
  AddLevelPresay(200, "Capitán General");

  AddRoomCmd("unirse","cmd_join");

}
