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

	const TCHAR* LongCharPtr = *LogCharString; // 고칠수없는 형태로 참조
	TCHAR* LogCharDataPtr = LogCharString.GetCharArray().GetData(); // FString의 GetCharArray()를 사용하여 TCHAR 배열로 변환하고, GetData()로 포인터를 얻는다.
	TCHAR LogCharArrayWithSize[100]; // 고정 크기의 배열을 선언

	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString); // FString의 내용을 고정 크기의 배열에 복사한다. FCString::Strcpy는 문자열을 복사하는 함수이다.


	if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		FString EndString =  LogCharString.Mid(Index);
		UE_LOG(LogTemp, Log, TEXT("Find Test : %s"), *EndString);
	}

	FString Left, Right;
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		UE_LOG(LogTemp, Log, TEXT("Split Test : %s 와 %s"), *Left, *Right);
	}

	int32 IntValue = 32;
	float FloatValue = 3.141592;

	FString FloatIntString = FString::Printf(TEXT("Int:%d Float:%f"), IntValue, FloatValue);
	FString FloatString = FString::SanitizeFloat(FloatValue);
	FString IntString = FString::FromInt(IntValue);

	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
	UE_LOG(LogTemp, Log, TEXT("Float:%s Int:%s"), *FloatString, *IntString);

	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);
	FString FloatIntString2 = FString::Printf(TEXT("Int:%d Float:%f"), IntValueFromString, FloatValueFromString);
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString2);


	// FName는 언리얼 엔진에서 문자열을 식별자로 사용하기 위한 클래스이다.
	// 에셋 관리를 위해 문자열을 해시값으로 변환하여 빠르게 비교할 수 있도록 최적화되어 있다. key-value pair로 사용
	// 대소문자 구분이 없다. 한 번 선언되면 바꿀 수 없다. 가볍고 빠르다.
	// 빌드 시 해시값으로 변환된다.
	// 문자열로 쓰이는게 아니고 찾기 위해 쓰는 것

	// FName 과 관련된 글로벌 Pool 자료구조를 가지고 있음. Singleton 패턴으로 관리된다.
	// Key-Value Pair로 관리, Key 가 저장된다. Pool에 있는지 없는지 빠르게 검출함

	FName Key1(TEXT("PELVIS"));
	FName Key2(TEXT("pelvis"));
	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과 : %s"), Key1 == Key2 ? TEXT("같음") : TEXT("다름"));


	for (int i = 0; i < 10000; ++i)
	{
		// FName 은 자주 실행되는 함수에서는 오버헤드가 발생할 수 있다.
		FName SearchInNamePool = FName(TEXT("pelvis")); // 오버헤드 발생
		const static FName StaticOnlyOnce(TEXT("pelvis")); // Static으로 선언하면 오버헤드가 발생하지 않는다.
	}

		
   // FText 다국어 지원을 위한 문자열 관리 체계
	
	UE_LOG(LogTemp, Log, LogCharArray);
}
