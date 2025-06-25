//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSConformal3D.h"


using namespace Terathon;


alignas(32) const ConstRoundPoint3D RoundPoint3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F};
alignas(64) const ConstDipole3D Dipole3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};
alignas(64) const ConstCircle3D Circle3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};
alignas(32) const ConstSphere3D Sphere3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F};


// ==============================================
//	Center
// ==============================================

RoundPoint3D Terathon::Center(const Dipole3D& d)
{
	return (RoundPoint3D(d.v.y * d.m.z - d.v.z * d.m.y + d.v.x * d.p.w,
	                     d.v.z * d.m.x - d.v.x * d.m.z + d.v.y * d.p.w,
	                     d.v.x * d.m.y - d.v.y * d.m.x + d.v.z * d.p.w,
	                     d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z,
	                     d.p.w * d.p.w - d.v.x * d.p.x - d.v.y * d.p.y - d.v.z * d.p.z));
}

RoundPoint3D Terathon::Center(const Circle3D& c)
{
	return (RoundPoint3D(c.g.y * c.v.z - c.g.z * c.v.y - c.g.x * c.g.w,
	                     c.g.z * c.v.x - c.g.x * c.v.z - c.g.y * c.g.w,
	                     c.g.x * c.v.y - c.g.y * c.v.x - c.g.z * c.g.w,
	                     c.g.x * c.g.x + c.g.y * c.g.y + c.g.z * c.g.z,
	                     c.v.x * c.v.x + c.v.y * c.v.y + c.v.z * c.v.z + c.g.x * c.m.x + c.g.y * c.m.y + c.g.z * c.m.z));
}

// ==============================================
//	FlatCenter
// ==============================================

FlatPoint3D Terathon::FlatCenter(const Dipole3D& d)
{
	return (FlatPoint3D(d.v.y * d.m.z - d.v.z * d.m.y + d.v.x * d.p.w,
	                    d.v.z * d.m.x - d.v.x * d.m.z + d.v.y * d.p.w,
	                    d.v.x * d.m.y - d.v.y * d.m.x + d.v.z * d.p.w,
	                    d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z));
}

FlatPoint3D Terathon::FlatCenter(const Circle3D& c)
{
	return (FlatPoint3D(c.g.y * c.v.z - c.g.z * c.v.y - c.g.x * c.g.w,
	                    c.g.z * c.v.x - c.g.x * c.v.z - c.g.y * c.g.w,
	                    c.g.x * c.v.y - c.g.y * c.v.x - c.g.z * c.g.w,
	                    c.g.x * c.g.x + c.g.y * c.g.y + c.g.z * c.g.z));
}

// ==============================================
//	Container
// ==============================================

Sphere3D Terathon::Container(const Dipole3D& d)
{
	return (Sphere3D(d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z,
	                 d.v.z * d.m.y - d.v.y * d.m.z - d.v.x * d.p.w,
	                 d.v.x * d.m.z - d.v.z * d.m.x - d.v.y * d.p.w,
	                 d.v.y * d.m.x - d.v.x * d.m.y - d.v.z * d.p.w,
	                 d.m.x * d.m.x + d.m.y * d.m.y + d.m.z * d.m.z + d.v.x * d.p.x + d.v.y * d.p.y + d.v.z * d.p.z));
}

Sphere3D Terathon::Container(const Circle3D& c)
{
	return (Sphere3D(-c.g.x * c.g.x - c.g.y * c.g.y - c.g.z * c.g.z,
	                  c.g.y * c.v.z - c.g.z * c.v.y - c.g.w * c.g.x,
	                  c.g.z * c.v.x - c.g.x * c.v.z - c.g.w * c.g.y,
	                  c.g.x * c.v.y - c.g.y * c.v.x - c.g.w * c.g.z,
	                  c.g.x * c.m.x + c.g.y * c.m.y + c.g.z * c.m.z - c.g.w * c.g.w));
}

