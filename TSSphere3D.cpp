//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSSphere3D.h"


using namespace Terathon;


const ConstSphere3D Sphere3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F};


Sphere3D Terathon::Container(const Dipole3D& d)
{
	return (Sphere3D(-d.v.x * d.v.x - d.v.y * d.v.y - d.v.z * d.v.z,
	                  d.v.y * d.m.z - d.v.z * d.m.y + d.v.x * d.p.w,
	                  d.v.z * d.m.x - d.v.x * d.m.z + d.v.y * d.p.w,
	                  d.v.x * d.m.y - d.v.y * d.m.x + d.v.z * d.p.w,
	                 -d.m.x * d.m.x - d.m.y * d.m.y - d.m.z * d.m.z - d.v.x * d.p.x - d.v.y * d.p.y - d.v.z * d.p.z));
}

Sphere3D Terathon::Container(const Circle3D& c)
{
	return (Sphere3D(-c.g.x * c.g.x - c.g.y * c.g.y - c.g.z * c.g.z,
	                  c.g.y * c.v.z - c.g.z * c.v.y - c.g.w * c.g.x,
	                  c.g.z * c.v.x - c.g.x * c.v.z - c.g.w * c.g.y,
	                  c.g.x * c.v.y - c.g.y * c.v.x - c.g.w * c.g.z,
	                  c.g.x * c.m.x + c.g.y * c.m.y + c.g.z * c.m.z - c.g.w * c.g.w));
}

Sphere3D Terathon::Wedge(const Round3D& a, const Circle3D& c)
{
	return (Sphere3D(a.x * c.g.x + a.y * c.g.y + a.z * c.g.z + a.w * c.g.w,
	                 a.z * c.v.y - a.y * c.v.z + a.w * c.m.x - a.u * c.g.x,
	                 a.x * c.v.z - a.z * c.v.x + a.w * c.m.y - a.u * c.g.y,
	                 a.y * c.v.x - a.x * c.v.y + a.w * c.m.z - a.u * c.g.z,
	                -a.x * c.m.x - a.y * c.m.y - a.z * c.m.z - a.u * c.g.w));
}

Sphere3D Terathon::Wedge(const Circle3D& c, const Round3D& a)
{
	return (Sphere3D(-a.x * c.g.x - a.y * c.g.y - a.z * c.g.z - a.w * c.g.w,
	                  a.y * c.v.z - a.z * c.v.y - a.w * c.m.x + a.u * c.g.x,
	                  a.z * c.v.x - a.x * c.v.z - a.w * c.m.y + a.u * c.g.y,
	                  a.x * c.v.y - a.y * c.v.x - a.w * c.m.z + a.u * c.g.z,
	                  a.x * c.m.x + a.y * c.m.y + a.z * c.m.z + a.u * c.g.w));
}

Sphere3D Terathon::Wedge(const Dipole3D& d, const Dipole3D& f)
{
	return (Sphere3D(-d.m.x * f.v.x - d.m.y * f.v.y - d.m.z * f.v.z - d.v.x * f.m.x - d.v.y * f.m.y - d.v.z * f.m.z,
	                  d.p.z * f.v.y - d.p.y * f.v.z + d.v.y * f.p.z - d.v.z * f.p.y + d.m.x * f.p.w + d.p.w * f.m.x,
	                  d.p.x * f.v.z - d.p.z * f.v.x + d.v.z * f.p.x - d.v.x * f.p.z + d.m.y * f.p.w + d.p.w * f.m.y,
	                  d.p.y * f.v.x - d.p.x * f.v.y + d.v.x * f.p.y - d.v.y * f.p.x + d.m.z * f.p.w + d.p.w * f.m.z,
	                 -d.m.x * f.p.x - d.m.y * f.p.y - d.m.z * f.p.z - d.p.x * f.m.x - d.p.y * f.m.y - d.p.z * f.m.z));
}

Circle3D Terathon::Antiwedge(const Sphere3D& s, const Sphere3D& t)
{
	return (Circle3D(s.u * t.x - s.x * t.u,
	                 s.u * t.y - s.y * t.u,
	                 s.u * t.z - s.z * t.u,
	                 s.u * t.w - s.w * t.u,

	                 s.z * t.y - s.y * t.z,
	                 s.x * t.z - s.z * t.x,
	                 s.y * t.x - s.x * t.y,

	                 s.x * t.w - s.w * t.x,
	                 s.y * t.w - s.w * t.y,
	                 s.z * t.w - s.w * t.z));
}

Circle3D Terathon::Antiwedge(const Sphere3D& s, const Plane3D& g)
{
	return (Circle3D(s.u * g.x, s.u * g.y, s.u * g.z, s.u * g.w,

	                 s.z * g.y - s.y * g.z,
	                 s.x * g.z - s.z * g.x,
	                 s.y * g.x - s.x * g.y,

	                 s.x * g.w - s.w * g.x,
	                 s.y * g.w - s.w * g.y,
	                 s.z * g.w - s.w * g.z));
}

