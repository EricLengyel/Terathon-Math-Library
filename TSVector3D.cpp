//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSBivector3D.h"


using namespace Terathon;


alignas(16) const ConstVector3D Vector3D::zero = {0.0F, 0.0F, 0.0F};
alignas(16) const ConstPoint3D Origin3D::origin = {0.0F, 0.0F, 0.0F};
alignas(16) const Origin3D Point3D::origin = {};

alignas(16) const ConstVector3D Vector3D::x_unit = {1.0F, 0.0F, 0.0F};
alignas(16) const ConstVector3D Vector3D::y_unit = {0.0F, 1.0F, 0.0F};
alignas(16) const ConstVector3D Vector3D::z_unit = {0.0F, 0.0F, 1.0F};

alignas(16) const ConstVector3D Vector3D::minus_x_unit = {-1.0F, 0.0F, 0.0F};
alignas(16) const ConstVector3D Vector3D::minus_y_unit = {0.0F, -1.0F, 0.0F};
alignas(16) const ConstVector3D Vector3D::minus_z_unit = {0.0F, 0.0F, -1.0F};


Vector3D& Vector3D::RotateAboutX(float angle)
{
	Vector2D v = CosSin(angle);
	float ny = v.x * y - v.y * z;
	float nz = v.x * z + v.y * y;

	y = ny;
	z = nz;
	return (*this);
}

Vector3D& Vector3D::RotateAboutY(float angle)
{
	Vector2D v = CosSin(angle);
	float nx = v.x * x + v.y * z;
	float nz = v.x * z - v.y * x;

	x = nx;
	z = nz;
	return (*this);
}

Vector3D& Vector3D::RotateAboutZ(float angle)
{
	Vector2D v = CosSin(angle);
	float nx = v.x * x - v.y * y;
	float ny = v.x * y + v.y * x;

	x = nx;
	y = ny;
	return (*this);
}

Vector3D& Vector3D::RotateAboutAxis(float angle, const Bivector3D& axis)
{
	Vector2D v = CosSin(angle);
	float u = 1.0F - v.x;

	float nx = x * (v.x + u * axis.x * axis.x) + y * (u * axis.x * axis.y - v.y * axis.z) + z * (u * axis.x * axis.z + v.y * axis.y);
	float ny = x * (u * axis.x * axis.y + v.y * axis.z) + y * (v.x + u * axis.y * axis.y) + z * (u * axis.y * axis.z - v.y * axis.x);
	float nz = x * (u * axis.x * axis.z - v.y * axis.y) + y * (u * axis.y * axis.z + v.y * axis.x) + z * (v.x + u * axis.z * axis.z);

	x = nx;
	y = ny;
	z = nz;
	return (*this);
}
