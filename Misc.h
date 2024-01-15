#pragma once

namespace PredictionData {
	struct
	{
		//std::array<Vector3, 64> velocities;
		Vector3 velocities[32];
		int currentVelocityRecords = {};
		int currentVelocityIndex = {};
		Vector3 avgVel = Vector3{ 0.f, 0.f, 0.f };
	} inline PredictionDatas;
}

void InteractiveFlyHack(bool IsTrue, PlayerWalkMovement* Walk)
{
	if (IsTrue && Flying || Vars::Misc::InteractiveDebug && Debugging) // Mega UD external Method FlyHack Very Good No Admin Flaaaag
	{
		float FlySpeed = Vars::Misc::FlySpeed;
		Vector3 TargetMovement = safe_read(Walk + 0x34, Vector3);
		Vector3 Movement = TargetMovement * FlySpeed;

		safe_write(Walk + O::PlayerWalkMovement::flying, 1, bool);	// private bool flying;
		safe_write(Walk + O::PlayerWalkMovement::swimming, 0.f, float);	// private bool swimming;
		safe_write(Walk + O::PlayerWalkMovement::gravityMultiplierSwimming, 0, bool);	// private bool gravityMultiplierSwimming;

		if (Unity::GetKeyInt(32)) {
			Movement += Vector3(0.f, 2.f * FlySpeed, 0.f);
		}
		if (Walk->Ducking()) {
			Movement -= Vector3(0.f, 2.f * FlySpeed, 0.f);
		}

		safe_write(Walk + 0x34, Movement, Vector3);
	}
}

void Ambient()
{
	static bool WasSkyOn = false;

	static bool DefaultSkyColor = false;
	static DWORD64 SavedSkyColor = 0;
	static DWORD64 SavedSkyColorDay = 0;

	static bool DefaultAmbColor = false;
	static DWORD64 SavedAmbColor = 0;

	UINT64 klass = Il2cpp::InitClass(_("TOD_Sky"), _(""));
	UINT64 static_fields = safe_read(klass + 0xB8, UINT64);

	UINT64 instances = safe_read(static_fields, UINT64);
	UINT64 List = safe_read(instances + 0x10, UINT64);
	UINT64 TOD_Sky = safe_read(List + 0x20, UINT64);
	const DWORD64 TOD_CycleParameters = Read<DWORD64>(TOD_Sky + 0x38);

	if (Vars::Misc::BrightNight) {

		UINT64 night = safe_read(TOD_Sky + 0x58, UINT64); // 0x54ToolCupboardDist
		UINT64 ambient = safe_read(TOD_Sky + 0x90, UINT64);

		safe_write(night + 0x54, 0, float);
		safe_write(ambient + 0x14, 0, float);
		safe_write(night + 0x50, 10, float);
	}
	if (GUI::open)
	{

		if (Vars::Misc::SkyColor)
		{
			UINT64 day = Read<UINT64>(TOD_Sky + 0x50);
			UINT64 sky_color = Read<UINT64>(day + 0x28);
			UINT64 sky_gradient = Read<UINT64>(sky_color + 0x10);
			Write<Color>(sky_gradient, ColorPicker::SkyRGBBool ? RGBA().GetUnityColor() : ColorPicker::SkyColor.GetUnityColor());

			DWORD64 night = Read<DWORD64>(TOD_Sky + 0x58);
			DWORD64 night_sky_color = Read<DWORD64>(night + 0x28);
			DWORD64 night_sky_gradient = Read<DWORD64>(night_sky_color + 0x10);

			Write<Color>(night_sky_gradient, ColorPicker::SkyRGBBool ? RGBA().GetUnityColor() : ColorPicker::SkyColor.GetUnityColor());
		}

		if (Vars::Misc::AmbientColor)
		{
			/*DWORD64 clouds = memory.read<DWORD64>(tod_sky_c + 0x78);
			Write<float>(clouds + 0x14, config.cloud_size);*/

			UINT64 Day = Read<UINT64>(TOD_Sky + 0x50);
			UINT64 DayAmbientColor = Read<UINT64>(Day + 0x40);
			UINT64 DayAmbientGradient = Read<UINT64>(DayAmbientColor + 0x10);
			Write<Color>(DayAmbientGradient, ColorPicker::AmbientRGBBool ? RGBA().GetUnityColor() : ColorPicker::AmbientColor.GetUnityColor());
		}
	}
}

void CustumTime() {
	static UINT64 st;

	if (!st) {
		auto klazz = Il2cpp::InitClass(_("Admin"), _("ConVar"));
		st = safe_read(klazz + 0xB8, UINT64); if (!st) return;
	}
	if (Vars::Misc::SkyFall) {
		Vars::Misc::TimeChanger = false;
		static float time;
		time += 0.01;
		Write<float>(st + 0x0, time);
		if (time > 23.98) time = 0;
	}
	if (Vars::Misc::TimeChanger) {
		Vars::Misc::SkyFall = false;
		Write<float>(st + 0x0, Vars::Misc::GameTime);
	}
	else if (!Vars::Misc::TimeChanger && !Vars::Misc::SkyFall)
	{
		Write<float>(st + 0x0, -1);
	}
}


float InstaHit(float desyncTime, float projectileVelocityScale, bool safe_mode = true) { //desyncTime: 1-0, projectileVelocityScale: un-modified base speed of projectile
	float initialDistance = 0.f;
	if (desyncTime < 1.f) {
		if (desyncTime > 0.075f) {
			if (safe_mode) {
				initialDistance = desyncTime * projectileVelocityScale;
			}
			else {
				initialDistance = (desyncTime * projectileVelocityScale) * (1.f + (0.49f * desyncTime));
			}
		}
		/*else {
			initialDistance = 10.f;
		}*/
	}
	return initialDistance;
}

float dlastKnock = 0.f;
void EbynMozga(DWORD64 Door) {
	float time = LocalPlayer->lastSentTickTime();
	if (time > dlastKnock + 0.5f) {
		auto Menu_KnockDoor = reinterpret_cast<void(*)(DWORD64, BasePlayer*)>(*reinterpret_cast<DWORD64*>(Il2cpp::Method(_("Door"), _("Menu_KnockDoor"), 0, _(""), _(""))));
		Menu_KnockDoor(Door, LocalPlayer);
		dlastKnock = time;
	}
}

namespace Manipulation {
	inline bool TestNoClipping(Vector3 oldPos, Vector3 newPos, float radius, bool sphereCast, int num1 = 429990145, float backtracking = 1) {
		int num = num1;
		// Vector3 oldPos, Vector3 newPos, float radius, float backtracking, bool sphereCast,  bool vehicleLayer = false, global::BaseEntity ignoreEntity = null
		Vector3 normalized = (newPos - oldPos).Normalized();
		Vector3 vector = oldPos - normalized * backtracking;
		float magnitude = (newPos - vector).Magnitude();
		bool flag{};
		if (sphereCast) {
			typedef bool (*AAA)(Ray, float, float, int);
			flag = ((AAA)(g_Base + offsets::o_SphereCast))(Ray(vector, normalized), radius, magnitude, num);/*Unity::SphereCast(Ray(vector, normalized), radius, magnitude, num);*/
		}
		return flag;
	}
	float NoClipRadius(float margin)
	{
		return  0.5f - margin;
	}
	float Max(float f1, float f2, float f3)
	{
		return max(max(f1, f2), f3);
	}

	double fAbs(double x)
	{
		union { double f; uint64_t i; } u = { x };
		u.i &= -1ULL / 2;
		return u.f;
	}


	//bool ValidateEyePos(BasePlayer* player, Vector3 eyePos, bool checkLineOfSight = true)
	//{
	//	bool flag = true;
	//	if (eyePos == Vector3::Zero())
	//	{
	//		// eye_nan
	//		flag = false;
	//	}
	//	if (AntiHack::eye_protection > 0)
	//	{
	//		double desyncTime = (Unity::RealtimeSinceStartup() - player->lastSentTickTime());
	//		float num = 1.f + AntiHack::eye_forgiveness;
	//		float eye_clientframes = AntiHack::eye_clientframes;
	//		float eye_serverframes = AntiHack::eye_serverframes;
	//		float num2 = eye_clientframes / 60.f;
	//		float num3 = eye_serverframes * max(Unity::get_deltaTime(), max(Unity::get_smoothDeltaTime(), Unity::get_fixedDeltaTime()));
	//		float num4 = (desyncTime + num2 + num3) * num;
	//		if (AntiHack::eye_protection >= 1)
	//		{
	//			float num5 = 5.5 + player->GetParentVelocity().Magnitude();
	//			float num6 = player->BoundsPadding() + num4 * num5;
	//			float num7 = player->GetEyes()->EyePosition().Distance(eyePos);
	//			if (num7 > num6)
	//			{
	//				// eye_distance
	//				flag = false;
	//			}
	//		}
	//		if (AntiHack::eye_protection >= 3)
	//		{
	//			float num8 = Maths::m_Abs(player->GetMountVelocity().y + player->GetParentVelocity().y);
	//			float num9 = player->BoundsPadding() + num4 * num8 + player->GetJumpHeight();
	//			float num10 = Maths::m_Abs(player->GetEyes()->EyePosition().y - eyePos.y);
	//			if (num10 > num9)
	//			{
	//				// eye_altitude
	//				flag = false;
	//			}
	//		}
	//		if (checkLineOfSight)
	//		{
	//			int num11 = 2162688;
	//			if (AntiHack::eye_terraincheck)
	//			{
	//				num11 |= 8388608;
	//			}
	//			if (AntiHack::eye_protection >= 2)
	//			{
	//				Vector3 center = player->GetEyes()->GetCenter();
	//				Vector3 position = player->GetEyes()->EyePosition();
	//				if (!Unity::LineOfSight(center, position, num11, AntiHack::eye_losradius, 0, 0) || !Unity::LineOfSight(position, eyePos, num11, AntiHack::eye_losradius, 0, 0))
	//				{
	//					// eye_los
	//					flag = false;
	//				}
	//			}
	//			if (AntiHack::eye_protection >= 4 && !Classes::HasParent(player))
	//			{
	//				Vector3 position2 = player->GetEyes()->EyePosition();
	//				float num12 = position2.Distance(eyePos);
	//				// Vector3 oldPos, Vector3 newPos, float radius, bool sphereCast, int num1 = 429990145, float backtracking = 1
	//				if (num12 > AntiHack::eye_noclip_cutoff)
	//				{
	//					if (Manipulation::TestNoClipping(position2, eyePos, Manipulation::NoClipRadius(AntiHack::eye_noclip_margin), AntiHack::noclip_protection >= 2, 429990145, AntiHack::eye_noclip_backtracking)) {
	//						// eye_noclip 
	//						flag = false;
	//					}
	//				}// Manipulation::TestNoClipping(position2, eyePos, Manipulation::NoClipRadius(AntiHack::eye_noclip_margin), AntiHack::noclip_protection >= 2, 429990145, AntiHack::eye_noclip_backtracking)
	//				else if (num12 > 0.01f && Manipulation::TestNoClipping(position2, eyePos, 0.01f, AntiHack::noclip_protection >= 2, 429990145, AntiHack::eye_noclip_backtracking))
	//				{
	//					// eye_noclip
	//					flag = false;
	//				} // Manipulation::TestNoClipping(position2, eyePos, 0.01f, AntiHack::eye_noclip_backtracking, AntiHack::noclip_protection >= 2, out collider, false, null)
	//			}
	//		}
	//		/*if (!flag)
	//		{
	//			global::AntiHack.AddViolation(player, global::AntiHackType.EyeHack, AntiHack::eye_penalty);
	//		}
	//		else if (AntiHack::eye_protection >= 5 && !player.HasParent() && !player.isMounted)
	//		{
	//			player.eyeHistory.PushBack(eyePos);
	//		}*/
	//	}
	//	return flag;
	//}

