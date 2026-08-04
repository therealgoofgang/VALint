#pragma once
#include <math.h>
#include <corecrt_math_defines.h>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>
#include "canvas_gui.h"
#include <stringapiset.h>

#define RAD(degs) float(degs) * PI / 180.0f
#define DEG(rads) float(rads) * 180.0f / PI



struct FVector
{
	float X, Y, Z;

	FVector() : X(0.f), Y(0.f), Z(0.f) {}

	FVector(float X, float Y, float z) : X(X), Y(Y), Z(z) {}

	FVector(float InF) : X(InF), Y(InF), Z(InF) { }

	FVector ClampFVector() {
		while (X < -88.f) X += 360;
		//    if (X == -89.f) X = !-89;
		while (X > 89.f) X -= 89.f;

		//if (X < 0)X >= 0;
		//if (X == -89.f) X != -89.f;
		while (Y < -180.f) Y += 360.f;
		while (Y > 180.f) Y -= 360.f;
		Z = 0.f;

		return FVector{ X, Y,Z };

	}

	inline float Distance(FVector v)
	{
		float X = this->X - v.X;
		float Y = this->Y - v.Y;
		float z = this->Z - v.Z;

		return sqrtf((X * X) + (Y * Y) + (z * z)) * 0.03048f;
	}

	inline float Dot(const FVector& B) const { return (X * B.X) + (Y * B.Y) + (Z * B.Z); }

	inline float MagnitudeSqr() const { return Dot(*this); }

	inline float Magnitude() const { return std::sqrtf(MagnitudeSqr()); }

	float Size() const { return sqrtf(X * X + Y * Y + Z * Z); }

	float Sum() const { return X + Y + Z; }

	float Size2D() const { return sqrtf(X * X + Y * Y); }

	float SizeSquared() const { return X * X + Y * Y + Z * Z; }

	float DistTo(const FVector& V) const { return (*this - V).Size(); }

	FVector operator+(const FVector& other) const { return FVector(X + other.X, Y + other.Y, Z + other.Z); }

	FVector operator-(const FVector& other) const { return FVector(X - other.X, Y - other.Y, Z - other.Z); }

	FVector operator*(const FVector& V) const { return FVector(X * V.X, Y * V.Y, Z * V.Z); }

	FVector operator/(const FVector& V) const { return FVector(X / V.X, Y / V.Y, Z / V.Z); }

	bool operator==(const FVector& V) const { return X == V.X && Y == V.Y && Z == V.Z; }

	bool operator!=(const FVector& V) const { return X != V.X || Y != V.Y || Z != V.Z; }

	FVector operator-() const { return FVector(-X, -Y, -Z); }

	FVector operator+(float Bias) const { return FVector(X + Bias, Y + Bias, Z + Bias); }

	FVector operator-(float Bias) const { return FVector(X - Bias, Y - Bias, Z - Bias); }

	FVector operator*(float Scale) const { return FVector(X * Scale, Y * Scale, Z * Scale); } const

		FVector operator/(float Scale) const { const float RScale = 1.f / Scale; return FVector(X * RScale, Y * RScale, Z * RScale); }

	FVector operator=(const FVector& V) { X = V.X; Y = V.Y; Z = V.Z; return *this; }

	FVector operator+=(const FVector& V) { X += V.X; Y += V.Y; Z += V.Z; return *this; }

	FVector operator-=(const FVector& V) { X -= V.X; Y -= V.Y; Z -= V.Z; return *this; }

	FVector operator*=(const FVector& V) { X *= V.X; Y *= V.Y; Z *= V.Z; return *this; }

	FVector operator/=(const FVector& V) { X /= V.X; Y /= V.Y; Z /= V.Z; return *this; }

	FVector operator*=(float Scale) { X *= Scale; Y *= Scale; Z *= Scale; return *this; }

	FVector operator/=(float V) { const float RV = 1.f / V; X *= RV; Y *= RV; Z *= RV; return *this; }

	float operator|(const FVector& V) const { return X * V.X + Y * V.Y + Z * V.Z; }

	FVector operator^(const FVector& V) const { return FVector(Y * V.Z - Z * V.Y, Z * V.X - X * V.Z, X * V.Y - Y * V.X); }

	bool IsValid()
	{
		if (X == 0 || Y == 0 || Z == 0)
			return false;
		else
			return true;
	}
	static const FVector ZeroVector;

	static const FVector OneVector;
};
class FTextData
{
private:
	std::uint8_t Padding[0x28];

public:
	wchar_t* Name;
	std::int32_t* Length;
};

class FText
{
public:
	FTextData* Data;

private:
	std::uint8_t Padding[0x10];
};
namespace Math
{
	float RadianToDegree(float radian)
	{
		return radian * (180 / M_PI);
	}

