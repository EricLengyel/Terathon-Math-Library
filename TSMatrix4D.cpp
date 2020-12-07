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


#include "TSMatrix4D.h"


using namespace Terathon;


const ConstTransform4D Terathon::Identity4D = {{{1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 1.0F}}};


Matrix4D::Matrix4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33) : Mat4D<TypeMatrix4D>(n00, n01, n02, n03, n10, n11, n12, n13, n20, n21, n22, n23, n30, n31, n32, n33)
{
}

Matrix4D::Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d)
{
	col0 = a;
	col1 = b;
	col2 = c;
	col3 = d;
}

Matrix4D::Matrix4D(const Bivector3D& a, float n03, const Bivector3D& b, float n13, const Bivector3D& c, float n23, const Bivector3D& d, float n33)
{
	row0.Set(a.x, a.y, a.z, n03);
	row1.Set(b.x, b.y, b.z, n13);
	row2.Set(c.x, c.y, c.z, n23);
	row3.Set(d.x, d.y, d.z, n33);
}

Matrix4D& Matrix4D::Set(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33)
{
	matrix.Set(n00, n01, n02, n03, n10, n11, n12, n13, n20, n21, n22, n23, n30, n31, n32, n33);
	return (*this);
}

Matrix4D& Matrix4D::Set(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d)
{
	col0 = a;
	col1 = b;
	col2 = c;
	col3 = d;
	return (*this);
}

Matrix4D& Matrix4D::operator *=(const Matrix4D& m)
{
	float x = m00;
	float y = m01;
	float z = m02;
	float w = m03;
	m00 = x * m.m00 + y * m.m10 + z * m.m20 + w * m.m30;
	m01 = x * m.m01 + y * m.m11 + z * m.m21 + w * m.m31;
	m02 = x * m.m02 + y * m.m12 + z * m.m22 + w * m.m32;
	m03 = x * m.m03 + y * m.m13 + z * m.m23 + w * m.m33;

	x = m10;
	y = m11;
	z = m12;
	w = m13;
	m10 = x * m.m00 + y * m.m10 + z * m.m20 + w * m.m30;
	m11 = x * m.m01 + y * m.m11 + z * m.m21 + w * m.m31;
	m12 = x * m.m02 + y * m.m12 + z * m.m22 + w * m.m32;
	m13 = x * m.m03 + y * m.m13 + z * m.m23 + w * m.m33;

	x = m20;
	y = m21;
	z = m22;
	w = m23;
	m20 = x * m.m00 + y * m.m10 + z * m.m20 + w * m.m30;
	m21 = x * m.m01 + y * m.m11 + z * m.m21 + w * m.m31;
	m22 = x * m.m02 + y * m.m12 + z * m.m22 + w * m.m32;
	m23 = x * m.m03 + y * m.m13 + z * m.m23 + w * m.m33;

	x = m30;
	y = m31;
	z = m32;
	w = m33;
	m30 = x * m.m00 + y * m.m10 + z * m.m20 + w * m.m30;
	m31 = x * m.m01 + y * m.m11 + z * m.m21 + w * m.m31;
	m32 = x * m.m02 + y * m.m12 + z * m.m22 + w * m.m32;
	m33 = x * m.m03 + y * m.m13 + z * m.m23 + w * m.m33;

	return (*this);
}

Matrix4D& Matrix4D::operator *=(const Matrix3D& m)
{
	float x = m00;
	float y = m01;
	float z = m02;
	m00 = x * m.m00 + y * m.m10 + z * m.m20;
	m01 = x * m.m01 + y * m.m11 + z * m.m21;
	m02 = x * m.m02 + y * m.m12 + z * m.m22;

	x = m10;
	y = m11;
	z = m12;
	m10 = x * m.m00 + y * m.m10 + z * m.m20;
	m11 = x * m.m01 + y * m.m11 + z * m.m21;
	m12 = x * m.m02 + y * m.m12 + z * m.m22;

	x = m20;
	y = m21;
	z = m22;
	m20 = x * m.m00 + y * m.m10 + z * m.m20;
	m21 = x * m.m01 + y * m.m11 + z * m.m21;
	m22 = x * m.m02 + y * m.m12 + z * m.m22;

	x = m30;
	y = m31;
	z = m32;
	m30 = x * m.m00 + y * m.m10 + z * m.m20;
	m31 = x * m.m01 + y * m.m11 + z * m.m21;
	m32 = x * m.m02 + y * m.m12 + z * m.m22;

	return (*this);
}

Matrix4D& Matrix4D::SetIdentity(void)
{
	m00 = m11 = m22 = m33 = 1.0F;
	m01 = m02 = m03 = m10 = m12 = m13 = m20 = m21 = m23 = m30 = m31 = m32 = 0.0F;
	return (*this);
}


Matrix4D Terathon::operator *(const Matrix4D& m1, const Matrix3D& m2)
{
	return (Matrix4D(m1(0,0) * m2(0,0) + m1(0,1) * m2(1,0) + m1(0,2) * m2(2,0),
					 m1(0,0) * m2(0,1) + m1(0,1) * m2(1,1) + m1(0,2) * m2(2,1),
					 m1(0,0) * m2(0,2) + m1(0,1) * m2(1,2) + m1(0,2) * m2(2,2),
					 m1(0,3),
					 m1(1,0) * m2(0,0) + m1(1,1) * m2(1,0) + m1(1,2) * m2(2,0),
					 m1(1,0) * m2(0,1) + m1(1,1) * m2(1,1) + m1(1,2) * m2(2,1),
					 m1(1,0) * m2(0,2) + m1(1,1) * m2(1,2) + m1(1,2) * m2(2,2),
					 m1(1,3),
					 m1(2,0) * m2(0,0) + m1(2,1) * m2(1,0) + m1(2,2) * m2(2,0),
					 m1(2,0) * m2(0,1) + m1(2,1) * m2(1,1) + m1(2,2) * m2(2,1),
					 m1(2,0) * m2(0,2) + m1(2,1) * m2(1,2) + m1(2,2) * m2(2,2),
					 m1(2,3),
					 m1(3,0) * m2(0,0) + m1(3,1) * m2(1,0) + m1(3,2) * m2(2,0),
					 m1(3,0) * m2(0,1) + m1(3,1) * m2(1,1) + m1(3,2) * m2(2,1),
					 m1(3,0) * m2(0,2) + m1(3,1) * m2(1,2) + m1(3,2) * m2(2,2),
					 m1(3,3)));
}

