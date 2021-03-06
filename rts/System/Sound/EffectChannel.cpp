/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "EffectChannel.h"

#include "ISound.h"
#include "Sim/Objects/WorldObject.h"
#include "Sim/Units/Unit.h"

EffectChannel::EffectChannel()
{
}

void EffectChannel::PlaySample(size_t id, float ovolume)
{
	if (enabled && emmitsThisFrame < emmitsPerFrame)
	{
		emmitsThisFrame++;
		sound->PlaySample(id, float3(0.0, 0.0, -1.0), ZeroVector, volume * ovolume, true);
	}
}

void EffectChannel::PlaySample(size_t id, const float3& p, float ovolume)
{
	if (enabled && emmitsThisFrame < emmitsPerFrame)
	{
		emmitsThisFrame++;
		sound->PlaySample(id, p, ZeroVector, volume * ovolume, false);
	}
}

void EffectChannel::PlaySample(size_t id, const float3& p, const float3& velocity, float ovolume)
{
	if (enabled && emmitsThisFrame < emmitsPerFrame)
	{
		emmitsThisFrame++;
		sound->PlaySample(id, p, velocity, volume * ovolume, false);
	}
}

void EffectChannel::PlaySample(size_t id, const CUnit* u,float ovolume)
{
	if (enabled && emmitsThisFrame < emmitsPerFrame)
	{
		emmitsThisFrame++;
		sound->PlaySample(id, u->pos, u->speed, volume * ovolume, false);
	}
}

void EffectChannel::PlaySample(size_t id, const CWorldObject* p,float ovolume)
{
	if (enabled && emmitsThisFrame < emmitsPerFrame)
	{
		emmitsThisFrame++;
		sound->PlaySample(id, p->pos, ZeroVector, volume * ovolume, false);
	}
} 
