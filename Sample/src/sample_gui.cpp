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

#include "sample_gui.h"

SampleWindow::SampleWindow(QWidget *parent)
  : QMainWindow(parent)
{
  ui_.setupUi(this);

  for (int i = 1; i < 3; i++)
  {
    ParameterSetter* setter = new ParameterSetter(this);
    ui_.verticalLayout_2->addWidget(setter);
  }
  connect(ui_.set_text_button, &QPushButton::clicked, this, [this]() { this->ui_.debug_textedit->setText("Hello world");});
}

SampleWindow::~SampleWindow()
{}

