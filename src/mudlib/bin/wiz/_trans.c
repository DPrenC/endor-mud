
/* SIMAURIA '/bin/wiz/_trans.c'
   ============================
   [w] Woo@simauria

   01-04-99 [w] Traspaso desde el player.c y retocado, por ejemplo he quitado
                toda la parte de trans para jugadores y ahora si pones
                'trans a <jugador>' funciona igual que 'trans <jugador>'.
*/

#include "/secure/wizlevels.h"
#include <moving.h>

int main( string str )
{
  object ob, old_env;
  string quien;

  if (!str)
    return notify_fail("�Transportar a qui�n?\n");

  // [w] Por si acaso pones 'trans a woo' funciona igual que 'trans woo'.
  if (sscanf(str,"a %s",quien)==1) str = quien;

  if (!(ob = find_object(lower_case(str)))) {
    write("No existe nadie llamado as�.\n");
    return 1;
  }
  tell_object(ob,"Un enceguecedor rel�mpago blanquecino estalla a tu alrededor.\n"
  "Por mediaci�n del insondable poder de Eru y perent�reo mandato de un Vala,  has \n"
  "sido convocado ante la presencia de uno de los Se�ores del mundo.\n");
  //[t] Cambio M_TELEPORT por M_SILENT
  old_env = environment(ob);
  if (ob->move(environment(TP), M_SILENT) != ME_OK) {
    write("�"+ob->QueryName()+" hace caso omiso de tu mandato.\n");
    tell_object(ob, "�"+TP->QueryName()
                +" te convoca junto a s�, pero su mandato no tiene ning�n efecto sobre ti.\n");
    return 1;
  }
  tell_object(ob, "Te hallas en otro lugar de Arda...\n");
  seteuid(getuid());
  log_file("TELETRANS", ctime() + ". " + CAP(TNREAL) + " teletransport� a " + CAP(NREAL(ob)) + " a " + object_name(environment(TP)) + " desde " + object_name(old_env) + ".\n");
  write("Invocas a Eru, y por mediaci�n de su Poder y como uno de los encumbrados Ainur \n"
  "que eres, convocas a uno de los seres mortales de Arda ante tu presencia.\n");
  return 1;
}
