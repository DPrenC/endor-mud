#include "/secure/config.h"
#include <wizlevels.h>
#include <files.h>

#define FAKER   "/secure/faker"

create() {
    seteuid(getuid());
    printf("Cargando el UPDATER con euid: %O.\n",geteuid());
}

/**
Hace un bucle por todos los savefile llamando lo q toque.
*/

private void _actualizar() {
    object ob;
    string dir, file, *savedirs = ({}), *errors = ({});

    log_file("UPDATER",sprintf("\t[%s] _actualizar()\n",ctime()));

    ob = find_object(PLAYER);
    if (ob && environment(ob)) destruct(ob);
    if (!find_object(PLAYER)) load_object(PLAYER);

    ob = find_object(FAKER);
    if (ob && environment(ob)) destruct(ob);
    if (!find_object(FAKER)) ob = load_object(FAKER);

//Puedo simplificar aun mas esto con mas filters... pero paso...
    savedirs = get_dir("/"+SAVEPATH+"*",GETDIR_PATH)-({"/"+SAVEPATH+".","/"+SAVEPATH+".."});
    foreach(dir: savedirs) if (file_size(dir)==FSIZE_DIR)
    {
        errors += filter(get_dir(dir+"/*.o",GETDIR_PATH), (: $2->fake_and_update($1) :), ob);
    }

    if (sizeof(errors))
    {
      log_file("UPDATER",sprintf("Errores: %O\n", errors));
    }
    log_file("UPDATER",sprintf("\t[%s] Terminado _actualizar()\n",ctime(time())));
}

public int Actualizar() {
    log_file("UPDATER",sprintf("-------------------------------------------------------------------------------\n"
                              "[%s] Llamada al Updater por '%O'.\n",ctime(time()),geteuid(PO)));

    if (!TI || !IS_CON(geteuid(TI)))
    {
       log_file("UPDATER",sprintf("\tLlamada no autorizada. No se ejecuta la actualización.\n"
                          "[%s] Llamada al Updater por '%O'.\n",ctime(time()),geteuid(PO)));
    }
    else
    {
        limited(SF(_actualizar));
    }

    log_file("UPDATER",sprintf("[%s] Llamada al Updater terminada.\n"
             "-------------------------------------------------------------------------------\n\n"
             ,ctime(time())));

    return 1;
}