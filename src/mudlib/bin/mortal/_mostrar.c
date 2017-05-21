/* Izet@Simauria
   Comando mostrar. Sirve para mostrar un objeto a otro jugador sin tener que
   darselo. Uso:  mostrar <objeto> a <jugador>
*/
int mostrar(string str) {
string obj, who;
object ob;
    if (!str || sscanf(str,"%s a %s",obj,who) != 2) {
        write("Enseñar QUE a QUIEN?\n");
        return 1;
    }
    who = lower_case(who);
   if (!present(obj, TP) ) {
      write("No tienes '"+obj+"' para enseñar a nadie.\n");
      return 1;
   }
   if (!find_object(who)) {
      write(capitalize(who)+" no está aquí.\n");
      return 1;
   }
   if (!present(find_object(who),environment(TP) ) ) {
       write(""+capitalize(who)+" no está aquí.\n");
       return 1;
   }
   if (find_object(who) == TP ) {
      write("¿Para qué quieres enseñártelo a ti mismo?\n");
      return 1;
   }
   ob = present(obj, TP);
   write("Le enseñas "+ob->QueryShort()+" a "+capitalize(who)+".\n");
   tell_object(find_object(who),
               TP->QueryName()+" te enseña "+ob->QueryShort()+":\n"+
               ob->QueryLong() );
   return 1;
}
