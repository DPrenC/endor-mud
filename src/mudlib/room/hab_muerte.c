/* Habitacion de la Muerte
**
** Make death such boring that players learn to avoid it.
** The player now returns to the place where it died.
**
**   26-Aug-92 [m] Adapted for native.
**   25-Nov-93 [p] combine_strings
**   18-May-94 [h] rewrite of functions
**   28-May-94 [l] Small bugfix. Also changed text to give "SHE" for females.
**                 Reformatted some lines to max 80 chars.
**   07-Seb-94 [m] Wizards are expelled from the room.
**   20-Jan-95 [p] Use preprocessor string concatenation instead of line
**		   continuations. Make player mapping private. Use closure.
**   09-Dec-95 [m] Wizards with P_NOWIZ set may die normally.
**   01-Jan-96 [m] Some details added.
**   20-Ene-98 [I] Traduccion para Simauria.
**   11-Nov-98 [n] Revision de la traduccion... 'Cambiar tu mente'????
**                 Pero tio! Que ingles te ensenyaron a ti?
**
**  [m] Mateese
**  [p] Pepel
**  [h] Hyp
**  [l] Loco
**  [I] Izet@Simauria
**  [n] Nemesis@Simauria
 */

#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <wizlevels.h>
#include <stdrooms.h>
#include <magia.h>
inherit "/std/room";

#define WRITE(x)     tell_object(who, "\n" x)
#define SPEAK(x)     tell_object(who, "\nDeath says: " x)
#define G(maletxt,femaletxt) ((who->QueryGender()==GENDER_MALE) ? maletxt : femaletxt)

private static mapping players = ([]);

_query_player() { return players; }

Genero(string str)  {
   if ( (TP->QueryGender() == 0 ) ) return "o";
   if ( (TP->QueryGender() == 1 ) ) return "a";
   if ( (TP->QueryGender() !=0) && (TP->QueryGender() != 1) ) return "o";
}

GeneroM(string str)  {
   if ( (TP->QueryGender() == 0 ) ) return "O";
   if ( (TP->QueryGender() == 1 ) ) return "A";
   if ( (TP->QueryGender() !=0) && (TP->QueryGender() != 1) ) return "O";
}

Bueno(string str)  {
   if ( (TP->QueryGender() == 0 ) ) return "Buen";
   if ( (TP->QueryGender() == 1 ) ) return "Buena";
   if ( (TP->QueryGender() !=0) && (TP->QueryGender() != 1) ) return "Buen";
}

Cab(string str)  {
   if ( (TP->QueryGender() == 0 ) ) return "Sr.";
   if ( (TP->QueryGender() == 1 ) ) return "Sra.";
   if ( (TP->QueryGender() !=0) && (TP->QueryGender() != 1) ) return "Sr.";
}

void create() {
  ::create();
  SetIntShort("La habitacion de la Muerte");
  SetIntLong(
"Estas en una habitacion oscura iluminada con una luz oscura. Es una extranya,\n"
"aun siendo negra la estancia esta iluminada. Entre la extranya luz puedes ver\n"
"un pupitre, colocado en el centro de la habitacion, sobre el que hay algunos\n"
"libros y diagramas. Las paredes estan cubiertas con estanterias llenas con\n"
"tomos oscuros hechos de piel leather y adornados con extranyas runas.\n\n");

  Set(P_TPORT, TPORT_NO);
  SetMagicProtection(([ST_ALL:"No puedes lanzar hechizos aqui.\n"]));
  SetIndoors(1);
  SetIntBright(20);
  AddItem("/room/death", REFRESH_REMOVE);

  AddDetail("pupitre",
"El pupitre esta hecho de madera de roble. Es majestuoso.\n"
           );
  AddDetail("libros",
"Los libros que hay encima del pupitre tienen las mismas runas extranyas que\n"
"los tomos de las estanterias.\n"
           );
  AddDetail("diagramas",
"Los diagramas cubren la mayor parte de la superficie del pupitre. Estan\n"
"cubiertos de lineas circulares y paralelas. No les encuentras ningun sentido.\n"
           );
  AddDetail("tomos",
"Son libros muy antiguos, hechos de la piel mas lujosa. La muerte debe tener\n"
"mucho dinero para disponer de estos lujos. Las cubiertas estan adornadas con\n"
"extranyas runas.\n"
           );
  AddDetail("runas",
"Las runas parecen antiguas y poderosas -- no logras identificarlas.\n"
           );
  AddDetail(({"estanterias", "estanteria", "pared","paredes" }),
"Las estanterias cubren la mayor parte del espacio disponible en las paredes\n"
"y estan llenas de antiguos tomos.\n"
           );
}

string QueryIntLong(mixed arg) {
  int i;
  string rc;

  rc = ::QueryIntLong(arg);
  if (!arg && (players[TP] >= 40 && players[TP] < 62))
    return rc + "Lars el Convincente.\n";
  return rc;
}

