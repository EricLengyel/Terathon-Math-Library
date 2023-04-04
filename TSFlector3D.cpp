//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSFlector3D.h"
#include "TSMotor3D.h"


using namespace Terathon;


Transform4D Flector4D::GetTransformMatrix(void) const
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

	return (Transform4D(   A00,    A01 + B01, A02 - B20, (A03 + B03) * 2.0F,
	                    A01 - B01,    A11,    A12 + B12, (A13 + B13) * 2.0F,
	                    A02 + B20, A12 - B12,    A22,    (A23 + B23) * 2.0F));
}

Transform4D Flector4D::GetInverseTransformMatrix(void) const
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

	return (Transform4D(   A00,    A01 - B01, A02 + B20, (A03 - B03) * 2.0F,
	                    A01 + B01,    A11,    A12 - B12, (A13 - B13) * 2.0F,
	                    A02 - B20, A12 + B12,    A22,    (A23 - B23) * 2.0F));
}

void Flector4D::GetTransformMatrices(Transform4D *M, Transform4D *Minv) const
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

Flector4D& Flector4D::SetTransformMatrix(const Transform4D& M)
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


Motor4D Terathon::operator *(const Flector4D& a, const Flector4D& b)
{
	return (Motor4D(a.g.z * b.g.y - a.g.y * b.g.z - a.g.x * b.p.w - a.p.w * b.g.x,
	                a.g.x * b.g.z - a.g.z * b.g.x - a.g.y * b.p.w - a.p.w * b.g.y,
					a.g.y * b.g.x - a.g.x * b.g.y - a.g.z * b.p.w - a.p.w * b.g.z,
					a.g.x * b.g.x + a.g.y * b.g.y + a.g.z * b.g.z - a.p.w * b.p.w,
	                a.p.z * b.g.y - a.p.y * b.g.z + a.g.y * b.p.z - a.g.z * b.p.y + a.g.x * b.g.w - a.g.w * b.g.x + a.p.w * b.p.x - a.p.x * b.p.w,
					a.p.x * b.g.z - a.p.z * b.g.x + a.g.z * b.p.x - a.g.x * b.p.z + a.g.y * b.g.w - a.g.w * b.g.y + a.p.w * b.p.y - a.p.y * b.p.w,
					a.p.y * b.g.x - a.p.x * b.g.y + a.g.x * b.p.y - a.g.y * b.p.x + a.g.z * b.g.w - a.g.w * b.g.z + a.p.w * b.p.z - a.p.z * b.p.w,
					a.p.x * b.g.x + a.p.y * b.g.y + a.p.z * b.g.z + a.p.w * b.g.w - a.g.x * b.p.x - a.g.y * b.p.y - a.g.z * b.p.z - a.g.w * b.p.w));
}

Flector4D Terathon::operator *(const Flector4D& a, const Motor4D& b)
{
	return (Flector4D(a.g.z * b.m.y - a.g.y * b.m.z + a.g.w * b.v.x - a.g.x * b.m.w + a.p.y * b.v.z - a.p.z * b.v.y + a.p.x * b.v.w - a.p.w * b.m.x,
	                  a.g.x * b.m.z - a.g.z * b.m.x + a.g.w * b.v.y - a.g.y * b.m.w + a.p.z * b.v.x - a.p.x * b.v.z + a.p.y * b.v.w - a.p.w * b.m.y,
					  a.g.y * b.m.x - a.g.x * b.m.y + a.g.w * b.v.z - a.g.z * b.m.w + a.p.x * b.v.y - a.p.y * b.v.x + a.p.z * b.v.w - a.p.w * b.m.z,
					  a.p.w * b.v.w - a.g.x * b.v.x - a.g.y * b.v.y - a.g.z * b.v.z,
					  a.g.y * b.v.z - a.g.z * b.v.y + a.p.w * b.v.x + a.g.x * b.v.w,
					  a.g.z * b.v.x - a.g.x * b.v.z + a.p.w * b.v.y + a.g.y * b.v.w,
					  a.g.x * b.v.y - a.g.y * b.v.x + a.p.w * b.v.z + a.g.z * b.v.w,
					  a.g.w * b.v.w + a.g.x * b.m.x + a.g.y * b.m.y + a.g.z * b.m.z - a.p.w * b.m.w - a.p.x * b.v.x - a.p.y * b.v.y - a.p.z * b.v.z));
}

