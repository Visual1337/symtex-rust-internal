#define powFFFFFFFFFFFFFFFFFFFFFF(n) (n)*(n)

DWORD64 g_Base = 0;
DWORD64 m_kernel32 = 0;



float sqrtn1(const float& x)
{
	union
	{
		int i;
		float x;
	} u;
	u.x = x;
	u.i = (1 << 29) + (u.i >> 1) - (1 << 22);

	u.x = u.x + x / u.x;
	u.x = 0.25f * u.x + x / u.x;

	return u.x;
}

class Vector3
{
public:
	float x, y, z;

	Vector3() {
		x = y = z = 0.0f;
	}

	Vector3(float X, float Y, float Z) {
		x = X; y = Y; z = Z;
	}

	float operator[](int i) const {
		return ((float*)this)[i];
	}

	Vector3& operator-=(float v) {
		x -= v; y -= v; z -= v; return *this;
	}

	Vector3 operator*(float v) const {
		return Vector3(x * v, y * v, z * v);
	}

	Vector3 operator/(float v) const
	{
		return Vector3(x / v, y / v, z / v);
	}

	Vector3& operator+=(const Vector3& v) {
		x += v.x; y += v.y; z += v.z; return *this;
	}

	Vector3 operator-(const Vector3& v) const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}
	bool operator==(const Vector3& b) const {
		return x == b.x && y == b.y && z == b.z;
	}
	Vector3& operator-=(const Vector3& v) {
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	Vector3& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		return *this;
	}

	Vector3 operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	static Vector3 Zero() {
		return Vector3(0.0f, 0.0f, 0.0f);
	}
	static float my_sqrt(float number) {
		long        i;
		float       x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y; // floating point bit level hacking [sic]
		i = 0x5f3759df - (i >> 1); // Newton's approximation
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y)); // 1st iteration
		y = y * (threehalfs - (x2 * y * y)); // 2nd iteration

		return 1 / y;
	}


	inline float Length()
	{
		return my_sqrt((x * x) + (y * y) + (z * z));
	}
	bool Empty() { return x == 0 && y == 0 && z == 0; }
	Vector3 Normalized() {
		float len = Length();
		return Vector3(x / len, y / len, z / len);
	}
	
	float Magnitude() {
		return my_sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	float Magnitude2D()
	{
		return my_sqrt(this->x * this->x + this->z * this->z);
	}

	Vector3 Normalize()
	{
		Vector3 out = *this;
		auto l = Length();
		if (l == 0)
			return *this;
		;
		out.x /= l;
		out.y /= l;
		out.z /= l;
		return out;
	}



	void UnityNormalize()
	{
		Vector3 tis(x, y, z);
		float num = Vector3(x, y, z).Magnitude();
		if (num > 1E-05f)
		{
			tis /= num;
		}
		else
		{
			tis = Vector3().Zero();
		}
		x = tis.x;
		y = tis.y;
		z = tis.z;
	}

	Vector3 midPoint(Vector3 v2)
	{
		return Vector3((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2);
	}

	__forceinline float Distance3D(const Vector3& Src, const Vector3& Dst)
	{
		return my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF((Src.x - Dst.x), 2) + powFFFFFFFFFFFFFFFFFFFFFF((Src.y - Dst.y), 2) + powFFFFFFFFFFFFFFFFFFFFFF((Src.z - Dst.z), 2));
	}

	inline float Dot(const Vector3& Vec2) {
		return this->x * Vec2.x + this->y * Vec2.y + this->z * Vec2.z;
	}

	inline float UnityDot(Vector3 lhs, Vector3 rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	float Distance(const Vector3& vector)
	{
		return my_sqrt(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z));
	}

	float DistanceXZ(const Vector3& vector)
	{
		return my_sqrt((x - vector.x) * (x - vector.x) + 0 + (z - vector.z) * (z - vector.z));
	}

	static Vector3 MoveTowards(Vector3 current, Vector3 target, float maxDistanceDelta)
	{
		float num = target.x - current.x;
		float num2 = target.y - current.y;
		float num3 = target.z - current.z;
		float num4 = num * num + num2 * num2 + num3 * num3;
		bool flag = num4 == 0.f || (maxDistanceDelta >= 0.f && num4 <= maxDistanceDelta * maxDistanceDelta);
		Vector3 result;
		if (flag)
		{
			result = target;
		}
		else
		{
			float num5 = (float)my_sqrt((double)num4);
			result = Vector3(current.x + num / num5 * maxDistanceDelta, current.y + num2 / num5 * maxDistanceDelta, current.z + num3 / num5 * maxDistanceDelta);
		}
		return result;
	}

	Vector3 XZ3D()
	{
		return Vector3(this->x, 0.f, this->z);
	}
};

