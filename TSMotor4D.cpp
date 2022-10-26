//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSMotor4D.h"


using namespace Terathon;


const ConstMotor4D Motor4D::identity = {0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F};


Vector3D Motor4D::GetDirectionX(void) const
{
	float rx = rotor.x;
	float ry = rotor.y;
	float rz = rotor.z;
	float rw = rotor.w;

	float A00 = 1.0F - (ry * ry + rz * rz) * 2.0F;
	float A01 = rx * ry;
	float A02 = rz * rx;
	float B01 = rz * rw;
	float B20 = ry * rw;

	return (Vector3D(A00, (A01 + B01) * 2.0F, (A02 - B20) * 2.0F));
}

Vector3D Motor4D::GetDirectionY(void) const
{
	float rx = rotor.x;
	float ry = rotor.y;
	float rz = rotor.z;
	float rw = rotor.w;

	float A11 = 1.0F - (rz * rz + rx * rx) * 2.0F;
	float A01 = rx * ry;
	float A12 = ry * rz;
	float B01 = rz * rw;
	float B12 = rx * rw;

	return (Vector3D((A01 - B01) * 2.0F, A11, (A12 + B12) * 2.0F));
}

Vector3D Motor4D::GetDirectionZ(void) const
{
	float rx = rotor.x;
	float ry = rotor.y;
	float rz = rotor.z;
	float rw = rotor.w;

	float A22 = 1.0F - (rx * rx + ry * ry) * 2.0F;
	float A02 = rz * rx;
	float A12 = ry * rz;
	float B20 = ry * rw;
	float B12 = rx * rw;

	return (Vector3D((A02 + B20) * 2.0F, (A12 - B12) * 2.0F, A22));
}

Point3D Motor4D::GetPosition(void) const
{
	float rx = rotor.x;
	float ry = rotor.y;
	float rz = rotor.z;
	float rw = rotor.w;
	float ux = screw.x;
	float uy = screw.y;
	float uz = screw.z;
	float uw = screw.w;

	float A03 = ry * uz - rz * uy;
	float A13 = rz * ux - rx * uz;
	float A23 = rx * uy - ry * ux;
	float B03 = ux * rw - rx * uw;
	float B13 = uy * rw - ry * uw;
	float B23 = uz * rw - rz * uw;

	return (Point3D((A03 + B03) * 2.0F, (A13 + B13) * 2.0F, (A23 + B23) * 2.0F));
}

Transform4D Motor4D::GetTransformMatrix(void) const
{
	float rx = rotor.x;
	float ry = rotor.y;
	float rz = rotor.z;
	float rw = rotor.w;
	float ux = screw.x;
	float uy = screw.y;
	float uz = screw.z;
	float uw = screw.w;
	float rx2 = rx * rx;
	float ry2 = ry * ry;
	float rz2 = rz * rz;

	float A00 = 1.0F - (ry2 + rz2) * 2.0F;
	float A11 = 1.0F - (rz2 + rx2) * 2.0F;
	float A22 = 1.0F - (rx2 + ry2) * 2.0F;
	float A01 = rx * ry;
	float A02 = rz * rx;
	float A12 = ry * rz;
	float A03 = ry * uz - rz * uy;
	float A13 = rz * ux - rx * uz;
	float A23 = rx * uy - ry * ux;

	float B01 = rz * rw;
	float B20 = ry * rw;
	float B12 = rx * rw;
	float B03 = ux * rw - rx * uw;
	float B13 = uy * rw - ry * uw;
	float B23 = uz * rw - rz * uw;

	return (Transform4D(       A00,         (A01 - B01) * 2.0F, (A02 + B20) * 2.0F, (A03 + B03) * 2.0F,
	                    (A01 + B01) * 2.0F,        A11,         (A12 - B12) * 2.0F, (A13 + B13) * 2.0F,
	                    (A02 - B20) * 2.0F, (A12 + B12) * 2.0F,        A22,         (A23 + B23) * 2.0F));
}

