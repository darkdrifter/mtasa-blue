/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/CExplosionSA.cpp
 *  PURPOSE:     Explosion
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#include "StdInc.h"
#include "CExplosionSA.h"
#include "CEntitySA.h"
#include "CVehicleSA.h"

eExplosionType CExplosionSA::GetExplosionType()
{
    return internalInterface->m_ExplosionType;
}

CVector* CExplosionSA::GetExplosionPosition()
{
    return &internalInterface->m_vecPosition;
}

void CExplosionSA::SetExplosionPosition(const CVector* vecPosition)
{
    internalInterface->m_vecPosition = *vecPosition;
}

/**
 * \todo Handle objects creating explosions
 */
CEntity* CExplosionSA::GetExplosionCreator()
{
    eEntityType entityType = (eEntityType)GetInterface()->m_pEntExplosionOwner->nType;

    CPools* pools = pGame->GetPools();
    switch (entityType)
    {
        case ENTITY_TYPE_PED:
        {
            SClientEntity<CPedSA>* pPedClientEntity = pools->GetPed((DWORD*)this->GetInterface()->m_pEntExplosionOwner);
            if (pPedClientEntity)
            {
                return pPedClientEntity->pEntity;
            }
            break;
        }
        case ENTITY_TYPE_VEHICLE:
        {
            SClientEntity<CVehicleSA>* pVehicleClientEntity = pools->GetVehicle((DWORD*)this->GetInterface()->m_pEntExplosionOwner);
            if (pVehicleClientEntity)
            {
                return pVehicleClientEntity->pEntity;
            }
            break;
        }
        case ENTITY_TYPE_OBJECT:
        {
            break;
        }
    }
    return NULL;
}

CEntity* CExplosionSA::GetExplodingEntity()
{
    return NULL;
}

bool CExplosionSA::IsActive()
{
    return internalInterface->m_cExplosionActive;
}

void CExplosionSA::Remove()
{
    internalInterface->m_cExplosionActive = 0;
}

float CExplosionSA::GetExplosionForce()
{
    return this->GetInterface()->m_fExplosionForce;
}

void CExplosionSA::SetExplosionForce(float fForce)
{
    this->GetInterface()->m_fExplosionForce = fForce;
}

void CExplosionSA::SetSilent(bool bSilent)
{
    this->GetInterface()->m_bMakeSound = !bSilent;
}

unsigned long CExplosionSA::GetActivationTimer()
{
    return this->GetInterface()->m_ActivationTime;
}

void CExplosionSA::SetActivationTimer(unsigned long ulActivationTime)
{
    this->GetInterface()->m_ActivationTime = ulActivationTime;
}

DWORD CExplosionSA::GetExpiryTime()
{
    return this->GetInterface()->m_TimeExpires;
}

void CExplosionSA::SetExpiryTime(DWORD dwExpiryTime)
{
    this->GetInterface()->m_TimeExpires = dwExpiryTime;
}

float CExplosionSA::GetExplosionRadius()
{
    return this->GetInterface()->m_fExplosionRadius;
}

void CExplosionSA::SetExplosionRadius(float fRadius)
{
    this->GetInterface()->m_fExplosionRadius = fRadius;
}
