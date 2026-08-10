.section .rodata

.include "asm/macros/m4a.inc"
.include "asm/macros/music_voice.inc"

@ Note, this appears identical to rs_drumset in pokeemerald
voice_group gUnknown_0852DBAC, 36
	voice_directsound_no_resample 60, 64, gDirectSound_08535870, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08535D10, 255, 0, 255, 242
	voice_directsound_no_resample 60, 64, gDirectSound_08536404, 255, 255, 255, 127
	voice_directsound_no_resample 60, 64, gDirectSound_08536C94, 255, 0, 255, 242
	voice_directsound 48, 44, gDirectSound_0853750C, 255, 210, 77, 204
	voice_directsound_no_resample 60, 79, gDirectSound_0853854C, 255, 127, 0, 188
	voice_directsound 51, 49, gDirectSound_0853750C, 255, 216, 77, 204
	voice_directsound_no_resample 60, 79, gDirectSound_0853854C, 255, 127, 0, 188
	voice_directsound 54, 59, gDirectSound_0853750C, 255, 216, 77, 204
	voice_directsound_no_resample 60, 79, gDirectSound_08538960, 255, 242, 141, 0
	voice_directsound 57, 69, gDirectSound_0853750C, 255, 210, 77, 204
	voice_directsound 60, 79, gDirectSound_0853750C, 255, 204, 77, 204
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 255, 246, 0, 216
	voice_directsound 62, 84, gDirectSound_0853750C, 255, 204, 77, 204
	voice_directsound_no_resample 70, 49, gDirectSound_0853A6BC, 255, 165, 103, 231
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 70, 49, gDirectSound_0853A6BC, 255, 165, 103, 231
	voice_directsound_no_resample 32, 34, gDirectSound_0853B650, 255, 127, 77, 204
	voice_directsound_no_resample 60, 14, gDirectSound_0853BF04, 255, 235, 0, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 255, 246, 0, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 255, 246, 0, 216
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 8, 0, 255, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 104, gDirectSound_0853C7E8, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 94, gDirectSound_0853CD00, 255, 0, 255, 0

gUnknown_0852DD08:: @ 0x0852DD08
	voice_directsound 60, 0, gDirectSound_0853D2C8, 255, 252, 0, 239
	voice_directsound 60, 0, gDirectSound_0853E228, 255, 250, 0, 221
	voice_directsound 60, 0, gDirectSound_0853F888, 255, 250, 0, 221
	voice_directsound 60, 0, gDirectSound_08540DE4, 255, 247, 0, 221

gUnknown_0852DD38:: @ 0x0852DD38
	voice_directsound 60, 0, gDirectSound_08541970, 255, 0, 255, 196
	voice_directsound 60, 0, gDirectSound_08544F14, 255, 0, 255, 196
	voice_directsound 60, 0, gDirectSound_08547230, 255, 0, 255, 196

gUnknown_0852DD5C:: @ 0x0852DD5C
	voice_directsound 60, 0, gDirectSound_0854A8FC, 255, 0, 193, 127
	voice_directsound 60, 0, gDirectSound_0854BC4C, 255, 0, 193, 127
	voice_directsound 60, 0, gDirectSound_0854D15C, 255, 0, 193, 127

gUnknown_0852DD80:: @ 0x0852DD80
	voice_directsound 60, 0, gDirectSound_0854E57C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0854F618, 255, 0, 255, 165

gUnknown_0852DD98:: @ 0x0852DD98
	voice_directsound 60, 0, gDirectSound_08550674, 255, 0, 224, 165
	voice_directsound 60, 0, gDirectSound_08557608, 255, 0, 218, 165

gUnknown_0852DDB0:: @ 0x0852DDB0
	voice_directsound 60, 0, gDirectSound_0853D2C8, 255, 252, 0, 252
	voice_directsound 60, 0, gDirectSound_0853E228, 255, 250, 0, 250
	voice_directsound 60, 0, gDirectSound_0853F888, 255, 250, 0, 250
	voice_directsound 60, 0, gDirectSound_08540DE4, 255, 247, 0, 247

gUnknown_0852DDE0:: @ 0x0852DDE0
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_directsound 60, 0, gDirectSound_085715B0, 255, 178, 180, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 165, 51, 235
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 242, 0, 204
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 1, 7, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 7, 1
	voice_square_2_alt 60, 0, 3, 0, 1, 7, 1
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 7, 1
	voice_square_2_alt 60, 0, 2, 0, 1, 4, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 2
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 15, 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 29, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 22, 2, 0, 2, 0, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08535870, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08535D10, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08536C94, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 32, 74, gDirectSound_0853B650, 255, 127, 77, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 66, gDirectSound_0853C7E8, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 62, gDirectSound_0853CD00, 255, 0, 255, 0

gUnknown_0852E404:: @ 0x0852E404
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 1, 9, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 9, 0
	voice_square_2_alt 60, 0, 3, 0, 1, 7, 0
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 64, gDirectSound_08536C94, 255, 0, 255, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 32, 49, gDirectSound_0853B650, 255, 127, 77, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 8, 0, 255, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 30, 54, gDirectSound_08539790, 255, 246, 0, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 79, gDirectSound_0853C7E8, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 72, 74, gDirectSound_0853CD00, 255, 0, 255, 0

gUnknown_0852E95C:: @ 0x0852E95C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0852EF5C:: @ 0x0852EF5C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 165, 90, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857358C, 255, 253, 0, 188
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 2, 3, 1
	voice_square_2_alt 60, 0, 2, 0, 2, 3, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D44, 0, 7, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0852F55C:: @ 0x0852F55C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857358C, 255, 253, 0, 188
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 242, 51, 242
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 0, 180, 246
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 2, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D44, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 2, 4, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0852FB5C:: @ 0x0852FB5C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 128, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857F80C, 255, 235, 128, 99
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 242, 0, 242
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D94, 0, 7, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0853015C:: @ 0x0853015C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 165, 72, 249
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 165, 90, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 128, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 0, 180, 246
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 0, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0853075C:: @ 0x0853075C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D84, 0, 7, 15, 3
	voice_square_2_alt 60, 0, 3, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_08530D5C:: @ 0x08530D5C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 76
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534DB4, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857F80C, 255, 235, 128, 99
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 0, 180, 246
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 1, 4, 1
	voice_square_1_alt 60, 0, 0, 2, 1, 1, 4, 1
	voice_square_2_alt 60, 0, 2, 1, 1, 4, 1
	voice_square_2_alt 60, 0, 1, 0, 1, 4, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_programmable_wave_alt 60, 0, gUnknown_08534D34, 0, 7, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 7, 1
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0

gUnknown_0853135C:: @ 0x0853135C
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 2, 0, 2, 3, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2 60, 0, 3, 0, 1, 7, 1
	voice_programmable_wave_alt 60, 0, gUnknown_08534D54, 0, 7, 15, 2
	voice_square_1 60, 0, 0, 3, 0, 1, 7, 1
	voice_square_1 60, 0, 0, 3, 0, 0, 7, 1

gUnknown_0853174C:: @ 0x0853174C
	voice_directsound 60, 0, gDirectSound_0855F22C, 255, 249, 103, 165
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 2, 0, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 4, 0, 1
	voice_square_1_alt 60, 0, 44, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 38, 0, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 7, 0, 0
	voice_square_1_alt 60, 0, 0, 2, 2, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 2, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 1, 0, 1, 9, 0
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 226, 0, 165
	voice_square_1_alt 60, 0, 0, 2, 0, 6, 0, 1
	voice_square_1_alt 60, 0, 36, 0, 0, 2, 0, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 3, 0, 1, 0, 1
	voice_square_1_alt 60, 0, 0, 3, 0, 1, 0, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 46, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 38, 2, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 119, 2, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 106, 2, 0, 2, 0, 0
	voice_square_1_alt 60, 0, 23, 2, 0, 1, 9, 0
	voice_square_1_alt 60, 0, 21, 2, 0, 1, 9, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 0, 15, 1
	voice_square_1_alt 60, 0, 47, 2, 0, 2, 6, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise 60, 0, 0, 0, 7, 15, 0
	voice_noise 60, 0, 0, 2, 7, 15, 0
	voice_noise_alt 60, 0, 0, 2, 0, 15, 0
	voice_noise_alt 60, 0, 1, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 2, 0, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 1

gUnknown_08531D4C:: @ 0x08531D4C
	voice_directsound_no_resample 60, 0, gDirectSound_08562D1C, 255, 249, 0, 165
	voice_directsound_alt 60, 0, gDirectSound_08562D1C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0855F22C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 242, 0, 127
	voice_noise_alt 60, 0, 0, 0, 1, 0, 1
	voice_noise_alt 60, 0, 1, 0, 1, 0, 1
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 0, 255, 165
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 1
	voice_directsound 60, 0, gDirectSound_08564D20, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_085661E4, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08566920, 255, 0, 255, 127
	voice_noise_alt 60, 0, 1, 0, 2, 0, 0
	voice_square_1 60, 0, 103, 3, 2, 7, 0, 0
	voice_square_2 60, 0, 3, 2, 7, 0, 0
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 226, 0, 127
	voice_directsound 60, 0, gDirectSound_08568510, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 204, 0, 127
	voice_square_1_alt 60, 0, 0, 2, 0, 2, 0, 1
	voice_directsound 60, 0, gDirectSound_085698C4, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0855FC38, 255, 0, 255, 127
	voice_square_1 60, 0, 103, 0, 0, 7, 0, 0
	voice_directsound 60, 0, gDirectSound_08536C94, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0856BF48, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0856D18C, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08535D10, 255, 0, 255, 127
	voice_noise_alt 60, 0, 0, 0, 7, 15, 1
	voice_directsound 60, 0, gDirectSound_0856E19C, 255, 0, 255, 127
	voice_noise_alt 60, 0, 1, 0, 7, 15, 1
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 246, 0, 127
	voice_directsound 60, 0, gDirectSound_0856F4A4, 255, 0, 255, 127
	voice_square_1_alt 60, 0, 19, 2, 0, 2, 0, 0
	voice_directsound 60, 0, gDirectSound_085715B0, 255, 0, 255, 127
	voice_square_1 60, 0, 103, 0, 0, 0, 15, 0
	voice_directsound_alt 60, 0, gDirectSound_0856F4A4, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0857358C, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08574158, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08574DCC, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085715B0, 255, 242, 0, 0
	voice_directsound 60, 0, gDirectSound_08576FDC, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 165, 90, 216
	voice_directsound 60, 0, gDirectSound_0853854C, 255, 127, 0, 188
	voice_directsound 60, 0, gDirectSound_08579118, 255, 249, 0, 165
	voice_square_1 60, 0, 0, 0, 4, 6, 0, 0
	voice_directsound 60, 0, gDirectSound_0856467C, 13, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085777A8, 13, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0857B0C8, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 252, 0, 204
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_square_1 60, 0, 0, 0, 4, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 188, 0, 0
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 226, 0, 127
	voice_directsound 60, 0, gDirectSound_08539790, 26, 0, 255, 127
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 0, 0
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 252, 0, 127
	voice_square_1_alt 60, 0, 0, 1, 0, 2, 0, 0
	voice_directsound 60, 0, gDirectSound_085661E4, 255, 127, 0, 127
	voice_noise_alt 60, 0, 0, 1, 6, 0, 0
	voice_directsound 60, 0, gDirectSound_0857F80C, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08536404, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08580744, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08557608, 11, 242, 0, 127
	voice_square_1_alt 60, 0, 0, 2, 4, 6, 0, 0
	voice_directsound 60, 0, gDirectSound_08582284, 255, 255, 255, 127
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_0853750C, 255, 0, 255, 165
	voice_noise_alt 60, 0, 0, 5, 7, 15, 1
	voice_directsound 60, 0, gDirectSound_0855FC38, 128, 242, 0, 165
	voice_directsound 60, 0, gDirectSound_08544F14, 255, 0, 255, 165
	voice_square_1 60, 0, 0, 0, 1, 5, 0, 0
	voice_noise_alt 60, 0, 0, 6, 6, 0, 1
	voice_noise_alt 60, 0, 0, 3, 6, 0, 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_085715B0, 15, 127, 231, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08583F1C, 255, 0, 255, 165

gUnknown_08532310:: @ 0x08532310
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 1, 0, 15, 0
	voice_noise_alt 60, 0, 0, 1, 3, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 0, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 3, 0, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 31, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 31, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 23, 1, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 55, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 0, 0, 4, 0, 0
	voice_square_1_alt 60, 0, 21, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 1, 0, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 63, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 103, 0, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 1, 1, 0, 15, 0
	voice_square_1_alt 60, 0, 103, 0, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_08584B2C, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_08588238, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_08588C10, 255, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_0856BF48, 64, 0, 255, 0
	voice_directsound 60, 0, gDirectSound_0858AA14, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_0858E078
	voice_directsound_compressed gDirectSound_pika_08595C7C
	voice_directsound_compressed gDirectSound_08597170
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed gDirectSound_0859BD58

gUnknown_08532808:: @ 0x08532808
	voice_keysplit_all voicegroup_gUnknown_0852DBAC
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_keysplit gUnknown_0852DDB0, keysplit_gUnknown_08534BC0
	voice_keysplit gUnknown_0852DD08, keysplit_gUnknown_08534BC0
	voice_directsound 60, 0, gDirectSound_085A37F4, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 210
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 165, 51, 235
	voice_directsound 60, 0, gDirectSound_0856467C, 255, 165, 51, 235
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_directsound 60, 0, gDirectSound_085A4FE4, 255, 241, 0, 210
	voice_directsound 60, 0, gDirectSound_0857EDD8, 255, 235, 0, 204
	voice_directsound 60, 0, gDirectSound_085777A8, 255, 216, 90, 242
	voice_directsound 60, 0, gDirectSound_0855EA58, 255, 241, 0, 232
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0855C2F0, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A5934, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_08582B4C, 255, 0, 255, 165
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_0855CAE8, 255, 249, 25, 149
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 248, 0, 127
	voice_directsound 60, 0, gDirectSound_085A3DF4, 255, 210, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, gDirectSound_085A45E0, 255, 252, 0, 127
	voice_directsound 60, 0, gDirectSound_0857358C, 255, 253, 0, 149
	voice_directsound 60, 0, gDirectSound_085A611C, 255, 253, 0, 149
	voice_directsound 60, 0, gDirectSound_085A7D6C, 255, 253, 0, 127
	voice_directsound 60, 0, gDirectSound_085A7D6C, 255, 253, 0, 127
	voice_directsound 60, 0, gDirectSound_0857F80C, 255, 235, 128, 115
	voice_directsound 60, 0, gDirectSound_085715B0, 255, 178, 180, 165
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_directsound 60, 0, gDirectSound_08574158, 255, 252, 0, 115
	voice_directsound 60, 0, gDirectSound_085A7EDC, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A7EDC, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8470, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8470, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_directsound 60, 0, gDirectSound_085661E4, 255, 216, 0, 165
	voice_directsound 60, 0, gDirectSound_0857E3A8, 255, 242, 0, 204
	voice_directsound 60, 0, gDirectSound_0856184C, 255, 246, 0, 226
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_keysplit gUnknown_0852DD38, keysplit_gUnknown_08534C08
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_directsound 60, 0, gDirectSound_085A9EA4, 255, 0, 255, 127
	voice_keysplit gUnknown_0852DD80, keysplit_gUnknown_08534C98
	voice_directsound 60, 0, gDirectSound_085A9EA4, 255, 210, 0, 127
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_keysplit gUnknown_0852DD5C, keysplit_gUnknown_08534C50
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA074, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085AA274, 128, 0, 255, 127
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_keysplit gUnknown_0852DD98, keysplit_gUnknown_08534CEC
	voice_directsound 60, 0, gDirectSound_085A9C78, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_085ABE38, 255, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_0855BB8C, 255, 127, 231, 127
	voice_directsound 60, 0, gDirectSound_085AA274, 128, 0, 255, 127
	voice_directsound 60, 0, gDirectSound_085A8788, 255, 0, 255, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, gDirectSound_085A5A74, 255, 241, 0, 127
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 0, gDirectSound_08539790, 255, 249, 0, 249
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_no_resample 60, 0, gDirectSound_0853854C, 255, 89, 0, 89

