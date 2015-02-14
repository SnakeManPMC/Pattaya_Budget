#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::on_update_Button_clicked()
{
	int eurobudget = (ui->days->value() * (ui->hotel->value() + ui->food->value() + ui->taxi->value() + ui->bars->value() + ui->nartut->value()) / ui->exchange->value() + ui->airlineTicket->value() );

	// EURO sum
	ui->sum_euro_Label->setText(QString::number(eurobudget));

	// BAHT sum
	ui->sum_baht_Label->setText(QString::number((ui->days->value() * (ui->hotel->value() + ui->food->value() + ui->taxi->value() + ui->bars->value() + ui->nartut->value())) + (ui->airlineTicket->value() * ui->exchange->value())));

	// monthly savings
	ui->sum_months_label->setText(QString::number(eurobudget / ui->monthlySavings->value()));
}
