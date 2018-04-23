// Fill out your copyright notice in the Description page of Project Settings.

#include "PauseMenu.h"
#include "Components/Button.h"



bool UPauseMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (CancelButton == nullptr || QuitLevelButton == nullptr || QuitButton == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Close Menu or Back Button Not Found"));

		return false;
	}
	CancelButton->OnClicked.AddDynamic(this, &UPauseMenu::CancelPressed);
	QuitLevelButton->OnClicked.AddDynamic(this, &UPauseMenu::QuitToMainMenuPressed);
	QuitButton->OnClicked.AddDynamic(this, &UPauseMenu::QuitGame);
	return true;
}

void UPauseMenu::CancelPressed()
{
	Teardown();
}

void UPauseMenu::QuitToMainMenuPressed()
{
	if (MenuInterface != nullptr)
	{
		Teardown();
		MenuInterface->LoadMainMenu();
	}
}

void UPauseMenu::QuitGame()
{
	CloseGame();
}
