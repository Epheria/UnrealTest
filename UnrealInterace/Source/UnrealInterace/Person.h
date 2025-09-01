// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.generated.h"

/**
 * 
 */
UCLASS()
class UNREALINTERACE_API UPerson : public UObject
{
	GENERATED_BODY()

public:
	UPerson();

	// inline : 인라인 함수로 만들어줌 - 헤더파일에 작성된 함수는 인라인 함수로 만들어주는게 좋음
	FORCEINLINE FString& GetName() { return Name; }
	FORCEINLINE void SetName(FString& InName) { Name = InName; }
	
protected:
	UPROPERTY()
	FString Name;
};
