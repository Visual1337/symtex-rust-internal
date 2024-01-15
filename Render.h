bool inited = false;
#define _FI __forceinline
DWORD64 g_WhiteTexture;
DWORD64 g_TestTexture;
#define M_PI 3.14159265358979323846
bool inColorPicker = false;

bool wakeup{ false };
bool sex{ false };
Vector2 window_pos{ 50, 50 }, mouse_pos, next_item_pos;
Vector2 window_sizemain;
Vector2 old_mouse_pos;
bool mouse_state, insert_state;
EventType menu_event;
bool old_mouse_state, old_insert_state;
int curkey;
float menu_alpha;
Vector2 widget_mouse_pos, old_widget_mouse_pos;
bool widget_state, old_widget_state;
float color_picker_alpha;
bool is_menu_open{ true };
bool interacting;
bool main_menu_open = false;

Color MyRGB;

Color MainColor = Color(200, 30, 30, 255);
Color ActiveColor = Color(255, 60, 60, 255);

enum class ScaleMode
{
	StretchToFill = 0,
	ScaleAndCrop = 1,
	ScaleToFit = 2,
};

enum class render_type {
	line = 1,
	fov,
	box,
	boxoutline,
	triangle
};


// internal static Material get_blendMaterial() { }

DWORD64 blendMaterial = NULL;
DWORD64 gl_material = NULL;


namespace GUI
{
	DWORD64 blendMat = 0;
	// Material get_blendMaterial() { }

	auto get_blendMaterial = reinterpret_cast<DWORD64(*)()>(0);

	auto get_current = reinterpret_cast<DWORD64(*)()>(0);

	auto get_type = reinterpret_cast<EventType(*)(DWORD64)>(0);

	auto Find = reinterpret_cast<DWORD64(*)(Str)>(0);
	auto SetInt = reinterpret_cast<void(*)(DWORD64, Str, int)>(0);
	auto SetRange = reinterpret_cast<void(*)(DWORD64, float)>(0);

	auto PopMatrix = reinterpret_cast<void(*)()>(0);

	auto End = reinterpret_cast<void(*)()>(0);

	auto Vertex = reinterpret_cast<void(*)(Vector3)>(0);

	auto ColorVer = reinterpret_cast<void(*)(Color)>(0);

	auto Begin = reinterpret_cast<void(*)(int)>(0);

	auto SetPass = reinterpret_cast<bool(*)(DWORD64, int)>(0);

	auto PushMatrix = reinterpret_cast<void(*)()>(0);

	auto MultMatrix = reinterpret_cast<void(*)(Matrix4x4Line)>(0);

	auto create_with_shader_fn = reinterpret_cast<void(*)(DWORD64, DWORD64)>(0);

	auto dont_destroy_on_load = reinterpret_cast<void(*)(DWORD64)>(0);

	auto draw_get = reinterpret_cast<void (*)()>(0);

	auto get_whiteTexture = reinterpret_cast<DWORD64(*)()>(0);

	auto get_skin = reinterpret_cast<DWORD64(*)()>(0);

	auto set_fontSize = reinterpret_cast<void(*)(DWORD64, int)>(0);

	auto set_color = reinterpret_cast<void(*)(Color)>(0);

	auto set_alignment = reinterpret_cast<void(*)(DWORD64, DWORD64)>(0);
	//MethodSin = reinterpret_cast<int(*)(double)>(
	namespace GuiMethods
	{
		auto get_mousePosition = reinterpret_cast<Vector3(*)()>(0);


		auto create = reinterpret_cast<void(*)(DWORD64, Str)>(0);

		auto add_component = reinterpret_cast<void(*)(DWORD64, DWORD64)>(0);

		auto Update = reinterpret_cast<void (*)(void*)>(0);

		//auto get_whiteTexture = reinterpret_cast<DWORD64(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));

		auto Label = reinterpret_cast<void(*)(Rect, DWORD64, DWORD64)>(0);

		auto get_texture = reinterpret_cast<DWORD64(*)(DWORD64)>(0);

		auto DrawTextureRounded = reinterpret_cast<void (*)(Rect, DWORD64, ScaleMode, bool, float, Color, float, float)>(0);

		auto DrawTexture = reinterpret_cast<void (*)(Rect, DWORD64)>(0);

		auto content_temp = reinterpret_cast<DWORD64(*)(Str*)>(0);

		//auto Label = reinterpret_cast<void(*)(Rect, DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

		void InitMethods()
		{
			// get_blendMaterial = reinterpret_cast<DWORD64(*)()>((DWORD64)(Il2cpp::Method(_("GUI"), _("get_blendMaterial"), 0, _(""), _("UnityEngine"))));
			/*get_blendMaterial = reinterpret_cast<DWORD64(*)()>((DWORD64)(Il2cpp::Method(_("GUI"), _("get_blendMaterial"), 0, _(""), _(""))));
			blendMaterial = get_blendMaterial();*/
			Label = reinterpret_cast<void(*)(Rect, DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

			DrawTexture = reinterpret_cast<void (*)(Rect, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));

			set_alignment = reinterpret_cast<void(*)(DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUIStyle"), _("set_alignment"), -1, _(""), _("UnityEngine"))));

			content_temp = reinterpret_cast<DWORD64(*)(Str*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

			get_whiteTexture = reinterpret_cast<DWORD64(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));

			get_skin = reinterpret_cast<DWORD64(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));

			set_fontSize = reinterpret_cast<void(*)(DWORD64, int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUIStyle"), _("set_fontSize"), -1, _(""), _("UnityEngine"))));

			set_color = reinterpret_cast<void(*)(Color)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUI"), _("set_color"), -1, _(""), _("UnityEngine"))));

			MethodSin = reinterpret_cast<double(*)(double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), ("Sin"), -1, _(""), _("System"))));