	bool ValidateEyePos(BasePlayer* player, Vector3 eyePos, bool checkLineOfSight = true)
	{
		Vector3 realEye = player->GetNetworkEyePosition();
		bool flag = true;
		if (!player) {
			flag = false;
		}
		if (eyePos == Vector3::Zero()) {
			// eye_nan
			flag = false;
		}
		if (AntiHack::eye_protection > 0) {
			float num = 1.f + AntiHack::eye_forgiveness;
			float eye_clientframes = AntiHack::eye_clientframes;
			float eye_serverframes = AntiHack::eye_serverframes;
			float num2 = eye_clientframes / 60.f;
			float num3 = eye_serverframes * max(Unity::get_deltaTime(), max(Unity::get_smoothDeltaTime(), Unity::get_fixedDeltaTime()));
			float num4 = (Vars::Exploits::DesyncTime + num2 + num3) * num;
			if (AntiHack::eye_protection >= 1)
			{
				float num5 = 5.5 + player->GetParentVelocity().Magnitude();
				float num6 = player->BoundsPadding() + num4 * num5;
				float num7 = realEye.Distance(eyePos);
				if (num7 > num6)
				{
					// eye_distance
					flag = false;
				}
			}
			if (AntiHack::eye_protection >= 3)
			{
				float num8 = Maths::m_Abs(player->GetMountVelocity().y + player->GetParentVelocity().y);
				float num9 = player->BoundsPadding() + num4 * num8 + player->GetJumpHeight();
				float num10 = Maths::m_Abs(realEye.y - eyePos.y);
				if (num10 > num9) {
					// eye_altitude
					flag = false;
				}
			}
			if (checkLineOfSight)
			{
				int num11 = 2162688;
				if (AntiHack::eye_terraincheck)
				{
					num11 |= 8388608;
				}

				/*bool CheckLOS(Vector3 source, Vector3 destination, float p1 = 0.18f, int layer = (int)Layers::ProjectileLineOfSightCheck | (int)Layers::Terrain | (int)Layers::z) {
					return LineOfSight(source, destination, layer, p1, 0, 0);
				}*/

				if (AntiHack::eye_protection >= 2)
				{
					Vector3 center = player->GetEyes()->GetCenter();
					Vector3 position = realEye;
					if (!Unity::LineOfSight(center, position, num11, AntiHack::eye_losradius, 0, 0) || !Unity::LineOfSight(position, eyePos, num11, AntiHack::eye_losradius, 0, 0))
					{
						// eye_los
						flag = false;
					}
				}
				if (AntiHack::eye_protection >= 4 && !Classes::HasParent(player))
				{
					Vector3 position2 = player->GetEyes()->EyePosition();
					float num12 = position2.Distance(eyePos);
					if (num12 > AntiHack::eye_noclip_cutoff)
					{
						if (TestNoClipping(position2, eyePos, NoClipRadius(AntiHack::eye_noclip_margin), AntiHack::noclip_protection >= 2, 429990145, AntiHack::eye_noclip_backtracking)) {
							// eye_noclip
							flag = false;
						}
					}
					else if (num12 > 0.01f && TestNoClipping(position2, eyePos, 0.01f, AntiHack::noclip_protection >= 2, 429990145, AntiHack::eye_noclip_backtracking)) {
						// eye_noclip
						flag = false;
					}
				}
			}
			/*if (!flag)
			{
				global::AntiHack.AddViolation(player, global::AntiHackType.EyeHack, AntiHack::eye_penalty);
			}
			else if (AntiHack::eye_protection >= 5 && !player.HasParent() && !player.isMounted)
			{
				player.eyeHistory.PushBack(eyePos);
			}*/
		}
		return flag;
	}

	//Vector3 ScanForHit(const Vector3& center_position, const Vector3& start_position, float radius, int numPoints)
	//{
	//	float angleIncrement = 2 * M_PI / numPoints;
	//	Vector3 normal = start_position - center_position;
	//	normal = normal.Normalized();
	//	float cosTheta = Maths::m_Cos(angleIncrement);
	//	float sinTheta = Maths::m_Sin(angleIncrement);
	//	float rotationMatrix[3][3] = {
	//		{ cosTheta + (1.f - cosTheta) * normal.x * normal.x, (1.f - cosTheta) * normal.x * normal.y - sinTheta * normal.z, (1.f - cosTheta) * normal.x * normal.z + sinTheta * normal.y },
	//		{ (1.f - cosTheta) * normal.y * normal.x + sinTheta * normal.z, cosTheta + (1.f - cosTheta) * normal.y * normal.y, (1.f - cosTheta) * normal.y * normal.z - sinTheta * normal.x },
	//		{ (1.f - cosTheta) * normal.z * normal.x - sinTheta * normal.y, (1.f - cosTheta) * normal.z * normal.y + sinTheta * normal.x, cosTheta + (1.f - cosTheta) * normal.z * normal.z }
	//	};

	//	float angle = 0.0f;
	//	for (int i = 0; i < numPoints; ++i)
	//	{
	//		float x = radius * Maths::m_Cos(angle);
	//		float y = radius * Maths::m_Sin(angle);
	//		float rotatedX = rotationMatrix[0][0] * x + rotationMatrix[0][1] * y;
	//		float rotatedY = rotationMatrix[1][0] * x + rotationMatrix[1][1] * y;
	//		float rotatedZ = rotationMatrix[2][0] * x + rotationMatrix[2][1] * y;

	//		Vector3 point(rotatedX + center_position.x, rotatedY + center_position.y, rotatedZ + center_position.z);

	//		if (point.Empty()) { angle += angleIncrement; continue; }
	//		if (!Unity::CheckLOS(start_position, point)) { angle += angleIncrement; continue; }
	//		if (!Unity::CheckLOS(point, center_position)) { angle += angleIncrement; continue; }

	//		return point;
	//	}
	//	return Vector3::Zero();
	//}

	template<typename T>
	class MyVector {
	private:
		T* data;
		size_t size;
		size_t capacity;

	public:
		MyVector() : data(nullptr), size(0), capacity(0) {}

		~MyVector() {
			delete[] data;
		}

		void push_back(const T& value) {
			if (size >= capacity) {
				reserve(capacity == 0 ? 1 : capacity * 2);
			}
			data[size++] = value;
		}

		void reserve(size_t newCapacity) {
			if (newCapacity <= capacity) {
				return;
			}

			T* newData = new T[newCapacity];
			for (size_t i = 0; i < size; ++i) {
				newData[i] = data[i];
			}

			delete[] data;
			data = newData;
			capacity = newCapacity;
		}

		size_t getSize() const {
			return size;
		}

		size_t getCapacity() const {
			return capacity;
		}
	};

	//int main() {
	//	MyVector<int> myVector;

	//	// Testing push_back function
	//	myVector.push_back(1);
	//	myVector.push_back(2);
	//	myVector.push_back(3);

	//	std::cout << "Size: " << myVector.getSize() << "\n";        // Output: Size: 3
	//	std::cout << "Capacity: " << myVector.getCapacity() << "\n";  // Output: Capacity: 4

	//	return 0;
	//}
	//```

	//	In this example, a simplified version of a custom `MyVector` class is created.The `push_back` function is implemented to add elements to the vector.If the current size of the vector exceeds the capacity, the `reserve` function is called, which increases the capacity by doubling it(if the capacity is initially 0, it is set to 1).

	//	The `reserve` function allocates a new block of memory with the new capacityand copies the existing elements from the current memory to the new memory block.Finally, the old memory is deallocatedand the new memory block is assigned as the vector's data.

	//	The `getSize` and `getCapacity` functions are included for testing purposes to retrieve the sizeand capacity of the vector.

	//	Please note that this is a simple implementationand may not include all the optimizationsand features of the standard library `std::vector`. The standard library implementation also provides additional functionality, such as iterators, dynamic resizing, and exception safety.


	double ceil(double x) {
		if (x >= 0.0) {
			int intValue = static_cast<int>(x);
			double fractionalPart = x - intValue;
			if (fractionalPart > 0.0) {
				intValue++;
			}
			return static_cast<double>(intValue);
		}
		else {
			int intValue = static_cast<int>(x);
			double fractionalPart = x - intValue;
			if (fractionalPart < 0.0) {
				intValue--;
			}
			return static_cast<double>(intValue);
		}
	}

	Vector3 generateSpherePoints(Vector3 eyePos, Vector3 start_pos, double radius, double step) {
		// Calculate the number of points required based on the radius and step value
		int numPoints = static_cast<int>(ceil((4 * M_PI * radius) / step));

		for (int i = 0; i < numPoints; ++i) {
			double theta = 2 * M_PI * i / numPoints;  // azimuthal angle
			double phi = M_PI * (i + 1) / (numPoints + 1);  // polar angle

			// Convert spherical coordinates to Cartesian coordinates
			double x = radius * Maths::m_Sin(phi) * Maths::m_Cos(theta);
			double y = radius * Maths::m_Sin(phi) * Maths::m_Sin(theta);
			double z = radius * Maths::m_Cos(phi);

			Vector3 point = Vector3((float)x + start_pos.x, (float)y + start_pos.y, (float)z + start_pos.z);
			if (point != Vector3::Zero()) {
				if (!Unity::CheckLOS(point, start_pos, 0.011)) continue;
				if (!Unity::CheckLOS(point, eyePos, 0.011)) continue;

				return point;
			}
		}
		return Vector3(0, 0, 0);
	} // ko pro hacker hit scan

	//int main() {
	//	double radius = 2.0;  // Radius of the sphere (in meters)
	//	double step = 0.2;  // Step size between each point (in meters)

	//	std::vector<Point3D> spherePoints = generateSpherePoints(radius, step);

	//	// Print the generated sphere points
	//	for (const Point3D& point : spherePoints) {
	//		std::cout << "Point: x = " << point.x << ", y = " << point.y << ", z = " << point.z << "\n";
	//	}

	//	return 0;
	//}

	inline Vector3 ScanForHit(Vector3 target, Vector3 start_pos, int numVertices, float radius = 1.59999999) {
		radius *= 0.99;
		Vector3* vectorList[] = { 0 };
		double phi = M_PI * (3 - Maths::m_Sqrt(5));
		for (int i = 0; i < numVertices; i++) {
			double y = 1 - (i / (numVertices - 1.0)) * 2;
			double radiusAtY = Maths::m_Sqrt(1 - y * y);
			double theta = phi * i;
			double x = Maths::m_Cos(theta) * radiusAtY;
			double z = Maths::m_Sin(theta) * radiusAtY;

			Vector3 check_pos = Vector3((float)x * ((float)(radius * 0.99)) + target.x, (float)y * ((float)(radius * 0.99)) + target.y, (float)z * ((float)(radius * 0.99)) + target.z);
			if (check_pos != Vector3(0, 0, 0) && check_pos.Distance(target) <= radius) {
				if (!Unity::CheckLOS(check_pos, start_pos, 0.2) || !Unity::CheckLOS(start_pos, check_pos, 0.2) || TestNoClipping(check_pos, target, 0.03125, true, (int)Layers::ProjectileLineOfSightCheck | (int)Layers::Terrain | (int)Layers::z, AntiHack::projectile_backtracking)) continue;
				return check_pos;
			}
		}
		return Vector3(0, 0, 0);
	} // Best HitScan In The World

	Vector3 ScanForHit(const Vector3& center_position, const Vector3& start_position, float radius, int numPoints)
	{
		float angleIncrement = 2 * M_PI / numPoints;
		Vector3 normal = start_position - center_position;
		normal = normal.Normalized();
		float cosTheta = Maths::m_Cos(angleIncrement);
		float sinTheta = Maths::m_Sin(angleIncrement);
		float rotationMatrix[3][3] = {
			{ cosTheta + (1.f - cosTheta) * normal.x * normal.x, (1.f - cosTheta) * normal.x * normal.y - sinTheta * normal.z, (1.f - cosTheta) * normal.x * normal.z + sinTheta * normal.y },
			{ (1.f - cosTheta) * normal.y * normal.x + sinTheta * normal.z, cosTheta + (1.f - cosTheta) * normal.y * normal.y, (1.f - cosTheta) * normal.y * normal.z - sinTheta * normal.x },
			{ (1.f - cosTheta) * normal.z * normal.x - sinTheta * normal.y, (1.f - cosTheta) * normal.z * normal.y + sinTheta * normal.x, cosTheta + (1.f - cosTheta) * normal.z * normal.z }
		};

		
		for (int i = 0; i < numPoints; ++i)
		{
			float angle = angleIncrement * i;
			float x = radius * Maths::m_Cos(angle);
			float y = radius * Maths::m_Sin(angle);
			/*double theta = phi * i;*/
			float rotatedX = rotationMatrix[0][0] * x + rotationMatrix[0][1] * y;
			float rotatedY = rotationMatrix[1][0] * x + rotationMatrix[1][1] * y;
			float rotatedZ = rotationMatrix[2][0] * x + rotationMatrix[2][1] * y;

			Vector3 point = Vector3(rotatedX + center_position.x, rotatedY + center_position.y, rotatedZ + center_position.z);

			Classes::DDrawSphere(point, 0.025, Color(255, 255, 255, 200), 0.01, false);

			if (point.Empty()) { angle += angleIncrement; continue; }
			if (!Unity::CheckLOS(start_position, point, 0.011)) { angle += angleIncrement; continue; }
			if (!Unity::CheckLOS(point, center_position, 0.011)) { angle += angleIncrement; continue; }

			return point;
		}
		return center_position;
	}
	namespace teleport {
		bool found_path = false;
		int current_step = 0;
		int path_ = 0;
		Vector3 path[1000]; //max 12?

		namespace options {
			int max_scans = 30;
		}
	};

