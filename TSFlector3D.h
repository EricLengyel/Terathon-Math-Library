//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSFlector3D_h
#define TSFlector3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSLine3D.h"
#include "TSMatrix4D.h"


#define TERATHON_FLECTOR3D 1


namespace Terathon
{
	class Motor4D;


	//# \class	Flector4D		Encapsulates a 4D reflection operator (flector).
	//
	//# The $Flector4D$ class encapsulates a 4D reflection operator (flector).
	//# For more information about flectors, see the <a href="http://projectivegeometricalgebra.org">projective geometric algebra</a> website.
	//
	//# \def	class Flector4D
	//
	//# \ctor	Flector4D();
	//# \ctor	Flector4D(float px, float py, float pz, float pw, float gx, float gy, float gz, float gw);
	//# \ctor	Flector4D(const Vector4D& point, const Plane3D& plane);
	//# \ctor	Flector4D(const Point3D& point, const Plane3D& plane);
	//# \ctor	explicit Flector4D(const Vector4D& point);
	//# \ctor	explicit Flector4D(const Point3D& point);
	//# \ctor	explicit Flector4D(const Plane3D& plane);
	//
	//# \param	px,py,pz,pw		The values of the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
	//# \param	gx,gy,gz,gw		The values of the <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, <b>e</b><sub>124</sub>, and <b>e</b><sub>321</sub> coordinates.
	//# \param	plane			A plane whose entries are copied to the <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, <b>e</b><sub>124</sub>, and <b>e</b><sub>321</sub> coordinates.
	//# \param	point			A point whose entries are copied to the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
	//
	//# \desc
	//# The $Flector4D$ class encapsulates a reflection operator (flector) in the 4D projective geometric algebra.
	//# It has the general form <i>F<sub>px</sub></i><b>e</b><sub>1</sub> + <i>F<sub>py</sub></i><b>e</b><sub>2</sub> + <i>F<sub>pz</sub></i><b>e</b><sub>3</sub> + <i>F<sub>pw</sub></i><b>e</b><sub>4</sub> + <i>F<sub>gx</sub></i><b>e</b><sub>234</sub> + <i>F<sub>gy</sub></i><b>e</b><sub>314</sub> + <i>F<sub>gz</sub></i><b>e</b><sub>124</sub> + <i>F<sub>gw</sub></i><b>e</b><sub>321</sub>.
	//#
	//# The default constructor leaves the components of the flector undefined.
	//# If the point $point$ and plane $plane$ are specified, then their coordinates are assigned to the vector part and trivector part of the flector, respectively.
	//# If only one of the point $point$ and plane $plane$ are specified, then the other part is set to zero.
	//# If the $point$ has type $@Point3D@$, then its <i>w</i> coordinate is assumed to be one.
	//
	//# \operator	Flector4D& operator *=(float n);
	//#				Multiplies by the scalar $n$.
	//
	//# \operator	Flector4D& operator /=(float n);
	//#				Multiplies by the inverse of the scalar $n$.
	//
	//# \action		bool operator ==(const Flector4D& a, const Flector4D& b);
	//#				Returns a boolean value indicating whether the two flectors $a$ and $b$ are equal.
	//
	//# \action		bool operator !=(const Flector4D& a, const Flector4D& b);
	//#				Returns a boolean value indicating whether the two flectors $a$ and $b$ are not equal.
	//
	//# \action		Flector4D operator ~(const Flector4D& F);
	//#				Returns the antireverse of the flector $F$.
	//
	//# \action		Flector4D operator -(const Flector4D& F);
	//#				Returns the negation of the flector $F$.
	//
	//# \action		Flector4D operator *(const Flector4D& F, float n);
	//#				Returns the product of the flector $F$ and the scalar $n$.
	//
	//# \action		Flector4D operator *(float n, const Flector4D& F);
	//#				Returns the product of the flector $F$ and the scalar $n$.
	//
	//# \action		Flector4D operator /(const Flector4D& F, float n);
	//#				Returns the product of the flector $G$ and the inverse of the scalar $n$.
	//
	//# \action		Motor4D operator *(const Flector4D& a, const Flector4D& b);
	//#				Returns the geometric antiproduct of the flectors $a$ and $b$, producing a motor.
	//
	//# \action		Flector4D operator *(const Flector4D& a, const Motor4D& b);
	//#				Returns the geometric antiproduct of the flector $a$ and the motor $b$, producing a flector.
	//
	//# \action		Flector4D operator *(const Motor4D& a, const Flector4D& b);
	//#				Returns the geometric antiproduct of the motor $a$ and the flector $b$, producing a flector.
	//
	//# \action		float BulkNorm(const Flector4D& F);
	//#				Returns the bulk norm of the flector $F$.
	//
	//# \action		float WeightNorm(const Flector4D& F);
	//#				Returns the weight norm of the flector $F$.
	//
	//# \action		Vector3D Transform(const Vector3D& v, const Flector4D& F);
	//#				Transforms the vector $v$ with the flector $F$.
	//
	//# \action		Bivector3D Transform(const Bivector3D& v, const Flector4D& F);
	//#				Transforms the bivector $v$ with the flector $F$.
	//
	//# \action		Vector4D Transform(const Vector4D& p, const Flector4D& F);
	//#				Transforms the point $p$ with the flector $F$.
	//
	//# \action		Point3D Transform(const Point3D& p, const Flector4D& F);
	//#				Transforms the point $p$ with the flector $F$.
	//
	//# \action		Line3D Transform(const Line3D& l, const Flector4D& F);
	//#				Transforms the line $l$ with the flector $F$.
	//
	//# \action		Plane3D Transform(const Plane3D& g, const Flector4D& F);
	//#				Transforms the plane $g$ with the flector $F$.
	//
	//# \also	$@Motor4D@$
	//# \also	$@Point3D@$
	//# \also	$@Line3D@$
	//# \also	$@Plane3D@$


