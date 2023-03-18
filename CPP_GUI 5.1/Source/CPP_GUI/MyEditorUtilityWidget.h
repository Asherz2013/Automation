// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "MyEditorUtilityWidget.generated.h"

/**
 * 
 */
UCLASS()
class CPP_GUI_API UMyEditorUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

	UFUNCTION(CallInEditor, BlueprintCallable)
	void Test();
};
