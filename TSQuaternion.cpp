//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSQuaternion.h"


using namespace Terathon;


const ConstQuaternion Quaternion::identity = {0.0F, 0.0F, 0.0F, 1.0F};


Quaternion& Quaternion::operator *=(const Quaternion& q)
{
	float a = w * q.x + x * q.w + y * q.z - z * q.y;
	float b = w * q.y - x * q.z + y * q.w + z * q.x;
	float c = w * q.z + x * q.y - y * q.x + z * q.w;

	w = w * q.w - x * q.x - y * q.y - z * q.z;
	x = a;
	y = b;
	z = c;

	return (*this);
}

Quaternion& Quaternion::operator *=(const Bivector3D& v)
{
	float a = w * v.x + y * v.z - z * v.y;
	float b = w * v.y - x * v.z + z * v.x;
	float c = w * v.z + x * v.y - y * v.x;

	w = -x * v.x - y * v.y - z * v.z;
	x = a;
	y = b;
	z = c;

	return (*this);
}

Matrix3D Quaternion::GetRotationMatrix(void) const
{
	// See FGED1, Section 2.7.

	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;
	float xy = x * y;
	float zx = z * x;
	float yz = y * z;
	float wx = w * x;
	float wy = w * y;
	float wz = w * z;

	return (Matrix3D(1.0F - 2.0F * (y2 + z2), 2.0F * (xy - wz), 2.0F * (zx + wy),
					 2.0F * (xy + wz), 1.0F - 2.0F * (x2 + z2), 2.0F * (yz - wx),
					 2.0F * (zx - wy), 2.0F * (yz + wx), 1.0F - 2.0F * (x2 + y2)));
}

template <class matrix>
Quaternion& Quaternion::SetRotationMatrix(const matrix& M)
{
	// See FGED1, Section 2.7.

	float m00 = M(0,0);
	float m11 = M(1,1);
	float m22 = M(2,2);
	float sum = m00 + m11 + m22;

	if (sum > 0.0F)
	{
		w = Sqrt(sum + 1.0F) * 0.5F;
		float f = 0.25F / w;

		x = (M(2,1) - M(1,2)) * f;
		y = (M(0,2) - M(2,0)) * f;
		z = (M(1,0) - M(0,1)) * f;
	}
	else if ((m00 > m11) && (m00 > m22))
	{
		x = Sqrt(m00 - m11 - m22 + 1.0F) * 0.5F;
		float f = 0.25F / x;

		y = (M(1,0) + M(0,1)) * f;
		z = (M(0,2) + M(2,0)) * f;
		w = (M(2,1) - M(1,2)) * f;
	}
	else if (m11 > m22)
	{
		y = Sqrt(m11 - m22 - m00 + 1.0F) * 0.5F;
		float f = 0.25F / y;

		x = (M(1,0) + M(0,1)) * f;
		z = (M(2,1) + M(1,2)) * f;
		w = (M(0,2) - M(2,0)) * f;
	}
	else
	{
		z = Sqrt(m22 - m00 - m11 + 1.0F) * 0.5F;
		float f = 0.25F / z;

		x = (M(0,2) + M(2,0)) * f;
		y = (M(2,1) + M(1,2)) * f;
		w = (M(1,0) - M(0,1)) * f;
	}

	return (*this);
}

template Quaternion& Quaternion::SetRotationMatrix(const Matrix3D& M);
template Quaternion& Quaternion::SetRotationMatrix(const Transform4D& M);


Quaternion Terathon::operator *(const Quaternion& q1, const Quaternion& q2)
{
	return (Quaternion(q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
					   q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
					   q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
					   q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z));
}

Quaternion Terathon::operator *(const Quaternion& q, const Bivector3D& v)
{
	return (Quaternion(q.w * v.x + q.y * v.z - q.z * v.y,
					   q.w * v.y - q.x * v.z + q.z * v.x,
					   q.w * v.z + q.x * v.y - q.y * v.x,
					  -q.x * v.x - q.y * v.y - q.z * v.z));
}

Quaternion Terathon::Sqrt(const Quaternion& q)
{
	float f = InverseSqrt(q.w * 2.0F + 2.0F);
	return (Quaternion(q.x * f, q.y * f, q.z * f, q.w * f + f));
}

Vector3D Terathon::Transform(const Vector3D& v, const Quaternion& q)
{
	const Bivector3D& b = q.GetBivectorPart();
	return (v * (q.w * q.w - SquaredMag(b)) + Complement(b * ((v ^ b) * 2.0F) + (!b ^ v) * (q.w * 2.0F)));
}
