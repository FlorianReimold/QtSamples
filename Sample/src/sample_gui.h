/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#pragma once

#include "ui_sample_gui.h"

#include "parametersetter.h"


class SampleWindow : public QMainWindow
{
  Q_OBJECT

//////////////////////////////////////////
// Constructor & Destructor
//////////////////////////////////////////
public:
  SampleWindow(QWidget *parent = Q_NULLPTR);
  ~SampleWindow();

////////////////////////////////////////////
// Member variables
////////////////////////////////////////////
private:
  Ui::EcalRecMainWindow ui_;

  std::vector<ParameterSetter*> parameter_setters;
};