class Vector2 {
public:
	float x, y;

	Vector2() {
		x = y = 0.0f;
	}

	Vector2 operator*(float v) const {
		return Vector2(x * v, y * v);
	}

	Vector2 operator/(float v) const {
		return Vector2(x / v, y / v);
	}
	Vector2(float X, float Y) {
		x = X; y = Y;
	}

	Vector2 operator-(const Vector2& v) const {
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 operator+(const Vector2& v) const {
		return Vector2(x + v.x, y + v.y);
	}

	Vector2& operator+=(const Vector2& v) {
		x += v.x; y += v.y; return *this;
	}

	bool Zero() const {
		return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
	}

	static Vector2 Zero2() {
		return Vector2(0.0f, 0.0f);
	}

	float Length() {
		return sqrtn1(x * x + y * y);
	}


	Vector2 Normalize() {
		return Vector2(this->x / Length(), this->y / Length());
	}


	void NormalizePredict()
	{

		if (x < -89)
			x = -89;

		else if (x > 89)
			x = 89;

		if (y < -360)
			y += 360;

		else if (y > 360)
			y -= 360;

	}

	static float my_sqrt(float number) {
		long        i;
		float       x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y; // floating point bit level hacking [sic]
		i = 0x5f3759df - (i >> 1); // Newton's approximation
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y)); // 1st iteration
		y = y * (threehalfs - (x2 * y * y)); // 2nd iteration

		return 1 / y;
	}

	float Distance(Vector2 b)
	{
		return my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF(b.x - x) + powFFFFFFFFFFFFFFFFFFFFFF(b.y - y));
	}

	

private:
	float sqrLength() {
		return (x * x + y * y);
	}

};

class Vector4 {
public:
	float x, y, z, w;
};

struct Matrix4x4Line
{
	float m00; float m10; float m20; float m30;
	float m01; float m11; float m21; float m31;
	float m02; float m12; float m22; float m32;
	float m03; float m13; float m23; float m33;

	Matrix4x4Line Identity() {
		this->m00 = 1.f;
		this->m11 = 1.f;
		this->m22 = 1.f;
		this->m33 = 1.f;
		return *this;
	}
};

struct Matrix4x4 {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};

	Vector3 MultiplyPoint3x4(Vector3 point)
	{
		Vector3 result;
		result.x = m[0][0] * point.x + m[0][1] * point.y + m[0][2] * point.z + m[0][3];
		result.y = m[1][0] * point.x + m[1][1] * point.y + m[1][2] * point.z + m[1][3];
		result.z = m[2][0] * point.x + m[2][1] * point.y + m[2][2] * point.z + m[2][3];
		return result;
	}
	
};

class Quaternion {
public:
	float x, y, z, w;

	Quaternion() {
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Quaternion(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Quaternion operator*(Quaternion rhs) {
		return Quaternion(
			this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y,
			this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z,
			this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x,
			this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z
		);
	}

	float Dot(Quaternion b) {
		return x * x + y * y + z * z + w * w;
	}

	Vector3 operator*(Vector3 point) {
		float num = this->x * 2.f;
		float num2 = this->y * 2.f;
		float num3 = this->z * 2.f;
		float num4 = this->x * num;
		float num5 = this->y * num2;
		float num6 = this->z * num3;
		float num7 = this->x * num2;
		float num8 = this->x * num3;
		float num9 = this->y * num3;
		float num10 = this->w * num;
		float num11 = this->w * num2;
		float num12 = this->w * num3;
		Vector3 result;
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}
};

Vector3 rpc_pos;

void push_back(Vector3*& arr, int& size, const Vector3& value) {
	//const static int sz = size + 1;
	Vector3* temp/* = new Vector3[size + 1]*/;
	for (int i = 0; i < size; ++i) {
		temp[i] = arr[i];
	}
	temp[size] = value;
	arr = nullptr;
	arr = temp;
	++size;
}