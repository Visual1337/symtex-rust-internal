#pragma once

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

Vector3 InitialVel;

class AimResult;
namespace Hooks
{
	auto VisUpdateUsingCulling = reinterpret_cast<void (*)(BasePlayer*, float, bool)>(0);
	auto ClientInput_Orig = reinterpret_cast<void (*)(BasePlayer*, InputState*)>(0);
	auto ProcessAttack_Orig = reinterpret_cast<void (*)(DWORD64, HitTest*)>(0);

	auto DoFixedUpdate_Orig = reinterpret_cast<void (*)(PlayerWalkMovement*, ModelState*)>(0);
	auto playerwalkmovement_client_input = reinterpret_cast<void (*)(PlayerWalkMovement*, DWORD64, ModelState*)>(0);
	auto OnLand = reinterpret_cast<void (*)(BasePlayer*, float)>(0);
	auto set_sprinting = reinterpret_cast<void (*)(ModelState*, bool)>(0);
	auto set_sleeping = reinterpret_cast<void (*)(ModelState*, bool)>(0);
	auto GetInheritedThrowVelocity_Orig = reinterpret_cast<Vector3(*)(BasePlayer*, Vector3)>(0);

	
	// OnViewmodelEvent
	auto OnViewmodelEvent_Orig = reinterpret_cast<void (*)(DWORD64, const char*)>(0);
	auto DoAttack_Orig = reinterpret_cast<void (*)(DWORD64)>(0);
	DWORD64 PlayerProjectileShoot_orig;
	DWORD64 PlayerProjectileUpdate_orig;
	DWORD64 PlayerProjectileRicochet_orig; // Strike
	auto OnAttacked = reinterpret_cast<void (*)(void*, HitInfo*)>(0);
	auto TryToMove = reinterpret_cast<void (*)(DWORD64)>(0);
	auto LaunchProjectile_Orig = reinterpret_cast<void(*)(DWORD64)>(0);
	auto ProjectileShoot_Orig = reinterpret_cast<void (*)(uint64_t, uint64_t)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ProjectileShoot"), _("WriteToStream"), -1, _(""), _("ProtoBuf"))));
	//auto getmodifiedaimcone = reinterpret_cast<Vector3(*)(float, Vector3, bool)>(*reinterpret_cast<DWORD64*>(0));
	void InitHooks()
	{
		OnViewmodelEvent_Orig = reinterpret_cast<void (*)(DWORD64, const char*)>((DWORD64)(Il2cpp::Method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));
		ProcessAttack_Orig = reinterpret_cast<void (*)(DWORD64, HitTest*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));

		ProjectileShoot_Orig = reinterpret_cast<void (*)(uint64_t, uint64_t)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ProjectileShoot"), _("WriteToStream"), -1, _(""), _("ProtoBuf"))));
		DoAttack_Orig = reinterpret_cast<void (*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("DoAttack"), 0, _(""), _(""))));
		GetInheritedThrowVelocity_Orig = reinterpret_cast<Vector3(*)(BasePlayer*, Vector3)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("GetInheritedThrowVelocity"), 0, _(""), _(""))));

		VisUpdateUsingCulling = reinterpret_cast<void (*)(BasePlayer*, float, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("VisUpdateUsingCulling"), -1, _(""), _(""))));
		LaunchProjectile_Orig = reinterpret_cast<void(*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BaseProjectile"), _("LaunchProjectile"), 0, _(""), _(""))));

		OnAttacked = reinterpret_cast<void (*)(void*, HitInfo*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("OnAttacked"), 1, _(""), _(""))));
		TryToMove = reinterpret_cast<void (*)(DWORD64)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ItemIcon"), _("TryToMove"), -1, _(""), _(""))));
		playerwalkmovement_client_input = reinterpret_cast<void (*)(PlayerWalkMovement*, DWORD64, ModelState*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		OnLand = reinterpret_cast<void (*)(BasePlayer*, float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));
		ClientInput_Orig = reinterpret_cast<void (*)(BasePlayer*, InputState*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("BasePlayer"), _("ClientInput"), -1, _(""), _(""))));
		DoFixedUpdate_Orig = reinterpret_cast<void (*)(PlayerWalkMovement*, ModelState*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));


		set_sprinting = reinterpret_cast<void (*)(ModelState*, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));
		set_sleeping = reinterpret_cast<void (*)(ModelState*, bool)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("ModelState"), _("set_sleeping"), -1, _(""), _(""))));
	}
}

void SimulateMovement()
{
	int Records = 32;
	Vector3 defaultVelocity = Classes::GetWorldVelocity(Target.Cur);
	if (defaultVelocity.Empty())
		defaultVelocity = Classes::GetWorldVelocity(Target.Cur);

	if (defaultVelocity.Empty())
	{
		PredictionData::PredictionDatas.currentVelocityRecords = 0;
		PredictionData::PredictionDatas.currentVelocityIndex = 0;
		PredictionData::PredictionDatas.avgVel = defaultVelocity;
	}
	else {
		PredictionData::PredictionDatas.velocities[PredictionData::PredictionDatas.currentVelocityIndex++] = defaultVelocity;
		if (PredictionData::PredictionDatas.currentVelocityIndex >= Records)
			PredictionData::PredictionDatas.currentVelocityIndex = 0;

		PredictionData::PredictionDatas.currentVelocityRecords++;
		if (PredictionData::PredictionDatas.currentVelocityRecords >= 0)
			PredictionData::PredictionDatas.currentVelocityRecords = Records;

		int currentRecords = PredictionData::PredictionDatas.currentVelocityRecords;

		Vector3 velSum{};
		for (size_t j = 0; j < currentRecords; j++)
			velSum += PredictionData::PredictionDatas.velocities[j];

		PredictionData::PredictionDatas.avgVel = velSum / (float)currentRecords;
	}
}


Vector3 MoveCircle(Vector3 position, Vector3 second_position, float value, bool negative) {

	if (value == 0) {
		position = position;
	}
	else {
		if (negative) {
			position -= second_position;
		}
		else {
			position += second_position;
		}
	}

	return position;
}
float deploy = 0.0;

void hk_DoFixedUpdate(PlayerWalkMovement* BaseMovement, ModelState* modelstate)
{
	Vector3 vel = BaseMovement->TargetMovement();
	float max_speed = (BaseMovement->Swimming() || BaseMovement->Ducking() > 0.5) ? 1.7f : 5.5f;
	max_speed = max(max_speed, vel.Length());
	if (Vars::Misc::OmniSprint) {
		float len = vel.Length();
		if (len > 0.f) {
			Vector3 target_vel = Vector3(vel.x / len * max_speed, vel.y, vel.z / len * max_speed);
			safe_write(BaseMovement + 0x34, target_vel, Vector3);
		}
	}

	if (Vars::Misc::WalkTo)
	{
		Weapon* Held = LocalPlayer->GetActiveWeapon()->HeldEntity();
		if (Held)
		{
			AI::AutoWalkTo(BaseMovement, modelstate);
			//AI::AutoWalkTo2(BaseMovement, modelstate);
		}
	}
	else
		CanBhopJump = false;



	Hooks::DoFixedUpdate_Orig(BaseMovement, modelstate);
}



