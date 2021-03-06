#include "otofileloadwidget.h"
#include "ui_otofileloadwidget.h"

#include <QMessageBox>
#include <otofilereader.h>
#include "../dialogs/showotolistdialog.h"

#ifdef SHINE5402OTOBOX_TEST
#include <QTimer>
#endif

//TODO: 编码检测

OtoFileLoadWidget::OtoFileLoadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtoFileLoadWidget)
{
    ui->setupUi(this);
    connect(ui->loadButton, &QPushButton::clicked, this, &OtoFileLoadWidget::loadOtoFile);
    connect(ui->showOtoListButton, &QPushButton::clicked, this, &OtoFileLoadWidget::showOtoListDialog);
}

OtoFileLoadWidget::~OtoFileLoadWidget()
{
    delete ui;
}

void OtoFileLoadWidget::setFileName(const QString& fileName)
{
    ui->openFileNameEdit->setFileName(fileName);
}

QString OtoFileLoadWidget::fileName() const
{
    return ui->openFileNameEdit->fileName();
}

OtoEntryList OtoFileLoadWidget::getEntryList() const
{
    return entryList;
}

bool OtoFileLoadWidget::isEntryListReaded() const
{
    return entryListReaded;
}

void OtoFileLoadWidget::reset()
{
    setFileName("");
    entryList.clear();
    entryListReaded = false;

    ui->showOtoListButton->setEnabled(false);
    ui->countLabel->setText(tr("还未加载原音设定"));
    ui->loadOtoWidget->setEnabled(true);
    emit resetted();
}

void OtoFileLoadWidget::loadOtoFile()
{
    auto path = ui->openFileNameEdit->fileName();

    if (!QFileInfo::exists(path)){
#ifdef SHINE5402OTOBOX_TEST
        Q_ASSERT(false);
#endif
        QMessageBox::critical(this, tr("文件不存在"), tr("您指定的文件不存在，请检查后再试。"));
        return;
    }

    OtoFileReader reader(path);
    entryList = reader.getEntryList();
    entryListReaded = true;

    ui->showOtoListButton->setEnabled(true);

    ui->countLabel->setText(tr("加载了 %1 条原音设定。").arg(entryList.count()));
    ui->loadOtoWidget->setDisabled(true);

    emit loaded();
}

void OtoFileLoadWidget::showOtoListDialog()
{
    auto dialog = new ShowOtoListDialog(&entryList ,this);
#ifdef SHINE5402OTOBOX_TEST
        QTimer::singleShot(0, dialog, &ShowOtoListDialog::accept);
#endif
    dialog->open();
}
