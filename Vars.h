#pragma once
class BasePlayer;
class ModelState;
class Weapon;
class BaseProjectile;
class Vector3;
class Color;
Vector3 EyePos = Vector3::Zero();
BaseProjectile* ActiveWeapon = NULL;
Weapon* HeldEntity = NULL;
__int64 lastProjectile = 0;
BasePlayer* TargetList[10];
int TargetIDList[10];
float HandsX;
float HandsY;
float HandsZ;

float LastDesyncDist = 0;

bool isInAir = false;
float flyhackDistanceVertical = 0.0f;
float flyhackDistanceHorizontal = 0.0f;
float flyhackPauseTime = 0.0f;

float flyhack_forgiveness_vertical_inertia = 10.0f;
float flyhack_forgiveness_vertical = 1.5f;
float flyhack_forgiveness_horizontal_inertia = 10.0f;
float flyhack_forgiveness_horizontal = 1.5f;

float flyhack_stepsize = 0.1f;
int flyhack_maxsteps = 15;


float bulletDropMaxVelocity = 300;
float AngleY = 100;
bool Manipulating = false;
bool Debugging = false;
bool Flying = false;
bool PSilenting = false;
bool TeleportingToPlayersHead = false;
bool AutoShooting = false;
bool FakeShooting = false;
bool Zooming = false;
bool OnLaddering = false; // TrashEsp
bool TrashEsp = false;
bool SilentStashing = false;
bool KeepTargeting = false;
bool OverridingSpeed = false;
bool ToggleFriend = false;
bool ToggleEnemy = false;

bool CanDrawHandChams = false;


bool HotKey_KeepTarget = false;
bool HotKey_Manipulation = false;
bool HotKey_AutoShoot = false;
bool HotKey_pSilent = false;
bool HotKey_TpToHead = false;
bool HotKey_OVBulletSpeed = false;
bool HotKey_SilentStash = false;
bool HotKey_FakeShootKey = false;
bool HotKey_InteractiveDebugKey = false;
bool HotKey_OnLadder = false; // Zoom
bool HotKey_TrashEsp = false;
bool HotKey_Zoom = false;
bool HotKey_FlyKey = false; // TrashEsp
bool HotKey_ToggleEnemy = false;


bool ProjectileShootInited = false;
bool ProjectileAttackInited = false;
DWORD64* ChamsLLLLLLIST[10];
float bSpeed1 = 0;
int SizeChams = 0;
int isisiChams = 0;

UINT64 FakeUpdate = NULL;

float ProjectileDrag = 0.1;
float ProjectileInitialDistance = 0;
float ProjectilegravityModifier = 2;
float ProjectileTravelTime = 0;

bool MainMenuOpen = false;

bool HookedProjShootBool = false;
int EntityCount = 0;
UINT64 EntityBuffer = 0;

bool CalledProjShoot = false;
double BulletTravelTime = 0.0;

bool isPredicted = false;

static bool CanBhopJump = false;

float CurHeaight;

float MyrepeatDelay;
bool DidPredict = false;

bool MFound = false;
namespace Vars
{

	float EspTextSize = 9;
	float WorldEspTextSize = 9;
	float GUITextSize = 9;
	float night1 = 0;
	float night2 = 0;
	float night3 = 0;

	unsigned int prp;
	bool VisState = false;

	float test = 60;

	int ScreenWidth = 0;
	int ScreenHeight = 0;

	int looklistpos = 0;
	uintptr_t* looklist[50];

	int selecttexst = 1;

	int ActiveTab;
	int ActuveSubTab;

	DWORD64 TargetPlayer = NULL;
	Vector3 RpcPosition;

	Vector3 OrigVel;

	float idelspeed = 1.6;

	bool initHook = false;

	float Speed;
	float VelZ;
	// Fonts|
	int CurFont = 0;
	int CurCfg = 0;
	namespace Aim
	{
		bool HitBox[7];

		bool KeepTarget = false;
		float HitChance = 0;
		int AimFov = 90;
		int OverrideAimFov = 90;
		float AimRange = 400;
		bool AimBot = false;
		bool pSilent = false;
		int pSilentSpread = 0;
		bool InitHooks = false;
		bool SilentMelee = false;



