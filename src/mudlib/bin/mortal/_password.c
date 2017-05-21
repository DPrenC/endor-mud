// Comando clave

#include <input_to.h>

static string passw;            /* temporal para cambio de clave */
static string passwold;         /* temporal para cambio de clave */

public int main(string str) {
  input_to("get_old_pass",   INPUT_PROMPT|INPUT_NOECHO|INPUT_APPEND,
           "Escribe tu contraseña actual: ");
  input_to("get_new_pass",   INPUT_PROMPT|INPUT_NOECHO|INPUT_APPEND,
           "Ahora, escribe tu nueva contraseña: ");
  input_to("reget_new_pass", INPUT_PROMPT|INPUT_NOECHO|INPUT_APPEND,
           "Para mayor seguridad, escribe tu nueva clave de nuevo: ");
  return 1;
}

static void get_old_pass(string str) {
  write("\n");
  if (!str) str == "";
  if (!MASTER->check_passwd(TNREAL, str)) {
    write("Contraseña incorrecta.\n");
    while (remove_input_to(TP));
  }
  passwold = str;
}

static void get_new_pass(string str) {
  write("\n");
  if ((!str) || str == "") {
    write("¡Interrumpido!\n");
    while (remove_input_to(TP));
  }
  if (strlen(str) < 4) {
    write("Tu contraseña debe de contar al menos con cuatro caracteres.\n");
    while (remove_input_to(TP));
    input_to("get_new_pass",   INPUT_PROMPT|INPUT_NOECHO|INPUT_APPEND,
             "Escribe tu nueva contraseña: ");
    input_to("reget_new_pass", INPUT_PROMPT|INPUT_NOECHO|INPUT_APPEND,
             "Por motivos de seguridad, escribe tu contraseña de nuevo: ");
  }
  else if (!sizeof(regexp(({str}), "^[-_a-zA-Z0-9]*$")))
  {
    write("\nLa contraseña no puede contener ningú carácter que no sea una letra,\n"
          "un número o los caracteres de guion (-) y guion bajo (_).\n");
    while (remove_input_to(TP));
    input_to("get_new_pass",   INPUT_PROMPT|INPUT_NOECHO|INPUT_APPEND,
             "Escribe tu nueva contraseña: ");
    input_to("reget_new_pass", INPUT_PROMPT|INPUT_NOECHO|INPUT_APPEND,
             "Por motivos de seguridad, escribe tu nueva clave otra vez: ");
  }
  else passw = str;
}

static void reget_new_pass(string str) {
  write("\n");
  if (!str || str != passw)
    write("¡Ésta es diferente! Clave NO cambiada.\n");
  else if (MASTER->update_password(passwold, passw))
    write("Tu contraseña ha sido modificada.\n");
  else
    write("Se ha producido un error mientras se cambiaba tu contraseña.\n");
}