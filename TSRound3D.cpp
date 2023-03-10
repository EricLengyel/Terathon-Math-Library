//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSRound3D.h"


using namespace Terathon;


const ConstRound3D Round3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F};


Plane3D Terathon::Wedge(const Round3D& a, const Line3D& l)
{
	return (Plane3D(a.z * l.v.y - a.y * l.v.z + a.w * l.m.x,
		            a.x * l.v.z - a.z * l.v.x + a.w * l.m.y,
		            a.y * l.v.x - a.x * l.v.y + a.w * l.m.z,
		           -a.x * l.m.x - a.y * l.m.y - a.z * l.m.z));
}

Plane3D Terathon::Wedge(const Line3D& l, const Round3D& a)
{
	return (Plane3D(a.y * l.v.z - a.z * l.v.y - a.w * l.m.x,
		            a.z * l.v.x - a.x * l.v.z - a.w * l.m.y,
		            a.x * l.v.y - a.y * l.v.x - a.w * l.m.z,
		            a.x * l.m.x + a.y * l.m.y + a.z * l.m.z));
}
