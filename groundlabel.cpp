#include "groundlabel.h"

GroundLabel::GroundLabel(QWidget *parent)
    : GroundLabel(40, parent)
{
}

GroundLabel::GroundLabel(int squareSidePixels, QWidget *parent)
    : QLabel(parent)
    , m_squareSide(squareSidePixels > 0 ? squareSidePixels : 40)
    , m_defaultLight(QColor(238, 238, 210)) // Default Cream
    , m_defaultDark(QColor(118, 150, 86))   // Default Green
{
}

void GroundLabel::setSquareSize(int sidePixels)
{
    if (sidePixels > 0) {
        m_squareSide = sidePixels;
        update(); // Redraw grid with new pixel sizes
    }
}

void GroundLabel::setDefaultColors(const QColor &light, const QColor &dark)
{
    m_defaultLight = light;
    m_defaultDark = dark;
    update();
}

void GroundLabel::setCellColor(int row, int col, const QColor &color)
{
    if (row < 0 || col < 0) return;

    m_customColors[qMakePair(row, col)] = color;
    update(); // Triggers automatic repaint
}

void GroundLabel::resetCellColor(int row, int col)
{
    m_customColors.remove(qMakePair(row, col));
    update();
}

void GroundLabel::resetBoard()
{
    m_customColors.clear();
    update();
}

int GroundLabel::getRows() const
{
    return height() / m_squareSide;
}

int GroundLabel::getCols() const
{
    return width() / m_squareSide;
}

QColor GroundLabel::getDefaultColor(int row, int col) const
{
    return ((row + col) % 2 == 0) ? m_defaultLight : m_defaultDark;
}

void GroundLabel::paintEvent(QPaintEvent *event)
{
    // Render default QLabel background base if set
    QLabel::paintEvent(event);

    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    // Calculate grid dimensions dynamically based on label width/height and square pixel size
    int cols = getCols();
    int rows = getRows();

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            QPair<int, int> cellKey = qMakePair(r, c);

            // Use custom color if set, otherwise default checkerboard pattern
            QColor fillColor = m_customColors.contains(cellKey)
                                   ? m_customColors.value(cellKey)
                                   : getDefaultColor(r, c);

            painter.setBrush(fillColor);

            // Draw exact 1:1 square grid cell using fixed pixel dimensions
            painter.drawRect(c * m_squareSide, r * m_squareSide, m_squareSide, m_squareSide);
        }
    }
}