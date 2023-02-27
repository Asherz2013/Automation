// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBatchRename.h"
#include "EditorUtilityLibrary.h"
#include "Engine/texture.h"


#pragma region RenameAssets

void UMyBatchRename::RenameSelectedAssets(FString SearchPattern, FString ReplacePatter, ESearchCase::Type SearchCase)
{
    // Check to see if we should do something
    if (SearchPattern.IsEmpty() || SearchPattern.Equals(ReplacePatter, SearchCase))
        return;

    // Get all the assets the user has selected
    TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();

    uint32 Count = 0;

    // Check each asset if it needs to be renamed
    for (UObject* SelectedObject : SelectedObjects)
    {
        if (ensure(SelectedObject))
        {
            FString AssetName = SelectedObject->GetName();
            if (AssetName.Contains(SearchPattern, SearchCase))
            {
                FString NewName = AssetName.Replace(*SearchPattern, *ReplacePatter, SearchCase);
                UEditorUtilityLibrary::RenameAsset(SelectedObject, NewName);

                ++Count;
            }
        }
    }
    GiveFeedback(TEXT("Rename"), Count);
}


#pragma endregion

#pragma region CheckPowerOfTwo

void UMyBatchRename::CheckPowerOfTwo()
{
    // Get all the assets the user has selected
    TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();

    uint32 Count = 0;

    // Check each asset if it needs to be renamed
    for (UObject* SelectedObject : SelectedObjects)
    {
        if (ensure(SelectedObject))
        {
            UTexture* texture = dynamic_cast<UTexture*>(SelectedObject);
            if (ensure(texture))
            {
                int32 Width = static_cast<int32>(texture->GetSurfaceWidth());
                int32 Height = static_cast<int32>(texture->GetSurfaceHeight());

                if (!IsPowerOfTwo(Width) || !IsPowerOfTwo(Height))
                {
                    PrintToScreen(SelectedObject->GetPathName() + " is not a power of 2 texture.", FColor::Red);
                }
                else
                {
                    Count++;
                }
            }
            else
            {
                PrintToScreen(SelectedObject->GetPathName() + " is not a texture.", FColor::Red);
            }
        }
    }

    GiveFeedback("Power of Two", Count);
}

#pragma endregion

#pragma region Helpers

bool UMyBatchRename::IsPowerOfTwo(int32 NumberToCheck)
{
    if (NumberToCheck == 0)
    {
        return false;
    }

    return (NumberToCheck & (NumberToCheck -1)) == 0;
}

void UMyBatchRename::PrintToScreen(FString Message, FColor Colour)
{
    if (ensure(GEngine))
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.5f, Colour, Message);
    }
}

void UMyBatchRename::GiveFeedback(FString Method, uint32 Counter)
{
    FString Message = FString("No Matching Files Found");
    FColor Colour = Counter > 0 ? FColor::Green : FColor::Red;
    if (Counter > 0)
    {
        Message = Method.AppendChar(' ');
        Message.AppendInt(Counter);
        Message.Append(Counter == 1 ? TEXT(" file") : TEXT(" files"));
    }
    PrintToScreen(Message, Colour);
}

#pragma endregion