// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"


/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UMyObject : public UObject

{
	GENERATED_BODY()
	
};
// 언리얼 오브젝트 코드 분석을 하는 UnrealHeaderTool 에 의해서 소스코드를 자동 생성 -> 이후 최종 빌드 진행
// UHT는 UObject 기반의 클래스에 대한 메타데이터를 수집하고, 이를 기반으로 C++ 코드를 생성하는 도구이다.
// 지정된 매크로를 사용해 빌드를 수행하면, 추가 코드가 자동으로 만들어지는 구조를 가진다.