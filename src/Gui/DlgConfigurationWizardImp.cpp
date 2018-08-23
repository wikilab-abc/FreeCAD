#include "PreCompiled.h"
#include "DlgConfigurationWizardImp.h"
#include "ui_DlgConfigurationWizard.h"

#ifndef _PreComp_
# include <QApplication>
# include <QLocale>
# include <QStyleFactory>
# include <QTextStream>
#endif

#include "DlgGeneralImp.h"
#include "Action.h"
#include "Application.h"
#include "DockWindowManager.h"
#include "MainWindow.h"
#include "PrefWidgets.h"
#include "PythonConsole.h"
#include "Language/Translator.h"




using namespace Gui::Dialog;

DlgConfigurationWizardImp::DlgConfigurationWizardImp(QWidget* parent, Qt::WindowFlags fl)
    : QDialog(parent, fl), ui(new Ui_DlgConfigurationWizard)
{
    ui->setupUi(this);

    // search for the language files
    ParameterGrp::handle hGrp = WindowParameter::getDefaultParameter()->GetGroup("General");
    QString lang = QLocale::languageToString(QLocale::system().language());
    QByteArray language = hGrp->GetASCII("Language", (const char*)lang.toLatin1()).c_str();
    int index = 1;
    ui->Languages->addItem(QString::fromLatin1("English"), QByteArray("English"));
    TStringMap list = Translator::instance()->supportedLocales();
    for (TStringMap::iterator it = list.begin(); it != list.end(); ++it, index++) {
        QLocale locale(QString::fromLatin1(it->second.c_str()));
        QByteArray lang = it->first.c_str();
        QString langname = QString::fromLatin1(lang.constData());
#if QT_VERSION >= 0x040800
        QString native = locale.nativeLanguageName();
        if (!native.isEmpty()) {
            if (native[0].isLetter())
                native[0] = native[0].toUpper();
            langname = native;
        }
#endif
        ui->Languages->addItem(langname, lang);
        if (language == lang) {
            ui->Languages->setCurrentIndex(index);
        }
    }




    connect(ui->buttonBox,
            SIGNAL(rejected()),
            this,
            SLOT(close()));
}

DlgConfigurationWizardImp::~DlgConfigurationWizardImp()
{
}

#include "moc_DlgConfigurationWizardImp.cpp"