	//# \function	Flector4D::Set		Sets all eight components of a flector.
	//
	//# \ctor	Flector4D& Set(float px, float py, float pz, float pw, float gx, float gy, float gz, float gw);
	//# \ctor	Flector4D& Set(const Vector4D& point, const Plane3D& plane);
	//# \ctor	Flector4D& Set(const Point3D& point, const Plane3D& plane);
	//
	//# \param	px,py,pz,pw		The values of the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
	//# \param	gx,gy,gz,gw		The values of the <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, <b>e</b><sub>124</sub>, and <b>e</b><sub>321</sub> coordinates.
	//# \param	plane			A plane whose entries are copied to the <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, <b>e</b><sub>124</sub>, and <b>e</b><sub>321</sub> coordinates.
	//# \param	point			A point whose entries are copied to the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
	//
	//# \desc
	//# The $Set$ function sets the eight coordinates of a flector.
	//# If the point $point$ and plane $plane$ are specified, then their coordinates are assigned to the vector part and trivector part of the flector, respectively.
	//# If the $point$ has type $@Point3D@$, then its <i>w</i> coordinate is assumed to be one.
	//#
	//# The return value is a reference to the flector object.


	//# \function	Flector4D::Unitize		Unitizes the weight of a flector.
	//
	//# \proto	Flector4D& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a flector by the inverse magnitude of its weight, which is made up of its
	//# <b>e</b><sub>4</sub>, <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, and <b>e</b><sub>124</sub> coordinates.
	//# If these coordinates are all zero, then the result is undefined.
	//#
	//# The return value is a reference to the flector object.


	//# \function	Flector4D::MakeTransflection		Returns a flector that represents a translation and a reflection.
	//
	//# \proto	static Flector4D MakeTransflection(const Vector3D& offset, const Plane3D& plane);
	//
	//# \param	offset		The translation vector.
	//# \param	plane		The unitized reflection plane.
	//
	//# \desc
	//# The $MakeTransflection$ function returns a flector representing a translation by the vector given
	//# by the $offset$ parameter and a reflection through the plane given by the $plane$ parameter.
	//# The resulting flector is unitized.
	//
	//# \also	$@Flector4D::MakeRotoreflection@$


	//# \function	Flector4D::MakeRotoreflection		Returns a flector that represents a rotation and a reflection.
	//
	//# \proto	static Flector4D MakeRotoreflection(float angle, const Line3D& axis, const Plane3D& plane);
	//
	//# \param	angle		The angle of rotation, in radians.
	//# \param	axis		The unitized line about which to rotate.
	//# \param	plane		The unitized reflection plane.
	//
	//# \desc
	//# The $MakeRotoreflection$ function returns a flector representing a rotation through the angle
	//# given by the $angle$ parameter about the line given by the $axis$ parameter and a reflection
	//# through the plane given by the $plane$ parameter.
	//
	//# \also	$@Flector4D::MakeTransflection@$