// ==============================================
//	Partner
// ==============================================

Dipole3D Terathon::Partner(const Dipole3D& d)
{
	float v2 = d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z;
	float f = d.p.w * d.p.w - d.m.x * d.m.x - d.m.y * d.m.y - d.m.z * d.m.z - d.v.x * d.p.x - d.v.y * d.p.y - d.v.z * d.p.z;

	return (Dipole3D(d.v.x * v2,
	                 d.v.y * v2,
	                 d.v.z * v2,

	                 d.m.x * v2,
	                 d.m.y * v2,
	                 d.m.z * v2,

	                 (d.m.z * d.v.y - d.m.y * d.v.z) * d.p.w + d.v.x * f,
	                 (d.m.x * d.v.z - d.m.z * d.v.x) * d.p.w + d.v.y * f,
	                 (d.m.y * d.v.x - d.m.x * d.v.y) * d.p.w + d.v.z * f,
	                 d.p.w * v2));
}

Circle3D Terathon::Partner(const Circle3D& c)
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

// ==============================================
//	Join
// ==============================================

Dipole3D Terathon::Wedge(const RoundPoint3D& a, const RoundPoint3D& b)
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

Line3D Terathon::Wedge(const FlatPoint3D& p, const RoundPoint3D& a)
{
	return (Line3D(p.x * a.w - p.w * a.x, p.y * a.w - p.w * a.y, p.z * a.w - p.w * a.z, p.z * a.y - p.y * a.z, p.x * a.z - p.z * a.x, p.y * a.x - p.x * a.y));
}

Line3D Terathon::Wedge(const Point3D& p, const RoundPoint3D& a)
{
	return (Line3D(p.x * a.w - a.x, p.y * a.w - a.y, p.z * a.w - a.z, p.z * a.y - p.y * a.z, p.x * a.z - p.z * a.x, p.y * a.x - p.x * a.y));
}

Circle3D Terathon::Wedge(const Dipole3D& d, const RoundPoint3D& a)
{
	return (Circle3D(d.v.y * a.z - d.v.z * a.y + d.m.x * a.w,
	                 d.v.z * a.x - d.v.x * a.z + d.m.y * a.w,
	                 d.v.x * a.y - d.v.y * a.x + d.m.z * a.w,
	                -d.m.x * a.x - d.m.y * a.y - d.m.z * a.z,

	                 d.p.x * a.w - d.p.w * a.x + d.v.x * a.u,
	                 d.p.y * a.w - d.p.w * a.y + d.v.y * a.u,
	                 d.p.z * a.w - d.p.w * a.z + d.v.z * a.u,

	                 d.p.z * a.y - d.p.y * a.z + d.m.x * a.u,
	                 d.p.x * a.z - d.p.z * a.x + d.m.y * a.u,
	                 d.p.y * a.x - d.p.x * a.y + d.m.z * a.u));
}

Plane3D Terathon::Wedge(const Line3D& l, const RoundPoint3D& a)
{
	return (Plane3D(l.v.z * a.y - l.v.y * a.z - l.m.x * a.w,
	                l.v.x * a.z - l.v.z * a.x - l.m.y * a.w,
	                l.v.y * a.x - l.v.x * a.y - l.m.z * a.w,
	                l.m.x * a.x + l.m.y * a.y + l.m.z * a.z));
}

Plane3D Terathon::Wedge(const RoundPoint3D& a, const Line3D& l)
{
	return (Plane3D(a.z * l.v.y - a.y * l.v.z + a.w * l.m.x,
	                a.x * l.v.z - a.z * l.v.x + a.w * l.m.y,
	                a.y * l.v.x - a.x * l.v.y + a.w * l.m.z,
	               -a.x * l.m.x - a.y * l.m.y - a.z * l.m.z));
}

