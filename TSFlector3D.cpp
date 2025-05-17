//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSFlector3D.h"


using namespace Terathon;


Transform3D Flector3D::GetTransformMatrix(void) const
{
	float gx2 = g.x * g.x;
	float gy2 = g.y * g.y;
	float gz2 = g.z * g.z;

	float A00 = (gy2 + gz2) * 2.0F - 1.0F;
	float A11 = (gz2 + gx2) * 2.0F - 1.0F;
	float A22 = (gx2 + gy2) * 2.0F - 1.0F;
	float A01 = g.x * g.y * -2.0F;
	float A02 = g.z * g.x * -2.0F;
	float A12 = g.y * g.z * -2.0F;
	float A03 = p.x * p.w - g.x * g.w;
	float A13 = p.y * p.w - g.y * g.w;
	float A23 = p.z * p.w - g.z * g.w;

	float B01 = g.z * p.w * 2.0F;
	float B20 = g.y * p.w * 2.0F;
	float B12 = g.x * p.w * 2.0F;
	float B03 = g.y * p.z - g.z * p.y;
	float B13 = g.z * p.x - g.x * p.z;
	float B23 = g.x * p.y - g.y * p.x;

	return (Transform3D(   A00,    A01 + B01, A02 - B20, (A03 + B03) * 2.0F,
	                    A01 - B01,    A11,    A12 + B12, (A13 + B13) * 2.0F,
	                    A02 + B20, A12 - B12,    A22,    (A23 + B23) * 2.0F));
}

Transform3D Flector3D::GetInverseTransformMatrix(void) const
{
	float gx2 = g.x * g.x;
	float gy2 = g.y * g.y;
	float gz2 = g.z * g.z;

	float A00 = (gy2 + gz2) * 2.0F - 1.0F;
	float A11 = (gz2 + gx2) * 2.0F - 1.0F;
	float A22 = (gx2 + gy2) * 2.0F - 1.0F;
	float A01 = g.x * g.y * -2.0F;
	float A02 = g.z * g.x * -2.0F;
	float A12 = g.y * g.z * -2.0F;
	float A03 = p.x * p.w - g.x * g.w;
	float A13 = p.y * p.w - g.y * g.w;
	float A23 = p.z * p.w - g.z * g.w;

	float B01 = g.z * p.w * 2.0F;
	float B20 = g.y * p.w * 2.0F;
	float B12 = g.x * p.w * 2.0F;
	float B03 = g.y * p.z - g.z * p.y;
	float B13 = g.z * p.x - g.x * p.z;
	float B23 = g.x * p.y - g.y * p.x;

	return (Transform3D(   A00,    A01 - B01, A02 + B20, (A03 - B03) * 2.0F,
	                    A01 + B01,    A11,    A12 - B12, (A13 - B13) * 2.0F,
	                    A02 - B20, A12 + B12,    A22,    (A23 - B23) * 2.0F));
}

void Flector3D::GetTransformMatrices(Transform3D *M, Transform3D *Minv) const
{
	float gx2 = g.x * g.x;
	float gy2 = g.y * g.y;
	float gz2 = g.z * g.z;

	float A00 = (gy2 + gz2) * 2.0F - 1.0F;
	float A11 = (gz2 + gx2) * 2.0F - 1.0F;
	float A22 = (gx2 + gy2) * 2.0F - 1.0F;
	float A01 = g.x * g.y * -2.0F;
	float A02 = g.z * g.x * -2.0F;
	float A12 = g.y * g.z * -2.0F;
	float A03 = p.x * p.w - g.x * g.w;
	float A13 = p.y * p.w - g.y * g.w;
	float A23 = p.z * p.w - g.z * g.w;

	float B01 = g.z * p.w * 2.0F;
	float B20 = g.y * p.w * 2.0F;
	float B12 = g.x * p.w * 2.0F;
	float B03 = g.y * p.z - g.z * p.y;
	float B13 = g.z * p.x - g.x * p.z;
	float B23 = g.x * p.y - g.y * p.x;

	   M->Set(   A00,    A01 + B01, A02 - B20, (A03 + B03) * 2.0F,
	          A01 - B01,    A11,    A12 + B12, (A13 + B13) * 2.0F,
	          A02 + B20, A12 - B12,    A22,    (A23 + B23) * 2.0F);

	Minv->Set(   A00,    A01 - B01, A02 + B20, (A03 - B03) * 2.0F,
	          A01 + B01,    A11,    A12 - B12, (A13 - B13) * 2.0F,
	          A02 - B20, A12 + B12,    A22,    (A23 - B23) * 2.0F);
}