	//# \function	Flector4D::GetTransformMatrix		Converts a flector to its corresponding 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# \proto	Transform4D GetTransformMatrix(void) const;
	//
	//# \desc
	//# The $GetTransformMatrix$ function converts a flector to the $@Transform4D@$ object that
	//# represents the same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object.
	//
	//# \also	$@Flector4D::GetInverseTransformMatrix@$
	//# \also	$@Flector4D::GetTransformMatrices@$
	//# \also	$@Flector4D::SetTransformMatrix@$
	//# \also	$@Flector4D::MakeTransflection@$
	//# \also	$@Flector4D::MakeRotoreflection@$


	//# \function	Flector4D::GetInverseTransformMatrix	Converts a flector to the inverse of its corresponding 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# \proto	Transform4D GetInverseTransformMatrix(void) const;
	//
	//# \desc
	//# The $GetInverseTransformMatrix$ function converts a flector to the inverse of the $@Transform4D@$ object that
	//# represents the same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object. Such a matrix
	//# correctly transforms a $@Plane3D@$ object when it postmultiplies it.
	//#
	//# This function performs the same amount of computation as the $@Flector4D::GetTransformMatrix@$ function, and is thus
	//# significantly faster than calling the $@Flector4D::GetTransformMatrix@$ function and inverting the result.
	//
	//# \also	$@Flector4D::GetTransformMatrix@$
	//# \also	$@Flector4D::GetTransformMatrices@$
	//# \also	$@Flector4D::SetTransformMatrix@$
	//# \also	$@Flector4D::MakeTransflection@$
	//# \also	$@Flector4D::MakeRotoreflection@$


	//# \function	Flector4D::GetTransformMatrices		Converts a flector to its corresponding 4&#x202F;&times;&#x202F;4 matrix and its inverse simultaneously.
	//
	//# \proto	void GetTransformMatrices(Transform4D *M, Transform4D *Minv) const;
	//
	//# \param	M		A pointer to the location where the transform matrix is returned.
	//# \param	Minv	A pointer to the location where the inverse transform matrix is returned.
	//
	//# \desc
	//# The $GetTransformMatrices$ function converts a flector to the $@Transform4D@$ object that represents the
	//# same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object and stores it in the location
	//# specified by the $M$ parameter. The inverse of this matrix is stored in the location specified by the $Minv$ parameter.
	//#
	//# Calling this function is much faster than making separate calls to the $@Flector4D::GetTransformMatrix@$ and
	//# $@Flector4D::GetInverseTransformMatrix@$ functions.
	//
	//# \also	$@Flector4D::GetTransformMatrix@$
	//# \also	$@Flector4D::GetInverseTransformMatrix@$
	//# \also	$@Flector4D::SetTransformMatrix@$
	//# \also	$@Flector4D::MakeTransflection@$
	//# \also	$@Flector4D::MakeRotoreflection@$


	//# \function	Flector4D::SetTransformMatrix		Converts a 4&#x202F;&times;&#x202F;4 matrix to its corresponding flector.
	//
	//# \proto	Flector4D& SetTransformMatrix(const Transform4D& M);
	//
	//# \param	M		The matrix to convert to a flector.
	//
	//# \desc
	//# The $SetTransformMatrix$ function sets the components of a flector to values that
	//# represent the same improper motion as the one represented by the matrix specified by the $M$ parameter.
	//#
	//# This function expects the matrix $M$ to be orthogonal and have a determinant of &minus;1.
	//# If these conditions are not met, then the results are unlikely to be meaningful.
	//
	//# \also	$@Flector4D::GetTransformMatrix@$
	//# \also	$@Flector4D::GetInverseTransformMatrix@$
	//# \also	$@Flector4D::GetTransformMatrices@$
	//# \also	$@Flector4D::MakeTransflection@$
	//# \also	$@Flector4D::MakeRotoreflection@$


	class Flector4D
	{
		public:

			Vector4D	p;
			Plane3D		g;

			inline Flector4D() = default;

			Flector4D(float px, float py, float pz, float pw, float gx, float gy, float gz, float gw)
			{
				p.Set(px, py, pz, pw);
				g.Set(gx, gy, gz, gw);
			}

