#include "steshellmanager.h"

static STEShellManager shellManagerInstance;

STEShellManager::STEShellManager(QObject *parent)
    : QObject(parent)
{

}

STEShellManager* STEShellManager::instance()
{
    return &shellManagerInstance;
}
