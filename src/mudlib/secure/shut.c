/**
 * /secure/shut.c
 */

#include "/secure/config.h"
#include "/secure/wizlevels.h"

/*------------------------------------------------------------------------*/

string	aleat_mensajes;	// Mensajes aleatorios de Apocalipsis
string  progr_mensajes; // Mensajes progresivos de Apocalipsis
int	shut_ok;        		// Hay shutdown?

int     ok_alt_msgs;    // Son correctos los mensajes aleatorios?
string  razon;
int     tiempo_rest;

/*------------------------------------------------------------------------*/

create() {
  seteuid(getuid(TO));

  if (   (-1 != member(object_name(TO), '#'))
      || object_name(TO)+".c" != __FILE__
     ) {
    log_file ("SIM_SHUT",
 ctime(time())+": shut: Intento ilegal!\n"
 "  este:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
 "  anterior:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<ninguno>")+"\n"
 "  jugador:     "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<ninguno>")+"\n"
 "  interactivo: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<ninguno>")+"\n\n"
             );
    destruct (TO);
    return;
  }

  razon = "Desconocida.";

aleat_mensajes = ({
	"Por todas partes el mundo se desmorona.\n Los Hombres se lamentan, maldicen y perecen.\n",
"Las huestes de Morgoth avanzan devastando el Mundo!\n",
"Las gloriosas Huestes de los Valar resplandecen en la sempiterna oscuridad que ya n jamás desaparecerá.\n Manwe, el Rey Supremo, ha descendido por fin de Taniquetil y se une al combate.\nAcabas de caer al suelo.\n",
"Un trueno y un rayo azotan los cielos!\n",
"Los Elfos han retornado de Valinor y todos ellos, Vanyar, Noldor \n"
"Teleri, Sindar y Avari arremeten contra las impenetrables filas de malignas criaturas de Morgoth.\n"
});

  progr_mensajes = ({
" es portador de malas nuevas!\n"
"Tal como se dijo, Melkor Morgoth, el Enemigo Oscuro de edades pasadas, ha regresado a Arda\n"
" al frente de sus huestes!\n"
"Preparaos, Hijos de Ilúvatar, pues la Dagor Dagorath y el Fin de Arda se avecinan!\n",
"Una insondable negrura procedente del Norte se extiende sobre Arda mientras la voz \n"
"del vala caído edades atrás desciende desde el negro firmamento hasta las más \n"
"abismales profundidades de la Tierra y el océano, entonando un salvaje grito de victoria.\n"
"La más negra desesperanza invade tu corazón.\n",
"Un postrer fulgor blanquecino quiebra por última vez la Oscuridad anunciando \n"
"la muerte de Anor, el Sol que alumbrara el despertar de los Primeros Hombres.\n"
"Un hálito de inconmensurable gelidez se abate sobre el mundo mientras fuegos rojos \n"
"danzan alocadamente sobre las altas cumbres.\n"
"Los océanos hierven con un monstruoso siseo y cubren de una húmeda mortaja las \n"
"tierras mortales.\n",
"En el Antiguo Occidente los Valar responden.\n"
"Un trueno inmenso y un rayo azulado invaden todo el cielo de Arda.\n",
"Balrogs de fuego irrumpen desde grutas olvidadas en las profundidades del mundo, \n"
"y los Uruloki, los Dragones de Fuego despiertan.\n",
"Los Ejércitos de los Valar marchan contra las Huestes de Morgoth y en la \n"
"confrontación las montañas explotan en nubes de magma y rocas fundidas y los ríos \n"
"burbujean coléricos en busca de sus antiguos cauces.\n",
"Antiguos héroes del pasado marchan a la Batalla Final.\n"
"La tierra estalla en llamas rojas y el aire se hace irrespirable.\n"
"Un viento ardiente se levanta bajo las alas de los Dragones, y barre la faz de Arda.\n"
"Los últimos seres ivientes perecen.\n"
"Túrin Turambar se enfrenta con Melkor, y de un postrer mandoble lo hace caer.\n"
"El destino de Arda se ha cumplido.\n",
(random(100) >= 75
   ? "Los árboles gimen mientras el fuego hace estallar sus troncos, y las plantas y \n"
   "flores y hierbas \n"
   "que alguna vez cubrieran la Tierra florecen una última vez, estallando en llamas \n"
   "salvajes.\n"
   : "Oyes como las voces de miles de almas se pierden en la lejania...\n"),
                       });

  shut_ok = 0;
  enable_commands();
  set_heart_beat(1);
}

/*-------------------------------------------------------------------------*/

clean_up(ref) { return 0; }
remove(int test)
{
  if (test < 0) /* Proteccion contra la limpieza de Simauria */
    return;
  destruct(TO);
}

/*-------------------------------------------------------------------------*/