			Flector4D(const Vector4D& point, const Plane3D& plane)
			{
				p = point;
				g = plane;
			}

			Flector4D(const Point3D& point, const Plane3D& plane)
			{
				p = point;
				g = plane;
			}

			explicit Flector4D(const Vector4D& point)
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			explicit Flector4D(const Point3D& point)
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			explicit Flector4D(const Plane3D& plane)
			{
				g = plane;
				p.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector4D& Set(float px, float py, float pz, float pw, float gx, float gy, float gz, float gw)
			{
				p.Set(px, py, pz, pw);
				g.Set(gx, gy, gz, gw);
				return (*this);
			}

			void Set(float px, float py, float pz, float pw, float gx, float gy, float gz, float gw) volatile
			{
				p.Set(px, py, pz, pw);
				g.Set(gx, gy, gz, gw);
			}

			Flector4D& Set(const Vector4D& point, const Plane3D& plane)
			{
				p = point;
				g = plane;
				return (*this);
			}

			void Set(const Vector4D& point, const Plane3D& plane) volatile
			{
				p = point;
				g = plane;
			}

			Flector4D& Set(const Point3D& point, const Plane3D& plane)
			{
				p = point;
				g = plane;
				return (*this);
			}

			void Set(const Point3D& point, const Plane3D& plane) volatile
			{
				p = point;
				g = plane;
			}

			Flector4D& operator =(const Flector4D& F)
			{
				p = F.p;
				g = F.g;
				return (*this);
			}

			void operator =(const Flector4D& F) volatile
			{
				p = F.p;
				g = F.g;
			}

			Flector4D& operator =(const Vector4D& point)
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Vector4D& point) volatile
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector4D& operator =(const Point3D& point)
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Point3D& point) volatile
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector4D& operator =(const Plane3D& plane)
			{
				g = plane;
				p.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Plane3D& plane) volatile
			{
				g = plane;
				p.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector4D& operator *=(float n)
			{
				p *= n;
				g *= n;
				return (*this);
			}

			Flector4D& operator /=(float n)
			{
				n = 1.0F / n;
				p *= n;
				g *= n;
				return (*this);
			}

			Flector4D& Unitize(void)
			{
				return (*this *= InverseSqrt(p.w * p.w + g.x * g.x + g.y * g.y + g.z * g.z));
			}

			static Flector4D MakeTransflection(const Vector3D& offset, const Plane3D& plane)
			{
				return (Flector4D((offset.y * plane.z - offset.z * plane.y) * 0.5F, (offset.z * plane.x - offset.x * plane.z) * 0.5F, (offset.x * plane.y - offset.y * plane.x) * 0.5F, 0.0F, plane.x, plane.y, plane.z, plane.w - (offset.x * plane.x + offset.y * plane.y + offset.z * plane.z) * 0.5F));
			}

			static Flector4D MakeRotoreflection(float angle, const Bivector3D& axis, const Plane3D& plane)
			{
				Vector2D t = CosSin(angle * 0.5F);
				float vx = axis.x * t.y;
				float vy = axis.y * t.y;
				float vz = axis.z * t.y;
				return (Flector4D(vx * plane.w, vy * plane.w, vz * plane.w, -vx * plane.x - vy * plane.y - vz * plane.z, t.x * plane.x + vy * plane.z - vz * plane.y, t.x * plane.y + vz * plane.x - vx * plane.z, t.x * plane.z + vx * plane.y - vy * plane.x, t.x * plane.w));
			}

			static Flector4D MakeRotoreflection(float angle, const Line3D& axis, const Plane3D& plane)
			{
				Vector2D t = CosSin(angle * 0.5F);
				float vx = axis.v.x * t.y;
				float vy = axis.v.y * t.y;
				float vz = axis.v.z * t.y;
				float mx = axis.m.x * t.y;
				float my = axis.m.y * t.y;
				float mz = axis.m.z * t.y;

				return (Flector4D(vx * plane.w + my * plane.z - mz * plane.y,
				                  vy * plane.w + mz * plane.x - mx * plane.z,
				                  vz * plane.w + mx * plane.y - my * plane.x,
				                 -vx * plane.x - vy * plane.y - vz * plane.z,
				                  t.x * plane.x + vy * plane.z - vz * plane.y,
				                  t.x * plane.y + vz * plane.x - vx * plane.z,
				                  t.x * plane.z + vx * plane.y - vy * plane.x,
				                  t.x * plane.w - mx * plane.x - my * plane.y - mz * plane.z));
			}

			TERATHON_API Transform4D GetTransformMatrix(void) const;
			TERATHON_API Transform4D GetInverseTransformMatrix(void) const;
			TERATHON_API void GetTransformMatrices(Transform4D *M, Transform4D *Minv) const;
			TERATHON_API Flector4D& SetTransformMatrix(const Transform4D& M);
	};


