//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSMotor3D_h
#define TSMotor3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSLine3D.h"
#include "TSQuaternion.h"


#define TERATHON_MOTOR3D 1


namespace Terathon
{
	struct ConstMotor3D;


	//# \class	Motor3D		Encapsulates a 3D motion operator (motor).
	//
	//# The $Motor3D$ class encapsulates a 3D motion operator (motor), also known as a dual quaternion.
	//# For more information about motors, see the <a href="http://projectivegeometricalgebra.org">projective geometric algebra</a> website.
	//
	//# \def	class Motor3D
	//
	//# \ctor	Motor3D();
	//# \ctor	Motor3D(float vx, float vy, float vz, float vw, float mx, float my, float mz, float mw);
	//# \ctor	Motor3D(const Quaternion& rotor);
	//# \ctor	Motor3D(const Quaternion& rotor, const Quaternion& screw);
	//# \ctor	Motor3D(const Plane3D& g, const Plane3D& h);
	//# \ctor	Motor3D(const Line3D& k, const Line3D& l);
	//# \ctor	Motor3D(const Point3D& p, const Point3D& q);
	//
	//# \param	vx,vy,vz,vw		The values of the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	mx,my,mz,mw		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//# \param	rotor			A quaternion whose entries are copied to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	screw			A quaternion whose entries are copied to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//# \param	g,h				Two 4D trivectors representing planes.
	//# \param	k,l				Two 4D bivectors representing lines.
	//# \param	p,q				Two 3D points.
	//
	//# \desc
	//# The $Motor3D$ class encapsulates a motion operator (motor) in the 4D projective geometric algebra.
	//# It has the general form <i>Q<sub>vx</sub></i><b>e</b><sub>41</sub> + <i>Q<sub>vy</sub></i><b>e</b><sub>42</sub> + <i>Q<sub>vz</sub></i><b>e</b><sub>43</sub> + <i>Q<sub>vw</sub></i>&#x1D7D9; + <i>Q<sub>mx</sub></i><b>e</b><sub>23</sub> + <i>Q<sub>my</sub></i><b>e</b><sub>31</sub> + <i>Q<sub>mz</sub></i><b>e</b><sub>12</sub> + <i>Q<sub>mw</sub></i>.
	//#
	//# The default constructor leaves the components of the motor undefined.
	//# If the quaternions $rotor$ and $screw$ are specified, then their coordinates are assigned to the weight and bulk of the motor, respectively.
	//# If only the quaternion $rotor$ is specified, then the bulk of the motor is set to zero.
	//#
	//# If the $g$ and $h$ parameters are specified, then the motor is set to the geometric antiproduct $h$&#x202F;&#x27C7;&#x202F;$g$,
	//# corresponding to the rotation about the line where the planes $g$ and $h$ intersect by twice the angle between them in the direction from $g$ to $h$.
	//#
	//# If the $k$ and $l$ parameters are specified, then the motor is set to the geometric antiproduct $l$&#x202F;&#x27C7;&#x202F;$k$,
	//# corresponding to the rotation about the line containing the closest points on the lines $k$ and $l$ by twice the angle between their directions and the translation by twice the distance between the lines in the direction from $k$ to $l$.
	//#
	//# If the $p$ and $q$ parameters are specified, then the motor is set to the geometric antiproduct $q$&#x202F;&#x27C7;&#x202F;$p$,
	//# corresponding to the translation by twice the distance between the points $p$ and $q$ in the direction from $p$ to $q$.
	//
	//# \operator	Motor3D& operator +=(const Motor3D& Q);
	//#				Adds the motor $Q$.
	//
	//# \operator	Motor3D& operator -=(const Motor3D& Q);
	//#				Subtracts the motor $Q$.
	//
	//# \operator	Motor3D& operator *=(float n);
	//#				Multiplies by the scalar $n$.
	//
	//# \operator	Motor3D& operator /=(float n);
	//#				Multiplies by the inverse of the scalar $n$.
	//
	//# \action		bool operator ==(const Motor3D& a, const Motor3D& b);
	//#				Returns a boolean value indicating whether the two motors $a$ and $b$ are equal.
	//
	//# \action		bool operator !=(const Motor3D& a, const Motor3D& b);
	//#				Returns a boolean value indicating whether the two motors $a$ and $b$ are not equal.
	//
	//# \action		Motor3D operator ~(const Motor3D& Q);
	//#				Returns the antireverse of the motor $Q$.
	//
	//# \action		Motor3D operator -(const Motor3D& Q);
	//#				Returns the negation of the motor $Q$.
	//
	//# \action		Motor3D operator +(const Motor3D& a, const Motor3D& b) const;
	//#				Returns the sum of the motors $a$ and $b$.
	//
	//# \action		Motor3D operator -(const Motor3D& a, const Motor3D& b) const;
	//#				Returns the difference of the motors $a$ and $b$.
	//
	//# \action		Motor3D operator *(const Motor3D& Q, float n);
	//#				Returns the product of the motor $Q$ and the scalar $n$.
	//
	//# \action		Motor3D operator *(float n, const Motor3D& Q);
	//#				Returns the product of the motor $Q$ and the scalar $n$.
	//
	//# \action		Motor3D operator /(const Motor3D& Q, float n);
	//#				Returns the product of the motor $Q$ and the inverse of the scalar $n$.
	//
	//# \action		Motor3D operator *(const Motor3D& a, const Motor3D& b);
	//#				Returns the geometric antiproduct of the motors $a$ and $b$.
	//
	//# \action		Motor3D operator *(const Motor3D& Q, const Quaternion& r);
	//#				Returns the geometric antiproduct of the motor $Q$ and the quaternion $r$.
	//
	//# \action		Motor3D operator *(const Quaternion& r, const Motor3D& Q);
	//#				Returns the geometric antiproduct of the quaternion $r$ and the motor $Q$.
	//
	//# \action		float BulkNorm(const Motor3D& Q);
	//#				Returns the bulk norm of the motor $Q$.
	//
	//# \action		float WeightNorm(const Motor3D& Q);
	//#				Returns the weight norm of the motor $Q$.
	//
	//# \action		Motor3D Sqrt(const Motor3D& Q);
	//#				Returns the square root of the motor $Q$ with respect to the geometric antiproduct.
	//
	//# \action		Vector3D Transform(const Vector3D& v, const Motor3D& Q);
	//#				Transforms the vector $v$ with the motor $Q$.
	//
	//# \action		Bivector3D Transform(const Bivector3D& v, const Motor3D& Q);
	//#				Transforms the bivector $v$ with the motor $Q$.
	//
	//# \action		Point3D Transform(const Point3D& p, const Motor3D& Q);
	//#				Transforms the point $p$ with the motor $Q$.
	//
	//# \action		Line3D Transform(const Line3D& l, const Motor3D& Q);
	//#				Transforms the line $l$ with the motor $Q$.
	//
	//# \action		Plane3D Transform(const Plane3D& g, const Motor3D& Q);
	//#				Transforms the plane $g$ with the motor $Q$.
	//
	//# \also	$@Flector3D@$
	//# \also	$@Quaternion@$
	//# \also	$@Point3D@$
	//# \also	$@Line3D@$
	//# \also	$@Plane3D@$


