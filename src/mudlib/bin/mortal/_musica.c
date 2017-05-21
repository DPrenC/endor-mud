/**
 * simauria /bin/mortal/_musica
 */

#include <sounds.h>

public int main(string str)
{
    int valor, szdisabled;
    string musica, *disabled;
    if (!TP) return 0;
    if (!str || !strlen(str))
    // mostrar ayuda
    {
        return notify_fail("Efectos musicales " + (TP->QueryMusic() ? "activados" : "desactivados") + ". " +
                           "Volumen por defecto de la música: " + TP->QueryMusicVolume() + "%. "
                           "Formato de ficheros de audio digital: " + TP->QuerySoundFormat() + ".\n"
                           "Uso: musica ultima, activar, desactivar, habilitar, deshabilitadas, volumen, formato.\n", NOTIFY_NOT_VALID);
    }
    str = LOWER(str);
    switch (str)
    {
    case "formato":
        write("Formato de audio actual: " + TP->QuerySoundFormat() + ".\nUsa musica formato "
            "<formato> para especificar el que desees. Los formatos soportados son: " +
            implode_list(SOUND_SUPPORT, 0,".\n","o"));
        return 1;
        break;
    case "volumen":
            write("Volumen por defecto para la música: " + TP->QueryMusicVolume() + "%. Usa musica volumen <valor> "
                  "(en porcentaje), para ajustar el volumen que tendrá la música que escuches.\n");
        return 1;
        break;
    case "activar":
        // activamos la musica
            if (TP->QueryMusic())
            {
                return notify_fail("Los efectos musicales ya estaban activados.\n");
            }
            TP->SetMusic(1);
            write("Efectos musicales activados.\n");
            return 1;
            break;
        case "desactivar":
            if (!TP->QueryMusic())
            // ya están desactivados
            {
                return notify_fail("Los efectos musicales ya estaban desactivados.\n");
            }
            stop_music(TP);
            TP->SetMusic(0);
            write("Efectos musicales desactivados.\n");
            return 1;
            break;
        case "ultima":
        // mostramos la ayuda de ultimo y la ruta de la última música
            if (!(musica = TP->QueryLastMusic()))
            // no ha escuchado ninguna últimamente
            {
                return notify_fail("No has escuchado ninguna música últimamente.\n");
            }
            write("La última musica que has escuchado ha sido: '" + musica +"'.\n" + 
                  ((disabled = TP->QueryMusicsDisabled()) && member(disabled, musica) >= 0 ?
                  "Actualmente está deshabilitada.\n" : 
                  "Usa: 'musica ultima escuchar' para escucharla, o 'musica ultima deshabilitar' para "
                  "deshabilitarla en futuras ocasiones.\n"));
            return 1;
            break;
        case "ultima escuchar":
            if (!(musica = TP->QueryLastMusic()))
            // no ha escuchado ninguna últimamente
            {
                return notify_fail("No has escuchado ninguna música últimamente.\n");
            }
            if (!TP->QueryMusic())
            {
                return notify_fail("No se puede reproducir la última musica, tienes los efectos "
                                   "musicales desactivados. Para activarlos, teclea 'musica activar'.\n");
            }
            write("Reproduciendo " + musica + ".\n");
            play_music(TP, musica);
            return 1;
            break;
        case "ultima deshabilitar":
            musica = TP->QueryLastMusic();
            
            if (!musica)
            {
                return notify_fail("No has escuchado ninguna música últimamente.\n");
            }
            if ((disabled = TP->QueryMusicsDisabled()) && member(disabled, musica) >= 0)
            // ya la tiene deshabilitada
            {
                return notify_fail("Esta musica ya está deshabilitada.\n");
            }
            write("Deshabilitando " + musica + ".\n");
            TP->DisableMusic(musica);
            return 1;
            break;
        case "deshabilitadas":
            // mostramos el listado
            int i;

            if (!(disabled = TP->QueryMusicsDisabled()) || !sizeof(disabled))
            // no tiene
            {
                return notify_fail("No tienes musicas deshabilitadas actualmente.\n");
            }
            STR->smore("Listado de musicas deshabilitadas:\n" +
                       implode(map(disabled, (:++$2 + ". " + $1:), &i), ".\n"));
            return 1;
            break;
    }
    // puede que se intente habilitar una musica, ajustar el formato de audio o ajustar su volúmen
    if (str[..6] == "formato")
    {
        if (member(SOUND_SUPPORT, str[8..]) < 0)
        {
            return notify_fail("Ese formato es desconocido. Usa " +
                implode_list(SOUND_SUPPORT, 0, 0, "o") + ", dependiendo del "
                               "tipo de audio que soporte tu cliente de muds, y del paquete de sonidos "
                               "que te hayas bajado de nuestra web.\n", NOTIFY_NOT_VALID);
        }
        TP->SetSoundFormat(str[8..]);
        write("Formato de audio establecido en " + str[8..] + ".\n");
        return 1;
    }
    if (str[..6] == "volumen")
    {
        if (!sscanf(str, "volumen %d", valor))
        {
            return notify_fail("Debes especificar un valor numérico comprendido entre 1 y 100.\n", NOTIFY_NOT_VALID);
        }
        if (valor < 1)
        {
            return notify_fail("El valor del volumen debe ser mayor o igual a 1.\n", NOTIFY_NOT_VALID);
        }
        if (valor > 100)
        {
            return notify_fail("El volumen de la música no puede ser mayor a 100. Recuerda que se "
                               "expresa como el porcentaje del volumen real del archivo sonoro.\n",
                               NOTIFY_NOT_VALID);
        }
        TP->SetMusicVolume(valor);
        write("Volumen de la música ajustado al " + valor + "%.\n");
        return 1;    
    }
    if (str[..8] == "habilitar")
    {
        if (sscanf(str, "habilitar %d", valor) != 1)
        {
            return notify_fail("Uso: musica habilitar <número de la musica>.\nPara ver las músicas "
                               "deshabilitadas y su número de identificación correspondiente, escribe musica "
                               "deshabilitadas.\n");
        }
        if (valor <= 0)
        {
            return notify_fail("El número de la música a habilitar debe ser positivo.\n");
        }
        if (!(disabled = TP->QueryMusicsDisabled()) || !(szdisabled = sizeof(disabled)))
            // no tiene músicas deshabilitadas
        {
            return notify_fail("Actualmente no tienes músicas deshabilitadas.\n");
        }
        if (valor > szdisabled)
        {
            return notify_fail("La música " + valor + " no es un número válido. Solo hay " + szdisabled +
                               " músicas deshabilitadas.\n");
        }
        write("Habilitando la música " + valor + ": " + disabled[--valor] + ".\n");
        TP->EnableMusic(disabled[valor]);
        return 1;
    }
    // Mostramos la ayuda
    return notify_fail("Efectos musicales " + (TP->QueryMusic() ? "activados" : "desactivados") + ". " +
                           "Volumen por defecto de la música: " + TP->QueryMusicVolume() + "%.\n"
                           "Uso: musica ultima, activar, desactivar, habilitar, deshabilitadas, volumen.\n", NOTIFY_NOT_VALID);
}