void hk_PlayerWalkMovement_ClientInput(PlayerWalkMovement* Movment, DWORD64 inputstate, ModelState* ModelState) {
	Hooks::playerwalkmovement_client_input(Movment, inputstate, ModelState);


	Hooks::set_sprinting(ModelState, true);
	//Hooks::set_sleeping(model_state, true);
	if (Vars::Misc::LockToPlayersHead && !(Vars::Misc::InteractiveDebug && Debugging)) {
		if (Target.Cur)
		{
			Vector3 Dir = (Target.Cur->GetEyes()->BodyForward());
			Vector3 LockPosition = Target.Pos + Vector3(-Dir.x, Dir.y - 0.2, -Dir.z);
			// Circle3D(Target.Cur->get_transform()->Position(), { 205.f, 100.f, 205.f, 255.f }, 2.5);
			if (Target.Distance < 2.5 && TeleportingToPlayersHead)
			{
				Classes::TeleportTo(Movment, LockPosition, LocalPlayer);
			}
		}
	}


	if (Vars::Misc::Jesus && LocalPlayer) {
		Vector3 vel = safe_read(Movment + O::BaseMovement::TargetMovementk__BackingField, Vector3);

		Vector3 local = LocalPlayer->GetBoneByID(BoneList::l_foot);

		typedef float(__stdcall* WD)(Vector3, bool, bool, BasePlayer*);

		float currentwater = ((WD)(g_Base + offsets::waterLevel))(local, true, false, LocalPlayer); // public static float GetWaterDepth(Vector3 pos, bool waves, bool volumes, BaseEntity forEntity) { }

		float upperwater = local.y - currentwater;
		upperwater -= 2.f;
		if (upperwater < 0.f && vel.y <= 0.1f) {
			vel.y = -upperwater;
		}
		safe_write(Movment + O::BaseMovement::TargetMovementk__BackingField, vel, Vector3);
	}

	safe_write(Movment + O::BaseMovement::adminCheat, false, bool);

	if (Vars::Misc::SpiderManBypass) Movment->set_radius(0.44); else Movment->set_radius(0.5);

	// Movment->set_height(0.2);

	if (Vars::Exploits::Manipulation && Manipulating && Vars::Exploits::AutoStopOnManipulation) Movment->TargetMovement({ 0, 0, 0 });

	DeathBarrier::IsInsideTerrain(Vars::Misc::AntiInsideTerrain);
	IsFlying(Vars::Misc::AntiFlyKick, Movment);
	InteractiveFlyHack(Vars::Misc::InteractiveFly, Movment);
	ModelState->RemoveFlag(ModelState_Flag::Flying);

	if (Vars::Misc::OnLadder && OnLaddering) ModelState->SetFlag(ModelState_Flag::OnLadder);

	if (Vars::Misc::InteractiveDebug && Debugging) {

		ModelState->SetFlag(ModelState_Flag::Mounted);
		ModelState->SetFlag(ModelState_Flag::OnGround);
		safe_write((uint64_t)Movment + 0x4C, 1, float);
	}

	if (Vars::Misc::Silent_walk)
	{
		ModelState->RemoveFlag(ModelState_Flag::OnGround);
	}

	if (Vars::Misc::JumpShoot)
	{
		ModelState->SetFlag(ModelState_Flag::OnGround);
		safe_write((uint64_t)Movment + 0x4C, 1, float);
	}
	if (Vars::Misc::Bhop && Unity::GetKeyInt(32) || CanBhopJump) {
		static float b = 32.0f;
		if (b >= 32.0f) {
			float radius = LocalPlayer->GetRadius();
			float height = LocalPlayer->GetHeight(false);
			Vector3 vector = (LocalPlayer->lastSentTick()->position() + LocalPlayer->get_transform()->Position()) * 0.5f;
			float flyhack_extrusion = 0.25f;
			Vector3 vector2 = vector + Vector3(0.0f, radius - flyhack_extrusion, 0.0f);
			Vector3 vector3 = vector + Vector3(0.0f, height - radius, 0.0f);
			float radius2 = radius - 0.05f;
			bool isgrounded = Unity::CheckCapsule(vector2, vector3, radius2, 1503731969, QueryTriggerInteraction::Ignore);
			if (isgrounded) {
				Movment->Jump(ModelState);
				b = 0.0f;
			}
		}
		b++;
	}

	
}

