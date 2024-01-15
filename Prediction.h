
bool LineCircleIntersection(Vector3 center, float radius, Vector3 rayStart, Vector3 rayEnd, float* offset)
{
	Vector2 P(rayStart.x, rayStart.z);
	Vector2 Q(rayEnd.x, rayEnd.z);

	float a = Q.y - P.y;
	float b = P.x - Q.x;
	float c = (a * (P.x) + b * (P.y)) * -1.f;

	float x = center.x;
	float y = center.z;

	float c_x = (b * ((b * x) - (a * y)) - a * c) / (powFFFFFFFFFFFFFFFFFFFFFF(a, 2) + powFFFFFFFFFFFFFFFFFFFFFF(b, 2));
	float c_y = (a * ((-b * x) + (a * y)) - (b * c)) / (powFFFFFFFFFFFFFFFFFFFFFF(a, 2) + powFFFFFFFFFFFFFFFFFFFFFF(b, 2));

	Vector2 closestPoint(c_x, c_y);

	float distance = P.Distance(Q);

	if (P.Distance(closestPoint) > distance || Q.Distance(closestPoint) > distance)
	{
		return false;
	}

	if (radius > closestPoint.Distance(Vector2(center.x, center.z)))
	{
		Vector2 P(rayStart.x, rayStart.y);
		Vector2 Q(rayEnd.x, rayEnd.y);

		float a = Q.y - P.y;
		float b = P.x - Q.x;
		float c = (a * (P.x) + b * (P.y)) * -1.f;

		float x = center.x;
		float y = center.y;

		float c_x = (b * ((b * x) - (a * y)) - a * c) / (powFFFFFFFFFFFFFFFFFFFFFF(a, 2) + powFFFFFFFFFFFFFFFFFFFFFF(b, 2));
		float c_y = (a * ((-b * x) + (a * y)) - (b * c)) / (powFFFFFFFFFFFFFFFFFFFFFF(a, 2) + powFFFFFFFFFFFFFFFFFFFFFF(b, 2));

		Vector2 closestPoint(c_x, c_y);
		if (radius > closestPoint.Distance(Vector2(center.x, center.y)))
		{
			return true;
		}
		else
		{
			*offset = (closestPoint.Distance(P) / distance);
			return false;
		}
	}

	return false;
}


Vector3 MoveTowards(Vector3 start, Vector3 end, float maxDistance) {
	Vector3 direction = end - start;
	float distance = direction.Magnitude();
	if (distance > maxDistance) {
		direction.Normalized();
		return start + direction * maxDistance;
	}
	return end;
}

Vector2 YawPitchAngles(const Vector3& velocity1, const Vector3& velocity2) {
	float deltaYaw = Maths::m_Atan2(velocity2.x, velocity2.z) - Maths::m_Atan2(velocity1.x, velocity1.z);
	//float deltaPitch = std::asin(velocity2.y) - std::asin(velocity1.y);
	return Vector2(deltaYaw, 0);
}

namespace VelocityData {
	struct
	{
		int Records = 16;
		Vector3 velocities[16];
		int currentVelocityRecords = {};
		int currentVelocityIndex = {};
		Vector3 avgVel = Vector3{ 0.f, 0.f, 0.f };
	} inline PredictionDatas;

