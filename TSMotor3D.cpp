//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSMotor3D.h"


using namespace Terathon;


const ConstMotor4D Motor4D::identity = {0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F};


Vector3D Motor4D::GetDirectionX(void) const
{
	float A00 = 1.0F - (v.y * v.y + v.z * v.z) * 2.0F;
	float A01 = v.x * v.y;
	float A02 = v.z * v.x;
	float B01 = v.z * v.w;
	float B20 = v.y * v.w;

	return (Vector3D(A00, (A01 + B01) * 2.0F, (A02 - B20) * 2.0F));
}

Vector3D Motor4D::GetDirectionY(void) const
{
	float A11 = 1.0F - (v.z * v.z + v.x * v.x) * 2.0F;
	float A01 = v.x * v.y;
	float A12 = v.y * v.z;
	float B01 = v.z * v.w;
	float B12 = v.x * v.w;

	return (Vector3D((A01 - B01) * 2.0F, A11, (A12 + B12) * 2.0F));
}

Vector3D Motor4D::GetDirectionZ(void) const
{
	float A22 = 1.0F - (v.x * v.x + v.y * v.y) * 2.0F;
	float A02 = v.z * v.x;
	float A12 = v.y * v.z;
	float B20 = v.y * v.w;
	float B12 = v.x * v.w;

	return (Vector3D((A02 + B20) * 2.0F, (A12 - B12) * 2.0F, A22));
}

Point3D Motor4D::GetPosition(void) const
{
	float A03 = v.y * m.z - v.z * m.y;
	float A13 = v.z * m.x - v.x * m.z;
	float A23 = v.x * m.y - v.y * m.x;
	float B03 = m.x * v.w - v.x * m.w;
	float B13 = m.y * v.w - v.y * m.w;
	float B23 = m.z * v.w - v.z * m.w;

	return (Point3D((A03 + B03) * 2.0F, (A13 + B13) * 2.0F, (A23 + B23) * 2.0F));
}

Transform4D Motor4D::GetTransformMatrix(void) const
{
	float vx2 = v.x * v.x;
	float vy2 = v.y * v.y;
	float vz2 = v.z * v.z;

	float A00 = 1.0F - (vy2 + vz2) * 2.0F;
	float A11 = 1.0F - (vz2 + vx2) * 2.0F;
	float A22 = 1.0F - (vx2 + vy2) * 2.0F;
	float A01 = v.x * v.y;
	float A02 = v.z * v.x;
	float A12 = v.y * v.z;
	float A03 = v.y * m.z - v.z * m.y;
	float A13 = v.z * m.x - v.x * m.z;
	float A23 = v.x * m.y - v.y * m.x;

	float B01 = v.z * v.w;
	float B20 = v.y * v.w;
	float B12 = v.x * v.w;
	float B03 = m.x * v.w - v.x * m.w;
	float B13 = m.y * v.w - v.y * m.w;
	float B23 = m.z * v.w - v.z * m.w;

	return (Transform4D(       A00,         (A01 - B01) * 2.0F, (A02 + B20) * 2.0F, (A03 + B03) * 2.0F,
	                    (A01 + B01) * 2.0F,        A11,         (A12 - B12) * 2.0F, (A13 + B13) * 2.0F,
	                    (A02 - B20) * 2.0F, (A12 + B12) * 2.0F,        A22,         (A23 + B23) * 2.0F));
}

