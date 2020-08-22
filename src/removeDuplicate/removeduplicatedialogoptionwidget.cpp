#include "removeduplicatedialogoptionwidget.h"
#include "ui_removeduplicatedialogoptionwidget.h"

RemoveDuplicateDialogOptionWidget::RemoveDuplicateDialogOptionWidget(QWidget *parent) :
    ToolOptionWidget(parent),
    ui(new Ui::RemoveDuplicateDialogOptionWidget)
{
    ui->setupUi(this);
}

RemoveDuplicateDialogOptionWidget::~RemoveDuplicateDialogOptionWidget()
{
    delete ui;
}

ToolOptions RemoveDuplicateDialogOptionWidget::getOptions() const
{
    //TODO: 使用去除Affix替换这里的后缀检测
    ToolOptions options;

    options.combine(ui->affixRemoveWidget->getOptions(), "affixRemove/");
    options.setOption("maxDuplicateCount", ui->maxSpinBox->value());
    options.setOption("shouldOrganize", ui->organizeCheckBox->isChecked());
    options.setOption("organizeStartFrom1", ui->organizeStartFrom1CheckBox->isChecked());
    options.setOption("pitchCaseOrganized", static_cast<int>(ui->organizeCaseComboBox->currentIndex() == 0 ? OtoEntryFunctions::Upper : OtoEntryFunctions::Lower));

    return options;
}

void RemoveDuplicateDialogOptionWidget::setOptions(const ToolOptions& options)
{
    ui->affixRemoveWidget->setOptions(options.extract("affixRemove"));
    ui->maxSpinBox->setValue(options.getOption("maxDuplicateCount").toInt());
    ui->organizeCheckBox->setChecked(options.getOption("shouldOrganize").toBool());
    ui->organizeStartFrom1CheckBox->setChecked(options.getOption("organizeStartFrom1").toBool());
    ui->organizeCaseComboBox->setCurrentIndex(options.getOption("pitchCaseOrganized").toInt() == OtoEntryFunctions::Upper ? 0 : 1);
}