		bool DrawFov = true;
		int TargetBone = 47;
		bool Cross = 2;

		bool RecoilControlSystem = false;
		bool BodyAim = false;
		bool HeadAim = true;
		bool Smooth = false;
		float SmoothFactor = 1;

		//  int AimBone = 47;
		int AimCombo = 0;

		bool InstaKill = false;

		bool IgnoreTeam = true;
		bool IgnoreVisible = true;
		bool IgnoreSleepers = true;
		bool IgnoreWounded = false;
		bool IgnoreNpc = true;
		bool IgnoreHeli = false;
		bool IgnoreTurrets = true;
		bool IgnoreSafeZone = true;
	}
	namespace HitBox
	{
		bool None = false;
		bool Head = false;
		bool Neck = false;
		bool Body = false;
		bool Hands = false;
		bool Legs = false;
	};

	namespace Exploits
	{
		bool BulletTpExternded = false;
		bool isBulletTpExternded = false;
		bool AutoShootType[2] = { false, false };
		bool Visualize = true;
		int HitScanBone = 47;

		bool AutoShootNoAnim = false;
		bool AutoShootNoSound = false;

		int BulletQueue = 4;

		int DesyncPercentage = 95;

		float DesyncDist = 950;
		float MinDecync = 50;
		bool Pierce = true;
		bool ShootThroughTeammates = true;

		bool InstaHit = false;
		bool InstaHitSafeMode = false;

		int BahindWallType = 0;
		int PlayerOverride = 0;
		int BulletTpType = 0;
		int BehindWallType = 0;
		bool HeliOverride = false;
		bool HeliMagic = false;

		bool BahindWallStatus = false;

		bool PsilentBehindWall = false;

		bool BestBW = false;
		bool ScanUp = false;
		bool BehindWall = false;
		float BehindWallRange = 1.6;
		Vector3 BehindWallPos = { 0,0,0 };

		bool Manipulation = false;
		bool ShowManipulation = true;
		bool AutoStopOnManipulation = false;
		bool InstaKill = false;
		bool BulletTp = false;
		bool DrawBulletTp = false;
		bool Bestrange = false;

		bool MeleePsilent = false;
		bool UknMeme = false;
		bool FastThrow = false;

		bool AutoShoot = false;
		float AutoShootTimeSinceLastShot = 0.0;

		int CheckAngels = 12;
		int BehindWallScanStrength = 15;
		float DistanceToBulletTp = 0.05;
		int Optimisation = 7;
		float DesyncTime;

		float BulletTpDist = 0.1; // player_corpse
		float test_dist = 0;

		bool stw = false;
		int stw_scans = 10;

		bool lv = false;
		bool lv_scanned = false;
		Vector3 lv_dir = Vector3::Zero();
	}
	namespace Visuals
	{
		bool DisableTrashEsp = false;


		namespace Ores
		{
			bool StoneOre = false;
			bool StoneDrawDistance = false;
			float StoneDistance = 300;

			bool SulfurOre = false;
			bool SulfurDrawDistance = false;
			float SulfurDistance = 300;

			bool MetalOre = false;
			bool MetalDrawDistance = false;
			float MetalDistance = 300;
		}

		namespace Crates
		{
			bool Elite = false;
			bool EliteDrawDistance = false;
			float EliteDistance = 300;

			bool Basic = false;
			bool BasicDrawDistance = false;
			float BasicDistance = 300;

			bool Normal = false;
			bool NormalDrawDistance = false;
			float NormalDistance = 300;

			bool Normal2 = false;
			bool Normal2DrawDistance = false;
			float Normal2Distance = 300;

			bool Tool = false;
			bool ToolDrawDistance = false;
			float ToolDistance = 300;
		}

		namespace Traps
		{
			bool FlameTurret = false;
			bool FlameTurretDrawDistance = false;
			float FlameTurretDistance = 300;
			bool FlameTurretHealth = false;

			bool BearTrap = false;
			bool BearTrapDrawDistance = false;
			float BearTrapDistance = 300;
			bool BearTrapHealth = false;

