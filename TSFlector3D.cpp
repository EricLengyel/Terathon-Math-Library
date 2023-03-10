//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSFlector3D.h"
#include "TSMotor3D.h"


using namespace Terathon;


Transform4D Flector4D::GetTransformMatrix(void) const
{
	float sx = point.x;
	float sy = point.y;
	float sz = point.z;
	float sw = point.w;
	float hx = plane.x;
	float hy = plane.y;
	float hz = plane.z;
	float hw = plane.w;
	float hx2 = hx * hx;
	float hy2 = hy * hy;
	float hz2 = hz * hz;

	float A00 = (hy2 + hz2) * 2.0F - 1.0F;
	float A11 = (hz2 + hx2) * 2.0F - 1.0F;
	float A22 = (hx2 + hy2) * 2.0F - 1.0F;
	float A01 = hx * hy * -2.0F;
	float A02 = hz * hx * -2.0F;
	float A12 = hy * hz * -2.0F;
	float A03 = sx * sw - hx * hw;
	float A13 = sy * sw - hy * hw;
	float A23 = sz * sw - hz * hw;

	float B01 = hz * sw * 2.0F;
	float B20 = hy * sw * 2.0F;
	float B12 = hx * sw * 2.0F;
	float B03 = hy * sz - hz * sy;
	float B13 = hz * sx - hx * sz;
	float B23 = hx * sy - hy * sx;

	return (Transform4D(   A00,    A01 + B01, A02 - B20, (A03 + B03) * 2.0F,
	                    A01 - B01,    A11,    A12 + B12, (A13 + B13) * 2.0F,
	                    A02 + B20, A12 - B12,    A22,    (A23 + B23) * 2.0F));
}

Transform4D Flector4D::GetInverseTransformMatrix(void) const
{
	float sx = point.x;
	float sy = point.y;
	float sz = point.z;
	float sw = point.w;
	float hx = plane.x;
	float hy = plane.y;
	float hz = plane.z;
	float hw = plane.w;
	float hx2 = hx * hx;
	float hy2 = hy * hy;
	float hz2 = hz * hz;

	float A00 = (hy2 + hz2) * 2.0F - 1.0F;
	float A11 = (hz2 + hx2) * 2.0F - 1.0F;
	float A22 = (hx2 + hy2) * 2.0F - 1.0F;
	float A01 = hx * hy * -2.0F;
	float A02 = hz * hx * -2.0F;
	float A12 = hy * hz * -2.0F;
	float A03 = sx * sw - hx * hw;
	float A13 = sy * sw - hy * hw;
	float A23 = sz * sw - hz * hw;

	float B01 = hz * sw * 2.0F;
	float B20 = hy * sw * 2.0F;
	float B12 = hx * sw * 2.0F;
	float B03 = hy * sz - hz * sy;
	float B13 = hz * sx - hx * sz;
	float B23 = hx * sy - hy * sx;

	return (Transform4D(   A00,    A01 - B01, A02 + B20, (A03 - B03) * 2.0F,
	                    A01 + B01,    A11,    A12 - B12, (A13 - B13) * 2.0F,
	                    A02 - B20, A12 + B12,    A22,    (A23 - B23) * 2.0F));
}

void Flector4D::GetTransformMatrices(Transform4D *M, Transform4D *Minv) const
{
	float sx = point.x;
	float sy = point.y;
	float sz = point.z;
	float sw = point.w;
	float hx = plane.x;
	float hy = plane.y;
	float hz = plane.z;
	float hw = plane.w;
	float hx2 = hx * hx;
	float hy2 = hy * hy;
	float hz2 = hz * hz;

	float A00 = (hy2 + hz2) * 2.0F - 1.0F;
	float A11 = (hz2 + hx2) * 2.0F - 1.0F;
	float A22 = (hx2 + hy2) * 2.0F - 1.0F;
	float A01 = hx * hy * -2.0F;
	float A02 = hz * hx * -2.0F;
	float A12 = hy * hz * -2.0F;
	float A03 = sx * sw - hx * hw;
	float A13 = sy * sw - hy * hw;
	float A23 = sz * sw - hz * hw;

	float B01 = hz * sw * 2.0F;
	float B20 = hy * sw * 2.0F;
	float B12 = hx * sw * 2.0F;
	float B03 = hy * sz - hz * sy;
	float B13 = hz * sx - hx * sz;
	float B23 = hx * sy - hy * sx;

	   M->Set(   A00,    A01 + B01, A02 - B20, (A03 + B03) * 2.0F,
	          A01 - B01,    A11,    A12 + B12, (A13 + B13) * 2.0F,
	          A02 + B20, A12 - B12,    A22,    (A23 + B23) * 2.0F);

	Minv->Set(   A00,    A01 - B01, A02 + B20, (A03 - B03) * 2.0F,
	          A01 + B01,    A11,    A12 - B12, (A13 - B13) * 2.0F,
	          A02 - B20, A12 + B12,    A22,    (A23 - B23) * 2.0F);
}

