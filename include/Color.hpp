#include <SDL3/SDL.h>
struct Color {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
    // Constructor
    constexpr Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255)
        : r(red), g(green), b(blue), a(alpha) {
    }

    // === Hex constructor (0xRRGGBB) ===
    constexpr Color(uint32_t hex, Uint8 alpha = 255)
        : r(static_cast<Uint8>((hex >> 16) & 0xFF)),
        g(static_cast<Uint8>((hex >> 8) & 0xFF)),
        b(static_cast<Uint8>(hex & 0xFF)),
        a(alpha) {
    }


    // default = black, opaque
    constexpr Color() : r(0), g(0), b(0), a(255) {}

    // === Static constants ===
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color White;
    static const Color Black;
    static const Color Transparent;

    static constexpr Color FromHex(uint32_t hex, Uint8 alpha = 255) {
        return Color(
            static_cast<Uint8>((hex >> 16) & 0xFF),
            static_cast<Uint8>((hex >> 8) & 0xFF),
            static_cast<Uint8>(hex & 0xFF),
            alpha
        );
    }
};


