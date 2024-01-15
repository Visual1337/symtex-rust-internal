namespace Dump {

	namespace CollectibleEntity
	{
		DWORD64 itemList;
	};

	namespace BaseNetworkable {
		DWORD64 get_ShortPrefabName;
	};

	namespace AttackEntity {
		
	}; // TerrainHeightMap

	namespace TerrainHeightMap {
		DWORD64 GetNormal_Vector3;
		DWORD64 GetHeight_Vector3;
	};

	namespace Terrain {
		DWORD64 SampleHeight_Vector3;
	};

	namespace TerrainCollision {
		DWORD64 GetIgnore_Vector3_float;
	};

	namespace TerrainMeta {
		DWORD64 Terraink__BackingField;
		DWORD64 get_Position;
		DWORD64 get_HeightMap;
		DWORD64 get_Terrain;
		DWORD64 get_Collision;
		
	};

	namespace BasePlayer {
		DWORD64 movement;
		DWORD64 userID; 
		DWORD64 groundAngleNew;
		DWORD64 groundAngle;
		DWORD64 groundTime;
		DWORD64 clActiveItem;
		DWORD64 inventory;
		DWORD64 modelState;
		DWORD64 playerFlags;
		DWORD64 clientTickInterval;
		DWORD64 lastSentTickTime;
		DWORD64 lastSentTick;
		DWORD64 input;
		DWORD64 playerModel;
	};

	namespace Planner
	{
		DWORD64 planner_rotationoffset = 0;
		DWORD64 planner_currentconstruction = 0;
		DWORD64 planner_guide = 0;
	};

	namespace BaseCombatEntity {
		DWORD64 lifestate;
		DWORD64 _health;
		DWORD64 _maxHealth;
	};

	namespace PlayerInventory {
		DWORD64 containerBelt;
	};

	namespace ItemContainer {
		DWORD64 itemList;
	};

	namespace BaseProjectile {
		DWORD64 primaryMagazine;
		DWORD64 recoil;
		DWORD64 projectileVelocityScale;

		DWORD64 LaunchProjectile;
		DWORD64 currentBurst;
	};

	namespace BaseEntity {
		DWORD64 ClosestPoint;
		DWORD64 model;
	};

	namespace Projectile {
		DWORD64 currentPosition;
		DWORD64 mod;
	};

	namespace Item {
		DWORD64 heldEntity;
		DWORD64 info;
		DWORD64 uid;
	};

	namespace ItemDefinition {
		DWORD64 displayName;
		DWORD64 itemid;
	}; 

	namespace PlayerWalkMovement {
		DWORD64 swimming;
		DWORD64 body;
		DWORD64 jumping;
		DWORD64 jumpTime;
	};

	namespace BaseMovement {
		DWORD64 TargetMovementk__BackingField;
		DWORD64 Duckingk__BackingField;
		DWORD64 set_TargetMovement;
		DWORD64 get_TargetMovement;
	}; 

	namespace GamePhysics {
		DWORD64 LineOfSight;
	};

	namespace BaseHelicopter {
		DWORD64 weakspots;
	};

	namespace UnityEngine_Transform {
		DWORD64 get_parent;
		DWORD64 InverseTransformPoint;
		DWORD64 InverseTransformDirection;
	};

	namespace ItemModProjectile {
		DWORD64 GetRandomVelocity;
		DWORD64 projectileVelocity;
	}; 

	void InitDumper1()
	{
		CollectibleEntity::itemList = Il2cpp::GetOffset(_("CollectibleEntity"), _("itemList"));

		Planner::planner_rotationoffset = Il2cpp::GetOffset(_("Planner"), _("rotationOffset"));
		Planner::planner_currentconstruction = Il2cpp::GetOffset(_("Planner"), _("currentConstruction"));
		Planner::planner_guide = Il2cpp::GetOffset(_("Planner"), _("guide"));

		ItemModProjectile::GetRandomVelocity = Il2cpp::GetOffset(_("ItemModProjectile"), _("GetRandomVelocity"));
		ItemModProjectile::projectileVelocity = Il2cpp::GetOffset(_("ItemModProjectile"), _("projectileVelocity"));

		BaseHelicopter::weakspots = Il2cpp::GetOffset(_("BaseHelicopter"), _("weakspots"));

		UnityEngine_Transform::get_parent = Il2cpp::resolve_icall(_("UnityEngine.Transform::get_parent()"));
		UnityEngine_Transform::InverseTransformPoint = Il2cpp::resolve_icall(_("UnityEngine.Transform::InverseTransformPoint()"));
		UnityEngine_Transform::InverseTransformDirection = Il2cpp::resolve_icall(_("UnityEngine.Transform::InverseTransformDirection()"));

		GamePhysics::LineOfSight = Il2cpp::GetOffset(_("GamePhysics"), _("LineOfSight"));

		PlayerWalkMovement::swimming = Il2cpp::GetOffset(_("PlayerWalkMovement"), _("swimming"));
		PlayerWalkMovement::jumping = Il2cpp::GetOffset(_("PlayerWalkMovement"), _("jumping"));
		PlayerWalkMovement::body = Il2cpp::GetOffset(_("PlayerWalkMovement"), _("body"));
		PlayerWalkMovement::jumpTime = Il2cpp::GetOffset(_("PlayerWalkMovement"), _("jumpTime"));

		BaseMovement::TargetMovementk__BackingField = Il2cpp::GetOffset(_("BaseMovement"), _("TargetMovementk__BackingField"));
		BaseMovement::Duckingk__BackingField = Il2cpp::GetOffset(_("BaseMovement"), _("Duckingk__BackingField"));
		BaseMovement::set_TargetMovement = Il2cpp::GetOffset(_("BaseMovement"), _("set_TargetMovement"));
		BaseMovement::get_TargetMovement = Il2cpp::GetOffset(_("BaseMovement"), _("get_TargetMovement"));

		BaseNetworkable::get_ShortPrefabName = Il2cpp::GetOffset(_("BaseNetworkable"), _("get_ShortPrefabName"));
		// groundTime
	}
	void InitDumper2()
	{
		BasePlayer::userID = Il2cpp::GetOffset(_("BasePlayer"), _("userID"));
		BasePlayer::movement = Il2cpp::GetOffset(_("BasePlayer"), _("movement"));
		BasePlayer::groundAngleNew = Il2cpp::GetOffset(_("PlayerWalkMovement"), _("groundAngleNew"));
		BasePlayer::groundTime = Il2cpp::GetOffset(_("PlayerWalkMovement"), _("groundTime"));
		BasePlayer::groundAngle = Il2cpp::GetOffset(_("PlayerWalkMovement"), _("groundAngle"));
		BasePlayer::clActiveItem = Il2cpp::GetOffset(_("BasePlayer"), _("clActiveItem"));
		BasePlayer::inventory = Il2cpp::GetOffset(_("BasePlayer"), _("inventory"));
		BasePlayer::modelState = Il2cpp::GetOffset(_("BasePlayer"), _("modelState"));
		BasePlayer::playerFlags = Il2cpp::GetOffset(_("BasePlayer"), _("playerFlags"));
		BasePlayer::clientTickInterval = Il2cpp::GetOffset(_("BasePlayer"), _("clientTickInterval"));
		BasePlayer::lastSentTickTime = Il2cpp::GetOffset(_("BasePlayer"), _("lastSentTickTime"));
		BasePlayer::lastSentTick = Il2cpp::GetOffset(_("BasePlayer"), _("lastSentTick"));
		BasePlayer::input = Il2cpp::GetOffset(_("BasePlayer"), _("input"));
		BasePlayer::playerModel = Il2cpp::GetOffset(_("BasePlayer"), _("GetJumpHeight"));

		// lastSentTick
		BaseEntity::ClosestPoint = Il2cpp::GetOffset(_("BaseEntity"), _("ClosestPoint"));
		BaseEntity::model = Il2cpp::GetOffset(_("BaseEntity"), _("model"));

		BaseCombatEntity::lifestate = Il2cpp::GetOffset(_("BaseCombatEntity"), _("lifestate"));
		BaseCombatEntity::_health = Il2cpp::GetOffset(_("BaseCombatEntity"), _("_health"));
		BaseCombatEntity::_maxHealth = Il2cpp::GetOffset(_("BaseCombatEntity"), _("_maxHealth"));

		PlayerInventory::containerBelt = Il2cpp::GetOffset(_("PlayerInventory"), _("containerBelt"));

		ItemContainer::itemList = Il2cpp::GetOffset(_("ItemContainer"), _("itemList"));
		// Item //
		Item::heldEntity = Il2cpp::GetOffset(_("Item"), _("heldEntity"));
		Item::info = Il2cpp::GetOffset(_("Item"), _("info"));
		Item::uid = Il2cpp::GetOffset(_("Item"), _("uid"));

		BaseProjectile::primaryMagazine = Il2cpp::GetOffset(_("BaseProjectile"), _("primaryMagazine"));
		BaseProjectile::recoil = Il2cpp::GetOffset(_("BaseProjectile"), _("recoil"));
		BaseProjectile::projectileVelocityScale = Il2cpp::GetOffset(_("BaseProjectile"), _("projectileVelocityScale"));
		BaseProjectile::LaunchProjectile = Il2cpp::GetOffset(_("BaseProjectile"), _("LaunchProjectile"));
		BaseProjectile::currentBurst = Il2cpp::GetOffset(_("BaseProjectile"), _("currentBurst"));
	}
	void InitDumper3()
	{
		Projectile::currentPosition = Il2cpp::GetOffset(_("Projectile"), _("currentPosition"));
		Projectile::mod = Il2cpp::GetOffset(_("Projectile"), _("mod"));
		// ItemDefinition //
		ItemDefinition::displayName = Il2cpp::GetOffset(_("ItemDefinition"), _("displayName"));
		ItemDefinition::itemid = Il2cpp::GetOffset(_("ItemDefinition"), _("itemid"));
	}
};