Flector3D& Flector3D::SetTransformMatrix(const Transform3D& M)
{
	float m00 = M(0,0);
	float m11 = M(1,1);
	float m22 = M(2,2);
	float sum = m00 + m11 + m22;

	if (sum < 0.0F)
	{
		p.w = Sqrt(1.0F - sum) * 0.5F;
		float f = -0.25F / p.w;

		g.x = (M(2,1) - M(1,2)) * f;
		g.y = (M(0,2) - M(2,0)) * f;
		g.z = (M(1,0) - M(0,1)) * f;
	}
	else if ((m00 < m11) && (m00 < m22))
	{
		g.x = Sqrt(1.0F - m00 + m11 + m22) * 0.5F;
		float f = -0.25F / g.x;

		g.y = (M(1,0) + M(0,1)) * f;
		g.z = (M(0,2) + M(2,0)) * f;
		p.w = (M(2,1) - M(1,2)) * f;
	}
	else if (m11 < m22)
	{
		g.y = Sqrt(1.0F - m11 + m22 + m00) * 0.5F;
		float f = -0.25F / g.y;

		g.x = (M(1,0) + M(0,1)) * f;
		g.z = (M(2,1) + M(1,2)) * f;
		p.w = (M(0,2) - M(2,0)) * f;
	}
	else
	{
		g.z = Sqrt(1.0F - m22 + m00 + m11) * 0.5F;
		float f = -0.25F / g.z;

		g.x = (M(0,2) + M(2,0)) * f;
		g.y = (M(2,1) + M(1,2)) * f;
		p.w = (M(1,0) - M(0,1)) * f;
	}

	float tx = M(0,3) * 0.5F;
	float ty = M(1,3) * 0.5F;
	float tz = M(2,3) * 0.5F;

	p.x =  p.w * tx + g.z * ty - g.y * tz;
	p.y =  p.w * ty + g.x * tz - g.z * tx;
	p.z =  p.w * tz + g.y * tx - g.x * ty;
	g.w = -g.x * tx - g.y * ty - g.z * tz;

	return (*this);
}


Motor3D Terathon::operator *(const Flector3D& a, const Flector3D& b)
{
	return (Motor3D(a.g.z * b.g.y - a.g.y * b.g.z - a.g.x * b.p.w - a.p.w * b.g.x,
	                a.g.x * b.g.z - a.g.z * b.g.x - a.g.y * b.p.w - a.p.w * b.g.y,
	                a.g.y * b.g.x - a.g.x * b.g.y - a.g.z * b.p.w - a.p.w * b.g.z,
	                a.g.x * b.g.x + a.g.y * b.g.y + a.g.z * b.g.z - a.p.w * b.p.w,
	                a.p.z * b.g.y - a.p.y * b.g.z + a.g.y * b.p.z - a.g.z * b.p.y + a.g.x * b.g.w - a.g.w * b.g.x + a.p.w * b.p.x - a.p.x * b.p.w,
	                a.p.x * b.g.z - a.p.z * b.g.x + a.g.z * b.p.x - a.g.x * b.p.z + a.g.y * b.g.w - a.g.w * b.g.y + a.p.w * b.p.y - a.p.y * b.p.w,
	                a.p.y * b.g.x - a.p.x * b.g.y + a.g.x * b.p.y - a.g.y * b.p.x + a.g.z * b.g.w - a.g.w * b.g.z + a.p.w * b.p.z - a.p.z * b.p.w,
	                a.p.x * b.g.x + a.p.y * b.g.y + a.p.z * b.g.z + a.p.w * b.g.w - a.g.x * b.p.x - a.g.y * b.p.y - a.g.z * b.p.z - a.g.w * b.p.w));
}

