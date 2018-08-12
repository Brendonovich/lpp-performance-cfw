#include "modes/special/boot.h"

u8 boot_note_elapsed = boot_note_tick;

u8 boot_notes[boot_note_length][boot_notes_per_frame] = { // Element [0] is array length
	{5, 89, 78, 67, 56, 45},
	{5, 79, 68, 57, 46, 55},
	{4, 69, 58, 47, 36},
	{4, 59, 48, 37, 35},
	{4, 49, 38, 27, 65},
	{4, 39, 28, 26, 66},
	{3, 29, 18, 25},
	{3, 19, 17, 75},
	{2, 16, 76},
	{3, 8, 15, 77},
	{2, 7, 85},
	{2, 6, 86},
	{2, 5, 87},
	{3, 95, 88, 99},
	{1, 96},
	{1, 97},
	{1, 98}
};
u8 boot_note_floor = 0;
u8 boot_note_ceil = 0;

u8 boot_fade_elapsed = boot_fade_tick;
u8 boot_fade_counter[16] = {};

u8 boot_colors[boot_colors_length][3] = {{0, 0, 1}, {0, 0, 2}, {0, 0, 3}, {0, 0, 4}, {0, 0, 5}, {0, 0, 6}, {0, 0, 7}, {0, 0, 8}, {0, 0, 9}, {0, 0, 10}, {0, 0, 11}, {0, 0, 12}, {0, 0, 13}, {0, 0, 14}, {0, 0, 15}, {0, 0, 16}, {0, 0, 17}, {0, 0, 18}, {0, 0, 19}, {0, 0, 20}, {0, 0, 21}, {0, 0, 22}, {0, 0, 23}, {0, 0, 24}, {0, 0, 25}, {0, 0, 26}, {0, 0, 27}, {0, 0, 28}, {0, 0, 29}, {0, 0, 30}, {0, 0, 31}, {0, 0, 32}, {0, 0, 33}, {0, 0, 34}, {0, 0, 35}, {0, 0, 36}, {0, 0, 37}, {0, 0, 38}, {0, 0, 39}, {0, 0, 40}, {0, 0, 41}, {0, 0, 42}, {0, 0, 43}, {0, 0, 44}, {0, 0, 45}, {0, 0, 46}, {0, 0, 47}, {0, 0, 48}, {0, 0, 49}, {0, 0, 50}, {0, 0, 51}, {0, 0, 52}, {0, 0, 53}, {0, 0, 54}, {0, 0, 55}, {0, 0, 56}, {0, 0, 57}, {0, 0, 58}, {0, 0, 59}, {0, 0, 60}, {0, 0, 61}, {0, 0, 62}, {0, 0, 63}, {1, 0, 63}, {2, 0, 63}, {3, 0, 63}, {4, 0, 63}, {5, 0, 63}, {6, 0, 63}, {7, 0, 63}, {8, 0, 63}, {9, 0, 63}, {10, 0, 63}, {11, 0, 63}, {12, 0, 63}, {13, 0, 63}, {14, 0, 63}, {15, 0, 63}, {16, 0, 63}, {17, 0, 63}, {18, 0, 63}, {19, 0, 63}, {20, 0, 63}, {21, 0, 63}, {22, 0, 63}, {23, 0, 63}, {24, 0, 63}, {25, 0, 63}, {26, 0, 63}, {27, 0, 63}, {28, 0, 63}, {29, 0, 63}, {30, 0, 63}, {31, 0, 63}, {32, 0, 63}, {33, 0, 63}, {34, 0, 63}, {35, 0, 63}, {36, 0, 63}, {37, 0, 63}, {38, 0, 63}, {39, 0, 63}, {40, 0, 63}, {41, 0, 63}, {42, 0, 63}, {43, 0, 63}, {44, 0, 63}, {45, 0, 63}, {46, 0, 63}, {47, 0, 63}, {48, 0, 63}, {49, 0, 63}, {50, 0, 63}, {51, 0, 63}, {52, 0, 63}, {53, 0, 63}, {54, 0, 63}, {55, 0, 63}, {56, 0, 63}, {57, 0, 63}, {58, 0, 63}, {59, 0, 63}, {60, 0, 63}, {61, 0, 63}, {62, 0, 63}, {63, 0, 63}, {63, 0, 62}, {63, 0, 61}, {63, 0, 60}, {63, 0, 59}, {63, 0, 58}, {63, 0, 57}, {63, 0, 56}, {63, 0, 55}, {63, 0, 54}, {63, 0, 53}, {63, 0, 52}, {63, 0, 51}, {63, 0, 50}, {63, 0, 49}, {63, 0, 48}, {63, 0, 47}, {63, 0, 46}, {63, 0, 45}, {63, 0, 44}, {63, 0, 43}, {63, 0, 42}, {63, 0, 41}, {63, 0, 40}, {63, 0, 39}, {63, 0, 38}, {63, 0, 37}, {63, 0, 36}, {63, 0, 35}, {63, 0, 34}, {63, 0, 33}, {63, 0, 32}, {63, 0, 31}, {63, 0, 30}, {63, 0, 29}, {63, 0, 28}, {63, 0, 27}, {63, 0, 26}, {63, 0, 25}, {63, 0, 24}, {63, 0, 23}, {63, 0, 22}, {63, 0, 21}, {63, 0, 20}, {63, 0, 19}, {63, 0, 18}, {63, 0, 17}, {63, 0, 16}, {63, 0, 15}, {63, 0, 14}, {63, 0, 13}, {63, 0, 12}, {63, 0, 11}, {63, 0, 10}, {63, 0, 9}, {63, 0, 8}, {63, 0, 7}, {63, 0, 6}, {63, 0, 5}, {63, 0, 4}, {63, 0, 3}, {63, 0, 2}, {63, 0, 1}, {63, 0, 0}, {62, 0, 0}, {61, 0, 0}, {60, 0, 0}, {59, 0, 0}, {58, 0, 0}, {57, 0, 0}, {56, 0, 0}, {55, 0, 0}, {54, 0, 0}, {53, 0, 0}, {52, 0, 0}, {51, 0, 0}, {50, 0, 0}, {49, 0, 0}, {48, 0, 0}, {47, 0, 0}, {46, 0, 0}, {45, 0, 0}, {44, 0, 0}, {43, 0, 0}, {42, 0, 0}, {41, 0, 0}, {40, 0, 0}, {39, 0, 0}, {38, 0, 0}, {37, 0, 0}, {36, 0, 0}, {35, 0, 0}, {34, 0, 0}, {33, 0, 0}, {32, 0, 0}, {31, 0, 0}, {30, 0, 0}, {29, 0, 0}, {28, 0, 0}, {27, 0, 0}, {26, 0, 0}, {25, 0, 0}, {24, 0, 0}, {23, 0, 0}, {22, 0, 0}, {21, 0, 0}, {20, 0, 0}, {19, 0, 0}, {18, 0, 0}, {17, 0, 0}, {16, 0, 0}, {15, 0, 0}, {14, 0, 0}, {13, 0, 0}, {12, 0, 0}, {11, 0, 0}, {10, 0, 0}, {9, 0, 0}, {8, 0, 0}, {7, 0, 0}, {6, 0, 0}, {5, 0, 0}, {4, 0, 0}, {3, 0, 0}, {2, 0, 0}, {1, 0, 0}, {0, 0, 0}};