	void ScanForTP(Vector3 start_pos, Vector3 end_pos) {
		if (!teleport::found_path) {
			teleport::current_step = 0;
		}
		float max_distance_2d = 5.f;
		float max_distance_y = 6.f;
		Vector3 pos_ = LocalPlayer->GetEyes()->EyePosition();
		for (int i = 0; i < 12;) {
			double phi = M_PI * (3 - Maths::m_Sqrt(5));
			if (teleport::found_path)
				break;
			for (int i = 0; i < teleport::options::max_scans; i++) {
				double y = 1 - (i / (teleport::options::max_scans - 1.0)) * 2;
				double radiusAtY = Maths::m_Sqrt(1 - y * y);
				double theta = phi * i;
				double x = Maths::m_Cos(theta) * radiusAtY;
				double z = Maths::m_Sin(theta) * radiusAtY;
				Vector3 check_pos = Vector3(x * 0.833333333f + start_pos.x, (float)y * 0.833333333f + start_pos.y, (float)z * 0.833333333f + start_pos.z);
				if (check_pos != Vector3(start_pos.x, (float)y * 0.833333333f + start_pos.y, start_pos.z))
				{
					if (!(Maths::m_Abs(start_pos.y - check_pos.y) > max_distance_y) && Vector2(start_pos.x, start_pos.z).Distance(Vector2(check_pos.x, check_pos.z)) < max_distance_2d) {
						if (!Manipulation::TestNoClipping(start_pos, check_pos, NoClipRadius(0.5), true)) {
							teleport::path[teleport::path_] = check_pos;
							teleport::path_++;
							max_distance_2d -= Vector2(start_pos.x, start_pos.z).Distance(Vector2(check_pos.x, check_pos.z));
							max_distance_y -= Maths::m_Abs(start_pos.y - check_pos.y);
							if (check_pos.Distance(end_pos) < 0.25f)
								teleport::found_path = true;
							break;
						}
					}
					else continue;
				}
			}
		}
	}

	Vector2 GetMaxDist(BasePlayer* player) {
		Vector2 flag = Vector2();

		if (!player)
			return flag;

		float desyncTime = (Unity::RealtimeSinceStartup() - LocalPlayer->lastSentTickTime());
		float num = 1.5f;
		float eye_clientframes = 2.0f;
		float eye_serverframes = 2.0f;
		float num2 = eye_clientframes / 60.f;
		float num3 = eye_serverframes * max(Unity::get_deltaTime(), max(Unity::get_smoothDeltaTime(), Unity::get_fixedDeltaTime()));
		float num4 = ((desyncTime + 2.f / 60.f) * num);
		float num5 = (5.5 + player->GetParentVelocity().Magnitude());// * mountNum;
		float num6 = (0.1f + (num4 * num5)) + 0.125f/*player->BoundsPadding() + num4 * num5*/; //max distance
		flag.x = num6;

		float num8 = Maths::m_Abs(player->GetMountVelocity().y + player->GetParentVelocity().y);
		float num9 = player->BoundsPadding() + num4 * num8 + player->GetJumpHeight(); //max y distance
		flag.y = num9;

		float num7 = Vector2().Zero2().Distance(flag); // we want this value to be less than num6
		if (num7 > num6) {
			float mod = num6 / num7;
			flag.y *= mod;
			flag.x *= mod;
		}
		num7 = Vector2().Zero2().Distance(flag);
		if (num7 > num6) {
			float mod = num6 / num7;
			flag.y *= mod;
			flag.x *= mod;
		}
		num7 = Vector2().Zero2().Distance(flag);
		if (num7 > num6) {
			float mod = num6 / num7;
			flag.y *= mod * mod;
			flag.x *= mod * mod;
		}
		return Vector2(flag.x * 0.99, flag.y * 0.99);
	}

	bool DoManipulation(BasePlayer* ply, Vector3 pos, float EyeDistance/*Vector2 EyeStruct*/)
	{
		/*float EyeDist = EyeStruct.x;
		float EyeRise = EyeStruct.y;*/
		Vector3 center = ply->GetNetworkEyePosition();
		Vector3 TargetPos = pos;
		Vector3 FakePos = pos;
		float ScanRange = Vars::Exploits::BulletTpExternded ? 6 : Vars::Exploits::BulletTpDist - Vars::Exploits::DistanceToBulletTp;
		if (Vars::Exploits::BulletTp && Vars::Exploits::DrawBulletTp) {
			Classes::DDrawSphere(Target.Cur->GetEyes()->EyePosition(), ScanRange, Color(0, 255, 255, 200), 0.01, false);
		}
		auto FindAngle = [&](Vector3 a) {
			Vector3 p = center + a;
			TargetPos = pos;

			if (!Manipulation::ValidateEyePos(LocalPlayer, p))
				return false;

			/*if (Vars::Exploits::ShowManipulation) {
				Classes::DDrawSphere(p, 0.025, { 255.f, 255.f, 255.f, 200.f }, 0.01, true);
			}*/

			bool got_los = false;
			bool losded;
			if (Vars::Exploits::BehindWall && (Vars::Exploits::BahindWallType == 0 || Vars::Exploits::BahindWallType == 1) && Vars::Exploits::Manipulation && Manipulating && !Target.Heli && !Target.Turret)
			{
				if (!Unity::CheckLOS(p, TargetPos))
				{ // Vars::Exploits::BehindWallScanStrength, ScanRange
					Vector3 checkTargePos = Target.Cur->get_transform()->Position() + Vector3(0, 1.26, 0) =  Classes::CenterPoint(Target.Cur) + Vector3(0, 0.2, 0);
					Vector3 RealTargetPosition = generateSpherePoints(p, checkTargePos, ScanRange, 0.2);/*ScanForHit(checkTargePos, p, Vars::Exploits::BehindWallScanStrength, ScanRange)*/;

					if (RealTargetPosition != Vector3(0, 0, 0)) {
						Vars::Exploits::BehindWallPos = RealTargetPosition;
						TargetPos = RealTargetPosition;
					}
					else { Vars::Exploits::BehindWallPos = { 0,0,0 }; TargetPos = pos; Vars::Exploits::HitScanBone = 47; }
				}
				else { Vars::Exploits::BehindWallPos = { 0,0,0 }; TargetPos = pos; Vars::Exploits::HitScanBone = 47; }
			}
			else { Vars::Exploits::BehindWallPos = { 0,0,0 }; TargetPos = pos; Vars::Exploits::HitScanBone = 47; }

			losded = !Unity::CheckLOS(p, TargetPos);

			if (losded)
				return false;

			ManipulationAngle = a;
			return true;
			};
		double height = 1.57079632679489661923;
		float y_step = height / Vars::Exploits::Optimisation;
		float step = (height * 2) / (Vars::Exploits::CheckAngels - 1);
		float x, z, current = 0;

		for (float y = height; y > -height; y -= y_step) {
			if (FindAngle(Vector3(0, y, 0))) return true;
			for (size_t val = 0; val < Vars::Exploits::CheckAngels; val++)
			{
				x = Maths::m_Sin(current) * EyeDistance;
				z = Maths::m_Cos(current) * EyeDistance;

				if (FindAngle(Vector3(x, y, z))) return true;
				if (FindAngle(Vector3(-x, y, z))) return true;
				if (FindAngle(Vector3(x, y, -z))) return true;
				if (FindAngle(Vector3(-x, y, -z))) return true;

				current += step;
			}
		}

		ManipulationAngle = Vector3(0, 0, 0);
		return false;
	}
}

namespace lowvelocity {
	Vector3 GetEndPointForTrajectory(Vector3 start, Vector3 target, float speed, float angle, float drag, float gravityMod)
	{
		auto checkCollision = [&](Vector3 start, Vector3 dir, Vector3* ray_hit) {
			RaycastHit outRay;
			auto mask = 10551296 | 1503731969 | 131072 | 1218519297 | 65536 | 1218519041;
			auto BigRayCast = reinterpret_cast<bool(*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>(g_Base + offsets::o_RaycastBig);
			if (BigRayCast(start, dir.Normalized(), &outRay, dir.Magnitude(), mask, QueryTriggerInteraction::Ignore))
			{
				*ray_hit = outRay.point;
				return true;
			}
			*ray_hit = Vector3();
			return false;
			};
		float pitchRad = DEG2RAD(angle);

		Vector3 dir = (target - start).Normalized();
		//dir.y = (float)Maths::m_Sin(pitchRad);

		Vector3 position = start;
		Vector3 posiiton = start;
		Vector3 velCheck = dir * speed;
		Vector3 velPrev = Vector3();

		const float stepSize = 0.03125f;

		for (float travelTime = 0.f; travelTime < 8.f; travelTime += stepSize)
		{
			velPrev = velCheck;
			posiiton = position;
			position += velCheck * stepSize;
			velCheck.y -= 9.81f * gravityMod * stepSize;
			velCheck -= velCheck * drag * stepSize;
			Vector3 hitpos = Vector3();
			if (checkCollision(start, velPrev, &hitpos)) {
				Classes::DDrawLine(EyePos, hitpos, Color(1, 1, 1, 1), 0.05, true, false);
				return hitpos;
			}
		}

		return position;
	}

	void find_prediction_angle() {
		if (Vars::Exploits::lv) {
			float min_vel = 0.6f;
			ItemModProj* mod = ActiveWeapon->GetItemModPr();
			Projectile* pr = mod->projectileObject()->Get()->get_class<Projectile*>();
			float drag = pr->Drag();
			float grav = pr->gravityModifier();
			float bulletSpeed = mod->GetRandomVelocity() * ActiveWeapon->HeldEntity()->projectileVelocityScale();

			GetEndPointForTrajectory(EyePos, EyePos + LocalPlayer->GetEyes()->BodyForward(), bulletSpeed, 60, drag, grav);
		}
	}
}

DWORD64 DoAttackhk;
DWORD64 MeleeDoAttack;
void hk_Melee_DoAttack(Weapon* baseProjectile) {

	/*if (Vars::Misc::HammerSpam) {
		if (baseProjectile) {
			if (ActiveWeapon->GetID() == 200773292) {
				BasePlayer* selectedEntity = Vars::Misc::HammerSpamMode == 0 ? LocalPlayer : Target.Cur;
				Vector3 HeadPos = selectedEntity->GetBoneByID(head);
				HammerSpam(selectedEntity, HeadPos, baseProjectile);
			}
		}
	}
	else
	{
		reinterpret_cast<DWORD64(*)(Weapon*)>(MeleeDoAttack)(baseProjectile);
	}*/

}

void hk_DoAttack(Weapon* baseProjectile)
{



	/*** RECOIL ***/
	RecoilProperties* h1 = Read<RecoilProperties*>((DWORD64)baseProjectile + Dump::BaseProjectile::recoil);
	RecoilProperties* NewRP = Read<RecoilProperties*>((DWORD64)h1 + 0x80);

	RecoilProperties* Current = NULL;

	if (NewRP)
		Current = NewRP;
	else if (h1)
		Current = h1;

	float controlled = Vars::Weapon::Recoil * 0.01;

	float& recoilYawMin = *(float*)(Current + 0x18);
	float	defaultrecoilYawMin = recoilYawMin;
	recoilYawMin *= controlled;

	float& recoilYawMax = *(float*)(Current + 0x1C);
	float	defaultrecoilYawMax = recoilYawMax;
	recoilYawMax *= controlled;

	float& recoilPitchMin = *(float*)(Current + 0x20);
	float	defaultrecoilPitchMin = recoilPitchMin;
	recoilPitchMin *= controlled;

	float& recoilPitchMax = *(float*)(Current + 0x24);
	float	defaultrecoilPitchMax = recoilPitchMax;
	recoilPitchMax *= controlled;
	/*** RECOIL ***/
	/*** Spread ***/

	float SpreadControlled = Vars::Weapon::Spread * 0.01;

	float& aimCone = *(float*)(baseProjectile + O::BaseProjectile::aimCone);
	float	defaultaimCone = aimCone;
	aimCone *= SpreadControlled;

	float& hipAimCone = *(float*)(baseProjectile + O::BaseProjectile::hipAimCone);
	float	defaulthipAimCone = hipAimCone;
	hipAimCone *= SpreadControlled;

	float& aimConePenaltyMax = *(float*)(baseProjectile + O::BaseProjectile::aimConePenaltyMax);
	float	defaultaimConePenaltyMax = aimConePenaltyMax;
	aimConePenaltyMax *= SpreadControlled;

	float& aimconePenaltyPerShot = *(float*)(baseProjectile + O::BaseProjectile::aimconePenaltyPerShot);
	float	defaultaimconePenaltyPerShot = aimconePenaltyPerShot;
	aimconePenaltyPerShot *= SpreadControlled;

	float& stancePenaltyScale = *(float*)(baseProjectile + O::BaseProjectile::stancePenaltyScale);
	float	defaultstancePenaltyScale = stancePenaltyScale;
	stancePenaltyScale *= SpreadControlled;

	float& aimconeCurveScale = *(float*)(Current + 0x60);
	float	defaultaimconeCurveScale = aimconeCurveScale;
	aimconeCurveScale *= SpreadControlled;


	/*** Spread ***/
	auto& repeatDelay = *(float*)(baseProjectile + O::AttackEntity::repeatDelay);
	auto defaultrepeatDelay = repeatDelay;

	repeatDelay /= (100 + Vars::Weapon::FireRate) / 100.f;
	MyrepeatDelay = repeatDelay;
	Classes::DoAttack((DWORD64)baseProjectile);

	repeatDelay = defaultrepeatDelay;
	/*** RECOIL ***/
	recoilYawMin = defaultrecoilYawMin;
	recoilYawMax = defaultrecoilYawMax;
	recoilPitchMin = defaultrecoilPitchMin;
	recoilPitchMax = defaultrecoilPitchMax;
	/*** RECOIL ***/
	/*** Spread ***/
	aimCone = defaultaimCone;
	hipAimCone = defaulthipAimCone;
	aimConePenaltyMax = defaultaimConePenaltyMax;
	aimconePenaltyPerShot = defaultaimconePenaltyPerShot;
	stancePenaltyScale = defaultstancePenaltyScale;
	aimconeCurveScale = defaultstancePenaltyScale;
	/*** Spread ***/
	return;

	//return Classes::DoAttack((DWORD64)baseProjectile);
}
namespace DeathBarrier
{
	class Terrain {
	public:
		float SampleHeight(Vector3 schingschongmydickislong)
		{
			if (!this || schingschongmydickislong == Vector3::Zero()) return 0.0f;
			return reinterpret_cast<float(*)(Terrain*, Vector3)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Terrain"), _("SampleHeight"), 1, _("worldPosition"), _("UnityEngine"), 1)))(this, schingschongmydickislong);
		}
	};