Vector4D Terathon::operator *(const Matrix4D& m, const Vector3D& v)
{
	return (Vector4D(m(0,0) * v.x + m(0,1) * v.y + m(0,2) * v.z,
					 m(1,0) * v.x + m(1,1) * v.y + m(1,2) * v.z,
					 m(2,0) * v.x + m(2,1) * v.y + m(2,2) * v.z,
					 m(3,0) * v.x + m(3,1) * v.y + m(3,2) * v.z));
}

Vector4D Terathon::operator *(const Vector3D& v, const Matrix4D& m)
{
	return (Vector4D(m(0,0) * v.x + m(1,0) * v.y + m(2,0) * v.z,
					 m(0,1) * v.x + m(1,1) * v.y + m(2,1) * v.z,
					 m(0,2) * v.x + m(1,2) * v.y + m(2,2) * v.z,
					 m(0,3) * v.x + m(1,3) * v.y + m(2,3) * v.z));
}

Vector4D Terathon::operator *(const Matrix4D& m, const Point3D& p)
{
	return (Vector4D(m(0,0) * p.x + m(0,1) * p.y + m(0,2) * p.z + m(0,3),
					 m(1,0) * p.x + m(1,1) * p.y + m(1,2) * p.z + m(1,3),
					 m(2,0) * p.x + m(2,1) * p.y + m(2,2) * p.z + m(2,3),
					 m(3,0) * p.x + m(3,1) * p.y + m(3,2) * p.z + m(3,3)));
}

Vector4D Terathon::operator *(const Point3D& p, const Matrix4D& m)
{
	return (Vector4D(m(0,0) * p.x + m(1,0) * p.y + m(2,0) * p.z + m(3,0),
					 m(0,1) * p.x + m(1,1) * p.y + m(2,1) * p.z + m(3,1),
					 m(0,2) * p.x + m(1,2) * p.y + m(2,2) * p.z + m(3,2),
					 m(0,3) * p.x + m(1,3) * p.y + m(2,3) * p.z + m(3,3)));
}

Vector4D Terathon::operator *(const Matrix4D& m, const Vector2D& v)
{
	return (Vector4D(m(0,0) * v.x + m(0,1) * v.y,
					 m(1,0) * v.x + m(1,1) * v.y,
					 m(2,0) * v.x + m(2,1) * v.y,
					 m(3,0) * v.x + m(3,1) * v.y));
}

Vector4D Terathon::operator *(const Vector2D& v, const Matrix4D& m)
{
	return (Vector4D(m(0,0) * v.x + m(1,0) * v.y,
					 m(0,1) * v.x + m(1,1) * v.y,
					 m(0,2) * v.x + m(1,2) * v.y,
					 m(0,3) * v.x + m(1,3) * v.y));
}

Vector4D Terathon::operator *(const Matrix4D& m, const Point2D& p)
{
	return (Vector4D(m(0,0) * p.x + m(0,1) * p.y + m(0,3),
					 m(1,0) * p.x + m(1,1) * p.y + m(1,3),
					 m(2,0) * p.x + m(2,1) * p.y + m(2,3),
					 m(3,0) * p.x + m(3,1) * p.y + m(3,3)));
}

Vector4D Terathon::operator *(const Point2D& p, const Matrix4D& m)
{
	return (Vector4D(m(0,0) * p.x + m(1,0) * p.y + m(3,0),
					 m(0,1) * p.x + m(1,1) * p.y + m(3,1),
					 m(0,2) * p.x + m(1,2) * p.y + m(3,2),
					 m(0,3) * p.x + m(1,3) * p.y + m(3,3)));
}

float Terathon::Determinant(const Matrix4D& m)
{
	const Vector3D& a = reinterpret_cast<const Vector3D&>(m[0]);
	const Vector3D& b = reinterpret_cast<const Vector3D&>(m[1]);
	const Vector3D& c = reinterpret_cast<const Vector3D&>(m[2]);
	const Vector3D& d = reinterpret_cast<const Vector3D&>(m[3]);

	const float& x = m(3,0);
	const float& y = m(3,1);
	const float& z = m(3,2);
	const float& w = m(3,3);

	Bivector3D s = a ^ b;
	Bivector3D t = c ^ d;
	Vector3D u = a * y - b * x;
	Vector3D v = c * w - d * z;

	return ((s ^ v) + (t ^ u));
}