Transform4D Motor4D::GetInverseTransformMatrix(void) const
{
	float vx2 = v.x * v.x;
	float vy2 = v.y * v.y;
	float vz2 = v.z * v.z;

	float A00 = 1.0F - (vy2 + vz2) * 2.0F;
	float A11 = 1.0F - (vz2 + vx2) * 2.0F;
	float A22 = 1.0F - (vx2 + vy2) * 2.0F;
	float A01 = v.x * v.y;
	float A02 = v.z * v.x;
	float A12 = v.y * v.z;
	float A03 = v.y * m.z - v.z * m.y;
	float A13 = v.z * m.x - v.x * m.z;
	float A23 = v.x * m.y - v.y * m.x;

	float B01 = v.z * v.w;
	float B20 = v.y * v.w;
	float B12 = v.x * v.w;
	float B03 = m.x * v.w - v.x * m.w;
	float B13 = m.y * v.w - v.y * m.w;
	float B23 = m.z * v.w - v.z * m.w;

	return (Transform4D(       A00,         (A01 + B01) * 2.0F, (A02 - B20) * 2.0F, (A03 - B03) * 2.0F,
	                    (A01 - B01) * 2.0F,        A11,         (A12 + B12) * 2.0F, (A13 - B13) * 2.0F,
	                    (A02 + B20) * 2.0F, (A12 - B12) * 2.0F,        A22,         (A23 - B23) * 2.0F));
}

void Motor4D::GetTransformMatrices(Transform4D *M, Transform4D *Minv) const
{
	float vx2 = v.x * v.x;
	float vy2 = v.y * v.y;
	float vz2 = v.z * v.z;

	float A00 = 1.0F - (vy2 + vz2) * 2.0F;
	float A11 = 1.0F - (vz2 + vx2) * 2.0F;
	float A22 = 1.0F - (vx2 + vy2) * 2.0F;
	float A01 = v.x * v.y;
	float A02 = v.z * v.x;
	float A12 = v.y * v.z;
	float A03 = v.y * m.z - v.z * m.y;
	float A13 = v.z * m.x - v.x * m.z;
	float A23 = v.x * m.y - v.y * m.x;

	float B01 = v.z * v.w;
	float B20 = v.y * v.w;
	float B12 = v.x * v.w;
	float B03 = m.x * v.w - v.x * m.w;
	float B13 = m.y * v.w - v.y * m.w;
	float B23 = m.z * v.w - v.z * m.w;

	   M->Set(       A00,         (A01 - B01) * 2.0F, (A02 + B20) * 2.0F, (A03 + B03) * 2.0F,
	          (A01 + B01) * 2.0F,        A11,         (A12 - B12) * 2.0F, (A13 + B13) * 2.0F,
	          (A02 - B20) * 2.0F, (A12 + B12) * 2.0F,        A22,         (A23 + B23) * 2.0F);

	Minv->Set(       A00,         (A01 + B01) * 2.0F, (A02 - B20) * 2.0F, (A03 - B03) * 2.0F,
	          (A01 - B01) * 2.0F,        A11,         (A12 + B12) * 2.0F, (A13 - B13) * 2.0F,
	          (A02 + B20) * 2.0F, (A12 - B12) * 2.0F,        A22,         (A23 - B23) * 2.0F);
}

Motor4D& Motor4D::SetTransformMatrix(const Transform4D& M)
{
	v.SetRotationMatrix(M);

	float tx = M(0,3) * 0.5F;
	float ty = M(1,3) * 0.5F;
	float tz = M(2,3) * 0.5F;

	m.x =  v.w * tx + v.z * ty - v.y * tz;
	m.y =  v.w * ty + v.x * tz - v.z * tx;
	m.z =  v.w * tz + v.y * tx - v.x * ty;
	m.w = -v.x * tx - v.y * ty - v.z * tz;

	return (*this);
}


