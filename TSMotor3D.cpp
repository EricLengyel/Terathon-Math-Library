//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSMotor3D.h"


using namespace Terathon;


alignas(32) const ConstMotor3D Motor3D::identity = {0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F};


Vector3D Motor3D::GetDirectionX(void) const
{
	float A00 = 1.0F - (v.y * v.y + v.z * v.z) * 2.0F;
	float A01 = v.x * v.y;
	float A02 = v.z * v.x;
	float B01 = v.z * v.w;
	float B20 = v.y * v.w;

	return (Vector3D(A00, (A01 + B01) * 2.0F, (A02 - B20) * 2.0F));
}

Vector3D Motor3D::GetDirectionY(void) const
{
	float A11 = 1.0F - (v.z * v.z + v.x * v.x) * 2.0F;
	float A01 = v.x * v.y;
	float A12 = v.y * v.z;
	float B01 = v.z * v.w;
	float B12 = v.x * v.w;

	return (Vector3D((A01 - B01) * 2.0F, A11, (A12 + B12) * 2.0F));
}

Vector3D Motor3D::GetDirectionZ(void) const
{
	float A22 = 1.0F - (v.x * v.x + v.y * v.y) * 2.0F;
	float A02 = v.z * v.x;
	float A12 = v.y * v.z;
	float B20 = v.y * v.w;
	float B12 = v.x * v.w;

	return (Vector3D((A02 + B20) * 2.0F, (A12 - B12) * 2.0F, A22));
}

Point3D Motor3D::GetPosition(void) const
{
	float A03 = v.y * m.z - v.z * m.y;
	float A13 = v.z * m.x - v.x * m.z;
	float A23 = v.x * m.y - v.y * m.x;
	float B03 = m.x * v.w - v.x * m.w;
	float B13 = m.y * v.w - v.y * m.w;
	float B23 = m.z * v.w - v.z * m.w;

	return (Point3D((A03 + B03) * 2.0F, (A13 + B13) * 2.0F, (A23 + B23) * 2.0F));
}

Transform3D Motor3D::GetTransformMatrix(void) const
{
	float vx2 = v.x * v.x;
	float vy2 = v.y * v.y;
	float vz2 = v.z * v.z;

	float A00 = 1.0F - (vy2 + vz2) * 2.0F;
	float A11 = 1.0F - (vz2 + vx2) * 2.0F;
	float A22 = 1.0F - (vx2 + vy2) * 2.0F;
	float A01 = v.x * v.y;
	float A02 = v.z * v.x;
	float A12 = v.y * v.z;
	float A03 = v.y * m.z - v.z * m.y;
	float A13 = v.z * m.x - v.x * m.z;
	float A23 = v.x * m.y - v.y * m.x;

	float B01 = v.z * v.w;
	float B20 = v.y * v.w;
	float B12 = v.x * v.w;
	float B03 = m.x * v.w - v.x * m.w;
	float B13 = m.y * v.w - v.y * m.w;
	float B23 = m.z * v.w - v.z * m.w;

	return (Transform3D(       A00,         (A01 - B01) * 2.0F, (A02 + B20) * 2.0F, (A03 + B03) * 2.0F,
	                    (A01 + B01) * 2.0F,        A11,         (A12 - B12) * 2.0F, (A13 + B13) * 2.0F,
	                    (A02 - B20) * 2.0F, (A12 + B12) * 2.0F,        A22,         (A23 + B23) * 2.0F));
}

Transform3D Motor3D::GetInverseTransformMatrix(void) const
{
	float vx2 = v.x * v.x;
	float vy2 = v.y * v.y;
	float vz2 = v.z * v.z;

	float A00 = 1.0F - (vy2 + vz2) * 2.0F;
	float A11 = 1.0F - (vz2 + vx2) * 2.0F;
	float A22 = 1.0F - (vx2 + vy2) * 2.0F;
	float A01 = v.x * v.y;
	float A02 = v.z * v.x;
	float A12 = v.y * v.z;
	float A03 = v.y * m.z - v.z * m.y;
	float A13 = v.z * m.x - v.x * m.z;
	float A23 = v.x * m.y - v.y * m.x;

	float B01 = v.z * v.w;
	float B20 = v.y * v.w;
	float B12 = v.x * v.w;
	float B03 = m.x * v.w - v.x * m.w;
	float B13 = m.y * v.w - v.y * m.w;
	float B23 = m.z * v.w - v.z * m.w;

	return (Transform3D(       A00,         (A01 + B01) * 2.0F, (A02 - B20) * 2.0F, (A03 - B03) * 2.0F,
	                    (A01 - B01) * 2.0F,        A11,         (A12 + B12) * 2.0F, (A13 - B13) * 2.0F,
	                    (A02 + B20) * 2.0F, (A12 - B12) * 2.0F,        A22,         (A23 - B23) * 2.0F));
}