gPokemonCryToneBank0:: @ 0x08532D6C
	voice_directsound_compressed gDirectSound_Cry_Bulbasaur
	voice_directsound_compressed gDirectSound_Cry_Ivysaur
	voice_directsound_compressed gDirectSound_Cry_003
	voice_directsound_compressed gDirectSound_Cry_004
	voice_directsound_compressed gDirectSound_Cry_005
	voice_directsound_compressed gDirectSound_Cry_006
	voice_directsound_compressed gDirectSound_Cry_007
	voice_directsound_compressed gDirectSound_Cry_008
	voice_directsound_compressed gDirectSound_Cry_009
	voice_directsound_compressed gDirectSound_Cry_010
	voice_directsound_compressed gDirectSound_Cry_011
	voice_directsound_compressed gDirectSound_Cry_012
	voice_directsound_compressed gDirectSound_Cry_013
	voice_directsound_compressed gDirectSound_Cry_014
	voice_directsound_compressed gDirectSound_Cry_015
	voice_directsound_compressed gDirectSound_Cry_016
	voice_directsound_compressed gDirectSound_Cry_017
	voice_directsound_compressed gDirectSound_Cry_018
	voice_directsound_compressed gDirectSound_Cry_019
	voice_directsound_compressed gDirectSound_Cry_020
	voice_directsound_compressed gDirectSound_Cry_021
	voice_directsound_compressed gDirectSound_Cry_022
	voice_directsound_compressed gDirectSound_Cry_023
	voice_directsound_compressed gDirectSound_Cry_024
	voice_directsound_compressed gDirectSound_085ABF3C
	voice_directsound_compressed gDirectSound_085ACFE4
	voice_directsound_compressed gDirectSound_085AE7A4
	voice_directsound_compressed gDirectSound_085AF0F8
	voice_directsound_compressed gDirectSound_Cry_029
	voice_directsound_compressed gDirectSound_Cry_030
	voice_directsound_compressed gDirectSound_Cry_031
	voice_directsound_compressed gDirectSound_Cry_032
	voice_directsound_compressed gDirectSound_Cry_033
	voice_directsound_compressed gDirectSound_Cry_034
	voice_directsound_compressed gDirectSound_Cry_035
	voice_directsound_compressed gDirectSound_Cry_036
	voice_directsound_compressed gDirectSound_085AFE88
	voice_directsound_compressed gDirectSound_085B1658
	voice_directsound_compressed gDirectSound_085B2EC4
	voice_directsound_compressed gDirectSound_085B3428
	voice_directsound_compressed gDirectSound_085B3AF0
	voice_directsound_compressed gDirectSound_085B4E5C
	voice_directsound_compressed gDirectSound_085B61C0
	voice_directsound_compressed gDirectSound_085B705C
	voice_directsound_compressed gDirectSound_085B7CD8
	voice_directsound_compressed gDirectSound_Cry_046
	voice_directsound_compressed gDirectSound_Cry_047
	voice_directsound_compressed gDirectSound_Cry_048
	voice_directsound_compressed gDirectSound_Cry_049
	voice_directsound_compressed gDirectSound_Cry_050
	voice_directsound_compressed gDirectSound_Cry_051
	voice_directsound_compressed gDirectSound_Cry_052
	voice_directsound_compressed gDirectSound_Cry_053
	voice_directsound_compressed gDirectSound_085B9674
	voice_directsound_compressed gDirectSound_085BA39C
	voice_directsound_compressed gDirectSound_Cry_056
	voice_directsound_compressed gDirectSound_Cry_057
	voice_directsound_compressed gDirectSound_Cry_058
	voice_directsound_compressed gDirectSound_Cry_059
	voice_directsound_compressed gDirectSound_Cry_060
	voice_directsound_compressed gDirectSound_Cry_061
	voice_directsound_compressed gDirectSound_Cry_062
	voice_directsound_compressed gDirectSound_085BAEE4
	voice_directsound_compressed gDirectSound_085BC648
	voice_directsound_compressed gDirectSound_085BE130
	voice_directsound_compressed gDirectSound_085C00CC
	voice_directsound_compressed gDirectSound_085C0E30
	voice_directsound_compressed gDirectSound_085C1BC0
	voice_directsound_compressed gDirectSound_Cry_069
	voice_directsound_compressed gDirectSound_Cry_070
	voice_directsound_compressed gDirectSound_Cry_071
	voice_directsound_compressed gDirectSound_085C2C48
	voice_directsound_compressed gDirectSound_085C3C38
	voice_directsound_compressed gDirectSound_085C5334
	voice_directsound_compressed gDirectSound_085C6AE8
	voice_directsound_compressed gDirectSound_085C86D0
	voice_directsound_compressed gDirectSound_Cry_077
	voice_directsound_compressed gDirectSound_Cry_078
	voice_directsound_compressed gDirectSound_Cry_079
	voice_directsound_compressed gDirectSound_Cry_080
	voice_directsound_compressed gDirectSound_085C94FC
	voice_directsound_compressed gDirectSound_085CA840
	voice_directsound_compressed gDirectSound_Cry_083
	voice_directsound_compressed gDirectSound_085CC028
	voice_directsound_compressed gDirectSound_085CD36C
	voice_directsound_compressed gDirectSound_Cry_086
	voice_directsound_compressed gDirectSound_Cry_087
	voice_directsound_compressed gDirectSound_085CE6E4
	voice_directsound_compressed gDirectSound_085CF16C
	voice_directsound_compressed gDirectSound_Cry_090
	voice_directsound_compressed gDirectSound_Cry_091
	voice_directsound_compressed gDirectSound_Cry_092
	voice_directsound_compressed gDirectSound_Cry_093
	voice_directsound_compressed gDirectSound_Cry_094
	voice_directsound_compressed gDirectSound_Cry_095
	voice_directsound_compressed gDirectSound_Cry_096
	voice_directsound_compressed gDirectSound_Cry_097
	voice_directsound_compressed gDirectSound_Cry_098
	voice_directsound_compressed gDirectSound_Cry_099
	voice_directsound_compressed gDirectSound_085D002C
	voice_directsound_compressed gDirectSound_085D18F0
	voice_directsound_compressed gDirectSound_Cry_102
	voice_directsound_compressed gDirectSound_Cry_103
	voice_directsound_compressed gDirectSound_Cry_104
	voice_directsound_compressed gDirectSound_Cry_105
	voice_directsound_compressed gDirectSound_Cry_106
	voice_directsound_compressed gDirectSound_Cry_107
	voice_directsound_compressed gDirectSound_Cry_108
	voice_directsound_compressed gDirectSound_085D3228
	voice_directsound_compressed gDirectSound_085D4684
	voice_directsound_compressed gDirectSound_085D5C30
	voice_directsound_compressed gDirectSound_085D6F9C
	voice_directsound_compressed gDirectSound_Cry_113
	voice_directsound_compressed gDirectSound_Cry_114
	voice_directsound_compressed gDirectSound_Cry_115
	voice_directsound_compressed gDirectSound_085D8408
	voice_directsound_compressed gDirectSound_085D8D84
	voice_directsound_compressed gDirectSound_085D95F0
	voice_directsound_compressed gDirectSound_085D9FC8
	voice_directsound_compressed gDirectSound_085DB320
	voice_directsound_compressed gDirectSound_085DC708
	voice_directsound_compressed gDirectSound_Cry_122
	voice_directsound_compressed gDirectSound_Cry_123
	voice_directsound_compressed gDirectSound_Cry_124
	voice_directsound_compressed gDirectSound_Cry_125
	voice_directsound_compressed gDirectSound_Cry_126
	voice_directsound_compressed gDirectSound_085DDBE4

gPokemonCryToneBank1:: @ 0x08533360
	voice_directsound_compressed gDirectSound_085DE840
	voice_directsound_compressed gDirectSound_085DFB48
	voice_directsound_compressed gDirectSound_Cry_131
	voice_directsound_compressed gDirectSound_Cry_132
	voice_directsound_compressed gDirectSound_Cry_133
	voice_directsound_compressed gDirectSound_Cry_134
	voice_directsound_compressed gDirectSound_Cry_135
	voice_directsound_compressed gDirectSound_Cry_136
	voice_directsound_compressed gDirectSound_Cry_137
	voice_directsound_compressed gDirectSound_Cry_138
	voice_directsound_compressed gDirectSound_Cry_139
	voice_directsound_compressed gDirectSound_Cry_140
	voice_directsound_compressed gDirectSound_Cry_141
	voice_directsound_compressed gDirectSound_085E0F7C
	voice_directsound_compressed gDirectSound_Cry_143
	voice_directsound_compressed gDirectSound_Cry_144
	voice_directsound_compressed gDirectSound_Cry_145
	voice_directsound_compressed gDirectSound_Cry_146
	voice_directsound_compressed gDirectSound_Cry_147
	voice_directsound_compressed gDirectSound_Cry_148
	voice_directsound_compressed gDirectSound_Cry_149
	voice_directsound_compressed gDirectSound_Cry_150
	voice_directsound_compressed gDirectSound_Cry_151
	voice_directsound_compressed gDirectSound_085E27D8
	voice_directsound_compressed gDirectSound_085E2D18
	voice_directsound_compressed gDirectSound_085E35E4
	voice_directsound_compressed gDirectSound_085E461C
	voice_directsound_compressed gDirectSound_085E4D20
	voice_directsound_compressed gDirectSound_085E5908
	voice_directsound_compressed gDirectSound_085E7F18
	voice_directsound_compressed gDirectSound_085E9170
	voice_directsound_compressed gDirectSound_085EA5AC
	voice_directsound_compressed gDirectSound_Cry_161
	voice_directsound_compressed gDirectSound_Cry_162
	voice_directsound_compressed gDirectSound_Cry_163
	voice_directsound_compressed gDirectSound_Cry_164
	voice_directsound_compressed gDirectSound_Cry_165
	voice_directsound_compressed gDirectSound_Cry_166
	voice_directsound_compressed gDirectSound_Cry_167
	voice_directsound_compressed gDirectSound_Cry_168
	voice_directsound_compressed gDirectSound_085EBF30
	voice_directsound_compressed gDirectSound_085ED660
	voice_directsound_compressed gDirectSound_085EE310
	voice_directsound_compressed gDirectSound_085EED9C
	voice_directsound_compressed gDirectSound_Cry_173
	voice_directsound_compressed gDirectSound_085EF4F0
	voice_directsound_compressed gDirectSound_Cry_175
	voice_directsound_compressed gDirectSound_Cry_176
	voice_directsound_compressed gDirectSound_085EFBEC
	voice_directsound_compressed gDirectSound_085F067C
	voice_directsound_compressed gDirectSound_Cry_179
	voice_directsound_compressed gDirectSound_Cry_180
	voice_directsound_compressed gDirectSound_Cry_181
	voice_directsound_compressed gDirectSound_085F1548
	voice_directsound_compressed gDirectSound_085F2360
	voice_directsound_compressed gDirectSound_085F3074
	voice_directsound_compressed gDirectSound_Cry_185
	voice_directsound_compressed gDirectSound_Cry_186
	voice_directsound_compressed gDirectSound_Cry_187
	voice_directsound_compressed gDirectSound_Cry_188
	voice_directsound_compressed gDirectSound_Cry_189
	voice_directsound_compressed gDirectSound_Cry_190
	voice_directsound_compressed gDirectSound_Cry_191
	voice_directsound_compressed gDirectSound_Cry_192
	voice_directsound_compressed gDirectSound_Cry_193
	voice_directsound_compressed gDirectSound_Cry_194
	voice_directsound_compressed gDirectSound_Cry_195
	voice_directsound_compressed gDirectSound_Cry_196
	voice_directsound_compressed gDirectSound_Cry_197
	voice_directsound_compressed gDirectSound_Cry_198
	voice_directsound_compressed gDirectSound_Cry_199
	voice_directsound_compressed gDirectSound_Cry_200
	voice_directsound_compressed gDirectSound_Cry_201
	voice_directsound_compressed gDirectSound_085F4160
	voice_directsound_compressed gDirectSound_085F55FC
	voice_directsound_compressed gDirectSound_Cry_204
	voice_directsound_compressed gDirectSound_Cry_205
	voice_directsound_compressed gDirectSound_Cry_206
	voice_directsound_compressed gDirectSound_Cry_207
	voice_directsound_compressed gDirectSound_Cry_208
	voice_directsound_compressed gDirectSound_Cry_209
	voice_directsound_compressed gDirectSound_Cry_210
	voice_directsound_compressed gDirectSound_Cry_211
	voice_directsound_compressed gDirectSound_Cry_212
	voice_directsound_compressed gDirectSound_Cry_213
	voice_directsound_compressed gDirectSound_085F64B0
	voice_directsound_compressed gDirectSound_Cry_215
	voice_directsound_compressed gDirectSound_Cry_216
	voice_directsound_compressed gDirectSound_Cry_217
	voice_directsound_compressed gDirectSound_085F7704
	voice_directsound_compressed gDirectSound_085F881C
	voice_directsound_compressed gDirectSound_Cry_220
	voice_directsound_compressed gDirectSound_Cry_221
	voice_directsound_compressed gDirectSound_085F9D24
	voice_directsound_compressed gDirectSound_Cry_223
	voice_directsound_compressed gDirectSound_Cry_224
	voice_directsound_compressed gDirectSound_Cry_225
	voice_directsound_compressed gDirectSound_Cry_226
	voice_directsound_compressed gDirectSound_085FAA04
	voice_directsound_compressed gDirectSound_Cry_228
	voice_directsound_compressed gDirectSound_Cry_229
	voice_directsound_compressed gDirectSound_085FC20C
	voice_directsound_compressed gDirectSound_085FCFE4
	voice_directsound_compressed gDirectSound_085FDB34
	voice_directsound_compressed gDirectSound_Cry_233
	voice_directsound_compressed gDirectSound_Cry_234
	voice_directsound_compressed gDirectSound_Cry_235
	voice_directsound_compressed gDirectSound_Cry_236
	voice_directsound_compressed gDirectSound_Cry_237
	voice_directsound_compressed gDirectSound_Cry_238
	voice_directsound_compressed gDirectSound_Cry_239
	voice_directsound_compressed gDirectSound_Cry_240
	voice_directsound_compressed gDirectSound_Cry_241
	voice_directsound_compressed gDirectSound_Cry_242
	voice_directsound_compressed gDirectSound_Cry_243
	voice_directsound_compressed gDirectSound_Cry_244
	voice_directsound_compressed gDirectSound_Cry_245
	voice_directsound_compressed gDirectSound_Cry_246
	voice_directsound_compressed gDirectSound_Cry_247
	voice_directsound_compressed gDirectSound_Cry_248
	voice_directsound_compressed gDirectSound_Cry_249
	voice_directsound_compressed gDirectSound_Cry_250
	voice_directsound_compressed gDirectSound_085FEC58
	voice_directsound_compressed gDirectSound_085FFAD0
	voice_directsound_compressed gDirectSound_08600330
	voice_directsound_compressed gDirectSound_08600DF0
	voice_directsound_compressed gDirectSound_0860173C
	voice_directsound_compressed gDirectSound_08602398

gPokemonCryToneBank2:: @ 0x08533960
	voice_directsound_compressed gDirectSound_086038A0
	voice_directsound_compressed gDirectSound_08604338
	voice_directsound_compressed gDirectSound_08604F68
	voice_directsound_compressed gDirectSound_08605D48
	voice_directsound_compressed gDirectSound_086068E8
	voice_directsound_compressed gDirectSound_08607FF4
	voice_directsound_compressed gDirectSound_08608984
	voice_directsound_compressed gDirectSound_086093EC
	voice_directsound_compressed gDirectSound_08609984
	voice_directsound_compressed gDirectSound_0860A4A0
	voice_directsound_compressed gDirectSound_0860ADF4
	voice_directsound_compressed gDirectSound_0860B3F4
	voice_directsound_compressed gDirectSound_0860BCF8
	voice_directsound_compressed gDirectSound_0860CEA8
	voice_directsound_compressed gDirectSound_0860DB14
	voice_directsound_compressed gDirectSound_0860E4BC
	voice_directsound_compressed gDirectSound_08610190
	voice_directsound_compressed gDirectSound_08612110
	voice_directsound_compressed gDirectSound_08612CB8
	voice_directsound_compressed gDirectSound_0861412C
	voice_directsound_compressed gDirectSound_08615B48
	voice_directsound_compressed gDirectSound_086162CC
	voice_directsound_compressed gDirectSound_086173D0
	voice_directsound_compressed gDirectSound_08618A50
	voice_directsound_compressed gDirectSound_08619618
	voice_directsound_compressed gDirectSound_0861A258
	voice_directsound_compressed gDirectSound_0861AF00
	voice_directsound_compressed gDirectSound_0861B740
	voice_directsound_compressed gDirectSound_0861BBA8
	voice_directsound_compressed gDirectSound_0861CA3C
	voice_directsound_compressed gDirectSound_0861DB0C
	voice_directsound_compressed gDirectSound_0861E338
	voice_directsound_compressed gDirectSound_0861EEA0
	voice_directsound_compressed gDirectSound_08620264
	voice_directsound_compressed gDirectSound_08620C78
	voice_directsound_compressed gDirectSound_08621544
	voice_directsound_compressed gDirectSound_08622570
	voice_directsound_compressed gDirectSound_08622DA8
	voice_directsound_compressed gDirectSound_08623DEC
	voice_directsound_compressed gDirectSound_08624A98
	voice_directsound_compressed gDirectSound_086254B4
	voice_directsound_compressed gDirectSound_086260E4
	voice_directsound_compressed gDirectSound_08627948
	voice_directsound_compressed gDirectSound_086281CC
	voice_directsound_compressed gDirectSound_08629024
	voice_directsound_compressed gDirectSound_08629A10
	voice_directsound_compressed gDirectSound_0862A080
	voice_directsound_compressed gDirectSound_0862ACA8
	voice_directsound_compressed gDirectSound_0862B460
	voice_directsound_compressed gDirectSound_0862BBBC
	voice_directsound_compressed gDirectSound_0862CC74
	voice_directsound_compressed gDirectSound_0862D9D8
	voice_directsound_compressed gDirectSound_0862EEBC
	voice_directsound_compressed gDirectSound_0862F7B8
	voice_directsound_compressed gDirectSound_086307C0
	voice_directsound_compressed gDirectSound_08631240
	voice_directsound_compressed gDirectSound_086325F4
	voice_directsound_compressed gDirectSound_08632D08
	voice_directsound_compressed gDirectSound_08634220
	voice_directsound_compressed gDirectSound_08634A24
	voice_directsound_compressed gDirectSound_08635B84
	voice_directsound_compressed gDirectSound_086364D0
	voice_directsound_compressed gDirectSound_08637BF0
	voice_directsound_compressed gDirectSound_0863852C
	voice_directsound_compressed gDirectSound_08639628
	voice_directsound_compressed gDirectSound_0863A22C
	voice_directsound_compressed gDirectSound_0863BAE4
	voice_directsound_compressed gDirectSound_0863C224
	voice_directsound_compressed gDirectSound_0863CEC4
	voice_directsound_compressed gDirectSound_0863D8E8
	voice_directsound_compressed gDirectSound_0863E6EC
	voice_directsound_compressed gDirectSound_086400F4
	voice_directsound_compressed gDirectSound_086409E4
	voice_directsound_compressed gDirectSound_08642094
	voice_directsound_compressed gDirectSound_08642D18
	voice_directsound_compressed gDirectSound_08644078
	voice_directsound_compressed gDirectSound_08645874
	voice_directsound_compressed gDirectSound_086468A0
	voice_directsound_compressed gDirectSound_08647074
	voice_directsound_compressed gDirectSound_086497B8
	voice_directsound_compressed gDirectSound_0864A234
	voice_directsound_compressed gDirectSound_0864AA54
	voice_directsound_compressed gDirectSound_0864BAD8
	voice_directsound_compressed gDirectSound_0864C08C
	voice_directsound_compressed gDirectSound_0864CC64
	voice_directsound_compressed gDirectSound_0864F0B0
	voice_directsound_compressed gDirectSound_08650300
	voice_directsound_compressed gDirectSound_086512E8
	voice_directsound_compressed gDirectSound_08652954
	voice_directsound_compressed gDirectSound_086532FC
	voice_directsound_compressed gDirectSound_0865502C
	voice_directsound_compressed gDirectSound_08655BE4
	voice_directsound_compressed gDirectSound_086572B8
	voice_directsound_compressed gDirectSound_08657C58
	voice_directsound_compressed gDirectSound_08658F2C
	voice_directsound_compressed gDirectSound_0865B6A4
	voice_directsound_compressed gDirectSound_0865BE78
	voice_directsound_compressed gDirectSound_0865D280
	voice_directsound_compressed gDirectSound_0865F25C
	voice_directsound_compressed gDirectSound_0866125C
	voice_directsound_compressed gDirectSound_08662960
	voice_directsound_compressed gDirectSound_086635F8
	voice_directsound_compressed gDirectSound_08664180
	voice_directsound_compressed gDirectSound_08665298
	voice_directsound_compressed gDirectSound_08665BE0
	voice_directsound_compressed gDirectSound_08666F6C
	voice_directsound_compressed gDirectSound_08667D24
	voice_directsound_compressed gDirectSound_086688C8
	voice_directsound_compressed gDirectSound_08669448
	voice_directsound_compressed gDirectSound_08669D74
	voice_directsound_compressed gDirectSound_0866B24C
	voice_directsound_compressed gDirectSound_0866CBF0
	voice_directsound_compressed gDirectSound_0866E020
	voice_directsound_compressed gDirectSound_0866E4FC
	voice_directsound_compressed gDirectSound_08670A08
	voice_directsound_compressed gDirectSound_08672DC0
	voice_directsound_compressed gDirectSound_08674AEC
	voice_directsound_compressed gDirectSound_08676408
	voice_directsound_compressed gDirectSound_086770C8
	voice_directsound_compressed gDirectSound_086779A0
	voice_directsound_compressed gDirectSound_0867983C
	voice_directsound_compressed gDirectSound_0867B900
	voice_directsound_compressed gDirectSound_0867D560
	voice_directsound_compressed gDirectSound_0867E0F0
	voice_directsound_compressed gDirectSound_0867FD38
	voice_directsound_compressed gDirectSound_08680A60
	voice_directsound_compressed gDirectSound_08683470
	voice_directsound_compressed gDirectSound_08683C94

