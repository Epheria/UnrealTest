// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"

#include "Card.h"

UStudent::UStudent()
{
	Name = TEXT("이학생");
	Card->SetCardType(ECardType::Student);
}

void UStudent::DoLesson()
{
	ILessonInterface::DoLesson(); // 인터페이스는 Super 로 가져올 수 없음
	UE_LOG(LogTemp, Log, TEXT("%s 님이 공부합니다."), *Name);
}

void UStudent::GetNotification(const FString& School, const FString& NewCourseInfo)
{
	UE_LOG(LogTemp, Log, TEXT("[Student] %s 학생이 %s 로부터 받은 메세지 : %s"), *Name, *School, *NewCourseInfo);
}
