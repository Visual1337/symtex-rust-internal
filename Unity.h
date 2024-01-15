#pragma once

enum class Layers
{
	z = 1503731969,
	Terrain = 8388608,
	World = 65536,
	Ragdolls = 512,
	Construction = 2097152,
	ConstructionSocket = 4194304,
	Craters = 1,
	GameTrace = 16384,
	Trigger = 262144,
	VehiclesDetailed = 8192,
	RainFall = 1101070337,
	Deploy = 1235288065,
	DefaultDeployVolumeCheck = 537001984,
	BuildLineOfSightCheck = 2097152,
	ProjectileLineOfSightCheck = 2162688,
	ProjectileLineOfSightCheckTerrain = 10551296,
	MeleeLineOfSightCheck = 2162688,
	EyeLineOfSightCheck = 2162688,
	EntityLineOfSightCheck = 1218519041,
	PlayerBuildings = 18874624,
	PlannerPlacement = 161546496,
	Solid = 1218652417,
	VisCulling = 10551297,
	AltitudeCheck = 1218511105,
	HABGroundEffect = 1218511105,
	AILineOfSight = 1218519297,
	DismountCheck = 1486946561,
	AIPlacement = 278986753,
	WheelRay = 1235321089,
};

class BaseEntity {
public:
	enum class Signal {
		Attack,
		Alt_Attack,
		DryFire,
		Reload,
		Deploy,
		Flinch_Head,
		Flinch_Chest,
		Flinch_Stomach,
		Flinch_RearHead,
		Flinch_RearTorso,
		Throw,
		Relax,
		Gesture,
		PhysImpact,
		Eat,
		Startled
	};
};

enum class TextureCreationFlags // TypeDefIndex: 10757
{
	None = 0,
	MipChain = 1,
	Crunch = 64,
};

