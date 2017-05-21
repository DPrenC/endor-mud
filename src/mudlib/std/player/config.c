/**
 * SIMAURIA '/std/player/config.c'
 */

#include <telnet.h>
#include <colours.h>
#include <sounds.h>
//----------------------------------------------------------------------------

private int tiflo;          // Vale 1 si el player tiene activados los mensajes para ciegos
private int sounds; // Vale 1 si tiene los sonidos activados
private int soundEnvironment; // sonidos de ambiente
private string lastSound; // último sonido escuchado
private string *soundsDisabled; // sonidos deshabilitados.
private int soundVolume = 100; // el volúmen de los sonidos
private string soundFormat = "mp3"; // formato de los archivos de audio
private int music; // si escucha o no la música en el juego
private string lastMusic; // última música escuchada
private string *musicsDisabled; // músicas deshabilitadas
private int musicVolume = 100; // el volúmen de la música
private string tty;           // tipo de terminal
private int key_charset;      // Juego de caracteres
private string pMainCharacter; // cual es su personaje principal


private int width = 80;       // Anchura de la pantalla
private int height = 25;      // Altura de la pantalla

private mapping pColours = DEFAULT_COLOURS; // Colores

//----------------------------------------------------------------------------

// Mensajes para ciegos
public int SetTiflo(int i)  { return tiflo = i?1:0; }
public int QueryTiflo()     { return tiflo; }

//----------------------------------------------------------------------------
// Sonidos

public int SetSounds(int i) { return sounds = i ? 1 : 0; }
public int QuerySounds() { return sounds; }

public int SetSoundEnvironment(int i) { return soundEnvironment= i; }
public int QuerySoundEnvironment() { return soundEnvironment; }

public string SetLastSound(string sound) { return lastSound = sound; }
public string QueryLastSound() { return lastSound; }

public string *SetSoundsDisabled(string *s) { return soundsDisabled = s; }
public string *QuerySoundsDisabled() { return copy(soundsDisabled); }

public int DisableSound(string s)
{
    if (!soundsDisabled)
    {
        soundsDisabled = ({s});
        return 1;
    }
    if (!sizeof (soundsDisabled) || member(soundsDisabled, s) < 0)
    {
        soundsDisabled += ({s});
        return 1;
    }
    return 0;
}

public int EnableSound(string s)
{
    if (!soundsDisabled || !sizeof(soundsDisabled) || member(soundsDisabled, s) < 0) return 0;
    soundsDisabled -= ({s});
    return 1;
}

public int QuerySoundEnabled(string sound) { return !soundsDisabled || member(soundsDisabled, sound) < 0; }


public int SetSoundVolume(int v)
{
    if (v < 1) v = 1;
    else if (v > 100) v = 100;
    return soundVolume = v;
}

public int QuerySoundVolume() { return soundVolume; }

public string SetSoundFormat(string s) { return soundFormat = s; }
public string QuerySoundFormat() { return soundFormat; }

//----------------------------------------------------------------------------
// Música

public int SetMusic(int i) { return music = i ? 1 : 0;
}
public int QueryMusic() { return music; }

public string SetLastMusic(string music) { return lastMusic = music; }
public string QueryLastMusic() { return lastMusic; }

public string *SetMusicsDisabled(string *s) { return musicsDisabled = s; }
public string *QueryMusicsDisabled() { return copy(musicsDisabled); }

public int DisableMusic(string s)
{
    if (!musicsDisabled)
    {
        musicsDisabled = ({s});
        return 1;
    }
    if (!sizeof (musicsDisabled) || member(musicsDisabled, s) < 0)
    {
        musicsDisabled += ({s});
        return 1;
    }
    return 0;
}


public int EnableMusic(string s)
{
    if (!musicsDisabled || !sizeof(musicsDisabled) || member(musicsDisabled, s) < 0) return 0;
    musicsDisabled -= ({s});
    return 1;
}

public int SetMusicVolume(int v)
{
    if (v < 1) v = 1;
    else if (v > 100) v = 100;
    return musicVolume = v;
}

public int QueryMusicEnabled(string music) { return !musicsDisabled || member(musicsDisabled, music) < 0; }


public int QueryMusicVolume() { return musicVolume; }



//----------------------------------------------------------------------------

// Tipo de terminal
public string SetTTY(string str) {
  if (str != "dumb" && str != "vt100" && str != "ansi") return 0;
  return tty = str;
}
public string QueryTTY() { return tty; }

//[t] Teclado "extendido"? == español...
public int QueryCharset()    { return key_charset; }
public int SetCharset(int k) { return key_charset = k; }

//----------------------------------------------------------------------------

// Altura y anchura de la pantalla
public int QueryConsoleWidth()      { return width; }
public int QueryConsoleHeight()     { return height; }
public int SetConsoleWidth(int to)  { return width = to; }
public int SetConsoleHeight(int to) { return height = to; }

// Tamaño de pagina
public int SetPageSize(int size) { return SetConsoleHeight(size); }
public int QueryPageSize()       { return QueryConsoleHeight() - 1; }

//----------------------------------------------------------------------------

// Personaje principal o secundario

public string SetMainCharacter(string s) { return pMainCharacter = s; }
public string QueryMainCharacter() { return pMainCharacter; }



// Negociación con el cliente
public void negotiate(int cmd, int option, int *args) {
    if (cmd == SB) {
        if (option == TELOPT_NAWS) {
            SetConsoleWidth(args[0]<<8|args[1]);
            SetConsoleHeight(args[2]<<8|args[3]);
        }
    }
    else if (cmd == WONT) {
        if (option == TELOPT_NAWS) {
            SetConsoleWidth(80);
            SetConsoleHeight(25);
        }
    }
}

//----------------------------------------------------------------------------

// Colores
public mapping SetColours(mapping m)    { return pColours = m; }
public mapping QueryColours()           {
    return (tiflo||(tty=="dumb"))?NO_COLOURS:pColours;
}
public void RestoreColours()            { pColours = DEFAULT_COLOURS; }
public void SetColour(string key, string colour) { pColours[key] = colour; }

//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Esta funcion es llamada cada vez que este objeto recibe un mensaje
// Mucho cuidado con ella, no tocar sin conocer en profundidad como funcionan
// las efuns write y tell_object junto con el catch_tell

void catch_tell(string str) {
    if (interactive() && sizeof(str)) {
        tell_object( TO,
                     terminal_colour( str
                                    , QueryColours()
                                    , QueryConsoleWidth()
                                    , 0 )
                   );
    }
}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// envía str al player sin pasar por catch_tell
public void TellDirectly(string str)
{
    if (!str || !strlen(str)) return;
    tell_object(TO, str);
}
//-----------------------------------------------------------------------------
