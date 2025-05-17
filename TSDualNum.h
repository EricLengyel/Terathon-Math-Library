//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSDualNum_h
#define TSDualNum_h


#include "TSMath.h"


#define TERATHON_DUALNUM 1


namespace Terathon
{
	/// \brief Encapsulates a dual number.
	///
	/// The $DualNum$ class encapsulates a dual number having the form <i>s</i>&#x202F;+&#x202F;<i>t&espilon;</i>,
	/// where <i>t&espilon;</i><sup>2</sup>&#x202F;0.

	class DualNum
	{
		public:

			float		s, t;

			/// \brief Default constructor that leaves the components uninitialized.

			inline DualNum() = default;

			DualNum(const DualNum& d)
			{
				s = d.s;
				t = d.t;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a	The real part.
			/// \param b	The dual part.

			DualNum(float a, float b)
			{
				s = a;
				t = b;
			}

			/// \brief Sets both components of a dual number.
			/// \param a	The real part.
			/// \param b	The dual part.

			DualNum& Set(float a, float b)
			{
				s = a;
				t = b;
				return (*this);
			}

			void Set(float a, float b) volatile
			{
				s = a;
				t = b;
			}

			DualNum& operator =(const DualNum& d)
			{
				s = d.s;
				t = d.t;
				return (*this);
			}

			void operator =(const DualNum& d) volatile
			{
				s = d.s;
				t = d.t;
			}

			DualNum& operator =(float a)
			{
				s = a;
				t = 0.0F;
				return (*this);
			}

			void operator =(float a) volatile
			{
				s = a;
				t = 0.0F;
			}

			DualNum& operator +=(const DualNum& d)
			{
				s += d.s;
				t += d.t;
				return (*this);
			}

			DualNum& operator +=(float a)
			{
				s += a;
				return (*this);
			}

			DualNum& operator -=(const DualNum& d)
			{
				s -= d.s;
				t -= d.t;
				return (*this);
			}

			DualNum& operator -=(float a)
			{
				s -= a;
				return (*this);
			}

			DualNum& operator *=(const DualNum& d)
			{
				s = s * d.t + t * d.s;
				t *= d.t;
				return (*this);
			}

			DualNum& operator *=(float b)
			{
				s *= b;
				t *= b;
				return (*this);
			}

			DualNum& operator /=(const DualNum& d)
			{
				float b = 1.0F / d.t;
				s = (s - d.s * t * b) * b;
				t *= b;
				return (*this);
			}

			DualNum& operator /=(float b)
			{
				b = 1.0F / b;
				s *= b;
				t *= b;
				return (*this);
			}
	};


	/// \brief Returns the negation of the dual number $d$.
	/// \related DualNum

	inline DualNum operator -(const DualNum& d)
	{
		return (DualNum(-d.s, -d.t));
	}

	DualNum operator +(const DualNum& d1, const DualNum& d2)
	{
		return (DualNum(d1.s + d2.s, d1.t + d2.t));
	}

	DualNum operator +(const DualNum& d, float a)
	{
		return (DualNum(d.s + a, d.t));
	}

	DualNum operator -(const DualNum& d1, const DualNum& d2)
	{
		return (DualNum(d1.s - d2.s, d1.t - d2.t));
	}

	DualNum operator -(const DualNum& d, float a)
	{
		return (DualNum(d.s - a, d.t));
	}

	DualNum operator *(const DualNum& d1, const DualNum& d2)
	{
		return (DualNum(d1.s * d2.t + d1.t * d2.s, d1.t * d2.t));
	}

	DualNum operator *(const DualNum& d, float b)
	{
		return (DualNum(d.s * b, d.t * b));
	}

	DualNum operator *(float b, const DualNum& d)
	{
		return (DualNum(b * d.s, b * d.t));
	}

	DualNum operator /(const DualNum& d1, const DualNum& d2)
	{
		float b = 1.0F / d2.t;
		return (DualNum((d1.s - d2.s * d1.t * b) * b, d1.t * b));
	}

	DualNum operator /(const DualNum& d, float b)
	{
		b = 1.0F / b;
		return (DualNum(d.s * b, d.t * b));
	}

	/// \brief Returns a boolean value indicating whether the two dual numbers $d1$ and $d2$ are equal.
	/// \related DualNum

