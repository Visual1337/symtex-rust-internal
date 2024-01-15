namespace ColorPicker {

	Color SkeletonsVisible;// ColorPicker::Test
	bool SkeletonsVisBool = false;
	bool SkeletonsRGBBool = false;
	//Color SkeletonsInVisible{ 230, 31, 0, 255 };// ColorPicker::Test
	Color SkeletonsInVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool SkeletonsInVisBool = false;

	Color WeaponVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool WeaponVisBool = false;
	Color WeaponInVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool WeaponInVisBool = false;

	Color ChamsVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool ChamsVisBool = false;
	Color ChamsInVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool ChamsInVisBool = false;

	Color FlagsVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool FlagsVisBool = false;
	Color FlagsInVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool FlagsInVisBool = false;


	Color BoxVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool BoxVisBool = false;
	bool BoxRGBBool = false;

	Color BoxInVisible{ 3, 221, 255, 255 };// ColorPicker::Test
	bool BoxInVisBool = false;

	Color TextEspVisible{ 3, 221, 255, 255 };// MovmentLine
	bool TextEspVisBool = false;
	Color TextEspInVisible{ 3, 221, 255, 255 };// MovmentLine
	bool TextEspInVisBool = false;
	bool TextRGBBool = false;

	Color MovmentLine{ 3, 221, 255, 255 };// MovmentLine
	bool MovmentLineBool = false;
	bool MovmentRGBBool = true;

	Color Fov{ 255, 255, 255,255 };// ColorPicker::Test
	bool FovBool = false;
	bool FovRGBBool = false;

	Color SkyColor{ 255, 80, 180,255 };// ColorPicker::Test
	bool SkyColorBool = false;
	bool SkyRGBBool = false;

	Color AmbientColor{ 255, 80, 180,255 };// ColorPicker::Test
	bool AmbientColorBool = false;
	bool AmbientRGBBool = false;

	Color BulletTracer{ 255, 255, 255,255 };// ColorPicker::Test
	bool BulletTracerBool = false;
	bool BulletRGBBool = false;

	Color OOFVisible{ 3, 221, 255, 255 };
	bool OOFVisBool = false;
	bool OOFRGBBool = false;
	float OOFPingPong = 255;

	Color OOFInVisible{ 3, 221, 255, 255 };
	bool OOFInVisBool = false;


	Color PlayerChamsVisible{ 127, 255, 0, 255 };
	bool PlayerChamsVisBool = false;
	bool PlayerChamsRGBBool = false;

	Color PlayerChamsInVisible{ 220, 20, 60, 255 };
	bool PlayerChamsInVisBool = false;

	Color HandChams{ 220, 20, 60, 255 };
	bool HandChamsBool = false;
	bool HandChamsRGBBool = false;

	Color HandChams2{ 220, 20, 60, 255 };
	bool HandChamsBool2 = false;

	Color RadarVisible{ 58, 214, 0, 255 };// ColorPicker::Test
	bool RadarVisBool = false;

	Color RadarInVisible{ 230, 31, 0, 255 };// ColorPicker::Test
	bool RadarInVisBool = false;
}


enum class configType : int {
	Save = 0,
	Load = 1,
	Delete = 2
};

bool initVal = false;
class cfgBool {
public:
	bool& value = initVal;

	inline cfgBool();
	inline cfgBool(bool& value);

};
inline cfgBool::cfgBool() {
	value = false;
}
inline cfgBool::cfgBool(bool& value)
	: value(value)
{
}

int intInitVal = 123;
class cfgInt {
public:
	int& value = intInitVal;

	inline cfgInt();
	inline cfgInt(int& value);

};
inline cfgInt::cfgInt() {
	value = 0;
}
inline cfgInt::cfgInt(int& value)
	: value(value)
{
}

float floatInitVal = 0.f;
class cfgFloat {
public:
	float& value = floatInitVal;

	inline cfgFloat();
	inline cfgFloat(float& value);

};
inline cfgFloat::cfgFloat() {
	value = 0;
}
inline cfgFloat::cfgFloat(float& value)
	: value(value)
{
}

