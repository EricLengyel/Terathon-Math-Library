//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSCircle3D.h"


using namespace Terathon;


const ConstCircle3D Circle3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};


inline Round3D Terathon::Center(const Circle3D& c)
{
	return (Round3D(c.g.y * c.v.z - c.g.z * c.v.y - c.g.x * c.g.w,
	                c.g.z * c.v.x - c.g.x * c.v.z - c.g.y * c.g.w,
	                c.g.x * c.v.y - c.g.y * c.v.x - c.g.z * c.g.w,
	                c.g.x * c.g.x + c.g.y * c.g.y + c.g.z * c.g.z,
	                c.v.x * c.v.x + c.v.y * c.v.y + c.v.z * c.v.z + c.g.x * c.m.x + c.g.y * c.m.y + c.g.z * c.m.z));
}

inline Point3D Terathon::FlatCenter(const Circle3D& c)
{
	float f = 1.0F / (c.g.x * c.g.x + c.g.y * c.g.y + c.g.z * c.g.z);

	return (Point3D((c.g.y * c.v.z - c.g.z * c.v.y - c.g.x * c.g.w) * f,
	                (c.g.z * c.v.x - c.g.x * c.v.z - c.g.y * c.g.w) * f,
	                (c.g.x * c.v.y - c.g.y * c.v.x - c.g.z * c.g.w) * f));
}

inline Circle3D Terathon::Partner(const Circle3D& c)
{
	float g2 = c.g.x * c.g.x + c.g.y * c.g.y + c.g.z * c.g.z;
	float f = c.g.w * c.g.w - c.v.x * c.v.x + c.v.y * c.v.y + c.v.z * c.v.z - c.g.x * c.m.x - c.g.y * c.m.y - c.g.z * c.m.z;

	return (Circle3D(c.g.x * g2,
	                 c.g.y * g2,
	                 c.g.z * g2,
	                 c.g.w * g2,

	                 c.v.x * g2,
	                 c.v.y * g2,
	                 c.v.z * g2,

	                 (c.v.y * c.g.z - c.v.z * c.g.y) * c.g.w + c.g.x * f,
	                 (c.v.z * c.g.x - c.v.x * c.g.z) * c.g.w + c.g.y * f,
	                 (c.v.x * c.g.y - c.v.y * c.g.x) * c.g.w + c.g.z * f));
}

inline Circle3D Terathon::Wedge(const Round3D& a, const Dipole3D& d)
{
	return (Circle3D(a.z * d.v.y - a.y * d.v.z + a.w * d.m.x,
	                 a.x * d.v.z - a.z * d.v.x + a.w * d.m.y,
	                 a.y * d.v.x - a.x * d.v.y + a.w * d.m.z,
	                -a.x * d.m.x - a.y * d.m.y - a.z * d.m.z,

	                 a.w * d.p.x - a.x * d.p.w + a.u * d.v.x,
	                 a.w * d.p.y - a.y * d.p.w + a.u * d.v.y,
	                 a.w * d.p.z - a.z * d.p.w + a.u * d.v.z,

	                 a.y * d.p.z - a.z * d.p.y + a.u * d.m.x,
	                 a.z * d.p.x - a.x * d.p.z + a.u * d.m.y,
	                 a.x * d.p.y - a.y * d.p.x + a.u * d.m.z));
}

Dipole3D Terathon::Antiwedge(const Circle3D& c, const Plane3D& g)
{
	return (Dipole3D(c.g.z * g.y - c.g.y * g.z,
	                 c.g.x * g.z - c.g.z * g.x,
	                 c.g.y * g.x - c.g.x * g.y,

	                 c.g.x * g.w - c.g.w * g.x,
	                 c.g.y * g.w - c.g.w * g.y,
	                 c.g.z * g.w - c.g.w * g.z,

	                 c.m.y * g.z - c.m.z * g.y + c.v.x * g.w,
	                 c.m.z * g.x - c.m.x * g.z + c.v.y * g.w,
	                 c.m.x * g.y - c.m.y * g.x + c.v.z * g.w,
	                -c.v.x * g.x - c.v.y * g.y - c.v.z * g.z));
}

Round3D Terathon::Antiwedge(const Circle3D& c, const Circle3D& o)
{
	return (Round3D(c.g.z * o.m.y - c.g.y * o.m.z + c.m.y * o.g.z - c.m.z * o.g.y + c.g.w * o.v.x + c.v.x * o.g.w,
	                c.g.x * o.m.z - c.g.z * o.m.x + c.m.z * o.g.x - c.m.x * o.g.z + c.g.w * o.v.y + c.v.y * o.g.w,
	                c.g.y * o.m.x - c.g.x * o.m.y + c.m.x * o.g.y - c.m.y * o.g.x + c.g.w * o.v.z + c.v.z * o.g.w,
	               -c.g.x * o.v.x - c.g.y * o.v.y - c.g.z * o.v.z - c.v.x * o.g.x - c.v.y * o.g.y - c.v.z * o.g.z,
	               -c.m.x * o.v.x - c.m.y * o.v.y - c.m.z * o.v.z - c.v.x * o.m.x - c.v.y * o.m.y - c.v.z * o.m.z));
}

Round3D Terathon::Antiwedge(const Circle3D& c, const Line3D& l)
{
	return (Round3D(c.g.z * l.m.y - c.g.y * l.m.z + c.g.w * l.v.x,
	                c.g.x * l.m.z - c.g.z * l.m.x + c.g.w * l.v.y,
	                c.g.y * l.m.x - c.g.x * l.m.y + c.g.w * l.v.z,
	               -c.g.x * l.v.x - c.g.y * l.v.y - c.g.z * l.v.z,
	               -c.m.x * l.v.x - c.m.y * l.v.y - c.m.z * l.v.z - c.v.x * l.m.x - c.v.y * l.m.y - c.v.z * l.m.z));
}