gPokemonCryToneBank3:: @ 0x08533F60
	voice_directsound_compressed gDirectSound_08684D9C
	voice_directsound_compressed gDirectSound_08686394
	voice_directsound_compressed gDirectSound_Cry_386
	voice_directsound_compressed gDirectSound_086885EC
	voice_directsound_compressed gDirectSound_Cry_387
	voice_directsound_compressed gDirectSound_Cry_388
	voice_directsound_compressed gDirectSound_Cry_389
	voice_directsound_compressed gDirectSound_Cry_390
	voice_directsound_compressed gDirectSound_Cry_391
	voice_directsound_compressed gDirectSound_Cry_392
	voice_directsound_compressed gDirectSound_Cry_393
	voice_directsound_compressed gDirectSound_Cry_394
	voice_directsound_compressed gDirectSound_Cry_395
	voice_directsound_compressed gDirectSound_Cry_396
	voice_directsound_compressed gDirectSound_Cry_397
	voice_directsound_compressed gDirectSound_Cry_398
	voice_directsound_compressed gDirectSound_Cry_399
	voice_directsound_compressed gDirectSound_Cry_400
	voice_directsound_compressed gDirectSound_Cry_401
	voice_directsound_compressed gDirectSound_Cry_402
	voice_directsound_compressed gDirectSound_Cry_403
	voice_directsound_compressed gDirectSound_Cry_404
	voice_directsound_compressed gDirectSound_Cry_405
	voice_directsound_compressed gDirectSound_Cry_406
	voice_directsound_compressed gDirectSound_Cry_407
	voice_directsound_compressed gDirectSound_Cry_408
	voice_directsound_compressed gDirectSound_Cry_409
	voice_directsound_compressed gDirectSound_Cry_410
	voice_directsound_compressed gDirectSound_Cry_411
	voice_directsound_compressed gDirectSound_Cry_412
	voice_directsound_compressed gDirectSound_Cry_413
	voice_directsound_compressed gDirectSound_Cry_414
	voice_directsound_compressed gDirectSound_Cry_415
	voice_directsound_compressed gDirectSound_Cry_416
	voice_directsound_compressed gDirectSound_Cry_417
	voice_directsound_compressed gDirectSound_Cry_418
	voice_directsound_compressed gDirectSound_Cry_419
	voice_directsound_compressed gDirectSound_Cry_420
	voice_directsound_compressed gDirectSound_Cry_421
	voice_directsound_compressed gDirectSound_Cry_422
	voice_directsound_compressed gDirectSound_Cry_423
	voice_directsound_compressed gDirectSound_Cry_424
	voice_directsound_compressed gDirectSound_Cry_425
	voice_directsound_compressed gDirectSound_Cry_426
	voice_directsound_compressed gDirectSound_Cry_427
	voice_directsound_compressed gDirectSound_Cry_428
	voice_directsound_compressed gDirectSound_Cry_429
	voice_directsound_compressed gDirectSound_Cry_430
	voice_directsound_compressed gDirectSound_Cry_431
	voice_directsound_compressed gDirectSound_Cry_432
	voice_directsound_compressed gDirectSound_Cry_433
	voice_directsound_compressed gDirectSound_Cry_434
	voice_directsound_compressed gDirectSound_Cry_435
	voice_directsound_compressed gDirectSound_Cry_436
	voice_directsound_compressed gDirectSound_Cry_437
	voice_directsound_compressed gDirectSound_Cry_438
	voice_directsound_compressed gDirectSound_Cry_439
	voice_directsound_compressed gDirectSound_Cry_440
	voice_directsound_compressed gDirectSound_Cry_441
	voice_directsound_compressed gDirectSound_Cry_442
	voice_directsound_compressed gDirectSound_Cry_443
	voice_directsound_compressed gDirectSound_Cry_444
	voice_directsound_compressed gDirectSound_Cry_445
	voice_directsound_compressed gDirectSound_Cry_446
	voice_directsound_compressed gDirectSound_Cry_447
	voice_directsound_compressed gDirectSound_Cry_448
	voice_directsound_compressed gDirectSound_Cry_449
	voice_directsound_compressed gDirectSound_Cry_450
	voice_directsound_compressed gDirectSound_Cry_451
	voice_directsound_compressed gDirectSound_Cry_452
	voice_directsound_compressed gDirectSound_Cry_453
	voice_directsound_compressed gDirectSound_Cry_454
	voice_directsound_compressed gDirectSound_Cry_455
	voice_directsound_compressed gDirectSound_Cry_456
	voice_directsound_compressed gDirectSound_Cry_457
	voice_directsound_compressed gDirectSound_Cry_458
	voice_directsound_compressed gDirectSound_Cry_459
	voice_directsound_compressed gDirectSound_Cry_460
	voice_directsound_compressed gDirectSound_Cry_461
	voice_directsound_compressed gDirectSound_Cry_462
	voice_directsound_compressed gDirectSound_Cry_463
	voice_directsound_compressed gDirectSound_Cry_464
	voice_directsound_compressed gDirectSound_Cry_465
	voice_directsound_compressed gDirectSound_Cry_466
	voice_directsound_compressed gDirectSound_Cry_467
	voice_directsound_compressed gDirectSound_Cry_468
	voice_directsound_compressed gDirectSound_Cry_469
	voice_directsound_compressed gDirectSound_Cry_470
	voice_directsound_compressed gDirectSound_Cry_471
	voice_directsound_compressed gDirectSound_Cry_472
	voice_directsound_compressed gDirectSound_Cry_473
	voice_directsound_compressed gDirectSound_Cry_474
	voice_directsound_compressed gDirectSound_Cry_475
	voice_directsound_compressed gDirectSound_Cry_476
	voice_directsound_compressed gDirectSound_Cry_477
	voice_directsound_compressed gDirectSound_Cry_478
	voice_directsound_compressed gDirectSound_Cry_479
	voice_directsound_compressed gDirectSound_Cry_480
	voice_directsound_compressed gDirectSound_Cry_481
	voice_directsound_compressed gDirectSound_Cry_482
	voice_directsound_compressed gDirectSound_Cry_483
	voice_directsound_compressed gDirectSound_Cry_484
	voice_directsound_compressed gDirectSound_Cry_485
	voice_directsound_compressed gDirectSound_Cry_486
	voice_directsound_compressed gDirectSound_Cry_487
	voice_directsound_compressed gDirectSound_Cry_488
	voice_directsound_compressed gDirectSound_Cry_489
	voice_directsound_compressed gDirectSound_Cry_490
	voice_directsound_compressed gDirectSound_Cry_491
	voice_directsound_compressed gDirectSound_Cry_492
	voice_directsound_compressed gDirectSound_Cry_493
	voice_directsound_compressed gDirectSound_Cry_610
	voice_directsound_compressed gDirectSound_Cry_698
	voice_directsound_compressed gDirectSound_Cry_722
	voice_directsound_compressed gDirectSound_Cry_840
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound_compressed_reverse gDirectSound_085FEC58
	voice_directsound_compressed_reverse gDirectSound_085FFAD0
	voice_directsound_compressed_reverse gDirectSound_08600330
	voice_directsound_compressed_reverse gDirectSound_08600DF0
	voice_directsound_compressed_reverse gDirectSound_0860173C
	voice_directsound_compressed_reverse gDirectSound_08602398
	voice_directsound_compressed_reverse gDirectSound_086038A0
	voice_directsound_compressed_reverse gDirectSound_08604338
	voice_directsound_compressed_reverse gDirectSound_08604F68
	voice_directsound_compressed_reverse gDirectSound_08605D48
	voice_directsound_compressed_reverse gDirectSound_086068E8
	voice_directsound_compressed_reverse gDirectSound_08607FF4
	voice_directsound_compressed_reverse gDirectSound_08608984
	voice_directsound_compressed_reverse gDirectSound_086093EC
	voice_directsound_compressed_reverse gDirectSound_08609984
	voice_directsound_compressed_reverse gDirectSound_0860A4A0
	voice_directsound_compressed_reverse gDirectSound_0860ADF4
	voice_directsound_compressed_reverse gDirectSound_0860B3F4
	voice_directsound_compressed_reverse gDirectSound_0860BCF8
	voice_directsound_compressed_reverse gDirectSound_0860CEA8
	voice_directsound_compressed_reverse gDirectSound_0860DB14
	voice_directsound_compressed_reverse gDirectSound_0860E4BC
	voice_directsound_compressed_reverse gDirectSound_08610190
	voice_directsound_compressed_reverse gDirectSound_08612110
	voice_directsound_compressed_reverse gDirectSound_08612CB8
	voice_directsound_compressed_reverse gDirectSound_0861412C
	voice_directsound_compressed_reverse gDirectSound_08615B48
	voice_directsound_compressed_reverse gDirectSound_086162CC
	voice_directsound_compressed_reverse gDirectSound_086173D0
	voice_directsound_compressed_reverse gDirectSound_08618A50
	voice_directsound_compressed_reverse gDirectSound_08619618
	voice_directsound_compressed_reverse gDirectSound_0861A258
	voice_directsound_compressed_reverse gDirectSound_0861AF00
	voice_directsound_compressed_reverse gDirectSound_0861B740
	voice_directsound_compressed_reverse gDirectSound_0861BBA8
	voice_directsound_compressed_reverse gDirectSound_0861CA3C
	voice_directsound_compressed_reverse gDirectSound_0861DB0C
	voice_directsound_compressed_reverse gDirectSound_0861E338
	voice_directsound_compressed_reverse gDirectSound_0861EEA0
	voice_directsound_compressed_reverse gDirectSound_08620264
	voice_directsound_compressed_reverse gDirectSound_08620C78
	voice_directsound_compressed_reverse gDirectSound_08621544
	voice_directsound_compressed_reverse gDirectSound_08622570
	voice_directsound_compressed_reverse gDirectSound_08622DA8
	voice_directsound_compressed_reverse gDirectSound_08623DEC
	voice_directsound_compressed_reverse gDirectSound_08624A98
	voice_directsound_compressed_reverse gDirectSound_086254B4
	voice_directsound_compressed_reverse gDirectSound_086260E4
	voice_directsound_compressed_reverse gDirectSound_08627948
	voice_directsound_compressed_reverse gDirectSound_086281CC
	voice_directsound_compressed_reverse gDirectSound_08629024
	voice_directsound_compressed_reverse gDirectSound_08629A10
	voice_directsound_compressed_reverse gDirectSound_0862A080
	voice_directsound_compressed_reverse gDirectSound_0862ACA8
	voice_directsound_compressed_reverse gDirectSound_0862B460
	voice_directsound_compressed_reverse gDirectSound_0862BBBC
	voice_directsound_compressed_reverse gDirectSound_0862CC74
	voice_directsound_compressed_reverse gDirectSound_0862D9D8
	voice_directsound_compressed_reverse gDirectSound_0862EEBC
	voice_directsound_compressed_reverse gDirectSound_0862F7B8
	voice_directsound_compressed_reverse gDirectSound_086307C0
	voice_directsound_compressed_reverse gDirectSound_08631240
	voice_directsound_compressed_reverse gDirectSound_086325F4
	voice_directsound_compressed_reverse gDirectSound_08632D08
	voice_directsound_compressed_reverse gDirectSound_08634220
	voice_directsound_compressed_reverse gDirectSound_08634A24
	voice_directsound_compressed_reverse gDirectSound_08635B84
	voice_directsound_compressed_reverse gDirectSound_086364D0
	voice_directsound_compressed_reverse gDirectSound_08637BF0
	voice_directsound_compressed_reverse gDirectSound_0863852C
	voice_directsound_compressed_reverse gDirectSound_08639628
	voice_directsound_compressed_reverse gDirectSound_0863A22C
	voice_directsound_compressed_reverse gDirectSound_0863BAE4
	voice_directsound_compressed_reverse gDirectSound_0863C224
	voice_directsound_compressed_reverse gDirectSound_0863CEC4
	voice_directsound_compressed_reverse gDirectSound_0863D8E8
	voice_directsound_compressed_reverse gDirectSound_0863E6EC
	voice_directsound_compressed_reverse gDirectSound_086400F4
	voice_directsound_compressed_reverse gDirectSound_086409E4
	voice_directsound_compressed_reverse gDirectSound_08642094
	voice_directsound_compressed_reverse gDirectSound_08642D18
	voice_directsound_compressed_reverse gDirectSound_08644078
	voice_directsound_compressed_reverse gDirectSound_08645874
	voice_directsound_compressed_reverse gDirectSound_086468A0
	voice_directsound_compressed_reverse gDirectSound_08647074
	voice_directsound_compressed_reverse gDirectSound_086497B8
	voice_directsound_compressed_reverse gDirectSound_0864A234
	voice_directsound_compressed_reverse gDirectSound_0864AA54
	voice_directsound_compressed_reverse gDirectSound_0864BAD8
	voice_directsound_compressed_reverse gDirectSound_0864C08C
	voice_directsound_compressed_reverse gDirectSound_0864CC64
	voice_directsound_compressed_reverse gDirectSound_0864F0B0
	voice_directsound_compressed_reverse gDirectSound_08650300
	voice_directsound_compressed_reverse gDirectSound_086512E8
	voice_directsound_compressed_reverse gDirectSound_08652954
	voice_directsound_compressed_reverse gDirectSound_086532FC
	voice_directsound_compressed_reverse gDirectSound_0865502C
	voice_directsound_compressed_reverse gDirectSound_08655BE4
	voice_directsound_compressed_reverse gDirectSound_086572B8
	voice_directsound_compressed_reverse gDirectSound_08657C58
	voice_directsound_compressed_reverse gDirectSound_08658F2C
	voice_directsound_compressed_reverse gDirectSound_0865B6A4
	voice_directsound_compressed_reverse gDirectSound_0865BE78
	voice_directsound_compressed_reverse gDirectSound_0865D280
	voice_directsound_compressed_reverse gDirectSound_0865F25C
	voice_directsound_compressed_reverse gDirectSound_0866125C
	voice_directsound_compressed_reverse gDirectSound_08662960
	voice_directsound_compressed_reverse gDirectSound_086635F8
	voice_directsound_compressed_reverse gDirectSound_08664180
	voice_directsound_compressed_reverse gDirectSound_08665298
	voice_directsound_compressed_reverse gDirectSound_08665BE0
	voice_directsound_compressed_reverse gDirectSound_08666F6C
	voice_directsound_compressed_reverse gDirectSound_08667D24
	voice_directsound_compressed_reverse gDirectSound_086688C8
	voice_directsound_compressed_reverse gDirectSound_08669448
	voice_directsound_compressed_reverse gDirectSound_08669D74
	voice_directsound_compressed_reverse gDirectSound_0866B24C
	voice_directsound_compressed_reverse gDirectSound_0866CBF0
	voice_directsound_compressed_reverse gDirectSound_0866E020
	voice_directsound_compressed_reverse gDirectSound_0866E4FC
	voice_directsound_compressed_reverse gDirectSound_08670A08
	voice_directsound_compressed_reverse gDirectSound_08672DC0
	voice_directsound_compressed_reverse gDirectSound_08674AEC
	voice_directsound_compressed_reverse gDirectSound_08676408
	voice_directsound_compressed_reverse gDirectSound_086770C8
	voice_directsound_compressed_reverse gDirectSound_086779A0
	voice_directsound_compressed_reverse gDirectSound_0867983C
	voice_directsound_compressed_reverse gDirectSound_0867B900
	voice_directsound_compressed_reverse gDirectSound_0867D560
	voice_directsound_compressed_reverse gDirectSound_0867E0F0
	voice_directsound_compressed_reverse gDirectSound_0867FD38
	voice_directsound_compressed_reverse gDirectSound_08680A60
	voice_directsound_compressed_reverse gDirectSound_08683470
	voice_directsound_compressed_reverse gDirectSound_08683C94
	voice_directsound_compressed_reverse gDirectSound_08684D9C
	voice_directsound_compressed_reverse gDirectSound_08686394
	voice_directsound_compressed_reverse gDirectSound_08687118
	voice_directsound_compressed_reverse gDirectSound_086885EC