Flector4D& Flector4D::SetTransformMatrix(const Transform4D& M)
{
	float m00 = M(0,0);
	float m11 = M(1,1);
	float m22 = M(2,2);
	float sum = m00 + m11 + m22;

	if (sum < 0.0F)
	{
		point.w = Sqrt(1.0F - sum) * 0.5F;
		float f = -0.25F / point.w;

		plane.x = (M(2,1) - M(1,2)) * f;
		plane.y = (M(0,2) - M(2,0)) * f;
		plane.z = (M(1,0) - M(0,1)) * f;
	}
	else if ((m00 < m11) && (m00 < m22))
	{
		plane.x = Sqrt(1.0F - m00 + m11 + m22) * 0.5F;
		float f = -0.25F / plane.x;

		plane.y = (M(1,0) + M(0,1)) * f;
		plane.z = (M(0,2) + M(2,0)) * f;
		point.w = (M(2,1) - M(1,2)) * f;
	}
	else if (m11 < m22)
	{
		plane.y = Sqrt(1.0F - m11 + m22 + m00) * 0.5F;
		float f = -0.25F / plane.y;

		plane.x = (M(1,0) + M(0,1)) * f;
		plane.z = (M(2,1) + M(1,2)) * f;
		point.w = (M(0,2) - M(2,0)) * f;
	}
	else
	{
		plane.z = Sqrt(1.0F - m22 + m00 + m11) * 0.5F;
		float f = -0.25F / plane.z;

		plane.x = (M(0,2) + M(2,0)) * f;
		plane.y = (M(2,1) + M(1,2)) * f;
		point.w = (M(1,0) - M(0,1)) * f;
	}

	float tx = M(0,3) * 0.5F;
	float ty = M(1,3) * 0.5F;
	float tz = M(2,3) * 0.5F;

	float hx = plane.x;
	float hy = plane.y;
	float hz = plane.z;
	float sw = point.w;

	point.x =  sw * tx + hz * ty - hy * tz;
	point.y =  sw * ty + hx * tz - hz * tx;
	point.z =  sw * tz + hy * tx - hx * ty;
	plane.w = -hx * tx - hy * ty - hz * tz;

	return (*this);
}


Motor4D Terathon::operator *(const Flector4D& a, const Flector4D& b)
{
	float px = a.point.x;
	float py = a.point.y;
	float pz = a.point.z;
	float pw = a.point.w;
	float fx = a.plane.x;
	float fy = a.plane.y;
	float fz = a.plane.z;
	float fw = a.plane.w;

	float qx = b.point.x;
	float qy = b.point.y;
	float qz = b.point.z;
	float qw = b.point.w;
	float gx = b.plane.x;
	float gy = b.plane.y;
	float gz = b.plane.z;
	float gw = b.plane.w;

	return (Motor4D(fz * gy - fy * gz - fx * qw - pw * gx,
	                fx * gz - fz * gx - fy * qw - pw * gy,
					fy * gx - fx * gy - fz * qw - pw * gz,
					fx * gx + fy * gy + fz * gz - pw * qw,
	                pz * gy - py * gz + fy * qz - fz * qy + fx * gw - fw * gx + pw * qx - px * qw,
					px * gz - pz * gx + fz * qx - fx * qz + fy * gw - fw * gy + pw * qy - py * qw,
					py * gx - px * gy + fx * qy - fy * qx + fz * gw - fw * gz + pw * qz - pz * qw,
					px * gx + py * gy + pz * gz + pw * gw - fx * qx - fy * qy - fz * qz - fw * qw));
}

Flector4D Terathon::operator *(const Flector4D& a, const Motor4D& b)
{
	float sx = a.point.x;
	float sy = a.point.y;
	float sz = a.point.z;
	float sw = a.point.w;
	float hx = a.plane.x;
	float hy = a.plane.y;
	float hz = a.plane.z;
	float hw = a.plane.w;

	float rx = b.rotor.x;
	float ry = b.rotor.y;
	float rz = b.rotor.z;
	float rw = b.rotor.w;
	float ux = b.screw.x;
	float uy = b.screw.y;
	float uz = b.screw.z;
	float uw = b.screw.w;

	return (Flector4D(hz * uy - hy * uz + hw * rx - hx * uw + sy * rz - sz * ry + sx * rw - sw * ux,
	                  hx * uz - hz * ux + hw * ry - hy * uw + sz * rx - sx * rz + sy * rw - sw * uy,
					  hy * ux - hx * uy + hw * rz - hz * uw + sx * ry - sy * rx + sz * rw - sw * uz,
					  sw * rw - hx * rx - hy * ry - hz * rz,
					  hy * rz - hz * ry + sw * rx + hx * rw,
					  hz * rx - hx * rz + sw * ry + hy * rw,
					  hx * ry - hy * rx + sw * rz + hz * rw,
					  hw * rw + hx * ux + hy * uy + hz * uz - sw * uw - sx * rx - sy * ry - sz * rz));
}