namespace Mathx
{
	float Decrement(float flt)
	{
		auto Decrement = reinterpret_cast<float (*)(float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Mathx"), _("Decrement"), 1, _(""), _(""))));
		return Decrement(flt);
	}

	float Increment(float flt)
	{
		auto Increment = reinterpret_cast<float (*)(float)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Mathx"), _("Increment"), 1, _(""), _(""))));
		return Increment(flt);
	}
};

void Launch(Projectile* pr, float initialDistance) {

	if (LocalPlayer && pr->owner()->GetSteamID() == LocalPlayer->GetSteamID()) {

		PrUpdate = pr;
		while (pr->IsAlive() && (pr->traveledDistance() < initialDistance || pr->traveledTime() < 0.1f))
		{
			Vector3 vector2 = pr->currentVelocity() * 0.03125;
			float magnitude = vector2.Magnitude();
			float num2 = 1.f / magnitude;
			Vector3 vector3 = vector2 * num2;
			Vector3 vector4 = pr->currentPosition() + vector3 * magnitude;
			RayLine line = RayLine(pr->currentPosition(), vector4);
			float ScanRange = Vars::Exploits::BulletTpExternded ? 6 : Vars::Exploits::BulletTpDist;

			Vector3 FirstNearest = line.ClosestPoint(Target.Pos);
			float DistanceToPoint1 = FirstNearest.Distance(Target.Pos);

			if (Vars::Exploits::BulletTp) {
				float ScanRange = Vars::Exploits::BulletTpDist;
				if (DistanceToPoint1 < ScanRange)
				//if (!Vars::Exploits::UknMeme && DistanceToPoint1 < 3)
				{
					UpdateVelocity(pr, 0.00025);
					BulletTeleport::TpBulletHitsP2(pr, FirstNearest, FirstNearest, 0);
				}
				else
				{
					UpdateVelocity(pr, 0.03125);
				}
			}
			else
			{
				UpdateVelocity(pr, 0.03125);
			}
		}
		
		float time = Unity::get_fixedTime();
		time -= pr->traveledTime();
		pr->launchTime(time);
	}
	else {
		return ProjectileLaunch(pr);
	}
}
bool CanAttack_hk(BaseProjectile* bp)
{
	return true;
}

bool CanAim_hk(BaseProjectile* bp)
{
	return true;
}

float GetMeleeDrag(int weaponID)
{
	switch (weaponID)
	{
	case 1326180354:
		return 0.5;
		break;
	case -1978999529:
		return 0.5;
		break;
	case 1090916276:
		return 0.5;
		break; // 1491189398
	case 1491189398:
		return 0.5;
		break; // paddle
	case -1137865085:
		return 0.5;
		break; // machete
	case -1966748496:
		return 0.5;
		break; // machete
	case 2040726127:
		return 0.5;
		break; // Combat Knife
	case 1814288539:
		return 0.5;
		break; // Костяной нож
	case -1469578201:
		return 0.5;
		break; // Костяной нож
	default:
		return 0.1;
		break;
	}
}

float GetMeleeGravity(int weaponID)
{
	switch (weaponID)
	{
	case 1540934679:
		return 2;
		break;
	case 1602646136:
		return 2;
		break;
	case 1090916276:
		return 2;
		break;
	case 1491189398:
		return 2;
		break;
	default:
		return 1;
		break;
	}
}

float ValidinitialDistance(Projectile* pr,float startVel, float initialDistance, float predictedTravelTime, float ShotTime) {

	float num21 = (initialDistance - 1) + (Vars::Exploits::DesyncTime * startVel);
	return num21;
}


float lastProjectileVelocity;
void hook_PlayerProjectileShoot(int64_t rcx, int64_t rdx, int64_t r9, int64_t projectileShoot, int64_t arg5)
{
	typedef void(__stdcall* Orig)(int64_t, int64_t, int64_t, int64_t, int64_t);

	float time = Unity::get_fixedTime();
	float TravelTime = 0.f;
	int Simulations = 0;

	const auto Orig_Func = reinterpret_cast<void (*)(int64_t, int64_t, int64_t, int64_t, int64_t)>(Hooks::PlayerProjectileShoot_orig);

	if (!HeldEntity) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);
	auto classname = HeldEntity->ClassName();
	if (!classname) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);
	// BaseLauncher
	if (m_strcmp(classname, _("BaseLauncher"))) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);

	float SpreadPsilent = (Vars::Aim::pSilentSpread * 0.01);

	float initialDistance = 0;

	DWORD64 ShootList = *(DWORD64*)(*(DWORD64*)(projectileShoot + 0x18));
	if (!ShootList) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);
	ShootList = *(DWORD64*)(*(DWORD64*)(projectileShoot + 0x18) + 0x10);
	auto Size = *(int*)(*(DWORD64*)(projectileShoot + 0x18) + 0x18);
	if (!Size) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);
	Vector3 TargetPos, rpc_position;
	Vector3 Orig_Vel{};
	Vector3 AimVel = Vector3(0, 0, 0);
	Vector3 outPosition = Vector3(0, 0, 0);
	Projectile* p;
	if (!(m_strcmp(classname, _("BaseMelee"))) && !(m_strcmp(classname, _("Paddle"))) && !(m_strcmp(classname, _("Jackhammer"))))
	{
		isPredicted = true;
		bVel = Vector3();

		BaseProjectile* ProjectileList = Read<BaseProjectile*>(Read<DWORD64>((DWORD64)HeldEntity + 0x398) + 0x10);
		if (!ProjectileList) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);

		bool Predicted = true;

		if (Vars::Exploits::BehindWall && Manipulating && Vars::Exploits::Manipulation && Vars::Exploits::BahindWallType == 0 && Vars::Exploits::BehindWallPos != Vector3(0, 0, 0))
			TargetPos = Vars::Exploits::BehindWallPos;
		else { TargetPos = Target.Pos; }

		for (int i = 0; i < Size; i++) {

			DWORD64 ProjectileShoot = *(DWORD64*)(ShootList + 0x20 + i * 0x8);
			if (!ProjectileShoot) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);
			Orig_Vel = Read<Vector3>(ProjectileShoot + 0x20);
			if (Orig_Vel == Vector3::Zero()) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);
			lastProjectileVelocity = Orig_Vel.Length();
			rpc_position = Read<Vector3>(ProjectileShoot + 0x14);
			if (rpc_position == Vector3::Zero()) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);
			InitialVel = Orig_Vel;
			BaseProjectile* projectile = Read<BaseProjectile*>(ShootList + 0x20 + i * 0x8);
			if (!projectile) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);

			p = *(Projectile**)((DWORD64)ProjectileList + 0x20 + i * 0x8);
			if (!p) return Orig_Func(rcx, rdx, r9, projectileShoot, arg5);
			Vector3 a;

			Vector3 EyePsoition = LocalPlayer->GetEyes()->EyePosition();
			Vector3 RealEyePsoition = LocalPlayer->GetEyes()->EyePosition();

			if (Vars::Exploits::Manipulation && Manipulating) {
				EyePsoition = EyePos;
			}
			else if (EyePsoition != RealEyePsoition)
			{
				EyePsoition = RealEyePsoition;
			}

			if (EyePsoition == Vector3::Zero()) return;

			//	Vector3 EyePsoition = EyePos;

			if (Vars::Exploits::Manipulation && Manipulating) {
				safe_write(projectile + 0x14, EyePos, Vector3);
			}
			outPosition = Read<Vector3>(ProjectileShoot + 0x14);
			Vector3 fakePos = Vector3::Zero();
			Vector3 AimPoint, AimPos;
			Vector3 OutputAngle, AimAngle;
			if (Vars::Aim::pSilent && Target.Cur)
			{
				if (PSilenting)
				{
					float HitChance = Maths::my_rand() % 100;
					if (Vars::Aim::HitChance <= HitChance)
						AimPoint = TargetPos;
					else AimPoint = TargetPos + Vector3(0, -2.1, 0);

					float IncBulletSpeed = 1;

					if (Vars::Weapon::fast_bullet)
					{
						IncBulletSpeed = Vars::Weapon::Bullet__Speed;

					}
					else
					{
						IncBulletSpeed = Vars::Weapon::BulletSpeed;
					}

					Vector3 StartPos = Read<Vector3>(ProjectileShoot + 0x14);
					float DistanceToTarget = Maths::Calc3D_Dist(EyePsoition, AimPoint);

					initialDistance = projectile->InitialDistance();

					Vector3 PredictedPoint = GetTrajectoryForEndPoint(AimPoint, EyePsoition, Orig_Vel.Length() * IncBulletSpeed, p->Drag(), p->gravityModifier(), initialDistance, &Predicted, &TravelTime);

				

					Vector3 PredictedPoint1337 = GetTrajectoryForEndPoint(AimPoint, StartPos, Orig_Vel.Length() * IncBulletSpeed, p->Drag(), p->gravityModifier(), initialDistance, &Predicted, &TravelTime);

					if (PredictedPoint1337 != Vector3::Zero())
					{
						AimPoint += PredictionData::PredictionDatas.avgVel * (TravelTime - (0.03125f * 2));
						bool EndPredict = false;
						Vector3 EndPoint = GetTrajectoryForEndPoint(AimPoint, StartPos, Orig_Vel.Length() * IncBulletSpeed, p->Drag(), p->gravityModifier(), initialDistance, &EndPredict, &TravelTime);
						Vector3 Direction = Classes::GetModifiedAimCone(SpreadPsilent, EndPoint - StartPos, false);

						AimVel = Direction.Normalized() * (Orig_Vel.Length() * IncBulletSpeed);

						if (EndPredict) {
							safe_write(projectile + 0x20, AimVel, Vector3);
						}
					}

					
				}
			}
		}

		for (int i = 0; i < ProjectileList->Size(); i++) {
			auto projectile = *(BaseProjectile**)((DWORD64)ProjectileList + 0x20 + i * 0x8);
			p = *(Projectile**)((DWORD64)ProjectileList + 0x20 + i * 0x8);

			if (!projectile) continue;


			ItemModProj* mod = projectile->GetItemModPr();
			if (mod)
			{
				Write<float>((DWORD64)mod + 0x30, 0);
				Write<float>((DWORD64)mod + 0x38, 0);
			}


			if (Vars::Aim::pSilent && Target.Cur) {
				if (Predicted && PSilenting) {
					projectile->CurrentVelocity(AimVel);
				}
			}

	

			if (Vars::Exploits::Manipulation && Manipulating) {
				projectile->GetTransform()->SetBonePos(EyePos);
				projectile->CurrentPosition(EyePos);
			}
			else {
				projectile->GetTransform()->SetBonePos(outPosition);
				projectile->CurrentPosition(outPosition);
			}


			Write<float>((DWORD64)projectile + 0x2c, Vars::Weapon::FatBulletValue);
			
		}
	}
	isPredicted = false;

	Vars::Misc::fixed_time_last_shot = Unity::get_fixedTime();
	Vars::Misc::did_reload = false;
	Vars::Misc::just_shot = true;

	Orig_Func(rcx, rdx, r9, projectileShoot, arg5);//fixed

	if (!(m_strcmp(classname, _("BaseMelee"))) && !(m_strcmp(classname, _("Paddle"))) && !(m_strcmp(classname, _("Jackhammer"))))
	{
		BaseProjectile* ProjectileList = Read<BaseProjectile*>(Read<DWORD64>((DWORD64)HeldEntity + 0x398) + 0x10);
		for (int i = 0; i < ProjectileList->Size(); i++) {
			auto pr = *(Projectile**)((DWORD64)ProjectileList + 0x20 + i * 0x8);
			if (!pr) continue;

			Launch(pr, initialDistance);
		}

		typedef void(*ClearAllLists)(uintptr_t);
		uintptr_t _List = safe_read((uintptr_t)HeldEntity + 0x398, uintptr_t);
		((ClearAllLists)(g_Base + offsets::ClearObjectList))(_List); // System_Collections_Generic_List_object___Clear
		// Recreated::ClearObjectList(_List);
	}
}

class ItemIcon
{
public:
	bool queuedForLooting()
	{
		if (!this) return false;
		return safe_read(this + 0x128, bool);
	}

	void RunTimedAction()
	{
		if (!this) return;
		typedef void(__stdcall* RunTimedA)(DWORD64);
		((RunTimedA)(g_Base + offsets::o_RunTimedAction))((DWORD64)this);
	}
};

void hk_TryToMove(ItemIcon* instance) {
	if (!instance) return Hooks::TryToMove((DWORD64)instance);

	Hooks::TryToMove((DWORD64)instance);

	if (Vars::Misc::FastLoot)
	{
		if (instance->queuedForLooting())
		{
			instance->RunTimedAction();
		}
	}
}