Flector4D Terathon::operator *(const Motor4D& a, const Flector4D& b)
{
	return (Flector4D(b.g.z * a.m.y - b.g.y * a.m.z + b.g.w * a.v.x + b.g.x * a.m.w + b.p.z * a.v.y - b.p.y * a.v.z + b.p.x * a.v.w + b.p.w * a.m.x,
	                  b.g.x * a.m.z - b.g.z * a.m.x + b.g.w * a.v.y + b.g.y * a.m.w + b.p.x * a.v.z - b.p.z * a.v.x + b.p.y * a.v.w + b.p.w * a.m.y,
					  b.g.y * a.m.x - b.g.x * a.m.y + b.g.w * a.v.z + b.g.z * a.m.w + b.p.y * a.v.x - b.p.x * a.v.y + b.p.z * a.v.w + b.p.w * a.m.z,
					  b.p.w * a.v.w - b.g.x * a.v.x - b.g.y * a.v.y - b.g.z * a.v.z,
					  b.g.z * a.v.y - b.g.y * a.v.z + b.p.w * a.v.x + b.g.x * a.v.w,
					  b.g.x * a.v.z - b.g.z * a.v.x + b.p.w * a.v.y + b.g.y * a.v.w,
					  b.g.y * a.v.x - b.g.x * a.v.y + b.p.w * a.v.z + b.g.z * a.v.w,
					  b.g.w * a.v.w - b.g.x * a.m.x - b.g.y * a.m.y - b.g.z * a.m.z + b.p.w * a.m.w - b.p.x * a.v.x - b.p.y * a.v.y - b.p.z * a.v.z));
}

Vector3D Terathon::Transform(const Vector3D& v, const Flector4D& F)
{
	float pw2 = F.p.w * F.p.w;
	float gx2 = F.g.x * F.g.x;
	float gy2 = F.g.y * F.g.y;
	float gz2 = F.g.z * F.g.z;
	float gygz = F.g.y * F.g.z;
	float gzgx = F.g.z * F.g.x;
	float gxgy = F.g.x * F.g.y;
	float gxpw = F.g.x * F.p.w;
	float gypw = F.g.y * F.p.w;
	float gzpw = F.g.z * F.p.w;

	return (Vector3D(v.x + ((gzpw - gxgy) * v.y - (gzgx + gypw) * v.z - (gx2 + pw2) * v.x) * 2.0F,
	                 v.y + ((gxpw - gygz) * v.z - (gxgy + gzpw) * v.x - (gy2 + pw2) * v.y) * 2.0F,
	                 v.z + ((gypw - gzgx) * v.x - (gygz + gxpw) * v.y - (gz2 + pw2) * v.z) * 2.0F));
}

Bivector3D Terathon::Transform(const Bivector3D& v, const Flector4D& F)
{
	float pw2 = F.p.w * F.p.w;
	float gx2 = F.g.x * F.g.x;
	float gy2 = F.g.y * F.g.y;
	float gz2 = F.g.z * F.g.z;
	float gygz = F.g.y * F.g.z;
	float gzgx = F.g.z * F.g.x;
	float gxgy = F.g.x * F.g.y;
	float gxpw = F.g.x * F.p.w;
	float gypw = F.g.y * F.p.w;
	float gzpw = F.g.z * F.p.w;

	return (Bivector3D(v.x + ((gzpw - gxgy) * v.y - (gzgx + gypw) * v.z - (gx2 + pw2) * v.x) * 2.0F,
	                   v.y + ((gxpw - gygz) * v.z - (gxgy + gzpw) * v.x - (gy2 + pw2) * v.y) * 2.0F,
	                   v.z + ((gypw - gzgx) * v.x - (gygz + gxpw) * v.y - (gz2 + pw2) * v.z) * 2.0F));
}

Vector4D Terathon::Transform(const Vector4D& p, const Flector4D& F)
{
	float pw2 = F.p.w * F.p.w;
	float gx2 = F.g.x * F.g.x;
	float gy2 = F.g.y * F.g.y;
	float gz2 = F.g.z * F.g.z;
	float gygz = F.g.y * F.g.z;
	float gzgx = F.g.z * F.g.x;
	float gxgy = F.g.x * F.g.y;
	float gxpw = F.g.x * F.p.w;
	float gypw = F.g.y * F.p.w;
	float gzpw = F.g.z * F.p.w;

	return (Vector4D(p.x + ((gzpw - gxgy) * p.y - (gzgx + gypw) * p.z - (gx2 + pw2) * p.x + (F.p.x * F.p.w - F.g.x * F.g.w + F.g.y * F.p.z - F.g.z * F.p.y) * p.w) * 2.0F,
	                 p.y + ((gxpw - gygz) * p.z - (gxgy + gzpw) * p.x - (gy2 + pw2) * p.y + (F.p.y * F.p.w - F.g.y * F.g.w + F.g.z * F.p.x - F.g.x * F.p.z) * p.w) * 2.0F,
	                 p.z + ((gypw - gzgx) * p.x - (gygz + gxpw) * p.y - (gz2 + pw2) * p.z + (F.p.z * F.p.w - F.g.z * F.g.w + F.g.x * F.p.y - F.g.y * F.p.x) * p.w) * 2.0F,
	                 p.w));
}