			bool Turrets = false;
			bool TurretsDrawDistance = false;
			float TurretsDistance = 300;
			bool TurretsHealth = false;

			bool SamSite = false;
			bool SamSiteDrawDistance = false;
			float SamSiteDistance = 300;
			bool SamSiteHealth = false;

			bool GunTrap = false;
			bool GunTrapDrawDistance = false;
			float GunTrapDistance = 300;
			bool GunTrapHealth = false;

			bool LandMine = false;
			bool LandMineDrawDistance = false;
			float LandMineDistance = 300;
			bool LandMineHealth = false;
		}

		namespace Animals
		{
			bool Boar = false;
			bool BoarDrawDistance = false;
			float BoarDistance = 300;
			bool BoarHealth = false;

			bool Bear = false;
			bool BearDrawDistance = false;
			float BearDistance = 300;
			bool BearHealth = false;

			bool Horse = false;
			bool HorseDrawDistance = false;
			float HorseDistance = 300;
			bool HorseHealth = false;

			bool Wolf = false;
			bool WolfDrawDistance = false;
			float WolfDistance = 300;
			bool WolfHealth = false;

		}

		namespace Vehicles
		{
			bool Minicopter = false;
			bool MinicopterDrawDistance = false;
			float MinicopterDistance = 300;
			bool MinicopterHealth = false;

			bool Bradley = false;
			bool BradleyDrawDistance = false;
			float BradleyDistance = 300;
			bool BradleyHealth = false;

			bool Rowboat = false;
			bool RowboatDrawDistance = false;
			float RowboatDistance = 300;
			bool RowboatHealth = false;

			bool Rhib = false;
			bool RhibDrawDistance = false;
			float RhibDistance = 300;
			bool RhibHealth = false;

			bool ScrapHeli = false;
			bool ScrapHeliDrawDistance = false;
			float ScrapHeliDistance = 300;
			bool ScrapHeliHealth = false;

			bool PatrolHeli = false;
			bool PatrolHeliDrawDistance = false;
			float PatrolHeliDistance = 300;
			bool PatrolHeliHealth = false;

		}

		namespace Misc
		{
			bool Hemp = false;
			bool HempDrawDistance = false;
			float HempDistance = 300;

			bool DroppedItems = false;
			bool DroppedItemsDrawDistance = false;
			float DroppedItemsDistance = 300;

			bool Corpse = false;
			bool CorpseDrawDistance = false;
			float CorpseDistance = 300;

			bool BackPack = false;
			bool BackPackDrawDistance = false;
			float BackPackDistance = 300;

			bool  HackableCrate = false;
			bool  HackableCrateDrawDistance = false;
			float HackableCrateDistance = 300;

			bool ToolCupboard = false;
			bool ToolCupboardHeliDrawDistance = false;
			float ToolCupboardHeliDistance = 300;
			bool ToolCupboardHeliHealth = false;

			bool  Stash = false;
			bool  StashDrawDistance = false;
			float StashDistance = 300;
		}

		bool RaidDrawDist = true;
		float RaidDist = 300;
		bool Raid = true;


		bool BackPackDrawDist = false;
		float BackPackDist = 300;
		bool BackPack = false;

		bool CorpseDrawDist = false;
		float CorpseDist = 300;
		bool Corpse = false;

		bool HackableCrateDrawDist = false;
		float HackableCrateDist = 1000;
		bool HackableCrate = false;

		bool ToolCupboard = false;
		bool ToolCupboardDrawDist = false;
		float ToolCupboardDist = 300;

		bool Stash = false;
		bool StashDrawDist = false;
		float StashDist = 300;

		bool DroppedItemsDistBool = false;
		float DroppedItemsDist = 300;
		bool DroppedItems = false;
		bool BulletTraces = false;
		bool HitMarker = false;
		bool DesyncBar = true;
		bool Reload_bar = false;

		bool reload_bar = true;


		// Diesel
		bool DieselDistBool = false;
		float DieselDist = 300;
		bool Diesel = false;

