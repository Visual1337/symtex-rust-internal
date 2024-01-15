#pragma once

namespace GUIElements
{

	bool CreateMenu(wchar_t* title, const Vector2& pos, const Vector2& window_size, bool always_open)
	{
		if (!GUI::open) return false;

		if (!sex) {
			window_pos = pos;
			sex = true;
		}
		mouse_state = Unity::GetMouseButton(0);
		mouse_pos.x = GUI::GuiMethods::get_mousePosition().x;
		mouse_pos.y = Vars::ScreenHeight - GUI::GuiMethods::get_mousePosition().y;

		if (GUI::is_mouse_in_box({ window_pos.x, window_pos.y - 10 }, { window_pos.x + window_size.x, window_pos.y + 20 }) && mouse_state && main_menu_open) {
			window_pos.x += mouse_pos.x - old_mouse_pos.x;
			window_pos.y += mouse_pos.y - old_mouse_pos.y;
		}

		GUI::FillBoxRounded({ window_pos.x, window_pos.y - 10, window_size.x, window_size.y + 10 }, { 21, 21, 21, 255 }, ScaleMode::StretchToFill, 0);
		
		GUI::GuiMethods::DrawTextureRounded({ window_pos.x, window_pos.y - 10, window_size.x, window_size.y + 10 }, g_WhiteTexture, ScaleMode::StretchToFill, true, 1, Color(57, 57, 57, 255).GetUnityColor(), 1, 0);

		GUI::FillBoxRounded({ window_pos.x + 10, window_pos.y + 20, window_size.x - 20, window_size.y - 30 }, { 12, 12, 12, 255 }, ScaleMode::StretchToFill, 0);

		GUI::GuiMethods::DrawTextureRounded({ window_pos.x + 10, window_pos.y + 20, window_size.x - 20, window_size.y - 30 }, g_WhiteTexture, ScaleMode::StretchToFill, true, 1, Color(57, 57, 57, 255).GetUnityColor(), 1, 0);

		GUI::DrawLine({ window_pos.x + 10, window_pos.y + 60 }, { window_pos.x + 740, window_pos.y + 60 }, { 57,57,57,255 }, 1, false);
		return true;
		
	}


