#pragma once

#include <QWidget>
#include "ui_parametersetter.h"

class ParameterSetter : public QWidget
{
  Q_OBJECT

public:
  ParameterSetter(QWidget *parent = Q_NULLPTR);
  ~ParameterSetter();

private:
  Ui::ParameterSetterWidget ui_;
};