void hook_PlayerProjectileAttack(int64_t rcx, int64_t rdx, int64_t r9, int64_t PlayerProjAttack, int64_t arg5) {
	typedef void(__stdcall* Orig)(int64_t, int64_t, int64_t, int64_t, int64_t);
	auto Held = HeldEntity; if (!Held) return ((Orig)(PlayerProjectileAttack_Orig))(rcx, rdx, r9, PlayerProjAttack, arg5);//fixed
	auto classname = Held->ClassName();
	if (m_strcmp(classname, _("BaseMelee")) || (m_strcmp(classname, _("Paddle")) || (m_strcmp(classname, _("Jackhammer")))))
		return ((Orig)(PlayerProjectileAttack_Orig))(rcx, rdx, r9, PlayerProjAttack, arg5);//fixed;
	if (!Target.Cur) return ((Orig)(PlayerProjectileAttack_Orig))(rcx, rdx, r9, PlayerProjAttack, arg5);//fixed;
	auto GetPPA = reinterpret_cast<PlayerProjectileAttack*>(PlayerProjAttack);
	auto& Attack = GetPPA->playerAttack->attack;
	


	if (Vars::Visuals::BulletTraces)
	{
		Color Col = RGBA();
		Classes::DDrawLine(EyePos, Attack->hitPositionWorld, { ColorPicker::MovmentRGBBool ? Color(Col.r,Col.g,Col.b,255) : ColorPicker::MovmentLine }, 2.f, false, true);
	}

	if (Vars::Exploits::BulletTp)
	{
		AimTarget target = AimTarget();
		target.Cur = (Vars::Aim::KeepTarget && KeepTargeting && lastTarget != 0) ? lastTarget : nullptr;
		Vector3 Position(0.0f, 0.0f, 0.0f);

		if (target.Cur != nullptr) {
			auto* transform = target.Cur->GetTransform(22);
			if (transform != nullptr) {
				transform->Position();
			}
		}
	
		Projectile* projectile = PrUpdate;

		float Dist = Maths::Calc3D_Dist(projectile->currentPosition(), Target.Cur->GetEyes()->EyePosition());
		if (Dist <= Vars::Exploits::BulletTpDist)
		{
			if (projectile)
			{
				Attack->hitPositionWorld = projectile->currentPosition();
				Classes::DDrawLine(Attack->hitPositionWorld, projectile->currentPosition(), ColorPicker::BulletRGBBool ? RGBA(0.08f).GetUnityColor() : ColorPicker::BulletTracer.GetUnityColor(), 4, false, true);
			}
		}
	}

	do
	{
		if (!Vars::Exploits::Pierce && !Vars::Exploits::ShootThroughTeammates) break;

		if (!LocalPlayer || Target.Heli || Target.Turret)
			break;

		Projectile* projectile = (Projectile*)lastProjectile;
		if (projectile)
		{
			auto HitTest = projectile->get_hit_test();
			if (HitTest)
			{
				auto GameObject = HitTest->get_GameObject();
				if (GameObject != 0)
				{
					bool canIgnore = Unity::CheckLOS(projectile->currentPosition(), Target.Pos, 0.18, 10551296);
					if (canIgnore)
					{
						auto layer = HitTest->get_GameObject()->get_layer();
						if (Vars::Exploits::Pierce)
						{
							if (layer != layer::Player_Server)
							{
								projectile->Integrity(1);
								safe_write(projectile + O::Projectile::invisible, false, bool);
								return;
							}
						}
						if (Vars::Exploits::ShootThroughTeammates && Target.IsTeammate)
						{
							if (layer == layer::Player_Server)
							{
								projectile->Integrity(1);
								safe_write(projectile + O::Projectile::invisible, false, bool);
								return;
							}
						}
					}
				}
			}
		}

	} while (0);

	do {
		if (!LocalPlayer)
			break;

		if (!Target.Cur)
			break;


		if (!Vars::Exploits::HeliOverride && Vars::Exploits::PlayerOverride == 0)
			break;

		if (Target.Cur)
		{
			if (!Target.Heli && Vars::Exploits::PlayerOverride != 0 && !Target.Turret) {
				if (Vars::Exploits::PlayerOverride != 0)
				{
					if (Vars::Exploits::PlayerOverride == 1)
					{
						Attack->hitBone = 698017942;
						Attack->hitPartID = 2173623152;
					}

					else if (Vars::Exploits::PlayerOverride == 2)
					{
						Attack->hitBone = 3901657145;
						Attack->hitPartID = 1750816991;
					}
					else if (Vars::Exploits::PlayerOverride == 3)
					{
						switch (Maths::my_rand() % 4) {
						case 0: // Body
							Attack->hitBone = 3901657145;
							Attack->hitPartID = 1750816991;
							break;
						case 1: // Legs
							Attack->hitBone = 3892428003;
							Attack->hitPartID = 1750816991;
							break;
						case 2: // LHand
							Attack->hitBone = 182688154;
							Attack->hitPartID = 1750816991;
							break;
						case 3: // RHand
							Attack->hitBone = 102231371;
							Attack->hitPartID = 1750816991;
							break;
						}
					}
					else if (Vars::Exploits::PlayerOverride == 4)
					{
						switch (Maths::my_rand() % 5) {
						case 0: // Body
							Attack->hitBone = 3901657145;
							Attack->hitPartID = 1750816991;
							break;
						case 1: // Legs
							Attack->hitBone = 3892428003;
							Attack->hitPartID = 1750816991;
							break;
						case 2: // LHand
							Attack->hitBone = 182688154;
							Attack->hitPartID = 1750816991;
							break;
						case 3: // RHand
							Attack->hitBone = 102231371;
							Attack->hitPartID = 1750816991;
							break;
						case 4: // RHand
							Attack->hitBone = 698017942;
							Attack->hitPartID = 2173623152;
							break;
						}
					}
				}
			}
			else if (Target.Heli && !Target.Turret) {


				auto weakspots = Target.Cur->WeakSpots();
				if (!weakspots)
					break;

				//if (!Vars::Exploits::HeliOverride) break;

				if (Target.Cur->GetHealth() <= 5000.0f)
				{
					Attack->hitBone = 2699525250;
					Attack->hitPartID = 2306822461;
				}
				else
				{
					Attack->hitBone = 224139191;
					Attack->hitPartID = 2306822461;
				}

			}
		}
	} while (0);



	return ((Orig)(PlayerProjectileAttack_Orig))(rcx, rdx, r9, PlayerProjAttack, arg5);
}

DWORD64 DoFixedUpd, PlayerWM, PlayerPS, PrShoot, hkAttack, InheritedThrowVel;
DWORD64 WriteToStreamOrig = 0;
DWORD64 HKBlockJump;
DWORD64 BaseMovement_BlockJump;

void OnAtttackedHook(void* pacan, HitInfo* hitinfo)
{
	if (!Target.Heli && !Target.Turret)
	{



		if (Vars::Visuals::HitMarker)
			Classes::DDrawSphereGizmo(hitinfo->HitPositionWorld(), 0.2, { 0,255,0,255 }, 1, false, false);

		if (Vars::Misc::HitSound)
			m_PlaySound(reinterpret_cast<LPCUTSTR>(_("C:\\HitSound\\hit.wav")), NULL, SND_FILENAME | SND_ASYNC);
	}
	if (!Vars::Misc::HitSound)
		Hooks::OnAttacked(pacan, hitinfo);

	ProjectileAttackInited = true;
}

DWORD64 mvitem;

DWORD64 Rainbow = NULL;

