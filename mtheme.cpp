#include "mtheme.h"

Ref<ImageTexture> image_blend(Ref<Texture2D> icon, Color color, float alpha) {
	Ref<Image> img = icon->get_image();
	for (int i = 0; i < img->get_width(); i++) {
		for (int j = 0; j < img->get_height(); j++) {
			if (img->get_pixel(i, j).a == 0) {
				continue;
			}
			img->set_pixel(i, j, img->get_pixel(i, j).blend(Color(color.r, color.g, color.b, alpha)));
		}
	}
	return ImageTexture::create_from_image(img);
}

void MTheme::reset_style_box_flat_color(StringName name, StringName theme_type, const Color *bg, const Color *border) {
	Ref<StyleBoxFlat> box;
	if (!this->get_stylebox(name, theme_type)->is_class("StyleBoxFlat")) {
		box.instantiate();
		box->set_content_margin_all(4);
		this->set_stylebox(name, theme_type, box);
	} else {
		box = this->get_stylebox(name, theme_type);
	}
	if (bg != nullptr) {
		box->set_bg_color(*bg);
	}
	if (border != nullptr) {
		box->set_border_color(*border);
	}
};

void MTheme::fill_theme(Dictionary contrast) {
	// scale = p_scale;
	// Default theme properties.
	// if (default_font != nullptr)
	// this->set_default_font(default_font);
	// this->set_default_font_size(Math::round(default_font_size * scale));
	// Ref<Font> default_font = this->get_default_font();
	// int default_font_size = this->get_default_font_size() <= 0 ? 16 : this->get_default_font_size();
	// float scale = this->get_default_base_scale() <= 0 ? 1 : this->get_default_base_scale();

	// Font colors
	// const Color control_font_color = Color(0.875, 0.875, 0.875);
	// const Color control_font_low_color = Color(0.7, 0.7, 0.7);
	// const Color control_font_lower_color = Color(0.65, 0.65, 0.65);
	// const Color control_font_hover_color = Color(0.95, 0.95, 0.95);
	// const Color control_font_focus_color = Color(0.95, 0.95, 0.95);
	// const Color control_font_disabled_color = control_font_color * Color(1, 1, 1, 0.5);
	// const Color control_font_placeholder_color = Color(control_font_color.r, control_font_color.g, control_font_color.b, 0.6f);
	// const Color control_font_pressed_color = Color(1, 1, 1);
	// const Color control_selection_color = Color(0.5, 0.5, 0.5);
	// std::cout << "can Convert: " << contrast[MaterialColorUtility::onSurfaceVariant].can_convert(godot::Variant::STRING, godot::Variant::COLOR) << std::endl;
	// std::cout << "Convert: " << contrast[MaterialColorUtility::onSurfaceVariant], Color()).to_html().utf8() << std::endl;
	// UtilityFunctions::print(contrast[MaterialColorUtility::onSurfaceVariant]);

	const Color control_font_color = contrast[Mcu::onSurfaceVariant]; // new Color(0.875f, 0.875f, 0.875f);
	const Color control_font_low_color = contrast[Mcu::onSurfaceVariant]; // new Color(0.7f, 0.7f, 0.7f);
	const Color control_font_lower_color = contrast[Mcu::onSurfaceVariant]; // new Color(0.65f, 0.65f, 0.65f);
	const Color control_font_hover_color = hovered(control_font_color, (contrast[Mcu::surface])); // new Color(0.95f, 0.95f, 0.95f);
	const Color control_font_focus_color = pressed(control_font_color, (contrast[Mcu::surface])); // new Color(0.95f, 0.95f, 0.95f);
	const Color control_font_disabled_color = disabled(control_font_color); // control_font_color * new Color(1, 1, 1, 0.5f);
	const Color control_font_placeholder_color = Color(control_font_color.r, control_font_color.g, control_font_color.b, 0.6f);
	const Color control_font_pressed_color = control_font_focus_color; // new Color(1, 1, 1);
	const Color control_selection_color = Color(control_font_color.r, control_font_color.g, control_font_color.b, 0.16f); // new Color(0.5f, 0.5f, 0.5f);
	// StyleBox colors
	// const Color style_normal_color = Color(0.1, 0.1, 0.1, 0.6);
	// const Color style_hover_color = Color(0.225, 0.225, 0.225, 0.6);
	// const Color style_pressed_color = Color(0, 0, 0, 0.6);
	// const Color style_disabled_color = Color(0.1, 0.1, 0.1, 0.3);
	// const Color style_focus_color = Color(1, 1, 1, 0.75);
	// const Color style_popup_color = Color(0.25, 0.25, 0.25, 1);
	// const Color style_popup_border_color = Color(0.175, 0.175, 0.175, 1);
	// const Color style_popup_hover_color = Color(0.4, 0.4, 0.4, 1);
	// const Color style_selected_color = Color(1, 1, 1, 0.3);
	// // Don't use a color too bright to keep the percentage readable.
	// const Color style_progress_color = Color(1, 1, 1, 0.4);
	// const Color style_separator_color = Color(0.5, 0.5, 0.5);
	// StyleBox colors
	const Color style_surface_container_color = contrast[Mcu::surfaceContainer];
	const Color style_surface_high_color = contrast[Mcu::surfaceContainerHigh];
	const Color style_surface_color = contrast[Mcu::surface]; //new Color(0.1f, 0.1f, 0.1f, 0.6f);
	const Color style_surface_hover_color = hovered(style_surface_color, contrast[Mcu::onSurface]); //new Color(0.225f, 0.225f, 0.225f, 0.6f);
	const Color style_surface_pressed_color = pressed(style_surface_color, (contrast[Mcu::onSurface])); //new Color(0, 0, 0, 0.6f);
	const Color style_surface_disabled_color = disabled(style_surface_color); //new Color(0.1f, 0.1f, 0.1f, 0.3f);
	const Color style_surface_focus_color = style_surface_pressed_color; //new Color(1, 1, 1, 0.75f);
	const Color style_popup_color = style_surface_high_color; //new Color(0.25f, 0.25f, 0.25f, 1);
	const Color style_popup_border_color = contrast[Mcu::outline];
	const Color style_popup_hover_color = hovered(style_popup_color, contrast[Mcu::onSurface]); //new Color(0.4f, 0.4f, 0.4f, 1);
	const Color style_selected_color = blend_alpha(style_surface_color, 0.16f, contrast[Mcu::onSurface]); //new Color(1, 1, 1, 0.3f);
	// Don't use a color too bright to keep the percentage readable.
	const Color style_progress_color = contrast[Mcu::primary]; //new Color(1, 1, 1, 0.4f);
	const Color style_progress_bg_color = contrast[Mcu::primaryContainer];
	const Color style_separator_color = contrast[Mcu::outlineVariant];

	const Color style_normal_color = contrast[Mcu::primary];
	const Color style_hover_color = hovered(style_normal_color);
	const Color style_pressed_color = pressed(style_normal_color); //new Color(0, 0, 0, 0.6f);
	const Color style_disabled_color = disabled(style_normal_color); //new Color(0.1f, 0.
	const Color style_focus_color_border = style_pressed_color;

	const Color style_font_color = contrast[Mcu::onPrimary];
	const Color style_font_pressed_color = pressed(style_font_color);
	const Color style_font_hover_color = hovered(style_font_color);
	const Color style_font_focus_color = style_font_pressed_color;
	const Color style_font_hover_pressed_color = style_font_pressed_color;
	const Color style_font_disabled_color = disabled(style_font_color);
	// Convert the generated icon sources to a dictionary for easier access.
	// Unlike the editor icons, there is no central repository of icons in the Theme resource itself to keep it tidy.
	// Dictionary icons;
	// for (int i = 0; i < default_theme_icons_count; i++) {
	// 	icons[default_theme_icons_names[i]] = generate_icon(i);
	// }

	// Panel
	this->reset_style_box_flat_color("panel", "Panel", &style_surface_color);

	// Button

	// Ref<StyleBoxFlat> button_normal = this->get_stylebox("normal", "Button");
	// Ref<StyleBoxFlat> button_hover = this->get_stylebox("hover", "Button");
	// Ref<StyleBoxFlat> button_pressed = this->get_stylebox("pressed", "Button");
	// Ref<StyleBoxFlat> button_disabled = this->get_stylebox("disabled", "Button");
	// Ref<StyleBoxFlat> button_focus = this->get_stylebox("focus", "Button");

	const Color button_normal = style_normal_color;
	const Color button_hover = style_hover_color;
	const Color button_pressed = style_pressed_color;
	const Color button_disabled = style_disabled_color;
	const Color button_focus_border = contrast[Mcu::inversePrimary];
	// Ref<StyleBoxFlat> focus = button_focus->duplicate();
	// focus->set_bg_color(style_focus_color);
	// Make the focus outline appear to be flush with the buttons it's focusing.
	// focus->set_border_color(style_focus_color);
	// focus->set_expand_margin_all(Math::round(2 * scale));

	// Ref<StyleBoxFlat> button_focus = focus->duplicate();

	this->reset_style_box_flat_color("normal", "Button", &button_normal);
	this->reset_style_box_flat_color("hover", "Button", &button_hover);
	this->reset_style_box_flat_color("pressed", "Button", &button_pressed);
	this->reset_style_box_flat_color("disabled", "Button", &button_disabled);
	this->reset_style_box_flat_color("focus", "Button", nullptr, &button_focus_border);

	// this->set_font("font", "Button", Ref<Font>());
	// this->set_font_size("font_size", "Button", -1);
	// this->set_constant("outline_size", "Button", 0);

	this->set_color("font_color", "Button", style_font_color);
	this->set_color("font_pressed_color", "Button", style_font_pressed_color);
	this->set_color("font_hover_color", "Button", style_font_hover_color);
	this->set_color("font_focus_color", "Button", style_font_focus_color);
	this->set_color("font_hover_pressed_color", "Button", style_font_pressed_color);
	this->set_color("font_disabled_color", "Button", style_font_disabled_color);
	// this->set_color("font_outline_color", "Button", Color(1, 1, 1));

	// this->set_color("icon_normal_color", "Button", Color(1, 1, 1, 1));
	// this->set_color("icon_pressed_color", "Button", Color(1, 1, 1, 1));
	// this->set_color("icon_hover_color", "Button", Color(1, 1, 1, 1));
	// this->set_color("icon_hover_pressed_color", "Button", Color(1, 1, 1, 1));
	// this->set_color("icon_focus_color", "Button", Color(1, 1, 1, 1));
	// this->set_color("icon_disabled_color", "Button", Color(1, 1, 1, 0.4));

	// this->set_constant("h_separation", "Button", Math::round(4 * scale));
	// this->set_constant("icon_max_width", "Button", 0);

	// MenuBar
	this->reset_style_box_flat_color("normal", "MenuBar", &button_normal);
	this->reset_style_box_flat_color("hover", "MenuBar", &button_hover);
	this->reset_style_box_flat_color("pressed", "MenuBar", &button_pressed);
	this->reset_style_box_flat_color("disabled", "MenuBar", &button_disabled);

	// this->set_font("font", "MenuBar", Ref<Font>());
	// this->set_font_size("font_size", "MenuBar", -1);
	// this->set_constant("outline_size", "MenuBar", 0);

	this->set_color("font_color", "MenuBar", style_font_color);
	this->set_color("font_pressed_color", "MenuBar", style_font_pressed_color);
	this->set_color("font_hover_color", "MenuBar", style_font_hover_color);
	this->set_color("font_focus_color", "MenuBar", style_font_focus_color);
	this->set_color("font_hover_pressed_color", "MenuBar", style_font_pressed_color);
	this->set_color("font_disabled_color", "MenuBar", style_font_disabled_color);
	// this->set_color("font_outline_color", "MenuBar", Color(1, 1, 1));

	// this->set_constant("h_separation", "MenuBar", Math::round(4 * scale));

	// LinkButton

	this->reset_style_box_flat_color("focus", "LinkButton", nullptr, &style_focus_color_border);

	// this->set_font("font", "LinkButton", Ref<Font>());
	// this->set_font_size("font_size", "LinkButton", -1);

	this->set_color("font_color", "LinkButton", style_normal_color);
	this->set_color("font_pressed_color", "LinkButton", style_pressed_color);
	this->set_color("font_hover_color", "LinkButton", style_hover_color);
	this->set_color("font_focus_color", "LinkButton", style_focus_color_border);
	// this->set_color("font_outline_color", "LinkButton", Color(1, 1, 1));

	// this->set_constant("outline_size", "LinkButton", 0);
	// this->set_constant("underline_spacing", "LinkButton", Math::round(2 * scale));

	// OptionButton
	this->reset_style_box_flat_color("focus", "OptionButton", nullptr, &style_focus_color_border);

	// Ref<StyleBox> sb_optbutton_normal = make_flat_stylebox(style_normal_color, 2 * default_margin, default_margin, 2 * default_margin, default_margin, default_corner_radius);
	// Ref<StyleBox> sb_optbutton_hover = make_flat_stylebox(style_hover_color, 2 * default_margin, default_margin, 2 * default_margin, default_margin, default_corner_radius);
	// Ref<StyleBox> sb_optbutton_pressed = make_flat_stylebox(style_pressed_color, 2 * default_margin, default_margin, 2 * default_margin, default_margin, default_corner_radius);
	// Ref<StyleBox> sb_optbutton_disabled = make_flat_stylebox(style_disabled_color, 2 * default_margin, default_margin, 2 * default_margin, default_margin, default_corner_radius);

	this->reset_style_box_flat_color("normal", "OptionButton", &style_normal_color);
	this->reset_style_box_flat_color("hover", "OptionButton", &style_hover_color);
	this->reset_style_box_flat_color("pressed", "OptionButton", &style_pressed_color);
	this->reset_style_box_flat_color("disabled", "OptionButton", &style_disabled_color);

	// Ref<StyleBox> sb_optbutton_normal_mirrored = make_flat_stylebox(style_normal_color, 2 * default_margin, default_margin, 2 * default_margin, default_margin, default_corner_radius);
	// Ref<StyleBox> sb_optbutton_hover_mirrored = make_flat_stylebox(style_hover_color, 2 * default_margin, default_margin, 2 * default_margin, default_margin, default_corner_radius);
	// Ref<StyleBox> sb_optbutton_pressed_mirrored = make_flat_stylebox(style_pressed_color, 2 * default_margin, default_margin, 2 * default_margin, default_margin, default_corner_radius);
	// Ref<StyleBox> sb_optbutton_disabled_mirrored = make_flat_stylebox(style_disabled_color, 2 * default_margin, default_margin, 2 * default_margin, default_margin, default_corner_radius);

	this->reset_style_box_flat_color("normal_mirrored", "OptionButton", &style_normal_color);
	this->reset_style_box_flat_color("hover_mirrored", "OptionButton", &style_hover_color);
	this->reset_style_box_flat_color("pressed_mirrored", "OptionButton", &style_pressed_color);
	this->reset_style_box_flat_color("disabled_mirrored", "OptionButton", &style_disabled_color);

	// this->set_icon("arrow", "OptionButton", icons["option_button_arrow"]);
	this->set_icon_color("arrow", "OptionButton", contrast[Mcu::inversePrimary]);

	// this->set_font("font", "OptionButton", Ref<Font>());
	// this->set_font_size("font_size", "OptionButton", -1);

	this->set_color("font_color", "OptionButton", style_font_color);
	this->set_color("font_pressed_color", "OptionButton", style_font_pressed_color);
	this->set_color("font_hover_color", "OptionButton", style_font_hover_color);
	this->set_color("font_hover_pressed_color", "OptionButton", style_font_pressed_color);
	this->set_color("font_focus_color", "OptionButton", style_font_focus_color);
	this->set_color("font_disabled_color", "OptionButton", style_font_disabled_color);
	// this->set_color("font_outline_color", "OptionButton", Color(1, 1, 1));

	// this->set_constant("h_separation", "OptionButton", Math::round(4 * scale));
	// this->set_constant("arrow_margin", "OptionButton", Math::round(4 * scale));
	// this->set_constant("outline_size", "OptionButton", 0);
	// this->set_constant("modulate_arrow", "OptionButton", false);

	// MenuButton

	this->reset_style_box_flat_color("normal", "MenuButton", &button_normal);
	this->reset_style_box_flat_color("pressed", "MenuButton", &button_pressed);
	this->reset_style_box_flat_color("hover", "MenuButton", &button_hover);
	this->reset_style_box_flat_color("disabled", "MenuButton", &button_disabled);
	this->reset_style_box_flat_color("focus", "MenuButton", nullptr, &button_focus_border);

	// this->set_font("font", "MenuButton", Ref<Font>());
	// this->set_font_size("font_size", "MenuButton", -1);

	this->set_color("font_color", "MenuButton", style_font_color);
	this->set_color("font_pressed_color", "MenuButton", style_font_pressed_color);
	this->set_color("font_hover_color", "MenuButton", style_font_hover_color);
	this->set_color("font_focus_color", "MenuButton", style_font_focus_color);
	// this->set_color("font_disabled_color", "MenuButton", Color(1, 1, 1, 0.3));
	// this->set_color("font_outline_color", "MenuButton", Color(1, 1, 1));

	// this->set_constant("h_separation", "MenuButton", Math::round(4 * scale));
	// this->set_constant("outline_size", "MenuButton", 0);

	// CheckBox

	// Ref<StyleBox> cbx_empty = memnew(StyleBoxEmpty);
	// cbx_empty->set_content_margin_all(Math::round(4 * scale));
	// Ref<StyleBox> cbx_focus = focus;
	// cbx_focus->set_content_margin_all(Math::round(4 * scale));

	// this->set_stylebox("normal", "CheckBox", cbx_empty);
	// this->set_stylebox("pressed", "CheckBox", cbx_empty);
	// this->set_stylebox("disabled", "CheckBox", cbx_empty);
	// this->set_stylebox("hover", "CheckBox", cbx_empty);
	// this->set_stylebox("hover_pressed", "CheckBox", cbx_empty);
	this->reset_style_box_flat_color("focus", "CheckBox", nullptr, &style_focus_color_border);

	// this->set_icon("checked", "CheckBox", icons["checked"]);
	// this->set_icon("checked_disabled", "CheckBox", icons["checked_disabled"]);
	// this->set_icon("unchecked", "CheckBox", icons["unchecked"]);
	// this->set_icon("unchecked_disabled", "CheckBox", icons["unchecked_disabled"]);
	// this->set_icon("radio_checked", "CheckBox", icons["radio_checked"]);
	// this->set_icon("radio_checked_disabled", "CheckBox", icons["radio_checked_disabled"]);
	// this->set_icon("radio_unchecked", "CheckBox", icons["radio_unchecked"]);
	// this->set_icon("radio_unchecked_disabled", "CheckBox", icons["radio_unchecked_disabled"]);

	this->set_icon_color("checked", "CheckBox", style_normal_color);
	this->set_icon_color("checked_disabled", "CheckBox", style_normal_color);
	this->set_icon_color("unchecked", "CheckBox", style_normal_color);
	this->set_icon_color("unchecked_disabled", "CheckBox", style_normal_color);
	this->set_icon_color("radio_checked", "CheckBox", style_normal_color);
	this->set_icon_color("radio_checked_disabled", "CheckBox", style_normal_color);
	this->set_icon_color("radio_unchecked", "CheckBox", style_normal_color);
	this->set_icon_color("radio_unchecked_disabled", "CheckBox", style_normal_color);

	// this->set_font("font", "CheckBox", Ref<Font>());
	// this->set_font_size("font_size", "CheckBox", -1);

	this->set_color("font_color", "CheckBox", style_normal_color);
	this->set_color("font_pressed_color", "CheckBox", style_pressed_color);
	this->set_color("font_hover_color", "CheckBox", style_hover_color);
	this->set_color("font_hover_pressed_color", "CheckBox", style_pressed_color);
	this->set_color("font_focus_color", "CheckBox", style_focus_color_border);
	this->set_color("font_disabled_color", "CheckBox", style_disabled_color);
	// this->set_color("font_outline_color", "CheckBox", Color(1, 1, 1));

	// this->set_constant("h_separation", "CheckBox", Math::round(4 * scale));
	// this->set_constant("check_v_offset", "CheckBox", 0);
	// this->set_constant("outline_size", "CheckBox", 0);

	// CheckButton

	// Ref<StyleBox> cb_empty = memnew(StyleBoxEmpty);
	// set_content_margin_individual(cb_empty, Math::round(6 * scale), Math::round(4 * scale), Math::round(6 * scale), Math::round(4 * scale));

	// this->set_stylebox("normal", "CheckButton", cb_empty);
	// this->set_stylebox("pressed", "CheckButton", cb_empty);
	// this->set_stylebox("disabled", "CheckButton", cb_empty);
	// this->set_stylebox("hover", "CheckButton", cb_empty);
	// this->set_stylebox("hover_pressed", "CheckButton", cb_empty);
	this->reset_style_box_flat_color("focus", "CheckButton", nullptr, &style_focus_color_border);

	// this->set_icon("checked", "CheckButton", icons["toggle_on"]);
	// this->set_icon("checked_disabled", "CheckButton", icons["toggle_on_disabled"]);
	// this->set_icon("unchecked", "CheckButton", icons["toggle_off"]);
	// this->set_icon("unchecked_disabled", "CheckButton", icons["toggle_off_disabled"]);

	// this->set_icon("checked_mirrored", "CheckButton", icons["toggle_on_mirrored"]);
	// this->set_icon("checked_disabled_mirrored", "CheckButton", icons["toggle_on_disabled_mirrored"]);
	// this->set_icon("unchecked_mirrored", "CheckButton", icons["toggle_off_mirrored"]);
	// this->set_icon("unchecked_disabled_mirrored", "CheckButton", icons["toggle_off_disabled_mirrored"]);

	this->set_icon_color("checked", "CheckButton", style_normal_color);
	this->set_icon_color("checked_disabled", "CheckButton", style_normal_color);
	this->set_icon_color("unchecked", "CheckButton", style_normal_color);
	this->set_icon_color("unchecked_disabled", "CheckButton", style_normal_color);

	this->set_icon_color("checked_mirrored", "CheckButton", style_normal_color);
	this->set_icon_color("checked_disabled_mirrored", "CheckButton", style_normal_color);
	this->set_icon_color("unchecked_mirrored", "CheckButton", style_normal_color);
	this->set_icon_color("unchecked_disabled_mirrored", "CheckButton", style_normal_color);

	// this->set_font("font", "CheckButton", Ref<Font>());
	// this->set_font_size("font_size", "CheckButton", -1);

	this->set_color("font_color", "CheckButton", style_normal_color);
	this->set_color("font_pressed_color", "CheckButton", style_pressed_color);
	this->set_color("font_hover_color", "CheckButton", style_hover_color);
	this->set_color("font_hover_pressed_color", "CheckButton", style_pressed_color);
	this->set_color("font_focus_color", "CheckButton", style_focus_color_border);
	this->set_color("font_disabled_color", "CheckButton", style_disabled_color);
	// this->set_color("font_outline_color", "CheckButton", Color(1, 1, 1));

	// this->set_constant("h_separation", "CheckButton", Math::round(4 * scale));
	// this->set_constant("check_v_offset", "CheckButton", 0);
	// this->set_constant("outline_size", "CheckButton", 0);

	// Button variations

	this->set_type_variation("FlatButton", "Button");
	this->set_type_variation("FlatMenuButton", "MenuButton");

	// Ref<StyleBoxEmpty> flat_button_normal = make_empty_stylebox();
	// for (int i = 0; i < 4; i++) {
	// 	flat_button_normal->set_content_margin((Side)i, button_normal->get_margin((Side)i) + button_normal->get_border_width((Side)i));
	// }
	// Ref<StyleBoxFlat> flat_button_pressed = button_pressed->duplicate();
	// flat_button_pressed->set_bg_color(style_pressed_color * Color(1, 1, 1, 0.85));
	// Ref<StyleBoxFlat> flat_button_normal = button_normal->duplicate();
	// Color bg_color = style_surface_high_color;
	// Color border_color = contrast[MaterialColorUtility::primary];
	// flat_button_normal->set_bg_color(bg_color);
	// flat_button_normal->set_border_color(border_color);
	// flat_button_normal->set_border_width_all(1);
	// Ref<StyleBoxFlat> flat_button_pressed = flat_button_normal->duplicate();
	// flat_button_pressed->set_bg_color(pressed(bg_color));
	// flat_button_pressed->set_border_color(pressed(border_color));
	// Ref<StyleBoxFlat> flat_button_hover = flat_button_normal->duplicate();
	// flat_button_hover->set_bg_color(hovered(bg_color));
	// flat_button_hover->set_border_color(hovered(border_color));
	// Ref<StyleBoxFlat> flat_button_disabled = flat_button_normal->duplicate();
	// flat_button_disabled->set_bg_color(disabled(bg_color));
	// flat_button_disabled->set_border_color(disabled(border_color));
	// Ref<StyleBoxFlat> flat_button_focus = flat_button_normal->duplicate();
	// flat_button_focus->set_border_color(control_font_color);
	// flat_button_focus->set_border_width_all(2);
	const Color flat_button_normal = style_surface_high_color;
	const Color flat_button_hover = hovered(style_surface_high_color);
	const Color flat_button_pressed = pressed(style_surface_high_color);
	const Color flat_button_disabled = disabled(style_surface_high_color);

	const Color flat_button_normal_border = style_normal_color;
	const Color flat_button_hover_border = hovered(style_normal_color);
	const Color flat_button_pressed_border = pressed(style_normal_color);
	const Color flat_button_disabled_border = disabled(style_normal_color);

	const Color flat_button_focus = flat_button_normal;
	const Color flat_button_focus_border = control_font_color;

	this->reset_style_box_flat_color("normal", "FlatButton", &flat_button_normal, &flat_button_normal_border);
	this->reset_style_box_flat_color("hover", "FlatButton", &flat_button_hover, &flat_button_hover_border);
	this->reset_style_box_flat_color("pressed", "FlatButton", &flat_button_pressed, &flat_button_pressed_border);
	this->reset_style_box_flat_color("disabled", "FlatButton", &flat_button_disabled, &flat_button_disabled_border);
	this->reset_style_box_flat_color("focus", "FlatButton", &flat_button_focus, &flat_button_focus_border);

	this->set_color("font_color", "FlatButton", style_normal_color);
	this->set_color("font_pressed_color", "FlatButton", style_pressed_color);
	this->set_color("font_hover_color", "FlatButton", style_hover_color);
	this->set_color("font_hover_pressed_color", "FlatButton", style_pressed_color);
	this->set_color("font_focus_color", "FlatButton", style_focus_color_border);
	this->set_color("font_disabled_color", "FlatButton", style_disabled_color);

	this->reset_style_box_flat_color("normal", "FlatMenuButton", &flat_button_normal, &flat_button_normal_border);
	this->reset_style_box_flat_color("hover", "FlatMenuButton", &flat_button_hover, &flat_button_hover_border);
	this->reset_style_box_flat_color("pressed", "FlatMenuButton", &flat_button_pressed, &flat_button_pressed_border);
	this->reset_style_box_flat_color("disabled", "FlatMenuButton", &flat_button_disabled, &flat_button_disabled_border);
	this->reset_style_box_flat_color("focus", "FlatMenuButton", &flat_button_focus, &flat_button_focus_border);

	this->set_color("font_color", "FlatMenuButton", style_normal_color);
	this->set_color("font_pressed_color", "FlatMenuButton", style_pressed_color);
	this->set_color("font_hover_color", "FlatMenuButton", style_hover_color);
	this->set_color("font_hover_pressed_color", "FlatMenuButton", style_pressed_color);
	this->set_color("font_focus_color", "FlatMenuButton", style_focus_color_border);
	this->set_color("font_disabled_color", "FlatMenuButton", style_disabled_color);

	// Label

	// this->set_stylebox("normal", "Label", memnew(StyleBoxEmpty));
	// this->set_font("font", "Label", Ref<Font>());
	// this->set_font_size("font_size", "Label", -1);

	this->set_color("font_color", "Label", control_font_color /* Color(1, 1, 1) */);
	// this->set_color("font_shadow_color", "Label", Color(0, 0, 0, 0));
	// this->set_color("font_outline_color", "Label", Color(1, 1, 1));

	// this->set_constant("shadow_offset_x", "Label", Math::round(1 * scale));
	// this->set_constant("shadow_offset_y", "Label", Math::round(1 * scale));
	// this->set_constant("outline_size", "Label", 0);
	// this->set_constant("shadow_outline_size", "Label", Math::round(1 * scale));
	// this->set_constant("line_spacing", "Label", Math::round(3 * scale));

	// this->set_type_variation("HeaderSmall", "Label");
	// this->set_font_size("font_size", "HeaderSmall", default_font_size + 4);

	// this->set_type_variation("HeaderMedium", "Label");
	// this->set_font_size("font_size", "HeaderMedium", default_font_size + 8);

	// this->set_type_variation("HeaderLarge", "Label");
	// this->set_font_size("font_size", "HeaderLarge", default_font_size + 12);

	// LineEdit

	// Ref<StyleBoxFlat> style_line_edit = make_flat_stylebox(style_surface_high_color, default_margin, default_margin, default_margin, default_margin, default_corner_radius);
	// Add a line at the bottom to make LineEdits distinguishable from Buttons.
	// style_line_edit->set_border_color(control_font_color);
	// style_line_edit->set_border_width_all(1);
	const Color style_line_edit = style_surface_high_color;
	const Color style_line_edit_border = contrast[Mcu::primaryContainer];
	const Color style_line_edit_read_only_border = style_surface_disabled_color;

	this->reset_style_box_flat_color("normal", "LineEdit", &style_line_edit, &style_line_edit_border);

	// Ref<StyleBoxFlat> style_line_edit_focus = focus;//style_line_edit->duplicate();
	// style_line_edit_focus->set_border_color(style_pressed_color);
	// style_line_edit_focus->set_border_width_all(3);
	this->reset_style_box_flat_color("focus", "LineEdit", nullptr, &style_font_color);

	// Ref<StyleBoxFlat> style_line_edit_read_only = make_flat_stylebox(style_surface_disabled_color, default_margin, default_margin, default_margin, default_margin, default_corner_radius);
	// Add a line at the bottom to make LineEdits distinguishable from Buttons.
	// style_line_edit_read_only->set_border_width(SIDE_BOTTOM, 2);
	// style_line_edit_read_only->set_border_color(control_font_disabled_color /* * Color(1, 1, 1, 0.5) */);
	this->reset_style_box_flat_color("read_only", "LineEdit", nullptr, &style_line_edit_read_only_border);

	// this->set_font("font", "LineEdit", Ref<Font>());
	// this->set_font_size("font_size", "LineEdit", -1);

	this->set_color("font_color", "LineEdit", control_font_color);
	this->set_color("font_selected_color", "LineEdit", control_font_pressed_color);
	this->set_color("font_uneditable_color", "LineEdit", control_font_disabled_color);
	this->set_color("font_placeholder_color", "LineEdit", control_font_placeholder_color);
	// this->set_color("font_outline_color", "LineEdit", Color(1, 1, 1));
	this->set_color("caret_color", "LineEdit", control_font_hover_color);
	this->set_color("selection_color", "LineEdit", control_selection_color);
	this->set_color("clear_button_color", "LineEdit", control_font_color);
	this->set_color("clear_button_color_pressed", "LineEdit", control_font_pressed_color);

	// this->set_constant("minimum_character_width", "LineEdit", 4);
	// this->set_constant("outline_size", "LineEdit", 0);
	// this->set_constant("caret_width", "LineEdit", 1);

	// this->set_icon("clear", "LineEdit", icons["line_edit_clear"]);
	this->set_icon_color("clear", "LineEdit", style_normal_color);

	// ProgressBar

	this->reset_style_box_flat_color("background", "ProgressBar", &style_progress_bg_color); //, 2, 2, 2, 2, 6));
	this->reset_style_box_flat_color("fill", "ProgressBar", &style_progress_color); //, 2, 2, 2, 2, 6));

	// this->set_font("font", "ProgressBar", Ref<Font>());
	// this->set_font_size("font_size", "ProgressBar", -1);

	this->set_color("font_color", "ProgressBar", style_font_color);
	this->set_color("font_outline_color", "ProgressBar", style_normal_color);

	// this->set_constant("outline_size", "ProgressBar", 0);
	// set outline to make the font more clear
	this->set_constant("outline_size", "ProgressBar", 8);

	// TextEdit bug, don't display border https://github.com/godotengine/godot/issues/32996

	this->reset_style_box_flat_color("normal", "TextEdit", &style_line_edit, &style_line_edit_border);
	this->reset_style_box_flat_color("focus", "TextEdit", nullptr, &style_focus_color_border);
	this->reset_style_box_flat_color("read_only", "TextEdit", nullptr, &style_line_edit_read_only_border);

	// this->set_icon("tab", "TextEdit", icons["text_edit_tab"]);
	// this->set_icon("space", "TextEdit", icons["text_edit_space"]);

	this->set_icon_color("tab", "TextEdit", style_normal_color);
	this->set_icon_color("space", "TextEdit", style_normal_color);

	// this->set_font("font", "TextEdit", Ref<Font>());
	// this->set_font_size("font_size", "TextEdit", -1);

	this->set_color("background_color", "TextEdit", style_surface_high_color);
	this->set_color("font_color", "TextEdit", control_font_color);
	// this->set_color("font_selected_color", "TextEdit", Color(0, 0, 0, 0));
	this->set_color("font_readonly_color", "TextEdit", control_font_disabled_color);
	this->set_color("font_placeholder_color", "TextEdit", control_font_placeholder_color);
	// this->set_color("font_outline_color", "TextEdit", Color(1, 1, 1));
	this->set_color("selection_color", "TextEdit", control_selection_color);
	// this->set_color("current_line_color", "TextEdit", Color(0.25, 0.25, 0.26, 0.8));
	this->set_color("caret_color", "TextEdit", control_font_color);
	// this->set_color("caret_background_color", "TextEdit", Color(0, 0, 0));
	// this->set_color("word_highlighted_color", "TextEdit", Color(0.5, 0.5, 0.5, 0.25));
	// this->set_color("search_result_color", "TextEdit", Color(0.3, 0.3, 0.3));
	// this->set_color("search_result_border_color", "TextEdit", Color(0.3, 0.3, 0.3, 0.4));

	// this->set_constant("line_spacing", "TextEdit", Math::round(4 * scale));
	// this->set_constant("outline_size", "TextEdit", 0);
	// this->set_constant("caret_width", "TextEdit", 1);

	// CodeEdit

	// this->set_stylebox("normal", "CodeEdit", style_line_edit);
	// this->set_stylebox("focus", "CodeEdit", focus);
	// this->set_stylebox("read_only", "CodeEdit", style_line_edit_read_only);
	// this->set_stylebox("completion", "CodeEdit", make_flat_stylebox(style_normal_color, 0, 0, 0, 0, default_corner_radius));

	// this->set_icon("tab", "CodeEdit", icons["text_edit_tab"]);
	// this->set_icon("space", "CodeEdit", icons["text_edit_space"]);
	// this->set_icon("breakpoint", "CodeEdit", icons["breakpoint"]);
	// this->set_icon("bookmark", "CodeEdit", icons["bookmark"]);
	// this->set_icon("executing_line", "CodeEdit", icons["arrow_right"]);
	// this->set_icon("can_fold", "CodeEdit", icons["arrow_down"]);
	// this->set_icon("folded", "CodeEdit", icons["arrow_right"]);
	// this->set_icon("can_fold_code_region", "CodeEdit", icons["region_unfolded"]);
	// this->set_icon("folded_code_region", "CodeEdit", icons["region_folded"]);
	// this->set_icon("folded_eol_icon", "CodeEdit", icons["text_edit_ellipsis"]);

	// this->set_font("font", "CodeEdit", Ref<Font>());
	// this->set_font_size("font_size", "CodeEdit", -1);

	// this->set_color("background_color", "CodeEdit", Color(0, 0, 0, 0));
	// this->set_color("completion_background_color", "CodeEdit", Color(0.17, 0.16, 0.2));
	// this->set_color("completion_selected_color", "CodeEdit", Color(0.26, 0.26, 0.27));
	// this->set_color("completion_existing_color", "CodeEdit", Color(0.87, 0.87, 0.87, 0.13));
	// this->set_color("completion_scroll_color", "CodeEdit", control_font_pressed_color * Color(1, 1, 1, 0.29));
	// this->set_color("completion_scroll_hovered_color", "CodeEdit", control_font_pressed_color * Color(1, 1, 1, 0.4));
	// this->set_color("font_color", "CodeEdit", control_font_color);
	// this->set_color("font_selected_color", "CodeEdit", Color(0, 0, 0, 0));
	// this->set_color("font_readonly_color", "CodeEdit", Color(control_font_color.r, control_font_color.g, control_font_color.b, 0.5f));
	// this->set_color("font_placeholder_color", "CodeEdit", control_font_placeholder_color);
	// this->set_color("font_outline_color", "CodeEdit", Color(1, 1, 1));
	// this->set_color("selection_color", "CodeEdit", control_selection_color);
	// this->set_color("bookmark_color", "CodeEdit", Color(0.5, 0.64, 1, 0.8));
	// this->set_color("breakpoint_color", "CodeEdit", Color(0.9, 0.29, 0.3));
	// this->set_color("executing_line_color", "CodeEdit", Color(0.98, 0.89, 0.27));
	// this->set_color("current_line_color", "CodeEdit", Color(0.25, 0.25, 0.26, 0.8));
	// this->set_color("code_folding_color", "CodeEdit", Color(0.8, 0.8, 0.8, 0.8));
	// this->set_color("folded_code_region_color", "CodeEdit", Color(0.68, 0.46, 0.77, 0.2));
	// this->set_color("caret_color", "CodeEdit", control_font_color);
	// this->set_color("caret_background_color", "CodeEdit", Color(0, 0, 0));
	// this->set_color("brace_mismatch_color", "CodeEdit", Color(1, 0.2, 0.2));
	// this->set_color("line_number_color", "CodeEdit", Color(0.67, 0.67, 0.67, 0.4));
	// this->set_color("word_highlighted_color", "CodeEdit", Color(0.8, 0.9, 0.9, 0.15));
	// this->set_color("line_length_guideline_color", "CodeEdit", Color(0.3, 0.5, 0.8, 0.1));
	// this->set_color("search_result_color", "CodeEdit", Color(0.3, 0.3, 0.3));
	// this->set_color("search_result_border_color", "CodeEdit", Color(0.3, 0.3, 0.3, 0.4));

	// this->set_constant("completion_lines", "CodeEdit", 7);
	// this->set_constant("completion_max_width", "CodeEdit", 50);
	// this->set_constant("completion_scroll_width", "CodeEdit", 6);
	// this->set_constant("line_spacing", "CodeEdit", Math::round(4 * scale));
	// this->set_constant("outline_size", "CodeEdit", 0);

	// Ref<Texture2D> empty_icon = memnew(ImageTexture);

	const Color style_h_scrollbar = style_progress_bg_color; // = make_flat_stylebox(style_progress_bg_color, 0, 4, 0, 4, 10);
	const Color style_v_scrollbar = style_progress_bg_color; // = make_flat_stylebox(style_progress_bg_color, 4, 0, 4, 0, 10);

	const Color style_h_scrollbar_focus = pressed(style_progress_bg_color); // = make_flat_stylebox(pressed(style_progress_bg_color), 0, 4, 0, 4, 10);
	const Color style_v_scrollbar_focus = pressed(style_progress_bg_color); // = make_flat_stylebox(pressed(style_progress_bg_color), 4, 0, 4, 0, 10);

	const Color style_scrollbar_grabber = style_progress_color; // = make_flat_stylebox(style_progress_color, 4, 4, 4, 4, 10);
	const Color style_scrollbar_grabber_highlight = hovered(style_scrollbar_grabber); // = make_flat_stylebox(hovered(style_progress_color) /* style_focus_color */, 4, 4, 4, 4, 10);
	const Color style_scrollbar_grabber_pressed = pressed(style_scrollbar_grabber); // = make_flat_stylebox(pressed(style_progress_color) /* style_focus_color * Color(0.75, 0.75, 0.75) */, 4, 4, 4, 4, 10);

	// HScrollBar

	this->reset_style_box_flat_color("scroll", "HScrollBar", &style_h_scrollbar);
	this->reset_style_box_flat_color("scroll_focus", "HScrollBar", &style_h_scrollbar_focus);
	this->reset_style_box_flat_color("grabber", "HScrollBar", &style_scrollbar_grabber);
	this->reset_style_box_flat_color("grabber_highlight", "HScrollBar", &style_scrollbar_grabber_highlight);
	this->reset_style_box_flat_color("grabber_pressed", "HScrollBar", &style_scrollbar_grabber_pressed);

	// this->set_icon("increment", "HScrollBar", empty_icon);
	// this->set_icon("increment_highlight", "HScrollBar", empty_icon);
	// this->set_icon("increment_pressed", "HScrollBar", empty_icon);
	// this->set_icon("decrement", "HScrollBar", empty_icon);
	// this->set_icon("decrement_highlight", "HScrollBar", empty_icon);
	// this->set_icon("decrement_pressed", "HScrollBar", empty_icon);

	// this->set_icon_color( "increment", "HScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "increment_highlight", "HScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "increment_pressed", "HScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "decrement", "HScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "decrement_highlight", "HScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "decrement_pressed", "HScrollBar", contrast[MaterialColorUtility::primary]);

	// VScrollBar

	this->reset_style_box_flat_color("scroll", "VScrollBar", &style_v_scrollbar);
	this->reset_style_box_flat_color("scroll_focus", "VScrollBar", &style_v_scrollbar_focus);
	this->reset_style_box_flat_color("grabber", "VScrollBar", &style_scrollbar_grabber);
	this->reset_style_box_flat_color("grabber_highlight", "VScrollBar", &style_scrollbar_grabber_highlight);
	this->reset_style_box_flat_color("grabber_pressed", "VScrollBar", &style_scrollbar_grabber_pressed);

	// this->set_icon("increment", "VScrollBar", empty_icon);
	// this->set_icon("increment_highlight", "VScrollBar", empty_icon);
	// this->set_icon("increment_pressed", "VScrollBar", empty_icon);
	// this->set_icon("decrement", "VScrollBar", empty_icon);
	// this->set_icon("decrement_highlight", "VScrollBar", empty_icon);
	// this->set_icon("decrement_pressed", "VScrollBar", empty_icon);

	// this->set_icon_color( "increment", "VScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "increment_highlight", "VScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "increment_pressed", "VScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "decrement", "VScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "decrement_highlight", "VScrollBar", contrast[MaterialColorUtility::primary]);
	// this->set_icon_color( "decrement_pressed", "VScrollBar", contrast[MaterialColorUtility::primary]);

	const Color style_slider = style_progress_bg_color; // make_flat_stylebox(style_progress_bg_color, 4, 4, 4, 4, 4);
	const Color style_slider_grabber = style_progress_color; // make_flat_stylebox(style_progress_color, 4, 4, 4, 4, 4);
	const Color style_slider_grabber_highlight = pressed(style_progress_color); // make_flat_stylebox(pressed(style_progress_color) /* style_focus_color */, 4, 4, 4, 4, 4);

	// HSlider

	this->reset_style_box_flat_color("slider", "HSlider", &style_slider);
	this->reset_style_box_flat_color("grabber_area", "HSlider", &style_slider_grabber);
	this->reset_style_box_flat_color("grabber_area_highlight", "HSlider", &style_slider_grabber_highlight);

	// this->set_icon("grabber", "HSlider", icons["slider_grabber"]);
	// this->set_icon("grabber_highlight", "HSlider", icons["slider_grabber_hl"]);
	// this->set_icon("grabber_disabled", "HSlider", icons["slider_grabber_disabled"]);
	// this->set_icon("tick", "HSlider", icons["hslider_tick"]);

	this->set_icon_color("grabber", "HSlider", style_normal_color);
	this->set_icon_color("grabber_highlight", "HSlider", style_normal_color);
	this->set_icon_color("grabber_disabled", "HSlider", style_normal_color);
	this->set_icon_color("tick", "HSlider", style_normal_color);

	// this->set_constant("center_grabber", "HSlider", 0);
	// this->set_constant("grabber_offset", "HSlider", 0);

	// VSlider

	this->reset_style_box_flat_color("slider", "VSlider", &style_slider);
	this->reset_style_box_flat_color("grabber_area", "VSlider", &style_slider_grabber);
	this->reset_style_box_flat_color("grabber_area_highlight", "VSlider", &style_slider_grabber_highlight);

	// this->set_icon("grabber", "VSlider", icons["slider_grabber"]);
	// this->set_icon("grabber_highlight", "VSlider", icons["slider_grabber_hl"]);
	// this->set_icon("grabber_disabled", "VSlider", icons["slider_grabber_disabled"]);
	// this->set_icon("tick", "VSlider", icons["vslider_tick"]);

	this->set_icon_color("grabber", "VSlider", style_normal_color);
	this->set_icon_color("grabber_highlight", "VSlider", style_normal_color);
	this->set_icon_color("grabber_disabled", "VSlider", style_normal_color);
	this->set_icon_color("tick", "VSlider", style_normal_color);

	// this->set_constant("center_grabber", "VSlider", 0);
	// this->set_constant("grabber_offset", "VSlider", 0);

	// SpinBox

	// this->set_icon("updown", "SpinBox", icons["updown"]);
	this->set_icon_color("updown", "SpinBox", style_normal_color);

	// ScrollContainer

	// Ref<StyleBoxEmpty> empty;
	// empty.instantiate();
	// this->set_stylebox("panel", "ScrollContainer", empty);

	// Window

	this->reset_style_box_flat_color("embedded_border", "Window", &style_popup_color); //, 10, 28, 10, 8, default_corner_radius), 8, 32, 8, 6));
	this->reset_style_box_flat_color("embedded_unfocused_border", "Window", &style_popup_hover_color); //, 10, 28, 10, 8, default_corner_radius), 8, 32, 8, 6));

	// this->set_font("title_font", "Window", Ref<Font>());
	// this->set_font_size("title_font_size", "Window", -1);
	this->set_color("title_color", "Window", control_font_color);
	// this->set_color("title_outline_modulate", "Window", Color(1, 1, 1));
	// this->set_constant("title_outline_size", "Window", 0);
	// this->set_constant("title_height", "Window", 36 * scale);
	// this->set_constant("resize_margin", "Window", Math::round(4 * scale));

	// this->set_icon("close", "Window", icons["close"]);
	// this->set_icon("close_pressed", "Window", icons["close_hl"]);

	this->set_icon_color("close", "Window", style_normal_color);
	this->set_icon_color("close_pressed", "Window", style_normal_color);

	// this->set_constant("close_h_offset", "Window", 18 * scale);
	// this->set_constant("close_v_offset", "Window", 24 * scale);

	// Dialogs

	// AcceptDialog is currently the base dialog, so this defines styles for all extending nodes.
	this->reset_style_box_flat_color("panel", "AcceptDialog", &style_popup_color); //, Math::round(8 * scale), Math::round(8 * scale), Math::round(8 * scale), Math::round(8 * scale), default_corner_radius));
	// this->set_constant("buttons_separation", "AcceptDialog", Math::round(10 * scale));

	// File Dialog

	// this->set_icon("parent_folder", "FileDialog", icons["folder_up"]);
	// this->set_icon("back_folder", "FileDialog", icons["arrow_left"]);
	// this->set_icon("forward_folder", "FileDialog", icons["arrow_right"]);
	// this->set_icon("reload", "FileDialog", icons["reload"]);
	// this->set_icon("toggle_hidden", "FileDialog", icons["visibility_visible"]);
	// this->set_icon("folder", "FileDialog", icons["folder"]);
	// this->set_icon("file", "FileDialog", icons["file"]);

	this->set_icon_color("parent_folder", "FileDialog", style_normal_color);
	this->set_icon_color("back_folder", "FileDialog", style_normal_color);
	this->set_icon_color("forward_folder", "FileDialog", style_normal_color);
	this->set_icon_color("reload", "FileDialog", style_normal_color);
	this->set_icon_color("toggle_hidden", "FileDialog", style_normal_color);
	this->set_icon_color("folder", "FileDialog", style_normal_color);
	this->set_icon_color("file", "FileDialog", style_normal_color);

	// this->set_color("folder_icon_color", "FileDialog", Color(1, 1, 1));
	// this->set_color("file_icon_color", "FileDialog", Color(1, 1, 1));
	// this->set_color("file_disabled_color", "FileDialog", Color(1, 1, 1, 0.25));

	// Popup

	this->reset_style_box_flat_color("panel", "PopupPanel", &style_surface_high_color); // /* style_normal_color */, default_margin, default_margin, default_margin, default_margin, default_corner_radius));

	// PopupDialog

	this->reset_style_box_flat_color("panel", "PopupDialog", &style_surface_high_color); // /* style_normal_color */, default_margin, default_margin, default_margin, default_margin, default_corner_radius));

	// PopupMenu

	// Ref<StyleBoxLine> separator_horizontal = memnew(StyleBoxLine);
	// separator_horizontal->set_thickness(Math::round(scale));
	// separator_horizontal->set_color(style_separator_color);
	// set_content_margin_individual(separator_horizontal, default_margin, 0, default_margin, 0);
	// Ref<StyleBoxLine> separator_vertical = separator_horizontal->duplicate();
	// separator_vertical->set_vertical(true);
	// set_content_margin_individual(separator_vertical, 0, default_margin, 0, default_margin);

	// Always display a border for PopupMenus so they can be distinguished from their background.
	// Ref<StyleBoxFlat> style_popup_panel = make_flat_stylebox(style_popup_color, default_margin, default_margin, default_margin, default_margin, default_corner_radius);
	// style_popup_panel->set_border_width_all(2);
	const Color style_popup_panel = style_popup_color;
	const Color style_popup_panel_border = style_popup_border_color;

	this->reset_style_box_flat_color("panel", "PopupMenu", &style_popup_panel, &style_popup_panel_border);
	this->reset_style_box_flat_color("hover", "PopupMenu", &style_popup_hover_color); //make_flat_stylebox(style_popup_hover_color, default_margin, default_margin, default_margin, default_margin, default_corner_radius));
	this->reset_style_box("separator", "PopupMenu", [&](Ref<StyleBoxLine> box) { box->set_color(style_separator_color); });
	this->reset_style_box("labeled_separator_left", "PopupMenu", [&](Ref<StyleBoxLine> box) { box->set_color(style_separator_color); });
	this->reset_style_box("labeled_separator_right", "PopupMenu", [&](Ref<StyleBoxLine> box) { box->set_color(style_separator_color); });

	// this->set_icon("checked", "PopupMenu", icons["checked"]);
	// this->set_icon("checked_disabled", "PopupMenu", icons["checked_disabled"]);
	// this->set_icon("unchecked", "PopupMenu", icons["unchecked"]);
	// this->set_icon("unchecked_disabled", "PopupMenu", icons["unchecked_disabled"]);
	// this->set_icon("radio_checked", "PopupMenu", icons["radio_checked"]);
	// this->set_icon("radio_checked_disabled", "PopupMenu", icons["radio_checked_disabled"]);
	// this->set_icon("radio_unchecked", "PopupMenu", icons["radio_unchecked"]);
	// this->set_icon("radio_unchecked_disabled", "PopupMenu", icons["radio_unchecked_disabled"]);
	// this->set_icon("submenu", "PopupMenu", icons["popup_menu_arrow_right"]);
	// this->set_icon("submenu_mirrored", "PopupMenu", icons["popup_menu_arrow_left"]);

	this->set_icon_color("checked", "PopupMenu", style_normal_color);
	this->set_icon_color("checked_disabled", "PopupMenu", style_normal_color);
	this->set_icon_color("unchecked", "PopupMenu", style_normal_color);
	this->set_icon_color("unchecked_disabled", "PopupMenu", style_normal_color);
	this->set_icon_color("radio_checked", "PopupMenu", style_normal_color);
	this->set_icon_color("radio_checked_disabled", "PopupMenu", style_normal_color);
	this->set_icon_color("radio_unchecked", "PopupMenu", style_normal_color);
	this->set_icon_color("radio_unchecked_disabled", "PopupMenu", style_normal_color);
	this->set_icon_color("submenu", "PopupMenu", style_normal_color);
	this->set_icon_color("submenu_mirrored", "PopupMenu", style_normal_color);

	// this->set_font("font", "PopupMenu", Ref<Font>());
	// this->set_font("font_separator", "PopupMenu", Ref<Font>());
	// this->set_font_size("font_size", "PopupMenu", -1);
	// this->set_font_size("font_separator_size", "PopupMenu", -1);

	this->set_color("font_color", "PopupMenu", control_font_color);
	// this->set_color("font_accelerator_color", "PopupMenu", Color(0.7, 0.7, 0.7, 0.8));
	// this->set_color("font_disabled_color", "PopupMenu", Color(0.4, 0.4, 0.4, 0.8));
	this->set_color("font_hover_color", "PopupMenu", control_font_color);
	this->set_color("font_separator_color", "PopupMenu", control_font_color);
	// this->set_color("font_outline_color", "PopupMenu", Color(1, 1, 1));
	// this->set_color("font_separator_outline_color", "PopupMenu", Color(1, 1, 1));

	// this->set_constant("indent", "PopupMenu", Math::round(10 * scale));
	// this->set_constant("h_separation", "PopupMenu", Math::round(4 * scale));
	// this->set_constant("v_separation", "PopupMenu", Math::round(4 * scale));
	// this->set_constant("outline_size", "PopupMenu", 0);
	// this->set_constant("separator_outline_size", "PopupMenu", 0);
	// this->set_constant("item_start_padding", "PopupMenu", Math::round(2 * scale));
	// this->set_constant("item_end_padding", "PopupMenu", Math::round(2 * scale));
	// this->set_constant("icon_max_width", "PopupMenu", 0);

	// GraphNode

	// Ref<StyleBoxFlat> graphnode_normal = make_flat_stylebox(style_normal_color, 18, 12, 18, 12, default_corner_radius);
	// graphnode_normal->set_border_color(Color(0.325, 0.325, 0.325, 0.6));
	// Ref<StyleBoxFlat> graphnode_selected = graphnode_normal->duplicate();
	// graphnode_selected->set_border_color(Color(0.625, 0.625, 0.625, 0.6));

	// Ref<StyleBoxFlat> graphn_sb_titlebar = make_flat_stylebox(style_normal_color.lightened(0.3), 4, 4, 4, 4, default_corner_radius);
	// Ref<StyleBoxFlat> graphn_sb_titlebar_selected = graphnode_normal->duplicate();
	// graphn_sb_titlebar_selected->set_bg_color(Color(1.0, 0.625, 0.625, 0.6));
	// Ref<StyleBoxEmpty> graphnode_slot = make_empty_stylebox(0, 0, 0, 0);

	// this->set_stylebox("panel", "GraphNode", graphnode_normal);
	// this->set_stylebox("panel_selected", "GraphNode", graphnode_selected);
	// this->set_stylebox("titlebar", "GraphNode", graphn_sb_titlebar);
	// this->set_stylebox("titlebar_selected", "GraphNode", graphn_sb_titlebar_selected);
	// this->set_stylebox("slot", "GraphNode", graphnode_slot);
	// this->set_icon("port", "GraphNode", icons["graph_port"]);
	// this->set_icon("resizer", "GraphNode", icons["resizer_se"]);
	// this->set_color("resizer_color", "GraphNode", control_font_color);
	// this->set_constant("separation", "GraphNode", Math::round(2 * scale));
	// this->set_constant("port_h_offset", "GraphNode", 0);

	// GraphNodes's title Label.

	// this->set_type_variation("GraphNodeTitleLabel", "Label");

	// this->set_stylebox("normal", "GraphNodeTitleLabel", make_empty_stylebox(0, 0, 0, 0));
	// this->set_font("font", "GraphNodeTitleLabel", Ref<Font>());
	// this->set_font_size("font_size", "GraphNodeTitleLabel", -1);
	// this->set_color("font_color", "GraphNodeTitleLabel", control_font_color);
	// this->set_color("font_shadow_color", "GraphNodeTitleLabel", Color(0, 0, 0, 0));
	// this->set_color("font_outline_color", "GraphNodeTitleLabel", control_font_color);
	// this->set_constant("shadow_offset_x", "GraphNodeTitleLabel", Math::round(1 * scale));
	// this->set_constant("shadow_offset_y", "GraphNodeTitleLabel", Math::round(1 * scale));
	// this->set_constant("outline_size", "GraphNodeTitleLabel", 0);
	// this->set_constant("shadow_outline_size", "GraphNodeTitleLabel", Math::round(1 * scale));
	// this->set_constant("line_spacing", "GraphNodeTitleLabel", Math::round(3 * scale));

	// Tree

	this->reset_style_box_flat_color("panel", "Tree", &style_surface_high_color); //, 4, 4, 4, 5, default_corner_radius));
	this->reset_style_box_flat_color("focus", "Tree", nullptr, &style_focus_color_border);
	this->reset_style_box_flat_color("selected", "Tree", &style_selected_color); //, default_margin, default_margin, default_margin, default_margin, default_corner_radius));
	this->reset_style_box_flat_color("selected_focus", "Tree", &style_selected_color); //, default_margin, default_margin, default_margin, default_margin, default_corner_radius));
	this->reset_style_box_flat_color("cursor", "Tree", nullptr, &style_focus_color_border);
	this->reset_style_box_flat_color("cursor_unfocused", "Tree", nullptr, &style_focus_color_border);
	this->reset_style_box_flat_color("button_pressed", "Tree", &button_pressed);
	this->reset_style_box_flat_color("title_button_normal", "Tree", &style_surface_color); //, 4, 4, 4, 4, default_corner_radius));
	this->reset_style_box_flat_color("title_button_pressed", "Tree", &style_surface_pressed_color); //, 4, 4, 4, 4, default_corner_radius));
	this->reset_style_box_flat_color("title_button_hover", "Tree", &style_surface_hover_color); //, 4, 4, 4, 4, default_corner_radius));
	this->reset_style_box_flat_color("custom_button", "Tree", &button_normal);
	this->reset_style_box_flat_color("custom_button_pressed", "Tree", &button_pressed);
	this->reset_style_box_flat_color("custom_button_hover", "Tree", &button_hover);

	// this->set_icon("checked", "Tree", icons["checked"]);
	// this->set_icon("checked_disabled", "Tree", icons["checked_disabled"]);
	// this->set_icon("unchecked", "Tree", icons["unchecked"]);
	// this->set_icon("unchecked_disabled", "Tree", icons["unchecked_disabled"]);
	// this->set_icon("indeterminate", "Tree", icons["indeterminate"]);
	// this->set_icon("indeterminate_disabled", "Tree", icons["indeterminate_disabled"]);
	// this->set_icon("updown", "Tree", icons["updown"]);
	// this->set_icon("select_arrow", "Tree", icons["option_button_arrow"]);
	// this->set_icon("arrow", "Tree", icons["arrow_down"]);
	// this->set_icon("arrow_collapsed", "Tree", icons["arrow_right"]);
	// this->set_icon("arrow_collapsed_mirrored", "Tree", icons["arrow_left"]);

	this->set_icon_color("checked", "Tree", style_normal_color);
	this->set_icon_color("checked_disabled", "Tree", style_normal_color);
	this->set_icon_color("unchecked", "Tree", style_normal_color);
	this->set_icon_color("unchecked_disabled", "Tree", style_normal_color);
	this->set_icon_color("indeterminate", "Tree", style_normal_color);
	this->set_icon_color("indeterminate_disabled", "Tree", style_normal_color);
	this->set_icon_color("updown", "Tree", style_normal_color);
	this->set_icon_color("select_arrow", "Tree", style_normal_color);
	this->set_icon_color("arrow", "Tree", style_normal_color);
	this->set_icon_color("arrow_collapsed", "Tree", style_normal_color);
	this->set_icon_color("arrow_collapsed_mirrored", "Tree", style_normal_color);

	// this->set_font("title_button_font", "Tree", Ref<Font>());
	// this->set_font("font", "Tree", Ref<Font>());
	// this->set_font_size("font_size", "Tree", -1);
	// this->set_font_size("title_button_font_size", "Tree", -1);

	this->set_color("title_button_color", "Tree", control_font_color);
	this->set_color("font_color", "Tree", control_font_low_color);
	this->set_color("font_selected_color", "Tree", control_font_pressed_color);
	this->set_color("font_disabled_color", "Tree", control_font_disabled_color);
	// this->set_color("font_outline_color", "Tree", Color(1, 1, 1));
	// this->set_color("guide_color", "Tree", Color(0.7, 0.7, 0.7, 0.25));
	// this->set_color("drop_position_color", "Tree", Color(1, 1, 1));
	// this->set_color("relationship_line_color", "Tree", Color(0.27, 0.27, 0.27));
	// this->set_color("parent_hl_line_color", "Tree", Color(0.27, 0.27, 0.27));
	// this->set_color("children_hl_line_color", "Tree", Color(0.27, 0.27, 0.27));
	this->set_color("custom_button_font_highlight", "Tree", control_font_hover_color);

	// this->set_constant("h_separation", "Tree", Math::round(4 * scale));
	// this->set_constant("v_separation", "Tree", Math::round(4 * scale));
	// this->set_constant("item_margin", "Tree", Math::round(16 * scale));
	// this->set_constant("inner_item_margin_bottom", "Tree", 0);
	// this->set_constant("inner_item_margin_left", "Tree", 0);
	// this->set_constant("inner_item_margin_right", "Tree", 0);
	// this->set_constant("inner_item_margin_top", "Tree", 0);
	// this->set_constant("button_margin", "Tree", Math::round(4 * scale));
	// this->set_constant("draw_relationship_lines", "Tree", 0);
	// this->set_constant("relationship_line_width", "Tree", 1);
	// this->set_constant("parent_hl_line_width", "Tree", 1);
	// this->set_constant("children_hl_line_width", "Tree", 1);
	// this->set_constant("parent_hl_line_margin", "Tree", 0);
	// this->set_constant("draw_guides", "Tree", 1);
	// this->set_constant("scroll_border", "Tree", Math::round(4 * scale));
	// this->set_constant("scroll_speed", "Tree", 12);
	// this->set_constant("outline_size", "Tree", 0);
	// this->set_constant("icon_max_width", "Tree", 0);
	// this->set_constant("scrollbar_margin_left", "Tree", -1);
	// this->set_constant("scrollbar_margin_top", "Tree", -1);
	// this->set_constant("scrollbar_margin_right", "Tree", -1);
	// this->set_constant("scrollbar_margin_bottom", "Tree", -1);
	// this->set_constant("scrollbar_h_separation", "Tree", Math::round(4 * scale));
	// this->set_constant("scrollbar_v_separation", "Tree", Math::round(4 * scale));

	// ItemList

	this->reset_style_box_flat_color("panel", "ItemList", &style_surface_high_color); //, default_margin, default_margin, default_margin, default_margin, default_corner_radius));
	this->reset_style_box_flat_color("focus", "ItemList", nullptr, &style_focus_color_border);
	// this->set_constant("h_separation", "ItemList", Math::round(4 * scale));
	// this->set_constant("v_separation", "ItemList", Math::round(2 * scale));
	// this->set_constant("icon_margin", "ItemList", Math::round(4 * scale));
	// this->set_constant("line_separation", "ItemList", Math::round(2 * scale));

	// this->set_font("font", "ItemList", Ref<Font>());
	// this->set_font_size("font_size", "ItemList", -1);

	this->set_color("font_color", "ItemList", control_font_lower_color);
	this->set_color("font_hovered_color", "ItemList", control_font_hover_color);
	this->set_color("font_selected_color", "ItemList", control_font_pressed_color);
	// this->set_color("font_outline_color", "ItemList", Color(1, 1, 1));
	// this->set_color("guide_color", "ItemList", Color(0.7, 0.7, 0.7, 0.25));
	// this->reset_style_box_flat_color("hovered", "ItemList", &Color);//(1, 1, 1, 0.07), default_margin, default_margin, default_margin, default_margin, default_corner_radius));
	this->reset_style_box_flat_color("selected", "ItemList", &style_selected_color); //, default_margin, default_margin, default_margin, default_margin, default_corner_radius));
	this->reset_style_box_flat_color("selected_focus", "ItemList", &style_selected_color); //, default_margin, default_margin, default_margin, default_margin, default_corner_radius));
	this->reset_style_box_flat_color("cursor", "ItemList", nullptr, &style_focus_color_border);
	this->reset_style_box_flat_color("cursor_unfocused", "ItemList", nullptr, &style_focus_color_border);

	this->set_constant("outline_size", "ItemList", 0);

	// TabContainer

	// Ref<StyleBoxFlat> style_tab_selected = make_flat_stylebox(style_surface_container_color, 10, 4, 10, 4, 0);
	// style_tab_selected->set_border_width(SIDE_TOP, Math::round(3 * scale));
	// style_tab_selected->set_border_color(style_normal_color);
	const Color style_tab_selected = style_surface_container_color;
	const Color style_tab_selected_border = style_normal_color;

	// Ref<StyleBoxFlat> style_tab_unselected = make_flat_stylebox(style_surface_color, 10, 4, 10, 4, 0);
	// Add some spacing between unselected tabs to make them easier to distinguish from each other.
	// style_tab_unselected->set_border_width(SIDE_LEFT, Math::round(scale));
	// style_tab_unselected->set_border_width(SIDE_RIGHT, Math::round(scale));
	// style_tab_unselected->set_border_color(style_surface_container_color);
	const Color style_tab_unselected = style_surface_color;
	const Color style_tab_unselected_border = style_surface_container_color;

	// Ref<StyleBoxFlat> style_tab_disabled = style_tab_unselected->duplicate();
	// style_tab_disabled->set_bg_color(style_surface_disabled_color);
	// Ref<StyleBoxFlat> style_tab_hovered = style_tab_unselected->duplicate();
	// style_tab_hovered->set_bg_color(style_surface_hover_color);
	// Ref<StyleBoxFlat> style_tab_focus = focus->duplicate();
	const Color style_tab_disabled = style_surface_disabled_color;
	const Color style_tab_disabled_border = style_surface_container_color;
	const Color style_tab_hovered = style_surface_hover_color;
	const Color style_tab_hovered_border = style_surface_container_color;

	this->reset_style_box_flat_color("tab_selected", "TabContainer", &style_tab_selected, &style_tab_selected_border);
	this->reset_style_box_flat_color("tab_hovered", "TabContainer", &style_tab_hovered, &style_tab_hovered_border);
	this->reset_style_box_flat_color("tab_unselected", "TabContainer", &style_tab_unselected, &style_tab_unselected_border);
	this->reset_style_box_flat_color("tab_disabled", "TabContainer", &style_tab_disabled, &style_tab_disabled_border);
	this->reset_style_box_flat_color("tab_focus", "TabContainer", nullptr, &style_focus_color_border);
	this->reset_style_box_flat_color("panel", "TabContainer", &style_surface_high_color); //, 0, 0, 0, 0, default_corner_radius));
	// this->set_stylebox("tabbar_background", "TabContainer", make_empty_stylebox(0, 0, 0, 0));

	// this->set_icon("increment", "TabContainer", icons["scroll_button_right"]);
	// this->set_icon("increment_highlight", "TabContainer", icons["scroll_button_right_hl"]);
	// this->set_icon("decrement", "TabContainer", icons["scroll_button_left"]);
	// this->set_icon("decrement_highlight", "TabContainer", icons["scroll_button_left_hl"]);
	// this->set_icon("drop_mark", "TabContainer", icons["tabs_drop_mark"]);
	// this->set_icon("menu", "TabContainer", icons["tabs_menu"]);
	// this->set_icon("menu_highlight", "TabContainer", icons["tabs_menu_hl"]);

	this->set_icon_color("increment", "TabContainer", style_normal_color);
	this->set_icon_color("increment_highlight", "TabContainer", style_normal_color);
	this->set_icon_color("decrement", "TabContainer", style_normal_color);
	this->set_icon_color("decrement_highlight", "TabContainer", style_normal_color);
	this->set_icon_color("drop_mark", "TabContainer", style_normal_color);
	this->set_icon_color("menu", "TabContainer", style_normal_color);
	this->set_icon_color("menu_highlight", "TabContainer", style_normal_color);

	// this->set_font("font", "TabContainer", Ref<Font>());
	// this->set_font_size("font_size", "TabContainer", -1);

	this->set_color("font_selected_color", "TabContainer", control_font_hover_color);
	this->set_color("font_hovered_color", "TabContainer", control_font_hover_color);
	this->set_color("font_unselected_color", "TabContainer", control_font_low_color);
	this->set_color("font_disabled_color", "TabContainer", control_font_disabled_color);
	// this->set_color("font_outline_color", "TabContainer", Color(1, 1, 1));
	// this->set_color("drop_mark_color", "TabContainer", Color(1, 1, 1));

	// this->set_constant("side_margin", "TabContainer", Math::round(8 * scale));
	// this->set_constant("icon_separation", "TabContainer", Math::round(4 * scale));
	// this->set_constant("icon_max_width", "TabContainer", 0);
	// this->set_constant("outline_size", "TabContainer", 0);

	// TabBar

	this->reset_style_box_flat_color("tab_selected", "TabBar", &style_tab_selected, &style_tab_selected_border);
	this->reset_style_box_flat_color("tab_hovered", "TabBar", &style_tab_hovered, &style_tab_hovered_border);
	this->reset_style_box_flat_color("tab_unselected", "TabBar", &style_tab_unselected, &style_tab_unselected_border);
	this->reset_style_box_flat_color("tab_disabled", "TabBar", &style_tab_disabled, &style_tab_disabled_border);
	this->reset_style_box_flat_color("tab_focus", "TabBar", nullptr, &style_focus_color_border);
	this->reset_style_box_flat_color("button_pressed", "TabBar", &button_pressed);
	this->reset_style_box_flat_color("button_highlight", "TabBar", &button_normal);

	// this->set_icon("increment", "TabBar", icons["scroll_button_right"]);
	// this->set_icon("increment_highlight", "TabBar", icons["scroll_button_right_hl"]);
	// this->set_icon("decrement", "TabBar", icons["scroll_button_left"]);
	// this->set_icon("decrement_highlight", "TabBar", icons["scroll_button_left_hl"]);
	// this->set_icon("drop_mark", "TabBar", icons["tabs_drop_mark"]);
	// this->set_icon("close", "TabBar", icons["close"]);

	this->set_icon_color("increment", "TabBar", style_normal_color);
	this->set_icon_color("increment_highlight", "TabBar", style_normal_color);
	this->set_icon_color("decrement", "TabBar", style_normal_color);
	this->set_icon_color("decrement_highlight", "TabBar", style_normal_color);
	this->set_icon_color("drop_mark", "TabBar", style_normal_color);
	this->set_icon_color("close", "TabBar", style_normal_color);

	// this->set_font("font", "TabBar", Ref<Font>());
	// this->set_font_size("font_size", "TabBar", -1);

	this->set_color("font_selected_color", "TabBar", control_font_hover_color);
	this->set_color("font_hovered_color", "TabBar", control_font_hover_color);
	this->set_color("font_unselected_color", "TabBar", control_font_low_color);
	this->set_color("font_disabled_color", "TabBar", control_font_disabled_color);
	// this->set_color("font_outline_color", "TabBar", Color(1, 1, 1));
	// this->set_color("drop_mark_color", "TabBar", Color(1, 1, 1));

	// this->set_constant("h_separation", "TabBar", Math::round(4 * scale));
	// this->set_constant("icon_max_width", "TabBar", 0);
	// this->set_constant("outline_size", "TabBar", 0);

	// Separators

	this->reset_style_box("separator", "HSeparator", [&](Ref<StyleBoxLine> box) { box->set_color(style_separator_color); });
	this->reset_style_box("separator", "VSeparator", [&](Ref<StyleBoxLine> box) { box->set_color(style_separator_color); });

	// this->set_icon("close", "Icons", icons["close"]);
	// this->set_font("normal", "Fonts", Ref<Font>());
	// this->set_font("large", "Fonts", Ref<Font>());

	// this->set_constant("separation", "HSeparator", Math::round(4 * scale));
	// this->set_constant("separation", "VSeparator", Math::round(4 * scale));

	// ColorPicker

	// this->set_constant("margin", "ColorPicker", Math::round(4 * scale));
	// this->set_constant("sv_width", "ColorPicker", Math::round(256 * scale));
	// this->set_constant("sv_height", "ColorPicker", Math::round(256 * scale));
	// this->set_constant("h_width", "ColorPicker", Math::round(30 * scale));
	// this->set_constant("label_width", "ColorPicker", Math::round(10 * scale));
	// this->set_constant("center_slider_grabbers", "ColorPicker", 1);

	// this->set_icon("folded_arrow", "ColorPicker", icons["arrow_right"]);
	// this->set_icon("expanded_arrow", "ColorPicker", icons["arrow_down"]);
	// this->set_icon("screen_picker", "ColorPicker", icons["color_picker_pipette"]);
	// this->set_icon("shape_circle", "ColorPicker", icons["picker_shape_circle"]);
	// this->set_icon("shape_rect", "ColorPicker", icons["picker_shape_rectangle"]);
	// this->set_icon("shape_rect_wheel", "ColorPicker", icons["picker_shape_rectangle_wheel"]);
	// this->set_icon("add_preset", "ColorPicker", icons["add"]);
	// this->set_icon("sample_bg", "ColorPicker", icons["mini_checkerboard"]);
	// this->set_icon("sample_revert", "ColorPicker", icons["reload"]);
	// this->set_icon("overbright_indicator", "ColorPicker", icons["color_picker_overbright"]);
	// this->set_icon("bar_arrow", "ColorPicker", icons["color_picker_bar_arrow"]);
	// this->set_icon("picker_cursor", "ColorPicker", icons["color_picker_cursor"]);

	// {
	// 	const int precision = 7;

	// 	Ref<Gradient> hue_gradient;
	// 	hue_gradient.instantiate();
	// 	PackedFloat32Array offsets;
	// 	offsets.resize(precision);
	// 	PackedColorArray colors;
	// 	colors.resize(precision);

	// 	for (int i = 0; i < precision; i++) {
	// 		float h = i / float(precision - 1);
	// 		offsets.write[i] = h;
	// 		colors.write[i] = Color::from_hsv(h, 1, 1);
	// 	}
	// 	hue_gradient->set_offsets(offsets);
	// 	hue_gradient->set_colors(colors);

	// 	Ref<GradientTexture2D> hue_texture;
	// 	hue_texture.instantiate();
	// 	hue_texture->set_width(800);
	// 	hue_texture->set_height(6);
	// 	hue_texture->set_gradient(hue_gradient);

	//  this->set_icon_color("color_hue", "ColorPicker", hue_texturecontrast[MaterialColorUtility::primary] }

	// {
	// 	const int precision = 7;

	// 	Ref<Gradient> hue_gradient;
	// 	hue_gradient.instantiate();
	// 	PackedFloat32Array offsets;
	// 	offsets.resize(precision);
	// 	PackedColorArray colors;
	// 	colors.resize(precision);

	// 	for (int i = 0; i < precision; i++) {
	// 		float h = i / float(precision - 1);
	// 		offsets.write[i] = h;
	// 		colors.write[i] = Color::from_ok_hsl(h, 1, 0.5);
	// 	}
	// 	hue_gradient->set_offsets(offsets);
	// 	hue_gradient->set_colors(colors);

	// 	Ref<GradientTexture2D> hue_texture;
	// 	hue_texture.instantiate();
	// 	hue_texture->set_width(800);
	// 	hue_texture->set_height(6);
	// 	hue_texture->set_gradient(hue_gradient);

	//  this->set_icon_color("color_okhsl_hue", "ColorPicker", hue_texturecontrast[MaterialColorUtility::primary] }

	// ColorPickerButton

	// this->set_icon("bg", "ColorPickerButton", icons["mini_checkerboard"]);
	// this->set_stylebox("normal", "ColorPickerButton", button_normal);
	// this->set_stylebox("pressed", "ColorPickerButton", button_pressed);
	// this->set_stylebox("hover", "ColorPickerButton", button_hover);
	// this->set_stylebox("disabled", "ColorPickerButton", button_disabled);
	// this->set_stylebox("focus", "ColorPickerButton", focus);

	// this->set_font("font", "ColorPickerButton", Ref<Font>());
	// this->set_font_size("font_size", "ColorPickerButton", -1);

	// this->set_color("font_color", "ColorPickerButton", Color(1, 1, 1, 1));
	// this->set_color("font_pressed_color", "ColorPickerButton", Color(0.8, 0.8, 0.8, 1));
	// this->set_color("font_hover_color", "ColorPickerButton", Color(1, 1, 1, 1));
	// this->set_color("font_focus_color", "ColorPickerButton", Color(1, 1, 1, 1));
	// this->set_color("font_disabled_color", "ColorPickerButton", Color(0.9, 0.9, 0.9, 0.3));
	// this->set_color("font_outline_color", "ColorPickerButton", Color(1, 1, 1));

	// this->set_constant("h_separation", "ColorPickerButton", Math::round(4 * scale));
	// this->set_constant("outline_size", "ColorPickerButton", 0);

	// ColorPresetButton

	// Ref<StyleBoxFlat> preset_sb = make_flat_stylebox(Color(1, 1, 1), 2, 2, 2, 2, default_corner_radius);
	// preset_sb->set_corner_radius_all(Math::round(2 * scale));
	// preset_sb->set_corner_detail(Math::round(2 * scale));
	// preset_sb->set_anti_aliased(false);

	// this->set_stylebox("preset_fg", "ColorPresetButton", preset_sb);
	// this->set_icon("preset_bg", "ColorPresetButton", icons["mini_checkerboard"]);
	// this->set_icon("overbright_indicator", "ColorPresetButton", icons["color_picker_overbright"]);

	// TooltipPanel + TooltipLabel
	const Color tooltip_panel = blend_alpha(style_surface_high_color, 0.8);
	this->set_type_variation("TooltipPanel", "PopupPanel");
	this->reset_style_box_flat_color("panel", "TooltipPanel", &tooltip_panel);
	//make_flat_stylebox(Color(style_surface_high_color.r, style_surface_high_color.g, style_surface_high_color.b, 0.8) /* Color(0, 0, 0, 0.5) */, 2 * default_margin, 0.5 * default_margin, 2 * default_margin, 0.5 * default_margin, default_corner_radius));

	this->set_type_variation("TooltipLabelM", "TooltipLabel");
	// this->set_font_size("font_size", "TooltipLabel", -1);
	// this->set_font("font", "TooltipLabel", Ref<Font>());

	this->set_color("font_color", "TooltipLabelM", control_font_color);
	// this->set_color("font_shadow_color", "TooltipLabel", Color(0, 0, 0, 0));
	// this->set_color("font_outline_color", "TooltipLabel", Color(0, 0, 0, 0));

	// this->set_constant("shadow_offset_x", "TooltipLabel", 1);
	// this->set_constant("shadow_offset_y", "TooltipLabel", 1);
	// this->set_constant("outline_size", "TooltipLabel", 0);

	// RichTextLabel

	this->reset_style_box_flat_color("focus", "RichTextLabel", nullptr, &style_focus_color_border);
	// this->set_stylebox("normal", "RichTextLabel", make_empty_stylebox(0, 0, 0, 0));

	// this->set_font("normal_font", "RichTextLabel", Ref<Font>());
	// this->set_font("bold_font", "RichTextLabel", bold_font);
	// this->set_font("italics_font", "RichTextLabel", italics_font);
	// this->set_font("bold_italics_font", "RichTextLabel", bold_italics_font);
	// this->set_font("mono_font", "RichTextLabel", Ref<Font>());
	// this->set_font_size("normal_font_size", "RichTextLabel", -1);
	// this->set_font_size("bold_font_size", "RichTextLabel", -1);
	// this->set_font_size("italics_font_size", "RichTextLabel", -1);
	// this->set_font_size("bold_italics_font_size", "RichTextLabel", -1);
	// this->set_font_size("mono_font_size", "RichTextLabel", -1);

	this->set_color("default_color", "RichTextLabel", control_font_color /* Color(1, 1, 1) */);
	// this->set_color("font_selected_color", "RichTextLabel", Color(0, 0, 0, 0));
	// this->set_color("selection_color", "RichTextLabel", Color(0.1, 0.1, 1, 0.8));

	// this->set_color("font_shadow_color", "RichTextLabel", Color(0, 0, 0, 0));

	// this->set_color("font_outline_color", "RichTextLabel", Color(1, 1, 1));

	// this->set_constant("shadow_offset_x", "RichTextLabel", Math::round(1 * scale));
	// this->set_constant("shadow_offset_y", "RichTextLabel", Math::round(1 * scale));
	// this->set_constant("shadow_outline_size", "RichTextLabel", Math::round(1 * scale));

	// this->set_constant("line_separation", "RichTextLabel", 0);
	// this->set_constant("table_h_separation", "RichTextLabel", Math::round(3 * scale));
	// this->set_constant("table_v_separation", "RichTextLabel", Math::round(3 * scale));

	// this->set_constant("outline_size", "RichTextLabel", 0);

	// this->set_color("table_odd_row_bg", "RichTextLabel", Color(0, 0, 0, 0));
	// this->set_color("table_even_row_bg", "RichTextLabel", Color(0, 0, 0, 0));
	// this->set_color("table_border", "RichTextLabel", Color(0, 0, 0, 0));

	// this->set_constant("text_highlight_h_padding", "RichTextLabel", Math::round(3 * scale));
	// this->set_constant("text_highlight_v_padding", "RichTextLabel", Math::round(3 * scale));

	// Containers

	// this->set_icon("h_grabber", "SplitContainer", icons["hsplitter"]);
	// this->set_icon("v_grabber", "SplitContainer", icons["vsplitter"]);
	// this->set_icon("grabber", "VSplitContainer", icons["vsplitter"]);
	// this->set_icon("grabber", "HSplitContainer", icons["hsplitter"]);

	this->set_icon_color("h_grabber", "SplitContainer", style_normal_color);
	this->set_icon_color("v_grabber", "SplitContainer", style_normal_color);
	this->set_icon_color("grabber", "VSplitContainer", style_normal_color);
	this->set_icon_color("grabber", "HSplitContainer", style_normal_color);

	// this->set_constant("separation", "BoxContainer", Math::round(4 * scale));
	// this->set_constant("separation", "HBoxContainer", Math::round(4 * scale));
	// this->set_constant("separation", "VBoxContainer", Math::round(4 * scale));
	// this->set_constant("margin_left", "MarginContainer", 0);
	// this->set_constant("margin_top", "MarginContainer", 0);
	// this->set_constant("margin_right", "MarginContainer", 0);
	// this->set_constant("margin_bottom", "MarginContainer", 0);
	// this->set_constant("h_separation", "GridContainer", Math::round(4 * scale));
	// this->set_constant("v_separation", "GridContainer", Math::round(4 * scale));
	// this->set_constant("separation", "SplitContainer", Math::round(12 * scale));
	// this->set_constant("separation", "HSplitContainer", Math::round(12 * scale));
	// this->set_constant("separation", "VSplitContainer", Math::round(12 * scale));
	// this->set_constant("minimum_grab_thickness", "SplitContainer", Math::round(6 * scale));
	// this->set_constant("minimum_grab_thickness", "HSplitContainer", Math::round(6 * scale));
	// this->set_constant("minimum_grab_thickness", "VSplitContainer", Math::round(6 * scale));
	// this->set_constant("autohide", "SplitContainer", 1);
	// this->set_constant("autohide", "HSplitContainer", 1);
	// this->set_constant("autohide", "VSplitContainer", 1);
	// this->set_constant("h_separation", "FlowContainer", Math::round(4 * scale));
	// this->set_constant("v_separation", "FlowContainer", Math::round(4 * scale));
	// this->set_constant("h_separation", "HFlowContainer", Math::round(4 * scale));
	// this->set_constant("v_separation", "HFlowContainer", Math::round(4 * scale));
	// this->set_constant("h_separation", "VFlowContainer", Math::round(4 * scale));
	// this->set_constant("v_separation", "VFlowContainer", Math::round(4 * scale));

	this->reset_style_box_flat_color("panel", "PanelContainer", &style_surface_container_color); //, 0, 0, 0, 0, default_corner_radius));

	// this->set_icon("zoom_out", "GraphEdit", icons["zoom_less"]);
	// this->set_icon("zoom_in", "GraphEdit", icons["zoom_more"]);
	// this->set_icon("zoom_reset", "GraphEdit", icons["zoom_reset"]);
	// this->set_icon("grid_toggle", "GraphEdit", icons["grid_toggle"]);
	// this->set_icon("minimap_toggle", "GraphEdit", icons["grid_minimap"]);
	// this->set_icon("snapping_toggle", "GraphEdit", icons["grid_snap"]);
	// this->set_icon("layout", "GraphEdit", icons["grid_layout"]);

	// this->set_stylebox("panel", "GraphEdit", make_flat_stylebox(style_normal_color, 4, 4, 4, 5, default_corner_radius));

	// Ref<StyleBoxFlat> graph_toolbar_style = make_flat_stylebox(Color(0.24, 0.24, 0.24, 0.6), 4, 2, 4, 2, default_corner_radius);
	// this->set_stylebox("menu_panel", "GraphEdit", graph_toolbar_style);

	// this->set_color("grid_minor", "GraphEdit", Color(1, 1, 1, 0.05));
	// this->set_color("grid_major", "GraphEdit", Color(1, 1, 1, 0.2));
	// this->set_color("selection_fill", "GraphEdit", Color(1, 1, 1, 0.3));
	// this->set_color("selection_stroke", "GraphEdit", Color(1, 1, 1, 0.8));
	// this->set_color("activity", "GraphEdit", Color(1, 1, 1));
	// this->set_color("connection_hover_tint_color", "GraphEdit", Color(0, 0, 0, 0.3));
	// this->set_color("connection_valid_target_tint_color", "GraphEdit", Color(1, 1, 1, 0.4));
	// this->set_color("connection_rim_color", "GraphEdit", style_normal_color);

	// Visual Node Ports

	// this->set_constant("port_hotzone_inner_extent", "GraphEdit", 22 * scale);
	// this->set_constant("port_hotzone_outer_extent", "GraphEdit", 26 * scale);

	// this->set_stylebox("panel", "GraphEditMinimap", make_flat_stylebox(Color(0.24, 0.24, 0.24), 0, 0, 0, 0, default_corner_radius));
	// Ref<StyleBoxFlat> style_minimap_camera = make_flat_stylebox(Color(0.65, 0.65, 0.65, 0.2), 0, 0, 0, 0, 0);
	// style_minimap_camera->set_border_color(Color(0.65, 0.65, 0.65, 0.45));
	// style_minimap_camera->set_border_width_all(1);
	// this->set_stylebox("camera", "GraphEditMinimap", style_minimap_camera);
	// this->set_stylebox("node", "GraphEditMinimap", make_flat_stylebox(Color(1, 1, 1), 0, 0, 0, 0, 2));

	// this->set_icon("resizer", "GraphEditMinimap", icons["resizer_nw"]);
	// this->set_color("resizer_color", "GraphEditMinimap", Color(1, 1, 1, 0.85));

	// Theme

	// default_icon = icons["error_icon"];
	// Same color as the error icon.
	// default_style = make_flat_stylebox(Color(1, 0.365, 0.365), 4, 4, 4, 4, 0, false, 2);
}