void Motor3D::GetTransformMatrices(Transform3D *M, Transform3D *Minv) const
{
	float vx2 = v.x * v.x;
	float vy2 = v.y * v.y;
	float vz2 = v.z * v.z;

	float A00 = 1.0F - (vy2 + vz2) * 2.0F;
	float A11 = 1.0F - (vz2 + vx2) * 2.0F;
	float A22 = 1.0F - (vx2 + vy2) * 2.0F;
	float A01 = v.x * v.y;
	float A02 = v.z * v.x;
	float A12 = v.y * v.z;
	float A03 = v.y * m.z - v.z * m.y;
	float A13 = v.z * m.x - v.x * m.z;
	float A23 = v.x * m.y - v.y * m.x;

	float B01 = v.z * v.w;
	float B20 = v.y * v.w;
	float B12 = v.x * v.w;
	float B03 = m.x * v.w - v.x * m.w;
	float B13 = m.y * v.w - v.y * m.w;
	float B23 = m.z * v.w - v.z * m.w;

	   M->Set(       A00,         (A01 - B01) * 2.0F, (A02 + B20) * 2.0F, (A03 + B03) * 2.0F,
	          (A01 + B01) * 2.0F,        A11,         (A12 - B12) * 2.0F, (A13 + B13) * 2.0F,
	          (A02 - B20) * 2.0F, (A12 + B12) * 2.0F,        A22,         (A23 + B23) * 2.0F);

	Minv->Set(       A00,         (A01 + B01) * 2.0F, (A02 - B20) * 2.0F, (A03 - B03) * 2.0F,
	          (A01 - B01) * 2.0F,        A11,         (A12 + B12) * 2.0F, (A13 - B13) * 2.0F,
	          (A02 + B20) * 2.0F, (A12 - B12) * 2.0F,        A22,         (A23 - B23) * 2.0F);
}

Motor3D& Motor3D::SetTransformMatrix(const Transform3D& M)
{
	v.SetRotationMatrix(M);

	float tx = M(0,3) * 0.5F;
	float ty = M(1,3) * 0.5F;
	float tz = M(2,3) * 0.5F;

	m.x =  v.w * tx + v.z * ty - v.y * tz;
	m.y =  v.w * ty + v.x * tz - v.z * tx;
	m.z =  v.w * tz + v.y * tx - v.x * ty;
	m.w = -v.x * tx - v.y * ty - v.z * tz;

	return (*this);
}


Motor3D Terathon::operator *(const Motor3D& a, const Motor3D& b)
{
	return (Motor3D(a.v.w * b.v.x + a.v.x * b.v.w + a.v.y * b.v.z - a.v.z * b.v.y,
	                a.v.w * b.v.y + a.v.y * b.v.w + a.v.z * b.v.x - a.v.x * b.v.z,
	                a.v.w * b.v.z + a.v.z * b.v.w + a.v.x * b.v.y - a.v.y * b.v.x,
	                a.v.w * b.v.w - a.v.x * b.v.x - a.v.y * b.v.y - a.v.z * b.v.z,
	                a.m.w * b.v.x + a.m.x * b.v.w + a.m.y * b.v.z - a.m.z * b.v.y + b.m.w * a.v.x + b.m.x * a.v.w - b.m.y * a.v.z + b.m.z * a.v.y,
	                a.m.w * b.v.y - a.m.x * b.v.z + a.m.y * b.v.w + a.m.z * b.v.x + b.m.w * a.v.y + b.m.x * a.v.z + b.m.y * a.v.w - b.m.z * a.v.x,
	                a.m.w * b.v.z + a.m.x * b.v.y - a.m.y * b.v.x + a.m.z * b.v.w + b.m.w * a.v.z - b.m.x * a.v.y + b.m.y * a.v.x + b.m.z * a.v.w,
	                a.m.w * b.v.w - a.m.x * b.v.x - a.m.y * b.v.y - a.m.z * b.v.z + b.m.w * a.v.w - b.m.x * a.v.x - b.m.y * a.v.y - b.m.z * a.v.z));
}

Motor3D Terathon::operator *(const Motor3D& Q, const Quaternion& r)
{
	return (Motor3D(Q.v.w * r.x + Q.v.x * r.w + Q.v.y * r.z - Q.v.z * r.y,
	                Q.v.w * r.y - Q.v.x * r.z + Q.v.y * r.w + Q.v.z * r.x,
	                Q.v.w * r.z + Q.v.x * r.y - Q.v.y * r.x + Q.v.z * r.w,
	                Q.v.w * r.w - Q.v.x * r.x - Q.v.y * r.y - Q.v.z * r.z,
	                Q.m.w * r.x + Q.m.x * r.w + Q.m.y * r.z - Q.m.z * r.y,
	                Q.m.w * r.y - Q.m.x * r.z + Q.m.y * r.w + Q.m.z * r.x,
	                Q.m.w * r.z + Q.m.x * r.y - Q.m.y * r.x + Q.m.z * r.w,
	                Q.m.w * r.w - Q.m.x * r.x - Q.m.y * r.y - Q.m.z * r.z));
}

