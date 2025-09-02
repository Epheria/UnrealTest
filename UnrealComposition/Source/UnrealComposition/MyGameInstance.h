// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCOMPOSITION_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMyGameInstance();

	virtual void Init() override;

	
private:
	UPROPERTY() // Unreal 엔진이 관리하도록 함 - 매크로 지정해주기
	FString SchoolName; // UPROPERTY 가 없으면 Unreal 엔진이 관리하지않음
	// 리플렉션 시스템을 사용하여 SchoolName 변수 정보에 대해 런타임, 컴파일타임이든 언제든지 얻어올 수 있음

	
};
