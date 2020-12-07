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


#include "TSMotor.h"


using namespace Terathon;


Transform4D Motor::GetTransformMatrix(void) const
{
	const Bivector3D& r = rotor.GetBivectorPart();
	const Bivector3D& u = screw.GetBivectorPart();
	Vector3D t = !u * rotor.w - !r * screw.w - (u ^ r);
	return (Transform4D(rotor.GetRotationMatrix(), t * 2.0F));
}

Motor& Motor::SetTransformMatrix(const Transform4D& H)
{
	rotor.SetRotationMatrix(H);
	const Bivector3D& r = rotor.GetBivectorPart();
	Vector3D u(H(0,3) * 0.5F, H(1,3) * 0.5F, H(2,3) * 0.5F);
	screw.Set(!u * rotor.w - (!r ^ u), -(u ^ r));
	return (*this);
}


Motor Terathon::operator *(const Motor& a, const Motor& b)
{
	return (Motor(a.rotor.w * b.rotor.x + a.rotor.x * b.rotor.w + a.rotor.y * b.rotor.z - a.rotor.z * b.rotor.y,
	              a.rotor.w * b.rotor.y + a.rotor.y * b.rotor.w + a.rotor.z * b.rotor.x - a.rotor.x * b.rotor.z,
	              a.rotor.w * b.rotor.z + a.rotor.z * b.rotor.w + a.rotor.x * b.rotor.y - a.rotor.y * b.rotor.x,
	              a.rotor.w * b.rotor.w - a.rotor.x * b.rotor.x - a.rotor.y * b.rotor.y - a.rotor.z * b.rotor.z,
	              a.screw.w * b.rotor.z + a.screw.x * b.rotor.y - a.screw.y * b.rotor.x + a.screw.z * b.rotor.w + b.screw.w * a.rotor.z - b.screw.x * a.rotor.y + b.screw.y * a.rotor.x + b.screw.z * a.rotor.w,
	              a.screw.w * b.rotor.x + a.screw.x * b.rotor.w + a.screw.y * b.rotor.z - a.screw.z * b.rotor.y + b.screw.w * a.rotor.x + b.screw.x * a.rotor.w - b.screw.y * a.rotor.z + b.screw.z * a.rotor.y,
	              a.screw.w * b.rotor.y - a.screw.x * b.rotor.z + a.screw.y * b.rotor.w + a.screw.z * b.rotor.x + b.screw.w * a.rotor.y + b.screw.x * a.rotor.z + b.screw.y * a.rotor.w - b.screw.z * a.rotor.x,
	              a.screw.w * b.rotor.w - a.screw.x * b.rotor.x - a.screw.y * b.rotor.y - a.screw.z * b.rotor.z + b.screw.w * a.rotor.w - b.screw.x * a.rotor.x - b.screw.y * a.rotor.y - b.screw.z * a.rotor.z));
}

Motor Terathon::operator *(const Motor& Q, const Quaternion& r)
{
	return (Motor(Q.rotor.w * r.x + Q.rotor.x * r.w + Q.rotor.y * r.z - Q.rotor.z * r.y,
	              Q.rotor.w * r.y - Q.rotor.x * r.z + Q.rotor.y * r.w + Q.rotor.z * r.x,
	              Q.rotor.w * r.z + Q.rotor.x * r.y - Q.rotor.y * r.x + Q.rotor.z * r.w,
	              Q.rotor.w * r.w - Q.rotor.x * r.x - Q.rotor.y * r.y - Q.rotor.z * r.z,
	              Q.screw.w * r.z + Q.screw.x * r.y - Q.screw.y * r.x + Q.screw.z * r.w,
	              Q.screw.w * r.x + Q.screw.x * r.w + Q.screw.y * r.z - Q.screw.z * r.y,
	              Q.screw.w * r.y - Q.screw.x * r.z + Q.screw.y * r.w + Q.screw.z * r.x,
	              Q.screw.w * r.w - Q.screw.x * r.x - Q.screw.y * r.y - Q.screw.z * r.z));
}

Motor Terathon::operator *(const Quaternion& r, const Motor& Q)
{
	return (Motor(r.w * Q.rotor.x + r.x * Q.rotor.w + r.y * Q.rotor.z - r.z * Q.rotor.y,
	              r.w * Q.rotor.y - r.x * Q.rotor.z + r.y * Q.rotor.w + r.z * Q.rotor.x,
	              r.w * Q.rotor.z + r.x * Q.rotor.y - r.y * Q.rotor.x + r.z * Q.rotor.w,
	              r.w * Q.rotor.w - r.x * Q.rotor.x - r.y * Q.rotor.y - r.z * Q.rotor.z,
	              r.w * Q.screw.z + r.x * Q.screw.y - r.y * Q.screw.x + r.z * Q.screw.w,
	              r.w * Q.screw.x + r.x * Q.screw.w + r.y * Q.screw.z - r.z * Q.screw.y,
	              r.w * Q.screw.y - r.x * Q.screw.z + r.y * Q.screw.w + r.z * Q.screw.x,
	              r.w * Q.screw.w - r.x * Q.screw.x - r.y * Q.screw.y - r.z * Q.screw.z));
}

