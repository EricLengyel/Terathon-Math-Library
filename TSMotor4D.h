//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSMotor4D_h
#define TSMotor4D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSBivector4D.h"
#include "TSQuaternion.h"


#define TERATHON_MOTOR4D 1


namespace Terathon
{
	struct ConstMotor4D;


	//# \class	Motor4D		Encapsulates a 4D motion operator (motor).
	//
	//# The $Motor4D$ class encapsulates a 4D motion operator (motor), also known as a dual quaternion.
	//# For more information about motors, see the <a href="http://projectivegeometricalgebra.org">projective geometric algebra</a> website.
	//
	//# \def	class Motor4D
	//
	//# \ctor	Motor4D();
	//# \ctor	Motor4D(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw);
	//# \ctor	Motor4D(const Quaternion& r);
	//# \ctor	Motor4D(const Quaternion& r, const Quaternion& u);
	//# \ctor	Motor4D(const Trivector4D& f, const Trivector4D& g);
	//# \ctor	Motor4D(const Bivector4D& K, const Bivector4D& L);
	//# \ctor	Motor4D(const Point3D& p, const Point3D& q);
	//
	//# \param	rx,ry,rz,rw		The values of the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	ux,uy,uz,uw		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//# \param	r				A quaternion whose entries are copied to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	u				A quaternion whose entries are copied to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//# \param	f,g				Two 4D trivectors representing planes.
	//# \param	K,L				Two 4D bivectors representing lines.
	//# \param	p,q				Two 3D points.
	//
	//# \desc
	//# The $Motor4D$ class encapsulates a motion operator (motor) in the 4D projective geometric algebra.
	//# It has the general form <i>r<sub>x</sub></i><b>e</b><sub>41</sub> + <i>r<sub>y</sub></i><b>e</b><sub>42</sub> + <i>r<sub>z</sub></i><b>e</b><sub>43</sub> + <i>r<sub>w</sub></i>&#x1D7D9; + <i>u<sub>x</sub></i><b>e</b><sub>23</sub> + <i>u<sub>y</sub></i><b>e</b><sub>31</sub> + <i>u<sub>z</sub></i><b>e</b><sub>12</sub> + <i>u<sub>w</sub></i>.
	//#
	//# The default constructor leaves the components of the motor undefined.
	//# If the quaternions $r$ and $u$ are specified, then their coordinates are assigned to the weight and bulk of the motor, respectively.
	//# If only the quaternion $r$ is specified, then the bulk of the motor is set to zero.
	//#
	//# If the $f$ and $g$ parameters are specified, then the motor is set to the geometric antiproduct $g$&#x202F;&#x27C7;&#x202F;$f$,
	//# corresponding to the rotation about the line where the planes $f$ and $g$ intersect by twice the angle between them in the direction from $f$ to $g$.
	//#
	//# If the $K$ and $L$ parameters are specified, then the motor is set to the geometric antiproduct $L$&#x202F;&#x27C7;&#x202F;$K$,
	//# corresponding to the rotation about the line containing the closest points on the lines $K$ and $L$ by twice the angle between their directions and the translation by twice the distance between the lines in the direction from $K$ to $L$.
	//#
	//# If the $p$ and $q$ parameters are specified, then the motor is set to the geometric antiproduct $q$&#x202F;&#x27C7;&#x202F;$p$,
	//# corresponding to the translation by twice the distance between the points $p$ and $q$ in the direction from $p$ to $q$.
	//
	//# \operator	Motor4D& operator +=(const Motor4D& Q);
	//#				Adds the motor $Q$.
	//
	//# \operator	Motor4D& operator -=(const Motor4D& Q);
	//#				Subtracts the motor $Q$.
	//
	//# \operator	Motor4D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Motor4D& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		bool operator ==(const Motor4D& a, const Motor4D& b);
	//#				Returns a boolean value indicating whether the two motors $a$ and $b$ are equal.
	//
	//# \action		bool operator !=(const Motor4D& a, const Motor4D& b);
	//#				Returns a boolean value indicating whether the two motors $a$ and $b$ are not equal.
	//
	//# \action		Motor4D operator ~(const Motor4D& Q);
	//#				Returns the antireverse of the motor $Q$.
	//
	//# \action		Motor4D operator -(const Motor4D& Q);
	//#				Returns the negation of the motor $Q$.
	//
	//# \action		Motor4D operator +(const Motor4D& a, const Motor4D& b) const;
	//#				Returns the sum of the motors $a$ and $b$.
	//
	//# \action		Motor4D operator -(const Motor4D& a, const Motor4D& b) const;
	//#				Returns the difference of the motors $a$ and $b$.
	//
	//# \action		Motor4D operator *(const Motor4D& Q, float s);
	//#				Returns the product of the motor $Q$ and the scalar $s$.
	//
	//# \action		Motor4D operator *(float s, const Motor4D& Q);
	//#				Returns the product of the motor $Q$ and the scalar $s$.
	//
	//# \action		Motor4D operator /(const Motor4D& Q, float s);
	//#				Returns the product of the motor $Q$ and the inverse of the scalar $s$.
	//
	//# \action		Motor4D operator *(const Motor4D& a, const Motor4D& b);
	//#				Returns the geometric antiproduct of the motors $a$ and $b$.
	//
	//# \action		Motor4D operator *(const Motor4D& Q, const Quaternion& r);
	//#				Returns the geometric antiproduct of the motor $Q$ and the quaternion $r$.
	//
	//# \action		Motor4D operator *(const Quaternion& r, const Motor4D& Q);
	//#				Returns the geometric antiproduct of the quaternion $r$ and the motor $Q$.
	//
	//# \action		float BulkNorm(const Motor4D& Q);
	//#				Returns the bulk norm of the motor $Q$.
	//
	//# \action		float WeightNorm(const Motor4D& Q);
	//#				Returns the weight norm of the motor $Q$.
	//
	//# \action		Motor4D Sqrt(const Motor4D& Q);
	//#				Returns the square root of the motor $Q$ with respect to the geometric antiproduct.
	//
	//# \action		Vector3D Transform(const Vector3D& v, const Motor4D& Q);
	//#				Transforms the vector $v$ with the motor $Q$.
	//
	//# \action		Bivector3D Transform(const Bivector3D& v, const Motor4D& Q);
	//#				Transforms the bivector $v$ with the motor $Q$.
	//
	//# \action		Point3D Transform(const Point3D& p, const Motor4D& Q);
	//#				Transforms the point $p$ with the motor $Q$.
	//
	//# \action		Bivector4D Transform(const Bivector4D& L, const Motor4D& Q);
	//#				Transforms the line $L$ with the motor $Q$.
	//
	//# \action		Trivector4D Transform(const Trivector4D& f, const Motor4D& Q);
	//#				Transforms the plane $f$ with the motor $Q$.
	//
	//# \also	$@Flector4D@$
	//# \also	$@Quaternion@$
	//# \also	$@Trivector4D@$
	//# \also	$@Bivector4D@$
	//# \also	$@Point3D@$


