// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"

UStudent::UStudent()
{
	Name = TEXT("이학생");
}

void UStudent::DoLesson()
{
	ILessonInterface::DoLesson(); // 인터페이스는 Super 로 가져올 수 없음
	UE_LOG(LogTemp, Log, TEXT("%s 님이 공부합니다."), *Name);
}