Transform4D Motor4D::GetInverseTransformMatrix(void) const
{
	float rx = rotor.x;
	float ry = rotor.y;
	float rz = rotor.z;
	float rw = rotor.w;
	float ux = screw.x;
	float uy = screw.y;
	float uz = screw.z;
	float uw = screw.w;
	float rx2 = rx * rx;
	float ry2 = ry * ry;
	float rz2 = rz * rz;

	float A00 = 1.0F - (ry2 + rz2) * 2.0F;
	float A11 = 1.0F - (rz2 + rx2) * 2.0F;
	float A22 = 1.0F - (rx2 + ry2) * 2.0F;
	float A01 = rx * ry;
	float A02 = rz * rx;
	float A12 = ry * rz;
	float A03 = ry * uz - rz * uy;
	float A13 = rz * ux - rx * uz;
	float A23 = rx * uy - ry * ux;

	float B01 = rz * rw;
	float B20 = ry * rw;
	float B12 = rx * rw;
	float B03 = ux * rw - rx * uw;
	float B13 = uy * rw - ry * uw;
	float B23 = uz * rw - rz * uw;

	return (Transform4D(       A00,         (A01 + B01) * 2.0F, (A02 - B20) * 2.0F, (A03 - B03) * 2.0F,
	                    (A01 - B01) * 2.0F,        A11,         (A12 + B12) * 2.0F, (A13 - B13) * 2.0F,
	                    (A02 + B20) * 2.0F, (A12 - B12) * 2.0F,        A22,         (A23 - B23) * 2.0F));
}

void Motor4D::GetTransformMatrices(Transform4D *M, Transform4D *Minv) const
{
	float rx = rotor.x;
	float ry = rotor.y;
	float rz = rotor.z;
	float rw = rotor.w;
	float ux = screw.x;
	float uy = screw.y;
	float uz = screw.z;
	float uw = screw.w;
	float rx2 = rx * rx;
	float ry2 = ry * ry;
	float rz2 = rz * rz;

	float A00 = 1.0F - (ry2 + rz2) * 2.0F;
	float A11 = 1.0F - (rz2 + rx2) * 2.0F;
	float A22 = 1.0F - (rx2 + ry2) * 2.0F;
	float A01 = rx * ry;
	float A02 = rz * rx;
	float A12 = ry * rz;
	float A03 = ry * uz - rz * uy;
	float A13 = rz * ux - rx * uz;
	float A23 = rx * uy - ry * ux;

	float B01 = rz * rw;
	float B20 = ry * rw;
	float B12 = rx * rw;
	float B03 = ux * rw - rx * uw;
	float B13 = uy * rw - ry * uw;
	float B23 = uz * rw - rz * uw;

	   M->Set(       A00,         (A01 - B01) * 2.0F, (A02 + B20) * 2.0F, (A03 + B03) * 2.0F,
	          (A01 + B01) * 2.0F,        A11,         (A12 - B12) * 2.0F, (A13 + B13) * 2.0F,
	          (A02 - B20) * 2.0F, (A12 + B12) * 2.0F,        A22,         (A23 + B23) * 2.0F);

	Minv->Set(       A00,         (A01 + B01) * 2.0F, (A02 - B20) * 2.0F, (A03 - B03) * 2.0F,
	          (A01 - B01) * 2.0F,        A11,         (A12 + B12) * 2.0F, (A13 - B13) * 2.0F,
	          (A02 + B20) * 2.0F, (A12 - B12) * 2.0F,        A22,         (A23 - B23) * 2.0F);
}

