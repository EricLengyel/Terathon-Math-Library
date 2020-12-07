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


#ifndef TSMotor_h
#define TSMotor_h


//# \component	Math Library
//# \prefix		Math/


#include "TSBivector4D.h"
#include "TSQuaternion.h"


#define TERATHON_MOTOR 1


namespace Terathon
{
	//# \class	Motor		Encapsulates a 4D motion operator (motor).
	//
	//# The $motor$ class encapsulates a 4D motion operator (motor), also known as a dual quaternion.
	//# For more information about motors, see the <a href="http://projectivegeometricalgebra.org">projective geometric algebra</a> website.
	//
	//# \def	class Motor
	//
	//# \ctor	Motor();
	//# \ctor	Motor(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw);
	//# \ctor	Motor(const Quaternion& r);
	//# \ctor	Motor(const Quaternion& r, const Quaternion& u);
	//# \ctor	Motor(const Trivector4D& f, const Trivector4D& g);
	//# \ctor	Motor(const Bivector4D& K, const Bivector4D& L);
	//# \ctor	Motor(const Point3D& p, const Point3D& q);
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
	//# The $Motor$ class encapsulates a motion operator (motor) in the 4D projective geometric algebra.
	//# It has the general form <i>r<sub>x</sub></i><b>e</b><sub>41</sub> + <i>r<sub>y</sub></i><b>e</b><sub>42</sub> + <i>r<sub>y</sub></i><b>e</b><sub>43</sub> + <i>r<sub>w</sub></i>&#x1D7D9; + <i>u<sub>x</sub></i><b>e</b><sub>23</sub> + <i>u<sub>y</sub></i><b>e</b><sub>31</sub> + <i>u<sub>y</sub></i><b>e</b><sub>12</sub> + <i>u<sub>w</sub></i>.
	//#
	//# The default constructor leaves the components of the motor undefined.
	//# If the quaternions $r$ and $u$ are specified, then their coordinates are assigned to the weight and bulk of the motor, respectively.
	//# If only the quaternion $r$ is specified, then the bulk of the motor is set to zero.
	//#
	//# If the $f$ and $g$ parameters are specified, then the motor is set to the geometric antiproduct $g$&#x202F;&#x27C7;&#x202F;$f$,
	//# corresponding to the rotation about the line where the planes $f$ and $g$ intersect by twice the angle between them in the direction from $f$ to $g$.
	//#
	//# If the $K$ and $L$ parameters are specified, then the motor is set to the geometric antiproduct $L$&#x202F;&#x27C7;&#x202F;$K$,
	//# corresponding to the rotation about the line containing the closest points on the lines $K$ and $L$ by twice the angle their directions and the translation by twice the distance between the lines in the direction from $K$ to $L$.
	//#
	//# If the $p$ and $q$ parameters are specified, then the motor is set to the geometric antiproduct $q$&#x202F;&#x27C7;&#x202F;$p$,
	//# corresponding to the translation by twice the distance between the points $p$ and $q$ in the direction from $p$ to $q$.
	//
	//# \operator	Motor& operator +=(const Motor& Q);
	//#				Adds the motor $Q$.
	//
	//# \operator	Motor& operator -=(const Motor& Q);
	//#				Subtracts the motor $Q$.
	//
	//# \operator	Motor& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Motor& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		Motor operator ~(const Motor& Q);
	//#				Returns the antireverse of the motor $Q$.
	//
	//# \action		Motor operator -(const Motor& Q);
	//#				Returns the negation of the motor $Q$.
	//
	//# \action		Motor operator +(const Motor& a, const Motor& b) const;
	//#				Returns the sum of the motors $a$ and $b$.
	//
	//# \action		Motor operator -(const Motor& a, const Motor& b) const;
	//#				Returns the difference of the motors $a$ and $b$.
	//
	//# \action		Motor operator *(const Motor& Q, float s);
	//#				Returns the product of the motor $Q$ and the scalar $s$.
	//
	//# \action		Motor operator *(float s, const Motor& Q);
	//#				Returns the product of the motor $Q$ and the scalar $s$.
	//
	//# \action		Motor operator /(const Motor& Q, float s);
	//#				Returns the product of the motor $Q$ and the inverse of the scalar $s$.
	//
	//# \action		Motor operator *(const Motor& a, const Motor& b);
	//#				Returns the geometric antiproduct of the motors $a$ and $b$.
	//
	//# \action		Motor operator *(const Motor& Q, const Quaternion& r);
	//#				Returns the geometric antiproduct of the motor $Q$ and the quaternion $r$.
	//
	//# \action		Motor operator *(const Quaternion& r, const Motor& Q);
	//#				Returns the geometric antiproduct of the quaternion $r$ and the motor $Q$.
	//
	//# \action		bool operator ==(const Motor& a, const Motor& b);
	//#				Returns a boolean value indicating the equality of the two motors $a$ and $b$.
	//
	//# \action		bool operator !=(const Motor& a, const Motor& b);
	//#				Returns a boolean value indicating the inequality of the two motors $a$ and $b$.
	//
	//# \action		Vector3D Transform(const Vector3D& v, const Motor& Q);
	//#				Transforms the vector $v$ with the motor $Q$.
	//
	//# \action		Bivector3D Transform(const Bivector3D& v, const Motor& Q);
	//#				Transforms the bivector $v$ with the motor $Q$.
	//
	//# \action		Point3D Transform(const Point3D& p, const Motor& Q);
	//#				Transforms the point $p$ with the motor $Q$.
	//
	//# \action		Bivector4D Transform(const Bivector4D& L, const Motor& Q);
	//#				Transforms the line $L$ with the motor $Q$.
	//
	//# \action		Trivector4D Transform(const Trivector4D& f, const Motor& Q);
	//#				Transforms the plane $f$ with the motor $Q$.
	//
	//# \also	$@Quaternion@$
	//# \also	$@Trivector4D@$
	//# \also	$@Bivector4D@$
	//# \also	$@Point3D@$


