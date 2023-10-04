# Terathon Math Library

This is a C++ math library containing classes for vectors, matrices, quaternions, and elements of projective geometric algebra. The specific classes are the following:

* **Vector2D** – A 2D vector (*x*, *y*) that extends to four dimensions as (*x*, *y*, 0, 0).
* **Vector3D** – A 3D vector (*x*, *y*, *z*) that extends to four dimensions as (*x*, *y*, *z*, 0).
* **Vector4D** – A 4D vector (*x*, *y*, *z*, *w*).
* **Point2D** – A 2D point (*x*, *y*) that extends to four dimensions as (*x*, *y*, 0, 1).
* **Point3D** – A 3D point (*x*, *y*, *z*) that extends to four dimensions as (*x*, *y*, *z*, 1).
* **Bivector3D** – A 3D bivector *x* **e**<sub>23</sub> + *y* **e**<sub>31</sub> + *z* **e**<sub>12</sub>.
* **Matrix2D** – A 2×2 matrix.
* **Matrix3D** – A 3×3 matrix.
* **Matrix4D** – A 4×4 matrix.
* **Transform2D** – A 3×3 matrix with fourth row always (0, 0, 1).
* **Transform3D** – A 4×4 matrix with fourth row always (0, 0, 0, 1).
* **Quaternion** – A conventional quaternion x**i** + y**j** + z**k** + w.

2D rigid geometric algebra
* **FlatPoint2D** – A 2D flat point *x* **e**<sub>1</sub> + *y* **e**<sub>2</sub> + *z* **e**<sub>3</sub>.
* **Line2D** – A 2D line *g<sub>x</sub>* **e**<sub>23</sub> + *g<sub>y</sub>* **e**<sub>31</sub> + *g<sub>z</sub>* **e**<sub>12</sub>.