	inline Flector4D Reverse(const Flector4D& F)
	{
		return (Flector4D(-F.p.x, -F.p.y, -F.p.z, -F.p.w, F.g.x, F.g.y, F.g.z, F.g.w));
	}

	inline Flector4D Antireverse(const Flector4D& F)
	{
		return (Flector4D(-F.p.x, -F.p.y, -F.p.z, -F.p.w, F.g.x, F.g.y, F.g.z, F.g.w));
	}

	inline Flector4D operator ~(const Flector4D& F)
	{
		return (Antireverse(F));
	}

	inline Flector4D operator -(const Flector4D& F)
	{
		return (Flector4D(-F.p.x, -F.p.y, -F.p.z, -F.p.w, -F.g.x, -F.g.y, -F.g.z, -F.g.w));
	}

	inline Flector4D operator *(const Flector4D& F, float n)
	{
		return (Flector4D(F.p.x * n, F.p.y * n, F.p.z * n, F.p.w * n, F.g.x * n, F.g.y * n, F.g.z * n, F.g.w * n));
	}

	inline Flector4D operator *(float n, const Flector4D& F)
	{
		return (Flector4D(n * F.p.x, n * F.p.y, n * F.p.z, n * F.p.w, n * F.g.x, n * F.g.y, n * F.g.z, n * F.g.w));
	}

	inline Flector4D operator /(const Flector4D& F, float n)
	{
		n = 1.0F / n;
		return (Flector4D(F.p.x * n, F.p.y * n, F.p.z * n, F.p.w * n, F.g.x * n, F.g.y * n, F.g.z * n, F.g.w * n));
	}

	inline bool operator ==(const Flector4D& a, const Flector4D& b)
	{
		return ((a.p == b.p) && (a.g == b.g));
	}

	inline bool operator !=(const Flector4D& a, const Flector4D& b)
	{
		return ((a.p != b.p) || (a.g != b.g));
	}


	TERATHON_API Motor4D operator *(const Flector4D& a, const Flector4D& b);
	TERATHON_API Flector4D operator *(const Flector4D& a, const Motor4D& b);
	TERATHON_API Flector4D operator *(const Motor4D& a, const Flector4D& b);


	TERATHON_API Vector3D Transform(const Vector3D& v, const Flector4D& F);
	TERATHON_API Bivector3D Transform(const Bivector3D& v, const Flector4D& F);
	TERATHON_API Vector4D Transform(const Vector4D& p, const Flector4D& F);
	TERATHON_API Point3D Transform(const Point3D& p, const Flector4D& F);
	TERATHON_API Line3D Transform(const Line3D& l, const Flector4D& F);
	TERATHON_API Plane3D Transform(const Plane3D& g, const Flector4D& F);


	inline float BulkNorm(const Flector4D& F)
	{
		return (Sqrt(F.p.x * F.p.x + F.p.y * F.p.y + F.p.z * F.p.z + F.g.w * F.g.w));
	}

	inline float WeightNorm(const Flector4D& F)
	{
		return (Sqrt(F.p.w * F.p.w + F.g.x * F.g.x + F.g.y * F.g.y + F.g.z * F.g.z));
	}

	inline Flector4D Unitize(const Flector4D& F)
	{
		return (F * InverseSqrt(F.p.w * F.p.w + F.g.x * F.g.x + F.g.y * F.g.y + F.g.z * F.g.z));
	}


	struct ConstFlector4D
	{
		float	px, py, pz, pw;
		float	gx, gy, gz, gw;

		operator const Flector4D&(void) const
		{
			return (reinterpret_cast<const Flector4D&>(*this));
		}

		const Flector4D *operator &(void) const
		{
			return (reinterpret_cast<const Flector4D *>(this));
		}

		const Flector4D *operator ->(void) const
		{
			return (reinterpret_cast<const Flector4D *>(this));
		}
	};
}


#endif