	//# \function	Motor4D::Set	Sets all eight components of a motor.
	//
	//# \ctor	Motor4D& Set(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw);
	//# \ctor	Motor4D& Set(const Quaternion& r, const Quaternion& u);
	//
	//# \param	rx,ry,rz,rw		The values of the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	ux,uy,uz,uw		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//# \param	r				A quaternion whose entries are copied to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	u				A quaternion whose entries are copied to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//
	//# \desc
	//# The $Set$ function sets the eight coordinates of a motor.
	//# If the quaternions $r$ and $u$ are specified, then their coordinates are assigned to the weight and bulk of the motor, respectively.
	//#
	//# The return value is a reference to the motor object.


	//# \function	Motor4D::Unitize		Unitizes the weight of a motor.
	//
	//# \proto	Motor4D& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a motor by the inverse magnitude of its weight, which is the quaternion
	//# given by its <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# After calling this function, the rotor component of the motor is unit-length.
	//# If these coordinates are all zero, then the result is undefined.
	//#
	//# The return value is a reference to the motor object.


	//# \function	Motor4D::MakeRotation		Returns a motor that represents a rotation about a given axis through the origin.
	//
	//# \proto	static Motor4D MakeRotation(float angle, const Bivector3D& axis);
	//
	//# \param	angle		The angle of rotation, in radians.
	//# \param	axis		The axis about which to rotate. This bivector must have unit magnitude.
	//
	//# \desc
	//# The $MakeRotation$ function returns a motor representing a rotation through the angle
	//# given by the $angle$ parameter about the axis through the origin given by the $axis$ parameter.
	//# The resulting motor is unitized.
	//
	//# \also	$@Motor4D::MakeTranslation@$
	//# \also	$@Motor4D::MakeScrew@$