		bool CrateDstanceBool = false;
		float CrateDstance = 300;
		bool EliteCrate = false;
		bool BasicCrate = false;
		bool NormalCrate = false;
		bool NormalCrate2 = false;
		bool ToolCrate = false;

		bool BerryDistanceBool = false;
		float BerryDstance = 300;
		bool YellowBerry = false;
		bool BlueBerry = false;
		bool RedBerry = false;
		bool GreenBerry = false;

		bool VehicleDistanceBool = false;
		float VehicleDstance = 300;
		bool VehicleHealth = false; // Vehicle
		bool Minicopter = false;
		bool Bradley = false;
		bool Rowboat = false;
		bool Rhib = false;
		bool ScrapTransportHeli = false;
		bool PatrolHelicopter = false;

		bool TrapDstanceBool = false;
		float TrapDstance = 300;
		bool TrapHealth = false;
		bool FlameTurret = false;
		bool BearTrap = false;
		bool Turrents = false;
		bool SamSite = false;
		bool Guntrap = false;
		bool LandMine = false;

		bool DistanceMisc = false;
		float DistanceMiscObj = 300;

		bool Hemp = false;
		bool HempDistanceBool = false;
		float HempDistance = 300;

		bool DistanceAnimalBool = false;
		float DistanceAnimal = 300;
		bool AnimalHealth = false; // Vehicle
		bool Wolf = false;
		bool Boar = false;
		bool Bear = false;
		bool Horse = false;

		bool OreHealth = false;
		bool StoneOre = false;
		bool MetalOre = false;
		bool SulfurOre = false;

		bool DrawdDstanceBool = false;
		bool DrawdHpBool = false;
		float DrawdDstance = 300;

		namespace PlayerEsp
		{
			bool LookDirection = false;
			bool ShowPlayerFlags = false;

			bool TeamID = false;

			bool ShowAmmo = false;
			bool TargetInfo = true;
			bool Radar = false;
			bool Radar_ld = false;
			bool LookingAtU = false;
			float LookingAtU_dist = 400;
			float LookingAtU_sensitivity = 5;
			int LookingAtUCombo = 0;
			bool PlayerChams = false;
			bool PlayerChams1 = false;

			bool HandChams = false;
			bool WeaponChams = false;
			bool OOFindicators = false;
			float OOFDist = 140;

			bool MovmentLine = false;
			bool TargetLine = false;
			bool TeamEsp = false;
			bool NpcEsp = false;
			bool SleeperEsp = false;

			bool TargetHotBar = false;
			bool Target_Belt = false;

			bool DistanceEsp = false;

			bool Skeleton = false;

			/*  bool BoxEspEmptyBool = false;
			  bool BoxEsp = false;
			  bool CornerBoxEsp = false;*/
			int PlayerChamsType = 1;
			int HandChamsType = 0;
			bool BOX = 0;

			int BoxEsp = 0;
			int HealthEsp = 0;

			bool NameEsp = false;
			bool WeaponEsp = false;

			/*  bool HealthEspEmptyBool = false;
			  bool TextHealthEsp = false;
			  bool SideHealthBarEsp = false;
			  bool TopHealthBarEsp = false;*/
		}
	}

	namespace Weapon
	{
		bool FullAuto = false;
		bool SilentReload = false;
		bool fast_bullet = false;

		bool ChangeVelScale = false;
		bool OVChangeVelScale = false;
		float BulletSpeed = 1.f;
		float Bullet__Speed = 0;

		float bullet_speed_increment = 0;

		float OVBulletSpeed = 1;
		bool CustomHitMat = false;

		bool LongMelee = false;
		bool NoDeployDelay = false;
		bool InstaEoka = false;
		bool NoRecoil = false;
		bool NoSpread = false;
		bool NoSway = false;
		float Recoil = 100;
		float Spread = 100;
		float pSilentSpread = 0.02;
		bool NoBob = false;
		bool NoLower = false;
		bool NoPunch = false;
		bool NoAnimation = false;
		bool NoBurst = false;


		bool FatBullet = false;
		float FatBulletValue = 0.1;
		float MeleeRadius = 2.15;
		int FireRate = 0;
		int bullet_speed = 0;

	}

