// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Card.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "CourseInfo.h"

UMyGameInstance::UMyGameInstance()
{
	// CDO
	SchoolName = TEXT("학교"); // 기본값은 CDO에 저장됨
	// 에디터 열 때 73~75% 정도에서 초기화가 됨
}

void UMyGameInstance::Init()
{
	Super::Init();

	// 외부에서 필요할 때만 CourseInfo 생성
	CourseInfo = NewObject<UCourseInfo>(this);

	// 동적 가변 배열
	UE_LOG(LogTemp, Log, TEXT("========================"));

	UStudent* Student1 = NewObject<UStudent>();
	Student1->SetName(TEXT("학생1"));
	UStudent* Student2 = NewObject<UStudent>();
	Student2->SetName(TEXT("학생2"));
	UStudent* Student3 = NewObject<UStudent>();
	Student3->SetName(TEXT("학생3"));

	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student2, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student3, &UStudent::GetNotification);
	
	CourseInfo->ChangeCourseInfo(SchoolName, TEXT("변경된 학사 정보"));

	UE_LOG(LogTemp, Log, TEXT("========================"));
}