Motor3D Terathon::operator *(const Quaternion& r, const Motor3D& Q)
{
	return (Motor3D(r.w * Q.v.x + r.x * Q.v.w + r.y * Q.v.z - r.z * Q.v.y,
	                r.w * Q.v.y - r.x * Q.v.z + r.y * Q.v.w + r.z * Q.v.x,
	                r.w * Q.v.z + r.x * Q.v.y - r.y * Q.v.x + r.z * Q.v.w,
	                r.w * Q.v.w - r.x * Q.v.x - r.y * Q.v.y - r.z * Q.v.z,
	                r.w * Q.m.x + r.x * Q.m.w + r.y * Q.m.z - r.z * Q.m.y,
	                r.w * Q.m.y - r.x * Q.m.z + r.y * Q.m.w + r.z * Q.m.x,
	                r.w * Q.m.z + r.x * Q.m.y - r.y * Q.m.x + r.z * Q.m.w,
	                r.w * Q.m.w - r.x * Q.m.x - r.y * Q.m.y - r.z * Q.m.z));
}

Motor3D Terathon::Sqrt(const Motor3D& Q)
{
	float b = InverseSqrt(Q.v.w * 2.0F + 2.0F);
	float a = -Q.m.w * (b * b);

	return (Motor3D(Q.v.x * b, Q.v.y * b, Q.v.z * b, Q.v.w * b + b, (Q.v.x * a + Q.m.x) * b, (Q.v.y * a + Q.m.y) * b, (Q.v.z * a + Q.m.z) * b, Q.m.w * (b * 0.5F)));
}

FlatPoint3D Terathon::Transform(const FlatPoint3D& p, const Motor3D& Q)
{
	#ifdef TERATHON_SSE

		FlatPoint3D		result;

		vec_float q = VecLoadUnaligned(&p.x);
		vec_float v = VecLoadUnaligned(&Q.v.x);
		vec_float m = VecLoadUnaligned(&Q.m.x);
		vec_float qw = VecSmearW(q);
		vec_float vw = VecSmearW(v);
		vec_float mw = VecSmearW(m);

		vec_float a = VecCross3D(v, q) + m * qw;
		vec_float u = VecCross3D(v, a) + a * vw - v * (mw * qw);

		VecStore3D(q + (u + u), &result.x);
		result.w = p.w;
		return (result);

	#else

		Bivector3D a = (!Q.v.xyz ^ p.xyz) + Q.m.xyz * p.w;
		return (FlatPoint3D(p.xyz + ((Q.v.xyz ^ a) + !a * Q.v.w - !Q.v.xyz * (Q.m.w * p.w)) * 2.0F, p.w));

	#endif
}

Point3D Terathon::Transform(const Point3D& p, const Motor3D& Q)
{
	#ifdef TERATHON_SSE

		Point3D		result;

		vec_float q = VecLoadUnaligned(&p.x);
		vec_float v = VecLoadUnaligned(&Q.v.x);
		vec_float m = VecLoadUnaligned(&Q.m.x);
		vec_float vw = VecSmearW(v);
		vec_float mw = VecSmearW(m);

		vec_float a = VecCross3D(v, q) + m;
		vec_float u = VecCross3D(v, a) + a * vw - v * mw;

		VecStore3D(q + (u + u), &result.x);
		return (result);

	#else

		Bivector3D a = (!Q.v.xyz ^ p) + Q.m.xyz;
		return (p + ((Q.v.xyz ^ a) + !a * Q.v.w - !Q.v.xyz * Q.m.w) * 2.0F);

	#endif
}

Line3D Terathon::Transform(const Line3D& l, const Motor3D& Q)
{
	Line3D		result;

	Bivector3D a = !Q.v.xyz ^ l.v;
	result.v = l.v + ((Q.v.xyz ^ a) + !a * Q.v.w) * 2.0F;

	Vector3D b = Q.v.xyz ^ l.m;
	Vector3D c = Q.m.xyz ^ !l.v;
	Vector3D d = b + c;
	result.m = l.m + (a * Q.m.w + !d * Q.v.w + (!Q.v.xyz ^ d) + !(Q.m.xyz ^ a)) * 2.0F;

	return (result);
}

Plane3D Terathon::Transform(const Plane3D& g, const Motor3D& Q)
{
	Vector3D b = (Q.m.xyz ^ g.xyz) + !g.xyz * Q.m.w;
	float bv = b.x * Q.v.x + b.y * Q.v.y + b.z * Q.v.z;
	float mg = Q.m.x * g.x + Q.m.y * g.y + Q.m.z * g.z;

	Vector3D a = (Q.v.xyz ^ g.xyz) * 2.0F;
	return (Plane3D(g.xyz + ((!Q.v.xyz ^ a) + !a * Q.v.w), g.w + (bv - mg * Q.v.w) * 2.0F));
}
