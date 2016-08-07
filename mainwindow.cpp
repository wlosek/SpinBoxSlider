#include "mainwindow.h"

#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSpinBox* spinBox = new QSpinBox( this);
    QSlider* slider = new QSlider( Qt::Horizontal, this);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    spinBox->setValue( 30);

    QHBoxLayout* layout = new QHBoxLayout( this);
    layout->addWidget(spinBox);
    layout->addWidget(slider);

    QWidget* wdg = new QWidget( this);
    wdg->setLayout( layout);
    setCentralWidget( wdg);

    setWindowTitle( QString("Title"));
}

MainWindow::~MainWindow()
{

}
