#pragma once

#include "material_color_utilities/cam/cam.h"
#include "material_color_utilities/scheme/scheme.h"

#include <core/io/resource.h>

using namespace godot;
namespace mcu = material_color_utilities;

inline Color argb2color(mcu::Argb c) {
	return Color(((0x00FF0000 & c) >> 16) / 255.0f, ((0x0000FF00 & c) >> 8) / 255.0f, (0x000000FF & c) / 255.0f, ((0xFF000000 & c) >> 24) / 255.0f);
}
inline mcu::Argb color2argb(Color c) {
	return (c.get_a8() << 24) | (c.get_r8() << 16) | (c.get_g8() << 8) | c.get_b8();
}

class Mcu : public RefCounted {
	GDCLASS(Mcu, RefCounted);

protected:
	static void _bind_methods();

public:
	enum Contrast {
		primary,
		onPrimary,
		primaryContainer,
		onPrimaryContainer,
		secondary,
		onSecondary,
		secondaryContainer,
		onSecondaryContainer,
		tertiary,
		onTertiary,
		tertiaryContainer,
		onTertiaryContainer,
		error,
		onError,
		errorContainer,
		onErrorContainer,
		background,
		onBackground,
		surface,
		onSurface,
		surfaceVariant,
		onSurfaceVariant,
		outline,
		outlineVariant,
		shadow,
		scrim,
		inverseSurface,
		inverseOnSurface,
		inversePrimary,

		surfaceContainer,
		surfaceContainerHigh,
	};

	static Dictionary get_scheme(Color c, bool is_dark = true);
};

class Hct : public Resource {
	GDCLASS(Hct, Resource);

	mcu::Hct hct = mcu::Hct(0, 0, 0);

protected:
	static void _bind_methods();

public:
	double get_hue() { return hct.get_hue(); };
	double get_chroma() { return hct.get_chroma(); };
	double get_tone() { return hct.get_tone(); };
	void set_hue(double hue) { hct.set_hue(hue); };
	void set_chroma(double chroma) { hct.set_chroma(chroma); };
	void set_tone(double tone) { hct.set_tone(tone); };

	Color to_color() { return argb2color(this->to_argb()); };
	mcu::Argb to_argb() { return hct.ToInt(); };

	static Ref<Hct> from_hct(double hue, double chroma, double tone) {
		Ref<Hct> res = memnew(Hct);
		res->hct = mcu::Hct(hue, chroma, tone);
		return res;
	};

	static Ref<Hct> from_color(Color c) {
		return from_argb(color2argb(c));
	};

	static Ref<Hct> from_argb(mcu::Argb argb) {
		Ref<Hct> res = memnew(Hct);
		res->hct = mcu::Hct(argb);
		return res;
	};
};
VARIANT_ENUM_CAST(Mcu::Contrast);
