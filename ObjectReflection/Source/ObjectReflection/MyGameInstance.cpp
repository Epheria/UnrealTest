// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h" // cpp 파일에서는 현재 클래스 헤더 보다 밑에 위치해야한다. 컴파일 에러 남

UMyGameInstance::UMyGameInstance()
{
	// CDO
	SchoolName = TEXT("한국IT직업전문학교"); // 기본값은 CDO에 저장됨
	// 에디터 열 때 73~75% 정도에서 초기화가 됨
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("==========================="));
	UClass* ClassRuntime = GetClass(); // UMyGameInstance 에 대한 클래스 정보 - 런타임 클래스
	UClass* ClassCompile = UMyGameInstance::StaticClass(); // 컴파일타임 클래스
	// 위 둘은 동일한 객체를 가리키고있음
	// check(ClassRuntime != ClassCompile); // assertion 반드시 검증하고 넘어가야할 경우 사용 - 실패시 크래시 발생
	// ensure(ClassRuntime != ClassCompile); // assertion - 실패시 크래시 발생하지않음
	// ensureMsgf(ClassRuntime != ClassCompile, TEXT("일부러 에러를 발생시킨 코드"));

	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName());

	SchoolName = TEXT("경북대학교 - 게임콘텐츠과"); // CDO 와 무관하게 생성됨

	UE_LOG(LogTemp, Log, TEXT("학교 이름 : %s"), *SchoolName);
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값 : %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

	// 언리얼 오브젝트 생성
	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();

	UE_LOG(LogTemp, Log, TEXT("==========================="));

	// getter setter 
	Student->SetName(TEXT("학생1"));
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름 : %s"), *Student->GetName());

	// reflection
	FString CurrentTeacherName;
	FString NewTeacherName(TEXT("이득우"));
	FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	if (NameProp)
	{
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름 : %s"), *CurrentTeacherName);

		NameProp->SetValue_InContainer(Teacher, &NewTeacherName);
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름 : %s"), *Teacher->GetName());
	}
	
	UE_LOG(LogTemp, Log, TEXT("==========================="));

	Student->DoLesson();
	UFunction* DoLessonFunc = Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson"));
	if (DoLessonFunc)
	{
		Teacher->ProcessEvent(DoLessonFunc, nullptr);
	}

	UE_LOG(LogTemp, Log, TEXT("==========================="));
	UE_LOG(LogTemp, Log, TEXT("==========================="));

}