3D rigid geometric algebra
* **FlatPoint3D** – A 3D [flat point](https://rigidgeometricalgebra.org/wiki/index.php?title=Point) *x* **e**<sub>1</sub> + *y* **e**<sub>2</sub> + *z* **e**<sub>3</sub> + *w* **e**<sub>4</sub>.
* **Line3D** – A 3D [line](https://rigidgeometricalgebra.org/wiki/index.php?title=Line) *v<sub>x</sub>* **e**<sub>41</sub> + *v<sub>y</sub>* **e**<sub>42</sub> + *v<sub>z</sub>* **e**<sub>43</sub> + *m<sub>x</sub>* **e**<sub>23</sub> + *m<sub>y</sub>* **e**<sub>31</sub> + *m<sub>z</sub>* **e**<sub>12</sub>.
* **Plane3D** – A 3D [plane](https://rigidgeometricalgebra.org/wiki/index.php?title=Plane) *x* **e**<sub>234</sub> + *y* **e**<sub>314</sub> + *z* **e**<sub>124</sub> + *w* **e**<sub>321</sub>.
* **Motor3D** – A 3D [motion operator](https://projectivegeometricalgebra.org/wiki/index.php?title=Motor) *r<sub>x</sub>* **e**<sub>41</sub> + *r<sub>y</sub>* **e**<sub>42</sub> + *r<sub>z</sub>* **e**<sub>43</sub> + *r<sub>w</sub>* 𝟙 + *u<sub>x</sub>* **e**<sub>23</sub> + *u<sub>y</sub>* **e**<sub>31</sub> + *u<sub>z</sub>* **e**<sub>12</sub> + *u<sub>w</sub>*.
* **Flector3D** - A 3D [reflection operator](https://projectivegeometricalgebra.org/wiki/index.php?title=Flector) *s<sub>x</sub>* **e**<sub>1</sub> + *s<sub>y</sub>* **e**<sub>2</sub> + *s<sub>z</sub>* **e**<sub>3</sub> + *s<sub>w</sub>* **e**<sub>4</sub> + *h<sub>x</sub>* **e**<sub>234</sub> + *h<sub>y</sub>* **e**<sub>314</sub> + *h<sub>z</sub>* **e**<sub>124</sub> + *h<sub>w</sub>* **e**<sub>321</sub>.

2D conformal geometric algebra
* **RoundPoint2D** – A 2D round point *x* **e**<sub>1</sub> + *y* **e**<sub>2</sub> + *z* **e**<sub>3</sub> + *w* **e**<sub>4</sub>.
* **Dipole2D** – A 2D dipole *d<sub>gx</sub>* **e**<sub>23</sub> + *d<sub>gy</sub>* **e**<sub>31</sub> + *d<sub>gz</sub>* **e**<sub>12</sub> + *d<sub>px</sub>* **e**<sub>41</sub> + *d<sub>py</sub>* **e**<sub>42</sub> + *d<sub>pz</sub>* **e**<sub>43</sub>.
* **Circle2D** – A 2D circle *w* **e**<sub>321</sub> + *x* **e**<sub>423</sub> + *y* **e**<sub>431</sub> + *z* **e**<sub>412</sub>.

3D conformal geometric algebra
* **RoundPoint3D** – A 3D [round point](https://conformalgeometricalgebra.org/wiki/index.php?title=Round_point) *x* **e**<sub>1</sub> + *y* **e**<sub>2</sub> + *z* **e**<sub>3</sub> + *w* **e**<sub>4</sub> + *u* **e**<sub>5</sub>.
* **Dipole3D** – A 3D [dipole](https://conformalgeometricalgebra.org/wiki/index.php?title=Dipole) *d<sub>vx</sub>* **e**<sub>41</sub> + *d<sub>vy</sub>* **e**<sub>42</sub> + *d<sub>vz</sub>* **e**<sub>43</sub> + *d<sub>mx</sub>* **e**<sub>23</sub> + *d<sub>my</sub>* **e**<sub>31</sub> + *d<sub>mz</sub>* **e**<sub>12</sub> + *d<sub>px</sub>* **e**<sub>15</sub> + *d<sub>py</sub>* **e**<sub>25</sub> + *d<sub>pz</sub>* **e**<sub>35</sub> + *d<sub>pw</sub>* **e**<sub>45</sub>.
* **Circle3D** – A 3D [circle](https://conformalgeometricalgebra.org/wiki/index.php?title=Circle) *c<sub>gx</sub>* **e**<sub>423</sub> + *c<sub>gy</sub>* **e**<sub>431</sub> + *c<sub>gz</sub>* **e**<sub>412</sub> + *c<sub>gw</sub>* **e**<sub>321</sub> + *c<sub>vx</sub>* **e**<sub>415</sub> + *c<sub>vy</sub>* **e**<sub>425</sub> + *c<sub>vz</sub>* **e**<sub>435</sub> + *c<sub>mx</sub>* **e**<sub>235</sub> + *c<sub>my</sub>* **e**<sub>315</sub> + *c<sub>mz</sub>* **e**<sub>125</sub>.
* **Sphere3D** – A 3D [sphere](https://conformalgeometricalgebra.org/wiki/index.php?title=Sphere) *u* **e**<sub>1234</sub> + *x* **e**<sub>4235</sub> + *y* **e**<sub>4315</sub> + *z* **e**<sub>4125</sub> + *w* **e**<sub>3215</sub>.

## Component Swizzling

Vector components can be swizzled using shading-language syntax. As an example, the following expressions are all valid for a `Vector3D` object `v`:

* `v.x` – The *x* component of `v`.
* `v.xy` – A 2D vector having the *x* and *y* components of `v`.
* `v.yzx` – A 3D vector having the components of `v` in the order (*y*, *z*, *x*).

Support for repeated components in a swizzle can be enabled by defining `TERATHON_SWIZZLE_REPEAT`. This is disabled by default because the large number of additional swizzling possibilities increases compile times substantially. Swizzles with repeated components are always `const` so that it's not possible to assign to them.

Rows, columns, and submatrices can be extracted from matrix objects using a similar syntax. As an example, the following expressions are all valid for a `Matrix3D` object `m`:

* `m.m12` – The (1,2) entry of `m`.
* `m.row0` – The first row of `m`.
* `m.col1` – The second column of `m`.
* `m.matrix2D` – The upper-left 2×2 submatrix of `m`.
* `m.transpose` – The transpose of `m`.

All of the above are generally *free operations*, with no copying, when their results are consumed by an expression. For more information, see Eric Lengyel's 2018 GDC talk [Linear Algebra Upgraded](http://terathon.com/gdc18_lengyel.pdf).

## Geometric Algebra

The `^` operator is overloaded for cases in which the wedge or antiwedge product can be applied between vectors, bivectors, flat points, lines, planes, round points, dipoles, circles, and spheres. (Note that `^` has lower precedence than just about everything else, so parentheses will be necessary.)

The library does not provide operators that directly calculate the geometric product and antiproduct because they would tend to generate inefficient code and produce intermediate results having unnecessary types when something like the sandwich product **Q** ⟇ *p* ⟇ ~**Q** appears in an expression. Instead, there are `Transform()` functions that take some object *p* for the first parameter and the motor **Q** with which to transform it for the second parameter.

See Eric Lengyel's [Projective Geometric Algebra website](http://projectivegeometricalgebra.org) for more information about operations among these types.

## API Documentation

There is API documentation embedded in the header files. The formatted equivalent can be found in the [C4 Engine documentation](http://c4engine.com/docs/Math/index.html).

## Licensing

Separate proprietary licenses are available from Terathon Software. Please [send an email](mailto:service@terathon.com) with details about your particular use case if you are interested.
