/**
 * simauria /obj/lib/date
 * Librería de funciones de manejo de fechas
*/


public int is_leap(int ano)
// devuelve si un año dado es o no bisiesto.
{
    return ano % 4 == 0 || (ano % 400 == 0 && ano % 100 == 0);
}

public int days_of_month(int mes, int ano)
{
    if (mes == 2)
    {
        return (is_leap(ano) ? 29 : 28);
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) return 30;
    return 31;
}

public int get_timestamp(string fecha)
// dada una fecha en el formato dd/mm/aaaa hh:mm:ss, o quitando la hora,
// devuelve la marca de tiempo timestamp.
{
    int dia, mes, ano, anos, timestamp, hora, minuto, segundo, i;
    string t, *t2;
    if (   sscanf(fecha, "%2d/%2d/%4d %2d:%2d:%2d", dia, mes, ano, hora, minuto, segundo) != 6
        && sscanf(fecha, "%2d/%2d/%4d %2d:%2d", dia, mes, ano, hora, minuto) != 5
        && sscanf(fecha, "%2d/%2d/%4d %2d", dia, mes, ano, hora) != 4
        && sscanf(fecha, "%2d/%2d/%4d", dia, mes, ano) != 3)
    // fecha no válida
    {
        return 0;
    }
    if (   dia > 31 || dia < 0 || mes > 12 || mes < 0
        || (!is_leap(ano) && mes == 2 && dia > 28)
        || dia > days_of_month(mes, ano)
        || hora > 23 || hora < 0
        || minuto > 60 || minuto < 0
        || segundo > 60 || segundo < 0
        || ano < 1970
        || ano == 1970 && hora < 1)
    {
        return 0;
    }

    // calculamos primero los años transcuridos desde el año de inicio (1970) hasta el año fin
    for (i = 1970;i<ano;i++)
    {
        timestamp += 60 * 60 * 24 * (is_leap(i) ? 366 : 365);
    }
    // ahora vamos con los días y meses de lo que resta:

    for (i=1;i<mes;i++)
    {
        timestamp += 60 * 60 * 24 * days_of_month(i, ano);
    }

    timestamp += 60 * 60 * 24 * (dia - 1);
    timestamp += 60 * 60 * hora;
    timestamp += 60 * minuto;
    timestamp += segundo;
    // restamos una hora pues el recuento comienza a las 01:00 del 1 de enero de 1970
    timestamp -= 3600;


    // calculamos si hay que quitarle una hora o no por lo del horario de verano
    t = ctime(timestamp);
    t2 = explode(t, " ");
    // si la hora del ctime no es la hora esperada, hay que restarle una hora al timestamp.
    if (t2[3] != (hora ? hora + ":" + (minuto ? minuto + ":" + (segundo ? segundo : "00") : "00:00") : "00:00:00"))
    {
        timestamp -= 3600;
    }

    return timestamp;
}