// Ref<MTheme> MTheme::new_with_args(Dictionary contrast, int default_margin, int default_corner_radius) {
// 	Ref<MTheme> theme = memnew(MTheme);
// 	theme->default_margin = default_margin;
// 	theme->default_corner_radius = default_corner_radius;
// 	theme->set_contrast(contrast);
// 	return theme;
// }

void MTheme::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("get_default_margin"), &MTheme::get_default_margin);
	// ClassDB::bind_method(D_METHOD("get_default_corner_radius"), &MTheme::get_default_corner_radius);
	ClassDB::bind_method(D_METHOD("is_dark"), &MTheme::is_dark);
	ClassDB::bind_method(D_METHOD("get_theme_color"), &MTheme::get_theme_color);

	// ClassDB::bind_method(D_METHOD("set_default_margin", "value"), &MTheme::set_default_margin);
	// ClassDB::bind_method(D_METHOD("set_default_corner_radius", "value"), &MTheme::set_default_corner_radius);
	ClassDB::bind_method(D_METHOD("set_dark", "value"), &MTheme::set_dark);
	ClassDB::bind_method(D_METHOD("set_theme_color"), &MTheme::set_theme_color);

	// ADD_PROPERTY(PropertyInfo(Variant::INT, "default_margin"), "set_default_margin", "get_default_margin");
	// ADD_PROPERTY(PropertyInfo(Variant::INT, "default_corner_radius"), "set_default_corner_radius", "get_default_corner_radius");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "dark"), "set_dark", "is_dark");
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "theme_color"), "set_theme_color", "get_theme_color");

	ClassDB::bind_method(D_METHOD("update_theme"), &MTheme::update_theme);
	ClassDB::bind_method(D_METHOD("fill_theme", "contrast"), &MTheme::fill_theme);
}
