#pragma once
#define OFFSET( type, name, offset ) __forceinline type& name( ) { return *reinterpret_cast< type* >( ( DWORD64 )this + offset ); }


//UINT64* PlayerList[250];
//
//UINT64* StoneList[100];
//UINT64* MetalList[100];
//UINT64* SulfurList[100];
//
//UINT64* DroppedItems[100];
//UINT64* DroppedEnts[100];
//
//UINT64* StashList[100];
//UINT64* TCList[100];
//UINT64* HackableCrateList[100];
//UINT64* HempList[100];
//UINT64* CorpseList[100];
//UINT64* BackPackList[100];
//
//UINT64* EliteCrate[100];
//UINT64* BasicCrate[100];
//UINT64* MilitaryCrate[100];
//UINT64* NormalCrate[100];
//UINT64* ToolCrate[100];
//
//UINT64* Minicopter[100];
//UINT64* Bradley[100];
//UINT64* Rowboat[100];
//UINT64* Rhib[100];
//UINT64* ScrapTransportHeli[100];
//
//UINT64* Wolf[100];
//UINT64* Boar[100];
//UINT64* Bear[100];
//UINT64* Horse[100];
//
//UINT64* FlameTurret[100];
//UINT64* LandMine[100];
//UINT64* SamSite[100];
//UINT64* Guntrap[100];
//UINT64* BearTrap[100];
//UINT64* Turrents[100];

struct weapon_data {
	float initial_velocity;
	float gravity_modifier;
	float drag;
	float initial_distance;
};

enum ammo_types : int32_t {
	shotgun = -1685290200,
	shotgun_slug = -727717969,
	shotgun_fire = -1036635990,
	shotgun_handmade = 588596902,

	rifle_556 = -1211166256,
	rifle_556_hv = 1712070256,
	rifle_556_fire = 605467368,
	rifle_556_explosive = -1321651331,

	pistol = 785728077,
	pistol_hv = -1691396643,
	pistol_fire = 51984655,



	_wooden = -1234735557,
	arrow_hv = -1023065463,
	arrow_fire = 14241751,
	arrow_bone = 215754713,

	nailgun_nails = -2097376851
};

enum weapon_types : int32_t {
	spear_stone = 1602646136,
	spear_wooden = 1540934679
};

//void ClearLists()
//{
//	*PlayerList = 0;
//
//	*StoneList = 0;
//	*MetalList = 0;
//	*SulfurList = 0;
//
//	*DroppedItems = 0;
//	*DroppedEnts = 0;
//
//	*StashList = 0;
//	*TCList = 0;
//	*HackableCrateList = 0;
//	*HempList = 0;
//	*CorpseList = 0;
//	*BackPackList = 0;
//
//	*EliteCrate = 0;
//	*BasicCrate = 0;
//	*MilitaryCrate = 0;
//	*NormalCrate = 0;
//	*ToolCrate = 0;
//
//	*Minicopter = 0;
//	*Bradley = 0;
//	*Rowboat = 0;
//	*Rhib = 0;
//	*ScrapTransportHeli = 0;
//
//	*Wolf = 0;
//	*Boar = 0;
//	*Bear = 0;
//	*Horse = 0;
//
//	*FlameTurret = 0;
//	*LandMine = 0;
//	*SamSite = 0;
//	*Guntrap = 0;
//	*BearTrap = 0;
//	*Turrents = 0;
//}


class Color {
public:
	float r;
	float g;
	float b;
	float a;

	Color()
	{
		r = 0;
		g = 0;
		b = 0;
		a = 0;
	}


	Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color GetUnityColor()
	{
		return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}

	Color Zero()
	{
		return Color(0, 0, 0, 0);
	}
};

enum class ModelState_Flag
{
	Ducked = 1,
	Jumped = 2,
	OnGround = 4,
	Sleeping = 8,
	Sprinting = 16,
	OnLadder = 32,
	Flying = 64,
	Aiming = 128,
	Prone = 256,
	Mounted = 512,
	Relaxed = 1024,
	Crawling = 4096,
};
class Transform;

class PlayerWalkMovement;


class Networkable;
class ItemModProj;
class Magazine;
class PlayerEyes;

class Projectile;
class HitTest;
class AimResult;
class Material;


class  AimTarget {
public:
	Vector3 Pos;
	BasePlayer* Cur;
	bool Heli;
	bool Turret;
	bool IsTeammate;
	bool inSafeZone;
	bool IsSleeping;
	bool Wounded;
	bool Npc;
	bool isvis;
	float Distance = 10000;

	int Fov = Vars::Aim::AimFov;
	//	if (!(Unity::GetKeyInt(Vars::Keys::KeepTargetKey) && Vars::Aim::KeepTarget))
	bool operator<(const AimTarget& b) {
		return Fov < b.Fov;
	}
};




