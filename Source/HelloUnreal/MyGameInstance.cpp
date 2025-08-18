// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init(); // 언리얼 엔진에서의 기본이다. 언리얼 엔진의 base class의 Init() 함수를 오버라이드하여 호출한다.

	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Hello Unreal!"));
}
