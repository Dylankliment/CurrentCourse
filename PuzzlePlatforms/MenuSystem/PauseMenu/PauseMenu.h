// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MenuWidget.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPauseMenu : public UMenuWidget
{
	GENERATED_BODY()
	
protected:

	virtual bool Initialize();


private:

		UPROPERTY(meta = (BindWidget))
		class UButton* CancelButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* QuitLevelButton;
		
		UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;
	
		UFUNCTION()
		void CancelPressed();

		UFUNCTION()
		void QuitToMainMenuPressed();

		UFUNCTION()
		void QuitGame();

};
