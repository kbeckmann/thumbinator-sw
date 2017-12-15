#include "effect.h"

#include <stdbool.h>
#include <stdint.h>

#include "ws2812b.h"
#include "hsv.h"

#define NUM_LEDS 97
#define V_MAX 127

static int current_effect;
static uint8_t g_pixels[2][NUM_LEDS * 3];
typedef void (*effect_render_cb)(uint32_t t, uint8_t * p_pixels, uint32_t num_bytes);

void render_colors(uint32_t t, uint8_t * p_pixels, uint32_t num_bytes)
{
    uint8_t h, s, v;

    for (int i = 0; i < num_bytes; i += 3) {
        uint8_t r, g, b;
        h = i % 255 + t;
        s = 255;
        v = V_MAX;

        hsvtorgb(&r, &g, &b, h, s, v);
        p_pixels[i]     = g;
        p_pixels[i + 1] = r;
        p_pixels[i + 2] = b;
    }
}

void render_constant(uint32_t t, uint8_t * p_pixels, uint32_t num_bytes)
{
    uint8_t h, s, v;
    uint8_t r, g, b;

    h = t;
    s = 255;
    v = V_MAX;
    hsvtorgb(&r, &g, &b, h, s, v);

    for (int i = 0; i < num_bytes; i += 3) {
        p_pixels[i]     = g;
        p_pixels[i + 1] = r;
        p_pixels[i + 2] = b;
    }
}

static effect_render_cb effects[] = {
    render_colors,
    render_constant,
};

static int effect_count = sizeof(effects)/sizeof(effects[0]);

void effect_next(void)
{
    current_effect = (current_effect + 1) % effect_count;
}

void effect_show(uint32_t t)
{
    effects[current_effect](t, g_pixels[0], sizeof(g_pixels[0]));
    effects[current_effect](t, g_pixels[1], sizeof(g_pixels[1]));

    ws2812b_write(g_pixels[0], sizeof(g_pixels[0]), CONN_11_GPIO_Port, CONN_11_Pin);
    ws2812b_write(g_pixels[1], sizeof(g_pixels[1]), CONN_12_GPIO_Port, CONN_12_Pin);
}
