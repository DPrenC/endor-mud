/* Habitacion de la Muerte
**
** Make death such boring that players learn to avoid it.
** The player now returns to the place where it died.
**
*/

#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <wizlevels.h>
#include <stdrooms.h>
#include <magia.h>
#include <colours.h>
inherit ROOM;

#define QG           QueryGender()
#define SPEAK        "\nLa voz de Eru resuena en tu mente:\n"
#define G(maletxt,femaletxt) ((who->QueryGender()==GENDER_MALE) ? maletxt : femaletxt)

private static mapping players = ([]);

_query_player() { return players; }

void create() {
  ::create();
  SetIntShort("algún lugar de las inconmensurables estancias de Ea");
  SetIntLong(
"Tu espíritu intangible vaga por un lugar fuera del tiempo, muy lejos de Arda.\n"
"Millones de estrellas lejanas resplandecen fríamente y eres consciente de la vastedad "
"de Ea y lo insignificante que resulta Arda en comparación. La paz que se respira está "
"más allá de toda comparación y el tiempo parece detenido mientras los cuerpos celestes "
"giran y envejecen ante tu incorpórea visión. Percibes que este lugar es la antesala "
"que precede al lugar donde moran Eru y los Ainur, fuera del Universo material. Queda por "
"saber si traspasarás ese umbral o retornarás al mundo de los mortales.\n");
  Set(P_TPORT, TPORT_NO);
  SetMagicProtection(([ST_ALL:"No tienes poder alguno en este lugar.\n"]));
  SetIntBright(30);
  SetIndoors(1);
}

string QueryIntLong(mixed arg) {
  int i;
  string rc;

  rc = ::QueryIntLong(arg);

  if (!arg && (players[TP] >= 3 && players[TP] < 15))
    return rc + "Eru Ilúvatar\n";
  return rc;
}

void init() {
  ::init();
        if (!IS_LEARNER(TP) && !TP->Query(P_NOWIZ)) {
      //write(SPEAK"'QUE HACES AQUI? LOS MORTALES YA SUFREN LO SUFICIENTE, NO CREES?'\n");
      TP->move(TP->QueryHome(), M_TELEPORT);
    }
    if (TP->QueryGhost()) {
      add_action("filter", "", 1);
      players[TP] = 0;
      set_heart_beat(1);
    }
}

int filter(string str) {
  switch (query_verb()) {
  default:
    if(IS_LEARNER(TP)) return 0;
    write(SPEAK"No puedes hacer eso en este lugar.\n");
    return 1;
  case "quit": case "desconectar": case "exit":
    write(SPEAK"Tu espíritu se disuelve y disgrega temporalmente.... la decisión de Eru "
    "ha sido postergada.\n");
  case "reiniciar":
    write(SPEAK"Tu espíritu se disuelve y disgrega temporalmente.... la decisión de Eru "
    "ha sido postergada.\n");

  case "exa":
  case "m":
  case "mirar":
  case "coger":
  case "mandos":
  break;
  }
  return 0;
}

void death_messages(object who, int waiting) {
  object dmark;
  mixed place;
  int notplace, rc;

  switch (++waiting) {

  case 2:
    if (who->QueryLDeathDisconnected())
    {
        tell_object(who, "Has caído muert" +
                    who->QueryGenderEndString() + " desconectad" +
                    who->QueryGenderEndString() + ", el " + STR->etime(who->QueryLDeathTime()) +
                    ".\n"
                    " " + CAP(who->QueryLDeathName()) + " fue quien terminó con tu vida.\n");
    }
    tell_object(who,
"\nArda desaparece y te ves transportad" + who->QueryGenderEndString() +" a un lugar "
"ignoto, más allá del alcance de cualquier mortal o Vala, situado en los confines de Ea.\n"
  );
  break;
  case 3:
  tell_object(who,
"\nTu alma inmortal vaga por los eternamente silenciosos límites del universo material...\n");
  break;
  case 7:
  tell_object(who,TC_RED+SPEAK+
" ¡óyeme, mortal!\n"
" tu espíritu  ha sido desprovisto de su envoltura carnal y ha dejado atrás el "
" mundo de los vivos. Aún así, el ínfimo papel que te toca desempeñar en la "
" Gran Canción aún no ha terminado. Así pues, y ya que son los Valar quienes gobiernan "
" Arda y todo lo que en ella hay en mi nombre, comparecerás ante Mandos en las "
" Estancias de Espera y por él serás juzgad" + who->QueryGenderEndString() +". Si él "
" te encuentra dign" + who->QueryGenderEndString() +" se te permitirá volver por un "
"corto lapso de tiempo a completar tu obra.\n"
" Ve con mi bendición, hij" + who->QueryGenderEndString() +" mí" + who->QueryGenderEndString() +"'\n"
  +TC_NORMAL);
  break;
  case 15..16:
  tell_object(who,
"\n Poco a poco la oscuridad estrellada se aclara revelando un cielo cubierto de una blanca "
  "capa de nubes que se abren revelando una lejana tierra cuyo resplandeciente verdor no "
  "se puede comparar en belleza a nada que hayas visto......\n\n"
  "Desciendes a enorme velocidad hacia el hermoso país que se va desplegando ante tu "
  "maravillada mirada, cuajado de praderas verdes, blancas ciudades y grandes bosques, "
  "todo ello rodeado por una gigantesca cordillera montañosa de formidables picos "
  "dentados...\n\n");

    while (dmark = present("death_mark", who)) {
     // place = dmark->query_place();
      dmark->remove();
      destruct(dmark);
    }
/*
   notplace = 0;

   if (!place || !(place->Query(P_TPORT)&TPORT_IN))
    {
      notplace = 1;
      place = who->QueryHome() || MANDOS;
    }
    Set(P_TPORT, TPORT_OUT);
    if (catch(rc = who->move(place, M_GO)) || rc != ME_OK)
    {
      notplace = 1;
      who->move(MANDOS, M_GO);
    }
    if (!notplace)
      tell_object(who,"El tacto del suelo te resulta familiar ... muy familiar...\n\n");
    else
      tell_object(who,"El tacto del suelo NO te resulta nada familiar...\n\n");
    Set(P_TPORT, TPORT_NO);
*/
    tell_room(MANDOS,"El fantasma de "+who->QueryName()+" aparece ante tus ojos.\n");

    tell_object(who,"Al Este distingues unos majestuosos palacios desprovistos de "
    "ventanas que se hacen cada vez más grandes hasta ocupar todo el horizonte ...\n\n"
    "Te ves irremisiblemente atraíd" + who->QueryGenderEndString() +" hacia una "
    "gigantesca puerta arqueada cuya pétrea superficie atraviesas como si se tratara de "
    "una cortina de agua.\n"
    "Penetras en las Estancias de Mandos. Tras de ti solo queda un muro liso e "
    "impenetrable que ni aún los espíritus incorpóreos de los Ainur podrían atravesar.\n\n");
    who->move(MANDOS,M_GO);
    m_delete(players, who);
  }
}
void heart_beat() {
  int s;

  m_delete(players, 0);
  walk_mapping(players, SF(death_messages));
  m_delete(players, 0);

  if (!sizeof(players))
    set_heart_beat(0);
}