Plane3D Terathon::Wedge(const Dipole3D& d, const FlatPoint3D& p)
{
	return (Plane3D(d.v.y * p.z - d.v.z * p.y + d.m.x * p.w,
	                d.v.z * p.x - d.v.x * p.z + d.m.y * p.w,
	                d.v.x * p.y - d.v.y * p.x + d.m.z * p.w,
	               -d.m.x * p.x - d.m.y * p.y - d.m.z * p.z));
}

Plane3D Terathon::Wedge(const Dipole3D& d, const Point3D& p)
{
	return (Plane3D(d.v.y * p.z - d.v.z * p.y + d.m.x,
	                d.v.z * p.x - d.v.x * p.z + d.m.y,
	                d.v.x * p.y - d.v.y * p.x + d.m.z,
	               -d.m.x * p.x - d.m.y * p.y - d.m.z * p.z));
}

Sphere3D Terathon::Wedge(const Circle3D& c, const RoundPoint3D& a)
{
	return (Sphere3D(-c.g.x * a.x - c.g.y * a.y - c.g.z * a.z - c.g.w * a.w,
	                  c.v.z * a.y - c.v.y * a.z - c.m.x * a.w + c.g.x * a.u,
	                  c.v.x * a.z - c.v.z * a.x - c.m.y * a.w + c.g.y * a.u,
	                  c.v.y * a.x - c.v.x * a.y - c.m.z * a.w + c.g.z * a.u,
	                  c.m.x * a.x + c.m.y * a.y + c.m.z * a.z + c.g.w * a.u));
}

Sphere3D Terathon::Wedge(const RoundPoint3D& a, const Circle3D& c)
{
	return (Sphere3D(a.x * c.g.x + a.y * c.g.y + a.z * c.g.z + a.w * c.g.w,
	                 a.z * c.v.y - a.y * c.v.z + a.w * c.m.x - a.u * c.g.x,
	                 a.x * c.v.z - a.z * c.v.x + a.w * c.m.y - a.u * c.g.y,
	                 a.y * c.v.x - a.x * c.v.y + a.w * c.m.z - a.u * c.g.z,
	                -a.x * c.m.x - a.y * c.m.y - a.z * c.m.z - a.u * c.g.w));
}

Sphere3D Terathon::Wedge(const Dipole3D& d, const Dipole3D& f)
{
	return (Sphere3D(-d.m.x * f.v.x - d.m.y * f.v.y - d.m.z * f.v.z - d.v.x * f.m.x - d.v.y * f.m.y - d.v.z * f.m.z,
	                  d.p.z * f.v.y - d.p.y * f.v.z + d.v.y * f.p.z - d.v.z * f.p.y + d.m.x * f.p.w + d.p.w * f.m.x,
	                  d.p.x * f.v.z - d.p.z * f.v.x + d.v.z * f.p.x - d.v.x * f.p.z + d.m.y * f.p.w + d.p.w * f.m.y,
	                  d.p.y * f.v.x - d.p.x * f.v.y + d.v.x * f.p.y - d.v.y * f.p.x + d.m.z * f.p.w + d.p.w * f.m.z,
	                 -d.m.x * f.p.x - d.m.y * f.p.y - d.m.z * f.p.z - d.p.x * f.m.x - d.p.y * f.m.y - d.p.z * f.m.z));
}

// ==============================================
//	Meet
// ==============================================

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
	return (Circle3D(-g.x * s.u, -g.y * s.u, -g.z * s.u, -g.w * s.u,

	                 g.z * s.y - g.y * s.z,
	                 g.x * s.z - g.z * s.x,
	                 g.y * s.x - g.x * s.y,

	                 g.x * s.w - g.w * s.x,
	                 g.y * s.w - g.w * s.y,
	                 g.z * s.w - g.w * s.z));
}

