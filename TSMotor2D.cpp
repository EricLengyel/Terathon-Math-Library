//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSMotor2D.h"


using namespace Terathon;


alignas(16) const ConstMotor2D Motor2D::identity = {0.0F, 0.0F, 0.0F, 1.0F};


Vector2D Motor2D::GetDirectionX(void) const
{
	return (Vector2D(1.0F - z * z * 2.0F, z * w * 2.0F));
}

Vector2D Motor2D::GetDirectionY(void) const
{
	return (Vector2D(z * w * -2.0F, 1.0F - z * z * 2.0F));
}

Point2D Motor2D::GetPosition(void) const
{
	return (Point2D((x * z + y * w) * 2.0F, (y * z - x * w) * 2.0F));
}

Transform2D Motor2D::GetTransformMatrix(void) const
{
	return (Transform2D(1.0F - z * z * 2.0F, z * w * -2.0F, (x * z + y * w) * 2.0F,
	                     z * w * 2.0F, 1.0F - z * z * 2.0F, (y * z - x * w) * 2.0F));
}

Transform2D Motor2D::GetInverseTransformMatrix(void) const
{
	return (Transform2D(1.0F - z * z * 2.0F,  z * w * 2.0F, (x * z - y * w) * 2.0F,
	                    z * w * -2.0F, 1.0F - z * z * 2.0F, (y * z + x * w) * 2.0F));
}

void Motor2D::GetTransformMatrices(Transform2D *M, Transform2D *Minv) const
{
	float xz = x * z * 2.0F;
	float yz = y * z * 2.0F;
	float xw = x * w * 2.0F;
	float yw = y * w * 2.0F;
	float zw = z * w * 2.0F;
	float z2 = 1.0F - z * z * 2.0F;

	M->Set(z2, -zw, xz + yw, zw, z2, yz - xw);
	Minv->Set(z2, zw, xz - yw, -zw, z2, yz + xw);
}

Motor2D& Motor2D::SetTransformMatrix(const Transform2D& M)
{
	float m00 = M(0,0);
	if (m00 < 1.0F)
	{
		z = Sqrt(0.5F - m00 * 0.5F);
		w = M(1,0) * 0.5F / z;

		float m02 = M(0,2) * 0.5F;
		float m12 = M(1,2) * 0.5F;

		x = z * m02 - w * m12;
		y = w * m02 + z * m12;
	}
	else
	{
		x = M(1,2) * -0.5F;
		y = M(0,2) * 0.5F;
		z = 0.0F;
		w = 1.0F;
	}

	return (*this);
}


Motor2D Terathon::operator *(const Motor2D& a, const Motor2D& b)
{
	return (Motor2D(a.x * b.w + b.x * a.w + a.y * b.z - a.z * b.y, a.y * b.w + b.y * a.w + a.z * b.x - a.x * b.z, a.z * b.w + a.w * b.z, a.w * b.w - a.z * b.z));
}

Vector2D Terathon::Transform(const Vector2D& v, const Motor2D& Q)
{
	float z2 = 1.0F - Q.z * Q.z * 2.0F;
	float zw = Q.z * Q.w * 2.0F;
	return (Vector2D(v.x * z2 - v.y * zw, v.y * z2 + v.x * zw));
}

FlatPoint2D Terathon::Transform(const FlatPoint2D& p, const Motor2D& Q)
{
	float z2 = 1.0F - Q.z * Q.z * 2.0F;
	float zw = Q.z * Q.w * 2.0F;
	float pz = p.z * 2.0F;
	return (FlatPoint2D(p.x * z2 - p.y * zw + (Q.x * Q.z + Q.y * Q.w) * pz, p.y * z2 + p.x * zw + (Q.y * Q.z - Q.x * Q.w) * pz, p.z));
}

Point2D Terathon::Transform(const Point2D& p, const Motor2D& Q)
{
	float z2 = 1.0F - Q.z * Q.z * 2.0F;
	float zw = Q.z * Q.w * 2.0F;
	return (Point2D(p.x * z2 - p.y * zw + (Q.x * Q.z + Q.y * Q.w) * 2.0F, p.y * z2 + p.x * zw + (Q.y * Q.z - Q.x * Q.w) * 2.0F));
}

Line2D Terathon::Transform(const Line2D& g, const Motor2D& Q)
{
	float z2 = 1.0F - Q.z * Q.z * 2.0F;
	float zw = Q.z * Q.w * 2.0F;
	return (Line2D(g.x * z2 - g.y * zw, g.y * z2 + g.x * zw, g.z + ((Q.x * Q.z - Q.y * Q.w) * g.x + (Q.y * Q.z + Q.x * Q.w) * g.y) * 2.0F));
}
