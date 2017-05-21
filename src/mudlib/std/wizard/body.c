/**
 * SIMAURIA '/std/wizard/body.c'
 */

inherit "/std/player/body";

//----------------------------------------------------------------------------

public varargs void Die(mixed silent) {
    /* Don't damage wizards too much ! */
    if (TO->QueryNowiz()) {
        return ::Die(silent);
    }

    TO->catch_msg("Tu condición de Vala te protege de una muerte segura.\n");
}

//----------------------------------------------------------------------------