KeyCode keyInitVal = KeyCode::nothing;
class cfgKey {
public:
	KeyCode& value = keyInitVal;

	inline cfgKey();
	inline cfgKey(KeyCode& value);

};
inline cfgKey::cfgKey() {
	value = (KeyCode)0;
}
inline cfgKey::cfgKey(KeyCode& value)
	: value(value)
{
}

Vector2 Vector2InitVal = Vector2::Zero2();
class cfgVec2 {
public:
	Vector2& value = Vector2InitVal;

	inline cfgVec2();
	inline cfgVec2(Vector2& value);

};
inline cfgVec2::cfgVec2() {
	value = Vector2::Zero2();
}
inline cfgVec2::cfgVec2(Vector2& value)
	: value(value)
{
}

#define _CRT_SECURE_DEPRECATE_MEMORY

typedef HRESULT(__stdcall* SHGFPW)(HWND hwnd, _In_ int csidl, _In_opt_ HANDLE hToken, _In_ DWORD dwFlags, _Out_writes_(MAX_PATH) LPWSTR pszPath);
SHGFPW m_SHGetFolderPathW;
typedef HANDLE(WINAPI* CFW)(_In_ LPCSTR lpFileName, _In_ DWORD dwDesiredAccess, _In_ DWORD dwShareMode, _In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes, _In_ DWORD dwCreationDisposition, _In_ DWORD dwFlagsAndAttributes, _In_opt_ HANDLE hTemplateFile);
CFW m_CreateFileA;
typedef BOOL(WINAPI* WFEX)(_In_ HANDLE hFile, _In_reads_bytes_opt_(nNumberOfBytesToWrite) LPCVOID lpBuffer, _In_ DWORD nNumberOfBytesToWrite, _Out_opt_ LPDWORD lpNumberOfBytesWritten, _Inout_opt_ LPOVERLAPPED lpOverlapped);
WFEX m_WriteFile;
typedef BOOL(WINAPI* RFEX)(_In_ HANDLE hFile, _Out_writes_bytes_to_opt_(nNumberOfBytesToRead, *lpNumberOfBytesRead) __out_data_source(FILE) LPVOID lpBuffer, _In_ DWORD nNumberOfBytesToRead, _Out_opt_ LPDWORD lpNumberOfBytesRead, _Inout_opt_ LPOVERLAPPED lpOverlapped);
RFEX m_ReadFile;
typedef BOOL(WINAPI* CH)(_In_ _Post_ptr_invalid_ HANDLE hObject);
CH m_CloseHandle;
typedef BOOL(WINAPI* DFW)(_In_ LPCWSTR lpFileName);
DFW m_DeleteFileW;
typedef BOOL(__stdcall* PFEW)(_In_ LPCWSTR pszPath);
PFEW m_PathFileExistsW;
typedef BOOL(WINAPI* GFSEX)(_In_ HANDLE hFile, _Out_ PLARGE_INTEGER lpFileSize);
GFSEX m_GetFileSizeEx;

KeyCode keytest = (KeyCode)8;
KeyCode keytest2 = (KeyCode)9;

class config {
private:
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define GENERIC_READ  (0x80000000L)
#define GENERIC_WRITE (0x40000000L)
#define CREATE_NEW          1
#define OPEN_EXISTING       3
#define FILE_ATTRIBUTE_TEMPORARY 0x00000100  

	int characterToInt(char a) {
		if (a == '\0' || a == '0') return 0;
		else if (a == '1') return 1;
		else if (a == '2') return 2;
		else if (a == '3') return 3;
		else if (a == '4') return 4;
		else if (a == '5') return 5;
		else if (a == '6') return 6;
		else if (a == '7') return 7;
		else if (a == '8') return 8;
		else if (a == '9') return 9;
		else return 0;
	}

