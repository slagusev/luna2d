//-----------------------------------------------------------------------------
// luna2d engine
// Copyright 2014-2015 Stepan Prokofjev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#pragma once

#include "lunalua.h"
#include "lunagraphics.h"
#include "lunarect.h"
#include "lunarange.h"
#include "lunastringenum.h"

namespace luna2d{

enum class LUNATextureSelectionMode
{
	SERIAL,
	RANDOM,
	SHUFFLE,
};

const LUNAStringEnum<LUNATextureSelectionMode> TEXTURE_SELECTION_MODE =
{
	"serial",
	"random",
	"shuffle",
};


enum class LUNASpawnAreaMode
{
	POINT,
	RECT,
	CIRCLE,
};

const LUNAStringEnum<LUNASpawnAreaMode> SPAWN_AREA_MODE =
{
	"point",
	"rect",
	"circle",
};


class LUNAParticleParams
{
public:
	LUNAParticleParams(const LuaTable& luaParams);

public:
	// Mode of area where spawns particles
	LUNASpawnAreaMode spawnAreaMode = LUNASpawnAreaMode::POINT;

	// Rectangle for "LUNASpawnAreaMode::RECT" spawn area mode
	// "x" and "y" of this rect are offset from emiiter position
	// For another spawn area modes will be ignored
	LUNARect spawnRect;

	// Radius for "LUNASpawnAreaMode::CIRCLE" spawn area mode
	// For another spawn area modes will be ignored
	float spawnCircleR = 0.0f;

	// List of textures or texture regions using to create particles
	// Stored as paths to asset in asset manager. Asset object gets from asset manager when emmiter created
	std::vector<std::string> textures;

	// Mode of selection texture from textures list for each new particle
	LUNATextureSelectionMode textureSelectionMode = LUNATextureSelectionMode::SHUFFLE;

	// Emitter position relative particle system
	glm::vec2 emitterPos;

	// Move particles with emmitter or not
	bool attached = false;

	// Duration of emitter working. "0" is infinite
	float duration = 0.0f;

	// Count of particles spawns at once
	int spawnCount = 1;

	// Delay between spawning
	float spawnDelay = 0.0f;

	// Particle lifetime
	LUNARangeFloat lifetime;

	// Particle direction
	LUNARangeFloat direction;

	// Set angle between initial particle pos and emitter pos as direction
	// "direction" value will be ignored.
	// Supports only on "LUNASpawnAreaMode::RECT" and "LUNASpawnAreaMode::CIRCLE" spawn area modes
	bool dirFromEmitter = false;

	// Particle speed
	LUNARangeFloat speedBegin = LUNARangeFloat(1.0f);
	LUNARangeFloat speedEnd = LUNARangeFloat(1.0f);

	// Initial rotation angle of particle
	LUNARangeFloat initAngle;

	// Particle rotation speed (in degrees per second)
	LUNARangeFloat rotateBegin, rotateEnd;

	// Particle scale
	LUNARangeFloat scaleBegin, scaleEnd;

	// Particle alpha
	LUNARangeFloat alphaBegin, alphaEnd;
};

}