void init() {
  object death;

  ::init();
  death = present("tunica", TO);
  if (TP != death) {
    if (IS_LEARNER(TP) && !TP->Query(P_NOWIZ)) {
      write(
"QUE HACES AQUI? LOS MORTALES YA SUFREN LO SUFICIENTE, NO CREES?\n"
           );
      TP->move(TP->QueryHome(), M_TELEPORT);
    } else if (TP->QueryGhost()) {
      add_action("_nor", "", 1);
      players[TP] = 0;
      set_heart_beat(1);
    } else {
      write(
"QUE HACES AQUI? TU HORA AUN NO HA LLEGADO. FUERA!!!\n");
      TP->move(TP->QueryHome(), M_TELEPORT);
    }
  }
}

int _nor(string str) {
  switch (query_verb()) {
  default:
    write("ESO NO ES POSIBLE EN TU ESTADO INMATERIAL!\n");
    return 1;
  case "quit":
    write("PODRAS IRTE AHORA, PERO TE COGERE LA PROXIMA VEZ!\n");
    /* FALL THROUGH */
  case "exa":
  case "m":
  case "mirar":
  case "coger":
    break;
  }
  return 0;
}

void death_messages(object who, int waiting) {
  object dmark;
  mixed place;
  int notplace, rc;

  switch (++waiting) {
  case 5:
    SPEAK("ES LA HORA.\n");
    WRITE(
"La muerte levanta su brazo derecho y hace un movimiento amenazante.\n"
"Estas del todo segur"+Genero()+" de que si estuvieras viv"+Genero()+
" moririas de miedo en el acto\n"
"Lo mas extranyo es que no sientes nada parecido, por ahora.\n");
    break;
  case 10:
    SPEAK("NO TEMAS Y NO TE DOLERA.\n");
    WRITE(
"La muerte parece sonreir un poco, aunque seria dificil de asegurar. Quiza\n"
"podria ser la expresion normal de su cara descarnada...\n");
    break;
  case 15:
    SPEAK("SIN TEMOR NO SENTIRAS NADA, NADA DE NADA.\n");
    WRITE(
"Bien, todo parece estar listo. Empiezas a sentir un extranyo aburrimiento.\n"
"Desearias que todo esto acabase pronto.\n");
    break;
  case 20:
    SPEAK("ACERCATE, DEBO EXAMINAR TU ALMA.\n");
    WRITE(
"La Muerte te obliga a acercarte despacio y pone su mano huesuda sobre tu\n"
"espalda. Sientes un extranyo quejido en tu interior como si tu alma se\n"
"hubiera desprendido de tu cuerpo... Repentinamente la Muerte recoge toda tu\n"
"esencia corporal con grandes gestos circulares de sus manos esqueleticas y la\n"
"pone en el interior de una pequenya esfera de cristal que inserta en una de\n"
"sus cavidades oculares!\n"
"Ves una extranya luz azul que proviene de la esfera y que penetra en tu\n"
"interior.\n");
    break;
  case 30:
    switch (who->Query(P_ALIGN)) {
    case -10000..-1000:
      SPEAK(
"TUS PECADOS SON TANTOS COMO LOS GRANOS DE ARENA DEL DESIERTO.\n"
"POSIBLEMENTE SEAS MAS MONSTRUOS"+GeneroM()+" QUE YO! JAAA JA JA!\n");
      break;
    case -999..-500:
      SPEAK(
"OH, QUE DESPIADADO INSECTO TENEMOS AQUI. ROBANDO DULCES A LOS NINYOS Y\n"
"GOLPEANDO A INOCENTES SIN DUDARLO. BUENO, AHORA IREMOS A BAILAR SOBRE\n"
"TU TUMBA. JAAA JA JA!\n");
      break;
      case -499..-200:
      SPEAK(
"TE HAN DICHO ALGUNA VEZ QUE ERES REPELENTE Y ATONTAD"+GeneroM()+"? NO?\n"
"NO TE PREOCUPES ENTONCES. TE LO DIRAN, DURANTE TODA LA ETERNIDAD!\n"
"JAAA JA JA!\n");
      break;
    case -199..-1:
      SPEAK(
"ARREPIENTE MORTAL! ROBAR Y ASESINAR, ES ESO TODO EN LO QUE PUEDES PENSAR?\n"
"BIEN, TE DARE TIEMPO PARA ARREPENTIRTE DE TUS ACCIONES... PARA SIEMPRE!\n"
"JAAA JA JA!\n");
      break;
    case 0:
      SPEAK(
"QUE SALTA-MUROS TENEMOS AQUI! TU MENTE NUNCA HA HECHO NADA MEJOR EN TODA TU\n"
"VIDA, NO? BUENO, NO TE PREOCUPES, LO HARAS A PARTIR DE AHORA! JAAA JA JA!\n");
      break;
    case 1..199:
      SPEAK(
"OH, QUE ALMA MAS PURA TENEMOS AQUI. SIEMPRE CAMINANDO POR EL BUEN CAMINO, NO?\n"
"BUENO, AHORA NUNCA SABRAS COMO ERA EL OTRO CAMINO! JAAA JA JA!\n");
      break;
    case 200..499:
      SPEAK(
"NUNCA HAS DICHO UNA PALABROTA EN TU VIDA, NO? BUENO, ES DEMASIADO TARDE PARA\n"
"CAMBIAR DE IDEA AHORA. JAAA JA JA! NO, "+Cab()+" "+Bueno()+"-TI"+GeneroM()+
", ERES LO QUE ERAS!\n"
"JAAA JA JA!\n");
      break;
    case 500..999:
      SPEAK(
"HE OIDO ALGO SOBRE LOS ARCANGELES EN EL CIELO. QUIZA PODRIAN CONSEGUIRTE UN\n"
"TRABAJO ALLI... ESPERO QUE SEPAS TOCAR EL ARPA, O LE DARAN EL TRABAJO A "
"OTR"+GeneroM()+"!\n"
"JAAA JA JA!\n");
      break;
    case 1000..10000:
      SPEAK(
"OH! QUE PASA? INTENTAS QUITARLE EL TRABAJO A LOS DIOSES? JAAA JA JA! DEJA\n"
"QUE TE DIGA UNA COSA ANTES DE QUE FIRMES ALGUN PAPEL. LOS DIOSES TIENEN MALOS\n"
"HORARIOS Y NO TIENEN VACACIONES. CREEME, NO TE VA GUSTAR!\n");
      break;
    }
    break;
  case 35:
    SPEAK(
"BUENO, CREO QUE HE HECHO TODO LO POSIBLE POR TU ALMA ESTA VEZ, NOS VEREMOS\n"
"EN EL DIA DEL JUICIO FINAL! JA JA JA JA JA JA JA JA JA JA!\n");
    WRITE(
"La Muerte saca la esfera de su ojo y se lecanta. De repente se da la vuelta y\n"
"se marcha fuera de la habitacion a traves de la pared mas cercana, contigo\n"
"asid"+Genero()+" de su mano! Camina rapidamente por un corredor oscuro y\n"
"serpenteante y baja por una escalera de caracol a la habitacion mas profunda\n"
"del lugar. Finalmente, la Muerte para en frente de una puerta en la que\n"
"leer la palabra 'ETERNIDAD' en letras negras.\n"
"En la puerta puedes ver una pequenya cerradura que la Muerte abre con un\n"
"movimiento de su mano. Al abrirse la puerta escuchas los murmullos de los\n"
"millones de almas que aqui se encuentran. Lentamente la muerte te empuja\n"
"hacia el interior de la habitacion.\n");
    break;
  case 40:
    WRITE("Lars llega a traves de un portal dimensional en el espacio.\n");
    break;
  case 45:
    WRITE("Lars te sonrie.\n");
    break;
  case 47:
    WRITE("Lars le susurra algo a la Muerte.\n");
    break;
  case 54:
    SPEAK("QUE? ESA NO ES LA CUESTION! Y TU LO SABES!\n");
    break;
  case 56:
    WRITE("Lars suspira profundamente.\n");
    break;
  case 58:
    WRITE("Lars le susurra algo a la Muerte.\n");
    break;
  case 60:
    SPEAK(
"REENCARNACION? PARA ESTA ALMA??\n"
+G("EL","ELLA")+" NO LO MERECE! POR FAVOR, SE MENOS SENSIBLE LARS!\n");
    break;
  case 62:
    WRITE("Lars se aleja hacia una esquina.\n");
    break;
  case 64:
    WRITE("Lars se marcha a traves de un portal dimensional en el espacio.\n");
    break;
  case 66:
    WRITE(
"La Muerte te mira de una forma que parece disgusto aunque no es facil de\n"
"decir. Su cara no es la mejor para poder mostrar alguna expresion, pero te\n"
"sientes convencido de que esta disgustada.\n");
    break;
  case 70..1000:
    SPEAK(
"OH, ESTA BIEN! PUEDO ESPERAR. DE TODOS MODOS ALGUN DIA SERAS\n"
 "MI"+GeneroM()+"!\n");
    WRITE(
"De repente la Muerte te lanza al aire, tienes una extranya sensacion, como\n"
"si pasaras a traves de las paredes de una edificacion. En el cielo abierto\n"
"ves caballos voladores que te miran sorprendidos y finalmente tu velocidad\n"
"disminuye y te paras.\n");
    while (dmark = present("death_mark", who)) {
      place = dmark->query_place();
      destruct(dmark);
    }
    notplace = 0;
    if (!place || !(place->Query(P_TPORT) & TPORT_IN))
    {
      notplace = 1;
      place = who->QueryHome() || CHURCH;
    }
    Set(P_TPORT, TPORT_OUT);
    if (catch(rc = who->move(place, M_SILENT)) || rc != ME_OK)
    {
      notplace = 1;
      who->move(CHURCH, M_SILENT);
    }
    if (!notplace)
      WRITE("El tacto del suelo te resulta familiar ... muy familiar...\n\n");
    else
      WRITE("El tacto del suelo NO te resulta familiar...\n\n");
    Set(P_TPORT, TPORT_NO);
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