	class TerrainCollision {
	public:
		bool GetIgnore(Vector3 yourmomsahoe, float flot)
		{
			if (!this || yourmomsahoe == Vector3::Zero() || !flot) return false;
			//auto GetIgnore = reinterpret_cast<Vector3(*)(DWORD64)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("TerrainMeta"), _("get_Position"), 0, _(""), _(""))));
			return reinterpret_cast<bool(*)(TerrainCollision*, Vector3, float)>(g_Base + offsets::o_GetIgnore)(this, yourmomsahoe, flot);
		}
	};

	class TerrainHeightMap {
	public:
		Vector3 GetNormal(Vector3 worldPos)
		{
			if (!this || worldPos == Vector3::Zero()) return Vector3::Zero();
			return reinterpret_cast<Vector3(*)(TerrainHeightMap*, Vector3)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("TerrainHeightMap"), _("GetNormal"), 0, _(""), _(""))))(this, worldPos);
		}
		float GetHeight(Vector3 idk)
		{
			if (!this || idk == Vector3::Zero()) return 0.0f;
			return reinterpret_cast<float(*)(TerrainHeightMap*, Vector3)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("TerrainHeightMap"), _("GetHeight"), 0, _(""), _(""))))(this, idk);
		}
	};

	class TerrainMeta {
	public:
		static TerrainMeta* New()
		{
			static DWORD64 klazz = 0;
			if (!klazz)
				klazz = Il2cpp::InitClass(_("TerrainMeta"), _(""));
			DWORD64 static_fields = Read<DWORD64>(klazz + 0xB8);
			return *reinterpret_cast<TerrainMeta**>(static_fields + 0x8);
		}

		Vector3 Position()
		{
			if (!this) return Vector3::Zero();
			auto get_pos = reinterpret_cast<Vector3(*)(DWORD64)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("TerrainMeta"), _("get_Position"), 0, _(""), _(""))));
			return get_pos((DWORD64)this);
		}

		TerrainHeightMap* HeightMap()
		{
			if (!this) return nullptr;
			auto get_HeightMap = reinterpret_cast<TerrainHeightMap * (*)(DWORD64)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("TerrainMeta"), _("get_HeightMap"), 0, _(""), _(""))));
			return get_HeightMap((DWORD64)this);
		}

		Terrain* terrain()
		{
			if (!this) return nullptr;
			auto get_Terrain = reinterpret_cast<Terrain * (*)(DWORD64)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("TerrainMeta"), _("get_Terrain"), 0, _(""), _(""))));
			return get_Terrain((DWORD64)this);
		}

		TerrainCollision* Collision()
		{
			if (!this) return nullptr;
			auto get_Collision = reinterpret_cast<TerrainCollision * (*)(DWORD64)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("TerrainMeta"), _("get_Collision"), 0, _(""), _(""))));
			return get_Collision((DWORD64)this);
		}
	};

	bool TestInsideTerrain(Vector3 pos)
	{
		auto Meta = TerrainMeta::New();
		if (!Meta) return false;
		if (!Meta->HeightMap()) return false;
		if (!Meta->terrain()) return false;
		if (!Meta->Collision()) return false;

		float height = Meta->HeightMap()->GetHeight(pos);

		if (pos.y > height - 0.3f)
			return false;

		float gaysex = Meta->Position().y + Meta->terrain()->SampleHeight(pos);
		return pos.y <= gaysex - 0.3f && !Meta->Collision()->GetIgnore(pos, 0.01f);
	}

	bool IsInsideTerrain(bool prevent = false)
	{
		BasePlayer* player = LocalPlayer;
		bool result = TestInsideTerrain(player->get_transform()->Position());
		if (prevent && result)
			Classes::ForcePositionTo(LocalPlayer, player->lastSentTick()->position());
		return result;
	}
};

float PowerShotTime = 8;
float nextActionTime = 0, period = 1.4721;