Matrix4D Terathon::Inverse(const Matrix4D& m)
{
	// See FGED1, Section 1.7.5.

	#ifdef TERATHON_SSE

		Transform4D		result;

		vec_float a = VecLoad(&m(0,0));
		vec_float b = VecLoad(&m(0,1));
		vec_float c = VecLoad(&m(0,2));
		vec_float d = VecLoad(&m(0,3));

		vec_float x = VecSmearW(a);
		vec_float y = VecSmearW(b);
		vec_float z = VecSmearW(c);
		vec_float w = VecSmearW(d);

		vec_float s = VecCross3D(a, b);
		vec_float t = VecCross3D(c, d);
		vec_float u = VecSub(VecMul(a, y), VecMul(b, x));
		vec_float v = VecSub(VecMul(c, w), VecMul(d, z));

		vec_float invDet = VecSmearX(VecDivScalar(VecLoadScalarConstant<0x3F800000>(), VecAdd(VecDot3D(s, v), VecDot3D(t, u))));

		s = VecMul(s, invDet);
		t = VecMul(t, invDet);
		u = VecMul(u, invDet);
		v = VecMul(v, invDet);

		vec_float r0 = VecAdd(VecCross3D(b, v), VecMul(t, y));
		vec_float r1 = VecSub(VecCross3D(v, a), VecMul(t, x));
		vec_float r2 = VecAdd(VecCross3D(d, u), VecMul(s, w));
		vec_float r3 = VecSub(VecCross3D(u, c), VecMul(s, z));

		vec_float h0 = _mm_shuffle_ps(r0, r1, _MM_SHUFFLE(1, 0, 1, 0));
		vec_float h1 = _mm_shuffle_ps(r2, r3, _MM_SHUFFLE(1, 0, 1, 0));
		vec_float h2 = _mm_shuffle_ps(r0, r1, _MM_SHUFFLE(3, 2, 3, 2));
		vec_float h3 = _mm_shuffle_ps(r2, r3, _MM_SHUFFLE(3, 2, 3, 2));

		VecStore(_mm_shuffle_ps(h0, h1, _MM_SHUFFLE(2, 0, 2, 0)), &result(0,0));
		VecStore(_mm_shuffle_ps(h0, h1, _MM_SHUFFLE(3, 1, 3, 1)), &result(0,1));
		VecStore(_mm_shuffle_ps(h2, h3, _MM_SHUFFLE(2, 0, 2, 0)), &result(0,2));

		VecStoreX(VecNegate(VecDot3D(b, t)), &result(0,3));
		VecStoreX(VecDot3D(a, t), &result(1,3));
		VecStoreX(VecNegate(VecDot3D(d, s)), &result(2,3));
		VecStoreX(VecDot3D(c, s), &result(3,3));

		return (result);

	#else

		const Vector3D& a = reinterpret_cast<const Vector3D&>(m[0]);
		const Vector3D& b = reinterpret_cast<const Vector3D&>(m[1]);
		const Vector3D& c = reinterpret_cast<const Vector3D&>(m[2]);
		const Vector3D& d = reinterpret_cast<const Vector3D&>(m[3]);

		const float& x = m(3,0);
		const float& y = m(3,1);
		const float& z = m(3,2);
		const float& w = m(3,3);

		Bivector3D s = a ^ b;
		Bivector3D t = c ^ d;
		Vector3D u = a * y - b * x;
		Vector3D v = c * w - d * z;

		float invDet = 1.0F / ((s ^ v) + (t ^ u));

		s *= invDet;
		t *= invDet;
		u *= invDet;
		v *= invDet;

		return (Matrix4D((b ^ v) + t * y, -(b ^ t),
						 (v ^ a) - t * x,  (a ^ t),
						 (d ^ u) + s * w, -(d ^ s),
						 (u ^ c) - s * z,  (c ^ s)));

	#endif
}

Matrix4D Terathon::Adjugate(const Matrix4D& m)
{
	const Vector3D& a = reinterpret_cast<const Vector3D&>(m[0]);
	const Vector3D& b = reinterpret_cast<const Vector3D&>(m[1]);
	const Vector3D& c = reinterpret_cast<const Vector3D&>(m[2]);
	const Vector3D& d = reinterpret_cast<const Vector3D&>(m[3]);

	const float& x = m(3,0);
	const float& y = m(3,1);
	const float& z = m(3,2);
	const float& w = m(3,3);

	Bivector3D s = a ^ b;
	Bivector3D t = c ^ d;
	Vector3D u = a * y - b * x;
	Vector3D v = c * w - d * z;

	return (Matrix4D((b ^ v) + t * y, -(b ^ t),
					 (v ^ a) - t * x,  (a ^ t),
					 (d ^ u) + s * w, -(d ^ s),
					 (u ^ c) - s * z,  (c ^ s)));
}


Transform4D::Transform4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23)
{
	m00 = n00;
	m01 = n01;
	m02 = n02;
	m03 = n03;
	m10 = n10;
	m11 = n11;
	m12 = n12;
	m13 = n13;
	m20 = n20;
	m21 = n21;
	m22 = n22;
	m23 = n23;

	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
}

Transform4D::Transform4D(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D& d)
{
	m00 = a.x;
	m10 = a.y;
	m20 = a.z;
	m01 = b.x;
	m11 = b.y;
	m21 = b.z;
	m02 = c.x;
	m12 = c.y;
	m22 = c.z;
	m03 = d.x;
	m13 = d.y;
	m23 = d.z;

	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
}

Transform4D::Transform4D(const Bivector3D& r0, float n03, const Bivector3D& r1, float n13, const Bivector3D& r2, float n23)
{
	row0.Set(r0.x, r0.y, r0.z, n03);
	row1.Set(r1.x, r1.y, r1.z, n13);
	row2.Set(r2.x, r2.y, r2.z, n23);
	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
}

Transform4D::Transform4D(const Matrix3D& m)
{
	m00 = m.m00;
	m10 = m.m10;
	m20 = m.m20;
	m01 = m.m01;
	m11 = m.m11;
	m21 = m.m21;
	m02 = m.m02;
	m12 = m.m12;
	m22 = m.m22;

	m03 = m13 = m23 = 0.0F;
	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
}

Transform4D::Transform4D(const Matrix3D& m, const Vector3D& v)
{
	m00 = m.m00;
	m10 = m.m10;
	m20 = m.m20;
	m01 = m.m01;
	m11 = m.m11;
	m21 = m.m21;
	m02 = m.m02;
	m12 = m.m12;
	m22 = m.m22;
	m03 = v.x;
	m13 = v.y;
	m23 = v.z;

	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
}

