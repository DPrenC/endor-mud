/***
Fichero: _obj.c
Autor: kastwey@simauria
Descripción: Devuelve los objetos de una habitación.
Creación: 19/11/2004
***/

#define MSG_SPEAK "all_speak:"
#define TIFLO(x) (TP->QueryTiflo() ? MSG_SPEAK : "") + x




public int main(string str)
{
    object pl = TP;
    object env;
    string objetos;
    int vision;


    if (!pl) return 0;

    if (!(env = environment(TP)))
    {
        return notify_fail(TIFLO("No estás en ningún sitio.\n"));
    }
    if ((vision = pl->CantSee()))
    {
        return notify_fail(TIFLO((vision > 0 ? "Hay demasiada luz. " :
                                               "Está demasiado oscuro. ") +
                                  "No ves nada.\n"));
    }

    objetos = env->Content();
    if (objetos == "") objetos = "No hay objetos.\n";
    write(TIFLO(objetos));
    return 1;
}