	//# \function	Motor3D::Set	Sets all eight components of a motor.
	//
	//# \ctor	Motor3D& Set(float vx, float vy, float vz, float vw, float mx, float my, float mz, float mw);
	//# \ctor	Motor3D& Set(const Quaternion& rotor, const Quaternion& screw);
	//
	//# \param	vx,vy,vz,vw		The values of the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	mx,my,mz,mw		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//# \param	rotor			A quaternion whose entries are copied to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	screw			A quaternion whose entries are copied to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//
	//# \desc
	//# The $Set$ function sets the eight coordinates of a motor.
	//# If the quaternions $rotor$ and $screw$ are specified, then their coordinates are assigned to the weight and bulk of the motor, respectively.
	//#
	//# The return value is a reference to the motor object.


	//# \function	Motor3D::Unitize		Unitizes the weight of a motor.
	//
	//# \proto	Motor3D& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a motor by the inverse magnitude of its weight, which is the quaternion
	//# given by its <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# After calling this function, the rotor component of the motor is unit-length.
	//# If these coordinates are all zero, then the result is undefined.
	//#
	//# The return value is a reference to the motor object.


	//# \function	Motor3D::MakeRotation		Returns a motor that represents a rotation about a given axis through the origin.
	//
	//# \proto	static Motor3D MakeRotation(float angle, const Bivector3D& axis);
	//
	//# \param	angle		The angle of rotation, in radians.
	//# \param	axis		The axis about which to rotate. This bivector must have unit magnitude.
	//
	//# \desc
	//# The $MakeRotation$ function returns a motor representing a rotation through the angle
	//# given by the $angle$ parameter about the axis through the origin given by the $axis$ parameter.
	//# The resulting motor is unitized.
	//
	//# \also	$@Motor3D::MakeTranslation@$
	//# \also	$@Motor3D::MakeScrew@$