Flector4D Terathon::operator *(const Motor4D& a, const Flector4D& b)
{
	float rx = a.rotor.x;
	float ry = a.rotor.y;
	float rz = a.rotor.z;
	float rw = a.rotor.w;
	float ux = a.screw.x;
	float uy = a.screw.y;
	float uz = a.screw.z;
	float uw = a.screw.w;

	float sx = b.point.x;
	float sy = b.point.y;
	float sz = b.point.z;
	float sw = b.point.w;
	float hx = b.plane.x;
	float hy = b.plane.y;
	float hz = b.plane.z;
	float hw = b.plane.w;

	return (Flector4D(hz * uy - hy * uz + hw * rx + hx * uw + sz * ry - sy * rz + sx * rw + sw * ux,
	                  hx * uz - hz * ux + hw * ry + hy * uw + sx * rz - sz * rx + sy * rw + sw * uy,
					  hy * ux - hx * uy + hw * rz + hz * uw + sy * rx - sx * ry + sz * rw + sw * uz,
					  sw * rw - hx * rx - hy * ry - hz * rz,
					  hz * ry - hy * rz + sw * rx + hx * rw,
					  hx * rz - hz * rx + sw * ry + hy * rw,
					  hy * rx - hx * ry + sw * rz + hz * rw,
					  hw * rw - hx * ux - hy * uy - hz * uz + sw * uw - sx * rx - sy * ry - sz * rz));
}

Vector3D Terathon::Transform(const Vector3D& v, const Flector4D& F)
{
	float sw = F.point.w;
	float hx = F.plane.x;
	float hy = F.plane.y;
	float hz = F.plane.z;

	float sw2 = sw * sw;
	float hx2 = hx * hx;
	float hy2 = hy * hy;
	float hz2 = hz * hz;
	float hyhz = hy * hz;
	float hzhx = hz * hx;
	float hxhy = hx * hy;
	float hxsw = hx * sw;
	float hysw = hy * sw;
	float hzsw = hz * sw;

	return (Vector3D(v.x + ((hzsw - hxhy) * v.y - (hzhx + hysw) * v.z - (hx2 + sw2) * v.x) * 2.0F,
	                 v.y + ((hxsw - hyhz) * v.z - (hxhy + hzsw) * v.x - (hy2 + sw2) * v.y) * 2.0F,
	                 v.z + ((hysw - hzhx) * v.x - (hyhz + hxsw) * v.y - (hz2 + sw2) * v.z) * 2.0F));
}

Bivector3D Terathon::Transform(const Bivector3D& v, const Flector4D& F)
{
	float sw = F.point.w;
	float hx = F.plane.x;
	float hy = F.plane.y;
	float hz = F.plane.z;

	float sw2 = sw * sw;
	float hx2 = hx * hx;
	float hy2 = hy * hy;
	float hz2 = hz * hz;
	float hyhz = hy * hz;
	float hzhx = hz * hx;
	float hxhy = hx * hy;
	float hxsw = hx * sw;
	float hysw = hy * sw;
	float hzsw = hz * sw;

	return (Bivector3D(v.x + ((hzsw - hxhy) * v.y - (hzhx + hysw) * v.z - (hx2 + sw2) * v.x) * 2.0F,
	                   v.y + ((hxsw - hyhz) * v.z - (hxhy + hzsw) * v.x - (hy2 + sw2) * v.y) * 2.0F,
	                   v.z + ((hysw - hzhx) * v.x - (hyhz + hxsw) * v.y - (hz2 + sw2) * v.z) * 2.0F));
}

