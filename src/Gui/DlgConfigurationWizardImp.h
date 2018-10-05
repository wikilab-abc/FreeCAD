#ifndef GUI_DIALOG_DLGCONFIGURATIONWIZARDIMP_H
#define GUI_DIALOG_DLGCONFIGURATIONWIZARDIMP_H

#include <QDialog>

namespace Gui {
namespace Dialog {

class Ui_DlgConfigurationWizard;

class GuiExport DlgConfigurationWizardImp : public QDialog
{
    Q_OBJECT

public:
    DlgConfigurationWizardImp(QWidget* parent = 0, Qt::WindowFlags fl = 0);
    ~DlgConfigurationWizardImp();

protected:
    void changeEvent(QEvent *e);

private Q_SLOTS:
    void configure();
    
private:
    Ui_DlgConfigurationWizard* ui;
};

} // namespace Dialog
} // namespace Gui

#endif // GUI_DIALOG_DLGCONFIGURATIONWIZARDIMP_H