	int table = 0;
	void Tab(const wchar_t* name, int id, Vector2 tab_size = Vector2(100.f, 50.f)) {

		if (GUI::is_mouse_in_box({ window_pos.x + (id * tab_size.x) + 10, window_pos.y }, { window_pos.x + tab_size.x + (id * tab_size.x), window_pos.y + tab_size.y }) && mouse_state)
			Vars::ActiveTab = id;

		//GUI::StartGlRender(render_type::box, { window_pos.x + (id * 100.f) + tab_size.x, window_pos.y + tab_size.y / 2}, { tab_size.x, 50.f }, id == Vars::ActiveTab ? Color{ 16,16,20, 255 } : Color{ 12,12,18, 255 });
		GUI::String({ window_pos.x + (id * tab_size.x) + 10, window_pos.y, tab_size.x, tab_size.y }, (name), id == Vars::ActiveTab ? Color{ 255, 255,255, 255 } : Color{ 255, 255,255, 140 }, true, 10);
		GUI::StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x) + 20, window_pos.y + 58 }, { tab_size.x - 15, 3}, id == Vars::ActiveTab ? Color{ 12, 12, 12, 255 } : Color{12,12,18, 0});

		GUI::DrawLine({ window_pos.x + (id * tab_size.x) + 20, window_pos.y + 59 }, { window_pos.x + (id * tab_size.x) + 20, window_pos.y + 24 }, id == Vars::ActiveTab ? Color{ 57,57,57,255 } : Color{0,0,0,0}, 1, false);
		
		GUI::DrawLine({ window_pos.x + (id * tab_size.x) + 19, window_pos.y + 24 }, { window_pos.x + (id * tab_size.x) + tab_size.x + 5, window_pos.y + 24 }, id == Vars::ActiveTab ? Color{ 57,57,57,255 } : Color{ 0,0,0,0 }, 1, false);
		// GUI::DrawLine({ window_pos.x + (id * tab_size.x) + 19, window_pos.y + 59 }, { window_pos.x + (id * tab_size.x) + tab_size.x - 10, window_pos.y + 24 }, id == Vars::ActiveTab ? Color{ 57,57,57,255 } : Color{ 0,0,0,0 }, 1, false);

		GUI::DrawLine({ window_pos.x + (id * tab_size.x) + tab_size.x + 5, window_pos.y + 24 }, { window_pos.x + (id * tab_size.x) + tab_size.x + 5 , window_pos.y + 59 }, id == Vars::ActiveTab ? Color{ 57,57,57,255 } : Color{ 0,0,0,0 }, 1, false);

		// GUI::StartGlRender(render_type::boxoutline, { window_pos.x + (id * tab_size.x) + 10, window_pos.y + 58 }, { tab_size.x, 3 }, id == Vars::ActiveTab ? Color{ 255, 255, 255, 255 } : Color{ 12,12,18, 0 });
		/*GUI::StartGlRender(render_type::box, { window_pos.x + 1, window_pos.y + (id * 50.f) + 20.f + 30 }, { 99, 50.f }, id == Vars::ActiveTab ? Color{ 16,16,20, 255 } : Color{ 12,12,18, 255 });
		if (id == Vars::ActiveTab)
			GUI::Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

		GUI::String({ window_pos.x + 20.f, window_pos.y + (id * 50.f) + 34.f + 30, 300, 40 }, (name), id == Vars::ActiveTab ? Color{ 255, 255,255, 255 } : Color{ 255, 255,255, 140 }, false, 10);*/
	}

	/*void CheckBox()
	{

	}*/

	inline void CheckBox(const wchar_t* title, bool& value, float dist = 0, float textdist = 0) {
		next_item_pos.y -= 2;
		if (GUI::is_mouse_in_box({ next_item_pos.x, next_item_pos.y }, { next_item_pos.x + 14, next_item_pos.y + 14 }) && mouse_state && !old_mouse_state) // && !inColorPicker
			value = !value;

		GUI::String({ next_item_pos.x + 20, next_item_pos.y - 5.f, 300, 40 }, title, Color(255, 255, 255, 255), false, Vars::GUITextSize);
		GUI::FillCornerBoxRounded({ next_item_pos.x - 2, next_item_pos.y - 2,16, 16 }, Color(60, 60, 60, 170), 2);
		GUI::FillBoxRounded({ next_item_pos.x, next_item_pos.y, 12, 12 }, value ? Color(255, 255, 255, 255) : Color(60, 60, 60, 170), ScaleMode::StretchToFill, 2);

		next_item_pos.y += 24;
	}

	inline void TabChild(const wchar_t* title, const Vector2& pos, const Vector2& size)
	{
		GUI::FillBoxRounded({ window_pos.x + pos.x, window_pos.y + pos.y, size.x, size.y }, { 17,17,17, 255 }, ScaleMode::StretchToFill, 0);
		GUI::FillCornerBoxRounded({ window_pos.x + pos.x, window_pos.y + pos.y , size.x, size.y }, { 57,57,57, 255 }, 0);
		GUI::String({ window_pos.x + 20, window_pos.y , 300, 40 }, title, { 255, 255, 255, 255 }, false, 11);
		next_item_pos = { window_pos.x + pos.x + 15, window_pos.y + pos.y + 17 };
	}

	inline void Slider(const wchar_t* title, float& value, float min, float max, wchar_t* type = _(L"%d"))
	{

		if (GUI::is_mouse_in_box({ next_item_pos.x - 5, next_item_pos.y }, { next_item_pos.x + 160, next_item_pos.y + 25 }) && mouse_state && !inColorPicker) {

			float m_flFilled = ((old_mouse_pos.x - next_item_pos.x) / 150);
			value = (max - min) * m_flFilled;

			if (value > max) value = max; if (value < min) value = min;
		}

		wchar_t Active[512];
		f_swprint(Active, type, static_cast<int>(value));

		// slider render //
		GUI::FillBoxRounded({ next_item_pos.x - 2, next_item_pos.y, 150, 16 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill, 2);
		GUI::FillBoxRounded({ next_item_pos.x - 2, next_item_pos.y, ((float)(value * 150) / max), 16 }, Color(255, 255, 255, 255), ScaleMode::StretchToFill, 2);
		GUI::FillCornerBoxRounded({ next_item_pos.x - 3, next_item_pos.y - 1, 152, 18 }, Color(60, 60, 60, 170), 2);

		GUI::String({ next_item_pos.x - 2, next_item_pos.y, 150, 16 }, title, { 255, 255, 255, 225 }, true, Vars::GUITextSize);
		// value render //
		GUI::FillBoxRounded({ next_item_pos.x + 154, next_item_pos.y - 1, 37, 18 }, Color(60, 60, 60, 170), ScaleMode::StretchToFill, 2);
		GUI::FillBoxRounded({ next_item_pos.x + 155, next_item_pos.y, 35, 16 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill, 2);
		GUI::String({ next_item_pos.x + 155, next_item_pos.y, 35, 16 }, Active, { 255, 255, 255, 225 }, true, Vars::GUITextSize);

		next_item_pos.y += 28;
	}


	inline void IntSlider(const wchar_t* title, int& value, float min, float max)
	{

		if (GUI::is_mouse_in_box({ next_item_pos.x - 5, next_item_pos.y }, { next_item_pos.x + 160, next_item_pos.y + 25 }) && mouse_state && !inColorPicker) {

			float m_flFilled = ((old_mouse_pos.x - next_item_pos.x) / 150);
			value = (max - min) * m_flFilled;

			if (value > max) value = max; if (value < min) value = min;
		}

		wchar_t Active[512];
		f_swprint(Active, _(L"%d"), static_cast<int>(value));

		// slider render //
		GUI::FillBoxRounded({ next_item_pos.x - 2, next_item_pos.y, 150, 16 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill, 2);
		GUI::FillBoxRounded({ next_item_pos.x - 2, next_item_pos.y, ((float)(value * 150) / max), 16 }, Color(255, 255, 255, 255), ScaleMode::StretchToFill, 2);
		GUI::FillCornerBoxRounded({ next_item_pos.x - 3, next_item_pos.y - 1, 152, 18 }, Color(60, 60, 60, 170), 2);

		GUI::String({ next_item_pos.x - 2, next_item_pos.y, 150, 16 }, title, { 255, 255, 255, 225 }, true, Vars::GUITextSize);
		// value render //
		GUI::FillBoxRounded({ next_item_pos.x + 154, next_item_pos.y - 1, 37, 18 }, Color(60, 60, 60, 170), ScaleMode::StretchToFill, 2);
		GUI::FillBoxRounded({ next_item_pos.x + 155, next_item_pos.y, 35, 16 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill, 2);
		GUI::String({ next_item_pos.x + 155, next_item_pos.y, 35, 16 }, Active, { 255, 255, 255, 225 }, true, Vars::GUITextSize);

		next_item_pos.y += 28;
	}

	void Hotkey(int* key, int* Type, bool& value, bool* GetKeyBind) {
		next_item_pos.x += 10;
		Rect TextPos = Rect(next_item_pos.x, next_item_pos.y, 200, 150);
		if (GUI::MouseInZone(Vector2{ next_item_pos.x + 130, next_item_pos.y - 5 }, { 80, 16 }) && mouse_state && !old_mouse_state)
		{
			*GetKeyBind = !*GetKeyBind;
		}

		Rect textPos = Rect{ next_item_pos.x + 130, next_item_pos.y - 5, 200,150 };

		GUI::FillBoxRounded({ next_item_pos.x + 130, next_item_pos.y - 5, 50, 16 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill, 2);
		GUI::FillCornerBoxRounded({ next_item_pos.x + 129, next_item_pos.y - 6, 52, 18 }, Color(60, 60, 60, 170), 2);

		if (*GetKeyBind)
		{
			GUI::String({ next_item_pos.x + 130, next_item_pos.y - 5, 50,16 }, _(L"..."), Color(255, 255, 255, 170), true, 10);

			for (int code = 0; code < 329; code++)
			{
				if (Unity::GetKeyInt(code))
				{
					if (code != 323)
					{
						*GetKeyBind = false;
						*key = code;
					}
				}
			}
		}
		else
		{
			Rect textPos = Rect{ next_item_pos.x + 130, next_item_pos.y - 5, 50,16 };
			GUI::String(textPos, get_keystr(*key), Color{ 255, 255, 255, 200 }, true);
		}

		if (GUI::is_mouse_in_box({ next_item_pos.x + 110, next_item_pos.y }, { next_item_pos.x + 126, next_item_pos.y + 20 }) && mouse_state && !old_mouse_state) // && !inColorPicker
			value = !value;
		
		GUI::FillBoxRounded({ next_item_pos.x + 110 , next_item_pos.y - 5, 16, 16 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill, 2);
		GUI::FillCornerBoxRounded({ next_item_pos.x + 109 , next_item_pos.y - 6, 18, 18 }, Color(60, 60, 60, 170), 2);

		// GUI::FillBoxRounded({ next_item_pos.x + 100 , next_item_pos.y - 4, 16, 16 }, { 0, 162, 152, 200 }, ScaleMode::ScaleAndCrop, 2); // 160,20,100,200
		GUI::String({ next_item_pos.x + 112 , next_item_pos.y - 5, 16, 16 }, value ? _(L"T") : _(L"H"), Color(255, 255, 255, 255), true, 10);

		if (!value)	*Type = 1; else if (value) *Type = 0;
		next_item_pos.x -= 10;

	}

	bool combo_(Str name, int* current_item, bool (*items_getter)(void*, int, const wchar_t**), void* data, int items_count) {
		const wchar_t* preview_value = NULL;
		next_item_pos.y += 2;
		if (*current_item >= 0 && *current_item < items_count) GUI::Items_ArrayGetter(data, *current_item, &preview_value);
		auto size = Vector2(195, 20);
		if (GUI::MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x + 20,size.y }) && mouse_state && !old_mouse_state) {
			GUI::list_clicked2 = !GUI::list_clicked2;
			if (GUI::list_open2 != current_item)
				GUI::list_open2 = current_item;
		}
		const wchar_t* item_text = _(L"");

		GUI::StartGlRender(render_type::box, { next_item_pos.x - 1, next_item_pos.y - 1 }, { size.x + 2, size.y + 2 }, { 23, 23, 23, 255 });
		GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 30, 30, 30, 255 });
		GUI::StartGlRender(render_type::triangle, { next_item_pos.x + size.x - 1 - 5, next_item_pos.y + size.y - 15 }, { next_item_pos.x + size.x - 1 - 15, next_item_pos.y + size.y - 15 }, { 255, 255, 255,60 }, { next_item_pos.x + size.x - 1 - 10, next_item_pos.y + size.y - 5 }, 0, Vector2(Vars::ScreenWidth / 2, Vars::ScreenHeight), { 10,20 });
		GUI::String({ next_item_pos.x + 5, next_item_pos.y - 1 , 200, 20 }, preview_value, Color(255, 255, 255, 255));

		bool value_changed = false;
		if (GUI::list_clicked2 && GUI::list_open2 == current_item) {

			for (int i = 0; i < items_count; i++) {
				const bool item_selected = (i == *current_item);
				if (!GUI::Items_ArrayGetter(data, i, &item_text)) item_text = _(L"???");
				next_item_pos.y += 20;
				if (GUI::MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x + 20,size.y }) && mouse_state && !old_mouse_state) {
					value_changed = true;
					*current_item = i;
				}
				Color clr = GUI::MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x,size.y }) && !(*current_item == i) ? Color(40, 40, 40, 255) : Color(30, 30, 30, 255);
				GUI::StartGlRender(render_type::box, { next_item_pos.x - 1, next_item_pos.y - 1 }, { size.x + 2, size.y + 2 }, { 23, 23, 23, 255 });
				GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, clr);

				GUI::String({ next_item_pos.x + 5, next_item_pos.y, 200, 20 }, item_text, Color(102, 102, 100, 200));

				if (*current_item == i)
					GUI::String({ next_item_pos.x + 5, next_item_pos.y + 1 , 200, 20 }, item_text, Color(255, 255, 255, 255));
			}
		}
		else {

		}


		next_item_pos.y += 32;
		return value_changed;
	}

	bool Combo(const wchar_t* name, int* current_item, const wchar_t* const items[], int items_count)
	{
		GUI::String({ next_item_pos.x + 5, next_item_pos.y - 12 , 180, 20 }, name, Color(255, 255, 255, 255), 18);
		const bool value_changed = combo_(name, current_item, GUI::Items_ArrayGetter, (void*)items, items_count);
		return value_changed;
	}

	static void MultiComboBox()
	{

	}

	void DoColorPicker(Color& outColor, bool& Value, bool isSecond, float Take = 0)
	{
		next_item_pos.y -= 4;
		float DistFromStart = isSecond ? 100 : 80;
		Vector2 pos = { next_item_pos.x + DistFromStart, next_item_pos.y };
		if (GUI::is_mouse_in_box({ pos.x, pos.y }, { pos.x + 14, pos.y + 14 }) && mouse_state && !old_mouse_state) {
			Value = !Value;
		}

		GUI::FillBoxRounded({ pos.x - 2, pos.y - 2,16, 16 }, Color(60, 60, 60, 170), ScaleMode::StretchToFill, 2);
		GUI::FillBoxRounded({ pos.x, pos.y,12, 12 }, outColor, ScaleMode::StretchToFill, 2);


		if (Value)
		{
			// GUI::FillCornerBoxRounded({ pos.x - 2, pos.y - 2,16, 16 }, outColor, 2);
			pos = { next_item_pos.x + DistFromStart + 40, next_item_pos.y };
			GUI::FillBoxRounded({ pos.x + 20, pos.y - 5 , 100, 100 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill, 0);

			GUI::DrawColorPickerColor(pos.x + 25.f, pos.y);

			if (GUI::MouseInZone({ pos.x + 25, pos.y }, { 90, 90 }) && mouse_state)
			{
				Color endColor = GUI::GetColorFromPenPosition({ mouse_pos.x - (pos.x + 25), mouse_pos.y - (pos.y) });
				outColor = endColor;
			}
		}
		next_item_pos.y += 4;
	}
};