	void Update(BasePlayer* target_ply)
	{
		if (!target_ply) {
			VelocityData::PredictionDatas.currentVelocityRecords = 0;
			VelocityData::PredictionDatas.currentVelocityIndex = 0;
			VelocityData::PredictionDatas.avgVel = Vector3::Zero();
			return;
		}
		int Records = VelocityData::PredictionDatas.Records;
		Vector3 defaultVelocity = Classes::GetWorldVelocity(target_ply);
		if (defaultVelocity.Empty())
			defaultVelocity = Classes::GetWorldVelocity(target_ply);

		if (defaultVelocity.Empty())
		{
			VelocityData::PredictionDatas.currentVelocityRecords = 0;
			VelocityData::PredictionDatas.currentVelocityIndex = 0;
			VelocityData::PredictionDatas.avgVel = defaultVelocity;
		}
		else {
			VelocityData::PredictionDatas.velocities[VelocityData::PredictionDatas.currentVelocityIndex++] = defaultVelocity;
			if (VelocityData::PredictionDatas.currentVelocityIndex >= Records)
				VelocityData::PredictionDatas.currentVelocityIndex = 0;

			VelocityData::PredictionDatas.currentVelocityRecords++;
			if (VelocityData::PredictionDatas.currentVelocityRecords >= 0)
				VelocityData::PredictionDatas.currentVelocityRecords = Records;

			int currentRecords = VelocityData::PredictionDatas.currentVelocityRecords;

			Vector3 velSum{};
			for (size_t j = 0; j < currentRecords; j++)
				velSum += VelocityData::PredictionDatas.velocities[j];

			VelocityData::PredictionDatas.avgVel = velSum / (float)currentRecords;
		}
	}
}

namespace AngleData {
	struct
	{
		int Records = 8;
		Vector2 Angles[8];
		int currentAngleRecords = {};
		int currentAngleIndex = {};
		Vector2 avgAV = Vector2{ 0.f, 0.f };
	} inline AngleDatas;

	void Update() {
		if (!Target.Cur) {
			AngleData::AngleDatas.currentAngleRecords = 0;
			AngleData::AngleDatas.currentAngleIndex = 0;
			AngleData::AngleDatas.avgAV = { 0.f, 0.f };
			return;
		}
		int Records = VelocityData::PredictionDatas.Records;
		Vector2 defaultAV = YawPitchAngles(VelocityData::PredictionDatas.avgVel, VelocityData::PredictionDatas.velocities[VelocityData::PredictionDatas.currentVelocityIndex]);

		if (defaultAV.x == 0 && defaultAV.y == 0)
		{
			AngleData::AngleDatas.currentAngleRecords = 0;
			AngleData::AngleDatas.currentAngleIndex = 0;
			AngleData::AngleDatas.avgAV = defaultAV;
		}
		else {
			AngleData::AngleDatas.Angles[AngleData::AngleDatas.currentAngleIndex++] = defaultAV;
			if (AngleData::AngleDatas.currentAngleIndex >= Records)
				AngleData::AngleDatas.currentAngleIndex = 0;

			AngleData::AngleDatas.currentAngleRecords++;
			if (AngleData::AngleDatas.currentAngleRecords >= 0)
				AngleData::AngleDatas.currentAngleRecords = Records;

			int currentRecords = AngleData::AngleDatas.currentAngleRecords;

			Vector2 velSum{};
			for (size_t j = 0; j < currentRecords; j++)
				velSum += AngleData::AngleDatas.Angles[j];

			AngleData::AngleDatas.avgAV = velSum / (float)currentRecords;
		}
	}
}

