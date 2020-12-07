//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2021, Terathon Software LLC
//
// This software is licensed under the GNU General Public License version 3.
// Separate proprietary licenses are available from Terathon Software.
//
// THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
// EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. 
//


#include "TSVector2D.h"


using namespace Terathon;


ConstPoint2D Zero2DType::zero = {0.0F, 0.0F};

const Zero2DType Terathon::Zero2D = {};


Vector2D& Vector2D::Rotate(float angle)
{
	Vector2D t = CosSin(angle);
	float nx = t.x * x - t.y * y;
	float ny = t.y * x + t.x * y;

	x = nx;
	y = ny;
	return (*this);
}