Transform4D& Transform4D::Set(const Matrix3D& m, const Vector3D& v)
{
	m00 = m.m00;
	m10 = m.m10;
	m20 = m.m20;
	m01 = m.m01;
	m11 = m.m11;
	m21 = m.m21;
	m02 = m.m02;
	m12 = m.m12;
	m22 = m.m22;
	m03 = v.x;
	m13 = v.y;
	m23 = v.z;

	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
	return (*this);
}

Transform4D& Transform4D::Set(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23)
{
	m00 = n00;
	m01 = n01;
	m02 = n02;
	m03 = n03;
	m10 = n10;
	m11 = n11;
	m12 = n12;
	m13 = n13;
	m20 = n20;
	m21 = n21;
	m22 = n22;
	m23 = n23;

	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
	return (*this);
}

Transform4D& Transform4D::Set(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D& p)
{
	m00 = a.x;
	m10 = a.y;
	m20 = a.z;
	m01 = b.x;
	m11 = b.y;
	m21 = b.z;
	m02 = c.x;
	m12 = c.y;
	m22 = c.z;
	m03 = p.x;
	m13 = p.y;
	m23 = p.z;

	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
	return (*this);
}

Transform4D& Transform4D::operator *=(const Transform4D& m)
{
	float x = m00;
	float y = m01;
	float z = m02;
	m00 = x * m.m00 + y * m.m10 + z * m.m20;
	m01 = x * m.m01 + y * m.m11 + z * m.m21;
	m02 = x * m.m02 + y * m.m12 + z * m.m22;
	m03 = x * m.m03 + y * m.m13 + z * m.m23 + m03;

	x = m10;
	y = m11;
	z = m12;
	m10 = x * m.m00 + y * m.m10 + z * m.m20;
	m11 = x * m.m01 + y * m.m11 + z * m.m21;
	m12 = x * m.m02 + y * m.m12 + z * m.m22;
	m13 = x * m.m03 + y * m.m13 + z * m.m23 + m13;

	x = m20;
	y = m21;
	z = m22;
	m20 = x * m.m00 + y * m.m10 + z * m.m20;
	m21 = x * m.m01 + y * m.m11 + z * m.m21;
	m22 = x * m.m02 + y * m.m12 + z * m.m22;
	m23 = x * m.m03 + y * m.m13 + z * m.m23 + m23;

	return (*this);
}

Transform4D& Transform4D::operator *=(const Matrix3D& m)
{
	float x = m00;
	float y = m01;
	float z = m02;
	m00 = x * m.m00 + y * m.m10 + z * m.m20;
	m01 = x * m.m01 + y * m.m11 + z * m.m21;
	m02 = x * m.m02 + y * m.m12 + z * m.m22;

	x = m10;
	y = m11;
	z = m12;
	m10 = x * m.m00 + y * m.m10 + z * m.m20;
	m11 = x * m.m01 + y * m.m11 + z * m.m21;
	m12 = x * m.m02 + y * m.m12 + z * m.m22;

	x = m20;
	y = m21;
	z = m22;
	m20 = x * m.m00 + y * m.m10 + z * m.m20;
	m21 = x * m.m01 + y * m.m11 + z * m.m21;
	m22 = x * m.m02 + y * m.m12 + z * m.m22;

	return (*this);
}

Transform4D& Transform4D::SetMatrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
{
	m00 = a.x;
	m10 = a.y;
	m20 = a.z;
	m01 = b.x;
	m11 = b.y;
	m21 = b.z;
	m02 = c.x;
	m12 = c.y;
	m22 = c.z;

	return (*this);
}

Transform4D& Transform4D::Orthogonalize(int32 column)
{
	Vector3D& x = (*this)[column];
	Vector3D& y = (*this)[(column < 2) ? column + 1 : 0];
	Vector3D& z = (*this)[(column > 0) ? column - 1 : 2];

	x.Normalize();
	y = Normalize(y - x * Dot(x, y));
	z = Normalize(z - x * Dot(x, z) - y * Dot(y, z));

	return (*this);
}

void Transform4D::GetEulerAngles(float *x, float *y, float *z) const
{
	float sy = m02;
	if (sy < 1.0F)
	{
		if (sy > -1.0F)
		{
			*x = -Arctan(m12, m22);
			*y = Arcsin(sy);
			*z = -Arctan(m01, m00);
		}
		else
		{
			*x = 0.0F;
			*y = -Math::tau_over_4;
			*z = Arctan(m10, m11);
		}
	}
	else
	{
		*x = 0.0F;
		*y = Math::tau_over_4;
		*z = Arctan(m10, m11);
	}
}

Transform4D& Transform4D::SetEulerAngles(float x, float y, float z)
{
	Vector2D xrot = CosSin(x);
	Vector2D yrot = CosSin(y);
	Vector2D zrot = CosSin(z);

	m00 = yrot.x * zrot.x;
	m10 = xrot.x * zrot.y + xrot.y * yrot.y * zrot.x;
	m20 = xrot.y * zrot.y - xrot.x * yrot.y * zrot.x;
	m01 = -yrot.x * zrot.y;
	m11 = xrot.x * zrot.x - xrot.y * yrot.y * zrot.y;
	m21 = xrot.y * zrot.x + xrot.x * yrot.y * zrot.y;
	m02 = yrot.y;
	m12 = -xrot.y * yrot.x;
	m22 = xrot.x * yrot.x;

	m03 = m13 = m23 = 0.0F;
	row3.Set(0.0F, 0.0F, 0.0F, 1.0F);
	return (*this);
}

Transform4D Transform4D::MakeRotationX(float angle)
{
	Vector2D v = CosSin(angle);

	return (Transform4D(1.0F, 0.0F, 0.0F, 0.0F,
						0.0F,  v.x, -v.y, 0.0F,
						0.0F,  v.y,  v.x, 0.0F));
}

Transform4D Transform4D::MakeRotationY(float angle)
{
	Vector2D v = CosSin(angle);

	return (Transform4D( v.x, 0.0F,  v.y, 0.0F,
						0.0F, 1.0F, 0.0F, 0.0F,
						-v.y, 0.0F,  v.x, 0.0F));
}

