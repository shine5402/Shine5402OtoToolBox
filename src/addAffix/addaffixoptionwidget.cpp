#include "addaffixoptionwidget.h"
#include <QFormLayout>

AddAffixOptionWidget::AddAffixOptionWidget(QWidget *parent) : ToolOptionWidget(parent)
{
    prefixEdit = new QLineEdit(this);
    suffixEdit = new QLineEdit(this);
    auto layout = new QFormLayout(this);
    layout->addRow(tr("前缀："), prefixEdit);
    layout->addRow(tr("后缀："), suffixEdit);
    setLayout(layout);
}

OptionContainer AddAffixOptionWidget::getOptions() const
{
    OptionContainer options;
    options.setOption("prefix", prefixEdit->text());
    options.setOption("suffix", suffixEdit->text());
    return options;
}

void AddAffixOptionWidget::setOptions(const OptionContainer& options)
{
    prefixEdit->setText(options.getOption("prefix").toString());
    suffixEdit->setText(options.getOption("suffix").toString());
}