Motor4D& Motor4D::SetTransformMatrix(const Transform4D& M)
{
	rotor.SetRotationMatrix(M);

	float tx = M(0,3) * 0.5F;
	float ty = M(1,3) * 0.5F;
	float tz = M(2,3) * 0.5F;

	float rx = rotor.x;
	float ry = rotor.y;
	float rz = rotor.z;
	float rw = rotor.w;

	screw.x =  rw * tx + rz * ty - ry * tz;
	screw.y =  rw * ty + rx * tz - rz * tx;
	screw.z =  rw * tz + ry * tx - rx * ty;
	screw.w = -rx * tx - ry * ty - rz * tz;

	return (*this);
}


Motor4D Terathon::operator *(const Motor4D& a, const Motor4D& b)
{
	return (Motor4D(a.rotor.w * b.rotor.x + a.rotor.x * b.rotor.w + a.rotor.y * b.rotor.z - a.rotor.z * b.rotor.y,
	                a.rotor.w * b.rotor.y + a.rotor.y * b.rotor.w + a.rotor.z * b.rotor.x - a.rotor.x * b.rotor.z,
	                a.rotor.w * b.rotor.z + a.rotor.z * b.rotor.w + a.rotor.x * b.rotor.y - a.rotor.y * b.rotor.x,
	                a.rotor.w * b.rotor.w - a.rotor.x * b.rotor.x - a.rotor.y * b.rotor.y - a.rotor.z * b.rotor.z,
	                a.screw.w * b.rotor.z + a.screw.x * b.rotor.y - a.screw.y * b.rotor.x + a.screw.z * b.rotor.w + b.screw.w * a.rotor.z - b.screw.x * a.rotor.y + b.screw.y * a.rotor.x + b.screw.z * a.rotor.w,
	                a.screw.w * b.rotor.x + a.screw.x * b.rotor.w + a.screw.y * b.rotor.z - a.screw.z * b.rotor.y + b.screw.w * a.rotor.x + b.screw.x * a.rotor.w - b.screw.y * a.rotor.z + b.screw.z * a.rotor.y,
	                a.screw.w * b.rotor.y - a.screw.x * b.rotor.z + a.screw.y * b.rotor.w + a.screw.z * b.rotor.x + b.screw.w * a.rotor.y + b.screw.x * a.rotor.z + b.screw.y * a.rotor.w - b.screw.z * a.rotor.x,
	                a.screw.w * b.rotor.w - a.screw.x * b.rotor.x - a.screw.y * b.rotor.y - a.screw.z * b.rotor.z + b.screw.w * a.rotor.w - b.screw.x * a.rotor.x - b.screw.y * a.rotor.y - b.screw.z * a.rotor.z));
}

Motor4D Terathon::operator *(const Motor4D& Q, const Quaternion& r)
{
	return (Motor4D(Q.rotor.w * r.x + Q.rotor.x * r.w + Q.rotor.y * r.z - Q.rotor.z * r.y,
	                Q.rotor.w * r.y - Q.rotor.x * r.z + Q.rotor.y * r.w + Q.rotor.z * r.x,
	                Q.rotor.w * r.z + Q.rotor.x * r.y - Q.rotor.y * r.x + Q.rotor.z * r.w,
	                Q.rotor.w * r.w - Q.rotor.x * r.x - Q.rotor.y * r.y - Q.rotor.z * r.z,
	                Q.screw.w * r.z + Q.screw.x * r.y - Q.screw.y * r.x + Q.screw.z * r.w,
	                Q.screw.w * r.x + Q.screw.x * r.w + Q.screw.y * r.z - Q.screw.z * r.y,
	                Q.screw.w * r.y - Q.screw.x * r.z + Q.screw.y * r.w + Q.screw.z * r.x,
	                Q.screw.w * r.w - Q.screw.x * r.x - Q.screw.y * r.y - Q.screw.z * r.z));
}