Circle3D Terathon::Antiwedge(const Plane3D& g, const Sphere3D& s)
{
	return (Circle3D(-s.u * g.x, -s.u * g.y, -s.u * g.z, -s.u * g.w,

	                 s.y * g.z - s.z * g.y,
	                 s.z * g.x - s.x * g.z,
	                 s.x * g.y - s.y * g.x,

	                 s.w * g.x - s.x * g.w,
	                 s.w * g.y - s.y * g.w,
	                 s.w * g.z - s.z * g.w));
}

Dipole3D Terathon::Antiwedge(const Sphere3D& s, const Circle3D& c)
{
	return (Dipole3D(c.g.z * s.y - c.g.y * s.z + c.v.x * s.u,
	                 c.g.x * s.z - c.g.z * s.x + c.v.y * s.u,
	                 c.g.y * s.x - c.g.x * s.y + c.v.z * s.u,

	                 c.g.x * s.w - c.g.w * s.x + c.m.x * s.u,
	                 c.g.y * s.w - c.g.w * s.y + c.m.y * s.u,
	                 c.g.z * s.w - c.g.w * s.z + c.m.z * s.u,

	                 c.m.y * s.z - c.m.z * s.y + c.v.x * s.w,
	                 c.m.z * s.x - c.m.x * s.z + c.v.y * s.w,
	                 c.m.x * s.y - c.m.y * s.x + c.v.z * s.w,
	                -c.v.x * s.x - c.v.y * s.y - c.v.z * s.z));
}

Dipole3D Terathon::Antiwedge(const Sphere3D& s, const Line3D& l)
{
	return (Dipole3D(l.v.x * s.u, l.v.y * s.u, l.v.z * s.u,
	                 l.m.x * s.u, l.m.y * s.u, l.m.z * s.u,

	                 l.m.y * s.z - l.m.z * s.y + l.v.x * s.w,
	                 l.m.z * s.x - l.m.x * s.z + l.v.y * s.w,
	                 l.m.x * s.y - l.m.y * s.x + l.v.z * s.w,
	                -l.v.x * s.x - l.v.y * s.y - l.v.z * s.z));
}

Round3D Terathon::Antiwedge(const Sphere3D& s, const Dipole3D& d)
{
	return (Round3D(d.m.z * s.y - d.m.y * s.z + d.p.x * s.u - d.v.x * s.w,
	                d.m.x * s.z - d.m.z * s.x + d.p.y * s.u - d.v.y * s.w,
	                d.m.y * s.x - d.m.x * s.y + d.p.z * s.u - d.v.z * s.w,
	                d.v.x * s.x + d.v.y * s.y + d.v.z * s.z + d.p.w * s.u,
	               -d.p.x * s.x - d.p.y * s.y - d.p.z * s.z - d.p.w * s.w));
}

Round3D Terathon::Antiwedge(const Dipole3D& d, const Sphere3D& s)
{
	return (Round3D(d.m.y * s.z - d.m.z * s.y + d.v.x * s.w - d.p.x * s.u,
	                d.m.z * s.x - d.m.x * s.z + d.v.y * s.w - d.p.y * s.u,
	                d.m.x * s.y - d.m.y * s.x + d.v.z * s.w - d.p.z * s.u,
	               -d.v.x * s.x - d.v.y * s.y - d.v.z * s.z - d.p.w * s.u,
	                d.p.x * s.x + d.p.y * s.y + d.p.z * s.z + d.p.w * s.w));
}

Round3D Terathon::Antiwedge(const Sphere3D& s, const Vector4D& p)
{
	return (Round3D(p.x * s.u, p.y * s.u, p.z * s.u, p.w * s.u, -p.x * s.x - p.y * s.y - p.z * s.z - p.w * s.w));
}

Round3D Terathon::Antiwedge(const Vector4D& p, const Sphere3D& s)
{
	return (Round3D(-p.x * s.u, -p.y * s.u, -p.z * s.u, -p.w * s.u, p.x * s.x + p.y * s.y + p.z * s.z + p.w * s.w));
}

Round3D Terathon::Antiwedge(const Sphere3D& s, const Point3D& p)
{
	return (Round3D(p.x * s.u, p.y * s.u, p.z * s.u, s.u, -p.x * s.x - p.y * s.y - p.z * s.z - s.w));
}

Round3D Terathon::Antiwedge(const Point3D& p, const Sphere3D& s)
{
	return (Round3D(-p.x * s.u, -p.y * s.u, -p.z * s.u, -s.u, p.x * s.x + p.y * s.y + p.z * s.z + s.w));
}