Point3D Terathon::Transform(const Point3D& p, const Motor& Q)
{
	#ifdef TERATHON_SSE

		Point3D		result;

		vec_float q = VecLoadUnaligned(&p.x);
		vec_float r = VecLoadUnaligned(&Q.rotor.x);
		vec_float u = VecLoadUnaligned(&Q.screw.x);

		vec_float r2 = VecMul(r, r);
		vec_float rw = VecSmearW(r);
		vec_float v = VecMadd(q, rw, u);

		vec_float a = VecAdd(VecSub(VecMul(u, rw), VecMul(r, VecSmearW(u))), VecCross3D(r, v));
		vec_float s1 = VecMul(_mm_shuffle_ps(r, r, _MM_SHUFFLE(3, 2, 0, 0)), _mm_shuffle_ps(r, r, _MM_SHUFFLE(3, 0, 1, 1)));
		vec_float s2 = VecMul(_mm_shuffle_ps(r, r, _MM_SHUFFLE(3, 1, 1, 2)), _mm_shuffle_ps(r, r, _MM_SHUFFLE(3, 2, 2, 0)));
		a = VecAdd(VecAdd(VecMul(_mm_shuffle_ps(q, q, _MM_SHUFFLE(3, 0, 0, 1)), s1), VecMul(_mm_shuffle_ps(q, q, _MM_SHUFFLE(3, 1, 2, 2)), s2)), a);
		a = VecNmsub(VecAdd(_mm_shuffle_ps(r2, r2, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(r2, r2, _MM_SHUFFLE(3, 1, 0, 2))), q, a);
		a = VecAdd(VecAdd(a, a), q);

		VecStore3D(a, &result.x);
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
		float rxy = rx * ry;
		float rzx = rz * rx;
		float ryz = ry * rz;

		Vector3D v = !Q.screw.GetBivectorPart() + p * rw;

		return (Point3D(p.x + (ux * rw - rx * uw + (ry * v.z - rz * v.y) + p.y * rxy + p.z * rzx - p.x * (ry2 + rz2)) * 2.0F,
						p.y + (uy * rw - ry * uw + (rz * v.x - rx * v.z) + p.x * rxy + p.z * ryz - p.y * (rz2 + rx2)) * 2.0F,
						p.z + (uz * rw - rz * uw + (rx * v.y - ry * v.x) + p.x * rzx + p.y * ryz - p.z * (rx2 + ry2)) * 2.0F));

	#endif
}

Bivector4D Terathon::Transform(const Bivector4D& L, const Motor& Q)
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
	float rxy = rx * ry;
	float rzx = rz * rx;
	float ryz = ry * rz;
	float rwx = rw * rx;
	float rwy = rw * ry;
	float rwz = rw * rz;

	Vector3D v = L.direction * rw;

	return (Bivector4D(L.direction.x + ((ry * v.z - rz * v.y) + L.direction.y * rxy + L.direction.z * rzx - L.direction.x * (ry2 + rz2)) * 2.0F,
	                   L.direction.y + ((rz * v.x - rx * v.z) + L.direction.x * rxy + L.direction.z * ryz - L.direction.y * (rz2 + rx2)) * 2.0F,
	                   L.direction.z + ((rx * v.y - ry * v.x) + L.direction.x * rzx + L.direction.y * ryz - L.direction.z * (rx2 + ry2)) * 2.0F,
					   L.moment.x + (L.moment.z * (rwy + rzx) - L.moment.y * (rwz + rxy) + L.direction.y * (ux * ry + uy * rx - uz * rw - rz * uw) + L.direction.z * (rz * ux + rw * uy + rx * uz + ry * uw) - L.direction.x * (uy * ry - uz * rz) * 2.0F - L.moment.x * (ry2 + rz2)) * 2.0F,
					   L.moment.y + (L.moment.x * (rwz + rxy) - L.moment.z * (rwx + ryz) + L.direction.z * (uy * rz + uz * ry - ux * rw - rx * uw) + L.direction.x * (ry * ux + rx * uy + rw * uz + rz * uw) - L.direction.y * (ux * rx - uz * rz) * 2.0F - L.moment.y * (rz2 + rx2)) * 2.0F,
					   L.moment.z + (L.moment.y * (rwx + ryz) - L.moment.x * (rwy + rzx) + L.direction.x * (uz * rx + ux * rz - uy * rw - ry * uw) + L.direction.y * (rw * ux + rz * uy + ry * uz + rx * uw) - L.direction.z * (ux * rx - uy * ry) * 2.0F - L.moment.z * (rx2 + ry2)) * 2.0F));
}

Trivector4D Terathon::Transform(const Trivector4D& f, const Motor& Q)
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
	float rxy = rx * ry;
	float rzx = rz * rx;
	float ryz = ry * rz;

	float fr = f.x * rx + f.y * ry + f.z * rz;
	float fu = f.x * ux + f.y * uy + f.z * uz;

	return (Trivector4D(f.x + ((ry * f.z - rz * f.y) * rw + f.y * rxy + f.z * rzx - f.x * (ry2 + rz2)) * 2.0F,
	                    f.y + ((rz * f.x - rx * f.z) * rw + f.x * rxy + f.z * ryz - f.y * (rz2 + rx2)) * 2.0F,
	                    f.z + ((rx * f.y - ry * f.x) * rw + f.x * rzx + f.y * ryz - f.z * (rx2 + ry2)) * 2.0F,
						f.w + (fr * uw - fu * rw + f.x * (ry * uz - rz * uy) + f.y * (rz * ux - rx * uz) + f.z * (rx * uy - ry * ux)) * 2.0F));
}