	//# \function	Motor3D::MakeTranslation	Returns a motor that represents a translation.
	//
	//# \proto	static Motor3D MakeTranslation(const Vector3D& offset);
	//
	//# \param	offset		The offset vector.
	//
	//# \desc
	//# The $MakeTranslation$ function returns a motor representing a translation by the
	//# direction and magnitude given by the $offset$ parameter.
	//
	//# \also	$@Motor3D::MakeRotation@$
	//# \also	$@Motor3D::MakeScrew@$


	//# \function	Motor3D::MakeScrew			Returns a motor that represents a general screw motion.
	//
	//# \proto	static Motor3D MakeScrew(float angle, const Line3D& axis, float disp);
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
	//# \also	$@Motor3D::MakeRotation@$
	//# \also	$@Motor3D::MakeTranslation@$


	//# \function	Motor3D::GetDirectionX		Returns the direction to which the <i>x</i> axis is transformed by a motor.
	//
	//# \proto	Vector3D GetDirectionX(void) const;
	//
	//# \desc
	//# The $GetDirectionX$ function calculates the 3D vector that results from transforming the direction vector (1,&nbsp;0,&nbsp;0)
	//# with the motor for which it is called.
	//
	//# \also	$@Motor3D::GetDirectionY@$
	//# \also	$@Motor3D::GetDirectionZ@$
	//# \also	$@Motor3D::GetPosition@$
	//# \also	$@Motor3D::GetTransformMatrix@$
	//# \also	$@Motor3D::GetInverseTransformMatrix@$
	//# \also	$@Motor3D::GetTransformMatrices@$
	//# \also	$@Motor3D::SetTransformMatrix@$


	//# \function	Motor3D::GetDirectionY		Returns the direction to which the <i>y</i> axis is transformed by a motor.
	//
	//# \proto	Vector3D GetDirectionY(void) const;
	//
	//# \desc
	//# The $GetDirectionY$ function calculates the 3D vector that results from transforming the direction vector (0,&nbsp;1,&nbsp;0)
	//# with the motor for which it is called.
	//
	//# \also	$@Motor3D::GetDirectionX@$
	//# \also	$@Motor3D::GetDirectionZ@$
	//# \also	$@Motor3D::GetPosition@$
	//# \also	$@Motor3D::GetTransformMatrix@$
	//# \also	$@Motor3D::GetInverseTransformMatrix@$
	//# \also	$@Motor3D::GetTransformMatrices@$
	//# \also	$@Motor3D::SetTransformMatrix@$


	//# \function	Motor3D::GetDirectionZ		Returns the direction to which the <i>z</i> axis is transformed by a motor.
	//
	//# \proto	Vector3D GetDirectionZ(void) const;
	//
	//# \desc
	//# The $GetDirectionZ$ function calculates the 3D vector that results from transforming the direction vector (0,&nbsp;0,&nbsp;1)
	//# with the motor for which it is called.
	//
	//# \also	$@Motor3D::GetDirectionX@$
	//# \also	$@Motor3D::GetDirectionY@$
	//# \also	$@Motor3D::GetPosition@$
	//# \also	$@Motor3D::GetTransformMatrix@$
	//# \also	$@Motor3D::GetInverseTransformMatrix@$
	//# \also	$@Motor3D::GetTransformMatrices@$
	//# \also	$@Motor3D::SetTransformMatrix@$


	//# \function	Motor3D::GetPosition		Returns the position to which the origin is transformed by a motor.
	//
	//# \proto	Point3D GetPosition(void) const;
	//
	//# \desc
	//# The $GetPosition$ function calculates the 3D point that results from transforming the origin
	//# with the motor for which it is called.
	//
	//# \also	$@Motor3D::GetDirectionX@$
	//# \also	$@Motor3D::GetDirectionY@$
	//# \also	$@Motor3D::GetDirectionZ@$
	//# \also	$@Motor3D::GetTransformMatrix@$
	//# \also	$@Motor3D::GetInverseTransformMatrix@$
	//# \also	$@Motor3D::GetTransformMatrices@$
	//# \also	$@Motor3D::SetTransformMatrix@$