	namespace Misc
	{
		bool autoHeal = false;
		bool WaterMark = true;
		int Indicator = 0;
		bool Bhop = false;
		bool AlwaysHotSpot = false;
		bool HitSound = false;
		bool InteractiveFly = false;
		bool AntiInsideTerrain = false;
		int FlySpeed = 1;

		bool AutoPickupCollect = false;
		bool AutoPickupLoot = false;
		bool just_shot = false;
		float fixed_time_last_shot = 0.0f;
		bool did_reload = false;
		float time_since_last_shot = 0.0f;
		float time_since_last_shotauto = 0.0f;
		float time_since_last_shot2 = 0.0f;
		float rl_time = 0.0;

		bool InteractiveDebug = false;
		bool MassSuicide = false;
		bool DoorKnocker = false;

		bool BuildAsUWant = false;
		bool RayLenthChanger = false;
		float RayleighValue = 0;
		bool ray_light_changer = false;
		float rayleigh = 1.f;
		float mie = 1.f;
		float brightness = 1.f;

		bool mie_changer = false;
		bool brighttness_changer = false;

		bool DrawColliders = false;
		bool FastLoot = false;
		bool NoClip = false;
		bool LockToPlayersHead = false;
		bool SpiderManBypass = false;

		bool OnLadder = false;

		bool LootTW = false;
		bool InstaRevive = false;
		bool AntiFlyKick = false;
		bool SilentStash = false;
		bool SilentTurret = false;
		bool StopRecycler = false;

		bool FakeShoot = false;

		bool FlyHackBar = true;
		float VerticalFly = 0.0f;
		float HorizontalFly = 0.0f;
		float MaxVerticalFly = 0.0f;
		float MaxHorizontalFly = 0.0f;

		bool DebugCamera = false;
		/*  bool AutoFarmStone = false;
		  bool AutoFarmMetal = false;
		  bool AutoFarmSulfur = false;*/
		bool SilentFarmOre = false;
		bool SilentFarmTree = false;
		bool RemoveCollision = false;
		bool Jesus = true;


		int AutoFarmOres = 0;
		int AutoBotMode = 0;
		int HammerSpamMode = 0;

		bool DoJump = false;
		float AutoBotJumpHeight = 5.5;

		Vector3 WalkToDir{};

		bool WalkTo = false;
		bool JitterAA = false;

		float jitter = 1;
		float jitter_speed = 10;

		float spin_speed = 70;
		float spin = 0;

		bool ShootMounted = false;
		bool OmniSprint = false;
		bool WalkOnWater = false;
		bool JumpShoot = false;
		bool Silent_walk = false;

		bool capsuleHeight = false;


		bool BrightNight = false;
		bool SkyColor = false;
		bool AmbientColor = false;

		bool SkyFall = false;
		bool TimeChanger = false;
		float GameTime = 12;

		bool AspectRatio = false;
		float Aspect = 1.7;

		bool HammerSpam = false;

		bool SpiderMan = false;
		bool InfinityJump = false;
		bool AdminFlag = false;
		bool BlockCommands = false;
		bool NoFallDamage = false;

		bool PlayerFovBool = false;
		int PlayerFov = 90;

		bool PlayerZoomBool = false;
		int Zoom = 30;

		Vector3 to_path[10];
		bool tp_gotpath = false;
	}

	namespace Keys
	{
		int InteractiveDebugKey = 0;
		int InteractiveDebugType = 0;
		bool InteractiveDebugVal = 0;
		bool InteractiveDebug = false;
		bool isInteractiveDebug = false;

		int FakeShootKey = 0;
		int FakeShootType = 0;
		bool FakeShootVal = 0;
		bool FakeShoot = false;
		bool isFakeShoot = false;

		int pSilent = 0;
		int pSilentType = 0;
		bool pSilentVal = 0;
		bool pSilenting = false;
		bool ispSilent = false;

		int TptoHead = 0;
		int TptoHeadType = 0;
		bool TptoHeadVal = 0;
		bool TptoHeading = false;
		bool isTptoHead = false;

