//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSConformal2D.h"


using namespace Terathon;


alignas(16) const ConstRoundPoint2D RoundPoint2D::zero = {0.0F, 0.0F, 0.0F, 0.0F};
alignas(32) const ConstDipole2D Dipole2D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};
alignas(16) const ConstCircle2D Circle2D::zero = {0.0F, 0.0F, 0.0F, 0.0F};


// ==============================================
//	Center
// ==============================================

RoundPoint2D Terathon::Center(const Dipole2D& d)
{
	return (RoundPoint2D(-d.g.y * d.p.z - d.g.x * d.g.z,
	                      d.g.x * d.p.z - d.g.y * d.g.z,
	                      d.g.x * d.g.x + d.g.y * d.g.y,
	                      d.p.z * d.p.z - d.g.x * d.p.y + d.g.y * d.p.x));
}

// ==============================================
//	FlatCenter
// ==============================================

FlatPoint2D Terathon::FlatCenter(const Dipole2D& d)
{
	return (FlatPoint2D(-d.g.x * d.g.z - d.g.y * d.p.z,
	                     d.g.x * d.p.z - d.g.y * d.g.z,
	                     d.g.x * d.g.x + d.g.y * d.g.y));
}

// ==============================================
//	Container
// ==============================================

Circle2D Terathon::Container(const Dipole2D& d)
{
	return (Circle2D(-d.g.x * d.g.x - d.g.y * d.g.y,
	                 -d.g.x * d.g.z - d.g.y * d.p.z,
	                  d.g.x * d.p.z - d.g.y * d.g.z,
	                  d.g.y * d.p.x - d.g.x * d.p.y - d.g.z * d.g.z));
}

// ==============================================
//	Partner
// ==============================================

Dipole2D Terathon::Partner(const Dipole2D& d)
{
	float gzpz = d.g.z * d.p.z;
	float gxy2 = -d.g.x * d.g.x - d.g.y * d.g.y;
	float f = d.p.z * d.p.z - d.g.z * d.g.z + d.g.y * d.p.x - d.g.x * d.p.y;

	return (Dipole2D(gxy2 * d.g.x,
	                 gxy2 * d.g.y,
	                 gxy2 * d.g.z,

	                 gzpz * d.g.x + f * d.g.y,
	                 gzpz * d.g.y - f * d.g.x,
	                 gxy2 * d.p.z));
}

// ==============================================
//	Join
// ==============================================

Dipole2D Terathon::Wedge(const RoundPoint2D& a, const RoundPoint2D& b)
{
	return (Dipole2D(a.y * b.z - a.z * b.y,
	                 a.z * b.x - a.x * b.z,
	                 a.x * b.y - a.y * b.x,

	                 a.w * b.x - a.x * b.w,
	                 a.w * b.y - a.y * b.w,
	                 a.w * b.z - a.z * b.w));
}

Line2D Terathon::Wedge(const FlatPoint2D& p, const RoundPoint2D& a)
{
	return (Line2D(p.y * a.z - p.z * a.y,
	               p.z * a.x - p.x * a.z,
	               p.x * a.y - p.y * a.x));
}

Line2D Terathon::Wedge(const Point2D& p, const RoundPoint2D& a)
{
	return (Line2D(p.y * a.z - a.y,
	               a.x - p.x * a.z,
	               p.x * a.y - p.y * a.x));
}

Circle2D Terathon::Wedge(const Dipole2D& d, const RoundPoint2D& a)
{
	return (Circle2D(-d.g.x * a.x - d.g.y * a.y - d.g.z * a.z,
	                  d.p.y * a.z - d.p.z * a.y + d.g.x * a.w,
	                  d.p.z * a.x - d.p.x * a.z + d.g.y * a.w,
	                  d.p.x * a.y - d.p.y * a.x + d.g.z * a.w));
}

// ==============================================
//	Meet
// ==============================================

Dipole2D Terathon::Antiwedge(const Circle2D& c, const Circle2D& o)
{
	return (Dipole2D(c.x * o.w - c.w * o.x,
	                 c.y * o.w - c.w * o.y,
	                 c.z * o.w - c.w * o.z,

	                 c.z * o.y - c.y * o.z,
	                 c.x * o.z - c.z * o.x,
	                 c.y * o.x - c.x * o.y));
}

Dipole2D Terathon::Antiwedge(const Circle2D& c, const Line2D& g)
{
	return (Dipole2D(-c.w * g.x,
	                 -c.w * g.y,
	                 -c.w * g.z,

	                 c.z * g.y - c.y * g.z,
	                 c.x * g.z - c.z * g.x,
	                 c.y * g.x - c.x * g.y));
}

Dipole2D Terathon::Antiwedge(const Line2D& g, const Circle2D& c)
{
	return (Dipole2D(g.x * c.w,
	                 g.y * c.w,
	                 g.z * c.w,

	                 g.z * c.y - g.y * c.z,
	                 g.x * c.z - g.z * c.x,
	                 g.y * c.x - g.x * c.y));
}

RoundPoint2D Terathon::Antiwedge(const Circle2D& c, const Dipole2D& d)
{
	return (RoundPoint2D(c.z * d.g.y - c.y * d.g.z + c.w * d.p.x,
	                     c.x * d.g.z - c.z * d.g.x + c.w * d.p.y,
	                     c.y * d.g.x - c.x * d.g.y + c.w * d.p.z,
	                    -c.x * d.p.x - c.y * d.p.y - c.z * d.p.z));
}

RoundPoint2D Terathon::Antiwedge(const Line2D& g, const Dipole2D& d)
{
	return (RoundPoint2D(g.z * d.g.y - g.y * d.g.z,
	                     g.x * d.g.z - g.z * d.g.x,
	                     g.y * d.g.x - g.x * d.g.y,
	                    -g.x * d.p.x - g.y * d.p.y - g.z * d.p.z));
}

RoundPoint2D Terathon::Antiwedge(const Circle2D& c, const FlatPoint2D& p)
{
	return (RoundPoint2D(c.w * p.x, c.w * p.y, c.w * p.z, -c.x * p.x - c.y * p.y - c.z * p.z));
}

RoundPoint2D Terathon::Antiwedge(const Circle2D& c, const Point2D& p)
{
	return (RoundPoint2D(c.w * p.x, c.w * p.y, c.w, -c.x * p.x - c.y * p.y - c.z));
}