Point3D Terathon::Transform(const Point3D& p, const Flector4D& F)
{
	float sx = F.point.x;
	float sy = F.point.y;
	float sz = F.point.z;
	float sw = F.point.w;
	float hx = F.plane.x;
	float hy = F.plane.y;
	float hz = F.plane.z;
	float hw = F.plane.w;

	float sw2 = sw * sw;
	float hx2 = hx * hx;
	float hy2 = hy * hy;
	float hz2 = hz * hz;
	float hyhz = hy * hz;
	float hzhx = hz * hx;
	float hxhy = hx * hy;
	float hxsw = hx * sw;
	float hysw = hy * sw;
	float hzsw = hz * sw;

	return (Point3D(p.x + ((hzsw - hxhy) * p.y - (hzhx + hysw) * p.z - (hx2 + sw2) * p.x + sx * sw - hx * hw + hy * sz - hz * sy) * 2.0F,
	                p.y + ((hxsw - hyhz) * p.z - (hxhy + hzsw) * p.x - (hy2 + sw2) * p.y + sy * sw - hy * hw + hz * sx - hx * sz) * 2.0F,
	                p.z + ((hysw - hzhx) * p.x - (hyhz + hxsw) * p.y - (hz2 + sw2) * p.z + sz * sw - hz * hw + hx * sy - hy * sx) * 2.0F));
}

Line3D Terathon::Transform(const Line3D& l, const Flector4D& F)
{
	float vx = l.v.x;
	float vy = l.v.y;
	float vz = l.v.z;
	float mx = l.m.x;
	float my = l.m.y;
	float mz = l.m.z;

	float sx = F.point.x;
	float sy = F.point.y;
	float sz = F.point.z;
	float sw = F.point.w;
	float hx = F.plane.x;
	float hy = F.plane.y;
	float hz = F.plane.z;
	float hw = F.plane.w;

	float sw2 = sw * sw;
	float hx2 = hx * hx;
	float hy2 = hy * hy;
	float hz2 = hz * hz;
	float hyhz = hy * hz;
	float hzhx = hz * hx;
	float hxhy = hx * hy;
	float hxsw = hx * sw;
	float hysw = hy * sw;
	float hzsw = hz * sw;

	return (Line3D(vx + ((hxhy - hzsw) * vy + (hzhx + hysw) * vz - (hy2 + hz2) * vx) * 2.0F,
	               vy + ((hyhz - hxsw) * vz + (hxhy + hzsw) * vx - (hz2 + hx2) * vy) * 2.0F,
	               vz + ((hzhx - hysw) * vx + (hyhz + hxsw) * vy - (hx2 + hy2) * vz) * 2.0F,
	               mx + ((hx * sy + hy * sx - sz * sw - hz * hw) * vy + (hx * sz + hz * sx + sy * sw + hy * hw) * vz - (hy * sy + hz * sz) * vx * 2.0F + (hzsw - hxhy) * my - (hzhx + hysw) * mz - (hx2 + sw2) * mx) * 2.0F,
	               my + ((hy * sz + hz * sy - sx * sw - hx * hw) * vz + (hy * sx + hx * sy + sz * sw + hz * hw) * vx - (hz * sz + hx * sx) * vy * 2.0F + (hxsw - hyhz) * mz - (hxhy + hzsw) * mx - (hy2 + sw2) * my) * 2.0F,
	               mz + ((hz * sx + hx * sz - sy * sw - hy * hw) * vx + (hz * sy + hy * sz + sx * sw + hx * hw) * vy - (hx * sx + hy * sy) * vz * 2.0F + (hysw - hzhx) * mx - (hyhz + hxsw) * my - (hz2 + sw2) * mz) * 2.0F));
}

Plane3D Terathon::Transform(const Plane3D& g, const Flector4D& F)
{
	float sx = F.point.x;
	float sy = F.point.y;
	float sz = F.point.z;
	float sw = F.point.w;
	float hx = F.plane.x;
	float hy = F.plane.y;
	float hz = F.plane.z;
	float hw = F.plane.w;

	float sw2 = sw * sw;
	float hx2 = hx * hx;
	float hy2 = hy * hy;
	float hz2 = hz * hz;
	float hyhz = hy * hz;
	float hzhx = hz * hx;
	float hxhy = hx * hy;
	float hxsw = hx * sw;
	float hysw = hy * sw;
	float hzsw = hz * sw;

	return (Plane3D(g.x + ((hzsw - hxhy) * g.y - (hzhx + hysw) * g.z - (hx2 + sw2) * g.x) * 2.0F,
	                g.y + ((hxsw - hyhz) * g.z - (hxhy + hzsw) * g.x - (hy2 + sw2) * g.y) * 2.0F,
	                g.z + ((hysw - hzhx) * g.x - (hyhz + hxsw) * g.y - (hz2 + sw2) * g.z) * 2.0F,
	                g.w + ((sx * sw - hx * hw - hy * sz + hz * sy) * g.x +
	                       (sy * sw - hy * hw - hz * sx + hx * sz) * g.y +
	                       (sz * sw - hz * hw - hx * sy + hy * sx) * g.z) * 2.0F));
}
