// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LessonInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULessonInterface : public UInterface // 타입 정보를 보관하기 위해 언리얼에서 자동으로 생성한 클래스
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNREALCOMPOSITION_API ILessonInterface // 실제 인터페이스 구현부
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//virtual void DoLesson() = 0; // 순수 가상 함수
	// 이 인터페이스를 상속받는 클래스들은 반드시 DoLesson 함수를 구현해야함

	virtual void DoLesson()
	{
		UE_LOG(LogTemp, Log, TEXT("수업에 입장합니다."));
	}
};
