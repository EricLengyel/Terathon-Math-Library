//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSDipole3D.h"


using namespace Terathon;


const ConstDipole3D Dipole3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};


Round3D Terathon::Center(const Dipole3D& d)
{
	return (Round3D(d.v.y * d.m.z - d.v.z * d.m.y + d.p.x * d.p.w,
	                d.v.z * d.m.x - d.v.x * d.m.z + d.p.y * d.p.w,
	                d.v.x * d.m.y - d.v.y * d.m.x + d.p.z * d.p.w,
	                d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z,
	                d.p.w * d.p.w - d.v.x * d.p.x - d.v.y * d.p.y - d.v.z * d.p.z));
}

Point3D Terathon::FlatCenter(const Dipole3D& d)
{
	float f = 1.0F / (d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z);

	return (Point3D((d.v.y * d.m.z - d.v.z * d.m.y + d.p.x * d.p.w) * f,
	                (d.v.z * d.m.x - d.v.x * d.m.z + d.p.y * d.p.w) * f,
	                (d.v.x * d.m.y - d.v.y * d.m.x + d.p.z * d.p.w) * f));
}

Dipole3D Terathon::Partner(const Dipole3D& d)
{
	float v2 = -d.v.x * d.v.x - d.v.y * d.v.y - d.v.z * d.v.z;
	float f = d.m.x * d.m.x + d.m.y * d.m.y + d.m.z * d.m.z - d.p.w * d.p.w + d.v.x * d.p.x + d.v.y * d.p.y + d.v.z * d.p.z;

	return (Dipole3D(d.v.x * v2,
	                 d.v.y * v2,
	                 d.v.z * v2,

	                 d.m.x * v2,
	                 d.m.y * v2,
	                 d.m.z * v2,

	                 (d.m.y * d.v.z - d.m.z * d.v.y) * d.p.w + d.v.x * f,
	                 (d.m.z * d.v.x - d.m.x * d.v.z) * d.p.w + d.v.y * f,
	                 (d.m.x * d.v.y - d.m.y * d.v.x) * d.p.w + d.v.z * f,
	                 d.p.w * v2));
}

Dipole3D Terathon::Wedge(const Round3D& a, const Round3D& b)
{
	return (Dipole3D(a.w * b.x - a.x * b.w,
	                 a.w * b.y - a.y * b.w,
	                 a.w * b.z - a.z * b.w,
	                 
	                 a.y * b.z - a.z * b.y,
	                 a.z * b.x - a.x * b.z,
	                 a.x * b.y - a.y * b.x,
	                 
	                 a.x * b.u - a.u * b.x,
	                 a.y * b.u - a.u * b.y,
	                 a.z * b.u - a.u * b.z,
	                 a.w * b.u - a.u * b.w));
}

Plane3D Terathon::Wedge(const Vector4D& p, const Dipole3D& d)
{
	return (Plane3D(d.v.y * p.z - d.v.z * p.y + d.m.x * p.w,
	                d.v.z * p.x - d.v.x * p.z + d.m.y * p.w,
	                d.v.x * p.y - d.v.y * p.x + d.m.z * p.w,
	               -d.m.x * p.x - d.m.y * p.y - d.m.z * p.z));
}

Plane3D Terathon::Wedge(const Point3D& p, const Dipole3D& d)
{
	return (Plane3D(d.v.y * p.z - d.v.z * p.y + d.m.x,
	                d.v.z * p.x - d.v.x * p.z + d.m.y,
	                d.v.x * p.y - d.v.y * p.x + d.m.z,
	               -d.m.x * p.x - d.m.y * p.y - d.m.z * p.z));
}

Round3D Terathon::Antiwedge(const Plane3D& g, Dipole3D& d)
{
	return (Round3D(d.m.z * g.y - d.m.y * g.z - d.v.x * g.w,
	                d.m.x * g.z - d.m.z * g.x - d.v.y * g.w,
	                d.m.y * g.x - d.m.x * g.y - d.v.z * g.w,
	                d.v.x * g.x + d.v.y * g.y + d.v.z * g.z,
	               -d.p.x * g.x - d.p.y * g.y - d.p.z * g.z - d.p.w * g.w));
}

Round3D Terathon::Antiwedge(Dipole3D& d, const Plane3D& g)
{
	return (Round3D(d.m.y * g.z - d.m.z * g.y + d.v.x * g.w,
	                d.m.z * g.x - d.m.x * g.z + d.v.y * g.w,
	                d.m.x * g.y - d.m.y * g.x + d.v.z * g.w,
	               -d.v.x * g.x - d.v.y * g.y - d.v.z * g.z,
	                d.p.x * g.x + d.p.y * g.y + d.p.z * g.z + d.p.w * g.w));
}
