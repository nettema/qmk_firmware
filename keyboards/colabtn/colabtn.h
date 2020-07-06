/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"
#define ___ KC_NO

#ifdef KEYBOARD_colabtn_promicro
    #include "promicro.h"
#endif

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments.
// The second converts the arguments into a two-dimensional array.
#define LAYOUT( \
  k00  \
) \
{ \
	{ k00 }  \
}

