int masalla(string str) {
string what;
string whom;

if (!str || sscanf(str,"%s %s",whom,what)!=2) {
   notify_fail("Uso: masalla <jugador> <mensaje>\n");
   return 0;
  } else {
  if (!find_object(lower_case(whom)) ) {
    notify_fail("El jugador "+capitalize(whom)+" no esta conectado.\n");
   return 0;
   }

tell_object(find_object(whom),"El mas alla te dice: "+what+"\n");
printf("Desde el mas alla, le dices a "+capitalize(whom)+":\n");
printf("'"+what+"'\n");
return 1;
  }
}
