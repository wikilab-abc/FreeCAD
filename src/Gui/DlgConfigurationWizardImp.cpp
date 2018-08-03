#include "PreCompiled.h"
#include "DlgConfigurationWizardImp.h"
#include "ui_DlgConfigurationWizard.h"

using namespace Gui::Dialog;

DlgConfigurationWizardImp::DlgConfigurationWizardImp(QWidget* parent, Qt::WindowFlags fl)
    : QDialog(parent, fl), ui(new Ui_DlgConfigurationWizard)
{
    ui->setupUi(this);
}

DlgConfigurationWizardImp::~DlgConfigurationWizardImp()
{
}

#include "moc_DlgConfigurationWizardImp.cpp"