	int getIntThisLine(char* buff, int& startNum) {
		int charAmount = 0;
		float ret = 0;
		char* final = _("");
		for (int i = startNum; i < (startNum + 100); i++) {
			startNum += 1;
			if (buff[i] == '\0' || buff[i] == '\n' || buff[i] == ' ') {
				i = startNum + 101;
				continue;
			}
			final[charAmount] = buff[i];
			charAmount += 1;
		}

		for (int i = 0; i < charAmount; i++) {
			int curCharAmm = charAmount - i;
			ret += characterToInt(final[i]) * (curCharAmm == 5 ? 10000 : (curCharAmm == 4 ? 1000 : (curCharAmm == 3 ? 100 : (curCharAmm == 2 ? 10 : 1))));
		}

		return ret;
	}

	char* m_concatenate(char* a, char* b) {
		char ret[8000];

		int curChar = 0,
			charAmount1 = m_strlen(a),
			charAmount2 = m_strlen(b);

		for (curChar = 0; curChar < charAmount1; curChar++)
			ret[curChar] = a[curChar];

		int second = 0, Zzz = charAmount1 + charAmount2;
		for (int i = charAmount1; i < Zzz; i++) {
			ret[i] = b[second];
			second += 1;
		}
		for (int i = Zzz; i < Zzz + 5; i++)
			ret[i] = '\0';

		return ret;
	}

	char* getAddText(float vall) {
		int val = (int)vall;
		char number[256];
		itoa(static_cast<int>(val), number, 10);
		return number;
	}

	void addValueToFinal(int value, char*& final, int& currentNum) {
		final = m_concatenate(final, getAddText(value));
		currentNum = m_strlen(final);

		final[currentNum] = '\n';
		currentNum += 1;
	}

