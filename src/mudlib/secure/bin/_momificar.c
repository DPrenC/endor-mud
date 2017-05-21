// Comando momificar
// Esto es por el rollo de las momias y tal... que por cierto no tengo muy claro
// para que valen.

#include <wizlevels.h>

/* Variables del fichero de secure/save */
string name;
string password;
int level;
int promotion_age;
int creation;

// Variables del baneo:
string reason;
string mummyfied_by;

//public int momificar(string str) {
public int main(string str) {
    string nombre, razon;

    if (!IS_ARCH(TI)) return 0;

    if (  !str
        || (sscanf(str, "%s porque %s", nombre, razon) != 2)
        ||!nombre
       )
    {
        return notify_fail("Uso: momificar <nombre> porque <razón>\n");
    }

    if (!LOGIN->valid_name(nombre))
        return notify_fail("Nombre no válido.\n");

    // [Nyh] La siguiente comprobación es estúpida, ya que cualquiera que pueda
    //       usar este comando tiene derechos de escritura para modificarlo.
    if (query_wiz_level(nombre) >= query_wiz_level(TI)) {
        return notify_fail("No puedes momificar a alguien con mayor o igual nivel que tú.\n");
    }

    seteuid(getuid());

    if (restore_object(SECUREMUMMYPATH + nombre)) {
        write("¡Ese nombre ya está momificado!\n");
        return 1;
    }

    if (!restore_object(SECURESAVEPATH + nombre[0..0] + "/" + nombre)) {
        write("Ese nombre no está siendo utilizado por nadie.\n");
        return 1;
    }

    log_file("MOMIAS","-> "+nombre+" por: "+TI->QueryRealName()+" motivo: "+razon+"\n");
    mummyfied_by = TI->QueryRealName();
    name = nombre;
    reason = razon;
    save_object(SECUREMUMMYPATH + nombre);
    write("Has momificado a "+nombre+".\n");
    return 1;
}