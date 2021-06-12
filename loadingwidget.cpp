#include "loadingwidget.h"

LoadingWidget::LoadingWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog); // �ޱ߿�
    setAttribute(Qt::WA_TranslucentBackground); // ����͸��
    //setAttribute(Qt::WA_DeleteOnClose); // ���ô����ڹر�ʱ����

    // ��Ļ������ʾ
    int frmX = this->width();
    int frmY = this->height();

    QDesktopWidget w;
    int deskWidth = w.width();
    int deskHeight = w.height();

    QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
    move(movePoint);

    // ����gifͼƬ
    movie = new QMovie(":/UniquenessCheck/Resources/loading1.gif");
    ui.labelLoading->setMovie(movie);
    movie->start();
}

LoadingWidget::~LoadingWidget()
{
    delete movie;
}