Flector3D Terathon::operator *(const Flector3D& a, const Motor3D& b)
{
	return (Flector3D(a.g.z * b.m.y - a.g.y * b.m.z + a.g.w * b.v.x - a.g.x * b.m.w + a.p.y * b.v.z - a.p.z * b.v.y + a.p.x * b.v.w - a.p.w * b.m.x,
	                  a.g.x * b.m.z - a.g.z * b.m.x + a.g.w * b.v.y - a.g.y * b.m.w + a.p.z * b.v.x - a.p.x * b.v.z + a.p.y * b.v.w - a.p.w * b.m.y,
	                  a.g.y * b.m.x - a.g.x * b.m.y + a.g.w * b.v.z - a.g.z * b.m.w + a.p.x * b.v.y - a.p.y * b.v.x + a.p.z * b.v.w - a.p.w * b.m.z,
	                  a.p.w * b.v.w - a.g.x * b.v.x - a.g.y * b.v.y - a.g.z * b.v.z,
	                  a.g.y * b.v.z - a.g.z * b.v.y + a.p.w * b.v.x + a.g.x * b.v.w,
	                  a.g.z * b.v.x - a.g.x * b.v.z + a.p.w * b.v.y + a.g.y * b.v.w,
	                  a.g.x * b.v.y - a.g.y * b.v.x + a.p.w * b.v.z + a.g.z * b.v.w,
	                  a.g.w * b.v.w + a.g.x * b.m.x + a.g.y * b.m.y + a.g.z * b.m.z - a.p.w * b.m.w - a.p.x * b.v.x - a.p.y * b.v.y - a.p.z * b.v.z));
}

Flector3D Terathon::operator *(const Motor3D& a, const Flector3D& b)
{
	return (Flector3D(b.g.z * a.m.y - b.g.y * a.m.z + b.g.w * a.v.x + b.g.x * a.m.w + b.p.z * a.v.y - b.p.y * a.v.z + b.p.x * a.v.w + b.p.w * a.m.x,
	                  b.g.x * a.m.z - b.g.z * a.m.x + b.g.w * a.v.y + b.g.y * a.m.w + b.p.x * a.v.z - b.p.z * a.v.x + b.p.y * a.v.w + b.p.w * a.m.y,
	                  b.g.y * a.m.x - b.g.x * a.m.y + b.g.w * a.v.z + b.g.z * a.m.w + b.p.y * a.v.x - b.p.x * a.v.y + b.p.z * a.v.w + b.p.w * a.m.z,
	                  b.p.w * a.v.w - b.g.x * a.v.x - b.g.y * a.v.y - b.g.z * a.v.z,
	                  b.g.z * a.v.y - b.g.y * a.v.z + b.p.w * a.v.x + b.g.x * a.v.w,
	                  b.g.x * a.v.z - b.g.z * a.v.x + b.p.w * a.v.y + b.g.y * a.v.w,
	                  b.g.y * a.v.x - b.g.x * a.v.y + b.p.w * a.v.z + b.g.z * a.v.w,
	                  b.g.w * a.v.w - b.g.x * a.m.x - b.g.y * a.m.y - b.g.z * a.m.z + b.p.w * a.m.w - b.p.x * a.v.x - b.p.y * a.v.y - b.p.z * a.v.z));
}

