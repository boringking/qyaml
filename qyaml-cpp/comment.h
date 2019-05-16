#ifndef COMMENT_H
#define COMMENT_H

#include <QByteArray>
#include <QString>

#include <yaml-cpp/emittermanip.h>

namespace YAML {

/*!
    \brief YAML::Comment extension for QString
*/
inline _Comment
Comment(const QString content)
{
  const std::string ssdstr = content.toStdString();
  return _Comment(ssdstr);
}

/*!
    \brief YAML::Comment extension for QByteArray
*/
inline _Comment
Comment(const QByteArray content)
{
  const std::string ssdstr = content.toStdString();
  return _Comment(ssdstr);
}

} // end namespace YAML

#endif // COMMENT_H