	//# \function	Motor::Set		Sets all eight components of a motor.
	//
	//# \ctor	Motor& Set(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw);
	//# \ctor	Motor& Set(const Quaternion& r);
	//# \ctor	Motor& Set(const Quaternion& r, const Quaternion& u);
	//
	//# \param	rx,ry,rz,rw		The values of the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	ux,uy,uz,uw		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//# \param	r				A quaternion whose entries are copied to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# \param	u				A quaternion whose entries are copied to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.
	//
	//# \desc
	//# The $Set$ function sets the eight coordinates of a motor.
	//# If the quaternions $r$ and $u$ are specified, then their coordinates are assigned to the weight and bulk of the motor, respectively.
	//# If only the quaternion $r$ is specified, then the bulk of the motor is set to zero.
	//#
	//# The return value is a reference to the motor object.


	//# \function	Motor::Unitize		Unitizes the weight of a motor.
	//
	//# \proto	Motor& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a motor by the inverse magnitude of its weight, which is the quaternion
	//# given by its <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	//# After calling this function, the rotor component of the motor is unit-length.
	//# If these coordinates are all zero, then the result is undefined.
	//#
	//# The return value is a reference to the motor object.


	//# \function	Motor::MakeRotation		Returns a motor that represents a rotation about a given axis through the origin.
	//
	//# \proto	static Motor MakeRotation(float angle, const Bivector3D& axis);
	//
	//# \param	angle		The angle of rotation, in radians.
	//# \param	axis		The axis about which to rotate. This bivector must have unit magnitude.
	//
	//# \desc
	//# The $MakeRotation$ function returns a motor representing a rotation through the angle
	//# given by the $angle$ parameter about the axis through the origin given by the $axis$ parameter.
	//# The resulting motor is unitized.
	//
	//# \also	$@Motor::MakeTranslation@$
	//# \also	$@Motor::MakeScrew@$


	//# \function	Motor::MakeTranslation		Returns a motor that represents a translation.
	//
	//# \proto	static Motor MakeTranslation(const Vector3D& offset);
	//
	//# \param	offset		The offset vector.
	//
	//# \desc
	//# The $MakeTranslation$ function returns a motor representing a translation by the
	//# direction and magnitude given by the $offset$ parameter.
	//
	//# \also	$@Motor::MakeRotation@$
	//# \also	$@Motor::MakeScrew@$


	//# \function	Motor::MakeScrew		Returns a motor that represents a general screw motion.
	//
	//# \proto	static Motor MakeScrew(float angle, const Bivector4D& axis, float disp);
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
	//# \also	$@Motor::MakeRotation@$
	//# \also	$@Motor::MakeTranslation@$


