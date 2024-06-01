#pragma once

#include "mcu.h"
#include <core/io/json.h>
#include <scene/resources/font.h>
#include <scene/resources/image_texture.h>
#include <scene/resources/style_box.h>
#include <scene/resources/style_box_flat.h>
#include <scene/resources/style_box_line.h>
#include <scene/resources/theme.h>
#include <scene/theme/theme_db.h>
using namespace godot;

inline Color blend_alpha(Color color, float alpha, Color bg = Color(0, 0, 0)) {
	return color.blend(Color(bg.r, bg.g, bg.b, alpha));
}
inline Color hovered(Color color, Color bg = Color(0, 0, 0)) { return blend_alpha(color, 0.08f, bg); }
inline Color pressed(Color color, Color bg = Color(0, 0, 0)) { return blend_alpha(color, 0.1f, bg); }
inline Color disabled(Color color) { return Color(color.r, color.g, color.b, 0.38f); }
Ref<ImageTexture> image_blend(Ref<Texture2D> icon, Color color, float alpha = 0.5);

class MTheme : public Theme {
	GDCLASS(MTheme, Theme);

	bool dark = true;
	Color theme_color = Color(103.0f / 255, 80.0f / 255, 164.0f / 255);

	template <typename Fn>
	void reset_style_box(StringName name, StringName theme_type, Fn set_box) {
		set_box(this->get_stylebox(name, theme_type));
	};

	void reset_style_box_flat_color(StringName name, StringName theme_type, const Color *bg = nullptr, const Color *border = nullptr);

	void set_icon_color(const StringName &name, const StringName &theme_type, Color color, float alpha = 0.5) {
		this->set_icon(name, theme_type, image_blend(this->get_icon(name, theme_type), color, alpha));
	}

protected:
	static void _bind_methods();

public:
	MTheme() {
		update_theme();
	}
	void update_theme() {
		merge_with(ThemeDB::get_singleton()->get_default_theme());
		fill_theme(Mcu::get_scheme(theme_color, dark));
	}

	bool is_dark() { return dark; };
	Color get_theme_color() { return theme_color; }

	void set_dark(bool value) { dark = value; }
	void set_theme_color(Color value) { theme_color = value; }

	void fill_theme(Dictionary contrast);
};
