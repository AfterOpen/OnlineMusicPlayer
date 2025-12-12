/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *search_box;
    QPushButton *search_btn;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *music_list;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPlainTextEdit *lyric;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QListWidget *history;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QSlider *processbar;
    QLabel *timer;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pre;
    QPushButton *pause;
    QPushButton *next;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSlider *volume;
    QLabel *volume_value;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow{background-image: url(:/res/robot.png);  background-repeat: no-repeat; /* \347\246\201\346\255\242\345\271\263\351\223\272 */\n"
"    background-position: center; /* \345\233\276\347\211\207\345\261\205\344\270\255 */\n"
"    background-size: cover; /* \346\214\211\346\257\224\344\276\213\347\274\251\346\224\276\357\274\214\345\256\214\346\225\264\346\230\276\347\244\272\345\233\276\347\211\207 */}\n"
"QLabel {color: rgb(255, 255, 255);}\n"
"QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 0.2); /* \347\231\275\350\211\262\345\215\212\351\200\217\346\230\216\357\274\21020%\344\270\215\351\200\217\346\230\216\345\272\246\357\274\211 */\n"
"    border: 1px solid rgba(255, 255, 255, 0.3); /* \350\276\271\346\241\206\345\215\212\351\200\217\346\230\216 */\n"
"    color: white; /* \346\226\207\345\255\227\347\231\275\350\211\262\357\274\210\351\201\277\345\205\215\351\200\217\346\230\216\350\203\214\346\231\257\344\270\213\347\234\213\344\270\215\346\270\205\357\274\211 */\n"
"    padding: 5px;"
                        " /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"/* 3. \345\210\227\350\241\250/\346\226\207\346\234\254\345\214\272\345\237\237\357\274\210\346\255\214\346\233\262\345\210\227\350\241\250\343\200\201\346\255\214\350\257\215\343\200\201\345\216\206\345\217\262\346\220\234\347\264\242\357\274\211\351\200\217\346\230\216 */\n"
"QListWidget, QPlainTextEdit, QScrollArea {\n"
"    background-color: rgba(0, 0, 0, 0.1); /* \351\273\221\350\211\262\345\215\212\351\200\217\346\230\216\357\274\21010%\344\270\215\351\200\217\346\230\216\345\272\246\357\274\211 */\n"
"    border: 1px solid rgba(255, 255, 255, 0.2); /* \350\276\271\346\241\206\350\275\273\345\276\256\345\217\257\350\247\201 */\n"
"    color: white; /* \346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"}\n"
"QToolButton{\n"
"	background-color: rgba(255, 255, 255,15);\n"
" border: 1px solid rgba(255, 255, 255, 0.2); /* \350\276\271\346\241\206\350\275\273\345\276\256\345\217\257\350\247\201 */\n"
"}\n"
"/* 4. \346\214\211\351\222\256\357\274\210"
                        "\346\220\234\347\264\242\346\214\211\351\222\256\343\200\201\346\222\255\346\224\276\346\216\247\345\210\266\346\214\211\351\222\256\357\274\211\351\200\217\346\230\216 */\n"
"QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.15); /* \347\231\275\350\211\262\345\215\212\351\200\217\346\230\216 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206\357\274\210\346\210\226\350\275\273\345\276\256\350\276\271\346\241\206\357\274\211 */\n"
"    color: white; /* \346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"    padding: 5px 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /*  hover\346\227\266\347\250\215\344\272\256 */\n"
"}\n"
"\n"
"/* 5. \346\273\221\345\235\227\357\274\210\350\277\233\345\272\246\346\235\241\357\274\211\351\200\217\346\230\216 */\n"
"QSlider::groove:horizontal {\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    height: 4px;\n"
"    border-radius: 2px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background-color:"
                        " white;\n"
