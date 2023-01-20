#pragma once
#include "DrawDebugHelpers.h"

/** 드로우 디버그 */
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Green, true);
#define DRAW_LINE(StartLocation, EndLocation) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Blue, true);
#define DRAW_VECTOR(StartLoaction, EndLocation) if(GetWorld()) \
	{	\
		DrawDebugLine(GetWorld(), StartLoaction, EndLocation, FColor::Red, true, -1.f,0,1.f);	\
		DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Blue, true);	\
	}