int HandChamUpd = 1000;
int HandChamUpdRate = 10000;
void HandChams()
{
	
	if (Vars::Visuals::PlayerEsp::HandChams || Vars::Visuals::PlayerEsp::WeaponChams)
	{
		if (!HeldEntity) return;
		if (HeldEntity->timeSinceDeploy() > HeldEntity->DeployDelay()) return;

		// if (Unity::ChamsShader)
		{
			auto viewModel = Read<DWORD64*>(HeldEntity + O::HeldEntity::viewModel);
		
			auto baseViewModel = Read<DWORD64*>(viewModel + O::ViewModel::instance);

			bool* cameraAddress = reinterpret_cast<bool*>(baseViewModel + O::BaseViewModel::useViewModelCamera);
			*cameraAddress = false;

			auto camera = Read<bool>(baseViewModel + O::BaseViewModel::useViewModelCamera);
			Write(camera, false);


			int Chamsdsjdaisd = 0;
			static bool CanSet = false;
			static bool DidSet = false;
			auto model = Classes::get_ActiveModel();

			if (model) {
				CanSet = true;
				auto render = Unity::GetComponentsInChildren((DWORD64)model, Il2cpp::TypeGetObject(_("UnityEngine"), _("Renderer")));
				if (render) {
					auto size = safe_read(render + 0x18, DWORD64);
					for (int i = 0; i < size; i++) {
						auto renderer = safe_read(render + 0x20 + (i * 0x8), DWORD64);
						if (renderer) {
							Material* material = (Material*)Classes::get_material(renderer);
							if (material) {
								//if (!MainHandShader)
								//	MainHandShader = Unity::LoadAsset(Unity::ChamsShader, _(L"hologram.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader")));//
								static DWORD64 chamsMat1 = 0;
								static DWORD64 chamsMat2 = 0;
								
								if (!Unity::CanOverWriteAssets ) {

									if (Vars::Visuals::PlayerEsp::WeaponChams || Vars::Visuals::PlayerEsp::HandChams)
									{
										if (!material->name()->Contains(_(L"fumes")) && !material->name()->Contains(_(L"flash")) && !material->name()->Contains(_(L"holosight")))
										{
											if (!material->name()->Contains(_(L"Arm")) && !material->name()->Contains(_(L"hoodie")) && !material->name()->Contains(_(L"Glove")) && !material->name()->Contains(_(L"Hand")) && !material->name()->Contains(_(L"Suit")) && !material->name()->Contains(_(L"Hand")) && !material->name()->Contains(_(L"tshirt")) && !material->name()->Contains(_(L"hazmat")) && !material->name()->Contains(_(L"torso")))
											{
												
												if (Vars::Visuals::PlayerEsp::WeaponChams) {
													switch (Vars::Visuals::PlayerEsp::HandChamsType)
													{
													case 0:
														if (StormShader != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, StormShader);
															chamsMat2 = Classes::get_material((DWORD64)renderer);
															GUI::SetInt((DWORD64)chamsMat2, _(L"rainbow_go"), 0);
														}
														break;
													case 1: // GalaxyPink
														if (GalaxyPink != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, GalaxyPink);
														}
														break;
													case 2:
														if (GalaxyGreen != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, GalaxyGreen);
														}
														break;
													case 3:
														if (GalaxyRed != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, GalaxyRed);
														}
														break;
													case 4:
														if (GalaxyBlue != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, GalaxyBlue);
														}
														break;
													case 5:
														if (Test_Bundle != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, Test_Bundle);
														}
														break;
													case 6:
														if (Test_Bundle2 != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, Test_Bundle2);
														}
														break;

													case 7:
														if (Harvey != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, Harvey);
															Classes::set_shader((DWORD64)material, Harvey_shader);
														}
														break;
													    case 8:
														if (FireBundleA != Classes::get_material((DWORD64)renderer)) {
															Unity::set_material(renderer, FireMaterialA);
															Classes::set_shader((DWORD64)material, FireShaderA);



														}
														break;
													
													}
												}
											}
											else if (Vars::Visuals::PlayerEsp::HandChams)
											{
												switch (Vars::Visuals::PlayerEsp::HandChamsType)
												{
												case 0:
													if (StormShader != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, StormShader);
														chamsMat2 = Classes::get_material((DWORD64)renderer);
														// GUI::SetInt((DWORD64)chamsMat2, _(L"rainbow_go"), 0);
													}
													break;
												case 1: // GalaxyPink
													if (GalaxyPink != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, GalaxyPink);
													}
													break;
												case 2:
													if (GalaxyGreen != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, GalaxyGreen);
													}
													break;
												case 3:
													if (GalaxyRed != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, GalaxyRed);
													}
													break;
												case 4:
													if (GalaxyBlue != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, GalaxyBlue);
													}
													break;
												case 5:
													if (Test_Bundle != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, Test_Bundle);
													}
													break;
												case 6:
													if (Test_Bundle2 != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, Test_Bundle2);
													}
													break;
												case 7:
													if (Harvey != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, Harvey);
														Classes::set_shader((DWORD64)material, Harvey_shader);
													}
													break;
												case 8:
													if (FireBundleA != Classes::get_material((DWORD64)renderer)) {
														Unity::set_material(renderer, FireMaterialA);
														Classes::set_shader((DWORD64)material, FireShaderA);



													}
													break;
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
		}
	}
}
void(*WriteToStream)(uint64_t, uint64_t) = NULL;

void LaunchProjectile_hk(DWORD baseProjectile)
{

	if (!baseProjectile) return;


	Hooks::LaunchProjectile_Orig(baseProjectile);

	Weapon* Held = HeldEntity;
	if (!Held) return;
	BaseProjectile* ProjectileList = Read<BaseProjectile*>(Read<DWORD64>((DWORD64)Held + 0x398) + 0x10);
	if (!ProjectileList) return;

	for (int i = 0; i < ProjectileList->Size(); i++) {
		auto pr = *(Projectile**)((DWORD64)ProjectileList + 0x20 + i * 0x8);

		if (!pr) continue;

		// Launch(pr);
	}

}
//int StoredStone111 = 0;
float LastPickUp = 0.0;
int LoopValue = 0;
int LoopUpdateRate = 100;
bool FindObjects = false;

void hook_PlayerProjectileUpdate(int64_t rcx, int64_t rdx, int64_t r9, int64_t PlayerProjUpdate, int64_t arg5)
{
	typedef void(__stdcall* Orig)(int64_t, int64_t, int64_t, int64_t, int64_t);

	auto ppu = reinterpret_cast<PlayerProjectileUpdate*>(PlayerProjUpdate);
	
	return ((Orig)(Hooks::PlayerProjectileUpdate_orig))(rcx, rdx, r9, PlayerProjUpdate, arg5);
}



class PlayerProjectileRicochet {
public:
	union {
		OFFSET(int, projectileID, 0x10);
		OFFSET(Vector3, hitPosition, 0x14);
		OFFSET(Vector3, inVelocity, 0x20);
		OFFSET(Vector3, outVelocity, 0x2C);
		OFFSET(Vector3, hitNormal, 0x38);
		OFFSET(float, travelTime, 0x44);
	};
};

void hook_PlayerProjectileRicochet(int64_t rcx, int64_t rdx, int64_t r9, int64_t playerProjectileRicochet, int64_t arg5)
{
	typedef void(__stdcall* Orig)(int64_t, int64_t, int64_t, int64_t, int64_t);
	auto projectileRicochet = reinterpret_cast<PlayerProjectileRicochet*>(playerProjectileRicochet);

	if (!Target.Cur) return ((Orig)(Hooks::PlayerProjectileRicochet_orig))(rcx, rdx, r9, playerProjectileRicochet, arg5);//fixed;

	Projectile* projectile = PrUpdate;
	if (projectile)
	{
		projectileRicochet->projectileID = projectile->projectileID();
		projectileRicochet->hitPosition = projectile->currentPosition();
		projectileRicochet->hitNormal = Vector3::Zero();
		projectileRicochet->travelTime = projectile->traveledTime();
		projectileRicochet->inVelocity = projectile->currentVelocity();

		Vector3 Direction = Classes::GetModifiedAimCone(0, Target.Pos - EyePos, false);
		Vector3 outVelocity = Direction.Normalized() * (projectile->currentVelocity().Length());

		projectileRicochet->outVelocity = outVelocity;
		projectile->currentVelocity(outVelocity);
		projectile->currentPosition(projectile->currentPosition() + projectile->currentVelocity().Normalized() * 0.001f);
		projectile->Integrity(1);
		((Orig)(Hooks::PlayerProjectileRicochet_orig))(rcx, rdx, r9, playerProjectileRicochet, arg5);

		Classes::DDrawSphere(projectileRicochet->hitPosition, 0.5, { 255,255,255,255 }, 5, false);
		return;
	}

	
}

