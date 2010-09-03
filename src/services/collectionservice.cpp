#include "collectionservice.h"

CollectionService::CollectionService(QObject *parent) :
    QObject(parent)
{
    watcher = new QFileSystemWatcher(this);
    qDebug("Collection service running!");

    // TODO: verify if every path is valid.
    watcher->addPaths(ApplicationSettings::collectionFolderList());

    connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(fileChanged(QString)));
    connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(dirChanged(QString)));

}

void CollectionService::fileChanged(QString path) {
    qDebug("FILE CHANGED " + path.toUtf8());
}

void CollectionService::dirChanged(QString path) {
    qDebug("DIR CHANGED " + path.toUtf8());
}

void CollectionService::refresh() {
    setPaths(ApplicationSettings::collectionFolderList());

}

void CollectionService::scan() {

}

void CollectionService::setPaths(QStringList paths) {
    watcher->removePaths(watcher->directories());

    // TODO: verify if every path is valid
    watcher->addPaths(paths);
}
