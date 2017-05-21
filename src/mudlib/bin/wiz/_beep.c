/* SIMAURIA '/bin/_beep.c'
   -----------------------
   [t] Theuzifan@localhost

   03-11-98 [t] Crea el comando beep pa wizs
*/

#include <sounds.h>

varargs beep(string str)
{
  object ob;
  string msg, who;

  if (!str)
    return notify_fail("Beepear a quien?\n");

  if (strstr(str, " ", 0) != -1)
    sscanf(str, "%s %s", who, msg);
  else who=str;

  ob=find_object(lower_case(who));
  if (!ob)
  {
    if (find_object(lower_case(who)))
      return notify_fail(capitalize(who)+" no esta en este momento.\n");
    else
      return notify_fail("No existe ningun jugador llamado "+capitalize(who)+".\n");
  }
  play_sound(ob, SND_SUCESOS("beep"));
  if (!msg)
  {
    tell_object(ob, "La voz de "+capitalize(TNAME)+" resuena de forma perentórea en tu mente, requiriendo tu plena atención.\n");
    write("Mediante  tus poderes mentales, y a través de tiempo y espacio requieres la atención de "+capitalize(ob->QueryRealName())+".\n");
  }
  else
  {
    tell_object(ob, "La poderosa voz de "+capitalize(TNAME)+" resuena en tu cabeza diciendo: "+msg+".\n");
    write("Utilizando tu poderosa mente, le hablas  a "+capitalize(ob->QueryRealName())+" diciéndole: "+msg+".\n");
  }

  return 1;
}
