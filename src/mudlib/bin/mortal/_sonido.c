/**
 * simauria /bin/mortal/_sonido
 */

#include <sounds.h>

public int main(string str)
{
    int valor, szdisabled;
    string sonido, *disabled;
    if (!TP) return 0;
    if (!str || !strlen(str))
    // mostrar ayuda
    {
        return notify_fail("Efectos sonoros " + (TP->QuerySounds() ? "activados" : "desactivados") + "." 
            " Sonidos de ambiente: " + (TP->QuerySoundEnvironment() ? "activados" : "desactivados") + ". "
            " Volumen por defecto: " + TP->QuerySoundVolume() + "%.\n" 
                           "Formato de ficheros de audio digital: " + (TP->QuerySoundFormat()) + ".\n"
                           "Uso: sonido ultimo, activar, desactivar, ambiente, "
                           "habilitar, deshabilitados, volumen, formato.\n", NOTIFY_NOT_VALID);
    }
    str = LOWER(str);
    switch (str)
    {
    case "formato":
        write("Formato actual de audio: " + TP->QuerySoundFormat() + ".\n"
            "Usa sonido formato, seguido de la opción que desees: " + implode_list(SOUND_SUPPORT, 0, ".\n", "o"));
        return 1;
        break;
    case "ambiente":
        write("Sonidos de ambiente " + (TP->QuerySoundEnvironment() ? "activados" : "desactivados") +
              ". Usa sonido ambiente activar/desactivar para modificar su estado.\n");
        return 1;
        break;
    case "volumen":
        write("Volumen de los sonidos: " + TP->QuerySoundVolume() + "%. Usa sonidos volumen <valor> "
              "(en porcentaje), para ajustar el volumen que tendrán los sonidos que escuches.\n");
        return 1;
        break;
    case "activar":
        // activamos los sonidos
            if (TP->QuerySounds())
            {
                return notify_fail("Los efectos sonoros ya estaban activados.\n");
            }
            TP->SetSounds(1);
            write("Efectos sonoros activados.\n");
            return 1;
            break;
        case "desactivar":
            if (!TP->QuerySounds())
            // ya están desactivados
            {
                return notify_fail("Los efectos sonoros ya estaban desactivados.\n");
            }
            stop_sounds(TP);
            TP->SetSounds(0);
            write("Efectos sonoros desactivados.\n");
            return 1;
            break;
        case "ambiente activar":
            object env;
            if (TP->QuerySoundEnvironment())
            {
                return notify_fail("Los sonidos de ambiente ya estaban activados.\n", NOTIFY_NOT_VALID);
                break;
            }
            TP->SetSoundEnvironment(1);
            if ((env = environment(TP)) && (sonido = env->QuerySoundEnvironment()))
            {
                play_sound(TP, funcall(sonido), 0, env->QuerySoundEnvironmentVolume(), -1);
            }
            write("Sonidos de ambiente activados.\n");
            return 1;
            break;
        case "ambiente desactivar":
            if (!TP->QuerySoundEnvironment())
            {
                return notify_fail("Los sonidos de ambiente ya estaban desactivados.\n", NOTIFY_NOT_VALID);
                break;
            }
            stop_sounds(TP);
            TP->SetSoundEnvironment(0);
            write("Sonidos de ambiente desactivados.\n");
            return 1;
            break;
        case "ultimo":
        // mostramos la ayuda de ultimo y la ruta del último sonido
            if (!(sonido = TP->QueryLastSound()))
            // no ha escuchado ninguno últimamente
            {
                return notify_fail("No has escuchado ningún sonido últimamente.\n");
            }
            write("El último sonido que has escuchado ha sido: '" + sonido +"'.\n" + 
                  ((disabled = TP->QuerySoundsDisabled()) && member(disabled, sonido) >= 0 ?
                  "Actualmente está deshabilitado.\n" : 
                  "Usa: 'sonido ultimo escuchar' para escucharlo, o 'sonido ultimo deshabilitar' para "
                  "deshabilitarlo en futuras ocasiones.\n"));
            return 1;
            break;
        case "ultimo escuchar":
            if (!(sonido = TP->QueryLastSound()))
            // no ha escuchado ninguno últimamente
            {
                return notify_fail("No has escuchado ningún sonido últimamente.\n");
            }
            if (!TP->QuerySounds())
            {
                return notify_fail("No se puede reproducir el último sonido, tienes los efectos "
                                   "sonoros desactivados. Para activarlos, teclea 'sonido activar'.\n");
            }
            write("Reproduciendo " + sonido + ".\n");
            play_sound(TP, sonido);
            return 1;
            break;
        case "ultimo deshabilitar":
            sonido = TP->QueryLastSound();
            
            if (!sonido)
            {
                return notify_fail("No has escuchado ningún sonido últimamente.\n");
            }
            if ((disabled = TP->QuerySoundsDisabled()) && member(disabled, sonido) >= 0)
            // ya lo tiene deshabilitado
            {
                return notify_fail("Este sonido ya está deshabilitado.\n");
            }
            write("Deshabilitando " + sonido + ".\n");
            TP->DisableSound(sonido);
            return 1;
            break;
        case "deshabilitados":
            // mostramos el listado
            int i;

            if (!(disabled = TP->QuerySoundsDisabled()) || !sizeof(disabled))
            // no tiene
            {
                return notify_fail("No tienes sonidos deshabilitados actualmente.\n");
            }
            STR->smore("Listado de sonidos deshabilitados:\n" +
                       implode(map(disabled, (:++$2 + ". " + $1:), &i), ".\n"));
            return 1;
            break;
    }
    // puede que se intente ajustar el volúmen, el formato de audio o habilitar un sonido
    if (str[..6] == "formato")
    {
        if (member(SOUND_SUPPORT, str[8..]) < 0)
        {
            return notify_fail("Ese formato es desconocido. Usa " +
                               implode_list(SOUND_SUPPORT, 0, 0, "o") + " dependiendo del "
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
            return notify_fail("El volumen de los sonidos no puede ser mayor a 100. Recuerda que se "
                               "expresa como el porcentaje del volumen real del archivo sonoro.\n",
                               NOTIFY_NOT_VALID);
        }
        TP->SetSoundVolume(valor);
        write("Volumen de los sonidos ajustado al " + valor + "%.\n");
        return 1;    
    }
    if (str[..8] == "habilitar")
    {
        if (sscanf(str, "habilitar %d", valor) != 1)
        {
            return notify_fail("Sonidos habilitar <número del sonido>.\nPara ver los sonido "
                               "deshabilitados y su número de identificación correspondiente, escribe sonido "
                               "deshabilitados.\n");
        }
        if (valor <= 0)
        {
            return notify_fail("El número del sonido a habilitar debe ser positivo.\n");
        }
        if (!(disabled = TP->QuerySoundsDisabled()) || !(szdisabled = sizeof(disabled)))
            // no tiene sonidos deshabilitados
        {
            return notify_fail("Actualmente no tienes sonidos deshabilitados.\n");
        }
        if (valor > szdisabled)
        {
            return notify_fail("El sonido " + valor + " no es un número válido. Solo hay " + szdisabled +
                               " sonidos deshabilitados.\n");
        }
        write("Habilitando el sonido " + valor + ": " + disabled[--valor] + ".\n");
        TP->EnableSound(disabled[valor]);
        return 1;
    }
// Mostramos la ayuda
    return notify_fail("Sintaxis: sonido ultimo, activar, desactivar, ambiente, habilitar, deshabilitados, volumen.\n", NOTIFY_NOT_VALID);
}