Motor4D Terathon::operator *(const Quaternion& r, const Motor4D& Q)
{
	return (Motor4D(r.w * Q.rotor.x + r.x * Q.rotor.w + r.y * Q.rotor.z - r.z * Q.rotor.y,
	                r.w * Q.rotor.y - r.x * Q.rotor.z + r.y * Q.rotor.w + r.z * Q.rotor.x,
	                r.w * Q.rotor.z + r.x * Q.rotor.y - r.y * Q.rotor.x + r.z * Q.rotor.w,
	                r.w * Q.rotor.w - r.x * Q.rotor.x - r.y * Q.rotor.y - r.z * Q.rotor.z,
	                r.w * Q.screw.z + r.x * Q.screw.y - r.y * Q.screw.x + r.z * Q.screw.w,
	                r.w * Q.screw.x + r.x * Q.screw.w + r.y * Q.screw.z - r.z * Q.screw.y,
	                r.w * Q.screw.y - r.x * Q.screw.z + r.y * Q.screw.w + r.z * Q.screw.x,
	                r.w * Q.screw.w - r.x * Q.screw.x - r.y * Q.screw.y - r.z * Q.screw.z));
}

Motor4D Terathon::Sqrt(const Motor4D& Q)
{
	float rx = Q.rotor.x;
	float ry = Q.rotor.y;
	float rz = Q.rotor.z;
	float rw = Q.rotor.w;
	float ux = Q.screw.x;
	float uy = Q.screw.y;
	float uz = Q.screw.z;
	float uw = Q.screw.w;

	float b = InverseSqrt(rw * 2.0F + 2.0F);
	float a = -uw * (b * b);

	return (Motor4D(rx * b, ry * b, rz * b, rw * b + b, (rx * a + ux) * b, (ry * a + uy) * b, (rz * a + uz) * b, uw * (b * 0.5F)));
}

Point3D Terathon::Transform(const Point3D& p, const Motor4D& Q)
{
	#ifdef TERATHON_SSE

		Point3D		result;

		vec_float q = VecLoadUnaligned(&p.x);
		vec_float r = VecLoadUnaligned(&Q.rotor.x);
		vec_float u = VecLoadUnaligned(&Q.screw.x);

		vec_float r2 = r * r;
		vec_float rw = VecSmearW(r);
		vec_float v = VecMadd(q, rw, u);

		vec_float a = u * rw - r * VecSmearW(u) + VecCross3D(r, v);
		vec_float s1 = VecShuffle<3,2,0,0>(r, r) * VecShuffle<3,0,1,1>(r, r);
		vec_float s2 = VecShuffle<3,1,1,2>(r, r) * VecShuffle<3,2,2,0>(r, r);
		a = VecMadd(VecShuffle<3,0,0,1>(q, q), s1, VecShuffle<3,1,2,2>(q, q) * s2) + a;
		a = VecNmsub(VecShuffle<3,0,2,1>(r2, r2) + VecShuffle<3,1,0,2>(r2, r2), q, a);

		VecStore3D(a + a + q, &result.x);
		return (result);

	#else

		float rx = Q.rotor.x;
		float ry = Q.rotor.y;
		float rz = Q.rotor.z;
		float rw = Q.rotor.w;
		float ux = Q.screw.x;
		float uy = Q.screw.y;
		float uz = Q.screw.z;
		float uw = Q.screw.w;

		float rx2 = rx * rx;
		float ry2 = ry * ry;
		float rz2 = rz * rz;
		float ryrz = ry * rz;
		float rzrx = rz * rx;
		float rxry = rx * ry;

		Vector3D v = !Q.screw.GetBivectorPart() + p * rw;

		return (Point3D(p.x + (ux * rw - rx * uw + (ry * v.z - rz * v.y) + p.y * rxry + p.z * rzrx - p.x * (ry2 + rz2)) * 2.0F,
						p.y + (uy * rw - ry * uw + (rz * v.x - rx * v.z) + p.x * rxry + p.z * ryrz - p.y * (rz2 + rx2)) * 2.0F,
						p.z + (uz * rw - rz * uw + (rx * v.y - ry * v.x) + p.x * rzrx + p.y * ryrz - p.z * (rx2 + ry2)) * 2.0F));

	#endif
}

