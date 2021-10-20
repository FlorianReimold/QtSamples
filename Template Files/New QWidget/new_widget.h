#pragma once

#include <QWidget>
#include "ui_new_widget.h"

class NewWidget : public QWidget
{
  Q_OBJECT

public:
  NewWidget(QWidget *parent = Q_NULLPTR);
  ~NewWidget();

private:
  Ui::NewWidget ui_;
};
