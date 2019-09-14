/***************************************************************************
  Copyright (c) 2013-2019, Simon Meaden
***************************************************************************

  Simonsoft - QYaml-Cpp

  qyaml-cpp is a set of extensions to yaml-cpp to handle some common
  Qt 5 types such a QString, QPint and others.

  This code is licensed under the GPL Version 3.0
***************************************************************************/

#ifndef COLLECTION_H
#define COLLECTION_H

#include <QFont>
#include <QList>
#include <QMap>
#include <QObject>
#include <QSet>
#include <QString>
#include <QStringList>
#include <QVector>

#include <list>
#include <map>
#include <vector>

#include "node.h"
#include "yaml-cpp/yaml.h"

namespace YAML {

// template <>
template<class T>
struct convert<QList<T>>
{
  static Node encode(const QList<T>& rhs) {
    Node node(NodeType::Sequence);

    std::list<T> slist = rhs.toStdList();
    node = slist;

    return node;
  }

  static bool decode(const Node& node, QList<T>& rhs) {
    if (!node.IsSequence()) {
      return false;
    }

    std::list<T> slist = node.as<std::list<T>>();
    rhs = QList<T>::fromStdList(slist);

    return true;
  }
};

template<class T>
inline void operator>>(const Node& node, QList<T>& q)
{
  std::list<T> slist;
  slist = node.as<std::list<T>>();
  q = QList<T>::fromStdList(slist);
}

template<class K, class V>
struct convert<QMap<K, V>>
{
  static Node encode(const QMap<K, V>& rhs) {
    Node node(NodeType::Map);

    std::map<K, V> smap = rhs.toStdMap();
    node = smap;

    return node;
  }

  static bool decode(const Node& node, QMap<K, V>& rhs) {
    if (!node.IsMap()) {
      return false;
    }

    std::map<K, V> smap = node.as<std::map<K, V>>();
    rhs = QMap<K, V>(smap);

    return true;
  }
};

template<class K, class V>
inline void operator>>(const Node& node, QMap<K, V>& q)
{
  std::map<K, V> smap;
  smap = node.as<std::map<K, V>>();
  q = QMap<K, V>(smap);
}

// template <>
template<class T>
struct convert<QVector<T>>
{
  static Node encode(const QVector<T>& rhs) {
    Node node(NodeType::Sequence);

    std::vector<T> svector = rhs.toStdVector();
    node = svector;

    return node;
  }

  static bool decode(const Node& node, QVector<T>& rhs) {
    if (!node.IsSequence()) {
      return false;
    }

    std::vector<T> svector = node.as<std::vector<T>>();
    rhs = QVector<T>::fromStdVector(svector);

    return true;
  }
};

template<class T>
inline void operator>>(const Node& node, QVector<T>& q)
{
  std::vector<T> svector;
  svector = node.as<std::vector<T>>();
  q = QVector<T>::fromStdVector(svector);
}

// template <>
template<class T>
struct convert<QSet<T>>
{
  static Node encode(const QSet<T>& rhs) {
    Node node(NodeType::Sequence);

    std::list<T> slist = rhs.toList();
    node = slist;

    return node;
  }

  static bool decode(const Node& node, QSet<T>& rhs) {
    if (!node.IsSequence()) {
      return false;
    }

    std::list<T> slist = node.as<std::list<T>>();
    rhs = QSet<T>::fromList(QList<T>::fromStdList(slist));

    return true;
  }
};

template<class T>
inline void operator>>(const Node& node, QSet<T>& q)
{
  std::list<T> slist = node.as<std::list<T>>();
  q = QSet<T>::fromList(QList<T>::fromStdList(slist));
}

} // end of namespace YAML

#endif // COLLECTION_H