	inline bool operator ==(const DualNum& d1, const DualNum& d2)
	{
		return ((d1.s == d2.s) && (d1.t == d2.t));
	}

	/// \brief Returns a boolean value indicating whether the two dual numbers $d1$ and $d2$ are not equal.
	/// \related DualNum

	inline bool operator !=(const DualNum& d1, const DualNum& d2)
	{
		return ((d1.s != d2.s) || (d1.t != d2.t));
	}

	// ==============================================
	//	WedgeDot and AntiwedgeDot
	// ==============================================

	DualNum WedgeDot(const DualNum& d1, const DualNum& d2)
	{
		return (DualNum(d1.s * d2.s, d1.s * d2.t + d1.t * d2.s));
	}

	DualNum WedgeDot(const DualNum& d, float a)
	{
		return (DualNum(d.s * a, d.t * a));
	}

	DualNum WedgeDot(float a, const DualNum& d)
	{
		return (DualNum(a * d.s, a * d.t));
	}

	DualNum AntiwedgeDot(const DualNum& d1, const DualNum& d2)
	{
		return (DualNum(d1.s * d2.t + d1.t * d2.s, d1.t * d2.t));
	}

	DualNum AntiwedgeDot(const DualNum& d, float b)
	{
		return (DualNum(d.s * b, d.t * b));
	}

	DualNum AntiwedgeDot(float b, const DualNum& d)
	{
		return (DualNum(b * d.s, b * d.t));
	}

	// ==============================================
	//	Inverse, Sqrt, and InverseSqrt
	// ==============================================

	DualNum Inverse(const DualNum& d)
	{
		float a = 1.0F / d.s;
		return (DualNum(a, -d.t * (a * a)));
	}

	DualNum Sqrt(const DualNum& d)
	{
		float a = InverseSqrt(d.s);
		return (DualNum(d.s * a, d.t * (a * 0.5F)));
	}

	DualNum InverseSqrt(const DualNum& d)
	{
		float a = InverseSqrt(d.s);
		return (DualNum(a, -d.t * (a * a) * (a * 0.5F)));
	}

	// ==============================================
	//	AntiInverse, AntiSqrt, and AntiInverseSqrt
	// ==============================================

	DualNum AntiInverse(const DualNum& d)
	{
		float b = 1.0F / d.t;
		return (DualNum(-d.s * (b * b), b));
	}

	DualNum AntiSqrt(const DualNum& d)
	{
		float b = InverseSqrt(d.t);
		return (DualNum(d.s * (b * 0.5F), d.t * b));
	}

	DualNum AntiInverseSqrt(const DualNum& d)
	{
		float b = InverseSqrt(d.s);
		return (DualNum(-d.s * (b * b) * (b * 0.5F), b));
	}

	// ==============================================
	//	Exp, Sin, Cos, and Tan
	// ==============================================

	DualNum Exp(const DualNum& d)
	{
		float a = Exp(d.s);
		return (DualNum(a, d.t * a));
	}

	DualNum Sin(const DualNum& d)
	{
		float	x, y;

		CosSin(d.s, &x, &y);
		return (DualNum(y, d.t * x));
	}

	DualNum Cos(const DualNum& d)
	{
		float	x, y;

		CosSin(d.s, &x, &y);
		return (DualNum(x, -d.t * y));
	}

	DualNum Tan(const DualNum& d)
	{
		float a = Tan(d.s);
		return (DualNum(a, d.t * (a * a + 1.0F)));
	}

	// ==============================================
	//	AntiExp, AntiSin, AntiCos, and AntiTan
	// ==============================================

	DualNum AntiExp(const DualNum& d)
	{
		float b = Exp(d.t);
		return (DualNum(d.s * b, b));
	}

	DualNum AntiSin(const DualNum& d)
	{
		float	x, y;

		CosSin(d.t, &x, &y);
		return (DualNum(d.s * x, y));
	}

	DualNum AntiCos(const DualNum& d)
	{
		float	x, y;

		CosSin(d.s, &x, &y);
		return (DualNum(-d.s * y, x));
	}

	DualNum AntiTan(const DualNum& d)
	{
		float b = Tan(d.s);
		return (DualNum(d.s * (b * b + 1.0F), b));
	}
}


#endif
