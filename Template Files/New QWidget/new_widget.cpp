#include "new_widget.h"

NewWidget::NewWidget(QWidget *parent)
  : QWidget(parent)
{
  ui_.setupUi(this);
}

NewWidget::~NewWidget()
{
}