	//# \function	Motor4D::MakeTranslation	Returns a motor that represents a translation.
	//
	//# \proto	static Motor4D MakeTranslation(const Vector3D& offset);
	//
	//# \param	offset		The offset vector.
	//
	//# \desc
	//# The $MakeTranslation$ function returns a motor representing a translation by the
	//# direction and magnitude given by the $offset$ parameter.
	//
	//# \also	$@Motor4D::MakeRotation@$
	//# \also	$@Motor4D::MakeScrew@$


	//# \function	Motor4D::MakeScrew			Returns a motor that represents a general screw motion.
	//
	//# \proto	static Motor4D MakeScrew(float angle, const Bivector4D& axis, float disp);
	//
	//# \param	angle		The angle of rotation, in radians.
	//# \param	axis		The unitized line about which to rotate.
	//# \param	disp		The displacement distance along the line.
	//
	//# \desc
	//# The $MakeScrew$ function returns a motor representing a rotation through the angle
	//# given by the $angle$ parameter about the line given by the $axis$ parameter and a
	//# translation along that line of the distance given by the $disp$ parameter.
	//
	//# \also	$@Motor4D::MakeRotation@$
	//# \also	$@Motor4D::MakeTranslation@$


	//# \function	Motor4D::GetDirectionX		Returns the direction to which the <i>x</i> axis is transformed by a motor.
	//
	//# \proto	Vector3D GetDirectionX(void) const;
	//
	//# \desc
	//# The $GetDirectionX$ function calculates the 3D vector that results from transforming the direction vector (1,&nbsp;0,&nbsp;0)
	//# with the motor for which it is called.
	//
	//# \also	$@Motor4D::GetDirectionY@$
	//# \also	$@Motor4D::GetDirectionZ@$
	//# \also	$@Motor4D::GetPosition@$
	//# \also	$@Motor4D::GetTransformMatrix@$
	//# \also	$@Motor4D::GetInverseTransformMatrix@$
	//# \also	$@Motor4D::GetTransformMatrices@$
	//# \also	$@Motor4D::SetTransformMatrix@$


	//# \function	Motor4D::GetDirectionY		Returns the direction to which the <i>y</i> axis is transformed by a motor.
	//
	//# \proto	Vector3D GetDirectionY(void) const;
	//
	//# \desc
	//# The $GetDirectionY$ function calculates the 3D vector that results from transforming the direction vector (0,&nbsp;1,&nbsp;0)
	//# with the motor for which it is called.
	//
	//# \also	$@Motor4D::GetDirectionX@$
	//# \also	$@Motor4D::GetDirectionZ@$
	//# \also	$@Motor4D::GetPosition@$
	//# \also	$@Motor4D::GetTransformMatrix@$
	//# \also	$@Motor4D::GetInverseTransformMatrix@$
	//# \also	$@Motor4D::GetTransformMatrices@$
	//# \also	$@Motor4D::SetTransformMatrix@$


