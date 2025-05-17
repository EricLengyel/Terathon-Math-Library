//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSFlector2D.h"


using namespace Terathon;


Transform2D Flector2D::GetTransformMatrix(void) const
{
	return (Transform2D(1.0F - x * x * 2.0F, x * y * -2.0F, (x * z + y * w) * -2.0F,
	                    x * y * -2.0F, 1.0F - y * y * 2.0F, (y * z - x * w) * -2.0F));
}

Transform2D Flector2D::GetInverseTransformMatrix(void) const
{
	return (Transform2D(1.0F - x * x * 2.0F, x * y * -2.0F, (x * z - y * w) * -2.0F,
	                    x * y * -2.0F, 1.0F - y * y * 2.0F, (y * z + x * w) * -2.0F));
}

void Flector2D::GetTransformMatrices(Transform2D *M, Transform2D *Minv) const
{
	float xy = x * y * -2.0F;
	float xz = x * z * -2.0F;
	float yz = y * z * -2.0F;
	float xw = x * w * -2.0F;
	float yw = y * w * -2.0F;
	float x2 = 1.0F - x * x * 2.0F;
	float y2 = 1.0F - y * y * 2.0F;

	M->Set(x2, xy, xz + yw, xy, y2, yz - xw);
	Minv->Set(x2, xy, xz - yw, xy, y2, yz + xw);
}

Flector2D& Flector2D::SetTransformMatrix(const Transform2D& M)
{
	float m00 = M(0,0);
	if (m00 < 1.0F)
	{
		x = Sqrt(0.5F - m00 * 0.5F);
		y = M(0,1) * -0.5F / x;

		float m02 = M(0,2) * -0.5F;
		float m12 = M(1,2) * -0.5F;

		z = x * m02 + y * m12;
		w = y * m02 - x * m12;
	}
	else
	{
		x = 0.0F;
		y = 1.0F;
		z = M(1,2) * -0.5F;
		w = M(0,2) * -0.5F;
	}

	return (*this);
}


Motor2D Terathon::operator *(const Flector2D& a, const Flector2D& b)
{
	return (Motor2D(a.z * b.y - a.y * b.z - a.x * b.w - b.x * a.w, a.x * b.z - a.z * b.x - a.y * b.w - b.y * a.w, a.y * b.x - a.x * b.y, a.x * b.x + a.y * b.y));
}

Flector2D Terathon::operator *(const Flector2D& a, const Motor2D& b)
{
	return (Flector2D(a.x * b.w + a.y * b.z, a.y * b.w - a.x * b.z, a.x * b.y - a.y * b.x + a.z * b.w + b.z * a.w, a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z));
}

Flector2D Terathon::operator *(const Motor2D& a, const Flector2D& b)
{
	return (Flector2D(a.w * b.x - a.z * b.y, a.w * b.y + a.z * b.x, a.x * b.y - a.y * b.x + a.z * b.w + b.z * a.w, a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z));
}

Vector2D Terathon::Transform(const Vector2D& v, const Flector2D& F)
{
	float xy = F.x * F.y * -2.0F;
	float x2 = 1.0F - F.x * F.x * 2.0F;
	float y2 = 1.0F - F.y * F.y * 2.0F;
	return (Vector2D(x2 * v.x + xy * v.y, xy * v.x + y2 * v.y));
}

FlatPoint2D Terathon::Transform(const FlatPoint2D& q, const Flector2D& F)
{
	float xy = F.x * F.y * -2.0F;
	float x2 = 1.0F - F.x * F.x * 2.0F;
	float y2 = 1.0F - F.y * F.y * 2.0F;
	float qz = q.z * -2.0F;
	return (FlatPoint2D(q.x * x2 + q.y * xy + (F.x * F.z + F.y * F.w) * qz, q.x * xy + q.y * y2 + (F.y * F.z - F.x * F.w) * qz, q.z));
}

Point2D Terathon::Transform(const Point2D& q, const Flector2D& F)
{
	float xy = F.x * F.y * -2.0F;
	float x2 = 1.0F - F.x * F.x * 2.0F;
	float y2 = 1.0F - F.y * F.y * 2.0F;
	return (Point2D(q.x * x2 + q.y * xy - (F.x * F.z + F.y * F.w) * 2.0F, q.x * xy + q.y * y2 - (F.y * F.z - F.x * F.w) * 2.0F));
}

Line2D Terathon::Transform(const Line2D& h, const Flector2D& F)
{
	float xy = F.x * F.y * -2.0F;
	float x2 = 1.0F - F.x * F.x * 2.0F;
	float y2 = 1.0F - F.y * F.y * 2.0F;
	return (Line2D(h.x * x2 + h.y * xy, h.x * xy + h.y * y2, h.z - ((F.x * F.z - F.y * F.w) * h.x + (F.y * F.z + F.x * F.w) * h.y) * 2.0F));
}
