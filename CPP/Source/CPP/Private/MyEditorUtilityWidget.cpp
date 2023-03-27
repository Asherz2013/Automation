// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEditorUtilityWidget.h"
#include "Subsystems/EditorActorSubsystem.h"

void UMyEditorUtilityWidget::Test()
{
    GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Red, TEXT("Hello World"));
}

void UMyEditorUtilityWidget::OrganiseWorldOuliner()
{
    TArray<AActor*> AllActors = UEditorActorSubsystem().GetAllLevelActors();

    for (AActor* Actor : AllActors)
    {
        if (ensure(Actor))
        {
            const FName* FolderName = FolderMap.Find(Actor->GetClass());
            if (ensure(FolderName))
            {
                Actor->SetFolderPath(*FolderName);
            }
        }
    }
}
