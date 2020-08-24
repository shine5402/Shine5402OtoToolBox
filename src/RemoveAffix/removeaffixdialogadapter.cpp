#include "removeaffixdialogadapter.h"
#include "removeaffixoptionwidget.h"
#include "removeaffixotolistmodifyworker.h"

RemoveAffixDialogAdapter::RemoveAffixDialogAdapter(QWidget* parent) : ToolDialogAdapter(parent)
{
    setWorker(new RemoveAffixOtoListModifyWorker(this));
    setOptionWidget(new RemoveAffixOptionWidget);
}

QString RemoveAffixDialogAdapter::getWindowTitle() const
{
    return tr("去除别名前/后缀");
}