	HANDLE OpenFile(const char* FileName)
	{
		HANDLE FileHandle = m_CreateFileA(FileName, GENERIC_ALL, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (FileHandle == INVALID_HANDLE_VALUE) {
			FileHandle = m_CreateFileA(FileName, GENERIC_ALL, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (FileHandle == INVALID_HANDLE_VALUE) {
				return INVALID_HANDLE_VALUE;
			}
		}
		return FileHandle;
	}

	bool writeToFile(const char* FileLocation, const char* WriteData)
	{
		DWORD WrittenBytes;
		HANDLE FileHandle = OpenFile(FileLocation);

		if (!m_WriteFile(FileHandle, WriteData, m_strlen(WriteData), &WrittenBytes, NULL))
		{
			m_CloseHandle(FileHandle);
			return false;
		}
		m_CloseHandle(FileHandle);
		return true;
	}

	const char* RFile(const char* FileLocation)
	{
		DWORD ReadBytes;
		char CharacterBuffer[4096];

		HANDLE FileHandle = OpenFile(FileLocation);

		if (!m_ReadFile(FileHandle, CharacterBuffer, 1024, &ReadBytes, NULL)) {
			m_CloseHandle(FileHandle);
			return _("-");
		}
		m_CloseHandle(FileHandle);
		return CharacterBuffer;
	}



public:

	void Config(configType type, const char* FileLocation) {

		cfgBool cfgBools[152] =
		{
			Vars::Visuals::PlayerEsp::TargetInfo,
			Vars::Visuals::PlayerEsp::TargetHotBar,
			Vars::Visuals::PlayerEsp::TeamEsp,
			Vars::Visuals::PlayerEsp::NpcEsp,
			Vars::Visuals::PlayerEsp::SleeperEsp,
			Vars::Visuals::PlayerEsp::MovmentLine,
			Vars::Visuals::PlayerEsp::OOFindicators,
			Vars::Visuals::PlayerEsp::Radar,
			Vars::Visuals::PlayerEsp::Radar_ld,
			Vars::Visuals::PlayerEsp::LookingAtU,

			Vars::Visuals::PlayerEsp::NameEsp,
			Vars::Visuals::PlayerEsp::WeaponEsp,
			Vars::Visuals::PlayerEsp::DistanceEsp,
			Vars::Visuals::PlayerEsp::LookDirection,
			Vars::Visuals::PlayerEsp::ShowPlayerFlags,
			Vars::Visuals::PlayerEsp::Skeleton,


			Vars::Weapon::FatBullet,
			Vars::Weapon::ChangeVelScale,
			Vars::Weapon::InstaEoka,
			Vars::Weapon::FullAuto,
			Vars::Misc::FakeShoot,
			Vars::Weapon::CustomHitMat,
			Vars::Weapon::SilentReload,

			Vars::Weapon::NoSway,
			Vars::Weapon::NoBob,
			Vars::Weapon::NoLower,
			Vars::Weapon::NoAnimation,
			Vars::Weapon::NoBurst,

			Vars::Visuals::DesyncBar,
			Vars::Visuals::DesyncBar,
			Vars::Aim::KeepTarget,
			Vars::Aim::pSilent,
			Vars::Aim::DrawFov,
			Vars::Exploits::MeleePsilent,
			Vars::Aim::SilentMelee,
			Vars::Visuals::PlayerEsp::TargetLine,
			Vars::Visuals::BulletTraces,
			Vars::Misc::LockToPlayersHead,
			Vars::Exploits::Manipulation,
			Vars::Exploits::AutoStopOnManipulation,
			Vars::Exploits::BehindWall,
			Vars::Exploits::AutoShoot,
			Vars::Aim::InstaKill,
			Vars::Exploits::InstaHit,
			Vars::Exploits::BulletTp,
			Vars::Exploits::DrawBulletTp,
			Vars::Exploits::isBulletTpExternded,
			Vars::Exploits::Pierce,
			Vars::Exploits::ShootThroughTeammates,
			Vars::Exploits::HeliOverride,

			Vars::Aim::IgnoreVisible,
			Vars::Aim::IgnoreHeli,
			Vars::Aim::IgnoreTurrets,
			Vars::Aim::IgnoreWounded,
			Vars::Aim::IgnoreSleepers,
			Vars::Aim::IgnoreNpc,
			Vars::Aim::IgnoreTeam,
			Vars::Aim::IgnoreSafeZone,
			Vars::Visuals::PlayerEsp::PlayerChams,
			Vars::Visuals::PlayerEsp::WeaponChams,
			Vars::Visuals::PlayerEsp::HandChams,
			Vars::Visuals::DrawdDstanceBool,
			Vars::Visuals::StoneOre,
			Vars::Visuals::MetalOre,
			Vars::Visuals::SulfurOre,
			Vars::Visuals::CrateDstanceBool,
			Vars::Visuals::EliteCrate,
			Vars::Visuals::BasicCrate,
			Vars::Visuals::NormalCrate,
			Vars::Visuals::NormalCrate2,
			Vars::Visuals::ToolCrate,
			Vars::Visuals::TrapHealth,
			Vars::Visuals::TrapDstanceBool,
			Vars::Visuals::FlameTurret,
			Vars::Visuals::BearTrap,
			Vars::Visuals::Turrents,
			Vars::Visuals::SamSite,
			Vars::Visuals::Guntrap,
			Vars::Visuals::LandMine,
			Vars::Visuals::AnimalHealth,
			Vars::Visuals::DistanceAnimalBool,
			Vars::Visuals::Boar,
			Vars::Visuals::Bear,
			Vars::Visuals::Horse,
			Vars::Visuals::Wolf,
			Vars::Visuals::VehicleHealth,
			Vars::Visuals::Minicopter,
			Vars::Visuals::Bradley,
			Vars::Visuals::Rowboat,
			Vars::Visuals::Rhib,
			Vars::Visuals::ScrapTransportHeli,
			Vars::Visuals::PatrolHelicopter,

			Vars::Visuals::DroppedItems,
			Vars::Visuals::DroppedItemsDistBool,
			Vars::Visuals::Corpse,
			Vars::Visuals::CorpseDrawDist,
			Vars::Visuals::BackPack,
			Vars::Visuals::BackPackDrawDist,
			Vars::Visuals::HackableCrate,
			Vars::Visuals::HackableCrateDrawDist,
			Vars::Visuals::ToolCupboard,
			Vars::Visuals::ToolCupboardDrawDist,
			Vars::Visuals::Stash,
			Vars::Visuals::StashDrawDist,
			Vars::Visuals::Hemp,
			Vars::Visuals::HempDistanceBool,

			Vars::Misc::WaterMark,
			Vars::Config::OutLineText,
			Vars::Misc::BrightNight,
			Vars::Misc::SkyColor,
			Vars::Misc::AmbientColor,
			Vars::Misc::SkyFall,
			Vars::Misc::TimeChanger,
			Vars::Misc::DrawColliders,
			Vars::Misc::RayLenthChanger,

			Vars::Misc::PlayerFovBool,
			Vars::Misc::PlayerZoomBool,
			Vars::Misc::AspectRatio,
			Vars::Misc::OmniSprint,
			Vars::Misc::JitterAA,
			Vars::Misc::SilentFarmOre,
			Vars::Misc::SilentFarmTree,
			Vars::Misc::WalkTo,
			Vars::Misc::Jesus,
			Vars::Misc::RemoveCollision,
			Vars::Misc::InstaRevive,
			Vars::Misc::SilentStash,
			Vars::Misc::MassSuicide,
			Vars::Misc::SilentTurret,
			Vars::Misc::StopRecycler,
			Vars::Misc::DoorKnocker,
			Vars::Misc::NoFallDamage,
			Vars::Misc::JumpShoot,
			Vars::Misc::SpiderMan,
			Vars::Misc::SpiderManBypass,
			Vars::Misc::InfinityJump,
			Vars::Misc::ShootMounted,
			Vars::Misc::InteractiveDebug,
			Vars::Misc::AdminFlag,
			Vars::Misc::OnLadder,
			Vars::Misc::Bhop,
			Vars::Misc::InteractiveFly,
			Vars::Misc::FlyHackBar,
			Vars::Misc::AntiFlyKick,
			Vars::Misc::AntiInsideTerrain,
			Vars::Misc::FastLoot,
			Vars::Misc::AlwaysHotSpot,
			Vars::Misc::HitSound,
			Vars::Misc::AutoPickupCollect,
			Vars::Misc::AutoPickupLoot,
			Vars::Misc::autoHeal,

			Vars::Visuals::DisableTrashEsp,
		};

		cfgInt cfgInts[34] =
		{
			Vars::Aim::pSilentSpread,
			Vars::Misc::FlySpeed,
			Vars::Keys::InteractiveDebugKey,
			Vars::Keys::OnLadder,
			Vars::Keys::FlyKey,
			Vars::Keys::SilentStash,
			Vars::Misc::AutoBotMode,
			Vars::Misc::AutoFarmOres,
			Vars::Keys::InstaRevive,
			Vars::Misc::Zoom,
			Vars::Keys::Zoom,
			Vars::Misc::PlayerFov,
			Vars::Visuals::PlayerEsp::HealthEsp,
			Vars::Visuals::PlayerEsp::BoxEsp,
			Vars::Visuals::PlayerEsp::HandChamsType,
			Vars::Visuals::PlayerEsp::PlayerChamsType,

			Vars::Visuals::PlayerEsp::LookingAtUCombo,
			Vars::Keys::FakeShootKey,
			Vars::Keys::OVBulletSpeed,
			Vars::Weapon::FireRate,
			Vars::Keys::KeepTarget,
			Vars::Aim::AimFov,
			Vars::Aim::TargetBone,
			Vars::Keys::TptoHead,
			Vars::Aim::AimCombo,
			Vars::Keys::ManipulationKey,
			Vars::Exploits::CheckAngels,
			Vars::Exploits::BehindWallScanStrength,
			Vars::Exploits::BehindWallType,
			Vars::Keys::AutoShoot,
			Vars::Exploits::BulletTpType,
			Vars::Exploits::PlayerOverride,

			Vars::CurFont,

		};
		// 88
		cfgFloat cfgFloats[120] =
		{
						ColorPicker::Fov.r,
			ColorPicker::Fov.g,
			ColorPicker::Fov.b,
			ColorPicker::Fov.a,
			// TextEspVisible
			ColorPicker::SkeletonsVisible.r,
			ColorPicker::SkeletonsVisible.g,
			ColorPicker::SkeletonsVisible.b,
			ColorPicker::SkeletonsVisible.a,
			
			ColorPicker::SkeletonsInVisible.r,
			ColorPicker::SkeletonsInVisible.g,
			ColorPicker::SkeletonsInVisible.b,
			ColorPicker::SkeletonsInVisible.a,
			
			ColorPicker::BoxVisible.r,
			ColorPicker::BoxVisible.g,
			ColorPicker::BoxVisible.b,
			ColorPicker::BoxVisible.a,
			
			ColorPicker::BoxInVisible.r,
			ColorPicker::BoxInVisible.g,
			ColorPicker::BoxInVisible.b,
			ColorPicker::BoxInVisible.a,
			
			ColorPicker::TextEspVisible.r,
			ColorPicker::TextEspVisible.g,
			ColorPicker::TextEspVisible.b,
			ColorPicker::TextEspVisible.a,
			
			ColorPicker::TextEspInVisible.r,
			ColorPicker::TextEspInVisible.g,
			ColorPicker::TextEspInVisible.b,
			ColorPicker::TextEspInVisible.a,
			
			ColorPicker::WeaponVisible.r,
			ColorPicker::WeaponVisible.g,
			ColorPicker::WeaponVisible.b,
			ColorPicker::WeaponVisible.a,
			
			ColorPicker::WeaponInVisible.r,
			ColorPicker::WeaponInVisible.g,
			ColorPicker::WeaponInVisible.b,
			ColorPicker::WeaponInVisible.a,
			
			ColorPicker::FlagsVisible.r,
			ColorPicker::FlagsVisible.g,
			ColorPicker::FlagsVisible.b,
			ColorPicker::FlagsVisible.a,
			
			ColorPicker::FlagsInVisible.r,
			ColorPicker::FlagsInVisible.g,
			ColorPicker::FlagsInVisible.b,
			ColorPicker::FlagsInVisible.a,
			
			ColorPicker::SkyColor.r,
			ColorPicker::SkyColor.g,
			ColorPicker::SkyColor.b,
			ColorPicker::SkyColor.a,
			
			ColorPicker::AmbientColor.r,
			ColorPicker::AmbientColor.g,
			ColorPicker::AmbientColor.b,
			ColorPicker::AmbientColor.a,
			
			ColorPicker::BulletTracer.r,
			ColorPicker::BulletTracer.g,
			ColorPicker::BulletTracer.b,
			ColorPicker::BulletTracer.a,
			
			ColorPicker::OOFVisible.r,
			ColorPicker::OOFVisible.g,
			ColorPicker::OOFVisible.b,
			ColorPicker::OOFVisible.a,
			
			ColorPicker::OOFInVisible.r,
			ColorPicker::OOFInVisible.g,
			ColorPicker::OOFInVisible.b,
			ColorPicker::OOFInVisible.a, // PlayerChamsInVisible
			
			ColorPicker::PlayerChamsVisible.r,
			ColorPicker::PlayerChamsVisible.g,
			ColorPicker::PlayerChamsVisible.b,
			ColorPicker::PlayerChamsVisible.a,
			
			ColorPicker::PlayerChamsInVisible.r,
			ColorPicker::PlayerChamsInVisible.g,
			ColorPicker::PlayerChamsInVisible.b,
			ColorPicker::PlayerChamsInVisible.a,
			
			ColorPicker::HandChams2.r,
			ColorPicker::HandChams2.g,
			ColorPicker::HandChams2.b,
			ColorPicker::HandChams2.a,
			
			ColorPicker::HandChams.r,
			ColorPicker::HandChams.g,
			ColorPicker::HandChams.b,
			ColorPicker::HandChams.a,
			
			ColorPicker::RadarVisible.r,
			ColorPicker::RadarVisible.g,
			ColorPicker::RadarVisible.b,
			ColorPicker::RadarVisible.a,
			
			ColorPicker::RadarInVisible.r,
			ColorPicker::RadarInVisible.g,
			ColorPicker::RadarInVisible.b,
			ColorPicker::RadarInVisible.a,

			Vars::Misc::AutoBotJumpHeight,
			Vars::EspTextSize,
			Vars::WorldEspTextSize,
			Vars::Misc::Aspect,
			Vars::Misc::RayleighValue,
			Vars::Misc::GameTime,
			Vars::Visuals::HempDistance,
			Vars::Visuals::StashDist,
			Vars::Visuals::ToolCupboardDist,
			Vars::Visuals::HackableCrateDist,
			Vars::Visuals::BackPackDist,
			Vars::Visuals::CorpseDist,
			Vars::Visuals::DroppedItemsDist,
			Vars::Visuals::VehicleDstance,
			Vars::Visuals::DistanceAnimal,
			Vars::Visuals::CrateDstance,
			Vars::Visuals::TrapDstance,
			Vars::Visuals::DrawdDstance,
			Vars::Visuals::PlayerEsp::OOFDist,
			Vars::Weapon::MeleeRadius,
			Vars::Weapon::BulletSpeed,
			Vars::Weapon::FatBulletValue,
			Vars::Weapon::Recoil,
			Vars::Weapon::Spread,
			Vars::Exploits::MinDecync,
			Vars::Exploits::DesyncDist,
			Vars::Aim::HitChance,
			Vars::Aim::AimRange,
			
			Vars::Radar::Pos.x,
			Vars::Radar::Pos.y,

			Vars::Belt::Pos.x,
			Vars::Belt::Pos.y,
		};


		cfgVec2 cfgVec2s[1] =
		{
			Vars::Radar::Pos,
		};

		int boolAmount = sizeof(cfgBools) / sizeof(cfgBools[0]),
			intAmount = sizeof(cfgInts) / sizeof(cfgInts[0]),
			floatAmount = sizeof(cfgFloats) / sizeof(cfgFloats[0]),
			posAmount = sizeof(cfgVec2s) / sizeof(cfgVec2s[0]),
			doubleBoolAmount = boolAmount * 2,
			currentNum = doubleBoolAmount;

		if (type == configType::Save) {
			char* final = _("");
			int currentCharNum = 0;

			for (int i = 0; i < boolAmount; i++)
				addValueToFinal(cfgBools[i].value, final, currentCharNum);
			for (int i = 0; i < intAmount; i++)
				addValueToFinal(cfgInts[i].value, final, currentCharNum);
			for (int i = 0; i < floatAmount; i++)
				addValueToFinal((int)cfgFloats[i].value, final, currentCharNum);

			writeToFile(FileLocation, final);

		}
		else if (type == configType::Load)
		{
			HANDLE hFile = OpenFile(FileLocation);
			DWORD ReadBytes;
			char CharacterBuffer[4096];
			if (m_ReadFile(hFile, CharacterBuffer, 1024, &ReadBytes, NULL))
			{
				for (int i = 0; i < doubleBoolAmount; i += 2) {
					cfgBools[(int)(i * 0.5)].value = (CharacterBuffer[i] == '1' ? true : false);
				}
				for (int i = 0; i < intAmount; i++) {
					cfgInts[i].value = (int)getIntThisLine(CharacterBuffer, currentNum);
				}
				for (int i = 0; i < floatAmount; i++) {
					cfgFloats[i].value = (float)getIntThisLine(CharacterBuffer, currentNum);
				}
				/*for (int i = 0; i < keyAmount; i++) {
					cfgKeys[i].value = (KeyCode)getIntThisLine(CharacterBuffer, currentNum);
				}*/
				m_CloseHandle(hFile);
			}
			else
			{
				m_CloseHandle(hFile);
			}
		}
	}
};