// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 *///Adding IMI makes it to where it can be used as a pointer to the functions in this class as well
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface 
{
	GENERATED_BODY()
public:

		UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);
	
		virtual void Init();

		UFUNCTION(BlueprintCallable)
		void LoadMenuWidget();
	
		void LoadPauseMenu();

		void LoadMainMenu();

		UFUNCTION(Exec)
		void Host();

		UFUNCTION(Exec)
		void Join(const FString& Address);

private:

	TSubclassOf<class UUserWidget> MenuClass;

	TSubclassOf<class UUserWidget> PauseMenuClass;

	class UPauseMenu* PauseMenu;

	class UMainMenu* Menu;
};
