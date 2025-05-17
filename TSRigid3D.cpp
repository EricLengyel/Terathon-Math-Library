//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSRigid3D.h"


using namespace Terathon;


alignas(16) const ConstFlatPoint3D FlatPoint3D::origin = {0.0F, 0.0F, 0.0F, 1.0F};
alignas(32) const ConstLine3D Line3D::zero = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};
alignas(16) const ConstPlane3D Plane3D::zero = {0.0F, 0.0F, 0.0F, 0.0F};
alignas(16) const ConstPlane3D Plane3D::horizon = {0.0F, 0.0F, 0.0F, 1.0F};