@ Due to the way mks4agb (Nintendo's tool) works, key split table labels can
@ appear before the actual start of the key split table data. If you look at
@ the first keysplit table (keysplit_piano), you'll notice it's offset backwards
@ by 36 bytes. This is because the key split tables don't map instruments
@ for the entire note range (0-127)--they only map subsets, and the upper
@ and lower ranges aren't necessarily 0 or 127.
@
@ For example if a key split table maps an note range of 10-20, then the key
@ split table label will be offset 10 bytes before the actual key split data
@ begins. Therefore, the notes naturally map to the key split table without
@ any extra offset calculation.

keysplit gUnknown_08534BC0, 36
	split 0, 55
	split 1, 70
	split 2, 91
	split 3, 108

keysplit gUnknown_08534C08, 36
	split 0, 69
	split 1, 81
	split 2, 108

keysplit gUnknown_08534C50, 36
	split 0, 66
	split 1, 84
	split 2, 108

keysplit gUnknown_08534C98, 24
	split 0, 42
	split 1, 108

keysplit gUnknown_08534CEC, 36
	split 0, 66
	split 1, 108

gUnknown_08534D34:: @ 0x08534D34
	.incbin "sound/programmable_wave_samples/gUnknown_08534D34.pcm"

gUnknown_08534D44:: @ 0x08534D44
	.incbin "sound/programmable_wave_samples/gUnknown_08534D44.pcm"

gUnknown_08534D54:: @ 0x08534D54
	.incbin "sound/programmable_wave_samples/gUnknown_08534D54.pcm"

gUnknown_08534D64:: @ 0x08534D64
	.incbin "sound/programmable_wave_samples/gUnknown_08534D64.pcm"

gUnknown_08534D74:: @ 0x08534D74
	.incbin "sound/programmable_wave_samples/gUnknown_08534D74.pcm"

gUnknown_08534D84:: @ 0x08534D84
	.incbin "sound/programmable_wave_samples/gUnknown_08534D84.pcm"

gUnknown_08534D94:: @ 0x08534D94
	.incbin "sound/programmable_wave_samples/gUnknown_08534D94.pcm"

gUnknown_08534DA4:: @ 0x08534DA4
	.incbin "sound/programmable_wave_samples/gUnknown_08534DA4.pcm"

gUnknown_08534DB4:: @ 0x08534DB4
	.incbin "sound/programmable_wave_samples/gUnknown_08534DB4.pcm"

gUnknown_08534DC4:: @ 0x08534DC4
	.incbin "sound/programmable_wave_samples/gUnknown_08534DC4.pcm"


	.equiv NUM_TRACKS_BGM, 10
	.equiv NUM_TRACKS_SE1, 3
	.equiv NUM_TRACKS_SE2, 3
	.equiv NUM_TRACKS_SE3, 2

	.align 2
gMPlayTable:: @ 0x08534DD4
	music_player gMPlayInfo_BGM, gMPlayTrack_BGM, NUM_TRACKS_BGM, 0
	music_player gMPlayInfo_SE1, gMPlayTrack_SE1, NUM_TRACKS_SE1, 0
	music_player gMPlayInfo_SE2, gMPlayTrack_SE2, NUM_TRACKS_SE2, 0
	music_player gMPlayInfo_SE3, gMPlayTrack_SE3, NUM_TRACKS_SE3, 0

.include "sound/song_table.inc"

.include "sound/songs/mus_dummy.s"

	.align 2
gDirectSound_Cry_Bulbasaur::
	.incbin "sound/direct_sound_samples/cries/cry_001_bulbasaur.bin"

	.align 2
gDirectSound_Cry_Ivysaur::
	.incbin "sound/direct_sound_samples/cries/cry_002_ivysaur.bin"

	.align 2
	.align 2
gDirectSound_Cry_003::
	.incbin "sound/direct_sound_samples/cries/cry_003_venusaur.bin"

	.align 2
gDirectSound_Cry_004::
	.incbin "sound/direct_sound_samples/cries/cry_004_charmander.bin"

	.align 2
gDirectSound_Cry_005::
	.incbin "sound/direct_sound_samples/cries/cry_005_charmeleon.bin"

	.align 2
gDirectSound_Cry_006::
	.incbin "sound/direct_sound_samples/cries/cry_006_charizard.bin"

	.align 2
gDirectSound_Cry_007::
	.incbin "sound/direct_sound_samples/cries/cry_007_squirtle.bin"

	.align 2
gDirectSound_Cry_008::
	.incbin "sound/direct_sound_samples/cries/cry_008_wartortle.bin"

	.align 2
gDirectSound_Cry_009::
	.incbin "sound/direct_sound_samples/cries/cry_009_blastoise.bin"

	.align 2
gDirectSound_Cry_010::
	.incbin "sound/direct_sound_samples/cries/cry_010_caterpie.bin"

	.align 2
gDirectSound_Cry_011::
	.incbin "sound/direct_sound_samples/cries/cry_011_metapod.bin"

	.align 2
gDirectSound_Cry_012::
	.incbin "sound/direct_sound_samples/cries/cry_012_butterfree.bin"

	.align 2
gDirectSound_Cry_013::
	.incbin "sound/direct_sound_samples/cries/cry_013_weedle.bin"

	.align 2
gDirectSound_Cry_014::
	.incbin "sound/direct_sound_samples/cries/cry_014_kakuna.bin"

	.align 2
gDirectSound_Cry_015::
	.incbin "sound/direct_sound_samples/cries/cry_015_beedrill.bin"

	.align 2
gDirectSound_Cry_016::
	.incbin "sound/direct_sound_samples/cries/cry_016_pidgey.bin"

	.align 2
gDirectSound_Cry_017::
	.incbin "sound/direct_sound_samples/cries/cry_017_pidgeotto.bin"

	.align 2
gDirectSound_Cry_018::
	.incbin "sound/direct_sound_samples/cries/cry_018_pidgeot.bin"

	.align 2
gDirectSound_Cry_019::
	.incbin "sound/direct_sound_samples/cries/cry_019_rattata.bin"

	.align 2
gDirectSound_Cry_020::
	.incbin "sound/direct_sound_samples/cries/cry_020_raticate.bin"

	.align 2
gDirectSound_Cry_021::
	.incbin "sound/direct_sound_samples/cries/cry_021_spearow.bin"

	.align 2
gDirectSound_Cry_022::
	.incbin "sound/direct_sound_samples/cries/cry_022_fearow.bin"

	.align 2
gDirectSound_Cry_023::
	.incbin "sound/direct_sound_samples/cries/cry_023_ekans.bin"

	.align 2
gDirectSound_Cry_024::
	.incbin "sound/direct_sound_samples/cries/cry_024_arbok.bin"

	.align 2
gDirectSound_Cry_029::
	.incbin "sound/direct_sound_samples/cries/cry_029_nidoran_female.bin"

	.align 2
gDirectSound_Cry_030::
	.incbin "sound/direct_sound_samples/cries/cry_030_nidorina.bin"

	.align 2
gDirectSound_Cry_031::
	.incbin "sound/direct_sound_samples/cries/cry_031_nidoqueen.bin"

	.align 2
gDirectSound_Cry_032::
	.incbin "sound/direct_sound_samples/cries/cry_032_nidoran_male.bin"

	.align 2
gDirectSound_Cry_033::
	.incbin "sound/direct_sound_samples/cries/cry_033_nidorino.bin"

	.align 2
gDirectSound_Cry_034::
	.incbin "sound/direct_sound_samples/cries/cry_034_nidoking.bin"

	.align 2
gDirectSound_Cry_035::
	.incbin "sound/direct_sound_samples/cries/cry_035_clefairy.bin"

	.align 2
gDirectSound_Cry_036::
	.incbin "sound/direct_sound_samples/cries/cry_036_clefable.bin"

	.align 2
gDirectSound_Cry_046::
	.incbin "sound/direct_sound_samples/cries/cry_046_paras.bin"

	.align 2
gDirectSound_Cry_047::
	.incbin "sound/direct_sound_samples/cries/cry_047_parasect.bin"

	.align 2
gDirectSound_Cry_048::
	.incbin "sound/direct_sound_samples/cries/cry_048_venonat.bin"

	.align 2
gDirectSound_Cry_049::
	.incbin "sound/direct_sound_samples/cries/cry_049_venomoth.bin"

	.align 2
gDirectSound_Cry_050::
	.incbin "sound/direct_sound_samples/cries/cry_050_diglett.bin"

	.align 2
gDirectSound_Cry_051::
	.incbin "sound/direct_sound_samples/cries/cry_051_dugtrio.bin"

	.align 2
gDirectSound_Cry_052::
	.incbin "sound/direct_sound_samples/cries/cry_052_meowth.bin"

	.align 2
gDirectSound_Cry_053::
	.incbin "sound/direct_sound_samples/cries/cry_053_persian.bin"

	.align 2
gDirectSound_Cry_056::
	.incbin "sound/direct_sound_samples/cries/cry_056_mankey.bin"

	.align 2
gDirectSound_Cry_057::
	.incbin "sound/direct_sound_samples/cries/cry_057_primeape.bin"

	.align 2
gDirectSound_Cry_058::
	.incbin "sound/direct_sound_samples/cries/cry_058_growlithe.bin"

	.align 2
gDirectSound_Cry_059::
	.incbin "sound/direct_sound_samples/cries/cry_059_arcanine.bin"

	.align 2
gDirectSound_Cry_060::
	.incbin "sound/direct_sound_samples/cries/cry_060_poliwag.bin"

	.align 2
gDirectSound_Cry_061::
	.incbin "sound/direct_sound_samples/cries/cry_061_poliwhirl.bin"

	.align 2
gDirectSound_Cry_062::
	.incbin "sound/direct_sound_samples/cries/cry_062_poliwrath.bin"

	.align 2
gDirectSound_Cry_069::
	.incbin "sound/direct_sound_samples/cries/cry_069_bellsprout.bin"

	.align 2
gDirectSound_Cry_070::
	.incbin "sound/direct_sound_samples/cries/cry_070_weepinbell.bin"

	.align 2
gDirectSound_Cry_071::
	.incbin "sound/direct_sound_samples/cries/cry_071_victreebel.bin"

	.align 2
gDirectSound_Cry_077::
	.incbin "sound/direct_sound_samples/cries/cry_077_ponyta.bin"

	.align 2
gDirectSound_Cry_078::
	.incbin "sound/direct_sound_samples/cries/cry_078_rapidash.bin"

	.align 2
gDirectSound_Cry_079::
	.incbin "sound/direct_sound_samples/cries/cry_079_slowpoke.bin"

	.align 2
gDirectSound_Cry_080::
	.incbin "sound/direct_sound_samples/cries/cry_080_slowbro.bin"

	.align 2
gDirectSound_Cry_083::
	.incbin "sound/direct_sound_samples/cries/cry_083_farfetchd.bin"

	.align 2
gDirectSound_Cry_086::
	.incbin "sound/direct_sound_samples/cries/cry_086_seel.bin"

	.align 2
gDirectSound_Cry_087::
	.incbin "sound/direct_sound_samples/cries/cry_087_dewgong.bin"

	.align 2
gDirectSound_Cry_090::
	.incbin "sound/direct_sound_samples/cries/cry_090_shellder.bin"

	.align 2
gDirectSound_Cry_091::
	.incbin "sound/direct_sound_samples/cries/cry_091_cloyster.bin"

	.align 2
gDirectSound_Cry_092::
	.incbin "sound/direct_sound_samples/cries/cry_092_gastly.bin"

	.align 2
gDirectSound_Cry_093::
	.incbin "sound/direct_sound_samples/cries/cry_093_haunter.bin"

	.align 2
gDirectSound_Cry_094::
	.incbin "sound/direct_sound_samples/cries/cry_094_gengar.bin"

	.align 2
gDirectSound_Cry_095::
	.incbin "sound/direct_sound_samples/cries/cry_095_onix.bin"

	.align 2
gDirectSound_Cry_096::
	.incbin "sound/direct_sound_samples/cries/cry_096_drowzee.bin"

	.align 2
gDirectSound_Cry_097::
	.incbin "sound/direct_sound_samples/cries/cry_097_hypno.bin"

	.align 2
gDirectSound_Cry_098::
	.incbin "sound/direct_sound_samples/cries/cry_098_krabby.bin"

	.align 2
gDirectSound_Cry_099::
	.incbin "sound/direct_sound_samples/cries/cry_099_kingler.bin"

	.align 2
gDirectSound_Cry_102::
	.incbin "sound/direct_sound_samples/cries/cry_102_exeggcute.bin"

	.align 2
gDirectSound_Cry_103::
	.incbin "sound/direct_sound_samples/cries/cry_103_exeggutor.bin"

	.align 2
gDirectSound_Cry_104::
	.incbin "sound/direct_sound_samples/cries/cry_104_cubone.bin"

	.align 2
gDirectSound_Cry_105::
	.incbin "sound/direct_sound_samples/cries/cry_105_marowak.bin"

	.align 2
gDirectSound_Cry_106::
	.incbin "sound/direct_sound_samples/cries/cry_106_hitmonlee.bin"

	.align 2
gDirectSound_Cry_107::
	.incbin "sound/direct_sound_samples/cries/cry_107_hitmonchan.bin"

	.align 2
gDirectSound_Cry_108::
	.incbin "sound/direct_sound_samples/cries/cry_108_lickitung.bin"

	.align 2
gDirectSound_Cry_113::
	.incbin "sound/direct_sound_samples/cries/cry_113_chansey.bin"

	.align 2
gDirectSound_Cry_114::
	.incbin "sound/direct_sound_samples/cries/cry_114_tangela.bin"

	.align 2
gDirectSound_Cry_115::
	.incbin "sound/direct_sound_samples/cries/cry_115_kangaskhan.bin"

	.align 2
gDirectSound_Cry_122::
	.incbin "sound/direct_sound_samples/cries/cry_122_mr_mime.bin"

	.align 2
gDirectSound_Cry_123::
	.incbin "sound/direct_sound_samples/cries/cry_123_scyther.bin"

	.align 2
gDirectSound_Cry_124::
	.incbin "sound/direct_sound_samples/cries/cry_124_jynx.bin"

	.align 2
gDirectSound_Cry_125::
	.incbin "sound/direct_sound_samples/cries/cry_125_electabuzz.bin"

	.align 2
gDirectSound_Cry_126::
	.incbin "sound/direct_sound_samples/cries/cry_126_magmar.bin"

	.align 2
gDirectSound_Cry_131::
	.incbin "sound/direct_sound_samples/cries/cry_131_lapras.bin"

	.align 2
gDirectSound_Cry_132::
	.incbin "sound/direct_sound_samples/cries/cry_132_ditto.bin"

	.align 2
gDirectSound_Cry_133::
	.incbin "sound/direct_sound_samples/cries/cry_133_eevee.bin"

	.align 2
gDirectSound_Cry_134::
	.incbin "sound/direct_sound_samples/cries/cry_134_vaporeon.bin"

	.align 2
gDirectSound_Cry_135::
	.incbin "sound/direct_sound_samples/cries/cry_135_jolteon.bin"

	.align 2
gDirectSound_Cry_136::
	.incbin "sound/direct_sound_samples/cries/cry_136_flareon.bin"

	.align 2
gDirectSound_Cry_137::
	.incbin "sound/direct_sound_samples/cries/cry_137_porygon.bin"

	.align 2
gDirectSound_Cry_138::
	.incbin "sound/direct_sound_samples/cries/cry_138_omanyte.bin"

	.align 2
gDirectSound_Cry_139::
	.incbin "sound/direct_sound_samples/cries/cry_139_omastar.bin"

	.align 2
gDirectSound_Cry_140::
	.incbin "sound/direct_sound_samples/cries/cry_140_kabuto.bin"

	.align 2
gDirectSound_Cry_141::
	.incbin "sound/direct_sound_samples/cries/cry_141_kabutops.bin"

	.align 2
gDirectSound_Cry_143::
	.incbin "sound/direct_sound_samples/cries/cry_143_snorlax.bin"

	.align 2
gDirectSound_Cry_144::
	.incbin "sound/direct_sound_samples/cries/cry_144_articuno.bin"

	.align 2
gDirectSound_Cry_145::
	.incbin "sound/direct_sound_samples/cries/cry_145_zapdos.bin"

	.align 2
gDirectSound_Cry_146::
	.incbin "sound/direct_sound_samples/cries/cry_146_moltres.bin"

	.align 2
gDirectSound_Cry_147::
	.incbin "sound/direct_sound_samples/cries/cry_147_dratini.bin"

	.align 2
gDirectSound_Cry_148::
	.incbin "sound/direct_sound_samples/cries/cry_148_dragonair.bin"

	.align 2
gDirectSound_Cry_149::
	.incbin "sound/direct_sound_samples/cries/cry_149_dragonite.bin"

	.align 2
gDirectSound_Cry_150::
	.incbin "sound/direct_sound_samples/cries/cry_150_mewtwo.bin"

	.align 2
gDirectSound_Cry_151::
	.incbin "sound/direct_sound_samples/cries/cry_151_mew.bin"

	.align 2
gDirectSound_Cry_161::
	.incbin "sound/direct_sound_samples/cries/cry_161_sentret.bin"

	.align 2
gDirectSound_Cry_162::
	.incbin "sound/direct_sound_samples/cries/cry_162_furret.bin"

	.align 2
gDirectSound_Cry_163::
	.incbin "sound/direct_sound_samples/cries/cry_163_hoothoot.bin"

	.align 2
gDirectSound_Cry_164::
	.incbin "sound/direct_sound_samples/cries/cry_164_noctowl.bin"

	.align 2
gDirectSound_Cry_165::
	.incbin "sound/direct_sound_samples/cries/cry_165_ledyba.bin"

	.align 2
gDirectSound_Cry_166::
	.incbin "sound/direct_sound_samples/cries/cry_166_ledian.bin"

	.align 2
gDirectSound_Cry_167::
	.incbin "sound/direct_sound_samples/cries/cry_167_spinarak.bin"

	.align 2
gDirectSound_Cry_168::
	.incbin "sound/direct_sound_samples/cries/cry_168_ariados.bin"

	.align 2
gDirectSound_Cry_173::
	.incbin "sound/direct_sound_samples/cries/cry_173_cleffa.bin"

	.align 2
gDirectSound_Cry_175::
	.incbin "sound/direct_sound_samples/cries/cry_175_togepi.bin"

	.align 2
gDirectSound_Cry_176::
	.incbin "sound/direct_sound_samples/cries/cry_176_togetic.bin"

	.align 2
gDirectSound_Cry_179::
	.incbin "sound/direct_sound_samples/cries/cry_179_mareep.bin"

	.align 2
gDirectSound_Cry_180::
	.incbin "sound/direct_sound_samples/cries/cry_180_flaaffy.bin"

	.align 2
gDirectSound_Cry_181::
	.incbin "sound/direct_sound_samples/cries/cry_181_ampharos.bin"

	.align 2
gDirectSound_Cry_185::
	.incbin "sound/direct_sound_samples/cries/cry_185_sudowoodo.bin"

	.align 2
gDirectSound_Cry_186::
	.incbin "sound/direct_sound_samples/cries/cry_186_politoed.bin"

	.align 2
gDirectSound_Cry_187::
	.incbin "sound/direct_sound_samples/cries/cry_187_hoppip.bin"

	.align 2
gDirectSound_Cry_188::
	.incbin "sound/direct_sound_samples/cries/cry_188_skiploom.bin"

	.align 2
gDirectSound_Cry_189::
	.incbin "sound/direct_sound_samples/cries/cry_189_jumpluff.bin"

	.align 2
gDirectSound_Cry_190::
	.incbin "sound/direct_sound_samples/cries/cry_190_aipom.bin"

	.align 2
gDirectSound_Cry_191::
	.incbin "sound/direct_sound_samples/cries/cry_191_sunkern.bin"

	.align 2
gDirectSound_Cry_192::
	.incbin "sound/direct_sound_samples/cries/cry_192_sunflora.bin"

	.align 2
gDirectSound_Cry_193::
	.incbin "sound/direct_sound_samples/cries/cry_193_yanma.bin"

	.align 2
gDirectSound_Cry_194::
	.incbin "sound/direct_sound_samples/cries/cry_194_wooper.bin"

	.align 2
gDirectSound_Cry_195::
	.incbin "sound/direct_sound_samples/cries/cry_195_quagsire.bin"

	.align 2
gDirectSound_Cry_196::
	.incbin "sound/direct_sound_samples/cries/cry_196_espeon.bin"

	.align 2
gDirectSound_Cry_197::
	.incbin "sound/direct_sound_samples/cries/cry_197_umbreon.bin"

	.align 2
gDirectSound_Cry_198::
	.incbin "sound/direct_sound_samples/cries/cry_198_murkrow.bin"

	.align 2
gDirectSound_Cry_199::
	.incbin "sound/direct_sound_samples/cries/cry_199_slowking.bin"

	.align 2
gDirectSound_Cry_200::
	.incbin "sound/direct_sound_samples/cries/cry_200_misdreavus.bin"

	.align 2
gDirectSound_Cry_201::
	.incbin "sound/direct_sound_samples/cries/cry_201_unown.bin"

	.align 2
gDirectSound_Cry_204::
	.incbin "sound/direct_sound_samples/cries/cry_204_pineco.bin"

	.align 2
gDirectSound_Cry_205::
	.incbin "sound/direct_sound_samples/cries/cry_205_forretress.bin"

	.align 2
gDirectSound_Cry_206::
	.incbin "sound/direct_sound_samples/cries/cry_206_dunsparce.bin"

	.align 2
gDirectSound_Cry_207::
	.incbin "sound/direct_sound_samples/cries/cry_207_gligar.bin"

	.align 2
gDirectSound_Cry_208::
	.incbin "sound/direct_sound_samples/cries/cry_208_steelix.bin"

	.align 2
gDirectSound_Cry_209::
	.incbin "sound/direct_sound_samples/cries/cry_209_snubbull.bin"

	.align 2
gDirectSound_Cry_210::
	.incbin "sound/direct_sound_samples/cries/cry_210_granbull.bin"

	.align 2
gDirectSound_Cry_211::
	.incbin "sound/direct_sound_samples/cries/cry_211_qwilfish.bin"

	.align 2
gDirectSound_Cry_212::
	.incbin "sound/direct_sound_samples/cries/cry_212_scizor.bin"

	.align 2
gDirectSound_Cry_213::
	.incbin "sound/direct_sound_samples/cries/cry_213_shuckle.bin"

	.align 2
gDirectSound_Cry_215::
	.incbin "sound/direct_sound_samples/cries/cry_215_sneasel.bin"

	.align 2
gDirectSound_Cry_216::
	.incbin "sound/direct_sound_samples/cries/cry_216_teddiursa.bin"

	.align 2
gDirectSound_Cry_217::
	.incbin "sound/direct_sound_samples/cries/cry_217_ursaring.bin"

	.align 2
gDirectSound_Cry_220::
	.incbin "sound/direct_sound_samples/cries/cry_220_swinub.bin"

	.align 2
gDirectSound_Cry_221::
	.incbin "sound/direct_sound_samples/cries/cry_221_piloswine.bin"

	.align 2
gDirectSound_Cry_223::
	.incbin "sound/direct_sound_samples/cries/cry_223_remoraid.bin"

	.align 2
gDirectSound_Cry_224::
	.incbin "sound/direct_sound_samples/cries/cry_224_octillery.bin"

	.align 2
gDirectSound_Cry_225::
	.incbin "sound/direct_sound_samples/cries/cry_225_delibird.bin"

	.align 2
gDirectSound_Cry_226::
	.incbin "sound/direct_sound_samples/cries/cry_226_mantine.bin"

	.align 2
gDirectSound_Cry_228::
	.incbin "sound/direct_sound_samples/cries/cry_228_houndour.bin"

	.align 2
gDirectSound_Cry_229::
	.incbin "sound/direct_sound_samples/cries/cry_229_houndoom.bin"

	.align 2
gDirectSound_Cry_233::
	.incbin "sound/direct_sound_samples/cries/cry_233_porygon2.bin"

	.align 2
gDirectSound_Cry_234::
	.incbin "sound/direct_sound_samples/cries/cry_234_stantler.bin"

	.align 2
gDirectSound_Cry_235::
	.incbin "sound/direct_sound_samples/cries/cry_235_smeargle.bin"

	.align 2
gDirectSound_Cry_236::
	.incbin "sound/direct_sound_samples/cries/cry_236_tyrogue.bin"

	.align 2
gDirectSound_Cry_237::
	.incbin "sound/direct_sound_samples/cries/cry_237_hitmontop.bin"

	.align 2
gDirectSound_Cry_238::
	.incbin "sound/direct_sound_samples/cries/cry_238_smoochum.bin"

	.align 2
gDirectSound_Cry_239::
	.incbin "sound/direct_sound_samples/cries/cry_239_elekid.bin"

	.align 2
gDirectSound_Cry_240::
	.incbin "sound/direct_sound_samples/cries/cry_240_magby.bin"

	.align 2
gDirectSound_Cry_241::
	.incbin "sound/direct_sound_samples/cries/cry_241_miltank.bin"

	.align 2
gDirectSound_Cry_242::
	.incbin "sound/direct_sound_samples/cries/cry_242_blissey.bin"

	.align 2
gDirectSound_Cry_243::
	.incbin "sound/direct_sound_samples/cries/cry_243_raikou.bin"

	.align 2
gDirectSound_Cry_244::
	.incbin "sound/direct_sound_samples/cries/cry_244_entei.bin"

	.align 2
gDirectSound_Cry_245::
	.incbin "sound/direct_sound_samples/cries/cry_245_suicune.bin"

	.align 2
gDirectSound_Cry_246::
	.incbin "sound/direct_sound_samples/cries/cry_246_larvitar.bin"

	.align 2
gDirectSound_Cry_247::
	.incbin "sound/direct_sound_samples/cries/cry_247_pupitar.bin"

	.align 2
gDirectSound_Cry_248::
	.incbin "sound/direct_sound_samples/cries/cry_248_tyranitar.bin"

	.align 2
gDirectSound_Cry_249::
	.incbin "sound/direct_sound_samples/cries/cry_249_lugia.bin"

	.align 2
gDirectSound_Cry_250::
	.incbin "sound/direct_sound_samples/cries/cry_250_ho_oh.bin"

	.align 2
gDirectSound_Cry_386::
	.incbin "sound/direct_sound_samples/cries/cry_386_deoxys.bin"

	.align 2
gDirectSound_Cry_387::
	.incbin "sound/direct_sound_samples/cries/cry_387_turtwig.bin"

	.align 2
gDirectSound_Cry_388::
	.incbin "sound/direct_sound_samples/cries/cry_388_grotle.bin"

	.align 2
gDirectSound_Cry_389::
	.incbin "sound/direct_sound_samples/cries/cry_389_torterra.bin"

	.align 2
gDirectSound_Cry_390::
	.incbin "sound/direct_sound_samples/cries/cry_390_chimchar.bin"

	.align 2
gDirectSound_Cry_391::
	.incbin "sound/direct_sound_samples/cries/cry_391_monferno.bin"

	.align 2
gDirectSound_Cry_392::
	.incbin "sound/direct_sound_samples/cries/cry_392_infernape.bin"

	.align 2
gDirectSound_Cry_393::
	.incbin "sound/direct_sound_samples/cries/cry_393_piplup.bin"

	.align 2
gDirectSound_Cry_394::
	.incbin "sound/direct_sound_samples/cries/cry_394_prinplup.bin"

	.align 2
gDirectSound_Cry_395::
	.incbin "sound/direct_sound_samples/cries/cry_395_empoleon.bin"

	.align 2
gDirectSound_Cry_396::
	.incbin "sound/direct_sound_samples/cries/cry_396_starly.bin"

	.align 2
gDirectSound_Cry_397::
	.incbin "sound/direct_sound_samples/cries/cry_397_staravia.bin"

	.align 2
gDirectSound_Cry_398::
	.incbin "sound/direct_sound_samples/cries/cry_398_staraptor.bin"

	.align 2
gDirectSound_Cry_399::
	.incbin "sound/direct_sound_samples/cries/cry_399_bidoof.bin"

	.align 2
gDirectSound_Cry_400::
	.incbin "sound/direct_sound_samples/cries/cry_400_bibarel.bin"

	.align 2
gDirectSound_Cry_401::
	.incbin "sound/direct_sound_samples/cries/cry_401_kricketot.bin"

	.align 2
gDirectSound_Cry_402::
	.incbin "sound/direct_sound_samples/cries/cry_402_kricketune.bin"

	.align 2
gDirectSound_Cry_403::
	.incbin "sound/direct_sound_samples/cries/cry_403_shinx.bin"

	.align 2
gDirectSound_Cry_404::
	.incbin "sound/direct_sound_samples/cries/cry_404_luxio.bin"

	.align 2
gDirectSound_Cry_405::
	.incbin "sound/direct_sound_samples/cries/cry_405_luxray.bin"

	.align 2
gDirectSound_Cry_406::
	.incbin "sound/direct_sound_samples/cries/cry_406_budew.bin"

	.align 2
gDirectSound_Cry_407::
	.incbin "sound/direct_sound_samples/cries/cry_407_roserade.bin"

	.align 2
gDirectSound_Cry_408::
	.incbin "sound/direct_sound_samples/cries/cry_408_cranidos.bin"

	.align 2
gDirectSound_Cry_409::
	.incbin "sound/direct_sound_samples/cries/cry_409_rampardos.bin"

	.align 2
gDirectSound_Cry_410::
	.incbin "sound/direct_sound_samples/cries/cry_410_shieldon.bin"

	.align 2
gDirectSound_Cry_411::
	.incbin "sound/direct_sound_samples/cries/cry_411_bastiodon.bin"

	.align 2
gDirectSound_Cry_412::
	.incbin "sound/direct_sound_samples/cries/cry_412_burmy.bin"

	.align 2
gDirectSound_Cry_413::
	.incbin "sound/direct_sound_samples/cries/cry_413_wormadam.bin"

	.align 2
gDirectSound_Cry_414::
	.incbin "sound/direct_sound_samples/cries/cry_414_mothim.bin"

	.align 2
gDirectSound_Cry_415::
	.incbin "sound/direct_sound_samples/cries/cry_415_combee.bin"

	.align 2
gDirectSound_Cry_416::
	.incbin "sound/direct_sound_samples/cries/cry_416_vespiquen.bin"

	.align 2
gDirectSound_Cry_417::
	.incbin "sound/direct_sound_samples/cries/cry_417_pachirisu.bin"

	.align 2
gDirectSound_Cry_418::
	.incbin "sound/direct_sound_samples/cries/cry_418_buizel.bin"

	.align 2
gDirectSound_Cry_419::
	.incbin "sound/direct_sound_samples/cries/cry_419_floatzel.bin"

	.align 2
gDirectSound_Cry_420::
	.incbin "sound/direct_sound_samples/cries/cry_420_cherubi.bin"

	.align 2
gDirectSound_Cry_421::
	.incbin "sound/direct_sound_samples/cries/cry_421_cherrim.bin"

	.align 2
gDirectSound_Cry_422::
	.incbin "sound/direct_sound_samples/cries/cry_422_shellos.bin"

	.align 2
gDirectSound_Cry_423::
	.incbin "sound/direct_sound_samples/cries/cry_423_gastrodon.bin"

	.align 2
gDirectSound_Cry_424::
	.incbin "sound/direct_sound_samples/cries/cry_424_ambipom.bin"

	.align 2
gDirectSound_Cry_425::
	.incbin "sound/direct_sound_samples/cries/cry_425_drifloon.bin"

	.align 2
gDirectSound_Cry_426::
	.incbin "sound/direct_sound_samples/cries/cry_426_drifblim.bin"

	.align 2
gDirectSound_Cry_427::
	.incbin "sound/direct_sound_samples/cries/cry_427_buneary.bin"

	.align 2
gDirectSound_Cry_428::
	.incbin "sound/direct_sound_samples/cries/cry_428_lopunny.bin"

	.align 2
gDirectSound_Cry_429::
	.incbin "sound/direct_sound_samples/cries/cry_429_mismagius.bin"

	.align 2
gDirectSound_Cry_430::
	.incbin "sound/direct_sound_samples/cries/cry_430_honchkrow.bin"

	.align 2
gDirectSound_Cry_431::
	.incbin "sound/direct_sound_samples/cries/cry_431_glameow.bin"

	.align 2
gDirectSound_Cry_432::
	.incbin "sound/direct_sound_samples/cries/cry_432_purugly.bin"

	.align 2
gDirectSound_Cry_433::
	.incbin "sound/direct_sound_samples/cries/cry_433_chingling.bin"

	.align 2
gDirectSound_Cry_434::
	.incbin "sound/direct_sound_samples/cries/cry_434_stunky.bin"

	.align 2
gDirectSound_Cry_435::
	.incbin "sound/direct_sound_samples/cries/cry_435_skuntank.bin"

	.align 2
gDirectSound_Cry_436::
	.incbin "sound/direct_sound_samples/cries/cry_436_bronzor.bin"

	.align 2
gDirectSound_Cry_437::
	.incbin "sound/direct_sound_samples/cries/cry_437_bronzong.bin"

	.align 2
gDirectSound_Cry_438::
	.incbin "sound/direct_sound_samples/cries/cry_438_bonsly.bin"

	.align 2
gDirectSound_Cry_439::
	.incbin "sound/direct_sound_samples/cries/cry_439_mime_jr.bin"

	.align 2
gDirectSound_Cry_440::
	.incbin "sound/direct_sound_samples/cries/cry_440_happiny.bin"

	.align 2
gDirectSound_Cry_441::
	.incbin "sound/direct_sound_samples/cries/cry_441_chatot.bin"

	.align 2
gDirectSound_Cry_442::
	.incbin "sound/direct_sound_samples/cries/cry_442_spiritomb.bin"

	.align 2
gDirectSound_Cry_443::
	.incbin "sound/direct_sound_samples/cries/cry_443_gible.bin"

	.align 2
gDirectSound_Cry_444::
	.incbin "sound/direct_sound_samples/cries/cry_444_gabite.bin"

	.align 2
gDirectSound_Cry_445::
	.incbin "sound/direct_sound_samples/cries/cry_445_garchomp.bin"

	.align 2
gDirectSound_Cry_446::
	.incbin "sound/direct_sound_samples/cries/cry_446_munchlax.bin"

	.align 2
gDirectSound_Cry_447::
	.incbin "sound/direct_sound_samples/cries/cry_447_riolu.bin"

	.align 2
gDirectSound_Cry_448::
	.incbin "sound/direct_sound_samples/cries/cry_448_lucario.bin"

	.align 2
gDirectSound_Cry_449::
	.incbin "sound/direct_sound_samples/cries/cry_449_hippopotas.bin"

	.align 2
gDirectSound_Cry_450::
	.incbin "sound/direct_sound_samples/cries/cry_450_hippowdon.bin"

	.align 2
gDirectSound_Cry_451::
	.incbin "sound/direct_sound_samples/cries/cry_451_skorupi.bin"

	.align 2
gDirectSound_Cry_452::
	.incbin "sound/direct_sound_samples/cries/cry_452_drapion.bin"

	.align 2
gDirectSound_Cry_453::
	.incbin "sound/direct_sound_samples/cries/cry_453_croagunk.bin"

	.align 2
gDirectSound_Cry_454::
	.incbin "sound/direct_sound_samples/cries/cry_454_toxicroak.bin"

	.align 2
gDirectSound_Cry_455::
	.incbin "sound/direct_sound_samples/cries/cry_455_carnivine.bin"

	.align 2
gDirectSound_Cry_456::
	.incbin "sound/direct_sound_samples/cries/cry_456_finneon.bin"

	.align 2
gDirectSound_Cry_457::
	.incbin "sound/direct_sound_samples/cries/cry_457_lumineon.bin"

	.align 2
gDirectSound_Cry_458::
	.incbin "sound/direct_sound_samples/cries/cry_458_mantyke.bin"

	.align 2
gDirectSound_Cry_459::
	.incbin "sound/direct_sound_samples/cries/cry_459_snover.bin"

	.align 2
gDirectSound_Cry_460::
	.incbin "sound/direct_sound_samples/cries/cry_460_abomasnow.bin"

	.align 2
gDirectSound_Cry_461::
	.incbin "sound/direct_sound_samples/cries/cry_461_weavile.bin"

	.align 2
gDirectSound_Cry_462::
	.incbin "sound/direct_sound_samples/cries/cry_462_magnezone.bin"

	.align 2
gDirectSound_Cry_463::
	.incbin "sound/direct_sound_samples/cries/cry_463_lickilicky.bin"

	.align 2
gDirectSound_Cry_464::
	.incbin "sound/direct_sound_samples/cries/cry_464_rhyperior.bin"

	.align 2
gDirectSound_Cry_465::
	.incbin "sound/direct_sound_samples/cries/cry_465_tangrowth.bin"

	.align 2
gDirectSound_Cry_466::
	.incbin "sound/direct_sound_samples/cries/cry_466_electivire.bin"

	.align 2
gDirectSound_Cry_467::
	.incbin "sound/direct_sound_samples/cries/cry_467_magmortar.bin"

	.align 2
gDirectSound_Cry_468::
	.incbin "sound/direct_sound_samples/cries/cry_468_togekiss.bin"

	.align 2
gDirectSound_Cry_469::
	.incbin "sound/direct_sound_samples/cries/cry_469_yanmega.bin"

	.align 2
gDirectSound_Cry_470::
	.incbin "sound/direct_sound_samples/cries/cry_470_leafeon.bin"

	.align 2
gDirectSound_Cry_471::
	.incbin "sound/direct_sound_samples/cries/cry_471_glaceon.bin"

	.align 2
gDirectSound_Cry_472::
	.incbin "sound/direct_sound_samples/cries/cry_472_gliscor.bin"

	.align 2
gDirectSound_Cry_473::
	.incbin "sound/direct_sound_samples/cries/cry_473_mamoswine.bin"

	.align 2
gDirectSound_Cry_474::
	.incbin "sound/direct_sound_samples/cries/cry_474_porygon_z.bin"

	.align 2
gDirectSound_Cry_475::
	.incbin "sound/direct_sound_samples/cries/cry_475_gallade.bin"

	.align 2
gDirectSound_Cry_476::
	.incbin "sound/direct_sound_samples/cries/cry_476_probopass.bin"

	.align 2
gDirectSound_Cry_477::
	.incbin "sound/direct_sound_samples/cries/cry_477_dusknoir.bin"

	.align 2
gDirectSound_Cry_478::
	.incbin "sound/direct_sound_samples/cries/cry_478_froslass.bin"

	.align 2
gDirectSound_Cry_479::
	.incbin "sound/direct_sound_samples/cries/cry_479_rotom.bin"

	.align 2
gDirectSound_Cry_480::
	.incbin "sound/direct_sound_samples/cries/cry_480_uxie.bin"

	.align 2
gDirectSound_Cry_481::
	.incbin "sound/direct_sound_samples/cries/cry_481_mesprit.bin"

	.align 2
gDirectSound_Cry_482::
	.incbin "sound/direct_sound_samples/cries/cry_482_azelf.bin"

	.align 2
gDirectSound_Cry_483::
	.incbin "sound/direct_sound_samples/cries/cry_483_dialga.bin"

	.align 2
gDirectSound_Cry_484::
	.incbin "sound/direct_sound_samples/cries/cry_484_palkia.bin"

	.align 2
gDirectSound_Cry_485::
	.incbin "sound/direct_sound_samples/cries/cry_485_heatran.bin"

	.align 2
gDirectSound_Cry_486::
	.incbin "sound/direct_sound_samples/cries/cry_486_regigigas.bin"

	.align 2
gDirectSound_Cry_487::
	.incbin "sound/direct_sound_samples/cries/cry_487_giratina.bin"

	.align 2
gDirectSound_Cry_488::
	.incbin "sound/direct_sound_samples/cries/cry_488_cresselia.bin"

	.align 2
gDirectSound_Cry_489::
	.incbin "sound/direct_sound_samples/cries/cry_489_phione.bin"

	.align 2
gDirectSound_Cry_490::
	.incbin "sound/direct_sound_samples/cries/cry_490_manaphy.bin"

	.align 2
gDirectSound_Cry_491::
	.incbin "sound/direct_sound_samples/cries/cry_491_darkrai.bin"

	.align 2
gDirectSound_Cry_492::
	.incbin "sound/direct_sound_samples/cries/cry_492_shaymin.bin"

	.align 2
gDirectSound_Cry_493::
	.incbin "sound/direct_sound_samples/cries/cry_493_arceus.bin"

	.align 2
gDirectSound_Cry_610::
	.incbin "sound/direct_sound_samples/cries/cry_610_axew.bin"

	.align 2
gDirectSound_Cry_698::
	.incbin "sound/direct_sound_samples/cries/cry_698_amaura.bin"

	.align 2
gDirectSound_Cry_722::
	.incbin "sound/direct_sound_samples/cries/cry_722_rowlet.bin"

	.align 2
gDirectSound_Cry_840::
	.incbin "sound/direct_sound_samples/cries/cry_840_applin.bin"

gDirectSound_08535870:: @ 0x08535870
	.incbin "sound/direct_sound_samples/gDirectSound_08535870.bin"

	.align 2
gDirectSound_08535D10:: @ 0x08535D10
	.incbin "sound/direct_sound_samples/gDirectSound_08535D10.bin"

	.align 2
gDirectSound_08536404:: @ 0x08536404
	.incbin "sound/direct_sound_samples/gDirectSound_08536404.bin"

	.align 2
gDirectSound_08536C94:: @ 0x08536C94
	.incbin "sound/direct_sound_samples/gDirectSound_08536C94.bin"

	.align 2
gDirectSound_0853750C:: @ 0x0853750C
	.incbin "sound/direct_sound_samples/gDirectSound_0853750C.bin"

	.align 2
gDirectSound_0853854C:: @ 0x0853854C
	.incbin "sound/direct_sound_samples/gDirectSound_0853854C.bin"

	.align 2
gDirectSound_08538960:: @ 0x08538960
	.incbin "sound/direct_sound_samples/gDirectSound_08538960.bin"

	.align 2
gDirectSound_08539790:: @ 0x08539790
	.incbin "sound/direct_sound_samples/gDirectSound_08539790.bin"

	.align 2
gDirectSound_0853A6BC:: @ 0x0853A6BC
	.incbin "sound/direct_sound_samples/gDirectSound_0853A6BC.bin"

	.align 2
gDirectSound_0853B650:: @ 0x0853B650
	.incbin "sound/direct_sound_samples/gDirectSound_0853B650.bin"

	.align 2
gDirectSound_0853BF04:: @ 0x0853BF04
	.incbin "sound/direct_sound_samples/gDirectSound_0853BF04.bin"

	.align 2
gDirectSound_0853C7E8:: @ 0x0853C7E8
	.incbin "sound/direct_sound_samples/gDirectSound_0853C7E8.bin"

	.align 2
gDirectSound_0853CD00:: @ 0x0853CD00
	.incbin "sound/direct_sound_samples/gDirectSound_0853CD00.bin"

	.align 2
gDirectSound_0853D2C8:: @ 0x0853D2C8
	.incbin "sound/direct_sound_samples/gDirectSound_0853D2C8.bin"

	.align 2
gDirectSound_0853E228:: @ 0x0853E228
	.incbin "sound/direct_sound_samples/gDirectSound_0853E228.bin"

	.align 2
gDirectSound_0853F888:: @ 0x0853F888
	.incbin "sound/direct_sound_samples/gDirectSound_0853F888.bin"

	.align 2
gDirectSound_08540DE4:: @ 0x08540DE4
	.incbin "sound/direct_sound_samples/gDirectSound_08540DE4.bin"

	.align 2
gDirectSound_08541970:: @ 0x08541970
	.incbin "sound/direct_sound_samples/gDirectSound_08541970.bin"

	.align 2
gDirectSound_08544F14:: @ 0x08544F14
	.incbin "sound/direct_sound_samples/gDirectSound_08544F14.bin"

	.align 2
gDirectSound_08547230:: @ 0x08547230
	.incbin "sound/direct_sound_samples/gDirectSound_08547230.bin"

	.align 2
gDirectSound_0854A8FC:: @ 0x0854A8FC
	.incbin "sound/direct_sound_samples/gDirectSound_0854A8FC.bin"

	.align 2
gDirectSound_0854BC4C:: @ 0x0854BC4C
	.incbin "sound/direct_sound_samples/gDirectSound_0854BC4C.bin"

	.align 2
gDirectSound_0854D15C:: @ 0x0854D15C
	.incbin "sound/direct_sound_samples/gDirectSound_0854D15C.bin"

	.align 2
gDirectSound_0854E57C:: @ 0x0854E57C
	.incbin "sound/direct_sound_samples/gDirectSound_0854E57C.bin"

	.align 2
gDirectSound_0854F618:: @ 0x0854F618
	.incbin "sound/direct_sound_samples/gDirectSound_0854F618.bin"

	.align 2
gDirectSound_08550674:: @ 0x08550674
	.incbin "sound/direct_sound_samples/gDirectSound_08550674.bin"

	.align 2
gDirectSound_08557608:: @ 0x08557608
	.incbin "sound/direct_sound_samples/gDirectSound_08557608.bin"

	.align 2
gDirectSound_0855BB8C:: @ 0x0855BB8C
	.incbin "sound/direct_sound_samples/gDirectSound_0855BB8C.bin"

	.align 2
gDirectSound_0855C2F0:: @ 0x0855C2F0
	.incbin "sound/direct_sound_samples/gDirectSound_0855C2F0.bin"

	.align 2
gDirectSound_0855CAE8:: @ 0x0855CAE8
	.incbin "sound/direct_sound_samples/gDirectSound_0855CAE8.bin"

	.align 2
gDirectSound_0855EA58:: @ 0x0855EA58
	.incbin "sound/direct_sound_samples/gDirectSound_0855EA58.bin"

	.align 2
gDirectSound_0855F22C:: @ 0x0855F22C
	.incbin "sound/direct_sound_samples/gDirectSound_0855F22C.bin"

	.align 2
gDirectSound_0855FC38:: @ 0x0855FC38
	.incbin "sound/direct_sound_samples/gDirectSound_0855FC38.bin"

	.align 2
gDirectSound_0856184C:: @ 0x0856184C
	.incbin "sound/direct_sound_samples/gDirectSound_0856184C.bin"

	.align 2
gDirectSound_08562D1C:: @ 0x08562D1C
	.incbin "sound/direct_sound_samples/gDirectSound_08562D1C.bin"

	.align 2
gDirectSound_0856467C:: @ 0x0856467C
	.incbin "sound/direct_sound_samples/gDirectSound_0856467C.bin"

	.align 2
gDirectSound_08564D20:: @ 0x08564D20
	.incbin "sound/direct_sound_samples/gDirectSound_08564D20.bin"

	.align 2
gDirectSound_085661E4:: @ 0x085661E4
	.incbin "sound/direct_sound_samples/gDirectSound_085661E4.bin"

	.align 2
gDirectSound_08566920:: @ 0x08566920
	.incbin "sound/direct_sound_samples/gDirectSound_08566920.bin"

	.align 2
gDirectSound_08568510:: @ 0x08568510
	.incbin "sound/direct_sound_samples/gDirectSound_08568510.bin"

	.align 2
gDirectSound_085698C4:: @ 0x085698C4
	.incbin "sound/direct_sound_samples/gDirectSound_085698C4.bin"

	.align 2
gDirectSound_0856BF48:: @ 0x0856BF48
	.incbin "sound/direct_sound_samples/gDirectSound_0856BF48.bin"

	.align 2
gDirectSound_0856D18C:: @ 0x0856D18C
	.incbin "sound/direct_sound_samples/gDirectSound_0856D18C.bin"

	.align 2
gDirectSound_0856E19C:: @ 0x0856E19C
	.incbin "sound/direct_sound_samples/gDirectSound_0856E19C.bin"

	.align 2
gDirectSound_0856F4A4:: @ 0x0856F4A4
	.incbin "sound/direct_sound_samples/gDirectSound_0856F4A4.bin"

	.align 2
gDirectSound_085715B0:: @ 0x085715B0
	.incbin "sound/direct_sound_samples/gDirectSound_085715B0.bin"

	.align 2
gDirectSound_0857358C:: @ 0x0857358C
	.incbin "sound/direct_sound_samples/gDirectSound_0857358C.bin"

	.align 2
gDirectSound_08574158:: @ 0x08574158
	.incbin "sound/direct_sound_samples/gDirectSound_08574158.bin"

	.align 2
gDirectSound_08574DCC:: @ 0x08574DCC
	.incbin "sound/direct_sound_samples/gDirectSound_08574DCC.bin"

	.align 2
gDirectSound_08576FDC:: @ 0x08576FDC
	.incbin "sound/direct_sound_samples/gDirectSound_08576FDC.bin"

	.align 2
gDirectSound_085777A8:: @ 0x085777A8
	.incbin "sound/direct_sound_samples/gDirectSound_085777A8.bin"

	.align 2
gDirectSound_08579118:: @ 0x08579118
	.incbin "sound/direct_sound_samples/gDirectSound_08579118.bin"

	.align 2
gDirectSound_0857B0C8:: @ 0x0857B0C8
	.incbin "sound/direct_sound_samples/gDirectSound_0857B0C8.bin"

	.align 2
gDirectSound_0857E3A8:: @ 0x0857E3A8
	.incbin "sound/direct_sound_samples/gDirectSound_0857E3A8.bin"

	.align 2
gDirectSound_0857EDD8:: @ 0x0857EDD8
	.incbin "sound/direct_sound_samples/gDirectSound_0857EDD8.bin"

	.align 2
gDirectSound_0857F80C:: @ 0x0857F80C
	.incbin "sound/direct_sound_samples/gDirectSound_0857F80C.bin"

	.align 2
gDirectSound_08580744:: @ 0x08580744
	.incbin "sound/direct_sound_samples/gDirectSound_08580744.bin"

	.align 2
gDirectSound_08582284:: @ 0x08582284
	.incbin "sound/direct_sound_samples/gDirectSound_08582284.bin"

	.align 2
gDirectSound_08582B4C:: @ 0x08582B4C
	.incbin "sound/direct_sound_samples/gDirectSound_08582B4C.bin"

	.align 2
gDirectSound_08583F1C:: @ 0x08583F1C
	.incbin "sound/direct_sound_samples/gDirectSound_08583F1C.bin"

	.align 2
gDirectSound_08584B2C:: @ 0x08584B2C
	.incbin "sound/direct_sound_samples/gDirectSound_08584B2C.bin"

	.align 2
gDirectSound_08588238:: @ 0x08588238
	.incbin "sound/direct_sound_samples/gDirectSound_08588238.bin"

	.align 2
gDirectSound_08588C10:: @ 0x08588C10
	.incbin "sound/direct_sound_samples/gDirectSound_08588C10.bin"

	.align 2
gDirectSound_0858AA14:: @ 0x0858AA14
	.incbin "sound/direct_sound_samples/gDirectSound_0858AA14.bin"

	.align 2
gDirectSound_0858E078:: @ 0x0858E078
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0858E078.bin"

	.align 2
gDirectSound_pika_08595C7C:: @ 0x08595C7C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_pika_08595C7C.bin"

	.align 2
gDirectSound_08597170:: @ 0x08597170
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08597170.bin"

	.align 2
gDirectSound_0859BD58:: @ 0x0859BD58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0859BD58.bin"

	.align 2
gDirectSound_085A37F4:: @ 0x085A37F4
	.incbin "sound/direct_sound_samples/gDirectSound_085A37F4.bin"

	.align 2
gDirectSound_085A3DF4:: @ 0x085A3DF4
	.incbin "sound/direct_sound_samples/gDirectSound_085A3DF4.bin"

	.align 2
gDirectSound_085A45E0:: @ 0x085A45E0
	.incbin "sound/direct_sound_samples/gDirectSound_085A45E0.bin"

	.align 2
gDirectSound_085A4FE4:: @ 0x085A4FE4
	.incbin "sound/direct_sound_samples/gDirectSound_085A4FE4.bin"

	.align 2
gDirectSound_085A5934:: @ 0x085A5934
	.incbin "sound/direct_sound_samples/gDirectSound_085A5934.bin"

	.align 2
gDirectSound_085A5A74:: @ 0x085A5A74
	.incbin "sound/direct_sound_samples/gDirectSound_085A5A74.bin"

	.align 2
gDirectSound_085A611C:: @ 0x085A611C
	.incbin "sound/direct_sound_samples/gDirectSound_085A611C.bin"

	.align 2
gDirectSound_085A7D6C:: @ 0x085A7D6C
	.incbin "sound/direct_sound_samples/gDirectSound_085A7D6C.bin"

	.align 2
gDirectSound_085A7EDC:: @ 0x085A7EDC
	.incbin "sound/direct_sound_samples/gDirectSound_085A7EDC.bin"

	.align 2
gDirectSound_085A8470:: @ 0x085A8470
	.incbin "sound/direct_sound_samples/gDirectSound_085A8470.bin"

	.align 2
gDirectSound_085A8788:: @ 0x085A8788
	.incbin "sound/direct_sound_samples/gDirectSound_085A8788.bin"

	.align 2
gDirectSound_085A9C78:: @ 0x085A9C78
	.incbin "sound/direct_sound_samples/gDirectSound_085A9C78.bin"

	.align 2
gDirectSound_085A9EA4:: @ 0x085A9EA4
	.incbin "sound/direct_sound_samples/gDirectSound_085A9EA4.bin"

	.align 2
gDirectSound_085AA074:: @ 0x085AA074
	.incbin "sound/direct_sound_samples/gDirectSound_085AA074.bin"

	.align 2
gDirectSound_085AA274:: @ 0x085AA274
	.incbin "sound/direct_sound_samples/gDirectSound_085AA274.bin"

	.align 2
gDirectSound_085ABE38:: @ 0x085ABE38
	.incbin "sound/direct_sound_samples/gDirectSound_085ABE38.bin"

	.align 2
gDirectSound_085ABF3C:: @ 0x085ABF3C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085ABF3C.bin"

	.align 2
gDirectSound_085ACFE4:: @ 0x085ACFE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085ACFE4.bin"

	.align 2
gDirectSound_085AE7A4:: @ 0x085AE7A4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085AE7A4.bin"

	.align 2
gDirectSound_085AF0F8:: @ 0x085AF0F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085AF0F8.bin"

	.align 2
gDirectSound_085AFE88:: @ 0x085AFE88
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085AFE88.bin"

	.align 2
gDirectSound_085B1658:: @ 0x085B1658
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B1658.bin"

	.align 2
gDirectSound_085B2EC4:: @ 0x085B2EC4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B2EC4.bin"

	.align 2
gDirectSound_085B3428:: @ 0x085B3428
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B3428.bin"

	.align 2
gDirectSound_085B3AF0:: @ 0x085B3AF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B3AF0.bin"

	.align 2
gDirectSound_085B4E5C:: @ 0x085B4E5C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B4E5C.bin"

	.align 2
gDirectSound_085B61C0:: @ 0x085B61C0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B61C0.bin"

	.align 2
gDirectSound_085B705C:: @ 0x085B705C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B705C.bin"

	.align 2
gDirectSound_085B7CD8:: @ 0x085B7CD8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B7CD8.bin"

	.align 2
gDirectSound_085B9674:: @ 0x085B9674
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085B9674.bin"

	.align 2
gDirectSound_085BA39C:: @ 0x085BA39C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085BA39C.bin"

	.align 2
gDirectSound_085BAEE4:: @ 0x085BAEE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085BAEE4.bin"

	.align 2
gDirectSound_085BC648:: @ 0x085BC648
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085BC648.bin"

	.align 2
gDirectSound_085BE130:: @ 0x085BE130
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085BE130.bin"

	.align 2
gDirectSound_085C00CC:: @ 0x085C00CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C00CC.bin"

	.align 2
gDirectSound_085C0E30:: @ 0x085C0E30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C0E30.bin"

	.align 2
gDirectSound_085C1BC0:: @ 0x085C1BC0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C1BC0.bin"

	.align 2
gDirectSound_085C2C48:: @ 0x085C2C48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C2C48.bin"

	.align 2
gDirectSound_085C3C38:: @ 0x085C3C38
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C3C38.bin"

	.align 2
gDirectSound_085C5334:: @ 0x085C5334
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C5334.bin"

	.align 2
gDirectSound_085C6AE8:: @ 0x085C6AE8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C6AE8.bin"

	.align 2
gDirectSound_085C86D0:: @ 0x085C86D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C86D0.bin"

	.align 2
gDirectSound_085C94FC:: @ 0x085C94FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085C94FC.bin"

	.align 2
gDirectSound_085CA840:: @ 0x085CA840
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CA840.bin"

	.align 2
gDirectSound_085CC028:: @ 0x085CC028
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CC028.bin"

	.align 2
gDirectSound_085CD36C:: @ 0x085CD36C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CD36C.bin"

	.align 2
gDirectSound_085CE6E4:: @ 0x085CE6E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CE6E4.bin"

	.align 2
gDirectSound_085CF16C:: @ 0x085CF16C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085CF16C.bin"

	.align 2
gDirectSound_085D002C:: @ 0x085D002C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D002C.bin"

	.align 2
gDirectSound_085D18F0:: @ 0x085D18F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D18F0.bin"

	.align 2
gDirectSound_085D3228:: @ 0x085D3228
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D3228.bin"

	.align 2
gDirectSound_085D4684:: @ 0x085D4684
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D4684.bin"

	.align 2
gDirectSound_085D5C30:: @ 0x085D5C30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D5C30.bin"

	.align 2
gDirectSound_085D6F9C:: @ 0x085D6F9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D6F9C.bin"

	.align 2
gDirectSound_085D8408:: @ 0x085D8408
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D8408.bin"

	.align 2
gDirectSound_085D8D84:: @ 0x085D8D84
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D8D84.bin"

	.align 2
gDirectSound_085D95F0:: @ 0x085D95F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D95F0.bin"

	.align 2
gDirectSound_085D9FC8:: @ 0x085D9FC8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085D9FC8.bin"

	.align 2
gDirectSound_085DB320:: @ 0x085DB320
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DB320.bin"

	.align 2
gDirectSound_085DC708:: @ 0x085DC708
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DC708.bin"

	.align 2
gDirectSound_085DDBE4:: @ 0x085DDBE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DDBE4.bin"

	.align 2
gDirectSound_085DE840:: @ 0x085DE840
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DE840.bin"

	.align 2
gDirectSound_085DFB48:: @ 0x085DFB48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085DFB48.bin"

	.align 2
gDirectSound_085E0F7C:: @ 0x085E0F7C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E0F7C.bin"

	.align 2
gDirectSound_085E27D8:: @ 0x085E27D8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E27D8.bin"

	.align 2
gDirectSound_085E2D18:: @ 0x085E2D18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E2D18.bin"

	.align 2
gDirectSound_085E35E4:: @ 0x085E35E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E35E4.bin"

	.align 2
gDirectSound_085E461C:: @ 0x085E461C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E461C.bin"

	.align 2
gDirectSound_085E4D20:: @ 0x085E4D20
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E4D20.bin"

	.align 2
gDirectSound_085E5908:: @ 0x085E5908
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E5908.bin"

	.align 2
gDirectSound_085E7F18:: @ 0x085E7F18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E7F18.bin"

	.align 2
gDirectSound_085E9170:: @ 0x085E9170
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085E9170.bin"

	.align 2
gDirectSound_085EA5AC:: @ 0x085EA5AC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EA5AC.bin"

	.align 2
gDirectSound_085EBF30:: @ 0x085EBF30
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EBF30.bin"

	.align 2
gDirectSound_085ED660:: @ 0x085ED660
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085ED660.bin"

	.align 2
gDirectSound_085EE310:: @ 0x085EE310
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EE310.bin"

	.align 2
gDirectSound_085EED9C:: @ 0x085EED9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EED9C.bin"

	.align 2
gDirectSound_085EF4F0:: @ 0x085EF4F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EF4F0.bin"

	.align 2
gDirectSound_085EFBEC:: @ 0x085EFBEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085EFBEC.bin"

	.align 2
gDirectSound_085F067C:: @ 0x085F067C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F067C.bin"

	.align 2
gDirectSound_085F1548:: @ 0x085F1548
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F1548.bin"

	.align 2
gDirectSound_085F2360:: @ 0x085F2360
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F2360.bin"

	.align 2
gDirectSound_085F3074:: @ 0x085F3074
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F3074.bin"

	.align 2
gDirectSound_085F4160:: @ 0x085F4160
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F4160.bin"

	.align 2
gDirectSound_085F55FC:: @ 0x085F55FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F55FC.bin"

	.align 2
gDirectSound_085F64B0:: @ 0x085F64B0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F64B0.bin"

	.align 2
gDirectSound_085F7704:: @ 0x085F7704
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F7704.bin"

	.align 2
gDirectSound_085F881C:: @ 0x085F881C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F881C.bin"

	.align 2
gDirectSound_085F9D24:: @ 0x085F9D24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085F9D24.bin"

	.align 2
gDirectSound_085FAA04:: @ 0x085FAA04
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FAA04.bin"

	.align 2
gDirectSound_085FC20C:: @ 0x085FC20C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FC20C.bin"

	.align 2
gDirectSound_085FCFE4:: @ 0x085FCFE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FCFE4.bin"

	.align 2
gDirectSound_085FDB34:: @ 0x085FDB34
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FDB34.bin"

	.align 2
gDirectSound_085FEC58:: @ 0x085FEC58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FEC58.bin"

	.align 2
gDirectSound_085FFAD0:: @ 0x085FFAD0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_085FFAD0.bin"

	.align 2
gDirectSound_08600330:: @ 0x08600330
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08600330.bin"

	.align 2
gDirectSound_08600DF0:: @ 0x08600DF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08600DF0.bin"

	.align 2
gDirectSound_0860173C:: @ 0x0860173C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860173C.bin"

	.align 2
gDirectSound_08602398:: @ 0x08602398
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08602398.bin"

	.align 2
gDirectSound_086038A0:: @ 0x086038A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086038A0.bin"

	.align 2
gDirectSound_08604338:: @ 0x08604338
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08604338.bin"

	.align 2
gDirectSound_08604F68:: @ 0x08604F68
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08604F68.bin"

	.align 2
gDirectSound_08605D48:: @ 0x08605D48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08605D48.bin"

	.align 2
gDirectSound_086068E8:: @ 0x086068E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086068E8.bin"

	.align 2
gDirectSound_08607FF4:: @ 0x08607FF4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08607FF4.bin"

	.align 2
gDirectSound_08608984:: @ 0x08608984
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08608984.bin"

	.align 2
gDirectSound_086093EC:: @ 0x086093EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086093EC.bin"

	.align 2
gDirectSound_08609984:: @ 0x08609984
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08609984.bin"

	.align 2
gDirectSound_0860A4A0:: @ 0x0860A4A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860A4A0.bin"

	.align 2
gDirectSound_0860ADF4:: @ 0x0860ADF4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860ADF4.bin"

	.align 2
gDirectSound_0860B3F4:: @ 0x0860B3F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860B3F4.bin"

	.align 2
gDirectSound_0860BCF8:: @ 0x0860BCF8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860BCF8.bin"

	.align 2
gDirectSound_0860CEA8:: @ 0x0860CEA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860CEA8.bin"

	.align 2
gDirectSound_0860DB14:: @ 0x0860DB14
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860DB14.bin"

	.align 2
gDirectSound_0860E4BC:: @ 0x0860E4BC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0860E4BC.bin"

	.align 2
gDirectSound_08610190:: @ 0x08610190
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08610190.bin"

	.align 2
gDirectSound_08612110:: @ 0x08612110
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08612110.bin"

	.align 2
gDirectSound_08612CB8:: @ 0x08612CB8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08612CB8.bin"

	.align 2
gDirectSound_0861412C:: @ 0x0861412C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861412C.bin"

	.align 2
gDirectSound_08615B48:: @ 0x08615B48
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08615B48.bin"

	.align 2
gDirectSound_086162CC:: @ 0x086162CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086162CC.bin"

	.align 2
gDirectSound_086173D0:: @ 0x086173D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086173D0.bin"

	.align 2
gDirectSound_08618A50:: @ 0x08618A50
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08618A50.bin"

	.align 2
gDirectSound_08619618:: @ 0x08619618
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08619618.bin"

	.align 2
gDirectSound_0861A258:: @ 0x0861A258
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861A258.bin"

	.align 2
gDirectSound_0861AF00:: @ 0x0861AF00
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861AF00.bin"

	.align 2
gDirectSound_0861B740:: @ 0x0861B740
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861B740.bin"

	.align 2
gDirectSound_0861BBA8:: @ 0x0861BBA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861BBA8.bin"

	.align 2
gDirectSound_0861CA3C:: @ 0x0861CA3C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861CA3C.bin"

	.align 2
gDirectSound_0861DB0C:: @ 0x0861DB0C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861DB0C.bin"

	.align 2
gDirectSound_0861E338:: @ 0x0861E338
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861E338.bin"

	.align 2
gDirectSound_0861EEA0:: @ 0x0861EEA0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0861EEA0.bin"

	.align 2
gDirectSound_08620264:: @ 0x08620264
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08620264.bin"

	.align 2
gDirectSound_08620C78:: @ 0x08620C78
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08620C78.bin"

	.align 2
gDirectSound_08621544:: @ 0x08621544
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08621544.bin"

	.align 2
gDirectSound_08622570:: @ 0x08622570
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08622570.bin"

	.align 2
gDirectSound_08622DA8:: @ 0x08622DA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08622DA8.bin"

	.align 2
gDirectSound_08623DEC:: @ 0x08623DEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08623DEC.bin"

	.align 2
gDirectSound_08624A98:: @ 0x08624A98
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08624A98.bin"

	.align 2
gDirectSound_086254B4:: @ 0x086254B4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086254B4.bin"

	.align 2
gDirectSound_086260E4:: @ 0x086260E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086260E4.bin"

	.align 2
gDirectSound_08627948:: @ 0x08627948
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08627948.bin"

	.align 2
gDirectSound_086281CC:: @ 0x086281CC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086281CC.bin"

	.align 2
gDirectSound_08629024:: @ 0x08629024
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08629024.bin"

	.align 2
gDirectSound_08629A10:: @ 0x08629A10
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08629A10.bin"

	.align 2
gDirectSound_0862A080:: @ 0x0862A080
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862A080.bin"

	.align 2
gDirectSound_0862ACA8:: @ 0x0862ACA8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862ACA8.bin"

	.align 2
gDirectSound_0862B460:: @ 0x0862B460
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862B460.bin"

	.align 2
gDirectSound_0862BBBC:: @ 0x0862BBBC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862BBBC.bin"

	.align 2
gDirectSound_0862CC74:: @ 0x0862CC74
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862CC74.bin"

	.align 2
gDirectSound_0862D9D8:: @ 0x0862D9D8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862D9D8.bin"

	.align 2
gDirectSound_0862EEBC:: @ 0x0862EEBC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862EEBC.bin"

	.align 2
gDirectSound_0862F7B8:: @ 0x0862F7B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0862F7B8.bin"

	.align 2
gDirectSound_086307C0:: @ 0x086307C0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086307C0.bin"

	.align 2
gDirectSound_08631240:: @ 0x08631240
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08631240.bin"

	.align 2
gDirectSound_086325F4:: @ 0x086325F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086325F4.bin"

	.align 2
gDirectSound_08632D08:: @ 0x08632D08
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08632D08.bin"

	.align 2
gDirectSound_08634220:: @ 0x08634220
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08634220.bin"

	.align 2
gDirectSound_08634A24:: @ 0x08634A24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08634A24.bin"

	.align 2
gDirectSound_08635B84:: @ 0x08635B84
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08635B84.bin"

	.align 2
gDirectSound_086364D0:: @ 0x086364D0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086364D0.bin"

	.align 2
gDirectSound_08637BF0:: @ 0x08637BF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08637BF0.bin"

	.align 2
gDirectSound_0863852C:: @ 0x0863852C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863852C.bin"

	.align 2
gDirectSound_08639628:: @ 0x08639628
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08639628.bin"

	.align 2
gDirectSound_0863A22C:: @ 0x0863A22C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863A22C.bin"

	.align 2
gDirectSound_0863BAE4:: @ 0x0863BAE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863BAE4.bin"

	.align 2
gDirectSound_0863C224:: @ 0x0863C224
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863C224.bin"

	.align 2
gDirectSound_0863CEC4:: @ 0x0863CEC4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863CEC4.bin"

	.align 2
gDirectSound_0863D8E8:: @ 0x0863D8E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863D8E8.bin"

	.align 2
gDirectSound_0863E6EC:: @ 0x0863E6EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0863E6EC.bin"

	.align 2
gDirectSound_086400F4:: @ 0x086400F4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086400F4.bin"

	.align 2
gDirectSound_086409E4:: @ 0x086409E4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086409E4.bin"

	.align 2
gDirectSound_08642094:: @ 0x08642094
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08642094.bin"

	.align 2
gDirectSound_08642D18:: @ 0x08642D18
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08642D18.bin"

	.align 2
gDirectSound_08644078:: @ 0x08644078
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08644078.bin"

	.align 2
gDirectSound_08645874:: @ 0x08645874
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08645874.bin"

	.align 2
gDirectSound_086468A0:: @ 0x086468A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086468A0.bin"

	.align 2
gDirectSound_08647074:: @ 0x08647074
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08647074.bin"

	.align 2
gDirectSound_086497B8:: @ 0x086497B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086497B8.bin"

	.align 2
gDirectSound_0864A234:: @ 0x0864A234
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864A234.bin"

	.align 2
gDirectSound_0864AA54:: @ 0x0864AA54
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864AA54.bin"

	.align 2
gDirectSound_0864BAD8:: @ 0x0864BAD8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864BAD8.bin"

	.align 2
gDirectSound_0864C08C:: @ 0x0864C08C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864C08C.bin"

	.align 2
gDirectSound_0864CC64:: @ 0x0864CC64
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864CC64.bin"

	.align 2
gDirectSound_0864F0B0:: @ 0x0864F0B0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0864F0B0.bin"

	.align 2
gDirectSound_08650300:: @ 0x08650300
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08650300.bin"

	.align 2
gDirectSound_086512E8:: @ 0x086512E8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086512E8.bin"

	.align 2
gDirectSound_08652954:: @ 0x08652954
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08652954.bin"

	.align 2
gDirectSound_086532FC:: @ 0x086532FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086532FC.bin"

	.align 2
gDirectSound_0865502C:: @ 0x0865502C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865502C.bin"

	.align 2
gDirectSound_08655BE4:: @ 0x08655BE4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08655BE4.bin"

	.align 2
gDirectSound_086572B8:: @ 0x086572B8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086572B8.bin"

	.align 2
gDirectSound_08657C58:: @ 0x08657C58
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08657C58.bin"

	.align 2
gDirectSound_08658F2C:: @ 0x08658F2C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08658F2C.bin"

	.align 2
gDirectSound_0865B6A4:: @ 0x0865B6A4
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865B6A4.bin"

	.align 2
gDirectSound_0865BE78:: @ 0x0865BE78
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865BE78.bin"

	.align 2
gDirectSound_0865D280:: @ 0x0865D280
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865D280.bin"

	.align 2
gDirectSound_0865F25C:: @ 0x0865F25C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0865F25C.bin"

	.align 2
gDirectSound_0866125C:: @ 0x0866125C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866125C.bin"

	.align 2
gDirectSound_08662960:: @ 0x08662960
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08662960.bin"

	.align 2
gDirectSound_086635F8:: @ 0x086635F8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086635F8.bin"

	.align 2
gDirectSound_08664180:: @ 0x08664180
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08664180.bin"

	.align 2
gDirectSound_08665298:: @ 0x08665298
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08665298.bin"

	.align 2
gDirectSound_08665BE0:: @ 0x08665BE0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08665BE0.bin"

	.align 2
gDirectSound_08666F6C:: @ 0x08666F6C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08666F6C.bin"

	.align 2
gDirectSound_08667D24:: @ 0x08667D24
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08667D24.bin"

	.align 2
gDirectSound_086688C8:: @ 0x086688C8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086688C8.bin"

	.align 2
gDirectSound_08669448:: @ 0x08669448
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08669448.bin"

	.align 2
gDirectSound_08669D74:: @ 0x08669D74
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08669D74.bin"

	.align 2
gDirectSound_0866B24C:: @ 0x0866B24C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866B24C.bin"

	.align 2
gDirectSound_0866CBF0:: @ 0x0866CBF0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866CBF0.bin"

	.align 2
gDirectSound_0866E020:: @ 0x0866E020
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866E020.bin"

	.align 2
gDirectSound_0866E4FC:: @ 0x0866E4FC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0866E4FC.bin"

	.align 2
gDirectSound_08670A08:: @ 0x08670A08
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08670A08.bin"

	.align 2
gDirectSound_08672DC0:: @ 0x08672DC0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08672DC0.bin"

	.align 2
gDirectSound_08674AEC:: @ 0x08674AEC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08674AEC.bin"

	.align 2
gDirectSound_08676408:: @ 0x08676408
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08676408.bin"

	.align 2
gDirectSound_086770C8:: @ 0x086770C8
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086770C8.bin"

	.align 2
gDirectSound_086779A0:: @ 0x086779A0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086779A0.bin"

	.align 2
gDirectSound_0867983C:: @ 0x0867983C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867983C.bin"

	.align 2
gDirectSound_0867B900:: @ 0x0867B900
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867B900.bin"

	.align 2
gDirectSound_0867D560:: @ 0x0867D560
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867D560.bin"

	.align 2
gDirectSound_0867E0F0:: @ 0x0867E0F0
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867E0F0.bin"

	.align 2
gDirectSound_0867FD38:: @ 0x0867FD38
	.incbin "sound/direct_sound_samples/cries/gDirectSound_0867FD38.bin"

	.align 2
gDirectSound_08680A60:: @ 0x08680A60
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08680A60.bin"

	.align 2
gDirectSound_08683470:: @ 0x08683470
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08683470.bin"

	.align 2
gDirectSound_08683C94:: @ 0x08683C94
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08683C94.bin"

	.align 2
gDirectSound_08684D9C:: @ 0x08684D9C
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08684D9C.bin"

	.align 2
gDirectSound_08686394:: @ 0x08686394
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08686394.bin"

	.align 2
gDirectSound_08687118:: @ 0x08687118
	.incbin "sound/direct_sound_samples/cries/gDirectSound_08687118.bin"

	.align 2
gDirectSound_086885EC:: @ 0x086885EC
	.incbin "sound/direct_sound_samples/cries/gDirectSound_086885EC.bin"

.include "sound/songs/mus_title.s"
.include "sound/songs/mus_table_select.s"
.include "sound/songs/mus_ereader.s"
.include "sound/songs/mus_unk_6.s"
.include "sound/songs/mus_opening.s"
.include "sound/songs/mus_high_score.s"
.include "sound/songs/mus_shop.s"
.include "sound/songs/mus_slots_prize.s"
.include "sound/songs/mus_end_of_ball.s"
.include "sound/songs/mus_bonus_chance.s"
.include "sound/songs/mus_bonus_chance_legendary.s"
.include "sound/songs/mus_travel_mode_start.s"
.include "sound/songs/mus_success.s"
.include "sound/songs/mus_success2.s"
.include "sound/songs/mus_end_of_ball2.s"
.include "sound/songs/mus_prize_awarded.s"
.include "sound/songs/mus_egg_mode.s"
.include "sound/songs/mus_egg_mode_start.s"
.include "sound/songs/mus_travel_mode.s"
.include "sound/songs/mus_unk_18.s"
.include "sound/songs/mus_hurry_up.s"
.include "sound/songs/mus_evolution.s"
.include "sound/songs/mus_field_ruby.s"
.include "sound/songs/mus_catch_em_mode.s"
.include "sound/songs/mus_evo_mode.s"
.include "sound/songs/mus_field_sapphire.s"
.include "sound/songs/mus_catch_em_mode2.s"
.include "sound/songs/mus_evo_mode2.s"
.include "sound/songs/mus_bonus_field_kecleon.s"
.include "sound/songs/mus_bonus_field_duskull.s"
.include "sound/songs/mus_bonus_field_dusclops.s"
.include "sound/songs/mus_bonus_field_spheal.s"
.include "sound/songs/mus_bonus_field_groudon.s"
.include "sound/songs/mus_bonus_field_kyogre.s"
.include "sound/songs/mus_bonus_field_rayquaza.s"
.include "sound/songs/mus_success3.s"
.include "sound/songs/mus_end_of_ball3.s"
.include "sound/songs/mus_pokedex.s"
.include "sound/songs/mus_jirachi.s"
.include "sound/songs/mus_field_ruby2.s"
.include "sound/songs/mus_field_sapphire2.s"
.include "sound/songs/mus_unk_5d.s"
.include "sound/songs/se_menu_select.s"
.include "sound/songs/se_menu_cancel.s"
.include "sound/songs/se_menu_move.s"
.include "sound/songs/se_menu_popup_open.s"
.include "sound/songs/se_menu_popup_close.s"
.include "sound/songs/se_score_entry_a_b_move.s"
.include "sound/songs/se_score_entry_letter_change.s"
.include "sound/songs/se_unused_0x6c.s"
.include "sound/songs/se_dex_info_field_select_move.s"
.include "sound/songs/se_unused_0x6e.s"
.include "sound/songs/se_unused_0x6f.s"
.include "sound/songs/se_unk_71.s"
.include "sound/songs/se_flipper_pressed.s"
.include "sound/songs/se_slingshot_hit.s"
.include "sound/songs/se_pokemon_catch_hit.s"
.include "sound/songs/se_pichu_in_position_chirp.s"
.include "sound/songs/se_trigger_button_hit.s"
.include "sound/songs/se_wall_hit.s"
.include "sound/songs/se_tilt_triggered.s"
.include "sound/songs/se_pika_spinner_clack.s"
.include "sound/songs/se_pika_full_charge_1_up.s"
.include "sound/songs/se_unk_7b.s"
.include "sound/songs/se_kickback_thunderwave.s"
.include "sound/songs/se_unused_0x7d.s"
.include "sound/songs/se_coin_collected.s"
.include "sound/songs/se_unused_0x7f.s"
.include "sound/songs/se_center_hole_eject.s"
.include "sound/songs/se_roulette_tick.s"
.include "sound/songs/se_evo_selection_move.s"
.include "sound/songs/se_evo_selection_confirm.s"
.include "sound/songs/se_evo_item_appear.s"
.include "sound/songs/se_evo_item_finish_appear.s"
.include "sound/songs/se_evo_item_collected.s"
.include "sound/songs/se_ball_upgrade.s"
.include "sound/songs/se_unused_0x88.s"
.include "sound/songs/se_unused_0x89.s"
.include "sound/songs/se_failure.s"
.include "sound/songs/se_catch_evo_banner.s"
.include "sound/songs/se_catch_tile_reveal.s"
.include "sound/songs/se_catch_all_reveal_lightning.s"
.include "sound/songs/se_catch_all_reveal_shatter.s"
.include "sound/songs/se_shop_list_reveal.s"
.include "sound/songs/se_bonus_score_tallied.s"
.include "sound/songs/se_hatch_flourish.s"
.include "sound/songs/se_area_roulette_selected.s"
.include "sound/songs/se_ball_saved.s"
.include "sound/songs/se_lati_delivery.s"
.include "sound/songs/se_saver_plunger_drop.s"
.include "sound/songs/se_travel_painter_flight.s"
.include "sound/songs/se_travel_painter_paints.s"
.include "sound/songs/se_evo_get_arrow_earned.s"
.include "sound/songs/se_mon_catch_ball_woosh.s"
.include "sound/songs/se_mon_catch_energy_beam.s"
.include "sound/songs/se_mon_catch_ball_close.s"
.include "sound/songs/se_mon_catch_ball_hit_ground.s"
.include "sound/songs/se_mon_catch_ball_shake.s"
.include "sound/songs/se_warp.s"
.include "sound/songs/se_unused_0xa0.s"
.include "sound/songs/se_ball_summary_text_progress.s"
.include "sound/songs/se_ball_summary_page_swipe.s"
.include "sound/songs/se_pause_cursor_move.s"
.include "sound/songs/se_bonus_panel_slide.s"
.include "sound/songs/se_pausing.s"
.include "sound/songs/se_unpausing.s"
.include "sound/songs/se_catch_mon_entity_appears.s"
.include "sound/songs/se_pika_charge_do.s"
.include "sound/songs/se_pika_charge_re.s"
.include "sound/songs/se_pika_charge_mi.s"
.include "sound/songs/se_pika_charge_fa.s"
.include "sound/songs/se_pika_charge_so.s"
.include "sound/songs/se_pika_charge_la.s"
.include "sound/songs/se_pika_charge_ti.s"
.include "sound/songs/se_pika_charge_high_do.s"
.include "sound/songs/se_evo_cutscene_mon_portrait_change.s"
.include "sound/songs/se_pikachu_kickback.s"
.include "sound/songs/se_pichu_kickback_enabled.s"
.include "sound/songs/se_pichu_kickback.s"
.include "sound/songs/se_unused_0xb4.s"
.include "sound/songs/se_ruby_bumper_hit.s"
.include "sound/songs/se_cyndaquil_egg_guard_hit.s"
.include "sound/songs/se_aerodactyl_egg_flight.s"
.include "sound/songs/se_cyndaquil_ball_eject_after_egg_arrival.s"
.include "sound/songs/se_unused_0xba.s"
.include "sound/songs/se_unused_0xbb.s"
.include "sound/songs/se_unused_0xbc.s"
.include "sound/songs/se_ruby_mart_gate_open.s"
.include "sound/songs/se_unused_0xbe.s"
.include "sound/songs/se_unused_0xbf.s"
.include "sound/songs/se_unused_0xc0.s"
.include "sound/songs/se_unused_0xc1.s"
.include "sound/songs/se_sharpedo_ball_eject.s"
.include "sound/songs/se_shop_eject.s"
.include "sound/songs/se_unused_0xc4.s"
.include "sound/songs/se_makuhita_punch.s"
.include "sound/songs/se_chikorita_leaf_blade.s"
.include "sound/songs/se_zigzagoon_emerge.s"
.include "sound/songs/se_ruby_bumper_emerges.s"
.include "sound/songs/se_ruby_bumper_leaves.s"
.include "sound/songs/se_ruby_mart_sign_changed.s"
.include "sound/songs/se_unused_0xcb.s"
.include "sound/songs/se_spoink_launcher_charged.s"
.include "sound/songs/se_spoink_launcher_fired.s"
.include "sound/songs/se_sharpedo_bite.s"
.include "sound/songs/se_nuzleaf_hit.s"
.include "sound/songs/se_nuzleaf_teetering.s"
.include "sound/songs/se_nuzleaf_forms_bridge.s"
.include "sound/songs/se_gulpin_lands_or_leaves.s"
.include "sound/songs/se_whiscash_emerge_splash.s"
.include "sound/songs/se_whiscash_leave_burble.s"
.include "sound/songs/se_whiscash_catch_ball.s"
.include "sound/songs/se_whiscash_spit_ball.s"
.include "sound/songs/se_whiscash_splashdown.s"
.include "sound/songs/se_ramp_prize_collected.s"
.include "sound/songs/se_hatch_machine_spinner_trigger.s"
.include "sound/songs/se_mon_lands_on_hatch_machine_top.s"
.include "sound/songs/se_hatch_machine_stage_advance.s"
.include "sound/songs/se_hatch_machine_egg_hatch.s"
.include "sound/songs/se_hatch_machine_elevator.s"
.include "sound/songs/se_hatch_machine_elevator_top.s"
.include "sound/songs/se_pelipper_ball_grab.s"
.include "sound/songs/se_pelipper_wing_flap.s"
.include "sound/songs/se_pelipper_swoosh.s"
.include "sound/songs/se_pelipper_ball_drop_lands.s"
.include "sound/songs/se_sapphire_mart_gate_trigger.s"
.include "sound/songs/se_sapphire_mart_gate_replaced.s"
.include "sound/songs/se_sapphire_mart_gate_hit.s"
.include "sound/songs/se_seedot_falling.s"
.include "sound/songs/se_seedot_lands.s"
.include "sound/songs/se_seedot_leaves.s"
.include "sound/songs/se_zigzagoon_roulette_stop.s"
.include "sound/songs/se_duskull_appear.s"
.include "sound/songs/se_duskull_death_cry.s"
.include "sound/songs/se_dusclops_depart_incomplete.s"
.include "sound/songs/se_dusclops_move.s"
.include "sound/songs/se_dusclops_appear.s"
.include "sound/songs/se_dusclops_hit.s"
.include "sound/songs/se_dusclops_ball_absorb.s"
.include "sound/songs/se_dusclops_ball_launch.s"
.include "sound/songs/se_bonus_board_ball_spawn.s"
.include "sound/songs/se_unused_0xfa.s"
.include "sound/songs/se_kecleon_side_look.s"
.include "sound/songs/se_kecleon_vanish.s"
.include "sound/songs/se_kecleon_startled.s"
.include "sound/songs/se_kecleon_running.s"
.include "sound/songs/se_kecleon_knocked_over.s"
.include "sound/songs/se_kecleon_hit_damaged.s"
.include "sound/songs/se_kecleon_hits_ground_defeated.s"
.include "sound/songs/se_kecleon_seeing_stars.s"
.include "sound/songs/se_kecleon_tree_hit.s"
.include "sound/songs/se_kecleon_scope_fall.s"
.include "sound/songs/se_kecleon_scope_activated.s"
.include "sound/songs/se_kyogre_hit.s"
.include "sound/songs/se_kyogre_breach_surface.s"
.include "sound/songs/se_kyogre_dive.s"
.include "sound/songs/se_kyogre_spawn_whirlpool.s"
.include "sound/songs/se_kyogre_freeze_ring.s"
.include "sound/songs/se_kyogre_departs.s"
.include "sound/songs/se_kyogre_freeze_hits_ball.s"
.include "sound/songs/se_kyogre_freeze_crack.s"
.include "sound/songs/se_kyogre_freeze_escaped.s"
.include "sound/songs/se_kyogre_whirlpool_grabs_ball.s"
.include "sound/songs/se_groudon_hit.s"
.include "sound/songs/se_groudon_step.s"
.include "sound/songs/se_groudon_intro_leap.s"
.include "sound/songs/se_groudon_lands.s"
.include "sound/songs/se_groudon_spits_fire.s"
.include "sound/songs/se_groudon_fire_ring.s"
.include "sound/songs/se_groudon_fire_grab_resist.s"
.include "sound/songs/se_groudon_fire_grab.s"
.include "sound/songs/se_groudon_fireball_connects.s"
.include "sound/songs/se_groudon_boulder_land.s"
.include "sound/songs/se_groudon_dustorm_lift.s"
.include "sound/songs/se_groudon_ball_hit_fire.s"
.include "sound/songs/se_rayquaza_hit.s"
.include "sound/songs/se_rayquaza_wind.s"
.include "sound/songs/se_rayquaza_lightning_charge.s"
.include "sound/songs/se_rayquaza_flyby.s"
.include "sound/songs/se_rayquaza_lightning_trap.s"
.include "sound/songs/se_rayquaza_whirlwind_ball_launch.s"
.include "sound/songs/se_rayquaza_whirlwind_ball_land.s"
.include "sound/songs/se_rayquaza_sonic_boom.s"
.include "sound/songs/se_rayquaza_stage_wind.s"
.include "sound/songs/se_spheal_surfacing.s"
.include "sound/songs/se_spheal_submerging.s"
.include "sound/songs/se_spheal_submerging_after_scoring.s"
.include "sound/songs/se_spheal_hit.s"
.include "sound/songs/se_spheal_net_swoosh.s"
.include "sound/songs/se_spheal_crowd_cheer.s"
.include "sound/songs/se_spheal_end_whistle.s"
.include "sound/songs/se_sealeo_hit_thud.s"
.include "sound/songs/se_sealeo_nose_bounce.s"
.include "sound/songs/se_spheal_land_under_net.s"
.include "sound/songs/se_unused_0x13f.s"
.include "sound/songs/se_spheal_surface_at_ramp.s"
.include "sound/songs/se_pika_no_kickback.s"
.include "sound/songs/se_jirachi_move.s"
.include "sound/songs/se_jirachi_hit.s"
.include "sound/songs/se_totodile_lowers_rope.s"
.include "sound/songs/se_totodile_slides_down.s"
.include "sound/songs/se_totodile_places_egg.s"
.include "sound/songs/se_totodile_climbs_rope.s"
.include "sound/songs/se_highest_score_earned.s"
.include "sound/songs/se_high_score_earned.s"
.include "sound/songs/se_whiscash_earthquake.s"