	//# \function	Motor3D::GetTransformMatrix		Converts a motor to its corresponding 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# \proto	Transform4D GetTransformMatrix(void) const;
	//
	//# \desc
	//# The $GetTransformMatrix$ function converts a motor to the $@Transform4D@$ object that
	//# represents the same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object.
	//
	//# \also	$@Motor3D::GetInverseTransformMatrix@$
	//# \also	$@Motor3D::GetTransformMatrices@$
	//# \also	$@Motor3D::SetTransformMatrix@$
	//# \also	$@Motor3D::GetDirectionX@$
	//# \also	$@Motor3D::GetDirectionY@$
	//# \also	$@Motor3D::GetDirectionZ@$
	//# \also	$@Motor3D::GetPosition@$
	//# \also	$@Motor3D::MakeRotation@$
	//# \also	$@Motor3D::MakeTranslation@$
	//# \also	$@Motor3D::MakeScrew@$


	//# \function	Motor3D::GetInverseTransformMatrix		Converts a motor to the inverse of its corresponding 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# \proto	Transform4D GetInverseTransformMatrix(void) const;
	//
	//# \desc
	//# The $GetInverseTransformMatrix$ function converts a motor to the inverse of the $@Transform4D@$ object that
	//# represents the same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object. Such a matrix
	//# correctly transforms a $@Plane3D@$ object when it postmultiplies it.
	//#
	//# This function performs the same amount of computation as the $@Motor3D::GetTransformMatrix@$ function, and is thus
	//# significantly faster than calling the $@Motor3D::GetTransformMatrix@$ function and inverting the result.
	//
	//# \also	$@Motor3D::GetTransformMatrix@$
	//# \also	$@Motor3D::GetTransformMatrices@$
	//# \also	$@Motor3D::SetTransformMatrix@$
	//# \also	$@Motor3D::GetDirectionX@$
	//# \also	$@Motor3D::GetDirectionY@$
	//# \also	$@Motor3D::GetDirectionZ@$
	//# \also	$@Motor3D::GetPosition@$
	//# \also	$@Motor3D::MakeRotation@$
	//# \also	$@Motor3D::MakeTranslation@$
	//# \also	$@Motor3D::MakeScrew@$


	//# \function	Motor3D::GetTransformMatrices		Converts a motor to its corresponding 4&#x202F;&times;&#x202F;4 matrix and its inverse simultaneously.
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
	//# Calling this function is much faster than making separate calls to the $@Motor3D::GetTransformMatrix@$ and
	//# $@Motor3D::GetInverseTransformMatrix@$ functions.
	//
	//# \also	$@Motor3D::GetTransformMatrix@$
	//# \also	$@Motor3D::GetInverseTransformMatrix@$
	//# \also	$@Motor3D::SetTransformMatrix@$
	//# \also	$@Motor3D::GetDirectionX@$
	//# \also	$@Motor3D::GetDirectionY@$
	//# \also	$@Motor3D::GetDirectionZ@$
	//# \also	$@Motor3D::GetPosition@$
	//# \also	$@Motor3D::MakeRotation@$
	//# \also	$@Motor3D::MakeTranslation@$
	//# \also	$@Motor3D::MakeScrew@$


	//# \function	Motor3D::SetTransformMatrix		Converts a 4&#x202F;&times;&#x202F;4 matrix to its corresponding motor.
	//
	//# \proto	Motor3D& SetTransformMatrix(const Transform4D& M);
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
	//# \also	$@Motor3D::GetTransformMatrix@$
	//# \also	$@Motor3D::GetInverseTransformMatrix@$
	//# \also	$@Motor3D::GetTransformMatrices@$
	//# \also	$@Motor3D::MakeRotation@$
	//# \also	$@Motor3D::MakeTranslation@$
	//# \also	$@Motor3D::MakeScrew@$


	class Motor3D
	{
		public:

			Quaternion		v;			//## The coordinates of the weight components using basis elements <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and <b>e</b><sub>1234</sub>.
			Quaternion		m;			//## The coordinates of the bulk components using basis elements <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and <b>1</b>.

			TERATHON_API static const ConstMotor3D identity;

			inline Motor3D() = default;

			Motor3D(float vx, float vy, float vz, float vw, float mx, float my, float mz, float mw)
			{
				v.Set(vx, vy, vz, vw);
				m.Set(mx, my, mz, mw);
			}