	//# \function	Motor4D::GetDirectionZ		Returns the direction to which the <i>z</i> axis is transformed by a motor.
	//
	//# \proto	Vector3D GetDirectionZ(void) const;
	//
	//# \desc
	//# The $GetDirectionZ$ function calculates the 3D vector that results from transforming the direction vector (0,&nbsp;0,&nbsp;1)
	//# with the motor for which it is called.
	//
	//# \also	$@Motor4D::GetDirectionX@$
	//# \also	$@Motor4D::GetDirectionY@$
	//# \also	$@Motor4D::GetPosition@$
	//# \also	$@Motor4D::GetTransformMatrix@$
	//# \also	$@Motor4D::GetInverseTransformMatrix@$
	//# \also	$@Motor4D::GetTransformMatrices@$
	//# \also	$@Motor4D::SetTransformMatrix@$


	//# \function	Motor4D::GetPosition		Returns the position to which the origin is transformed by a motor.
	//
	//# \proto	Point3D GetPosition(void) const;
	//
	//# \desc
	//# The $GetPosition$ function calculates the 3D point that results from transforming the origin
	//# with the motor for which it is called.
	//
	//# \also	$@Motor4D::GetDirectionX@$
	//# \also	$@Motor4D::GetDirectionY@$
	//# \also	$@Motor4D::GetDirectionZ@$
	//# \also	$@Motor4D::GetTransformMatrix@$
	//# \also	$@Motor4D::GetInverseTransformMatrix@$
	//# \also	$@Motor4D::GetTransformMatrices@$
	//# \also	$@Motor4D::SetTransformMatrix@$


	//# \function	Motor4D::GetTransformMatrix		Converts a motor to its corresponding 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# \proto	Transform4D GetTransformMatrix(void) const;
	//
	//# \desc
	//# The $GetTransformMatrix$ function converts a motor to the $@Transform4D@$ object that
	//# represents the same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object.
	//
	//# \also	$@Motor4D::GetInverseTransformMatrix@$
	//# \also	$@Motor4D::GetTransformMatrices@$
	//# \also	$@Motor4D::SetTransformMatrix@$
	//# \also	$@Motor4D::GetDirectionX@$
	//# \also	$@Motor4D::GetDirectionY@$
	//# \also	$@Motor4D::GetDirectionZ@$
	//# \also	$@Motor4D::GetPosition@$
	//# \also	$@Motor4D::MakeRotation@$
	//# \also	$@Motor4D::MakeTranslation@$
	//# \also	$@Motor4D::MakeScrew@$


	//# \function	Motor4D::GetInverseTransformMatrix		Converts a motor to the inverse of its corresponding 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# \proto	Transform4D GetInverseTransformMatrix(void) const;
	//
	//# \desc
	//# The $GetInverseTransformMatrix$ function converts a motor to the inverse of the $@Transform4D@$ object that
	//# represents the same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object. Such a matrix
	//# correctly transforms a $@Trivector4D@$ object when it postmultiplies it.
	//#
	//# This function performs the same amount of computation as the $@Motor4D::GetTransformMatrix@$ function, and is thus
	//# significantly faster than calling the $@Motor4D::GetTransformMatrix@$ function and inverting the result.
	//
	//# \also	$@Motor4D::GetTransformMatrix@$
	//# \also	$@Motor4D::GetTransformMatrices@$
	//# \also	$@Motor4D::SetTransformMatrix@$
	//# \also	$@Motor4D::GetDirectionX@$
	//# \also	$@Motor4D::GetDirectionY@$
	//# \also	$@Motor4D::GetDirectionZ@$
	//# \also	$@Motor4D::GetPosition@$
	//# \also	$@Motor4D::MakeRotation@$
	//# \also	$@Motor4D::MakeTranslation@$
	//# \also	$@Motor4D::MakeScrew@$