enum GraphicsFormat // TypeDefIndex: 10760
{
	None = 0,
	R8_SRGB = 1,
	R8G8_SRGB = 2,
	R8G8B8_SRGB = 3,
	R8G8B8A8_SRGB = 4,
	R8_UNorm = 5,
	R8G8_UNorm = 6,
	R8G8B8_UNorm = 7,
	R8G8B8A8_UNorm = 8,
	R8_SNorm = 9,
	R8G8_SNorm = 10,
	R8G8B8_SNorm = 11,
	R8G8B8A8_SNorm = 12,
	R8_UInt = 13,
	R8G8_UInt = 14,
	R8G8B8_UInt = 15,
	R8G8B8A8_UInt = 16,
	R8_SInt = 17,
	R8G8_SInt = 18,
	R8G8B8_SInt = 19,
	R8G8B8A8_SInt = 20,
	R16_UNorm = 21,
	R16G16_UNorm = 22,
	R16G16B16_UNorm = 23,
	R16G16B16A16_UNorm = 24,
	R16_SNorm = 25,
	R16G16_SNorm = 26,
	R16G16B16_SNorm = 27,
	R16G16B16A16_SNorm = 28,
	R16_UInt = 29,
	R16G16_UInt = 30,
	R16G16B16_UInt = 31,
	R16G16B16A16_UInt = 32,
	R16_SInt = 33,
	R16G16_SInt = 34,
	R16G16B16_SInt = 35,
	R16G16B16A16_SInt = 36,
	R32_UInt = 37,
	R32G32_UInt = 38,
	R32G32B32_UInt = 39,
	R32G32B32A32_UInt = 40,
	R32_SInt = 41,
	R32G32_SInt = 42,
	R32G32B32_SInt = 43,
	R32G32B32A32_SInt = 44,
	R16_SFloat = 45,
	R16G16_SFloat = 46,
	R16G16B16_SFloat = 47,
	R16G16B16A16_SFloat = 48,
	R32_SFloat = 49,
	R32G32_SFloat = 50,
	R32G32B32_SFloat = 51,
	R32G32B32A32_SFloat = 52,
	B8G8R8_SRGB = 56,
	B8G8R8A8_SRGB = 57,
	B8G8R8_UNorm = 58,
	B8G8R8A8_UNorm = 59,
	B8G8R8_SNorm = 60,
	B8G8R8A8_SNorm = 61,
	B8G8R8_UInt = 62,
	B8G8R8A8_UInt = 63,
	B8G8R8_SInt = 64,
	B8G8R8A8_SInt = 65,
	R4G4B4A4_UNormPack16 = 66,
	B4G4R4A4_UNormPack16 = 67,
	R5G6B5_UNormPack16 = 68,
	B5G6R5_UNormPack16 = 69,
	R5G5B5A1_UNormPack16 = 70,
	B5G5R5A1_UNormPack16 = 71,
	A1R5G5B5_UNormPack16 = 72,
	E5B9G9R9_UFloatPack32 = 73,
	B10G11R11_UFloatPack32 = 74,
	A2B10G10R10_UNormPack32 = 75,
	A2B10G10R10_UIntPack32 = 76,
	A2B10G10R10_SIntPack32 = 77,
	A2R10G10B10_UNormPack32 = 78,
	A2R10G10B10_UIntPack32 = 79,
	A2R10G10B10_SIntPack32 = 80,
	A2R10G10B10_XRSRGBPack32 = 81,
	A2R10G10B10_XRUNormPack32 = 82,
	R10G10B10_XRSRGBPack32 = 83,
	R10G10B10_XRUNormPack32 = 84,
	A10R10G10B10_XRSRGBPack32 = 85,
	A10R10G10B10_XRUNormPack32 = 86,
	D16_UNorm = 90,
	D24_UNorm = 91,
	D24_UNorm_S8_UInt = 92,
	D32_SFloat = 93,
	D32_SFloat_S8_UInt = 94,
	S8_UInt = 95,
	RGB_DXT1_SRGB = 96,
	RGBA_DXT1_SRGB = 96,
	RGB_DXT1_UNorm = 97,
	RGBA_DXT1_UNorm = 97,
	RGBA_DXT3_SRGB = 98,
	RGBA_DXT3_UNorm = 99,
	RGBA_DXT5_SRGB = 100,
	RGBA_DXT5_UNorm = 101,
	R_BC4_UNorm = 102,
	R_BC4_SNorm = 103,
	RG_BC5_UNorm = 104,
	RG_BC5_SNorm = 105,
	RGB_BC6H_UFloat = 106,
	RGB_BC6H_SFloat = 107,
	RGBA_BC7_SRGB = 108,
	RGBA_BC7_UNorm = 109,
	RGB_PVRTC_2Bpp_SRGB = 110,
	RGB_PVRTC_2Bpp_UNorm = 111,
	RGB_PVRTC_4Bpp_SRGB = 112,
	RGB_PVRTC_4Bpp_UNorm = 113,
	RGBA_PVRTC_2Bpp_SRGB = 114,
	RGBA_PVRTC_2Bpp_UNorm = 115,
	RGBA_PVRTC_4Bpp_SRGB = 116,
	RGBA_PVRTC_4Bpp_UNorm = 117,
	RGB_ETC_UNorm = 118,
	RGB_ETC2_SRGB = 119,
	RGB_ETC2_UNorm = 120,
	RGB_A1_ETC2_SRGB = 121,
	RGB_A1_ETC2_UNorm = 122,
	RGBA_ETC2_SRGB = 123,
	RGBA_ETC2_UNorm = 124,
	R_EAC_UNorm = 125,
	R_EAC_SNorm = 126,
	RG_EAC_UNorm = 127,
	RG_EAC_SNorm = 128,
	RGBA_ASTC4X4_SRGB = 129,
	RGBA_ASTC4X4_UNorm = 130,
	RGBA_ASTC5X5_SRGB = 131,
	RGBA_ASTC5X5_UNorm = 132,
	RGBA_ASTC6X6_SRGB = 133,
	RGBA_ASTC6X6_UNorm = 134,
	RGBA_ASTC8X8_SRGB = 135,
	RGBA_ASTC8X8_UNorm = 136,
	RGBA_ASTC10X10_SRGB = 137,
	RGBA_ASTC10X10_UNorm = 138,
	RGBA_ASTC12X12_SRGB = 139,
	RGBA_ASTC12X12_UNorm = 140,
	YUV2 = 141,
	DepthAuto = 142,

