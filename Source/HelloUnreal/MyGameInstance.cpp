// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init(); // 언리얼 엔진에서의 기본이다. 언리얼 엔진의 base class의 Init() 함수를 오버라이드하여 호출한다.

	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Hello Unreal!")); // 포맷 문자열은 반드시 리터럴이어야 한다. 실제 메세지를 가변 인자로 넘기는 방법
	static constexpr TCHAR LogCharArray[] = TEXT("Hello Unreal!"); // 정적 상수로 만들어서 사용하는 방법

	// 문자열을 자유롭게 조절하고싶다면 FString을 사용한다.
	FString LogCharString = LogCharArray;

	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString); // FString을 언리얼 엔진의 로그 시스템에 넘길 때는 *를 붙여서 FString을 FStringView로 변환한다.
	
	UE_LOG(LogTemp, Log, LogCharArray);
}
