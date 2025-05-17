//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSRigid2D.h"


using namespace Terathon;


alignas(16) const ConstFlatPoint2D FlatPoint2D::origin = {0.0F, 0.0F, 1.0F};
alignas(16) const ConstLine2D Line2D::zero = {0.0F, 0.0F, 0.0F};
alignas(16) const ConstLine2D Line2D::horizon = {0.0F, 0.0F, 1.0F};