	//# \function	Motor::GetTransformMatrix		Converts a motor to a 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# \proto	Transform4D GetTransformMatrix(void) const;
	//
	//# \desc
	//# The $GetTransformMatrix$ function converts a motor to a $@Transform4D@$ object that
	//# represents the same transformation when it premultiplies a $@Vector3D@$ or $@Point3D@$ object.
	//
	//# \also	$@Motor::SetTransformMatrix@$
	//# \also	$@Motor::MakeRotation@$
	//# \also	$@Motor::MakeTranslation@$
	//# \also	$@Motor::MakeScrew@$


	//# \function	Motor::SetTransformMatrix		Converts a 4&#x202F;&times;&#x202F;4 matrix to a motor.
	//
	//# \proto	Motor& SetTransformMatrix(const Transform4D& H);
	//
	//# \param	H		The matrix to convert to a motor.
	//
	//# \desc
	//# The $SetTransformMatrix$ function sets the components of a motor to values that
	//# represent the same rigid motion as the one represented by the matrix specified by the $H$ parameter.
	//#
	//# For best results, the matrix $H$ should be orthogonal. If the determinant of $H$ is not positive,
	//# then the results are undefined.
	//
	//# \also	$@Motor::GetTransformMatrix@$
	//# \also	$@Motor::MakeRotation@$
	//# \also	$@Motor::MakeTranslation@$
	//# \also	$@Motor::MakeScrew@$


	class Motor
	{
		public:

			Quaternion		rotor;			//## The coordinates of the rotor part consisting of the weight components using basis elements <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and <b>e</b><sub>1234</sub>.
			Quaternion		screw;			//## The coordinates of the screw part consisting of the bulk components using basis elements <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and 1.

			inline Motor() = default;

			Motor(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw)
			{
				rotor.Set(rx, ry, rz, rw);
				screw.Set(ux, uy, uz, uw);
			}

			explicit Motor(const Quaternion& r)
			{
				rotor = r;
				screw.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Motor(const Quaternion& r, const Quaternion& u)
			{
				rotor = r;
				screw = u;
			}

			Motor(const Trivector4D& f, const Trivector4D& g)
			{
				rotor.Set(f.y * g.z - f.z * g.y, f.z * g.x - f.x * g.z, f.x * g.y - f.y * g.x, f.x * g.x + f.y * g.y + f.z * g.z);
				screw.Set(f.w * g.x - f.x * g.w, f.w * g.y - f.y * g.w, f.w * g.z - f.z * g.w, 0.0F);
			}

			Motor(const Bivector4D& K, const Bivector4D& L)
			{
				rotor.Set(K.direction ^ L.direction, -Dot(K.direction, L.direction));
				screw.Set((L.direction ^ !K.moment) - (K.direction ^ !L.moment), -(L.direction ^ K.moment) - (K.direction ^ L.moment));
			}

			Motor(const Point3D& p, const Point3D& q)
			{
				rotor.Set(0.0F, 0.0F, 0.0F, -1.0F);
				screw.Set(p.x - q.x, p.y - q.y, p.z - q.z, 0.0F);
			}

			Motor& Set(float rx, float ry, float rz, float rw, float ux, float uy, float uz, float uw)
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

			Motor& Set(const Quaternion& r)
			{
				rotor = r;
				screw.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void Set(const Quaternion& r) volatile
			{
				rotor = r;
				screw.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Motor& Set(const Quaternion& r, const Quaternion& u)
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

			Motor& operator =(const Motor& Q)
			{
				rotor = Q.rotor;
				screw = Q.screw;
				return (*this);
			}

			void operator =(const Motor& Q) volatile
			{
				rotor = Q.rotor;
				screw = Q.screw;
			}

			Motor& operator =(const Quaternion& r)
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

			Motor& operator +=(const Motor& Q)
			{
				rotor += Q.rotor;
				screw += Q.screw;
				return (*this);
			}

			Motor& operator -=(const Motor& Q)
			{
				rotor -= Q.rotor;
				screw -= Q.screw;
				return (*this);
			}

			Motor& operator *=(float s)
			{
				rotor *= s;
				screw *= s;
				return (*this);
			}

			Motor& operator /=(float s)
			{
				s = 1.0F / s;
				rotor *= s;
				screw *= s;
				return (*this);
			}

			Motor& Unitize(void)
			{
				return (*this *= InverseMag(rotor));
			}

			static Motor MakeRotation(float angle, const Bivector3D& axis)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Motor(axis.x * v.y, axis.y * v.y, axis.z * v.y, v.x, 0.0F, 0.0F, 0.0F, 0.0F));
			}

			static Motor MakeTranslation(const Vector3D& offset)
			{
				return (Motor(0.0F, 0.0F, 0.0F, 1.0F, offset.x * 0.5F, offset.y * 0.5F, offset.z * 0.5F, 0.0F));
			}

			static Motor MakeScrew(float angle, const Bivector4D& axis, float disp)
			{
				disp *= 0.5F;
				Vector2D v = CosSin(angle * 0.5F);
				return (Motor(axis.direction.x * v.y, axis.direction.y * v.y, axis.direction.z * v.y, v.x, disp * axis.direction.x * v.x + axis.moment.x * v.y, disp * axis.direction.y * v.x + axis.moment.y * v.y, disp * axis.direction.z * v.x + axis.moment.z * v.y, -disp * v.y));
			}

			TERATHON_API Transform4D GetTransformMatrix(void) const;
			TERATHON_API Motor& SetTransformMatrix(const Transform4D& H);
	};