	ShadowAuto = 143,

	VideoAuto = 144,
	RGBA_ASTC4X4_UFloat = 145,
	RGBA_ASTC5X5_UFloat = 146,
	RGBA_ASTC6X6_UFloat = 147,
	RGBA_ASTC8X8_UFloat = 148,
	RGBA_ASTC10X10_UFloat = 149,
	RGBA_ASTC12X12_UFloat = 150,
};

enum BoneList : int
{
	l_hip = 1,
	l_knee,
	l_foot,
	l_toe,
	l_ankle_scale,
	pelvis,
	penis,
	GenitalCensor,
	GenitalCensor_LOD0,
	Inner_LOD0,
	GenitalCensor_LOD1,
	GenitalCensor_LOD2,
	r_hip,
	r_knee,
	r_foot,
	r_toe,
	r_ankle_scale,
	spine1,
	spine1_scale,
	spine2,
	spine3,
	spine4,
	l_clavicle,
	l_upperarm,
	l_forearm,
	l_hand,
	l_index1,
	l_index2,
	l_index3,
	l_little1,
	l_little2,
	l_little3,
	l_middle1,
	l_middle2,
	l_middle3,
	l_prop,
	l_ring1,
	l_ring2,
	l_ring3,
	l_thumb1,
	l_thumb2,
	l_thumb3,
	IKtarget_righthand_min,
	IKtarget_righthand_max,
	l_ulna,
	neck,
	head,
	jaw,
	eyeTranform,
	l_eye,
	l_Eyelid,
	r_eye,
	r_Eyelid,
	r_clavicle,
	r_upperarm,
	r_forearm,
	r_hand,
	r_index1,
	r_index2,
	r_index3,
	r_little1,
	r_little2,
	r_little3,
	r_middle1,
	r_middle2,
	r_middle3,
	r_prop,
	r_ring1,
	r_ring2,
	r_ring3,
	r_thumb1,
	r_thumb2,
	r_thumb3,
	IKtarget_lefthand_min,
	IKtarget_lefthand_max,
	r_ulna,
	l_breast,
	r_breast,
	BoobCensor,
	BreastCensor_LOD0,
	BreastCensor_LOD1,
	BreastCensor_LOD2,
	collision,
	displacement
};

enum class KeyCode
{