	//# \function	Motor4D::GetTransformMatrices		Converts a motor to its corresponding 4&#x202F;&times;&#x202F;4 matrix and its inverse simultaneously.
	//
	//# \proto	void GetTransformMatrices(Transform4D *M, Transform4D *Minv) const;
	//
	//# \param	M		A pointer to the location where the transform matrix is returned.
	//# \param	Minv	A pointer to the location where the inverse transform matrix is returned.
	//
	//# \desc
	//# The $GetTransformMatrices$ function converts a motor to the $@Transform4D@$ object that represents the
	//# same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object and stores it in the location
	//# specified by the $M$ parameter. The inverse of this matrix is stored in the location specified by the $Minv$ parameter.
	//#
	//# Calling this function is much faster than making separate calls to the $@Motor4D::GetTransformMatrix@$ and
	//# $@Motor4D::GetInverseTransformMatrix@$ functions.
	//
	//# \also	$@Motor4D::GetTransformMatrix@$
	//# \also	$@Motor4D::GetInverseTransformMatrix@$
	//# \also	$@Motor4D::SetTransformMatrix@$
	//# \also	$@Motor4D::GetDirectionX@$
	//# \also	$@Motor4D::GetDirectionY@$
	//# \also	$@Motor4D::GetDirectionZ@$
	//# \also	$@Motor4D::GetPosition@$
	//# \also	$@Motor4D::MakeRotation@$
	//# \also	$@Motor4D::MakeTranslation@$
	//# \also	$@Motor4D::MakeScrew@$


	//# \function	Motor4D::SetTransformMatrix		Converts a 4&#x202F;&times;&#x202F;4 matrix to its corresponding motor.
	//
	//# \proto	Motor4D& SetTransformMatrix(const Transform4D& M);
	//
	//# \param	M		The matrix to convert to a motor.
	//
	//# \desc
	//# The $SetTransformMatrix$ function sets the components of a motor to values that
	//# represent the same rigid motion as the one represented by the matrix specified by the $M$ parameter.
	//#
	//# This function expects the matrix $M$ to be orthogonal and have a determinant of +1.
	//# If these conditions are not met, then the results are unlikely to be meaningful.
	//
	//# \also	$@Motor4D::GetTransformMatrix@$
	//# \also	$@Motor4D::GetInverseTransformMatrix@$
	//# \also	$@Motor4D::GetTransformMatrices@$
	//# \also	$@Motor4D::MakeRotation@$
	//# \also	$@Motor4D::MakeTranslation@$
	//# \also	$@Motor4D::MakeScrew@$


	class Motor4D
	{
		public:

			Quaternion		rotor;			//## The coordinates of the rotor part consisting of the weight components using basis elements <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and <b>e</b><sub>1234</sub>.
			Quaternion		screw;			//## The coordinates of the screw part consisting of the bulk components using basis elements <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and <b>1</b>.

			TERATHON_API static const ConstMotor4D identity;

			inline Motor4D() = default;

			Motor4D(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw)
			{
				rotor.Set(rx, ry, rz, rw);
				screw.Set(ux, uy, uz, uw);
			}

