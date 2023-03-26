// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEditorUtilityWidget.h"
#include "EditorLevelLibrary.h"

void UMyEditorUtilityWidget::Test()
{
    GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Red, TEXT("Hello World"));
}

void UMyEditorUtilityWidget::OrganiseWorldOuliner()
{
    TArray<AActor*> AllActors = UEditorLevelLibrary().GetAllLevelActors();

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