	Backspace = 8,
	Delete = 127,
	Tab = 9,
	Clear = 12,
	Return = 13,
	Pause = 19,
	Escape = 27,
	Space = 32,
	Keypad0 = 256,
	Keypad1 = 257,
	Keypad2 = 258,
	Keypad3 = 259,
	Keypad4 = 260,
	Keypad5 = 261,
	Keypad6 = 262,
	Keypad7 = 263,
	Keypad8 = 264,
	Keypad9 = 265,
	KeypadPeriod = 266,
	KeypadDivide = 267,
	KeypadMultiply = 268,
	KeypadMinus = 269,
	KeypadPlus = 270,
	KeypadEnter = 271,
	KeypadEquals = 272,
	UpArrow = 273,
	DownArrow = 274,
	RightArrow = 275,
	LeftArrow = 276,
	Insert = 277,
	Home = 278,
	End = 279,
	PageUp = 280,
	PageDown = 281,
	F1 = 282,
	F2 = 283,
	F3 = 284,
	F4 = 285,
	F5 = 286,
	F6 = 287,
	F7 = 288,
	F8 = 289,
	F9 = 290,
	F10 = 291,
	F11 = 292,
	F12 = 293,
	F13 = 294,
	F14 = 295,
	F15 = 296,
	Alpha0 = 48,
	Alpha1 = 49,
	Alpha2 = 50,
	Alpha3 = 51,
	Alpha4 = 52,
	Alpha5 = 53,
	Alpha6 = 54,
	Alpha7 = 55,
	Alpha8 = 56,
	Alpha9 = 57,
	Exclaim = 33,
	DoubleQuote = 34,
	Hash = 35,
	Dollar = 36,
	Percent = 37,
	Ampersand = 38,
	Quote = 39,
	LeftParen = 40,
	RightParen = 41,
	Asterisk = 42,
	Plus = 43,
	Comma = 44,
	Minus = 45,
	Period = 46,
	Slash = 47,
	Colon = 58,
	Semicolon = 59,
	Less = 60,
	Equals = 61,
	Greater = 62,
	Question = 63,
	At = 64,
	LeftBracket = 91,
	Backslash = 92,
	RightBracket = 93,
	Caret = 94,
	Underscore = 95,
	BackQuote = 96,
	A = 97,
	B = 98,
	C = 99,
	D = 100,
	E = 101,
	F = 102,
	G = 103,
	H = 104,
	I = 105,
	J = 106,
	K = 107,
	L = 108,
	M = 109,
	N = 110,
	O = 111,
	P = 112,
	Q = 113,
	R = 114,
	S = 115,
	T = 116,
	U = 117,
	V = 118,
	W = 119,
	X = 120,
	Y = 121,
	Z = 122,
	LeftCurlyBracket = 123,
	Pipe = 124,
	RightCurlyBracket = 125,
	Tilde = 126,
	Numlock = 300,
	CapsLock = 301,
	ScrollLock = 302,
	RightShift = 303,
	LeftShift = 304,
	RightControl = 305,
	LeftControl = 306,
	RightAlt = 307,
	LeftAlt = 308,
	LeftCommand = 310,
	LeftApple = 310,
	LeftWindows = 311,
	RightCommand = 309,
	RightApple = 309,
	RightWindows = 312,
	AltGr = 313,
	Help = 315,
	Pr = 316,
	SysReq = 317,
	Break = 318,
	Menu = 319,
	Mouse0 = 323,
	Mouse1 = 324,
	Mouse2 = 325,
	Mouse3 = 326,
	Mouse4 = 327,
	Mouse5 = 328,
	Mouse6 = 329,
	nothing = 0
};

enum class layer : uint32_t {
	Default = 0,
	TransparentFX = 1,
	Ignore_Raycast = 2,
	Reserved1 = 3,
	Water = 4,
	UI = 5,
	Reserved2 = 6,
	Reserved3 = 7,
	Deployed = 8,
	Ragdoll = 9,
	Invisible = 10,
	AI = 11,
	PlayerMovement = 12,
	Vehicle_Detailed = 13,
	Game_Trace = 14,
	Vehicle_World = 15,
	World = 16,
	Player_Server = 17,
	Trigger = 18,
	Player_Model_Rendering = 19,
	Physics_Projectile = 20,
	Construction = 21,
	Construction_Socket = 22,
	Terrain = 23,
	Transparent = 24,
	Clutter = 25,
	Debris = 26,
	Vehicle_Large = 27,
	Prevent_Movement = 28,
	Prevent_Building = 29,
	Tree = 30,
	Unused2 = 31,
	//Pierce = 10551296
};

enum QueryTriggerInteraction
{
	UseGlobal,
	Ignore,
	Collide
};


Matrix4x4* pViewMatrix = nullptr;

template<typename T>
class GameList {
public:
	T Get(uint32_t idx)
	{
		const auto internal_list = reinterpret_cast<uintptr_t>(this + 0x20);
		return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
	}
	T GetValue(uint32_t idx) {
		const auto list = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
		const auto internal_list = list + 0x20;
		return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
	}
	T operator[](uint32_t idx) { return Get(idx); }
	const uint32_t GetSize() { return *reinterpret_cast<uint32_t*>((uintptr_t)this + 0x18); }
	template<typename F>
	void ForEach(const F callback) {
		for (auto i = 0; i < GetSize(); i++) {
			auto object = this->Get(i);
			if (!object) continue;
			callback(object, i);
		}
	}
};

struct Ray {
	Vector3 origin;
	Vector3 dir;
	Ray(Vector3 o, Vector3 d) {
		origin = o;
		dir = d;
	}
};
class RaycastHit {
public:
	Vector3 point;
	Vector3 normal;
	RaycastHit()
	{
		point = Vector3::Zero();
		normal = Vector3::Zero();
	}
};

