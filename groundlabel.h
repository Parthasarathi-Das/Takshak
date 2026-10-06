#ifndef GROUNDLABEL_H
#define GROUNDLABEL_H

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QColor>
#include <QMap>
#include <QPair>

class GroundLabel : public QLabel
{
    Q_OBJECT

public:
    // Pass squareSidePixels to define the size of each grid square in pixels
    // Used by Qt Designer (promoted widget): GroundLabel(parent)
    explicit GroundLabel(QWidget *parent = nullptr);
    explicit GroundLabel(int squareSidePixels, QWidget *parent = nullptr);

    // --- Configuration API ---
    void setSquareSize(int sidePixels);
    void setDefaultColors(const QColor &light, const QColor &dark);

    // --- Cell Color Abstraction API ---
    void setCellColor(int row, int col, const QColor &color);
    void resetCellColor(int row, int col);
    void resetBoard();

    // Getter utilities
    int getRows() const;
    int getCols() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_squareSide; // Size of each square in pixels
    QColor m_defaultLight;
    QColor m_defaultDark;

    // Sparse storage for custom cell colors: Key is (row, col)
    QMap<QPair<int, int>, QColor> m_customColors;

    QColor getDefaultColor(int row, int col) const;
};

#endif // GROUNDLABEL_H