Transform4D Transform4D::MakeRotationZ(float angle)
{
	Vector2D v = CosSin(angle);

	return (Transform4D( v.x, -v.y, 0.0F, 0.0F,
						 v.y,  v.x, 0.0F, 0.0F,
						0.0F, 0.0F, 1.0F, 0.0F));
}

Transform4D Transform4D::MakeRotation(float angle, const Bivector3D& axis)
{
	Vector2D v = CosSin(angle);
	const float& c = v.x;
	const float& s = v.y;
	float d = 1.0F - c;

	float x = axis.x * d;
	float y = axis.y * d;
	float z = axis.z * d;
	float axay = x * axis.y;
	float axaz = x * axis.z;
	float ayaz = y * axis.z;

	return (Transform4D(c + x * axis.x, axay - s * axis.z, axaz + s * axis.y, 0.0F,
						axay + s * axis.z, c + y * axis.y, ayaz - s * axis.x, 0.0F,
						axaz - s * axis.y, ayaz + s * axis.x, c + z * axis.z, 0.0F));
}

Transform4D Transform4D::MakeReflection(const Vector3D& a)
{
	float x = a.x * -2.0F;
	float y = a.y * -2.0F;
	float z = a.z * -2.0F;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Transform4D(x * a.x + 1.0F, axay, axaz, 0.0F,
						axay, y * a.y + 1.0F, ayaz, 0.0F,
						axaz, ayaz, z * a.z + 1.0F, 0.0F));
}

Transform4D Transform4D::MakeInvolution(const Vector3D& a)
{
	float x = a.x * 2.0F;
	float y = a.y * 2.0F;
	float z = a.z * 2.0F;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Transform4D(x * a.x - 1.0F, axay, axaz, 0.0F,
						axay, y * a.y - 1.0F, ayaz, 0.0F,
						axaz, ayaz, z * a.z - 1.0F, 0.0F));
}

Transform4D Transform4D::MakeReflection(const Trivector4D& plane)
{
	float x = plane.x * -2.0F;
	float y = plane.y * -2.0F;
	float z = plane.z * -2.0F;
	float nxny = x * plane.y;
	float nxnz = x * plane.z;
	float nynz = y * plane.z;

	return (Transform4D(x * plane.x + 1.0F, nxny, nxnz, x * plane.w,
						nxny, y * plane.y + 1.0F, nynz, y * plane.w,
						nxnz, nynz, z * plane.z + 1.0F, z * plane.w));
}

Transform4D Transform4D::MakeScaleX(float sx)
{
	return (Transform4D(sx, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F));
}

Transform4D Transform4D::MakeScaleY(float sy)
{
	return (Transform4D(1.0F, 0.0F, 0.0F, 0.0F, 0.0F, sy, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F));
}

Transform4D Transform4D::MakeScaleZ(float sz)
{
	return (Transform4D(1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, sz, 0.0F));
}

Transform4D Transform4D::MakeScale(float scale)
{
	return (Transform4D(scale, 0.0F, 0.0F, 0.0F, 0.0F, scale, 0.0F, 0.0F, 0.0F, 0.0F, scale, 0.0F));
}

Transform4D Transform4D::MakeScale(float sx, float sy, float sz)
{
	return (Transform4D(sx, 0.0F, 0.0F, 0.0F, 0.0F, sy, 0.0F, 0.0F, 0.0F, 0.0F, sz, 0.0F));
}

Transform4D Transform4D::MakeScale(float scale, const Vector3D& a)
{
	scale -= 1.0F;
	float x = a.x * scale;
	float y = a.y * scale;
	float z = a.z * scale;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Transform4D(x * a.x + 1.0F, axay, axaz, 0.0F,
						axay, y * a.y + 1.0F, ayaz, 0.0F,
						axaz, ayaz, z * a.z + 1.0F, 0.0F));
}

Transform4D Transform4D::MakeSkew(float angle, const Vector3D& a, const Vector3D& b)
{
	float t = Tan(angle);
	float x = a.x * t;
	float y = a.y * t;
	float z = a.z * t;

	return (Transform4D(x * b.x + 1.0F, x * b.y, x * b.z, 0.0F,
						y * b.x, y * b.y + 1.0F, y * b.z, 0.0F,
						z * b.x, z * b.y, z * b.z + 1.0F, 0.0F));
}

Transform4D Transform4D::MakeTranslation(const Vector3D& dv)
{
	return (Transform4D(1.0F, 0.0F, 0.0F, dv.x, 0.0F, 1.0F, 0.0F, dv.y, 0.0F, 0.0F, 1.0F, dv.z));
}


Transform4D Terathon::operator *(const Transform4D& m1, const Transform4D& m2)
{
	#ifndef TERATHON_NO_SIMD

		Transform4D		result;

		vec_float a = VecLoad(&m1(0,0));
		vec_float b = VecLoad(&m1(0,1));
		vec_float c = VecLoad(&m1(0,2));
		VecStore(VecTransformVector3D(a, b, c, VecLoad(&m2(0,0))), &result(0,0));
		VecStore(VecTransformVector3D(a, b, c, VecLoad(&m2(0,1))), &result(0,1));
		VecStore(VecTransformVector3D(a, b, c, VecLoad(&m2(0,2))), &result(0,2));
		VecStore(VecTransformPoint3D(a, b, c, VecLoad(&m1(0,3)), VecLoad(&m2(0,3))), &result(0,3));

		return (result);

	#else

		return (Transform4D(m1(0,0) * m2(0,0) + m1(0,1) * m2(1,0) + m1(0,2) * m2(2,0),
							m1(0,0) * m2(0,1) + m1(0,1) * m2(1,1) + m1(0,2) * m2(2,1),
							m1(0,0) * m2(0,2) + m1(0,1) * m2(1,2) + m1(0,2) * m2(2,2),
							m1(0,0) * m2(0,3) + m1(0,1) * m2(1,3) + m1(0,2) * m2(2,3) + m1(0,3),
							m1(1,0) * m2(0,0) + m1(1,1) * m2(1,0) + m1(1,2) * m2(2,0),
							m1(1,0) * m2(0,1) + m1(1,1) * m2(1,1) + m1(1,2) * m2(2,1),
							m1(1,0) * m2(0,2) + m1(1,1) * m2(1,2) + m1(1,2) * m2(2,2),
							m1(1,0) * m2(0,3) + m1(1,1) * m2(1,3) + m1(1,2) * m2(2,3) + m1(1,3),
							m1(2,0) * m2(0,0) + m1(2,1) * m2(1,0) + m1(2,2) * m2(2,0),
							m1(2,0) * m2(0,1) + m1(2,1) * m2(1,1) + m1(2,2) * m2(2,1),
							m1(2,0) * m2(0,2) + m1(2,1) * m2(1,2) + m1(2,2) * m2(2,2),
							m1(2,0) * m2(0,3) + m1(2,1) * m2(1,3) + m1(2,2) * m2(2,3) + m1(2,3)));

	#endif
}

