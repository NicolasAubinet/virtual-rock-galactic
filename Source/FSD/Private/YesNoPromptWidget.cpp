#include "YesNoPromptWidget.h"

UYesNoPromptWidget::UYesNoPromptWidget() {
    this->bDestroyOnClick = false;
    this->bCloseAllWindows = true;
    this->bIsClosable = true;
}

void UYesNoPromptWidget::Show(FText Title, FText Message, const UYesNoPromptWidget::FOnYesNoClickedDelegate& OnYesNoClicked, bool IsClosable) {
}




void UYesNoPromptWidget::Clicked(bool YesClicked) {
}