Dipole3D Terathon::Antiwedge(const Sphere3D& s, const Circle3D& c)
{
	return (Dipole3D(s.y * c.g.z - s.z * c.g.y + s.u * c.v.x,
	                 s.z * c.g.x - s.x * c.g.z + s.u * c.v.y,
	                 s.x * c.g.y - s.y * c.g.x + s.u * c.v.z,

	                 s.w * c.g.x - s.x * c.g.w + s.u * c.m.x,
	                 s.w * c.g.y - s.y * c.g.w + s.u * c.m.y,
	                 s.w * c.g.z - s.z * c.g.w + s.u * c.m.z,

	                 s.z * c.m.y - s.y * c.m.z + s.w * c.v.x,
	                 s.x * c.m.z - s.z * c.m.x + s.w * c.v.y,
	                 s.y * c.m.x - s.x * c.m.y + s.w * c.v.z,
	                -s.x * c.v.x - s.y * c.v.y - s.z * c.v.z));
}

Dipole3D Terathon::Antiwedge(const Plane3D& g, const Circle3D& c)
{
	return (Dipole3D(g.y * c.g.z - g.z * c.g.y,
	                 g.z * c.g.x - g.x * c.g.z,
	                 g.x * c.g.y - g.y * c.g.x,

	                 g.w * c.g.x - g.x * c.g.w,
	                 g.w * c.g.y - g.y * c.g.w,
	                 g.w * c.g.z - g.z * c.g.w,

	                 g.z * c.m.y - g.y * c.m.z + g.w * c.v.x,
	                 g.x * c.m.z - g.z * c.m.x + g.w * c.v.y,
	                 g.y * c.m.x - g.x * c.m.y + g.w * c.v.z,
	                -g.x * c.v.x - g.y * c.v.y - g.z * c.v.z));
}

Dipole3D Terathon::Antiwedge(const Sphere3D& s, const Line3D& l)
{
	return (Dipole3D(s.u * l.v.x, s.u * l.v.y, s.u * l.v.z,
	                 s.u * l.m.x, s.u * l.m.y, s.u * l.m.z,

	                 s.z * l.m.y - s.y * l.m.z + s.w * l.v.x,
	                 s.x * l.m.z - s.z * l.m.x + s.w * l.v.y,
	                 s.y * l.m.x - s.x * l.m.y + s.w * l.v.z,
	                -s.x * l.v.x - s.y * l.v.y - s.z * l.v.z));
}

RoundPoint3D Terathon::Antiwedge(const Circle3D& c, const Circle3D& o)
{
	return (RoundPoint3D(c.g.z * o.m.y - c.g.y * o.m.z + c.m.y * o.g.z - c.m.z * o.g.y + c.g.w * o.v.x + c.v.x * o.g.w,
	                     c.g.x * o.m.z - c.g.z * o.m.x + c.m.z * o.g.x - c.m.x * o.g.z + c.g.w * o.v.y + c.v.y * o.g.w,
	                     c.g.y * o.m.x - c.g.x * o.m.y + c.m.x * o.g.y - c.m.y * o.g.x + c.g.w * o.v.z + c.v.z * o.g.w,
	                    -c.g.x * o.v.x - c.g.y * o.v.y - c.g.z * o.v.z - c.v.x * o.g.x - c.v.y * o.g.y - c.v.z * o.g.z,
	                    -c.m.x * o.v.x - c.m.y * o.v.y - c.m.z * o.v.z - c.v.x * o.m.x - c.v.y * o.m.y - c.v.z * o.m.z));
}

RoundPoint3D Terathon::Antiwedge(const Circle3D& c, const Line3D& l)
{
	return (RoundPoint3D(c.g.z * l.m.y - c.g.y * l.m.z + c.g.w * l.v.x,
	                     c.g.x * l.m.z - c.g.z * l.m.x + c.g.w * l.v.y,
	                     c.g.y * l.m.x - c.g.x * l.m.y + c.g.w * l.v.z,
	                    -c.g.x * l.v.x - c.g.y * l.v.y - c.g.z * l.v.z,
	                    -c.m.x * l.v.x - c.m.y * l.v.y - c.m.z * l.v.z - c.v.x * l.m.x - c.v.y * l.m.y - c.v.z * l.m.z));
}

