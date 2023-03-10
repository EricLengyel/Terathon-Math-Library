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
	//# \ctor	Flector4D(float sx, float sy, float sz, float sw, float hx, float hy, float hz, float hw);
	//# \ctor	Flector4D(const Vector4D& v, const Plane3D& g);
	//# \ctor	Flector4D(const Point3D& p, const Plane3D& g);
	//# \ctor	explicit Flector4D(const Vector4D& v);
	//# \ctor	explicit Flector4D(const Point3D& p);
	//# \ctor	explicit Flector4D(const Plane3D& g);
	//
	//# \param	sx,sy,sz,sw		The values of the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
	//# \param	hx,hy,hz,hw		The values of the <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, <b>e</b><sub>124</sub>, and <b>e</b><sub>321</sub> coordinates.
	//# \param	g				A plane whose entries are copied to the <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, <b>e</b><sub>124</sub>, and <b>e</b><sub>321</sub> coordinates.
	//# \param	v				A vector whose entries are copied to the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
	//# \param	p				A point whose entries are copied to the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, and <b>e</b><sub>3</sub> coordinates.
	//
	//# \desc
	//# The $Flector4D$ class encapsulates a reflection operator (flector) in the 4D projective geometric algebra.
	//# It has the general form <i>s<sub>x</sub></i><b>e</b><sub>1</sub> + <i>s<sub>y</sub></i><b>e</b><sub>2</sub> + <i>s<sub>z</sub></i><b>e</b><sub>3</sub> + <i>s<sub>w</sub></i><b>e</b><sub>4</sub> + <i>h<sub>x</sub></i><b>e</b><sub>234</sub> + <i>h<sub>y</sub></i><b>e</b><sub>314</sub> + <i>h<sub>z</sub></i><b>e</b><sub>124</sub> + <i>h<sub>w</sub></i><b>e</b><sub>321</sub>.
	//#
	//# The default constructor leaves the components of the flector undefined.
	//# If the vector $v$ and plane $g$ are specified, then their coordinates are assigned to the vector part and trivector part of the flector, respectively.
	//# If only one of the vector $v$ and plane $g$ are specified, then the other part is set to zero.
	//# If the point $p$ is specified, then its <i>w</i> coordinate is assumed to be one.
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
	//# \ctor	Flector4D& Set(float sx, float sy, float sz, float sw, float hx, float hy, float hz, float hw);
	//# \ctor	Flector4D& Set(const Vector4D& v, const Plane3D& g);
	//# \ctor	Flector4D& Set(const Point3D& p, const Plane3D& g);
	//
	//# \param	sx,sy,sz,sw		The values of the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
	//# \param	hx,hy,hz,hw		The values of the <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, <b>e</b><sub>124</sub>, and <b>e</b><sub>321</sub> coordinates.
	//# \param	g				A plane whose entries are copied to the <b>e</b><sub>234</sub>, <b>e</b><sub>314</sub>, <b>e</b><sub>124</sub>, and <b>e</b><sub>321</sub> coordinates.
	//# \param	v				A vector whose entries are copied to the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
	//# \param	p				A point whose entries are copied to the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, and <b>e</b><sub>3</sub> coordinates.
	//
	//# \desc
	//# The $Set$ function sets the eight coordinates of a flector.
	//# If the vector $v$ and plane $g$ are specified, then their coordinates are assigned to the vector part and trivector part of the flector, respectively.
	//# If the point $p$ is specified, then its <i>w</i> coordinate is assumed to be one.
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
	//# \proto	static Flector4D MakeTransflection(const Vector3D& offset, const Plane3D& g);
	//
	//# \param	offset		The translation vector.
	//# \param	g			The unitized reflection plane.
	//
	//# \desc
	//# The $MakeTransflection$ function returns a flector representing a translation by the vector given
	//# by the $offset$ parameter and a reflection through the plane given by the $g$ parameter.
	//# The resulting flector is unitized.
	//
	//# \also	$@Flector4D::MakeRotoreflection@$


	//# \function	Flector4D::MakeRotoreflection		Returns a flector that represents a rotation and a reflection.
	//
	//# \proto	static Flector4D MakeRotoreflection(float angle, const Line3D& axis, const Plane3D& g);
	//
	//# \param	angle		The angle of rotation, in radians.
	//# \param	axis		The unitized line about which to rotate.
	//# \param	g			The unitized reflection plane.
	//
	//# \desc
	//# The $MakeRotoreflection$ function returns a flector representing a rotation through the angle
	//# given by the $angle$ parameter about the line given by the $axis$ parameter and a reflection
	//# through the plane given by the $g$ parameter.
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

			Vector4D	point;
			Plane3D		plane;

			inline Flector4D() = default;

			Flector4D(float sx, float sy, float sz, float sw, float hx, float hy, float hz, float hw)
			{
				point.Set(sx, sy, sz, sw);
				plane.Set(hx, hy, hz, hw);
			}

			Flector4D(const Vector4D& v, const Plane3D& g)
			{
				point = v;
				plane = g;
			}

			Flector4D(const Point3D& p, const Plane3D& g)
			{
				point = p;
				plane = g;
			}

			explicit Flector4D(const Vector4D& v)
			{
				point = v;
				plane.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			explicit Flector4D(const Point3D& p)
			{
				point = p;
				plane.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			explicit Flector4D(const Plane3D& g)
			{
				plane = g;
				point.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector4D& Set(float sx, float sy, float sz, float sw, float hx, float hy, float hz, float hw)
			{
				point.Set(sx, sy, sz, sw);
				plane.Set(hx, hy, hz, hw);
				return (*this);
			}

			void Set(float sx, float sy, float sz, float sw, float hx, float hy, float hz, float hw) volatile
			{
				point.Set(sx, sy, sz, sw);
				plane.Set(hx, hy, hz, hw);
			}

			Flector4D& Set(const Vector4D& v, const Plane3D& g)
			{
				point = v;
				plane = g;
				return (*this);
			}

			void Set(const Vector4D& v, const Plane3D& g) volatile
			{
				point = v;
				plane = g;
			}

			Flector4D& Set(const Point3D& p, const Plane3D& g)
			{
				point = p;
				plane = g;
				return (*this);
			}

			void Set(const Point3D& p, const Plane3D& g) volatile
			{
				point = p;
				plane = g;
			}

			Flector4D& operator =(const Flector4D& F)
			{
				point = F.point;
				plane = F.plane;
				return (*this);
			}

			void operator =(const Flector4D& F) volatile
			{
				point = F.point;
				plane = F.plane;
			}

			Flector4D& operator =(const Vector4D& v)
			{
				point = v;
				plane.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Vector4D& v) volatile
			{
				point = v;
				plane.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector4D& operator =(const Point3D& p)
			{
				point = p;
				plane.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Point3D& p) volatile
			{
				point = p;
				plane.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector4D& operator =(const Plane3D& g)
			{
				plane = g;
				point.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Plane3D& g) volatile
			{
				plane = g;
				point.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector4D& operator *=(float n)
			{
				point *= n;
				plane *= n;
				return (*this);
			}

			Flector4D& operator /=(float n)
			{
				n = 1.0F / n;
				point *= n;
				plane *= n;
				return (*this);
			}

			Flector4D& Unitize(void)
			{
				return (*this *= InverseSqrt(point.w * point.w + plane.x * plane.x + plane.y * plane.y + plane.z * plane.z));
			}

			static Flector4D MakeTransflection(const Vector3D& offset, const Plane3D& g)
			{
				return (Flector4D((offset.y * g.z - offset.z * g.y) * 0.5F, (offset.z * g.x - offset.x * g.z) * 0.5F, (offset.x * g.y - offset.y * g.x) * 0.5F, 0.0F, g.x, g.y, g.z, g.w - (offset.x * g.x + offset.y * g.y + offset.z * g.z) * 0.5F));
			}

			static Flector4D MakeRotoreflection(float angle, const Bivector3D& axis, const Plane3D& g)
			{
				Vector2D v = CosSin(angle * 0.5F);
				float rx = axis.x * v.y;
				float ry = axis.y * v.y;
				float rz = axis.z * v.y;
				return (Flector4D(rx * g.w, ry * g.w, rz * g.w, -rx * g.x - ry * g.y - rz * g.z, v.x * g.x + ry * g.z - rz * g.y, v.x * g.y + rz * g.x - rx * g.z, v.x * g.z + rx * g.y - ry * g.x, v.x * g.w));
			}

			static Flector4D MakeRotoreflection(float angle, const Line3D& axis, const Plane3D& g)
			{
				Vector2D v = CosSin(angle * 0.5F);
				float rx = axis.v.x * v.y;
				float ry = axis.v.y * v.y;
				float rz = axis.v.z * v.y;
				float ux = axis.m.x * v.y;
				float uy = axis.m.y * v.y;
				float uz = axis.m.z * v.y;
				return (Flector4D(rx * g.w + uy * g.z - uz * g.y, ry * g.w + uz * g.x - ux * g.z, rz * g.w + ux * g.y - uy * g.x, -rx * g.x - ry * g.y - rz * g.z, v.x * g.x + ry * g.z - rz * g.y, v.x * g.y + rz * g.x - rx * g.z, v.x * g.z + rx * g.y - ry * g.x, v.x * g.w - ux * g.x - uy * g.y - uz * g.z));
			}

			TERATHON_API Transform4D GetTransformMatrix(void) const;
			TERATHON_API Transform4D GetInverseTransformMatrix(void) const;
			TERATHON_API void GetTransformMatrices(Transform4D *M, Transform4D *Minv) const;
			TERATHON_API Flector4D& SetTransformMatrix(const Transform4D& M);
	};


	inline Flector4D operator ~(const Flector4D& F)
	{
		return (Flector4D(-F.point.x, -F.point.y, -F.point.z, -F.point.w, F.plane.x, F.plane.y, F.plane.z, F.plane.w));
	}

	inline Flector4D operator -(const Flector4D& F)
	{
		return (Flector4D(-F.point.x, -F.point.y, -F.point.z, -F.point.w, -F.plane.x, -F.plane.y, -F.plane.z, -F.plane.w));
	}

	inline Flector4D operator *(const Flector4D& F, float n)
	{
		return (Flector4D(F.point.x * n, F.point.y * n, F.point.z * n, F.point.w * n, F.plane.x * n, F.plane.y * n, F.plane.z * n, F.plane.w * n));
	}

	inline Flector4D operator *(float n, const Flector4D& F)
	{
		return (Flector4D(n * F.point.x, n * F.point.y, n * F.point.z, n * F.point.w, n * F.plane.x, n * F.plane.y, n * F.plane.z, n * F.plane.w));
	}

	inline Flector4D operator /(const Flector4D& F, float n)
	{
		n = 1.0F / n;
		return (Flector4D(F.point.x * n, F.point.y * n, F.point.z * n, F.point.w * n, F.plane.x * n, F.plane.y * n, F.plane.z * n, F.plane.w * n));
	}

	inline bool operator ==(const Flector4D& a, const Flector4D& b)
	{
		return ((a.point == b.point) && (a.plane == b.plane));
	}

	inline bool operator !=(const Flector4D& a, const Flector4D& b)
	{
		return ((a.point != b.point) || (a.plane != b.plane));
	}


	TERATHON_API Motor4D operator *(const Flector4D& a, const Flector4D& b);
	TERATHON_API Flector4D operator *(const Flector4D& a, const Motor4D& b);
	TERATHON_API Flector4D operator *(const Motor4D& a, const Flector4D& b);


	TERATHON_API Vector3D Transform(const Vector3D& v, const Flector4D& F);
	TERATHON_API Bivector3D Transform(const Bivector3D& v, const Flector4D& F);
	TERATHON_API Point3D Transform(const Point3D& p, const Flector4D& F);
	TERATHON_API Line3D Transform(const Line3D& l, const Flector4D& F);
	TERATHON_API Plane3D Transform(const Plane3D& g, const Flector4D& F);


	inline Flector4D Reverse(const Flector4D& F)
	{
		return (Flector4D(F.point.x, F.point.y, F.point.z, F.point.w, -F.plane.x, -F.plane.y, -F.plane.z, -F.plane.w));
	}

	inline Flector4D Antireverse(const Flector4D& F)
	{
		return (~F);
	}

	inline float BulkNorm(const Flector4D& F)
	{
		return (Sqrt(F.point.x * F.point.x + F.point.y * F.point.y + F.point.z * F.point.z + F.plane.w * F.plane.w));
	}

	inline float WeightNorm(const Flector4D& F)
	{
		return (Sqrt(F.point.w * F.point.w + F.plane.x * F.plane.x + F.plane.y * F.plane.y + F.plane.z * F.plane.z));
	}

	inline Flector4D Unitize(const Flector4D& F)
	{
		return (F * InverseSqrt(F.point.w * F.point.w + F.plane.x * F.plane.x + F.plane.y * F.plane.y + F.plane.z * F.plane.z));
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
