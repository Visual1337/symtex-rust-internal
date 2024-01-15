#pragma once
#define _FI inline

uintptr_t* friends[100];
uintptr_t* enemies[100];
BasePlayer* EspObjects[512];



struct CLStash {
	UINT64 Entity;
	Vector3 Pos = Vector3::Zero();
	float Dist = 0;
} inline ClosestStash;

struct CLTurret {
	UINT64 Entity;
	Vector3 Pos = Vector3::Zero();
	float Dist = 0;
} inline ClosestTurret;

struct CLRecycler {
	UINT64 Entity;
	Vector3 Pos = Vector3::Zero();
	float Dist = 0;
} inline ClosestRecycler;

struct CLDoor {
	UINT64 Entity;
	Vector3 Pos = Vector3::Zero();
	float Dist = 0;
} inline ClosestDoor;

void arc(float x, float y, float radius, float min_angle, float max_angle, Color col, float thickness) {

}

Vector2 RotateVertex(const Vector2& p, const Vector2& v, float angle) {
	// convert theta angle to sine and cosine representations.
	float c = Maths::m_Cos(DEG2RAD(angle));
	float s = Maths::m_Sin(DEG2RAD(angle));

	return {
		p.x + (v.x - p.x) * c - (v.y - p.y) * s,
		p.y + (v.x - p.x) * s + (v.y - p.y) * c
	};
}

_FI void InvisiblePlayerIndicator(Vector3 position)
{
	if (Vars::Visuals::PlayerEsp::OOFindicators)
	{

		Vector3 local = LocalPlayer->get_transform()->Position();
		Quaternion localRotation = LocalPlayer->GetEyes()->Rotation();
		float num = Maths::m_Atan2(local.x - position.x, local.z - position.z) * 57.29578f - 180.f - Maths::EulerAngles(localRotation).y;

		if (!(num < (-420) || num >(-300))) return;

		Vector2 tp1337 = Maths::CosTanSinLineH(num, 1, Vars::ScreenWidth / 2, Vars::ScreenHeight / 2, Vars::Visuals::PlayerEsp::OOFDist);

		Vector2 verts[3], verts_outline[3];
		Vector2 offscreen_pos = tp1337;
		// setup vertices for the triangle.
		verts[0] = { offscreen_pos.x, offscreen_pos.y };        // 0,  0
		verts[1] = { offscreen_pos.x - 7.f, offscreen_pos.y + 14.f }; // -1, 1
		verts[2] = { offscreen_pos.x + 7.f, offscreen_pos.y + 14.f }; // 1,  1

		// setup verts for the triangle's outline.
		verts_outline[0] = { verts[0].x - 1.f, verts[0].y - 1.f };
		verts_outline[1] = { verts[1].x - 1.f, verts[1].y + 1.f };
		verts_outline[2] = { verts[2].x + 1.f, verts[2].y + 1.f };

		// rotate all vertices to point towards our target.
		verts[0] = RotateVertex(offscreen_pos, verts[0], num);
		verts[1] = RotateVertex(offscreen_pos, verts[1], num);
		verts[2] = RotateVertex(offscreen_pos, verts[2], num);
		verts_outline[0] = RotateVertex(offscreen_pos, verts_outline[0], num);
		verts_outline[1] = RotateVertex(offscreen_pos, verts_outline[1], num);
		verts_outline[2] = RotateVertex(offscreen_pos, verts_outline[2], num);

		Color clr = Unity::CheckLOS(EyePos, position) ? Color(ColorPicker::OOFVisible.r, ColorPicker::OOFVisible.g, ColorPicker::OOFVisible.b, ColorPicker::OOFPingPong) : Color(ColorPicker::OOFInVisible.r, ColorPicker::OOFInVisible.g, ColorPicker::OOFInVisible.b, ColorPicker::OOFPingPong); //ColorPicker::OOFInVisible;
		GUI::StartGlRender(render_type::triangle, verts[0], verts[1], clr, verts[2], 0, Vector2(Vars::ScreenWidth / 2, Vars::ScreenHeight), Vector2::Zero2(), 0);
		// GUI::DrawLine({ (float)Vars::ScreenWidth / 2, (float)Vars::ScreenHeight / 2 }, verts[0], Color(255, 255, 255, 255), 1.2, false);

	}
}

//void DrawRaid()
//{
//	auto effect_network = Il2cpp::InitClass(_("EffectNetwork"));
//	if (!effect_network)WdFilter.sys
//		return;
//	//pViewMatrix = unity::get_view_matrix();
//
//	auto effect = *reinterpret_cast<uintptr_t*>(effect_network + 0xB8);
//	if (!effect)
//	{
//		return;
//	}
//
//	effect = *reinterpret_cast<uintptr_t*>(effect);
//	if (!effect)
//	{
//		return;
//	}
//	/*if (get_fixedTime() >= settings::raidupdatetime + settings::raidupdatedelay) {
//		return;
//	}*/
//	auto position = Read<Vector3>(effect + 0x50);
//	if (position == Vector3(0, 0, 0)) return;
//	//Vector3 Pos = transf->Position(); 
//
//	//auto pooled_str = (pUncStr)(Read<DWORD64>(effect + 0x88));
//	//auto pooledString = pooled_str->str;
//
//	//if (m_strstr(pooledString ,_("assets/prefabs/tools/c4/effects/c4_explosion.prefab"))) {
//		Classes::DDrawSphereGizmo(position, 0.5, Color(255, 0, 0, 255), 10, false, false);
//	//}
//}

#define ponos 0.3333333333f
inline void DrawRadar()
{
	static bool sodoaso = false;
	if (!sodoaso)
	{
		Vars::Radar::Pos = { 50,50 };
		Vars::Radar::Size = { 200,200 }; sodoaso = true;
	}

	Vars::Radar::mouse_pos.x = GUI::GuiMethods::get_mousePosition().x;
	Vars::Radar::mouse_pos.y = Vars::ScreenHeight - GUI::GuiMethods::get_mousePosition().y;

	if (Vars::Radar::MouseInBox({ Vars::Radar::Pos.x, Vars::Radar::Pos.y }, { Vars::Radar::Pos.x + Vars::Radar::Size.x, Vars::Radar::Pos.y + Vars::Radar::Size.y }) && mouse_state && main_menu_open) {
		Vars::Radar::Pos.x += Vars::Radar::mouse_pos.x - Vars::Radar::old_mouse_pos.x;
		Vars::Radar::Pos.y += Vars::Radar::mouse_pos.y - Vars::Radar::old_mouse_pos.y;
	}
	float MegaPonosX = Vars::Radar::Size.x * ponos;
	float MegaPonosY = Vars::Radar::Size.y * ponos;

	GUI::FillBoxRounded({ Vars::Radar::Pos.x,Vars::Radar::Pos.y,Vars::Radar::Size.x,Vars::Radar::Size.y }, { 21,21,21,170 }, ScaleMode::StretchToFill, 360);
	GUI::FillCornerBoxRounded({ Vars::Radar::Pos.x + 66.f,Vars::Radar::Pos.y + 66.f,Vars::Radar::Size.x * ponos ,Vars::Radar::Size.y * ponos }, { 170,170,170,120 }, 360);
	GUI::FillCornerBoxRounded({ Vars::Radar::Pos.x + 33.5f, Vars::Radar::Pos.y + 33.5f, MegaPonosX * 2 ,MegaPonosY * 2 }, { 170,170,170,105 }, 360);
	GUI::FillCornerBoxRounded({ Vars::Radar::Pos.x,Vars::Radar::Pos.y,Vars::Radar::Size.x,Vars::Radar::Size.y }, { 170,170,170,90 }, 360);
	GUI::FillBoxRounded({ Vars::Radar::Pos.x + Vars::Radar::Size.x / 2 - 2,Vars::Radar::Pos.y + Vars::Radar::Size.y / 2 - 2,4,4 }, { 170,170,170,120 }, ScaleMode::StretchToFill, 360);

	Vars::Radar::EndWindow();
	return;
}

inline void TargetHotBar() {

	float x = Vars::ScreenWidth / 2, y = Vars::ScreenHeight / 2;
	static bool sodoaso = false;
	if (!sodoaso)
	{
		Vars::Belt::Pos = { 1000,150 };
		Vars::Belt::Size = { 440 , 65 };
		sodoaso = true;
	}

	if (Vars::Visuals::PlayerEsp::TargetHotBar)
	{
		float Pos = 0;

		float w = 75, h = 75;

		Vars::Belt::mouse_pos.x = GUI::GuiMethods::get_mousePosition().x;
		Vars::Belt::mouse_pos.y = Vars::ScreenHeight - GUI::GuiMethods::get_mousePosition().y;

		if (Vars::Belt::MouseInBox({ Vars::Belt::Pos.x, Vars::Belt::Pos.y }, { Vars::Belt::Pos.x + 475, Vars::Belt::Pos.y + h }) && mouse_state && main_menu_open) {
			Vars::Belt::Pos.x += Vars::Belt::mouse_pos.x - Vars::Belt::old_mouse_pos.x;
			Vars::Belt::Pos.y += Vars::Belt::mouse_pos.y - Vars::Belt::old_mouse_pos.y;
		}

		GUI::FillBoxRounded(Rect(Vars::Belt::Pos.x, Vars::Belt::Pos.y, 475, 75), { 221,221,221, 170 }, ScaleMode::StretchToFill);

		if (Target.Cur && !Target.IsTeammate && !Target.Heli && !Target.Turret)
		{
			for (int i = 0; i < 6; i++)
			{

				BaseProjectile* ActWeapon = Target.Cur->GetWeaponInfo(i);

				if (!ActWeapon)
					return;


				if (ActWeapon && ActWeapon != nullptr && ActWeapon != 0)
				{
					const wchar_t* GetName = ActWeapon->GetWeaponName();
					if (GetName && GetName != 0)
					{
						if (ActWeapon != nullptr)
						{
							int getAmount = ActWeapon->GetAmount();
							Color col = Target.Cur->GetActiveWeapon() == ActWeapon ? Color(221, 221, 221, 170) : Color(255, 255, 255, 0);
							GUI::FillCornerBoxRounded({ Vars::Belt::Pos.x + Pos, Vars::Belt::Pos.y, w, h }, col);


							auto sprite = Classes::get_iconSprite(ActWeapon); if (!sprite) return;

							auto texture = Classes::get_texture(sprite);
							if (!texture)
								return;


							GUI::set_color({ 1, 1, 1, 1 });
							GUI::GuiMethods::DrawTexture({ Vars::Belt::Pos.x + Pos, Vars::Belt::Pos.y + 5, 73, 63.f }, texture);

							if (getAmount > 0)
							{
								wchar_t outputText[512];
								f_swprint(outputText, _(L"%d"), getAmount);
								GUI::String({ Vars::Belt::Pos.x + Pos, Vars::Belt::Pos.y + 2, 73, 63.f }, outputText, { 255 , 255 ,255,255 }, true, Vars::WorldEspTextSize);
							}
						}
					}
				}

				Pos += 80;
			}
		}

		Vars::Belt::EndWindow();
		return;
	}
}


