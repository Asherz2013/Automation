// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "MyBatchRename.generated.h"

/**
 * 
 */
UCLASS()
class CPP_API UMyBatchRename : public UAssetActionUtility
{
	GENERATED_BODY()

public:
	/*
	* Rename the selected assets
	* @param SearchPattern - The pattern to search for
	* @param ReplacePattern - The pattern to replace with
	* @param SearchCase - should the case be ignored?
	*/
	UFUNCTION(CallInEditor)
	void RenameSelectedAssets(FString SearchPattern, FString ReplacePatter, ESearchCase::Type SearchCase);
	
private:

	/*
	* Prints a message to the screen
	* @param Message - the message to print
	* @param Colour - the colour to use for the message
	*/
	void PrintToScreen(FString Message, FColor Colour);

	/*
	* Give Feedback to the user
	* @param Method - the Method that was used
	* @param Counter - how many objects where effected
	*/
	void GiveFeedback(FString Method, uint32 Counter);
};