namespace Classes
{
	auto HasParent = reinterpret_cast<bool (*)(BasePlayer*)>(0);
	auto CenterPoint = reinterpret_cast<Vector3(*)(BasePlayer*)>(0);
	auto WaterLevelTest = reinterpret_cast<bool(*)(Vector3, bool, BasePlayer*)>(0);
	auto SendSignal = reinterpret_cast<void(*)(DWORD64, BaseEntity::Signal, Str)>(0);
	auto DoThrow = reinterpret_cast<void(*)(DWORD64)>(0);
	auto GetParentVelocity = reinterpret_cast<Vector3(*)(BasePlayer*)>(0);
	auto GetMountVelocity = reinterpret_cast<Vector3(*)(BasePlayer*)>(0);
	auto console_msg = reinterpret_cast<void(*)(uintptr_t, Str)>(0);
	auto SetTimedLootAction = reinterpret_cast<void (*)(DWORD64, DWORD64, DWORD64)>(0); // StartTimedLootAction
	auto StartTimedLootAction = reinterpret_cast<DWORD64(*)(DWORD64, float)>(0); // StartTimedLootAction
	auto Hidden = reinterpret_cast<bool(*)(DWORD64)>(0);
	auto isHidden = reinterpret_cast<bool* (*)(DWORD64)>(0);
	auto getContainMaterial = reinterpret_cast<Material * (*)(DWORD64)>(0);
	auto CanAttack = reinterpret_cast<bool (*)(DWORD64)>(0);
	//auto HasProperty = reinterpret_cast<bool (*)(Material*, Str)>(0);
	auto Projectile_Launch = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Projectile"), _("Launch"), 0, _(""), _(""))));
	auto SendClientTick = reinterpret_cast<void(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BasePlayer"), _("SendClientTick"), 0, _(""), _(""))));
	auto SphereCast = reinterpret_cast<bool (*)(Ray, float, float, int, QueryTriggerInteraction)>(0);
	auto set_atmosphere_rayleigh = reinterpret_cast<void (*)(float)>(0);
	auto HasAttackCooldown = reinterpret_cast<bool(*)(Weapon*)>(0);
	auto BeginCycle = reinterpret_cast<void(*)(Weapon*)>(0);
	auto GetAimCone = reinterpret_cast<float(*)(Weapon*)>(0);
	// O::ViewModel::Play
	auto TryReload = reinterpret_cast<void(*)(DWORD64)>(0);
	auto Vm_Play = reinterpret_cast<void(*)(DWORD64, Str, int)>(0);

	auto DidAttackClientside = reinterpret_cast<void(*)(Weapon*)>(0);
	auto _getjumpheight = reinterpret_cast<float(*)(BasePlayer*)>(0);
	auto get_IsNpc = reinterpret_cast<bool(*)(DWORD64)>(0);
	//auto get_JustCreated = reinterpret_cast<float(*)(BasePlayer*)>(0); // get_JustCreated
	auto _GetRadius = reinterpret_cast<float(*)(BasePlayer*)>(0); //
	auto ServerRPC = reinterpret_cast<void (*)(DWORD64, Str)>(0);
	auto ServerRPC3Arg = reinterpret_cast<void (*)(DWORD64, int, Str, wchar_t*, bool)>(0);

	auto GetHeight = reinterpret_cast<float(*)(BasePlayer*)>(0);
	auto get_iconSprite = reinterpret_cast<DWORD64(*)(BaseProjectile*)>(0);
	auto get_iconSprite1 = reinterpret_cast<DWORD64(*)(Magazine*)>(0);

	
	auto UpdateAmmoDisplay = reinterpret_cast<void(*)(Weapon*)>(0);
	auto ShotFired = reinterpret_cast<void(*)(Weapon*)>(0);
	auto Launchprojectile = reinterpret_cast<void(*)(DWORD64)>(0); // UpdateAmmoDisplay
	auto DoAttack = reinterpret_cast<void(*)(DWORD64)>(0);
	auto BaseMeleeDoAttack = reinterpret_cast<void(*)(DWORD64)>(0);
	auto get_texture = reinterpret_cast<DWORD64(*)(DWORD64)>(0);
	auto CreatePrefab = reinterpret_cast<DWORD64(*)(DWORD64, Str, bool)>(0);
	auto BoundsPadding = reinterpret_cast<float(*)(BasePlayer*)>(0);
	auto StartAttackCooldown = reinterpret_cast<void(*)(Weapon*, float)>(0);
	auto get_mounted = reinterpret_cast<DWORD64(*)(DWORD64)>(0);
	auto get_parent_entity = reinterpret_cast<DWORD64(*)(DWORD64)>(0);
	auto get_short_prefab_name = reinterpret_cast<Str(*)(DWORD64)>(0);
	auto ProcessAttack = reinterpret_cast<void(*)(Weapon*, HitTest*)>(0);
	auto PEyes_get_rotation = reinterpret_cast<Quaternion(*)(DWORD64)>(0);
	auto get_ActiveModel = reinterpret_cast<DWORD64(*)()>(0);
	auto SetColor = reinterpret_cast<void(*)(DWORD64, Str, Color)>(0);
	auto set_shader = reinterpret_cast<void(*)(DWORD64, DWORD64)>(0);
	auto get_shader = reinterpret_cast<DWORD64(*)(DWORD64)>(0);
	auto HasProperty = reinterpret_cast<bool(*)(DWORD64, Str)>(0);
	auto get_material = reinterpret_cast<DWORD64(*)(DWORD64)>(0);
	auto set_material = reinterpret_cast<void(*)(DWORD64, DWORD64)>(0);
	auto get_Renderers = reinterpret_cast<GameList<DWORD64>*(*)(DWORD64)>(0);
	auto get_maxspeed = reinterpret_cast<float(*)(BasePlayer*)>(0);
	auto get_position = reinterpret_cast<Vector3(*)(DWORD64)>(0);
	auto eye_get_position = reinterpret_cast<Vector3(*)(PlayerEyes*)>(0);
	//template<typename T = Component>
	/*T* GetComponent(Type* type) {
		if (!this || !type) return nullptr;
		static auto off = METHOD("UnityEngine.CoreModule::UnityEngine::Component::GetComponent(Type): Component");
		return SafeExecution::Execute<T*>(off, nullptr, this, type);
	}*/

	auto IsOutside = reinterpret_cast<bool (*)(BasePlayer*)>(0);

	auto GetComponent = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(0);
	auto BodyForward = reinterpret_cast<Vector3(*)(PlayerEyes*)>(0);

	auto DDrawText = reinterpret_cast<void(*)(DWORD64, Vector3, Color, float, float)>(0);
	auto get_isHeadshot = reinterpret_cast<bool(*)(DWORD64)>(0);

	auto get_center = reinterpret_cast<Vector3(*)(DWORD64)>(0);
	auto get_component = reinterpret_cast<DWORD64(*)(DWORD64, DWORD64)>(0);
	auto getaspectratio = reinterpret_cast<void (*)(float)>(0);
	auto GetWorldVelocity = reinterpret_cast<Vector3(*)(BasePlayer*)>(0);
	auto GetModifiedAimCone = reinterpret_cast<Vector3(*)(float, Vector3, bool)>(0);
	auto set_position = reinterpret_cast<void(*)(Transform*, Vector3)>(0);
	auto get_trasform_fn = reinterpret_cast<Transform * (*)(void*)>(0);
	auto DDrawLine = reinterpret_cast<void (*)(Vector3, Vector3, Color, float, bool, bool)>(0);
	auto DDrawSphere = reinterpret_cast<void (*)(Vector3, float, Color, float, bool)>(0);
	auto DDrawSphereGizmo = reinterpret_cast<void (*)(Vector3, float, Color, float, bool, bool)>(0);
	//auto GetWorldVelocity = reinterpret_cast<Vector3(*)(BasePlayer *)>(*reinterpret_cast<DWORD64*>(0));
	auto TeleportTo = reinterpret_cast<void(*)(PlayerWalkMovement*, Vector3, BasePlayer*)>(0);
	auto ForcePositionTo = reinterpret_cast<void(*)(BasePlayer*, Vector3)>(0);
	auto Jump = reinterpret_cast<void(*)(PlayerWalkMovement*, ModelState*, bool)>(0);
	auto OnViewModeChanged = reinterpret_cast<void (*)(DWORD64)>(0);
	auto set_capsuleRadius = reinterpret_cast<void(*)(DWORD64, float)>(0);
	auto set_capsuleHeight = reinterpret_cast<void(*)(DWORD64, float)>(0);
	auto get_localToWorldMatrix = reinterpret_cast<Matrix4x4(*)(Transform*)>(0);

	auto set_jumped = reinterpret_cast<void(*)(DWORD64, bool)>(0);

	auto set_rigidbody_velocity = reinterpret_cast<void(*)(DWORD64, Vector3)>(0);

	auto get_rigidbody_velocity = reinterpret_cast<Vector3(*)(DWORD64)>(0);

	auto GetInheritedVelocity = reinterpret_cast<Vector3(*)(Weapon*, BasePlayer*, Vector3)>(0);
	auto CapsuleColliderheight = reinterpret_cast<void(*)(DWORD64, float)>(0);
	auto StrPool = reinterpret_cast<Vector3(*)(DWORD64)>(0);
	auto get_transform = reinterpret_cast<Transform * (*)(BasePlayer*)>(0);
	auto LoadFromMemory_Internal = reinterpret_cast<DWORD64(*)(BYTE*, uint32_t, uint64_t)>(0);

	auto ClosestPoint = reinterpret_cast<Vector3(*)(BasePlayer*, Vector3)>(0);
	// 
	// RVA: 0x25A8A10 Offset: 0x25A7610 VA: 0x1825A8A10
	// public void set_localPosition(Vector3 value) { }
	auto set_localPosition = reinterpret_cast<void  (*)(Transform*, Vector3)>(0);
	auto get_localPosition = reinterpret_cast<Vector3(*)(Transform*)>(0);
	auto FindIconSprite = reinterpret_cast<DWORD64 (*)(DWORD64, int)>(0); // Sprite FindIconSprite(int skinid)
	void InitClasses()
	{
		CapsuleColliderheight = reinterpret_cast<void(*)(DWORD64, float)>((DWORD64)(Il2cpp::Method(_("CapsuleCollider"), _("set_height"), 0, _(""), _("UnityEngine"))));
		LoadFromMemory_Internal = reinterpret_cast<DWORD64(*)(BYTE*, uint32_t, uint64_t)>(Il2cpp::resolve_icall(_("UnityEngine.AssetBundle::LoadFromMemory_Internal()")));
		set_localPosition = reinterpret_cast<void  (*)(Transform*, Vector3)>((DWORD64)(Il2cpp::Method(_("Transform"), _("set_localPosition"), 0, _(""), _("UnityEngine"))));
		get_localPosition = reinterpret_cast<Vector3(*)(Transform*)>((DWORD64)(Il2cpp::Method(_("Transform"), _("get_localPosition"), 0, _(""), _("UnityEngine"))));
		SendClientTick = reinterpret_cast<void(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BasePlayer"), _("SendClientTick"), 0, _(""), _(""))));
		HasParent = reinterpret_cast<bool (*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BaseNetworkable"), _("HasParent"), 0, _(""), _(""))));
		CenterPoint = reinterpret_cast<Vector3(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BaseEntity"), _("CenterPoint"), 0, _(""), _(""))));
		//set_material = reinterpret_cast<void(*)(DWORD64, DWORD64)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Renderer"), _("set_material"), 1, _("value"), _("UnityEngine"), 1)));
		//OnViewModeChanged = reinterpret_cast<void (*)(DWORD64)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BasePlayer"), _("OnViewModeChanged"), 0, _(""), _(""))));
		IsOutside = reinterpret_cast<bool (*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BaseEntity"), _("IsOutside"), 0, _(""), _(""))));
		//ret = reinterpret_cast<Vector3(*)(DWORD64, Vector3)>(g_Base + 0x2521D20);
		Vm_Play = reinterpret_cast<void(*)(DWORD64, Str, int)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("ViewModel"), _("Play"), 2, _(""), _(""))));
		HasProperty = reinterpret_cast<bool(*)(DWORD64, Str)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Material"), _("HasProperty"), 1, _("name"), _("UnityEngine"), 1)));
		SphereCast = reinterpret_cast<bool (*)(Ray, float, float, int, QueryTriggerInteraction)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Physics"), _("SphereCast"), 5, _("queryTriggerInteraction"), _("UnityEngine"))));
		set_atmosphere_rayleigh = reinterpret_cast<void (*)(float)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Weather"), _("set_atmosphere_rayleigh"), 0, _(""), _("ConVar"))));
		Projectile_Launch = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Projectile"), _("Launch"), 0, _(""), _(""))));
		CanAttack = reinterpret_cast<bool (*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("CanAttack"), -1, _(""), _(""))));
		TryReload = reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BowWeapon"), _("TryReload"), -1, _(""), _(""))));
		////HasProperty = reinterpret_cast<bool(*)(Material*, Str)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Material"), _("HasProperty"), 1, _("name"), _("UnityEngine"), 1)));
		DDrawText = reinterpret_cast<void(*)(DWORD64, Vector3, Color, float, float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("DDraw"), _("Text"), 5, _(""), _("UnityEngine"))));
		get_isHeadshot = reinterpret_cast<bool(*)(DWORD64)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("HitInfo"), _("get_isHeadshot"), 0, _(""), _(""))));
		WaterLevelTest = reinterpret_cast<bool(*)(Vector3, bool, BasePlayer*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("WaterLevel"), _("Test"), 3, _(""), _(""))));
		ClosestPoint = reinterpret_cast<Vector3(*)(BasePlayer*, Vector3)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseEntity"), _("ClosestPoint"), 0, _(""), _(""))));
		set_capsuleRadius = reinterpret_cast<void(*)(DWORD64, float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("CapsuleCollider"), _("set_radius"), 0, _(""), _("UnityEngine"))));
		set_capsuleHeight = reinterpret_cast<void(*)(DWORD64, float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("CapsuleCollider"), _("set_height"), 0, _(""), _("UnityEngine"))));
		SendSignal = reinterpret_cast<void(*)(DWORD64, BaseEntity::Signal, Str)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseEntity"), _("SendSignalBroadcast"), 2, _(""), _(""))));
		DoThrow = reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseMelee"), _("DoThrow"), 0, _(""), _(""))));
		GetParentVelocity = reinterpret_cast<Vector3(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BaseEntity"), _("GetParentVelocity"), 0, _(""), _(""))));
		GetMountVelocity = reinterpret_cast<Vector3(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BasePlayer"), _("GetMountVelocity"), 0, _(""), _(""))));
		console_msg = reinterpret_cast<void(*)(uintptr_t, Str)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("BasePlayer"), _("ConsoleMessage"), 0, _(""), _(""))));
		GetComponent = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Component"), _("GetComponent"), 1, _("type"), _("UnityEngine"), 1)));
		SetTimedLootAction = reinterpret_cast<void (*)(DWORD64, DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ItemIcon"), _("SetTimedLootAction"), -1, _(""), _(""))));
		StartTimedLootAction = reinterpret_cast<DWORD64(*)(DWORD64, float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ItemIcon"), _("StartTimedLootAction"), -1, _(""), _(""))));
		Hidden = reinterpret_cast<bool(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("StashContainer"), _("IsHidden"), -1, _(""), _(""))));
		isHidden = reinterpret_cast<bool* (*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("StashContainer"), _("IsHidden"), -1, _(""), _(""))));
		HasAttackCooldown = reinterpret_cast<bool(*)(Weapon*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("AttackEntity"), _("HasAttackCooldown"), -1, _(""), _(""))));
		GetInheritedVelocity = reinterpret_cast<Vector3(*)(Weapon*, BasePlayer*, Vector3)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("AttackEntity"), _("GetInheritedVelocity"), -1, _(""), _(""))));
		DDrawSphereGizmo = reinterpret_cast<void (*)(Vector3, float, Color, float, bool, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("DDraw"), _("SphereGizmo"), 7, _(""), _("UnityEngine"))));
		getContainMaterial = reinterpret_cast<Material * (*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));

		GetAimCone = reinterpret_cast<float(*)(Weapon*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("GetAimCone"), 0, _(""), _(""))));

		BeginCycle = reinterpret_cast<void(*)(Weapon*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("BeginCycle"), 0, _(""), _(""))));
		DidAttackClientside = reinterpret_cast<void(*)(Weapon*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("DidAttackClientside"), 0, _(""), _(""))));
		ShotFired = reinterpret_cast<void(*)(Weapon*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("ShotFired"), 0, _(""), _(""))));
		UpdateAmmoDisplay = reinterpret_cast<void(*)(Weapon*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("UpdateAmmoDisplay"), 0, _(""), _(""))));
		get_mounted = reinterpret_cast<DWORD64(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("GetMounted"), 0, _(""), _(""))));
		get_parent_entity = reinterpret_cast<DWORD64(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseNetworkable"), _("GetParentEntity"), 0, _(""), _(""))));
		get_short_prefab_name = reinterpret_cast<Str(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseNetworkable"), _("get_ShortPrefabName"), 0, _(""), _(""))));
		ServerRPC = reinterpret_cast<void (*)(DWORD64, Str)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));
		ServerRPC3Arg = reinterpret_cast<void (*)(DWORD64, int, Str, wchar_t*, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseEntity"), _("ServerRPC"), 4, _("arg2"), _(""), 4)));
		get_IsNpc = reinterpret_cast<bool(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PlayerModel"), _("get_IsNpc"), -1, _(""), _(""))));
		_getjumpheight = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("GetJumpHeight"), 0, _(""), _(""))));
		ForcePositionTo = reinterpret_cast<void(*)(BasePlayer*, Vector3)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("ForcePositionTo"), 0, _(""), _(""))));
		_GetRadius = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("GetRadius"), 0, _(""), _(""))));
		GetHeight = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("GetHeight"), 0, _(""), _(""))));
		Launchprojectile = reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("LaunchProjectile"), 0, _(""), _(""))));
		DoAttack = reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("DoAttack"), 0, _(""), _(""))));
		BaseMeleeDoAttack = reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseMelee"), _("DoAttack"), 0, _(""), _(""))));
		get_iconSprite = reinterpret_cast<DWORD64(*)(BaseProjectile*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Item"), _("get_iconSprite"), 0, _(""), _(""))));
		get_iconSprite1 = reinterpret_cast<DWORD64(*)(Magazine*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Item"), _("get_iconSprite"), 0, _(""), _(""))));
		FindIconSprite = reinterpret_cast<DWORD64(*)(DWORD64, int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ItemDefinition"), _("FindIconSprite"), 1, _(""), _("")))); // Sprite FindIconSprite(int skinid)

		get_texture = reinterpret_cast<DWORD64(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Sprite"), _("get_texture"), 0, _(""), _("UnityEngine"))));
		PEyes_get_rotation = reinterpret_cast<Quaternion(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PlayerEyes"), _("get_rotation"), 0, _(""), _(""))));
		CreatePrefab = reinterpret_cast<DWORD64(*)(DWORD64, Str, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GameManager"), _("CreatePrefab"), 2, _("active"), _(""))));
		BoundsPadding = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseEntity"), _("BoundsPadding"), 2, _(""), _(""))));
		get_center = reinterpret_cast<Vector3(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PlayerEyes"), _("get_center"), 0, _(""), _(""))));
		Jump = reinterpret_cast<void(*)(PlayerWalkMovement*, ModelState*, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PlayerWalkMovement"), _("Jump"), 2, _(""), _(""))));
		get_transform = reinterpret_cast<Transform * (*)(BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));
		StartAttackCooldown = reinterpret_cast<void(*)(Weapon*, float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("AttackEntity"), _("StartAttackCooldown"), 1, _(""), _(""))));
		ProcessAttack = reinterpret_cast<void(*)(Weapon*, HitTest*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));
	}
	void InitClasses2()
	{
		get_ActiveModel = reinterpret_cast<DWORD64(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseViewModel"), _("get_ActiveModel"), 0, _(""), _(""))));
		GetWorldVelocity = reinterpret_cast<Vector3(*)(BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));
		SetColor = reinterpret_cast<void(*)(DWORD64, Str, Color)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Material"), _("SetColor"), 2, _("name"), _("UnityEngine"), 1)));
		set_shader = reinterpret_cast<void(*)(DWORD64, DWORD64)>(Il2cpp::resolve_icall(_("UnityEngine.Material::set_shader()")));
		get_shader = reinterpret_cast<DWORD64(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Material"), _("get_shader"), 0, _(""), _("UnityEngine"))));
		get_material = reinterpret_cast<DWORD64(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));
		get_Renderers = reinterpret_cast<GameList<DWORD64> *(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("SkinnedMultiMesh"), _("get_Renderers"), 0, _(""), _(""))));


		BodyForward = reinterpret_cast<Vector3(*)(PlayerEyes*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PlayerEyes"), _("BodyForward"), 0, _(""), _(""))));
		eye_get_position = reinterpret_cast<Vector3(*)(PlayerEyes*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PlayerEyes"), _("get_position"), 0, _(""), _(""))));
		set_rigidbody_velocity = reinterpret_cast<void(*)(DWORD64, Vector3)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Rigidbody"), _("set_velocity"), 0, _(""), _("UnityEngine"))));
		get_rigidbody_velocity = reinterpret_cast<Vector3(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Rigidbody"), _("get_velocity"), 0, _(""), _("UnityEngine"))));
		set_jumped = reinterpret_cast<void(*)(DWORD64, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ModelState"), _("set_jumped"), 0, _(""), _(""))));
		get_localToWorldMatrix = reinterpret_cast<Matrix4x4(*)(Transform*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Transform"), _("get_localToWorldMatrix"), 0, _(""), _("UnityEngine"))));
		TeleportTo = reinterpret_cast<void(*)(PlayerWalkMovement*, Vector3, BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseMovement"), _("TeleportTo"), 2, _(""), _(""))));
		DDrawSphere = reinterpret_cast<void (*)(Vector3, float, Color, float, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("DDraw"), _("Sphere"), 5, _(""), _("UnityEngine"))));
		DDrawLine = reinterpret_cast<void (*)(Vector3, Vector3, Color, float, bool, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));
		get_maxspeed = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("GetMaxSpeed"), 0, _(""), _(""))));
		get_trasform_fn = reinterpret_cast<Transform * (*)(void*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Component"), _("get_transform"), -1, _(""), _("UnityEngine"))));
		//GetWorldVelocity = reinterpret_cast<Vector3(*)(BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));
		GetModifiedAimCone = reinterpret_cast<Vector3(*)(float, Vector3, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("AimConeUtil"), _("GetModifiedAimConeDirection"), 0, _(""), _(""))));
		get_component = reinterpret_cast<DWORD64(*)(DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Component"), _("GetComponent"), 0, _(""), _("UnityEngine"))));
		getaspectratio = reinterpret_cast<void (*)(float)>(Il2cpp::resolve_icall(_("UnityEngine.Camera::set_aspect()")));
		set_position = reinterpret_cast<void(*)(Transform*, Vector3)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Transform"), _("set_position"), 1, _(""), _("UnityEngine"))));
		get_position = reinterpret_cast<Vector3(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Transform"), _("get_position"), 0, _(""), _("UnityEngine"))));
	}


}

bool WorldToScreen(const Vector3& EntityPos, Vector2& ScreenPos)
{
	if (!pViewMatrix) return false;
	Vector3 TransVec = Vector3(pViewMatrix->_14, pViewMatrix->_24, pViewMatrix->_34);
	Vector3 RightVec = Vector3(pViewMatrix->_11, pViewMatrix->_21, pViewMatrix->_31);
	Vector3 UpVec = Vector3(pViewMatrix->_12, pViewMatrix->_22, pViewMatrix->_32);
	float w = Maths::Dot(TransVec, EntityPos) + pViewMatrix->_44;
	if (w < 0.098f) return false;
	float y = Maths::Dot(UpVec, EntityPos) + pViewMatrix->_42;
	float x = Maths::Dot(RightVec, EntityPos) + pViewMatrix->_41;
	float xs = Vars::ScreenWidth / 2, ys = Vars::ScreenHeight / 2;
	ScreenPos = Vector2((xs) * (1.f + x / w), (ys) * (1.f - y / w));
	return true;
}

float GetFovBom(Vector2 Pos) {
	return Maths::Calc2D_Dist(Vector2(Unity::get_width() / 2, Unity::get_height() / 2), Pos);
}

float GetFov(Vector3 Pos) {

	Vector2 ScreenPos;
	if (!WorldToScreen(Pos, ScreenPos)) return 1000.f;
	return GetFovBom(ScreenPos);
}

class Object {
public:
	Str* name()
	{
		// public class Object // TypeDefIndex: 10323
		auto get_name = reinterpret_cast<Str * (*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Object"), _("get_name"), 0, _(""), _("UnityEngine"))));
		return get_name((DWORD64)this);
	}

	char* ClassName() {
		auto bp = *reinterpret_cast<DWORD64*>(this);
		if (IsValidPointer(bp))
			return (char*)Read<DWORD64>(bp + 0x10);
	}

	const char* charname()
	{
		// public class Object // TypeDefIndex: 10323
		auto get_name = reinterpret_cast<const char* (*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Object"), _("get_name"), 0, _(""), _("UnityEngine"))));
		return get_name((DWORD64)this);
	}

	const wchar_t* GetName()
	{
		// public class Object // TypeDefIndex: 10323
		auto get_name = reinterpret_cast<const wchar_t* (*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Object"), _("get_name"), 0, _(""), _("UnityEngine"))));
		return get_name((DWORD64)this);
	}
};
class Material : public Object
{
public:
	// public bool HasProperty(string name) { }

};

class Component : public Object {
public:
	Transform* get_transform() {
		if (!this || !IsValidCheck(this)) {
			//EspObjects[i] = 0;
			return 0;
		}
		return Classes::get_trasform_fn(this);
	}
};

class Behaviour : public Component {

};

class FacepunchBehaviour : public Behaviour {

};

class BaseMonoBehaviour : public FacepunchBehaviour {

};

class Transform : public Component
{
public:

	Vector3 Position()
	{
		if (!this) return Vector3::Zero();
		return Classes::get_position((DWORD64)this);
	}

	void SetBonePos(Vector3 d) {

		if (!(DWORD64)this) return;
		Classes::set_position(this, d);
		// return Classes::set_position(this, d);
	}

	Transform* get_parent()
	{
		if (!this) return nullptr;
		return reinterpret_cast<Transform * (*)(Transform*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Transform"), _("get_parent"), 0, _(""), _("UnityEngine"))))(this);// Read<Transform * (*)(Transform*)>(g_Base + Dump::UnityEngine_Transform::get_parent)(this);
	}

};
int ScannedBone = 47;
Vector3 BoneScanPos = Vector3::Zero();
BasePlayer* LocalPlayer = NULL;
AimTarget Target;
AimTarget FindCurTarget;
BasePlayer* lastTarget = NULL;




class PlayerInventory
{
public:
	

	int GetUID() {
		return safe_read(this + Dump::Item::uid, int);
	}

	const wchar_t* get_clothes_name() {
		if (!this) return 0;
		auto item_def = Read<DWORD64>((DWORD64)this + Dump::Item::info);
		if (!item_def)
			return {};

		auto display_name = Read<DWORD64>(item_def + Dump::ItemDefinition::displayName);
		if (!display_name)
			return {};

		auto weapon_name = (pUncStr)(Read<DWORD64>(display_name + 0x18));

		return weapon_name->str;
	}

};

class BaseProjectile {
public:

	char* ClassName() { return (char*)safe_read(safe_read(safe_read(this + Dump::Item::heldEntity, DWORD64), DWORD64) + 0x10, DWORD64); }

	bool IsWeapon() {
		const auto item_definition = Read<DWORD64>((DWORD64)this + O::Item::info);
		if (!item_definition)
			return false;

		return Read<uint32_t>(item_definition + O::ItemDefinition::category) == 0;
	}

	void CurrentVelocity(Vector3 position) {
		Write<Vector3>((DWORD64)this + O::Projectile::currentVelocity, position);
	}

	void initialVelocity(Vector3 position) {
		Write<Vector3>((DWORD64)this + O::Projectile::initialVelocity, position);
	}

	ItemModProj* ItemModProjectile() {
		return *reinterpret_cast<ItemModProj**>((uintptr_t)this + O::Projectile::mod);
	}

	Vector3 CurrentPosition() {
		return Read<Vector3>((DWORD64)this + O::Projectile::currentPosition);
	}
	void CurrentPosition(Vector3 position) {
		Write<Vector3>((DWORD64)this + O::Projectile::currentPosition, position);
	}

	Vector3 prevPosition() {
		return Read<Vector3>((DWORD64)this + O::Projectile::previousPosition);
	}
	void prevPosition(Vector3 position) {
		Write<Vector3>((DWORD64)this + O::Projectile::previousPosition, position);
	}

	float InitialDistance() {
		return Read<float>((DWORD64)this + O::Projectile::initialDistance);
	}
	void InitialDistance(float d) {
		Write<float>((DWORD64)this + O::Projectile::initialDistance, d);
	}


	const wchar_t* GetWeaponName() {
		if (!this) return 0;
		auto item_def = Read<DWORD64>((DWORD64)this + Dump::Item::info);
		if (!item_def)
			return {};

		auto display_name = Read<DWORD64>(item_def + Dump::ItemDefinition::displayName);
		if (!display_name)
			return {};

		auto weapon_name = (pUncStr)(Read<DWORD64>(display_name + 0x18));

		return weapon_name->str;
	}

	int GetUID() {
		return safe_read(this + Dump::Item::uid, int);
	}

	int LoadedAmmo() {
		UINT64 Held = safe_read((UINT64)this + Dump::Item::heldEntity, UINT64);
		if (Held <= 0) return 0;
		UINT64 Magazine = safe_read(Held + Dump::BaseProjectile::primaryMagazine, UINT64);
		if (Magazine <= 0 || Magazine == 0x3F000000) {
			return 0;
		}
		UINT64 ammoType = safe_read(Magazine + 0x20, UINT64); //BaseProjectile.Magazine!
		if (ammoType <= 0 || ammoType == 0x3F000000) {
			return 0;
		}
		int ammo = safe_read(ammoType + Dump::ItemDefinition::itemid, int);
		return ammo;
	}

	UINT64 GetAmmoType() {
		UINT64 Held = safe_read((UINT64)this + Dump::Item::heldEntity, UINT64);
		if (Held <= 0) return 0;
		UINT64 Magazine = safe_read(Held + Dump::BaseProjectile::primaryMagazine, UINT64);
		if (Magazine <= 0 || Magazine == 0x3F000000) {
			return 0;
		}
		UINT64 ammoType = safe_read(Magazine + 0x20, UINT64); //BaseProjectile.Magazine!
		if (ammoType <= 0 || ammoType == 0x3F000000) {
			return 0;
		}

		return ammoType;
	}

	int GetID() {
		UINT64 Info = safe_read((UINT64)this + Dump::Item::info, UINT64);
		int ID = safe_read(Info + Dump::ItemDefinition::itemid, int);
		return ID;
	} // amount

	int GetAmount() {
		if (!this) return 0;
		return safe_read((UINT64)this + O::Item::amount, int);
	} // amount

	Transform* GetTransform() {
		if (!this) return nullptr;
		return Classes::get_trasform_fn(this);
	}

	uint32_t Size() { return Read<uint32_t>((DWORD64)this + 0x18); }

	Weapon* HeldEntity() {
		if (!this) return {};
		return Read<Weapon*>((DWORD64)this + Dump::Item::heldEntity);
	}

	UINT64 GetItemID() {
		if (!this)
			return -1;

		UINT64 Held = safe_read((UINT64)this + Dump::Item::heldEntity, UINT64);
		if (Held <= 0)
			return -1;

		uintptr_t item_definition = safe_read(Held + O::Item::info, uintptr_t);
		if (!item_definition)
			return -1;

		UINT64 itemID = safe_read(item_definition + O::ItemDefinition::itemid, UINT64);
		return itemID;
	}

	ItemModProj* GetItemModPr() {
		return Read<ItemModProj*>((DWORD64)this + O::Projectile::mod);
	}





};


class Magazine
{
public:
	UINT_PTR Base_ = 0;

	Magazine(UINT_PTR base)
	{
		Base_ = base;
	} // 0x1c

	int contents()
	{
		return Read<int>((DWORD64)this + 0x1C);
	}
	/*int& contents2()
	{
		return Read<int&>((DWORD64)this + 0x1C);
	}*/
	int& contents2()
	{
		int& ptr = *(int*)(this + 0x1C);
		return ptr;
	}
	int capacity()
	{
		return Read<int>((DWORD64)this + 0x18);
	}
	UINT_PTR ammoType()
	{
		return *(UINT_PTR*)(this->Base_ + 0x18);
	}
};
class PlayerModel {
public:
	Vector3 ModelPosition()
	{
		return Read<Vector3>((DWORD64)this + O::PlayerModel::position);
	}
};

class HeldEntity {
public:

};
float GLOBAL_TIME = 0.f;
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Planner : public HeldEntity {
public:
	Vector3 RotationOffset() { return Read<Vector3>((DWORD64)this + Dump::Planner::planner_rotationoffset); }
	void RotationOffset(Vector3 o) { Write((DWORD64)this + Dump::Planner::planner_rotationoffset, o); }
	DWORD64 CurrentConstruction() { return Read<DWORD64>((DWORD64)this + Dump::Planner::planner_currentconstruction); }
	void CurrentConstruction(DWORD64 o) { Write((DWORD64)this + Dump::Planner::planner_currentconstruction, o); }
	DWORD64 Guide() { return Read<DWORD64>((DWORD64)this + Dump::Planner::planner_guide); }
};
class Weapon {
public:

	Magazine* primaryMagazine()
	{
		return Read<Magazine*>((DWORD64)this + O::BaseProjectile::primaryMagazine);
	}
	char* ClassName() {
		auto bp = *reinterpret_cast<DWORD64*>(this);
		if (IsValidPointer(bp))
			return (char*)Read<DWORD64>(bp + 0x10);
	}

	bool isDeployed()
	{
		return safe_read((DWORD64)this + 0x10, bool);;
	}

	void MeleeHitDistance(float d)
	{
		if (!this) return;

		safe_write(this + O::BaseMelee::maxDistance, Vars::Weapon::MeleeRadius, float);
		safe_write(this + O::BaseMelee::attackRadius, Vars::Weapon::MeleeRadius, float);

		safe_write(this + O::BaseMelee::blockSprintOnAttack, false, bool);
		safe_write(this + O::BaseMelee::onlyThrowAsProjectile, false, bool);//0x27A
		safe_write(this + O::BaseMelee::isAutomatic, true, bool);
		safe_write(this + O::BaseMelee::throwReady, true, bool);

	}
	

	float CalculateCooldownTime(float nextTime, float cooldown) {
		float num = Unity::get_time();
		float num2 = 0.f;

		float ret = nextTime;

		if (ret < 0.f) {
			ret = max(0.f, num + cooldown - num2);
		}
		else if (num - ret <= num2) {
			ret = min(ret + cooldown, num + cooldown);
		}
		else {
			ret = max(ret + cooldown, num + cooldown - num2);
		}
		return ret;
	}


	int32_t get_definition_id()
	{
		uintptr_t item_info = 0;
		if (!item_info)
			item_info = Il2cpp::GetOffset(_("Item"), _("info"));
		const auto item_definition = *reinterpret_cast<uintptr_t*>((uintptr_t)this + item_info);
		if (!item_definition)
			return 0;

		return *reinterpret_cast<int32_t*>(item_definition + 0x18);
	}
	
		int GetID() {
		UINT64 Info = safe_read((UINT64)this + Dump::Item::info, UINT64);
		int ID = safe_read(Info + Dump::ItemDefinition::itemid, int);
		return ID;
	} // am

		int Prefab_id() {
			UINT64 ID = safe_read((UINT64)this + O::BaseNetworkable::prefabID, UINT64);
			return ID;
		} // am

	void LaunchProjectile(bool instakill = false)
	{
		if (!this) return;

		if (instakill) {

			auto HeldEntity = (Weapon*)this;
			auto m = HeldEntity->RepeatDelay() * 0.75f;

			int r = Vars::Exploits::DesyncTime / m;

			float NextShot = Vars::Exploits::AutoShootTimeSinceLastShot + HeldEntity->RepeatDelay() + 0.2;
			if (Unity::get_fixedTime() > NextShot) {
				if (r > 1)
				{
					for (size_t i = 0; i <= r; i++)
					{
						DWORD64 magazine = safe_read(HeldEntity + O::BaseProjectile::primaryMagazine, DWORD64);
						int contents = safe_read(magazine + 0x1C, int); //BaseProjectile.Magazine!

						if (contents <= 0) {
							return;
						}

						auto viewModel = Read<DWORD64>((DWORD64)HeldEntity + O::HeldEntity::viewModel);
						if (viewModel && !Vars::Exploits::AutoShootType[0])
						{
							Classes::Vm_Play(viewModel, _(L"attack"), 0);
						}
						if (!Vars::Exploits::AutoShootType[1])
						{
							Classes::SendSignal((DWORD64)HeldEntity, BaseEntity::Signal::Attack, _(L""));
						}

						safe_write(magazine + 0x1C, contents - 1, int);

						float kd = safe_read(HeldEntity + O::AttackEntity::repeatDelay, float);

						//Classes::StartAttackCooldown(HeldEntity, kd + 0.02);

						Classes::Launchprojectile((DWORD64)this);

						Classes::TryReload((DWORD64)HeldEntity);
						Classes::UpdateAmmoDisplay(HeldEntity);
						Classes::DidAttackClientside(HeldEntity);

						if (i >= r - 1) Vars::Exploits::AutoShootTimeSinceLastShot = Unity::get_fixedTime();
					}
					return;
				}
			}
		}

		else Classes::Launchprojectile((DWORD64)this);
	}
	void DoAttack() {
		if (!this) return;
		// reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("DoAttack"), -1, _(""), _(""))));
		auto off = reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("DryFire"), -1, _(""), _(""))));
		return off((DWORD64)this);
	}
	/*void DoAttack()
	{
		if (!this) return;
		return Classes::DoAttack((DWORD64)this);
	}*/
	/*void UpdateAmmoDisplay()
	{
		if (!this) return;
		Classes::UpdateAmmoDisplay((DWORD64)this);
	}*/
	float& projectileVelocityScale()
	{
		return *reinterpret_cast<float*>((DWORD64)this + Dump::BaseProjectile::projectileVelocityScale);
	}

	float GetFovOverride() {
		if (!this) return 1337.f;

		return reinterpret_cast<float(*)(DWORD64)>((DWORD64)(g_Base + offsets::GetFovOverride))((DWORD64)this);
	}

	void InstaEoka()
	{
		if (Vars::Weapon::InstaEoka)
		{
			if (!this) return;
			Write<bool>((uint64_t)this + O::BowWeapon::wasAiming, true);
			Write<float>((uint64_t)this + O::BowWeapon::attackReady, 1.f);
		}
	}

	void RemoveBurst()
	{
		if (!this) return; safe_write(this + Dump::BaseProjectile::currentBurst, 0, int);
	}

	float RepeatDelay() {
		return Read<float>((DWORD64)this + O::AttackEntity::repeatDelay);
	} // timeSinceDeploy

	float timeSinceDeploy() {
		return Read<float>((DWORD64)this + O::AttackEntity::timeSinceDeploy);
	} // timeSinceDeploy

	void RepeatDelay(float val)
	{
		if (!this) return; Write<float>((DWORD64)this + 0x1FC, val);
	}
	bool& Automatic() {
		return *reinterpret_cast<bool*>((uintptr_t)this + O::BaseProjectile::automatic) = true;
	}
	float NextAttackTime() {
		return Read<float>((DWORD64)this + O::AttackEntity::nextAttackTime);
	}
	void NextAttackTime(float& val)
	{
		Write<float>((DWORD64)this + O::AttackEntity::nextAttackTime, val);
	}
	float TimeSinceDeploy() {
		return Read<float>((DWORD64)this + O::AttackEntity::timeSinceDeploy);
	}//0x25c

	float DeployDelay() {
		return Read<float>((DWORD64)this + O::AttackEntity::deployDelay);
	} //0x1f8
	DWORD64 DamageProperties() {
		return Read<DWORD64>((DWORD64)this + O::HitTest::damageProperties);
	}
	DWORD64 IfClothings()
	{
		if (!this)
			return 0;

		auto viewModel = Read<DWORD64*>((DWORD64)this + O::HeldEntity::viewModel);
		if (!viewModel)
			return 0;
		auto baseViewModel = *(DWORD64*)(viewModel + O::ViewModel::instance);
		if (!baseViewModel)
			return 0;

		auto clothings = *(DWORD64*)(baseViewModel + O::BaseViewModel::Clothing);
		return clothings;
	}

	float nextReloadTime() {
		return Read<float>((DWORD64)this + O::BaseProjectile::nextReloadTime);
	}
	float reloadTime() {
		return Read<float>((DWORD64)this + O::BaseProjectile::reloadTime);

	}
	bool HasReloadCooldown() {
		return Unity::get_time() < this->nextReloadTime();
	}

	void NoDeployDelay()
	{
		if (!this)
			return;
		*(float*)((DWORD64)this + O::AttackEntity::deployDelay) = 0;
		*(float*)((DWORD64)this + O::AttackEntity::animationDelay) = 0;
	}

	void changeHandsPosition()
	{
		if (!this)
			return;

		DWORD64 viewModel = Read<DWORD64>((DWORD64)this + O::HeldEntity::viewModel);
		if (!viewModel)
			return;
		DWORD64 baseViewModel = Read<DWORD64>(viewModel + O::ViewModel::instance);
		if (!baseViewModel)
			return;

		DWORD64 ViewmodelAspectOffset = Read<DWORD64>(baseViewModel + O::BaseViewModel::aspectOffset);

		Write<Vector3>(ViewmodelAspectOffset + 0x18, Vector3(HandsX, HandsY, HandsZ));
		// Write<float>(ViewmodelAspectOffset + 0x24, 1);
	}

	void WeaponAnimations()
	{
		if (!this)
			return;

		auto viewModel = Read<DWORD64>((DWORD64)this + O::HeldEntity::viewModel);
		if (!viewModel)
			return;
		auto baseViewModel = *(DWORD64*)(viewModel + O::ViewModel::instance);
		if (!baseViewModel)
			return;

		if (Vars::Weapon::NoBob)
		{
			auto bob = *(DWORD64*)(baseViewModel + O::BaseViewModel::bob);
			if (!bob)
				return;
			*(float*)(bob + 0x20) = 0.f;
			*(float*)(bob + 0x24) = 0.f;
			*(float*)(bob + 0x28) = 0.f;
			*(float*)(bob + 0x2c) = 0.f;
			*(float*)(bob + 0x30) = 0.f;
		}

		if (Vars::Weapon::NoSway) // 0x70
		{
			auto sway = *(DWORD64*)(baseViewModel + O::BaseViewModel::sway);
			if (!sway)
				return;
			*(float*)(sway + 0x18) = 0.f;
			*(float*)(sway + 0x1c) = 0.f;
			*(float*)(sway + 0x20) = 0.f;
			*(float*)(sway + 0x24) = 0.f;
			*(float*)(sway + 0x58) = 0.f;
		}

		if (Vars::Weapon::NoSpread)
		{
			auto punch = *(DWORD64*)(baseViewModel + O::BaseViewModel::punch);//136
			if (!punch)
				return;

			*(float*)(punch + 0x2c) = 0.f;
			*(float*)(punch + 0x30) = 0.f;
			*(float*)(punch + 0x34) = 0.f;
		}

		if (Vars::Weapon::NoLower)
		{
			auto lower = *(DWORD64*)(baseViewModel + O::BaseViewModel::lower);
			if (!lower)
				return;
			*(float*)(lower + 0x1c) = 0.f;
		}

		if (Vars::Weapon::NoAnimation)
			*(DWORD64*)(baseViewModel + O::BaseViewModel::animator) = 0;
	}
};

class RecoilProperties
{
public:
	float recoilYawMin()
	{
		return safe_read((DWORD64)this + O::RecoilProperties::recoilYawMin, float);
	}
	void recoilYawMin(float r)
	{
		safe_write((DWORD64)this + O::RecoilProperties::recoilYawMin, r, float)
	}
	float recoilYawMax()
	{
		return safe_read((DWORD64)this + O::RecoilProperties::recoilYawMax, float);
	}
	void recoilYawMax(float r)
	{
		safe_write((DWORD64)this + O::RecoilProperties::recoilYawMax, r, float)
	}
	float recoilPitchMin()
	{
		return safe_read((DWORD64)this + O::RecoilProperties::recoilPitchMin, float);
	}
	void recoilPitchMin(float r)
	{
		safe_write((DWORD64)this + O::RecoilProperties::recoilPitchMin, r, float)
	}
	float recoilPitchMax()
	{
		return safe_read((DWORD64)this + O::RecoilProperties::recoilPitchMax, float);
	}
	void recoilPitchMax(float r)
	{
		safe_write((DWORD64)this + O::RecoilProperties::recoilPitchMax, r, float)
	}
};

class PlayerEyes : public Transform
{ // BodyForward
public:
	Vector3 EyePosition()
	{
		if (!(DWORD64)this)
			return {};

		return Classes::eye_get_position((PlayerEyes*)this);
	}

	Vector3 BodyForward()
	{
		if (!(DWORD64)this)
			return {};

		return Classes::BodyForward((PlayerEyes*)this);
	}

	Vector3 GetCenter() {
		if (!this) return Vector3(0, 0, 0);
		auto center = Classes::get_center((DWORD64)this);
		return center;
	}

	Quaternion Rotation() {
		//if (!this) return Vector4(0, 0, 0, 0);
		return Classes::PEyes_get_rotation((DWORD64)this);
		/*typedef Quaternion(__stdcall* get_rotation)(PlayerEyes*);
		Quaternion result = ((get_rotation)(mem::game_assembly_base + O::PlayerEyes::get_rotation))(this);
		return result;*/
	}
};

//BasePlayer* TargetHeli = NULL;

class PlayerTick {
public:
	Vector3 position()
	{
		if (!this) return Vector3::Zero();
		return Read<Vector3>((DWORD64)this + 0x18);
	}
};

class Networkable {
public:
	unsigned int GetID() {
		return Read<unsigned int>((DWORD64)this + 0x10);
	}

};
// get_isHeadshot
class BaseMountable {
public:
	bool CanwieldItem(bool b) {
		return *reinterpret_cast<bool*>((uintptr_t)this + O::BaseMountable::canWieldItems) = b;
	}
};



enum class Button : int {
	FORWARD = 2,
	BACKWARD = 4,
	LEFT = 8,
	RIGHT = 16,
	JUMP = 32,
	DUCK = 64,
	SPRINT = 128,
	USE = 256,
	FIRE_PRIMARY = 1024,
	FIRE_SECONDARY = 2048,
	RELOAD = 8192,
	FIRE_THIRD = 134217728
};

class BasePlayer : public Component
{
public:

	UINT_PTR Base_ = 0;

	bool GetKeyState(Button b) {
		DWORD64 InputState = safe_read(safe_read(this + O::BasePlayer::input, DWORD64) + O::PlayerInput::state, DWORD64);
		DWORD64 Cur = safe_read(InputState + O::InputState::current, DWORD64);
		if (!Cur) return false;
		int btn = safe_read(Cur + O::InputMessage::buttons, int);
		return ((btn & (int)b) == (int)b);
	}

	bool CanAttack()
	{
		return Classes::CanAttack((DWORD64)this) == true;
	}

	wchar_t* GetName() {
		if (!this) return _(L"");
		pUncStr name = (pUncStr)safe_read(this + O::BasePlayer::_displayName, DWORD64);
		if (name)
		{
			wchar_t* end = name->str;
			if (end)
			{
				return end;
			}
		}
		return _(L"");
	}

	

	bool IsValid() {
		bool res = true;

		if (!safe_read(this + O::BaseNetworkable::net, DWORD64)) res = false;
		if (res) {
			if (IsDead()) res = false;
		}
		return res;
	}

	void SendProjectileUpdate(DWORD64 update)
	{
		typedef float(__stdcall* spu)(DWORD64, DWORD64);
		((spu)(g_Base + offsets::o_SendProjectileUpdate))((DWORD64)this, update);
	}

	void SendProjectileAttack(DWORD64 update)
	{
		typedef float(__stdcall* spu)(DWORD64, DWORD64);
		((spu)(g_Base + offsets::o_SendProjectileAttack))((DWORD64)this, update);
	}

	float GetRadius()
	{
		if (!this) return 0.0f;
		return Classes::_GetRadius(this);
		//return 0.5f;
	}

	void ConsoleMsg(const wchar_t* str) {
		//string::format(("%s %d"), _("B:"), (int)vars->visual.VisBcolor))
		//auto s = string::wformat(_(L"trap [%d]: %s"), (int)get_fixedTime(), str);
		Classes::console_msg((uintptr_t)this, str);
	}

	float GetHeight(bool ducked)
	{
		if (!this) return 0.0f;
		return Classes::GetHeight(this);

		//return 1.8f;
	}

	float GetJumpHeight()
	{
		if (!this) return 0.0f;
		return Classes::_getjumpheight(this);
		//return 1.5f;
	}

	BasePlayer rInventory()
	{

		return safe_read(this + O::BasePlayer::inventory, BasePlayer);
	}


	float BoundsPadding() {
		if (!this) return 0;
		return Classes::BoundsPadding(this);
	}

	void SetVA(const Vector2& VA) {
		DWORD64 Input = safe_read(this + Dump::BasePlayer::input, DWORD64);
		safe_write(Input + O::PlayerInput::bodyAngles, VA, Vector2);
	}
	Vector2 GetVA() {
		DWORD64 Input = safe_read(this + Dump::BasePlayer::input, DWORD64);
		return safe_read(Input + O::PlayerInput::bodyAngles, Vector2);
	}

	PlayerTick* lastSentTick() {
		return (PlayerTick*)Read<DWORD64*>((DWORD64)this + Dump::BasePlayer::lastSentTick);
	}

	Vector2 GetRA()
	{
		DWORD64 Input = safe_read((DWORD64)this + Dump::BasePlayer::input, DWORD64);
		return safe_read(Input + 0x64, Vector2);
	}
	//*** base entity info ***//
	float GetHealth() {
		if (!this) return 0;
		return safe_read(this + O::BaseCombatEntity::_health, float);
	}

	float GetMaxHealth() {
		if (!this) return 0;
		return safe_read(this + O::BaseCombatEntity::_maxHealth, float);
	} // 

	Vector3 GetVelocity() {
		ULONG64 PlayerModel = safe_read(this + O::BasePlayer::playerModel, ULONG64);
		return safe_read(PlayerModel + O::PlayerModel::newVelocity, Vector3);
	}

	float GetMaxSpeed()
	{
		if (!this) return 0;
		return Classes::get_maxspeed(this);
	}

	ModelState* GetModelState() {
		if (!this) return 0;
		return Read<ModelState*>((DWORD64)this + Dump::BasePlayer::modelState);
	}

	BaseMountable* Mountable() {
		if (!this) return 0;
		return Read<BaseMountable*>((DWORD64)this + O::BasePlayer::mounted);
	}

	PlayerModel* GetPlayerModel() {
		if (!this) return 0;
		return Read<PlayerModel*>((DWORD64)this + O::BasePlayer::playerModel);
	}
	Vector3 GetParentVelocity() {
		if (!this) return Vector3(0, 0, 0);
		return Classes::GetParentVelocity(this);
	}
	Vector3 GetMountVelocity() {
		if (!this) return Vector3(0, 0, 0);
		return Classes::GetMountVelocity(this);
	}
	auto lastSentTickTime() {
		//if (!this) return 0;
		return Read<float>((DWORD64)this + Dump::BasePlayer::lastSentTickTime);
	}
	void ClientTickInterval(float tick) {
		if (!this) return;
		Write<float>((DWORD64)this + O::BasePlayer::clientTickInterval, tick);
	}

	void SetFlag(int Flg) {
		int PlayerFlag = Read<int>((uintptr_t)this + O::BasePlayer::playerFlags);
		Write<int>((uintptr_t)this + O::BasePlayer::playerFlags, PlayerFlag |= (int)Flg);
	}

	bool HasFlags(int Flg) {
		return (Read<int>((DWORD64)this + O::BasePlayer::playerFlags) & Flg);
	}

	bool IsSleeping() { return HasFlags(16); }
	bool IsWounded() { return HasFlags(64); }
	bool IsMounted() { return HasFlags(64); }
	bool IsInSafeZone() { return HasFlags(131072); }
	bool IsW1() { return HasFlags(1048576); }
	bool IsW2() { return HasFlags(2097152); }
	bool IsW3() { return HasFlags(4194304); }
	// public class PlayerTeam : IDisposable, Pool.IPooled, IProto // TypeDefIndex: 9604

	DWORD64 GetTeammateByPos(int Id) {
		DWORD64 ClientTeam = safe_read(this + O::BasePlayer::clientTeam, DWORD64);
		DWORD64 members = safe_read(ClientTeam + 0x28, DWORD64);
		DWORD64 List222 = safe_read(members + 0x10, DWORD64);
		DWORD64 player = safe_read(List222 + 0x20 + (Id * 0x8), DWORD64);
		return safe_read(player + 0x18, DWORD64);
	}
	bool IsTeamMate(BasePlayer* Player)
	{
		ULONG64 ClientTeam = safe_read(Player + O::BasePlayer::clientTeam, ULONG64);
		ULONG64 members = safe_read(ClientTeam + O::ProtoBuf_PlayerTeam::members, ULONG64);
		int size = safe_read(members + 0x18, int);
		ULONG64 List212 = safe_read(members + 0x10, ULONG64);

		DWORD64 Search = this->GetSteamID();
		for (int i = 0; i < size; i++) {
			ULONG64 player = safe_read(List212 + 0x20 + (i * 0x8), ULONG64);
			DWORD64 id = safe_read(player + 0x18, ULONG64);
			if (id == Search) return true;
		}
		return false;
	}



	DWORD64 WeakSpots() {
		return Read<DWORD64>((DWORD64)this + Dump::BaseHelicopter::weakspots);
	}

	bool IsDead() {
		if (!this)
			return 0;
		const auto life_state = Read<uint32_t>((uintptr_t)this + O::BaseCombatEntity::lifestate);
		return life_state == 0;
	}

	PlayerWalkMovement* GetMovement() {
		return Read<PlayerWalkMovement*>((DWORD64)this + Dump::BasePlayer::movement);
	}

	DWORD64 GetSteamID() {
		return safe_read(this + O::BasePlayer::userID, DWORD64);
	}

	uint64_t& userID() {
		return *reinterpret_cast<uint64_t*>(this + 0x20);
	}

	ULONG64 TeamID() {
		return safe_read(this + 0x630, ULONG64);
		/*auto clientTeam = safe_read(this + O::BasePlayer::clientTeam, ULONG64);
		return safe_read(clientTeam + 0x10, ULONG64);*/
	}

	Str* TeamName() {
		auto clientTeam = safe_read(this + O::BasePlayer::clientTeam, DWORD64);
		return Read<Str*>(clientTeam + 0x18);
	}


	//*** localplayer ***//

	PlayerEyes* GetEyes()
	{
		if (!this) return 0;
		return Read<PlayerEyes*>((DWORD64)this + O::BasePlayer::eyes);
	}

	void SendClientTick() {
		if (!this) return;
		reinterpret_cast<void(*)(BasePlayer*)>((DWORD64)(g_Base + offsets::SendClientTickk))(this);
	}

	Vector3 ManipPoint()
	{
		/*if (!this) return Vector3::Zero();

		return Vector3(Target.Pos.x, Target.Pos.y - 0.26, Target.Pos.z);*/

		if (!this) return Vector3::Zero();

		/*if (targetpos == Vector3::Zero())
			return Vector3(Target.Pos.x, Target.Pos.y - 0.31, Target.Pos.z);
		else
			return Vector3(targetpos.x, targetpos.y - 0.31, targetpos.z);*/
		//PlayerWalkMovement* movement = Target.Cur->GetMovement();
		//// float capsuleHeight = safe_read((DWORD64)g_Base + O::PlayerWalkMovement::capsuleHeight, float);
		//Vector3 capsuleCenter = safe_read((DWORD64)movement + O::PlayerWalkMovement::capsuleCenter, Vector3);
		//// capsuleHeight
		return Vector3(Target.Pos.x, Target.Pos.y - 0.31, Target.Pos.z);
		//return Target.Cur->lastSentTick()->position() + Vector3(0, 1.5, 0);
		// return Vector3::Zero();
	}

	BaseProjectile* GetActiveWeapon() {
		if (!this) return 0;
		int ActUID = safe_read(this + Dump::BasePlayer::clActiveItem, int);
		if (!ActUID) return nullptr;

		BaseProjectile* ActiveWeapon;

		ULONG64 Inventory = safe_read(this + Dump::BasePlayer::inventory, ULONG64);
		ULONG64 Belt = safe_read(Inventory + Dump::PlayerInventory::containerBelt, ULONG64);
		ULONG64 ItemList = safe_read(Belt + Dump::ItemContainer::itemList, ULONG64);
		ULONG64 Items = safe_read(ItemList + 0x10, ULONG64);
		for (int i = 0; i < 6; i++)
			if (ActUID == (ActiveWeapon = (BaseProjectile*)safe_read(Items + 0x20 + (i * 0x8), ULONG64))->GetUID()) {
				return ActiveWeapon;
			}

		return 0;
	}

	PlayerInventory* get_clothing() {
		if (!this) return 0;
		int ActUID = safe_read(this + Dump::BasePlayer::clActiveItem, int);
		if (!ActUID) return nullptr;

		PlayerInventory* Wearing;

		ULONG64 Inventory = safe_read(this + Dump::BasePlayer::inventory, ULONG64);
		ULONG64 Belt = safe_read(Inventory + O::PlayerInventory::containerWear, ULONG64);
		ULONG64 ItemList = safe_read(Belt + Dump::ItemContainer::itemList, ULONG64);
		ULONG64 Items = safe_read(ItemList + 0x10, ULONG64);
		for (int i = 0; i < 6; i++)
			if (ActUID == (Wearing = (PlayerInventory*)safe_read(Items + 0x20 + (i * 0x8), ULONG64))->GetUID()) {
				return Wearing;
			}

		return 0;
	}

	int getcont() {
		if (!this) return 0;

		return 0U;
	}



	void SetModelFlag(ModelState_Flag flag) {
		DWORD64 mstate = safe_read(this + Dump::BasePlayer::modelState, DWORD64);

		int flags = Read<int>((DWORD64)this + 0x20);

		Write<int>((DWORD64)this + 0x20, flags |= (int)flag);
	}

	//Did some funny autosort using itemcategoryand itemid.
	//	What you need to do to get the container is LocalPlayer->inventory->loot->containers, 
	//	|then container->itemlist for the items.To move the items call 
	//	LocalPlayer::MoveItem with the matching arguments.To make it easier make a vector
	//	you push the moving items toand add a rpc cooldown in order not to get kickedand check if the current item |
	//	is being moved already.Hopefully I said enough

	BaseProjectile* GetWeaponInfo(int Id) {
		DWORD64 Inventory = Read<DWORD64>((DWORD64)this + O::BasePlayer::inventory);
		DWORD64 Belt = Read<DWORD64>(Inventory + O::PlayerInventory::containerBelt);
		DWORD64 ItemList = Read<DWORD64>(Belt + O::ItemContainer::itemList);
		DWORD64 Items = Read<DWORD64>(ItemList + 0x10);
		return (BaseProjectile*)Read<DWORD64>(Items + 0x20 + (Id * 0x8));
	}

	BaseProjectile* GetWeaponInfo1(int Id) {
		DWORD64 Inventory = Read<DWORD64>((DWORD64)this + O::BasePlayer::inventory);
		DWORD64 Belt = Read<DWORD64>(Inventory + O::PlayerInventory::containerWear);
		DWORD64 ItemList = Read<DWORD64>(Belt + O::ItemContainer::itemList);
		DWORD64 Items = Read<DWORD64>(ItemList + 0x10);
		return (BaseProjectile*)Read<DWORD64>(Items + 0x20 + (Id * 0x8));
	}

	void SetFov() {

		float CurFov = (Vars::Misc::PlayerZoomBool && Zooming) ? Vars::Misc::Zoom : Vars::Misc::PlayerFov;
		/*static float CurFov = 90;
		if (CurFov > GetFov) CurFov--; else if (CurFov < GetFov) CurFov++;*/
		// Vars::Misc::NoGrass
		auto pizdec = Il2cpp::InitClass(_("Graphics"), _("ConVar"));
		auto static_fields = safe_read(pizdec + 0xb8, DWORD64);
		float origFov = safe_read(static_fields + 0x18, float);
		if (Vars::Misc::PlayerFovBool || Vars::Misc::PlayerZoomBool && Zooming) {
			safe_write(static_fields + 0x18, CurFov, float);
		}

		if (true) {
			auto CalculateCircleRadius = [&](float fov, float defaultRadius) {
				float fovRad = fov * (M_PI / 180.0f);
				float radius = defaultRadius / Maths::m_Tan(fovRad / 2.0f);
				return radius;
				};

			float mod = HeldEntity->GetFovOverride();
			Vars::Aim::AimFov = CalculateCircleRadius(mod == 1337.f ? origFov : mod, Vars::Aim::OverrideAimFov);
		}

	}


	void DebugColliders() {
		auto pizdec = Il2cpp::InitClass(_("Debugging"), _("ConVar"));
		auto static_fields = safe_read(pizdec + 0xb8, DWORD64);
		if (Vars::Misc::DrawColliders)
		{
			safe_write(static_fields + 0x62, true, bool);
		}
		else { safe_write(static_fields + 0x62, false, bool); }
	}

	// public static void debugcamera(ConsoleSystem.Arg arg) { }

	void SpiderMan() {
		ULONG64 Movement = safe_read(this + Dump::BasePlayer::movement, ULONG64);
		safe_write(Movement + Dump::BasePlayer::groundAngleNew, 0.f, float);
	}

	void NoFall() {
		ULONG64 Movement = safe_read(this + Dump::BasePlayer::movement, ULONG64);
		safe_write(Movement + Dump::BasePlayer::groundTime, 9999999.f, float);
	}


	Networkable* GetNet() {
		return Read<Networkable*>((DWORD64)this + 0x30);
	}

	void InfinityJump() {
		//DWORD64 mov = Il2cpp::GetValue(_("BasePlayer"), _("movement"));
		ULONG64 Movement = safe_read(this + Dump::BasePlayer::movement, ULONG64);
		safe_write(Movement + Dump::BasePlayer::groundAngleNew, Vector3(0, 2, 0), Vector3);
		safe_write(Movement + Dump::BasePlayer::groundAngle, Vector3(99999, 2, 99999), Vector3);
	}

	Vector3 GetBoneByID(BoneList BoneID)
	{
		if (!this) return Vector3::Zero();
		DWORD64 player_model = Read<DWORD64>((DWORD64)this + Dump::BaseEntity::model);// public Model model
		DWORD64 boneTransforms = Read<DWORD64>(player_model + 0x48);//public Transform[] boneTransforms;
		Transform* BoneValue = Read<Transform*>(boneTransforms + 0x20 + BoneID * 0x8);

		if (!BoneValue)
			return Vector3::Zero();

		return BoneValue->Position();
	}

	Transform* GetTransform(int bone)
	{
		DWORD64 entity_model = safe_read(this + Dump::BaseEntity::model, DWORD64);
		DWORD64 bone_dict = safe_read(entity_model + 0x48, DWORD64);
		Transform* BoneValue = Read<Transform*>(bone_dict + 0x20 + bone * 0x8);
		return BoneValue;
	}
	// the most retarded target search

	AimTarget LoopTarget(WORD Tag, BasePlayer* Entity, unsigned int PrefabID )
	{
		if (!Entity) return AimTarget();
		if (EyePos == Vector3::Zero()) return AimTarget();
		AimTarget EndTarget = AimTarget();

		bool isTurret = PrefabID == 3312510084;
		bool isHeli = PrefabID == 3029415845;

		AimTarget CheckTarget = AimTarget();
		
		if (Tag == 6) {
			
			BasePlayer* Player = Entity;
			CheckTarget.Cur = (Vars::Aim::KeepTarget && KeepTargeting && lastTarget != 0) ? lastTarget : Entity;
			if (!Player->IsDead()) return AimTarget();

			CheckTarget.IsSleeping = Player->IsSleeping();
			CheckTarget.Wounded = Player->IsWounded();
			CheckTarget.IsTeammate = Player->IsTeamMate(LocalPlayer);
			CheckTarget.Npc = Classes::get_IsNpc((DWORD64)Player->GetPlayerModel());
			CheckTarget.inSafeZone = Player->IsInSafeZone();

			if (!CheckTarget.inSafeZone || !Vars::Aim::IgnoreSafeZone) {
				if (!CheckTarget.IsSleeping || !Vars::Aim::IgnoreSleepers) {
					if (!CheckTarget.Wounded || !Vars::Aim::IgnoreWounded) {
						if (!CheckTarget.IsTeammate || !Vars::Aim::IgnoreTeam) {
							if (!CheckTarget.Npc || !Vars::Aim::IgnoreNpc) {
								if (!CheckTarget.Heli || !Vars::Aim::IgnoreHeli) {
									if (!CheckTarget.Turret || !Vars::Aim::IgnoreTurrets) {

										auto PlayerPos = Vars::Aim::AimCombo == 0 ? CheckTarget.Cur->GetTransform(47)->Position() : CheckTarget.Cur->GetTransform(22)->Position();
										CheckTarget.Pos = PlayerPos;

										auto Network = CheckTarget.Cur->GetNet(); if (!Network) return AimTarget();

										auto idd = Network->GetID(); if (!idd) return AimTarget();

										CheckTarget.isvis = Unity::CheckLOS(EyePos, PlayerPos);

										if (CheckTarget.isvis || Vars::Aim::IgnoreVisible) {

											CheckTarget.Distance = EyePos.Distance(PlayerPos);

											CheckTarget.Fov = GetFov(CheckTarget.Pos);

											if (!(Vars::Aim::KeepTarget && KeepTargeting))
											{
												if (CheckTarget < EndTarget
													&& CheckTarget.Fov < Vars::Aim::AimFov)
													EndTarget = CheckTarget;
												if (EndTarget.Fov > Vars::Aim::AimFov)
													EndTarget = AimTarget();
											}
											else
											{
												EndTarget = CheckTarget;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else if (isTurret || isHeli)
		{
			if ((!CheckTarget.Heli || !Vars::Aim::IgnoreHeli) || (!CheckTarget.Turret || !Vars::Aim::IgnoreTurrets)) {
				auto Network = CheckTarget.Cur->GetNet(); if (!Network) return AimTarget();
				auto idd = Network->GetID(); if (!idd) return AimTarget();

				auto PlayerPos = Vars::Aim::AimCombo == 0 ? CheckTarget.Cur->GetTransform(47)->Position() : CheckTarget.Cur->GetTransform(22)->Position();
				auto pos = (isTurret || isHeli) ? (CheckTarget.Cur->get_transform()->Position() + Vector3(0, 0.6, 0)) : PlayerPos;
				CheckTarget.Pos = pos;

				CheckTarget.Turret = isTurret;
				CheckTarget.Heli = isHeli;

				

				auto visible = Unity::CheckLOS(EyePos, pos);
				CheckTarget.isvis = visible;

				CheckTarget.Distance = EyePos.Distance(pos);

				CheckTarget.Fov = GetFov(CheckTarget.Pos);

				if (CheckTarget < EndTarget && CheckTarget.Fov < Vars::Aim::AimFov)
					EndTarget = CheckTarget;
				if (EndTarget.Fov > Vars::Aim::AimFov)
					EndTarget = AimTarget();
			}
		}
		lastTarget = EndTarget.Cur;
		return EndTarget;
	}

	AimTarget TargetLast;
	AimTarget FindBestTarget(Vector3 source, float max_distance = 2000) {
		AimTarget best_target = AimTarget();

		DWORD64 ClientEntities = Il2cpp::GetValue(_("BaseNetworkable"), _("clientEntities"), false);
		DWORD64 ClientEntities_list = Read<DWORD64>(ClientEntities + 0x10);
		DWORD64 ClientEntities_values = Read<DWORD64>(ClientEntities_list + 0x28);
		int EntityCount = Read<int>(ClientEntities_values + 0x10);
		DWORD64 EntityBuffer = Read<DWORD64>(ClientEntities_values + 0x18);
		//if (!EntityBuffer || !EntityBuffer) return AimTarget();
		for (int i = 0; i <= EntityCount; i++) {
			auto current_object = Read<DWORD64>(EntityBuffer + 0x20 + (i * 0x8));
			if (!current_object)
				continue;

			auto base_object = Read<DWORD64>(current_object + 0x10);
			if (!base_object)
				continue;

			auto object = Read<DWORD64>(base_object + 0x30);
			if (!object)
				continue;

			WORD tag = Read<WORD>(object + 0x54);

			pUncStr name = safe_read(object + 0x60, pUncStr); if (!name) continue;
			char* buff = name->stub;

			//auto ent_class = Read<DWORD64>(ent);
			//auto entity_class_name = (char*)Read<DWORD64>(ent_class + 0x10);

			bool is_heli = false;
			bool is_turret = false;

			//if (*(int*)(entity_class_name + 4) == 'ileH')
			if (m_strstr(buff, _("patrolhelicopter.prefab")))
				is_heli = true;

			if (m_strstr(buff, _("autoturret_deployed.prefab")))
				is_turret = true;

			/*if (tag == 6 && !settings::visuals::player_esp)
				continue;*/

			if (is_heli && Vars::Aim::IgnoreHeli)
				continue;

			if (is_turret && Vars::Aim::IgnoreTurrets)
				continue;

			if (tag != 6 && !is_heli && !is_turret)
				continue;

			BasePlayer* player = (BasePlayer*)current_object;
			if (!player)
				continue;

			DWORD64 object_name_ptr = Read<DWORD64>(object + 0x60);

			if (player != LocalPlayer)
			{
				AimTarget target = AimTarget();
				target.Cur = (Vars::Aim::KeepTarget && KeepTargeting && lastTarget != 0) ? lastTarget : player;

				if (!is_heli && !is_turret) {
					if (!player->IsDead()) continue;
					if (player->IsSleeping())
						target.IsSleeping = true;
					if (player->IsWounded())
						target.Wounded = true;
					if (player->IsTeamMate(LocalPlayer))
						target.IsTeammate = true;
					if (Classes::get_IsNpc((DWORD64)player->GetPlayerModel()))
						target.Npc = true;
					if (player->IsInSafeZone())
						target.inSafeZone = true;

					if (!target.inSafeZone || !Vars::Aim::IgnoreSafeZone) {
						if (!target.IsSleeping || !Vars::Aim::IgnoreSleepers) {
							if (!target.Wounded || !Vars::Aim::IgnoreWounded) {
								if (!target.IsTeammate || !Vars::Aim::IgnoreTeam) {
									if (!target.Npc || !Vars::Aim::IgnoreNpc) {
										if (!target.Heli || !Vars::Aim::IgnoreHeli) {
											if (!target.Turret || !Vars::Aim::IgnoreTurrets) {
												//IgnoreSafeZone;

												auto PlayerPos = Vars::Aim::AimCombo == 0 ? target.Cur->GetTransform(ScannedBone)->Position() : target.Cur->GetTransform(22)->Position();
												Vector3	pos = PlayerPos;
												target.Pos = pos;

												target.Heli = is_heli;

												auto Network = target.Cur->GetNet(); if (!Network) continue;

												auto idd = Network->GetID(); if (!idd) continue;

												auto visible = Unity::CheckLOS(source, pos);
												target.isvis = visible;

												if (target.isvis || Vars::Aim::IgnoreVisible) {

													auto distance = source.Distance(pos);
													target.Distance = distance; if (distance > max_distance) continue;

													auto fov = GetFov(target.Pos);
													target.Fov = fov;

													if (!(Vars::Aim::KeepTarget && KeepTargeting))
													{
														if (target < best_target
															&& target.Fov < Vars::Aim::AimFov)
															best_target = target;
														if (best_target.Fov > Vars::Aim::AimFov)
															best_target = AimTarget();
													}
													else
													{
														best_target = target;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				else if (is_heli || is_turret) {
					if ((!target.Heli || !Vars::Aim::IgnoreHeli) || (!target.Turret || !Vars::Aim::IgnoreTurrets)) {

						auto PlayerPos = Vars::Aim::AimCombo == 0 ? target.Cur->GetTransform(47)->Position() : target.Cur->GetTransform(22)->Position();
						auto pos = (is_heli || is_turret) ? (target.Cur->get_transform()->Position() + Vector3(0, 0.6, 0)) : PlayerPos;
						target.Pos = pos;

						target.Turret = is_turret;
						target.Heli = is_heli;

						auto Network = target.Cur->GetNet(); if (!Network) continue;

						auto idd = Network->GetID(); if (!idd) continue;

						auto visible = Unity::CheckLOS(source, pos);
						target.isvis = visible;

						auto distance = source.Distance(pos);
						target.Distance = distance; if (distance > max_distance) continue;

						auto fov = GetFov(target.Pos);
						target.Fov = fov;

						if (target < best_target && target.Fov < Vars::Aim::AimFov)
							best_target = target;
						if (best_target.Fov > Vars::Aim::AimFov)
							best_target = AimTarget();
					}
				}
			}
		}
		lastTarget = best_target.Cur;
		return best_target;
	}

	AimTarget FindAimTarget(AimTarget RealTarget) {
		AimTarget FindTarget = AimTarget();

		if (!RealTarget.IsSleeping || !Vars::Aim::IgnoreSleepers) {
			if (!RealTarget.Wounded || !Vars::Aim::IgnoreWounded) {
				if (!RealTarget.IsTeammate || !Vars::Aim::IgnoreTeam) {
					if (!RealTarget.Npc || !Vars::Aim::IgnoreNpc) {
						if (!RealTarget.Heli || !Vars::Aim::IgnoreHeli) {
							if (RealTarget.isvis || Vars::Aim::IgnoreVisible) {
								FindTarget = RealTarget;
							}
						}
					}
				}
			}
		}

		return FindTarget;
	}

	Vector3 GetNetworkEyePosition() {
		if (!this) return Vector3();
		bool mounted = Classes::HasParent(this);
		if (!mounted) {
			Vector3 basePos = this->lastSentTick()->position() + Vector3(0, 1.5f, 0);
			/*ModelState* modState = Read<ModelState*>((DWORD64)this + Dump::BasePlayer::modelState);
			if (modState->HasFlag(ModelState_Flag::Ducked)) {
				basePos.y -= 0.6f;
			}*/
			return basePos;
		}
		else {
			return this->GetEyes()->EyePosition(); //don't forget to give forgiviness If mounted
		}
	}
};

class PlayerNameID {
public:
	Str GetUsername() {
		auto username = Read<Str*>((DWORD64)this + 0x10);
		return username->str;
	}

	unsigned long UserId()
	{
		return Read<unsigned long>((DWORD64)this + 0x18);
	}
};

class ModelState // ModelState
{
public:
	void RemoveFlag(ModelState_Flag flag) {
		int flags = Read<int>((DWORD64)this + 0x20);
		flags &= ~(int)flag;
		Write<int>((DWORD64)this + 0x20, flags);
	}

	void SetFlag(ModelState_Flag flag) {
		int flags = Read<int>((DWORD64)this + 0x20);
		Write<int>((DWORD64)this + 0x20, flags |= (int)flag);
	}


	bool HasFlag(ModelState_Flag f)
	{
		int& flags = *reinterpret_cast<int*>((DWORD64)this + 0x20);
		return (flags & (int)f) == (int)f;
	}

	void SetJumped(bool j) {
		if (!this) return;
		return Classes::set_jumped((DWORD64)this, j);;
	}
};


class PlayerWalkMovement // ModelState
{
public:
	void TargetMovement(Vector3 v) {
		Write<Vector3>((DWORD64)this + 0x34, v);
	}
	bool Swimming() {
		return *reinterpret_cast<bool*>((DWORD64)this + O::PlayerWalkMovement::swimming);
	}
	float Ducking() {
		return *reinterpret_cast<float*>((DWORD64)this + O::BaseMovement::Duckingk__BackingField);
	}
	Vector3 TargetMovement() {
		return Read<Vector3>((DWORD64)this + 0x34);
	} // capsuleHeight

	void set_radius(float time) { // 0xB0
		auto capsule = safe_read((DWORD64)this + 0xB0, DWORD64);
		//Write<float>((DWORD64)this + 0x2539B40, time);
		Classes::set_capsuleRadius(capsule, time);
	} // jumping

	void set_height(float time) { // 0xB0
		auto capsule = safe_read((DWORD64)this + 0xB0, DWORD64);
		Classes::set_capsuleHeight(capsule, time);
	}

	void JumpTime(float time) {
		Write<float>((DWORD64)this + 0xd0, time);
	}

	void Jump(ModelState* state) {
		if (!this) return;
		//JumpTime(Unity::get_time());
		/*Write<bool>((DWORD64)this + O::PlayerWalkMovement::landTime, 0.1);

		Write<bool>((DWORD64)this + O::PlayerWalkMovement::jumping, true);*/
		//state->SetJumped(true);
		Classes::Jump(this, state, false);
		//return Classes::Jump(this, state, false);

	}

	DWORD64 GetBody() {
		return Read<DWORD64>((DWORD64)this + Dump::PlayerWalkMovement::body);
	}

	Vector3 BodyVelocity() {
		return Classes::get_rigidbody_velocity(GetBody());
	}

	void BodyVelocity(Vector3 v) {
		Classes::set_rigidbody_velocity(GetBody(), v);
	} // Jump

	void DoJump(PlayerWalkMovement* pwm, ModelState* state, float force = 9) {
		state->SetFlag(ModelState_Flag::OnGround);
		state->SetJumped(true);
		pwm->JumpTime(Unity::get_time());
		auto vel = pwm->BodyVelocity();
		pwm->BodyVelocity(Vector3(vel.x, force, vel.z));
		return;
	}
};

class BaseCombatEntity {
public:
	char* ClassName() {
		if (!this) return _("");
		auto oc = Read<uint64_t>((DWORD64)this);
		if (!oc) return _("");
		return Read<char*>(oc + 0x10);
	}
};

namespace utils {
	Vector3 GetEntityPosition(uint64_t entity) {
		if (!entity) return Vector3::Zero();

		DWORD64 plyVis = Read<DWORD64>(entity + 0x8);
		if (!plyVis) return Vector3::Zero();

		DWORD64 visualState = Read<DWORD64>(plyVis + 0x38);
		if (!visualState) return Vector3::Zero();

		Vector3 ret = Read<Vector3>(visualState + 0x90);
		return ret;
	}
	Vector3 ClosestPoint(BasePlayer* player, Vector3 vec) {
		Vector3 result = Classes::ClosestPoint(player, vec);
		return result;
	}
};
#define _FI __forceinline
_FI Vector3 GetObjectPos(DWORD64 entity)
{
	const auto player_visual = Read<DWORD64>(entity + 0x8);
	if (!player_visual)
		return { 0,0,0 };
	const auto visual_state = Read<DWORD64>(player_visual + 0x38);
	if (!visual_state)
		return { 0,0,0 };

	return Read<Vector3>(visual_state + 0x90);
}

class InputState
{
public:
	void AimAngles(Vector3 aim_angle) {
		auto current = Read<DWORD64>((DWORD64)this + 0x10);
		Write<Vector3>(current + 0x14, aim_angle);
	}

	Vector3 AimAngles() {
		auto current = Read<DWORD64>((DWORD64)this + 0x10);
		return Read<Vector3>(current + 0x14);
	}
};

class GameManifest {
public:
	static Object* GUIDToObject(Str* guid)
	{
		Object* _cachedObject = 0;
		if (_cachedObject == 0)
		{
			//auto v6 = *(uintptr_t*)(this + 16);
			_cachedObject = (Object*)Unity::GUIDToObject((uintptr_t)guid);
		}
		return _cachedObject;
	}
};

template<typename T = Object>
class ResourceRef {
public:
	T* Get() {
		if (!this) return nullptr;
		Str* guid = *reinterpret_cast<Str**>(this + 0x10);
		T* _cachedObject = (T*)GameManifest::GUIDToObject(guid);

		return _cachedObject;
	}
};
class GameObject : public Object {
public:
	template<typename T>
	T get_class()
	{
		return Read<T>((DWORD64)this + 0x30);
	}

	template<typename T>
	T get_class(uint32_t second_offset)
	{
		const auto object = Read<DWORD64>((DWORD64)this + 0x30);
		if (!object)
			return nullptr;

		return Read<T*>(object + second_offset);
	}

	char* get_prefab_name() { return Read<char*>((DWORD64)this + 0x60); }

	uint32_t get_tag() { return Read<uint16_t>((DWORD64)this + 0x54); }

	layer get_layer() { return Read<layer>((DWORD64)this + 0x50); }
};
class ItemModProj {
public:
	float GetRandomVelocity()
	{
		return Read<float>((DWORD64)this + Dump::ItemModProjectile::GetRandomVelocity);
	}
	float projectileVelocity()
	{
		if (!this) return {};
		return Read<float>((DWORD64)this + O::ItemModProjectile::projectileVelocity);
	}
	ResourceRef<GameObject>* projectileObject() {
		return Read<ResourceRef<GameObject>*>((DWORD64)this + O::ItemModProjectile::projectileObject);
	}
};


//static ItemModProj* Get_ItemModProjectile_ItemInfo() {
//
//	auto local = LocalPlayer;
//	if (!local)
//		return nullptr;
//
//	auto Item = local->GetActiveWeapon();
//	if (!Item)
//		return nullptr;
//
//	auto info = Read<uintptr_t>((uintptr_t)Item + 0x18);
//	if (!info)
//		return nullptr;
//
//	ItemModProj* component = (ItemModProj*)Classes::GetComponent(info, Il2cpp::TypeGetObject("", _("ItemModProjectile")));
//	if (!component)
//		return nullptr;
//
//	//ItemModProj* itemmod = Read< ItemModProj* >((uintptr_t)g_Base + 49473064);
//
//	return component;
//}
//
//static Projectile* GetProjectile_ItemInfo() {
//
//	ItemModProj* component = Get_ItemModProjectile_ItemInfo();
//
//	GameManifest* projectileObject = (GameManifest*)component->projectileObject();
//
//	auto get = projectileObject->GUIDToObject();
//
//	Projectile* component3 = (Projectile*)Unity::ObjectComponent((UINT_PTR)get, Il2cpp::TypeGetObject(_(""), _("Projectile")));
//
//	return component3;
//}



class HitTest {
public:
	void DidHit(bool did_hit) { Write<bool>((DWORD64)this + O::HitTest::DidHit, did_hit); }
	bool DidHit() { return Read<bool>((DWORD64)this + O::HitTest::DidHit); }
	void HitPart(unsigned int i) { Write<unsigned int>((DWORD64)this + O::HitTest::HitPart, i); }
	unsigned int HitPart() { return Read<unsigned int>((DWORD64)this + O::HitTest::HitPart); }

	void HitEntity(BasePlayer* entity) { Write<BasePlayer*>((DWORD64)this + O::HitTest::HitEntity, entity); }

	BasePlayer*& HitEntity() {
		return *reinterpret_cast<BasePlayer**>((DWORD64)this + 0x88);
	}

	void HitTest_HitMaterial(Str* material) {
		Write<Str*>((DWORD64)this + 0xC0, material); // 0xc0
	}

	Str* get_HitMaterial() {
		return Read<Str*>((DWORD64)this + 0xC0); // 0xc0
	}

	unsigned int HTHitMaterial()
	{
		return Read<unsigned int>((DWORD64)this + 0xc0);
	}

	void HitMaterial(unsigned int material) {
		Write<unsigned int>((DWORD64)this + 0x50, material); // 0xc0
	}
	unsigned int HitMaterial()
	{
		return Read<unsigned int>((DWORD64)this + 0x50);
	}
	void HitTransform(Transform* hit_transform) { Write<Transform*>((DWORD64)this + O::HitTest::HitTransform, hit_transform); }
	Transform* HitTransform() { return Read<Transform*>((DWORD64)this + O::HitTest::HitTransform); }
	void AttackRay(Ray ray) { Write<Ray>((DWORD64)this + O::HitTest::AttackRay, ray); }
	Ray* AttackRay() { return Read<Ray*>((DWORD64)this + O::HitTest::AttackRay); }
	void Radius(float radius) { Write<float>((DWORD64)this + O::HitTest::Radius, radius); }
	void Frogivness(float radius) { Write<float>((DWORD64)this + O::HitTest::Forgiveness, radius); }

	void IgnoreEntity(BasePlayer* entity_to_ignore) {
		Write<BasePlayer*>((DWORD64)this + O::HitTest::ignoreEntity, entity_to_ignore);
	}

	void DamageProperties(DWORD64 damage_properties) { Write<DWORD64>((DWORD64)this + O::HitTest::damageProperties, damage_properties); }
	void MaxDistance(float max_dist) { Write<float>((DWORD64)this + O::HitTest::MaxDistance, max_dist); }
	float MaxDistance() { return Read<float>((DWORD64)this + O::HitTest::MaxDistance); }
	void BestHit(bool best_hit) { Write<bool>((DWORD64)this + O::HitTest::BestHit, best_hit); }
	void HitPoint(Vector3 ray) { Write<Vector3>((DWORD64)this + O::HitTest::HitPoint, ray); }
	Vector3 HitPoint() { return Read<Vector3>((DWORD64)this + O::HitTest::HitPoint); }
	void HitNormal(Vector3 ray2) { Write<Vector3>((DWORD64)this + O::HitTest::HitNormal, ray2); }
	Vector3 HitNormal() { return Read<Vector3>((DWORD64)this + O::HitTest::HitNormal); }
	void HitDistance(float max_dist) { Write<float>((DWORD64)this + O::HitTest::HitDistance, max_dist); }
	DWORD64 gameobject() { return Read<DWORD64>((DWORD64)this + 0x70); }

	GameObject* get_GameObject()
	{
		auto gameObject = gameobject();
		if (!gameObject)
			return nullptr;

		return Read<GameObject*>(gameObject + 0x10);
	}

	/*bool get_isHeadshot(bool b) {
		return Classes::get_isHeadshot((DWORD64)this) == b;
	}*/

	Vector3 HitPositionWorld() { return Read<Vector3>((DWORD64)this + 0x54); }
};

class Projectile : public BaseMonoBehaviour {

public:

	bool needsLOS() { return safe_read(this + O::Projectile::createDecals, bool); }
	void needsLOS(bool d) { if (!this) return; safe_write(this + O::Projectile::createDecals, d, bool); }
	void invisible(bool d) { if (!this) return; safe_write(this + O::Projectile::invisible, d, bool); }
	void InitialVelocity(Vector3 d) { if (!this) return; safe_write(this + O::Projectile::initialVelocity, d, Vector3); }
	Vector3 InitialVelocity() { return safe_read(this + O::Projectile::initialVelocity, Vector3); }
	Vector3 previousPosition() { return safe_read(this + O::Projectile::previousPosition, Vector3); }
	// createDecals
	bool createDecals() { return safe_read(this + O::Projectile::createDecals, bool); }
	DWORD64 sourceProjectilePrefab() { return safe_read(this + O::Projectile::sourceProjectilePrefab, DWORD64); }
	DWORD64 sourceWeaponPrefab() { return safe_read(this + O::Projectile::sourceWeaponPrefab, DWORD64); }
	Vector3 sentPosition() { return safe_read(this + O::Projectile::sentPosition, Vector3); }
	void sentPosition(Vector3 d) { safe_write(this + O::Projectile::sentPosition, d, Vector3); }
	void currentVelocity(Vector3 d) { safe_write(this + O::Projectile::currentVelocity, d, Vector3); }
	Vector3 currentVelocity() { return safe_read(this + O::Projectile::currentVelocity, Vector3); }

	int projectileID() { return safe_read(this + O::Projectile::projectileID, int); }
	void projectileID(int id) { safe_write(this + O::Projectile::projectileID, id, int); }

	float ricochetChance() { return safe_read(this + O::Projectile::ricochetChance, float); }
	void ricochetChance(float d) { safe_write(this + O::Projectile::ricochetChance, d, float); }

	Vector3 currentPosition() { return Read<Vector3>((DWORD64)this + O::Projectile::currentPosition); }
	void currentPosition(Vector3 position) { Write<Vector3>((DWORD64)this + O::Projectile::currentPosition, position); }
	void previousPosition(Vector3 position) { Write<Vector3>((DWORD64)this + O::Projectile::previousPosition, position); }
	float previoustraveledTime() { return safe_read(this + O::Projectile::previousTraveledTime, float); }
	void previoustraveledTime(float d) { if (!this) return; safe_write(this + O::Projectile::previousTraveledTime, d, float); }
	//bool Authoritative() { return safe_read(this + isAuthoritative, bool); }

	void previousVelocity(Vector3 position) { Write<Vector3>((DWORD64)this + O::Projectile::previousVelocity, position); }
	void partialTime(float f) { if (!this) return; safe_write(this + O::Projectile::tumbleSpeed, f, float); }
	float partialTime() { return safe_read(this + O::Projectile::tumbleSpeed, float); }
	Vector3 previousVelocity() { return safe_read(this + O::Projectile::previousVelocity, Vector3); }
	float Drag() { return safe_read(this + O::Projectile::drag, float); }
	BasePlayer* owner() { return (BasePlayer*)safe_read(this + O::Projectile::owner, DWORD64); }
	void Integrity(float f) { safe_write(this + O::Projectile::integrity, f, float); }
	void penetrationPower(float f) { safe_write(this + O::Projectile::penetrationPower, f, float); }
	float Integrity() { return safe_read(this + O::Projectile::integrity, float); }
	float PrevioustraveledTime() { return safe_read(this + O::Projectile::previousTraveledTime, float); }
	void previousTraveledTime(float d) { safe_write(this + O::Projectile::previousTraveledTime, d, float); }  // previousVelocity

	//void DoHit(float d) { safe_write(this + O::Projectile::DoHit, d, float); }  // HitDistance

	void PartialTime(float f) { safe_write(this + O::Projectile::tumbleSpeed, f, float); }
	float PartialTime() { return safe_read(this + O::Projectile::tumbleSpeed, float); }

	float& projectileVelocityScale()
	{
		return *reinterpret_cast<float*>((DWORD64)this + Dump::BaseProjectile::projectileVelocityScale);
	}
	float gravityModifier() { return safe_read(this + O::Projectile::gravityModifier, float); }

	ItemModProj* GetItemModProjectile() {
		return Read<ItemModProj*>((DWORD64)this + O::Projectile::mod);
	}

	float launchTime() { return safe_read(this + O::Projectile::launchTime, float); }
	void launchTime(float d) { safe_write(this + O::Projectile::launchTime, d, float); }

	DWORD64 damageDistances() { return safe_read(this + O::Projectile::damageDistances, DWORD64); }

	void hitTest(DWORD64 d) { safe_write(this + O::Projectile::hitTest, d, DWORD64); }
	DWORD64 hitTest() { return safe_read(this + O::Projectile::hitTest, DWORD64); }
	HitTest* get_hit_test() {
		return Read<HitTest*>((DWORD64)this + O::Projectile::hitTest);
	}
	DWORD64 damageProperties() { return safe_read(this + O::Projectile::damageProperties, DWORD64); }
	void damageProperties(DWORD64 d) { safe_write(this + O::Projectile::damageProperties, d, DWORD64); }

	float traveledDistance() { return safe_read(this + O::Projectile::traveledDistance, float); }
	void traveledDistance(float d) { safe_write(this + O::Projectile::traveledDistance, d, float); }

	float initialDistance() { return safe_read(this + O::Projectile::initialDistance, float); }
	void initialDistance(float d) { safe_write(this + O::Projectile::initialDistance, d, float); }

	float sentTraveledTime() { return safe_read(this + O::Projectile::closeFlybyDistance, float); }
	void sentTraveledTime(float d) { safe_write(this + O::Projectile::closeFlybyDistance, d, float); }

	Vector3 prevSentVelocity() { return safe_read(this + O::Projectile::tumbleAxis, Vector3); }
	void prevSentVelocity(Vector3 d) { safe_write(this + O::Projectile::tumbleAxis, d, Vector3); }

	Vector3 prevSentPosition() { return safe_read(this + O::Projectile::sentPosition, Vector3); }
	void prevSentPosition(Vector3 d) { safe_write(this + O::Projectile::sentPosition, d, Vector3); }

	float traveledTime() { return safe_read(this + O::Projectile::traveledTime, float); }
	void traveledTime(float d) { safe_write(this + O::Projectile::traveledTime, d, float); }
	float maxDistance() { return safe_read(this + O::Projectile::maxDistance, float); }
	bool IsAlive() {
		return (this->Integrity() > 0.001f && this->traveledDistance() < this->maxDistance() && this->traveledTime() < 8);
	}
};

class AimResult {
public:
	bool valid;
	BasePlayer* entity;
	Vector3 pos;
	float dist = 10000.f;
	float realdist = 0.f;
	float fov = 10000.f;

	bool operator<(const AimResult& b) { return this->dist < b.dist; }
	bool operator>(const AimResult& b) { return this->dist > b.dist; }
	bool operator<=(const AimResult& b) { return this->dist <= b.dist; }
	bool operator>=(const AimResult& b) { return this->dist >= b.dist; }

	AimResult() {
		this->valid = false;
	}
	AimResult(Vector3 target) {
		this->valid = false;
		this->pos = target;
	}

	static inline AimResult get_closest_object(Vector3 from, const char* namee, Vector3 ignore = Vector3::Zero(), Vector3 ignore2 = Vector3::Zero(), Vector3 ignore3 = Vector3::Zero(), bool classname = false, const char* classnamee = _(""), float get_dist = 99999.f, bool vis = false, bool y = false) {
		AimResult lowest = AimResult();
		DWORD64 ClientEntities = ClientEntities = Il2cpp::GetValue(_("BaseNetworkable"), _("clientEntities"), false);
		DWORD64 ClientEntities_list = Read<DWORD64>(ClientEntities + 0x10);
		DWORD64 ClientEntities_values = Read<DWORD64>(ClientEntities_list + 0x28);
		int EntityCount = Read<int>(ClientEntities_values + 0x10);

		DWORD64 EntityBuffer = Read<DWORD64>(ClientEntities_values + 0x18);
		for (int i = 0; i <= EntityCount; i++) {

			DWORD64 Entity = Read<DWORD64>(EntityBuffer + 0x20 + (i * 0x8));
			if (Entity <= 100000) continue;
			DWORD64 Object = Read<DWORD64>(Entity + 0x10);
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = Read<DWORD64>(Object + 0x30);
			if (ObjectClass <= 100000) continue;
			pUncStr name = Read<pUncStr>(ObjectClass + 0x60);
			if (!name) continue;
			char* buff = name->stub;
			AimResult res = AimResult();

			if (classname) {
				if (m_strstr((char*)Read<DWORD64>(Read<DWORD64>(Read<DWORD64>(Object + 0x28)) + 0x10), classnamee)) {
					DWORD64 a = Read<DWORD64>(ObjectClass + 0x30);
					float dist = Maths::Calc3D_Dist(utils::GetEntityPosition(a), from);
					if (utils::GetEntityPosition(a) != ignore && utils::GetEntityPosition(a) != ignore2 && utils::GetEntityPosition(a) != ignore3) {
						res.valid = dist <= get_dist;
						res.dist = dist;
						res.entity = (BasePlayer*)Entity;
						res.pos = utils::GetEntityPosition(a);
						if (res < lowest) lowest = res;
					}
				}
			}
			else {
				if (m_strstr(buff, namee)) {
					DWORD64 a = Read<DWORD64>(ObjectClass + 0x30);
					float dist = Maths::Calc3D_Dist(utils::GetEntityPosition(a), from);
					if (utils::GetEntityPosition(a) != ignore && utils::GetEntityPosition(a) != ignore2 && utils::GetEntityPosition(a) != ignore3) {
						if (vis ? Unity::CheckLOS(utils::GetEntityPosition(a), from) : true) {
							if (y) {
								if (utils::GetEntityPosition(a).y > 0) {
									res.valid = dist <= get_dist;
									res.dist = dist;
									res.entity = (BasePlayer*)Entity;
									res.pos = utils::GetEntityPosition(a);
									if (res < lowest) lowest = res;
								}
							}
							else {
								res.valid = dist <= get_dist;
								res.dist = dist;
								res.entity = (BasePlayer*)Entity;
								res.pos = utils::GetEntityPosition(a);
								if (res < lowest) lowest = res;
							}
						}
					}
				}

			}
		}

		return lowest;
	}

	static AimResult SafeObjectToWalk(Vector3 from, const char* namee, Vector3 ignore = Vector3::Zero(), Vector3 ignore2 = Vector3::Zero(), Vector3 ignore3 = Vector3::Zero(), AimResult dangerPos = Vector3::Zero(), AimResult dangerPos1 = Vector3::Zero(), AimResult dangerPos2 = Vector3::Zero(), AimResult dangerPos3 = Vector3::Zero(), AimResult dangerPos4 = Vector3::Zero(), float get_dist = 99999.f, bool vis = false, bool y = false) {
		AimResult lowest = AimResult();
		DWORD64 ClientEntities = ClientEntities = Il2cpp::GetValue(_("BaseNetworkable"), _("clientEntities"), false);
		DWORD64 ClientEntities_list = Read<DWORD64>(ClientEntities + 0x10);
		DWORD64 ClientEntities_values = Read<DWORD64>(ClientEntities_list + 0x28);
		int EntityCount = Read<int>(ClientEntities_values + 0x10);

		DWORD64 EntityBuffer = Read<DWORD64>(ClientEntities_values + 0x18);
		for (int i = 0; i <= EntityCount; i++) {

			DWORD64 Entity = Read<DWORD64>(EntityBuffer + 0x20 + (i * 0x8));
			if (Entity <= 100000) continue;
			DWORD64 Object = Read<DWORD64>(Entity + 0x10);
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = Read<DWORD64>(Object + 0x30);
			if (ObjectClass <= 100000) continue;
			pUncStr name = Read<pUncStr>(ObjectClass + 0x60);
			if (!name) continue;
			char* buff = name->stub;
			AimResult res = AimResult();


			if (m_strstr(buff, namee)) {
				DWORD64 a = Read<DWORD64>(ObjectClass + 0x30);
				float dist = Maths::Calc3D_Dist(utils::GetEntityPosition(a), from);
				float disttodanger = Maths::Calc3D_Dist(utils::GetEntityPosition(a), dangerPos.pos);
				float disttodanger1 = Maths::Calc3D_Dist(utils::GetEntityPosition(a), dangerPos1.pos);
				float disttodanger2 = Maths::Calc3D_Dist(utils::GetEntityPosition(a), dangerPos2.pos);
				float disttodanger3 = Maths::Calc3D_Dist(utils::GetEntityPosition(a), dangerPos3.pos);
				float disttodanger4 = Maths::Calc3D_Dist(utils::GetEntityPosition(a), dangerPos4.pos);

				if (utils::GetEntityPosition(a) != ignore && utils::GetEntityPosition(a) != ignore2 && utils::GetEntityPosition(a) != ignore3 && disttodanger > 31 && disttodanger1 > 7 && disttodanger2 > 7 && disttodanger3 > 3 && disttodanger4 > 3) {
					if (vis ? Unity::CheckLOS(utils::GetEntityPosition(a), from) : true) {
						if (y) {
							if (utils::GetEntityPosition(a).y > 0) {
								res.valid = dist <= get_dist;
								res.dist = dist;
								res.entity = (BasePlayer*)Entity;
								res.pos = utils::GetEntityPosition(a);
								if (res < lowest) lowest = res;
							}
						}
						else {
							res.valid = dist <= get_dist;
							res.dist = dist;
							res.entity = (BasePlayer*)Entity;
							res.pos = utils::GetEntityPosition(a);
							if (res < lowest) lowest = res;
						}
					}
				}
			}

		}

		return lowest;
	}

	static AimResult GetJunkpile(AimResult tur, AimResult stonewall, AimResult woodwall, AimResult mine, AimResult brtr) {
		if (Vars::Misc::AutoFarmOres == 5) {
			AimResult poop;
			AimResult pooop;
			AimResult poooop;
			AimResult shitcode;

			AimResult ja = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_a.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
			AimResult jb = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_b.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
			AimResult jc = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_c.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);

			AimResult jd = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_d.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
			AimResult je = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_e.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
			AimResult jf = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_f.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);

			AimResult jg = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_g.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
			AimResult jh = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_h.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
			AimResult ji = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_i.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);

			AimResult jj = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("junkpile_j.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);

			if (ja.valid) {
				if (jb.valid) {
					if (jc.valid) {//s & m & sf
						if (ja.dist < jb.dist && ja.dist < jc.dist) {
							poop = ja;
						}
						else if (jb.dist < ja.dist && jb.dist < jc.dist) {
							poop = jb;
						}
						else if (jc.dist < jb.dist && jc.dist < ja.dist) {
							poop = jc;
						}
					}
				}
				else if (jc.valid) {//s & sf
					if (ja.dist < jc.dist)
						poop = ja;
					else if (jc.dist < ja.dist)
						poop = jc;
				}
			}
			else if (jb.valid) {
				if (jc.valid) {//m & sf
					if (jb.dist < jc.dist)
						poop = jb;
					else if (jc.dist < jb.dist)
						poop = jc;
				}
				else
					poop = jb;
			}
			else if (jc.valid) {
				poop = jc;
			}

			if (jd.valid) {
				if (je.valid) {
					if (jf.valid) {//s & m & sf
						if (jd.dist < je.dist && jd.dist < jf.dist) {
							pooop = jd;
						}
						else if (je.dist < jd.dist && je.dist < jf.dist) {
							pooop = je;
						}
						else if (jf.dist < je.dist && jf.dist < jd.dist) {
							pooop = jf;
						}
					}
				}
				else if (jf.valid) {//s & sf
					if (jd.dist < jf.dist)
						pooop = jd;
					else if (jf.dist < jd.dist)
						pooop = jf;
				}
			}
			else if (je.valid) {
				if (jf.valid) {//m & sf
					if (je.dist < jf.dist)
						pooop = je;
					else if (jf.dist < je.dist)
						pooop = jf;
				}
				else
					pooop = je;
			}
			else if (jf.valid) {
				pooop = jf;
			}

			if (jg.valid) {
				if (jh.valid) {
					if (ji.valid) {//s & m & sf
						if (jg.dist < jh.dist && jg.dist < ji.dist) {
							poooop = jg;
						}
						else if (jh.dist < jg.dist && jh.dist < ji.dist) {
							poooop = jh;
						}
						else if (ji.dist < jh.dist && ji.dist < jg.dist) {
							poooop = ji;
						}
					}
				}
				else if (ji.valid) {//s & sf
					if (jg.dist < ji.dist)
						poooop = jg;
					else if (ji.dist < jg.dist)
						poooop = ji;
				}
			}
			else if (jh.valid) {
				if (ji.valid) {//m & sf
					if (jh.dist < ji.dist)
						poooop = jh;
					else if (ji.dist < jh.dist)
						poooop = ji;
				}
				else
					poooop = jh;
			}
			else if (ji.valid) {
				poooop = ji;
			}

			if (poop.valid) {
				if (pooop.valid) {
					if (poooop.valid) {//s & m & sf
						if (poop.dist < pooop.dist && poop.dist < poooop.dist) {
							shitcode = poop;
						}
						else if (pooop.dist < poop.dist && pooop.dist < poooop.dist) {
							shitcode = pooop;
						}
						else if (poooop.dist < pooop.dist && poooop.dist < poop.dist) {
							shitcode = poooop;
						}
					}
				}
				else if (poooop.valid) {//s & sf
					if (poop.dist < poooop.dist)
						shitcode = poop;
					else if (poooop.dist < poop.dist)
						shitcode = poooop;
				}
			}
			else if (pooop.valid) {
				if (poooop.valid) {//m & sf
					if (pooop.dist < poooop.dist)
						shitcode = pooop;
					else if (poooop.dist < pooop.dist)
						shitcode = poooop;
				}
				else
					shitcode = pooop;
			}
			else if (poooop.valid) {
				shitcode = poooop;
			}

			if (shitcode.valid) {
				return shitcode;
			}
			else {
				return jj;
			}
		}
		return AimResult::AimResult();
	}

	static AimResult GetBarrel() {
		//loot_barrel_1
		//loot_barrel_2
		//loot-barrel-1
		//loot-barrel-2
		//oil_barrel
		AimResult loot_barrel_1 = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("loot_barrel_1.prefab"));
		AimResult loot_barrel_2 = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("loot_barrel_2.prefab"));
		AimResult oil_barrel = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("oil_barrel.prefab"));
		AimResult barrel1 = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("loot-barrel-1.prefab"));
		AimResult barrel2 = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("loot-barrel-2.prefab"));

		AimResult aba;
		AimResult bab;

		if (loot_barrel_1.valid) {
			if (loot_barrel_2.valid) {
				if (oil_barrel.valid) {//s & m & sf
					if (loot_barrel_1.dist < loot_barrel_2.dist && loot_barrel_1.dist < oil_barrel.dist) {
						aba = loot_barrel_1;
					}
					else if (loot_barrel_2.dist < loot_barrel_1.dist && loot_barrel_2.dist < oil_barrel.dist) {
						aba = loot_barrel_2;
					}
					else if (oil_barrel.dist < loot_barrel_2.dist && oil_barrel.dist < loot_barrel_1.dist) {
						aba = oil_barrel;
					}
				}
			}
			else if (oil_barrel.valid) {//s & sf
				if (loot_barrel_1.dist < oil_barrel.dist)
					aba = loot_barrel_1;
				else if (oil_barrel.dist < loot_barrel_1.dist)
					aba = oil_barrel;
			}
		}
		else if (loot_barrel_2.valid) {
			if (oil_barrel.valid) {//m & sf
				if (loot_barrel_2.dist < oil_barrel.dist)
					aba = loot_barrel_2;
				else if (oil_barrel.dist < loot_barrel_2.dist)
					aba = oil_barrel;
			}
			else
				aba = loot_barrel_2;
		}
		else if (oil_barrel.valid) {
			aba = oil_barrel;
		}

		if (barrel1.valid) {
			if (barrel2.valid) {
				if (barrel1.dist < barrel2.dist) {
					bab = barrel1;
				}
				else {
					bab = barrel2;
				}
			}
			else {
				bab = barrel1;
			}
		}
		//else bab = AimResult::AimResult();

		if (aba.valid) {
			if (bab.valid) {
				if (aba.dist < bab.dist) {
					return aba;
				}
				else {
					return bab;
				}
			}
			else {
				return aba;
			}
		}

		return AimResult::AimResult();
	}
};

void Circle3D(Vector3 pos, Color clr, float radius, float penis = 0) {
	Vector3 prev = Vector3(pos.x + radius, pos.y, pos.z);
	for (float num = 0.f; num < 6.2831855f; num += 0.05f) {

		float val_x = Maths::m_Cos(num) * radius;
		float val_z = Maths::m_Sin(num) * radius;
		Vector3 newPos = Vector3(pos.x + val_x, pos.y + penis, pos.z + val_z);

		Classes::DDrawLine(prev, newPos, clr, 0.01, false, true);

		prev = newPos;
	}
}

float MaxMeleeDist(DWORD64 melee, bool localplayer) {
	float pad = 0.1f;
	typedef float(__stdcall* RetF)();
	float time = Unity::get_time();

	float desyncTime = max(time - LocalPlayer->lastSentTickTime() - 0.0325f, 0.f);
	float res = pad + desyncTime * 5.5f;
	if (localplayer) {
		res += (1.5f * safe_read(melee + O::BaseMelee::maxDistance, float));
	}
	return max(res, 0.05f);
}

class TickInterpolator
{
public:

	Vector3 StartPoint()
	{
		return  Read<Vector3>((DWORD64)this + 0x2C);
	}

	Vector3 EndPoint()
	{
		return  Read<Vector3>((DWORD64)this + 0x38);
	}
};

class DamageTypeList
{
public:

};






class HitInfo {
public:


	void Initiator(BasePlayer* entity) { Write<BasePlayer*>((DWORD64)this + O::HitInfo::Initiator, entity); }
	void ProjectileID(int id) { Write<int>((DWORD64)this + O::HitInfo::ProjectileID, id); }
	void ProjectileDistance(float id) { Write<float>((DWORD64)this + O::HitInfo::ProjectileDistance, id); }
	void ProjectileVelocity(Vector3 id) { Write<Vector3>((DWORD64)this + O::HitInfo::ProjectileVelocity, id); }
	void ProjectilePrefab(uint32_t id) { Write<uint32_t>((DWORD64)this + O::HitInfo::ProjectilePrefab, id); }
	void IsPredicting(bool id) { Write<bool>((DWORD64)this + O::HitInfo::IsPredicting, id); } // DoDecals
	void WeaponPrefab(uint32_t id) { Write<uint32_t>((DWORD64)this + O::HitInfo::IsPredicting, id); }
	void DoDecals(uint32_t id) { Write<uint32_t>((DWORD64)this + O::HitInfo::IsPredicting, id); }

	// int ProjectileHits(int id) { Write<int>((DWORD64)this + O::HitInfo::ProjectileHits, id); }
	// ProjectileHits

	/////////////// THE FUN PART - THE HIT PART ///////////////

	void HitMaterial(unsigned int material) {
		Write<unsigned int>((DWORD64)this + +O::HitInfo::HitMaterial, material); // 0xc0
	}

	void DidHit(bool did_hit) { Write<bool>((DWORD64)this + O::HitInfo::DidHit, did_hit); }
	void HitPart(unsigned int i) { Write<unsigned int>((DWORD64)this + O::HitInfo::HitPart, i); }
	void HitBone(unsigned int i) { Write<unsigned int>((DWORD64)this + O::HitInfo::HitBone, i); } // HitMaterial
	void HitPositionWorld(Vector3 i) { Write<Vector3>((DWORD64)this + O::HitInfo::HitPositionWorld, i); }
	Vector3 HitPositionWorld() { return Read<Vector3>((DWORD64)this + O::HitInfo::HitPositionWorld); }
	void HitPositionLocal(Vector3 i) { Write<Vector3>((DWORD64)this + O::HitInfo::HitPositionLocal, i); }
	void HitNormalWorld(Vector3 i) { Write<Vector3>((DWORD64)this + O::HitInfo::HitNormalWorld, i); }
	void HitNormalLocal(Vector3 i) { Write<Vector3>((DWORD64)this + O::HitInfo::HitNormalLocal, i); }
	// ProjectileHits
	void ProjectileHits(int i) { Write<int>((DWORD64)this + O::HitInfo::ProjectileHits, i); }
	void PointStart(Vector3 i) { Write<Vector3>((DWORD64)this + O::HitInfo::PointStart, i); }
	void PointEnd(Vector3 i) { Write<Vector3>((DWORD64)this + O::HitInfo::PointEnd, i); }

	//void PointEnd(Vector3 i) { Write<Vector3>((DWORD64)this + O::HitInfo::PointEnd, i); }
	float ProjectileDistance() { return Read<float>((DWORD64)this + O::HitInfo::ProjectileDistance); }

	void HitEntity(BasePlayer* entity) { Write<BasePlayer*>((DWORD64)this + O::HitInfo::HitEntity, entity); }


	/*void HitTransform(Transform* hit_transform) { Write<Transform*>((DWORD64)this + O::HitInfo::HitTransform, hit_transform); }
	Transform* HitTransform() { return Read<Transform*>((DWORD64)this + O::HitInfo::HitTransform); }
	void AttackRay(Ray ray) { Write<Ray>((DWORD64)this + O::HitInfo::AttackRay, ray); }
	Ray* AttackRay() { return Read<Ray*>((DWORD64)this + O::HitInfo::AttackRay); }
	void Radius(float radius) { Write<float>((DWORD64)this + O::HitInfo::Radius, radius); }
	void Frogivness(float radius) { Write<float>((DWORD64)this + O::HitInfo::Forgiveness, radius); }

	void IgnoreEntity(BasePlayer* entity_to_ignore) {
		Write<BasePlayer*>((DWORD64)this + O::HitInfo::ignoreEntity, entity_to_ignore);
	}

	void DamageProperties(DWORD64 damage_properties) { Write<DWORD64>((DWORD64)this + O::HitInfo::damageProperties, damage_properties); }
	void MaxDistance(float max_dist) { Write<float>((DWORD64)this + O::HitInfo::MaxDistance, max_dist); }
	float MaxDistance() { return Read<float>((DWORD64)this + O::HitInfo::MaxDistance); }
	void BestHit(bool best_hit) { Write<bool>((DWORD64)this + O::HitInfo::BestHit, best_hit); }
	void HitPoint(Vector3 ray) { Write<Vector3>((DWORD64)this + O::HitInfo::HitPoint, ray); }
	Vector3 HitPoint() { return Read<Vector3>((DWORD64)this + O::HitInfo::HitPoint); }
	void HitNormal(Vector3 ray2) { Write<Vector3>((DWORD64)this + O::HitInfo::HitNormal, ray2); }
	Vector3 HitNormal() { return Read<Vector3>((DWORD64)this + O::HitInfo::HitNormal); }
	void HitDistance(float max_dist) { Write<float>((DWORD64)this + O::HitInfo::HitDistance, max_dist); }*/
};

class Performance {
public:
	static class Tick {
	public:
		int frameID; // 0x0
		int frameRate; // 0x4
		float frameTime; // 0x8
		float frameRateAverage; // 0xC
		float frameTimeAverage; // 0x10
		long memoryUsageSystem; // 0x18
		long memoryAllocations; // 0x20
		long memoryCollections; // 0x28
		long loadBalancerTasks; // 0x30
		long invokeHandlerTasks; // 0x38
		long workshopSkinsQueued; // 0x40
		int ping; // 0x48
		bool gcTriggered; // 0x4C
		//PerformanceSamplePoint performanceSample; // 0x50
	};

	static Tick* current() {
		return *reinterpret_cast<Tick**>(((uintptr_t)Il2cpp::InitClass(_("Performance"), _("")) + 0xB8) + 0x0);
	}

	static int frames() {
		return *reinterpret_cast<int*>(((uintptr_t)Il2cpp::InitClass(_("Performance"), _("")) + 0xB8) + 0x18);
	}
};

int GetPingMs() {
	auto thang = Performance::current();
	if (thang) {
		return thang->ping;
	}
	return 0;
}

int GetFramesMs() {
	auto thang = Performance::frames();
	if (thang) {
		return thang;
	}
	return 0;
}