Motor4D Terathon::operator *(const Motor4D& a, const Motor4D& b)
{
	return (Motor4D(a.v.w * b.v.x + a.v.x * b.v.w + a.v.y * b.v.z - a.v.z * b.v.y,
	                a.v.w * b.v.y + a.v.y * b.v.w + a.v.z * b.v.x - a.v.x * b.v.z,
	                a.v.w * b.v.z + a.v.z * b.v.w + a.v.x * b.v.y - a.v.y * b.v.x,
	                a.v.w * b.v.w - a.v.x * b.v.x - a.v.y * b.v.y - a.v.z * b.v.z,
	                a.m.w * b.v.z + a.m.x * b.v.y - a.m.y * b.v.x + a.m.z * b.v.w + b.m.w * a.v.z - b.m.x * a.v.y + b.m.y * a.v.x + b.m.z * a.v.w,
	                a.m.w * b.v.x + a.m.x * b.v.w + a.m.y * b.v.z - a.m.z * b.v.y + b.m.w * a.v.x + b.m.x * a.v.w - b.m.y * a.v.z + b.m.z * a.v.y,
	                a.m.w * b.v.y - a.m.x * b.v.z + a.m.y * b.v.w + a.m.z * b.v.x + b.m.w * a.v.y + b.m.x * a.v.z + b.m.y * a.v.w - b.m.z * a.v.x,
	                a.m.w * b.v.w - a.m.x * b.v.x - a.m.y * b.v.y - a.m.z * b.v.z + b.m.w * a.v.w - b.m.x * a.v.x - b.m.y * a.v.y - b.m.z * a.v.z));
}

Motor4D Terathon::operator *(const Motor4D& Q, const Quaternion& r)
{
	return (Motor4D(Q.v.w * r.x + Q.v.x * r.w + Q.v.y * r.z - Q.v.z * r.y,
	                Q.v.w * r.y - Q.v.x * r.z + Q.v.y * r.w + Q.v.z * r.x,
	                Q.v.w * r.z + Q.v.x * r.y - Q.v.y * r.x + Q.v.z * r.w,
	                Q.v.w * r.w - Q.v.x * r.x - Q.v.y * r.y - Q.v.z * r.z,
	                Q.m.w * r.z + Q.m.x * r.y - Q.m.y * r.x + Q.m.z * r.w,
	                Q.m.w * r.x + Q.m.x * r.w + Q.m.y * r.z - Q.m.z * r.y,
	                Q.m.w * r.y - Q.m.x * r.z + Q.m.y * r.w + Q.m.z * r.x,
	                Q.m.w * r.w - Q.m.x * r.x - Q.m.y * r.y - Q.m.z * r.z));
}

Motor4D Terathon::operator *(const Quaternion& r, const Motor4D& Q)
{
	return (Motor4D(r.w * Q.v.x + r.x * Q.v.w + r.y * Q.v.z - r.z * Q.v.y,
	                r.w * Q.v.y - r.x * Q.v.z + r.y * Q.v.w + r.z * Q.v.x,
	                r.w * Q.v.z + r.x * Q.v.y - r.y * Q.v.x + r.z * Q.v.w,
	                r.w * Q.v.w - r.x * Q.v.x - r.y * Q.v.y - r.z * Q.v.z,
	                r.w * Q.m.z + r.x * Q.m.y - r.y * Q.m.x + r.z * Q.m.w,
	                r.w * Q.m.x + r.x * Q.m.w + r.y * Q.m.z - r.z * Q.m.y,
	                r.w * Q.m.y - r.x * Q.m.z + r.y * Q.m.w + r.z * Q.m.x,
	                r.w * Q.m.w - r.x * Q.m.x - r.y * Q.m.y - r.z * Q.m.z));
}

Motor4D Terathon::Sqrt(const Motor4D& Q)
{
	float b = InverseSqrt(Q.v.w * 2.0F + 2.0F);
	float a = -Q.m.w * (b * b);

	return (Motor4D(Q.v.x * b, Q.v.y * b, Q.v.z * b, Q.v.w * b + b, (Q.v.x * a + Q.m.x) * b, (Q.v.y * a + Q.m.y) * b, (Q.v.z * a + Q.m.z) * b, Q.m.w * (b * 0.5F)));
}