Flector3D Terathon::operator *(const Flector3D& F, const Quaternion& r)
{
	return (Flector3D(F.g.w * r.x + F.p.y * r.z - F.p.z * r.y + F.p.x * r.w,
	                  F.g.w * r.y + F.p.z * r.x - F.p.x * r.z + F.p.y * r.w,
	                  F.g.w * r.z + F.p.x * r.y - F.p.y * r.x + F.p.z * r.w,
	                  F.p.w * r.w - F.g.x * r.x - F.g.y * r.y - F.g.z * r.z,
	                  F.g.y * r.z - F.g.z * r.y + F.p.w * r.x + F.g.x * r.w,
	                  F.g.z * r.x - F.g.x * r.z + F.p.w * r.y + F.g.y * r.w,
	                  F.g.x * r.y - F.g.y * r.x + F.p.w * r.z + F.g.z * r.w,
	                  F.g.w * r.w - F.p.x * r.x - F.p.y * r.y - F.p.z * r.z));
}

Flector3D Terathon::operator *(const Quaternion& r, const Flector3D& F)
{
	return (Flector3D(F.g.w * r.x + F.p.z * r.y - F.p.y * r.z + F.p.x * r.w,
	                  F.g.w * r.y + F.p.x * r.z - F.p.z * r.x + F.p.y * r.w,
	                  F.g.w * r.z + F.p.y * r.x - F.p.x * r.y + F.p.z * r.w,
	                  F.p.w * r.w - F.g.x * r.x - F.g.y * r.y - F.g.z * r.z,
	                  F.g.z * r.y - F.g.y * r.z + F.p.w * r.x + F.g.x * r.w,
	                  F.g.x * r.z - F.g.z * r.x + F.p.w * r.y + F.g.y * r.w,
	                  F.g.y * r.x - F.g.x * r.y + F.p.w * r.z + F.g.z * r.w,
	                  F.g.w * r.w - F.p.x * r.x - F.p.y * r.y - F.p.z * r.z));
}

Vector3D Terathon::Transform(const Vector3D& v, const Flector3D& F)
{
	Bivector3D a = (!F.g.xyz ^ v) * 2.0F;
	return ((a ^ F.g.xyz) - !a * F.p.w - v);
}

FlatPoint3D Terathon::Transform(const FlatPoint3D& q, const Flector3D& F)
{
	Bivector3D a = (!F.g.xyz ^ q.xyz) - !F.p.xyz * q.w;
	return (FlatPoint3D(((a ^ F.g.xyz) - !a * F.p.w - !F.g.xyz * (F.g.w * q.w)) * 2.0F - q.xyz, q.w));
}

Point3D Terathon::Transform(const Point3D& q, const Flector3D& F)
{
	Bivector3D a = (!F.g.xyz ^ q.xyz) - !F.p.xyz;
	return (((a ^ F.g.xyz) - !a * F.p.w - !F.g.xyz * F.g.w) * 2.0F - q);
}

Line3D Terathon::Transform(const Line3D& l, const Flector3D& F)
{
	Line3D		result;

	Bivector3D Fglv = (!F.g.xyz ^ l.v) * 2.0F;
	result.v = (F.g.xyz ^ Fglv) + !Fglv * F.p.w + l.v;

	Vector3D Fplv = (!F.p.xyz ^ !l.v) * 2.0F;
	Vector3D Fglm = (F.g.xyz ^ l.m) * 2.0F;
	result.m = !(Fplv - Fglm) * F.p.w + Fglv * F.g.w + (F.p.xyz ^ !Fglv) + (!F.g.xyz ^ (Fplv - Fglm)) - l.m;

	return (result);
}

Plane3D Terathon::Transform(const Plane3D& h, const Flector3D& F)
{
	float hp = h.x * F.p.x + h.y * F.p.y + h.z * F.p.z;
	float hg = h.x * F.g.x + h.y * F.g.y + h.z * F.g.z;

	Vector3D Fgh = (F.g.xyz ^ h.xyz) * 2.0F;
	return (Plane3D((!F.g.xyz ^ Fgh) + !Fgh * F.p.w + h.xyz, (hg * F.g.w - hp * F.p.w - (h.xyz ^ !F.p.xyz ^ F.g.xyz)) * 2.0F - h.w));
}