void DrawNewMenu()
{
	if (!GUI::open) return;

	static bool InitColors = false;
	if (!InitColors)	
	{ // WeaponVisible
		//ColorPicker::SkeletonsVisible = Color(58, 214, 0, 255);// ColorPicker::Test
		//ColorPicker::SkeletonsInVisible = Color(230, 31, 0, 255);// ColorPicker::Test

		//ColorPicker::BoxVisible = Color(58, 214, 0, 255);//
		//ColorPicker::BoxInVisible = Color(230, 31, 0, 255);//

		//ColorPicker::TextEspVisible = Color(3, 221, 255, 255);//
		//ColorPicker::TextEspInVisible = Color(255, 80, 180, 255);//

		//ColorPicker::WeaponVisible = Color(3, 221, 255, 255);//
		//ColorPicker::WeaponInVisible = Color(255, 80, 180, 255);//

		//ColorPicker::FlagsVisible = Color(3, 221, 255, 255);//
		//ColorPicker::FlagsInVisible = Color(255, 80, 180, 255);//

		//ColorPicker::MovmentLine = Color(3, 221, 255, 255);//
		//ColorPicker::Fov = Color(3, 221, 255, 255);//

		//ColorPicker::SkyColor = Color(255, 80, 180, 255);//
		//ColorPicker::AmbientColor = Color(255, 80, 180, 255);//

		//ColorPicker::BulletTracer = Color(255, 255, 255, 255);//
		//ColorPicker::OOFVisible = Color(58, 214, 0, 255);//

		//ColorPicker::OOFInVisible = Color(230, 31, 0, 255);//
		//ColorPicker::PlayerChamsVisible = Color(127, 255, 0, 255);//
		//ColorPicker::PlayerChamsInVisible = Color(220, 20, 60, 255);//

		//ColorPicker::HandChams2 = Color(230, 31, 0, 255);//
		//ColorPicker::HandChams = Color(127, 255, 0, 255);//

		//ColorPicker::RadarVisible = Color(230, 31, 0, 255);//
		//ColorPicker::RadarInVisible = Color(127, 255, 0, 255);//
		InitColors = true;
	}


	const wchar_t* CrossType[] = { _(L"None"),_(L"Coss"),_(L"Dot"), };

	const wchar_t* PlayerChamsCombo[] = { _(L"Storm"),_(L"Pink Galaxy"), _(L"Green Galaxy"), _(L"Red Galaxy"),_(L"Blue Galaxy"), };

	const wchar_t* HandChamsCombo[] = { _(L"Storm"),_(L"Pink Galaxy"), _(L"Green Galaxy"), _(L"Red Galaxy"),_(L"Blue Galaxy"), };

	const wchar_t* BoxCombo[] = { _(L"None"),_(L"Default Box"),_(L"Corner Box"), };

	const wchar_t* HealthCombo[] = { _(L"None"),_(L"Vertical"),_(L"Horizontal"), };

	const wchar_t* IndicatorCombo[] = { _(L"Nicotine"),_(L"DS"), };

	const wchar_t* TargtCombo[] = { _(L"Head"),_(L"Body"), };

	const wchar_t* BehindWallCombo[] = { _(L"Normal"),_(L"Hvh") };
	// Small/Average/Big
	const wchar_t* BulletTpCombo[] = { _(L"Small"),_(L"Average"),_(L"Big") };

	const wchar_t* HitBoxOVPlayerMulti[] = { _(L"None"),_(L"Head"),_(L"Body"),_(L"Random No Head"),_(L"Random With Head") };
	const wchar_t* LookWarnCombo[] = { _(L"Everyone"), _(L"Threat") };

	// 2 // 4 // 5
	const wchar_t* CfgArray[] = { _(L"Legit"),_(L"Rage"), _(L"Other"), };
	const wchar_t* AutoFarmTargetCombo[] = { _(L"None"),_(L"Stone Ore"), _(L"Metal Ore"),_(L"Sulfur Ore"), _(L"Tree"), _(L"Road Loot"), };

	const wchar_t* AutoFarmModeCombo[] = { _(L"Smart"), _(L"Retard"), };
	const wchar_t* BehindTypeCombo[] = { _(L"On Manipulation"), _(L"Always"), };

	const wchar_t* HammerSpamCombo[] = { _(L"Local"), _(L"Target"), };

	const wchar_t* AutoShootType[] = { _(L"No Animation"),_(L"Silent"), };
	bool* ComboAutoShoot[] = { &Vars::Exploits::AutoShootType[0], &Vars::Exploits::AutoShootType[1], };

	const wchar_t* FontsCombo[] = { _(L"Default"), _(L"Pixel"), };

	main_menu_open = GUIElements::CreateMenu(_(L"Nicotine"), { 50, 50 }, { 750 , 610 }, false);
	////////////////////////////// GUI CODE //////////////////////////////
	// 203
	GUIElements::Tab(_(L"Combat"), 0, Vector2(146, 80));
	GUIElements::Tab(_(L"Player Visuals"), 1, Vector2(146, 80));
	GUIElements::Tab(_(L"World Visuals"), 2, Vector2(146, 80));
	GUIElements::Tab(_(L"Misc"), 3, Vector2(146, 80));
	GUIElements::Tab(_(L"Config"), 4, Vector2(146, 80));

	switch (Vars::ActiveTab)
	{
		///////////// COMBAT /////////////
	case 0:

		GUIElements::TabChild(_(L""), { 25, 320 }, { 223, 270 });
		{
			GUIElements::Hotkey(&Vars::Keys::ManipulationKey, &Vars::Keys::ManipulationKeyType, Vars::Keys::ManipulationVal, &HotKey_Manipulation);
			GUIElements::CheckBox(_(L"Desync"), Vars::Exploits::Manipulation);
			
			GUIElements::IntSlider(_(L"Desync Percentage"), Vars::Exploits::DesyncPercentage, 0.0, 100);

			GUIElements::CheckBox(_(L"Visualize"), Vars::Exploits::Visualize);
			GUIElements::IntSlider(_(L"Manipulation Sectors"), Vars::Exploits::CheckAngels, 0, 24);
			GUIElements::IntSlider(_(L"Manipulation Layers"), Vars::Exploits::Optimisation, 0, 12);
			GUIElements::CheckBox(_(L"Desync Indicator"), Vars::Visuals::DesyncBar);
			GUIElements::CheckBox(_(L"Auto Stop"), Vars::Exploits::AutoStopOnManipulation);
			GUIElements::CheckBox(_(L"Behind Wall"), Vars::Exploits::BehindWall);
			if (Vars::Exploits::BehindWall)
				Vars::Exploits::BahindWallType == 1;
			else Vars::Exploits::BahindWallType == 0;
			if (Vars::Exploits::BehindWall)
			{
				GUIElements::IntSlider(_(L"Scan Points"), Vars::Exploits::BehindWallScanStrength, 0, 30);
				GUIElements::Combo(_(L"BehindWall Mode"), &Vars::Exploits::BehindWallType, BehindWallCombo, ARRAYSIZE(BehindWallCombo));

				if (Vars::Exploits::BehindWallType == 0)
					Vars::Exploits::DistanceToBulletTp = 0.10;
				if (Vars::Exploits::BehindWallType == 1)
					Vars::Exploits::DistanceToBulletTp = 0.05;
				GUI::Slider(_(L"Distance To Bullet Tp"), Vars::Exploits::DistanceToBulletTp, 0, 0.5);
			}
			
		}

		GUIElements::TabChild(_(L""), { 25, 70 }, { 223, 240 });
		{
			GUIElements::Hotkey(&Vars::Keys::KeepTarget, &Vars::Keys::KeepTargetType, Vars::Keys::KeepTargetVal, &HotKey_KeepTarget);
			GUIElements::CheckBox(_(L"pSilent"), Vars::Aim::pSilent);
			GUIElements::IntSlider(_(L"pSilent Spread"), Vars::Aim::pSilentSpread, 0, 100);
			GUIElements::CheckBox(_(L"Melee pSilent"), Vars::Exploits::MeleePsilent);
			GUIElements::DoColorPicker(ColorPicker::Fov, ColorPicker::FovBool, true);
			GUIElements::CheckBox(_(L"Draw Fov"), Vars::Aim::DrawFov);
			GUIElements::IntSlider(_(L"Fov Range"), Vars::Aim::AimFov, 0, 1000);
			GUIElements::CheckBox(_(L"Silent Melee"), Vars::Aim::SilentMelee);

			GUIElements::CheckBox(_(L"Target Line"), Vars::Visuals::PlayerEsp::TargetLine);
			GUIElements::DoColorPicker(ColorPicker::BulletTracer, ColorPicker::BulletTracerBool, true);
			GUIElements::CheckBox(_(L"Bullet Traces"), Vars::Visuals::BulletTraces);
			GUIElements::Combo(_(L"Target Bone"), &Vars::Aim::AimCombo, TargtCombo, ARRAYSIZE(TargtCombo));

		}

		GUIElements::TabChild(_(L""), { 263, 260 }, { 223, 140 });
		{
			GUIElements::CheckBox(_(L"Shoot Through Teammates"), Vars::Exploits::ShootThroughTeammates);
			GUIElements::CheckBox(_(L"Heli Override"), Vars::Exploits::HeliOverride);
			GUIElements::CheckBox(_(L"Magic Heli"), Vars::Exploits::HeliMagic);
			// GUI::CheckBox(_(L"Ukn Meme"), Vars::Exploits::UknMeme);
			GUIElements::Combo(_(L"Bone Override"), &Vars::Exploits::PlayerOverride, HitBoxOVPlayerMulti, ARRAYSIZE(HitBoxOVPlayerMulti));
		}

		GUIElements::TabChild(_(L""), { 263, 70 }, { 223, 180 });
		{
			GUIElements::Hotkey(&Vars::Keys::AutoShoot, &Vars::Keys::AutoShootType, Vars::Keys::AutoShootVal, &HotKey_AutoShoot);
			GUIElements::CheckBox(_(L"Auto Shoot"), Vars::Exploits::AutoShoot);
			GUIElements::CheckBox(_(L"Power Shot"), Vars::Aim::InstaKill); // Vars::Exploits::UknMeme

			GUIElements::CheckBox(_(L"Insta Hit"), Vars::Exploits::InstaHit);
			GUIElements::CheckBox(_(L"Bullet Tp"), Vars::Exploits::BulletTp);

			GUIElements::CheckBox(_(L"Visualization"), Vars::Exploits::DrawBulletTp);

			GUIElements::CheckBox(_(L"Extend On Mounted"), Vars::Exploits::isBulletTpExternded);
			GUIElements::Combo(_(L"Bullet Tp Mode"), &Vars::Exploits::BulletTpType, BulletTpCombo, ARRAYSIZE(BulletTpCombo));
		}

		GUIElements::TabChild(_(L""), { 501, 70 }, { 223, 140 });
		{

		}
		break;
		///////////// COMBAT /////////////
	case 1:
		GUIElements::TabChild(_(L""), { 25, 70 }, { 223, 240 });
		{

		}

		GUIElements::TabChild(_(L""), { 263, 70 }, { 223, 140 });
		{

		}

		GUIElements::TabChild(_(L""), { 501, 70 }, { 223, 140 });
		{

		}
		break;
	case 2:

		break;
	case 3:

		break;
	}
	////////////////////////////// GUI CODE //////////////////////////////
	GUI::end_window();
	return;
}