Point3D Terathon::Transform(const Point3D& p, const Flector4D& F)
{
	float pw2 = F.p.w * F.p.w;
	float gx2 = F.g.x * F.g.x;
	float gy2 = F.g.y * F.g.y;
	float gz2 = F.g.z * F.g.z;
	float gygz = F.g.y * F.g.z;
	float gzgx = F.g.z * F.g.x;
	float gxgy = F.g.x * F.g.y;
	float gxpw = F.g.x * F.p.w;
	float gypw = F.g.y * F.p.w;
	float gzpw = F.g.z * F.p.w;

	return (Point3D(p.x + ((gzpw - gxgy) * p.y - (gzgx + gypw) * p.z - (gx2 + pw2) * p.x + (F.p.x * F.p.w - F.g.x * F.g.w + F.g.y * F.p.z - F.g.z * F.p.y)) * 2.0F,
	                p.y + ((gxpw - gygz) * p.z - (gxgy + gzpw) * p.x - (gy2 + pw2) * p.y + (F.p.y * F.p.w - F.g.y * F.g.w + F.g.z * F.p.x - F.g.x * F.p.z)) * 2.0F,
	                p.z + ((gypw - gzgx) * p.x - (gygz + gxpw) * p.y - (gz2 + pw2) * p.z + (F.p.z * F.p.w - F.g.z * F.g.w + F.g.x * F.p.y - F.g.y * F.p.x)) * 2.0F));
}

Line3D Terathon::Transform(const Line3D& l, const Flector4D& F)
{
	float pw2 = F.p.w * F.p.w;
	float gx2 = F.g.x * F.g.x;
	float gy2 = F.g.y * F.g.y;
	float gz2 = F.g.z * F.g.z;
	float gygz = F.g.y * F.g.z;
	float gzgx = F.g.z * F.g.x;
	float gxgy = F.g.x * F.g.y;
	float gxpw = F.g.x * F.p.w;
	float gypw = F.g.y * F.p.w;
	float gzpw = F.g.z * F.p.w;

	return (Line3D(l.v.x + ((gxgy - gzpw) * l.v.y + (gzgx + gypw) * l.v.z - (gy2 + gz2) * l.v.x) * 2.0F,
	               l.v.y + ((gygz - gxpw) * l.v.z + (gxgy + gzpw) * l.v.x - (gz2 + gx2) * l.v.y) * 2.0F,
	               l.v.z + ((gzgx - gypw) * l.v.x + (gygz + gxpw) * l.v.y - (gx2 + gy2) * l.v.z) * 2.0F,
	               l.m.x + ((F.g.x * F.p.y + F.g.y * F.p.x - F.p.z * F.p.w - F.g.z * F.g.w) * l.v.y + (F.g.x * F.p.z + F.g.z * F.p.x + F.p.y * F.p.w + F.g.y * F.g.w) * l.v.z - (F.g.y * F.p.y + F.g.z * F.p.z) * l.v.x * 2.0F + (gzpw - gxgy) * l.m.y - (gzgx + gypw) * l.m.z - (gx2 + pw2) * l.m.x) * 2.0F,
	               l.m.y + ((F.g.y * F.p.z + F.g.z * F.p.y - F.p.x * F.p.w - F.g.x * F.g.w) * l.v.z + (F.g.y * F.p.x + F.g.x * F.p.y + F.p.z * F.p.w + F.g.z * F.g.w) * l.v.x - (F.g.z * F.p.z + F.g.x * F.p.x) * l.v.y * 2.0F + (gxpw - gygz) * l.m.z - (gxgy + gzpw) * l.m.x - (gy2 + pw2) * l.m.y) * 2.0F,
	               l.m.z + ((F.g.z * F.p.x + F.g.x * F.p.z - F.p.y * F.p.w - F.g.y * F.g.w) * l.v.x + (F.g.z * F.p.y + F.g.y * F.p.z + F.p.x * F.p.w + F.g.x * F.g.w) * l.v.y - (F.g.x * F.p.x + F.g.y * F.p.y) * l.v.z * 2.0F + (gypw - gzgx) * l.m.x - (gygz + gxpw) * l.m.y - (gz2 + pw2) * l.m.z) * 2.0F));
}

Plane3D Terathon::Transform(const Plane3D& g, const Flector4D& F)
{
	float pw2 = F.p.w * F.p.w;
	float gx2 = F.g.x * F.g.x;
	float gy2 = F.g.y * F.g.y;
	float gz2 = F.g.z * F.g.z;
	float gygz = F.g.y * F.g.z;
	float gzgx = F.g.z * F.g.x;
	float gxgy = F.g.x * F.g.y;
	float gxpw = F.g.x * F.p.w;
	float gypw = F.g.y * F.p.w;
	float gzpw = F.g.z * F.p.w;

	return (Plane3D(g.x + ((gzpw - gxgy) * g.y - (gzgx + gypw) * g.z - (gx2 + pw2) * g.x) * 2.0F,
	                g.y + ((gxpw - gygz) * g.z - (gxgy + gzpw) * g.x - (gy2 + pw2) * g.y) * 2.0F,
	                g.z + ((gypw - gzgx) * g.x - (gygz + gxpw) * g.y - (gz2 + pw2) * g.z) * 2.0F,
	                g.w + ((F.p.x * F.p.w - F.g.x * F.g.w - F.g.y * F.p.z + F.g.z * F.p.y) * g.x +
	                       (F.p.y * F.p.w - F.g.y * F.g.w - F.g.z * F.p.x + F.g.x * F.p.z) * g.y +
	                       (F.p.z * F.p.w - F.g.z * F.g.w - F.g.x * F.p.y + F.g.y * F.p.x) * g.z) * 2.0F));
}