Vector3 PredictTarget(Vector3 TargetPos, Vector3 InitialPos, float Velocity, float Drag, float GravityMulti, float initialDistance, bool* Sims_finished, float* TravelTime)
{
	float totalTT = 0;
	bool SimulationFinished = false;
	static int MaximumSims = 30;

	float TraveledDistance = 0;
	float PitchOffset = 0;
	Vector3 TargetPostion = TargetPos;

	for (int i = 0; i < MaximumSims; i++)
	{
		TargetPostion.y += PitchOffset; //Append Last Offset
		Vector3 Angle = TargetPostion - InitialPos;
		Vector3 CalcVelocity = Angle.Normalized() * Velocity;
		Vector3 ProjectilePosition = InitialPos;
		Vector3 PreviousPosition = Vector3();
		const float StepSize = 0.03125f;
		for (float ProjectileTime = 0.f; ProjectileTime < 8.f; ProjectileTime += StepSize)
		{
			PreviousPosition = ProjectilePosition;
			ProjectilePosition = ProjectilePosition + (CalcVelocity * StepSize);

			TraveledDistance += (ProjectilePosition - PreviousPosition).Magnitude();
			if (TraveledDistance < initialDistance)
				ProjectileTime -= StepSize;

			CalcVelocity.y -= 9.81f * GravityMulti * StepSize;
			CalcVelocity -= CalcVelocity * Drag * StepSize;
			float eep = 0;
			if (LineCircleIntersection(TargetPos, 0.025f, PreviousPosition, ProjectilePosition, &eep)) {
				SimulationFinished = true;

				totalTT = ProjectileTime - ((getLerp(TargetPostion, ProjectilePosition, PreviousPosition) * StepSize));
				totalTT = ((totalTT > 0.f ? totalTT : 0.f) < 8.f) ? totalTT : 8.f;

				break;
			}
			else if (InitialPos.Distance(TargetPos) < InitialPos.Distance(ProjectilePosition)) {
				Vector3 CalculatedPosition = Vector3(TargetPos.x, Maths::Lerp(ProjectilePosition.y, PreviousPosition.y, getLerp(TargetPostion, ProjectilePosition, PreviousPosition)), TargetPos.z);
				PitchOffset = TargetPos.y - CalculatedPosition.y;
				break;
			}
		}


		if (SimulationFinished)
			break;
	}

	bool SecondSimulationFinished = false;

	float SecondTraveledDistance = 0;
	float SecondPitchOffset = 0;
	Vector3 semipredict = (VelocityData::PredictionDatas.avgVel * totalTT) + Vector3((AngleData::AngleDatas.avgAV * totalTT).x, 0, 0);
	Vector3 SecondTargetPostion = TargetPostion + semipredict;

	for (int i = 0; i < MaximumSims; i++)
	{
		SecondTargetPostion.y += SecondPitchOffset; //Append Last Offset
		Vector3 Angle = SecondTargetPostion - InitialPos;
		Vector3 CalcVelocity = Angle.Normalized() * Velocity;
		Vector3 ProjectilePosition = InitialPos;
		Vector3 PreviousPosition = Vector3();
		const float StepSize = 0.03125f;
		for (float ProjectileTime = 0.f; ProjectileTime < 8.f; ProjectileTime += StepSize)
		{
			PreviousPosition = ProjectilePosition;
			ProjectilePosition = ProjectilePosition + (CalcVelocity * StepSize);

			SecondTraveledDistance += (ProjectilePosition - PreviousPosition).Magnitude();
			if (SecondTraveledDistance < initialDistance)
				ProjectileTime -= StepSize;

			CalcVelocity.y -= 9.81f * GravityMulti * StepSize;
			CalcVelocity -= CalcVelocity * Drag * StepSize;
			float eep = 0;
			if (LineCircleIntersection(TargetPos, 0.025f, PreviousPosition, ProjectilePosition, &eep)) {
				SecondSimulationFinished = true;

				totalTT = ProjectileTime - ((getLerp(TargetPostion, ProjectilePosition, PreviousPosition) * StepSize));
				totalTT = ((totalTT > 0.f ? totalTT : 0.f) < 8.f) ? totalTT : 8.f;

				break;
			}
			else if (InitialPos.Distance(TargetPos) < InitialPos.Distance(ProjectilePosition)) {
				Vector3 CalculatedPosition = Vector3(TargetPos.x, Maths::Lerp(ProjectilePosition.y, PreviousPosition.y, getLerp(TargetPostion, ProjectilePosition, PreviousPosition)), TargetPos.z);
				SecondPitchOffset = TargetPos.y - CalculatedPosition.y;
				break;
			}
		}


		if (SecondSimulationFinished)
			break;
	}
	*TravelTime = totalTT;
	*Sims_finished = SimulationFinished && SecondSimulationFinished;
	return TargetPostion;
}
