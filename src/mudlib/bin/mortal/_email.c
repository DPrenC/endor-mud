/* SIMAURIA '/bin/mortal/_email.c'
*/

#include "/secure/userinfo.h"
#include <input_to.h>
#include <characters.h>

private static string _email;
private static mixed *uinfo;

public int main(string str)
{
    uinfo = MASTER->find_userinfo(TNREAL, 1);
    if (!str || str == "")
    {
        write("Tu dirección de correo electrónico actual es: " +
              uinfo[USER_EMAIL] + ".\n");
        return 1;
    }
    if (uinfo[USER_ID] != uinfo[USER_MAIN_CHARACTER])
    {
        return notify_fail("Sólo podrás cambiar la dirección de correo de tus personajes "
                           "desde tu personaje principal.\n");
    }
    if (uinfo[USER_EMAIL] == str)
    {
        return notify_fail("Esa ya es tu dirección de correo actual.\n");
    }
    if (LOGIN->valid_email(str) <= 0)
    {
        return notify_fail("Esa dirección de correo no es válida.\n");
    }
    if (MASTER->mail_exists(str))
    {
        return notify_fail("Esa dirección de correo ya está registrada en el sistema para otro "
                           "personaje no asociado a este.\n");
    }
    _email = str;
    input_to("enter_email", INPUT_PROMPT,
        "Vuelve a escribir la nueva dirección de correo electrónico: ");
    return 1;
}

public void enter_email(string str)
{
    mixed *info;
    if (str != _email)
    {
        write("¡Has introducido dos direcciones de correo diferentes!\n");
        return;
    }
    if ((info = CHARMASTER->QueryBanishedEmail(str, CH_INFO))[CH_STATUS])
    {
        write("\n¡Esa dirección de correo electrónico está baneada" +
            (info[CH_INFO][E_BAN_UNTIL] ? " hasta el " + STR->etime(1, ctime(info[CH_INFO][E_BAN_UNTIL])) : "") +
            "!\n");
        return;
    }
    if (!send_server_request("ChangeEmail", MASTER->find_userinfo(TNREAL)[USER_ID], _email))
    {
        write("¡Error al enviar la petición de cambio de dirección de correo electrónico!\n"
              "Por favor, inténtalo de nuevo, y si continúa sin funcionar, contacta con "
              "un vala.\n");
        return;
    }
    write("De acuerdo. Se te ha enviado un e-mail a " + _email + " con instrucciones "
          "para realizar el cambio de dirección.\n");
}