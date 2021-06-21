#ifndef PLOTTER_H
#define PLOTTER_H

#include "OptionMenuPlotter.h"
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QValueAxis>

using namespace QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class Plotter; }
QT_END_NAMESPACE

class Plotter : public QMainWindow
  {
  Q_OBJECT
  private:
    Ui::Plotter *m_pUi;
    QLineSeries *m_pSeries0=new QLineSeries;
    QVector <QLineSeries *> m_Series={};
    QScatterSeries *m_pSeriesBreakPoint = new QScatterSeries;
    QValueAxis *m_pAxisX = new QValueAxis;
    QValueAxis *m_pAxisY = new QValueAxis;
    QGraphicsScene *m_pScene = nullptr;
    QChart *m_pChart = new QChart;
    QChartView *m_pChartView=nullptr;
    OptionMenuPlotter *m_PlotterMenu=nullptr;
    SettingsChart m_MainChart;
    QVector<QPointF> m_Result{};
    QVector <double> m_BadPoints{};
    QVector <QPointF> m_BreakPoints{};
    QVector <double> m_BreakPointsX{};
    QVector <int> number_of_breakpoints{};

    QByteArray m_Formula;
    QPen m_Pen;
    double m_YStart = 1.79769e+308, m_YEnd = 2.22507e-308, m_YMaxValue{};
    double m_Precision = 1e-10;
    int m_Prec = 1;
    bool m_NeedReCalc = true;
    bool m_NumberAxisIsHidden=true;
    bool m_NamesAxisIsHidden=true;

    void ConfigureGraph();
    void ReCalculate();
    QByteArray FindExprScob(int index);
    int FindIndexLastExprScob(int index);
    void DomainFunction(double *pX_start,double *pX_end, double *pX_step);
    QVector <QPointF> CalculatePoint();


public:
     Plotter(QObject* parent=nullptr);
     ~Plotter();
     bool Plot(QByteArray Formula);

  private slots:
    void on_xmin_valueChanged(const QString &arg1);
    void on_xmax_valueChanged(const QString &arg1);
    void on_ymin_valueChanged(const QString &arg1);
    void on_ymax_valueChanged(const QString &arg1);
    void on_cur_val_slider_valueChanged(int value);
    void on_precision_Fx_value_changed(int value);
    void on_ContextMenuCall(QPoint val);
    void on_HideNumbers();
    void on_HideNames();
    void on_SaveGraph();
    void on_Options();
    //void GraphSettings(SettingsChart chart);
};

#endif // PLOTTER_H
