// Comando suicidar
#include <colours.h>
#include <input_to.h>
#include <wizlevels.h>
#include "/secure/userinfo.h"

public int main(string arg) {
  if (!TP || !TI || TI != TP || IS_LEARNER(TI)) return 0;

  input_to("suicide2", INPUT_PROMPT,
  ANSI_RED+"¡Aviso!\n"+ANSI_NORMAL+
  "El comando suicidar únicamente es para borrar la ficha en Endor-Mud.\n"
  "Para continuar introduce la contraseña del personaje.\n Si no quieres borrar la ficha del mud escribe cancelar.\n");
                                     return 1;
}

private void remove_player()
{
    if (!"/secure/remover"->remove_player(getuid(TP))) write("Inténtalo en otro momento.\n");
    else
    {
        write(
        "\nQue Mandos y Eru guarden tu alma. Esperamos volver a verte por las legendarias tierras de Endor.\n");

        catch(TP->remove());
        if (TP) destruct(TP);
    }
    return;
}

public static void suicide2 (string str)
{
    mixed *uinfo;
    mixed *secundary;
    string *secundary_names;

    if (LOWER(str) == "cancelar")
    {
        write("\nLos Valar ven con aprobación que hayas decidido seguir recorriendo tu camino en la Tierra Media.\n");
        return;
    }
    write("\n");
    if (!MASTER->check_passwd(TNREAL, str || ""))
    {
        input_to("suicide2", INPUT_PROMPT,
                 ANSI_RED+"¡Contraseña  incorrecta!"+ANSI_NORMAL+
                 "\n Escribe correctamente la contraseña de tu personaje, o cancelar para salir del borrado de la ficha.\n");
        return;
    }

    write("Confirmado.\n\n");
    if (   (uinfo = MASTER->find_userinfo(TNREAL)) && uinfo[USER_ID] == uinfo[USER_MAIN_CHARACTER]
        && sizeof(secundary = MASTER->find_secundary_characters(uinfo[USER_ID])))
    // este personaje es principal
    {
        secundary_names = map(secundary, (:$1[AR_NAME]:));
        if (sizeof(secundary) == 1)
        // solo tiene un personaje secundario, así que convertimos a ese en principal, y ale
        {
            write("" + CAP(secundary_names[0]) + " es ahora tu personaje principal.\n");
            MASTER->update_secundary_characters(uinfo[USER_ID], secundary[0][AR_ID]);
            remove_player();
            return;
        }
        input_to("fsuicide3", INPUT_PROMPT,
                 "Al borrar este personaje te has quedado sin personaje principal.\n"
                 "Selecciona ahora cual de tus personajes secundarios quieres que sea tu personaje principal:\n"+
                 implode_list(secundary_names, 0, ".\n", "o") +
                 "Nombre de tu personaje secundario que quieres como principal: ", secundary,
                 secundary_names, uinfo[USER_ID]);
        return;
    }
    remove_player();
}

public void fsuicide3(string name, mixed *secundary, string *secundary_names, int id)
{
    int indice;
    if (!name || name == "")
    {
        input_to("fsuicide3", INPUT_PROMPT,
                 "Debes introducir el nombre de uno de tus personajes secundarios para "
                 "convertirlo en personaje principal.\n"
                 "Escribe uno de estos:\n" +
                 implode_list(secundary_names, 0, 0, "o") +
                 "Nombre de tu personaje secundario que quieres como principal: ", secundary, secundary_names, id);
        return;
    }
    if ((indice = member(secundary_names, name)) < 0)
    //  no tienes ningún personaje que se llame así
    {
    input_to("fsuicide3", INPUT_PROMPT,
                 "Ninguno de tus personajes secundarios se llama así.\n"
                 "Escribe uno de estos:\n" +
                 implode_list(secundary_names, 0, ".\n", "o") +
                 "Nombre de tu personaje secundario que quieres como principal: ", secundary, secundary_names, id);
        return;
    }
    write("" + CAP(name) + " es ahora tu personaje "
          "principal.\n"
          "Se han actualizado " + MASTER->update_secundary_characters(id, secundary[indice][AR_ID]) +
          ".\n");
    remove_player();
}