			MethodTan = reinterpret_cast<double(*)(double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), ("Tan"), -1, _(""), _("System"))));

			MethodCos = reinterpret_cast<double(*)(double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), ("Cos"), -1, _(""), _("System"))));

			MethodSqrt = reinterpret_cast<double(*)(double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), ("Sqrt"), -1, _(""), _("System"))));

			MethodAcos = reinterpret_cast<double(*)(double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), ("Acos"), -1, _(""), _("System"))));

			MethodClamp = reinterpret_cast<int(*)(int, int, int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), _("Clamp"), 3, _(""), _("System"))));

			MethodASIN = reinterpret_cast<double(*)(double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), ("Asin"), -1, _(""), _("System"))));

			MethodATAN2 = reinterpret_cast<double(*)(double, double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), _("Atan2"), -1, _(""), _("System"))));
			MethodATAN = reinterpret_cast<double(*)(double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), _("Atan"), -1, _(""), _("System"))));
			MethodABS = reinterpret_cast<double(*)(double)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Math"), ("Abs"), -1, _(""), _("System"))));

			get_type = reinterpret_cast<EventType(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));

			get_current = reinterpret_cast<DWORD64(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));

			draw_get = reinterpret_cast<void (*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("DDraw"), _("Get"), 0, _(""), _("UnityEngine"))));

			create_with_shader_fn = reinterpret_cast<void(*)(DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Material"), _("CreateWithShader"), 0, _(""), _("UnityEngine"))));
		}
		void InitMethods2()
		{



			Find = reinterpret_cast<DWORD64(*)(Str)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));

			SetInt = reinterpret_cast<void(*)(DWORD64, Str, int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Material"), _("SetInt"), 1, _(""), _("UnityEngine"))));

			PopMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GL"), _("PopMatrix"), 0, _(""), _("UnityEngine"))));

			End = reinterpret_cast<void(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GL"), _("End"), 0, _(""), _("UnityEngine"))));

			Vertex = reinterpret_cast<void(*)(Vector3)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GL"), _("Vertex"), 0, _(""), _("UnityEngine"))));

			ColorVer = reinterpret_cast<void(*)(Color)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GL"), _("Color"), 0, _(""), _("UnityEngine"))));

			Begin = reinterpret_cast<void(*)(int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GL"), _("Begin"), 0, _(""), _("UnityEngine"))));

			SetPass = reinterpret_cast<bool(*)(DWORD64, int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Material"), _("SetPass"), 0, _(""), _("UnityEngine"))));

			PushMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GL"), _("PushMatrix"), 0, _(""), _("UnityEngine"))));

			MultMatrix = reinterpret_cast<void(*)(Matrix4x4Line)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GL"), _("MultMatrix"), 0, _(""), _("UnityEngine"))));
			//GUI::MultMatrix = reinterpret_cast<void(*)(Matrix4x4)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GL"), _("MultMatrix"), 0, _(""), _("UnityEngine"))));

			DrawTextureRounded = reinterpret_cast<void (*)(Rect, DWORD64, ScaleMode, bool, float, Color, float, float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUI"), _("DrawTexture"), 8, _("image"), _("UnityEngine"), 2)));

			get_texture = reinterpret_cast<DWORD64(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Sprite"), _("get_texture"), 0, _(""), _("UnityEngine"))));

			get_mousePosition = reinterpret_cast<Vector3(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Input"), _("get_mousePosition"), 0, _(""), _("UnityEngine"))));

			dont_destroy_on_load = reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Object"), _("DontDestroyOnLoad"), 0, _(""), _("UnityEngine"))));

			create = reinterpret_cast<void(*)(DWORD64, Str)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GameObject"), _("Internal_CreateGameObject"), 0, _(""), _("UnityEngine"))));

			add_component = reinterpret_cast<void(*)(DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GameObject"), _("Internal_AddComponentWithType"), 0, _(""), _("UnityEngine"))));

			Update = reinterpret_cast<void (*)(void*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PerformanceUI"), _("Update"), 0, _(""), _("Facepunch"))));

			Label = reinterpret_cast<void(*)(Rect, DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

			// g_WhiteTexture = get_whiteTexture();
		}
	}


	typedef void(__stdcall* Labell)(Rect, DWORD64, DWORD64);
	typedef void(__stdcall* Aligment)(DWORD64, DWORD64);
	typedef void(__stdcall* SetClr)(Color);
	typedef int(__stdcall* EventT)(DWORD64);
	typedef DWORD64(__stdcall* RetEmpty)();
	typedef void(__stdcall* SetText)(DWORD64, int);
	typedef DWORD64(__stdcall* Content)(Str*);
	typedef void(__stdcall* DrawT)(Rect, DWORD64);

	DWORD64 label, skin, labels;
	//DWORD64 Oselblya = (DWORD64)ZalupaImage;


// #include "bytes.h"
	void InitAssets()
	{
		Unity::GGshader = Unity::LoadFromFile(_(L"C:\\Asset.bundle"));
		Unity::NicotineBundle = Unity::LoadFromFile(_(L"C:\\kozimozi"));
		Unity::Harvey = Unity::LoadFromFile(_(L"C:\\Geometric_Dissolve.unity3d"));
		Unity::sandy = Unity::LoadFromFile(_(L"C:\\sandy.bundle"));
		Unity::sandy1 = Unity::LoadFromFile(_(L"C:\\sandy1.bundle"));
		Unity::FireBundleA = Unity::LoadFromFile(_(L"C:\\FireBundleA.bundle"));

	}

	void Init() {
		//if (Unity::MyFont) {
		//	DWORD64 currentFont = 0;
			// Vars::CurFont
		//	if (Vars::CurFont == 0)
		//		currentFont = Unity::LoadAsset(Unity::MyFont, _(L"assets/baloobhai2-bold.ttf"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Font")));
		//	if (Vars::CurFont == 1)
//				currentFont = Unity::LoadAsset(Unity::MyFont, _(L"assets/smallest_pixel-7.ttf"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Font")));
////
		//	Write<DWORD64>(skin + 0x18, currentFont);
		//}
		if (label && skin) return;

		GUI::skin = get_skin();
		GUI::label = safe_read(skin + 0x38, DWORD64);

		//Unity::MyFont = Unity::LoadFromFile(_(L"C:\\Windows\\Bundle\\fontsbundle"));

		set_alignment(label, 1);
		set_color(Color(1, 1, 1, 1));
	}

	inline void FillBoxRounded(Rect pos, Color clr, ScaleMode sm, float Round = 15) {
		GuiMethods::DrawTextureRounded(pos, g_WhiteTexture, sm, true, 1, clr.GetUnityColor(), 550, Round);
	}

	inline void DrawPng(Rect pos) {
		//if (Unity::LogoPng != 0)
		//{
		//	DWORD64 Png = (DWORD64)Unity::LoadAsset(Unity::LogoPng, _(L"Nicotine.png"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Texture2D")));
		//	GuiMethods::DrawTexture(pos, Png);
		//}
	}

	inline void FillCornerBoxRounded(Rect pos, Color clr, float round = 15) {
		GuiMethods::DrawTextureRounded(pos, g_WhiteTexture, ScaleMode::StretchToFill, true, 1, clr.GetUnityColor(), 1, round);
	}

	void InitGL()
	{
		if ((gl_material == NULL && !inited)) {
			gl_material = Il2cpp::object_new(Il2cpp::InitClass(_("Material"), _("UnityEngine")));
		}
		create_with_shader_fn(gl_material, Find(_(L"Hidden/Internal-Colored"))); // Hidden/Internal-Colored
		if (!inited) {
			dont_destroy_on_load(gl_material);
			inited = true;
		}

		
		/*if (!inited)
		{
			dont_destroy_on_load(gl_material);
		}*/
		
	}

	inline void drawFov()
	{
		float AimFov = Vars::Aim::AimFov * 2;;
		Color fovColor = ColorPicker::FovRGBBool ? RGBA() : ColorPicker::Fov;
		GuiMethods::DrawTextureRounded({ (float)Vars::ScreenWidth / 2 - AimFov / 2, (float)Vars::ScreenHeight / 2 - AimFov / 2, AimFov, AimFov }, g_WhiteTexture, ScaleMode::StretchToFill, true, 1, fovColor.GetUnityColor(), 1, 999);
	}

	inline void StartGlRender(render_type type, Vector2 pos = Vector2::Zero2(), Vector2 size = Vector2::Zero2(), Color col = { 255,0,0,255 }, Vector2 center = Vector2::Zero2(), float radius = 0.f, Vector2 start = Vector2::Zero2(), Vector2 end = Vector2::Zero2(), float thickness = 0) {
		if (gl_material && inited)
		{
			SetPass(gl_material, 0);
			if (type == render_type::triangle)
				Begin(4);
			if (type == render_type::box)
				Begin(5);
			if (type == render_type::fov || type == render_type::boxoutline)
				Begin(2);
			else
				Begin(1);

			ColorVer(col.GetUnityColor());
			if (type == render_type::line) {

				Vertex(Vector3(start.x, start.y, 0));
				Vertex(Vector3(end.x, end.y, 0));
			}
			if (type == render_type::fov) {
				for (float num = 0.f; num < 6.2831855; num += 0.1f)
				{
					Vertex(Vector3(Maths::m_Cos(num) * radius + center.x, Maths::m_Sin(num) * radius + center.y, 0));
					Vertex(Vector3(Maths::m_Cos(num + 0.1f) * radius + center.x, Maths::m_Sin(num + 0.1f) * radius + center.y, 0));
				}
			}
			if (type == render_type::box) {
				Vertex(Vector3(pos.x + 0.5f, pos.y + 0.5f, 0));
				Vertex(Vector3(pos.x + size.x + 0.5f, pos.y + 0.5f, 0));
				Vertex(Vector3(pos.x + size.x + 0.5f, pos.y + size.y + 0.5f, 0));
				Vertex(Vector3(pos.x + 0.5f, pos.y + size.y + 0.5f, 0));
				Vertex(Vector3(pos.x + 0.5f, pos.y + 0.5f, 0));
			}
			if (type == render_type::boxoutline) {
				Vertex(Vector3(pos.x + 0.5f, pos.y + 0.5f, 0));
				Vertex(Vector3(pos.x + size.x + 0.5f, pos.y + 0.5f, 0));
				Vertex(Vector3(pos.x + size.x + 0.5f, pos.y + size.y + 0.5f, 0));
				Vertex(Vector3(pos.x + 0.5f, pos.y + size.y + 0.5f, 0));
				Vertex(Vector3(pos.x + 0.5f, pos.y + 0.5f, 0));
			}
			if (type == render_type::triangle) {

				Vertex(Vector3(pos.x, pos.y, 0));
				Vertex(Vector3(size.x, size.y, 0));
				Vertex(Vector3(center.x, center.y, 0));
			}
			End();
		}
	}

	inline void String(Rect pos, Str text, Color clr, bool centered = false, float size = 8)
	{
		//Labell draw_label = (Labell)(g_Base + offsets::Label);
		DWORD64 content = GuiMethods::content_temp(&text);

		if (centered) set_alignment(label, 0x4);
		else set_alignment(label, 0x0);

		set_fontSize(label, 12);
		if (Vars::Config::OutLineText)
		{
			set_color({ 0,0,0,170 });
			GuiMethods::Label({ pos.x - 1, pos.y, pos.wid, pos.hei }, content, label);
			GuiMethods::Label({ pos.x + 1, pos.y, pos.wid, pos.hei }, content, label);
			GuiMethods::Label({ pos.x, pos.y - 1, pos.wid, pos.hei }, content, label);
			GuiMethods::Label({ pos.x, pos.y + 1, pos.wid, pos.hei }, content, label);
			/*GuiMethods::Label({ pos.x + 1, pos.y, pos.wid, pos.hei }, content, label);
			GuiMethods::Label({ pos.x, pos.y + 1, pos.wid, pos.hei }, content, label);*/
		}
		set_color(clr.GetUnityColor());
		GuiMethods::Label({ pos.x, pos.y, pos.wid, pos.hei }, content, label);
	}

	bool InsertPressed;
	bool open = false;

	inline void OnKeyUp(KeyCode key, KeyCode searchkey = KeyCode::Insert) {
		if (key == searchkey) {
			InsertPressed = false;
		}
	}

	inline void OnKeyDown(KeyCode key, KeyCode searchkey = KeyCode::Insert) {
		if (!InsertPressed && key == searchkey) {
			InsertPressed = true;
			open = !open;
		}
	}

	inline void DrawFadeRect(float x, float y, float w, float h, Color startColor, Color endColor, bool useByX = false)
	{
		int32_t startRed = (int32_t)startColor.r, startGreen = (int32_t)startColor.g, startBlue = (int32_t)startColor.b, startAlpha = (int32_t)startColor.a;
		int32_t endRed = (int32_t)endColor.r, endGreen = (int32_t)endColor.g, endBlue = (int32_t)endColor.b, endAlpha = (int32_t)endColor.a;

		float useBy = useByX ? w : h;

		for (int32_t i = 0; i < useBy; i++)
		{
			int32_t fadeRed, fadeGreen, fadeBlue, fadeAlpha;

			fadeRed = startRed + (i * (endRed - startRed) / useBy);
			fadeGreen = startGreen + (i * (endGreen - startGreen) / useBy);
			fadeBlue = startBlue + (i * (endBlue - startBlue) / useBy);
			fadeAlpha = startAlpha + (i * (endAlpha - startAlpha) / useBy);

			Vector2 first = useByX ? Vector2(x + i, y) : Vector2(x, y + i);
			Vector2 second = useByX ? Vector2(1, h) : Vector2(w, 1);
			StartGlRender(render_type::box, first, second, Color(fadeRed, fadeGreen, fadeBlue, fadeAlpha));
			// SourceDrawFilledRect(pMaterialSurface, x, y + i, w, 1, SColor(fadeRed, fadeGreen, fadeBlue, 255));
		}
	}

	uintptr_t BlitMaterial;
	uintptr_t BlendMaterial;
	uintptr_t AALineTexture;
	uintptr_t LineTexture;
	int AALineTextureInstanceID;
	int LineTextureInstanceID;

	Color perc_col(float Num, float alpha = 255)
	{

		float red, green, blue;
		if (Num < 0.5)
		{
			red = 255.f;
			green = 255.f;
			blue = 0;
		}
		else
		{
			red = Num * 2.f * 255.f;
			green = (2.f - 2.f * Num) * 255.f;
			blue = 0;
		}

		red -= 100;
		green -= 100;
		blue -= 100;
		return Color(red, green, blue, alpha);

	}

	float diff_but_if_equal_return_first(float a, float b) {
		if (a == b) return a;
		else return a = b;
	}

	/*Color SmoothGradient(const Color start, const Color end, int index, int total)
	{
		float r = Maths::m_Abs(diff_but_if_equal_return_first(start.r, end.r) / total);
		float g = Maths::m_Abs(diff_but_if_equal_return_first(start.g, end.g) / total);
		float b = Maths::m_Abs(diff_but_if_equal_return_first(start.b, end.b) / total);
		float a = Maths::m_Abs(diff_but_if_equal_return_first(start.a, end.a) / total);
		return Color(int(r * index), int(g * index), int(b * index), int(a * index));
	}*/

	inline Color SmoothGradient(Rect pos, bool Alpha, Color startColor, Color endColor)
	{
		float r = 0;
		float g = 0;
		float b = 0;
		float a = 255;
		if (Alpha)
			a = 0;

		for (int i = 0; i < 510; i++)
		{
			if (i <= 255)
			{
				r = i - 255;
				g = i + 2;
				b = i - 8;
				if (Alpha)
					a = i;
			}
			if (i > 255 && i <= 510)
			{// 255, 80, 180, 255 // 0, 252, 242, 255
				r = 0 - (i - 255);
				g = 252 - (i - 255);
				b = 242 - (i - 255);
				if (Alpha)
					a = 255;

				/*r = 255 - (i - 255);
				g = 80 - (i - 255);
				b = 180 - (i - 255);
				if (Alpha)
					a = 255;*/
			}
			// StartGlRender(render_type::box, { pos.x + (i / (float)5.23), pos.y }, { pos.wid - (i / (float)5.23), pos.hei }, Color(r, g, b, a));
		}

	}



	Color GetColorFromPenPosition(Vector2 pen)
	{
		int div = 90 / 6;
		int phase = pen.x / div;
		float t = ((int)pen.x % div) / (float)div;
		int r, g, b;

		switch (phase)
		{
		case(0):
			r = 255;
			g = 255 * t;
			b = 0;
			break;
		case(1):
			r = 255 * (1.f - t);
			g = 255;
			b = 0;
			break;
		case(2):
			r = 0;
			g = 255;
			b = 255 * t;
			break;
		case(3):
			r = 0;
			g = 255 * (1.f - t);
			b = 255;
			break;
		case(4):
			r = 255 * t;
			g = 0;
			b = 255;
			break;
		case(5):
			r = 255;
			g = 0;
			b = 255 * (1.f - t);
			break;
		}

		float sat = pen.y / 90;
		return Color(r + sat * (255 - r), g + sat * (255 - g), b + sat * (255 - b), 255);
	}

	void DrawColorPickerColor(float x, float y,int Width = 90, int Height = 90)
	{
		for (int i = 0; i < Width; i++)
		{
			int div = Width / 6;
			int phase = i / div;
			float t = (i % div) / (float)div;
			int r, g, b;

			switch (phase)
			{
			case(0):
				r = 255;
				g = 255 * t;
				b = 0;
				break;
			case(1):
				r = 255 * (1.f - t);
				g = 255;
				b = 0;
				break;
			case(2):
				r = 0;
				g = 255;
				b = 255 * t;
				break;
			case(3):
				r = 0;
				g = 255 * (1.f - t);
				b = 255;
				break;
			case(4):
				r = 255 * t;
				g = 0;
				b = 255;
				break;
			case(5):
				r = 255;
				g = 0;
				b = 255 * (1.f - t);
				break;
			}
			for (int k = 0; k < Height; k++)
			{
				float sat = k / (float)Height;
				int _r = r + sat * (255 - r);
				int _g = g + sat * (255 - g);
				int _b = b + sat * (255 - b);
				set_color(Color(r + sat * (255 - r), g + sat * (255 - g), b + sat * (255 - b), 255).GetUnityColor());
				GuiMethods::DrawTexture({ x + i, y + k, 1, 1 }, g_WhiteTexture);
				/*Interfaces::Surface->SetDrawColor(_r, _g, _b, 255);
				Framework::DrawFilledRect(10 + i, 10 + k, 1, 1);*/
			}
		}
	}

	inline void DrawBar(Vector2 start, Vector2 end, float a, float b, bool full = true)
	{
		if (a < 0) return;
		if (full)
			GUI::FillBoxRounded({ start.x, start.y , end.x, end.y + 1 }, Color(0, 0, 0, 170), ScaleMode::StretchToFill, 15);
		if ((a / b) > 1)
			a = b;
		GUI::FillBoxRounded({ start.x + 1, start.y + 1 , (end.x * (a / b)) - 1, end.y - 1 }, { 0,255,0,255 }, ScaleMode::StretchToFill, 15); // perc_col(a / b)
	}


	inline void DrawBar1(Vector2 start, Vector2 end, float a, float b, bool full = true)
	{
		if (a < 0) return;

		Color nigga;
		if (a == 0.2)
		{
			nigga = Color(0, 255, 0, 255);
		}
		else if (a == 0.5)
		{
			nigga = Color(255, 165, 0, 255);
		}
		else if (a == 0.8)
		{
			nigga = Color(255, 0, 0, 255);
		}

		if (full)
			GUI::FillBoxRounded({ start.x, start.y , end.x, end.y + 1 }, Color(0, 0, 0, 170), ScaleMode::StretchToFill, 15);
		if ((a / b) > 1)
			a = b;
		

		GUI::FillBoxRounded({ start.x + 1, start.y + 1 , (end.x * (a / b)) - 1, end.y - 1 }, nigga, ScaleMode::StretchToFill, 15); // perc_col(a / b)
	}
	

	inline bool is_mouse_in_box(const Vector2& pos1, const Vector2& pos2) {
		if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y)
			return false;
		if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y)
			return false;

		return true;
	}

	inline bool MouseInZone(Vector2 pos, Vector2 size)
	{
		if (mouse_pos.x > pos.x && mouse_pos.y > pos.y)
			if (mouse_pos.x < pos.x + size.x && mouse_pos.y < pos.y + size.y)
				return true;
		return false;
	}
	bool hover_element = false;

	int* list_open2 = 0;
	bool list_clicked2 = false;

	// using namespace std;
	// #include <array>
	static bool combo_clicked = false;
	inline void MultiCombo(const wchar_t* name, const wchar_t* combo_str[], bool* comb[], int num = 8)
	{
		auto size = Vector2(100, 20);
		if (MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x,size.y }) && mouse_state && !old_mouse_state) {
			combo_clicked = !combo_clicked; //if (list_clicked2)  list_clicked2 = !list_clicked2;
		}
		Color color = Color(34, 41, 47, 255);
		Color color2 = Color(255, 0, 0, 255);
		GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 23, 23, 23, 255 });
		GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 255,255,255, 60 });

		GUI::String({ next_item_pos.x, next_item_pos.y,150,20 }, name, Color(255, 255, 255, 255));

		if (combo_clicked) {

			for (size_t i = 0; i < num; i++) {
				next_item_pos.y += 20;
				if (MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x,size.y }) && mouse_state && !old_mouse_state) if (&comb[i])*comb[i] = !*comb[i];
				GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 23, 23, 23, 255 });
				GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 255,255,255, 60 });
				auto name = combo_str[i];
				bool s = *comb[i];
				GUI::String({ next_item_pos.x + 5, next_item_pos.y,150,20 }, name, Color(255, 255, 255, 150));

				if (s) String({ next_item_pos.x + 5, next_item_pos.y ,150,20 }, name, Color(255, 255, 255, 255));
			}
		}
		next_item_pos.y += 30;
	}

	inline bool Button(const wchar_t* title)
	{
		bool pressing = false;
		if (is_mouse_in_box({ next_item_pos.x, next_item_pos.y }, { next_item_pos.x + 100, next_item_pos.y + 20 }) && mouse_state) // && !inColorPicker
			pressing = true;

		GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { 100, 20 }, { 23, 23, 23, 255 });
		GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x, next_item_pos.y }, { 100, 20 }, pressing ? Color(0, 252, 242, 255) : Color(65, 65, 65, 255));
		String({ next_item_pos.x + 5, next_item_pos.y + 2, 200, 20 }, title, Color(200, 200, 200, 200));
		//FillBoxRounded({ next_item_pos.x + 210 - dist , next_item_pos.y + 1, 26, 10 }, { 0, 162, 152, 200 }, ScaleMode::ScaleAndCrop, 1); // 160,20,100,200
		//FillBoxRounded(Rect(!value ? next_item_pos.x + 208 - dist : next_item_pos.x + 222 - dist, next_item_pos.y - 2, 16, 16), !value ? Color(0, 182, 172, 255) : Color(0, 252, 242, 255), ScaleMode::ScaleAndCrop, 20);
		//StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y + 16 }, { 60, 16 }, pressing ? Color(0, 252, 242, 255) : Color(65, 65, 65, 255 ));
		//String({ next_item_pos.x, next_item_pos.y + 16 , 200, 16 }, title, Color(255, 255, 255, 255), false, 18);
		// 180, 40, 120, 255
		next_item_pos.x += 120;
		return pressing;
	}

	inline bool GetToggleKey(KeyCode searchkey, bool& Pressed, bool& Open)
	{
		DWORD64 Event = GUI::get_current();
		EventType type = GUI::get_type(Event);

		if (type == EventType::KeyDown || type == EventType::KeyUp) {
			KeyCode cur = Unity::get_keyCode(Event);
			if (type == EventType::KeyDown)
			{
				if (!Pressed && cur == searchkey) {
					Pressed = true;
					Open = !Open;
				}
			}
			else
			{
				if (cur == searchkey) {
					Pressed = false;
				}
			}
		}

		return Open;
	}

	void InitializeAADrawing()
	{
		static bool LinesOk = false;
		// internal static Object FindObjectFromInstanceID(int instanceID) { }
		// public int GetInstanceID() { }
		auto FindObjectFromInstanceID = reinterpret_cast<uintptr_t(*)(int)>((DWORD64)(g_Base + offsets::o_FindObjectFromInstanceID));
		if (!FindObjectFromInstanceID(AALineTextureInstanceID)) {
			AALineTexture = Il2cpp::object_new(Il2cpp::InitClass(_("Texture2D"), _("UnityEngine"))); // if (!AALineTexture) return;

			// Create
			auto Create = reinterpret_cast<void(*)(uintptr_t, int, int, int, int, int, __int64)>((DWORD64)(g_Base + offsets::o_TextureCreate));
			Create(AALineTexture, 1, 3, 4, 4, 0, 0);

			auto FindObjectFromInstanceID = reinterpret_cast<int(*)(uintptr_t)>((DWORD64)(g_Base + offsets::o_GetInstanceID));
			AALineTextureInstanceID = FindObjectFromInstanceID(AALineTexture);
			// SetPixel
			auto SetPixel = reinterpret_cast<void(*)(uintptr_t, int, int, Color)>((DWORD64)(g_Base + offsets::o_TextureSetPixel));
			SetPixel(AALineTexture, 0, 0, { 255, 255, 255, 0 });
			SetPixel(AALineTexture, 0, 1, { 255, 255, 255, 255 });
			SetPixel(AALineTexture, 0, 2, { 255, 255, 255, 0 });
			// Apply
			auto Apply = reinterpret_cast<void(*)(uintptr_t, bool)>((DWORD64)(g_Base + offsets::o_TextureApply));
			Apply(AALineTexture, true);
		}

		if (!FindObjectFromInstanceID(LineTextureInstanceID)) {
			LineTexture = Il2cpp::object_new(Il2cpp::InitClass(_("Texture2D"), _("UnityEngine"))); // if (!AALineTexture) return;

			// Create
			auto Create = reinterpret_cast<void(*)(uintptr_t, int, int, int, int, int, __int64)>((DWORD64)(g_Base + offsets::o_TextureCreate));
			Create(LineTexture, 1, 1, 4, 4, 0, 0);

			auto FindObjectFromInstanceID = reinterpret_cast<int(*)(uintptr_t)>((DWORD64)(g_Base + offsets::o_GetInstanceID));
			LineTextureInstanceID = FindObjectFromInstanceID(LineTexture);
			// SetPixel
			auto SetPixel = reinterpret_cast<void(*)(uintptr_t, int, int, Color)>((DWORD64)(g_Base + offsets::o_TextureSetPixel));
			SetPixel(LineTexture, 0, 1, { 255, 255, 255, 255 });
			// Apply
			auto Apply = reinterpret_cast<void(*)(uintptr_t, bool)>((DWORD64)(g_Base + offsets::o_TextureApply));
			Apply(LineTexture, true);
		}
	}
	inline void DrawLine(Vector2 PointA, Vector2 PointB, Color clr, float Width, bool AntiAlias)
	{
		GUI::InitializeAADrawing();

		float DeltaX = PointB.x - PointA.x;
		float DeltaY = PointB.y - PointA.y;
		float Length = Maths::m_Sqrt(DeltaX * DeltaX + DeltaY * DeltaY);

		uintptr_t Texture = AntiAlias ? AALineTexture : g_WhiteTexture;
		if (AntiAlias) Width *= 3.f;

		float WidthDeltaX = Width * DeltaY / Length;
		float WidthDeltaY = Width * DeltaX / Length;

		Matrix4x4Line Matrix = Matrix4x4Line().Identity();
		Matrix.m00 = DeltaX;
		Matrix.m01 = -WidthDeltaX;
		Matrix.m03 = PointA.x + 0.5f * WidthDeltaX;
		Matrix.m10 = DeltaY;
		Matrix.m11 = WidthDeltaY;
		Matrix.m13 = PointA.y - 0.5f * WidthDeltaY;

		PushMatrix();
		MultMatrix(Matrix);
		GUI::set_color(clr.GetUnityColor());
		GUI::GuiMethods::DrawTexture(Rect(0, 0, 1, 1), Texture);
		PopMatrix();
	}

	

	//void DrawLine(Vector2 pointA, Vector2 pointB, Color color, float thickness, bool antiAlias = false)
	//{
	//	float dx = pointB.x - pointA.x;
	//	float dy = pointB.y - pointA.y;
	//	float len = Maths::m_Sqrt(dx * dx + dy * dy);

	//	if (len < 0.001f)
	//	{
	//		return;
	//	}

	//	/*Texture2D* texture2D = antiAlias ? aaLineTex : lineTex;
	//	Material* mat = antiAlias ? blendMaterial : blitMaterial;*/
	//	if (antiAlias)
	//		thickness *= 3.0f;

	//	float wdx = thickness * dy / len;
	//	float wdy = thickness * dx / len;

	//	Matrix4x4Line matrix;
	//	matrix = matrix.Identity();
	//	matrix.m00 = dx;
	//	matrix.m01 = -wdx;
	//	matrix.m03 = pointA.x + 0.5f * wdx;
	//	matrix.m10 = dy;
	//	matrix.m11 = wdy;
	//	matrix.m13 = pointA.y - 0.5f * wdy;

	//	PushMatrix();
	//	MultMatrix(matrix);

	//	GUI::set_color({1,1,1,1});
	//	GUI::GuiMethods::DrawTexture(Rect(0, 0, 1, 1), g_WhiteTexture);

	//	// RVA: 0x2546B20 Offset: 0x2545720 VA: 0x182546B20
	//	// public static void DrawTexture(Rect screenRect, Texture texture, Rect sourceRect, int leftBorder, int rightBorder, int topBorder, int bottomBorder, Material mat, int pass) { }
	//	// set_color({ 1,1,1,1 });
	//	// reinterpret_cast<void(*)(Rect, DWORD64, Rect, int, int, int, int, DWORD64, int)>((DWORD64)(g_Base + 0x2546B20))(Rect(0, 0, 1, 1), g_WhiteTexture, Rect(0, 0, 1, 1), 0, 0, 0, 0, blendMaterial, 0);
	//		//Graphics::DrawTexture(Rect(0, 0, 1, 1), texture2D, Rect(0, 0, 1, 1), 0, 0, 0, 0, color, mat);
	//	PopMatrix();
	//	/*PushMatrix();
	//	MultMatrix(matrix);
	//	Graphics::DrawTexture(Rect(0, 0, 1, 1), texture2D, Rect(0, 0, 1, 1), 0, 0, 0, 0, color, mat);
	//	PopMatrix();*/
	//}

	bool KeyBind(int key, bool& Pressed, bool& isAlready, int Type = 0)
	{
		if (Type == 0)
		{
			DWORD64 Event = GUI::get_current();
			EventType type = GUI::get_type(Event);

			if (type == EventType::KeyDown) {
				bool cur = Unity::GetKeyInt(key);
				if (cur)
				{
					if (!isAlready) {
						isAlready = true;
						Pressed = !Pressed;
					}
					else if (isAlready)
					{
						isAlready = false;
					}
				}
			}
			else if (type == EventType::KeyUp) {
				bool cur = Unity::GetKeyInt(key);
				if (cur)
				{
					if (!isAlready) {
						isAlready = true;
						Pressed = !Pressed;
					}
					else if (isAlready)
					{
						isAlready = false;
					}
				}
			}

			return Pressed;
		}
		if (Type == 1)
		{
			if (Unity::GetKeyInt(key))
			{
				return true;
			}
		}

		return false;
	}

	_FI void CornerBox(float Entity_x, float Entity_y, float Entity_w, float Entity_h, Color clr, float Wight) {
		// float thickness = 0.6;
		/*GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2(1, 1), clr, Vector2::Zero2(), 0, { Entity_x, Entity_y }, { Entity_x + Entity_w / 6.f ,Entity_y }, thickness);
		GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2(1, 1), clr, Vector2::Zero2(), 0, { Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / 6.f }, thickness);
		GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2(1, 1), clr, Vector2::Zero2(), 0, { Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / 6.f,Entity_y }, thickness);
		GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2(1, 1), clr, Vector2::Zero2(), 0, { Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / 6.f }, thickness);
		GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2(1, 1), clr, Vector2::Zero2(), 0, { Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / 6.f,Entity_y + Entity_h }, thickness);
		GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2(1, 1), clr, Vector2::Zero2(), 0, { Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / 6.f }, thickness);
		GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2(1, 1), clr, Vector2::Zero2(), 0, { Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / 6.f,Entity_y + Entity_h }, thickness);
		GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2(1,1), clr, Vector2::Zero2(), 0, { Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / 6.f }, thickness);*/

		GUI::DrawLine({ Entity_x, Entity_y }, { Entity_x + Entity_w / 6.f ,Entity_y }, clr, Wight, false);
		GUI::DrawLine({ Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / 6.f }, clr, Wight, false);
		GUI::DrawLine({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / 6.f,Entity_y }, clr, Wight, false);
		GUI::DrawLine({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / 6.f }, clr, Wight, false);

		GUI::DrawLine({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / 6.f,Entity_y + Entity_h }, clr, Wight, false);
		GUI::DrawLine({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / 6.f }, clr, Wight, false);
		GUI::DrawLine({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / 6.f,Entity_y + Entity_h }, clr, Wight, false);
		GUI::DrawLine({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / 6.f }, clr, Wight, false);

		return;
	}

	float newnew = 0;

	inline bool Items_ArrayGetter(void* data, int idx, const wchar_t** out_text)
	{
		const wchar_t* const* items = (const wchar_t* const*)data;
		if (out_text)
			*out_text = items[idx];
		return true;
	}

	float ComboAlpha = 0;
	float CurrentComboAlpha = 0;
	float GetAlpha(float curAlpha, float maxAlpha)
	{
		return min(maxAlpha - 40 + curAlpha, maxAlpha);
	}

	bool combo_(Str name, int* current_item, bool (*items_getter)(void*, int, const wchar_t**), void* data, int items_count) {
		const wchar_t* preview_value = NULL;
		next_item_pos.y -= 7;
		if (*current_item >= 0 && *current_item < items_count) Items_ArrayGetter(data, *current_item, &preview_value);
		auto size = Vector2(239, 20);
		if (MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x + 20,size.y }) && mouse_state && !old_mouse_state) {
			list_clicked2 = !list_clicked2;
			if (list_open2 != current_item)
				list_open2 = current_item;
		}
		const wchar_t* item_text = _(L"");

		GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 23, 23, 23, 255 });
		/*DrawFadeRect(next_item_pos.x, next_item_pos.y + size.y - 5, size.x / 2, 5, { 255,255,255, 0 }, { 255,255,255, 120 }, true);
		DrawFadeRect(next_item_pos.x + size.x / 2, next_item_pos.y + size.y - 5, size.x / 2, 5, { 255,255,255, 120 }, { 255,255,255, 0 }, true);*/
		GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 255,255,255, 60 });
		String({ next_item_pos.x + 5, next_item_pos.y + 1 , 200, 20 }, preview_value, Color(255, 255, 255, 255), false, 8);

		bool value_changed = false;
		if (list_clicked2 && list_open2 == current_item) {

			for (int i = 0; i < items_count; i++) {
				// ComboAlpha++;
				const bool item_selected = (i == *current_item);
				if (!Items_ArrayGetter(data, i, &item_text)) item_text = _(L"???");
				next_item_pos.y += 20;
				if (MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x + 20,size.y }) && mouse_state && !old_mouse_state) {
					value_changed = true;
					*current_item = i;
				}
				GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 23, 23, 23, 255 });
				//DrawFadeRect(next_item_pos.x, next_item_pos.y + size.y - 5, size.x / 2, 5, { 255,255,255, 0 }, { 255,255,255, 120 }, true);
				//DrawFadeRect(next_item_pos.x + size.x / 2, next_item_pos.y + size.y - 5, size.x / 2, 5, { 255,255,255, 120 }, { 255,255,255, 0 }, true);
				GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 255,255,255, 60 });
				String({ next_item_pos.x + 5, next_item_pos.y, 200, 20 }, item_text, Color(102, 102, 100, 200), false, 8);

				if (*current_item == i)
					String({ next_item_pos.x + 5, next_item_pos.y + 1 , 200, 20 }, item_text, Color(255, 255, 255, 255), false, 8);
				if (MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x,size.y }) && !(*current_item == i))
				{
					String({ next_item_pos.x + 5, next_item_pos.y + 1 , 200, 20 }, item_text, Color(255, 255, 255, 120));
					GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 255,255,255, 60 });
				}
			}
		}
		else {
			ComboAlpha = 0;
		}


		next_item_pos.y += 30;
		return value_changed;
	}

	bool Combo(const wchar_t* name, int* current_item, const wchar_t* const items[], int items_count)
	{
		String({ next_item_pos.x, next_item_pos.y - 5 , 200, 20 }, name, Color(255, 255, 255, 255));
		next_item_pos.y += 5;
		const bool value_changed = combo_(name, current_item, Items_ArrayGetter, (void*)items, items_count);
		return value_changed;
	}

	void Hotkey(int* key, int* Type, bool& value, bool* GetKeyBind)
	{
		Rect TextPos = Rect(next_item_pos.x, next_item_pos.y, 200, 150);
		//FillBoxRounded({ next_item_pos.x + 130 , next_item_pos.y - 2, 80, 14 }, { 65, 65, 65, 255 }, ScaleMode::ScaleAndCrop, 0);
		Rect textPos = Rect{ next_item_pos.x + 85, next_item_pos.y - 5, 200,150 };
		String(textPos, _(L"Hotkey:"), Color(255, 255, 255, 255), false, 8);
		if (MouseInZone(Vector2{ next_item_pos.x + 130, next_item_pos.y - 5 }, { 80, 14 }) && mouse_state && !old_mouse_state)
		{
			*GetKeyBind = !*GetKeyBind;
		}
		if (*GetKeyBind)
		{
			Rect textPos = Rect{ next_item_pos.x + 130, next_item_pos.y - 5, 200,150 };
			//FillBoxRounded({ next_item_pos.x + 226 , next_item_pos.y - 4, 14, 14 }, { 255, 255, 255, 255 }, ScaleMode::ScaleAndCrop, 0);
			String(textPos, _(L""), Color(255, 255, 255, 255), false, 8);

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
			Rect textPos = Rect{ next_item_pos.x + 130, next_item_pos.y - 5, 200,150 };
			String(textPos, get_keystr(*key), Color{ 255, 255, 255, 255 });
		}

		if (is_mouse_in_box({ next_item_pos.x + 226, next_item_pos.y - 2 }, { next_item_pos.x + 226 + 14, next_item_pos.y - 2 + 14 }) && mouse_state && !old_mouse_state) // && !inColorPicker
			value = !value;

		FillBoxRounded({ next_item_pos.x + 226 , next_item_pos.y - 2, 14, 14 }, { 255, 255, 255, 255 }, ScaleMode::ScaleAndCrop, 0); // 160,20,100,200
		String({ next_item_pos.x + 228.5f, next_item_pos.y - 5.f, 300, 40 }, value ? _(L"T") : _(L"H"), Color(255, 255, 255, 255), false, Vars::GUITextSize);

		if (!value)	*Type = 1; else if (value) *Type = 0;

	}

	//int* list_open = 0;
	//bool list_clicked = false;
	/*void ComboBox(const wchar_t* name,std::array<wchar_t*, 10 > combo_str, int* selected, int szsz = 0)
	{
		String({ next_item_pos.x + 5, next_item_pos.y , 200, 20 }, name, Color(255, 255, 255, 255));
		next_item_pos.y += 20;
		auto sz = sizeof(combo_str) / sizeof(combo_str[0]) - szsz;
		auto size = Vector2(100, 20);
		if (MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x,size.y }) && mouse_state && !old_mouse_state) {
			list_clicked = !list_clicked;
			if (list_open != selected)
				list_open = selected;
		}

		Color color = Color(12, 12, 18, 255);
			GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { color });
			GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 255,255,255, 60 });
		String({ next_item_pos.x + 5, next_item_pos.y , 200, 20 }, combo_str[*selected], Color(255, 255, 255, 255));
		if (list_clicked && list_open == selected) {
			for (size_t i = 1; i < sz; i++) {
				next_item_pos.y += 20;
				if (MouseInZone({ next_item_pos.x, next_item_pos.y }, { size.x,size.y }) && mouse_state && !old_mouse_state) if (combo_str[i]) *selected = i;
				GUI::StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { color });
				GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x, next_item_pos.y }, { size.x, size.y }, { 255,255,255, 60 });
				wchar_t* name = combo_str[i];
				String({ next_item_pos.x + 5, next_item_pos.y , 200, 20 }, name, Color(128, 128, 128, 128));
				if (*selected == i) String({ next_item_pos.x + 5, next_item_pos.y , 200, 20 }, name, Color(255, 255, 255, 255));
			}
		}
		next_item_pos.y += 30;
	}*/

	bool Window(wchar_t* title, const Vector2& pos, const Vector2& window_size, bool always_open)
	{

		if (open)
		{

			if (!sex) {
				window_pos = pos;
				sex = true;
			}
			mouse_state = Unity::GetMouseButton(0);
			mouse_pos.x = GUI::GuiMethods::get_mousePosition().x;
			mouse_pos.y = Vars::ScreenHeight - GUI::GuiMethods::get_mousePosition().y;

			if (is_mouse_in_box({ window_pos.x, window_pos.y }, { window_pos.x + window_size.x, window_pos.y + 20 }) && mouse_state && main_menu_open) {
				window_pos.x += mouse_pos.x - old_mouse_pos.x;
				window_pos.y += mouse_pos.y - old_mouse_pos.y;
			}
			if (open)
			{



				FillBoxRounded({ window_pos.x, window_pos.y, window_size.x, window_size.y }, { 17,17,17, 255 }, ScaleMode::StretchToFill, 0);
				//FillBoxRounded({ window_pos.x, window_pos.y, 100.f, window_size.y }, { 12,12,18, 255 }, ScaleMode::StretchToFill, 0);
				// FillCornerBoxRounded({ window_pos.x, window_pos.y, window_size.x, window_size.y }, { 0, 252, 242, 120 }, 0);
				String({ window_pos.x + 10, window_pos.y + 18, window_size.x, window_size.y }, title, Color(255, 60, 60, 255), false, 11);

				/*FillBoxRounded({ window_pos.x + window_size.x + 10, window_pos.y, window_size.x / 2, window_size.y }, { 16,16,20, 255 }, StretchToFill);
				FillCornerBoxRounded({ window_pos.x + window_size.x + 10, window_pos.y, window_size.x / 2, window_size.y }, { 255,255,255, 60 });

				FillBoxRounded({ window_pos.x + window_size.x + 30, window_pos.y + 20, window_size.x / 2 - 40, window_size.y - 40 }, { 12,12,18, 255 }, StretchToFill);
				FillCornerBoxRounded({ window_pos.x + window_size.x + 30, window_pos.y + 20, window_size.x / 2 - 40, window_size.y - 40 }, { 255,255,255, 60 });

				GUI::DrawPng({ window_pos.x + window_size.x + 90, window_pos.y + 80, 200, window_size.y / 2 + 80 });

				if (Vars::Visuals::PlayerEsp::BoxEsp == 2)
					StartGlRender(render_type::boxoutline, { window_pos.x + window_size.x + 90, window_pos.y + 80 }, { 200, window_size.y / 2 + 80 }, Color(0, 255, 0, 255));
				if (Vars::Visuals::PlayerEsp::BoxEsp == 3)
					CornerBox(window_pos.x + window_size.x + 90, window_pos.y + 80, 200, window_size.y / 2 + 80, { 0,255,0,255 });

				float CalcX = window_pos.x + window_size.x + 90;
				float CalcW = 200;
				float CalcY = window_pos.y + 80;
				float CalcH = window_size.y / 2 + 80;
				if (Vars::Visuals::PlayerEsp::HealthEsp == 2)
				{
					GUI::StartGlRender(render_type::box, { CalcX + CalcW + 10.f, CalcY }, { 5.2, CalcH }, { 0, 0, 0, 170 });
					GUI::StartGlRender(render_type::box, { CalcX + CalcW + 8.f, CalcY }, { 5, CalcH }, { 0,255, 0,255 });
				}
				if (Vars::Visuals::PlayerEsp::HealthEsp == 3)
				{
					GUI::StartGlRender(render_type::box, { CalcX - 14, CalcY - 15}, { CalcW + 26.4f, 4 }, { 0, 0, 0, 170 });
					GUI::StartGlRender(render_type::box, { CalcX - 14, CalcY - 15 }, { CalcW + 26, 4 }, { 0,255, 0,255 });
				}

				if (Vars::Visuals::PlayerEsp::NameEsp)
					GUI::String({ CalcX + 20, CalcY - 40, 150, 20 }, _(L"KO"), {3, 221, 255, 255}, true, 16);*/

			}
			return true;
		}
	}


	void TabChild(const wchar_t* title, const Vector2& pos, const Vector2& size)
	{
		FillBoxRounded({ window_pos.x + pos.x, window_pos.y + pos.y, size.x, size.y }, { 21,21,21, 255 }, ScaleMode::StretchToFill, 0);
		FillCornerBoxRounded({ window_pos.x + pos.x, window_pos.y + pos.y , size.x, size.y }, { 33,33,33, 255 }, 0);
		String({ window_pos.x + pos.x + 6.f, window_pos.y + pos.y - 20.f, 400, 40 }, title, { 255, 255, 255, 255 }, false, 11);
		next_item_pos = { window_pos.x + pos.x + 15, window_pos.y + pos.y + 17 };
	}

	void ColorCheckBox(Vector2& pos, bool& isRGBA)
	{

	}

	bool PenisCol2 = false;

	void DoColorPicker(Color& outColor, bool& Value, bool isSecond, float Take = 0)
	{
		float DistFromStart = isSecond ? 180 : 160;
		Vector2 pos = { next_item_pos.x + DistFromStart, next_item_pos.y };
		if (is_mouse_in_box({ pos.x + 46, pos.y - 2 }, { pos.x + 46 + 14, pos.y - 2 + 14 }) && mouse_state && !old_mouse_state) {
			Value = !Value;
		}

		GUI::FillBoxRounded({ pos.x + 46, pos.y - 2,14, 14 }, Color(60, 60, 60, 255), ScaleMode::StretchToFill, 2);
		GUI::FillBoxRounded({ pos.x + 48, pos.y,10, 10 }, outColor, ScaleMode::StretchToFill, 2);

		
		if (Value)
		{
			// GUI::FillCornerBoxRounded({ pos.x - 2, pos.y - 2,16, 16 }, outColor, 2);
			pos = { next_item_pos.x + DistFromStart + 40, next_item_pos.y };
			GUI::FillBoxRounded({ pos.x + 20 + (!isSecond ? 165 : 40), pos.y - 5 , 100, 100 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill, 0);

			//DrawColorPickerColor(pos.x + 25.f, pos.y);
			DrawColorPickerColor(pos.x + 25.f + (!isSecond ? 165 : 40), pos.y);
			if (MouseInZone({ pos.x + 25.f + (!isSecond ? 165 : 40), pos.y }, { 90, 90 }) && mouse_state)
			{
				Color endColor = GetColorFromPenPosition(mouse_pos - Vector2{ pos.x + 25.f + (!isSecond ? 165 : 40), pos.y });
				outColor = endColor;
			}
		}
	}

	void ColorPicker(Vector2 pos, bool& value, Color& color, bool& PenisCol, float dist = 180)
	{
		Vector2 mousepos = Vector2{ next_item_pos.x + dist, next_item_pos.y };
		if (is_mouse_in_box({ mousepos.x, mousepos.y }, { mousepos.x + 14, mousepos.y + 14 }) && mouse_state && !old_mouse_state)
			value = !value;

		GUI::FillBoxRounded({ mousepos.x - 2, mousepos.y - 2,16, 16 }, Color(60, 60, 60, 170), ScaleMode::StretchToFill, 2);
		GUI::FillBoxRounded({ mousepos.x, mousepos.y,12, 12 }, color, ScaleMode::StretchToFill, 2);
		if (value)
		{
			GUI::FillCornerBoxRounded({ mousepos.x - 2, mousepos.y - 2,16, 16 }, color, 2);
			GUI::FillBoxRounded({ pos.x + 20, pos.y - 5 , 180, 160 }, Color(21, 21, 21, 255), ScaleMode::StretchToFill);
			GUI::FillBoxRounded({ pos.x + 25, pos.y + 25, 150, 125 }, Color(0, 0, 0, 255), ScaleMode::StretchToFill);
			GUI::FillBoxRounded({ pos.x + 180, pos.y , 15, 150 }, Color(0, 0, 0, 255), ScaleMode::StretchToFill);

			/*if (MouseInZone({ pos.x + 30, pos.y + 5 }, { 31, 15 }) && mouse_state && !old_mouse_state)
				PenisCol = !PenisCol;

			FillBoxRounded({ pos.x + 35 , pos.y + 8, 26, 10 }, { 160,20,100,200 }, ScaleMode::ScaleAndCrop, 20);
			FillBoxRounded(Rect(!PenisCol ? pos.x + 35 - 2 : pos.x + 35 + 12, pos.y + 5, 16, 16), !PenisCol ? Color(180, 40, 120, 255) : Color(0, 252, 242, 255), ScaleMode::ScaleAndCrop, 20);
			String({ pos.x + 75, pos.y + 1, 150, 20 }, _(L"RGB Mode"), { 255,0,0,255 }, false, 8);*/

			float r = 0;
			float g = 0;
			float b = 0;
			float a = 255;

			for (int i = 0; i < 1530; i++)
			{
				if (i <= 255)
				{
					r = 255;
					g = i;
					b = 0;
				}
				if (i > 255 && i <= 510)
				{
					r = 255 - (i - 255);
					g = 255;
					b = 0;
				}
				if (i > 510 && i <= 765)
				{
					r = 0;
					g = 255;
					b = (i - 510);
				}
				if (i > 765 && i <= 1020)
				{
					r = 0;
					g = 255 - (i - 765);
					b = 255;
				}
				if (i > 1020 && i <= 1275)
				{
					r = (i - 1020);
					g = 0;
					b = 255;
				}
				if (i > 1275 && i <= 1530)
				{
					r = 255;
					g = 0;
					b = 255 - (i - 1275);
				}

				GUI::FillBoxRounded({ pos.x + 180, pos.y + (i / 10.23f) , 15, 0.5f }, { r, g, b, 255 }, ScaleMode::StretchToFill, 30);
			}

			if (is_mouse_in_box({ pos.x + 180, pos.y + 2 }, { pos.x + 195, pos.y + 155 }) && mouse_state)
			{
				float i = old_mouse_pos.y - pos.y;
				i *= 10.25;

				if (i <= 255)
				{
					r = 255;
					g = i;
					b = 0;
				}
				if (i > 255 && i <= 510)
				{
					r = 255 - (i - 255);
					g = 255;
					b = 0;
				}
				if (i > 510 && i <= 765)
				{
					r = 0;
					g = 255;
					b = (i - 510);
				}
				if (i > 765 && i <= 1020)
				{
					r = 0;
					g = 255 - (i - 765);
					b = 255;
				}
				if (i > 1020 && i <= 1275)
				{
					r = (i - 1020);
					g = 0;
					b = 255;
				}
				if (i > 1275 && i <= 1530)
				{
					r = 255;
					g = 0;
					b = 255 - (i - 1275);
				}
				color = { r, g, b, a };
			}

			//for (int i = 0; i < 600; i++)
			//{
			//	float blm = i * 0.25;
			//	float Red = 255 - color.r;
			//	float Green = 255 - color.r;
			//	float Blue = 255 - color.r;

			//	// Color gradientColor = GUI::SmoothGradient();
			//	
			//	Color gradientColor = GUI::SmoothGradient(Color( 250, 250, 250,255 ), color, i, 600);

			//	GUI::FillBoxRounded({ ((pos.x + 25) + blm), pos.y + 25 , 0.59, 125 }, gradientColor, ScaleMode::StretchToFill, 0);
			//}

			//if (is_mouse_in_box({ pos.x + 25, pos.y + 25 }, { pos.x + 175, pos.y + 125 }) && mouse_state)
			//{
			//	float i = old_mouse_pos.x - (pos.x + 25);

			//	i = i / 0.59;

			//	Color gradientColor = GUI::SmoothGradient({255,255,255,255}, color, i, 150);

			//	color = gradientColor; //{ color.r, color.g, color.b, i };

			//}

		}

	}

	void ColorPicker2(Vector2 pos, bool& value, float color[3], float dist = 180)
	{
		Vector2 mousepos = Vector2{ next_item_pos.x + dist, next_item_pos.y };
		if (is_mouse_in_box({ mousepos.x, mousepos.y }, { mousepos.x + 14, mousepos.y + 14 }) && mouse_state && !old_mouse_state)
			value = !value;

		GUI::FillBoxRounded({ mousepos.x - 10, mousepos.y - 2,16, 16 }, Color(60, 60, 60, 170), ScaleMode::StretchToFill, 2);
		GUI::FillBoxRounded({ mousepos.x - 10, mousepos.y,12, 12 }, { color[0],color[1],color[2],color[3] }, ScaleMode::StretchToFill, 2);
	}

	inline void CheckBox(const wchar_t* title, bool& value, float dist = 0, float textdist = 0) {
		if (is_mouse_in_box({ next_item_pos.x + 0, next_item_pos.y - 2 }, { next_item_pos.x + 14, next_item_pos.y + 14 }) && mouse_state && !old_mouse_state) // && !inColorPicker
			value = !value;


		String({ next_item_pos.x + 18, next_item_pos.y - 5.f, 300, 40 }, title, Color(255, 255, 255, 255), false, Vars::GUITextSize);
		//GUI::StartGlRender(render_type::boxoutline, { next_item_pos.x + 225 - dist , next_item_pos.y - 1}, { 12, 12 }, Color(255, 255, 255, 255));
		FillCornerBoxRounded({ next_item_pos.x + 0, next_item_pos.y - 2, 14, 14 }, Color(255, 255, 255, 200), 0);
		FillBoxRounded({ next_item_pos.x + 2, next_item_pos.y, 10, 10 }, !value ? Color(17, 17, 17, 255) : Color(255, 255, 255, 255), ScaleMode::ScaleAndCrop, 1); // 160,20,100,200
		//FillBoxRounded(Rect(!value ? next_item_pos.x + 208 - dist : next_item_pos.x + 222 - dist, next_item_pos.y - 2, 16, 16), !value ? Color(0, 182, 172, 255) : Color(0, 252, 242, 255), ScaleMode::ScaleAndCrop, 20);
		// 180, 40, 120, 255
		next_item_pos.y += 22;
	}


	void Slider(const wchar_t* title, float& value, float min, float max, wchar_t* type = _(L"%s: %0.2f "))
	{
		if (GUI::open)
		{
			if (is_mouse_in_box({ next_item_pos.x - 5, next_item_pos.y }, { next_item_pos.x + 240, next_item_pos.y + 25 }) && mouse_state && !inColorPicker) {

				float m_flFilled = ((old_mouse_pos.x - next_item_pos.x) / 240.f);
				value = (max - min) * m_flFilled;

				if (value > max) value = max; if (value < min) value = min;
			}

			wchar_t Active[128];
			f_swprint(Active, type, title, value);

			String({ next_item_pos.x, next_item_pos.y - 5, 300, 20 }, Active, { 255, 255, 255, 225 },false, Vars::GUITextSize);
			StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y + 16 }, { 240, 6 }, { 65, 65, 65, 255 });
			StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y + 16 }, { ((float)(value * 240) / max), 6 }, Color(255, 255, 255, 255)); // 255, 80, 180, 255
			//FillBoxRounded({ next_item_pos.x , next_item_pos.y + 11, ((float)(value * 140) / max) * 2, 16 }, Color(255, 60, 60, 255), ScaleMode::ScaleToFit, 50); // 255, 80, 180, 255
			next_item_pos.y += 28;
		}
	}

	void IntSlider(const wchar_t* title, int& value, int min, int max, wchar_t* type = _(L"%s: %d "))
	{
		if (GUI::open)
		{
			if (is_mouse_in_box({ next_item_pos.x - 5, next_item_pos.y }, { next_item_pos.x + 240, next_item_pos.y + 25 }) && mouse_state && !inColorPicker) {

				value = float((old_mouse_pos.x - (next_item_pos.x)) * (max - min) / 240);

				if (value > max)
					value = max;
				if (value < min)
					value = min;
			}

			wchar_t Active[128];
			f_swprint(Active, type, title, value);
			String({ next_item_pos.x, next_item_pos.y - 5, 300, 20 }, Active, { 255, 255, 255, 225 },false, Vars::GUITextSize);
			StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y + 16 }, { 240, 6 }, { 65, 65, 65, 255 });
			StartGlRender(render_type::box, { next_item_pos.x, next_item_pos.y + 16 }, { ((float)(value * 240) / max), 6 }, Color(255, 255, 255, 255)); // 255, 80, 180, 255
			//FillBoxRounded({ next_item_pos.x , next_item_pos.y + 11, ((float)(value * 140) / max) * 2, 16 }, Color(255, 60, 60, 255), ScaleMode::ScaleToFit, 50); // 255, 80, 180, 255
			next_item_pos.y += 28;
		}
	}

	int table = 0;
	void Tab(const wchar_t* name, int id, Vector2 tab_size = Vector2(148.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y }, { window_pos.x + (id * tab_size.x) + 148.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y}) && mouse_state)
				Vars::ActiveTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y }, tab_size, id == Vars::ActiveTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 16.f, window_pos.y + (tab_size.y) - 22, 300, 40 }, (name), id == Vars::ActiveTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void Tab1(const wchar_t* name, int id, Vector2 tab_size = Vector2(148.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y }, { window_pos.x + (id * tab_size.x) + 148.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y }) && mouse_state)
				Vars::ActiveTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y }, tab_size, id == Vars::ActiveTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 18.f, window_pos.y + (tab_size.y) - 22, 300, 40 }, (name), id == Vars::ActiveTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void Tab2(const wchar_t* name, int id, Vector2 tab_size = Vector2(148.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y }, { window_pos.x + (id * tab_size.x) + 148.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y }) && mouse_state)
				Vars::ActiveTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y }, tab_size, id == Vars::ActiveTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 15.5f, window_pos.y + (tab_size.y) - 22, 300, 40 }, (name), id == Vars::ActiveTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void Tab3(const wchar_t* name, int id, Vector2 tab_size = Vector2(148.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y }, { window_pos.x + (id * tab_size.x) + 148.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y }) && mouse_state)
				Vars::ActiveTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y }, tab_size, id == Vars::ActiveTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 24.f, window_pos.y + (tab_size.y) - 22, 300, 40 }, (name), id == Vars::ActiveTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void subTab(const wchar_t* name, int id, Vector2 tab_size = Vector2(148.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y + 25}, { window_pos.x + (id * tab_size.x) + 148.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y + 26 }) && mouse_state)
				Vars::ActuveSubTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y + 25 }, tab_size, id == Vars::ActuveSubTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y + 25 }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 22.f, window_pos.y + 23 + (tab_size.y) - 20, 300, 40 }, (name), id == Vars::ActuveSubTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void DoubleSubTab1(const wchar_t* name, int id, Vector2 tab_size = Vector2(156.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y + 25 }, { window_pos.x + (id * tab_size.x) + 156.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y + 26 }) && mouse_state)
				Vars::ActuveSubTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y + 25 }, tab_size, id == Vars::ActuveSubTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y + 25 }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 52.5f, window_pos.y + 26 + (tab_size.y) - 23, 300, 40 }, (name), id == Vars::ActuveSubTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void DoubleSubTab2(const wchar_t* name, int id, Vector2 tab_size = Vector2(156.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y + 25 }, { window_pos.x + (id * tab_size.x) + 156.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y + 26 }) && mouse_state)
				Vars::ActuveSubTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y + 25 }, tab_size, id == Vars::ActuveSubTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y + 25 }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 49.f, window_pos.y + 26 + (tab_size.y) - 23, 300, 40 }, (name), id == Vars::ActuveSubTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void DoubleSubTab3(const wchar_t* name, int id, Vector2 tab_size = Vector2(156.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y + 25 }, { window_pos.x + (id * tab_size.x) + 156.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y + 26 }) && mouse_state)
				Vars::ActuveSubTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y + 25 }, tab_size, id == Vars::ActuveSubTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y + 25 }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 54.f, window_pos.y + 26 + (tab_size.y) - 23, 300, 40 }, (name), id == Vars::ActuveSubTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void DoubleSubTab4(const wchar_t* name, int id, Vector2 tab_size = Vector2(156.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y + 25 }, { window_pos.x + (id * tab_size.x) + 156.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y + 26 }) && mouse_state)
				Vars::ActuveSubTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y + 25 }, tab_size, id == Vars::ActuveSubTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y + 25 }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 56.f, window_pos.y + 26 + (tab_size.y) - 23, 300, 40 }, (name), id == Vars::ActuveSubTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void DoubleSubTab5(const wchar_t* name, int id, Vector2 tab_size = Vector2(156.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y + 25 }, { window_pos.x + (id * tab_size.x) + 156.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y + 26 }) && mouse_state)
				Vars::ActuveSubTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y + 25 }, tab_size, id == Vars::ActuveSubTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y + 25 }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 54.f, window_pos.y + 26 + (tab_size.y) - 23, 300, 40 }, (name), id == Vars::ActuveSubTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void DoubleSubTab6(const wchar_t* name, int id, Vector2 tab_size = Vector2(156.f, 25.f)) {
		if (open)
		{
			if (is_mouse_in_box({ window_pos.x + (id * tab_size.x), window_pos.y + 25 }, { window_pos.x + (id * tab_size.x) + 156.f /*+ tab_size.x + 30*/, window_pos.y + tab_size.y + 26 }) && mouse_state)
				Vars::ActuveSubTab = id;

			StartGlRender(render_type::box, { window_pos.x + (id * tab_size.x), window_pos.y + 25 }, tab_size, id == Vars::ActuveSubTab ? Color{ 25,25,25, 255 } : Color{ 17,17,17, 255 });
			FillCornerBoxRounded({ window_pos.x + (id * tab_size.x), window_pos.y,  tab_size.x, tab_size.y + 25 }, { 33, 33, 33, 255 }, 0);
			//if (id == Vars::ActiveTab)
				//Gradient(Rect(window_pos.x + 1, window_pos.y + (id * 50.f) + 68.5f + 30, 99.f, 1.5f), true);

			String({ window_pos.x + (id * tab_size.x) + 49.f, window_pos.y + 26 + (tab_size.y) - 23, 300, 40 }, (name), id == Vars::ActuveSubTab ? Color{ 255, 255, 255, 255 } : Color{ 105, 105,105, 255 }, false, 10);
		}
	}
	void end_window() {
		old_insert_state = insert_state;
		old_mouse_pos = mouse_pos;
		old_mouse_state = mouse_state;
	}



}