Vector4D Terathon::Transform(const Vector4D& p, const Motor4D& Q)
{
	float vx2 = Q.v.x * Q.v.x;
	float vy2 = Q.v.y * Q.v.y;
	float vz2 = Q.v.z * Q.v.z;
	float vyvz = Q.v.y * Q.v.z;
	float vzvx = Q.v.z * Q.v.x;
	float vxvy = Q.v.x * Q.v.y;
	float vxvw = Q.v.x * Q.v.w;
	float vyvw = Q.v.y * Q.v.w;
	float vzvw = Q.v.z * Q.v.w;

	return (Vector4D(p.x + ((Q.m.x * Q.v.w - Q.v.x * Q.m.w + Q.v.y * Q.m.z - Q.v.z * Q.m.y) * p.w + p.y * (vxvy - vzvw) + p.z * (vzvx + vyvw) - p.x * (vy2 + vz2)) * 2.0F,
	                 p.y + ((Q.m.y * Q.v.w - Q.v.y * Q.m.w + Q.v.z * Q.m.x - Q.v.x * Q.m.z) * p.w + p.z * (vyvz - vxvw) + p.x * (vxvy + vzvw) - p.y * (vz2 + vx2)) * 2.0F,
	                 p.z + ((Q.m.z * Q.v.w - Q.v.z * Q.m.w + Q.v.x * Q.m.y - Q.v.y * Q.m.x) * p.w + p.x * (vzvx - vyvw) + p.y * (vyvz + vxvw) - p.z * (vx2 + vy2)) * 2.0F,
					 p.w));
}

Point3D Terathon::Transform(const Point3D& p, const Motor4D& Q)
{
	#ifdef TERATHON_SSE

		Point3D		result;

		vec_float q = VecLoadUnaligned(&p.x);
		vec_float v = VecLoadUnaligned(&Q.v.x);
		vec_float m = VecLoadUnaligned(&Q.m.x);

		vec_float v2 = v * v;
		vec_float vw = VecSmearW(v);
		vec_float k = VecMadd(q, vw, m);

		vec_float a = m * vw - v * VecSmearW(m) + VecCross3D(v, k);
		vec_float s1 = VecShuffle<3,2,0,0>(v, v) * VecShuffle<3,0,1,1>(v, v);
		vec_float s2 = VecShuffle<3,1,1,2>(v, v) * VecShuffle<3,2,2,0>(v, v);
		a = VecMadd(VecShuffle<3,0,0,1>(q, q), s1, VecShuffle<3,1,2,2>(q, q) * s2) + a;
		a = VecNmsub(VecShuffle<3,0,2,1>(v2, v2) + VecShuffle<3,1,0,2>(v2, v2), q, a);

		VecStore3D(a + a + q, &result.x);
		return (result);

	#else

		float vx2 = Q.v.x * Q.v.x;
		float vy2 = Q.v.y * Q.v.y;
		float vz2 = Q.v.z * Q.v.z;
		float vyvz = Q.v.y * Q.v.z;
		float vzvx = Q.v.z * Q.v.x;
		float vxvy = Q.v.x * Q.v.y;

		Vector3D k = !Q.m.GetBivectorPart() + p * Q.v.w;

		return (Point3D(p.x + (Q.m.x * Q.v.w - Q.v.x * Q.m.w + (Q.v.y * k.z - Q.v.z * k.y) + p.y * vxvy + p.z * vzvx - p.x * (vy2 + vz2)) * 2.0F,
		                p.y + (Q.m.y * Q.v.w - Q.v.y * Q.m.w + (Q.v.z * k.x - Q.v.x * k.z) + p.x * vxvy + p.z * vyvz - p.y * (vz2 + vx2)) * 2.0F,
		                p.z + (Q.m.z * Q.v.w - Q.v.z * Q.m.w + (Q.v.x * k.y - Q.v.y * k.x) + p.x * vzvx + p.y * vyvz - p.z * (vx2 + vy2)) * 2.0F));

	#endif
}

