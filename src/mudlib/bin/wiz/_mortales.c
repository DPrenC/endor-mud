/* SIMAURIA '/bin/wiz/_mortales.c'
   ===============================
   [i] Izet@simauria
   [w] Woo@simauria

   ??-??-?? [i] Creación de este archivo
   17-11-99 [w] Retocado .. bastante.
*/

int main() {
  object *usuarios;
  int i,no_users;
  string ret;

  usuarios=users();

  for(i=0;i<sizeof(usuarios);i++) {
   if((!query_wiz_level(usuarios[i])) &&
      (geteuid(usuarios[i])!="ze/us") &&
      (geteuid(usuarios[i])!="gopher")) {
      if(!no_users) {
        ret="  Jugador          Fza   Int   Des   Con   Nivel   Experiencia\n";
        ret+="  ------------------------------------------------------------------------\n";
        no_users=1;
      }
      ret+="  "+STR->ladjust(capitalize(getuid(usuarios[i])),17);
      ret+=STR->ladjust(""+(usuarios[i]->QueryStr()>90?"<I>":usuarios[i]->QueryStr()),6);
      ret+=STR->ladjust(""+(usuarios[i]->QueryInt()>90?"<I>":usuarios[i]->QueryInt()),6);
      ret+=STR->ladjust(""+(usuarios[i]->QueryDex()>90?"<I>":usuarios[i]->QueryDex()),6);
      ret+=STR->ladjust(""+(usuarios[i]->QueryCon()>90?"<I>":usuarios[i]->QueryCon()),6);
      ret+="<"+STR->ladjust(""+usuarios[i]->QueryLevel(),3)+">   ";
      ret+=usuarios[i]->QueryXP()+"\n";
      }
   }
  if (!no_users) return notify_fail("No hay ningún jugador conectado.\n"),0;
  return write(ret+"\n"),1;
}
