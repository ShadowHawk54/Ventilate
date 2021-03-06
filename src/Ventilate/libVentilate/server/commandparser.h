/*! \file
 * \brief Abstract base class that defines behavior for command parsers.
 * \author Ryan Porterfield
 * \since 2015-11-12
 * \copyright 2015-11-10
 */

#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QDataStream>
#include "connectionhandler.h"

class CommandParser
{
public:
    static const QString ACCEPT;
    static const QString ACCOUNT;
    static const QString ADD;
    static const QString CHANGE;
    static const QString CREATE;
    static const QString DELETE;
    static const QString HISTORY;
    static const QString JOIN;
    static const QString LEAVE;
    static const QString LIST;
    static const QString LOGIN;
    static const QString MESSAGE;
    static const QString MODE;
    static const QString PASSWORD;
    static const QString PEER;
    static const QString REJECT;
    static const QString REQUEST;
    static const QString RESET;
    static const QString ROOM;

    static const QString GENERIC_ERROR;
    static const QString INVALID_PASSWORD;

    explicit CommandParser();
    virtual ~CommandParser();

    /*!
     * \brief Parse an incoming command from a client.
     *
     * This pure virtual function must be implemented by all concrete
     * sub-classes. This function handles extended parsing of sub-commands.
     *
     * \param handler Reference to the ConnectionHandler that recieved the
     * request.
     * \param request QDataStream that the handler read in from the network.
     */
    virtual void parse(const ConnectionHandler& handler, QDataStream& stream) = 0;

protected:
    static const QString LIST_SEPARATOR;
};

#endif // COMMANDPARSER_H
