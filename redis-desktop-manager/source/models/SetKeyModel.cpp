#include "SetKeyModel.h"

SetKeyModel::SetKeyModel(ConnectionBridge * db, const QString &keyName, int dbIndex)
	: KeyModel(db, keyName, dbIndex), PaginatedModel()
{
	setColumnCount(1);
}

void SetKeyModel::loadValue()
{
	QString command = QString("SMEMBERS %1").arg(keyName);

	db->addCommand(Command(command, this, CALLMETHOD("loadedValue"), dbIndex));
}

void SetKeyModel::initModel(const QVariant & value)
{
	*rawData = value.toStringList();
	setCurrentPage(1);
}

void SetKeyModel::setCurrentPage(int page)
{
	//todo implement this

}