Matrix4D Terathon::operator *(const Matrix4D& m1, const Transform4D& m2)
{
	#ifndef TERATHON_NO_SIMD

		Matrix4D	result;

		vec_float a = VecLoad(&m1(0,0));
		vec_float b = VecLoad(&m1(0,1));
		vec_float c = VecLoad(&m1(0,2));
		VecStore(VecTransformVector3D(a, b, c, VecLoad(&m2(0,0))), &result(0,0));
		VecStore(VecTransformVector3D(a, b, c, VecLoad(&m2(0,1))), &result(0,1));
		VecStore(VecTransformVector3D(a, b, c, VecLoad(&m2(0,2))), &result(0,2));
		VecStore(VecTransformPoint3D(a, b, c, VecLoad(&m1(0,3)), VecLoad(&m2(0,3))), &result(0,3));

		return (result);

	#else

		return (Matrix4D(m1(0,0) * m2(0,0) + m1(0,1) * m2(1,0) + m1(0,2) * m2(2,0),
						 m1(0,0) * m2(0,1) + m1(0,1) * m2(1,1) + m1(0,2) * m2(2,1),
						 m1(0,0) * m2(0,2) + m1(0,1) * m2(1,2) + m1(0,2) * m2(2,2),
						 m1(0,0) * m2(0,3) + m1(0,1) * m2(1,3) + m1(0,2) * m2(2,3) + m1(0,3),
						 m1(1,0) * m2(0,0) + m1(1,1) * m2(1,0) + m1(1,2) * m2(2,0),
						 m1(1,0) * m2(0,1) + m1(1,1) * m2(1,1) + m1(1,2) * m2(2,1),
						 m1(1,0) * m2(0,2) + m1(1,1) * m2(1,2) + m1(1,2) * m2(2,2),
						 m1(1,0) * m2(0,3) + m1(1,1) * m2(1,3) + m1(1,2) * m2(2,3) + m1(1,3),
						 m1(2,0) * m2(0,0) + m1(2,1) * m2(1,0) + m1(2,2) * m2(2,0),
						 m1(2,0) * m2(0,1) + m1(2,1) * m2(1,1) + m1(2,2) * m2(2,1),
						 m1(2,0) * m2(0,2) + m1(2,1) * m2(1,2) + m1(2,2) * m2(2,2),
						 m1(2,0) * m2(0,3) + m1(2,1) * m2(1,3) + m1(2,2) * m2(2,3) + m1(2,3),
						 m1(3,0) * m2(0,0) + m1(3,1) * m2(1,0) + m1(3,2) * m2(2,0),
						 m1(3,0) * m2(0,1) + m1(3,1) * m2(1,1) + m1(3,2) * m2(2,1),
						 m1(3,0) * m2(0,2) + m1(3,1) * m2(1,2) + m1(3,2) * m2(2,2),
						 m1(3,0) * m2(0,3) + m1(3,1) * m2(1,3) + m1(3,2) * m2(2,3) + m1(3,3)));

	#endif
}

Matrix4D Terathon::operator *(const Transform4D& m1, const Matrix4D& m2)
{
	return (Matrix4D(m1(0,0) * m2(0,0) + m1(0,1) * m2(1,0) + m1(0,2) * m2(2,0) + m1(0,3) * m2(3,0),
					 m1(0,0) * m2(0,1) + m1(0,1) * m2(1,1) + m1(0,2) * m2(2,1) + m1(0,3) * m2(3,1),
					 m1(0,0) * m2(0,2) + m1(0,1) * m2(1,2) + m1(0,2) * m2(2,2) + m1(0,3) * m2(3,2),
					 m1(0,0) * m2(0,3) + m1(0,1) * m2(1,3) + m1(0,2) * m2(2,3) + m1(0,3) * m2(3,3),
					 m1(1,0) * m2(0,0) + m1(1,1) * m2(1,0) + m1(1,2) * m2(2,0) + m1(1,3) * m2(3,0),
					 m1(1,0) * m2(0,1) + m1(1,1) * m2(1,1) + m1(1,2) * m2(2,1) + m1(1,3) * m2(3,1),
					 m1(1,0) * m2(0,2) + m1(1,1) * m2(1,2) + m1(1,2) * m2(2,2) + m1(1,3) * m2(3,2),
					 m1(1,0) * m2(0,3) + m1(1,1) * m2(1,3) + m1(1,2) * m2(2,3) + m1(1,3) * m2(3,3),
					 m1(2,0) * m2(0,0) + m1(2,1) * m2(1,0) + m1(2,2) * m2(2,0) + m1(2,3) * m2(3,0),
					 m1(2,0) * m2(0,1) + m1(2,1) * m2(1,1) + m1(2,2) * m2(2,1) + m1(2,3) * m2(3,1),
					 m1(2,0) * m2(0,2) + m1(2,1) * m2(1,2) + m1(2,2) * m2(2,2) + m1(2,3) * m2(3,2),
					 m1(2,0) * m2(0,3) + m1(2,1) * m2(1,3) + m1(2,2) * m2(2,3) + m1(2,3) * m2(3,3),
					 m2(3,0), m2(3,1), m2(3,2), m2(3,3)));
}