slow_shut (minutos) {
  int i, delay, segundos;
  string quien;

  if (minutos <= 10) return shut(minutos);

  i = remove_call_out("cont_shutting");
  if (i > 0) {
    write("Ya existe un proceso de shutdown, " + i + " segundos.\n");
    return;
  }
  if (!intp(minutos)) {
    write("Argumento no valido.\n");
    return;
  }
  if (minutos <= 0) {
    write("Debes dar el tiempo.\n");
    return;
  }

  Armagedon()->Shut();

  if (TP) quien = capitalize(TP->QueryRealName());
  else if (object_name(PO) == MASTER) quien = "El Espiritu de Simauria";
  else quien = 0;

  catch(log_file ("SIM_SHUT", ctime(time())+" "
                        +(quien || (object_name(PO)
                                  +" ["+getuid(PO)+"]"
                                 )
                         )
                        +" trae las nuevas de que el Fin de Arda se producirá ("+minutos+" minutos)\n"
                         "=========> Razon: "+razon+".\n"
           ));

  shut_ok = 1;
  ok_alt_msgs = 0;
  segundos = minutos * 60;
  tiempo_rest = segundos;
  delay = segundos * 3 / 4 - 10;
  call_out("cont_shutting", segundos - delay, delay);
  return 1;
}

static void shout (string msg)
{
  filter(users(), SF(tell_object), msg);
}

shut(minutos) {
  int i;
  string quien;

  i = remove_call_out("cont_shutting");
  if (i > 0) {
    write("Ya existe un proceso de shutdown, " + i + " segundos.\n");
    return;
  }

  if (!intp(minutos)) {
    write("Argumento no valido.\n");
    return;
  }

  if (minutos <= 0) {
    write("Debes dar el tiempo.\n");
    return;
  }

  if (TP) quien = capitalize(TP->QueryName());
  else if (object_name(PO) == MASTER)
    quien = "El Espiritu de Simauria";
  else quien = 0;

  shout((quien || "Alguien")+progr_mensajes[0]+"");
  catch(log_file ("SIM_SHUT", ctime(time())+" "
                        +(quien || (object_name(PO)
                                  +" ["+getuid(PO)+"]"
                                 )
                         )
                        +" ha provocado el Apocalipsis ("+minutos+" minutos)\n"
                         "==========> Razon: "+razon+".\n"
           ));
  shut_ok = 1;
  ok_alt_msgs = (minutos <= 5);
  tiempo_rest = minutos * 60;
  call_out("cont_shutting", 0, minutos * 60);
  return(1);
}

/*-------------------------------------------------------------------------*/
static cont_shutting(segundos) {
  string delay;
  int    nuevo_delay;

  if (segundos <= 0) {
    do_shout("El Fin de Arda se avecina!!!\n");
    do_shout("Arda será creada de nuevo por Eru  en varios minutos.\n");
    catch(log_file ("SIM_SHUT", ctime(time())+" Ilúvatar ha desconectado Endor.\n"));
    shutdown();
    call_out("do_shout", 5, "Me HAN detenido... pero regresare!\n");
    remove();
    return;
  }

  nuevo_delay = segundos * 3 / 4 - 10;
  tiempo_rest = segundos;
  call_out("cont_shutting", segundos - nuevo_delay, nuevo_delay);
  delay = "";
  if (segundos > 3599) {
    delay = segundos / 3600 + " horas ";
    segundos = segundos % 3600;
  }
  if (segundos > 59) {
    delay = segundos / 60 + " minutos ";
    segundos = segundos % 60;
  }
  if (segundos != 0) {
    delay += segundos + " segundos ";
  }
  do_shout(delay + "hasta el fin de Arda.\n");
  if(tiempo_rest < 600 && shut_ok < sizeof(progr_mensajes)) {
    call_out("efunshout", random(3), progr_mensajes[shut_ok]);
    shut_ok++;
  }
  ok_alt_msgs = (nuevo_delay <= 300);
}

/*-------------------------------------------------------------------------*/
stopshut() {
  remove_call_out("cont_shutting");
  if (!shut_ok) return;
  shut_ok = 0;
  if (TP) {
    catch(log_file("SIM_SHUT",TP->QueryRealName()+
                        " ha logrado detener la destrucción de Arda "+ctime(time())+"\n"));
  }
  shout("El Fin de Arda no ha llegado aún. Da gracias a Eru por ello.\n");
  remove();
}

/*-------------------------------------------------------------------------*/
heart_beat() {
  if(shut_ok && ok_alt_msgs) {
    /* random apocalypse messages */
    if(random(100) < 5) {
      shout(aleat_mensajes[random(sizeof(aleat_mensajes))]);
    }
  }
  set_heart_beat(1);
}

/*-------------------------------------------------------------------------*/
do_shout(str) {
  shout("[ ] " + str);
  if (TP) tell_object(TP, "[ ] "+str);
}

/*-------------------------------------------------------------------------*/
query_progress() {
  return shut_ok;
}

query_reason() { return razon; }
set_reason(arg) { return razon = arg; }
query_time_left() { return tiempo_rest; }

/*-------------------------------------------------------------------------*/
/* To call 'shout' via call_out(), even reaching the player which started
** the shutdown
*/
efunshout(str) {
  shout(str);
  if (TP) tell_object(TP, str);
}

/*========================================================================*/
