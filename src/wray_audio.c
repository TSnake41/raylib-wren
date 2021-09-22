/*
  Copyright (C) 2019-2021 Astie Teddy

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
  OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include <wren.h>
#include "wray_internal.h"
#include <raylib.h>

void wray_InitAudioDevice(WrenVM *vm)
{
  InitAudioDevice();
}

void wray_CloseAudioDevice(WrenVM *vm)
{
  CloseAudioDevice();
}

void wray_IsAudioDeviceReady_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, IsAudioDeviceReady());
}

void wray_MasterVolume_set(WrenVM *vm)
{
  SetMasterVolume(wrenGetSlotDouble(vm, 1));
}

void wray_StopSoundMulti(WrenVM *vm)
{
  StopSoundMulti();
}

void wray_SoundsPlaying_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetSoundsPlaying());
}

static void wray_sound_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Sound));
}

static void wray_sound_finalize(void *ptr)
{
  if (IsAudioDeviceReady())
    UnloadSound(*(Sound *)ptr);
}

static void wray_sound_new(WrenVM *vm)
{
  Sound *sound = wrenGetSlotForeign(vm, 0);

  if (wrenGetSlotType(vm, 1) == WREN_TYPE_STRING) {
    /* Load from path */
    *sound = LoadSound(wrenGetSlotString(vm, 1));
  } else {
    /* Load from wave */
    NYI
    /*
    wray_CheckForeignType(vm, 1, "Wave");
    *sound = LoadSoundFromWave(*(Wave *)wrenGetSlotForeign(vm, 1));
    */
  }
}

static void wray_sound_play(WrenVM *vm)
{
  PlaySound(*(Sound *)wrenGetSlotForeign(vm, 0));
}

static void wray_sound_stop(WrenVM *vm)
{
  StopSound(*(Sound *)wrenGetSlotForeign(vm, 0));
}

static void wray_sound_pause(WrenVM *vm)
{
  PauseSound(*(Sound *)wrenGetSlotForeign(vm, 0));
}

static void wray_sound_resume(WrenVM *vm)
{
  ResumeSound(*(Sound *)wrenGetSlotForeign(vm, 0));
}

static void wray_sound_play_multi(WrenVM *vm)
{
  PlaySoundMulti(*(Sound *)wrenGetSlotForeign(vm, 0));
}

static void wray_sound_playing_get(WrenVM *vm)
{
  Sound sound = *(Sound *)wrenGetSlotForeign(vm, 0);

  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, IsSoundPlaying(sound));
}

static void wray_sound_volume_set(WrenVM *vm)
{
  Sound sound = *(Sound *)wrenGetSlotForeign(vm, 0);
  SetSoundVolume(sound, wrenGetSlotDouble(vm, 1));
}

static void wray_sound_pitch_set(WrenVM *vm)
{
  Sound sound = *(Sound *)wrenGetSlotForeign(vm, 0);
  SetSoundPitch(sound, wrenGetSlotDouble(vm, 1));
}

const wray_binding_class wray_sound_class = {
  "Sound", { wray_sound_initialize, wray_sound_finalize }, {
    { wray_sound_new, false, "init new(_)" },
    { wray_sound_play, false, "play()" },
    { wray_sound_stop, false, "stop()" },
    { wray_sound_pause, false, "pause()" },
    { wray_sound_resume, false, "resume()" },
    { wray_sound_play_multi, false, "playMulti()" },
    { wray_sound_playing_get, false, "playing" },
    { wray_sound_volume_set, false, "volume=(_)" },
    { wray_sound_pitch_set, false, "pitch=(_)" },
    { NULL, NULL, NULL }
  }
};

static void wray_music_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Music));
}

static void wray_music_finalize(void *ptr)
{
  if (IsAudioDeviceReady())
    UnloadMusicStream(*(Music *)ptr);
}

static void wray_music_new(WrenVM *vm)
{
  Music *music = wrenGetSlotForeign(vm, 0);
  *music = LoadMusicStream(wrenGetSlotString(vm, 1));
}

static void wray_music_update(WrenVM *vm)
{
  UpdateMusicStream(*(Music *)wrenGetSlotForeign(vm, 0));
}

static void wray_music_play(WrenVM *vm)
{
  PlayMusicStream(*(Music *)wrenGetSlotForeign(vm, 0));
}

static void wray_music_stop(WrenVM *vm)
{
  StopMusicStream(*(Music *)wrenGetSlotForeign(vm, 0));
}

static void wray_music_pause(WrenVM *vm)
{
  PauseMusicStream(*(Music *)wrenGetSlotForeign(vm, 0));
}

static void wray_music_resume(WrenVM *vm)
{
  ResumeMusicStream(*(Music *)wrenGetSlotForeign(vm, 0));
}

static void wray_music_playing_get(WrenVM *vm)
{
  Music music = *(Music *)wrenGetSlotForeign(vm, 0);

  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, IsMusicStreamPlaying(music));
}

static void wray_music_volume_set(WrenVM *vm)
{
  Music music = *(Music *)wrenGetSlotForeign(vm, 0);
  SetMusicVolume(music, wrenGetSlotDouble(vm, 1));
}

static void wray_music_pitch_set(WrenVM *vm)
{
  Music music = *(Music *)wrenGetSlotForeign(vm, 0);
  SetMusicPitch(music, wrenGetSlotDouble(vm, 1));
}

static void wray_music_length_get(WrenVM *vm)
{
  Music music = *(Music *)wrenGetSlotForeign(vm, 0);

  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, GetMusicTimeLength(music));
}

static void wray_music_played_get(WrenVM *vm)
{
  Music music = *(Music *)wrenGetSlotForeign(vm, 0);

  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, GetMusicTimePlayed(music));
}


const wray_binding_class wray_music_class = {
  "Music", { wray_music_initialize, wray_music_finalize }, {
    { wray_music_new, false, "init new(_)" },
    { wray_music_update, false, "update()" },
    { wray_music_play, false, "play()" },
    { wray_music_stop, false, "stop()" },
    { wray_music_pause, false, "pause()" },
    { wray_music_resume, false, "resume()" },
    { wray_music_playing_get, false, "playing" },
    { wray_music_volume_set, false, "volume=(_)" },
    { wray_music_pitch_set, false, "pitch=(_)" },
    { wray_music_length_get, false, "length" },
    { wray_music_played_get, false, "played" },
    { NULL, NULL, NULL }
  }
};

