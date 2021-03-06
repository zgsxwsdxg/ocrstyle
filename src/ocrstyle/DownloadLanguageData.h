// Copyright 2013, Zaoqibu Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Zaoqibu Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: vwarship@163.com (Junjian Wang)
//
// The Optical Character Recognition (OCR Style)

#ifndef DownloadLanguageData_H
#define DownloadLanguageData_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QModelIndex>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QFile;
class QLabel;
class QLineEdit;
class QProgressBar;
class QPushButton;
class QSslError;
class QAuthenticator;
class QNetworkReply;
class QListView;
class QStandardItemModel;
QT_END_NAMESPACE

class DownloadLanguageData : public QDialog
{
    Q_OBJECT

public:
    DownloadLanguageData(QWidget *parent = 0);

    void startRequest(QUrl url);

private:
    QWidget* createOCRLanguages();
    QLayout* createControlButtons();
    void createOCRLanguagesItemModel();
    bool isExistOCRLanguages(QString languageAlias);

private slots:
    void downloadFile();
    void cancelDownload();
    void closeWindow();
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);
    void enableDownloadButton(QModelIndex modelIndex);

private:
    QLabel *statusLabel;
    QProgressBar *progressBar;
    QPushButton *downloadButton;
    QPushButton *cancelButton;
    QPushButton *quitButton;

    QUrl url;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    QFile *file;
    int httpGetId;
    bool httpRequestAborted;

    QListView *ocrLanguagesListView;
    QStandardItemModel *ocrLanguagesItemModel;

};

#endif