			explicit Motor4D(const Quaternion& r)
			{
				rotor = r;
				screw.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Motor4D(const Quaternion& r, const Quaternion& u)
			{
				rotor = r;
				screw = u;
			}

			Motor4D(const Trivector4D& f, const Trivector4D& g)
			{
				rotor.Set(f.y * g.z - f.z * g.y, f.z * g.x - f.x * g.z, f.x * g.y - f.y * g.x, f.x * g.x + f.y * g.y + f.z * g.z);
				screw.Set(f.w * g.x - f.x * g.w, f.w * g.y - f.y * g.w, f.w * g.z - f.z * g.w, 0.0F);
			}

			Motor4D(const Bivector4D& K, const Bivector4D& L)
			{
				rotor.Set(K.direction ^ L.direction, -Dot(K.direction, L.direction));
				screw.Set((L.direction ^ !K.moment) - (K.direction ^ !L.moment), -(L.direction ^ K.moment) - (K.direction ^ L.moment));
			}

			Motor4D(const Point3D& p, const Point3D& q)
			{
				rotor.Set(0.0F, 0.0F, 0.0F, -1.0F);
				screw.Set(p.x - q.x, p.y - q.y, p.z - q.z, 0.0F);
			}

			Motor4D& Set(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw)
			{
				rotor.Set(rx, ry, rz, rw);
				screw.Set(ux, uy, uz, uw);
				return (*this);
			}

			void Set(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw) volatile
			{
				rotor.Set(rx, ry, rz, rw);
				screw.Set(ux, uy, uz, uw);
			}

			Motor4D& Set(const Quaternion& r, const Quaternion& u)
			{
				rotor = r;
				screw = u;
				return (*this);
			}

			void Set(const Quaternion& r, const Quaternion& u) volatile
			{
				rotor = r;
				screw = u;
			}

			Motor4D& operator =(const Motor4D& Q)
			{
				rotor = Q.rotor;
				screw = Q.screw;
				return (*this);
			}

			void operator =(const Motor4D& Q) volatile
			{
				rotor = Q.rotor;
				screw = Q.screw;
			}

			Motor4D& operator =(const Quaternion& r)
			{
				rotor = r;
				screw.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Quaternion& r) volatile
			{
				rotor = r;
				screw.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Motor4D& operator +=(const Motor4D& Q)
			{
				rotor += Q.rotor;
				screw += Q.screw;
				return (*this);
			}

			Motor4D& operator -=(const Motor4D& Q)
			{
				rotor -= Q.rotor;
				screw -= Q.screw;
				return (*this);
			}

			Motor4D& operator *=(float s)
			{
				rotor *= s;
				screw *= s;
				return (*this);
			}

			Motor4D& operator /=(float s)
			{
				s = 1.0F / s;
				rotor *= s;
				screw *= s;
				return (*this);
			}

			Motor4D& Unitize(void)
			{
				return (*this *= InverseMag(rotor));
			}

			static Motor4D MakeRotation(float angle, const Bivector3D& axis)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Motor4D(axis.x * v.y, axis.y * v.y, axis.z * v.y, v.x, 0.0F, 0.0F, 0.0F, 0.0F));
			}

			static Motor4D MakeTranslation(const Vector3D& offset)
			{
				return (Motor4D(0.0F, 0.0F, 0.0F, 1.0F, offset.x * 0.5F, offset.y * 0.5F, offset.z * 0.5F, 0.0F));
			}

			static Motor4D MakeScrew(float angle, const Bivector4D& axis, float disp)
			{
				disp *= 0.5F;
				Vector2D v = CosSin(angle * 0.5F);
				return (Motor4D(axis.direction.x * v.y, axis.direction.y * v.y, axis.direction.z * v.y, v.x, disp * axis.direction.x * v.x + axis.moment.x * v.y, disp * axis.direction.y * v.x + axis.moment.y * v.y, disp * axis.direction.z * v.x + axis.moment.z * v.y, -disp * v.y));
			}

			TERATHON_API Vector3D GetDirectionX(void) const;
			TERATHON_API Vector3D GetDirectionY(void) const;
			TERATHON_API Vector3D GetDirectionZ(void) const;
			TERATHON_API Point3D GetPosition(void) const;

			TERATHON_API Transform4D GetTransformMatrix(void) const;
			TERATHON_API Transform4D GetInverseTransformMatrix(void) const;
			TERATHON_API void GetTransformMatrices(Transform4D *M, Transform4D *Minv) const;
			TERATHON_API Motor4D& SetTransformMatrix(const Transform4D& M);
	};


	inline Motor4D operator ~(const Motor4D& Q)
	{
		return (Motor4D(-Q.rotor.x, -Q.rotor.y, -Q.rotor.z, Q.rotor.w, -Q.screw.x, -Q.screw.y, -Q.screw.z, Q.screw.w));
	}