Line3D Terathon::Transform(const Line3D& l, const Motor4D& Q)
{
	float vx2 = Q.v.x * Q.v.x;
	float vy2 = Q.v.y * Q.v.y;
	float vz2 = Q.v.z * Q.v.z;
	float vyvz = Q.v.y * Q.v.z;
	float vzvx = Q.v.z * Q.v.x;
	float vxvy = Q.v.x * Q.v.y;
	float vxvw = Q.v.x * Q.v.w;
	float vyvw = Q.v.y * Q.v.w;
	float vzvw = Q.v.z * Q.v.w;

	return (Line3D(l.v.x + ((vyvw * l.v.z - vzvw * l.v.y) + l.v.y * vxvy + l.v.z * vzvx - l.v.x * (vy2 + vz2)) * 2.0F,
	               l.v.y + ((vzvw * l.v.x - vxvw * l.v.z) + l.v.x * vxvy + l.v.z * vyvz - l.v.y * (vz2 + vx2)) * 2.0F,
	               l.v.z + ((vxvw * l.v.y - vyvw * l.v.x) + l.v.x * vzvx + l.v.y * vyvz - l.v.z * (vx2 + vy2)) * 2.0F,
	               l.m.x + (l.m.z * (vyvw + vzvx) - l.m.y * (vzvw + vxvy) + l.v.y * (Q.m.x * Q.v.y + Q.m.y * Q.v.x - Q.m.z * Q.v.w - Q.v.z * Q.m.w) + l.v.z * (Q.v.z * Q.m.x + Q.v.w * Q.m.y + Q.v.x * Q.m.z + Q.v.y * Q.m.w) - l.v.x * (Q.m.y * Q.v.y - Q.m.z * Q.v.z) * 2.0F - l.m.x * (vy2 + vz2)) * 2.0F,
	               l.m.y + (l.m.x * (vzvw + vxvy) - l.m.z * (vxvw + vyvz) + l.v.z * (Q.m.y * Q.v.z + Q.m.z * Q.v.y - Q.m.x * Q.v.w - Q.v.x * Q.m.w) + l.v.x * (Q.v.y * Q.m.x + Q.v.x * Q.m.y + Q.v.w * Q.m.z + Q.v.z * Q.m.w) - l.v.y * (Q.m.x * Q.v.x - Q.m.z * Q.v.z) * 2.0F - l.m.y * (vz2 + vx2)) * 2.0F,
	               l.m.z + (l.m.y * (vxvw + vyvz) - l.m.x * (vyvw + vzvx) + l.v.x * (Q.m.z * Q.v.x + Q.m.x * Q.v.z - Q.m.y * Q.v.w - Q.v.y * Q.m.w) + l.v.y * (Q.v.w * Q.m.x + Q.v.z * Q.m.y + Q.v.y * Q.m.z + Q.v.x * Q.m.w) - l.v.z * (Q.m.x * Q.v.x - Q.m.y * Q.v.y) * 2.0F - l.m.z * (vx2 + vy2)) * 2.0F));
}

Plane3D Terathon::Transform(const Plane3D& g, const Motor4D& Q)
{
	float vx2 = Q.v.x * Q.v.x;
	float vy2 = Q.v.y * Q.v.y;
	float vz2 = Q.v.z * Q.v.z;
	float vyvz = Q.v.y * Q.v.z;
	float vzvx = Q.v.z * Q.v.x;
	float vxvy = Q.v.x * Q.v.y;

	float gv = g.x * Q.v.x + g.y * Q.v.y + g.z * Q.v.z;
	float gm = g.x * Q.m.x + g.y * Q.m.y + g.z * Q.m.z;

	return (Plane3D(g.x + ((Q.v.y * g.z - Q.v.z * g.y) * Q.v.w + g.y * vxvy + g.z * vzvx - g.x * (vy2 + vz2)) * 2.0F,
	                g.y + ((Q.v.z * g.x - Q.v.x * g.z) * Q.v.w + g.x * vxvy + g.z * vyvz - g.y * (vz2 + vx2)) * 2.0F,
	                g.z + ((Q.v.x * g.y - Q.v.y * g.x) * Q.v.w + g.x * vzvx + g.y * vyvz - g.z * (vx2 + vy2)) * 2.0F,
	                g.w + (gv * Q.m.w - gm * Q.v.w + g.x * (Q.v.y * Q.m.z - Q.v.z * Q.m.y) + g.y * (Q.v.z * Q.m.x - Q.v.x * Q.m.z) + g.z * (Q.v.x * Q.m.y - Q.v.y * Q.m.x)) * 2.0F));
}
