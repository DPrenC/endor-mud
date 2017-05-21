// Comando unalias

#include <sounds.h>

public int main(string str) {

    string al,cmd,msg_als;
    int i;

    if(str=="?" || !str)
        return notify_fail(
"     unalias/dealias <alias>        Elimina el alias <alias>\n"
"     unalias/dealias *              Elimina TODOS los alias definidos\n"
"Si quieres más informacion escribe 'ayuda unalias/dealias'.\n");

    if (str == "*") {
        write("Borrando TODOS tus alias almacenados...\n");
        TP->ResetAliases();
    }
    else {
        if (TP->RemoveAlias(str)) {
            write("El alias '"+str+"' ha sido eliminado correctamente.\n");
            play_sound(TP, SND_SUCESOS("removealias"));
        }
        else {
            write("El alias "+str+" no existe.\n");
        }
    }
    return 1;
}