#include "GUI.h"

//#include <QFrame>

#include <QTextStream>
//#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QApplication>
#include <QKeyEvent>
#include <QMoveEvent>
//#include <QTime>
//#include <QTimer>

//#include <QSpinBox>

//#include <QStatusBar>

#include <QInputDialog>

#include <QPixmap> // to work with images


#include <QGridLayout>
#include <QLineEdit>




//#include <QPainter>
//#include <QPainterPath>

boost::multiprecision::cpp_dec_float_50 globalvars::targetXCoord = boost::multiprecision::cpp_dec_float_50("-1.47979627090176002442527993477041152564555105443259951790980763282428625440");
boost::multiprecision::cpp_dec_float_50 globalvars::targetYCoord = boost::multiprecision::cpp_dec_float_50("+0.00119944395281344774628197323337446844456031411413253836203756920565742221");

int globalvars::TOTAL_FRAMES = 10;



VerticalBox::VerticalBox(QWidget *parent) : QMainWindow(parent) {





    std::cout << "LOG=" << std::log10(10.01) << std::endl;



    //const int WIDTH = 800;
    //const int HEIGHT = 600;

    std::cout << "Start of the Mandelbrot creation:" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    std::cout << constants::WIDTH << std::endl;

    std::cout.precision(std::numeric_limits<boost::multiprecision::cpp_dec_float_50>::digits10);


    /*const boost::multiprecision::cpp_dec_float_50 targetXCoord = boost::multiprecision::cpp_dec_float_50("1.556278000000000000000000000000000000000000000000000");


    boost::multiprecision::cpp_dec_float_50 test = boost::multiprecision::cpp_dec_float_50("1.5562780000000000000000000000000000000000000000000000000000152234534534535377788");
    std::cout << targetXCoord << std::endl;
    std::cout << test << std::endl;
    std::cout << targetXCoord - test << std::endl;

    std::cout << sizeof(targetXCoord) << std::endl;
    std::cout << sizeof(test) << std::endl;
    std::cout << sizeof(targetXCoord - test) << std::endl;

    const boost::multiprecision::cpp_dec_float_50 diff1 = targetXCoord - test;
    const long double diff2 = (targetXCoord - test).convert_to<long double>();
    const double diff3 = targetXCoord - test;

    std::cout << diff1 << std::endl;
    std::cout << diff2 << std::endl;
    std::cout << diff3 << std::endl;



    std::cout << sizeof(diff1) << std::endl;
    std::cout << sizeof(diff2) << std::endl;
    std::cout << sizeof(diff3) << std::endl;*/


    for (int i=0; i<=360; i+=50000) {
        double hue = i;
        tmcvsp::HSV hsv(hue, 1, 1);


        tmcvsp::RGB color = hsv.convertToRGB();

        std::cout << "hue=" << i << " " << 255*color.r << " " << 255*color.g << " " << 255*color.b << std::endl;
    }

    tmcvsp::HSV hsv(30.0/360, 1.0, 1.0);


    tmcvsp::RGB color = hsv.convertToRGB();

    std::cout << "hue=5.0" << " " << 30.0/360 << " " << color.r << " " << color.b << " " << color.g << std::endl;


    //return 0;



    //std::vector<int> x = {15, 3, 0, 20};

    std::vector<double> x(5) ;


    x[0] = 15.2;
    x[1] = 3.69;
    x[2] = 0.33;
    x[3] = 20.15;
    x[4] = 12.09;



    //std::vector<int> y;

    std::vector<int> y(x.size());
    std::size_t n(0);
    std::generate(std::begin(y), std::end(y), [&]{ return n++; });

    std::sort(  std::begin(y),
                std::end(y),
                [&](int i1, int i2) { return x[i1] < x[i2]; } );

    for (auto v : y)
        std::cout << v << ' ';




    std::cout << std::endl << std::endl;


    std::vector<int> z(x.size());
    n = 0;
    std::generate(std::begin(z), std::end(z), [&]{ return n++; });

    std::sort(  std::begin(z),
                std::end(z),
                [&](int i1, int i2) { return y[i1] < y[i2]; } );

    for (auto v : z)
        std::cout << v << ' ';




    std::cout << std::endl << std::endl;








    std::vector<int> fractalValues(5) ;


    fractalValues[0] = 15;
    fractalValues[1] = 3;
    fractalValues[2] = 0;
    fractalValues[3] = 20;
    fractalValues[4] = 12;

    std::vector<size_t> idx(5);
    std::iota(idx.begin(), idx.end(), 0);


    for (int i=0; i<5; i++) {
        std::cout << fractalValues[i] << " " << idx[i] << std::endl;
    }

    //std::sort(&fractalValues[0], &fractalValues[5]);

    std::sort(idx.begin(), idx.end(),
              [&fractalValues](size_t i1, size_t i2) {return fractalValues[i1] < fractalValues[i2];});


    for (int i=0; i<5; i++) {
        std::cout << fractalValues[i] << " " << idx[i] << std::endl;
    }






    //return 0;



    //std::sort(fractalCreator.m_fractal, fractalCreator.m_fractal+constants::WIDTH*constants::HEIGHT);
    // sort indexes based on comparing values in v
    //std::sort(idx.begin(), idx.end(),
    //     [&fractalCreator.m_fractal](size_t i1, size_t i2) {return fractalCreator.m_fractal[i1] < fractalCreator.m_fractal[i2];});

    //return 0;


    /*std::unique_ptr<int[]> fractalValues(new int[5]{0}) ;


    fractalValues[0] = 700;
    fractalValues[1] = 4500;
    fractalValues[2] = 3;
    fractalValues[3] = 1259;
    fractalValues[4] = 66500;


    std::vector<int> m_huesCumulative(5);
    std::iota(m_huesCumulative.begin(), m_huesCumulative.end(), 0);

    //std::vector<int> m_huesCumulative(5);
    //std::iota(&m_huesCumulative[0], &m_huesCumulative[5], 0);


    for (int i=0; i<5; i++) {
        std::cout << fractalValues[i] << " " << m_huesCumulative[i] << std::endl;
    }

    //std::sort(&fractalValues[0], &fractalValues[5]);
    std::sort(m_huesCumulative.begin(), m_huesCumulative.end(),
         [&fractalValues](int i1, int i2) {return fractalValues[i1] < fractalValues[i2];});

    //[&fractalValues](size_t i1, size_t i2) {return fractalValues[i1] < fractalValues[i2];});


    for (int i=0; i<5; i++) {
        std::cout << fractalValues[i] << " " << m_huesCumulative[i] << std::endl;
    }

    return 0;*/
























    QFrame *frame = new QFrame(this);
    setCentralWidget(frame);


    QHBoxLayout *hbox = new QHBoxLayout(frame);




















    // Setting pixels

    //QImage fractal()

    img = QImage(constants::WIDTH, constants::HEIGHT, QImage::Format_ARGB32);
    img.fill(QColor(Qt::white).rgb());

    for (int x = 0; x < constants::WIDTH; ++x) {
        for (int y = 0; y < constants::HEIGHT; ++y) {

            //uint32_t colorRGBA = 0xFF00FF00;
            img.setPixel(x, y, qRgb(0, 0, 0));
            //img.setPixel(x, y, colorRGBA);
        }
    }

    l = new QLabel;
    l->setCursor(Qt::CrossCursor);
    l->setPixmap(QPixmap::fromImage(img));
    l->show();


    hbox->addWidget(l);








    QTabWidget *myTabWidget = new QTabWidget;
    myTabWidget->setFixedWidth(600);

    //tabDocument->addTab(tab, tr("General"));



    QWidget *pageSingle = new QWidget;
    myTabWidget->addTab(pageSingle, "Draw a single frame");
    QWidget *pageVideo = new QWidget;
    myTabWidget->addTab(pageVideo, "Run video");










    QVBoxLayout *vboxSingle = new QVBoxLayout(pageSingle);
    vboxSingle->setSpacing(10);






    QGridLayout *gridSingle = new QGridLayout();
    gridSingle->setVerticalSpacing(10);
    gridSingle->setHorizontalSpacing(20);
    gridSingle->setColumnStretch(2, 1);

    // X Location
    QLabel *xLocLabelSingle = new QLabel("x:", this);
    gridSingle->addWidget(xLocLabelSingle, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    xLocTextSingle = new QLineEdit(this);
    xLocTextSingle->setText("-1.47979");
    xLocTextSingle->setFixedWidth(150);
    gridSingle->addWidget(xLocTextSingle, 0, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *xLocInfoSingle = new QLabel("(Insert the x-coordinate to zoom at)", this);
    gridSingle->addWidget(xLocInfoSingle, 0, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);


    // Y Location
    QLabel *yLocLabelSingle = new QLabel("y:", this);
    gridSingle->addWidget(yLocLabelSingle, 1, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    yLocTextSingle = new QLineEdit(this);
    yLocTextSingle->setText("+0.00119");
    yLocTextSingle->setFixedWidth(150);
    gridSingle->addWidget(yLocTextSingle, 1, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *yLocInfoSingle = new QLabel("(Insert the y-coordinate to zoom at)", this);
    gridSingle->addWidget(yLocInfoSingle, 1, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    // Scale
    QLabel *scaleLabelSingle = new QLabel("scale:", this);
    gridSingle->addWidget(scaleLabelSingle, 2, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    scaleTextSingle = new QLineEdit(this);
    scaleTextSingle->setText("0.005");
    scaleTextSingle->setFixedWidth(150);
    gridSingle->addWidget(scaleTextSingle, 2, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *scaleInfoSingle = new QLabel("(Insert the desired scale - default: 0.005)", this);
    gridSingle->addWidget(scaleInfoSingle, 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);


    //QSpacerItem *verticalSpacer = new QSpacerItem(250, 40);
    //grid->addItem(verticalSpacer, 0, 2, 3, 1);

    //QLabel *review = new QLabel("Review:", this);
    //grid->addWidget(review, 2, 0, 1, 1);
    //review->setAlignment(Qt::AlignRight | Qt::AlignTop);

    //QTextEdit *te = new QTextEdit(this);
    //grid->addWidget(te, 2, 1, 3, 1);

    //setLayout(grid);
    vboxSingle->addLayout(gridSingle);

    vboxSingle->addSpacing(50);

    startLoopSingle = new QPushButton("Start", this);
    startLoopSingle->setFixedWidth(100);
    vboxSingle->addWidget(startLoopSingle, 0, Qt::AlignCenter | Qt::AlignVCenter);

    vboxSingle->addStretch(2);

    /*
    add = new QPushButton("Add", this);
    rename = new QPushButton("Rename", this);
    remove = new QPushButton("Remove", this);
    removeAll = new QPushButton("Remove All", this);

    vboxSingle->addStretch(10);
    vboxSingle->addWidget(add);
    vboxSingle->addWidget(rename);
    vboxSingle->addWidget(remove);
    vboxSingle->addWidget(removeAll);
    vboxSingle->addStretch(50);
    */

    





    
    
    
    
    
    
    
    
    
    QVBoxLayout *vboxVideo = new QVBoxLayout(pageVideo);
    vboxVideo->setSpacing(10);






    QGridLayout *gridVideo = new QGridLayout();
    gridVideo->setVerticalSpacing(10);
    gridVideo->setHorizontalSpacing(20);
    gridVideo->setColumnStretch(2, 1);

    // X Location
    QLabel *xLocLabelVideo = new QLabel("x:", this);
    gridVideo->addWidget(xLocLabelVideo, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    xLocTextVideo = new QLineEdit(this);
    xLocTextVideo->setText("-1.47979");
    xLocTextVideo->setFixedWidth(150);
    gridVideo->addWidget(xLocTextVideo, 0, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *xLocInfoVideo = new QLabel("(Insert the x-coordinate to zoom at)", this);
    gridVideo->addWidget(xLocInfoVideo, 0, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);


    // Y Location
    QLabel *yLocLabelVideo = new QLabel("y:", this);
    gridVideo->addWidget(yLocLabelVideo, 1, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    yLocTextVideo = new QLineEdit(this);
    yLocTextVideo->setText("+0.00119");
    yLocTextVideo->setFixedWidth(150);
    gridVideo->addWidget(yLocTextVideo, 1, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *yLocInfoVideo = new QLabel("(Insert the y-coordinate to zoom at)", this);
    gridVideo->addWidget(yLocInfoVideo, 1, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    // Scale
    QLabel *scaleLabelVideo = new QLabel("scale:", this);
    gridVideo->addWidget(scaleLabelVideo, 2, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    scaleTextVideo = new QLineEdit(this);
    scaleTextVideo->setText("0.005");
    scaleTextVideo->setFixedWidth(150);
    gridVideo->addWidget(scaleTextVideo, 2, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *scaleInfoVideo = new QLabel("(Insert the desired scale - default: 0.005)", this);
    gridVideo->addWidget(scaleInfoVideo, 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    // Scale Factor
    QLabel *scaleFactorLabelVideo = new QLabel("scale factor:", this);
    gridVideo->addWidget(scaleFactorLabelVideo, 3, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    scaleFactorTextVideo = new QLineEdit(this);
    scaleFactorTextVideo->setText("0.75");
    scaleFactorTextVideo->setFixedWidth(150);
    gridVideo->addWidget(scaleFactorTextVideo, 3, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *scaleFactorInfoVideo = new QLabel("(Insert the desired scale factor to zoom-in per frame - default: 0.75)", this);
    gridVideo->addWidget(scaleFactorInfoVideo, 3, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);


    // Total Frames
    QLabel *totalFramesLabelVideo = new QLabel("Total frames:", this);
    gridVideo->addWidget(totalFramesLabelVideo, 4, 0, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    totalFramesTextVideo = new QLineEdit(this);
    totalFramesTextVideo->setText("10");
    totalFramesTextVideo->setFixedWidth(150);
    gridVideo->addWidget(totalFramesTextVideo, 4, 1, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *totalFramesInfoVideo = new QLabel("(How many frames to draw - default: 10)", this);
    gridVideo->addWidget(totalFramesInfoVideo, 4, 2, 1, 1, Qt::AlignLeft | Qt::AlignVCenter);



    //QSpacerItem *verticalSpacer = new QSpacerItem(250, 40);
    //grid->addItem(verticalSpacer, 0, 2, 3, 1);

    //QLabel *review = new QLabel("Review:", this);
    //grid->addWidget(review, 2, 0, 1, 1);
    //review->setAlignment(Qt::AlignRight | Qt::AlignTop);

    //QTextEdit *te = new QTextEdit(this);
    //grid->addWidget(te, 2, 1, 3, 1);

    //setLayout(grid);
    vboxVideo->addLayout(gridVideo);


    //QPushButton *startVideo = new QPushButton("Start", this);
    //startVideo->setFixedWidth(100);
    //vboxVideo->addWidget(startVideo, 0, Qt::AlignCenter | Qt::AlignVCenter);

    vboxVideo->addStretch(2);
    

    QHBoxLayout *hboxVideoContainer = new QHBoxLayout;
    startLoopVideo = new QPushButton("Begin loop", this);
    startLoopVideo->setFixedWidth(100);
    hboxVideoContainer->addWidget(startLoopVideo, 0, Qt::AlignRight | Qt::AlignVCenter);

    hboxVideoContainer->addSpacing(50);

    stopLoopVideo = new QPushButton("Stop loop", this);
    stopLoopVideo->setFixedWidth(100);
    stopLoopVideo->setDisabled(true);
    hboxVideoContainer->addWidget(stopLoopVideo, 0, Qt::AlignLeft | Qt::AlignVCenter);


    vboxVideo->addLayout(hboxVideoContainer);

    vboxVideo->addStretch(10);
    

    //hbox->addWidget(lw);
    //hbox->addSpacing(15);
    //hbox->addLayout(vbox);
    
    
    
    
    // Add the whole tab widget to the window
    hbox->addWidget(myTabWidget);

    




    /*
    // Painting a number of ellipses

    QPicture pi;
    QPainter painter(&pi);
    //p.setRenderHint(QPainter::Antialiasing);
    //painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
    //painter.drawLine(0, 0, 200, 200);



    painter.setPen(QPen(QBrush("#535353"), 0.5));
    painter.setRenderHint(QPainter::Antialiasing);

    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));

    for (qreal rot=0; rot < 20.0; rot+=20.0 ) {
        painter.drawEllipse(-142344, -40, 250, 80);
        painter.rotate(rot);
    }




    painter.end(); // Don't forget this line!

    QLabel* labelPic = new QLabel;
    labelPic->setPicture(pi);
    //l.show();
    //return a.exec();

    hbox->addWidget(labelPic);


    */









    /*
    // QPixmap

    QPixmap pixmap("mandelbrot_icon.png");

    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap);

    hbox->addWidget(label, 0, Qt::AlignTop);
    */




    /*
    // Progress bar


    //QVBoxLayout *vboxProg = new QVBoxLayout();

    progress = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &VerticalBox::updateBar);

    QGridLayout *vboxProg = new QGridLayout();
    vboxProg->setColumnStretch(2, 1);

    pbar = new QProgressBar();
    vboxProg->addWidget(pbar, 0, 0, 1, 3);

    startBtn = new QPushButton("Start", this);
    connect(startBtn, &QPushButton::clicked, this, &VerticalBox::startMyTimer);
    vboxProg->addWidget(startBtn, 1, 0, 1, 1);

    stopBtn = new QPushButton("Stop", this);
    connect(stopBtn, &QPushButton::clicked, this, &VerticalBox::stopMyTimer);
    vboxProg->addWidget(stopBtn, 1, 1);


    hbox->addLayout(vboxProg);
    */





    /*
    lw = new QListWidget(this);
    lw->addItem("The Omen");
    lw->addItem("The Exorcist");
    lw->addItem("Notes on a scandal");
    lw->addItem("Fargo");
    lw->addItem("Capote");
    */









    /*
    clickBtn = new QPushButton("Click", this);
    hbox->addWidget(clickBtn, 0, Qt::AlignLeft | Qt::AlignTop);

    QCheckBox *cb = new QCheckBox("Connect", this);
    cb->setCheckState(Qt::Checked);
    hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);



    slider = new QSlider(Qt::Horizontal, this);
    hbox->addWidget(slider, 0, Qt::AlignLeft | Qt::AlignTop);
    slider->setMaximum(599);

    label = new QLabel("0", this);
    hbox->addWidget(label, 0, Qt::AlignLeft | Qt::AlignTop);



    QStringList distros = {"Arch", "Xubuntu", "Redhat", "Debian", "Mandriva"};
    combo = new QComboBox();
    combo->addItems(distros);
    hbox->addWidget(combo);
    hbox->addSpacing(15);

    QLabel *labelFromDistros = new QLabel("Arch", this);
    hbox->addWidget(labelFromDistros);




    QSpinBox *spinbox = new QSpinBox(this);
    QLabel *lbl = new QLabel("0", this);
    hbox->addWidget(spinbox);
    hbox->addWidget(lbl);



    QPushButton *okBtn = new QPushButton("OK", this);
    hbox->addWidget(okBtn, 0, Qt::AlignLeft | Qt::AlignTop);
    QPushButton *applyBtn = new QPushButton("Apply", this);
    hbox->addWidget(applyBtn, 1, Qt::AlignLeft | Qt::AlignTop);

    statusBar();
    */



    //connect(clickBtn, &QPushButton::clicked, this, &VerticalBox::onClick);
    //connect(cb, &QCheckBox::stateChanged, this, &VerticalBox::onCheck);
    //connect(slider, &QSlider::valueChanged, label, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    //connect(combo, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::activated), labelFromDistros, &QLabel::setText);
    //connect(spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), lbl, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    //connect(okBtn, &QPushButton::clicked, this, &VerticalBox::onOkPressed);
    //connect(applyBtn, &QPushButton::clicked, this, &VerticalBox::onApplyPressed);




    connect(startLoopSingle, &QPushButton::clicked, this, [this]() {tryInfiniteLoop("Single");} );
    //connect(startVideo, &QPushButton::clicked, this, [this]() {displayFractal("Video");} );

    connect(startLoopVideo, &QPushButton::clicked, this, [this]() {tryInfiniteLoop("Video");} );
    connect(stopLoopVideo, &QPushButton::clicked, this, &VerticalBox::stopInfiniteLoop);



    //thread = new QThread;

    thread->start();






    //connect(add, &QPushButton::clicked, this, &VerticalBox::addItem);
    //connect(rename, &QPushButton::clicked, this, &VerticalBox::renameItem);
    //connect(remove, &QPushButton::clicked, this, &VerticalBox::removeItem);
    //connect(removeAll, &QPushButton::clicked, this, &VerticalBox::clearItems);








    /*QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    QPushButton *quitBtn = new QPushButton("Quit", this);
    hbox->addWidget(quitBtn, 0, Qt::AlignLeft | Qt::AlignTop);

    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);*/


    /*QGridLayout *grid = new QGridLayout(this);
    grid->setVerticalSpacing(15);
    grid->setHorizontalSpacing(10);

    QLabel *title = new QLabel("Title:", this);
    grid->addWidget(title, 0, 0, 1, 1);
    title->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *edt1 = new QLineEdit(this);
    grid->addWidget(edt1, 0, 1, 1, 1);

    QLabel *author = new QLabel("Author:", this);
    grid->addWidget(author, 1, 0, 1, 1);
    author->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLineEdit *edt2 = new QLineEdit(this);
    grid->addWidget(edt2, 1, 1, 1, 1);

    QLabel *review = new QLabel("Review:", this);
    grid->addWidget(review, 2, 0, 1, 1);
    review->setAlignment(Qt::AlignRight | Qt::AlignTop);

    QTextEdit *te = new QTextEdit(this);
    grid->addWidget(te, 2, 1, 3, 1);

    setLayout(grid);

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    QPushButton *quitBtn = new QPushButton("Quit", this);
    hbox->addWidget(quitBtn, 0, Qt::AlignLeft | Qt::AlignTop);*/





    /*QList<QString> values({ "7", "8", "9", "/",
                            "4", "5", "6", "*",
                            "1", "2", "3", "-",
                            "0", ".", "=", "+"});

    int pos = 0;

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {

            QPushButton *btn = new QPushButton(values[pos], this);
            btn->setFixedSize(40, 40);
            grid->addWidget(btn, i, j);
            pos++;

        }
    }

    setLayout(grid);*/





    /*QLineEdit *nameEdit = new QLineEdit(this);
    QLineEdit *addrEdit = new QLineEdit(this);
    QLineEdit *occpEdit = new QLineEdit(this);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addRow("Name:", nameEdit);
    formLayout->addRow("Email:", addrEdit);
    formLayout->addRow("Age:", occpEdit);

    setLayout(formLayout);*/



    /*QVBoxLayout *vbox = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout(this);

    QListWidget *lw = new QListWidget(this);
    lw->addItem("The omen");
    lw->addItem("The Exorcist");
    lw->addItem("Notes on a scandal");
    lw->addItem("Fargo");
    lw->addItem("Capote");

    QPushButton *add = new QPushButton("Add", this);
    QPushButton *rename = new QPushButton("Rename", this);
    QPushButton *remove = new QPushButton("Remove", this);
    QPushButton *removeall = new QPushButton("Remove All", this);

    vbox->addSpacing(1);
    vbox->addStretch(5);
    vbox->addWidget(add);
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(removeall);
    vbox->addStretch(1);

    hbox->addWidget(lw);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

    setLayout(hbox);*/


    /*QPushButton *okBtn = new QPushButton("OK", this);
    QPushButton *applyBtn = new QPushButton("Apply", this);

    hbox->addWidget(okBtn, 1, Qt::AlignRight);
    hbox->addWidget(applyBtn, 0);

    vbox->addStretch(1);
    vbox->addLayout(hbox);

    vbox->setSpacing(1);

    QPushButton *settings = new QPushButton("Settings", this);
    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *accounts = new QPushButton("Accounts", this);
    accounts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *loans = new QPushButton("Loans", this);
    loans->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *cash = new QPushButton("Cash", this);
    cash->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPushButton *debts = new QPushButton("Debts", this);
    debts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    vbox->addWidget(settings);
    vbox->addWidget(accounts);
    vbox->addWidget(loans);
    vbox->addWidget(cash);
    vbox->addWidget(debts);

    setLayout(vbox);*/
}


void VerticalBox::mousePressEvent(QMouseEvent *event) {

    //std::cout << event->pos().x() << " " << event->pos().y() << std::endl;

    QPoint p = l->mapFrom(this, event->pos());


    //std::cout << " A " << std::endl;

    double iterations = worker->m_fractal[p.y()*constants::WIDTH + p.x()];


    //std::cout << " B " << std::endl;

    int range = worker->getRange(std::round(iterations));
    int rangeTotal = worker->m_rangeTotals[range];


    //std::cout << " C " << std::endl;

    double hue = (double)( 360.0* ( worker->m_histogramCumulative[std::floor(iterations)] + (iterations - std::floor(iterations))*( worker->m_histogramCumulative[std::ceil(iterations)] - worker->m_histogramCumulative[std::floor(iterations)] ) )/rangeTotal );

    double hueCumulative = worker->m_huesCumulative[p.y()*constants::WIDTH + p.x()];

    std::cout << p.x() << " " << p.y() << " Hue=" << hue << " Iters=" << iterations << " Hue cumulative rank=" << hueCumulative << std::endl;





    // Zoom-in cursor functionality

    //p.x();
    //p.y();

    //std::cout << "The current center is placed at x=: " << xLocTextSingle->text().toDouble() << std::endl;
    //std::cout << "and at y=: " << yLocTextSingle->text().toDouble() << std::endl;




    double xFractal = (p.x() - constants::WIDTH/2)*scaleTextSingle->text().toDouble() + xLocTextSingle->text().toDouble();
    double yFractal = -(p.y() - constants::HEIGHT/2)*scaleTextSingle->text().toDouble() + yLocTextSingle->text().toDouble();

    std::cout << "The new center will be placed at x=: " << xFractal << " and at y=: " << yFractal << std::endl;



    xLocTextSingle->setText(QString::number(xFractal));
    yLocTextSingle->setText(QString::number(yFractal));
    scaleTextSingle->setText(QString::number(scaleTextSingle->text().toDouble()*0.5));



    tryInfiniteLoop("Single");

}

void VerticalBox::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Escape) {
        qApp->quit();
    }

}

void VerticalBox::moveEvent(QMoveEvent *event) {

    int x = event->pos().x();
    int y = event->pos().y();

    QString text = "Mandelbrot Plot Tool (" + QString::number(x) + "," + QString::number(y) + ")";

    setWindowTitle(text);

}

/*
void VerticalBox::timerEvent(QTimerEvent *event) {

    Q_UNUSED(event);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    label->setText(stime);

}
*/


/*
void VerticalBox::onClick() {

    QTextStream out(stdout);
    out << "Button clicked" << endl;

}

void VerticalBox::onCheck(int state) {

    if (state == Qt::Checked) {
        connect(clickBtn, &QPushButton::clicked, this, &VerticalBox::onClick);
    }
    else {
        disconnect(clickBtn, &QPushButton::clicked, this, &VerticalBox::onClick);
    }

}

void VerticalBox::onOkPressed() {
    statusBar()->showMessage("OK button pressed", 2000);
}

void VerticalBox::onApplyPressed() {
    statusBar()->showMessage("Apply button pressed", 2000);
}
*/



/*
void VerticalBox::displayFractal(std::string&& mode) {

    std::cout << "asdasdasd:" << xLocTextSingle->text().toDouble() << std::endl;
    std::cout << "asdasdasd:" << yLocTextSingle->text().toStdString() << std::endl;
    std::cout << "asdasdasd:" << scaleTextSingle->text().toDouble() << std::endl;

    double xLoc;
    double yLoc;
    double scale;
    double scaleFactor;

    if ( mode == "Single" ) {
        std::cout << "Single mode" << std::endl;

        xLoc = xLocTextSingle->text().toDouble();
        yLoc = yLocTextSingle->text().toDouble();
        scale = scaleTextSingle->text().toDouble();
    }
    else if ( mode == "Video" ) {
        std::cout << "Video mode" << std::endl;

        xLoc = xLocTextVideo->text().toDouble();
        yLoc = yLocTextVideo->text().toDouble();
        scale = scaleTextVideo->text().toDouble();
        scaleFactor = scaleFactorTextVideo->text().toDouble();

        globalvars::TOTAL_FRAMES = totalFramesTextVideo->text().toInt();

        std::cout << "TEST FOR INT: " << globalvars::TOTAL_FRAMES << std::endl;
    }



    fractalCreator->addRange(0.0, tmcvsp::RGB(0, 0, 0));
    //fractalCreator.addRange(0.3, tmcvsp::RGB(255, 0, 0));
    //fractalCreator.addRange(0.5, tmcvsp::RGB(255, 255, 0));
    fractalCreator->addRange(1.0, tmcvsp::RGB(0.9, 0, 0));



    //fractalCreator.addZoom(tmcvsp::Zoom(constants::WIDTH/2, constants::HEIGHT/2, 1.0));
    //fractalCreator.addZoom(tmcvsp::Zoom(312, 304, 0.1));

    fractalCreator->m_zoomList.setTo( xLoc, yLoc, scale );

    //fractalCreator.addZoom(tmcvsp::Zoom( xLocText->text().toDouble() + constants::WIDTH/2,
    //                        -yLocText->text().toDouble() + constants::HEIGHT/2,
    //                        scaleText->text().toDouble() ));

    //    fractalCreator.calculateIteration();
    //    fractalCreator.calculateTotalIterations();
    //    fractalCreator.calculateRangeTotals();

    //    fractalCreator.drawFractal();

    //    fractalCreator.writeBitmap("test.bmp");


    //fractalCreator.run("test.bmp");




    uint32_t* buffer = new uint32_t[constants::WIDTH*constants::HEIGHT];

    memset(buffer, 0x00, constants::WIDTH*constants::HEIGHT*sizeof(uint32_t));


    //Uint8 temp = fractalCreator.m_arrayRGBA[5][215];
    //std::cout << fractalCreator.m_arrayRGBA[5][215][3] << std::endl;
    //fractalCreator.m_arrayRGBA[5][215][3] = 'A';
    //std::cout << fractalCreator.m_arrayRGBA[5][215][3] << std::endl;
    //fractalCreator.drawOnWindow();





    bool isRunning = true;

    //SDL_Event event;

    int frame = 0;
    while (isRunning) {

        // "Compute" a frame of the fractal

        if (frame < globalvars::TOTAL_FRAMES) {

            std::cout << "Computation of frame no: " << frame << std::endl;
            std::cout << "---------------------------------" << std::endl;

            fractalCreator->calculateIterationsForAllPixels("double");
            fractalCreator->calculateTotalIterations();
            fractalCreator->calculateCumulativeHues();
            fractalCreator->calculateRangeTotals();

            fractalCreator->drawFractal("HSV_with_histogram");


            // SDL Related
            fractalCreator->writeToSDLBuffer(buffer);



            // End of loop and prepare for next frame
            fractalCreator->prepareForTheNextFrame(scaleFactor);


            //SDL_UpdateTexture(texture, NULL, buffer, constants::WIDTH*sizeof(Uint32));
            //SDL_RenderClear(renderer);
            //SDL_RenderCopy(renderer, texture, NULL, NULL);
            //SDL_RenderPresent(renderer);

            std::cout << "OKKKKKK2" << std::endl;
            // Write to Bitmap file
            fractalCreator->writeBitmap("test"+ std::to_string(frame) + ".bmp");
            std::cout << "OKKKKKK3" << std::endl;
            frame++;



            //img.fill(QColor(Qt::yellow).rgb());

            for (int x = 0; x < constants::WIDTH; ++x) {
                for (int y = 0; y < constants::HEIGHT; ++y) {

                    if (x==241 && y==240) {
                        //std::cout << std::hex << x << ", " << y << ", " << buffer[y*constants::WIDTH + x] << std::dec << std::endl;
                    }
                    img.setPixel(x, y, buffer[y*constants::WIDTH + x]);
                }
            }

            l->setPixmap(QPixmap::fromImage(img));
            l->repaint();


        }
        else {
            isRunning = false;
        }








        // Zoom in


        // Stop after the first frame for the single frame case
        if ( mode == "Single" ) {
            isRunning = false;
        }













        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            else if (event.type == SDL_MOUSEBUTTONUP) {
                if (event.button.button == SDL_BUTTON_LEFT) {

                    double iterations = fractalCreator.m_fractal[event.button.y*constants::WIDTH + event.button.x];


                    int range = fractalCreator.getRange(std::round(iterations));
                    int rangeTotal = fractalCreator.m_rangeTotals[range];




                    double hue = (double)( 360.0* ( fractalCreator.m_histogramCumulative[std::floor(iterations)] + (iterations - std::floor(iterations))*( fractalCreator.m_histogramCumulative[std::ceil(iterations)] - fractalCreator.m_histogramCumulative[std::floor(iterations)] ) )/rangeTotal );

                    double hueCumulative = fractalCreator.m_huesCumulative[event.button.y*constants::WIDTH + event.button.x];

                    std::cout << event.button.x << " " << event.button.y << " Hue=" << hue << " Iters=" << iterations << " Hue cumulative rank=" << hueCumulative << std::endl;
                }
            }
        }




    }





    std::cout << "OKKKKKK1" << std::endl;











    std::cout << "OKKKKKK7" << std::endl;

    delete [] buffer;

    std::cout << "OKKKKKK8" << std::endl;


}
*/










void VerticalBox::tryInfiniteLoop(std::string&& mode) {

    std::cout << "asdasdasd:" << xLocTextSingle->text().toDouble() << std::endl;
    std::cout << "asdasdasd:" << yLocTextSingle->text().toDouble() << std::endl;
    std::cout << "asdasdasd:" << scaleTextSingle->text().toDouble() << std::endl;

    double xLoc;
    double yLoc;
    double scale;
    double scaleFactor;

    if ( mode == "Single" ) {
        std::cout << "Single mode started." << std::endl;

        startLoopSingle->setDisabled(true);

        xLoc = xLocTextSingle->text().toDouble();
        yLoc = yLocTextSingle->text().toDouble();
        scale = scaleTextSingle->text().toDouble();
        scaleFactor = 1.0;
        globalvars::TOTAL_FRAMES = 1;
    }
    else if ( mode == "Video" ) {
        std::cout << "Video mode started." << std::endl;

        startLoopVideo->setDisabled(true);
        stopLoopVideo->setEnabled(true);

        xLoc = xLocTextVideo->text().toDouble();
        yLoc = yLocTextVideo->text().toDouble();
        scale = scaleTextVideo->text().toDouble();
        scaleFactor = scaleFactorTextVideo->text().toDouble();
        globalvars::TOTAL_FRAMES = totalFramesTextVideo->text().toInt();

        std::cout << "TEST FOR INT: " << globalvars::TOTAL_FRAMES << std::endl;
    }


    // Creating "placeholder" FractalCreator() here. Each time a button is pressed we create the correct one.

    //worker = new tmcvsp::FractalCreator();
    //worker->moveToThread(thread);
    //connect(worker, &Worker::error, this, &VerticalBox::errorString, Qt::QueuedConnection);

    std::cout << "Reached A." << std::endl;

    //thread->~QThread();
    //thread = new QThread;

    std::cout << "Reached B." << std::endl;


    // Destroying any previous FractalCreator and creating a correct new here.
    worker->~FractalCreator();
    worker = new tmcvsp::FractalCreator( xLoc, yLoc, scale, scaleFactor );
    worker->moveToThread(thread);



    std::cout << "Reached C." << std::endl;

    connect(this, &VerticalBox::startFractalCreation, worker, &tmcvsp::FractalCreator::process, Qt::QueuedConnection);
    connect(worker, &tmcvsp::FractalCreator::sendBuffer, this, &VerticalBox::drawBufferOnGUI, Qt::QueuedConnection);
    connect(this, &VerticalBox::drawingCompleted, worker, &tmcvsp::FractalCreator::setDrawingFlag, Qt::QueuedConnection);
    connect(this, &VerticalBox::signalTermination, worker, &tmcvsp::FractalCreator::setTerminationFlag, Qt::QueuedConnection);
    connect(thread, &QThread::started, worker, &tmcvsp::FractalCreator::process);
    connect(worker, &tmcvsp::FractalCreator::finished, thread, &QThread::quit);
    connect(worker, &tmcvsp::FractalCreator::finished, worker, &tmcvsp::FractalCreator::deleteLater);
    connect(worker, &tmcvsp::FractalCreator::reenableButtons, this, &VerticalBox::finishButtonJobs);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);


    emit startFractalCreation();
    
    //worker->process();
    //worker->computeFractal();


}



void VerticalBox::drawBufferOnGUI(uint32_t* bufferOfImage) {
    std::cout << "Drawing the frame on GUI..." << std::endl;

    uint32_t a = bufferOfImage[500];

    std::cout << "Got the 500th element equal to: " << a << std::endl;

    //img.fill(QColor(Qt::yellow).rgb());

    for (int x = 0; x < constants::WIDTH; ++x) {
        for (int y = 0; y < constants::HEIGHT; ++y) {

            if (x==241 && y==240) {
                //std::cout << std::hex << x << ", " << y << ", " << buffer[y*constants::WIDTH + x] << std::dec << std::endl;
            }
            img.setPixel(x, y, bufferOfImage[y*constants::WIDTH + x]);
        }
    }

    std::cout << "Fractal was drawn." << std::endl;
    
    emit drawingCompleted();

    l->setPixmap(QPixmap::fromImage(img));
    l->repaint();


}



void VerticalBox::stopInfiniteLoop() {


    std::cout << "Main thread: Stop button pressed." << std::endl;

    //thread->requestInterruption();

    emit signalTermination();

    std::cout << "Main thread: Worker thread terminated successfully." << std::endl;
}

void VerticalBox::finishButtonJobs() {

    if ( globalvars::TOTAL_FRAMES > 1 ) {
        std::cout << "ALL WENT GOOD. VIDEO JOB FINISHING" << std::endl;

        startLoopVideo->setEnabled(true);
        stopLoopVideo->setDisabled(true);
    }
    else {
        std::cout << "ALL WENT GOOD. SINGLE JOB FINISHING" << std::endl;

        startLoopSingle->setEnabled(true);
    }

}


//void VerticalBox::errorString(QString a) {
//    std::cout << a.toStdString() << std::endl;
//}





/*
void VerticalBox::addItem() {
    QString c_text = QInputDialog::getText(this, "Item", "Enter new item");
    QString s_text = c_text.simplified();

    if (!s_text.isEmpty()) {
        lw->addItem(s_text);
        int r = lw->count() - 1;
        lw->setCurrentRow(r);
    }
}

void VerticalBox::renameItem() {
    QListWidgetItem *curItem = lw->currentItem();

    int r = lw->row(curItem);
    QString c_text = curItem->text();
    QString r_text = QInputDialog::getText(this, "Item", "Enter new item", QLineEdit::Normal, c_text);
    QString s_text = r_text.simplified();

    if (!s_text.isEmpty()) {
        QListWidgetItem *item = lw->takeItem(r);
        delete item;
        lw->insertItem(r, s_text);
        lw->setCurrentRow(r);
    }


}

void VerticalBox::removeItem() {

    int r = lw->currentRow();

    QTextStream out(stdout);
    out << r << "th item removed" << endl;

    if (r != -1) {
        QListWidgetItem *item = lw->takeItem(r);
        delete item;
    }

}

void VerticalBox::clearItems() {
    if (lw->count() != 0) {
        lw->clear();
    }
}
*/


/*
void VerticalBox::startMyTimer() {

    if (progress >= MAX_VALUE) {
        progress = 0;
        pbar->setValue(0);
    }

    if (!timer->isActive()) {
        startBtn->setEnabled(false);
        stopBtn->setEnabled(true);
        timer->start(DELAY);
    }

}

void VerticalBox::stopMyTimer() {

    if (timer->isActive()) {
        startBtn->setEnabled(true);
        stopBtn->setEnabled(false);
        timer->stop();
    }

}

void VerticalBox::updateBar() {

    progress++;

    if (progress <= MAX_VALUE) {
        pbar->setValue(progress);
    }
    else {
        startBtn->setEnabled(true);
        stopBtn->setEnabled(false);
        timer->stop();
    }


}
*/


/*
void VerticalBox::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    //QPainter qp(pwidget);
    //drawLines(&qp);
}

void VerticalBox::drawLines(QPainter *qp) {

    QPen pen(Qt::black, 2, Qt::SolidLine);
    qp->setPen(pen);
    qp->drawLine(20, 40, 250, 40);

    pen.setStyle(Qt::DashLine);
    qp->setPen(pen);
    qp->drawLine(20, 80, 250, 80);

    pen.setStyle(Qt::DashDotLine);
    qp->setPen(pen);
    qp->drawLine(20, 120, 250, 120);

    QVector<qreal> dashes;
    qreal space = 4;

    dashes << 1 << space << 5 << space;

    pen.setStyle(Qt::CustomDashLine);
    pen.setDashPattern(dashes);
    qp->setPen(pen);
    qp->drawLine(20, 240, 250, 240);
}
*/