Bivector4D Terathon::Transform(const Bivector4D& L, const Motor4D& Q)
{
	float vx = L.direction.x;
	float vy = L.direction.y;
	float vz = L.direction.z;
	float mx = L.moment.x;
	float my = L.moment.y;
	float mz = L.moment.z;

	float rx = Q.rotor.x;
	float ry = Q.rotor.y;
	float rz = Q.rotor.z;
	float rw = Q.rotor.w;
	float ux = Q.screw.x;
	float uy = Q.screw.y;
	float uz = Q.screw.z;
	float uw = Q.screw.w;

	float rx2 = rx * rx;
	float ry2 = ry * ry;
	float rz2 = rz * rz;
	float ryrz = ry * rz;
	float rzrx = rz * rx;
	float rxry = rx * ry;
	float rxrw = rx * rw;
	float ryrw = ry * rw;
	float rzrw = rz * rw;

	return (Bivector4D(vx + ((ryrw * vz - rzrw * vy) + vy * rxry + vz * rzrx - vx * (ry2 + rz2)) * 2.0F,
	                   vy + ((rzrw * vx - rxrw * vz) + vx * rxry + vz * ryrz - vy * (rz2 + rx2)) * 2.0F,
	                   vz + ((rxrw * vy - ryrw * vx) + vx * rzrx + vy * ryrz - vz * (rx2 + ry2)) * 2.0F,
					   mx + (mz * (ryrw + rzrx) - my * (rzrw + rxry) + vy * (ux * ry + uy * rx - uz * rw - rz * uw) + vz * (rz * ux + rw * uy + rx * uz + ry * uw) - vx * (uy * ry - uz * rz) * 2.0F - mx * (ry2 + rz2)) * 2.0F,
					   my + (mx * (rzrw + rxry) - mz * (rxrw + ryrz) + vz * (uy * rz + uz * ry - ux * rw - rx * uw) + vx * (ry * ux + rx * uy + rw * uz + rz * uw) - vy * (ux * rx - uz * rz) * 2.0F - my * (rz2 + rx2)) * 2.0F,
					   mz + (my * (rxrw + ryrz) - mx * (ryrw + rzrx) + vx * (uz * rx + ux * rz - uy * rw - ry * uw) + vy * (rw * ux + rz * uy + ry * uz + rx * uw) - vz * (ux * rx - uy * ry) * 2.0F - mz * (rx2 + ry2)) * 2.0F));
}

Trivector4D Terathon::Transform(const Trivector4D& f, const Motor4D& Q)
{
	float rx = Q.rotor.x;
	float ry = Q.rotor.y;
	float rz = Q.rotor.z;
	float rw = Q.rotor.w;
	float ux = Q.screw.x;
	float uy = Q.screw.y;
	float uz = Q.screw.z;
	float uw = Q.screw.w;

	float rx2 = rx * rx;
	float ry2 = ry * ry;
	float rz2 = rz * rz;
	float ryrz = ry * rz;
	float rzrx = rz * rx;
	float rxry = rx * ry;

	float fr = f.x * rx + f.y * ry + f.z * rz;
	float fu = f.x * ux + f.y * uy + f.z * uz;

	return (Trivector4D(f.x + ((ry * f.z - rz * f.y) * rw + f.y * rxry + f.z * rzrx - f.x * (ry2 + rz2)) * 2.0F,
	                    f.y + ((rz * f.x - rx * f.z) * rw + f.x * rxry + f.z * ryrz - f.y * (rz2 + rx2)) * 2.0F,
	                    f.z + ((rx * f.y - ry * f.x) * rw + f.x * rzrx + f.y * ryrz - f.z * (rx2 + ry2)) * 2.0F,
						f.w + (fr * uw - fu * rw + f.x * (ry * uz - rz * uy) + f.y * (rz * ux - rx * uz) + f.z * (rx * uy - ry * ux)) * 2.0F));
}