	inline Motor operator ~(const Motor& Q)
	{
		return (Motor(-Q.rotor.x, -Q.rotor.y, -Q.rotor.z, Q.rotor.w, -Q.screw.x, -Q.screw.y, -Q.screw.z, Q.screw.w));
	}

	inline Motor operator -(const Motor& Q)
	{
		return (Motor(-Q.rotor.x, -Q.rotor.y, -Q.rotor.z, -Q.rotor.w, -Q.screw.x, -Q.screw.y, -Q.screw.z, -Q.screw.w));
	}

	inline Motor operator +(const Motor& a, const Motor& b)
	{
		return (Motor(a.rotor + b.rotor, a.screw + b.screw));
	}

	inline Motor operator -(const Motor& a, const Motor& b)
	{
		return (Motor(a.rotor - b.rotor, a.screw - b.screw));
	}

	inline Motor operator *(const Motor& Q, float s)
	{
		return (Motor(Q.rotor.x * s, Q.rotor.y * s, Q.rotor.z * s, Q.rotor.w * s, Q.screw.x * s, Q.screw.y * s, Q.screw.z * s, Q.screw.w * s));
	}

	inline Motor operator *(float s, const Motor& Q)
	{
		return (Motor(s * Q.rotor.x, s * Q.rotor.y, s * Q.rotor.z, s * Q.rotor.w, s * Q.screw.x, s * Q.screw.y, s * Q.screw.z, s * Q.screw.w));
	}

	inline Motor operator /(const Motor& Q, float s)
	{
		s = 1.0F / s;
		return (Motor(Q.rotor.x * s, Q.rotor.y * s, Q.rotor.z * s, Q.rotor.w * s, Q.screw.x * s, Q.screw.y * s, Q.screw.z * s, Q.screw.w * s));
	}

	inline bool operator ==(const Motor& a, const Motor& b)
	{
		return ((a.rotor == b.rotor) && (a.screw == b.screw));
	}

	inline bool operator !=(const Motor& a, const Motor& b)
	{
		return ((a.rotor != b.rotor) || (a.screw != b.screw));
	}


	TERATHON_API Motor operator *(const Motor& a, const Motor& b);
	TERATHON_API Motor operator *(const Motor& Q, const Quaternion& r);
	TERATHON_API Motor operator *(const Quaternion& r, const Motor& Q);


	inline Vector3D Transform(const Vector3D& v, const Motor& Q)
	{
		return (Transform(v, Q.rotor));
	}

	inline Bivector3D Transform(const Bivector3D& v, const Motor& Q)
	{
		return (!Transform(!v, Q.rotor));
	}

	Point3D Transform(const Point3D& p, const Motor& Q);
	Bivector4D Transform(const Bivector4D& L, const Motor& Q);
	Trivector4D Transform(const Trivector4D& f, const Motor& Q);
}


#endif