void WeaponFix()
{
	BaseProjectile* weapon = ActiveWeapon;

	auto DoHeal = [&](BaseProjectile* held) {
		auto time = Unity::RealtimeSinceStartup();
		if (held->GetID() == 1079279582)
		{
			if (held->HeldEntity()->timeSinceDeploy() > held->HeldEntity()->DeployDelay() && held->HeldEntity()->NextAttackTime() <= time) {
				if (time > nextActionTime) {
					nextActionTime = time + period;
					Classes::ServerRPC((DWORD64)held->HeldEntity(), _(L"UseSelf"));
					// Classes::ServerRPC((DWORD64)held->HeldEntity(), _(L"D"));
				}
			}
		}
		else if (held->GetID() == -2072273936)
		{
			if (held->HeldEntity()->timeSinceDeploy() > held->HeldEntity()->DeployDelay() && held->HeldEntity()->NextAttackTime() <= time) {
				if (time > nextActionTime) {
					nextActionTime = time + (period * 2);
					Classes::ServerRPC((DWORD64)held->HeldEntity(), _(L"UseSelf"));
					// Classes::ServerRPC((DWORD64)held->HeldEntity(), _(L"D"));
				}
			}
		}
		};

	float time = Unity::get_fixedTime();
	if (weapon)
	{
		Weapon* held = HeldEntity;
		Weapon* HeldEntity = held;
		if (HeldEntity)
		{
			auto classname = HeldEntity->ClassName();
			// HeldEntity->changeHandsPosition();

			if (weapon->IsWeapon())
			{

				if (Vars::Weapon::fast_bullet)
				{

					unsigned int PrefabID = safe_read(HeldEntity + O::BaseNetworkable::prefabID, UINT64);





					if (PrefabID == 1877401463 || PrefabID == 554582418 || PrefabID == 1877401463 || PrefabID == 2176761593 || PrefabID == 2696589892 || PrefabID == 3474489095)
					{
						Vars::Weapon::Bullet__Speed = 1.20;

					}

					else if (PrefabID == 4279856314)
					{
						Vars::Weapon::Bullet__Speed = 1.18;

					}

					else if (PrefabID == 1978739833 || PrefabID == 844375121 || PrefabID == 4231282088)
					{
						Vars::Weapon::Bullet__Speed = 1.21;

					}
					else if (PrefabID == 2545523575 || PrefabID == 3243900999 || PrefabID == 563371667 || PrefabID == 2293870814 || PrefabID == 636374895 || PrefabID == 3305012504 || PrefabID == 2477536592) { //mp4a5, custom-smg
						Vars::Weapon::Bullet__Speed = 1.15;
					}
					else if (PrefabID == 3759841439)
					{
						Vars::Weapon::Bullet__Speed = 1.09;

					}
					else if (PrefabID == 3459133190) { //hmlmg
						Vars::Weapon::Bullet__Speed = 1.2f;
					}
					else if (PrefabID == 1440914039) {//m249
						Vars::Weapon::Bullet__Speed = 1.3f;
					}
					else if (PrefabID == 1517089664) { //m39 rifle
						Vars::Weapon::Bullet__Speed = 1.25f;
					}
					else if (PrefabID == 2620171289) {//l96
						Vars::Weapon::Bullet__Speed = 3.f;
					}
					else if (PrefabID == 1665481300) { //bolty
						Vars::Weapon::Bullet__Speed = 1.75f;
					}
					else if (PrefabID == 2727391082) { //crossbow
						Vars::Weapon::Bullet__Speed = 1.5f;
					}
					else if (PrefabID == 2836331625) { //bow
						Vars::Weapon::Bullet__Speed = 1.20f;
					}

					else {
						Vars::Weapon::Bullet__Speed = 1.0f;
					}

					HeldEntity->projectileVelocityScale() = Vars::Weapon::Bullet__Speed;


				}

				if (classname && !(m_strcmp(classname, _("BaseMelee"))) && !(m_strcmp(classname, _("Paddle"))) && !(m_strcmp(classname, _("Jackhammer"))))
				{
					canThrowAsProjectile = false;

					if (Vars::Weapon::SilentReload)
					{
						float IndicatorPos = 15;

						if (HeldEntity->primaryMagazine()->contents() < HeldEntity->primaryMagazine()->capacity()) // HeldEntity->primaryMagazine()->contents()
						{

							Vars::Misc::time_since_last_shot = (Unity::get_fixedTime() - Vars::Misc::fixed_time_last_shot);
							Vars::Misc::time_since_last_shot2 = Vars::Misc::time_since_last_shot;
							if (Vars::Misc::just_shot && (Vars::Misc::time_since_last_shot > 0.2f))
							{
								Classes::ServerRPC((DWORD64)HeldEntity, _(L"StartReload"));
								Vars::Misc::just_shot = false;
							}
							float reloadtime = HeldEntity->reloadTime();

							Vars::Misc::rl_time = reloadtime;

							if (Vars::Misc::time_since_last_shot > reloadtime
								&& !Vars::Misc::did_reload)
							{
								Classes::ServerRPC((DWORD64)HeldEntity, _(L"Reload"));
								Vars::Misc::did_reload = true;
								Vars::Misc::time_since_last_shot = 0;
							}

						}

					}
					else
					{
						Vars::Misc::time_since_last_shot2 = 0;
						Vars::Misc::fixed_time_last_shot = Unity::get_fixedTime();
						Vars::Misc::did_reload = false;
						Vars::Misc::just_shot = true;
					}





					if (Vars::Misc::FakeShoot && FakeShooting)
					{
						Classes::SendSignal((DWORD64)HeldEntity, BaseEntity::Signal::Attack, _(L""));
					}
					if (Vars::Aim::InstaKill || Vars::Exploits::AutoShoot && AutoShooting)
					{
						if (Target.Cur)
						{
							Vector3 TargetPos;
							if (Vars::Exploits::BehindWall && Vars::Exploits::BehindWallPos != Vector3(0, 0, 0) && !Target.Heli && !Target.Turret && Vars::Exploits::Manipulation && Manipulating)
								TargetPos = Vars::Exploits::BehindWallPos;
							else { TargetPos = Target.Pos; }


							if (Unity::CheckLOS(EyePos, TargetPos))
							{
								if (Vars::Aim::InstaKill)
								{
									auto ItemId = weapon->GetID();
									float next_rape = Vars::Exploits::AutoShootTimeSinceLastShot + 1;
									if (ItemId != -75944661 && ItemId != -1367281941 && ItemId != 1443579727 && ItemId != 795371088 && ItemId != -765183617)
									{
										HeldEntity->LaunchProjectile(Vars::Aim::InstaKill);
									}
								}


								if (Vars::Exploits::AutoShoot && AutoShooting)
								{
									if (Unity::CheckLOS(EyePos, TargetPos, 0))
									if (!Manipulation::TestNoClipping(EyePos, TargetPos, 0.03, true))
									{
										auto PrimMag = HeldEntity->primaryMagazine();
										if (PrimMag->contents() > 0)
										{
											if (weapon->GetID() == 1443579727 || weapon->GetID() == 1965232394 || weapon->GetID() == 884424049)
											{
												float NextShotBow = Vars::Exploits::AutoShootTimeSinceLastShot + HeldEntity->RepeatDelay() + 0.39;

												if (Unity::get_fixedTime() > NextShotBow)
												{
													if (HeldEntity->NextAttackTime() >= Unity::get_time())
														return;

													DWORD64 magazine = safe_read(HeldEntity + O::BaseProjectile::primaryMagazine, DWORD64);
													int contents = safe_read(magazine + 0x1C, int); //BaseProjectile.Magazine!
													//safe_write(HeldEntity + O::BowWeapon::attackReady, false, bool);
													typedef void(__stdcall* TryReload)(DWORD64);
													if (contents <= 0) {
														Classes::TryReload((DWORD64)HeldEntity);
														return;
													}

													auto viewModel = Read<DWORD64>((DWORD64)HeldEntity + 0x188);
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
													typedef void(__stdcall* StartKD)(DWORD64, float);

													Vars::Exploits::AutoShootTimeSinceLastShot = Unity::get_fixedTime();
													HeldEntity->LaunchProjectile();

													Classes::TryReload((DWORD64)HeldEntity);
													Classes::UpdateAmmoDisplay(HeldEntity);
													Classes::DidAttackClientside(HeldEntity);


												}
											}
											else if (weapon->GetID() == -75944661)
											{
												float NextShot = Vars::Exploits::AutoShootTimeSinceLastShot + HeldEntity->RepeatDelay() + 0.05;
												if (Unity::get_fixedTime() > NextShot)
												{
													if (HeldEntity->NextAttackTime() >= Unity::get_time())
														return;

													if (HeldEntity->TimeSinceDeploy() < HeldEntity->DeployDelay())
														return;

													DWORD64 magazine = safe_read(HeldEntity + O::BaseProjectile::primaryMagazine, DWORD64);
													int contents = safe_read(magazine + 0x1C, int); //BaseProjectile.Magazine!

													if (contents <= 0) {
														return;
													}

													auto viewModel = Read<DWORD64>((DWORD64)HeldEntity + 0x188);
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
													Vars::Exploits::AutoShootTimeSinceLastShot = Unity::get_fixedTime();
													//Classes::StartAttackCooldown(HeldEntity, kd + 0.02);

													HeldEntity->LaunchProjectile();

													Classes::TryReload((DWORD64)HeldEntity);
													Classes::UpdateAmmoDisplay(HeldEntity);
													Classes::DidAttackClientside(HeldEntity);



												}
											}
											else
											{
												float NextShot = Vars::Exploits::AutoShootTimeSinceLastShot + MyrepeatDelay + 0.001;
												if (Unity::get_fixedTime() > NextShot) // Unity::get_fixedTime() - Vars::Exploits::AutoShootTimeSinceLastShot >= HeldEntity->RepeatDelay()
												{
													if (HeldEntity->NextAttackTime() >= Unity::get_time())
														return;

													if (HeldEntity->TimeSinceDeploy() < HeldEntity->DeployDelay())
														return;

													DWORD64 magazine = safe_read(HeldEntity + O::BaseProjectile::primaryMagazine, DWORD64);
													int contents = safe_read(magazine + 0x1C, int); //BaseProjectile.Magazine!

													if (contents <= 0) {
														return;
													}

													auto viewModel = Read<DWORD64>((DWORD64)HeldEntity + 0x188);
													if (viewModel && !Vars::Exploits::AutoShootType[0])
													{
														Classes::Vm_Play(viewModel, _(L"attack"), 0);
													}
													if (!Vars::Exploits::AutoShootType[1])
													{
														Classes::SendSignal((DWORD64)HeldEntity, BaseEntity::Signal::Attack, _(L""));
													}

													safe_write(magazine + 0x1C, contents - 1, int);
													HeldEntity->LaunchProjectile();

													Classes::UpdateAmmoDisplay(HeldEntity);
													Classes::DidAttackClientside(HeldEntity);

													Vars::Exploits::AutoShootTimeSinceLastShot = Unity::get_fixedTime();

												}
											}

										}



									}
								}
								else
								{
									Classes::UpdateAmmoDisplay(HeldEntity);
								}
							}
						}
					}
					int WeaponID = weapon->GetID();
					if (WeaponID)
					{
						HeldEntity->WeaponAnimations();

						switch (WeaponID)
						{
						case -75944661:
							HeldEntity->InstaEoka();
							break;
						default:
							if (Vars::Weapon::NoBurst) // Automatic
								HeldEntity->RemoveBurst();
							if (Vars::Weapon::FullAuto) // Automatic
								HeldEntity->Automatic();
							if (Vars::Weapon::NoDeployDelay)
								HeldEntity->NoDeployDelay();
							break;
						}
					}


				}
			}

			bool isMelee = Read<bool>((DWORD64)HeldEntity + 0x2D1);
			if (classname && (m_strcmp(classname, _("BaseMelee")) || (m_strcmp(classname, _("Paddle"))) || (m_strcmp(classname, _("Jackhammer")))))
			{

				canThrowAsProjectile = true; // 326
				if (Vars::Exploits::AutoShoot && AutoShooting)
				{
					if (Target.Cur)
					{
						Vector3 TargetPos;
						if (Vars::Exploits::BehindWall && Vars::Exploits::BehindWallPos != Vector3(0, 0, 0) && !Target.Heli && !Target.Turret && Vars::Exploits::Manipulation && Manipulating)
							TargetPos = Vars::Exploits::BehindWallPos;
						else { TargetPos = Target.Pos; }
						if (Unity::CheckLOS(EyePos, TargetPos, 0.21) && TargetPos.Distance(EyePos) < 60.f)
						{
							if (Classes::HasAttackCooldown(HeldEntity))
								return;

							if (HeldEntity->NextAttackTime() >= Unity::get_time())
								return;

							if (HeldEntity->TimeSinceDeploy() < HeldEntity->DeployDelay())
								return;

							Classes::StartAttackCooldown(HeldEntity, HeldEntity->RepeatDelay());
							Classes::DoThrow((DWORD64)HeldEntity);
						}
					}
				}

				HeldEntity->MeleeHitDistance(Vars::Weapon::MeleeRadius);
				if (Vars::Aim::SilentMelee && Target.Cur)
				{
					auto ScanProcessAttack = [&](Vector3 start, Vector3 end) //a: this node | b: next node
						{
							Classes::DDrawSphere(start, 0.01, Color(0, 255, 255, 200), 0.01, false);
							if (ValidateProcessAttack((uintptr_t*)Target.Cur, end, HeldEntity, start, (!Target.Heli && !Target.Turret))) {
								return true;
							}
							return false;
						};
					Transform* PlayerTrans;
					if (Target.Heli) {
						PlayerTrans = Target.Cur->get_transform();
					}
					else if (Target.Turret) {
						PlayerTrans = Classes::get_transform(Target.Cur);
					}
					else {
						PlayerTrans = (Vars::Aim::AimCombo == 0 ? Target.Cur->GetTransform(47) : Target.Cur->GetTransform(22));
					}
					Vector3 targetPosition;
					if (PlayerTrans) {
						targetPosition = PlayerTrans->Position();

						Vector3 AttackStart = LocalPlayer->GetEyes()->EyePosition();
						float y_step = 2.f / 5;
						float step = 1.57079632679489661923f / 12;
						float x, z, current = 0;
						if (ScanProcessAttack(AttackStart, targetPosition))
						{
							AttackMelee(Target.Cur, targetPosition, HeldEntity, AttackStart, (!Target.Heli && !Target.Turret));
						}
						if (Vars::Exploits::stw) {
							for (float y = 1; y > -1; y -= y_step) {
								for (size_t val = 0; val < 48; val++)
								{
									x = Maths::m_Sin(current) * 2;
									z = Maths::m_Cos(current) * 2;
									Vector3 TestStart = Vector3(AttackStart.x + x, AttackStart.y + y, AttackStart.z + z);
									if (ScanProcessAttack(TestStart, targetPosition))
									{
										AttackMelee(Target.Cur, targetPosition, HeldEntity, TestStart, (!Target.Heli && !Target.Turret));
									}
									current += step;
								}
							}
						}
					}

					/*if (Target.Cur)
					{
						if (Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(spine4), Target.Pos) <= Vars::Weapon::MeleeRadius)
						{
							AttackMelee(Target.Cur, Target.Pos, HeldEntity, true);
						}
					}*/
				}
				if (Vars::Misc::SilentFarmOre)
				{
					AimResult closest = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("OreHotSpot"));
					if (closest.valid)
					{
						// Circle3D(closest.pos, { 205.f, 100.f, 205.f, 255.f }, Vars::Weapon::MeleeRadius);
						if (Maths::Calc3D_Dist(LocalPlayer->GetBoneByID(spine4), closest.pos) <= Vars::Weapon::MeleeRadius)
						{
							AttackMelee(closest.entity, closest.pos, HeldEntity);
						}
					}
				}
				if (Vars::Misc::SilentFarmTree)
				{
					AimResult TreeEntity = AimResult::get_closest_object(LocalPlayer->GetEyes()->EyePosition(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("TreeEntity"));
					if (TreeEntity.valid)
					{
						 Circle3D(TreeEntity.pos, { 205.f, 100.f, 205.f, 255.f }, Vars::Weapon::MeleeRadius);
						AimResult TreeMarker = AimResult::get_closest_object(LocalPlayer->GetEyes()->EyePosition(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("TreeMarker"));
						if (TreeMarker.valid && Maths::Calc3D_Dist(LocalPlayer->GetEyes()->EyePosition(), TreeMarker.pos) < Vars::Weapon::MeleeRadius)
						{
							TreeEntity.pos = TreeMarker.pos;
							AttackMelee(TreeEntity.entity, TreeEntity.pos, HeldEntity, LocalPlayer->GetEyes()->EyePosition(), false);
						}
						else if (Maths::Calc3D_Dist(LocalPlayer->GetEyes()->EyePosition(), TreeEntity.pos) < Vars::Weapon::MeleeRadius) {
							AttackMelee(TreeEntity.entity, Vector3(TreeEntity.pos.x, TreeEntity.pos.y + 0.25, TreeEntity.pos.z), HeldEntity, LocalPlayer->GetEyes()->EyePosition(), false);
						}
					}
				}
				if (Vars::Misc::AutoFarmOres == 5 && Vars::Misc::WalkTo) {
					AimResult ent = AimResult::GetBarrel();
					Vars::Misc::AutoPickupLoot = true;
					if (ent.valid) {
						Circle3D(ent.pos, { 205.f, 100.f, 205.f, 255.f }, Vars::Weapon::MeleeRadius);
						if (Maths::Calc3D_Dist(LocalPlayer->GetEyes()->EyePosition(), ent.pos) < (Vars::Weapon::MeleeRadius + 0.2))
						{
							AttackMelee(ent.entity, Vector3::MoveTowards(Vector3(ent.pos.x, ent.pos.y + 0.5, ent.pos.z), LocalPlayer->GetEyes()->EyePosition(), 0.1), HeldEntity, LocalPlayer->GetEyes()->EyePosition(), false);
						}
					}
				}
			}
			if (Vars::Misc::autoHeal && LocalPlayer->GetHealth() <= 95) DoHeal(weapon);
		}
		else
		{

			Vars::Misc::fixed_time_last_shot = Unity::get_fixedTime();
			Vars::Misc::time_since_last_shot2 = 0;
			Vars::Misc::did_reload = false;
			Vars::Misc::just_shot = true;
		}

	}
	else
	{

		Vars::Misc::fixed_time_last_shot = Unity::get_fixedTime();
		Vars::Misc::time_since_last_shot2 = 0;
		Vars::Misc::did_reload = false;
		Vars::Misc::just_shot = true;
	}



}

Vector3 cLastTickPos{};

enum EnvironmentType
{
	Underground = 1,
	Building = 2,
	Outdoor = 4,
	Elevator = 8,
	PlayerConstruction = 16,
	TrainTunnels = 32,
	UnderwaterLab = 64,
	Submarine = 128,
	BuildingDark = 256,
	BuildingVeryDark = 512
};

class EnvironmentManager {
public:
	static EnvironmentType Get(Vector3 pos)
	{
		return reinterpret_cast<EnvironmentType(*)(Vector3)>(g_Base + offsets::o_EnvironmentTypeGet)(pos);
	}
};

bool inAir(BasePlayer* ply, Vector3 oldPos, Vector3 newPos)
{
	bool isFlying = false;
	float num = 2.0f;

	float radius = Classes::_GetRadius(ply);
	float height = Classes::GetHeight(ply);
	Vector3 vector = (oldPos + newPos) * 0.5f;

	if (!Classes::HasParent(ply) && !Classes::WaterLevelTest(vector - Vector3(0.0f, num, 0.0f), true, ply) && (EnvironmentManager::Get(vector) & EnvironmentType::Elevator) == (EnvironmentType)0)
	{
		Vector3 vector2 = vector + Vector3(0.0f, radius - num, 0.0f);
		// Classes::DDrawSphereGizmo(vector2, 0.2, { 0,255,0,255 }, 0.2, false, false);
		Vector3 vector3 = vector + Vector3(0.0f, height - radius, 0.0f);
		// Classes::DDrawSphereGizmo(vector3, 0.2, { 0,255,0,255 }, 0.2, false, false);
		float radius2 = radius - 0.05f;
		isFlying = !Unity::CheckCapsule(vector2, vector3, radius2, 1503731969, QueryTriggerInteraction::Ignore);
	}

	return isFlying;
}

bool OnWater()
{
	if (!LocalPlayer) return false;
	Vector3 current = LocalPlayer->get_transform()->Position();
	Vector3 old = LocalPlayer->lastSentTick()->position();

	float num = 2.0f;
	Vector3 vector = (old + current) * 0.5f;
	return Classes::WaterLevelTest(vector - Vector3(0.0f, 0.5, 0.0f), true, LocalPlayer);
}

float HFlyhack = 0;
float VFlyhack = 0;
float VMaxFlyhack = 0;
float HMaxFlyhack = 0;

//public static bool TestFlying(global::BasePlayer ply, Vector3 oldPos, Vector3 newPos, bool verifyGrounded)
//{
//	ply.isInAir = false;
//	ply.isOnPlayer = false;
//	if (verifyGrounded)
//	{
//		float flyhack_extrusion = AntiHack::flyhack_extrusion;
//		Vector3 vector = (oldPos + newPos) * 0.5f;
//		if (!ply.OnLadder() && !global::WaterLevel.Test(vector - new Vector3(0f, flyhack_extrusion, 0f), true, true, ply) && (global::EnvironmentManager.Get(vector) & global::EnvironmentType.Elevator) == (global::EnvironmentType)0)
//		{
//			float flyhack_margin = AntiHack::flyhack_margin;
//			float radius = ply.GetRadius();
//			float height = ply.GetHeight(false);
//			Vector3 vector2 = vector + new Vector3(0f, radius - flyhack_extrusion, 0f);
//			Vector3 vector3 = vector + new Vector3(0f, height - radius, 0f);
//			float num = radius - flyhack_margin;
//			ply.isInAir = !UnityEngine.Physics.CheckCapsule(vector2, vector3, num, 1503731969, 1);
//			if (ply.isInAir)
//			{
//				int num2 = UnityEngine.Physics.OverlapCapsuleNonAlloc(vector2, vector3, num, global::AntiHack.buffer, 131072, 1);
//				for (int i = 0; i < num2; i++)
//				{
//					global::BasePlayer basePlayer = global::AntiHack.buffer[i].gameObject.ToBaseEntity() as global::BasePlayer;
//					if (!(basePlayer == null) && !(basePlayer == ply) && !basePlayer.isInAir && !basePlayer.isOnPlayer && !basePlayer.TriggeredAntiHack(1f, float.PositiveInfinity) && !basePlayer.IsSleeping())
//					{
//						ply.isOnPlayer = true;
//						ply.isInAir = false;
//						break;
//					}
//				}
//				for (int j = 0; j < global::AntiHack.buffer.Length; j++)
//				{
//					global::AntiHack.buffer[j] = null;
//				}
//			}
//		}
//	}
//	else
//	{
//		ply.isInAir = (!ply.OnLadder() && !ply.IsSwimming() && !ply.IsOnGround());
//	}
//	if (ply.isInAir)
//	{
//		bool flag = false;
//		Vector3 vector4 = newPos - oldPos;
//		float num3 = Mathf.Abs(vector4.y);
//		float num4 = Vector3Ex.Magnitude2D(vector4);
//		if (vector4.y >= 0f)
//		{
//			ply.flyhackDistanceVertical += vector4.y;
//			flag = true;
//		}
//		if (num3 < num4)
//		{
//			ply.flyhackDistanceHorizontal += num4;
//			flag = true;
//		}
//		if (flag)
//		{
//			float num5 = Mathf.Max((ply.flyhackPauseTime > 0f) ? AntiHack::flyhack_forgiveness_vertical_inertia : AntiHack::flyhack_forgiveness_vertical, 0f);
//			float num6 = ply.GetJumpHeight() + num5;
//			if (ply.flyhackDistanceVertical > num6)
//			{
//				return true;
//			}
//			float num7 = Mathf.Max((ply.flyhackPauseTime > 0f) ? AntiHack::flyhack_forgiveness_horizontal_inertia : AntiHack::flyhack_forgiveness_horizontal, 0f);
//			float num8 = 5f + num7;
//			if (ply.flyhackDistanceHorizontal > num8)
//			{
//				return true;
//			}
//		}
//	}
//	else
//	{
//		ply.flyhackDistanceVertical = 0f;
//		ply.flyhackDistanceHorizontal = 0f;
//	}
//	return false;
//}


bool TestFlying(BasePlayer* ply, Vector3 oldPos, Vector3 newPos)
{
	isInAir = inAir(ply, oldPos, newPos);
	Vector3 vector = (oldPos + newPos) * 0.5f;
	flyhackPauseTime = max(0.f, flyhackPauseTime - Unity::get_deltaTime());
	if (isInAir)
	{
		if (!ply->IsSleeping() && !ply->GetModelState()->HasFlag(ModelState_Flag::OnLadder) && !ply->GetModelState()->HasFlag(ModelState_Flag::Mounted))
		{
			bool flag = false;
			Vector3 vector4 = newPos - oldPos;
			float num2 = Maths::m_Abs(vector4.y);
			float num3 = vector4.Magnitude2D();
			if (vector4.y >= 0.0f)
			{
				flyhackDistanceVertical += vector4.y;
				flag = true;
			}
			if (num2 < num3)
			{
				flyhackDistanceHorizontal += num3;
				flag = true;
			}
			if (flag)
			{
				float num4 = max((flyhackPauseTime > 0.0f) ? AntiHack::flyhack_forgiveness_horizontal_inertia : AntiHack::flyhack_forgiveness_horizontal, 0.0f);
				float num5 = (Classes::_getjumpheight(ply) + num4) * 2.6;
				Vars::Misc::MaxVerticalFly = num5;
				if (flyhackDistanceVertical >= num5)
				{
					return true;
				}
				float num6 = max((flyhackPauseTime > 0.f) ? AntiHack::flyhack_forgiveness_horizontal_inertia : AntiHack::flyhack_forgiveness_horizontal, 0.f);
				float num7 = (5.0f + num6) * 2.6;
				Vars::Misc::MaxHorizontalFly = num7;
				if (flyhackDistanceHorizontal >= num7)
				{
					return true;
				}
			}
		}
		else {
			flyhackDistanceVertical = 0.0f;
			flyhackDistanceHorizontal = 0.0f;
		}
	}
	else {
		flyhackDistanceVertical = 0.0f;
		flyhackDistanceHorizontal = 0.0f;
	}

	Vars::Misc::HorizontalFly = flyhackDistanceHorizontal;
	Vars::Misc::VerticalFly = flyhackDistanceVertical;
	return false;
}

bool IsFlying(bool PreventFlyhack, PlayerWalkMovement* Movment)
{
	static float oldx;
	static float oldy;
	static float oldz;

	BasePlayer* ply = LocalPlayer;

	Vector3 current = ply->get_transform()->Position();
	Vector3 old = ply->lastSentTick()->position();
	/*static float delayTime;
	if (Unity::get_time() > LocalPlayer->lastSentTickTime()) {
		oldx = current.x; oldy = current.y; oldz = current.z;
		delayTime = Unity::get_time();
	}
	Vector3 old = Vector3(oldx, oldy, oldz);*/
	Vector3 overrided = current;
	Classes::DDrawSphere(old, 0.2, Color(1, 1, 1, 0.9), 0.2, false);
	bool result = TestFlying(ply, old, current);

	if (flyhackDistanceVertical >= (Vars::Misc::MaxVerticalFly - 0.01f)) {
		overrided = Vector3(overrided.x, old.y, overrided.z);
		if (result && PreventFlyhack && !(Vars::Misc::InteractiveDebug && Debugging)) {
			if (overrided != current && current.y - overrided.y > 0.001)
				Classes::ForcePositionTo(LocalPlayer, overrided);
		}
	}
	if (flyhackDistanceHorizontal >= (Vars::Misc::MaxHorizontalFly - 0.01f)) {
		overrided = Vector3(old.x, overrided.y, old.z);
		if (result && PreventFlyhack && !(Vars::Misc::InteractiveDebug && Debugging)) {
			if (overrided != current && overrided.DistanceXZ(current) > 0.001)
				Classes::ForcePositionTo(LocalPlayer, overrided);
		}
	}

	return result;
}

bool testSpeedHack() {
	return true;
}

float JumpTime = 0.0;
namespace AI
{
	namespace pathfinding {
		bool clearPath = false;
		int pathPosition = 0;
		int velPathPos = 0;
		Vector3* rayNode = nullptr;
		Vector3* pathNode = nullptr;

		namespace cll {
			void ClearNodes(Vector3* t) {
				for (int i = 0; i < ARRAYSIZE(t); i++) {
					t[i] = Vector3::Zero();
				}
				t = nullptr;
			}
			void ClearPath(Vector3* t) {
				for (int i = 0; i < ARRAYSIZE(t); i++) {
					t[i] = Vector3::Zero();
				}
				t = nullptr;
			}
		};

		bool CreateTerrainList(Ray initialPosition, float maxDistance)
		{
			auto Meta = DeathBarrier::TerrainMeta::New();
			if (!Meta) return false;
			if (!Meta->HeightMap()) return false;
			if (!Meta->terrain()) return false;
			cll::ClearNodes(rayNode);
			Vector3 currentPosition = initialPosition.origin;
			float stepSize = 1;
			int steps = Maths::XFloor_f__((maxDistance + 1) / stepSize);
			if (steps > 0) {
				for (int listPos = 0; listPos < steps; listPos++)
				{
					float height = Meta->HeightMap()->GetHeight(currentPosition);
					static int sz = ARRAYSIZE(rayNode);
					push_back(rayNode, sz, Vector3(currentPosition.x, height, currentPosition.z));
					currentPosition += initialPosition.dir * stepSize;

					if (Vector3(currentPosition.x, 0, currentPosition.z).Distance(Vector3(initialPosition.origin.x, 0, initialPosition.origin.z)) > maxDistance)
						break;
				}
			}

			return true;
		}

		bool CreateTerrainPath(Vector3 initialPosition, Vector3 endPosition)
		{
			auto ValidateNode = [&](Vector3 a, Vector3 b) //a: this node | b: next node
				{

					if (b.y - a.y > 0.31) return false;
					if (!(Maths::Calc2D_Dist(Vector2(a.x, a.z), Vector2(endPosition.x, endPosition.z)) > Maths::Calc2D_Dist(Vector2(b.x, b.z), Vector2(endPosition.x, endPosition.z)))) return false;
					if (Classes::WaterLevelTest(b, true, LocalPlayer)) return false;
					if (Manipulation::TestNoClipping(a, a, 0.31, true)) return false;

					return true;
				};
			pathNode[0] = initialPosition;
			int sectors = 8;
			float step = ((1.57079632679489661923)) / (sectors - 1);
			float x, z, current = 0;
			float dist = Maths::Calc2D_Dist(Vector2(initialPosition.x, initialPosition.z), Vector2(endPosition.x, endPosition.z));
			for (size_t val = 0; val < sectors; val++)
			{
				cll::ClearPath(pathNode);
				x = Maths::m_Sin(current) * dist;
				z = Maths::m_Cos(current) * dist;

				Ray gaysex = Ray(initialPosition, Vector3(x, initialPosition.y, z));

				if (initialPosition.Distance(endPosition) < Vector3(initialPosition.x + x, initialPosition.y, initialPosition.z + z).Distance(endPosition)) continue;

				if (CreateTerrainList(gaysex, 1)) {
					if (ValidateNode(rayNode[0], rayNode[1])) {
						static int sz = ARRAYSIZE(pathNode);
						push_back(pathNode, sz, rayNode[1]);
						return true;
					}
				}

				current += step;
			}
			pathPosition = 0;
		}

		bool VisualizeTerrain(Vector3 initialPosition)
		{
			int sectors = 8;
			float step = ((1.57079632679489661923)) / (sectors - 1);
			float x, z, current = 0;
			for (size_t val = 0; val < sectors; val++)
			{
				x = Maths::m_Sin(current) * 100;
				z = Maths::m_Cos(current) * 100;

				Ray gaysex = Ray(initialPosition, Vector3(initialPosition.x + x, initialPosition.y, initialPosition.z + z));

				if (CreateTerrainList(gaysex, 10)) {
					for (int i = 1; i < 10; i++) {
						Classes::DDrawSphere(rayNode[i], 0.5, Color(0, 255, 255, 200), 0.5, false);
					}
				}

				current += step;
			}

			return true;
		}
	};

	Vector3 last_bear_pos = Vector3();
	Vector3 last_pear_pos = Vector3();
	Vector3 last_wolf_pos = Vector3();
	Vector3 last_boar_pos = Vector3();
	Vector3 last_wall_pos = Vector3();

	int ticks_with_boost = 0;
	bool boosting = false;
	float boostUpdate() {
		if (ticks_with_boost > 100) {
			ticks_with_boost = 0;
			boosting != boosting;
		}
		else ticks_with_boost++;

		if (boosting) return 6.25f;
		else return 5.5f;
	}
	void AutoWalkTo(PlayerWalkMovement* BaseMovement, ModelState* MState)
	{
		//float speed = Vars::Misc::AutoBotJumpHeight;
		AimResult tur = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("autoturret_deployed.prefab"));
		AimResult mine = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("landmine.prefab"));
		AimResult brtr = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("beartrap.prefab"));
		AimResult stonewall = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("wall.external.high.stone.prefab"));
		AimResult woodwall = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("wall.external.high.wood.prefab"));
		AimResult stonegate = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("gates.external.high.stone.prefab"));
		AimResult woodgate = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("gates.external.high.wood.prefab"));
		AimResult wolf = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("wolf.prefab"));
		AimResult bear = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("bear.prefab"));
		AimResult pbear = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("polarbear.prefab"));
		AimResult boar = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("boar.prefab"));
		AimResult apc = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("bradleyapc.prefab"));


		AimResult woodwirebarricade = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("barricade.woodwire.prefab"));
		AimResult woodbarricade = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("barricade.wood.prefab"));
		AimResult metalbarricade = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("barricade.metal.prefab"));
		AimResult floorspike = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _("spikes.floor.prefab"));
		bool targetIsEntity = true;
		AimResult closest;
		if (Vars::Misc::WalkTo) {
			if (Vars::Misc::AutoFarmOres == 1) {
				closest = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("stone-ore.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
				Vars::Weapon::MeleeRadius = 3.5;
				Vars::Misc::AutoPickupLoot = false;
			}
			if (Vars::Misc::AutoFarmOres == 2) {
				closest = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("metal-ore.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
				Vars::Weapon::MeleeRadius = 3.5;
				Vars::Misc::AutoPickupLoot = false;
			}
			if (Vars::Misc::AutoFarmOres == 3) {
				closest = AimResult::SafeObjectToWalk(LocalPlayer->GetTransform(47)->Position(), _("sulfur-ore.prefab"), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), tur, stonewall, woodwall, mine, brtr);
				Vars::Weapon::MeleeRadius = 3.5;
				Vars::Misc::AutoPickupLoot = false;
			}
			if (Vars::Misc::AutoFarmOres == 4) {
				closest = AimResult::get_closest_object(LocalPlayer->GetTransform(47)->Position(), _(""), Vector3::Zero(), Vector3::Zero(), Vector3::Zero(), true, _("TreeEntity"));
				Vars::Weapon::MeleeRadius = 3.5;
				Vars::Misc::AutoPickupLoot = false;
			}
			if (Vars::Misc::AutoFarmOres == 5) {
				closest = AimResult::GetBarrel();
				Vars::Weapon::MeleeRadius = 2.75;
				Vars::Misc::AutoPickupLoot = true;
			}
			if (Vars::Misc::AutoFarmOres == 6) {
				closest = AimResult();
				//closest.valid = false;
				targetIsEntity = false;
				Vars::Misc::AutoPickupLoot = false;
			}
		}

		if (closest.valid && targetIsEntity) TargetOrePos = closest.pos;
		//else if (!targetIsEntity && !SavedPos.Empty()) TargetOrePos = SavedPos;
		else TargetOrePos = Vector3::Zero();

		Vector3 target_pos = TargetOrePos;
		//Vars::Misc::AutoBotJumpHeight = boostUpdate();

		bool goin_around = false;
		bool needs_up = false;
		bool needs_los = false;
		bool needs_back = false;
		bool FORCE_UP = false;
		bool go_overthething = false;
		bool go_long = false;

		if (!target_pos.Empty() && BaseMovement && MState)
		{
			auto eyepos = LocalPlayer->GetEyes()->GetCenter();
			Vector3 vel = safe_read(BaseMovement + 0x34, Vector3);
			Vector3 dir = (Vector3(target_pos.x, eyepos.y, target_pos.z) - eyepos).Normalized();
			float len = vel.Length();

			if (Vars::Misc::AutoBotMode == 0)
			{
				CanBhopJump = false;
				if (tur.valid && tur.dist < 31 && !goin_around) {
					Vector3 turdir = (tur.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
				}
				if (apc.valid && apc.dist < 101 && !goin_around) {
					Vector3 apcdir = (apc.pos - eyepos).Normalized();
					dir = dir - (dir + dir);
					dir -= apcdir;
					goin_around = true;
				}
				else if (apc.valid && apc.dist < 106 && !goin_around) {
					Vector3 apcdir = (apc.pos - eyepos).Normalized();
					dir -= apcdir;
					goin_around = true;
				}
				if (mine.valid && mine.dist < 3 && !goin_around) {
					Vector3 turdir = (mine.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
				}
				if (brtr.valid && brtr.dist < 3 && !goin_around) {
					Vector3 turdir = (brtr.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
				}
				if (stonewall.valid && stonewall.dist < 7 && !goin_around) {
					Vector3 turdir = (stonewall.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
					last_wall_pos = stonewall.pos;
				}
				if (woodwall.valid && woodwall.dist < 7 && !goin_around) {
					Vector3 turdir = (woodwall.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
					last_wall_pos = woodwall.pos;
				}
				if (woodgate.valid && woodgate.dist < 7 && !goin_around) {
					Vector3 turdir = (woodgate.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
					last_wall_pos = woodgate.pos;
				}
				if (stonegate.valid && stonegate.dist < 7 && !goin_around) {
					Vector3 turdir = (stonegate.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
					last_wall_pos = stonegate.pos;
				}
				if (last_wall_pos.Distance(stonewall.pos) < 10 || last_wall_pos.Distance(woodwall.pos) < 10 || last_wall_pos.Distance(stonegate.pos) < 10 || last_wall_pos.Distance(woodgate.pos) < 10) {
					//go_long = true;
				}
				if (wolf.valid && wolf.dist < 10) {
					if (!last_wolf_pos.Empty() && last_wolf_pos != wolf.pos)
						FORCE_UP = true;
					last_wolf_pos = wolf.pos;
				}
				if (bear.valid && bear.dist < 10) {
					if (!last_bear_pos.Empty() && last_bear_pos != bear.pos)
						FORCE_UP = true;
					last_bear_pos = bear.pos;
				}
				if (pbear.valid && pbear.dist < 10) {
					if (!last_pear_pos.Empty() && last_pear_pos != pbear.pos)
						FORCE_UP = true;
					last_pear_pos = pbear.pos;
				}
				if (boar.valid && boar.dist < 10) {
					if (!last_boar_pos.Empty() && last_boar_pos != boar.pos)
						FORCE_UP = true;
					last_boar_pos = boar.pos;
				}
				if (metalbarricade.valid && metalbarricade.dist < 4 && !goin_around) {
					Vector3 turdir = (metalbarricade.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
				}
				if (woodbarricade.valid && woodbarricade.dist < 4 && !goin_around) {
					Vector3 turdir = (woodbarricade.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
				}
				if (woodwirebarricade.valid && woodwirebarricade.dist < 4 && !goin_around) {
					Vector3 turdir = (woodwirebarricade.pos - eyepos).Normalized();
					dir -= turdir;
					goin_around = true;
				}
				if (floorspike.valid && floorspike.dist < 4) {
					go_overthething = true;
				}
				vel = { (dir.x * Vars::Misc::AutoBotJumpHeight), vel.y, (dir.z * Vars::Misc::AutoBotJumpHeight) };
				Vars::Misc::WalkToDir = dir;
				if (!go_long) {
					needs_up = Manipulation::TestNoClipping(eyepos, eyepos + (dir * 0.3), 0.41, true);

					if (needs_up && !goin_around) {
						vel.x *= 0.33;
						vel.y += 10;
						vel.z *= 0.33;
					}

					needs_los = Manipulation::TestNoClipping(eyepos, eyepos + (dir * 3), 0.41, true);

					if (needs_los && !needs_up) {
						vel.x = dir.x * Vars::Misc::AutoBotJumpHeight;
						vel.y = dir.y;
						vel.z = dir.z * Vars::Misc::AutoBotJumpHeight;
					}

					needs_back = Manipulation::TestNoClipping(eyepos, { eyepos.x, eyepos.y + 1, eyepos.z }, Manipulation::NoClipRadius(0.21), true);

					if (needs_back) {
						vel.x = -dir.x * 4;
						vel.y += 2;
						vel.z = -dir.z * 4;
					}

					if (!needs_back && go_overthething) {
						vel.y += 3.125;
					}

					if (LocalPlayer->GetVelocity().Length() <= 0.05f && eyepos.Distance(target_pos) > max(Vars::Weapon::MeleeRadius, 0)) {
						FORCE_UP = true;
					}

					if (eyepos.Distance(target_pos) < max(Vars::Weapon::MeleeRadius - 1.5f, 0) && !FORCE_UP) {
						vel = safe_read(BaseMovement + 0x34, Vector3);
					}

					if (Maths::m_Abs(eyepos.x - target_pos.x) < max(Vars::Weapon::MeleeRadius - 1.5f, 0) && Maths::m_Abs(eyepos.z - target_pos.z) < max(Vars::Weapon::MeleeRadius - 1.5f, 0) && !FORCE_UP) {
						vel.y = safe_read(BaseMovement + 0x34, Vector3).y;
					}
				}
				if (Vars::Misc::VerticalFly + 0.4 < Vars::Misc::MaxVerticalFly && Vars::Misc::HorizontalFly + 0.4 < Vars::Misc::MaxHorizontalFly)
					safe_write(BaseMovement + 0x34, ((FORCE_UP && !needs_back) ? Vector3(0, 90, 0) : vel), Vector3);
			}
			else if (Vars::Misc::AutoBotMode == 1)
			{
				if (pathfinding::VisualizeTerrain(LocalPlayer->GetPlayerModel()->ModelPosition())) {
					vel = pathfinding::pathNode[pathfinding::velPathPos] - pathfinding::pathNode[pathfinding::velPathPos - 1];
					safe_write(BaseMovement + 0x34, vel, Vector3);
				}
				//safe_write(BaseMovement + 0x34, vel, Vector3);
			}
			else
				CanBhopJump = false;
		}
	}
};






float speedhackPauseTime = 0.f;
float speedhack_slopespeed = 10.f;
float speedhack_forgiveness_inertia = 10.f;
float speedhack_forgiveness = 2.f;
float speedhackDistance = 0.f;

//bool IsSpeeding(BasePlayer* ply, TickInterpolator* ticks, float deltaTime)
//{
//	auto Clamp = [&](float value, float min, float max)
//	{
//		bool flag = value < min;
//		if (flag)
//		{
//			value = min;
//		}
//		else
//		{
//			bool flag2 = value > max;
//			if (flag2)
//			{
//				value = max;
//			}
//		}
//		return value;
//	};
//	auto Clamp01 = [&](float value)
//	{
//		bool flag = value < 0.f;
//		float result;
//		if (flag)
//		{
//			result = 0.f;
//		}
//		else
//		{
//			bool flag2 = value > 1.f;
//			if (flag2)
//			{
//				result = 1.f;
//			}
//			else
//			{
//				result = value;
//			}
//		}
//		return result;
//	};
//	auto Lerp = [&](float a, float b, float t)
//	{
//		return a + (b - a) * Clamp01(t);
//	};
//	//  clothingBlocksAiming	    bool	0x760
//	//	clothingMoveSpeedReduction	float	0x764
//	//	clothingWaterSpeedBonus	    float	0x768
//	//	clothingAccuracyBonus	    float	0x76c
//	auto GetSpeed = [&](float running, float ducking, float crawling)
//	{
//		float num = 1.f;
//		num -= safe_read((DWORD64)ply + 0x764, float);
//		if (Classes::WaterLevelTest(Vector3(0.0f, ply->GetEyes()->GetCenter().y, 0.0f), true, ply))
//		{
//			num += safe_read((DWORD64)ply + 0x768, float);
//		}
//		if (crawling > 0.f)
//		{
//			return Lerp(2.8f, 0.72f, crawling) * num;
//		}
//		return Lerp(Lerp(2.8f, 5.5f, running), 1.7f, ducking) * num;
//	};
//	bool result;
//	speedhackPauseTime = max(0.f, speedhackPauseTime - deltaTime);
//	if (!ply)
//	{
//		result = false;
//	}
//	else
//	{
//		bool flag = ply->get_transform()->get_parent() == nullptr;
//		auto localToWorldMatrix = reinterpret_cast<Matrix4x4(*)(Transform*)>(*reinterpret_cast<uintptr_t*>(Il2cpp::Method(_("Transform"), _("get_localToWorldMatrix"), 0, _(""), _("UnityEngine"))));
//		Matrix4x4 matrix4x = flag ? Matrix4x4() : localToWorldMatrix(ply->get_transform()->get_parent());
//		Vector3 vector = flag ? ticks->StartPoint() : matrix4x.MultiplyPoint3x4(ticks->StartPoint());
//		Vector3 a = flag ? ticks->EndPoint() : matrix4x.MultiplyPoint3x4(ticks->EndPoint());
//		float running = 1.f;
//		float ducking = 0.f;
//		float crawling = 0.f;
//
//		bool flag2 = ply->GetModelState()->HasFlag(ModelState_Flag::Sprinting);
//		bool flag3 = ply->GetModelState()->HasFlag(ModelState_Flag::Ducked);
//		bool flag4 = Classes::WaterLevelTest(Vector3(0.0f, ply->GetEyes()->GetCenter().y, 0.0f), true, ply);
//		bool flag5 = ply->GetModelState()->HasFlag(ModelState_Flag::Crawling);
//		running = (flag2 ? 1.f : 0.f);
//		ducking = ((flag3 || flag4) ? 1.f : 0.f);
//		crawling = (flag5 ? 1.f : 0.f);
//
//		float speed = GetSpeed(running, ducking, crawling);
//		Vector3 v = a - vector;
//		float num = v.Magnitude2D();
//		float num2 = deltaTime * speed;
//		if (num > num2)
//		{
//			DeathBarrier::TerrainMeta* benis = DeathBarrier::TerrainMeta::New();
//			Vector3 v2 = benis->HeightMap() ? benis->HeightMap()->GetNormal(vector) : Vector3(0, 1, 0);
//			float num3 = max(0.f, v2.UnityDot({ v2.x,0,v2.z }, { v.x,0,v.z })) * speedhack_slopespeed * deltaTime;
//			num = max(0.f, num - num3);
//		}
//		float num4 = max((speedhackPauseTime > 0.f) ? speedhack_forgiveness_inertia : speedhack_forgiveness, 0.1f);
//		float num5 = num4 + max(speedhack_forgiveness, 0.1f);
//		speedhackDistance = Clamp(speedhackDistance, -num5, num5);
//		speedhackDistance = Clamp(speedhackDistance - num2, -num5, num5);
//		if (speedhackDistance > num4)
//		{
//			result = true;
//		}
//		else
//		{
//			speedhackDistance = Clamp(speedhackDistance + num, -num5, num5);
//			if (speedhackDistance > num4)
//			{
//				result = true;
//			}
//			else
//			{
//				result = false;
//			}
//		}
//	}
//	return result;
//}
//
//Vector3 refarray[] = { Vector3::Zero() };
//
//#include <vector>
//void PathSmooth(const Vector3& ref) {
//	if (ARRAYSIZE(refarray) < 3) return;
//	// std::array<Vector3, 32>& ref
//	Vector3 new_path[] = { refarray[0], refarray[1] };
//	// std::array<Vector3, 32> new_path = { ref[0], ref[1] };
//	auto lp = LocalPlayer;
//	Vector3 current = refarray[0];
//	Vector3 next = refarray[1];
//	int fi = 0;
//	for (size_t i = 2; i < ARRAYSIZE(refarray); i++)
//	{
//		next = refarray[i];
//		if (Unity::CheckLOS(current, next)) continue;
//		else {
//			int arraySize = ARRAYSIZE(new_path);
//			// push_back(*new_path, arraySize, next);// new_path.push_back(next);
//		}
//
//		if (ARRAYSIZE(new_path) > 0 && ARRAYSIZE(new_path) < ARRAYSIZE(refarray))
//			refarray[i] = new_path[i];
//	}
//	
//}
//
//struct NodeTarget {
//	Vector3 pos;
//	int steps;
//	Vector3 path[100];
//	BaseEntity* ent;
//};
//NodeTarget node;
//
//Vector3 lowest_pos(Vector3 in)
//{
//	Vector3 current = in;
//	for (size_t i = 0; i < 100; i++)
//	{
//		if (Unity::CheckLOS(in, current))
//		{
//			current = Vector3(current.x, current.y -= 1.f, current.z);
//			continue;
//		}
//		else break;
//	}
//	return Vector3(current.x, current.y += 1.6f, current.z);
//}
//
//float dist_from_ground(Vector3 v)
//{
//	Vector3 p = v;
//	int t = 0;
//	while (t++ < 100)
//	{
//		if (!Unity::CheckLOS(v, p))
//			return v.Distance(p);
//		p.y -= 0.1;
//	}
//}
//
//std::array<Vector3, 73> sphere1m = { Vector3(0.000000, -1.000000, 0.000000), Vector3(0.382683, -0.923880, 0.000000), Vector3(0.270598, -0.923880, 0.270598), Vector3(-0.000000, -0.923880, 0.382683), Vector3(-0.270598, -0.923880, 0.270598), Vector3(-0.382683, -0.923880, -0.000000), Vector3(-0.270598, -0.923880, -0.270598), Vector3(0.000000, -0.923880, -0.382683), Vector3(0.270598, -0.923880, -0.270598), Vector3(0.382683, -0.923880, 0.000000), Vector3(0.707107, -0.707107, 0.000000), Vector3(0.500000, -0.707107, 0.500000), Vector3(-0.000000, -0.707107, 0.707107), Vector3(-0.500000, -0.707107, 0.500000), Vector3(-0.707107, -0.707107, -0.000000), Vector3(-0.500000, -0.707107, -0.500000), Vector3(0.000000, -0.707107, -0.707107), Vector3(0.500000, -0.707107, -0.500000), Vector3(0.707107, -0.707107, 0.000000), Vector3(0.923880, -0.382683, 0.000000), Vector3(0.653281, -0.382683, 0.653281), Vector3(-0.000000, -0.382683, 0.923880), Vector3(-0.653281, -0.382683, 0.653281), Vector3(-0.923880, -0.382683, -0.000000), Vector3(-0.653281, -0.382683, -0.653282), Vector3(0.000000, -0.382683, -0.923880), Vector3(0.653282, -0.382683, -0.653281), Vector3(0.923880, -0.382683, 0.000000), Vector3(1.000000, 0.000000, 0.000000), Vector3(0.707107, 0.000000, 0.707107), Vector3(-0.000000, 0.000000, 1.000000), Vector3(-0.707107, 0.000000, 0.707107), Vector3(-1.000000, 0.000000, -0.000000), Vector3(-0.707107, 0.000000, -0.707107), Vector3(0.000000, 0.000000, -1.000000), Vector3(0.707107, 0.000000, -0.707107), Vector3(1.000000, 0.000000, 0.000000), Vector3(0.923880, 0.382683, 0.000000), Vector3(0.653281, 0.382683, 0.653281), Vector3(-0.000000, 0.382683, 0.923880), Vector3(-0.653281, 0.382683, 0.653281), Vector3(-0.923880, 0.382683, -0.000000), Vector3(-0.653281, 0.382683, -0.653282), Vector3(0.000000, 0.382683, -0.923880), Vector3(0.653282, 0.382683, -0.653281), Vector3(0.923880, 0.382683, 0.000000), Vector3(0.707107, 0.707107, 0.000000), Vector3(0.500000, 0.707107, 0.500000), Vector3(-0.000000, 0.707107, 0.707107), Vector3(-0.500000, 0.707107, 0.500000), Vector3(-0.707107, 0.707107, -0.000000), Vector3(-0.500000, 0.707107, -0.500000), Vector3(0.000000, 0.707107, -0.707107), Vector3(0.500000, 0.707107, -0.500000), Vector3(0.707107, 0.707107, 0.000000), Vector3(0.382683, 0.923880, 0.000000), Vector3(0.270598, 0.923880, 0.270598), Vector3(-0.000000, 0.923880, 0.382683), Vector3(-0.270598, 0.923880, 0.270598), Vector3(-0.382683, 0.923880, -0.000000), Vector3(-0.270598, 0.923880, -0.270598), Vector3(0.000000, 0.923880, -0.382683), Vector3(0.270598, 0.923880, -0.270598), Vector3(0.382683, 0.923880, 0.000000), Vector3(-0.000000, 1.000000, -0.000000), Vector3(-0.000000, 1.000000, -0.000000), Vector3(0.000000, 1.000000, -0.000000), Vector3(0.000000, 1.000000, -0.000000), Vector3(0.000000, 1.000000, 0.000000), Vector3(0.000000, 1.000000, 0.000000), Vector3(-0.000000, 1.000000, 0.000000), Vector3(-0.000000, 1.000000, 0.000000), Vector3(-0.000000, 1.000000, -0.000000) };
//
//void CreatePath(Vector3 marker_pos,
//	Vector3 point)
//{
//	node.pos = marker_pos;
//	node.steps = 1;
//	//create path
//	Vector3 path[100] = {};
//	// std::vector<Vector3> path;
//	Vector3 original = point;
//	bool failed = false;
//	Vector3 old_point = point;
//	float control = 0.f;
//	int iterations = 0;
//	while (point.Distance(node.pos) > 1.5f)
//	{
//		if (iterations++ > 500)
//			break;
//
//		int arraySize = ARRAYSIZE(path);
//		push_back(&*path, arraySize, point);
//		// path.push_back(point);
//		Vector3 new_point = Vector3::MoveTowards(point, node.pos, 1.0f);
//
//		if (Unity::CheckLOS(point, new_point, 1.5f))
//		{
//			// esp::local_player->console_echo(string::wformat(_(L"[trap]: CreatePath - visibility straight ahead (%d)"), path.size()));
//			old_point = point;
//			point = lowest_pos(new_point);
//		}
//		else
//		{
//			// esp::local_player->console_echo(string::wformat(_(L"[trap]: CreatePath - no visibility straight ahead, creating sphere (%d)"), path.size()));
//
//			Vector3 ps[100] = {};
//
//			// std::vector<Vector3> ps = {};
//
//			for (auto e : sphere1m) //create sphere if cannot find LOS straight ahead
//				if (Unity::CheckLOS(point, point + e, 1.5f)
//					&& (point + e).Distance(node.pos) < point.Distance(node.pos)
//					&& (point + e).Distance(point) > 0.7f)
//				{
//					int arraySize2 = ARRAYSIZE(ps);
//					push_back(&*ps, arraySize2, (point + e));
//				}
//
//			Vector3 best = Vector3(0, 0, 0);
//			if (ARRAYSIZE(ps) == 0) {
//				// esp::local_player->console_echo(string::wformat(_(L"[trap]: CreatePath could not create another node, path size: %i"), path.size()));
//				break;
//			}
//
//
//			for (auto e : ps) {
//				if (e.Distance(node.pos) < best.Distance(node.pos) && dist_from_ground(e) < 1.6f)
//					best = e;
//			}
//			
//			old_point = point;
//			point = best;
//		}
//	}
//
//
//	for (int i = 0; i <= 100; i++) {
//		if (path[i] != Vector3::Zero())
//			node.path[i] = path[i];
//	}
//}

void BlockServerComands()
{ // 50121592
	typedef GameList<uintptr_t>* (*AAA)();//real rust 36223520 ALKAD 36217232 "Name": "ConsoleSystem.Index$$get_All",
	GameList<uintptr_t>* command_list = ((AAA)(g_Base + offsets::ConsoleSystem_Index$$get_All))();

	if (command_list) {
		auto sz = *reinterpret_cast<int*>(command_list + 0x18);
		for (size_t i = 0; i < sz; i++)
		{
			auto commandInList = *reinterpret_cast<uintptr_t*>(command_list + 0x20 + i * 0x8); if (!commandInList) continue;
			const wchar_t* command = Read<const wchar_t*>((uintptr_t)commandInList + 0x10);
			if (!m_wcsicmp(command, _(L"noclip")) || !m_wcsicmp(command, _(L"debugcamera")) || !m_wcsicmp(command, _(L"camspeed")) || !m_wcsicmp(command, _(L"camlook")))
				// if (*(int*)(command + 2) == 'pilc' || *(int*)(command + 5) == 'emac' || *(int*)(command + 3) == 'eeps' || *(int*)(command + 3) == 'prel' || *(int*)(command + 3) == 'kool')
			{
				// LocalPlayer->ConsoleMsg(_(L"noclip"));
				Write<bool>((uintptr_t)commandInList + 0x58, false);
			}
		}
	}
}