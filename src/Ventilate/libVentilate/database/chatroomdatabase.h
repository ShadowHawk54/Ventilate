/*! \file
 * \brief Helper class that interfaces with the chat room database.
 * \author Ryan Porterfield
 * \since 2015-11-11
 * \copyright BSD 3 Clause
 */

#ifndef CHATROOMDATABASE_H
#define CHATROOMDATABASE_H

#include <QList>
#include "chatroom.h"
#include "databaseinterface.h"
#include "libventilate_global.h"

class LIBVENTILATESHARED_EXPORT ChatRoomDatabase
        : public DatabaseInterface<ChatRoom>
{
public:
    explicit ChatRoomDatabase();

    virtual bool add(const ChatRoom& elem);
    virtual ChatRoom find(const QUuid& id);
    virtual QList<ChatRoom> getAll();
    virtual bool remove(const ChatRoom& elem);

protected:
    virtual ChatRoom buildFromQuery(const QSqlQuery& query) const;

private:
};

#endif // CHATROOMDATABASE_H
