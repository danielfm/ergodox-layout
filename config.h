#ifndef CONFIG_USER_H
#define CONFIG_USER_H

// Should fix issues with duplicate keys being emitted by mistake
#define DEBOUNCE 15

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_ALPHA

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 5000

// Disable some effects to save firmware space
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_RAINDROPS

#endif