	float DegreeToRadian(float degree)
	{
		return degree * (M_PI / 180);

	}

	FVector RadianToDegree(FVector radians)
	{
		FVector degrees;
		degrees.X = radians.X * (180 / M_PI);
		degrees.Y = radians.Y * (180 / M_PI);
		degrees.Z = radians.Z * (180 / M_PI);
		return degrees;
	}

	FVector DegreeToRadian(FVector degrees)
	{
		FVector radians;
		radians.X = degrees.X * (M_PI / 180);
		radians.Y = degrees.Y * (M_PI / 180);
		radians.Z = degrees.Z * (M_PI / 180);
		return radians;
	}

	void normalize(FVector& in)
	{
		if (in.X > 89.f) in.X -= 360.f;
		else if (in.X < -89.f) in.X += 360.f;

		// in.Y = fmodf(in.Y, 360.0f);
		while (in.Y > 180)in.Y -= 360;
		while (in.Y < -180)in.Y += 360;
		in.Z = 0;
	}
	__forceinline void Clamp(FVector& Ang) {
		if (Ang.X < 0.f)
			Ang.X += 360.f;

		if (Ang.X > 360.f)
			Ang.X -= 360.f;

		if (Ang.Y < 0.f) Ang.Y += 360.f;
		if (Ang.Y > 360.f) Ang.Y -= 360.f;
		Ang.Z = 0.f;
	}
	FVector SmoothAim(FVector target, FVector delta_rotation, float smooth) {
		FVector diff = target - delta_rotation;
		normalize(diff);
		return delta_rotation + diff / smooth;
	}
	FVector CalcAngle(FVector src, FVector dst)
	{
		FVector angle;
		angle.X = -atan2f(dst.X - src.X, dst.Y - src.Y) / M_PI * 180.0f + 180.0f;
		angle.Y = asinf((dst.Z - src.Z) / src.Distance(dst)) * 180.0f / M_PI;
		angle.Z = 0.0f;

		return angle;
	}
	void NormalizeAngles(FVector& angle)
	{
		while (angle.X > 89.0f)
			angle.X -= 180.f;

		while (angle.X < -89.0f)
			angle.X += 180.f;

		while (angle.Y > 180.f)
			angle.Y -= 360.f;

		while (angle.Y < -180.f)
			angle.Y += 360.f;
	}
	FVector CalcAngleBackSideRotation(FVector src, FVector dst)
	{
		FVector angle;
		FVector delta = FVector((src.X - dst.X), (src.Y - dst.Y), (src.Z - dst.Z));

		double hyp = sqrtf(delta.X * delta.X + delta.Y * delta.Y);

		angle.X = atanf(delta.Z / hyp) * (180.0f / hyp);
		angle.Y = atanf(delta.Y / delta.X) * (180.0f / M_PI);
		angle.Z = 0;
		if (delta.X >= 0.0) angle.Y += 180.0f;

		return angle;
	}
	float GetFov(const FVector viewAngle, const FVector aimAngle)
	{
		FVector Delta = FVector(aimAngle.X - viewAngle.X, aimAngle.Y - viewAngle.Y, aimAngle.Z - viewAngle.Z);
		NormalizeAngles(Delta);
		return sqrt(pow(Delta.X, 2.0f) + pow(Delta.Y, 2.0f));
	}
	FVector RCS(FVector Target, FVector Camera_rotation, float SmoothFactor, FVector control_rot) {
		FVector ConvertRotation = Camera_rotation;
		normalize(ConvertRotation);
		FVector DeltaRotation = ConvertRotation - control_rot;
		normalize(DeltaRotation);

		ConvertRotation = Target - (DeltaRotation * SmoothFactor);
		normalize(ConvertRotation);

		FVector Smoothed = SmoothAim(Camera_rotation, ConvertRotation, SmoothFactor);
		Smoothed -= (DeltaRotation / SmoothFactor);
		Clamp(Smoothed);
		return Smoothed;
	}
	float CalculateDistance(int p1x, int p1y, int p2x, int p2y)
	{
		float diffY = p1y - p2y;
		float diffX = p1x - p2x;
		return sqrt((diffY * diffY) + (diffX * diffX));
	}

}
class FLinearColor
{
public:
	float R, G, B, A;
};
struct FVector2D
{
	float X, Y;
	FVector2D() : X(0), Y(0) {}

	FVector2D(float X, float Y) : X(X), Y(Y) {}
	float Size() const;

	FVector2D operator + (const FVector2D& other) const { return FVector2D(X + other.X, Y + other.Y); }

	FVector2D operator- (const FVector2D& other) const { return FVector2D(X - other.X, Y - other.Y); }

