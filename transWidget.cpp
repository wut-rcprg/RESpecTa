#include "transWidget.h"
#include <QtGui>
#include "GraphFunctions.h"
#include "GraphFunctions.cpp"




using namespace boost;

TransWidget::TransWidget(QWidget *parent)
: QWidget(parent)
{
   TransitionLayout = new QVBoxLayout;

   QLabel *transCondLabel = new QLabel(tr("Transition condition:"));
   conditionLineEdit = new QLineEdit;
   connect(conditionLineEdit, SIGNAL(textChanged(QString)), this, SLOT(lengthChanged(QString)));
   QHBoxLayout *bottomLayout = new QHBoxLayout;
   TransitionLayout->addWidget(transCondLabel);
   TransitionLayout->addWidget(conditionLineEdit);

   RESpecTa * x = (RESpecTa *) this->parentWidget()->parentWidget()->parentWidget();
   QStringList subtaskList;
   xsubtasks = x->getSubtasks();
   for (std::map<std::string, MyGraphType*>::iterator it = xsubtasks->begin(); it!=xsubtasks->end() ;it++)
   {
       subtaskList<<(*it).first.c_str();
   }

   /*

   QLabel *sourceLabel = new QLabel(tr("Source State:"));
   sourceCombo = new QComboBox(this);
   MyGraphType * myGraph = x->getGraph();
   QStringList sourceItems = getStateNames(vertices((*myGraph)).first, vertices((*myGraph)).second, (*myGraph));
   sourceCombo->addItems(sourceItems);
   TransitionLayout->addWidget(sourceLabel);
   TransitionLayout->addWidget(sourceCombo);

   QLabel *destLabel = new QLabel(tr("Dest State:"));
   destCombo = new QComboBox(this);
   QStringList destItems = getStateNames(vertices((*myGraph)).first, vertices((*myGraph)).second, (*myGraph));
   destCombo->addItems(destItems);
   TransitionLayout->addWidget(destLabel);
   TransitionLayout->addWidget(destCombo);*/

   QLabel * taskLabel = new QLabel(tr("Subtask:"));
   subtaskCombo = new QComboBox(this);
   subtaskCombo->addItem("None");
   subtaskCombo->addItems(subtaskList);
   TransitionLayout->addWidget(taskLabel);
   TransitionLayout->addWidget(subtaskCombo);

   OKButton = new QPushButton(tr("&OK"));
   OKButton->setChecked(false);
   connect(OKButton, SIGNAL(clicked()), this, SLOT(AcceptTrans()));
   OKButton->setDown(true);
   bottomLayout->addWidget(OKButton);

   InsertButton = new QPushButton(tr("&Insert"));
   InsertButton->setChecked(false);
   connect(InsertButton, SIGNAL(clicked()), this, SLOT(InsertTrans()));
   InsertButton->setDown(true);
   bottomLayout->addWidget(InsertButton);

   TransitionLayout->addLayout(bottomLayout);
   setLayout(TransitionLayout);
}

void TransWidget::AcceptTrans()
{


}

void TransWidget::lengthChanged(QString newString)
{
    if(newString.size()>0)
    {
        OKButton->setDown(false);
        InsertButton->setDown(false);
    }
    else
    {
        OKButton->setDown(true);
        InsertButton->setDown(true);
    }
}


void TransWidget::InsertTrans()
{


}

void TransWidget::refreshData()
{
    QStringList subtaskList;
    for (std::map<std::string, MyGraphType*>::iterator it = xsubtasks->begin(); it!=xsubtasks->end() ;it++)
    {
        subtaskList<<(*it).first.c_str();
    }
    subtaskCombo->clear();
    subtaskCombo->addItem("None");
    subtaskCombo->addItems(subtaskList);
}
