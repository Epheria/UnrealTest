// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Person.h" // generated.h 앞에 include 해야함 - 빌드 실패뜸
#include "Teacher.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UTeacher : public UPerson
{
	GENERATED_BODY()
public:
	UTeacher();

	virtual void DoLesson() override;
	
private:
	UPROPERTY()
	int32 Id;
};