	FVector2D operator* (float scalar) const { return FVector2D(X * scalar, Y * scalar); }

	FVector2D& operator=  (const FVector2D& other) { X = other.X; Y = other.Y; return *this; }

	FVector2D& operator+= (const FVector2D& other) { X += other.X; Y += other.Y; return *this; }

	FVector2D& operator-= (const FVector2D& other) { X -= other.X; Y -= other.Y; return *this; }

	FVector2D& operator*= (const float other) { X *= other; Y *= other; return *this; }

	friend bool operator==(const FVector2D& one, const FVector2D& two) { return one.X == two.X && one.Y == two.Y; }

	friend bool operator!=(const FVector2D& one, const FVector2D& two) { return !(one == two); }

	friend bool operator>(const FVector2D& one, const FVector2D& two) { return one.X > two.X && one.Y > two.Y; }

	friend bool operator<(const FVector2D& one, const FVector2D& two) { return one.X < two.X && one.Y < two.Y; }
	bool IsValid()
	{
		if (X == 0 || Y == 0)
			return false;
		else
			return true;
	}
};
struct alignas(16) FPlane : public FVector {
	float W;
};
enum class EAresAlliance : uint8_t {
	Alliance_Ally = 0,
	Alliance_Enemy = 1,
	Alliance_Neutral = 2,
	Alliance_Any = 3,
	Alliance_Count = 4,
	Alliance_MAX = 5
};
enum class EAresOutlineMode : uint8_t {
	None = 0,
	Outline = 1,
	Block = 2,
	Enemy = 3,
	AlwaysOutline = 4,
	AlwaysEnemy = 5,
	EAresOutlineMode_MAX = 6
};
struct FMatrix {

	struct FPlane XPlane;
	struct FPlane YPlane;
	struct FPlane ZPlane;
	struct FPlane WPlane;

};

static FMatrix ToMatrix(FVector rot) {
	FVector origin = FVector{};
	float radPitch = (rot.X * float(M_PI) / 180.f);
	float radYaw = (rot.Y * float(M_PI) / 180.f);
	float radRoll = (rot.Z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	FMatrix matrix;
	matrix.XPlane.X = CP * CY;
	matrix.XPlane.Y = CP * SY;
	matrix.XPlane.Z = SP;
	matrix.XPlane.W = 0.f;

	matrix.YPlane.X = SR * SP * CY - CR * SY;
	matrix.YPlane.Y = SR * SP * SY + CR * CY;
	matrix.YPlane.Z = -SR * CP;
	matrix.YPlane.W = 0.f;

	matrix.ZPlane.X = -(CR * SP * CY + SR * SY);
	matrix.ZPlane.Y = CY * SR - CR * SP * SY;
	matrix.ZPlane.Z = CR * CP;
	matrix.ZPlane.W = 0.f;

	matrix.WPlane.X = origin.X;
	matrix.WPlane.Y = origin.Y;
	matrix.WPlane.Z = origin.Z;
	matrix.WPlane.W = 1.f;

	return matrix;
}
template<class T>
struct TArray
{
	friend class FString;

public:
	TArray()
	{
		Data = nullptr;
		Count = Max = 0;
	}

	TArray(T* data, int32_t count, int32_t max)
		: Data(data),
		Count(count),
		Max(max)
	{
	}

	int Num() const
	{
		return Count;
	}

	T& operator[](int i)
	{
		return Data[i];
	}

	const T& operator[](int i) const
	{
		return Data[i];
	}

	bool IsValidIndex(int i) const
	{
		return i < Num();
	}
	bool IsEmpty() const
	{
		return Num() == 0;
	}



private:
	T* Data;
	int32_t Count;
	int32_t Max;
};
class FString : public TArray<wchar_t>
{
public:
	inline FString()
	{
	};

	
	FString(const wchar_t* other)
	{
		Max = Count = *other ? static_cast<int>(std::wcslen(other)) + 1 : 0;

		if (Count)
		{
			Data = const_cast<wchar_t*>(other);
		}
	};
	FString(const wchar_t* other, int count)
	{
		Data = const_cast<wchar_t*>(other);;
		Max = Count = count;
	};

	inline bool IsValid() const
	{
		return Data != nullptr;
	}

	inline const wchar_t* wide() const
	{
		return Data;
	}
	const wchar_t* c_str() const
	{
		return this->Data;
	}
	int multi(char* name, int size) const
	{
		return WideCharToMultiByte(CP_UTF8, 0, Data, Count, name, size, nullptr, nullptr) - 1;
	}

	std::string ToString() const
	{
		auto length = std::wcslen(Data);

		std::string str(length, '\0');

		std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

		return str;
	}
};