//// RVA: 0x19DFA10 Offset: 0x19DE610 VA: 0x1819DFA10
//public static string Format(string format, object arg0) { }
//
//// RVA: 0x19DFC50 Offset: 0x19DE850 VA: 0x1819DFC50
//public static string Format(string format, object arg0, object arg1) { }
//
//// RVA: 0x19DF900 Offset: 0x19DE500 VA: 0x1819DF900
//public static string Format(string format, object arg0, object arg1, object arg2) { }
//
//// RVA: 0x19DF780 Offset: 0x19DE380 VA: 0x1819DF780
//public static string Format(string format, object[] args) { }

DWORD64 ForceField_shader = 0;
DWORD64 chams_shader = 0;
DWORD64 xray_shader = 0;
DWORD64 hologram_shader = 0;
DWORD64 Galaxymaterial = NULL;
DWORD64 StormShader = NULL;
DWORD64 FlatShader = NULL;
DWORD64 StandardMat = NULL;
// Blue
DWORD64 GalaxyPink = NULL;
DWORD64 GalaxyRed = NULL;
DWORD64 GalaxyGreen = NULL;
DWORD64 GalaxyBlue = NULL;
DWORD64 Test_Bundle = NULL;
DWORD64 Test_Bundle_Shader = NULL;

DWORD64 Test_Bundle1 = NULL;
DWORD64 Test_Bundle2 = NULL;
DWORD64 Test_Bundle2_shader = NULL;

DWORD64 Harvey = NULL;
DWORD64 Harvey_shader = NULL;
DWORD64 FireBundleA = NULL;
DWORD64 FireShaderA = NULL;
DWORD64 FireMaterialA = NULL;


namespace Unity
{
	auto get_keyCode = reinterpret_cast<KeyCode(*)(DWORD64)>(0);
	auto get_keyCodeInt = reinterpret_cast<int(*)(DWORD64)>(0);
	auto set_material = reinterpret_cast<DWORD64(*)(DWORD64, DWORD64)>(0);
	auto set_int = reinterpret_cast<void(*)(DWORD64, Str, int)>(0);

	auto get_main_camera = reinterpret_cast<DWORD64(*)()>(0);
	auto GUIDToObject = reinterpret_cast<DWORD64(*)(DWORD64)>(0);
	auto get_aspect = reinterpret_cast<float(*)(DWORD64)>(0);

	auto aspect = reinterpret_cast<void(*)(DWORD64, float)>(0);

	auto Raycast = reinterpret_cast<bool (*)(Ray, float, int)>(0);


	// RVA: 0x19DF900 Offset: 0x19DE500 VA: 0x1819DF900
	// public static string Format(string format, object arg0, object arg1, object arg2) { }
	auto Format = reinterpret_cast<Str(*)(wchar_t*, wchar_t*, wchar_t*, wchar_t*)> (0);
	auto UnloadBundle = reinterpret_cast<void (*)(DWORD64, bool)>(0);
	// RVA: 0x25ADAB0 Offset: 0x25ACAB0 VA: 0x1825ADAB0
	//public static bool Raycast(Vector3 origin, Vector3 direction, out RaycastHit hitInfo, float maxDistance, int layerMask, QueryTriggerInteraction queryTriggerInteraction) { }
	auto RaycastBig = reinterpret_cast<bool (*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>(0);
	auto LoadAsset = reinterpret_cast<DWORD64(*)(DWORD64, Str, DWORD64)>(0);
	auto IgnoreLayerCollision = reinterpret_cast<void(*)(layer, layer, bool)>(0);
	auto RealtimeSinceStartup = reinterpret_cast<float(*)()>(0);
	auto GetKey = reinterpret_cast<bool(*)(KeyCode)>(*reinterpret_cast<DWORD64*>(0));
	auto GetKeyInt = reinterpret_cast<bool(*)(int)>(*reinterpret_cast<DWORD64*>(0));
	auto CheckCapsule = reinterpret_cast<bool (*)(Vector3, Vector3, float, int, int)>(0);
	//	auto get_keyCode = reinterpret_cast<KeyCode(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(0));
	// UnityEngine.Camera::set_fieldOfView
	auto set_fieldOfView = reinterpret_cast<void(*)(DWORD64,float)>(Il2cpp::resolve_icall(_("UnityEngine.Camera::set_fieldOfView()")));
	auto LoadFromFile = reinterpret_cast<DWORD64(*)(Str)>(0);
	auto LoadFromMemory = reinterpret_cast<DWORD64(*)(DWORD64)>(0);
	auto GetComponentsInChildren = reinterpret_cast<GameList<DWORD64>*(*)(DWORD64, DWORD64)>(0);
	//auto GetComponents = reinterpret_cast<List<DWORD64>*(*)(DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(0));
	auto FloorToInt = reinterpret_cast<int (*)(float)>(0);
	auto get_gravity = reinterpret_cast<Vector3(*)()>(0);
	auto get_width = reinterpret_cast<int(*)()>(0);

	auto get_height = reinterpret_cast<int(*)()>(0);
	auto get_deltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(0));

