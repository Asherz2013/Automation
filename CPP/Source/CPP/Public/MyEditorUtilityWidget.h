// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"

#include "Engine/StaticMeshActor.h"
#include "Engine/ReflectionCapture.h"
#include "Engine/Skylight.h"

#include "MyEditorUtilityWidget.generated.h"


/**
 * 
 */
UCLASS()
class CPP_API UMyEditorUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(CallInEditor, BlueprintCallable)
	void Test();

	UFUNCTION(CallInEditor, BlueprintCallable)
	void OrganiseWorldOuliner();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrganizerWorldOutliner")
	TMap<UClass*, FName> FolderMap = {
		{AStaticMeshActor::StaticClass(), "Static Meshes"},
		{AReflectionCapture::StaticClass(), "Reflection Capturs"},
		{ASkyLight::StaticClass(), "Lights"}
	};
	
};
