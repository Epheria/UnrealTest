// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Card.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

UMyGameInstance::UMyGameInstance()
{
	// CDO
	SchoolName = TEXT("한국IT직업전문학교"); // 기본값은 CDO에 저장됨
	// 에디터 열 때 73~75% 정도에서 초기화가 됨
}

void UMyGameInstance::Init()
{
	Super::Init();

	// 동적 가변 배열
	UE_LOG(LogTemp, Log, TEXT("========================"));
	TArray<UPerson*> Persons = {
		NewObject<UStudent>(), // NewObject : UObject 계열의 오브젝트를 생성할 때 사용하는 API
		NewObject<UTeacher>(),
		NewObject<UStaff>()
	};

	for (const auto Person : Persons)
	{
		const UCard* OwnCard = Person->GetCard();
		check(OwnCard);
		ECardType CardType = OwnCard->GetCardType();
		
		//UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 : %d"), *Person->GetName(),CardType);

		const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/UnrealComposition.ECardType"));
		if (CardEnumType)
		{
			FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)CardType).ToString();
			UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 : %s"), *Person->GetName(), *CardMetaData);
		}
	}
	
	UE_LOG(LogTemp, Log, TEXT("========================"));
}
