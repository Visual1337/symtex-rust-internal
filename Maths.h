#pragma once

#define M_PI 3.14159265358979323846f
#define M_RADPI	57.295779513082f
#define PI 3.14159265358979323846
#define PI_2 1.57079632679489661923
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F / 180.f))

unsigned short lfsr = 0xACE1u;
unsigned int bit = 0;

auto MethodClamp = reinterpret_cast<int(*)(int, int, int)>(0);
auto MethodSqrt = reinterpret_cast<double(*)(double)>(0);
auto MethodAcos = reinterpret_cast<double(*)(double)>(0);
auto MethodSin = reinterpret_cast<double(*)(double)>(0);
auto MethodTan = reinterpret_cast<double(*)(double)>(0);
auto MethodCos = reinterpret_cast<double(*)(double)>(0);
auto MethodASIN = reinterpret_cast<double(*)(double)>(0);
auto MethodATAN2 = reinterpret_cast<double(*)(double, double)>(0);
auto MethodATAN = reinterpret_cast<double(*)(double)>(0);

auto MethodABS = reinterpret_cast<double(*)(double)>(0);
namespace Maths
{
	int m_Clamp(int a, int b, int c) {
		return MethodClamp(a, b, c); // g_Base + 0x1AE4060 // Il2cpp::Method(_("Math"), ("Sin"), -1, _(""), _("System"))
	}

	double m_Sin(double d) {
		return MethodSin(d); // g_Base + 0x1AE4060 // Il2cpp::Method(_("Math"), ("Sin"), -1, _(""), _("System"))
	}
	double m_Cos(double d) {
		return MethodCos(d);
	}
	double m_Abs(double d) {
		return MethodABS(d);
	}
	double m_Sqrt(double d) {
		return MethodSqrt(d);
	};
	double m_Acos(double d) {
		return MethodAcos(d);
	};
	double m_Asin(double d) {
		return MethodASIN(d);
	}
	double m_Atan2(double y, double x) {
		return MethodATAN2(y, x);
	}
	double m_Tan(double d) {
		return MethodTan(d);
	}
	double m_Atan(double y) {
		return MethodATAN(y);
	}
	__forceinline float Calc3D_Dist(const Vector3& Src, const Vector3& Dst) {
		return m_Sqrt(powFFFFFFFFFFFFFFFFFFFFFF(Src.x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(Src.y - Dst.y) + powFFFFFFFFFFFFFFFFFFFFFF(Src.z - Dst.z));
	}

	__forceinline float Calc2D_Dist(const Vector2& Src, const Vector2& Dst) {
		return m_Sqrt(powFFFFFFFFFFFFFFFFFFFFFF(Src.x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(Src.y - Dst.y));
	}


	__forceinline float Dot(const Vector3& Vec1, const Vector3& Vec2) {
		return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
	}

	__forceinline Vector2 CalcAngle(const Vector3& Src, const Vector3& Dst) {
		Vector3 dir = Src - Dst;
		return Vector2{ RAD2DEG(Maths::m_Asin(dir.y / dir.Length())), RAD2DEG(-Maths::m_Atan2(dir.x, -dir.z)) };
	}

	void Normalize(float& Yaw, float& Pitch) {
		if (Pitch < -89) Pitch = -89;
		else if (Pitch > 89) Pitch = 89;
		if (Yaw < -360) Yaw += 360;
		else if (Yaw > 360) Yaw -= 360;
	}

	bool LineCircleIntersection(Vector3 center,
		float radius,
		Vector3 rayStart,
		Vector3 rayEnd,
		float& offset)
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
				offset += m_Abs(center.y - closestPoint.y);
				return false;
			}
		}