		int OVBulletSpeed = 0;
		int OVBulletSpeedType = 0;
		bool OVBulletSpeedVal = 0;
		bool OVBulletSpeeding = false;
		bool isOVBulletSpeed = false;

		int ToggleFriend = 0;
		int ToggleFriendType = 0;
		bool ToggleFriendVal = 0;
		bool ToggleFriend_ = false;
		bool isToggleFriend = false;

		int ToggleEnemy = 0;
		int ToggleEnemyType = 0;
		bool ToggleEnemyVal = 0;
		bool ToggleEnemy_ = false;
		bool isToggleEnemy = false;

		int LTW = 0;
		int AimKey = 0;

		int ManipulationKey = 0; // InstaKill
		int ManipulationKeyType = 0; // InstaKill
		bool ManipulationVal = 0;
		bool Manip = false;
		bool isManip = false;

		int FlyKey = 0; // InstaKill
		int FlyKeyType = 0; // InstaKill
		bool FlyVal = 0;
		bool Fly = false;
		bool isFly = false;

		int InstaKillKey = 0;

		int AutoShoot = 0;
		int AutoShootType = 0;
		bool AutoShootVal = 0;
		bool AutoShooting = false;
		bool isAutoShooting = false;

		int InstaRevive = 0;
		int InstaReviveType = 0;
		bool InstaReviveVal = 0;
		bool InstaReviving = false;
		bool isInstaReviving = false;

		int VelOV = 0;
		int NoClip = 0;

		int TrashEsp = 0;
		int TrashEspType = 0;
		bool TrashEspVal = 0;
		bool TrashEsping = false;
		bool isTrashEsp = false;

		int OnLadder = 0;
		int OnLadderType = 0;
		bool OnLadderVal = 0;
		bool OnLaddering = false;
		bool isOnLadder = false;

		int Zoom = 0;
		int ZoomType = 0;
		bool ZoomVal = 0;
		bool Zooming = false;
		bool isZoom = false;

		int SilentStash = 0;
		int SilentStashType = 0;
		bool SilentStashVal = 0;
		bool SilentStashing = false;
		bool isSilentStash = false;

		int KeepTarget = 0;
		int KeepTargetType = 0;
		bool KeepTargetVal = 0;
		bool KeepTargeting = false;
		bool isKeepTarget = false;

		int SilentTurret = 0;
		// int KeepTargetKey = 0;
		int Test = 278;
		bool Testing = false;
		bool isAlready = false;

	}

	namespace Radar
	{
		Vector2 Pos{ 50,50 };
		Vector2 Size{ 200,200 };
		Vector2 old_mouse_pos;
		Vector2 mouse_pos;

		bool MouseInBox(const Vector2& pos1, const Vector2& pos2) {
			if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y)
				return false;
			if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y)
				return false;

			return true;
		}

		void EndWindow() {
			old_mouse_pos = mouse_pos;
		}
	}

	namespace Belt
	{
		Vector2 Pos{ 1230 , 150 };
		Vector2 Size{ 475 , 75 };
		Vector2 old_mouse_pos;
		Vector2 mouse_pos;


		bool MouseInBox(const Vector2& pos1, const Vector2& pos2) {
			if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y)
				return false;
			if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y)
				return false;

			return true;
		}

		void EndWindow() {
			old_mouse_pos = mouse_pos;
		}
	}

	namespace Belt1
	{
		Vector2 Pos{ 1230 , 250 };
		Vector2 Size{ 475 , 75 };
		Vector2 old_mouse_pos;
		Vector2 mouse_pos;


		bool MouseInBox(const Vector2& pos1, const Vector2& pos2) {
			if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y)
				return false;
			if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y)
				return false;

			return true;
		}

		void EndWindow() {
			old_mouse_pos = mouse_pos;
		}
	}


	namespace Config
	{
		bool OutLineText = true;
	}

}