void boot_init() {}

void boot_timer_event() {
	if (++boot_note_elapsed >= boot_note_tick) { // Start fading next note
		if (boot_note_ceil < boot_note_length) boot_note_ceil++;
		
		boot_note_elapsed = 0;
	}
	
	if (++boot_fade_elapsed >= boot_fade_tick) { // Redraw fades
		if (boot_note_floor == boot_note_length) { // Enter Performance mode (end condition)
			mode_update(mode_performance);
		
		} else {
			for (u8 i = boot_note_floor; i < boot_note_ceil; i++) {
				if (boot_fade_counter[i] < boot_colors_length) { // Draw next fade for note
					for (u8 j = 1; j <= boot_notes[i][0]; j++) { // For each note in frame
						if (boot_notes[i][j] != 98 || boot_fade_counter[i] <= boot_user_stop) { // Check for leaving User LED on
							rgb_led(boot_notes[i][j], boot_colors[boot_fade_counter[i]][0], boot_colors[boot_fade_counter[i]][1], boot_colors[boot_fade_counter[i]][2]);
						}
						
						if (boot_rotate_180) rgb_led(99 - boot_notes[i][j], boot_colors[boot_fade_counter[i]][0], boot_colors[boot_fade_counter[i]][1], boot_colors[boot_fade_counter[i]][2]);
					}
					boot_fade_counter[i]++;
					
				} else { // Stop fading a finished note
					boot_note_floor++;
				}
			}
		}
		
		boot_fade_elapsed = 0;
	}
}

void boot_surface_event(u8 p, u8 v, u8 x, u8 y) {
	if (p == 0 && v != 0) mode_update(mode_performance); // Manually interrupt boot animation
}

void boot_midi_event(u8 port, u8 t, u8 ch, u8 p, u8 v) {}