		return false;
	};

	float Lerp(float a, float b, float t)
	{
		return a + (b - a) * t;
	}

	unsigned my_rand()
	{
		if (!lfsr) {
			lfsr = 0xACE1u; bit = 0;
		}
		bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
		return lfsr = (lfsr >> 1) | (bit << 15);
	}

	float NormalizeAngle(float angle) {
		while (angle > 360.0f) {
			angle -= 360.0f;
		}
		while (angle < 0.0f) {
			angle += 360.0f;
		}
		return angle;
	}

	Vector3 NormalizeAngles(Vector3 angles) {
		angles.x = NormalizeAngle(angles.x);
		angles.y = NormalizeAngle(angles.y);
		angles.z = NormalizeAngle(angles.z);
		return angles;
	}

	Vector2 CosTanSinLineH(float flAngle, float range, int x, int y, int LineLength) {
		float mainAngle = flAngle;
		mainAngle += 45.f;

		float flYaw = (mainAngle) * (M_PI / 180.0);

		float viewcosyawzzzzzzz = m_Cos(flYaw);
		float viewsinyawzzzzzzz = m_Sin(flYaw);

		float x2 = range * (-viewcosyawzzzzzzz) + range * viewsinyawzzzzzzz;
		float y2 = range * (-viewcosyawzzzzzzz) - range * viewsinyawzzzzzzz;

		int posonscreenX = x + int(x2 / range * (LineLength));
		int posonscreenY = y + int(y2 / range * (LineLength));

		return Vector2(posonscreenX, posonscreenY);
	}

	Vector3 EulerAngles(Quaternion q1) {
		float num = q1.w * q1.w;
		float num2 = q1.x * q1.x;
		float num3 = q1.y * q1.y;
		float num4 = q1.z * q1.z;
		float num5 = num2 + num3 + num4 + num;
		float num6 = q1.x * q1.w - q1.y * q1.z;
		Vector3 vector;
		if (num6 > 0.4995f * num5) {
			vector.y = 2.0f * m_Atan2(q1.y, q1.x);
			vector.x = 1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		if (num6 < -0.4995f * num5) {
			vector.y = -2.0f * m_Atan2(q1.y, q1.x);
			vector.x = -1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		Quaternion quaternion = Quaternion(q1.w, q1.z, q1.x, q1.y);
		vector.y = m_Atan2(2.0f * quaternion.x * quaternion.w + 2.0f * quaternion.y * quaternion.z, 1.0f - 2.0f * (quaternion.z * quaternion.z + quaternion.w * quaternion.w));
		vector.x = m_Asin(2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y));
		vector.z = m_Atan2(2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w, 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z));
		return NormalizeAngles(vector * 57.2958f);
	}

	int XFloor_f__(float value) {
		int fl = static_cast<int>(value);
		return (value < 0 && value != fl) ? fl - 1 : fl;
	}
}

//char* Itoa(int m_iValue, char* m_pBuffer, int m_iRadix)
//{
//	auto xtoa = [](int a1, char* a2, int a3, bool a4) -> char
//	{
//		char* v5; // r10
//		char* v6; // r8
//		char* v7; // r11
//		char* v8; // r9
//		unsigned int v9; // edx
//		char v10; // al
//		char result; // al
//		char v12; // cl
//
//		v5 = a2;
//		if (a4)
//		{
//			v5 = a2 + 1;
//			*a2 = 45;
//			a1 = -a1;
//		}
//		v6 = v5;
//		do
//		{
//			v7 = v5 + 1;
//			v8 = v5;
//			v9 = a1 % a3;
//			a1 /= a3;
//			v10 = 87;
//			if (v9 <= 9)
//				v10 = 48;
//			*v5++ = v9 + v10;
//		} while (a1);
//		*v7 = 0;
//		do
//		{
//			result = *v6;
//			v12 = *v8;
//			*v8-- = *v6;
//			*v6++ = v12;
//		} while (v6 < v8);
//		return result;
//	};
//
//	bool v3; // r9
//
//	v3 = false;
//	if (m_iRadix == 10 && m_iValue < 0)
//		v3 = true;
//	xtoa(m_iValue, m_pBuffer, m_iRadix, v3);
//	return m_pBuffer;
//}
//
//void AnsiToUnicode(const char* m_szAnsi, wchar_t* m_pBuffer)
//{
//	for (int i = 0; ; ++i)
//	{
//		m_pBuffer[i] = static_cast<char>(m_szAnsi[i]);
//
//		if (!m_szAnsi[i])
//			return;
//	}
//}