//ColorPicker::Fov.r,
//ColorPicker::Fov.g,
//ColorPicker::Fov.b,
//ColorPicker::Fov.a,
//// TextEspVisible
//ColorPicker::SkeletonsVisible.r,
//ColorPicker::SkeletonsVisible.g,
//ColorPicker::SkeletonsVisible.b,
//ColorPicker::SkeletonsVisible.a,
//
//ColorPicker::SkeletonsInVisible.r,
//ColorPicker::SkeletonsInVisible.g,
//ColorPicker::SkeletonsInVisible.b,
//ColorPicker::SkeletonsInVisible.a,
//
//ColorPicker::BoxVisible.r,
//ColorPicker::BoxVisible.g,
//ColorPicker::BoxVisible.b,
//ColorPicker::BoxVisible.a,
//
//ColorPicker::BoxInVisible.r,
//ColorPicker::BoxInVisible.g,
//ColorPicker::BoxInVisible.b,
//ColorPicker::BoxInVisible.a,
//
//ColorPicker::TextEspVisible.r,
//ColorPicker::TextEspVisible.g,
//ColorPicker::TextEspVisible.b,
//ColorPicker::TextEspVisible.a,
//
//ColorPicker::TextEspInVisible.r,
//ColorPicker::TextEspInVisible.g,
//ColorPicker::TextEspInVisible.b,
//ColorPicker::TextEspInVisible.a,
//
//ColorPicker::WeaponVisible.r,
//ColorPicker::WeaponVisible.g,
//ColorPicker::WeaponVisible.b,
//ColorPicker::WeaponVisible.a,
//
//ColorPicker::WeaponInVisible.r,
//ColorPicker::WeaponInVisible.g,
//ColorPicker::WeaponInVisible.b,
//ColorPicker::WeaponInVisible.a,
//
//ColorPicker::FlagsVisible.r,
//ColorPicker::FlagsVisible.g,
//ColorPicker::FlagsVisible.b,
//ColorPicker::FlagsVisible.a,
//
//ColorPicker::FlagsInVisible.r,
//ColorPicker::FlagsInVisible.g,
//ColorPicker::FlagsInVisible.b,
//ColorPicker::FlagsInVisible.a,
//
//ColorPicker::SkyColor.r,
//ColorPicker::SkyColor.g,
//ColorPicker::SkyColor.b,
//ColorPicker::SkyColor.a,
//
//ColorPicker::AmbientColor.r,
//ColorPicker::AmbientColor.g,
//ColorPicker::AmbientColor.b,
//ColorPicker::AmbientColor.a,
//
//ColorPicker::BulletTracer.r,
//ColorPicker::BulletTracer.g,
//ColorPicker::BulletTracer.b,
//ColorPicker::BulletTracer.a,
//
//ColorPicker::OOFVisible.r,
//ColorPicker::OOFVisible.g,
//ColorPicker::OOFVisible.b,
//ColorPicker::OOFVisible.a,
//
//ColorPicker::OOFInVisible.r,
//ColorPicker::OOFInVisible.g,
//ColorPicker::OOFInVisible.b,
//ColorPicker::OOFInVisible.a, // PlayerChamsInVisible
//
//ColorPicker::PlayerChamsVisible.r,
//ColorPicker::PlayerChamsVisible.g,
//ColorPicker::PlayerChamsVisible.b,
//ColorPicker::PlayerChamsVisible.a,
//
//ColorPicker::PlayerChamsInVisible.r,
//ColorPicker::PlayerChamsInVisible.g,
//ColorPicker::PlayerChamsInVisible.b,
//ColorPicker::PlayerChamsInVisible.a,
//
//ColorPicker::HandChams2.r,
//ColorPicker::HandChams2.g,
//ColorPicker::HandChams2.b,
//ColorPicker::HandChams2.a,
//
//ColorPicker::HandChams.r,
//ColorPicker::HandChams.g,
//ColorPicker::HandChams.b,
//ColorPicker::HandChams.a,
//
//ColorPicker::RadarVisible.r,
//ColorPicker::RadarVisible.g,
//ColorPicker::RadarVisible.b,
//ColorPicker::RadarVisible.a,
//
//ColorPicker::RadarInVisible.r,
//ColorPicker::RadarInVisible.g,
//ColorPicker::RadarInVisible.b,
//ColorPicker::RadarInVisible.a,