"    width: 12px;\n"
"    margin: -4px 0; /* \346\211\251\345\261\225\346\273\221\345\235\227\347\202\271\345\207\273\345\214\272\345\237\237 */\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QSpliter{background-color: rgba(0, 0, 0, 5);}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton = new QToolButton(groupBox_4);
        toolButton->setObjectName("toolButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy2);
        toolButton->setMinimumSize(QSize(20, 26));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        toolButton->setIcon(icon);

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout_5->addWidget(groupBox_4);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        groupBox->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:{rgb(85, 255, 255)}\n"
"background-color: rgb(85, 170, 0);"));

        horizontalLayout->addWidget(label);

        search_box = new QLineEdit(groupBox);
        search_box->setObjectName("search_box");
        search_box->setFont(font);

        horizontalLayout->addWidget(search_box);

        search_btn = new QPushButton(groupBox);
        search_btn->setObjectName("search_btn");
        search_btn->setFont(font);
        search_btn->setStyleSheet(QString::fromUtf8("color:{rgb(85, 255, 255)}\n"
"background-color: rgb(85, 170, 0);"));

        horizontalLayout->addWidget(search_btn);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        splitter = new QSplitter(groupBox_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        music_list = new QListWidget(layoutWidget);
        music_list->setObjectName("music_list");

        verticalLayout_2->addWidget(music_list);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName("layoutWidget1");
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(label_3);

        lyric = new QPlainTextEdit(layoutWidget1);
        lyric->setObjectName("lyric");

        verticalLayout_3->addWidget(lyric);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName("layoutWidget2");
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        history = new QListWidget(layoutWidget2);
        history->setObjectName("history");

        verticalLayout_4->addWidget(history);

        splitter->addWidget(layoutWidget2);

        verticalLayout_6->addWidget(splitter);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setFlat(false);
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        processbar = new QSlider(groupBox_3);
        processbar->setObjectName("processbar");
        processbar->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_5->addWidget(processbar);

        timer = new QLabel(groupBox_3);
        timer->setObjectName("timer");
        timer->setFrameShape(QFrame::Shape::Box);
        timer->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_5->addWidget(timer);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pre = new QPushButton(groupBox_3);
        pre->setObjectName("pre");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoPrevious));
        pre->setIcon(icon1);

        horizontalLayout_3->addWidget(pre);

        pause = new QPushButton(groupBox_3);
        pause->setObjectName("pause");
        pause->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause));
        pause->setIcon(icon2);

        horizontalLayout_3->addWidget(pause);

        next = new QPushButton(groupBox_3);
        next->setObjectName("next");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::MediaSkipForward));
        next->setIcon(icon3);

        horizontalLayout_3->addWidget(next);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        volume = new QSlider(groupBox_3);
        volume->setObjectName("volume");
        sizePolicy1.setHeightForWidth(volume->sizePolicy().hasHeightForWidth());
        volume->setSizePolicy(sizePolicy1);
        volume->setMinimumSize(QSize(80, 0));
        volume->setValue(50);
        volume->setOrientation(Qt::Orientation::Horizontal);
        volume->setTickPosition(QSlider::TickPosition::NoTicks);

        horizontalLayout_4->addWidget(volume);

        volume_value = new QLabel(groupBox_3);
        volume_value->setObjectName("volume_value");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(volume_value->sizePolicy().hasHeightForWidth());
        volume_value->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(volume_value);


        horizontalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_6->addWidget(groupBox_3);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 1);

        verticalLayout_5->addWidget(groupBox_2);

        verticalLayout_5->setStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_4->setTitle(QString());
        toolButton->setText(QString());
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262\345\220\215\347\247\260\357\274\232", nullptr));
        search_btn->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\255\214\350\257\215", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\346\220\234\347\264\242", nullptr));
        groupBox_3->setTitle(QString());
        timer->setText(QCoreApplication::translate("MainWindow", "00\357\274\23200", nullptr));
        pre->setText(QString());
        pause->setText(QString());
        next->setText(QString());
        volume_value->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
