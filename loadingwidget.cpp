#include "loadingwidget.h"

LoadingWidget::LoadingWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog); // 无边框
    setAttribute(Qt::WA_TranslucentBackground); // 背景透明
    //setAttribute(Qt::WA_DeleteOnClose); // 设置窗口在关闭时销毁

    // 屏幕居中显示
    int frmX = this->width();
    int frmY = this->height();

    QDesktopWidget w;
    int deskWidth = w.width();
    int deskHeight = w.height();

    QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
    move(movePoint);

    // 加载gif图片
    movie = new QMovie(":/UniquenessCheck/Resources/loading1.gif");
    ui.labelLoading->setMovie(movie);
    movie->start();
}

LoadingWidget::~LoadingWidget()
{
    delete movie;
}