void ProcessAttack_hk(DWORD64 melee, HitTest* hitTest)
{

	if (Vars::Misc::AlwaysHotSpot)
	{

		AimResult OreEntity = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("OreResourceEntity"));
		AimResult TreeEntity = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("TreeEntity"));

		if (TreeEntity.valid && TreeEntity.dist <= 3 && TreeEntity.dist < OreEntity.dist)
		{
			AimResult TreeMarker = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("TreeMarker"));
			if (TreeMarker.valid && TreeMarker.dist <= 3)
			{
				TreeEntity = TreeMarker; // hitTest->HitTest_HitMaterial((Str*)Il2cpp::new_string("glass"));
				hitTest->HitTransform(TreeEntity.entity->get_transform());
				hitTest->HitPoint(InverseTransformPoint(TreeEntity.entity->get_transform(), TreeEntity.entity->get_transform()->Position()));
				hitTest->HitTest_HitMaterial((Str*)Il2cpp::new_string(_("wood")));
			}
		}

		if (OreEntity.valid && OreEntity.dist <= 3 && OreEntity.dist < TreeEntity.dist)
		{
			AimResult OreHotSpot = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("OreHotSpot"));
			if (OreHotSpot.valid && OreHotSpot.dist <= 3)
			{
				OreEntity = OreHotSpot;
				hitTest->HitTransform(OreEntity.entity->get_transform());
				hitTest->HitPoint(InverseTransformPoint(OreEntity.entity->get_transform(), OreEntity.entity->get_transform()->Position()));
			}
		}
	}
	



	return Hooks::ProcessAttack_Orig(melee, hitTest);


}

void GetHeldEntity(BasePlayer* player)
{
	BaseProjectile* get_ActiveWeapon = player->GetActiveWeapon();
	if (get_ActiveWeapon)
	{
		ActiveWeapon = get_ActiveWeapon;
		HeldEntity = ActiveWeapon->HeldEntity();
	}
	else
	{
		ActiveWeapon = 0;
		HeldEntity = 0;
	}
}

BasePlayer* PlayerList[256];

void StoringEspLoop() {
	int ListSize = sizeof(EspObjects) / sizeof(EspObjects[0]);

	for (int i = 0; i < ListSize; i++) {

	}
}

void hk_BlockJump(float duration)
{
	reinterpret_cast<void (*)(float)>(HKBlockJump)(0);
} // BaseMovement_BlockJump

void hk_BaseMovement_BlockJump(float duration)
{
	reinterpret_cast<void (*)(float)>(BaseMovement_BlockJump)(0);
}



#define CALLED_BY(func,off) (reinterpret_cast<std::uint64_t>(_ReturnAddress()) > func && reinterpret_cast<std::uint64_t>(_ReturnAddress()) < func + off)

DWORD64 get_fixedTime_orig, get_trans_orig, get_run_orig;
bool cokksdf = false;



void MeleeAimBot(Projectile* pr)
{
	if (Vars::Exploits::MeleePsilent)
	{
		if (!Target.Cur) return;

		Vector3 EyePsoition = LocalPlayer->GetEyes()->EyePosition();
		Vector3 RealEyePsoition = LocalPlayer->GetEyes()->EyePosition();

		if (Vars::Exploits::Manipulation && Manipulating) {
			EyePsoition += ManipulationAngle;
		}
		else if (EyePsoition != RealEyePsoition)
		{
			EyePsoition = RealEyePsoition;
		}

		float TravelTime = 0;
		Vector3 aimVel;
		bool didPredict = false;

		Vector3 origVel = Read<Vector3>((DWORD64)pr + O::Projectile::initialVelocity);

		Vector3 EndPoint = GetTrajectoryForEndPoint(Target.Pos, EyePsoition, origVel.Length() * 1.5f, pr->Drag(), pr->gravityModifier(), 0, &didPredict, &TravelTime);
		EndPoint += (PredictionData::PredictionDatas.avgVel) * TravelTime;
		Vector3 Direction = Classes::GetModifiedAimCone(0, EndPoint - EyePsoition, false);

		aimVel = Direction.Normalized() * (origVel.Length() * 1.5f);


		Write<Vector3>((DWORD64)pr + O::Projectile::initialVelocity, aimVel);
		Write<Vector3>((DWORD64)pr + O::Projectile::currentVelocity, aimVel);
		pr->get_transform()->SetBonePos(EyePsoition);
		pr->currentPosition(EyePsoition);
	
	}
}

float hk_getFixedTime() {
	if (CALLED_BY(g_Base + 0x709670 , 0x100)) {
		Projectile* pr = reinterpret_cast<Projectile*>(lastProjectile);
		if (pr) {
			Weapon* Held = HeldEntity; 
			if (Held && get_isAlive(pr) && get_isAuthoritative(pr)) {
				auto classname = Held->ClassName();
				if (m_strcmp(classname, _("BaseMelee")) || (m_strcmp(classname, _("Paddle")) || (m_strcmp(classname, _("Jackhammer"))))) {
					MeleeAimBot(pr);
				}
			}
		}
	}

	return reinterpret_cast<float(*)()>(get_fixedTime_orig)();
}

char* hk_Run() {

	return _("assets/bundled/prefabs/fx/")/*reinterpret_cast<float(*)()>(get_fixedTime_orig)()*/;
}

__int64 hk_get_transform(__int64 a1) {
	if (CALLED_BY(g_Base + 0x709670, 0x100)) {
		Projectile* pr = reinterpret_cast<Projectile*>(a1);
		if (get_isAlive(pr) && get_isAuthoritative(pr)) {
			lastProjectile = a1;
		}
	}

	return reinterpret_cast<__int64(*)(__int64)>(get_trans_orig)(a1);
}


