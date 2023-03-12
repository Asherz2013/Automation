// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"

#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "Particles/ParticleSystem.h"
#include "Sound/Soundcue.h"
#include "Sound/SoundWave.h"
#include "Engine/Texture.h"
#include "Blueprint/UserWidget.h"
#include "Animation/MorphTarget.h"
#include "Components/SkeletalMeshComponent.h"

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
	
	/*
	* Checks textured to make sure they are a Power of 2
	*/
	UFUNCTION(CallInEditor)
	void CheckPowerOfTwo();

	/*
	* Puts assets into their appropriate folder
	*/
	UFUNCTION(CallInEditor)
	void CleanupFolder(FString ParentFolder = FString("/Game"));

	/*
	* Dupliacate the number of assets NumberOfDuplicates times
	* @param NumberOfDuplcates - How many times you want the selected assets to be duplicated by
	* @param bSave - Automatically save the file
	*/
	UFUNCTION(CallInEditor)
	void DuplicateAssets(uint32 NumberOfDuplicates, bool bSave);

	/*
	* Nish Special - Nish asked me to create an Asset Duplicated that applies suffix's and duplicates assets
	* @param Skylight - Do you want this Suffix to be applied
	* @param Lighting - Do you want this Suffix to be applied
	* @param SomeOther - Do you want thsi Suffix to be applied
	*/
	UFUNCTION(CallInEditor)
	void NishSpecial(bool bSkylight, bool bLighting, bool bSomeOther, bool bSave);

	/*
	* Automatically re-names all the selected files to have the UE prefix terminology
	* The Prefix data comes from a JSON file
	*/
	UFUNCTION(CallInEditor)
	void AutoPrefix();

private:

	const TMap<UClass*, FString> PrefixMap = {
		{UBlueprint::StaticClass(), TEXT("BP_")},
		{UStaticMesh::StaticClass(), TEXT("SM_")},
		{UMaterial::StaticClass(), TEXT("M_")},
		{UMaterialInstance::StaticClass(), TEXT("MI_")},
		{UMaterialFunctionInterface::StaticClass(), TEXT("MF_")},
		{UParticleSystem::StaticClass(), TEXT("PS_")},
		{USoundCue::StaticClass(), TEXT("SC_")},
		{USoundWave::StaticClass(), TEXT("S_")},
		{UTexture::StaticClass(), TEXT("T_")},
		{UTexture2D::StaticClass(), TEXT("T_")},
		{UUserWidget::StaticClass(), TEXT("UWB_")},
		{UMorphTarget::StaticClass(), TEXT("MT_")},
		{USkeletalMeshComponent::StaticClass(), TEXT("SK_")}
	};

	/*
	* Checks if NumberToCheck is a power of two
	* @param NumberToCheck - Number to check
	* @return Bool - True or False
	*/
	bool IsPowerOfTwo(int32 NumberToCheck);

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