	inline Motor4D operator -(const Motor4D& Q)
	{
		return (Motor4D(-Q.rotor.x, -Q.rotor.y, -Q.rotor.z, -Q.rotor.w, -Q.screw.x, -Q.screw.y, -Q.screw.z, -Q.screw.w));
	}

	inline Motor4D operator +(const Motor4D& a, const Motor4D& b)
	{
		return (Motor4D(a.rotor + b.rotor, a.screw + b.screw));
	}

	inline Motor4D operator -(const Motor4D& a, const Motor4D& b)
	{
		return (Motor4D(a.rotor - b.rotor, a.screw - b.screw));
	}

	inline Motor4D operator *(const Motor4D& Q, float s)
	{
		return (Motor4D(Q.rotor.x * s, Q.rotor.y * s, Q.rotor.z * s, Q.rotor.w * s, Q.screw.x * s, Q.screw.y * s, Q.screw.z * s, Q.screw.w * s));
	}

	inline Motor4D operator *(float s, const Motor4D& Q)
	{
		return (Motor4D(s * Q.rotor.x, s * Q.rotor.y, s * Q.rotor.z, s * Q.rotor.w, s * Q.screw.x, s * Q.screw.y, s * Q.screw.z, s * Q.screw.w));
	}

	inline Motor4D operator /(const Motor4D& Q, float s)
	{
		s = 1.0F / s;
		return (Motor4D(Q.rotor.x * s, Q.rotor.y * s, Q.rotor.z * s, Q.rotor.w * s, Q.screw.x * s, Q.screw.y * s, Q.screw.z * s, Q.screw.w * s));
	}

	inline bool operator ==(const Motor4D& a, const Motor4D& b)
	{
		return ((a.rotor == b.rotor) && (a.screw == b.screw));
	}

	inline bool operator !=(const Motor4D& a, const Motor4D& b)
	{
		return ((a.rotor != b.rotor) || (a.screw != b.screw));
	}


	TERATHON_API Motor4D operator *(const Motor4D& a, const Motor4D& b);
	TERATHON_API Motor4D operator *(const Motor4D& Q, const Quaternion& r);
	TERATHON_API Motor4D operator *(const Quaternion& r, const Motor4D& Q);


	TERATHON_API Motor4D Sqrt(const Motor4D& Q);


	inline Vector3D Transform(const Vector3D& v, const Motor4D& Q)
	{
		return (Transform(v, Q.rotor));
	}

	inline Bivector3D Transform(const Bivector3D& v, const Motor4D& Q)
	{
		return (!Transform(!v, Q.rotor));
	}

	TERATHON_API Point3D Transform(const Point3D& p, const Motor4D& Q);
	TERATHON_API Bivector4D Transform(const Bivector4D& L, const Motor4D& Q);
	TERATHON_API Trivector4D Transform(const Trivector4D& f, const Motor4D& Q);


	inline Motor4D Reverse(const Motor4D& Q)
	{
		return (~Q);
	}

	inline Motor4D Antireverse(const Motor4D& Q)
	{
		return (~Q);
	}

	inline float BulkNorm(const Motor4D& Q)
	{
		return (Magnitude(Q.screw));
	}

	inline float WeightNorm(const Motor4D& Q)
	{
		return (Magnitude(Q.rotor));
	}

	inline Motor4D Unitize(const Motor4D& Q)
	{
		return (Q * InverseMag(Q.rotor));
	}


	struct ConstMotor4D
	{
		float	rx;
		float	ry;
		float	rz;
		float	rw;
		float	ux;
		float	uy;
		float	uz;
		float	uw;

		operator const ConstMotor4D&(void) const
		{
			return (reinterpret_cast<const ConstMotor4D&>(*this));
		}

		const ConstMotor4D *operator &(void) const
		{
			return (reinterpret_cast<const ConstMotor4D *>(this));
		}
	};
}


#endif