RoundPoint3D Terathon::Antiwedge(const Sphere3D& s, const Dipole3D& d)
{
	return (RoundPoint3D(s.y * d.m.z - s.z * d.m.y + s.u * d.p.x - s.w * d.v.x,
	                     s.z * d.m.x - s.x * d.m.z + s.u * d.p.y - s.w * d.v.y,
	                     s.x * d.m.y - s.y * d.m.x + s.u * d.p.z - s.w * d.v.z,
	                     s.x * d.v.x + s.y * d.v.y + s.z * d.v.z + s.u * d.p.w,
	                    -s.x * d.p.x - s.y * d.p.y - s.z * d.p.z - s.w * d.p.w));
}

RoundPoint3D Terathon::Antiwedge(const Dipole3D& d, const Sphere3D& s)
{
	return (RoundPoint3D(d.m.y * s.z - d.m.z * s.y + d.v.x * s.w - d.p.x * s.u,
	                     d.m.z * s.x - d.m.x * s.z + d.v.y * s.w - d.p.y * s.u,
	                     d.m.x * s.y - d.m.y * s.x + d.v.z * s.w - d.p.z * s.u,
	                    -d.v.x * s.x - d.v.y * s.y - d.v.z * s.z - d.p.w * s.u,
	                     d.p.x * s.x + d.p.y * s.y + d.p.z * s.z + d.p.w * s.w));
}

RoundPoint3D Terathon::Antiwedge(const Plane3D& g, const Dipole3D& d)
{
	return (RoundPoint3D(g.y * d.m.z - g.z * d.m.y - g.w * d.v.x,
	                     g.z * d.m.x - g.x * d.m.z - g.w * d.v.y,
	                     g.x * d.m.y - g.y * d.m.x - g.w * d.v.z,
	                     g.x * d.v.x + g.y * d.v.y + g.z * d.v.z,
	                    -g.x * d.p.x - g.y * d.p.y - g.z * d.p.z - g.w * d.p.w));
}

RoundPoint3D Terathon::Antiwedge(const Dipole3D& d, const Plane3D& g)
{
	return (RoundPoint3D(d.m.y * g.z - d.m.z * g.y + d.v.x * g.w,
	                     d.m.z * g.x - d.m.x * g.z + d.v.y * g.w,
	                     d.m.x * g.y - d.m.y * g.x + d.v.z * g.w,
	                    -d.v.x * g.x - d.v.y * g.y - d.v.z * g.z,
	                     d.p.x * g.x + d.p.y * g.y + d.p.z * g.z + d.p.w * g.w));
}

RoundPoint3D Terathon::Antiwedge(const Sphere3D& s, const FlatPoint3D& p)
{
	return (RoundPoint3D(s.u * p.x, s.u * p.y, s.u * p.z, s.u * p.w, -s.x * p.x - s.y * p.y - s.z * p.z - s.w * p.w));
}

RoundPoint3D Terathon::Antiwedge(const FlatPoint3D& p, const Sphere3D& s)
{
	return (RoundPoint3D(-p.x * s.u, -p.y * s.u, -p.z * s.u, -p.w * s.u, p.x * s.x + p.y * s.y + p.z * s.z + p.w * s.w));
}

RoundPoint3D Terathon::Antiwedge(const Sphere3D& s, const Point3D& p)
{
	return (RoundPoint3D(s.u * p.x, s.u * p.y, s.u * p.z, s.u, -s.x * p.x - s.y * p.y - s.z * p.z - s.w));
}

RoundPoint3D Terathon::Antiwedge(const Point3D& p, const Sphere3D& s)
{
	return (RoundPoint3D(-p.x * s.u, -p.y * s.u, -p.z * s.u, -s.u, p.x * s.x + p.y * s.y + p.z * s.z + s.w));
}
