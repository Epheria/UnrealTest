// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCOMPOSITION_API UPerson : public UObject
{
	GENERATED_BODY()

public:
	UPerson();

	// inline : 인라인 함수로 만들어줌 - 헤더파일에 작성된 함수는 인라인 함수로 만들어주는게 좋음
	FORCEINLINE const FString& GetName() const { return Name; } // 레퍼런스는 변경이 가능하므로 앞에도 const 를 붙여야함
	FORCEINLINE void SetName(const FString& InName) { Name = InName; }

	FORCEINLINE class UCard* GetCard() const { return Card; }
	FORCEINLINE void SetCard(class UCard* InCard) { Card = InCard; }
	
protected:
	UPROPERTY()
	FString Name;

	// 전방선언(의존성을 줄임) 시 헤더를 포함하지 않고도 사용 가능함 : 컴포지션 - 언리얼 오브젝트를 선언
	// UPROPERTY()
	// class UCard* Card;
	// 이 방식은 언리얼4 버전용

	// 언리얼 5 버전용
	TObjectPtr<class UCard> Card;
};