inline void TargetHotBar1() {

	static bool sodoaso = false;
	if (!sodoaso)
	{
		Vars::Belt1::Pos = { 1000,300 };
		Vars::Belt1::Size = { 440 , 65 };
		sodoaso = true;
	}

	if (Vars::Visuals::PlayerEsp::Target_Belt)
	{
		float Pos = 0;

		float w = 75, h = 75;

		Vars::Belt1::mouse_pos.x = GUI::GuiMethods::get_mousePosition().x;
		Vars::Belt1::mouse_pos.y = Vars::ScreenHeight - GUI::GuiMethods::get_mousePosition().y;

		if (Vars::Belt1::MouseInBox({ Vars::Belt1::Pos.x, Vars::Belt1::Pos.y }, { Vars::Belt1::Pos.x + 475, Vars::Belt1::Pos.y + h }) && mouse_state && main_menu_open) {
			Vars::Belt1::Pos.x += Vars::Belt1::mouse_pos.x - Vars::Belt1::old_mouse_pos.x;
			Vars::Belt1::Pos.y += Vars::Belt1::mouse_pos.y - Vars::Belt1::old_mouse_pos.y;
		}

		GUI::FillBoxRounded(Rect(Vars::Belt1::Pos.x, Vars::Belt1::Pos.y, 475, 75), { 221,221,221, 170 }, ScaleMode::StretchToFill);

		if (Target.Cur && !Target.IsTeammate && !Target.Heli && !Target.Turret)
		{
			for (int i = 0; i < 6; i++)
			{

				BaseProjectile* ActWeapon = Target.Cur->GetWeaponInfo1(i);

				if (!ActWeapon)
					return;


				if (ActWeapon && ActWeapon != nullptr && ActWeapon != 0)
				{
					const wchar_t* GetName = ActWeapon->GetWeaponName();
					if (GetName && GetName != 0)
					{
						if (ActWeapon != nullptr)
						{
							int getAmount = ActWeapon->GetAmount();
							Color col = Color(221, 221, 221, 170);
							GUI::FillCornerBoxRounded({ Vars::Belt1::Pos.x + Pos, Vars::Belt1::Pos.y, w, h }, col);


							auto sprite = Classes::get_iconSprite(ActWeapon); if (!sprite) return;

							auto texture = Classes::get_texture(sprite);
							if (!texture)
								return;


							GUI::set_color({ 1, 1, 1, 1 });
							GUI::GuiMethods::DrawTexture({ Vars::Belt1::Pos.x + Pos, Vars::Belt1::Pos.y + 5, 73, 63.f }, texture);



						}
					}
				}

				Pos += 80;
			}
		}

		Vars::Belt1::EndWindow();
		return;
	}
}



//void DroppedItems(DWORD64 ObjectClass, DWORD64 Object, char* buff) {
//	typedef DWORD64(__stdcall* GetItem)(DWORD64);
//	if (Vars::Visuals::DroppedItems) {
//		if (m_strstr(buff, _("world"))) {
//
// 
//			BasePlayer* item = (BasePlayer*)Object;
//			if (item) {
//				Vector3 pos = item->get_transform()->Position();
//				float distance = Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), pos);
//				Vector2 screen;
//				if (WorldToScreen(pos, screen) && distance <= Vars::Visuals::DroppedItemsDist) {
//					//DWORD64 Item = safe_read(item + O::WorldItem::It, DWORD64); // public Item item; || public class WorldItem : BaseEntity
//					//DWORD64 itemDefinition = safe_read(Item + 0x20, DWORD64);
//					//DWORD64 displayName = safe_read(itemDefinition + 0x28, DWORD64);
//					//auto* english = reinterpret_cast<pUncStr>(safe_read(displayName + 0x18, DWORD64)); // get name of item
//					//int amount = safe_read(Item + 0x30, int);
//					
//				}
//			}
//		}
//	}
//}
//class ESPOption
//{
//public:
//	const char* Prefab = "";
//	const wchar_t* Name = L"";
//	const wchar_t* SubTab = L"";
//	bool Alive = false;
//
//	bool Draw = false;
//	bool DrawName = true;
//	bool DrawDistance = true;
//	bool DrawHealth = true;
//	bool checkMaxDistance = false;
//	float MaxDistance = 400;
//	float Color[3] = { 255.f, 255.f, 255.f };
//};
//#include <list>
//std::list<ESPOption> ESPOptions;



namespace Esp
{
	BasePlayer* StoredPlayers = NULL;
	//void DoAimBot(BasePlayer* player);
	int ChamUpd = 0;
	int ChamUpdRate = 150;
	void Chams(BasePlayer* Player);
	void Chams1(BasePlayer* Player);

	inline void DrawTarget(AimTarget Target);

	inline void PlayerDraw(BasePlayer* Player, bool isNpc, bool isEnemy);

	int LoopUpdateRate = 1;
	int ChachedLoop = 0;



	//_FI	void DrawObject(DWORD64 ObjectClass, char* buff, bool draw, bool showDistance, float drawDistance, const char* substring, const wchar_t* targettext, Color color, bool showhp, DWORD64 Ent);


	//void bradley(DWORD64 ObjectClass, DWORD64 Object, char* buff) {
	//	if (Vars::Visuals::) {
	//		if (m_strstr(buff, xorstr("bradleyapc.prefab"))) {

	//			BaseCombatEntity* bradley = (BaseCombatEntity*)Object;
	//			if (bradley) {
	//				Vector3 pos = bradley->transform()->position();/*utils::GetEntityPosition(object);*/
	//				int distance = Math::Distance_3D(LocalPlayer::Entity()->get_bone_pos(head), pos);
	//				float health = bradley->health();
	//				Vector2 screen;
	//				if (utils::w2s(pos, screen)) {
	//					if (health > 0) {
	//						Renderer::Text(screen, D2D1::ColorF::Red, true, true, xorstr(L"Bradley APC [%.2fm]"), Math::Distance_3D(LocalPlayer::Entity()->get_bone_pos(head), pos));

