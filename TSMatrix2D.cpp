//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSMatrix2D.h"


using namespace Terathon;


const ConstMatrix2D Matrix2D::identity = {{{1.0F, 0.0F}, {0.0F, 1.0F}}};


Matrix2D::Matrix2D(float n00, float n01, float n10, float n11) : Mat2D<TypeMatrix2D>(n00, n01, n10, n11)
{
}

Matrix2D::Matrix2D(const Vector2D& a, const Vector2D& b)
{
	col0 = a;
	col1 = b;
}

Matrix2D& Matrix2D::Set(float n00, float n01, float n10, float n11)
{
	matrix.Set(n00, n01, n10, n11);
	return (*this);
}

Matrix2D& Matrix2D::Set(const Vector2D& a, const Vector2D& b)
{
	col0 = a;
	col1 = b;
	return (*this);
}

Matrix2D& Matrix2D::operator *=(const Matrix2D& m)
{
	float t = m00 * m(0,0) + m01 * m(1,0);
	m01 = m00 * m(0,1) + m01 * m(1,1);
	m00 = t;

	t = m10 * m(0,0) + m11 * m(1,0);
	m11 = m10 * m(0,1) + m11 * m(1,1);
	m10 = t;

	return (*this);
}

Matrix2D& Matrix2D::operator *=(float s)
{
	matrix *= s;
	return (*this);
}

Matrix2D& Matrix2D::operator /=(float s)
{
	matrix /= s;
	return (*this);
}

Matrix2D& Matrix2D::SetIdentity(void)
{
	m00 = m11 = 1.0F;
	m01 = m10 = 0.0F;
	return (*this);
}

Matrix2D& Matrix2D::Orthogonalize(int32 column)
{
	Vector2D& x = (*this)[column];
	Vector2D& y = (*this)[column ^ 1];

	x.Normalize();
	y = Normalize(y - x * Dot(x, y));

	return (*this);
}

Matrix2D Matrix2D::MakeRotation(float angle)
{
	Vector2D v = CosSin(angle);
	return (Matrix2D(v.x, -v.y, v.y,  v.x));
}

Matrix2D Matrix2D::MakeScaleX(float sx)
{
	return (Matrix2D(sx, 0.0F, 0.0F, 1.0F));
}

Matrix2D Matrix2D::MakeScaleY(float sy)
{
	return (Matrix2D(1.0F, 0.0F, 0.0F, sy));
}

Matrix2D Matrix2D::MakeScale(float scale)
{
	return (Matrix2D(scale, 0.0F, 0.0F, scale));
}

Matrix2D Matrix2D::MakeScale(float sx, float sy)
{
	return (Matrix2D(sx, 0.0F, 0.0F, sy));
}


Matrix2D Terathon::operator *(const Matrix2D& m, float s)
{
	return (Matrix2D(m(0,0) * s, m(0,1) * s, m(1,0) * s, m(1,1) * s));
}

Matrix2D Terathon::operator /(const Matrix2D& m, float s)
{
	s = 1.0F / s;
	return (Matrix2D(m(0,0) * s, m(0,1) * s, m(1,0) * s, m(1,1) * s));
}

float Terathon::Determinant(const Matrix2D& m)
{
	return (m(0,0) * m(1,1) - m(0,1) * m(1,0));
}

Matrix2D Terathon::Inverse(const Matrix2D& m)
{
	float invDet = 1.0F / (m(0,0) * m(1,1) - m(0,1) * m(1,0));

	return (Matrix2D(m(1,1) * invDet, -m(0,1) * invDet,
					-m(1,0) * invDet,  m(0,0) * invDet));
}

Matrix2D Terathon::Adjugate(const Matrix2D& m)
{
	return (Matrix2D(m(1,1), -m(0,1), -m(1,0),  m(0,0)));
}
