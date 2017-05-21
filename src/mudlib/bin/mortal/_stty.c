// Comando stty

#include <colours.h>

public main(string str) {
  if (!str || str == "") {
    write("tty es "+(TP->QueryTTY()?TP->QueryTTY():"none")+".\n");
    return 1;
  }

  switch (lower_case(str)) {
  case "vt100":
    TP->SetTTY("vt100");
    write("Esto debería ser "+ANSI_BOLD+"bold"+ANSI_NORMAL+"\n");
    break;
  case "ansi":
    TP->SetTTY("ansi");
    write("Esto debería ser "+ANSI_RED+"rojo"+ANSI_NORMAL+"\n");
    break;
  case "dumb":
  case "":
    TP->SetTTY("dumb");
    write("Deberías pensar en actualizar el tipo de terminal...\n");
    break;
  default:
    write("Ese tipo de terminal no está soportado; utiliza uno de estos:\n");
    write("vt100, ansi o dumb\n");
  }
  return 1;
}