Vector3D Terathon::operator *(const Transform4D& m, const Vector3D& v)
{
	#ifndef TERATHON_NO_SIMD

		Vector3D	result;

		VecStore3D(VecTransformVector3D(VecLoad(&m(0,0)), VecLoad(&m(0,1)), VecLoad(&m(0,2)), VecLoadUnaligned(&v.x)), &result.x);
		return (result);

	#else

		return (m * v.xyz);

	#endif
}

Bivector3D Terathon::operator *(const Bivector3D& v, const Transform4D& m)
{
	return (v.xyz * m);
}

Point3D Terathon::operator *(const Transform4D& m, const Point3D& p)
{
	#ifndef TERATHON_NO_SIMD

		Point3D		result;

		VecStore3D(VecTransformPoint3D(VecLoad(&m(0,0)), VecLoad(&m(0,1)), VecLoad(&m(0,2)), VecLoad(&m(0,3)), VecLoadUnaligned(&p.x)), &result.x);
		return (result);

	#else

		return (Point3D(m(0,0) * p.x + m(0,1) * p.y + m(0,2) * p.z + m(0,3),
						m(1,0) * p.x + m(1,1) * p.y + m(1,2) * p.z + m(1,3),
						m(2,0) * p.x + m(2,1) * p.y + m(2,2) * p.z + m(2,3)));

	#endif
}

Vector2D Terathon::operator *(const Transform4D& m, const Vector2D& v)
{
	return (Vector2D(m(0,0) * v.x + m(0,1) * v.y,
					 m(1,0) * v.x + m(1,1) * v.y));
}

Point2D Terathon::operator *(const Transform4D& m, const Point2D& p)
{
	return (Point2D(m(0,0) * p.x + m(0,1) * p.y + m(0,3),
					m(1,0) * p.x + m(1,1) * p.y + m(1,3)));
}

Transform4D Terathon::Scale(const Transform4D& m, const Vector3D& v)
{
	return (Transform4D(m(0,0) * v.x, m(0,1) * v.x, m(0,2) * v.x, m(0,3) * v.x,
						m(1,0) * v.y, m(1,1) * v.y, m(1,2) * v.y, m(1,3) * v.y,
						m(2,0) * v.z, m(2,1) * v.z, m(2,2) * v.z, m(2,3) * v.z));
}

Matrix3D Terathon::Transform(const Transform4D& m1, const Matrix3D& m2)
{
	return (Matrix3D(m1(0,0) * m2(0,0) + m1(0,1) * m2(1,0) + m1(0,2) * m2(2,0),
					 m1(0,0) * m2(0,1) + m1(0,1) * m2(1,1) + m1(0,2) * m2(2,1),
					 m1(0,0) * m2(0,2) + m1(0,1) * m2(1,2) + m1(0,2) * m2(2,2),
					 m1(1,0) * m2(0,0) + m1(1,1) * m2(1,0) + m1(1,2) * m2(2,0),
					 m1(1,0) * m2(0,1) + m1(1,1) * m2(1,1) + m1(1,2) * m2(2,1),
					 m1(1,0) * m2(0,2) + m1(1,1) * m2(1,2) + m1(1,2) * m2(2,2),
					 m1(2,0) * m2(0,0) + m1(2,1) * m2(1,0) + m1(2,2) * m2(2,0),
					 m1(2,0) * m2(0,1) + m1(2,1) * m2(1,1) + m1(2,2) * m2(2,1),
					 m1(2,0) * m2(0,2) + m1(2,1) * m2(1,2) + m1(2,2) * m2(2,2)));
}

#ifndef TERATHON_NO_SIMD

	vec_float Terathon::TransformVector3D(const Transform4D& m, vec_float v)
	{
		return (VecTransformVector3D(VecLoad(&m(0,0)), VecLoad(&m(0,1)), VecLoad(&m(0,2)), v));
	}

	vec_float Terathon::TransformPoint3D(const Transform4D& m, vec_float p)
	{
		return (VecTransformPoint3D(VecLoad(&m(0,0)), VecLoad(&m(0,1)), VecLoad(&m(0,2)), VecLoad(&m(0,3)), p));
	}

#endif


float Terathon::Determinant(const Transform4D& m)
{
	return (m(0,0) * (m(1,1) * m(2,2) - m(1,2) * m(2,1)) - m(0,1) * (m(1,0) * m(2,2) - m(1,2) * m(2,0)) + m(0,2) * (m(1,0) * m(2,1) - m(1,1) * m(2,0)));
}

