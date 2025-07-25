#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QString>
#include <QMediaPlayer>
#include <QTimer>
#include <QAudioOutput>

class Alarm : public QObject
{
    Q_OBJECT
public:
    virtual ~Alarm(){};
    static Alarm & GetInstance()
    {
        static Alarm instance;
        return instance;
    }
    void Start(bool useCustom);
    void Stop();
    bool isPlaying();
    bool canResume;
    void SetCustomPath(QString);
    bool UsingCustomPath;
    bool isBastard;
    bool isOneshot;
    int listId;
private:
    explicit Alarm(QObject *parent = 0);
    QMediaPlayer * media;
    QString _DefaultPath;
    QString _CustPath;
    QAudioOutput *audioOutput;

    QTimer *_Pause;

    bool _isPlaying;
    
signals:
    
public slots:
    void RepeatAllTheThings(QMediaPlayer::MediaStatus);
    void Resume();
    void SetVolume(int);
    
};

#endif // ALARM_H