	//						Renderer::FillRectangle(Vector2{ screen - Vector2(30, 0) + Vector2(0, 15) }, Vector2{ 60 * (health / 1000.f), 6 }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
	//						Renderer::Rectangle(Vector2{ screen - Vector2(30, 0) + Vector2(0, 15) }, Vector2{ 60, 6 }, D2D1::ColorF::Black, 0.5f);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	inline void DrawStash(DWORD64 Object) {
		typedef bool(__stdcall* IsHidden)(BasePlayer*);
		//if (Vars::Visuals::Stash) {
			//if (m_strstr(buff, _("small_stash_deployed.prefab"))) {
		Vector2 screen_Pos;
		BasePlayer* Stash = (BasePlayer*)Object;
		if (Stash)
		{
			BasePlayer* Object = (BasePlayer*)Stash;
			if (!Object) return;
			const Vector3 Pos = Stash->get_transform()->Position();
			if (Pos == Vector3::Zero()) return;
			int dist = (int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos);
			int pos = 15;
			if (WorldToScreen(Pos, screen_Pos)) {
				if (dist <= Vars::Visuals::StashDist) {

					if (Classes::Hidden((DWORD64)Stash)) {
						GUI::String({ screen_Pos.x - 75, screen_Pos.y, 150, 20 }, _(L"Stash [Hidden]"), { 255 , 66 ,68,255 }, true, Vars::WorldEspTextSize);
					}
					else {
						GUI::String({ screen_Pos.x - 75, screen_Pos.y, 150, 20 }, _(L"Stash [Open]"), { 66 , 255 ,107,255 }, true, Vars::WorldEspTextSize);
					}
					if (Vars::Visuals::StashDrawDist) {
						wchar_t outputText[512];
						f_swprint(outputText, _(L"[%d m]"), dist);
						GUI::String({ screen_Pos.x - 75, screen_Pos.y + 10, 150, 20 }, outputText, Classes::Hidden((DWORD64)Stash) ? Color(255, 66, 68, 255) : Color(66, 255, 107, 255), true, Vars::WorldEspTextSize);
					}
				}
			}
		}
		//}
	//}
	}

	inline void ToolCupboard(DWORD64 Object) {
		//if (Vars::Visuals::ToolCupboard) { // chinooklockedcrate.prefab

			//if (m_strstr(buff, _("cupboard.tool.deployed.prefab"))) {
		Vector2 screen_Pos;
		BasePlayer* cupboard = (BasePlayer*)Object;
		if (cupboard)
		{ // 
			const Vector3 Pos = cupboard->get_transform()->Position();
			int pos = 15; // ToolCupboardDist
			float Calc3DDist = Maths::Calc3D_Dist(EyePos, Pos);
			if (Calc3DDist <= Vars::Visuals::ToolCupboardDist && WorldToScreen(Pos, screen_Pos)) {
				int upkeep = safe_read(cupboard + 0x288, float); // private Upkeep upkeep; // 0x288

				wchar_t outputText[512];
				f_swprint(outputText, _(L"[%d]"), upkeep / 60);

				GUI::String({ screen_Pos.x - 75, screen_Pos.y - 15, 150, 20 }, outputText, { 255 , 0 ,0,255 }, true, Vars::WorldEspTextSize);
				GUI::String({ screen_Pos.x - 75, screen_Pos.y, 150, 20 }, _(L"Tool Cupboard"), { 255 , 0 ,0,255 }, true, Vars::WorldEspTextSize);
				DWORD64 authedPly = safe_read(cupboard + 0x700, DWORD64); // public List<PlayerNameID> authorizedPlayers; // 0x700
				GameList<PlayerNameID*>* authedPly_list = Read<GameList<PlayerNameID*>*>(authedPly + 0x10);
				authedPly_list->ForEach([&](PlayerNameID* authorizedPlayer, int32_t idx) {
					if (authorizedPlayer) {
						auto user = authorizedPlayer->GetUsername();
						GUI::String({ screen_Pos.x - 75, screen_Pos.y + pos - 90, 150, 200 }, user, { 0 , 255 ,0,255 }, true, Vars::WorldEspTextSize);
						pos += 15;
					}
					});

			}
		}
		//}
	//}
	}

	inline void HackableCrate(DWORD64 Object) {
		//if (Vars::Visuals::HackableCrate) { // chinooklockedcrate.prefab

			//if (m_strstr(buff, _("codelockedhackablecrate.prefab")) || m_strstr(buff, _("codelockedhackablecrate_oilrig.prefab"))) {
		Vector2 screen_Pos;
		BasePlayer* crate = (BasePlayer*)Object;
		if (crate)
		{
			const Vector3 Pos = crate->get_transform()->Position();
			if (WorldToScreen(Pos, screen_Pos)) {
				DWORD64 timerText = safe_read(crate + 0x548, DWORD64); // public Text timerText; 
				auto* m_Text = reinterpret_cast<pUncStr>(safe_read(timerText + 0xD0, DWORD64));

				if ((int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos) <= Vars::Visuals::HackableCrateDist) {
					wchar_t outputText[512];
					f_swprint(outputText, _(L"[%s]"), m_Text->str);
					GUI::String({ screen_Pos.x - 75, screen_Pos.y - 10, 150, 20 }, outputText, { 245 , 115 ,0,255 }, true, Vars::WorldEspTextSize);
					GUI::String({ screen_Pos.x - 75, screen_Pos.y, 150, 20 }, _(L"Chinook Crate"), { 245 , 115 ,0,255 }, true, Vars::WorldEspTextSize);
					if (Vars::Visuals::HackableCrateDrawDist) {
						int dist = (int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos);
						wchar_t outputText[512];
						f_swprint(outputText, _(L"[%d]"), dist);
						GUI::String({ screen_Pos.x - 75, screen_Pos.y + 10, 150, 20 }, outputText, { 245 , 115 ,0,255 }, true, Vars::WorldEspTextSize);
					}
				}
			}
		}
		//}
	//}
	}

	// Classes::DDrawText();
	// TimedExplosive

	// Namespace: ProtoBuf
	//public class TimedExplosive : IDisposable, Pool.IPooled, IProto // TypeDefIndex: 9597
	//{
	//	// Fields
	//	public uint parentid; // 0x10
	//	public Vector3 pos; // 0x14
	//	public Vector3 normal; // 0x20
	//	public bool rfOn; // 0x2C
	//	public int freq; // 0x30
	//	public ulong creatorID; // 0x38
	//	public bool ShouldPool; // 0x40
	//	private bool _disposed; // 0x41

	void DrawRaid(DWORD64 ObjectClass, char* buff, bool draw, bool showDistance, float drawDistance, const char* substring, const wchar_t* targettext, Color color, bool showhp = false, DWORD64 Ent = 0) {
		if (draw) {
			if (m_strstr(buff, substring)) {
				if (ObjectClass) {
					const auto StoneOreObject = Read<DWORD64>(ObjectClass + 0x30);
					const Vector3 Pos = GetObjectPos(StoneOreObject);

					RaidInfo.Name = targettext;
					RaidInfo.Pos = Pos;
					// Classes::DDrawText(targettext, Pos, color, 5);
				}
			}
		}
	}

	inline void DrawObject(DWORD64 DrawObject, bool showDistance, float drawDistance, const wchar_t* targettext, Color color, bool showhp = false, int i = 0) {
		Vector2 screen_Pos;
		if (!DrawObject) {
			return;
		}
		BasePlayer* Object = (BasePlayer*)DrawObject;
		if (!Object) {
			return;
		}
		Transform* transform = Object->get_transform();
		if (!transform) {
			return;
		}
		const Vector3 Pos = transform->Position();
		if (Pos == Vector3::Zero()) {
			return;
		}
		if (WorldToScreen(Pos, screen_Pos)) {

			if ((int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos) <= drawDistance) {
				if (!showDistance)
				{
					int dist = (int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos);
					wchar_t outputText[512];
					f_swprint(outputText, _(L"%s"), targettext);
					GUI::String({ screen_Pos.x - 200, screen_Pos.y - 5, 400, 20 }, outputText, color, true, Vars::WorldEspTextSize);
				}
				else if (showDistance) {
					int dist = (int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos);
					wchar_t outputText[512];
					f_swprint(outputText, _(L"%s [%d]"), targettext, dist);
					GUI::String({ screen_Pos.x - 200, screen_Pos.y - 5, 400, 20 }, outputText, color, true, Vars::WorldEspTextSize);
				}
				if (showhp)
				{
					// public List<ulong> users; // 0x10

					auto cur_helth = Object->GetHealth();
					const auto max_health = Object->GetMaxHealth();
					float health_pc = min(cur_helth / max_health, 1);

					GUI::StartGlRender(render_type::box, { screen_Pos.x - 14.f, screen_Pos.y + 13 }, { 26, 4 }, { 0, 0, 0, 170 });
					GUI::StartGlRender(render_type::box, { screen_Pos.x - 13.f, screen_Pos.y + 13 }, { 25 * health_pc, 3 }, { 0,255, 0,255 });
					GUI::StartGlRender(render_type::boxoutline, { screen_Pos.x - 14.f, screen_Pos.y + 13 }, { 26, 4 }, { 0, 0, 0, 255 });
				}
			}
		}

		return;
	}

	inline void DrawMovingObject(DWORD64 DrawObject, bool showDistance, float drawDistance, const wchar_t* targettext, Color color, bool showhp, int i) {
		Vector2 screen_Pos;
		if (!DrawObject) {
			EspObjects[i] = 0;
			return;
		}
		BasePlayer* Object = (BasePlayer*)DrawObject;
		if (!Object) {
			EspObjects[i] = 0;
			return;
		}
		Transform* transform = Object->get_transform();
		if (!transform) {
			EspObjects[i] = 0;
			return;
		}
		const Vector3 Pos = transform->Position();
		if (Pos == Vector3::Zero()) {
			EspObjects[i] = 0;
			return;
		}
		if (WorldToScreen(Pos, screen_Pos)) {

			if ((int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos) <= drawDistance) {
				if (!showDistance)
				{
					int dist = (int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos);
					wchar_t outputText[512];
					f_swprint(outputText, _(L"%s"), targettext);
					GUI::String({ screen_Pos.x - 200, screen_Pos.y - 5, 400, 20 }, outputText, color, true, Vars::WorldEspTextSize);
				}
				else if (showDistance) {
					int dist = (int)Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), Pos);
					wchar_t outputText[512];
					f_swprint(outputText, _(L"%s [%d]"), targettext, dist);
					GUI::String({ screen_Pos.x - 200, screen_Pos.y - 5, 400, 20 }, outputText, color, true, Vars::WorldEspTextSize);
				}
				if (showhp)
				{
					// public List<ulong> users; // 0x10

					auto cur_helth = Object->GetHealth();
					const auto max_health = Object->GetMaxHealth();
					float health_pc = min(cur_helth / max_health, 1);

					GUI::StartGlRender(render_type::box, { screen_Pos.x - 14.f, screen_Pos.y + 13 }, { 26, 4 }, { 0, 0, 0, 170 });
					GUI::StartGlRender(render_type::box, { screen_Pos.x - 13.f, screen_Pos.y + 13 }, { 25 * health_pc, 3 }, { 0,255, 0,255 });
					GUI::StartGlRender(render_type::boxoutline, { screen_Pos.x - 14.f, screen_Pos.y + 13 }, { 26, 4 }, { 0, 0, 0, 255 });
				}

				return;
			}
			else
			{
				EspObjects[i] = 0;
				return;
			}
		}
		else {
			EspObjects[i] = 0;
			return;
		}
	}

	inline void RadarLogic(BasePlayer* player, bool is_npc)
	{
		if (Vars::Visuals::PlayerEsp::Radar || Vars::Visuals::PlayerEsp::LookingAtU)
		{
			Vector3 LocalPos = LocalPlayer->GetTransform(47)->Position();
			Vector3 PlayerPos = player->GetTransform(47)->Position();
			float Distance = Maths::Calc3D_Dist(LocalPos, PlayerPos);

			const float y = LocalPos.x - PlayerPos.x;
			const float x = LocalPos.z - PlayerPos.z;
			Vector3 eulerAngles = Maths::EulerAngles(LocalPlayer->GetEyes()->Rotation());
			const float num = Maths::m_Atan2(y, x) * 57.29578f - 270 - eulerAngles.y;
			float RealDist = 0.0;

			Distance *= 0.66;
			if (Distance > 198)
			{
				float Calc = Distance - 198;
				RealDist = Distance - Calc;
			}
			else
			{
				RealDist = Distance;
			}

			float PointPos_X = RealDist * Maths::m_Cos(num * 0.0174532924f);
			float PointPos_Y = RealDist * Maths::m_Sin(num * 0.0174532924f);
			PointPos_X = PointPos_X * (Vars::Radar::Size.x / 200) / 2.f;
			PointPos_Y = PointPos_Y * (Vars::Radar::Size.y / 200) / 2.f;
			Vector2 point = Vector2(Vars::Radar::Pos.x + Vars::Radar::Size.x / 2.f + PointPos_X, Vars::Radar::Pos.y + Vars::Radar::Size.y / 2.f + PointPos_Y);

			const Color Color_ = Vars::VisState ? ColorPicker::RadarVisible : ColorPicker::RadarInVisible; //blue

			if (Distance <= 400)
			{
				float sizee = 4;
				//GUI::StartGlRender(render_type::fov, Vector2::Zero2(), Vector2::Zero2(), Color, point, 2);
				if (Vars::Visuals::PlayerEsp::Radar_ld || Vars::Visuals::PlayerEsp::LookingAtU) {
					const Vector3 PlayerPosl = (player->GetBoneByID(head) + (player->GetEyes()->BodyForward() * 30));
					float Distancel = Maths::Calc3D_Dist(LocalPos, PlayerPosl);

					const float yl = LocalPos.x - PlayerPosl.x;
					const float xl = LocalPos.z - PlayerPosl.z;
					Vector3 eulerAnglesl = Maths::EulerAngles(LocalPlayer->GetEyes()->Rotation());
					const float numl = Maths::m_Atan2(yl, xl) * 57.29578f - 270 - eulerAnglesl.y;
					float RealDistl = 0.0;

					Distancel *= 0.66;
					if (Distancel > 198)
					{
						float Calcl = Distancel - 198;
						RealDistl = Distancel - Calcl;
					}
					else
					{
						RealDistl = Distancel;
					}
					Color Benis_ = { 255, 255, 0, 255 };
					float xscreen = Vars::ScreenWidth / 2, yscreen = Vars::ScreenHeight / 4;
					float PointPos_Xl = RealDistl * Maths::m_Cos(numl * 0.0174532924f);
					float PointPos_Yl = RealDistl * Maths::m_Sin(numl * 0.0174532924f);
					PointPos_Xl = PointPos_Xl * (Vars::Radar::Size.x / 200) / 2.f;
					PointPos_Yl = PointPos_Yl * (Vars::Radar::Size.y / 200) / 2.f;
					Vector2 pointl = Vector2(Vars::Radar::Pos.x + Vars::Radar::Size.x / 2.f + PointPos_Xl, Vars::Radar::Pos.y + Vars::Radar::Size.y / 2.f + PointPos_Yl);
					if (Vars::Visuals::PlayerEsp::Radar_ld) {
						GUI::StartGlRender(render_type::line, Vector2::Zero2(), Vector2::Zero2(), Benis_, Vector2::Zero2(), 0, { pointl.x + (sizee / 2), pointl.y + (sizee / 2) }, { point.x + (sizee / 2), point.y + (sizee / 2) });
					}
				}
				if (Vars::Visuals::PlayerEsp::Radar)
					GUI::FillBoxRounded({ point.x, point.y, sizee, sizee }, Color_, ScaleMode::ScaleToFit, 260);
			}

		}

	}
	float LastPickUp = 0.0;

	AimTarget FindBestPlayerTarget(BasePlayer* DrawEntity, AimTarget EndTarget)
	{
		if (!DrawEntity || !IsValidPointer((DWORD64)DrawEntity)) return EndTarget;
		AimTarget target = AimTarget();
		target.Cur = (Vars::Aim::KeepTarget && KeepTargeting && lastTarget != 0) ? lastTarget : DrawEntity;

		if (!DrawEntity->IsDead()) return EndTarget;
		if (DrawEntity->IsSleeping())
			target.IsSleeping = true;
		if (DrawEntity->IsWounded())
			target.Wounded = true;
		if (DrawEntity->IsTeamMate(LocalPlayer))
			target.IsTeammate = true;
		if (Classes::get_IsNpc((DWORD64)DrawEntity->GetPlayerModel()))
			target.Npc = true;
		if (DrawEntity->IsInSafeZone())
			target.inSafeZone = true;

		if (!target.inSafeZone || !Vars::Aim::IgnoreSafeZone) {
			if (!target.IsSleeping || !Vars::Aim::IgnoreSleepers) {
				if (!target.Wounded || !Vars::Aim::IgnoreWounded) {
					if (!target.IsTeammate || !Vars::Aim::IgnoreTeam) {
						if (!target.Npc || !Vars::Aim::IgnoreNpc) {
							if (!target.Heli || !Vars::Aim::IgnoreHeli) {
								if (!target.Turret || !Vars::Aim::IgnoreTurrets) {

									target.Pos = Vars::Aim::AimCombo == 0 ? target.Cur->GetTransform(47)->Position() : target.Cur->GetTransform(22)->Position();

									auto Network = target.Cur->GetNet(); if (!Network) return EndTarget;

									auto idd = Network->GetID(); if (!idd) return EndTarget;

									target.isvis = Unity::CheckLOS(EyePos, target.Pos);

									if (target.isvis || Vars::Aim::IgnoreVisible) {

										target.Distance = EyePos.Distance(target.Pos);

										target.Fov = GetFov(target.Pos);

										if (!(Vars::Aim::KeepTarget && KeepTargeting))
										{
											if (target < EndTarget
												&& target.Fov < Vars::Aim::AimFov)
												EndTarget = target;
											if (EndTarget.Fov > Vars::Aim::AimFov)
												EndTarget = AimTarget();
										}
										else
										{
											EndTarget = target;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		lastTarget = EndTarget.Cur;
		return EndTarget;
	}

	AimTarget FindBestObjectTarget(BasePlayer* DrawEntity, AimTarget EndTarget, bool isTurret, bool isHeli, int i)
	{
		/*if (m_strstr(buff, _("patrolhelicopter.prefab")))
			is_heli = true;

		if (m_strstr(buff, _("autoturret_deployed.prefab")))
			is_turret = true;*/

		if (!DrawEntity) {
			EspObjects[i] = 0;
			return EndTarget;
		}
		AimTarget target = AimTarget();
		target.Cur = (Vars::Aim::KeepTarget && KeepTargeting && lastTarget != 0) ? lastTarget : DrawEntity;

		target.Turret = isTurret;
		target.Heli = isHeli;

		if (!target.Heli || !Vars::Aim::IgnoreHeli) {
			if (!target.Turret || !Vars::Aim::IgnoreTurrets) {

				if (isHeli && !target.Cur->WeakSpots())
				{
					EspObjects[i] = 0;
					return EndTarget;
				}

				target.Pos = target.Cur->get_transform()->Position() + Vector3(0, 0.6, 0);

				//auto Network = target.Cur->GetNet(); if (!Network) return EndTarget;

				//auto idd = Network->GetID(); if (!idd) return EndTarget;

				target.isvis = Unity::CheckLOS(EyePos, target.Pos);

				if (target.isvis || Vars::Aim::IgnoreVisible) {

					target.Distance = EyePos.Distance(target.Pos);

					target.Fov = GetFov(target.Pos);

					if (!(Vars::Aim::KeepTarget && KeepTargeting))
					{
						if (target < EndTarget && target.Fov < Vars::Aim::AimFov)
							EndTarget = target;
						if (EndTarget.Fov > Vars::Aim::AimFov)
							EndTarget = AimTarget();
					}
					else
					{
						EndTarget = target;
					}
				}
			}
		}

		lastTarget = EndTarget.Cur;
		return EndTarget;
	}

	class Effect {
	public:
		union {
			OFFSET(Vector3, Up, 0x58);
			OFFSET(Vector3, worldPos, 0x64);
			OFFSET(Vector3, worldNrm, 0x70);
			OFFSET(bool, attached, 0x7C);
			OFFSET(Transform*, transform, 0x80);
			OFFSET(DWORD64, gameObject, 0x88);
			OFFSET(DWORD64, pooledString, 0x90);
			OFFSET(bool, broadcast, 0x98);
			// OFFSET(DWORD64, reusableInstace, 0x0);
		};
	};
	DWORD64 oPlayerList = 0;
	int PlayerEspDelay = 0;
	AimTarget LastPlayerTarget = AimTarget();
	AimTarget LastObjectTarget = AimTarget();
	void PlayerLoop()
	{
		AimTarget EndTarget = AimTarget();
		static UINT64 ClientEntities = NULL;
		static UINT64 ClientEntities_list = NULL;
		// static int EntityCount = NULL;
		// UINT64 EntityBuffer = NULL;

		if (!oPlayerList) {
			DWORD64 val = Il2cpp::InitClass(_("BasePlayer"), _(""));
			DWORD64 st = safe_read(val + 0xB8, DWORD64);
			oPlayerList = safe_read(st + 0x20, DWORD64); // private static ListDictionary<ulong, BasePlayer> visiblePlayerList; // 0x20
		}
		UINT64 ClientEntities_values = Read<UINT64>(oPlayerList + 0x28); if (!ClientEntities_values) return;
		UINT64 EntityCount = Read<int>(ClientEntities_values + 0x10);
		if (!EntityCount) {
			LastPlayerTarget = EndTarget;
			return;
		}
		UINT64 EntityBuffer = Read<UINT64>(ClientEntities_values + 0x18); if (!EntityBuffer) return;

		for (int i = 1; i < EntityCount; i++) {
			UINT64 Entity = safe_read(EntityBuffer + 0x20 + (i * 0x8), UINT64); if (!Entity) continue;
			bool ShowNpc = false;

			BasePlayer* DrawEntity = (BasePlayer*)Entity;
			if (DrawEntity)
			{
				EndTarget = FindBestPlayerTarget(DrawEntity, EndTarget);

				if (!DrawEntity->IsDead()) continue;
				if (DrawEntity->IsSleeping() && !Vars::Visuals::PlayerEsp::SleeperEsp) continue;
				if (DrawEntity->IsTeamMate(LocalPlayer) && !Vars::Visuals::PlayerEsp::TeamEsp) continue;

				if (Classes::get_IsNpc((DWORD64)DrawEntity->GetPlayerModel())) {
					ShowNpc = true;
					if (!Vars::Visuals::PlayerEsp::NpcEsp) continue;
				}

				if (ChamUpd == 0)
				{
					Esp::Chams(DrawEntity);
					ChamUpd = ChamUpdRate;
				}
				else ChamUpd--;

				bool isEnemy = false;

				PlayerDraw(DrawEntity, ShowNpc, isEnemy);
				RadarLogic(DrawEntity, ShowNpc);
				InvisiblePlayerIndicator(DrawEntity->GetBoneByID(head));
			}

		}

		Target = EndTarget;
	}
	int LastEntityCount = 0;
	int InitEspDelay = 0;
	int ClearEspDelay = 0;
	void ESPLoop() {

		AimTarget EndTarget = AimTarget();
		static UINT64 ClientEntities = NULL;
		static UINT64 ClientEntities_list = NULL;
		static UINT64 ClientEntities_values = NULL;
		static int EntityCount = NULL;
		static UINT64 EntityBuffer = NULL;

		if (ClientEntities == 0) {
			ClientEntities = Il2cpp::GetValue(_("BaseNetworkable"), _("clientEntities"), false);
			if (!ClientEntities) return;
		}
		ClientEntities_list = Read<UINT64>(ClientEntities + 0x10); if (!ClientEntities_list) return;
		ClientEntities_values = Read<UINT64>(ClientEntities_list + 0x28); if (!ClientEntities_values) return;
		EntityCount = Read<int>(ClientEntities_values + 0x10);
		if (!EntityCount) {
			return;
		}
		EntityBuffer = Read<UINT64>(ClientEntities_values + 0x18); if (!EntityBuffer) return;

		for (int i = 1; i < EntityCount; i++) {

			UINT64 Entity = safe_read(EntityBuffer + 0x20 + (i * 0x8), UINT64); if (!Entity) continue;
			unsigned int PrefabId = safe_read(Entity + O::BaseNetworkable::prefabID, UINT64); if (!PrefabId) continue;

			bool ShowNpc = false;

			bool SulfurOre = (PrefabId == 3058967796 || PrefabId == 1227527004 || PrefabId == 2204178116);
			bool StoneOre = (PrefabId == 4124824587 || PrefabId == 266547145 || PrefabId == 723721358);
			bool MetalOre = (PrefabId == 3774647716 || PrefabId == 4225479497 || PrefabId == 3345228353);

			bool Minicopter = PrefabId == 2278499844;
			bool Bradley = PrefabId == 1456850188;
			bool Rowboat = PrefabId == 1283317166;
			bool Rhib = PrefabId == 2226588638;
			bool ScrapTransportHeli = PrefabId == 3484163637;
			bool PatrolHelicopter = PrefabId == 3029415845;

			bool EliteCrate = (PrefabId == 3286607235 || PrefabId == 96231181);
			bool BasicCrate = (PrefabId == 1603759333);
			bool NormalCrate = (PrefabId == 2857304752 || PrefabId == PrefabId == 2857304752);
			bool NormalCrate2 = (PrefabId == 1546200557 || PrefabId == PrefabId == 2276830067);
			bool ToolCrate = (PrefabId == 1892026534 || PrefabId == 3027334492);

			bool Wolf = (PrefabId == 2144238755);
			bool Boar = (PrefabId == 502341109);
			bool Bear = (PrefabId == 1799741974);
			bool Horse = (PrefabId == 3880446623 || PrefabId == 2421623959);

			bool FlameTurret = (PrefabId == 4075317686);
			bool LandMine = (PrefabId == 1463807579);
			bool SamSite = (PrefabId == 2059775839);
			bool Guntrap = (PrefabId == 1348746224);
			bool BearTrap = (PrefabId == 922529517);
			bool Turrents = (PrefabId == 3312510084);

			bool Hemp = (PrefabId == 3006540952 || PrefabId == 3587624038);
			bool Corpse = (PrefabId == 2400390439 || PrefabId == 3842948583 || PrefabId == 1236143239 || PrefabId == 2604534927);
			bool BackPack = (PrefabId == 1519640547);
			bool Stash = PrefabId == 2568831788;


			bool SilentTurret = PrefabId == 3312510084;
			bool StopRecycler = PrefabId == 1729604075;
			bool ToolCupboardbool = PrefabId == 2476970476;
			bool HackableCrateBool = (PrefabId == 209286362 || PrefabId == 2043434947 || PrefabId == 3527151681);
			bool DroppedItems = (PrefabId == 545786656 || PrefabId == 3255145925);

			bool YellowBerry = (PrefabId == 3056106441);
			bool BlueBerry = (PrefabId == 2764599810);
			bool RedBerry = (PrefabId == 1378329388);
			bool GreenBerry = (PrefabId == 3306182606);

			// (Vars::Visuals::DroppedItems || Vars::Misc::AutoPickupLoot) && (PrefabId == 545786656 || PrefabId == 3255145925)


			if (!SulfurOre && !StoneOre && !MetalOre
				&& !Minicopter && !Bradley && !Rowboat && !Rhib && !ScrapTransportHeli && !PatrolHelicopter
				&& !EliteCrate && !BasicCrate && !NormalCrate && !NormalCrate2 && !ToolCrate
				&& !Wolf && !Boar && !Bear && !Horse
				&& !FlameTurret && !LandMine && !SamSite && !Guntrap && !BearTrap && !Turrents
				&& !Hemp && !Corpse && !BackPack && !Stash
				&& !SilentTurret && !StopRecycler && !ToolCupboardbool && !HackableCrateBool && !DroppedItems
				&& !YellowBerry && !BlueBerry && !RedBerry && !GreenBerry
				) continue;

			///////////////// Ores /////////////////

			if ((Turrents || PatrolHelicopter) && (!Vars::Aim::IgnoreHeli || !Vars::Aim::IgnoreTurrets))
				EndTarget = FindBestObjectTarget((BasePlayer*)Entity, Target, Turrents, PatrolHelicopter, i);

			if (TrashEsp && Vars::Visuals::DisableTrashEsp) continue;

			/*if (Vars::Visuals::Diesel && Diesel)
			{
				DrawObject(Entity, Vars::Visuals::DieselDistBool, Vars::Visuals::DieselDist, _(L"Diesel"), Color(30, 30, 30, 255), false, i);
			}*/
			if (Vars::Visuals::BlueBerry && BlueBerry)
			{
				DrawObject(Entity, Vars::Visuals::BerryDistanceBool, Vars::Visuals::BerryDstance, _(L"Blue Berry"), Color(0, 0, 255, 255), Vars::Visuals::OreHealth, i);
			}
			if (Vars::Visuals::YellowBerry && YellowBerry)
			{
				DrawObject(Entity, Vars::Visuals::BerryDistanceBool, Vars::Visuals::BerryDstance, _(L"Yellow Berry"), Color(255, 186, 0, 255), Vars::Visuals::OreHealth, i);
			}
			if (Vars::Visuals::RedBerry && RedBerry)
			{
				DrawObject(Entity, Vars::Visuals::BerryDistanceBool, Vars::Visuals::BerryDstance, _(L"Red Berry"), Color(255, 0, 0, 255), Vars::Visuals::OreHealth, i);
			}
			if (Vars::Visuals::GreenBerry && GreenBerry)
			{
				DrawObject(Entity, Vars::Visuals::BerryDistanceBool, Vars::Visuals::BerryDstance, _(L"Green Berry"), Color(0, 255, 0, 255), Vars::Visuals::OreHealth, i);
			}
			if (Vars::Visuals::SulfurOre && SulfurOre)
			{
				DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Sulfur Ore"), Color(255, 186, 0, 255), Vars::Visuals::OreHealth, Entity);
			}
			else if (Vars::Visuals::StoneOre && StoneOre)
			{
				DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Stone Ore"), Color(128, 128, 128, 255), Vars::Visuals::OreHealth, Entity);
			}
			if (Vars::Visuals::MetalOre && MetalOre)
			{
				DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Metal Ore"), Color(123, 0, 28, 255), Vars::Visuals::OreHealth, Entity);
			}
			///////////////// Vehicles /////////////////
			if (Vars::Visuals::Minicopter && Minicopter)
			{
				DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Minicopter"), Color(250, 250, 0, 255), Vars::Visuals::VehicleHealth, Entity);
			}
			if (Vars::Visuals::Bradley && Bradley)
			{
				DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Bradley"), Color(250, 152, 0, 255), Vars::Visuals::VehicleHealth, Entity);
			}
			if (Vars::Visuals::Rowboat && Rowboat)
			{
				DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Rowboat"), Color(255, 142, 13, 255), Vars::Visuals::VehicleHealth, Entity);
			}
			if (Vars::Visuals::Rhib && Rhib)
			{
				DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Rhib"), Color(128, 58, 0, 255), Vars::Visuals::VehicleHealth, Entity);
			}
			if (Vars::Visuals::ScrapTransportHeli && ScrapTransportHeli)
			{
				DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Scrap Helicopter"), Color(250, 0, 9, 255), Vars::Visuals::VehicleHealth, Entity);
			}
			if (Vars::Visuals::PatrolHelicopter && PatrolHelicopter)
			{
				DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, 10000, _(L"Patrol Helicopter"), Color(255, 0, 0, 255), true);
			}
			///////////////// Crates /////////////////
			if (Vars::Visuals::EliteCrate && EliteCrate)
			{
				DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Elite Crate"), Color(250, 250, 0, 255));
			}
			if (Vars::Visuals::BasicCrate && BasicCrate)
			{
				DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Basic Crate"), Color(250, 152, 0, 255));
			}
			if (Vars::Visuals::NormalCrate && NormalCrate)
			{
				DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Military Crate"), Color(255, 142, 13, 255));
			}
			if (Vars::Visuals::NormalCrate2 && NormalCrate2)
			{
				DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Normal Crate"), Color(128, 58, 0, 255));
			}
			if (Vars::Visuals::ToolCrate && ToolCrate)
			{
				DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Tool Crate"), Color(250, 0, 9, 255));
			}
			///////////////// Animals /////////////////
			if (Vars::Visuals::Wolf && Wolf)
			{
				DrawObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Wolf"), Color(122, 24, 255, 255));
			}
			if (Vars::Visuals::Boar && Boar)
			{
				DrawObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Boar"), Color(122, 24, 255, 255));
			}
			if (Vars::Visuals::Bear && Bear)
			{
				DrawObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Bear"), Color(122, 24, 255, 255));
			}
			if (Vars::Visuals::Horse && Horse)
			{
				DrawObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Horse"), Color(51, 173, 0, 255));
			}
			///////////////// Traps /////////////////
			if (Vars::Visuals::FlameTurret && FlameTurret)
			{
				DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Flame Turret"), Color(72, 61, 139, 255));
			}
			if (Vars::Visuals::LandMine && LandMine)
			{
				DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"LandMine"), Color(72, 61, 139, 255));
			}
			if (Vars::Visuals::SamSite && SamSite)
			{
				DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Sam Site"), Color(72, 61, 139, 255));
			}
			if (Vars::Visuals::Guntrap && Guntrap)
			{
				DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Shotgun Trap"), Color(72, 61, 139, 255));
			}
			if (Vars::Visuals::BearTrap && BearTrap)
			{
				DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Bear Trap"), Color(72, 61, 139, 255));
			}
			if (Vars::Visuals::Turrents && Turrents)
			{
				DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Auto Turret"), Color(72, 61, 139, 255));
			}
			///////////////// Miscs /////////////////
			if (Vars::Visuals::Hemp && Hemp)
			{
				DrawObject(Entity, Vars::Visuals::HempDistanceBool, Vars::Visuals::HempDistance, _(L"Hemp"), Color(60, 225, 60, 255));
			}
			if (Vars::Visuals::Corpse && Corpse)
			{
				DrawObject(Entity, Vars::Visuals::CorpseDrawDist, Vars::Visuals::CorpseDist, _(L"Corpse"), Color(255, 0, 0, 255));
			}
			if (Vars::Visuals::BackPack && BackPack)
			{
				DrawObject(Entity, Vars::Visuals::BackPackDrawDist, Vars::Visuals::BackPackDist, _(L"BackPack"), Color(255, 66, 184, 255));
			}
			if (Vars::Visuals::Stash && Stash)
				DrawStash(Entity);

			if (Vars::Misc::SilentTurret && SilentTurret)
			{
				const Vector3 Pos = reinterpret_cast<BasePlayer*>(Entity)->get_transform()->Position();
				Vector3 ClosestPos = utils::ClosestPoint(LocalPlayer, Pos);
				float Dist = Maths::Calc3D_Dist(ClosestPos, Pos);

				if (Dist < 3)
				{
					ClosestTurret.Pos = ClosestPos;
					ClosestTurret.Dist = Dist;
					ClosestTurret.Entity = Entity;
				}
			}

			if (Vars::Misc::StopRecycler && StopRecycler)
			{
				const Vector3 Pos = reinterpret_cast<BasePlayer*>(Entity)->get_transform()->Position();
				Vector3 ClosestPos = utils::ClosestPoint(LocalPlayer, Pos);
				float Dist = Maths::Calc3D_Dist(ClosestPos, Pos);

				if (Dist < 3) // ClosestDoor
				{
					ClosestRecycler.Pos = ClosestPos;
					ClosestRecycler.Dist = Dist;
					ClosestRecycler.Entity = Entity;
				}
			}

			//if (Vars::Misc::StopRecycler && PrefabId == 1729604075)
			//{
			//	const Vector3 Pos = reinterpret_cast<BasePlayer*>(Entity)->get_transform()->Position();
			//	Vector3 ClosestPos = utils::ClosestPoint(LocalPlayer, Pos);
			//	float Dist = Maths::Calc3D_Dist(ClosestPos, Pos);

			//	if (Dist < 3) // ClosestDoor
			//	{
			//		ClosestDoor.Pos = ClosestPos;
			//		ClosestDoor.Dist = Dist;
			//		ClosestDoor.Entity = Entity;
			//	}
			//}

			if (Vars::Visuals::ToolCupboard && ToolCupboardbool)
				ToolCupboard(Entity);
			if (Vars::Visuals::HackableCrate && HackableCrateBool)
				HackableCrate(Entity);

			if ((Vars::Visuals::DroppedItems || Vars::Misc::AutoPickupLoot) && DroppedItems)//m_strstr((char*)Read<DWORD64>(Read<DWORD64>(Read<DWORD64>(Object + 0x28)) + 0x10), _("DroppedItem")))
			{ // 545786656
				UINT64 Object = safe_read(Entity + 0x10, UINT64); if (!Object) continue;
				DWORD64 Ent = safe_read(Object + 0x28, UINT64);
				if (Ent)
				{
					if (Vars::Visuals::DroppedItems)
					{

						auto Item = Read<DWORD64>(Ent + Dump::CollectibleEntity::itemList);
						if (!Item)
							continue;

						auto item = reinterpret_cast<BaseProjectile*>(Item);
						if (item)
						{
							auto item_name = item->GetWeaponName();
							DrawObject(Entity, Vars::Visuals::DroppedItemsDistBool, Vars::Visuals::DroppedItemsDist, item_name, Color(232, 232, 232, 255));
						}
					}
					if (Vars::Misc::AutoPickupLoot)
					{
						if (Unity::get_fixedTime() > LastPickUp + 0.01)
						{
							BasePlayer* tar = (BasePlayer*)Entity;
							if (tar)
							{
								const Vector3 Pos = tar->get_transform()->Position();
								typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
								Vector3 local = utils::ClosestPoint(LocalPlayer, Pos);
								if (Maths::Calc3D_Dist(local, Pos) < 3.f) {
									Classes::ServerRPC((DWORD64)Ent, _(L"Pickup"));
									LastPickUp = Unity::get_fixedTime();
								}
							}
						}
					}
				}
			}

			/*std::vector<UINT64> tstetaet = {};
			tstetaet.push_back(Entity);*/

			if (Vars::Misc::AutoPickupCollect) { //settings::visuals::collectablecandy

				UINT64 Object = safe_read(Entity + 0x10, UINT64); if (Object <= 100000) continue;
				UINT64 ObjectClass = safe_read(Object + 0x30, UINT64); if (ObjectClass <= 100000) continue;
				pUncStr name = safe_read(ObjectClass + 0x60, pUncStr); if (!name) continue;
				char* buff = name->stub;
				DWORD64 Ent = safe_read(Object + 0x28, UINT64);
				if (m_strstr(buff, _("/collectable/")))
				{
					if (Unity::get_fixedTime() > LastPickUp + 0.01)
					{
						BasePlayer* tar = (BasePlayer*)Entity;
						if (tar)
						{
							const Vector3 Pos = tar->get_transform()->Position();
							typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
							Vector3 local = utils::ClosestPoint(LocalPlayer, Pos);
							if (Maths::Calc3D_Dist(local, Pos) < 3.f) {
								Classes::ServerRPC((DWORD64)Ent, _(L"Pickup"));
								LastPickUp = Unity::get_fixedTime();
							}
						}
					}
				}
			}
			/*pUncStr name = safe_read(ObjectClass + 0x60, pUncStr); if (!name) continue;
			char* buff = name->stub;*/


		}

		if (!Vars::Aim::IgnoreHeli || !Vars::Aim::IgnoreTurrets) {
			if (EndTarget < Target && EndTarget.Fov < Vars::Aim::AimFov)
				Target = EndTarget;
			else if (Target < EndTarget && Target.Fov < Vars::Aim::AimFov)
				Target = Target;
		}

		//if (Unity::RealtimeSinceStartup() >= (InitEspDelay + 5) || LocalPlayer->IsSleeping()) {
		//
		///*if (Unity::RealtimeSinceStartup() >= (ClearEspDelay + 10))
		//{

		//	ClearEspDelay = Unity::RealtimeSinceStartup();
		//}*/
		//	BasePlayer* LoopedPlayerList[256] = { 0 };
		//	BasePlayer* LoopedObjectList[256] = { 0 };
		//	int numList = 0;

		//	/*for (int i = 0; i < 512; i++)
		//	{
		//		EspObjects[i] = 0;
		//	}*/

		//	for (int i = 1; i < EntityCount; i++) {

		//		// EspObjects[i] = 0; // cleaning object from list

		//		UINT64 Entity = safe_read(EntityBuffer + 0x20 + (i * 0x8), UINT64); if (!Entity) continue;
		//		unsigned int PrefabId = safe_read(Entity + O::BaseNetworkable::prefabID, UINT64); if (!PrefabId) continue;

		//		bool ShowNpc = false;

		//		bool SulfurOre = (PrefabId == 3058967796 || PrefabId == 1227527004 || PrefabId == 2204178116);
		//		bool StoneOre = (PrefabId == 4124824587 || PrefabId == 266547145 || PrefabId == 723721358);
		//		bool MetalOre = (PrefabId == 3774647716 || PrefabId == 4225479497 || PrefabId == 3345228353);

		//		bool Minicopter = PrefabId == 2278499844;
		//		bool Bradley = PrefabId == 1456850188;
		//		bool Rowboat = PrefabId == 1283317166;
		//		bool Rhib = PrefabId == 2226588638;
		//		bool ScrapTransportHeli = PrefabId == 3484163637;
		//		bool PatrolHelicopter = PrefabId == 3029415845;

		//		bool EliteCrate = (PrefabId == 3286607235 || PrefabId == 96231181);
		//		bool BasicCrate = (PrefabId == 1603759333);
		//		bool NormalCrate = (PrefabId == 2857304752 || PrefabId == PrefabId == 2857304752);
		//		bool NormalCrate2 = (PrefabId == 1546200557 || PrefabId == PrefabId == 2276830067);
		//		bool ToolCrate = (PrefabId == 1892026534 || PrefabId == 3027334492);

		//		bool Wolf = (PrefabId == 2144238755);
		//		bool Boar = (PrefabId == 502341109);
		//		bool Bear = (PrefabId == 1799741974);
		//		bool Horse = (PrefabId == 3880446623 || PrefabId == 2421623959);

		//		bool FlameTurret = (PrefabId == 4075317686);
		//		bool LandMine = (PrefabId == 1463807579);
		//		bool SamSite = (PrefabId == 2059775839);
		//		bool Guntrap = (PrefabId == 1348746224);
		//		bool BearTrap = (PrefabId == 922529517);
		//		bool Turrents = (PrefabId == 3312510084);

		//		bool Hemp = (PrefabId == 3006540952 || PrefabId == 3587624038);
		//		bool Corpse = (PrefabId == 2400390439 || PrefabId == 3842948583 || PrefabId == 1236143239 || PrefabId == 2604534927);
		//		bool BackPack = (PrefabId == 1519640547);
		//		bool Stash = PrefabId == 2568831788;

		//		bool YellowBerry = (PrefabId == 3056106441);
		//		bool BlueBerry = (PrefabId == 2764599810);
		//		bool RedBerry = (PrefabId == 1378329388);
		//		bool GreenBerry = (PrefabId == 3306182606);

		//		bool SilentTurret = PrefabId == 3312510084;
		//		bool StopRecycler = PrefabId == 1729604075;
		//		bool ToolCupboardbool = PrefabId == 2476970476;
		//		bool HackableCrateBool = (PrefabId == 209286362 || PrefabId == 2043434947 || PrefabId == 3527151681);
		//		bool DroppedItems = (PrefabId == 545786656 || PrefabId == 3255145925);
		//		// (Vars::Visuals::DroppedItems || Vars::Misc::AutoPickupLoot) && (PrefabId == 545786656 || PrefabId == 3255145925)


		//		if (!SulfurOre && !StoneOre && !MetalOre
		//			&& !Minicopter && !Bradley && !Rowboat && !Rhib && !ScrapTransportHeli && !PatrolHelicopter
		//			&& !EliteCrate && !BasicCrate && !NormalCrate && !NormalCrate2 && !ToolCrate
		//			&& !Wolf && !Boar && !Bear && !Horse
		//			&& !FlameTurret && !LandMine && !SamSite && !Guntrap && !BearTrap && !Turrents
		//			&& !Hemp && !Corpse && !BackPack && !Stash
		//			&& !SilentTurret && !StopRecycler && !ToolCupboardbool && !HackableCrateBool && !DroppedItems
		//			&& !YellowBerry && !BlueBerry && !RedBerry && !GreenBerry
		//			) continue;

		//		if (numList < 256) {
		//			if (Entity)
		//			{
		//				BasePlayer* StoredObject = (BasePlayer*)Entity;
		//				if (StoredObject) {
		//					LoopedObjectList[numList] = StoredObject; // storing only objects that we need
		//					numList++;
		//				}
		//			}
		//		}
		//	}

		//	for (int i = 0; i < 256; i++)
		//	{
		//		if (LoopedObjectList[i])
		//		{
		//			EspObjects[i] = LoopedObjectList[i]; // validate check and storing again
		//		}
		//		else
		//		{
		//			EspObjects[i] = 0;
		//		}
		//	}

		//	InitEspDelay = Unity::RealtimeSinceStartup();
		//}

		//for (int i = 0; i < 256; i++)
		//{
		//	if (TrashEsp && Vars::Visuals::DisableTrashEsp) continue;

		//	DWORD64 Entity = (DWORD64)EspObjects[i];

		//	if (Entity) {

		//		unsigned int PrefabId = safe_read(Entity + O::BaseNetworkable::prefabID, UINT64); if (!PrefabId) continue;

		//		bool ShowNpc = false;

		//		bool SulfurOre = Vars::Visuals::SulfurOre && (PrefabId == 3058967796 || PrefabId == 1227527004 || PrefabId == 2204178116);
		//		bool StoneOre = Vars::Visuals::StoneOre && (PrefabId == 4124824587 || PrefabId == 266547145 || PrefabId == 723721358);
		//		bool MetalOre = Vars::Visuals::MetalOre && (PrefabId == 3774647716 || PrefabId == 4225479497 || PrefabId == 3345228353);

		//		bool Minicopter = Vars::Visuals::Minicopter && PrefabId == 2278499844;
		//		bool Bradley = Vars::Visuals::Bradley && PrefabId == 1456850188;
		//		bool Rowboat = Vars::Visuals::Rowboat && PrefabId == 1283317166;
		//		bool Rhib = Vars::Visuals::Rhib && PrefabId == 2226588638;
		//		bool ScrapTransportHeli = Vars::Visuals::ScrapTransportHeli && PrefabId == 3484163637;
		//		bool PatrolHelicopter = Vars::Visuals::PatrolHelicopter && PrefabId == 3029415845;

		//		bool EliteCrate = Vars::Visuals::EliteCrate && (PrefabId == 3286607235 || PrefabId == 96231181);
		//		bool BasicCrate = Vars::Visuals::BasicCrate && (PrefabId == 1603759333);
		//		bool NormalCrate = Vars::Visuals::NormalCrate && (PrefabId == 2857304752 || PrefabId == PrefabId == 2857304752);
		//		bool NormalCrate2 = Vars::Visuals::NormalCrate2 && (PrefabId == 1546200557 || PrefabId == PrefabId == 2276830067);
		//		bool ToolCrate = Vars::Visuals::ToolCrate && (PrefabId == 1892026534 || PrefabId == 3027334492);

		//		bool Wolf = Vars::Visuals::Wolf && (PrefabId == 2144238755);
		//		bool Boar = Vars::Visuals::Boar && (PrefabId == 502341109);
		//		bool Bear = Vars::Visuals::Bear && (PrefabId == 1799741974);
		//		bool Horse = Vars::Visuals::Horse && (PrefabId == 3880446623 || PrefabId == 2421623959);

		//		bool FlameTurret = Vars::Visuals::FlameTurret && (PrefabId == 4075317686);
		//		bool LandMine = Vars::Visuals::LandMine && (PrefabId == 1463807579);
		//		bool SamSite = Vars::Visuals::SamSite && (PrefabId == 2059775839);
		//		bool Guntrap = Vars::Visuals::Guntrap && (PrefabId == 1348746224);
		//		bool BearTrap = Vars::Visuals::BearTrap && (PrefabId == 922529517);
		//		bool Turrents = Vars::Visuals::Turrents && (PrefabId == 3312510084);

		//		bool Hemp = Vars::Visuals::Hemp && (PrefabId == 3006540952 || PrefabId == 3587624038);
		//		bool Corpse = Vars::Visuals::Corpse && (PrefabId == 2400390439 || PrefabId == 3842948583 || PrefabId == 1236143239 || PrefabId == 2604534927);
		//		bool BackPack = Vars::Visuals::BackPack && (PrefabId == 1519640547);
		//		bool Stash = Vars::Visuals::Stash && PrefabId == 2568831788;
		//		
		//		bool YellowBerry = Vars::Visuals::YellowBerry && (PrefabId == 3056106441);
		//		bool BlueBerry = Vars::Visuals::BlueBerry && (PrefabId == 2764599810);
		//		bool RedBerry = Vars::Visuals::RedBerry && (PrefabId == 1378329388);
		//		bool GreenBerry = Vars::Visuals::GreenBerry && (PrefabId == 3306182606);

		//		bool SilentTurret = PrefabId == 3312510084;
		//		bool StopRecycler = PrefabId == 1729604075;
		//		bool ToolCupboardbool = Vars::Visuals::ToolCupboard && PrefabId == 2476970476;
		//		bool HackableCrateBool = Vars::Visuals::HackableCrate && (PrefabId == 209286362 || PrefabId == 2043434947 || PrefabId == 3527151681);
		//		bool DroppedItems = Vars::Visuals::DroppedItems && (PrefabId == 545786656 || PrefabId == 3255145925);
		//		bool Diesel = Vars::Visuals::Diesel && (PrefabId == 4140706055 || PrefabId == 1388355532);
		//		if (Vars::Visuals::Diesel && Diesel)
		//		{
		//			DrawObject(Entity, Vars::Visuals::DieselDistBool, Vars::Visuals::DieselDist, _(L"Diesel"), Color(30, 30, 30, 255), false, i);
		//		}
		//		if (Vars::Visuals::BlueBerry && BlueBerry)
		//		{
		//			DrawObject(Entity, Vars::Visuals::BerryDistanceBool, Vars::Visuals::BerryDstance, _(L"Blue Berry"), Color(255, 186, 0, 255), Vars::Visuals::OreHealth, i);
		//		}
		//		if (Vars::Visuals::YellowBerry && YellowBerry)
		//		{
		//			DrawObject(Entity, Vars::Visuals::BerryDistanceBool, Vars::Visuals::BerryDstance, _(L"Yellow Berry"), Color(255, 186, 0, 255), Vars::Visuals::OreHealth, i);
		//		}
		//		if (Vars::Visuals::RedBerry && RedBerry)
		//		{
		//			DrawObject(Entity, Vars::Visuals::BerryDistanceBool, Vars::Visuals::BerryDstance, _(L"Red Berry"), Color(255, 186, 0, 255), Vars::Visuals::OreHealth, i);
		//		}
		//		if (Vars::Visuals::GreenBerry && GreenBerry)
		//		{
		//			DrawObject(Entity, Vars::Visuals::BerryDistanceBool, Vars::Visuals::BerryDstance, _(L"Green Berry"), Color(255, 186, 0, 255), Vars::Visuals::OreHealth, i);
		//		}

		//		if (Vars::Visuals::SulfurOre && SulfurOre)
		//		{
		//			DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Sulfur Ore"), Color(255, 186, 0, 255), Vars::Visuals::OreHealth, i);
		//		}
		//		if (Vars::Visuals::StoneOre && StoneOre)
		//		{
		//			DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Stone Ore"), Color(128, 128, 128, 255), Vars::Visuals::OreHealth, i);
		//		}
		//		if (Vars::Visuals::MetalOre && MetalOre)
		//		{
		//			DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Metal Ore"), Color(123, 0, 28, 255), Vars::Visuals::OreHealth, i);
		//		}
		//		///////////////// Vehicles /////////////////
		//		if (Vars::Visuals::Minicopter && Minicopter)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Minicopter"), Color(250, 250, 0, 255), Vars::Visuals::VehicleHealth, i);
		//		}
		//		if (Vars::Visuals::Bradley && Bradley)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Bradley"), Color(250, 152, 0, 255), Vars::Visuals::VehicleHealth, i);
		//		}
		//		if (Vars::Visuals::Rowboat && Rowboat)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Rowboat"), Color(255, 142, 13, 255), Vars::Visuals::VehicleHealth, i);
		//		}
		//		if (Vars::Visuals::Rhib && Rhib)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Rhib"), Color(128, 58, 0, 255), Vars::Visuals::VehicleHealth, i);
		//		}
		//		if (Vars::Visuals::ScrapTransportHeli && ScrapTransportHeli)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Scrap Helicopter"), Color(250, 0, 9, 255), Vars::Visuals::VehicleHealth, i);
		//		}
		//		if (Vars::Visuals::PatrolHelicopter && PatrolHelicopter)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::VehicleDistanceBool, 9000, _(L"Patrol Helicopter"), Color(255, 0, 0, 255),false, i);
		//		}
		//		///////////////// Crates /////////////////
		//		if (Vars::Visuals::EliteCrate && EliteCrate)
		//		{
		//			DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Elite Crate"), Color(250, 250, 0, 255), false, i);
		//		}
		//		if (Vars::Visuals::BasicCrate && BasicCrate)
		//		{
		//			DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Basic Crate"), Color(250, 152, 0, 255), false, i);
		//		}
		//		if (Vars::Visuals::NormalCrate && NormalCrate)
		//		{
		//			DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Military Crate"), Color(255, 142, 13, 255), false, i);
		//		}
		//		if (Vars::Visuals::NormalCrate2 && NormalCrate2)
		//		{
		//			DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Normal Crate"), Color(128, 58, 0, 255), false, i);
		//		}
		//		if (Vars::Visuals::ToolCrate && ToolCrate)
		//		{
		//			DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Tool Crate"), Color(250, 0, 9, 255), false, i);
		//		}
		//		///////////////// Animals /////////////////
		//		if (Vars::Visuals::Wolf && Wolf)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Wolf"), Color(122, 24, 255, 255), false, i);
		//		}
		//		if (Vars::Visuals::Boar && Boar)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Boar"), Color(122, 24, 255, 255), false, i);
		//		}
		//		if (Vars::Visuals::Bear && Bear)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Bear"), Color(122, 24, 255, 255), false, i);
		//		}
		//		if (Vars::Visuals::Horse && Horse)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Horse"), Color(51, 173, 0, 255), false, i);
		//		}
		//		///////////////// Traps /////////////////
		//		if (Vars::Visuals::FlameTurret && FlameTurret)
		//		{
		//			DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Flame Turret"), Color(72, 61, 139, 255), false, i);
		//		}
		//		if (Vars::Visuals::LandMine && LandMine)
		//		{
		//			DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"LandMine"), Color(72, 61, 139, 255), false, i);
		//		}
		//		if (Vars::Visuals::SamSite && SamSite)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Sam Site"), Color(72, 61, 139, 255), false, i);
		//		}
		//		if (Vars::Visuals::Guntrap && Guntrap)
		//		{
		//			DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Shotgun Trap"), Color(72, 61, 139, 255), false, i);
		//		}
		//		if (Vars::Visuals::BearTrap && BearTrap)
		//		{
		//			DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Bear Trap"), Color(72, 61, 139, 255), false, i);
		//		}
		//		if (Vars::Visuals::Turrents && Turrents)
		//		{
		//			DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Auto Turret"), Color(72, 61, 139, 255), false, i);
		//		}
		//		///////////////// Miscs /////////////////
		//		if (Vars::Visuals::Hemp && Hemp)
		//		{
		//			DrawObject(Entity, Vars::Visuals::HempDistanceBool, Vars::Visuals::HempDistance, _(L"Hemp"), Color(60, 225, 60, 255), false, i);
		//		}
		//		if (Vars::Visuals::Corpse && Corpse)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::CorpseDrawDist, Vars::Visuals::CorpseDist, _(L"Corpse"), Color(255, 0, 0, 255), false, i);
		//		}
		//		if (Vars::Visuals::BackPack && BackPack)
		//		{
		//			DrawMovingObject(Entity, Vars::Visuals::BackPackDrawDist, Vars::Visuals::BackPackDist, _(L"BackPack"), Color(255, 66, 184, 255), false, i);
		//		}
		//		if (Vars::Visuals::Stash && Stash)
		//			DrawStash(Entity);

		//		if (Vars::Misc::SilentTurret && SilentTurret)
		//		{
		//			const Vector3 Pos = reinterpret_cast<BasePlayer*>(Entity)->get_transform()->Position();
		//			Vector3 ClosestPos = utils::ClosestPoint(LocalPlayer, Pos);
		//			float Dist = Maths::Calc3D_Dist(ClosestPos, Pos);

		//			if (Dist < 3)
		//			{
		//				ClosestTurret.Pos = ClosestPos;
		//				ClosestTurret.Dist = Dist;
		//				ClosestTurret.Entity = Entity;
		//			}
		//		}

		//		if (Vars::Misc::StopRecycler && StopRecycler)
		//		{
		//			const Vector3 Pos = reinterpret_cast<BasePlayer*>(Entity)->get_transform()->Position();
		//			Vector3 ClosestPos = utils::ClosestPoint(LocalPlayer, Pos);
		//			float Dist = Maths::Calc3D_Dist(ClosestPos, Pos);

		//			if (Dist < 3) // ClosestDoor
		//			{
		//				ClosestRecycler.Pos = ClosestPos;
		//				ClosestRecycler.Dist = Dist;
		//				ClosestRecycler.Entity = Entity;
		//			}
		//		}

		//		if (Vars::Visuals::ToolCupboard && ToolCupboardbool)
		//			ToolCupboard(Entity);
		//		if (Vars::Visuals::HackableCrate && HackableCrateBool)
		//			HackableCrate(Entity);

		//		if ((Vars::Visuals::DroppedItems || Vars::Misc::AutoPickupLoot) && DroppedItems)
		//		{ // 545786656
		//			UINT64 Object = safe_read(Entity + 0x10, UINT64); if (!Object) continue;
		//			DWORD64 Ent = safe_read(Object + 0x28, UINT64);
		//			if (Ent)
		//			{
		//				if (Vars::Visuals::DroppedItems)
		//				{

		//					auto Item = Read<DWORD64>(Ent + Dump::CollectibleEntity::itemList);
		//					if (!Item)
		//						continue;

		//					auto item = reinterpret_cast<BaseProjectile*>(Item);
		//					if (item)
		//					{
		//						auto item_name = item->GetWeaponName();
		//						DrawMovingObject(Entity, Vars::Visuals::DroppedItemsDistBool, Vars::Visuals::DroppedItemsDist, item_name, Color(232, 232, 232, 255),false, i);
		//					}
		//				}
		//				if (Vars::Misc::AutoPickupLoot)
		//				{
		//					if (Unity::get_fixedTime() > LastPickUp + 0.01)
		//					{
		//						BasePlayer* tar = (BasePlayer*)Entity;
		//						if (tar)
		//						{
		//							const Vector3 Pos = tar->get_transform()->Position();
		//							typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
		//							Vector3 local = utils::ClosestPoint(LocalPlayer, Pos);
		//							if (Maths::Calc3D_Dist(local, Pos) < 3.f) {
		//								Classes::ServerRPC((DWORD64)Ent, _(L"Pickup"));
		//								LastPickUp = Unity::get_fixedTime();
		//							}
		//						}
		//					}
		//				}
		//			}
		//		}

		//		if ((Turrents || PatrolHelicopter) && (!Vars::Aim::IgnoreHeli || !Vars::Aim::IgnoreTurrets))
		//			EndTarget = FindBestObjectTarget((BasePlayer*)Entity, Target, Turrents, PatrolHelicopter, i);

		//		// FindBestObjectTarget
		//		if (Vars::Misc::AutoPickupCollect) { //settings::visuals::collectablecandy

		//			UINT64 Object = safe_read(Entity + 0x10, UINT64); if (!Object) continue;
		//			UINT64 ObjectClass = safe_read(Object + 0x30, UINT64); if (!ObjectClass) continue;
		//			pUncStr name = safe_read(ObjectClass + 0x60, pUncStr); if (!name) continue;
		//			char* buff = name->stub;
		//			DWORD64 Ent = safe_read(Object + 0x28, UINT64);
		//			if (m_strstr(buff, _("/collectable/")))
		//			{
		//				if (Unity::get_fixedTime() > LastPickUp + 0.01)
		//				{
		//					BasePlayer* tar = (BasePlayer*)Entity;
		//					if (tar)
		//					{
		//						const Vector3 Pos = tar->get_transform()->Position();
		//						typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
		//						Vector3 local = utils::ClosestPoint(LocalPlayer, Pos);
		//						if (Maths::Calc3D_Dist(local, Pos) < 3.f) {
		//							Classes::ServerRPC((DWORD64)Ent, _(L"Pickup"));
		//							LastPickUp = Unity::get_fixedTime();
		//						}
		//					}
		//				}
		//			}
		//		}
		//	}
		//	else
		//	{
		//		EspObjects[i] = 0;
		//	}
		//}

		//if (!Vars::Aim::IgnoreHeli || !Vars::Aim::IgnoreTurrets) {
		//	if (EndTarget < Target && EndTarget.Fov < Vars::Aim::AimFov)
		//		Target = EndTarget;
		//	else if (Target < EndTarget && Target.Fov < Vars::Aim::AimFov)
		//		Target = Target;
		//}
		/*AimTarget EndTarget = AimTarget();
		if (LastObjectTarget.Cur)
		{
			if (LastObjectTarget < EndTarget && LastObjectTarget.Fov < Vars::Aim::AimFov) {
				EndTarget = target;
				Target = EndTarget;
			}
		}
		else
		{
			Target = Target;
		}*/

		//DrawRaid();
		DrawTarget(Target);

		TargetHotBar();
		TargetHotBar1();

	}


}


//for (int i = 1; i < EntityCount; i++) {
//	UINT64 Entity = safe_read(EntityBuffer + 0x20 + (i * 0x8), UINT64); if (!Entity) continue;
//	unsigned int PrefabId = safe_read(Entity + O::BaseNetworkable::prefabID, UINT64); if (!PrefabId) continue;
//
//	bool ShowNpc = false;
//
//	bool SulfurOre = (PrefabId == 3058967796 || PrefabId == 1227527004 || PrefabId == 2204178116);
//	bool StoneOre = (PrefabId == 4124824587 || PrefabId == 266547145 || PrefabId == 723721358);
//	bool MetalOre = (PrefabId == 3774647716 || PrefabId == 4225479497 || PrefabId == 3345228353);
//
//	bool Minicopter = PrefabId == 2278499844;
//	bool Bradley = PrefabId == 1456850188;
//	bool Rowboat = PrefabId == 1283317166;
//	bool Rhib = PrefabId == 2226588638;
//	bool ScrapTransportHeli = PrefabId == 3484163637;
//	bool PatrolHelicopter = PrefabId == 3029415845;
//
//	bool EliteCrate = (PrefabId == 3286607235 || PrefabId == 96231181);
//	bool BasicCrate = (PrefabId == 1603759333);
//	bool NormalCrate = (PrefabId == 2857304752 || PrefabId == PrefabId == 2857304752);
//	bool NormalCrate2 = (PrefabId == 1546200557 || PrefabId == PrefabId == 2276830067);
//	bool ToolCrate = (PrefabId == 1892026534 || PrefabId == 3027334492);
//
//	bool Wolf = (PrefabId == 2144238755);
//	bool Boar = (PrefabId == 502341109);
//	bool Bear = (PrefabId == 1799741974);
//	bool Horse = (PrefabId == 3880446623 || PrefabId == 2421623959);
//
//	bool FlameTurret = (PrefabId == 4075317686);
//	bool LandMine = (PrefabId == 1463807579);
//	bool SamSite = (PrefabId == 2059775839);
//	bool Guntrap = (PrefabId == 1348746224);
//	bool BearTrap = (PrefabId == 922529517);
//	bool Turrents = (PrefabId == 3312510084);
//
//	bool Hemp = (PrefabId == 3006540952 || PrefabId == 3587624038);
//	bool Corpse = (PrefabId == 2400390439 || PrefabId == 3842948583 || PrefabId == 1236143239 || PrefabId == 2604534927);
//	bool BackPack = (PrefabId == 1519640547);
//	bool Stash = PrefabId == 2568831788;
//
//
//	bool SilentTurret = PrefabId == 3312510084;
//	bool StopRecycler = PrefabId == 1729604075;
//	bool ToolCupboardbool = PrefabId == 2476970476;
//	bool HackableCrateBool = (PrefabId == 209286362 || PrefabId == 2043434947 || PrefabId == 3527151681);
//	bool DroppedItems = (PrefabId == 545786656 || PrefabId == 3255145925);
//	// (Vars::Visuals::DroppedItems || Vars::Misc::AutoPickupLoot) && (PrefabId == 545786656 || PrefabId == 3255145925)
//
//
//	if (!SulfurOre && !StoneOre && !MetalOre
//		&& !Minicopter && !Bradley && !Rowboat && !Rhib && !ScrapTransportHeli && !PatrolHelicopter
//		&& !EliteCrate && !BasicCrate && !NormalCrate && !NormalCrate2 && !ToolCrate
//		&& !Wolf && !Boar && !Bear && !Horse
//		&& !FlameTurret && !LandMine && !SamSite && !Guntrap && !BearTrap && !Turrents
//		&& !Hemp && !Corpse && !BackPack && !Stash
//		&& !SilentTurret && !StopRecycler && !ToolCupboardbool && !HackableCrateBool && !DroppedItems
//		) continue;
//
//	if (Entity)
//	{ // LoopedPlayerList
//		BasePlayer* StoredObject = (BasePlayer*)Entity;
//		if (StoredObject) {
//			LoopedPlayerList[numList] = StoredObject;
//		}
//	}
//	///////////////// Ores /////////////////
//
//	if (Vars::Visuals::SulfurOre && SulfurOre)
//	{
//		DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Sulfur Ore"), Color(255, 186, 0, 255), Vars::Visuals::OreHealth, Entity);
//	}
//	else if (Vars::Visuals::StoneOre && StoneOre)
//	{
//		DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Stone Ore"), Color(128, 128, 128, 255), Vars::Visuals::OreHealth, Entity);
//	}
//	if (Vars::Visuals::MetalOre && MetalOre)
//	{
//		DrawObject(Entity, Vars::Visuals::DrawdDstanceBool, Vars::Visuals::DrawdDstance, _(L"Metal Ore"), Color(123, 0, 28, 255), Vars::Visuals::OreHealth, Entity);
//	}
//	///////////////// Vehicles /////////////////
//	if (Vars::Visuals::Minicopter && Minicopter)
//	{
//		DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Minicopter"), Color(250, 250, 0, 255), Vars::Visuals::VehicleHealth, Entity);
//	}
//	if (Vars::Visuals::Bradley && Bradley)
//	{
//		DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Bradley"), Color(250, 152, 0, 255), Vars::Visuals::VehicleHealth, Entity);
//	}
//	if (Vars::Visuals::Rowboat && Rowboat)
//	{
//		DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Rowboat"), Color(255, 142, 13, 255), Vars::Visuals::VehicleHealth, Entity);
//	}
//	if (Vars::Visuals::Rhib && Rhib)
//	{
//		DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Rhib"), Color(128, 58, 0, 255), Vars::Visuals::VehicleHealth, Entity);
//	}
//	if (Vars::Visuals::ScrapTransportHeli && ScrapTransportHeli)
//	{
//		DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, Vars::Visuals::VehicleDstance, _(L"Scrap Helicopter"), Color(250, 0, 9, 255), Vars::Visuals::VehicleHealth, Entity);
//	}
//	if (Vars::Visuals::PatrolHelicopter && PatrolHelicopter)
//	{
//		DrawObject(Entity, Vars::Visuals::VehicleDistanceBool, 10000, _(L"Patrol Helicopter"), Color(255, 0, 0, 255));
//	}
//	///////////////// Crates /////////////////
//	if (Vars::Visuals::EliteCrate && EliteCrate)
//	{
//		DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Elite Crate"), Color(250, 250, 0, 255));
//	}
//	if (Vars::Visuals::BasicCrate && BasicCrate)
//	{
//		DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Basic Crate"), Color(250, 152, 0, 255));
//	}
//	if (Vars::Visuals::NormalCrate && NormalCrate)
//	{
//		DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Military Crate"), Color(255, 142, 13, 255));
//	}
//	if (Vars::Visuals::NormalCrate2 && NormalCrate2)
//	{
//		DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Normal Crate"), Color(128, 58, 0, 255));
//	}
//	if (Vars::Visuals::ToolCrate && ToolCrate)
//	{
//		DrawObject(Entity, Vars::Visuals::CrateDstanceBool, Vars::Visuals::CrateDstance, _(L"Tool Crate"), Color(250, 0, 9, 255));
//	}
//	///////////////// Animals /////////////////
//	if (Vars::Visuals::Wolf && Wolf)
//	{
//		DrawObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Wolf"), Color(122, 24, 255, 255));
//	}
//	if (Vars::Visuals::Boar && Boar)
//	{
//		DrawObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Boar"), Color(122, 24, 255, 255));
//	}
//	if (Vars::Visuals::Bear && Bear)
//	{
//		DrawObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Bear"), Color(122, 24, 255, 255));
//	}
//	if (Vars::Visuals::Horse && Horse)
//	{
//		DrawObject(Entity, Vars::Visuals::DistanceAnimalBool, Vars::Visuals::DistanceAnimal, _(L"Horse"), Color(51, 173, 0, 255));
//	}
//	///////////////// Traps /////////////////
//	if (Vars::Visuals::FlameTurret && FlameTurret)
//	{
//		DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Flame Turret"), Color(72, 61, 139, 255));
//	}
//	if (Vars::Visuals::LandMine && LandMine)
//	{
//		DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"LandMine"), Color(72, 61, 139, 255));
//	}
//	if (Vars::Visuals::SamSite && SamSite)
//	{
//		DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Sam Site"), Color(72, 61, 139, 255));
//	}
//	if (Vars::Visuals::Guntrap && Guntrap)
//	{
//		DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Shotgun Trap"), Color(72, 61, 139, 255));
//	}
//	if (Vars::Visuals::BearTrap && BearTrap)
//	{
//		DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Bear Trap"), Color(72, 61, 139, 255));
//	}
//	if (Vars::Visuals::Turrents && Turrents)
//	{
//		DrawObject(Entity, Vars::Visuals::TrapDstanceBool, Vars::Visuals::TrapDstance, _(L"Auto Turret"), Color(72, 61, 139, 255));
//	}
//	///////////////// Miscs /////////////////
//	if (Vars::Visuals::Hemp && Hemp)
//	{
//		DrawObject(Entity, Vars::Visuals::HempDistanceBool, Vars::Visuals::HempDistance, _(L"Hemp"), Color(60, 225, 60, 255));
//	}
//	if (Vars::Visuals::Corpse && Corpse)
//	{
//		DrawObject(Entity, Vars::Visuals::CorpseDrawDist, Vars::Visuals::CorpseDist, _(L"Corpse"), Color(255, 0, 0, 255));
//	}
//	if (Vars::Visuals::BackPack && BackPack)
//	{
//		DrawObject(Entity, Vars::Visuals::BackPackDrawDist, Vars::Visuals::BackPackDist, _(L"BackPack"), Color(255, 66, 184, 255));
//	}
//	if (Vars::Visuals::Stash && Stash)
//		DrawStash(Entity);
//
//	if (Vars::Misc::SilentTurret && SilentTurret)
//	{
//		const Vector3 Pos = reinterpret_cast<BasePlayer*>(Entity)->get_transform()->Position();
//		Vector3 ClosestPos = utils::ClosestPoint(LocalPlayer, Pos);
//		float Dist = Maths::Calc3D_Dist(ClosestPos, Pos);
//
//		if (Dist < 3)
//		{
//			ClosestTurret.Pos = ClosestPos;
//			ClosestTurret.Dist = Dist;
//			ClosestTurret.Entity = Entity;
//		}
//	}
//
//	if (Vars::Misc::StopRecycler && StopRecycler)
//	{
//		const Vector3 Pos = reinterpret_cast<BasePlayer*>(Entity)->get_transform()->Position();
//		Vector3 ClosestPos = utils::ClosestPoint(LocalPlayer, Pos);
//		float Dist = Maths::Calc3D_Dist(ClosestPos, Pos);
//
//		if (Dist < 3) // ClosestDoor
//		{
//			ClosestRecycler.Pos = ClosestPos;
//			ClosestRecycler.Dist = Dist;
//			ClosestRecycler.Entity = Entity;
//		}
//	}
//
//	//if (Vars::Misc::StopRecycler && PrefabId == 1729604075)
//	//{
//	//	const Vector3 Pos = reinterpret_cast<BasePlayer*>(Entity)->get_transform()->Position();
//	//	Vector3 ClosestPos = utils::ClosestPoint(LocalPlayer, Pos);
//	//	float Dist = Maths::Calc3D_Dist(ClosestPos, Pos);
//
//	//	if (Dist < 3) // ClosestDoor
//	//	{
//	//		ClosestDoor.Pos = ClosestPos;
//	//		ClosestDoor.Dist = Dist;
//	//		ClosestDoor.Entity = Entity;
//	//	}
//	//}
//
//	if (Vars::Visuals::ToolCupboard && ToolCupboardbool)
//		ToolCupboard(Entity);
//	if (Vars::Visuals::HackableCrate && HackableCrateBool)
//		HackableCrate(Entity);
//
//	if ((Vars::Visuals::DroppedItems || Vars::Misc::AutoPickupLoot) && DroppedItems)//m_strstr((char*)Read<DWORD64>(Read<DWORD64>(Read<DWORD64>(Object + 0x28)) + 0x10), _("DroppedItem")))
//	{ // 545786656
//		UINT64 Object = safe_read(Entity + 0x10, UINT64); if (!Object) continue;
//		DWORD64 Ent = safe_read(Object + 0x28, UINT64);
//		if (Ent)
//		{
//			if (Vars::Visuals::DroppedItems)
//			{
//
//				auto Item = Read<DWORD64>(Ent + Dump::CollectibleEntity::itemList);
//				if (!Item)
//					continue;
//
//				auto item = reinterpret_cast<BaseProjectile*>(Item);
//				if (item)
//				{
//					auto item_name = item->GetWeaponName();
//					DrawObject(Entity, Vars::Visuals::DroppedItemsDistBool, Vars::Visuals::DroppedItemsDist, item_name, Color(232, 232, 232, 255));
//				}
//			}
//			if (Vars::Misc::AutoPickupLoot)
//			{
//				if (Unity::get_fixedTime() > LastPickUp + 0.01)
//				{
//					BasePlayer* tar = (BasePlayer*)Entity;
//					if (tar)
//					{
//						const Vector3 Pos = tar->get_transform()->Position();
//						typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
//						Vector3 local = utils::ClosestPoint(LocalPlayer, Pos);
//						if (Maths::Calc3D_Dist(local, Pos) < 3.f) {
//							Classes::ServerRPC((DWORD64)Ent, _(L"Pickup"));
//							LastPickUp = Unity::get_fixedTime();
//						}
//					}
//				}
//			}
//		}
//	}
//
//	/*std::vector<UINT64> tstetaet = {};
//	tstetaet.push_back(Entity);*/
//
//	if (Vars::Misc::AutoPickupCollect) { //settings::visuals::collectablecandy
//
//		UINT64 Object = safe_read(Entity + 0x10, UINT64); if (Object <= 100000) continue;
//		UINT64 ObjectClass = safe_read(Object + 0x30, UINT64); if (ObjectClass <= 100000) continue;
//		pUncStr name = safe_read(ObjectClass + 0x60, pUncStr); if (!name) continue;
//		char* buff = name->stub;
//		DWORD64 Ent = safe_read(Object + 0x28, UINT64);
//		if (m_strstr(buff, _("/collectable/")))
//		{
//			if (Unity::get_fixedTime() > LastPickUp + 0.01)
//			{
//				BasePlayer* tar = (BasePlayer*)Entity;
//				if (tar)
//				{
//					const Vector3 Pos = tar->get_transform()->Position();
//					typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
//					Vector3 local = utils::ClosestPoint(LocalPlayer, Pos);
//					if (Maths::Calc3D_Dist(local, Pos) < 3.f) {
//						Classes::ServerRPC((DWORD64)Ent, _(L"Pickup"));
//						LastPickUp = Unity::get_fixedTime();
//					}
//				}
//			}
//		}
//	}
//	/*pUncStr name = safe_read(ObjectClass + 0x60, pUncStr); if (!name) continue;
//	char* buff = name->stub;*/
//
//
//}


//if (m_strstr((char*)Read<DWORD64>(Read<DWORD64>(Read<DWORD64>(Object + 0x28)) + 0x10), _("OreResourceEntity"))) {//if (m_strstr(buff, _("OreResourceEntity"))) {
//	if (Unity::ChamsMaterial)
//	{
//		auto render = Unity::GetComponentsInChildren(Entity, Il2cpp::TypeGetObject(_("UnityEngine"), _("Renderer")));
//		if (render) {
//			auto size = safe_read(render + 0x18, DWORD64);
//			for (int i = 0; i < size; i++) {
//				auto renderer = safe_read(render + 0x20 + (i * 0x8), DWORD64);
//				if (renderer) {
//					auto material = Classes::get_material(renderer);
//					if (material) {

//						///*auto Galaxy = Unity::LoadAsset(Unity::ChamsMaterial, _(L"galaxymaterial_13.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material")));
//						//if (Classes::get_material(renderer) != Galaxy && Galaxy)
//						//	Unity::set_material(renderer, Galaxy);*/

//						if (!Unity::PlayerChamsShader)
//							Unity::PlayerChamsShader = Unity::LoadAsset(Unity::ChamsShader, _(L"force field.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader")));

//						if (Classes::get_shader(material) != Unity::PlayerChamsShader)
//						{
//							Classes::set_shader(material, Unity::PlayerChamsShader);
//							GUI::SetInt(material, _(L"_ZTest"), 0); // _FresnelPower
//							//GUI::SetInt(material, _(L"_FresnelPower"), 60); // _FresnelPower
//							Classes::SetColor(material, _(L"_Color"), Color(255, 255, 255,255).GetUnityColor());
//							
//						//	Classes::SetColor(material, _(L"_Color"), Color(0, 255, 0, 255).GetUnityColor()); _FresnelPower
//						}
//					}
//				}
//			}
//		}
//	}