Transform4D Terathon::Inverse(const Transform4D& m)
{
	// See FGED1, Section 2.6.

	#ifdef TERATHON_SSE

		Transform4D		result;

		vec_float a = VecLoad(&m(0,0));
		vec_float b = VecLoad(&m(0,1));
		vec_float c = VecLoad(&m(0,2));
		vec_float d = VecLoad(&m(0,3));

		vec_float t0 = _mm_shuffle_ps(a, b, _MM_SHUFFLE(1, 0, 1, 0));
		vec_float t1 = _mm_shuffle_ps(c, d, _MM_SHUFFLE(1, 0, 1, 0));
		vec_float t2 = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3, 2, 3, 2));
		vec_float t3 = _mm_shuffle_ps(c, d, _MM_SHUFFLE(3, 2, 3, 2));

		a = _mm_shuffle_ps(t0, t1, _MM_SHUFFLE(2, 0, 2, 0));
		b = _mm_shuffle_ps(t0, t1, _MM_SHUFFLE(3, 1, 3, 1));
		c = _mm_shuffle_ps(t2, t3, _MM_SHUFFLE(2, 0, 2, 0));

		vec_float x = VecSmearW(a);
		vec_float y = VecSmearW(b);
		vec_float z = VecSmearW(c);

		vec_float s = VecCross3D(a, b);
		vec_float u = VecSub(VecMul(a, y), VecMul(b, x));

		vec_float invDet = VecSmearX(VecDivScalar(VecLoadScalarConstant<0x3F800000>(), VecDot3D(s, c)));

		s = VecMul(s, invDet);
		u = VecMul(u, invDet);
		vec_float v = VecMul(c, invDet);

		VecStore(VecCross3D(b, v), &result(0,0));
		VecStore(VecCross3D(v, a), &result(0,1));
		VecStore(s, &result(0,2));
		VecStore(VecSub(VecCross3D(u, c), VecMul(s, z)), &result(0,3));

		result(3,0) = result(3,1) = result(3,2) = 0.0F;
		result(3,3) = 1.0F;
		return (result);

	#else

		const Vector3D& a = m[0];
		const Vector3D& b = m[1];
		const Vector3D& c = m[2];
		const Vector3D& d = m[3];

		Bivector3D s = a ^ b;
		Bivector3D t = c ^ d;

		float invDet = 1.0F / (s ^ c);

		s *= invDet;
		t *= invDet;
		Vector3D v = c * invDet;

		return (Transform4D(b ^ v, -(b ^ t), v ^ a, a ^ t, s, -(d ^ s)));

	#endif
}

Transform4D Terathon::Adjugate(const Transform4D& m)
{
	#ifdef TERATHON_SSE

		Transform4D		result;

		vec_float a = VecLoad(&m(0,0));
		vec_float b = VecLoad(&m(0,1));
		vec_float c = VecLoad(&m(0,2));
		vec_float d = VecLoad(&m(0,3));

		vec_float t0 = _mm_shuffle_ps(a, b, _MM_SHUFFLE(1, 0, 1, 0));
		vec_float t1 = _mm_shuffle_ps(c, d, _MM_SHUFFLE(1, 0, 1, 0));
		vec_float t2 = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3, 2, 3, 2));
		vec_float t3 = _mm_shuffle_ps(c, d, _MM_SHUFFLE(3, 2, 3, 2));

		vec_float r0 = _mm_shuffle_ps(t0, t1, _MM_SHUFFLE(2, 0, 2, 0));
		vec_float r1 = _mm_shuffle_ps(t0, t1, _MM_SHUFFLE(3, 1, 3, 1));
		vec_float r2 = _mm_shuffle_ps(t2, t3, _MM_SHUFFLE(2, 0, 2, 0));

		vec_float s = VecCross3D(r0, r1);
		vec_float h = VecSub(VecMul(r0, VecSmearW(r1)), VecMul(r1, VecSmearW(r0)));

		VecStore(VecCross3D(r1, r2), &result(0,0));
		VecStore(VecCross3D(r2, r0), &result(0,1));
		VecStore(s, &result(0,2));
		VecStore(VecSub(VecCross3D(h, r2), VecMul(s, VecSmearW(r2))), &result(0,3));

		result(3,0) = result(3,1) = result(3,2) = 0.0F;
		result(3,3) = 1.0F;
		return (result);

	#else

		const Vector3D& a = m[0];
		const Vector3D& b = m[1];
		const Vector3D& c = m[2];
		const Vector3D& d = m[3];

		Bivector3D s = a ^ b;
		Bivector3D t = c ^ d;

		return (Transform4D(b ^ c, -(b ^ t), c ^ a, a ^ t, s, -(d ^ s)));

	#endif
}

Matrix3D Terathon::Adjugate3D(const Transform4D& m)
{
	const Vector3D& a = m[0];
	const Vector3D& b = m[1];
	const Vector3D& c = m[2];

	Bivector3D g0 = b ^ c;
	Bivector3D g1 = c ^ a;
	Bivector3D g2 = a ^ b;

	return (Matrix3D(g0.x, g0.y, g0.z, g1.x, g1.y, g1.z, g2.x, g2.y, g2.z));
}

Vector3D Terathon::InverseTransform(const Transform4D& m, const Vector3D& v)
{
	const Vector3D& a = m[0];
	const Vector3D& b = m[1];
	const Vector3D& c = m[2];

	Bivector3D s = a ^ b;
	float invDet = 1.0F / (s ^ c);

	return (Vector3D((b ^ c ^ v) * invDet, (c ^ a ^ v) * invDet, (s ^ v) * invDet));
}

Point3D Terathon::InverseTransform(const Transform4D& m, const Point3D& p)
{
	const Vector3D& a = m[0];
	const Vector3D& b = m[1];
	const Vector3D& c = m[2];
	const Vector3D& d = m[3];

	Bivector3D s = a ^ b;
	float invDet = 1.0F / (s ^ c);

	Vector3D q = p - d;
	return (Point3D((b ^ c ^ q) * invDet, (c ^ a ^ q) * invDet, (s ^ q) * invDet));
}

Vector3D Terathon::AdjugateTransform(const Transform4D& m, const Vector3D& v)
{
	const Vector3D& a = m[0];
	const Vector3D& b = m[1];
	const Vector3D& c = m[2];

	return (Vector3D(b ^ c ^ v, c ^ a ^ v, a ^ b ^ v));
}

Point3D Terathon::AdjugateTransform(const Transform4D& m, const Point3D& p)
{
	const Vector3D& a = m[0];
	const Vector3D& b = m[1];
	const Vector3D& c = m[2];
	const Vector3D& d = m[3];

	Vector3D q = p - d;
	return (Point3D(b ^ c ^ q, c ^ a ^ q, a ^ b ^ q));
}
