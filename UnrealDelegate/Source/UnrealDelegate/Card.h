// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

UENUM()
enum class ECardType : uint8 // 8bit bute 형태가 일반적
{
	Student = 1 UMETA(DisplayName = "For Student"), // 메타 데이터를 집어넣을 수 있음
	Teacher UMETA(DisplayName = "For Teacher"),
	Staff UMETA(DisplayName = "For Staff"),
	Invalid
};

/**
 * 
 */
UCLASS()
class UNREALDELEGATE_API UCard : public UObject
{
	GENERATED_BODY()

public:
	UCard();

	ECardType GetCardType() const {	return CardType; }
	void SetCardType(ECardType InCardType) { CardType = InCardType; }

private:
	UPROPERTY()
	ECardType CardType;
	
	UPROPERTY()
	uint32 Id;
};
