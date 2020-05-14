#include "audiolevel.h"
#include <QPainter>

AudioLevel::AudioLevel(QWidget *parent)
  : QWidget(parent)
{
    setMinimumHeight(15);
    setMaximumHeight(50);
}

void AudioLevel::setLevel(qreal level)
{
    if (m_level != level) {
        m_level = level;
        update();
    }
}

void AudioLevel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    // draw level
    qreal widthLevel = m_level * width();
    painter.fillRect(0, 0, widthLevel, height(), Qt::red);
    // clear the rest of the control
    painter.fillRect(widthLevel, 0, width(), height(), Qt::black);
}
