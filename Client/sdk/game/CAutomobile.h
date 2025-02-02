/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        sdk/game/CAutomobile.h
 *  PURPOSE:     Automobile vehicle entity interface
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include "Common.h"
#include "CVehicle.h"

class CPhysical;
class CDoor;

class CAutomobile : public virtual CVehicle
{
public:
    virtual ~CAutomobile(){};

    virtual bool  BurstTyre(DWORD dwTyreID) = 0;
    virtual bool  BreakTowLink() = 0;
    virtual bool  IsComponentPresent(int iComponentID) = 0;

    virtual void       ResetSuspension() = 0;
    virtual void       SetTaxiLight(bool bState) = 0;
    virtual void       SetTowLink(CVehicle* pVehicle, bool bRemoveAdd) = 0;
    virtual CPhysical* SpawnFlyingComponent(int iCarNodeIndex, int iUnknown) = 0;

    virtual CDoor* GetDoor(eDoors doorID) = 0;
};