	auto get_smoothDeltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(0));

	auto get_fixedDeltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(0));

	auto get_IsNpc = reinterpret_cast<bool(*)(DWORD64)>(0);

	auto get_time = reinterpret_cast<float(*)()>(0);
	// aspect = reinterpret_cast<void(*)(DWORD64, float)>(Il2cpp::resolve_icall(_("UnityEngine.Camera::set_aspect()")));
	auto ObjectComponent = reinterpret_cast<UINT_PTR(*)(UINT_PTR, UINT_PTR)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GameObject"), _("GetComponent"), 1, _("type"), _("UnityEngine"))));
	auto get_timeScale = reinterpret_cast<float(*)()>(0);
	auto get_fixedTime = reinterpret_cast<float(*)()>(0);
	auto LineOfSight = reinterpret_cast<bool(*)(Vector3, Vector3, int, float, float, DWORD64)>(0);
	auto GetMouseButtonMeth = reinterpret_cast<bool(*)(int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Input"), _("GetMouseButton"), 0, _(""), _("UnityEngine"))));
	void InitUnity()
	{


		set_fieldOfView = reinterpret_cast<void(*)(DWORD64, float)>(Il2cpp::resolve_icall(_("UnityEngine.Camera::set_fieldOfView()")));
		UnloadBundle = reinterpret_cast<void (*)(DWORD64, bool)>((DWORD64)(g_Base + offsets::o_Unload))/*g_Base + 0x253B290*/; //  public void Unload(bool unloadAllLoadedObjects) { }
		// Format = reinterpret_cast<Str(*)(wchar_t*, wchar_t*, wchar_t*, wchar_t*)> ((DWORD64)(g_Base + 0x19DF900));
		get_width = reinterpret_cast<int (*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Screen"), _("get_width"), 0, _(""), _("UnityEngine"))));
		RaycastBig = reinterpret_cast<bool (*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>((DWORD64)(g_Base + offsets::o_RaycastBig));// 0x25C8100
		Raycast = reinterpret_cast<bool(*)(Ray, float, int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Physics"), _("Raycast"), 0, _(""), _("UnityEngine"))));// reinterpret_cast<bool (*)(Ray, float, int)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Physics"), _("Raycast"), 0, _(""), _("UnityEngine"))));
		get_height = reinterpret_cast<int (*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Screen"), _("get_height"), 0, _(""), _("UnityEngine"))));

		ObjectComponent = reinterpret_cast<UINT_PTR(*)(UINT_PTR, UINT_PTR)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GameObject"), _("GetComponent"), 1, _("type"), _("UnityEngine"), 1)));
		GUIDToObject = reinterpret_cast<DWORD64(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GameManifest"), _("GUIDToObject"), 1, _(""), _(""))));
		GetContain = reinterpret_cast<bool(*)(Str*, Str)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("String"), _("Contains"), -1, _(""), _("System"))));
		FloorToInt = reinterpret_cast<int (*)(float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Mathf"), _("FloorToInt"), 1, _(""), _("UnityEngine"))));
		IgnoreLayerCollision = reinterpret_cast<void(*)(layer, layer, bool)>(Il2cpp::resolve_icall(_("UnityEngine.Physics::IgnoreLayerCollision()")));
		get_keyCode = reinterpret_cast<KeyCode(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Event"), _("get_keyCode"), 0, _(""), _("UnityEngine"))));
		get_keyCodeInt = reinterpret_cast<int(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Event"), _("get_keyCode"), 0, _(""), _("UnityEngine"))));
		set_material = reinterpret_cast<DWORD64(*)(DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Renderer"), _("set_material"), 0, _(""), _("UnityEngine"))));
		set_int = reinterpret_cast<void(*)(DWORD64, Str, int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Material"), _("SetInt"), 1, _(""), _("UnityEngine"))));

		GetMouseButtonMeth = reinterpret_cast<bool(*)(int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Input"), _("GetMouseButton"), 0, _(""), _("UnityEngine"))));
		CheckCapsule = reinterpret_cast<bool (*)(Vector3, Vector3, float, int, int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GamePhysics"), _("CheckCapsule"), 0, _(""), _(""))));
		RealtimeSinceStartup = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Time"), _("get_realtimeSinceStartup"), 0, _(""), _("UnityEngine"))));

		get_gravity = reinterpret_cast<Vector3(*)()>(*reinterpret_cast<DWORD64*>((Il2cpp::Method(_("Physics"), _("get_gravity"), 1, _(""), _("UnityEngine")))));
		LoadFromMemory = reinterpret_cast<DWORD64(*)(DWORD64)>(Il2cpp::resolve_icall(_("UnityEngine.AssetBundle.LoadFromMemory()")));
		//set_timeScale = reinterpret_cast<void(*)(float)>(*reinterpret_cast<DWORD64*>(il2cpp::method(_("Time"), _("set_timeScale"), 1, _(""), _("UnityEngine"))));
		get_timeScale = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Time"), _("get_timeScale"), 0, _(""), _("UnityEngine"))));

		get_fixedTime = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Time"), _("get_fixedTime"), 0, _(""), _("UnityEngine"))));
		get_fixedDeltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Time"), _("get_fixedDeltaTime"), 0, _(""), _("UnityEngine"))));
		get_smoothDeltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Time"), _("get_smoothDeltaTime"), 0, _(""), _("UnityEngine"))));

		get_deltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Time"), _("get_deltaTime"), 0, _(""), _("UnityEngine"))));

		get_time = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Time"), _("get_time"), 0, _(""), _("UnityEngine"))));

		LoadAsset = reinterpret_cast<DWORD64(*)(DWORD64, Str, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("AssetBundle"), _("LoadAsset_Internal"), 2, _("name"), _("UnityEngine"), 1)));
		//get_keyCode = reinterpret_cast<KeyCode(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Event"), _("get_keyCode"), 0, _(""), _("UnityEngine"))));

		get_main_camera = reinterpret_cast<DWORD64(*)()>(Il2cpp::resolve_icall(_("UnityEngine.Camera::get_main()")));

		aspect = reinterpret_cast<void(*)(DWORD64, float)>(Il2cpp::resolve_icall(_("UnityEngine.Camera::set_aspect()")));
		get_aspect = reinterpret_cast<float(*)(DWORD64)>(Il2cpp::resolve_icall(_("UnityEngine.Camera::get_aspect()")));
		GetComponentsInChildren = reinterpret_cast<GameList<DWORD64>*(*)(DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Component"), _("GetComponentsInChildren"), 0, _(""), _("UnityEngine"))));
		LineOfSight = reinterpret_cast<bool(*)(Vector3, Vector3, int, float, float, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("GamePhysics"), _("LineOfSight"), 6, _("padding1"), _(""))));

		LoadFromFile = reinterpret_cast<DWORD64(*)(Str)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));
		//GetComponents = reinterpret_cast<List<DWORD64>*(*)(DWORD64, DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Component"), _("GetComponent"), 1, _(""), _("UnityEngine"))));
		GetKey = reinterpret_cast<bool(*)(KeyCode)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Input"), _("GetKeyInt"), 1, _(""), _("UnityEngine"))));

		GetKeyInt = reinterpret_cast<bool(*)(int)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Input"), _("GetKeyInt"), 1, _(""), _("UnityEngine"))));
	}
	float last_frame = 0.f;
	DWORD64 MyFont = 0;
	DWORD64 LogoPng = 0;
	DWORD64 LanerBundle = 0;
	// DWORD64 ChamsShader = 0;
	DWORD64 GGshader = 0;
	DWORD64 NicotineBundle = 0;
	DWORD64 Harvey = 0;
	DWORD64 test12 = 0;
	DWORD64 FireBundleA = 0;

	DWORD64 Test_Bundle = 0;
	DWORD64 sandy = 0;
	DWORD64 sandy1 = 0;

	DWORD64 ChamSlit = 0;
	DWORD64 VisCheckBundle = 0;
	//DWORD64 ChamsMaterial;
	DWORD64 PlayerChamsShader;
	DWORD64 HandsChamsShader;
	bool CanOverWriteAssets = false;

	bool CheckLOS(Vector3 source, Vector3 destination, float p1 = 0.18f, int layer = (int)Layers::ProjectileLineOfSightCheck | (int)Layers::Terrain | (int)Layers::z) {
		return LineOfSight(source, destination, layer, p1, 0, 0);
	}

	bool PerfectCheckLOS(Vector3 source, Vector3 destination, float p1 = 0.18f) {
		auto mask = 10551296 | 1503731969 | 131072 | 1218519297 | 65536 | 1218519041;
		return LineOfSight(source, destination, mask, p1, 0, 0);
	}

	static auto GetMouseButton(int A) -> bool
	{
		return GetMouseButtonMeth(A);
	}

	/*static bool CheckCapsule(Vector3 start, Vector3 end, float radius, int layerMask, QueryTriggerInteraction queryTriggerInteraction)
	{
		return reinterpret_cast<bool(*)(Vector3, Vector3, float, int, QueryTriggerInteraction)>(g_Base + Dump::UnityEngine_Physics::CheckCapsule)(start, end, radius, layerMask, queryTriggerInteraction);
	}*/

	void FindMatrix(DWORD64 StoredMainCamera) {
		auto Entity = safe_read(StoredMainCamera + 0x10, DWORD64);
		pViewMatrix = (Matrix4x4*)(Entity + 0x2E4);
		return;
	}

	void SetAspect(DWORD64 camera, float value ) {
		aspect(camera, value);
	}

	/*class EnvironmentManager {
	public:
		static EnvironmentType Get(Vector3 pos)
		{
			return reinterpret_cast<EnvironmentType(*)(Vector3)>(g_Base + 0x79FE30)(pos);
		}
	};*/

	/*template<typename T = UINT_PTR>
	T* GetComponent(UINT_PTR anus, UINT_PTR type) {
		if (!this || !type) return nullptr;
		return (T*)Classes::get_component(anus, type);
	}*/

	/*DWORD64 GUIDToObject(Str* guid) {
		typedef UINT_PTR GUIDToObject(Str*);
		return ((GUIDToObject*)(g_Base + Il2cpp::Method(_("Component"), _("GetComponent"), 1, _(""), _("UnityEngine")))(guid);
	}*/

	/*inline UINT_PTR GetClassObject(UINT_PTR pointer) {
		Str* guid = *reinterpret_cast<Str**>(pointer + 0x10);
		UINT_PTR _cachedObject = GUIDToObject(guid);
		return _cachedObject;
	}*/



	Vector3 MainCameraPos() {
		auto camera = get_main_camera();

		if (!camera) {
			camera = Unity::get_main_camera();
		}

		auto camera_ = safe_read(camera + 0x10, DWORD64);
		if (!camera_) {
			camera = Unity::get_main_camera();
			return {};
		}

		auto matrix = safe_read(camera_ + 0x42C, Vector3);
		if (!matrix.x || !matrix.y) {
			camera = Unity::get_main_camera();
			return {};
		}


		return matrix;
	}

}