DWORD64 HookedProjShoot;
void hk_ClientInput(BasePlayer* baseplayer, InputState* state) {


	if (!DoAttackhk)
		DoAttackhk = Virtual_Hook(_("BaseProjectile"), _("DoAttack"), &hk_DoAttack);
	if (!hkAttack)
		hkAttack = Virtual_Hook(_("BasePlayer"), _("OnAttacked"), &OnAtttackedHook); // HitInfo info
	if (!mvitem)
		mvitem = Virtual_Hook(_("ItemIcon"), _("TryToMove"), &hk_TryToMove);
	if (!DoFixedUpd)
		DoFixedUpd = Virtual_Hook(_("PlayerWalkMovement"), _("DoFixedUpdate"), &hk_DoFixedUpdate);
	if (!PlayerWM)
		PlayerWM = Virtual_Hook(_("PlayerWalkMovement"), _("ClientInput"), &hk_PlayerWalkMovement_ClientInput);
	
	
	{
		static bool psilent_hook = true;
		if (psilent_hook) {
			auto& serverrpc_playerprojectileattack = *(__int64*)(**(__int64**)(*(__int64*)(g_Base + offsets::Method$BaseEntity_ServerRPCPlayerProjectileShoot__) + 0x38) + 8);
			if (serverrpc_playerprojectileattack)
			{
				Hooks::PlayerProjectileShoot_orig = serverrpc_playerprojectileattack;
				serverrpc_playerprojectileattack = (DWORD64)&hook_PlayerProjectileShoot;
				psilent_hook = false;
			}
		}


		{
			static bool attack_hook = true;
			if (attack_hook) {
				auto& serverrpc_playerprojectileattack = *(__int64*)(**(__int64**)(*(__int64*)(g_Base + offsets::Method$BaseEntity_ServerRPC_PlayerProjectileAttack___) + 0x38) + 8);
				if (serverrpc_playerprojectileattack)
				{
					PlayerProjectileAttack_Orig = serverrpc_playerprojectileattack;
					serverrpc_playerprojectileattack = (DWORD64)&hook_PlayerProjectileAttack;
					attack_hook = false;
				}
			}
		}

		
	}
	float MEGAMAGICBULLETCALCULATION;
	static DWORD64 StoredMainCamera = 0;
	if (baseplayer) {

		if (LocalPlayer != baseplayer)
		{

			if (Unity::NicotineBundle)
				Unity::UnloadBundle(Unity::NicotineBundle, true);
			if (Unity::GGshader)
				Unity::UnloadBundle(Unity::GGshader, true);
			if (Unity::LogoPng)
				Unity::UnloadBundle(Unity::LogoPng, true);
			Unity::CanOverWriteAssets = true;

			GUI::InitAssets();

			if (!StoredMainCamera || Unity::CanOverWriteAssets)
				StoredMainCamera = Unity::get_main_camera();
 
			bool loaded_bundles;
			bool loaded1 = false, loaded2 = false, loaded3 = false, loaded4 = false, loaded5 = false, loaded6 = false, loaded7 = false, loaded8 = false, loaded9 = false;
			if (Unity::NicotineBundle && Unity::GGshader && !loaded_bundles) {
				if (Unity::CanOverWriteAssets || GalaxyPink == 0) {
					//Galaxymaterial = Unity::LoadAsset(Unity::GGshader, _(L"assets/hologramshader.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader"))); loaded1 = true;
					GalaxyPink = Unity::LoadAsset(Unity::GGshader, _(L"assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_11.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded1 = true;
				}
				if (Unity::CanOverWriteAssets || StormShader == 0) {
					StormShader = Unity::LoadAsset(Unity::NicotineBundle, _(L"assets/magicrainbowdiscogridshader/tazoshader/magicrainbowdiscogridshader/material/mat_dance_rainbow.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded2 = true;
				}
				if (Unity::CanOverWriteAssets || GalaxyGreen == 0) {
					// StandardMat = Unity::LoadAsset(Unity::GGshader, _(L"assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_14.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded3 = true;
					GalaxyGreen = Unity::LoadAsset(Unity::GGshader, _(L"assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_14.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded3 = true;
				}
				if (Unity::CanOverWriteAssets || GalaxyRed == 0) {
					//	FlatShader = Unity::LoadAsset(Unity::GGshader, _(L"assets/chams.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader"))); loaded4 = true;
					GalaxyRed = Unity::LoadAsset(Unity::GGshader, _(L"assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_09.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded4 = true;
				}
				if (Unity::CanOverWriteAssets || GalaxyBlue == 0) {
					//	FlatShader = Unity::LoadAsset(Unity::GGshader, _(L"assets/chams.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader"))); loaded4 = true;
					GalaxyBlue = Unity::LoadAsset(Unity::GGshader, _(L"assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_02.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded5 = true;
				} // assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_07.mat

				if (Unity::CanOverWriteAssets || GalaxyBlue == 0) {
					//	FlatShader = Unity::LoadAsset(Unity::GGshader, _(L"assets/chams.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader"))); loaded4 = true;
					GalaxyBlue = Unity::LoadAsset(Unity::GGshader, _(L"assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_02.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded6 = true;
				} // assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_07.mat
				if (Unity::CanOverWriteAssets || Test_Bundle == 0) {
					FlatShader = Unity::LoadAsset(Unity::GGshader, _(L"assets/chams.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader"))); loaded4 = true;
					Test_Bundle = Unity::LoadAsset(Unity::sandy, _(L"assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_13.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded7 = true;
				} // assets/sinevfx/galaxymaterials/resources/materials/galaxymaterial_07.mat
				if (Unity::CanOverWriteAssets || Test_Bundle2 == 0) {
					FlatShader = Unity::LoadAsset(Unity::GGshader, _(L"assets/chams.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader"))); loaded4 = true;
					Test_Bundle2 = Unity::LoadAsset(Unity::sandy1, _(L"hologram gun body.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded8 = true;
					loaded_bundles = true;
				}
				if (Unity::CanOverWriteAssets || Harvey == 0) {
					Harvey_shader = Unity::LoadAsset(Unity::Harvey, _(L"poiyomi pro geometric dissolve.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader"))); loaded4 = true;
					Harvey = Unity::LoadAsset(Unity::Harvey, _(L"galaxy.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded8 = true;
					loaded_bundles = true;
				}
	
			if (Unity::CanOverWriteAssets || FireBundleA == 0) {
				Harvey_shader = Unity::LoadAsset(Unity::Harvey, _(L"new amplifyshader.shader"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Shader"))); loaded4 = true;
				Harvey = Unity::LoadAsset(Unity::Harvey, _(L"fire.mat"), Il2cpp::TypeGetObject(_("UnityEngine"), _("Material"))); loaded8 = true;
				loaded_bundles = true;
			}
			}
			if (loaded1 && loaded2 && loaded3 && loaded4 && loaded5 && loaded6 && loaded7 && loaded8)
				Unity::CanOverWriteAssets = false;

			Unity::FindMatrix(StoredMainCamera);
			LocalPlayer = baseplayer;
		}
		GetHeldEntity(baseplayer);

		// baseplayer->SetFlag(131072);

		float MaxDesync = Vars::Exploits::DesyncDist * 0.001;
		
		MyRGB = Color(RGBA().r, RGBA().g, RGBA().b, 255);

		Vector3 MyEyePos = baseplayer->GetNetworkEyePosition();// baseplayer->GetEyes()->EyePosition();
		MyEyePos += ManipulationAngle;
		EyePos = MyEyePos;

		// Target = baseplayer->FindBestTarget(EyePos);
		if (Target.Cur)
			Vars::Exploits::BulletTpExternded = Vars::Exploits::isBulletTpExternded && Classes::get_mounted((DWORD64)Target.Cur) ? true : false;
		lowvelocity::find_prediction_angle();
		uintptr_t* mount_ptr = (DWORD64*)Classes::get_mounted((DWORD64)baseplayer);
		float num5 = mount_ptr ? 25 : 5.5;

		double desyncTime = (Unity::RealtimeSinceStartup() - baseplayer->lastSentTickTime());
		Vars::Exploits::DesyncTime = desyncTime;
		float num = 1.f + AntiHack::eye_forgiveness;
		float eye_clientframes = AntiHack::eye_clientframes;
		float eye_serverframes = AntiHack::eye_serverframes;
		float num2 = eye_clientframes / 60.f;
		float num3 = eye_serverframes * max(Unity::get_deltaTime(), Unity::get_smoothDeltaTime(), Unity::get_fixedDeltaTime());
		float num4 = (Vars::Exploits::DesyncTime + num2 + num3) * num;
		float num6 = 5.5 + LocalPlayer->GetParentVelocity().Magnitude() + LocalPlayer->GetMountVelocity().Magnitude();
		float num7 = LocalPlayer->BoundsPadding() + num4 * num6 + 0.125f;

		double EyeDist = num7/*num7*/;/*(0.1f + ((desyncTime + 2.f / 60.f) * 1.5f) * 5.5) + 0.125f;*///  (0.1f + ((desyncTime + 2.f / 60.f) * 1.50f) * num5) - 0.59375;
		if (Vars::Exploits::Manipulation && Manipulating)
			LastDesyncDist = max(LastDesyncDist, EyeDist);
		if (Vars::Misc::BrightNight || Vars::Misc::TimeChanger || Vars::Misc::SkyColor || Vars::Misc::AmbientColor)
			Ambient();

		CustumTime();

		if (Vars::Misc::NoFallDamage) baseplayer->NoFall();


		if (Vars::Misc::MassSuicide)
			Hooks::OnLand(baseplayer, -1337);

		if (Vars::Misc::DoorKnocker) {
			AimResult closest = AimResult::get_closest_object(baseplayer->GetTransform(47)->Position(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("Door"));
			if (closest.valid && Maths::Calc3D_Dist(baseplayer->GetBoneByID(head), closest.pos) < 3) {
				EbynMozga((DWORD64)closest.entity);
			}
		}

		

		if (Vars::Misc::ray_light_changer) {
			reinterpret_cast<void(__fastcall*)(float)>(g_Base + offsets::set_rayleigh)(Vars::Misc::rayleigh);
		}
		else {
			reinterpret_cast<void(__fastcall*)(float)>(g_Base + offsets::set_rayleigh)(Vars::Misc::rayleigh);
		}
		if (Vars::Misc::mie_changer) {
			reinterpret_cast<void(__fastcall*)(float)>(g_Base + offsets::set_mie)(Vars::Misc::mie);
		}
		else {
			reinterpret_cast<void(__fastcall*)(float)>(g_Base + offsets::set_mie)(Vars::Misc::mie);
		}
		if (Vars::Misc::brighttness_changer) {
			reinterpret_cast<void(__fastcall*)(float)>(g_Base + offsets::set_brightness)(Vars::Misc::brightness);
		}
		else {
			reinterpret_cast<void(__fastcall*)(float)>(g_Base + offsets::set_brightness)(Vars::Misc::brightness);
		}

		if (Vars::Misc::ShootMounted) {
			auto mountable = baseplayer->Mountable();
			if (mountable)
				mountable->CanwieldItem(true);
		}


		baseplayer->DebugColliders();

		if (Vars::Misc::SpiderMan)
			baseplayer->SpiderMan();

		if (Vars::Misc::BlockCommands) {
			BlockServerComands();
		}
		
		if (Vars::Misc::AdminFlag) {
			baseplayer->SetFlag(4);
		}

		if (Vars::Misc::InfinityJump)
			baseplayer->InfinityJump();

			baseplayer->SetFov();

		static float DefaultAspect = 0;
		if (!DefaultAspect)
			DefaultAspect = Maths::m_Abs( Unity::get_aspect(StoredMainCamera) );
		if (Vars::Misc::AspectRatio)
		{
			Unity::SetAspect(StoredMainCamera, Vars::Misc::Aspect);
		}
		else if (DefaultAspect && !Vars::Misc::AspectRatio)
		{
			Unity::SetAspect(StoredMainCamera, DefaultAspect);
		}



		if (Vars::Visuals::PlayerEsp::MovmentLine)
		{
			Color Col = RGBA();
			Classes::DDrawLine(baseplayer->GetPlayerModel()->ModelPosition(), baseplayer->lastSentTick()->position(), { ColorPicker::MovmentRGBBool ? Color(Col.r,Col.g,Col.b,255) : ColorPicker::MovmentLine }, 2.f, false, true);
		}
	

		if (Vars::Exploits::Manipulation && Manipulating) 
		{
			baseplayer->ClientTickInterval(MaxDesync);
		}
		else {
			float MinDesync = Vars::Exploits::MinDecync * 0.001;
			baseplayer->ClientTickInterval(MinDesync); }
		if (Vars::Exploits::Manipulation && Manipulating)
		{
			if (Target.Cur) Manipulation::DoManipulation(baseplayer, Target.Pos, EyeDist);

			if (Vars::Exploits::Visualize) {

				static float desyncPoint = 0;
				float x, z = 0;
				if (desyncPoint < 360)
				{
					desyncPoint += 0.08;
				}
				else
				{
					desyncPoint = 0;
				}
				Vector3 playerPos = LocalPlayer->GetBoneByID(head);

				x = Maths::m_Sin(desyncPoint) * EyeDist;
				z = Maths::m_Cos(desyncPoint) * EyeDist;

				Classes::DDrawSphereGizmo(playerPos + Vector3(-x, 0, -z), 0.06, { 0, 197, 255, 200 }, 0.06, false, false);

				Classes::DDrawSphereGizmo(playerPos + Vector3(x, 0, z), 0.06, { 0, 197, 255, 200 }, 0.06, false, false);


			}
		}
		else if (!ManipulationAngle.Empty())
		{
			ManipulationAngle = Vector3::Zero();
		}

		bool chamsdist = false;
		if (!chamsdist || baseplayer->IsSleeping())
		{
			auto klazz = Il2cpp::InitClass(_("Culling"), _("ConVar"));
			UINT64 st = safe_read(klazz + 0xB8, UINT64);
			safe_write(st + 0x4, 400.f, float);
			safe_write(st + 0x8, 0, float);
			chamsdist = true;
		}

		WeaponFix();
		HandChams();
	}

	if (Vars::Visuals::PlayerEsp::HandChams || Vars::Visuals::PlayerEsp::WeaponChams) { // WeaponChams
		auto pizdec = Il2cpp::InitClass(_("Graphics"), _("ConVar"));
		auto static_fields = safe_read(pizdec + 0xb8, uintptr_t);
		safe_write(static_fields + 0x85, false, bool);
	}

	if (Vars::Misc::InstaRevive && Unity::GetKeyInt(Vars::Keys::InstaRevive))
	{
		if (FindCurTarget.Cur && FindCurTarget.Wounded && !FindCurTarget.Heli && Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(head), FindCurTarget.Pos) < 3)
			Classes::ServerRPC((DWORD64)Target.Cur, _(L"RPC_Assist"));
	}


	if (Vars::Misc::SilentStash && SilentStashing)
	{
		AimResult Closest = AimResult::get_closest_object(baseplayer->GetTransform(47)->Position(), _("small_stash_deployed.prefab"));
		if (Closest.valid)
		{
			if (Closest.dist < 3) Classes::ServerRPC((DWORD64)Closest.entity, _(L"RPC_OpenLoot"));
		}
	}
	if (Vars::Misc::SilentTurret)
	{
		if (ClosestTurret.Entity != 0)
		{
			if (ClosestTurret.Dist < 3) Classes::ServerRPC((DWORD64)ClosestTurret.Entity, _(L"AddSelfAuthorize"));
		}
	}
	float last_recycler = 0.f;
	if (Vars::Misc::StopRecycler && Unity::get_fixedTime() > last_recycler + 0.35f)
	{
		if (ClosestRecycler.Entity != 0)
		{
			if (ClosestRecycler.Dist < 3)
			{
				Classes::ServerRPC((DWORD64)ClosestRecycler.Entity, _(L"SVSwitch"));
				last_recycler = Unity::get_fixedTime();
			}
		}
	}


	Unity::IgnoreLayerCollision(layer::PlayerMovement, layer::Water, !Vars::Misc::Jesus);
	Unity::IgnoreLayerCollision(layer::PlayerMovement, layer::Tree, Vars::Misc::RemoveCollision);
	Unity::IgnoreLayerCollision(layer::PlayerMovement, layer::AI, Vars::Misc::RemoveCollision);

	if (Target.Cur)
		SimulateMovement();

	if (Vars::Exploits::BulletTpType == 0)
		Vars::Exploits::BulletTpDist = 1.6;
	if (Vars::Exploits::BulletTpType == 1)
		Vars::Exploits::BulletTpDist = 1.8;
	if (Vars::Exploits::BulletTpType == 2)
		Vars::Exploits::BulletTpDist = 1.95;
	if (Vars::Exploits::BulletTpType == 3) {
		float endScanRange = 2.95;
		Vars::Exploits::BulletTpDist = endScanRange;
	}
		

	if (Target.Cur && Vars::Exploits::BulletTp && Vars::Exploits::DrawBulletTp && !Target.Heli && !Target.Turret)
	{
		float ScanRange = Vars::Exploits::BulletTpExternded ? 6 : Vars::Exploits::BulletTpDist;
		Classes::DDrawSphere(Target.Cur->ManipPoint(), Vars::Exploits::BulletTpDist, { 0, 197, 255, 200 }, 0.01, false);
	}


	Hooks::ClientInput_Orig(baseplayer, state);

	if (Vars::Misc::JitterAA) {
		Vector3 spin_angles = Vector3::Zero();
		Vector3 real_angles = state->AimAngles();

		spin_angles = Vector3(Maths::my_rand() % 999 + -200, Maths::my_rand() % 600 + -200, Maths::my_rand() % 200 + -200);//Vector3(-999, Maths::my_rand() % 999, Maths::my_rand() % 999);

		spin_angles.z = 0.f;
		spin_angles.y = real_angles.y - 180.f;

		state->AimAngles(spin_angles);
	}

	
}