			explicit Motor3D(const Quaternion& rotor)
			{
				v = rotor;
				m.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Motor3D(const Quaternion& rotor, const Quaternion& screw)
			{
				v = rotor;
				m = screw;
			}

			Motor3D(const Plane3D& g, const Plane3D& h)
			{
				v.Set(g.y * h.z - g.z * h.y, g.z * h.x - g.x * h.z, g.x * h.y - g.y * h.x, g.x * h.x + g.y * h.y + g.z * h.z);
				m.Set(g.w * h.x - g.x * h.w, g.w * h.y - g.y * h.w, g.w * h.z - g.z * h.w, 0.0F);
			}

			Motor3D(const Line3D& k, const Line3D& l)
			{
				v.Set(k.v ^ l.v, -Dot(k.v, l.v));
				m.Set((l.v ^ !k.m) - (k.v ^ !l.m), -(l.v ^ k.m) - (k.v ^ l.m));
			}

			Motor3D(const Point3D& p, const Point3D& q)
			{
				v.Set(0.0F, 0.0F, 0.0F, -1.0F);
				m.Set(p.x - q.x, p.y - q.y, p.z - q.z, 0.0F);
			}

			Motor3D& Set(float vx, float vy, float vz, float vw, float mx, float my, float mz, float mw)
			{
				v.Set(vx, vy, vz, vw);
				m.Set(mx, my, mz, mw);
				return (*this);
			}

			void Set(float vx, float vy, float vz, float vw, float mx, float my, float mz, float mw) volatile
			{
				v.Set(vx, vy, vz, vw);
				m.Set(mx, my, mz, mw);
			}

			Motor3D& Set(const Quaternion& rotor, const Quaternion& screw)
			{
				v = rotor;
				m = screw;
				return (*this);
			}

			void Set(const Quaternion& rotor, const Quaternion& screw) volatile
			{
				v = rotor;
				m = screw;
			}

			Motor3D& operator =(const Motor3D& Q)
			{
				v = Q.v;
				m = Q.m;
				return (*this);
			}

			void operator =(const Motor3D& Q) volatile
			{
				v = Q.v;
				m = Q.m;
			}

			Motor3D& operator =(const Quaternion& rotor)
			{
				v = rotor;
				m.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Quaternion& rotor) volatile
			{
				v = rotor;
				m.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Motor3D& operator +=(const Motor3D& Q)
			{
				v += Q.v;
				m += Q.m;
				return (*this);
			}

			Motor3D& operator -=(const Motor3D& Q)
			{
				v -= Q.v;
				m -= Q.m;
				return (*this);
			}

			Motor3D& operator *=(float n)
			{
				v *= n;
				m *= n;
				return (*this);
			}

			Motor3D& operator /=(float n)
			{
				n = 1.0F / n;
				v *= n;
				m *= n;
				return (*this);
			}

			Motor3D& Unitize(void)
			{
				return (*this *= InverseMag(v));
			}

			static Motor3D MakeRotation(float angle, const Bivector3D& axis)
			{
				Vector2D t = CosSin(angle * 0.5F);
				return (Motor3D(axis.x * t.y, axis.y * t.y, axis.z * t.y, t.x, 0.0F, 0.0F, 0.0F, 0.0F));
			}

			static Motor3D MakeTranslation(const Vector3D& offset)
			{
				return (Motor3D(0.0F, 0.0F, 0.0F, 1.0F, offset.x * 0.5F, offset.y * 0.5F, offset.z * 0.5F, 0.0F));
			}

			static Motor3D MakeScrew(float angle, const Line3D& axis, float disp)
			{
				disp *= 0.5F;
				Vector2D t = CosSin(angle * 0.5F);
				return (Motor3D(axis.v.x * t.y, axis.v.y * t.y, axis.v.z * t.y, t.x, disp * axis.v.x * t.x + axis.m.x * t.y, disp * axis.v.y * t.x + axis.m.y * t.y, disp * axis.v.z * t.x + axis.m.z * t.y, -disp * t.y));
			}

			TERATHON_API Vector3D GetDirectionX(void) const;
			TERATHON_API Vector3D GetDirectionY(void) const;
			TERATHON_API Vector3D GetDirectionZ(void) const;
			TERATHON_API Point3D GetPosition(void) const;

			TERATHON_API Transform4D GetTransformMatrix(void) const;
			TERATHON_API Transform4D GetInverseTransformMatrix(void) const;
			TERATHON_API void GetTransformMatrices(Transform4D *M, Transform4D *Minv) const;
			TERATHON_API Motor3D& SetTransformMatrix(const Transform4D& M);
	};


	inline Motor3D Reverse(const Motor3D& Q)
	{
		return (Motor3D(-Q.v.x, -Q.v.y, -Q.v.z, Q.v.w, -Q.m.x, -Q.m.y, -Q.m.z, Q.m.w));
	}

	inline Motor3D Antireverse(const Motor3D& Q)
	{
		return (Motor3D(-Q.v.x, -Q.v.y, -Q.v.z, Q.v.w, -Q.m.x, -Q.m.y, -Q.m.z, Q.m.w));
	}

	inline Motor3D operator ~(const Motor3D& Q)
	{
		return (Antireverse(Q));
	}

	inline Motor3D operator -(const Motor3D& Q)
	{
		return (Motor3D(-Q.v.x, -Q.v.y, -Q.v.z, -Q.v.w, -Q.m.x, -Q.m.y, -Q.m.z, -Q.m.w));
	}

	inline Motor3D operator +(const Motor3D& a, const Motor3D& b)
	{
		return (Motor3D(a.v + b.v, a.m + b.m));
	}

	inline Motor3D operator -(const Motor3D& a, const Motor3D& b)
	{
		return (Motor3D(a.v - b.v, a.m - b.m));
	}

	inline Motor3D operator *(const Motor3D& Q, float n)
	{
		return (Motor3D(Q.v.x * n, Q.v.y * n, Q.v.z * n, Q.v.w * n, Q.m.x * n, Q.m.y * n, Q.m.z * n, Q.m.w * n));
	}

	inline Motor3D operator *(float n, const Motor3D& Q)
	{
		return (Motor3D(n * Q.v.x, n * Q.v.y, n * Q.v.z, n * Q.v.w, n * Q.m.x, n * Q.m.y, n * Q.m.z, n * Q.m.w));
	}

	inline Motor3D operator /(const Motor3D& Q, float n)
	{
		n = 1.0F / n;
		return (Motor3D(Q.v.x * n, Q.v.y * n, Q.v.z * n, Q.v.w * n, Q.m.x * n, Q.m.y * n, Q.m.z * n, Q.m.w * n));
	}

	inline bool operator ==(const Motor3D& a, const Motor3D& b)
	{
		return ((a.v == b.v) && (a.m == b.m));
	}

	inline bool operator !=(const Motor3D& a, const Motor3D& b)
	{
		return ((a.v != b.v) || (a.m != b.m));
	}


	TERATHON_API Motor3D operator *(const Motor3D& a, const Motor3D& b);
	TERATHON_API Motor3D operator *(const Motor3D& Q, const Quaternion& r);
	TERATHON_API Motor3D operator *(const Quaternion& r, const Motor3D& Q);


	TERATHON_API Motor3D Sqrt(const Motor3D& Q);


	inline Vector3D Transform(const Vector3D& v, const Motor3D& Q)
	{
		return (Transform(v, Q.v));
	}

	inline Bivector3D Transform(const Bivector3D& v, const Motor3D& Q)
	{
		return (!Transform(!v, Q.v));
	}

	TERATHON_API Vector4D Transform(const Vector4D& p, const Motor3D& Q);
	TERATHON_API Point3D Transform(const Point3D& p, const Motor3D& Q);
	TERATHON_API Line3D Transform(const Line3D& l, const Motor3D& Q);
	TERATHON_API Plane3D Transform(const Plane3D& g, const Motor3D& Q);


	inline float BulkNorm(const Motor3D& Q)
	{
		return (Magnitude(Q.m));
	}

	inline float WeightNorm(const Motor3D& Q)
	{
		return (Magnitude(Q.v));
	}

	inline Motor3D Unitize(const Motor3D& Q)
	{
		return (Q * InverseMag(Q.v));
	}


	struct ConstMotor3D
	{
		float	vx, vy, vz, vw;
		float	mx, my, mz, mw;

		operator const Motor3D&(void) const
		{
			return (reinterpret_cast<const Motor3D&>(*this));
		}

		const Motor3D *operator &(void) const
		{
			return (reinterpret_cast<const Motor3D *>(this));
		}

		const Motor3D *operator ->(void) const
		{
			return (reinterpret_cast<const Motor3D *>(this));
		}
	};
}


#endif
